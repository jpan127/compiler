/**
 * <h1>SymTabEntryImpl</h1>
 *
 * <p>An implementation of a symbol table entry.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_INTERMEDIATE_SYMTABIMPL_SYMTABENTRYIMPL_H_
#define WCI_INTERMEDIATE_SYMTABIMPL_SYMTABENTRYIMPL_H_

#include <string>
#include <map>
#include "../SymTab.h"
#include "../SymTabEntry.h"
#include "../../Object.h"

namespace wci { namespace intermediate { namespace symtabimpl {

using namespace std;
using namespace wci::intermediate;

/**
 * Symbol table entry keys.
 */
enum class SymTabKeyImpl
{
    // Constant.
    CONSTANT_VALUE,

    // Procedure or function.
    ROUTINE_CODE, ROUTINE_SYMTAB, ROUTINE_ICODE,
    ROUTINE_PARMS, ROUTINE_ROUTINES,

    // Variable or record field value.
    DATA_VALUE
};

constexpr SymTabKeyImpl CONSTANT_VALUE = SymTabKeyImpl::CONSTANT_VALUE;
constexpr SymTabKeyImpl ROUTINE_CODE = SymTabKeyImpl::ROUTINE_CODE;
constexpr SymTabKeyImpl ROUTINE_SYMTAB = SymTabKeyImpl::ROUTINE_SYMTAB;
constexpr SymTabKeyImpl ROUTINE_ICODE = SymTabKeyImpl::ROUTINE_ICODE;
constexpr SymTabKeyImpl ROUTINE_PARMS = SymTabKeyImpl::ROUTINE_PARMS;
constexpr SymTabKeyImpl ROUTINE_ROUTINES = SymTabKeyImpl::ROUTINE_ROUTINES;
constexpr SymTabKeyImpl DATA_VALUE = SymTabKeyImpl::DATA_VALUE;

class SymTabEntryImpl : public SymTabEntry
{
public:
    /**
     * Constructor.
     * @param name the name of the entry.
     * @param symTab the symbol table that contains this entry.
     */
    SymTabEntryImpl(const string name, SymTab *symtab);

    /**
     * Destructor.
     */
    virtual ~SymTabEntryImpl();

    /**
     * Getter.
     * @return the name of the entry.
     */
    string get_name() const;

    /**
     * Getter.
     * @return the symbol table that contains this entry.
     */
    SymTab *get_symtab() const;

    /**
     * Append a source line number to the entry.
     * @param line_number the line number to append.
     */
    void append_line_number(const int line_number);

    /**
     * Getter.
     * @return the list of source line numbers.
     */
    vector<int> get_line_numbers();

    /**
     * Set an attribute of the entry.
     * Implementation of wci::intermediate::SymTabEntry.
     * @param key the attribute key.
     * @param value the attribute value.
     */
    void set_attribute(const SymTabKey key, Object value);

    /**
     * Get the value of an attribute of the entry.
     * Implementation of wci::intermediate::SymTabEntry.
     * @param key the attribute key.
     * @return the attribute value.
     */
    Object get_attribute(const SymTabKey key);

private:
    string name;               // entry name
    SymTab *symtab;            // parent symbol table
    vector<int> line_numbers;  // source line numbers
    map<SymTabKey, Object> contents;
};

}}}  // namespace wci::intermediate::symtabimpl

#endif /* WCI_INTERMEDIATE_SYMTABIMPL_SYMTABENTRYIMPL_H_ */
