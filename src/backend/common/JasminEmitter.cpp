#include "JasminEmitter.hpp"

/// https://cs.au.dk/~mis/dOvs/jvmspec/ref-Java.html



namespace backend
{

    JasminEmitter::JasminEmitter(std::ofstream & ofile) : ofile(ofile)
    {
        /// Empty
    }

    /// @ { Local Variable Instructions
    void JasminEmitter::emit_aload(const std::string & value)  { ofile << TAB << "aload "  << value << NEW_LINE; }
    void JasminEmitter::emit_astore(const std::string & value) { ofile << TAB << "astore " << value << NEW_LINE; }
    void JasminEmitter::emit_dload(const std::string & value)  { ofile << TAB << "dload "  << value << NEW_LINE; }
    void JasminEmitter::emit_dstore(const std::string & value) { ofile << TAB << "dstore " << value << NEW_LINE; }
    void JasminEmitter::emit_fload(const std::string & value)  { ofile << TAB << "fload "  << value << NEW_LINE; }
    void JasminEmitter::emit_fstore(const std::string & value) { ofile << TAB << "fstore " << value << NEW_LINE; }
    void JasminEmitter::emit_iload(const std::string & value)  { ofile << TAB << "iload "  << value << NEW_LINE; }
    void JasminEmitter::emit_istore(const std::string & value) { ofile << TAB << "istore " << value << NEW_LINE; }
    void JasminEmitter::emit_lload(const std::string & value)  { ofile << TAB << "lload "  << value << NEW_LINE; }
    void JasminEmitter::emit_lstore(const std::string & value) { ofile << TAB << "lstore " << value << NEW_LINE; }
    /// @ }

    /// @ { Branch Instructions
    void JasminEmitter::emit_goto(const std::string & label)        { ofile << TAB << "goto "      << label << NEW_LINE; }
    void JasminEmitter::emit_goto_w(const std::string & label)      { ofile << TAB << "goto_w "    << label << NEW_LINE; }
    void JasminEmitter::emit_if_acmpeq(const std::string & label)   { ofile << TAB << "if_acmpeq " << label << NEW_LINE; }
    void JasminEmitter::emit_if_acmpne(const std::string & label)   { ofile << TAB << "if_acmpne " << label << NEW_LINE; }
    void JasminEmitter::emit_if_icmpeq(const std::string & label)   { ofile << TAB << "if_icmpeq " << label << NEW_LINE; }
    void JasminEmitter::emit_if_icmpge(const std::string & label)   { ofile << TAB << "if_icmpge " << label << NEW_LINE; }
    void JasminEmitter::emit_if_icmpgt(const std::string & label)   { ofile << TAB << "if_icmpgt " << label << NEW_LINE; }
    void JasminEmitter::emit_if_icmple(const std::string & label)   { ofile << TAB << "if_icmple " << label << NEW_LINE; }
    void JasminEmitter::emit_if_icmplt(const std::string & label)   { ofile << TAB << "if_icmplt " << label << NEW_LINE; }
    void JasminEmitter::emit_if_icmpne(const std::string & label)   { ofile << TAB << "if_icmpne " << label << NEW_LINE; }
    void JasminEmitter::emit_ifeq(const std::string & label)        { ofile << TAB << "ifeq "      << label << NEW_LINE; }
    void JasminEmitter::emit_ifge(const std::string & label)        { ofile << TAB << "ifge "      << label << NEW_LINE; }
    void JasminEmitter::emit_ifgt(const std::string & label)        { ofile << TAB << "ifgt "      << label << NEW_LINE; }
    void JasminEmitter::emit_ifle(const std::string & label)        { ofile << TAB << "ifle "      << label << NEW_LINE; }
    void JasminEmitter::emit_iflt(const std::string & label)        { ofile << TAB << "iflt "      << label << NEW_LINE; }
    void JasminEmitter::emit_ifne(const std::string & label)        { ofile << TAB << "ifne "      << label << NEW_LINE; }
    void JasminEmitter::emit_ifnonnull(const std::string & label)   { ofile << TAB << "ifnonnull " << label << NEW_LINE; }
    void JasminEmitter::emit_ifnull(const std::string & label)      { ofile << TAB << "ifnull "    << label << NEW_LINE; }
    void JasminEmitter::emit_jsr(const std::string & label)         { ofile << TAB << "jsr "       << label << NEW_LINE; }
    void JasminEmitter::emit_jsr_w(const std::string & label)       { ofile << TAB << "jsr_w "     << label << NEW_LINE; }
    /// @ }

    /// @ { Class + Object Creation
    void JasminEmitter::emit_anewarray(const std::string & type)  { ofile << TAB << "anewarray "  << type << NEW_LINE; }
    void JasminEmitter::emit_checkcast(const std::string & type)  { ofile << TAB << "checkcast "  << type << NEW_LINE; }
    void JasminEmitter::emit_instanceof(const std::string & type) { ofile << TAB << "instanceof " << type << NEW_LINE; }
    void JasminEmitter::emit_new(const std::string & type)        { ofile << TAB << "new "        << type << NEW_LINE; }
    /// @ }

    /// @ { Method Invokation
    void JasminEmitter::emit_invokenonvirtual(const std::string & method) { ofile << TAB << "invokenonvirtual " << method << NEW_LINE; }
    void JasminEmitter::emit_invokestatic(const std::string & method)     { ofile << TAB << "invokestatic "     << method << NEW_LINE; }
    void JasminEmitter::emit_invokevirtual(const std::string & method)    { ofile << TAB << "invokevirtual "    << method << NEW_LINE; }
    /// @ }

    /// @ { Field Manipulation Instructions
    void JasminEmitter::emit_getfield(const std::string & descriptor)  { ofile << TAB << "getfield "  << descriptor << NEW_LINE; }
    void JasminEmitter::emit_getstatic(const std::string & descriptor) { ofile << TAB << "getstatic " << descriptor << NEW_LINE; }
    void JasminEmitter::emit_putfield(const std::string & descriptor)  { ofile << TAB << "putfield "  << descriptor << NEW_LINE; }
    void JasminEmitter::emit_putstatic(const std::string & descriptor) { ofile << TAB << "putstatic " << descriptor << NEW_LINE; }
    /// @ }

    /// @ { Array Creation Instructions
    void JasminEmitter::emit_newarray(const ArrayType type)
    {
        switch (type)
        {
            case ArrayType::atype_boolean : ofile << TAB << "anewarray int"              << NEW_LINE; break;
            case ArrayType::atype_char    : ofile << TAB << "anewarray char"             << NEW_LINE; break;
            case ArrayType::atype_float   : ofile << TAB << "anewarray float"            << NEW_LINE; break;
            case ArrayType::atype_double  : ofile << TAB << "anewarray double"           << NEW_LINE; break;
            case ArrayType::atype_byte    : ofile << TAB << "anewarray byte"             << NEW_LINE; break;
            case ArrayType::atype_short   : ofile << TAB << "anewarray short"            << NEW_LINE; break;
            case ArrayType::atype_int     : ofile << TAB << "anewarray int"              << NEW_LINE; break;
            case ArrayType::atype_long    : ofile << TAB << "anewarray long"             << NEW_LINE; break;
            case ArrayType::atype_object  : ofile << TAB << "anewarray java/lang/Object" << NEW_LINE; break;
            default:
                THROW_EXCEPTION(InvalidCase, "Invalid ArrayType");
        }
    }
    /// @ }

    /// @ { Load Value Instructions
    void JasminEmitter::emit_ldc(const std::string & value)
    {
        ofile << TAB << "ldc " << value << NEW_LINE;
    }

    void JasminEmitter::emit_ldc2_w(const std::string & value)
    {
        ofile << TAB << "ldc2_w " << value;
        if (value.find(".") == std::string::npos)
        {
            ofile << ".0";
        }
        ofile << NEW_LINE;
    }
    /// @ }

    /// @ { Switch Instruction
    void JasminEmitter::emit_lookupswitch(const std::map <std::string, std::string> & switch_map)
    {
        /// https://cs.au.dk/~mis/dOvs/jvmspec/ref--41.html
        ofile << TAB << "lookupswitch" << NEW_LINE;
        for (const auto & pair : switch_map)
        {
            ofile << TAB << TAB << pair.first << ": " << pair.second << NEW_LINE;
        }
    }
    void JasminEmitter::emit_tableswitch(const uint32_t low, const uint32_t high, const std::vector <std::string> & table_map, const std::string & default_label)
    {
        /// https://cs.au.dk/~mis/dOvs/jvmspec/ref-tableswi.html
        ofile << TAB << "tableswitch " << low << " " << high << NEW_LINE;
        for (const auto & label : table_map)
        {
            ofile << TAB << TAB << label << NEW_LINE;
        }
        ofile << TAB << TAB << "default: " << default_label << NEW_LINE;
    }
    /// @ }

    /// @ { No Parameter Instructions
    void JasminEmitter::emit_aaload()       { ofile << TAB << "aaload"       << NEW_LINE; };
    void JasminEmitter::emit_aastore()      { ofile << TAB << "aastore"      << NEW_LINE; };
    void JasminEmitter::emit_aconst_null()  { ofile << TAB << "aconst_null"  << NEW_LINE; };
    void JasminEmitter::emit_aload_0()      { ofile << TAB << "aload_0"      << NEW_LINE; };
    void JasminEmitter::emit_aload_1()      { ofile << TAB << "aload_1"      << NEW_LINE; };
    void JasminEmitter::emit_aload_2()      { ofile << TAB << "aload_2"      << NEW_LINE; };
    void JasminEmitter::emit_aload_3()      { ofile << TAB << "aload_3"      << NEW_LINE; };
    void JasminEmitter::emit_areturn()      { ofile << TAB << "areturn"      << NEW_LINE; };
    void JasminEmitter::emit_arraylength()  { ofile << TAB << "arraylength"  << NEW_LINE; };
    void JasminEmitter::emit_astore_0()     { ofile << TAB << "astore_0"     << NEW_LINE; };
    void JasminEmitter::emit_astore_1()     { ofile << TAB << "astore_1"     << NEW_LINE; };
    void JasminEmitter::emit_astore_2()     { ofile << TAB << "astore_2"     << NEW_LINE; };
    void JasminEmitter::emit_astore_3()     { ofile << TAB << "astore_3"     << NEW_LINE; };
    void JasminEmitter::emit_athrow()       { ofile << TAB << "athrow"       << NEW_LINE; };
    void JasminEmitter::emit_baload()       { ofile << TAB << "baload"       << NEW_LINE; };
    void JasminEmitter::emit_bastore()      { ofile << TAB << "bastore"      << NEW_LINE; };
    void JasminEmitter::emit_breakpoint()   { ofile << TAB << "breakpoint"   << NEW_LINE; };
    void JasminEmitter::emit_caload()       { ofile << TAB << "caload"       << NEW_LINE; };
    void JasminEmitter::emit_castore()      { ofile << TAB << "castore"      << NEW_LINE; };
    void JasminEmitter::emit_d2f()          { ofile << TAB << "d2f"          << NEW_LINE; };
    void JasminEmitter::emit_d2i()          { ofile << TAB << "d2i"          << NEW_LINE; };
    void JasminEmitter::emit_d2l()          { ofile << TAB << "d2l"          << NEW_LINE; };
    void JasminEmitter::emit_dadd()         { ofile << TAB << "dadd"         << NEW_LINE; };
    void JasminEmitter::emit_daload()       { ofile << TAB << "daload"       << NEW_LINE; };
    void JasminEmitter::emit_dastore()      { ofile << TAB << "dastore"      << NEW_LINE; };
    void JasminEmitter::emit_dcmpg()        { ofile << TAB << "dcmpg"        << NEW_LINE; };
    void JasminEmitter::emit_dcmpl()        { ofile << TAB << "dcmpl"        << NEW_LINE; };
    void JasminEmitter::emit_dconst_0()     { ofile << TAB << "dconst_0"     << NEW_LINE; };
    void JasminEmitter::emit_dconst_1()     { ofile << TAB << "dconst_1"     << NEW_LINE; };
    void JasminEmitter::emit_ddiv()         { ofile << TAB << "ddiv"         << NEW_LINE; };
    void JasminEmitter::emit_dload_0()      { ofile << TAB << "dload_0"      << NEW_LINE; };
    void JasminEmitter::emit_dload_1()      { ofile << TAB << "dload_1"      << NEW_LINE; };
    void JasminEmitter::emit_dload_2()      { ofile << TAB << "dload_2"      << NEW_LINE; };
    void JasminEmitter::emit_dload_3()      { ofile << TAB << "dload_3"      << NEW_LINE; };
    void JasminEmitter::emit_dmul()         { ofile << TAB << "dmul"         << NEW_LINE; };
    void JasminEmitter::emit_dneg()         { ofile << TAB << "dneg"         << NEW_LINE; };
    void JasminEmitter::emit_drem()         { ofile << TAB << "drem"         << NEW_LINE; };
    void JasminEmitter::emit_dreturn()      { ofile << TAB << "dreturn"      << NEW_LINE; };
    void JasminEmitter::emit_dstore_0()     { ofile << TAB << "dstore_0"     << NEW_LINE; };
    void JasminEmitter::emit_dstore_1()     { ofile << TAB << "dstore_1"     << NEW_LINE; };
    void JasminEmitter::emit_dstore_2()     { ofile << TAB << "dstore_2"     << NEW_LINE; };
    void JasminEmitter::emit_dstore_3()     { ofile << TAB << "dstore_3"     << NEW_LINE; };
    void JasminEmitter::emit_dsub()         { ofile << TAB << "dsub"         << NEW_LINE; };
    void JasminEmitter::emit_dup()          { ofile << TAB << "dup"          << NEW_LINE; };
    void JasminEmitter::emit_dup2()         { ofile << TAB << "dup2"         << NEW_LINE; };
    void JasminEmitter::emit_dup2_x1()      { ofile << TAB << "dup2_x1"      << NEW_LINE; };
    void JasminEmitter::emit_dup2_x2()      { ofile << TAB << "dup2_x2"      << NEW_LINE; };
    void JasminEmitter::emit_dup_x1()       { ofile << TAB << "dup_x1"       << NEW_LINE; };
    void JasminEmitter::emit_dup_x2()       { ofile << TAB << "dup_x2"       << NEW_LINE; };
    void JasminEmitter::emit_f2d()          { ofile << TAB << "f2d"          << NEW_LINE; };
    void JasminEmitter::emit_f2i()          { ofile << TAB << "f2i"          << NEW_LINE; };
    void JasminEmitter::emit_f2l()          { ofile << TAB << "f2l"          << NEW_LINE; };
    void JasminEmitter::emit_fadd()         { ofile << TAB << "fadd"         << NEW_LINE; };
    void JasminEmitter::emit_faload()       { ofile << TAB << "faload"       << NEW_LINE; };
    void JasminEmitter::emit_fastore()      { ofile << TAB << "fastore"      << NEW_LINE; };
    void JasminEmitter::emit_fcmpg()        { ofile << TAB << "fcmpg"        << NEW_LINE; };
    void JasminEmitter::emit_fcmpl()        { ofile << TAB << "fcmpl"        << NEW_LINE; };
    void JasminEmitter::emit_fconst_0()     { ofile << TAB << "fconst_0"     << NEW_LINE; };
    void JasminEmitter::emit_fconst_1()     { ofile << TAB << "fconst_1"     << NEW_LINE; };
    void JasminEmitter::emit_fconst_2()     { ofile << TAB << "fconst_2"     << NEW_LINE; };
    void JasminEmitter::emit_fdiv()         { ofile << TAB << "fdiv"         << NEW_LINE; };
    void JasminEmitter::emit_fload_0()      { ofile << TAB << "fload_0"      << NEW_LINE; };
    void JasminEmitter::emit_fload_1()      { ofile << TAB << "fload_1"      << NEW_LINE; };
    void JasminEmitter::emit_fload_2()      { ofile << TAB << "fload_2"      << NEW_LINE; };
    void JasminEmitter::emit_fload_3()      { ofile << TAB << "fload_3"      << NEW_LINE; };
    void JasminEmitter::emit_fmul()         { ofile << TAB << "fmul"         << NEW_LINE; };
    void JasminEmitter::emit_fneg()         { ofile << TAB << "fneg"         << NEW_LINE; };
    void JasminEmitter::emit_frem()         { ofile << TAB << "frem"         << NEW_LINE; };
    void JasminEmitter::emit_freturn()      { ofile << TAB << "freturn"      << NEW_LINE; };
    void JasminEmitter::emit_fstore_0()     { ofile << TAB << "fstore_0"     << NEW_LINE; };
    void JasminEmitter::emit_fstore_1()     { ofile << TAB << "fstore_1"     << NEW_LINE; };
    void JasminEmitter::emit_fstore_2()     { ofile << TAB << "fstore_2"     << NEW_LINE; };
    void JasminEmitter::emit_fstore_3()     { ofile << TAB << "fstore_3"     << NEW_LINE; };
    void JasminEmitter::emit_fsub()         { ofile << TAB << "fsub"         << NEW_LINE; };
    void JasminEmitter::emit_i2d()          { ofile << TAB << "i2d"          << NEW_LINE; };
    void JasminEmitter::emit_i2f()          { ofile << TAB << "i2f"          << NEW_LINE; };
    void JasminEmitter::emit_i2l()          { ofile << TAB << "i2l"          << NEW_LINE; };
    void JasminEmitter::emit_iadd()         { ofile << TAB << "iadd"         << NEW_LINE; };
    void JasminEmitter::emit_iaload()       { ofile << TAB << "iaload"       << NEW_LINE; };
    void JasminEmitter::emit_iand()         { ofile << TAB << "iand"         << NEW_LINE; };
    void JasminEmitter::emit_iastore()      { ofile << TAB << "iastore"      << NEW_LINE; };
    void JasminEmitter::emit_iconst_0()     { ofile << TAB << "iconst_0"     << NEW_LINE; };
    void JasminEmitter::emit_iconst_1()     { ofile << TAB << "iconst_1"     << NEW_LINE; };
    void JasminEmitter::emit_iconst_2()     { ofile << TAB << "iconst_2"     << NEW_LINE; };
    void JasminEmitter::emit_iconst_3()     { ofile << TAB << "iconst_3"     << NEW_LINE; };
    void JasminEmitter::emit_iconst_4()     { ofile << TAB << "iconst_4"     << NEW_LINE; };
    void JasminEmitter::emit_iconst_5()     { ofile << TAB << "iconst_5"     << NEW_LINE; };
    void JasminEmitter::emit_iconst_m1()    { ofile << TAB << "iconst_m1"    << NEW_LINE; };
    void JasminEmitter::emit_idiv()         { ofile << TAB << "idiv"         << NEW_LINE; };
    void JasminEmitter::emit_iload_0()      { ofile << TAB << "iload_0"      << NEW_LINE; };
    void JasminEmitter::emit_iload_1()      { ofile << TAB << "iload_1"      << NEW_LINE; };
    void JasminEmitter::emit_iload_2()      { ofile << TAB << "iload_2"      << NEW_LINE; };
    void JasminEmitter::emit_iload_3()      { ofile << TAB << "iload_3"      << NEW_LINE; };
    void JasminEmitter::emit_imul()         { ofile << TAB << "imul"         << NEW_LINE; };
    void JasminEmitter::emit_ineg()         { ofile << TAB << "ineg"         << NEW_LINE; };
    void JasminEmitter::emit_int2byte()     { ofile << TAB << "int2byte"     << NEW_LINE; };
    void JasminEmitter::emit_int2char()     { ofile << TAB << "int2char"     << NEW_LINE; };
    void JasminEmitter::emit_int2short()    { ofile << TAB << "int2short"    << NEW_LINE; };
    void JasminEmitter::emit_ior()          { ofile << TAB << "ior"          << NEW_LINE; };
    void JasminEmitter::emit_irem()         { ofile << TAB << "irem"         << NEW_LINE; };
    void JasminEmitter::emit_ireturn()      { ofile << TAB << "ireturn"      << NEW_LINE; };
    void JasminEmitter::emit_ishl()         { ofile << TAB << "ishl"         << NEW_LINE; };
    void JasminEmitter::emit_ishr()         { ofile << TAB << "ishr"         << NEW_LINE; };
    void JasminEmitter::emit_istore_0()     { ofile << TAB << "istore_0"     << NEW_LINE; };
    void JasminEmitter::emit_istore_1()     { ofile << TAB << "istore_1"     << NEW_LINE; };
    void JasminEmitter::emit_istore_2()     { ofile << TAB << "istore_2"     << NEW_LINE; };
    void JasminEmitter::emit_istore_3()     { ofile << TAB << "istore_3"     << NEW_LINE; };
    void JasminEmitter::emit_isub()         { ofile << TAB << "isub"         << NEW_LINE; };
    void JasminEmitter::emit_iushr()        { ofile << TAB << "iushr"        << NEW_LINE; };
    void JasminEmitter::emit_ixor()         { ofile << TAB << "ixor"         << NEW_LINE; };
    void JasminEmitter::emit_l2d()          { ofile << TAB << "l2d"          << NEW_LINE; };
    void JasminEmitter::emit_l2f()          { ofile << TAB << "l2f"          << NEW_LINE; };
    void JasminEmitter::emit_l2i()          { ofile << TAB << "l2i"          << NEW_LINE; };
    void JasminEmitter::emit_ladd()         { ofile << TAB << "ladd"         << NEW_LINE; };
    void JasminEmitter::emit_laload()       { ofile << TAB << "laload"       << NEW_LINE; };
    void JasminEmitter::emit_land()         { ofile << TAB << "land"         << NEW_LINE; };
    void JasminEmitter::emit_lastore()      { ofile << TAB << "lastore"      << NEW_LINE; };
    void JasminEmitter::emit_lcmp()         { ofile << TAB << "lcmp"         << NEW_LINE; };
    void JasminEmitter::emit_lconst_0()     { ofile << TAB << "lconst_0"     << NEW_LINE; };
    void JasminEmitter::emit_lconst_1()     { ofile << TAB << "lconst_1"     << NEW_LINE; };
    void JasminEmitter::emit_ldiv()         { ofile << TAB << "ldiv"         << NEW_LINE; };
    void JasminEmitter::emit_lload_0()      { ofile << TAB << "lload_0"      << NEW_LINE; };
    void JasminEmitter::emit_lload_1()      { ofile << TAB << "lload_1"      << NEW_LINE; };
    void JasminEmitter::emit_lload_2()      { ofile << TAB << "lload_2"      << NEW_LINE; };
    void JasminEmitter::emit_lload_3()      { ofile << TAB << "lload_3"      << NEW_LINE; };
    void JasminEmitter::emit_lmul()         { ofile << TAB << "lmul"         << NEW_LINE; };
    void JasminEmitter::emit_lneg()         { ofile << TAB << "lneg"         << NEW_LINE; };
    void JasminEmitter::emit_lor()          { ofile << TAB << "lor"          << NEW_LINE; };
    void JasminEmitter::emit_lrem()         { ofile << TAB << "lrem"         << NEW_LINE; };
    void JasminEmitter::emit_lreturn()      { ofile << TAB << "lreturn"      << NEW_LINE; };
    void JasminEmitter::emit_lshl()         { ofile << TAB << "lshl"         << NEW_LINE; };
    void JasminEmitter::emit_lshr()         { ofile << TAB << "lshr"         << NEW_LINE; };
    void JasminEmitter::emit_lstore_0()     { ofile << TAB << "lstore_0"     << NEW_LINE; };
    void JasminEmitter::emit_lstore_1()     { ofile << TAB << "lstore_1"     << NEW_LINE; };
    void JasminEmitter::emit_lstore_2()     { ofile << TAB << "lstore_2"     << NEW_LINE; };
    void JasminEmitter::emit_lstore_3()     { ofile << TAB << "lstore_3"     << NEW_LINE; };
    void JasminEmitter::emit_lsub()         { ofile << TAB << "lsub"         << NEW_LINE; };
    void JasminEmitter::emit_lushr()        { ofile << TAB << "lushr"        << NEW_LINE; };
    void JasminEmitter::emit_lxor()         { ofile << TAB << "lxor"         << NEW_LINE; };
    void JasminEmitter::emit_monitorenter() { ofile << TAB << "monitorenter" << NEW_LINE; };
    void JasminEmitter::emit_monitorexit()  { ofile << TAB << "monitorexit"  << NEW_LINE; };
    void JasminEmitter::emit_nop()          { ofile << TAB << "nop"          << NEW_LINE; };
    void JasminEmitter::emit_pop()          { ofile << TAB << "pop"          << NEW_LINE; };
    void JasminEmitter::emit_pop2()         { ofile << TAB << "pop2"         << NEW_LINE; };
    void JasminEmitter::emit_return()       { ofile << TAB << "return"       << NEW_LINE; };
    void JasminEmitter::emit_saload()       { ofile << TAB << "saload"       << NEW_LINE; };
    void JasminEmitter::emit_sastore()      { ofile << TAB << "sastore"      << NEW_LINE; };
    void JasminEmitter::emit_swap()         { ofile << TAB << "swap"         << NEW_LINE; };
    /// @ }


    void JasminEmitter::emit_default_constructor()
    {
        ofile                                                              << NEW_LINE;
        ofile        << ".method public <init>()V"                         << NEW_LINE;
        ofile                                                              << NEW_LINE;
        ofile << TAB << "\taload_0"                                        << NEW_LINE;
        ofile << TAB << "\tinvokenonvirtual    java/lang/Object/<init>()V" << NEW_LINE;
        ofile << TAB << "\treturn"                                         << NEW_LINE;
        ofile                                                              << NEW_LINE;
        ofile << TAB << ".limit locals 1"                                  << NEW_LINE;
        ofile << TAB << ".limit stack  1"                                  << NEW_LINE;
        ofile        << ".end method"                                      << NEW_LINE;
    }

    void JasminEmitter::emit_public_method_signature(const std::string & method_name, const std::vector <std::string> & args, const std::string & return_type)
    {
        ofile << ".method public static " << method_name << "(";

        for (const auto & arg : args)
        {
            ofile << arg;
        }

        ofile << ")" << return_type << NEW_LINE;
    }

    void JasminEmitter::emit_class_variable(const std::string & variable, const std::string & type_letter)
    {
        ofile << ".field private static " << variable << " " << type_letter << NEW_LINE;
    }

    void JasminEmitter::emit_main_class(const std::string & program_name)
    {
        ofile << ".class public " << program_name << NEW_LINE;
        ofile << ".super java/lang/Object"        << NEW_LINE;
        ofile                                     << NEW_LINE;
    }

    void JasminEmitter::emit_printf(const std::string & format_string, const std::map <uint32_t, std::string> & variables)
    {
        ofile << TAB << "ldc " << format_string      << NEW_LINE;
        ofile << TAB << "ldc " << variables.size()   << NEW_LINE;
        ofile << TAB << "anewarray java/lang/Object" << NEW_LINE;
        ofile << TAB << "dup"                        << NEW_LINE;

        uint32_t i = 0;
        for (const auto & pair : variables)
        {
            ofile << TAB << "ldc "          << i++          << NEW_LINE;
            ofile << TAB << "iload "        << pair.first   << NEW_LINE;
            ofile << TAB << "invokestatic " << pair.second  << NEW_LINE;
            ofile << TAB << "aastore"                       << NEW_LINE;
        }

        ofile << TAB << "invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;" << NEW_LINE;
    }

    void JasminEmitter::emit_comment(const std::string & comment)
    {
        ofile << TAB << "; " << comment << NEW_LINE;
    }

    void JasminEmitter::emit_comment_custom(const std::string & comment, const uint8_t indents)
    {
        for (uint8_t i = 0; i < indents; i++)
        {
            ofile << TAB;
        }
        ofile << "; " << comment << NEW_LINE;
    }

} /// backend
