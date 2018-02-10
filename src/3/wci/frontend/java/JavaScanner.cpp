#include "JavaScanner.hpp"

/// Standard libraries
#include <iostream>
/// wci::frontend libraries
#include "../Source.h"
/// wci::frontend::java libraries
#include "JavaScanner.h"
#include "JavaToken.h"
#include "JavaError.h"
/// wci::frontend::java::tokens libraries
#include "tokens/JavaWordToken.h"
#include "tokens/JavaNumberToken.h"
#include "tokens/JavaStringToken.h"
#include "tokens/JavaSpecialSymbolToken.h"
#include "tokens/JavaErrorToken.h"



namespace wci::frontend::java
{

JavaScanner::JavaScanner(Source *source) : Source(source)
{
    /* Empty */
}

Token * JavaScanner::get_next_token()
{
    ignore_all_whitespaces();

    Token * token = NULL;
    char c = current_char();
    string str = c;

    if (c == Source::END_OF_FILE)       token = nullptr;
    else if (isalpha(c))                token = new JavaWordToken(source);
    else if (isdigit(c))                token = new JavaNumberToken(source);
    else if (c == '\'' || c == '\"')    token = new JavaStringToken(source);
    else if (JavaToken::SPECIAL_SYMBOLS.find(str) != JavaToken::SPECIAL_SYMBOLS.end())
                                        token = new JavaSpecialSymbolToken(source);
    else
    {
        token = new JavaErrorToken(source, INVALID_CHARACTER, str);
        next_char();
    }

    return token;
}

void JavaScanner::ignore_all_whitespaces()
{
    // Syntactical symbols
    const char slash    = '/';
    const char asterisk = '*';
    const char new_line = '\n';

    /**
     *  @note:
     *  If the scanner encounters a slash, but it is not proceeded by another slash or asterisk,
     *  then there is most likely a syntax issue.  The slash should have been preceeded by a left hand operator.
     */

    scanner_state_E state = ignored_characters;
    char c = 0;

    while (isspace(c) || c == slash)
    {
        c = next_char();

        // Finding the first slash
        if (c == slash)
        {
            c = next_char();

            // Finds a second slash, so it is a single line comment
            if (c == slash)
            {
                // Ignore all characters of the current line
                while (c != new_line)
                {
                    next_char();
                }
            }
            // Finds an asterisk, so it is a multi line comment
            else if (c == asterisk)
            {
                // Search for next asterisk that is proceeded by a slash
                while (1)
                {
                    c = next_char();

                    // If parsing the comment and finds an asterisk
                    if (state == ignoring_characters && c == asterisk)
                    {
                        state = ending_asterisk;
                    }
                    // If just found an asterisk and finds another slash
                    else if (state == ending_asterisk && c == slash)
                    {
                        break;
                    }
                    // If just found an asterisk, and ending slash not found
                    else if (state == ending_asterisk && c != slash)
                    {
                        state = ignoring_characters;
                    }
                }
            }
        }
    }
}

} /// wci::frontend::java