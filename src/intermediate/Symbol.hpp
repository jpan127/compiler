#pragma once

#include "common.hpp"
#include "TypeSpecifier.hpp"



namespace intermediate
{

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
         *  @param id   : ID of the symbol at time of construction
         *  @param type : Type of symbol
         */
        Symbol(const uint32_t id, backend::TypeSpecifier type) : m_id(id),  m_type(type)
        {
            m_type_letter = letter_map.at(type.get_type());
        }

        /// Assignment operator
        Symbol & operator = (Symbol rhs)
        {
            std::swap(m_id           , rhs.m_id          );
            std::swap(m_type_letter  , rhs.m_type_letter );
            std::swap(m_type         , rhs.m_type        );
            std::swap(m_line_numbers , rhs.m_line_numbers);
            return *this;
        }

        /// Returns the ID of the symbol
        uint32_t get_id() const { return m_id; }

        /// Returns the type letter of the symbol
        char get_type_letter() const { return m_type_letter; }

        /// Returns the type specifier of the symbol
        const backend::TypeSpecifier & get_type() const { return m_type; }

    private:

        /// ID of the symbol, enumerated in the parent symbol table
        uint32_t m_id;

        /// The type of the symbol, the Jasmin type specifier
        char m_type_letter;

        /// Pointer to the Predefined type
        backend::TypeSpecifier m_type;

        /// Keeps track of the line numbers this symbol was referenced
        std::vector <uint32_t> m_line_numbers;

        const std::unordered_map <backend::Type, char> letter_map =
        {
            { backend::Type::t_void   , 'V' },
            { backend::Type::t_bool   , 'B' },
            { backend::Type::t_char   , 'C' },
            { backend::Type::t_int    , 'I' },
            { backend::Type::t_float  , 'F' },
            { backend::Type::t_double , 'D' },
        };

    };

} /// intermediate
