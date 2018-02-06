/**
 * <h1>CodeGenerator</h1>
 *
 * <p>The code generator for a compiler back end.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_BACKEND_COMPILER_CODEGENERATOR_H_
#define WCI_BACKEND_COMPILER_CODEGENERATOR_H_

#include "../Backend.h"

namespace wci { namespace backend { namespace compiler {

using namespace std;
using namespace wci::backend;

class CodeGenerator : public Backend
{
public:
    /**
     * Process the intermediate code and the symbol table created by the
     * parser to generate object code.
     * Implementation of wci::backend::Backend.
     * @param icode the intermediate code.
     * @param symtab the symbol table.
     * @throw a string message if an error occurred.
     */
    void process(ICode *icode, SymTab *symtab) throw (string);
};

}}} // namespace wci::backend::compiler

#endif /* WCI_BACKEND_COMPILER_CODEGENERATOR_H_ */
