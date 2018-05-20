#include "SymbolTableStack.hpp"



namespace intermediate
{

    SymbolTableStack::SymbolTableStack(SymbolTablePtr & global_table) : m_current_nesting_level(0)
    {
        stack.push_back(global_table);
    }

    const SymbolTablePtr & SymbolTableStack::get_global_symbol_table() const
    {
        return stack.front();
    }

    const SymbolTablePtr & SymbolTableStack::get_local_symbol_table() const
    {
        return stack.back();
    }

    void SymbolTableStack::push_symbol_table(SymbolTablePtr & table)
    {
        stack.push_back(table);
        m_current_nesting_level++;
    }

    SymbolTablePtr SymbolTableStack::pop_symbol_table()
    {
        SymbolTablePtr table_ptr = stack.back();
        stack.pop_back();
        return table_ptr;
    }

    SymbolPtr SymbolTableStack::lookup_symbol_locally(const std::string & name) const
    {
        return stack.back()->lookup_symbol(name);
    }

    SymbolPtr SymbolTableStack::lookup_symbol_globally(const std::string & name) const
    {
        return stack.front()->lookup_symbol(name);
    }

} /// intermediate
