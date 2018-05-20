#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#include "common.hpp"



namespace backend
{

    enum class ArrayType
    {
        atype_boolean,
        atype_char,
        atype_float,
        atype_double,
        atype_byte,
        atype_short,
        atype_int,
        atype_long,
    };

    /**
     *  @class : JasminEmitter
     *
     *  This class is responsible for directly emitting code to the output assembly file
     *  Each method has its own template for the instruction, some are simple, and some are more involved
     *  This will be the only and direct interface for handling emitting code
     *
     *  @note : https://cs.au.dk/~mis/dOvs/jvmspec/ref-Java.html
     */

    class JasminEmitter
    {
    public:

        JasminEmitter(std::ofstream & ofile);

    private:

        const char NEW_LINE = '\n';
        const char TAB      = '\t';

        std::ofstream & ofile;

        /// @ {
        void emit_default_constructor();
        void emit_public_method_signature(const std::string & method_name, const std::vector <std::string> & args, const std::string & return_type);
        void emit_class_variable(const std::string & variable, const char type_letter);
        void emit_main_class(const std::string & program_name);
        void emit_printf(const std::string & format_string, const std::map <uint32_t, std::string> & variables);
        /// @ }

        /// @ { Local Variable Instructions
        void emit_ret(const int32_t value);
        void emit_aload(const int32_t value);
        void emit_astore(const int32_t value);
        void emit_dload(const int32_t value);
        void emit_dstore(const int32_t value);
        void emit_fload(const int32_t value);
        void emit_fstore(const int32_t value);
        void emit_iload(const int32_t value);
        void emit_istore(const int32_t value);
        void emit_lload(const int32_t value);
        void emit_lstore(const int32_t value);
        /// @ }

        /// @ { Branch Instructions
        void emit_goto(const std::string & label);
        void emit_goto_w(const std::string & label);
        void emit_if_acmpeq(const std::string & label);
        void emit_if_acmpne(const std::string & label);
        void emit_if_icmpeq(const std::string & label);
        void emit_if_icmpge(const std::string & label);
        void emit_if_icmpgt(const std::string & label);
        void emit_if_icmple(const std::string & label);
        void emit_if_icmplt(const std::string & label);
        void emit_if_icmpne(const std::string & label);
        void emit_ifeq(const std::string & label);
        void emit_ifge(const std::string & label);
        void emit_ifgt(const std::string & label);
        void emit_ifle(const std::string & label);
        void emit_iflt(const std::string & label);
        void emit_ifne(const std::string & label);
        void emit_ifnonnull(const std::string & label);
        void emit_ifnull(const std::string & label);
        void emit_jsr(const std::string & label);
        void emit_jsr_w(const std::string & label);
        /// @ }

        /// @ { Class + Object Creation
        void emit_anewarray(const std::string & type);
        void emit_checkcast(const std::string & type);
        void emit_instanceof(const std::string & type);
        void emit_new(const std::string & type);
        /// @ }

        /// @ { Method Invokation
        void emit_invokenonvirtual(const std::string & method);
        void emit_invokestatic(const std::string & method);
        void emit_invokevirtual(const std::string & method);
        /// @ }

        /// @ { Field Manipulation Instructions
        void emit_getfield(const std::string & descriptor);
        void emit_getstatic(const std::string & descriptor);
        void emit_putfield(const std::string & descriptor);
        void emit_putstatic(const std::string & descriptor);
        /// @ }

        /// @ { Array Creation Instructions
        void emit_newarray(const ArrayType type);
        /// @ }

        /// @ { Load Value Instructions
        void emit_ldc(const std::string & value);
        void emit_ldc2_w(const std::string & value);
        /// @ }

        /// @ { Switch Instruction
        void emit_lookupswitch(const std::map <std::string, std::string> & switch_map);
        void emit_tableswitch(const uint32_t low, const uint32_t high, const std::vector <std::string> & table_map, const std::string & default_label);
        /// @ }

        /// @ { No Parameter Instructions
        void emit_aaload();
        void emit_aastore();
        void emit_aconst_null();
        void emit_aload_0();
        void emit_aload_1();
        void emit_aload_2();
        void emit_aload_3();
        void emit_areturn();
        void emit_arraylength();
        void emit_astore_0();
        void emit_astore_1();
        void emit_astore_2();
        void emit_astore_3();
        void emit_athrow();
        void emit_baload();
        void emit_bastore();
        void emit_breakpoint();
        void emit_caload();
        void emit_castore();
        void emit_d2f();
        void emit_d2i();
        void emit_d2l();
        void emit_dadd();
        void emit_daload();
        void emit_dastore();
        void emit_dcmpg();
        void emit_dcmpl();
        void emit_dconst_0();
        void emit_dconst_1();
        void emit_ddiv();
        void emit_dload_0();
        void emit_dload_1();
        void emit_dload_2();
        void emit_dload_3();
        void emit_dmul();
        void emit_dneg();
        void emit_drem();
        void emit_dreturn();
        void emit_dstore_0();
        void emit_dstore_1();
        void emit_dstore_2();
        void emit_dstore_3();
        void emit_dsub();
        void emit_dup();
        void emit_dup2();
        void emit_dup2_x1();
        void emit_dup2_x2();
        void emit_dup_x1();
        void emit_dup_x2();
        void emit_f2d();
        void emit_f2i();
        void emit_f2l();
        void emit_fadd();
        void emit_faload();
        void emit_fastore();
        void emit_fcmpg();
        void emit_fcmpl();
        void emit_fconst_0();
        void emit_fconst_1();
        void emit_fconst_2();
        void emit_fdiv();
        void emit_fload_0();
        void emit_fload_1();
        void emit_fload_2();
        void emit_fload_3();
        void emit_fmul();
        void emit_fneg();
        void emit_frem();
        void emit_freturn();
        void emit_fstore_0();
        void emit_fstore_1();
        void emit_fstore_2();
        void emit_fstore_3();
        void emit_fsub();
        void emit_i2d();
        void emit_i2f();
        void emit_i2l();
        void emit_iadd();
        void emit_iaload();
        void emit_iand();
        void emit_iastore();
        void emit_iconst_0();
        void emit_iconst_1();
        void emit_iconst_2();
        void emit_iconst_3();
        void emit_iconst_4();
        void emit_iconst_5();
        void emit_iconst_m1();
        void emit_idiv();
        void emit_iload_0();
        void emit_iload_1();
        void emit_iload_2();
        void emit_iload_3();
        void emit_imul();
        void emit_ineg();
        void emit_int2byte();
        void emit_int2char();
        void emit_int2short();
        void emit_ior();
        void emit_irem();
        void emit_ireturn();
        void emit_ishl();
        void emit_ishr();
        void emit_istore_0();
        void emit_istore_1();
        void emit_istore_2();
        void emit_istore_3();
        void emit_isub();
        void emit_iushr();
        void emit_ixor();
        void emit_l2d();
        void emit_l2f();
        void emit_l2i();
        void emit_ladd();
        void emit_laload();
        void emit_land();
        void emit_lastore();
        void emit_lcmp();
        void emit_lconst_0();
        void emit_lconst_1();
        void emit_ldiv();
        void emit_lload_0();
        void emit_lload_1();
        void emit_lload_2();
        void emit_lload_3();
        void emit_lmul();
        void emit_lneg();
        void emit_lor();
        void emit_lrem();
        void emit_lreturn();
        void emit_lshl();
        void emit_lshr();
        void emit_lstore_0();
        void emit_lstore_1();
        void emit_lstore_2();
        void emit_lstore_3();
        void emit_lsub();
        void emit_lushr();
        void emit_lxor();
        void emit_monitorenter();
        void emit_monitorexit();
        void emit_nop();
        void emit_pop();
        void emit_pop2();
        void emit_return();
        void emit_saload();
        void emit_sastore();
        void emit_swap();
        /// @ }
    };

} /// backend
