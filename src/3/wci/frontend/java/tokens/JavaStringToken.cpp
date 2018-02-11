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

    void JavaStringToken::extract()
    {
        string value_str = "";

        char current_ch = next_char();  // consume initial quote
        text += "'";

        // Get string characters.
        do
        {
            // Replace any whitespace character with a blank.
            if (isspace(current_ch)) current_ch = ' ';

            if ((current_ch != '\'') && (current_ch != EOF))
            {
                text += current_ch;
                value_str  += current_ch;
                current_ch = next_char();  // consume character
            }

            // Quote?  Each pair of adjacent quotes represents a single-quote.
            if (current_ch == '\'')
            {
                while ((current_ch == '\'') && (peek_char() == '\''))
                {
                    text += "''";
                    value_str  += current_ch;  // append single-quote
                    current_ch = next_char();  // consume pair of quotes
                    current_ch = next_char();
                }
            }
        } while ((current_ch != '\'') && (current_ch != Source::END_OF_FILE));

        if (current_ch == '\'')
        {
            next_char();  // consume final quote
            text += '\'';
            type = (TokenType) JavaTokenType::token_string;
            value = value_str;
        }
        else
        {
            type = (TokenType) JavaTokenType::token_error;
            value = (int) JavaErrorCode::UNEXPECTED_EOF;
        }
    }

} /// namespace wci::frontend::java::tokens
