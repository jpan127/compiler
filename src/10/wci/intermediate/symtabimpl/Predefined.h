/**
 * <h1>Predefined</h1>
 *
 * <p>Enter the predefined Pascal types, identifiers, and constants
 * into the symbol table.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef PREDEFINED_H_
#define PREDEFINED_H_

#include <vector>
#include "../TypeSpec.h"
#include "../SymTabStack.h"

namespace wci { namespace intermediate { namespace symtabimpl {

using namespace std;
using namespace wci::intermediate;

class Predefined
{
public:
    // Predefined types.
    static TypeSpec *integer_type;
    static TypeSpec *real_type;
    static TypeSpec *boolean_type;
    static TypeSpec *char_type;
    static TypeSpec *undefined_type;
    static TypeSpec *complex_type;
    static TypeSpec *complex_real_type;
    static TypeSpec *complex_imag_type;
    
    // Predefined identifiers.
    static SymTabEntry *integer_id;
    static SymTabEntry *real_id;
    static SymTabEntry *boolean_id;
    static SymTabEntry *char_id;
    static SymTabEntry *false_id;
    static SymTabEntry *true_id;
    static SymTabEntry *complex_id;
    static SymTabEntry *complex_real_id;
    static SymTabEntry *complex_imag_id;

    /**
     * Initialize a symbol table stack with predefined identifiers.
     * @param symTab the symbol table stack to initialize.
     */
    static void initialize(SymTabStack *symtab_stack);

private:
    /**
     * Initialize the predefined types.
     * @param symtab_stack the symbol table stack to initialize.
     */
    static void initialize_types(SymTabStack *symtab_stack);

    /**
     * Initialize the predefined constant.
     * @param symtab_stack the symbol table stack to initialize.
     */
    static void initialize_constants(SymTabStack *symtab_stack);
};

}}}  // namespace wci::intermediate::symtabimpl

#endif /* PREDEFINED_H_ */
