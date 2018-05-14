/**
 * <h1>TypeChecker</h1>
 *
 * <p>Perform type checking.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "TypeChecker.h"
#include "../TypeSpec.h"
#include "../symtabimpl/Predefined.h"
#include "../typeimpl/TypeSpecImpl.h"

namespace wci { namespace intermediate { namespace typeimpl {

using namespace std;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::typeimpl;

bool TypeChecker::is_integer(TypeSpec *typespec)
{
    return    (typespec != nullptr)
           && (typespec->base_type() == Predefined::integer_type);
}

bool TypeChecker::are_both_integer(TypeSpec *typespec1,
                                   TypeSpec *typespec2)
{
    return is_integer(typespec1) && is_integer(typespec2);
}

bool TypeChecker::is_real(TypeSpec *typespec)
{
    return    (typespec != nullptr)
           && (typespec->base_type() == Predefined::real_type);
}

bool TypeChecker::is_integer_or_real(TypeSpec *typespec)
{
    return is_integer(typespec) || is_real(typespec);
}

bool TypeChecker::is_at_least_one_real(TypeSpec *typespec1, TypeSpec *typespec2)
{
    return (is_real(typespec1) && is_real(typespec2)) ||
           (is_real(typespec1) && is_integer(typespec2)) ||
           (is_integer(typespec1) && is_real(typespec2));
}

/**
 * Check if a type specification is bool.
 * @param type the type specification to check.
 * @return true if bool, else false.
 */
bool TypeChecker::is_boolean(TypeSpec *typespec)
{
    return    (typespec != nullptr)
           && (typespec->base_type() == Predefined::boolean_type);
}

bool TypeChecker::are_both_boolean(TypeSpec *typespec1,
                                   TypeSpec *typespec2)
{
    return is_boolean(typespec1) && is_boolean(typespec2);
}

bool TypeChecker::is_char(TypeSpec *typespec)
{
    return    (typespec != nullptr)
           && (typespec->base_type() == Predefined::char_type);
}

bool TypeChecker::are_assignment_compatible(TypeSpec *target_typespec,
                                            TypeSpec *value_typespec)
{
    if ((target_typespec == nullptr) || (value_typespec == nullptr))
    {
        return false;
    }

    target_typespec = target_typespec->base_type();
    value_typespec  = value_typespec->base_type();

    bool compatible = false;

    // Identical types.
    if (target_typespec == value_typespec)
    {
        compatible = true;
    }

    // real := integer
    else if (is_real(target_typespec) && is_integer(value_typespec))
    {
        compatible = true;
    }

    // string := string
    else {
        compatible =    target_typespec->is_pascal_string()
                     && value_typespec->is_pascal_string();
    }

    return compatible;
}

bool TypeChecker::are_comparison_compatible(TypeSpec *typespec1,
                                            TypeSpec *typespec2)
{
    if ((typespec1 == nullptr) || (typespec2 == nullptr)) {
        return false;
    }

    typespec1 = typespec1->base_type();
    typespec2 = typespec2->base_type();
    TypeFormImpl form = (TypeFormImpl) typespec1->get_form();

    bool compatible = false;

    // Two identical scalar or enumeration types.
    if (   (typespec1 == typespec2)
        && (   (form == TF_SCALAR)
            || (form == TF_ENUMERATION)))
    {
        compatible = true;
    }

    // One integer and one real.
    else if (is_at_least_one_real(typespec1, typespec2))
    {
        compatible = true;
    }

    // Two strings.
    else
    {
        compatible =    typespec1->is_pascal_string()
                     && typespec2->is_pascal_string();
    }

    return compatible;
}

}}}  // namespace wci::intermediate::typeimpl
