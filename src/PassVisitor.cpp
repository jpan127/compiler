#include "PassVisitor.hpp"

#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;



uint64_t PassVisitor::scope_counter = 0;

const unordered_map <string, Type> PassVisitor::type_map =
{
    { "void"    , Type::t_void   },
    { "bool"    , Type::t_bool   },
    { "char"    , Type::t_char   },
    { "int"     , Type::t_int    },
    { "float"   , Type::t_float  },
    { "double"  , Type::t_double },
};

const unordered_map <Type, char> PassVisitor::letter_map =
{
    { Type::t_void   , 'V' },
    { Type::t_bool   , 'B' },
    { Type::t_char   , 'C' },
    { Type::t_int    , 'I' },
    { Type::t_float  , 'F' },
    { Type::t_double , 'D' },
};

const unordered_map <Type, char> PassVisitor::instruction_prefix_map =
{
    { Type::t_bool   , 'i' },
    { Type::t_char   , 'i' },
    { Type::t_int    , 'i' },
    { Type::t_float  , 'f' },
    { Type::t_double , 'd' },
};

unordered_map <string, unordered_map <string, ::intermediate::Symbol>> PassVisitor::variable_id_map =
{
    { "global" , unordered_map <string, ::intermediate::Symbol> () },
};

unordered_map <string, string> PassVisitor::function_definition_map;

string PassVisitor::current_function = "global";

Type PassVisitor::resolve_expression_type(Type lhs_type, Type rhs_type)
{
    // If any are double then result is double
    if (Type::t_double == lhs_type || Type::t_double == rhs_type)
    {
        return Type::t_double;
    }
    // If any are not real and neither are double then result is real
    else if (Type::t_float == lhs_type || Type::t_float == rhs_type)
    {
        return Type::t_float;
    }
    // Otherwise integer
    else
    {
        return Type::t_int;
    }
}

bool PassVisitor::print_debug_context(antlr4::ParserRuleContext * context, const std::string & rule_name) const
{
    constexpr size_t longest_name = 35;
    const string error_prefix = "<missing";
    const string space_padding(longest_name - rule_name.length(), ' ');
    const string text = context->getText();

    // if (text.find("<missing") != std::string::npos)
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

char PassVisitor::letter_map_lookup(const Type type) const
{
    char ret = '?';

    bool found = false;
    for (auto t : letter_map)
    {
        if (t.first == type)
        {
            ret = t.second;
            found = true;
            break;
        }
    }

    // If not found, compilation should not continue
    if (!found)
    {
        throw InvalidType("[letter_map_lookup] Type not found : " + to_string(type));
    }

    return ret;
}

char PassVisitor::instruction_prefix_map_lookup(const Type type) const
{
    char ret = '?';

    bool found = false;
    for (auto t : instruction_prefix_map)
    {
        if (t.first == type)
        {
            ret = t.second;
            found = true;
            break;
        }
    }

    // If not found, compilation should not continue
    if (!found)
    {
        throw InvalidType("[instruction_prefix_map_lookup] Can only resolve instructions for [double | float | int], got : " + to_string(type));
    }

    return ret;
}

string PassVisitor::create_get_variable_instruction(const string program_name, const string variable, const char type_letter)
{
    string instruction = "\t";

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
                            throw InvalidType("[create_get_variable_instruction] Invalid type letter for variable : " + variable + " type_letter : " + type_letter);
                    }
                }
                return instruction;
            }
        }
    }

    return "???????????????????????????????????";
}

string PassVisitor::create_put_variable_instruction(const string program_name, const string variable, const char type_letter)
{
    string instruction = "\t";

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
                            throw InvalidType("[create_get_variable_instruction] Invalid type letter for variable : " + variable + " type_letter : " + type_letter);
                    }
                }
                return instruction;
            }
        }
    }

    return "???????????????????????????????????";
}

uint32_t PassVisitor::get_variable_id(const string variable) const
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

bool PassVisitor::is_global(const string variable) const
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

string PassVisitor::convert_type_if_neccessary(Type current_type, Type needed_type)
{
    string instruction;

    if (current_type != needed_type)
    {
             if (Type::t_double == current_type) { instruction += "d2"; }
        else if (Type::t_float  == current_type) { instruction += "f2"; }
        else if (Type::t_int    == current_type) { instruction += "i2"; }
        else { throw InvalidType("Unsupported type for conversion instruction : " + to_string(current_type)); }

             if (Type::t_double == needed_type) { instruction += "d"; }
        else if (Type::t_float  == needed_type) { instruction += "f"; }
        else if (Type::t_int    == needed_type) { instruction += "i"; }
        else { throw InvalidType("Unsupported type for conversion instruction : " + to_string(current_type)); }
    }

    return instruction;
}
