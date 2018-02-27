/**
 * <h1>CaseStatementParser</h1>
 *
 * <p>Parse a Pascal CASE statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <set>
#include "CaseStatementParser.h"
#include "StatementParser.h"
#include "AssignmentStatementParser.h"
#include "ExpressionParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

set<PascalTokenType> CaseStatementParser::CONSTANT_START_SET =
{
    PT_IDENTIFIER, PT_INTEGER, PT_PLUS, PT_MINUS, PT_STRING,
};

set<PascalTokenType> CaseStatementParser::OF_SET;
set<PascalTokenType> CaseStatementParser::COMMA_SET;

bool CaseStatementParser::INITIALIZED = false;

void CaseStatementParser::initialize()
{
    if (INITIALIZED) return;

    OF_SET = CONSTANT_START_SET;
    OF_SET.insert(PT_OF);

    COMMA_SET = CONSTANT_START_SET;
    COMMA_SET.insert(PT_COMMA);
    COMMA_SET.insert(PT_COLON);

    set<PascalTokenType>::iterator it;
    for (it  = StatementParser::STMT_START_SET.begin();
         it != StatementParser::STMT_START_SET.end();
         it++)
    {
        COMMA_SET.insert(*it);
    }
    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
         it != StatementParser::STMT_FOLLOW_SET.end();
         it++)
    {
        OF_SET.insert(*it);
        COMMA_SET.insert(*it);
    }

    INITIALIZED = true;
}

CaseStatementParser::CaseStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *CaseStatementParser::parse_statement(Token *token) 
{
    token = next_token(token);  // consume the CASE

    // Create a SELECT node.
    ICodeNode *select_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_SELECT);

    // Parse the CASE expression.
    // The SELECT node adopts the expression subtree as its first child.
    ExpressionParser expression_parser(this);
    select_node->add_child(expression_parser.parse_statement(token));

    // Synchronize at the OF.
    token = synchronize(OF_SET);
    if (token->get_type() == (TokenType) PT_OF)
    {
        token = next_token(token);  // consume the OF
    }
    else {
        error_handler.flag(token, MISSING_OF, this);
    }

    // Set of CASE branch constants.
    set<int> constant_set;

    // Loop to parse each CASE branch until the END token
    // or the end of the source file.
    while ((token != nullptr) &&
           (token->get_type() != (TokenType) PT_END))
    {
        // The SELECT node adopts the CASE branch subtree.
        select_node->add_child(parse_branch(token, constant_set));

        token = current_token();
        TokenType token_type = token->get_type();

        // Look for the semicolon between CASE branches.
        if (token_type == (TokenType) PT_SEMICOLON)
        {
            token = next_token(token);  // consume the ;
        }

        // If at the start of the next constant, then missing a semicolon.
        else if (CONSTANT_START_SET.find((PascalTokenType) token_type)
                      != CONSTANT_START_SET.end())
        {
            error_handler.flag(token, MISSING_SEMICOLON, this);
        }
    }

    // Look for the END token.
    if (token->get_type() == (TokenType) PT_END)
    {
        token = next_token(token);  // consume END
    }
    else
    {
        error_handler.flag(token, MISSING_END, this);
    }

    return select_node;
}

ICodeNode *CaseStatementParser::parse_branch(Token *token,
                                             set<int>& constant_set)
    
{
    // Create an SELECT_BRANCH node and a SELECT_CONSTANTS node.
    // The SELECT_BRANCH node adopts the SELECT_CONSTANTS node as its
    // first child.
    ICodeNode *branch_node =
            ICodeFactory::create_icode_node(
                                       (ICodeNodeType) NT_SELECT_BRANCH);
    ICodeNode *constants_node =
            ICodeFactory::create_icode_node(
                                    (ICodeNodeType) NT_SELECT_CONSTANTS);
    branch_node->add_child(constants_node);

    // Parse the list of CASE branch constants.
    // The SELECT_CONSTANTS node adopts each constant.
    parse_constant_list(token, constants_node, constant_set);

    // Look for the : token.
    token = current_token();
    if (token->get_type() == (TokenType) PT_COLON)
    {
        token = next_token(token);  // consume the :
    }
    else
    {
        error_handler.flag(token, MISSING_COLON, this);
    }

    // Parse the CASE branch statement. The SELECT_BRANCH node adopts
    // the statement subtree as its second child.
    StatementParser statementParser(this);
    branch_node->add_child(statementParser.parse_statement(token));

    return branch_node;
}

void CaseStatementParser::parse_constant_list(Token *token,
                                              ICodeNode *constants_node,
                                              set<int>& constant_set)
    
{
    // Loop to parse each constant.
    while (CONSTANT_START_SET.find((PascalTokenType) token->get_type())
            != CONSTANT_START_SET.end())
    {

        // The constants list node adopts the constant node.
        constants_node->add_child(parse_constant(token, constant_set));

        // Synchronize at the comma between constants.
        token = synchronize(COMMA_SET);

        // Look for the comma.
        if (token->get_type() == (TokenType) PT_COMMA)
        {
            token = next_token(token);  // consume the ,
        }

        // If at the start of the next constant, then missing a comma.
        else if (CONSTANT_START_SET.find((PascalTokenType) token->get_type())
                    != CONSTANT_START_SET.end())
        {
            error_handler.flag(token, MISSING_COMMA, this);
        }
    }
}

ICodeNode *CaseStatementParser::parse_constant(Token *token,
                                               set<int>& constant_set)
    
{
    bool minus_sign = false;
    ICodeNode *constant_node = nullptr;

    // Synchronize at the start of a constant.
    token = synchronize(CONSTANT_START_SET);
    TokenType token_type = token->get_type();

    // Plus or minus sign?
    if (   (token_type == (TokenType) PT_PLUS)
        || (token_type == (TokenType) PT_MINUS))
    {
        minus_sign = token_type == (TokenType) PT_MINUS;
        token = next_token(token);  // consume sign
    }

    // Parse the constant.
    switch ((PascalTokenType) token->get_type())
    {
        case PT_IDENTIFIER:
        {
            constant_node = parse_identifier_constant(token, minus_sign);
            break;
        }

        case PT_INTEGER:
        {
            constant_node = parse_integer_constant(token->get_text(),
                                                   minus_sign);
            break;
        }

        case PT_STRING:
        {
            constant_node =
                parse_character_constant(token, cast(token->get_value(), string),
                                         minus_sign);
            break;
        }

        default:
        {
            error_handler.flag(token, INVALID_CONSTANT, this);
            break;
        }
    }

    // Check for reused constants.
    if (constant_node != nullptr)
    {
        Object data_value = constant_node->get_attribute((ICodeKey) VALUE);
        int value = cast(data_value, int);

        if (constant_set.find(value) != constant_set.end())
        {
            error_handler.flag(token, CASE_CONSTANT_REUSED, this);
        }
        else
        {
            constant_set.insert(value);
        }
    }

    next_token(token);  // consume the constant
    return constant_node;
}

ICodeNode *CaseStatementParser::parse_identifier_constant(
                                     Token *token, const bool minus_sign)
    
{
    // Placeholder: Don't allow for now.
    error_handler.flag(token, INVALID_CONSTANT, this);
    return nullptr;
}

ICodeNode *CaseStatementParser::parse_integer_constant(
                              const string value, const bool minus_sign)
{
    ICodeNode *constant_node =
            ICodeFactory::create_icode_node(
                                    (ICodeNodeType) NT_INTEGER_CONSTANT);

    int int_value = stoi(value);
    if (minus_sign) int_value = -int_value;

    constant_node->set_attribute((ICodeKey) VALUE, int_value);
    return constant_node;
}

ICodeNode *CaseStatementParser::parse_character_constant(
                 Token *token, const string value, const bool minus_sign)
{
    ICodeNode *constant_node = nullptr;

    if (minus_sign)
    {
        error_handler.flag(token, INVALID_CONSTANT, this);
    }
    else
    {
        if (value.length() == 1)
        {
            constant_node =
                ICodeFactory::create_icode_node(
                                     (ICodeNodeType) NT_INTEGER_CONSTANT);
            constant_node->set_attribute((ICodeKey) VALUE, (int) value[0]);
        }
        else
        {
            error_handler.flag(token, INVALID_CONSTANT, this);
        }
    }

    return constant_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
