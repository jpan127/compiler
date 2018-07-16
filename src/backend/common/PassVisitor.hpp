#pragma once

#include "common.hpp"
#include "CmmBaseVisitor.h"

#include "SymbolTableStack.hpp"
#include "SymbolStore.hpp"
#include "TypeSpecifier.hpp"
#include "JasminEmitter.hpp"



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
        PassVisitor(const uint8_t pass_number, std::ofstream & j_file) :
            pass_number(pass_number),
            j_file(j_file)
        {
            /// Empty
        }

        /// Virtual destructor
        virtual ~PassVisitor() { }

        /// Enumerates the pass number
        const uint8_t pass_number;

        /// Just a tab character
        static constexpr char TAB = '\t';

        /// Stores symbol tables
        static intermediate::SymbolTableStore store;

        /// Maps function names to their function invoke signature
        static std::unordered_map <std::string, std::string> function_definition_map;

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
         *  Prints the current visit context information
         *  @param context   : Current context or parser rule
         *  @param rule_name : Name of current rule
         */
        bool print_debug_context(antlr4::ParserRuleContext * context, const std::string & rule_name) const;

        /**
         *  Sets up a GET instruction depending on global or not global
         *  @param program_name : The name of the program
         *  @param variable     : The name of the variable
         *  @param type_letter  : The type of the variable
         *  @returns            : Pointer to the instruction emit function and the parameters for the consumer to use
         *  @throws             : InvalidType if type letter not supported
         */
        backend::string_JasminEmitter_FUNCT create_get_variable_instruction(const std::string program_name, const std::string variable, const char type_letter);

        /**
         *  Sets up a PUT instruction depending on global or not global
         *  @param program_name : The name of the program
         *  @param variable     : The name of the variable
         *  @param type_letter  : The type of the variable
         *  @returns            : Pointer to the instruction emit function and the parameters for the consumer to use
         *  @throws             : InvalidType if type letter not supported
         */
        backend::string_JasminEmitter_FUNCT create_put_variable_instruction(const std::string program_name, const std::string variable, const char type_letter);

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

    };

} /// backend
