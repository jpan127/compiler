#pragma once

#include "common.hpp"



namespace backend
{

    /// Specifies the type of some object
    class TypeSpecifier
    {
    public:

        /// Enumerates the possible types of this class
        enum class Type
        {
            t_void,
            t_bool,
            t_char,
            t_short,
            t_int,
            t_long,
            t_float,
            t_double,
            t_signed,
            t_unsigned,
            t_uint32_t,
            t_int32_t,
        };

        /// Constructor that takes the type
        TypeSpecifier(const TypeSpecifier::Type type) : m_type(type) { }

        /// Overloading output stream for TypeSpecifier
        friend std::ostream & operator << (std::ostream & out, const TypeSpecifier & rhs);

        /// @ { Overloaded comparison operators
        friend bool operator == (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator != (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator <  (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator >  (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator <= (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator >= (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        /// @ }

        /// Stringifies the enumerated type
        std::string to_string() const;

        /// Returns the type
        const TypeSpecifier::Type & get_type() const { return m_type; }

    private:

        /// Stores the enumerated type of this object
        const TypeSpecifier::Type m_type;

        /// Maps the enumerated types to their quantifiable weight / importance
        static const std::map <TypeSpecifier::Type, uint8_t> type_weight_map;

    };

} /// backend
