#pragma once

#include <iostream>
#include <set>
#include <map>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "Pcl2BaseVisitor.h"
#include "antlr4-runtime.h"
#include "Pcl2Visitor.h"

#include "common.hpp"

using namespace wci;
using namespace wci::intermediate;



class PassVisitor
{
protected:

    /// Protected constructor
    PassVisitor() { }

    /// Virtual destructor
    virtual ~PassVisitor() { }

    /// Just a tab character
    static const char TAB = '\t';

    /// Maps string types to a pointer to the typespec
    static const unordered_map <string, TypeSpec **> type_map;

    /// Maps a pointer to the typespec to the type letter
    static const unordered_map <TypeSpec **, char> letter_map;

    /// Maps a pointer to the typespec to the instruction prefix
    static const unordered_map <TypeSpec **, char> instruction_prefix_map;

    static unordered_map <string, unordered_map <string, uint32_t>> variable_id_map;

    static string current_function;

    /// Counts up for each compound statement
    static uint64_t scope_counter;

    /**
     *  Determines the resulting type depending on the two operands
     *  @param lhs_type : Type of LHS
     *  @param rhs_type : Type of RHS
     *  @returns        : A single type which is the greater of the two
     */
    TypeSpec * resolve_expression_type(TypeSpec * lhs_type, TypeSpec * rhs_type);

    /**
     *  Looks up the letter with [letter_map]
     *  @param type : The type to lookup
     *  @returns    : The letter looked up, throws if not found
     *  @throws     : InvalidType
     */
    char letter_map_lookup(const TypeSpec * type) const;

    /**
     *  Looks up the letter with [instruction_prefix_map]
     *  @param type : The type to lookup
     *  @returns    : The letter looked up, throws if not found
     *  @throws     : InvalidType
     */
    char instruction_prefix_map_lookup(const TypeSpec * type) const;

    /**
     *  Prints the current visit context information if [debug_flag] is true
     *  @param pass_num  : The current pass number
     *  @param context   : Current context or parser rule
     *  @param rule_name : Name of current rule
     */
    void print_debug_context(const uint8_t pass_num, antlr4::ParserRuleContext * context, const std::string & rule_name) const;

    /**
     *  Wrapper for determining if an identifier is a digit or not
     *  @param identifier : String identifier
     *  @returns          : True for digit
     */
    static bool is_digit(const string & identifier)
    {
        return std::isdigit(identifier[0]);
    }

    string create_get_variable_instruction(const string program_name, const string variable, const char type_letter);
    string create_put_variable_instruction(const string program_name, const string variable, const char type_letter);

};