/**
 * <h1>Predefined</h1>
 *
 * <p>Enter the predefined Pascal types, identifiers, and constants
 * into the symbol table.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include "Predefined.h"
#include "SymTabEntryImpl.h"
#include "../TypeSpec.h"
#include "../TypeFactory.h"
#include "../SymTabEntry.h"
#include "../SymTabStack.h"
#include "../typeimpl/TypeSpecImpl.h"
#include "../../DataValue.h"

namespace wci { namespace intermediate { namespace symtabimpl {

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::typeimpl;
using namespace wci::intermediate::symtabimpl;

// Predefined types.
TypeSpec *Predefined::integer_type;
TypeSpec *Predefined::real_type;
TypeSpec *Predefined::boolean_type;
TypeSpec *Predefined::char_type;
TypeSpec *Predefined::undefined_type;

// Predefined identifiers.
SymTabEntry *Predefined::integer_id;
SymTabEntry *Predefined::real_id;
SymTabEntry *Predefined::boolean_id;
SymTabEntry *Predefined::char_id;
SymTabEntry *Predefined::false_id;
SymTabEntry *Predefined::true_id;
SymTabEntry *Predefined::read_id;
SymTabEntry *Predefined::readln_id;
SymTabEntry *Predefined::write_id;
SymTabEntry *Predefined::writeln_id;
SymTabEntry *Predefined::abs_id;
SymTabEntry *Predefined::arctan_id;
SymTabEntry *Predefined::chr_id;
SymTabEntry *Predefined::cos_id;
SymTabEntry *Predefined::eof_id;
SymTabEntry *Predefined::eoln_id;
SymTabEntry *Predefined::exp_id;
SymTabEntry *Predefined::ln_id;
SymTabEntry *Predefined::odd_id;
SymTabEntry *Predefined::ord_id;
SymTabEntry *Predefined::pred_id;
SymTabEntry *Predefined::round_id;
SymTabEntry *Predefined::sin_id;
SymTabEntry *Predefined::sqr_id;
SymTabEntry *Predefined::sqrt_id;
SymTabEntry *Predefined::succ_id;
SymTabEntry *Predefined::trunc_id;

void Predefined::initialize(SymTabStack *symtab_stack)
{
    initialize_types(symtab_stack);
    initialize_constants(symtab_stack);
    initialize_standard_routines(symtab_stack);
}

/**
 * Initialize the predefined types.
 * @param symTabStack the symbol table stack to initialize.
 */
void Predefined::initialize_types(SymTabStack *symtab_stack)
{
    // Type integer.
    integer_id = symtab_stack->enter_local("integer");
    integer_type = TypeFactory::create_type((TypeForm) TF_SCALAR);
    integer_type->set_identifier(integer_id);
    integer_id->set_definition((Definition) DF_TYPE);
    integer_id->set_typespec(integer_type);

    // Type real.
    real_id = symtab_stack->enter_local("real");
    real_type = TypeFactory::create_type((TypeForm) TF_SCALAR);
    real_type->set_identifier(real_id);
    real_id->set_definition((Definition) DF_TYPE);
    real_id->set_typespec(real_type);

    // Type boolean.
    boolean_id = symtab_stack->enter_local("boolean");
    boolean_type = TypeFactory::create_type((TypeForm) TF_ENUMERATION);
    boolean_type->set_identifier(boolean_id);
    boolean_id->set_definition((Definition) DF_TYPE);
    boolean_id->set_typespec(boolean_type);

    // Type char.
    char_id = symtab_stack->enter_local("char");
    char_type = TypeFactory::create_type((TypeForm) TF_SCALAR);
    char_type->set_identifier(char_id);
    char_id->set_definition((Definition) DF_TYPE);
    char_id->set_typespec(char_type);

    // Undefined type.
    undefined_type = TypeFactory::create_type((TypeForm) TF_SCALAR);
}

void Predefined::initialize_constants(SymTabStack *symtab_stack)
{
    // Boolean enumeration constant false.
    false_id = symtab_stack->enter_local("false");
    false_id->set_definition((Definition) DF_ENUMERATION_CONSTANT);
    false_id->set_typespec(boolean_type);
    false_id->set_attribute((SymTabKey) CONSTANT_VALUE,
                            new EntryValue(new DataValue(0)));

    // Boolean enumeration constant true.
    true_id = symtab_stack->enter_local("true");
    true_id->set_definition((Definition) DF_ENUMERATION_CONSTANT);
    true_id->set_typespec(boolean_type);
    true_id->set_attribute((SymTabKey) CONSTANT_VALUE,
                           new EntryValue(new DataValue(1)));

    // Add false and true to the boolean enumeration type.
    TypeValue *type_value = new TypeValue();
    type_value->v.push_back(false_id);
    type_value->v.push_back(true_id);
    boolean_type->set_attribute((TypeKey) ENUMERATION_CONSTANTS,
                                type_value);
}

void Predefined::initialize_standard_routines(SymTabStack *symtab_stack)
{
    read_id    = enter_standard(symtab_stack,
                                (Definition) DF_PROCEDURE,
                                "read",
                                (RoutineCode) RoutineCodeImpl::READ);
    readln_id  = enter_standard(symtab_stack,
                                (Definition) DF_PROCEDURE,
                                "readln",
                                (RoutineCode) RoutineCodeImpl::READLN);
    write_id   = enter_standard(symtab_stack,
                                (Definition) DF_PROCEDURE,
                                "write",
                                (RoutineCode) RoutineCodeImpl::WRITE);
    writeln_id = enter_standard(symtab_stack,
                                (Definition) DF_PROCEDURE,
                                "writeln",
                                (RoutineCode) RoutineCodeImpl::WRITELN);

    abs_id    = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "abs",
                               (RoutineCode) RoutineCodeImpl::ABS);
    arctan_id = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "arctan",
                               (RoutineCode) RoutineCodeImpl::ARCTAN);
    chr_id    = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "chr",
                               (RoutineCode) RoutineCodeImpl::CHR);
    cos_id    = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "cos",
                               (RoutineCode) RoutineCodeImpl::COS);
    eof_id    = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "eof",
                               (RoutineCode) RoutineCodeImpl::EOF_FUNCTION);
    eoln_id   = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "eoln",
                               (RoutineCode) RoutineCodeImpl::EOLN_FUNCTION);
    exp_id    = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "exp",
                               (RoutineCode) RoutineCodeImpl::EXP);
    ln_id     = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "ln",
                               (RoutineCode) RoutineCodeImpl::LN);
    odd_id    = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "odd",
                               (RoutineCode) RoutineCodeImpl::ODD);
    ord_id    = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "ord",
                               (RoutineCode) RoutineCodeImpl::ORD);
    pred_id   = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "pred",
                               (RoutineCode) RoutineCodeImpl::PRED);
    round_id  = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "round",
                               (RoutineCode) RoutineCodeImpl::ROUND);
    sin_id    = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "sin",
                               (RoutineCode) RoutineCodeImpl::SIN);
    sqr_id    = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "sqr",
                               (RoutineCode) RoutineCodeImpl::SQR);
    sqrt_id   = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "sqrt",
                               (RoutineCode) RoutineCodeImpl::SQRT);
    succ_id   = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "succ",
                               (RoutineCode) RoutineCodeImpl::SUCC);
    trunc_id  = enter_standard(symtab_stack,
                               (Definition) DF_FUNCTION,
                               "trunc",
                               (RoutineCode) RoutineCodeImpl::TRUNC);
}

SymTabEntry *Predefined::enter_standard(SymTabStack *symtab_stack,
                                        Definition defn, string name,
                                        RoutineCode routine_code)
{
    SymTabEntry *proc_id = symtab_stack->enter_local(name);
    proc_id->set_definition(defn);
    proc_id->set_attribute((SymTabKey) ROUTINE_CODE,
                           new EntryValue(routine_code));

    return proc_id;
}

}}}  // namespace wci::intermediate::symtabimpl
