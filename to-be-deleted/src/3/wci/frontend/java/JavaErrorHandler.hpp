#pragma once

#include "../Token.h"
#include "../Parser.h"
#include "JavaError.hpp"

namespace wci::frontend::java 
{

    using namespace std;
    using namespace wci::frontend;

    class JavaErrorHandler
    {
    public:
        /**
         *  Getter.
         *  @return the syntax error count.
         */
        int get_error_count() const;

        /**
         *  Flag an error in the source line.
         *  @param token the bad token.
         *  @param errorCode the error code.
         *  @param parser the parser.
         *  @return the flagger string.
         */
        void flag(Token *token, JavaErrorCode error_code, Parser *parser);

        /**
         * Abort the translation.
         * @param errorCode the error code.
         * @param parser the parser.
         */
        void abort_translation(JavaErrorCode error_code, Parser *parser);

    private:
        static int error_count;
        static const int MAX_ERRORS;
    };

} /// namespace wci::frontend::java
