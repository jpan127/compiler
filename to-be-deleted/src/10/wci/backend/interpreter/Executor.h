/**
 * <h1>Executor</h1>
 *
 * <p>The executor for an interpreter back end.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_BACKEND_INTERPRETER_EXECUTOR_H_
#define WCI_BACKEND_INTERPRETER_EXECUTOR_H_

#include "../Backend.h"
#include "RuntimeErrorHandler.h"

namespace wci { namespace backend { namespace interpreter {

using namespace std;
using namespace wci::backend;

class Executor : public Backend
{
public:
    /**
     * Constructor.
     */
    Executor();

    /**
     * Process the intermediate code and the symbol table created by the
     * parser to execute the program.
     * Implementation of wci::backend::Backend.
     * @param icode the intermediate code.
     * @param symtab_stack the symbol table stack.
     * @throw a string message if an error occurred.
     */
    void process(ICode *icode, SymTabStack *symtab_stack) throw (string);

protected:
    static RuntimeErrorHandler error_handler;
    static int execution_count;
};

}}} // namespace wci::backend::compiler

#endif /* WCI_BACKEND_INTERPRETER_EXECUTOR_H_ */
