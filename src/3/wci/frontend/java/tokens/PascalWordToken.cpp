/**
 * <h1>PascalWordToken</h1>
 *
 * <p> Pascal word tokens (identifiers and reserved words).</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <iostream>
#include <string>
#include <map>
#include "PascalWordToken.h"
#include "../PascalError.h"

namespace wci { namespace frontend { namespace pascal { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;

PascalWordToken::PascalWordToken(Source *source) throw (string)
    : PascalToken(source)
{
    extract();
}

/**
 * Extract a Pascal word token from the source.
 * @throws Exception if an error occurred.
 */
void PascalWordToken::extract() throw (string)
{
    char current_ch = current_char();

    // Get the word characters (letter or digit). The scanner has
    // already determined that the first character is a letter.
    while (isalnum(current_ch))
    {
        text += current_ch;
        current_ch = next_char();  // consume character
    }

    // Is it a reserved word or an identifier?
    string upper_case = to_upper(text);
    if (PascalToken::RESERVED_WORDS.find(upper_case)
            != PascalToken::RESERVED_WORDS.end())
    {
        // Reserved word.
        type = (TokenType) PascalToken::RESERVED_WORDS[upper_case];
        value = upper_case;
    }
    else
    {
        // Identifier.
        type = (TokenType) PT_IDENTIFIER;
    }
}

}}}}  // namespace wci::frontend::pascal::tokens
