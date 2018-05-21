#include "SymbolTable.hpp"



namespace intermediate
{

    const SymbolPtr & SymbolTable::create_and_add_symbol(const std::string & name, Type type)
    {
        if (Type::t_double == type || Type::t_long == type)
        {
            m_current_symbol_id += 2;
        }
        else
        {
            m_current_symbol_id++;
        }

        SymbolPtr s_ptr = std::make_shared <Symbol> (m_current_symbol_id, type);
        m_table[name] = s_ptr;
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
        bool exists = false;

        if (m_table.find(name) != m_table.end())
        {
            exists = true;
        }

        return exists;
    }

} /// intermediate
