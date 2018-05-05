#pragma once



enum class ArrayType
{
    array_type_int,
    array_type_int8_t,
    array_type_int16_t,
    array_type_int32_t,
    array_type_uint8_t,
    array_type_uint16_t,
    array_type_uint32_t,
    array_type_char,
    array_type_float,
};

enum class ConstantObjectType
{
    constant_object_type_string,
    constant_object_type_float,
    constant_object_type_uint,
    constant_object_type_int,
};

typedef struct
{
    std::string s;
    float f;
    uint32_t ui;
    int32_t i;
    ConstantObjectType type;
} ConstantObject;

class JasminEmitter
{
public:

    JasminEmitter(ofstream * ofile);

private:

    static const char NEW_LINE = "\n";
    static const char TAB = "\n";

    ofstream * ofile;

    /// @ {
    void emit_init_method();
    void emit_method(const string method_name, const vector <string> args);
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
    void emit_goto(const std::string label);
    void emit_goto_w(const std::string label);
    void emit_if_acmpeq(const std::string label);
    void emit_if_acmpne(const std::string label);
    void emit_if_icmpeq(const std::string label);
    void emit_if_icmpge(const std::string label);
    void emit_if_icmpgt(const std::string label);
    void emit_if_icmple(const std::string label);
    void emit_if_icmplt(const std::string label);
    void emit_if_icmpne(const std::string label);
    void emit_ifeq(const std::string label);
    void emit_ifge(const std::string label);
    void emit_ifgt(const std::string label);
    void emit_ifle(const std::string label);
    void emit_iflt(const std::string label);
    void emit_ifne(const std::string label);
    void emit_ifnonnull(const std::string label);
    void emit_ifnull(const std::string label);
    void emit_jsr(const std::string label);
    void emit_jsr_w(const std::string label);
    /// @ }

    /// @ { Class + Object Creation
    void emit_anewarray(const std::string class);
    void emit_checkcast(const std::string class);
    void emit_instanceof(const std::string class);
    void emit_new(const std::string class);
    /// @ }

    /// @ { Method Invokation
    void emit_invokenonvirtual(const std::string method);
    void emit_invokestatic(const std::string method);
    void emit_invokevirtual(const std::string method);
    /// @ }

    /// @ { Field Manipulation Instructions
    void emit_getfield(const std::string descriptor);
    void emit_getstatic(const std::string descriptor);
    void emit_putfield(const std::string descriptor);
    void emit_putstatic(const std::string descriptor);
    /// @ }

    /// @ { Array Creation Instructions
    void newarray(ArrayType type);
    /// @ }

    /// @ { Load Value Instructions
    void emit_ldc(ConstantObject const_object);
    void emit_ldc_w(ConstantObject const_object);
    /// @ }

    /// @ { Switch Instruction
    void emit_lookupswitch(const map <uint32_t, std::string> switch_map);
    void emit_tableswitch(const vector <std::string> table_map);
    /// @ }

    /// @ { No Parameter Instructions
    void emit_aaload()           { ofile << "aaload"       << NEW_LINE; };
    void emit_aastore()          { ofile << "aastore"      << NEW_LINE; };
    void emit_aconst_null()      { ofile << "aconst_null"  << NEW_LINE; };
    void emit_aload_0()          { ofile << "aload_0"      << NEW_LINE; };
    void emit_aload_1()          { ofile << "aload_1"      << NEW_LINE; };
    void emit_aload_2()          { ofile << "aload_2"      << NEW_LINE; };
    void emit_aload_3()          { ofile << "aload_3"      << NEW_LINE; };
    void emit_areturn()          { ofile << "areturn"      << NEW_LINE; };
    void emit_arraylength()      { ofile << "arraylength"  << NEW_LINE; };
    void emit_astore_0()         { ofile << "astore_0"     << NEW_LINE; };
    void emit_astore_1()         { ofile << "astore_1"     << NEW_LINE; };
    void emit_astore_2()         { ofile << "astore_2"     << NEW_LINE; };
    void emit_astore_3()         { ofile << "astore_3"     << NEW_LINE; };
    void emit_athrow()           { ofile << "athrow"       << NEW_LINE; };
    void emit_baload()           { ofile << "baload"       << NEW_LINE; };
    void emit_bastore()          { ofile << "bastore"      << NEW_LINE; };
    void emit_breakpoint()       { ofile << "breakpoint"   << NEW_LINE; };
    void emit_caload()           { ofile << "caload"       << NEW_LINE; };
    void emit_castore()          { ofile << "castore"      << NEW_LINE; };
    void emit_d2f()              { ofile << "d2f"          << NEW_LINE; };
    void emit_d2i()              { ofile << "d2i"          << NEW_LINE; };
    void emit_d2l()              { ofile << "d2l"          << NEW_LINE; };
    void emit_dadd()             { ofile << "dadd"         << NEW_LINE; };
    void emit_daload()           { ofile << "daload"       << NEW_LINE; };
    void emit_dastore()          { ofile << "dastore"      << NEW_LINE; };
    void emit_dcmpg()            { ofile << "dcmpg"        << NEW_LINE; };
    void emit_dcmpl()            { ofile << "dcmpl"        << NEW_LINE; };
    void emit_dconst_0()         { ofile << "dconst_0"     << NEW_LINE; };
    void emit_dconst_1()         { ofile << "dconst_1"     << NEW_LINE; };
    void emit_ddiv()             { ofile << "ddiv"         << NEW_LINE; };
    void emit_dload_0()          { ofile << "dload_0"      << NEW_LINE; };
    void emit_dload_1()          { ofile << "dload_1"      << NEW_LINE; };
    void emit_dload_2()          { ofile << "dload_2"      << NEW_LINE; };
    void emit_dload_3()          { ofile << "dload_3"      << NEW_LINE; };
    void emit_dmul()             { ofile << "dmul"         << NEW_LINE; };
    void emit_dneg()             { ofile << "dneg"         << NEW_LINE; };
    void emit_drem()             { ofile << "drem"         << NEW_LINE; };
    void emit_dreturn()          { ofile << "dreturn"      << NEW_LINE; };
    void emit_dstore_0()         { ofile << "dstore_0"     << NEW_LINE; };
    void emit_dstore_1()         { ofile << "dstore_1"     << NEW_LINE; };
    void emit_dstore_2()         { ofile << "dstore_2"     << NEW_LINE; };
    void emit_dstore_3()         { ofile << "dstore_3"     << NEW_LINE; };
    void emit_dsub()             { ofile << "dsub"         << NEW_LINE; };
    void emit_dup()              { ofile << "dup"          << NEW_LINE; };
    void emit_dup2()             { ofile << "dup2"         << NEW_LINE; };
    void emit_dup2_x1()          { ofile << "dup2_x1"      << NEW_LINE; };
    void emit_dup2_x2()          { ofile << "dup2_x2"      << NEW_LINE; };
    void emit_dup_x1()           { ofile << "dup_x1"       << NEW_LINE; };
    void emit_dup_x2()           { ofile << "dup_x2"       << NEW_LINE; };
    void emit_f2d()              { ofile << "f2d"          << NEW_LINE; };
    void emit_f2i()              { ofile << "f2i"          << NEW_LINE; };
    void emit_f2l()              { ofile << "f2l"          << NEW_LINE; };
    void emit_fadd()             { ofile << "fadd"         << NEW_LINE; };
    void emit_faload()           { ofile << "faload"       << NEW_LINE; };
    void emit_fastore()          { ofile << "fastore"      << NEW_LINE; };
    void emit_fcmpg()            { ofile << "fcmpg"        << NEW_LINE; };
    void emit_fcmpl()            { ofile << "fcmpl"        << NEW_LINE; };
    void emit_fconst_0()         { ofile << "fconst_0"     << NEW_LINE; };
    void emit_fconst_1()         { ofile << "fconst_1"     << NEW_LINE; };
    void emit_fconst_2()         { ofile << "fconst_2"     << NEW_LINE; };
    void emit_fdiv()             { ofile << "fdiv"         << NEW_LINE; };
    void emit_fload_0()          { ofile << "fload_0"      << NEW_LINE; };
    void emit_fload_1()          { ofile << "fload_1"      << NEW_LINE; };
    void emit_fload_2()          { ofile << "fload_2"      << NEW_LINE; };
    void emit_fload_3()          { ofile << "fload_3"      << NEW_LINE; };
    void emit_fmul()             { ofile << "fmul"         << NEW_LINE; };
    void emit_fneg()             { ofile << "fneg"         << NEW_LINE; };
    void emit_frem()             { ofile << "frem"         << NEW_LINE; };
    void emit_freturn()          { ofile << "freturn"      << NEW_LINE; };
    void emit_fstore_0()         { ofile << "fstore_0"     << NEW_LINE; };
    void emit_fstore_1()         { ofile << "fstore_1"     << NEW_LINE; };
    void emit_fstore_2()         { ofile << "fstore_2"     << NEW_LINE; };
    void emit_fstore_3()         { ofile << "fstore_3"     << NEW_LINE; };
    void emit_fsub()             { ofile << "fsub"         << NEW_LINE; };
    void emit_i2d()              { ofile << "i2d"          << NEW_LINE; };
    void emit_i2f()              { ofile << "i2f"          << NEW_LINE; };
    void emit_i2l()              { ofile << "i2l"          << NEW_LINE; };
    void emit_iadd()             { ofile << "iadd"         << NEW_LINE; };
    void emit_iaload()           { ofile << "iaload"       << NEW_LINE; };
    void emit_iand()             { ofile << "iand"         << NEW_LINE; };
    void emit_iastore()          { ofile << "iastore"      << NEW_LINE; };
    void emit_iconst_0()         { ofile << "iconst_0"     << NEW_LINE; };
    void emit_iconst_1()         { ofile << "iconst_1"     << NEW_LINE; };
    void emit_iconst_2()         { ofile << "iconst_2"     << NEW_LINE; };
    void emit_iconst_3()         { ofile << "iconst_3"     << NEW_LINE; };
    void emit_iconst_4()         { ofile << "iconst_4"     << NEW_LINE; };
    void emit_iconst_5()         { ofile << "iconst_5"     << NEW_LINE; };
    void emit_iconst_m1()        { ofile << "iconst_m1"    << NEW_LINE; };
    void emit_idiv()             { ofile << "idiv"         << NEW_LINE; };
    void emit_iload_0()          { ofile << "iload_0"      << NEW_LINE; };
    void emit_iload_1()          { ofile << "iload_1"      << NEW_LINE; };
    void emit_iload_2()          { ofile << "iload_2"      << NEW_LINE; };
    void emit_iload_3()          { ofile << "iload_3"      << NEW_LINE; };
    void emit_imul()             { ofile << "imul"         << NEW_LINE; };
    void emit_ineg()             { ofile << "ineg"         << NEW_LINE; };
    void emit_int2byte()         { ofile << "int2byte"     << NEW_LINE; };
    void emit_int2char()         { ofile << "int2char"     << NEW_LINE; };
    void emit_int2short()        { ofile << "int2short"    << NEW_LINE; };
    void emit_ior()              { ofile << "ior"          << NEW_LINE; };
    void emit_irem()             { ofile << "irem"         << NEW_LINE; };
    void emit_ireturn()          { ofile << "ireturn"      << NEW_LINE; };
    void emit_ishl()             { ofile << "ishl"         << NEW_LINE; };
    void emit_ishr()             { ofile << "ishr"         << NEW_LINE; };
    void emit_istore_0()         { ofile << "istore_0"     << NEW_LINE; };
    void emit_istore_1()         { ofile << "istore_1"     << NEW_LINE; };
    void emit_istore_2()         { ofile << "istore_2"     << NEW_LINE; };
    void emit_istore_3()         { ofile << "istore_3"     << NEW_LINE; };
    void emit_isub()             { ofile << "isub"         << NEW_LINE; };
    void emit_iushr()            { ofile << "iushr"        << NEW_LINE; };
    void emit_ixor()             { ofile << "ixor"         << NEW_LINE; };
    void emit_l2d()              { ofile << "l2d"          << NEW_LINE; };
    void emit_l2f()              { ofile << "l2f"          << NEW_LINE; };
    void emit_l2i()              { ofile << "l2i"          << NEW_LINE; };
    void emit_ladd()             { ofile << "ladd"         << NEW_LINE; };
    void emit_laload()           { ofile << "laload"       << NEW_LINE; };
    void emit_land()             { ofile << "land"         << NEW_LINE; };
    void emit_lastore()          { ofile << "lastore"      << NEW_LINE; };
    void emit_lcmp()             { ofile << "lcmp"         << NEW_LINE; };
    void emit_lconst_0()         { ofile << "lconst_0"     << NEW_LINE; };
    void emit_lconst_1()         { ofile << "lconst_1"     << NEW_LINE; };
    void emit_ldiv()             { ofile << "ldiv"         << NEW_LINE; };
    void emit_lload_0()          { ofile << "lload_0"      << NEW_LINE; };
    void emit_lload_1()          { ofile << "lload_1"      << NEW_LINE; };
    void emit_lload_2()          { ofile << "lload_2"      << NEW_LINE; };
    void emit_lload_3()          { ofile << "lload_3"      << NEW_LINE; };
    void emit_lmul()             { ofile << "lmul"         << NEW_LINE; };
    void emit_lneg()             { ofile << "lneg"         << NEW_LINE; };
    void emit_lor()              { ofile << "lor"          << NEW_LINE; };
    void emit_lrem()             { ofile << "lrem"         << NEW_LINE; };
    void emit_lreturn()          { ofile << "lreturn"      << NEW_LINE; };
    void emit_lshl()             { ofile << "lshl"         << NEW_LINE; };
    void emit_lshr()             { ofile << "lshr"         << NEW_LINE; };
    void emit_lstore_0()         { ofile << "lstore_0"     << NEW_LINE; };
    void emit_lstore_1()         { ofile << "lstore_1"     << NEW_LINE; };
    void emit_lstore_2()         { ofile << "lstore_2"     << NEW_LINE; };
    void emit_lstore_3()         { ofile << "lstore_3"     << NEW_LINE; };
    void emit_lsub()             { ofile << "lsub"         << NEW_LINE; };
    void emit_lushr()            { ofile << "lushr"        << NEW_LINE; };
    void emit_lxor()             { ofile << "lxor"         << NEW_LINE; };
    void emit_monitorenter()     { ofile << "monitorenter" << NEW_LINE; };
    void emit_monitorexit()      { ofile << "monitorexit"  << NEW_LINE; };
    void emit_nop()              { ofile << "nop"          << NEW_LINE; };
    void emit_pop()              { ofile << "pop"          << NEW_LINE; };
    void emit_pop2()             { ofile << "pop2"         << NEW_LINE; };
    void emit_return()           { ofile << "return"       << NEW_LINE; };
    void emit_saload()           { ofile << "saload"       << NEW_LINE; };
    void emit_sastore()          { ofile << "sastore"      << NEW_LINE; };
    void emit_swap()             { ofile << "swap"         << NEW_LINE; };
    /// @ }
};

JasminEmitter::JasminEmitter(ofstream * ofile)
{
    if (!ofile)
    {
        throw "Invalid input <ofile>";
    }
    else
    {
        this->ofile = ofile;
    }
}

void JasminEmitter::emit_init_method()
{
    ofile                                                          << endl;
    ofile << ".method public <init>()V"                            << endl;
    ofile                                                          << endl;
    ofile << "\taload_0"                                           << endl;
    ofile << "\tinvokenonvirtual    java/lang/Object/<init>()V"    << endl;
    ofile << "\treturn"                                            << endl;
    ofile                                                          << endl;
    ofile << ".limit locals 1"                                     << endl;
    ofile << ".limit stack 1"                                      << endl;
    ofile << ".end method"                                         << endl;
}

void JasminEmitter::emit_method(const string method_name, const vector <string> args)
{
    ofile << ".method public static " << method_name << "([";
    
    for (arg : args)
    {
        ofile << arg;
    }

    ofile << ";)V" << endl;
}

void JasminEmitter::emit_main_class(const std::string & program_name)
{
    ofile << ".class public " << program_name << endl;
    ofile << ".super java/lang/Object"        << endl;
    ofile                                     << endl;
}

void JasminEmitter::emit_field(const std::string & field)
{
    ofile << ".field private static " << field << ";" << endl;
}

void JasminEmitter::emit_lookupswitch(const map <uint32_t, std::string> switch_map, const std::string default_label)
{
    std::string instruction = "<lookupswitch> ::=\n\tlookupswitch\n";
    
    for (auto pair : switch_map)
    {
        instruction += "\t\t<" + pair.first + "> : <" + pair.second + ">\n";
    }
    
    instruction += "\t\t<default> : <" + default_label + ">\n";

    ofile << instruction;
}

void JasminEmitter::emit_tableswitch(const vector <std::string> table_map)
{

}