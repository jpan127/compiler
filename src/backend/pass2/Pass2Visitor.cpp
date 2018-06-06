#include "Pass2Visitor.hpp"



namespace backend
{

    Pass2Visitor::Pass2Visitor(const std::string fname, std::ofstream & j_file, JasminEmitter & j_emitter, const bool debug) :
        PassVisitor(2, j_file),
        program_name(fname),
        debug_flag(debug),
        j_emitter(j_emitter)
    {
        /// Empty
    }

    Pass2Visitor::~Pass2Visitor()
    {
        j_file.flush();
        j_file.close();
    }

    void Pass2Visitor::emit_expression_instruction(const backend::TypeSpecifier & type, const std::string & opr)
    {
        typedef std::function <void(JasminEmitter *)> void_no_param_JasminEmitter_FPTR;
        const std::map <const std::string, const std::map <const std::string, const void_no_param_JasminEmitter_FPTR>> expression_fptr_map =
        {
        //  Operator     Integer Function Pointers                    Float Function Pointers                      Double Function Pointers
            { "*"  , { { "i", &backend::JasminEmitter::emit_imul }, { "f", &backend::JasminEmitter::emit_fmul }, { "d", &backend::JasminEmitter::emit_dmul } } },
            { "/"  , { { "i", &backend::JasminEmitter::emit_idiv }, { "f", &backend::JasminEmitter::emit_fdiv }, { "d", &backend::JasminEmitter::emit_ddiv } } },
            { "%"  , { { "i", &backend::JasminEmitter::emit_irem }, { "f", &backend::JasminEmitter::emit_frem }, { "d", &backend::JasminEmitter::emit_drem } } },
            { "+"  , { { "i", &backend::JasminEmitter::emit_iadd }, { "f", &backend::JasminEmitter::emit_fadd }, { "d", &backend::JasminEmitter::emit_dadd } } },
            { "-"  , { { "i", &backend::JasminEmitter::emit_isub }, { "f", &backend::JasminEmitter::emit_fsub }, { "d", &backend::JasminEmitter::emit_dsub } } },
            { "<<" , { { "i", &backend::JasminEmitter::emit_ishl }, { "f", &backend::JasminEmitter::emit_ishl }, { "d", &backend::JasminEmitter::emit_ishl } } },
            { ">>" , { { "i", &backend::JasminEmitter::emit_ishr }, { "f", &backend::JasminEmitter::emit_ishr }, { "d", &backend::JasminEmitter::emit_ishr } } },
            { "&"  , { { "i", &backend::JasminEmitter::emit_iand }, { "f", &backend::JasminEmitter::emit_iand }, { "d", &backend::JasminEmitter::emit_iand } } },
            { "|"  , { { "i", &backend::JasminEmitter::emit_ior  }, { "f", &backend::JasminEmitter::emit_ior  }, { "d", &backend::JasminEmitter::emit_ior  } } },
            { "~"  , { { "i", &backend::JasminEmitter::emit_ineg }, { "f", &backend::JasminEmitter::emit_fneg }, { "d", &backend::JasminEmitter::emit_dneg } } },
            { "^"  , { { "i", &backend::JasminEmitter::emit_ixor }, { "f", &backend::JasminEmitter::emit_ixor }, { "d", &backend::JasminEmitter::emit_ixor } } },
        };

        const std::string type_letter(1, instruction_prefix_map_lookup(type));

        if (expression_fptr_map.find(opr) == expression_fptr_map.end())
        {
            THROW_EXCEPTION(InvalidOperator, opr);
        }
        else if (expression_fptr_map.at(opr).find(type_letter) == expression_fptr_map.at(opr).end())
        {
            THROW_EXCEPTION(InvalidType, type.to_string());
        }
        else
        {
            const void_no_param_JasminEmitter_FPTR & instruction_fptr = expression_fptr_map.at(opr).at(type_letter);
            instruction_fptr(&j_emitter);
        }
    }

    void Pass2Visitor::emit_symbol_table()
    {
        j_emitter.emit_new_line();
        j_emitter.emit_box_comment("Printing results of the program below");
        j_emitter.emit_label("print_results");
        j_emitter.emit_getstatic("java/lang/System/out Ljava/io/PrintStream;");

        j_emitter.emit_dup();
        j_emitter.emit_dup();
        j_emitter.emit_ldc("\"-----------------------------------------------------------------\"");
        j_emitter.emit_invokevirtual("java/io/PrintStream/println(Ljava/lang/String;)V");
        j_emitter.emit_new_line();

        const intermediate::SymbolTablePtr global_table = store.lookup_symbol_table("global");
        const intermediate::SymbolTablePtr main_table   = store.lookup_symbol_table("main");
        const std::vector <intermediate::SymbolTablePtr> tables_to_print = { global_table , main_table };

        for (const auto & table : tables_to_print)
        {
            for (const auto & symbol : table->get_table())
            {
                j_emitter.emit_comment(symbol.first);

                switch (symbol.second->get_type_letter())
                {
                    case 'F': j_emitter.emit_ldc("\"" + symbol.first + " : %f\\n\""); break;
                    case 'D': j_emitter.emit_ldc("\"" + symbol.first + " : %f\\n\""); break;
                    case 'I': j_emitter.emit_ldc("\"" + symbol.first + " : %d\\n\""); break;
                    case 'L': j_emitter.emit_ldc("\"" + symbol.first + " : %d\\n\""); break;
                    default :
                        THROW_EXCEPTION(InvalidType, std::string("Invalid type letter found : ") + std::string(1, symbol.second->get_type_letter()));
                }

                j_emitter.emit_ldc("1");
                j_emitter.emit_newarray(ArrayType::atype_object);
                j_emitter.emit_dup();
                j_emitter.emit_iconst_0();

                // Get function
                const backend::string_JasminEmitter_FUNCT & emit_callback = create_get_variable_instruction(program_name, symbol.first, symbol.second->get_type_letter());
                const backend::string_JasminEmitter_FPTR & emit_fptr = emit_callback.first;
                const std::string & value = emit_callback.second;
                emit_fptr(&j_emitter, value);

                switch (symbol.second->get_type_letter())
                {
                    case 'F': j_emitter.emit_invokestatic("java/lang/Float/valueOf(F)Ljava/lang/Float;");     break;
                    case 'D': j_emitter.emit_invokestatic("java/lang/Double/valueOf(D)Ljava/lang/Double;");   break;
                    case 'I': j_emitter.emit_invokestatic("java/lang/Integer/valueOf(I)Ljava/lang/Integer;"); break;
                    case 'L': j_emitter.emit_invokestatic("java/lang/Long/valueOf(L)Ljava/lang/Long;");       break;
                    default :
                        THROW_EXCEPTION(InvalidType, std::string("Invalid type letter found : ") + std::string(1, symbol.second->get_type_letter()));
                }

                j_emitter.emit_aastore();
                j_emitter.emit_invokevirtual("java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;");
                j_emitter.emit_new_line();
            }
        }

        j_emitter.emit_dup();
        j_emitter.emit_ldc("\"-----------------------------------------------------------------\"");
        j_emitter.emit_invokevirtual("java/io/PrintStream/println(Ljava/lang/String;)V");
        j_emitter.emit_new_line();
        j_emitter.emit_line(1);
    }

} /// backend
