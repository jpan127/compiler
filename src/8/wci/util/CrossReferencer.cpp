/**
 * <h1>CrossReferencer</h1>
 *
 * <p>Generate a cross-reference listing.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <iostream>
#include <string>
#include <vector>
#include "CrossReferencer.h"
#include "../intermediate/SymTab.h"
#include "../intermediate/SymTabEntry.h"
#include "../intermediate/SymTabStack.h"

namespace wci { namespace util {

using namespace std;
using namespace wci::intermediate;

const int CrossReferencer::NAME_WIDTH = 16;

const string CrossReferencer::NAME_FORMAT = string("%-") +
                                            to_string(NAME_WIDTH) +
                                            string("s");
const string CrossReferencer::NUMBERS_LABEL = " Line numbers    ";
const string CrossReferencer::NUMBERS_UNDERLINE = " ------------    ";
const string CrossReferencer::NUMBER_FORMAT = " %03d";

const int CrossReferencer::LABEL_WIDTH  = NUMBERS_LABEL.length();
const int CrossReferencer::INDENT_WIDTH = NAME_WIDTH + LABEL_WIDTH;

const string CrossReferencer::INDENT = string(INDENT_WIDTH, ' ');

void CrossReferencer::print(const SymTabStack *symtab_stack) const
{
    cout << "\n===== CROSS-REFERENCE TABLE =====" << endl;
    print_column_headings();

    print_symtab(symtab_stack->get_local_symtab());
}

void CrossReferencer::print_column_headings() const
{
    cout << endl;
    printf(NAME_FORMAT.c_str(), "Identifier");
    cout << NUMBERS_LABEL << endl;
    printf(NAME_FORMAT.c_str(), "----------");
    cout << NUMBERS_UNDERLINE << endl;
}

void CrossReferencer::print_symtab(SymTab *symtab) const
{
    // Loop over the sorted list of symbol table entries.
    vector<SymTabEntry *> sorted = symtab->sorted_entries();
    for (SymTabEntry *entry : sorted)
    {
        vector<int> line_numbers = entry->get_line_numbers();

        // For each entry, print the identifier name
        // followed by the line numbers.
        printf(NAME_FORMAT.c_str(), entry->get_name().c_str());
        if (line_numbers.size() > 0)
        {
            for (int line_number : line_numbers)
            {
                printf(NUMBER_FORMAT.c_str(), line_number);
            }
        }

        cout << endl;
    }
}

}}  // namespace wci::util
