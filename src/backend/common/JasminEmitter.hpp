#pragma once

#include "common.hpp"
#include "SymbolTableStack.hpp"



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
        atype_object,
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

    private:

        /// @ { Useful helper variables
        static constexpr char NEW_LINE = '\n';
        static constexpr char TAB      = '\t';
        static constexpr uint8_t line_length = 80;
        static constexpr char const * line = ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
                                             ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
        /// @ }

        /// Output stream used for emitting assembly instructions
        std::ofstream & ofile;

        /**
         *  Emits an instruction for loading a constant integer
         *  If the integer is less than 6, it uses an iconst instruction, otherwise ldc
         *  @param integer : The integer to load
         */
        void emit_integer(const uint32_t integer);

        /**
         *  From a string representation of a constant, determine its type letter
         *  @param constant : The string representation of a constant
         *  @returns        : The determined type letter
         */
        char determine_constant_type(const std::string & constant);

        /**
         *  Emits a static method invokation for the valueof() function depending on the type
         *  @param type_letter : The letter of the type of the value that is on the top of the stack
         */
        void emit_value_of(const char type_letter);

    public:

        /// Constructor with only member as parameter
        JasminEmitter(std::ofstream & ofile);

        /// @ { Miscellaneous / Not A Specific Instruction
        /// Init function for a Java main class
        void emit_default_constructor();
        /**
         *  Public method prototype
         *  @param method_name : Name of method
         *  @param args        : List of arguments whether it is a single char 'I' or a full string for Object
         *  @param return_type : Type of returned value, same as above
         */
        void emit_public_method_signature(const std::string & method_name, const std::vector <std::string> & args, const std::string & return_type);
        /**
         *  Class member variable declaration
         *  @param variable    : Name of variable
         *  @param type_letter : Letter representing the type of the variable
         */
        void emit_class_variable(const std::string & variable, const std::string & type_letter);
        /**
         *  Main method prototype
         *  @param program_name : Name of the program
         */
        void emit_main_class(const std::string & program_name);
        /**
         *  The sequence of instructions for a Java printf in Jasmin
         *  @param format_string    : A formatted string with the % specifiers
         *  @param args             : Vector of arguments that replaces the specifiers
         *  @param current_function : The current function of compilation, for debugging purposes
         *  @param local_table      : The local symbol table to retrieve symbols from
         */
        void emit_printf(const std::string & format_string,
            const std::vector <std::string> & args,
            const std::string & current_function,
            const intermediate::SymbolTablePtr local_table);

        /**
         *  Comment
         *  @param comment : The string for the comment
         */
        void emit_comment(const std::string & comment);
        /**
         *  Comment with a configurable number of indentations
         *  @param comment : The string for the comment
         *  @param indents : Number of indents
         */
        void emit_comment_custom(const std::string & comment, const uint8_t indents=1);
        /// Emits a new line
        void emit_new_line()
        {
            ofile << std::endl;
        }
        /**
         *  Number of local variables, size of the current method's stack, and the ending label
         *  @param local_vars : Number of local variables to the method
         *  @param stack_size : Size of stack in bytes of the method
         */
        void emit_function_end(const uint32_t local_vars, const uint32_t stack_size)
        {
            ofile << ".limit locals " << local_vars << NEW_LINE;
            ofile << ".limit stack "  << stack_size << NEW_LINE;
            ofile << ".end method"                  << NEW_LINE;
        }
        /**
         *  Comment surrounded by a box
         *  @param comment : The comment that goes in the middle of the box
         *  @example:
         *      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
         *      ;           comment           ;
         *      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
         */
        void emit_box_comment(const std::string & comment)
        {
            const uint8_t num_spaces_padding = (line_length - comment.length() - 2) / 2;
            ofile << TAB << line << NEW_LINE;
            ofile << TAB << ";"  << string(num_spaces_padding, ' ')
                                 << comment
                                 << string(num_spaces_padding, ' ')
                         << ";"  << NEW_LINE;
            ofile << TAB << line << NEW_LINE;
        }
        /**
         *  Label for branch statements
         *  @param label : Name of the label
         */
        void emit_label(const std::string & label)
        {
            ofile << label << ":" << NEW_LINE;
        }
        /**
         *  A comment line for separating blocks of code
         *  @param indents : Number of indentations before the comment
         */
        void emit_line(const uint8_t indents=0)
        {
            for (uint8_t i = 0; i < indents; i++)
            {
                ofile << TAB;
            }
            ofile << line << NEW_LINE;
        }
        /// @ }

        /// @ { Local Variable Instructions
        void emit_ret(const std::string & value);
        void emit_aload(const std::string & value);
        void emit_astore(const std::string & value);
        void emit_dload(const std::string & value);
        void emit_dstore(const std::string & value);
        void emit_fload(const std::string & value);
        void emit_fstore(const std::string & value);
        void emit_iload(const std::string & value);
        void emit_istore(const std::string & value);
        void emit_lload(const std::string & value);
        void emit_lstore(const std::string & value);
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

    /// Typedef'd function pointers for JasminEmitter public functions
    typedef std::function <void(JasminEmitter *, const int32_t      )> int_JasminEmitter_FPTR;
    typedef std::function <void(JasminEmitter *                     )> void_JasminEmitter_FPTR;
    typedef std::function <void(JasminEmitter *, const std::string &)> string_JasminEmitter_FPTR;

    /// Typedef'd grouping of a function pointer and the value that should be passed in when the function is called
    typedef std::pair <int_JasminEmitter_FPTR, const uint32_t> int_JasminEmitter_FUNCT;
    typedef std::pair <void_JasminEmitter_FPTR, void         > void_JasminEmitter_FUNCT;
    typedef std::pair <string_JasminEmitter_FPTR, std::string> string_JasminEmitter_FUNCT;

    /// Macro for an empty function pair, since the pair can not be initialized null so it is useful for pre-declaring a pair
    #define EMPTY_STRING_CALLBACK (std::make_pair(nullptr, ""))

} /// backend
