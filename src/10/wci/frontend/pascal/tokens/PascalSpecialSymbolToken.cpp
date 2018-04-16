/**
 * <h1>PascalSpecialSymbolToken</h1>
 *
 * <p> Pascal special symbol tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "PascalSpecialSymbolToken.h"
#include "../PascalError.h"

namespace wci { namespace frontend { namespace pascal { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;

PascalSpecialSymbolToken::PascalSpecialSymbolToken(Source *source) throw (string)
    : PascalToken(source)
{
    extract();
}

void PascalSpecialSymbolToken::extract() throw (string)
{
    char current_ch = current_char();
    bool good_symbol = true;

    text = current_ch;

    switch (current_ch)
    {
        // Single-character special symbols.
        case '+':  case '-':  case '*':  case '/':  case ',':
        case ';':  case '\'': case '=':  case '(':  case ')':
        case '[':  case ']':  case '{':  case '}':  case '^':
        {
            next_char();  // consume character
            break;
        }

        // : or :=
        case ':':
        {
            current_ch = next_char();  // consume ':';

            if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }

            break;
        }

        // < or <= or <>
        case '<':
        {
            current_ch = next_char();  // consume '<';

            if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }
            else if (current_ch == '>')
            {
                text += current_ch;
                next_char();  // consume '>'
            }

            break;
        }

        // > or >=
        case '>':
        {
            current_ch = next_char();  // consume '>';

            if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }

            break;
        }

        // . or ..
        case '.':
        {
            current_ch = next_char();  // consume '.';

            if (current_ch == '.')
            {
                text += current_ch;
                next_char();  // consume '.'
            }

            break;
        }

        default:
        {
            next_char();  // consume bad character
            type = (TokenType) (PT_ERROR);
            value = (int) INVALID_CHARACTER;
            good_symbol = false;
        }
    }

    // Set the type if it wasn't an error.
    if (good_symbol) {
        type = (TokenType) (PascalToken::SPECIAL_SYMBOLS[text]);
    }
}

}}}}  // namespace wci::frontend::pascal::tokens
