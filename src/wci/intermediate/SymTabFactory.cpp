/**
 * <h1>SymTabFactory</h1>
 *
 * <p>A factory for creating objects that implement the symbol table.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "SymTabFactory.h"
#include "SymTab.h"
#include "SymTabEntry.h"
#include "SymTabStack.h"
#include "symtabimpl/SymTabImpl.h"
#include "symtabimpl/SymTabEntryImpl.h"
#include "symtabimpl/SymTabStackImpl.h"

namespace wci { namespace intermediate {

using namespace std;
using namespace wci::intermediate::symtabimpl;

SymTabStack *SymTabFactory::create_symtab_stack()
{
    return new SymTabStackImpl();
}

SymTab *SymTabFactory::create_symtab(int nesting_level)
{
    return new SymTabImpl(nesting_level);
}

SymTabEntry *SymTabFactory::create_symtab_entry(string name, SymTab *symtab)
{
    return new SymTabEntryImpl(name, symtab);
}

}} // namespace wci::intermediate
