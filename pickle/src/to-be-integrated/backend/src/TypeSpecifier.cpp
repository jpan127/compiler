#include "TypeSpecifier.hpp"

namespace backend
{

    const std::map <TypeSpecifier::Type, uint8_t> TypeSpecifier::type_weight_map =
    {
        { TypeSpecifier::Type::t_void     , 0 },
        { TypeSpecifier::Type::t_bool     , 0 },
        { TypeSpecifier::Type::t_char     , 0 },
        { TypeSpecifier::Type::t_short    , 0 },
        { TypeSpecifier::Type::t_int      , 0 },
        { TypeSpecifier::Type::t_signed   , 0 },
        { TypeSpecifier::Type::t_unsigned , 0 },
        { TypeSpecifier::Type::t_uint32_t , 0 },
        { TypeSpecifier::Type::t_int32_t  , 0 },
        { TypeSpecifier::Type::t_float    , 1 },
        { TypeSpecifier::Type::t_double   , 2 },
        { TypeSpecifier::Type::t_long     , 2 },
    };

    std::ostream & operator << (std::ostream & out, const TypeSpecifier & rhs)
    {
        switch (rhs.m_type)
        {
            case TypeSpecifier::Type::t_void     : out << "void";     break;
            case TypeSpecifier::Type::t_bool     : out << "bool";     break;
            case TypeSpecifier::Type::t_char     : out << "char";     break;
            case TypeSpecifier::Type::t_short    : out << "short";    break;
            case TypeSpecifier::Type::t_int      : out << "int";      break;
            case TypeSpecifier::Type::t_long     : out << "long";     break;
            case TypeSpecifier::Type::t_float    : out << "float";    break;
            case TypeSpecifier::Type::t_double   : out << "double";   break;
            case TypeSpecifier::Type::t_signed   : out << "signed";   break;
            case TypeSpecifier::Type::t_unsigned : out << "unsigned"; break;
            case TypeSpecifier::Type::t_uint32_t : out << "uint32_t"; break;
            case TypeSpecifier::Type::t_int32_t  : out << "int32_t";  break;
            default                              :                    break;
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
            case TypeSpecifier::Type::t_void     : return "void";     break;
            case TypeSpecifier::Type::t_bool     : return "bool";     break;
            case TypeSpecifier::Type::t_char     : return "char";     break;
            case TypeSpecifier::Type::t_short    : return "short";    break;
            case TypeSpecifier::Type::t_int      : return "int";      break;
            case TypeSpecifier::Type::t_long     : return "long";     break;
            case TypeSpecifier::Type::t_float    : return "float";    break;
            case TypeSpecifier::Type::t_double   : return "double";   break;
            case TypeSpecifier::Type::t_signed   : return "signed";   break;
            case TypeSpecifier::Type::t_unsigned : return "unsigned"; break;
            case TypeSpecifier::Type::t_uint32_t : return "uint32_t"; break;
            case TypeSpecifier::Type::t_int32_t  : return "int32_t";  break;
            default                              : return "";         break;
        }
    }

} /// backend
