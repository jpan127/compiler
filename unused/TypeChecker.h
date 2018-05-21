/**
 * <h1>TypeChecker</h1>
 *
 * <p>Perform type checking.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef TYPECHECKER_H_
#define TYPECHECKER_H_

#include "../TypeSpec.h"

namespace wci { namespace intermediate { namespace typeimpl {

using namespace std;
using namespace wci::intermediate;

class TypeChecker
{
public:
    /**
     * Check if a type specification is integer.
     * @param typespec the type specification to check.
     * @return true if integer, else false.
     */
    static bool is_integer(TypeSpec *typespec);

    /**
     * Check if both type specifications are integer.
     * @param typespec1 the first type specification to check.
     * @param typespec2 the second type specification to check.
     * @return true if both are integer, else false.
     */
    static bool are_both_integer(TypeSpec *typespec1, TypeSpec *typespec2);

    /**
     * Check if a type specification is real.
     * @param typespec the type specification to check.
     * @return true if real, else false.
     */
    static bool is_real(TypeSpec *typespec);

    /**
     * Check if a type specification is integer or real.
     * @param typespec the type specification to check.
     * @return true if integer or real, else false.
     */
    static bool is_integer_or_real(TypeSpec *typespec);

    /**
     * Check if at least one of two type specifications is real.
     * @param typespec1 the first type specification to check.
     * @param typespec2 the second type specification to check.
     * @return true if at least one is real, else false.
     */
    static bool is_at_least_one_real(TypeSpec *typespec1, TypeSpec *typespec2);

    /**
     * Check if a type specification is boolean.
     * @param type the type specification to check.
     * @return true if boolean, else false.
     */
    static bool is_boolean(TypeSpec *typespec);

    /**
     * Check if both type specifications are boolean.
     * @param typespec1 the first type specification to check.
     * @param typespec2 the second type specification to check.
     * @return true if both are boolean, else false.
     */
    static bool are_both_boolean(TypeSpec *typespec1, TypeSpec *typespec2);

    /**
     * Check if a type specification is char.
     * @param type the type specification to check.
     * @return true if char, else false.
     */
    static bool is_char(TypeSpec *typespec);

    /**
     * Check if two type specifications are assignment compatible.
     * @param target_typespec the target type specification.
     * @param value_typespec the value type specification.
     * @return true if the value can be assigned to the target, else false.
     */
    static bool are_assignment_compatible(TypeSpec *target_typespec,
                                          TypeSpec *value_typespec);

    /**
     * Check if two type specifications are comparison compatible.
     * @param typespec1 the first type specification to check.
     * @param typespec2 the second type specification to check.
     * @return true if the types can be compared to each other, else false.
     */
    static bool are_comparison_compatible(TypeSpec *typespec1,
                                          TypeSpec *typespec2);
};

}}}  // namespace wci::intermediate::typeimpl

#endif /* TYPECHECKER_H_ */
