#include "TypeSpecifier.hpp"



namespace backend
{

    const std::map <Type, uint8_t> TypeSpecifier::type_weight_map =
    {
        { Type::t_null   , 0 },
        { Type::t_void   , 0 },
        { Type::t_bool   , 0 },
        { Type::t_char   , 0 },
        { Type::t_int    , 0 },
        { Type::t_float  , 1 },
        { Type::t_double , 2 },
    };

    const std::unordered_map <std::string, Type> TypeSpecifier::type_map =
    {
        { "void"   , Type::t_void   },
        { "bool"   , Type::t_bool   },
        { "char"   , Type::t_char   },
        { "int"    , Type::t_int    },
        { "float"  , Type::t_float  },
        { "double" , Type::t_double },
    };

    std::ostream & operator << (std::ostream & out, const TypeSpecifier & rhs)
    {
        switch (rhs.get_type())
        {
            case Type::t_null   : out << "null";   break;
            case Type::t_void   : out << "void";   break;
            case Type::t_bool   : out << "bool";   break;
            case Type::t_char   : out << "char";   break;
            case Type::t_int    : out << "int";    break;
            case Type::t_float  : out << "float";  break;
            case Type::t_double : out << "double"; break;
            default             :                  break;
        }

        return out;
    }

    std::ostream & operator << (std::ostream & out, const Type & rhs)
    {
        switch (rhs)
        {
            case Type::t_null   : out << "null";   break;
            case Type::t_void   : out << "void";   break;
            case Type::t_bool   : out << "bool";   break;
            case Type::t_char   : out << "char";   break;
            case Type::t_int    : out << "int";    break;
            case Type::t_float  : out << "float";  break;
            case Type::t_double : out << "double"; break;
            default             :                  break;
        }

        return out;
    }

    bool operator == (const TypeSpecifier & lhs, const TypeSpecifier & rhs) { return (TypeSpecifier::type_weight_map.at(lhs.m_type) == TypeSpecifier::type_weight_map.at(rhs.m_type)); }
    bool operator != (const TypeSpecifier & lhs, const TypeSpecifier & rhs) { return !(operator == (lhs, rhs));                                                                        }
    bool operator <  (const TypeSpecifier & lhs, const TypeSpecifier & rhs) { return (TypeSpecifier::type_weight_map.at(lhs.m_type) < TypeSpecifier::type_weight_map.at(rhs.m_type));  }
    bool operator >  (const TypeSpecifier & lhs, const TypeSpecifier & rhs) { return (operator < (rhs, lhs));                                                                          }
    bool operator <= (const TypeSpecifier & lhs, const TypeSpecifier & rhs) { return !(operator > (lhs, rhs));                                                                         }
    bool operator >= (const TypeSpecifier & lhs, const TypeSpecifier & rhs) { return !(operator < (lhs, rhs));                                                                         }

    bool operator == (const Type & lhs, const TypeSpecifier & rhs) { return (TypeSpecifier::type_weight_map.at(lhs) == TypeSpecifier::type_weight_map.at(rhs.m_type)); }
    bool operator != (const Type & lhs, const TypeSpecifier & rhs) { return !(operator == (lhs, rhs));                                                                 }
    bool operator <  (const Type & lhs, const TypeSpecifier & rhs) { return (TypeSpecifier::type_weight_map.at(lhs) < TypeSpecifier::type_weight_map.at(rhs.m_type));  }
    bool operator >  (const Type & lhs, const TypeSpecifier & rhs) { return (operator < (rhs, lhs));                                                                   }
    bool operator <= (const Type & lhs, const TypeSpecifier & rhs) { return !(operator > (lhs, rhs));                                                                  }
    bool operator >= (const Type & lhs, const TypeSpecifier & rhs) { return !(operator < (lhs, rhs));                                                                  }

    std::string TypeSpecifier::to_string() const
    {
        switch (m_type)
        {
            case Type::t_null   : return "null";   break;
            case Type::t_void   : return "void";   break;
            case Type::t_bool   : return "bool";   break;
            case Type::t_char   : return "char";   break;
            case Type::t_int    : return "int";    break;
            case Type::t_float  : return "float";  break;
            case Type::t_double : return "double"; break;
            default             : return "";       break;
        }
    }

    void TypeSpecifier::set_type(const std::string & type)
    {
        if (type_map.find(type) != type_map.end())
        {
            m_type = type_map.at(type);
            m_type_letter = toupper(type[0]);
        }
        else
        {
            /// @TODO : After compiler is done and validated, this can be used as a CompilerError
            THROW_EXCEPTION(InvalidType, "Type not supported : " + type);
        }
    }

    void type_swap(TypeSpecifier & lhs, TypeSpecifier & rhs)
    {
        std::swap(lhs.m_type, rhs.m_type);
        std::swap(lhs.m_type_letter, rhs.m_type_letter);
    }

} /// backend
