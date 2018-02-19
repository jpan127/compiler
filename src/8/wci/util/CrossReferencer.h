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

#include "../intermediate/SymTab.h"
#include "../intermediate/SymTabStack.h"

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

    static const int LABEL_WIDTH;
    static const int INDENT_WIDTH;

    static const string INDENT;

    /**
     * Print column headings.
     */
    void print_column_headings() const;

    /**
     * Print the entries in a symbol table.
     * @param SymTab the symbol table.
     */
    void print_symtab(SymTab *symtab) const;
};

}}  // namespace wci::util

#endif /* WCI_UTIL_CROSSREFERENCER_H_ */
