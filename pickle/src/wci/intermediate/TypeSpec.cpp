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
            else if (other->get_identifier() == symtabimpl::Predefined::integer_type->get_identifier()  ) { output = "integer_type" ; }
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
             if (this == (symtabimpl::Predefined::void_type)     ) { s = "void"    ; }
        else if (this == (symtabimpl::Predefined::bool_type)     ) { s = "bool"    ; }
        else if (this == (symtabimpl::Predefined::char_type)     ) { s = "char"    ; }
        else if (this == (symtabimpl::Predefined::short_type)    ) { s = "short"   ; }
        else if (this == (symtabimpl::Predefined::int_type)      ) { s = "int"     ; }
        else if (this == (symtabimpl::Predefined::long_type)     ) { s = "long"    ; }
        else if (this == (symtabimpl::Predefined::float_type)    ) { s = "float"   ; }
        else if (this == (symtabimpl::Predefined::double_type)   ) { s = "double"  ; }
        else if (this == (symtabimpl::Predefined::signed_type)   ) { s = "signed"  ; }
        else if (this == (symtabimpl::Predefined::unsigned_type) ) { s = "unsigned"; }
        else if (this == (symtabimpl::Predefined::uint32_t_type) ) { s = "uint32_t"; }
        else if (this == (symtabimpl::Predefined::integer_type)  ) { s = "integer" ; }
        else                                                       { s = "????????"; }
    }
    catch (const char * msg)
    {
        cout << msg << endl;
        exit(-1);
    }

    return s;
}

}}