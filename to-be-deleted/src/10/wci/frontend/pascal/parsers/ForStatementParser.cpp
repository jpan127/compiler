/**
 * <h1>ForStatementParser</h1>
 *
 * <p>Parse a FOR statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <set>
#include "ForStatementParser.h"
#include "StatementParser.h"
#include "AssignmentStatementParser.h"
#include "ExpressionParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/symtabimpl/Predefined.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"
#include "../../../intermediate/TypeSpec.h"
#include "../../../intermediate/typeimpl/TypeSpecImpl.h"
#include "../../../intermediate/typeimpl/TypeChecker.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::icodeimpl;
using namespace wci::intermediate::typeimpl;

bool ForStatementParser::INITIALIZED = false;

set<PascalTokenType> ForStatementParser::TO_DOWNTO_SET;
set<PascalTokenType> ForStatementParser::DO_SET;

void ForStatementParser::initialize()
{
    if (INITIALIZED) return;

    TO_DOWNTO_SET = ExpressionParser::EXPR_START_SET;
    TO_DOWNTO_SET.insert(PascalTokenType::TO);
    TO_DOWNTO_SET.insert(PascalTokenType::DOWNTO);

    DO_SET = StatementParser::STMT_START_SET;
    DO_SET.insert(PascalTokenType::DO);

    set<PascalTokenType>::iterator it;
    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
         it != StatementParser::STMT_FOLLOW_SET.end();
         it++)
    {
        TO_DOWNTO_SET.insert(*it);
        DO_SET.insert(*it);
    }

    INITIALIZED = true;
}

ForStatementParser::ForStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *ForStatementParser::parse_statement(Token *token)
    throw (string)
{
    int for_line_number = token->get_line_number();
    token = next_token(token);  // consume the FOR

    // Create the loop COMPOUND, LOOP, and TEST nodes.
    ICodeNode *compound_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_COMPOUND);
    ICodeNode *loop_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_LOOP);
    ICodeNode *test_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_TEST);

    set_line_number(loop_node, for_line_number);

    // Parse the embedded initial assignment.
    AssignmentStatementParser assignment_parser(this);
    ICodeNode *init_assign_node = assignment_parser.parse_statement(token);
    TypeSpec *control_typespec = init_assign_node != nullptr
                                     ? init_assign_node->get_typespec()
                                     : Predefined::undefined_type;

    set_line_number(init_assign_node, for_line_number);

    // Type check: The control variable's type must be integer
    //             or enumeration.
    if (!TypeChecker::is_integer(control_typespec) &&
        (control_typespec->get_form()
                               != (TypeForm) TypeFormImpl::ENUMERATION))
    {
        error_handler.flag(token, INCOMPATIBLE_TYPES, this);
    }

    // The COMPOUND node adopts the initial ASSIGN and the LOOP nodes
    // as its first and second children.
    compound_node->add_child(init_assign_node);
    compound_node->add_child(loop_node);

    // Synchronize at the TO or DOWNTO.
    token = synchronize(TO_DOWNTO_SET);
    TokenType direction = token->get_type();

    // Look for the TO or DOWNTO.
    if (   (direction == (TokenType) PT_TO)
        || (direction == (TokenType) PT_DOWNTO))
    {
        token = next_token(token);  // consume the TO or DOWNTO
    }
    else {
        direction = (TokenType) PT_TO;
        error_handler.flag(token, MISSING_TO_DOWNTO, this);
    }

    // Create a relational operator node: GT for TO, or LT for DOWNTO.
    ICodeNode *relop_node =
        ICodeFactory::create_icode_node(
                direction == (TokenType) PT_TO ? (ICodeNodeType) NT_GT
                                               : (ICodeNodeType) NT_LT);
    relop_node->set_typespec(Predefined::boolean_type);

    // Copy the control VARIABLE node. The relational operator
    // node adopts the copied VARIABLE node as its first child.
    ICodeNode *control_var_node = init_assign_node->get_children()[0];
    relop_node->add_child(control_var_node->copy());

    // Parse the termination expression. The relational operator node
    // adopts the expression as its second child.
    ExpressionParser expression_parser(this);
    ICodeNode *expr_node = expression_parser.parse_statement(token);
    relop_node->add_child(expr_node);

    // Type check: The termination expression type must be assignment
    //             compatible with the control variable's type.
    TypeSpec *expr_typespec = expr_node != nullptr
                                  ? expr_node->get_typespec()
                                  : Predefined::undefined_type;
    if (!TypeChecker::are_assignment_compatible(control_typespec,
                                                expr_typespec))
    {
        error_handler.flag(token, INCOMPATIBLE_TYPES, this);
    }

    // The TEST node adopts the relational operator node as its only child.
    // The LOOP node adopts the TEST node as its first child.
    test_node->add_child(relop_node);
    loop_node->add_child(test_node);

    // Synchronize at the DO.
    token = synchronize(DO_SET);
    if (token->get_type() == (TokenType) PT_DO)
    {
        token = next_token(token);  // consume the DO
    }
    else {
        error_handler.flag(token, MISSING_DO, this);
    }

    // Parse the nested statement. The LOOP node adopts the statement
    // node as its second child.
    StatementParser statement_parser(this);
    loop_node->add_child(statement_parser.parse_statement(token));

    // Create an assignment with a copy of the control variable
    // to advance the value of the variable.
    ICodeNode *next_assign_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_ASSIGN);
    next_assign_node->set_typespec(control_typespec);
    next_assign_node->add_child(control_var_node->copy());
    set_line_number(next_assign_node, for_line_number);

    // Create the arithmetic operator node:
    // ADD for TO, or SUBTRACT for DOWNTO.
    ICodeNode *arith_op_node =
            ICodeFactory::create_icode_node(
                    direction == (TokenType) PT_TO
                                        ? (ICodeNodeType) NT_ADD
                                        : (ICodeNodeType) NT_SUBTRACT);
    arith_op_node->set_typespec(Predefined::integer_type);

    // The operator node adopts a copy of the loop variable as its
    // first child and the value 1 as its second child.
    arith_op_node->add_child(control_var_node->copy());
    ICodeNode *one_node =
            ICodeFactory::create_icode_node(
                                    (ICodeNodeType) NT_INTEGER_CONSTANT);
    one_node->set_attribute((ICodeKey) VALUE, 1);
    arith_op_node->add_child(one_node);

    // The next ASSIGN node adopts the arithmetic operator node as its
    // second child. The loop node adopts the next ASSIGN node as its
    // third child.
    next_assign_node->add_child(arith_op_node);
    loop_node->add_child(next_assign_node);

    return compound_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
