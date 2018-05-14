#pragma once

#include <string>

#include "../JavaError.hpp"
#include "../JavaToken.hpp"

namespace wci::frontend::java::tokens
{

    using namespace std;
    using namespace wci::frontend::java;

    class JavaErrorToken : public JavaToken
    {
    public:

        /**
         * Constructor.
         * @param source the source from where to fetch subsequent characters.
         * @param errorCode the error code.
         * @param tokenText the text of the erroneous token.
         * @throw a string message if an error occurred.
         */
        JavaErrorToken(Source *source, JavaErrorCode error_code, string token_text);

    protected:

        /**
         * Do nothing.  Do not consume any source characters.
         * Override of wci::frontend::Token.
         * @throw a string message if an error occurred.
         */
        void extract();
    };

} /// namespace wci::frontend::java::tokens
