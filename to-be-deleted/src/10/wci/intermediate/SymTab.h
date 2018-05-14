/**
 * <h1>SymTab</h1>
 *
 * <p>The framework interface that represents the symbol table.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_INTERMEDIATE_SYMTAB_H_
#define WCI_INTERMEDIATE_SYMTAB_H_

#include <string>
#include <vector>

namespace wci { namespace intermediate {

using namespace std;

class SymTabEntry;  // forward declaration

class SymTab
{
public:
    /**
     * Destructor.
     */
    virtual ~SymTab() {}

    /**
     * Getter.
     * @return the scope nesting level of this entry.
     */
    virtual int get_nesting_level() const = 0;

    /**
     * Create and enter a new entry into the symbol table.
     * To be defined by implementation subclasses.
     * @param name the name of the entry.
     * @return the new entry.
     */
    virtual SymTabEntry *enter(const string name) = 0;

    /**
     * Look up an existing symbol table entry.
     * To be defined by implementation subclasses.
     * @param name the name of the entry.
     * @return the entry, or null if it does not exist.
     */
    virtual SymTabEntry *lookup(const string name) = 0;

    /**
     * Return a vector of entries sorted by key.
     * To be defined by implementation subclasses.
     * @return a list of symbol table entries sorted by name.
     */
    virtual vector<SymTabEntry *> sorted_entries() = 0;
};

}} // namespace wci::intermediate

#endif /* WCI_INTERMEDIATE_SYMTAB_H_ */
