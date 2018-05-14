#pragma once

#include <string>

#include "../JavaToken.hpp"

namespace wci::frontend::java::tokens
{

    using namespace std;
    using namespace wci::frontend::java;

    class JavaStringToken : public JavaToken
    {
    public:

        /**
         * Constructor.
         * @param source the source from where to fetch the token's characters.
         * @throw a string message if an error occurred.
         */
        JavaStringToken(Source *source);

    protected:

        /**
         * Extract a Java string token from the source.
         * Override of wci::frontend::Token.
         * @throw a string message if an error occurred.
         */
        void extract();

    private:

        inline bool is_double_quote(char c) const;
        inline bool is_single_quote(char c) const;
        void replace_escape_sequences(char &c, string &str);
    };

} /// namespace wci::frontend::java::tokens
