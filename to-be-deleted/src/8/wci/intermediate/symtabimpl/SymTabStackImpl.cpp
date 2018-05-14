/**
 * <h1>SymTabStack</h1>
 *
 * <p>An implementation of the symbol table stack.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include "SymTabStackImpl.h"
#include "../SymTabFactory.h"

namespace wci { namespace intermediate { namespace symtabimpl {

using namespace std;
using namespace wci::intermediate;

SymTabStackImpl::SymTabStackImpl() : current_nesting_level(0)
{
    stack.push_back(SymTabFactory::create_symtab(0));
}

SymTabStackImpl::~SymTabStackImpl()
{
    for (SymTab *symtab : stack) if (symtab != nullptr) delete symtab;
}

int SymTabStackImpl::get_current_nesting_level() const
{
    return current_nesting_level;
};

SymTab *SymTabStackImpl::get_local_symtab() const
{
    return stack[current_nesting_level];
}

SymTabEntry *SymTabStackImpl::enter_local(const string name)
{
    return stack[current_nesting_level]->enter(name);
}

SymTabEntry *SymTabStackImpl::lookup_local(const string name) const
{
    return stack[current_nesting_level]->lookup(name);
}

SymTabEntry *SymTabStackImpl::lookup(const string name) const
{
    return lookup_local(name);
}

}}}  // namespace wci::intermediate::symtabimpl
