/**
 * <h1>RuntimeErrorHandler</h1>
 *
 * <p>Runtime error handler for the backend interpreter.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef RUNTIMEERRORHANDLER_H_
#define RUNTIMEERRORHANDLER_H_

#include "../Backend.h"
#include "RuntimeError.h"

namespace wci { namespace backend { namespace interpreter {

using namespace std;
using namespace wci::backend;

class RuntimeErrorHandler
{
public:
    /**
     * Getter
     * @return the count of runtime errors.
     */
    int get_error_count() const;

    /**
     * Flag a runtime error.
     * @param node the root node of the offending statement or expression.
     * @param errorCode the runtime error code.
     * @param backend the backend processor.
     */
    void flag(ICodeNode *node, RuntimeErrorCode error_code,
              Backend *backend);

private:
    static int error_count;
    static const int MAX_ERRORS;
};

using namespace std;

}}}  // wci::backend::interpreter

#endif /* RUNTIMEERRORHANDLER_H_ */
