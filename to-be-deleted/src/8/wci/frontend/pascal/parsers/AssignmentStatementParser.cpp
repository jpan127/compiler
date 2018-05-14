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
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

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
    
{
    // Create the ASSIGN node.
    ICodeNode *assign_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_ASSIGN);


    // Look up the target identifier in the symbol table stack.
    // Enter the identifier into the table if it's not found.
    string target_name = to_lower(token->get_text());
    SymTabEntry *target_id = symtab_stack->lookup(target_name);
    if (target_id == nullptr)
    {
        target_id = symtab_stack->enter_local(target_name);
    }
    target_id->append_line_number(token->get_line_number());

    token = next_token(token);  // consume the identifier token

    // Create the variable node and set its name attribute.
    ICodeNode *variable_node =
            ICodeFactory::create_icode_node(
                             (ICodeNodeType) NT_VARIABLE);
    variable_node->set_attribute((ICodeKey) ID, target_id);

    // The ASSIGN node adopts the variable node as its first child.
    assign_node->add_child(variable_node);

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

    // Parse the expression.  The ASSIGN node adopts the expression's
    // node as its second child.
    ExpressionParser expression_parser(this);
    assign_node->add_child(expression_parser.parse_statement(token));

    return assign_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
