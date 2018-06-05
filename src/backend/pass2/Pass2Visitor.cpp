#include "Pass2Visitor.hpp"



namespace backend
{

    Pass2Visitor::Pass2Visitor(const std::string fname, std::ofstream & j_file, const bool debug) :
        PassVisitor(2, j_file),
        program_name(fname),
        debug_flag(debug)
    {
        /// Empty
    }

    Pass2Visitor::~Pass2Visitor()
    {
        j_file.flush();
        j_file.close();
    }

    std::string Pass2Visitor::resolve_expression_instruction(const backend::TypeSpecifier & type, const std::string & opr)
    {
        static const std::map <const std::string, const std::string> operator_to_opcode_map =
        {
            { "*"  , "mul" },
            { "/"  , "div" },
            { "%"  , "rem" },
            { "+"  , "add" },
            { "-"  , "sub" },
            { "<<" , "shl" },
            { ">>" , "shr" },
            { "&"  , "and" },
            { "|"  , "or"  },
            { "~"  , "neg" },
            { "^"  , "xor" },
        };

        // Get opcode prefix
        std::string opcode(1, instruction_prefix_map_lookup(type));

        // Get opcode
        if (operator_to_opcode_map.find(opr) != operator_to_opcode_map.end())
        {
            opcode += operator_to_opcode_map.at(opr);
        }
        else
        {
            THROW_EXCEPTION(InvalidOperator, opr);
        }

        return opcode;
    }

    void Pass2Visitor::emit_symbol_table()
    {
        j_file                                                                                       << endl;
        j_file << "; Printing results of the program below"                                          << endl;
        j_file << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;
        j_file << "print_results:"                                                                   << endl << endl;
        j_file << TAB << "getstatic java/lang/System/out Ljava/io/PrintStream;"                      << endl;

        j_file << TAB << "dup"                                                                       << endl;
        j_file << TAB << "ldc \"-----------------------------------------------------------------\"" << endl;
        j_file << TAB << "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V"            << endl;
        j_file                                                                                       << endl;

        const intermediate::SymbolTablePtr global_table = store.lookup_symbol_table("global");
        const intermediate::SymbolTablePtr main_table   = store.lookup_symbol_table("main");
        const std::vector <intermediate::SymbolTablePtr> tables_to_print = { global_table , main_table };

        for (const auto & table : tables_to_print)
        {
            for (const auto & symbol : table->get_table())
            {
                j_file << TAB << "; Printing symbol - " << symbol.first << endl;
                j_file << TAB << "ldc \"" + symbol.first << " : ";

                switch (symbol.second->get_type_letter())
                {
                    case 'F': j_file << "%f\\n\"" << endl; break;
                    case 'D': j_file << "%f\\n\"" << endl; break;
                    case 'I': j_file << "%d\\n\"" << endl; break;
                    case 'L': j_file << "%d\\n\"" << endl; break;
                    default :
                        THROW_EXCEPTION(InvalidType, std::string("Invalid type letter found : ") + std::string(1, symbol.second->get_type_letter()));
                }

                j_file << TAB << "ldc 1"                      << endl;
                j_file << TAB << "anewarray java/lang/Object" << endl;
                j_file << TAB << "dup"                        << endl;
                j_file << TAB << "iconst_0"                   << endl;

                j_file << create_get_variable_instruction(program_name, symbol.first, symbol.second->get_type_letter()) << endl;

                switch (symbol.second->get_type_letter())
                {
                    case 'F': j_file << TAB << "invokestatic java/lang/Float/valueOf(F)Ljava/lang/Float;"     << endl; break;
                    case 'D': j_file << TAB << "invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;"   << endl; break;
                    case 'I': j_file << TAB << "invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;" << endl; break;
                    case 'L': j_file << TAB << "invokestatic java/lang/Long/valueOf(L)Ljava/lang/Long;"       << endl; break;
                    default :
                        THROW_EXCEPTION(InvalidType, std::string("Invalid type letter found : ") + std::string(1, symbol.second->get_type_letter()));
                }

                j_file << TAB << "aastore" << endl;
                j_file << TAB << "invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;" << endl;
                j_file << endl;
            }
        }

        j_file << TAB << "dup"                                                                       << endl;
        j_file << TAB << "ldc \"-----------------------------------------------------------------\"" << endl;
        j_file << TAB << "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V"            << endl;
        j_file                                                                                       << endl;
        j_file << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;
    }

} /// backend
