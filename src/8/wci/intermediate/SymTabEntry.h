/**
 * <h1>SymTabEntry</h1>
 *
 * <p>The interface for a symbol table entry.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_INTERMEDIATE_SYMTABENTRY_H_
#define WCI_INTERMEDIATE_SYMTABENTRY_H_

#include <vector>
#include <string>
#include "SymTab.h"
#include "../Object.h"

namespace wci { namespace intermediate {

using namespace std;
using namespace wci;

/**
 * Symbol table entry keys.
 */
enum class SymTabKey
{
    // to be "subclassed" by implementation-specific symbol table keys
};

class SymTabEntry
{
public:
    /**
     * Destructor.
     */
    virtual ~SymTabEntry() {}

    /**
     * Getter.
     * @return the name of the entry.
     */
    virtual string get_name() const = 0;

    /**
     * Getter.
     * @return the symbol table that contains this entry.
     */
    virtual SymTab *get_symtab() const = 0;

    /**
     * Append a source line number to the entry.
     * @param line_number the line number to append.
     */
    virtual void append_line_number(const int line_number) = 0;

    /**
     * Getter.
     * @return the list of source line numbers.
     */
    virtual vector<int> get_line_numbers() = 0;

    /**
     * Set an attribute of the entry.
     * To be defined by an implementation subclass.
     * @param key the attribute key.
     * @param value the attribute value.
     */
    virtual void set_attribute(const SymTabKey key, Object value) = 0;

    /**
     * Get the value of an attribute of the entry.
     * To be defined by an implementation subclass.
     * @param key the attribute key.
     * @return the attribute value.
     */
    virtual Object get_attribute(const SymTabKey key) = 0;
};

}} // namespace wci::intermediate

#endif /* WCI_INTERMEDIATE_SYMTABENTRY_H_ */
