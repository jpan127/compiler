#include "JavaScanner.hpp"

/// Standard libraries
#include <iostream>
/// wci::frontend libraries
#include "../Source.h"
/// wci::frontend::java libraries
#include "JavaScanner.hpp"
#include "JavaToken.hpp"
#include "JavaError.hpp"
/// wci::frontend::java::tokens libraries
#include "tokens/JavaWordToken.hpp"
#include "tokens/JavaNumberToken.hpp"
#include "tokens/JavaStringToken.hpp"
#include "tokens/JavaSpecialSymbolToken.hpp"
#include "tokens/JavaErrorToken.hpp"



namespace wci::frontend::java
{

    using namespace std;
    using namespace wci::frontend;
    using namespace wci::frontend::java::tokens;

    JavaScanner::JavaScanner(Source *source) : Scanner(source)
    {
        JavaToken::initialize();
    }

    Token * JavaScanner::extract_token()
    {
        find_next_token();

        Token * token = NULL;
        char c = current_char();
        string str;
        str += c;

        if (c == Source::END_OF_FILE)                       token = nullptr;
        else if (isalpha(c))                                token = new JavaWordToken(source);
        else if (isdigit(c))                                token = new JavaNumberToken(source);
        else if (c == '\'' || c == '\"')                    token = new JavaStringToken(source);
        else if (JavaToken::SPECIAL_SYMBOLS.count(str) > 0) token = new JavaSpecialSymbolToken(source);
        else                                                token = new JavaErrorToken(source, JavaErrorCode::INVALID_CHARACTER, str);

        return token;
    }

    void JavaScanner::ignore_all_whitespaces(char &c)
    {
        const char eof = 0;
        while (isspace(c) && c != eof)
        {
            c = next_char();
        }
    }

    void JavaScanner::find_next_token()
    {
        // Syntactical symbols
        const char slash    = '/';
        const char asterisk = '*';
        const char new_line = '\n';
        const char eof      = 0;

        /**
         *  @note:
         *  If the scanner encounters a slash, but it is not proceeded by another slash or asterisk,
         *  then there is most likely a syntax issue.  The slash should have been preceeded by a left hand operator.
         */

        scanner_state_E state = scanner_state_E::ignoring_characters;
        char c = ' ';

        while (c != eof)
        {
            // Read all preceeding spaces
            ignore_all_whitespaces(c);

            // Finding the first slash
            if (c == slash)
            {
                c = next_char();

                // Finds a second slash, so it is a single line comment
                if (c == slash)
                {
                    // Ignore all characters of the current line
                    while (c != new_line && c != eof)
                    {
                        c = next_char();
                    }

                    // Read all subsequent spaces
                    c = next_char();
                    ignore_all_whitespaces(c);

                }
                // Finds an asterisk, so it is a multi line comment
                else if (c == asterisk)
                {
                    // Search for next asterisk that is proceeded by a slash
                    while (c != eof)
                    {
                        c = next_char();

                        // If parsing the comment and finds an asterisk
                        if (state == scanner_state_E::ignoring_characters && c == asterisk)
                        {
                            state = scanner_state_E::ending_asterisk;
                        }
                        // If just found an asterisk and finds another slash
                        else if (state == scanner_state_E::ending_asterisk && c == slash)
                        {
                            break;
                        }
                        // If just found an asterisk, and ending slash not found
                        else if (state == scanner_state_E::ending_asterisk && c != slash)
                        {
                            state = scanner_state_E::ignoring_characters;
                        }
                    }

                    // Read all subsequent spaces
                    c = next_char();
                    ignore_all_whitespaces(c);
                }
                else
                {
                    put_back();
                    break;
                }
            }
            // If the next character is not a space or a slash then it must be a token
            else if (!isspace(c))
            {
                break;
            }
        }
    }

} /// wci::frontend::java