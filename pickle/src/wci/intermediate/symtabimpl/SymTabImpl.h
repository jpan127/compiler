/**
 * <h1>SymTabImpl</h1>
 *
 * <p>An implementation of the symbol table.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef SYMTABIMPL_H_
#define SYMTABIMPL_H_

#include <string>
#include <map>
#include "../SymTab.h"
#include "SymTabEntryImpl.h"

namespace wci { namespace intermediate { namespace symtabimpl {

using namespace std;
using namespace wci::intermediate;

class SymTabImpl : public SymTab
{
public:
    /**
     * Constructor.
     * @param nesting_level the scope nesting level of this table
     */
    SymTabImpl(const int nesting_level);

    /**
     * Destructor.
     */
    virtual ~SymTabImpl();

    /**
     * Getter.
     * @return the scope nesting level of this entry.
     */
    int get_nesting_level() const;

    /**
     * Create and enter a new entry into the symbol table.
     * To be defined by implementation subclasses.
     * Implementation of wci::intermediate::SymTab.
     * @param name the name of the entry.
     * @return the new entry.
     */
    SymTabEntry *enter(const string name);

    /**
     * Look up an existing symbol table entry.
     * To be defined by implementation subclasses.
     * Implementation of wci::intermediate::SymTab.
     * @param name the name of the entry.
     * @return the entry, or null if it does not exist.
     */
    SymTabEntry *lookup(const string name);

    /**
     * Return a vector of entries sorted by key.
     * Implementation of wci::intermediate::SymTab.
     * @return a list of symbol table entries sorted by name.
     */
    vector<SymTabEntry *> sorted_entries();

private:
    int nesting_level;  // scope nesting level
    map<string, SymTabEntryImpl *> contents;
};

}}}  // namespace wci::intermediate::symtabimpl

#endif /* SYMTABIMPL_H_ */
