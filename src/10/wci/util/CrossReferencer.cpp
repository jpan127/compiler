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
#include "../Object.h"
#include "../intermediate/SymTab.h"
#include "../intermediate/SymTabEntry.h"
#include "../intermediate/SymTabStack.h"
#include "../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../intermediate/typeimpl/TypeSpecImpl.h"

namespace wci { namespace util {

using namespace std;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::typeimpl;

const int CrossReferencer::NAME_WIDTH = 16;

const string CrossReferencer::NAME_FORMAT = string("%-") +
                                            to_string(NAME_WIDTH) +
                                            string("s");
const string CrossReferencer::NUMBERS_LABEL = " Line numbers    ";
const string CrossReferencer::NUMBERS_UNDERLINE = " ------------    ";
const string CrossReferencer::NUMBER_FORMAT = " %03d";
const string CrossReferencer::ENUM_CONST_FORMAT = string("%") +
                                                  to_string(NAME_WIDTH) +
                                                  string("s = %s");

const int CrossReferencer::LABEL_WIDTH  = NUMBERS_LABEL.length();
const int CrossReferencer::INDENT_WIDTH = NAME_WIDTH + LABEL_WIDTH;

const string CrossReferencer::INDENT = string(INDENT_WIDTH, ' ');

void CrossReferencer::print(const SymTabStack *symtab_stack) const
{
    cout << "\n===== CROSS-REFERENCE TABLE =====" << endl;

    SymTabEntry *program_id = symtab_stack->get_program_id();
    print_routine(program_id);
}

void CrossReferencer::print_routine(SymTabEntry *routine_id) const
{
    Definition defn = routine_id->get_definition();
    cout << endl << "*** "
         << SymTabEntryImpl::DEFINITION_WORDS[(DefinitionImpl) defn]
         << " " << routine_id->get_name() << " ***" << endl;
    print_column_headings();

    // Print the entries in the routine's symbol table.
    Object entry_value =
        routine_id->get_attribute((SymTabKey) ROUTINE_SYMTAB);
    SymTab *symtab = cast(entry_value, SymTab*);
    vector<TypeSpec *> new_record_types;
    print_symtab(symtab, new_record_types);

    // Print cross-reference tables for any records defined in the routine.
    if (new_record_types.size() > 0) print_records(new_record_types);

    // Print any procedures and functions defined in the routine.
    entry_value =
        routine_id->get_attribute((SymTabKey) ROUTINE_ROUTINES);
    if (!entry_value.empty())
    {
        vector<SymTabEntry *> routine_ids =
                                cast(entry_value, vector<SymTabEntry *>);
        for (SymTabEntry *routine_id : routine_ids)
        {
            print_routine(routine_id);
        }
    }
}

void CrossReferencer::print_column_headings() const
{
    cout << endl;
    printf(NAME_FORMAT.c_str(), "Identifier");
    cout << NUMBERS_LABEL     << "Type specification" << endl;
    printf(NAME_FORMAT.c_str(), "----------");
    cout << NUMBERS_UNDERLINE << "------------------" << endl;
}

void CrossReferencer::print_symtab(SymTab *symtab,
                                   vector<TypeSpec *>& record_types) const
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

        // Print the symbol table entry.
        cout << endl;
        print_entry(entry, record_types);
    }
}

void CrossReferencer::print_entry(SymTabEntry *entry,
                                  vector<TypeSpec *>& record_types) const
{
    Definition defn = entry->get_definition();
    int nestingLevel = entry->get_symtab()->get_nesting_level();
    cout << INDENT << "Defined as: "
         << SymTabEntryImpl::DEFINITION_WORDS[(DefinitionImpl) defn] << endl;
    cout << INDENT << "Scope nesting level: " << nestingLevel << endl;

    // Print the type specification.
    TypeSpec *typespec = entry->get_typespec();
    print_type(typespec);

    switch ((DefinitionImpl) defn)
    {
        case DF_CONSTANT:
        {
            Object data_value =
                    entry->get_attribute((SymTabKey) CONSTANT_VALUE);
            bool need_quotes =    instanceof(data_value, char)
                               || instanceof(data_value, string);
            cout << INDENT << "Value = ";
            if (need_quotes) cout << "'";
            cout << stringify(data_value);
            if (need_quotes) cout << "'";
            cout << endl;

            // Print the type details only if the type is unnamed.
            if (typespec->get_identifier() == nullptr)
            {
                print_type_detail(typespec, record_types);
            }

            break;
        }

        case DF_ENUMERATION_CONSTANT:
        {
            Object data_value =
                entry->get_attribute((SymTabKey) CONSTANT_VALUE);
            cout << INDENT << "Value = " << stringify(data_value) << endl;

            break;
        }

        case DF_TYPE:
        {
            // Print the type details only when the type is first defined.
            if (entry == typespec->get_identifier())
            {
                print_type_detail(typespec, record_types);
            }

            break;
        }

        case DF_VARIABLE:
        {
            // Print the type details only if the type is unnamed.
            if (typespec->get_identifier() == nullptr)
            {
                print_type_detail(typespec, record_types);
            }

            break;
        }

        default: break;  // shouldn't get here
    }
}

void CrossReferencer::print_type(TypeSpec *typespec) const
{
    if (typespec != nullptr)
    {
        TypeForm form = typespec->get_form();
        SymTabEntry *type_id = typespec->get_identifier();
        string type_name = type_id != nullptr
                                 ? type_id->get_name()
                                 : "<unnamed>";

        cout << INDENT << "Type form = "
             << TypeSpecImpl::TYPE_FORM_NAMES[(TypeFormImpl) form]
             << ", Type id = " << type_name << endl;
    }
}

void CrossReferencer::print_type_detail(TypeSpec *typespec,
                                        vector<TypeSpec *>& record_types)
    const
{
    TypeForm form = typespec->get_form();

    switch ((TypeFormImpl) form)
    {
        case TF_ENUMERATION:
        {
            Object type_value =
                typespec->get_attribute((TypeKey) ENUMERATION_CONSTANTS);
            vector<SymTabEntry *> constant_ids =
                cast(type_value, vector<SymTabEntry *>);

            cout << INDENT << "--- Enumeration constants ---" << endl;

            // Print each enumeration constant and its value.
            for (SymTabEntry *constant_id : constant_ids)
            {
                string name = constant_id->get_name();
                Object data_value =
                    constant_id->get_attribute((SymTabKey) CONSTANT_VALUE);

                cout << INDENT;
                printf(ENUM_CONST_FORMAT.c_str(), name.c_str(),
                       stringify(data_value).c_str());
                cout << endl;
            }

            break;
        }

        case TF_SUBRANGE:
        {
            Object type_value =
                typespec->get_attribute((TypeKey) SUBRANGE_MIN_VALUE);
            int min_value = cast(type_value, int);

            type_value =
                typespec->get_attribute((TypeKey) SUBRANGE_MAX_VALUE);
            int max_value = cast(type_value, int);

            type_value =
                typespec->get_attribute((TypeKey) SUBRANGE_BASE_TYPE);
            TypeSpec *base_typespec = cast(type_value, TypeSpec*);

            cout << INDENT + "--- Base type ---" << endl;
            print_type(base_typespec);

            // Print the base type details only if the type is unnamed.
            if (base_typespec->get_identifier() == nullptr)
            {
                print_type_detail(base_typespec, record_types);
            }

            cout << INDENT << "Range = ";
            cout << min_value << ".." << max_value << endl;

            break;
        }

        case TF_ARRAY:
        {
            Object type_value =
                typespec->get_attribute((TypeKey) ARRAY_INDEX_TYPE);
            TypeSpec *index_type = cast(type_value, TypeSpec*);

            type_value =
                typespec->get_attribute((TypeKey) ARRAY_ELEMENT_TYPE);
            TypeSpec *element_type = cast(type_value, TypeSpec*);

            type_value =
                typespec->get_attribute((TypeKey) ARRAY_ELEMENT_COUNT);
            int count = cast(type_value, int);

            cout << INDENT << "--- INDEX TYPE ---" << endl;
            print_type(index_type);

            // Print the index type details only if the type is unnamed.
            if (index_type->get_identifier() == nullptr)
            {
                print_type_detail(index_type, record_types);
            }

            cout << INDENT << "--- ELEMENT TYPE ---" << endl;
            print_type(element_type);
            cout << INDENT << count << " elements" << endl;

            // Print the element type details only if the type is unnamed.
            if (element_type->get_identifier() == nullptr)
            {
                print_type_detail(element_type, record_types);
            }

            break;
        }

        case TF_RECORD:
        {
            record_types.push_back(typespec);
            break;
        }

        default: break;  // shouldn't get here
    }
}

void CrossReferencer::print_records(vector<TypeSpec *>& record_types) const
{
    for (TypeSpec *record_type : record_types)
    {
        SymTabEntry *record_id = record_type->get_identifier();
        string name = record_id != nullptr ? record_id->get_name()
                                           : "<unnamed>";

        cout << endl << "--- RECORD " << name << " ---" << endl;
        print_column_headings();

        // Print the entries in the record's symbol table.
        Object type_value =
                record_type->get_attribute((TypeKey) RECORD_SYMTAB);
        SymTab *symtab = cast(type_value, SymTab*);
        vector<TypeSpec *> new_record_types;
        print_symtab(symtab, new_record_types);

        // Print cross-reference tables for any nested records.
        if (new_record_types.size() > 0)
        {
            print_records(new_record_types);
        }
    }
}

string CrossReferencer::print_string(Object data_value) const
{
    if (instanceof(data_value, string))
    {
        return "'" + cast(data_value, string) + "'";
    }
    else
    {
        return stringify(data_value);
    }
}

}}  // namespace wci::util
