#pragma once

#include "globals.hpp"



/// Types of symbols
enum class SymbolType
{
    constant,
    function_code,
    function_arguments,
    data,
};

/**
 *  This class is a symbol, or an entry into the symbol table
 *  Each symbol table composes of a variety of symbols and this exposes a
 *  pretty generic interface and a method of data encapsulation
 */

class Symbol
{
public:

    /**
     *  Constructor
     *  @param name  : Name of this symbol
     */
    Symbol(const string name);

    /// Returns the name of this symbol
    const string get_symbol_name(void) const;

    /// Returns the type of this symbol
    const SymbolType get_symbol_type(void) const;

    /// Returns the value of this symbol
    const data_S & get_symbol_value(void) const;

    /// Inserts the line number of an appearance of this symbol
    void add_line_number(uint32_t line_number);

    /// Returns a reference to the vector of line numbers
    vector <uint32_t> & get_line_numbers(void) const;

    /**
     *  Returns the value of an existing attribute
     *  @param type  : The type of attribute
     *  @param value : The value of the attribute modified by reference
     *  @returns     : True for found, false for not found
     */
    bool get_symbol_attribute(const SymbolType type, data_S & value) const;

    /**
     *  Inserts an attribute : value pair
     *  @param type  : The type of attribute
     *  @param value : The value of the attribute
     */
    void set_symbol_attribute(const SymbolType type, const data_S value);

private:

    /// Name of this symbol
    const string name;

    /// Vector of line numbers this symbol appeared in
    vector <uint32_t> line_numbers;

    /// Attributes of this symbol
    map <const SymbolType, const data_S> attributes;

};