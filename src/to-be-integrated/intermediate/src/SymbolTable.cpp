#include "SymbolTable.hpp"



namespace intermediate
{

    const SymbolPtr & SymbolTable::create_and_add_symbol(const std::string & name,
        const uint32_t id, 
        const char type_letter, 
        const TypeSpec * type)
    {
        SymbolPtr s_ptr = std::make_shared <Symbol> (id, type_letter, type);
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
