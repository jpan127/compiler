#pragma once

#include "common.hpp"



namespace intermediate
{

    /**
     *  @class : SymbolTableStore
     *
     *  Maintains persistent symbol tabless as storage
     */
    class SymbolTableStore
    {

    public:

        /// Constructor
        SymbolTableStore() { }

        /**
         *  Registers a symbol table into the store
         *  @param table_ptr : Pointer to the symbol table
         */
        void register_symbol_table(SymbolTablePtr table_ptr)
        {
            m_tables.push_back(table_ptr);
        }

        /**
         *  Looks up a symbol in the entire store
         *  @param name  : Name of the symbol
         *  @param scope : Scope of the table that found the symbol, to be set
         *  @returns     : Pointer to the symbol
         */
        SymbolPtr lookup_symbol(const std::string & name, std::string & scope) const
        {
            SymbolPtr s_ptr = nullptr;

            for (auto table : m_tables)
            {
                s_ptr = table->lookup_symbol(name);
                if (nullptr != s_ptr)
                {
                    scope = table->get_table_name();
                    break;
                }
            }

            return s_ptr;
        }

        /**
         *  Looks up a symbol in the entire store
         *  @param name : Name of the symbol
         *  @returns    : Pointer to the symbol
         */
        SymbolPtr lookup_symbol(const std::string & name) const
        {
            SymbolPtr s_ptr = nullptr;

            for (auto table : m_tables)
            {
                s_ptr = table->lookup_symbol(name);
                if (nullptr != s_ptr)
                {
                    break;
                }
            }

            return s_ptr;
        }

        /**
         *  Looks up a symbol table in the entire store
         *  @param name : Name of the table
         *  @returns    : Pointer to the table
         */
        SymbolTablePtr lookup_symbol_table(const std::string & name) const
        {
            SymbolTablePtr table_ptr = nullptr;

            for (auto table : m_tables)
            {
                if (table->get_table_name() == name)
                {
                    table_ptr = table;
                    break;
                }
            }

            return table_ptr;
        }

    private:

        /// Stores symbol tables in a vector
        std::vector <SymbolTablePtr> m_tables;

    };

} /// intermediate
