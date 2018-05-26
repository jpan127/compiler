#pragma once

#include "common.hpp"



namespace backend
{

    enum class Type
    {
        t_null,
        t_void,
        t_bool,
        t_char,
        t_int,
        t_float,
        t_double,
        t_long,
    };

    /// Specifies the type of some object
    class TypeSpecifier
    {
    public:

        /// Constructor that takes the type
        TypeSpecifier(const std::string type) { set_type(type); }
        TypeSpecifier(const Type type) : m_type(type) { }
        TypeSpecifier() : m_type(Type::t_null) { }

        /// Overloading output stream for TypeSpecifier
        friend std::ostream & operator << (std::ostream & out, const TypeSpecifier & rhs);
        friend std::ostream & operator << (std::ostream & out, const Type & rhs);

        friend void type_swap(TypeSpecifier & lhs, TypeSpecifier & rhs);

        /// Assignment operator
        TypeSpecifier & operator = (TypeSpecifier rhs)
        {
            type_swap(rhs, *this);
            return *this;
        }

        /// @ { Overloaded comparison operators
        friend bool operator == (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator != (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator <  (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator >  (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator <= (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator >= (const TypeSpecifier & lhs, const TypeSpecifier & rhs);
        friend bool operator == (const Type & lhs, const TypeSpecifier & rhs);
        friend bool operator != (const Type & lhs, const TypeSpecifier & rhs);
        friend bool operator <  (const Type & lhs, const TypeSpecifier & rhs);
        friend bool operator >  (const Type & lhs, const TypeSpecifier & rhs);
        friend bool operator <= (const Type & lhs, const TypeSpecifier & rhs);
        friend bool operator >= (const Type & lhs, const TypeSpecifier & rhs);
        /// @ }

        /// Stringifies the enumerated type
        std::string to_string() const;

        /// Returns the type
        const Type & get_type() const { return m_type; }
        const char get_letter() const { return m_type_letter; }

        void set_type(const TypeSpecifier & type) { m_type = type.get_type(); }
        void set_type(const Type & type) { m_type = type; }
        void set_type(const std::string & type);

        /// Checks if null
        const bool is_null() const { return m_type == Type::t_null; }

    private:

        /// Stores the enumerated type of this object
        Type m_type;

        char m_type_letter;

        /// Maps the enumerated types to their quantifiable weight / importance
        static const std::map <Type, uint8_t> type_weight_map;

        /// Maps string types to a pointer to the type
        static const std::unordered_map <std::string, Type> type_map;

    };

} /// backend
