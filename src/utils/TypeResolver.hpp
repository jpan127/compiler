#pragma once

#include "common.hpp"
#include "TypeSpecifier.hpp"



namespace utils
{

    /// Enumerates the different type conversion instructions
    enum class TypeConversion
    {
        // d   l    f    i
             d2l, d2f, d2i,
        l2d,      l2f, l2i,
        f2d, f2l,      f2i,
        i2d, i2l, i2f,
        none,
    };

    /**
     *  Resolves types by determining which, if any, of the types has a higher precedence
     *  Because precedences matter in Jasmin, type conversion is always necessary, and this
     *  function helps resolve any type conflicts
     *  @param lhs : Type specifier of the left operand
     *  @param rhs : Type specifier of the right operand
     *  @returns   : A type specifier which is the greater precedence of the two operands
     */
    backend::TypeSpecifier resolve_types(const backend::TypeSpecifier & lhs, const backend::TypeSpecifier & rhs);

    /**
     *  Determines if a type conversion instruction is necessary
     *  @param start : Type specifier of the left operand
     *  @param end   : Type specifier of the right operand
     *  @returns     : A type conversion instruction
     */
    TypeConversion determine_conversion_requirement(const backend::TypeSpecifier & start, const backend::TypeSpecifier & end);

}
