/**
 * <h1>SymTabImpl</h1>
 *
 * <p>An implementation of the symbol table.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <map>
#include "SymTabImpl.h"
#include "../SymTab.h"
#include "../SymTabEntry.h"
#include "../SymTabFactory.h"

namespace wci { namespace intermediate { namespace symtabimpl {

using namespace std;
using namespace wci::intermediate;

SymTabImpl::SymTabImpl(const int nesting_level)
    : nesting_level(nesting_level)
{
}

SymTabImpl::~SymTabImpl()
{
}

int SymTabImpl::get_nesting_level() const { return nesting_level; }

SymTabEntry *SymTabImpl::enter(string name)
{
    SymTabEntry *entry = SymTabFactory::create_symtab_entry(name, this);
    contents[name] = (SymTabEntryImpl *) entry;

    return entry;
}

SymTabEntry *SymTabImpl::lookup(const string name)
{
    return (contents.find(name) != contents.end())
                ? contents[name]
                : nullptr;
}

/**
 * @return a list of symbol table entries sorted by name.
 */
vector<SymTabEntry *> SymTabImpl::sorted_entries()
{
    vector<SymTabEntry *> list;
    map<string, SymTabEntryImpl *>::iterator it;

    for (it = contents.begin(); it != contents.end(); it++)
    {
        list.push_back(it->second);
    }

    return list;  // sorted list of entries
}

}}}  // namespace wci::intermediate::symtabimpl
