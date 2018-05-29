#include "PassVisitor.hpp"



namespace backend
{

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *              S T A T I C  V A R I A B L E S               *
     *                                                           *
     */////////////////////////////////////////////////////////////

    uint64_t PassVisitor::scope_counter = 0;

    std::unordered_map <std::string, std::unordered_map <std::string, intermediate::Symbol>> PassVisitor::variable_id_map =
    {
        { "global" , std::unordered_map <std::string, intermediate::Symbol> () },
    };

    std::unordered_map <std::string, std::string> PassVisitor::function_definition_map;

    const backend::TypeSpecifier PassVisitor::resolve_expression_type(const backend::TypeSpecifier & lhs_type, const backend::TypeSpecifier & rhs_type)
    {
        return (lhs_type < rhs_type) ? (rhs_type) : (lhs_type);
    }

    bool PassVisitor::print_debug_context(antlr4::ParserRuleContext * context, const std::string & rule_name) const
    {
        constexpr size_t longest_name = 35;
        const std::string error_prefix = "<missing";
        const std::string space_padding(longest_name - rule_name.length(), ' ');
        const std::string text = context->getText();

        if (std::equal(error_prefix.begin(), error_prefix.end(), text.begin()))
        {
            cout << "-----------------------------------------------------------" << endl;
            cout << "[PASS"
                 << std::to_string(pass_number)
                 << "]["
                 << context->children.size()
                 << "][COMPILATION ERROR] "
                 << rule_name
                 << " : "
                 << context->getText()
                 << endl;
            cout << "Skipping this node!" << endl;
            cout << "-----------------------------------------------------------" << endl;
            return false;
        }
        else
        {
            cout << "[PASS"
                 << std::to_string(pass_number)
                 << "]["
                 << context->children.size()
                 << "] "
                 << rule_name
                 << space_padding
                 << " : "
                 << context->getText()
                 << endl;
            return true;
        }
    }

    char PassVisitor::letter_map_lookup(const backend::TypeSpecifier & type) const
    {
        static const std::unordered_map <backend::Type, char> letter_map =
        {
            { backend::Type::t_void   , 'V' },
            { backend::Type::t_bool   , 'B' },
            { backend::Type::t_char   , 'C' },
            { backend::Type::t_int    , 'I' },
            { backend::Type::t_float  , 'F' },
            { backend::Type::t_double , 'D' },
        };

        const backend::Type & t = type.get_type();

        if (letter_map.find(t) != letter_map.end())
        {
            return letter_map.at(t);
        }
        else
        {
            THROW_EXCEPTION(InvalidType, "Type not found : " + type.to_string());
            return '?';
        }
    }

    char PassVisitor::instruction_prefix_map_lookup(const backend::TypeSpecifier & type) const
    {
        static const std::unordered_map <backend::Type, char> instruction_prefix_map =
        {
            { backend::Type::t_bool   , 'i' },
            { backend::Type::t_char   , 'i' },
            { backend::Type::t_int    , 'i' },
            { backend::Type::t_float  , 'f' },
            { backend::Type::t_double , 'd' },
        };

        const backend::Type & t = type.get_type();

        if (instruction_prefix_map.find(t) != instruction_prefix_map.end())
        {
            return instruction_prefix_map.at(t);
        }
        else
        {
            THROW_EXCEPTION(InvalidType, "Can only resolve instructions for [double | float | int], got : " + type.to_string());
        }
    }

    std::string PassVisitor::create_get_variable_instruction(const std::string program_name, const std::string variable, const char type_letter)
    {
        std::string instruction;

        for (auto function : variable_id_map)
        {
            for (auto symbols : function.second)
            {
                if (symbols.first == variable)
                {
                    if (function.first == "global")
                    {
                        instruction += "getstatic\t" + program_name + "/" + variable + " " + type_letter;
                    }
                    else
                    {
                        switch (type_letter)
                        {
                            case 'I': instruction += "iload " + std::to_string(symbols.second.get_id()); break;
                            case 'F': instruction += "fload " + std::to_string(symbols.second.get_id()); break;
                            case 'D': instruction += "dload " + std::to_string(symbols.second.get_id()); break;
                            case 'L': instruction += "lload " + std::to_string(symbols.second.get_id()); break;
                            default :
                                THROW_EXCEPTION(InvalidType, "Invalid type letter for variable : " + variable + " type_letter : " + type_letter);
                        }
                    }
                    return instruction;
                }
            }
        }

        return "???????????????????????????????????";
    }

    std::string PassVisitor::create_put_variable_instruction(const std::string program_name, const std::string variable, const char type_letter)
    {
        std::string instruction = "\t";

        for (auto function : variable_id_map)
        {
            for (auto symbols : function.second)
            {
                if (symbols.first == variable)
                {
                    if (function.first == "global")
                    {
                        instruction += "putstatic\t" + program_name + "/" + variable + " " + type_letter;
                    }
                    else
                    {
                        switch (type_letter)
                        {
                            case 'I': instruction += "istore " + std::to_string(symbols.second.get_id()); break;
                            case 'F': instruction += "fstore " + std::to_string(symbols.second.get_id()); break;
                            case 'D': instruction += "dstore " + std::to_string(symbols.second.get_id()); break;
                            case 'L': instruction += "lstore " + std::to_string(symbols.second.get_id()); break;
                            default :
                                THROW_EXCEPTION(InvalidType, "Invalid type letter for variable : " + variable + " type_letter : " + type_letter);
                        }
                    }
                    return instruction;
                }
            }
        }

        return "???????????????????????????????????";
    }

    uint32_t PassVisitor::get_variable_id(const std::string variable) const
    {
        for (auto function : variable_id_map)
        {
            for (auto symbols : function.second)
            {
                if (symbols.first == variable)
                {
                    return symbols.second.get_id();
                }
            }
        }

        return static_cast <uint32_t> (-1);
    }

    bool PassVisitor::is_global(const std::string variable) const
    {
        for (auto symbols : variable_id_map["global"])
        {
            if (symbols.first == variable)
            {
                return true;
            }
        }

        return false;
    }

    std::string PassVisitor::convert_type_if_neccessary(const backend::TypeSpecifier & current_type, const backend::TypeSpecifier & needed_type)
    {
        std::string instruction;

        const backend::Type & current = current_type.get_type();
        const backend::Type & needed  = needed_type.get_type();

        if (current != needed)
        {
                 if (backend::Type::t_double == current) { instruction += "d2"; }
            else if (backend::Type::t_float  == current) { instruction += "f2"; }
            else if (backend::Type::t_int    == current) { instruction += "i2"; }
            else { THROW_EXCEPTION(InvalidType, "Unsupported type for conversion instruction : " + current_type.to_string()); }

                 if (backend::Type::t_double == needed) { instruction += "d"; }
            else if (backend::Type::t_float  == needed) { instruction += "f"; }
            else if (backend::Type::t_int    == needed) { instruction += "i"; }
            else { THROW_EXCEPTION(InvalidType, "Unsupported type for conversion instruction : " + needed_type.to_string()); }
        }

        return instruction;
    }

} /// backend
