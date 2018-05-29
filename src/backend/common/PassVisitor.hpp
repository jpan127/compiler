#pragma once

#include "CmmBaseVisitor.h"

#include "common.hpp"
#include "SymbolTableStack.hpp"
#include "TypeSpecifier.hpp"



namespace backend
{

    /// Common code to all visit nodes, not the best but could not find a better solution
    #define PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR()                 \
        if (!print_debug_context(context, string(__FUNCTION__)))    \
        {                                                           \
            return nullptr;                                         \
        }

    enum class PassEnumeration
    {
        pass1 = 1,
        pass2 = 2,
        pass3 = 3,
    };

    /**
     *  Class that Pass1Visitor and Pass2Visitor inherit from
     *  Contains data structures used by all passes and generic helper functions
     *  Protected constructor to prevent direct instantiation
     */

    class PassVisitor
    {
    protected:

        /// Protected constructor
        PassVisitor(const uint8_t pass_number, std::ofstream & j_file) : pass_number(pass_number), j_file(j_file) { }

        /// Virtual destructor
        virtual ~PassVisitor() { }

        /// Enumerates the pass number
        const uint8_t pass_number;

        /// Just a tab character
        static constexpr char TAB = '\t';

        /// Maps scope names to maps of symbol names to symbol attributes
        static std::unordered_map <std::string, std::unordered_map <std::string, intermediate::Symbol>> variable_id_map;

        /// Maps function names to their function invoke signature
        static std::unordered_map <std::string, std::string> function_definition_map;

        /// Stores the current function name
        static std::string current_function;

        /// Counts up for each compound statement
        static uint64_t scope_counter;

        /// Output file
        std::ofstream & j_file;

        /**
         *  Determines the resulting type depending on the two operands
         *  @param lhs_type : Type of LHS
         *  @param rhs_type : Type of RHS
         *  @returns        : A single type which is the greater of the two
         */
        const backend::TypeSpecifier resolve_expression_type(const backend::TypeSpecifier & lhs_type, const backend::TypeSpecifier & rhs_type);

        /**
         *  Looks up the letter with [letter_map]
         *  @param type : The type to lookup
         *  @returns    : The letter looked up, throws if not found
         *  @throws     : InvalidType
         */
        char letter_map_lookup(const backend::TypeSpecifier & type) const;

        /**
         *  Looks up the letter with [instruction_prefix_map]
         *  @param type : The type to lookup
         *  @returns    : The letter looked up, throws if not found
         *  @throws     : InvalidType
         */
        char instruction_prefix_map_lookup(const backend::TypeSpecifier & type) const;

        /**
         *  Prints the current visit context information if [debug_flag] is true
         *  @param context   : Current context or parser rule
         *  @param rule_name : Name of current rule
         */
        bool print_debug_context(antlr4::ParserRuleContext * context, const std::string & rule_name) const;

        /**
         *  Wrapper for determining if an identifier is a digit or not
         *  @param identifier : String identifier
         *  @returns          : True for digit
         */
        static bool is_digit(const std::string & identifier)
        {
            return std::isdigit(identifier[0]) || (identifier[0] == '-' && std::isdigit(identifier[1]));
        }

        /**
         *  Sets up a GET instruction depending on global or not global
         *  @param program_name : The name of the program
         *  @param variable     : The name of the variable
         *  @param type_letter  : The type of the variable
         *  @returns            : The constructed instruction, returns ???? if not found
         *  @throws             : InvalidType if type letter not supported
         */
        std::string create_get_variable_instruction(const std::string program_name, const std::string variable, const char type_letter);

        /**
         *  Sets up a PUT instruction depending on global or not global
         *  @param program_name : The name of the program
         *  @param variable     : The name of the variable
         *  @param type_letter  : The type of the variable
         *  @returns            : The constructed instruction, returns ???? if not found
         *  @throws             : InvalidType if type letter not supported
         */
        std::string create_put_variable_instruction(const std::string program_name, const std::string variable, const char type_letter);

        /**
         *  Looks up the variable ID in the variable id table
         *  @param variable : The name of the variable
         *  @returns        : The enumerated ID of the variable
         */
        uint32_t get_variable_id(const std::string variable) const;

        /**
         *  Determines if a variable is in the global symbol table
         *  @param variable : The name of the variable
         *  @returns        : True for global, false for not global
         */
        bool is_global(const std::string variable) const;

        /**
         *  Determines if a type conversion instruction is necessary when working with two types
         *  @param current_type : The type the last instruction was working with
         *  @param needed_type  : The type the next instruction is working with
         *  @returns            : A string with the type instruction, empty if no instruction needed
         */
        std::string convert_type_if_neccessary(const backend::TypeSpecifier & current_type, const backend::TypeSpecifier & needed_type);

        void emit_comment(antlr4::ParserRuleContext * context, const uint8_t indents=0) const
        {
            for (uint8_t i = 0; i < indents; i++)
            {
                j_file << TAB;
            }
            j_file << "; " << context->getText() << endl;
        }

    };

} /// backend
