#include "JavaSpecialSymbolToken.hpp"

#include <string>

#include "../JavaError.hpp"

namespace wci::frontend::java::tokens
{

    using namespace std;
    using namespace wci::frontend;
    using namespace wci::frontend::java;

    JavaSpecialSymbolToken::JavaSpecialSymbolToken(Source *source) : JavaToken(source)
    {
        extract();
    }

    void JavaSpecialSymbolToken::extract()
    {
        char current_ch = current_char();
        bool good_symbol = true;

        text = current_ch;

        switch (current_ch)
        {
            // Single-character special symbols.
            case '~':   // No break
            case '!':   // No break
            case '@':   // No break
            case '%':   // No break
            case '^':   // No break
            case '&':   // No break
            case '*':   // No break
            case '-':   // No break
            case '+':   // No break
            case '=':   // No break
            case '|':   // No break
            case '/':   // No break
            case ':':   // No break
            case ';':   // No break
            case '?':   // No break
            case '<':   // No break
            case '>':   // No break
            case '.':   // No break
            case ',':   // No break

            case '\'':  // No break
            case '\"':  // No break

            case '(':   // No break
            case ')':   // No break
            case '[':   // No break
            case '[':   // No break
            case '{':   // No break
            case '}':   // No break
            
            case '++':  // No break
            case '--':  // No break
            case '<<':  // No break
            case '>>':  // No break
            case '<=':  // No break
            case '>=':  // No break
            case '+=':  // No break
            case '-=':  // No break
            case '*=':  // No break
            case '/=':  // No break
            case '==':  // No break
            case '|=':  // No break
            case '%=':  // No break
            case '&=':  // No break
            case '^=':  // No break
            case '!=':  // No break
            case '<<=': // No break
            case '>>=': // No break
            case '||':  // No break
            case '&&':  // No break
            case '//':  // No break
            case '/*':  // No break
            case '*/':  // No break

            // < or <= or <>
            case '<':
            {
                current_ch = next_char();  // consume '<';

                if (current_ch == '=')
                {
                    text += current_ch;
                    next_char();  // consume '='
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

            default:
            {
                next_char();  // consume bad character
                type = (TokenType) (JavaTokenType::token_error);
                value = (int) JavaErrorCode::INVALID_CHARACTER;
                good_symbol = false;
            }
        }

        // Set the type if it wasn't an error.
        if (good_symbol) {
            type = (TokenType) (JavaToken::SPECIAL_SYMBOLS[text]);
        }
    }

} /// namespace wci::frontend::java::tokens
