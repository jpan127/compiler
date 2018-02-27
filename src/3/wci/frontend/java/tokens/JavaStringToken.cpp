#include "JavaStringToken.hpp"

#include <string>

#include "../JavaError.hpp"

namespace wci::frontend::java::tokens
{

    using namespace std;
    using namespace wci::frontend;
    using namespace wci::frontend::java;

    JavaStringToken::JavaStringToken(Source *source) : JavaToken(source)
    {
        extract();
    }

    inline bool JavaStringToken::is_double_quote(char c) const
    {
        const char double_quote = '"';

        return (double_quote == c);
    }

    inline bool JavaStringToken::is_single_quote(char c) const
    {
        const char single_quote = '\'';

        return (single_quote == c);
    }

    void JavaStringToken::replace_escape_sequences(char &c, string &str)
    {
        static const map <string, string> escape_sequences =
        {
            { "\n", "\n"   },
            { "\t", "    " },
            { "\'", "'"    },
            { "\"", "\""   },
            { "\\", "\\"   },
        };

        c = next_char();

        // @note : Using a string = '\' + 'n' does not equal "\n" so cannot do a straight lookup
        switch (c)
        {
            case 'n'  :   text += escape_sequences.at("\n");   str += escape_sequences.at("\n");   break;
            case 't'  :   text += escape_sequences.at("\t");   str += escape_sequences.at("\t");   break;
            case '\'' :   text += escape_sequences.at("\'");   str += escape_sequences.at("\'");   break;
            case '\"' :   text += escape_sequences.at("\"");   str += escape_sequences.at("\"");   break;
            case '\\' :   text += escape_sequences.at("\\");   str += escape_sequences.at("\\");   break;
            default   :                                                                            break;
        }
    }

    void JavaStringToken::extract()
    {
        /**
         *  1. Current char should either be a single quote or a double quote, otherwise parsing or syntax error
         *  2. If single quote, get character or get escaped character
         *  3. If double quote, parse the entire string, until before the closing quote
         *  4. Consume the closing quote and exit
         */

        const char escape = '\\';
        const char eof    = 0;
     
        string value_str;
        char current_ch = current_char();
        bool exit_condition = false;

        if (is_single_quote(current_ch))
        {
            if (peek_char() == escape)
            {
                next_char();
                replace_escape_sequences(current_ch, value_str);
            }
            else
            {
                current_ch = next_char();
                text      += current_ch;
                value_str += current_ch;
            }
            next_char();
        }
        else if (is_double_quote(current_ch))
        {
            do
            {
                current_ch = next_char();

                // EOF, exit
                if (eof == current_ch)
                {
                    break;
                }
                // Replace any whitespace character with a blank.
                else if (isspace(current_ch))
                {
                    text       += ' ';
                    value_str  += ' ';
                }
                // Replace any escape sequences
                else if (escape == current_ch)
                {
                    replace_escape_sequences(current_ch, value_str);
                    // Skip exit condition check
                    continue;
                }
                // Normal character
                else if (!is_double_quote(current_ch))
                {
                    text       += current_ch;
                    value_str  += current_ch;
                }

                // The condition to exit loop is if next character is closing quote AND current character is not a slash
                // Because if current character is a slash then the next quote character is escaped
                exit_condition = (is_double_quote(current_char()));

            } while ((!exit_condition) && (current_ch != eof));
        }
        else
        {
            type  = (TokenType) JavaTokenType::token_error;
            value = (int) JavaErrorCode::INVALID_STRING;
            return;
        }

        if (is_double_quote(current_char()) || is_single_quote(current_char()))
        {
            // Throw away closing single or double quote
            next_char();
            type   = (TokenType) JavaTokenType::token_string;
            value  = value_str;
        }
        else
        {
cout << "******************************************* eof " << peek_char() << endl;
            type = (TokenType) JavaTokenType::token_error;
            value = (int) JavaErrorCode::UNEXPECTED_EOS;
        }
    }

} /// namespace wci::frontend::java::tokens
