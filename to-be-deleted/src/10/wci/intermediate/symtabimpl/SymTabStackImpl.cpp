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

SymTabEntry *SymTabStackImpl::get_program_id() const { return program_id; }

void SymTabStackImpl::set_program_id(SymTabEntry *id)
{
    program_id = id;
}

SymTab *SymTabStackImpl::get_local_symtab() const
{
    return stack[current_nesting_level];
}

SymTab *SymTabStackImpl::push()
{
    SymTab *symtab = SymTabFactory::create_symtab(++current_nesting_level);
    stack.push_back(symtab);

    return symtab;
}

SymTab *SymTabStackImpl::push(SymTab *symtab)
{
    ++current_nesting_level;
    stack.push_back(symtab);

    return symtab;
}

SymTab *SymTabStackImpl::pop()
{
    SymTab *symtab = stack[current_nesting_level];
    stack.erase(stack.begin() + current_nesting_level);
    current_nesting_level--;

    return symtab;
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
    SymTabEntry *found_entry = nullptr;

    // Search the current and enclosing scopes.
    for (int i = current_nesting_level;
         (i >= 0) && (found_entry == nullptr); --i)
    {
        found_entry = stack[i]->lookup(name);
    }

    return found_entry;
}

}}}  // namespace wci::intermediate::symtabimpl
