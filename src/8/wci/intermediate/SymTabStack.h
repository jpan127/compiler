/**
 * <h1>SymTabStack</h1>
 *
 * <p>The interface for the symbol table stack.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_INTERMEDIATE_SYMTABSTACK_H_
#define WCI_INTERMEDIATE_SYMTABSTACK_H_

#include <vector>
#include "SymTab.h"

namespace wci { namespace intermediate {

using namespace std;

class SymTabStack
{
public:
    /**
     * Destructor.
     */
    virtual ~SymTabStack() {}

    /**
     * Getter.
     * @return the current nesting level.
     */
    virtual int get_current_nesting_level() const = 0;

    /**
     * Return the local symbol table which is at the top of the stack.
     * To be defined by implementation subclasses.
     * @return the local symbol table.
     */
    virtual SymTab *get_local_symtab() const = 0;

    /**
     * Create and enter a new entry into the local symbol table.
     * To be defined by implementation subclasses.
     * @param name the name of the entry.
     * @return the new entry.
     */
    virtual SymTabEntry *enter_local(const string name) = 0;

    /**
     * Look up an existing symbol table entry in the local symbol table.
     * To be defined by implementation subclasses.
     * @param name the name of the entry.
     * @return the entry, or null if it does not exist.
     */
    virtual SymTabEntry *lookup_local(const string name) const = 0;

    /**
     * Look up an existing symbol table entry throughout the stack.
     * To be defined by implementation subclasses.
     * @param name the name of the entry.
     * @return the entry, or null if it does not exist.
     */
    virtual SymTabEntry *lookup(const string name) const = 0;
};

}} // namespace wci::intermediate

#endif /* WCI_INTERMEDIATE_SYMTABSTACK_H_ */
