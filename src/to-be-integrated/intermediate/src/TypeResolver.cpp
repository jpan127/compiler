#include "TypeResolver.hpp"



namespace utils
{

    namespace /// Anonymous
    {
        TypeConversion convert_from_double(const backend::TypeSpecifier & end)
        {
            TypeConversion conversion = TypeConversion::none;

            const backend::TypeSpecifier::Type & end_type = end.get_type();
            
            switch (end_type)
            {
                case backend::TypeSpecifier::Type::t_void     : conversion = TypeConversion::d2i; break;
                case backend::TypeSpecifier::Type::t_bool     : conversion = TypeConversion::d2i; break;
                case backend::TypeSpecifier::Type::t_char     : conversion = TypeConversion::d2i; break;
                case backend::TypeSpecifier::Type::t_short    : conversion = TypeConversion::d2i; break;
                case backend::TypeSpecifier::Type::t_int      : conversion = TypeConversion::d2i; break;
                case backend::TypeSpecifier::Type::t_long     : conversion = TypeConversion::d2l; break;
                case backend::TypeSpecifier::Type::t_float    : conversion = TypeConversion::d2f; break;
                case backend::TypeSpecifier::Type::t_double   :                                   break;
                case backend::TypeSpecifier::Type::t_uint32_t : conversion = TypeConversion::d2i; break;
                case backend::TypeSpecifier::Type::t_int32_t  : conversion = TypeConversion::d2i; break;
                default                                       :                                   break;
            }

            return conversion;
        }

        TypeConversion convert_from_long(const backend::TypeSpecifier & end)
        {
            TypeConversion conversion = TypeConversion::none;

            const backend::TypeSpecifier::Type & end_type = end.get_type();
            
            switch (end_type)
            {
                case backend::TypeSpecifier::Type::t_void     : conversion = TypeConversion::l2i; break;
                case backend::TypeSpecifier::Type::t_bool     : conversion = TypeConversion::l2i; break;
                case backend::TypeSpecifier::Type::t_char     : conversion = TypeConversion::l2i; break;
                case backend::TypeSpecifier::Type::t_short    : conversion = TypeConversion::l2i; break;
                case backend::TypeSpecifier::Type::t_int      : conversion = TypeConversion::l2i; break;
                case backend::TypeSpecifier::Type::t_long     :                                   break;
                case backend::TypeSpecifier::Type::t_float    : conversion = TypeConversion::l2f; break;
                case backend::TypeSpecifier::Type::t_double   : conversion = TypeConversion::l2d; break;
                case backend::TypeSpecifier::Type::t_uint32_t : conversion = TypeConversion::l2i; break;
                case backend::TypeSpecifier::Type::t_int32_t  : conversion = TypeConversion::l2i; break;
                default                                       :                                   break;
            }

            return conversion;
        }

        TypeConversion convert_from_float(const backend::TypeSpecifier & end)
        {
            TypeConversion conversion = TypeConversion::none;

            const backend::TypeSpecifier::Type & end_type = end.get_type();
            
            switch (end_type)
            {
                case backend::TypeSpecifier::Type::t_void     : conversion = TypeConversion::f2i; break;
                case backend::TypeSpecifier::Type::t_bool     : conversion = TypeConversion::f2i; break;
                case backend::TypeSpecifier::Type::t_char     : conversion = TypeConversion::f2i; break;
                case backend::TypeSpecifier::Type::t_short    : conversion = TypeConversion::f2i; break;
                case backend::TypeSpecifier::Type::t_int      : conversion = TypeConversion::f2i; break;
                case backend::TypeSpecifier::Type::t_long     : conversion = TypeConversion::f2l; break;
                case backend::TypeSpecifier::Type::t_float    :                                   break;
                case backend::TypeSpecifier::Type::t_double   : conversion = TypeConversion::f2d; break;
                case backend::TypeSpecifier::Type::t_uint32_t : conversion = TypeConversion::f2i; break;
                case backend::TypeSpecifier::Type::t_int32_t  : conversion = TypeConversion::f2i; break;
                default                                       :                                   break;
            }

            return conversion;
        }

        TypeConversion convert_from_int(const backend::TypeSpecifier & end)
        {
            TypeConversion conversion = TypeConversion::none;

            const backend::TypeSpecifier::Type & end_type = end.get_type();
            
            switch (end_type)
            {
                case backend::TypeSpecifier::Type::t_void     :                                   break;
                case backend::TypeSpecifier::Type::t_bool     :                                   break;
                case backend::TypeSpecifier::Type::t_char     :                                   break;
                case backend::TypeSpecifier::Type::t_short    :                                   break;
                case backend::TypeSpecifier::Type::t_int      :                                   break;
                case backend::TypeSpecifier::Type::t_long     : conversion = TypeConversion::i2l; break;
                case backend::TypeSpecifier::Type::t_float    : conversion = TypeConversion::i2f; break;
                case backend::TypeSpecifier::Type::t_double   : conversion = TypeConversion::i2d; break;
                case backend::TypeSpecifier::Type::t_uint32_t :                                   break;
                case backend::TypeSpecifier::Type::t_int32_t  :                                   break;
                default                                       :                                   break;
            }

            return conversion;
        }
    }

    backend::TypeSpecifier resolve_types(const backend::TypeSpecifier & lhs, const backend::TypeSpecifier & rhs)
    {
        return (lhs < rhs) ? (rhs) : (lhs);
    }

    TypeConversion determine_conversion_requirement(const backend::TypeSpecifier & start, const backend::TypeSpecifier & end)
    {
        TypeConversion conversion = TypeConversion::none;

        if (start != end)
        {
            const backend::TypeSpecifier::Type & start_type = start.get_type();
            
            switch (start_type)
            {
                case backend::TypeSpecifier::Type::t_void     : conversion = convert_from_int(end);    break;
                case backend::TypeSpecifier::Type::t_bool     : conversion = convert_from_int(end);    break;
                case backend::TypeSpecifier::Type::t_char     : conversion = convert_from_int(end);    break;
                case backend::TypeSpecifier::Type::t_short    : conversion = convert_from_int(end);    break;
                case backend::TypeSpecifier::Type::t_int      : conversion = convert_from_int(end);    break;
                case backend::TypeSpecifier::Type::t_long     : conversion = convert_from_long(end);   break;
                case backend::TypeSpecifier::Type::t_float    : conversion = convert_from_float(end);  break;
                case backend::TypeSpecifier::Type::t_double   : conversion = convert_from_double(end); break;
                case backend::TypeSpecifier::Type::t_uint32_t : conversion = convert_from_int(end);    break;
                case backend::TypeSpecifier::Type::t_int32_t  : conversion = convert_from_int(end);    break;
                default                                       :                                        break;
            }
        }

        return conversion;
    }

} /// utils
