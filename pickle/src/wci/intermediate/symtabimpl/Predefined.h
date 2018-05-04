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
#include "../SymTabEntry.h"
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

    // Predefined identifiers.
    static SymTabEntry *integer_id;
    static SymTabEntry *real_id;
    static SymTabEntry *boolean_id;
    static SymTabEntry *char_id;
    static SymTabEntry *false_id;
    static SymTabEntry *true_id;
    static SymTabEntry *read_id;
    static SymTabEntry *readln_id;
    static SymTabEntry *write_id;
    static SymTabEntry *writeln_id;
    static SymTabEntry *abs_id;
    static SymTabEntry *arctan_id;
    static SymTabEntry *chr_id;
    static SymTabEntry *cos_id;
    static SymTabEntry *eof_id;
    static SymTabEntry *eoln_id;
    static SymTabEntry *exp_id;
    static SymTabEntry *ln_id;
    static SymTabEntry *odd_id;
    static SymTabEntry *ord_id;
    static SymTabEntry *pred_id;
    static SymTabEntry *round_id;
    static SymTabEntry *sin_id;
    static SymTabEntry *sqr_id;
    static SymTabEntry *sqrt_id;
    static SymTabEntry *succ_id;
    static SymTabEntry *trunc_id;

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

    /**
     * Initialize the standard procedures and functions.
     * @param symtab_stack the symbol table stack to initialize.
     */
    static void initialize_standard_routines(SymTabStack *symtab_stack);

    /**
     * Enter a standard procedure or function into the symbol table stack.
     * @param symTabStack the symbol table stack to initialize.
     * @param defn either PROCEDURE or FUNCTION.
     * @param name the procedure or function name.
     */
    static SymTabEntry *enter_standard(SymTabStack *symtab_stack,
                                       Definition defn, string name,
                                       RoutineCode routine_code);
};

}}}  // namespace wci::intermediate::symtabimpl

#endif /* PREDEFINED_H_ */
