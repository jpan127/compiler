/**
 * <h1>PascalParserTD</h1>
 *
 * <p>The top-down Pascal parser.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <chrono>
#include "PascalParserTD.h"

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"
#include "PascalToken.h"
#include "PascalError.h"
#include "parsers/StatementParser.h"
#include "../../intermediate/SymTabEntry.h"
#include "../../intermediate/ICode.h"
#include "../../intermediate/ICodeNode.h"
#include "../../intermediate/ICodeFactory.h"
#include "../../intermediate/icodeimpl/ICodeNodeImpl.h"
#include "../../message/Message.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;
using namespace std::chrono;
using namespace wci::frontend;
using namespace wci::frontend::pascal::parsers;
using namespace wci::intermediate::icodeimpl;
using namespace wci::message;

PascalErrorHandler PascalParserTD::error_handler;

PascalParserTD::PascalParserTD(Scanner *scanner) : Parser(scanner)
{
    PascalError::initialize();
}

PascalParserTD::PascalParserTD(PascalParserTD *parent)
    : Parser(parent->get_scanner())
{
}

void PascalParserTD::parse() 
{
    steady_clock::time_point start_time = steady_clock::now();
    icode = ICodeFactory::create_icode();

    Token *token = next_token(nullptr);
    ICodeNode *root_node = nullptr;

    // Look for the BEGIN token to parse a compound statement.
    if (token->get_type() == (TokenType) PT_BEGIN)
    {
        StatementParser *statement_parser = new StatementParser(this);
        root_node = statement_parser->parse_statement(token);
        token = current_token();
    }
    else {
        error_handler.flag(token, UNEXPECTED_TOKEN, this);
    }

    // Look for the final period.
    if (token->get_type() != (TokenType) PT_DOT)
    {
        error_handler.flag(token, MISSING_PERIOD, this);
    }

    int last_line_number = token->get_line_number();

    // Set the parse tree root node.
    if (root_node != nullptr) icode->set_root(root_node);

    // Send the parser summary message.
    steady_clock::time_point end_time = steady_clock::now();
    double elapsed_time =
            duration_cast<duration<double>>(end_time - start_time).count();
    Message message(PARSER_SUMMARY,
                    LINE_COUNT, to_string(last_line_number),
                    ERROR_COUNT, to_string(get_error_count()),
                    ELAPSED_TIME, to_string(elapsed_time));
    send_message(message);
}

int PascalParserTD::get_error_count() const
{
    return error_handler.get_error_count();
}

PascalToken *PascalParserTD::synchronize(const set<PascalTokenType>& sync_set)
{
    Token *token = current_token();

    // If the current token is not in the synchronization set,
    // then it is unexpected and the parser must recover.
    if (sync_set.find((PascalTokenType) token->get_type()) == sync_set.end())
    {
        // Flag the unexpected token.
        error_handler.flag(token, UNEXPECTED_TOKEN, this);

        // Recover by skipping tokens that are not
        // in the synchronization set.
        do
        {
            token = next_token(token);
        } while ((token != nullptr) &&
                 (sync_set.find((PascalTokenType) token->get_type())
                      == sync_set.end()));
    }

    return (PascalToken *) token;
}

}}} // namespace wci::frontend::pascal
