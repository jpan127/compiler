#pragma once

#include <string>

#include "../JavaToken.hpp"

namespace wci::frontend::java::tokens
{

    using namespace std;
    using namespace wci::frontend::java;

    class JavaSpecialSymbolToken : public JavaToken
    {
    public:

        /**
         * Constructor.
         * @param source the source from where to fetch the token's characters.
         * @throw a string message if an error occurred.
         */
        JavaSpecialSymbolToken(Source *source);

    protected:

        /**
         * Extract a Java special symbol token from the source.
         * Override of wci::frontend::Token.
         * @throw a string message if an error occurred.
         */
        void extract();
    };

} /// namespace wci::frontend::java::tokens
