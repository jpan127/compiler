/**
 * <h1>PascalScanner</h1>
 *
 * <p>The Pascal scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <iostream>
#include "PascalScanner.h"
#include "PascalToken.h"
#include "PascalError.h"
#include "../Source.h"
#include "tokens/PascalWordToken.h"
#include "tokens/PascalNumberToken.h"
#include "tokens/PascalStringToken.h"
#include "tokens/PascalSpecialSymbolToken.h"
#include "tokens/PascalErrorToken.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal::tokens;

PascalScanner::PascalScanner(Source *source) : Scanner(source)
{
}

Token *PascalScanner::extract_token() throw (string)
{
    skip_white_space();

    Token *token;
    char current_ch = current_char();
    string string_ch = " ";

    string_ch[0] = current_ch;

    // Construct the next token.  The current character determines the
    // token type.
    if (current_ch == Source::END_OF_FILE)
    {
        token = nullptr;
    }
    else if (isalpha(current_ch))
    {
        token = new PascalWordToken(source);
    }
    else if (isdigit(current_ch))
    {
        token = new PascalNumberToken(source);
    }
    else if (current_ch == '\'')
    {
        token = new PascalStringToken(source);
    }
    else if (PascalToken::SPECIAL_SYMBOLS.find(string_ch)
                != PascalToken::SPECIAL_SYMBOLS.end())
    {
        token = new PascalSpecialSymbolToken(source);
    }
    else
    {
        token = new PascalErrorToken(source, INVALID_CHARACTER, string_ch);
        next_char();  // consume character
    }

    return token;
}

void PascalScanner::skip_white_space() throw (string)
{
    char current_ch = current_char();

    while (isspace(current_ch) || (current_ch == '{')) {

        // Start of a comment?
        if (current_ch == '{')
        {
            do
            {
                current_ch = next_char();  // consume comment characters
            } while ((current_ch != '}') &&
                     (current_ch != Source::END_OF_FILE));

            // Found closing '}'?
            if (current_ch == '}') {
                current_ch = next_char();  // consume the '}'
            }
        }

        // Not a comment.
        else current_ch = next_char();  // consume whitespace character
    }
}

}}} // namespace wci::frontend::pascal
