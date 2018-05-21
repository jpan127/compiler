#include "TypeSpecifier.hpp"



/// @TODO : Remove this
std::ostream & operator << (std::ostream & out, const Type & rhs)
{
    switch (rhs)
    {
        case Type::t_null     : out << "null";     break;
        case Type::t_void     : out << "void";     break;
        case Type::t_bool     : out << "bool";     break;
        case Type::t_char     : out << "char";     break;
        case Type::t_int      : out << "int";      break;
        case Type::t_float    : out << "float";    break;
        case Type::t_double   : out << "double";   break;
        case Type::t_long     : out << "long"  ;   break;
        default               :                    break;
    }

    return out;
}

namespace backend
{

    const std::map <Type, uint8_t> TypeSpecifier::type_weight_map =
    {
        { Type::t_null     , 0 },
        { Type::t_void     , 0 },
        { Type::t_bool     , 0 },
        { Type::t_char     , 0 },
        { Type::t_int      , 0 },
        { Type::t_float    , 1 },
        { Type::t_double   , 2 },
        // { Type::t_signed   , 0 },
        // { Type::t_unsigned , 0 },
        // { Type::t_uint32_t , 0 },
        // { Type::t_short    , 0 },
        // { Type::t_int32_t  , 0 },
        // { Type::t_long     , 2 },
    };

    std::ostream & operator << (std::ostream & out, const TypeSpecifier & rhs)
    {
        switch (rhs.m_type)
        {
            case Type::t_null     : out << "null";     break;
            case Type::t_void     : out << "void";     break;
            case Type::t_bool     : out << "bool";     break;
            case Type::t_char     : out << "char";     break;
            case Type::t_int      : out << "int";      break;
            case Type::t_float    : out << "float";    break;
            case Type::t_double   : out << "double";   break;
            // case Type::t_long     : out << "long";     break;
            // case Type::t_short    : out << "short";    break;
            // case Type::t_signed   : out << "signed";   break;
            // case Type::t_unsigned : out << "unsigned"; break;
            // case Type::t_uint32_t : out << "uint32_t"; break;
            // case Type::t_int32_t  : out << "int32_t";  break;
            default               :                    break;
        }

        return out;
    }

    bool operator == (const TypeSpecifier & lhs, const TypeSpecifier & rhs)
    {
        return (TypeSpecifier::type_weight_map.at(lhs.m_type) == TypeSpecifier::type_weight_map.at(rhs.m_type));
    }
    bool operator != (const TypeSpecifier & lhs, const TypeSpecifier & rhs)
    {
        return !(operator == (lhs, rhs));
    }
    bool operator < (const TypeSpecifier & lhs, const TypeSpecifier & rhs)
    {
        return (TypeSpecifier::type_weight_map.at(lhs.m_type) < TypeSpecifier::type_weight_map.at(rhs.m_type));
    }
    bool operator > (const TypeSpecifier & lhs, const TypeSpecifier & rhs)
    {
        return (operator < (rhs, lhs));
    }
    bool operator <= (const TypeSpecifier & lhs, const TypeSpecifier & rhs)
    {
        return !(operator > (lhs, rhs));
    }
    bool operator >= (const TypeSpecifier & lhs, const TypeSpecifier & rhs)
    {
        return !(operator < (lhs, rhs));
    }

    std::string TypeSpecifier::to_string() const
    {
        switch (m_type)
        {
            case Type::t_null     : return "null";     break;
            case Type::t_void     : return "void";     break;
            case Type::t_bool     : return "bool";     break;
            case Type::t_char     : return "char";     break;
            case Type::t_int      : return "int";      break;
            case Type::t_float    : return "float";    break;
            case Type::t_double   : return "double";   break;
            // case Type::t_short    : return "short";    break;
            // case Type::t_long     : return "long";     break;
            // case Type::t_signed   : return "signed";   break;
            // case Type::t_unsigned : return "unsigned"; break;
            // case Type::t_uint32_t : return "uint32_t"; break;
            // case Type::t_int32_t  : return "int32_t";  break;
            default               : return "";         break;
        }
    }

} /// backend
