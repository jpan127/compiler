/**
 * <h1>AssignmentStatementParser</h1>
 *
 * <p>Parse a Pascal assignment statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "AssignmentStatementParser.h"
#include "StatementParser.h"
#include "ExpressionParser.h"
#include "VariableParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/symtabimpl/Predefined.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"
#include "../../../intermediate/TypeSpec.h"
#include "../../../intermediate/TypeFactory.h"
#include "../../../intermediate/typeimpl/TypeChecker.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::icodeimpl;
using namespace wci::intermediate::typeimpl;

bool AssignmentStatementParser::INITIALIZED = false;

set<PascalTokenType> AssignmentStatementParser::COLON_EQUALS_SET;

void AssignmentStatementParser::initialize()
{
    if (INITIALIZED) return;

    COLON_EQUALS_SET = ExpressionParser::EXPR_START_SET;
    COLON_EQUALS_SET.insert(PascalTokenType::COLON_EQUALS);

    set<PascalTokenType>::iterator it;
    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
         it != StatementParser::STMT_FOLLOW_SET.end();
         it++)
    {
        COLON_EQUALS_SET.insert(*it);
    }

    INITIALIZED = true;
}

AssignmentStatementParser::AssignmentStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *AssignmentStatementParser::parse_statement(Token *token)
    throw (string)
{
    // Create the ASSIGN node.
    ICodeNode *assign_node = ICodeFactory::create_icode_node((ICodeNodeType) NT_ASSIGN);

    // Parse the target variable.
    VariableParser variableParser(this);
    ICodeNode *target_node = variableParser.parse_variable(token);
    TypeSpec *target_typespec = target_node != nullptr
                                    ? target_node->get_typespec()
                                    : Predefined::undefined_type;

    // The ASSIGN node adopts the variable node as its first child.
    assign_node->add_child(target_node);

    // Synchronize on the := token.
    token = synchronize(COLON_EQUALS_SET);
    if (token->get_type() == (TokenType) PT_COLON_EQUALS)
    {
        token = next_token(token);  // consume the :=
    }
    else
    {
        error_handler.flag(token, MISSING_COLON_EQUALS, this);
    }

    Token *expr_token = new Token(*token);

    // Parse the expression.  The ASSIGN node adopts the expression's
    // node as its second child.
    ExpressionParser expression_parser(this);
    ICodeNode *expr_node = expression_parser.parse_statement(token);
    assign_node->add_child(expr_node);

    // Type check: Assignment compatible?
    TypeSpec *expr_typespec = expr_node != nullptr
                                  ? expr_node->get_typespec()
                                  : Predefined::undefined_type;
    if (!TypeChecker::are_assignment_compatible(target_typespec,
                                                expr_typespec))
    {
        token = current_token();
        error_handler.flag(expr_token, PascalErrorCode::INCOMPATIBLE_TYPES,
                           this);
    }

    assign_node->set_typespec(target_typespec);

    delete expr_token;
    return assign_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
