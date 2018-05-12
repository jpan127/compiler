#include "TypeSpec.h"

namespace wci { namespace intermediate {

using namespace std;
using namespace symtabimpl;

ostream & operator << (ostream & out, const TypeSpec * other)
{
    if (!other)
    {
        out << "NULL";
    }
    else
    {
        string output;

        try
        {
                 if (other->get_identifier() == symtabimpl::Predefined::void_type->get_identifier()     ) { output = "void_type"    ; }
            else if (other->get_identifier() == symtabimpl::Predefined::bool_type->get_identifier()     ) { output = "bool_type"    ; }
            else if (other->get_identifier() == symtabimpl::Predefined::char_type->get_identifier()     ) { output = "char_type"    ; }
            else if (other->get_identifier() == symtabimpl::Predefined::short_type->get_identifier()    ) { output = "short_type"   ; }
            else if (other->get_identifier() == symtabimpl::Predefined::int_type->get_identifier()      ) { output = "int_type"     ; }
            else if (other->get_identifier() == symtabimpl::Predefined::long_type->get_identifier()     ) { output = "long_type"    ; }
            else if (other->get_identifier() == symtabimpl::Predefined::float_type->get_identifier()    ) { output = "float_type"   ; }
            else if (other->get_identifier() == symtabimpl::Predefined::double_type->get_identifier()   ) { output = "double_type"  ; }
            else if (other->get_identifier() == symtabimpl::Predefined::signed_type->get_identifier()   ) { output = "signed_type"  ; }
            else if (other->get_identifier() == symtabimpl::Predefined::unsigned_type->get_identifier() ) { output = "unsigned_type"; }
            else if (other->get_identifier() == symtabimpl::Predefined::uint32_t_type->get_identifier() ) { output = "uint32_t_type"; }
            else if (other->get_identifier() == symtabimpl::Predefined::int32_t_type->get_identifier()  ) { output = "int32_t_type" ; }
            else                                                                                          { output = "???"          ; }
        }
        catch (const char * msg)
        {
            cout << msg << endl;
            exit(-1);
        }

        out << output;
    }

    return out;
}

string TypeSpec::to_string() const
{
    string s;

    try
    {
             if (this == (symtabimpl::Predefined::void_type)     ) { s = "void_type"    ; }
        else if (this == (symtabimpl::Predefined::bool_type)     ) { s = "bool_type"    ; }
        else if (this == (symtabimpl::Predefined::char_type)     ) { s = "char_type"    ; }
        else if (this == (symtabimpl::Predefined::short_type)    ) { s = "short_type"   ; }
        else if (this == (symtabimpl::Predefined::int_type)      ) { s = "int_type"     ; }
        else if (this == (symtabimpl::Predefined::long_type)     ) { s = "long_type"    ; }
        else if (this == (symtabimpl::Predefined::float_type)    ) { s = "float_type"   ; }
        else if (this == (symtabimpl::Predefined::double_type)   ) { s = "double_type"  ; }
        else if (this == (symtabimpl::Predefined::signed_type)   ) { s = "signed_type"  ; }
        else if (this == (symtabimpl::Predefined::unsigned_type) ) { s = "unsigned_type"; }
        else if (this == (symtabimpl::Predefined::uint32_t_type) ) { s = "uint32_t_type"; }
        else if (this == (symtabimpl::Predefined::int32_t_type)  ) { s = "int32_t_type" ; }
        else                                                       { s = "???"          ; }
    }
    catch (const char * msg)
    {
        cout << msg << endl;
        exit(-1);
    }

    return s;
}

}}