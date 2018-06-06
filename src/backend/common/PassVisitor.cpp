#include "PassVisitor.hpp"



namespace backend
{

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *              S T A T I C  V A R I A B L E S               *
     *                                                           *
     */////////////////////////////////////////////////////////////

    uint64_t PassVisitor::scope_counter = 0;

    intermediate::SymbolTableStore PassVisitor::store;

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

    backend::string_JasminEmitter_FUNCT PassVisitor::create_get_variable_instruction(const std::string program_name, const std::string variable, const char type_letter)
    {
        backend::string_JasminEmitter_FPTR instruction;
        std::string value;
        std::string scope;

        const intermediate::SymbolPtr s_ptr = store.lookup_symbol(variable, scope);

        if (nullptr == s_ptr)
        {
            throw MissingSymbol(variable);
        }
        else if ("global" == scope)
        {
            instruction = &backend::JasminEmitter::emit_getstatic;
            value = program_name + "/" + variable + " " + type_letter;
        }
        else
        {
            switch (type_letter)
            {
                case 'I': instruction = &backend::JasminEmitter::emit_iload; break;
                case 'F': instruction = &backend::JasminEmitter::emit_fload; break;
                case 'D': instruction = &backend::JasminEmitter::emit_dload; break;
                case 'L': instruction = &backend::JasminEmitter::emit_lload; break;
                default :
                    THROW_EXCEPTION(InvalidType, "Invalid type letter for variable : " + variable + " type_letter : " + type_letter);
            }

            value = std::to_string(s_ptr->get_id());
        }

        return std::make_pair(instruction, value);
    }

    backend::string_JasminEmitter_FUNCT PassVisitor::create_put_variable_instruction(const std::string program_name, const std::string variable, const char type_letter)
    {
        backend::string_JasminEmitter_FPTR instruction;
        std::string value;
        std::string scope;

        const intermediate::SymbolPtr s_ptr = store.lookup_symbol(variable, scope);

        if (nullptr == s_ptr)
        {
            throw MissingSymbol(variable);
        }
        else if ("global" == scope)
        {
            instruction = &backend::JasminEmitter::emit_putstatic;
            value = program_name + "/" + variable + " " + type_letter;
        }
        else
        {
            switch (type_letter)
            {
                case 'I': instruction = &backend::JasminEmitter::emit_istore; break;
                case 'F': instruction = &backend::JasminEmitter::emit_fstore; break;
                case 'D': instruction = &backend::JasminEmitter::emit_dstore; break;
                case 'L': instruction = &backend::JasminEmitter::emit_lstore; break;
                default :
                    THROW_EXCEPTION(InvalidType, "Invalid type letter for variable : " + variable + " type_letter : " + type_letter);
            }

            value = std::to_string(s_ptr->get_id());
        }

        return std::make_pair(instruction, value);
    }

} /// backend
