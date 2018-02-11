#pragma once

#include <string>

#include "../JavaToken.hpp"

namespace wci::frontend::java::tokens
{

    using namespace std;
    using namespace wci::frontend::java;

    class JavaWordToken : public JavaToken
    {
    public:

        /**
         * Constructor.
         * @param source the source from where to fetch the token's characters.
         * @throw a string message if an error occurred.
         */
        JavaWordToken(Source *source);

    protected:

        /**
         * Extract a java word token from the source.
         * Override of wci::frontend::Token.
         * @throw a string message if an error occurred.
         */
        void extract();
    };

} /// namespace wci::frontend::java::tokens
