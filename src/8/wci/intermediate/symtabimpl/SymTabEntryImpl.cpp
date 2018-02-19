/**
 * <h1>SymTabEntryImpl</h1>
 *
 * <p>An implementation of a symbol table entry.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#include <string>
#include <map>
#include "SymTabEntryImpl.h"
#include "../SymTab.h"
#include "../SymTabEntry.h"

namespace wci { namespace intermediate { namespace symtabimpl {

using namespace std;
using namespace wci;
using namespace wci::intermediate;

SymTabEntryImpl::SymTabEntryImpl(const string name, SymTab *symtab)
    : name(name), symtab(symtab)
{
}

SymTabEntryImpl::~SymTabEntryImpl()
{
}

string SymTabEntryImpl::get_name() const { return name; }

SymTab *SymTabEntryImpl::get_symtab() const { return symtab; }

void SymTabEntryImpl::append_line_number(const int line_number)
{
    line_numbers.push_back(line_number);
}

vector<int> SymTabEntryImpl::get_line_numbers() { return line_numbers; }

void SymTabEntryImpl::set_attribute(const SymTabKey key, Object value)
{
    contents[key] = value;
}

Object SymTabEntryImpl::get_attribute(const SymTabKey key)
{
    return (contents.find(key) != contents.end()) ? contents[key]
                                                  : Object();  // empty
}

}}}  // namespace wci::intermediate::symtabimpl
