#include "PassVisitor.hpp"

#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;



uint64_t PassVisitor::scope_counter = 0;

const unordered_map <string, TypeSpec **> PassVisitor::type_map =
{
    { "void"    , &Predefined::void_type   },
    { "bool"    , &Predefined::bool_type   },
    { "char"    , &Predefined::char_type   },
    { "int"     , &Predefined::int_type    },
    { "float"   , &Predefined::float_type  },
    { "double"  , &Predefined::double_type },
};

const unordered_map <TypeSpec **, char> PassVisitor::letter_map =
{
    { &Predefined::void_type   , 'V' },
    { &Predefined::bool_type   , 'B' },
    { &Predefined::char_type   , 'C' },
    { &Predefined::int_type    , 'I' },
    { &Predefined::float_type  , 'F' },
    { &Predefined::double_type , 'D' },
};

const unordered_map <TypeSpec **, char> PassVisitor::instruction_prefix_map =
{
    { &Predefined::bool_type   , 'i' },
    { &Predefined::char_type   , 'i' },
    { &Predefined::int_type    , 'i' },
    { &Predefined::float_type  , 'f' },
    { &Predefined::double_type , 'l' },
};

TypeSpec * PassVisitor::resolve_expression_type(TypeSpec * lhs_type, TypeSpec * rhs_type)
{
    if (nullptr == lhs_type && rhs_type == nullptr)
    {
        return Predefined::int_type;
    }
    else if (nullptr == lhs_type)
    {
        return rhs_type;
    }
    else if (nullptr == rhs_type)
    {
        return lhs_type;
    }
    // If any are double then result is double
    else if (Predefined::double_type == lhs_type || Predefined::double_type == rhs_type)
    {
        return Predefined::double_type;
    }
    // If any are not real and neither are double then result is real
    else if (Predefined::float_type == lhs_type || Predefined::float_type == rhs_type)
    {
        return Predefined::float_type;
    }
    // Otherwise integer
    else
    {
        return Predefined::int_type;
    }
}

void PassVisitor::print_debug_context(const uint8_t pass_num, antlr4::ParserRuleContext * context, const std::string & rule_name) const
{
    constexpr size_t longest_name = 30;
    const string space_padding(longest_name - rule_name.length(), ' ');
    
    cout << "[PASS"
         << std::to_string(pass_num)
         << "][" 
         << context->children.size() 
         << "] " 
         << rule_name 
         << space_padding 
         << " : " 
         << context->getText() 
         << endl;
}

char PassVisitor::letter_map_lookup(const TypeSpec * type) const
{
    char ret = '?';

    // NULL check
    if (nullptr == type)
    {
        throw InvalidType("[letter_map_lookup] NULL");
    }

    bool found = false;
    for (auto t : letter_map)
    {
        if (*t.first == type)
        {
            ret = t.second;
            found = true;
            break;
        }
    }

    // If not found, compilation should not continue
    if (!found)
    {
        throw InvalidType("[letter_map_lookup] Type not found : " + type->to_string());
    }

    return ret;
}

char PassVisitor::instruction_prefix_map_lookup(const TypeSpec * type) const
{
    char ret = '?';

    // NULL check
    if (nullptr == type)
    {
        throw InvalidType("[instruction_prefix_map_lookup] NULL");
    }

    bool found = false;
    for (auto t : instruction_prefix_map)
    {
        if (*t.first == type)
        {
            ret = t.second;
            found = true;
            break;
        }
    }

    // If not found, compilation should not continue
    if (!found)
    {
        throw InvalidType("[instruction_prefix_map_lookup] Can only resolve instructions for [double | float | int], got : " + type->to_string());
    }

    return ret;
}
