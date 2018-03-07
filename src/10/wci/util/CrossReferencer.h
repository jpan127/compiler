/**
 * <h1>CrossReferencer</h1>
 *
 * <p>Generate a cross-reference listing.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_UTIL_CROSSREFERENCER_H_
#define WCI_UTIL_CROSSREFERENCER_H_

#include <string>
#include <vector>
#include "../intermediate/SymTab.h"
#include "../intermediate/SymTabStack.h"
#include "../intermediate/TypeSpec.h"
#include "../Object.h"

namespace wci { namespace util {

using namespace std;
using namespace wci::intermediate;

class CrossReferencer
{
public:
    /**
     * Print the cross-reference table.
     * @param symtab_stack the symbol table stack.
     */
    void print(const SymTabStack *symtab_stack) const;

private:
    static const int NAME_WIDTH;

    static const string NAME_FORMAT;
    static const string NUMBERS_LABEL;
    static const string NUMBERS_UNDERLINE;
    static const string NUMBER_FORMAT;
    static const string ENUM_CONST_FORMAT;

    static const int LABEL_WIDTH;
    static const int INDENT_WIDTH;

    static const string INDENT;

    /**
     * Print a cross-reference table for a routine.
     * @param routine_id the routine identifier's symbol table entry.
     */
    void print_routine(SymTabEntry *routine_id) const;

    /**
     * Print column headings.
     */
    void print_column_headings() const;

    /**
     * Print the entries in a symbol table.
     * @param SymTab the symbol table.
     * @param record_types the list to fill with RECORD type specifications.
     */
    void print_symtab(SymTab *symtab,
                      vector<TypeSpec *>& record_types) const;

    /**
     * Print a symbol table entry.
     * @param entry the symbol table entry.
     * @param record_types the list to fill with RECORD type specifications.
     */
    void print_entry(SymTabEntry *entry,
                     vector<TypeSpec *>& record_types) const;

    /**
     * Print a type specification.
     * @param typespec the type specification.
     */
    void print_type(TypeSpec *typespec) const;

    /**
     * Print the details of a type specification.
     * @param typespec the type specification.
     * @param record_types the list to fill with RECORD type specifications.
     */
    void print_type_detail(TypeSpec *typespec,
                           vector<TypeSpec *>& record_types) const;

    /**
     * Print cross-reference tables for records defined in the routine.
     * @param record_types the list to fill with RECORD type specifications.
     */
    void print_records(vector<TypeSpec *>& record_types) const;

    /**
     * Print a string value.
     * @param data_value the value.
     * @return the string.
     */
    string print_string(Object data_value) const;
};

}}  // namespace wci::util

#endif /* WCI_UTIL_CROSSREFERENCER_H_ */
