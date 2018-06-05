#include "SymbolTableStack.hpp"



namespace intermediate
{

    SymbolTableStack::SymbolTableStack() : m_current_nesting_level(0)
    {
        SymbolTablePtr table_ptr = std::make_shared <SymbolTable>
        (
            SymbolTableScope::global,
            "global",
            0
        );

        push_symbol_table(table_ptr);
    }

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

    void SymbolTableStack::push_symbol_locally(const std::string & name, backend::TypeSpecifier type)
    {
        stack.back()->create_and_add_symbol(name, type);
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
        SymbolPtr symbol = nullptr;

        for (const auto & table : stack)
        {
            if (nullptr != table->lookup_symbol(name))
            {
                symbol = table->lookup_symbol(name);
                break;
            }
        }

        return symbol;
    }

#if 0
    bool SymbolTableStack::function_exists(const std::string & name) const
    {
        bool found = false;

        for (const auto & table : stack)
        {
            if (name == table->get_table_name())
            {
                found = true;
                break;
            }
        }

        return found;
    }

    std::vector <SymbolPtr> SymbolTableStack::glob_all_symbols() const
    {
        std::vector <SymbolPtr> all_symbols;

        for (const auto & table : stack)
        {
            const std::vector <SymbolPtr> table_symbols = table->glob_all_symbols();
            all_symbols.insert(all_symbols.end(), table_symbols.begin(), table_symbols.end());
        }

        return all_symbols;
    }
#endif

} /// intermediate
