#include "JavaErrorToken.hpp"

#include "../../Token.h"
#include "../JavaToken.hpp"

namespace wci::frontend::java::tokens
{

    using namespace std;
    using namespace wci::frontend::java;

    JavaErrorToken::JavaErrorToken(Source *source, JavaErrorCode error_code, string token_text) : JavaToken(source)
    {
        type  = (TokenType) JavaTokenType::token_error;
        text  = token_text;
        value = (int) error_code;
    }

    void JavaErrorToken::extract()
    {
        // do nothing
    }

} /// namespace wci::frontend::java::tokens
