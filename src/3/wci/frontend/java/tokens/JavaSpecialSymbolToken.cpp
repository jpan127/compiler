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
        char next_ch = 0;
        bool good_symbol = true;

        text = current_ch;

        switch (current_ch)
        {
            // Single-character special symbols.
            case '\'':  // No break, escaped characters dont read in the slash, i think
            case '\"':  // No break, escaped characters dont read in the slash, i think
            case '~':   // No break
            case '@':   // No break
            case ';':   // No break
            case '?':   // No break
            case ',':   // No break

            case '(':   // No break
            case ')':   // No break
            case '[':   // No break
            case ']':   // No break
            case '{':   // No break
            case '}':   break;

            // Characters only itself and with an equals sign
            case '*':   if ('=' == peek_char()) { text += next_char(); }    break;
            case '=':   if ('=' == peek_char()) { text += next_char(); }    break;
            case '%':   if ('=' == peek_char()) { text += next_char(); }    break;
            case '^':   if ('=' == peek_char()) { text += next_char(); }    break;
            case '!':   if ('=' == peek_char()) { text += next_char(); }    break;

            case ':':
                // This is not pascal!
                if (peek_char() == '=')
                {
                    next_char();  // consume bad character
                    type = (TokenType) (JavaTokenType::token_error);
                    value = (int) JavaErrorCode::INVALID_CHARACTER;
                    good_symbol = false;
                    cout << "--------------------------------------" << endl;
                    cout << "Operator := found, this is not pascal!" << endl;
                    cout << "--------------------------------------" << endl;
                    break;
                }
                break;

            case '.':
                // This is not pascal!
                if (peek_char() == '.')
                {
                    next_char();  // consume bad character
                    type = (TokenType) (JavaTokenType::token_error);
                    value = (int) JavaErrorCode::INVALID_CHARACTER;
                    good_symbol = false;
                    cout << "--------------------------------------" << endl;
                    cout << "Operator .. found, this is not pascal!" << endl;
                    cout << "--------------------------------------" << endl;
                    break;
                }
                break;

            // Characters with more than 2 variations
            case '&':
                next_ch = peek_char();
                switch (next_ch)
                {
                    case '&' :                                      ///< '&'
                    case '=' :                                      ///< '&='
                        text += next_ch;
                        next_char(); 
                        break;
                    default  :
                        break;
                }
                break;

            case '<':
                next_ch = peek_char();
                switch (next_ch)
                {
                    case '=' :                                      ///< '<=' 
                        text += next_ch;
                        next_char();
                        break;
                    case '<' :                                      ///< '<<'
                        text += next_ch;
                        next_char();
                        next_ch = peek_char();
                        if ('=' == next_ch)                         ///< '<<='
                        {
                            next_char();
                            text += next_ch;
                        }
                        break;
                    case '>' :
                        next_char();  // consume bad character
                        type = (TokenType) (JavaTokenType::token_error);
                        value = (int) JavaErrorCode::INVALID_CHARACTER;
                        good_symbol = false;
                        cout << "--------------------------------------" << endl;
                        cout << "Operator <> found, this is not pascal!" << endl;
                        cout << "--------------------------------------" << endl;
                        break;
                    default  :
                         break;
                }
                break;

            case '>':
                next_ch = peek_char();
                switch (next_ch)
                {
                    case '=' :                                      ///< '>='
                        text += next_ch;
                        next_char();
                        break;
                    case '>' :                                      ///< '>>'
                        text += next_ch;
                        next_char();
                        next_ch = peek_char();
                        if ('=' == next_ch)                         ///< '>>='
                        {
                            next_char();
                            text += next_ch;
                        }
                        break;
                    default  :
                        break;
                }
                break;

            case '+':
                next_ch = peek_char();
                switch (next_ch)
                {
                    case '+' :                                      ///< '+'
                    case '=' :                                      ///< '+='  
                        text += next_ch;
                        next_char();
                        break;
                    default  :
                        break;
                }
                break;

            case '-':
                next_ch = peek_char();
                switch (next_ch)
                {
                    case '-' :                                      ///< '--'
                    case '=' :                                      ///< '-='
                        text += next_ch;
                        next_char();
                        break;
                    default  :
                        break;
                }
                break;

            case '|':
                next_ch = peek_char();
                switch (next_ch)
                {
                    case '|' :                                      ///< '||'
                    case '=' :                                      ///< '|='
                        text += next_ch;
                        next_char();
                        break;
                    default  :
                        break;
                }
                break;
            
            case '/':
                next_ch = peek_char();
                switch (next_ch)
                {
                    case '/' :                                      ///< '//'
                    case '*' :                                      ///< '/*'
                    case '=' :                                      ///< '/='
                        text += next_ch;
                        next_char();
                        break;
                    default  :
                        break;
                }
                break;
            
            default:
            {
                next_char();  // consume bad character
                type = (TokenType) (JavaTokenType::token_error);
                value = (int) JavaErrorCode::INVALID_CHARACTER;
                good_symbol = false;
            }
        }

        // Set the type if it wasn't an error.
        if (good_symbol) 
        {
            type = (TokenType) (JavaToken::SPECIAL_SYMBOLS[text]);
        }
    }

} /// namespace wci::frontend::java::tokens
