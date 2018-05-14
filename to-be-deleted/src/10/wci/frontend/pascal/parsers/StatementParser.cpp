/**
 * <h1>StatementParser</h1>
 *
 * <p>Parse a Pascal statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "StatementParser.h"
#include "CompoundStatementParser.h"
#include "AssignmentStatementParser.h"
#include "RepeatStatementParser.h"
#include "WhileStatementParser.h"
#include "ForStatementParser.h"
#include "IfStatementParser.h"
#include "CaseStatementParser.h"
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

set<PascalTokenType> StatementParser::STMT_START_SET =
{
    PT_BEGIN, PT_CASE, PT_FOR, PT_IF, PT_REPEAT, PT_WHILE,
    PT_IDENTIFIER, PT_SEMICOLON,
};

set<PascalTokenType> StatementParser::STMT_FOLLOW_SET =
{
    PT_SEMICOLON, PT_END, PT_ELSE, PT_UNTIL, PT_DOT,
};

StatementParser::StatementParser(PascalParserTD *parent)
    : PascalParserTD(parent)
{
}

ICodeNode *StatementParser::parse_statement(Token *token) throw (string)
{
    ICodeNode *statement_node = nullptr;
    int line_number = token->get_line_number();

// cout << "<<< " << token->get_text() << " " << PascalToken::token_to_string_map[(PascalTokenType)token->get_type()] << endl;

    switch ((PascalTokenType) token->get_type())
    {
        case PT_BEGIN:
        {
            CompoundStatementParser compound_parser(this);
            statement_node = compound_parser.parse_statement(token);
            break;
        }

        // An assignment statement begins with a variable's identifier.
        case PT_IDENTIFIER:
        {
            AssignmentStatementParser assignment_parser(this);
            statement_node = assignment_parser.parse_statement(token);
            break;
        }

        case PT_REPEAT:
        {
            RepeatStatementParser repeat_parser(this);
            statement_node = repeat_parser.parse_statement(token);
            break;
        }

        case PT_WHILE:
        {
            WhileStatementParser while_parser(this);
            statement_node = while_parser.parse_statement(token);
            break;
        }

        case PT_FOR:
        {
            ForStatementParser for_parser(this);
            statement_node = for_parser.parse_statement(token);
            break;
        }

        case PT_IF:
        {
            IfStatementParser if_parser(this);
            statement_node = if_parser.parse_statement(token);
            break;
        }

        case PT_CASE:
        {
            CaseStatementParser case_parser(this);
            statement_node = case_parser.parse_statement(token);
            break;
        }

        default:
        {
            statement_node =
                ICodeFactory::create_icode_node((ICodeNodeType) NT_NO_OP);
            break;
        }
    }

    set_line_number(statement_node, line_number);
    return statement_node;
}

void StatementParser::set_line_number(ICodeNode *node, int line_number)
{
    if (node != nullptr)
    {
        node->set_attribute((ICodeKey) ICodeKeyImpl::LINE, line_number);
    }
}

void StatementParser::parse_list(Token *token, ICodeNode *parent_node,
                                 const PascalTokenType terminator,
                                 const PascalErrorCode error_code)
    throw (string)
{
    // Synchronization set for the terminator.
    set<PascalTokenType> terminator_set(STMT_START_SET);
    terminator_set.insert(terminator);

    // Loop to parse each statement until the END token
    // or the end of the source file.
    while (   (token != nullptr)
           && (token->get_type() != (TokenType) terminator))
    {
        // Parse a statement.  The parent node adopts the statement node.
        ICodeNode *statement_node = parse_statement(token);
        parent_node->add_child(statement_node);

        token = current_token();
        TokenType token_type = token->get_type();

        // Look for the semicolon between statements.
        if (token_type == (TokenType) PT_SEMICOLON)
        {
            token = next_token(token);  // consume the ;
        }

        // If at the start of the next statement, then missing a semicolon.
        else if (STMT_START_SET.find((PascalTokenType) token_type)
                    != STMT_START_SET.end())
        {
            error_handler.flag(token, MISSING_SEMICOLON, this);
        }

        // Synchronize at the start of the next statement
        // or at the terminator.
        token = synchronize(terminator_set);
    }

    // Look for the terminator token.
    if (token->get_type() == (TokenType) terminator)
    {
        token = next_token(token);  // consume the terminator token
    }
    else {
        error_handler.flag(token, error_code, this);
    }
}

}}}}  // namespace wci::frontend::pascal::parsers
