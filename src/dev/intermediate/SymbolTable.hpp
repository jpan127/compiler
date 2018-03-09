#pragma once

#include "globals.hpp"



/**
 *  A symbol table represents all of the symbols in a given scope
 *  Each symbol table will have the following attributes:
 *      - stack level : The level of the symbol table in the symbol table stack
 *      - symbols     : The different symbols in the current scope
 */

class SymbolTable
{
public:

    /**
     *  Constructor
     *  @param level : The current stack level of this symbol table
     */
    SymbolTable(const uint32_t level);

    /// Returns the stack level of the current symbol table
    uint32_t get_current_stack_level(void) const;

    /**
     *  Add a new symbol into the table
     *  @param name   : The name of the new symbol to add
     *  @param symbol : The symbol object
     */
    void add_new_symbol(const string name, const Symbol * symbol);

    /**
     *  Finds an existing symbol in the table
     *  @param name   : The name of the symbol to look up
     *  @param symbol : The symbol object passed in by reference
     *  @returns      : True for found, false for not found
     */
    bool get_symbol(const string name, const Symbol & symbol) const;

private:

    /// Stack level of this symbol table
    const uint32_t stack_level;

    map <const string, const Symbol> symbols;

};