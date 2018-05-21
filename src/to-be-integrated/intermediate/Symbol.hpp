#pragma once

#include <unordered_map>

#include "common.hpp"
#include "wci/intermediate/TypeSpec.h"
#include "wci/intermediate/symtabimpl/Predefined.h"



namespace intermediate
{

    using wci::intermediate::TypeSpec;
    using wci::intermediate::symtabimpl::Predefined;

    /**
     *  @class : Symbol
     *
     *  The purpose of this class is a completely immutable object
     *  that contains the attributes of a symbol
     */

    class Symbol
    {

    public:

        /**
         *  Constructor
         *  Initializes the constant member variables
         *  @TODO : Change to TypeSpecifier
         */
        Symbol(const uint32_t id, TypeSpec * type) : m_id(id),  m_type(type) 
        {
            if (nullptr == type)
            {
                throw InvalidType("Impossible to create symbol with a NULL type");
            }
            else
            {
                m_type_letter = letter_map.at(type);
            }
        }

        /// Assignment operator
        Symbol & operator = (Symbol rhs)
        {
            std::swap(rhs, *this);
            return *this;
        }

        /// Returns the ID of the symbol
        uint32_t get_id() const { return m_id; }

        /// Returns the type letter of the symbol
        char get_type_letter() const { return m_type_letter; }

        /// Returns the type specifier of the symbol
        TypeSpec * get_type() const { return m_type; }

    private:

        /// ID of the symbol, enumerated in the parent symbol table
        uint32_t m_id;

        /// The type of the symbol, the Jasmin type specifier
        char m_type_letter;

        /// Pointer to the Predefined type
        TypeSpec * m_type;

        /// Keeps track of the line numbers this symbol was referenced
        std::vector <uint32_t> line_numbers;

        const std::unordered_map <TypeSpec *, char> letter_map =
        {
            { Predefined::void_type   , 'V' },
            { Predefined::bool_type   , 'B' },
            { Predefined::char_type   , 'C' },
            { Predefined::int_type    , 'I' },
            { Predefined::float_type  , 'F' },
            { Predefined::double_type , 'D' },
        };

    };

} /// intermediate
