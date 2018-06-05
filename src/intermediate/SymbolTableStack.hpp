#pragma once

#include "common.hpp"
#include "SymbolTable.hpp"



namespace intermediate
{

    /// Alias for shared pointer to a symbol table
    using SymbolTablePtr = std::shared_ptr <SymbolTable>;

    /**
     *  @class : SymbolTableStack
     *
     *  Maintains a stack of symbol tables
     *  The global symbol table is initialized on instantiation
     *  Easily allows for access to symbols and the local / global symbol tables
     */

    class SymbolTableStack
    {
    public:

        /**
         *  Default Constructor
         *  Creates an empty global symbol table
         */
        SymbolTableStack();

        /**
         *  Constructor
         *  @param global_table : Global symbol table to push onto the stack first
         */
        SymbolTableStack(SymbolTablePtr & global_table);

        /// Returns the current nesting level
        uint32_t get_current_nesting_level() const { return m_current_nesting_level; }

        /// Returns the last symbol ID of the local symbol table
        uint32_t get_last_symbol_id_locally() const { return stack.back()->get_last_symbol_id(); }

        /// Returns the global symbol table, will always exist
        const SymbolTablePtr & get_global_symbol_table() const;

        /// Returns the local symbol table, will always exist
        const SymbolTablePtr & get_local_symbol_table() const;

        /**
         *  Pushes a symbol onto the local symbol table
         *  @param name : Name of symbol
         *  @param type : Type of the symbol
         */
        void push_symbol_locally(const std::string & name, backend::TypeSpecifier type);

        /**
         *  Pushes a new symbol table onto the stack
         *  @param table : Pointer to the symbol table to copy onto the stack
         */
        void push_symbol_table(SymbolTablePtr & table);

        /**
         *  Pops the top most symbol table off the stack if the local table is not the global table
         *  @returns : Copy of the shared_ptr to the symbol table popped, passing ownership, otherwise nullptr
         *  @note    : It is imperative that the caller assumes responsibility of cleaning up the popped pointer
         */
        SymbolTablePtr pop_symbol_table();

        /**
         *  Looks up a symbol in the local symbol table
         *  @param name : Name of the symbol to lookup
         *  @returns    : Pointer to the symbol table found, otherwise nullptr
         */
        SymbolPtr lookup_symbol_locally(const std::string & name) const;

        /**
         *  Looks up a symbol in the global symbol table
         *  @param name : Name of the symbol to lookup
         *  @returns    : Pointer to the symbol table found, otherwise nullptr
         */
        SymbolPtr lookup_symbol_globally(const std::string & name) const;

#if 0
        bool function_exists(const std::string & name) const;

        std::vector <SymbolPtr> glob_all_symbols() const;
#endif

    private:

        /// Tracks the current nesting level of the local symbol table
        uint32_t m_current_nesting_level;

        /// Maintains a stack of symbol tables, is a vector for simpler lookup through all tables
        std::vector <SymbolTablePtr> stack;

    };

} /// intermediate
