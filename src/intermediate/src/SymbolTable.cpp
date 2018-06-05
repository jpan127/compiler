#include "SymbolTable.hpp"



namespace intermediate
{

    const SymbolPtr & SymbolTable::create_and_add_symbol(const std::string & name, backend::TypeSpecifier type)
    {
        if (backend::Type::t_double == type.get_type() || backend::Type::t_long == type.get_type())
        {
            m_current_symbol_id++;
        }

        SymbolPtr s_ptr = std::make_shared <Symbol> (m_current_symbol_id, type);
        m_table[name] = s_ptr;

        m_current_symbol_id++;

        return m_table[name];
    }

    SymbolPtr SymbolTable::lookup_symbol(const std::string & name) const
    {
        SymbolPtr s_ptr = nullptr;

        if (m_table.find(name) != m_table.end())
        {
            s_ptr = m_table.at(name);
        }

        return s_ptr;
    }

    bool SymbolTable::symbol_exists(const std::string & name) const
    {
        return (m_table.find(name) != m_table.end());
    }

    std::vector <SymbolPtr> SymbolTable::glob_all_symbols() const
    {
        std::vector <SymbolPtr> symbols;

        for (const auto & pair : m_table)
        {
            symbols.push_back(pair.second);
        }

        return symbols;
    }

} /// intermediate
