/**
 * <h1>PascalErrorHandler</h1>
 *
 * <p>Error handler Pascal syntax errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_PASCAL_PASCALERRORHANDLER_H_
#define WCI_FRONTEND_PASCAL_PASCALERRORHANDLER_H_

#include "../Token.h"
#include "../Parser.h"
#include "PascalError.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;
using namespace wci::frontend;

class PascalErrorHandler
{
public:
    /**
     * Getter.
     * @return the syntax error count.
     */
    int get_error_count() const;

    /**
     * Flag an error in the source line.
     * @param token the bad token.
     * @param errorCode the error code.
     * @param parser the parser.
     * @return the flagger string.
     */
    void flag(Token *token, PascalErrorCode error_code, Parser *parser);

    /**
     * Abort the translation.
     * @param errorCode the error code.
     * @param parser the parser.
     */
    void abort_translation(PascalErrorCode error_code, Parser *parser);

private:
    static int error_count;
    static const int MAX_ERRORS;
};

}}}  // namespace wci::frontend::pascal

#endif /* WCI_FRONTEND_PASCAL_PASCALERRORHANDLER_H_ */
