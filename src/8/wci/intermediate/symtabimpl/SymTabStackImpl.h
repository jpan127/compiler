/**
 * <h1>SymTabStack</h1>
 *
 * <p>An implementation of the symbol table stack.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_INTERMEDIATE_SYMTABIMPL_SYMTABSTACKIMPL_H_
#define WCI_INTERMEDIATE_SYMTABIMPL_SYMTABSTACKIMPL_H_

#include <vector>
#include "SymTabImpl.h"
#include "../SymTabStack.h"

namespace wci { namespace intermediate { namespace symtabimpl {

using namespace std;
using namespace wci::intermediate;

class SymTabStackImpl : public SymTabStack
{
public:
    /**
     * Constructor.
     */
    SymTabStackImpl();

    /**
     * Destructor.
     */
    virtual ~SymTabStackImpl();

    /**
     * Getter.
     * @return the current nesting level.
     */
    int get_current_nesting_level() const;

    /**
     * Return the local symbol table which is at the top of the stack.
     * Implementation of wci::intermediate::SymTabStack.
     * @return the local symbol table.
     */
    SymTab *get_local_symtab() const;

    /**
     * Create and enter a new entry into the local symbol table.
     * Implementation of wci::intermediate::SymTabStack.
     * @param name the name of the entry.
     * @return the new entry.
     */
    SymTabEntry *enter_local(const string name);

    /**
     * Look up an existing symbol table entry in the local symbol table.
     * Implementation of wci::intermediate::SymTabStack.
     * @param name the name of the entry.
     * @return the entry, or null if it does not exist.
     */
    SymTabEntry *lookup_local(const string name) const;

    /**
     * Look up an existing symbol table entry throughout the stack.
     * Implementation of wci::intermediate::SymTabStack.
     * @param name the name of the entry.
     * @return the entry, or null if it does not exist.
     */
    SymTabEntry *lookup(const string name) const;

private:
    int current_nesting_level;  // current scope nesting level
    vector<SymTab *> stack;
};

}}}  // namespace wci::intermediate::symtabimpl

#endif /* WCI_INTERMEDIATE_SYMTABIMPL_SYMTABSTACKIMPL_H_ */
