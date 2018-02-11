#include "JavaWordToken.hpp"

#include <iostream>
#include <string>
#include <map>

#include "../JavaError.hpp"

namespace wci::frontend::java::tokens
{
    using namespace std;
    using namespace wci::frontend;
    using namespace wci::frontend::java;

    JavaWordToken::JavaWordToken(Source *source) : JavaToken(source)
    {
        extract();
    }

    /**
     * Extract a Java word token from the source.
     * @throws Exception if an error occurred.
     */
    void JavaWordToken::extract()
    {
        char current_ch = current_char();

        // Get the word characters (letter or digit). The scanner has
        // already determined that the first character is a letter.
        while (isalnum(current_ch))
        {
            text += current_ch;
            current_ch = next_char();  // consume character
        }

        if (!isalnum(current_ch))
        {
            put_back();
        }
        
        // Is it a reserved word or an identifier?
        string token = "token_" + text;
        if (JavaToken::RESERVED_WORDS.find(token) != JavaToken::RESERVED_WORDS.end())
        {
            // Reserved word.
            type = (TokenType) JavaToken::RESERVED_WORDS[token];
            value = token;
        }
        else
        {
            // Identifier.
            type = (TokenType) JavaTokenType::token_identifier;
        }
    }

} /// namespace wci::frontend::java::tokens
