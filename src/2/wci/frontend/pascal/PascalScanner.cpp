/**
 * <h1>PascalScanner</h1>
 *
 * <p>The Pascal scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "PascalScanner.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;
using namespace wci::frontend;

PascalScanner::PascalScanner(Source *source) : Scanner(source)
{
}

Token *PascalScanner::extract_token() throw (string)
{
    Token *token;
    char current_ch = current_char();

    // Construct the next token.  The current character determines the
    // token type.
    if (current_ch == Source::END_OF_FILE)
    {
        token = nullptr;
    }
    else
    {
        token = new Token(source);
    }

    return token;
}

}}} // namespace wci::frontend::pascal
