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
#include "../../message/Message.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;
using namespace std::chrono;
using namespace wci::frontend;
using namespace wci::message;

PascalParserTD::PascalParserTD(Scanner *scanner) : Parser(scanner)
{
}

PascalParserTD::PascalParserTD(PascalParserTD *parent)
    : Parser(parent->get_scanner())
{
}

void PascalParserTD::parse() throw (string)
{
    steady_clock::time_point start_time = steady_clock::now();

    int last_line_number;
    Token *token = nullptr;

    // Loop over each token until the end of file.
    while ((token = next_token(token)) != nullptr)
    {
        last_line_number = token->get_line_number();
    }

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

int PascalParserTD::get_error_count() const { return 0; }

}}} // namespace wci::frontend::pascal
