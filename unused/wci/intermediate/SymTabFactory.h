/**
 * <h1>SymTabFactory</h1>
 *
 * <p>A factory for creating objects that implement the symbol table.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_INTERMEDIATE_SYMTABFACTORY_CPP_
#define WCI_INTERMEDIATE_SYMTABFACTORY_CPP_

#include "symtabimpl/SymTabImpl.h"
#include "symtabimpl/SymTabEntryImpl.h"
#include "symtabimpl/SymTabStackImpl.h"

namespace wci { namespace intermediate {

using namespace std;

class SymTabFactory
{
public:
    /**
     * Create and return a symbol table stack implementation.
     * @return the symbol table implementation.
     */
    static SymTabStack *create_symtab_stack();

    /**
     * Create and return a symbol table implementation.
     * @param nesting_level the nesting level.
     * @return the symbol table implementation.
     */
    static SymTab *create_symtab(int nesting_level);

    /**
     * Create and return a symbol table entry implementation.
     * @param name the identifier name.
     * @param symtab the symbol table that contains this entry.
     * @return the symbol table entry implementation.
     */
    static SymTabEntry *create_symtab_entry(string name, SymTab *symtab);
};

}} // namespace wci::intermediate

#endif /* WCI_INTERMEDIATE_SYMTABFACTORY_CPP_ */
