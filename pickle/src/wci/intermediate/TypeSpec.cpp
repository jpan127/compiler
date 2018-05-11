#include "TypeSpec.h"

namespace wci { namespace intermediate {

using namespace std;
using namespace symtabimpl;

ostream & operator << (ostream & out, const TypeSpec * other)
{
    try
    {
             if (other == (symtabimpl::Predefined::void_type)     ) { out << "void_type"     << endl; }
        else if (other == (symtabimpl::Predefined::bool_type)     ) { out << "bool_type"     << endl; }
        else if (other == (symtabimpl::Predefined::char_type)     ) { out << "char_type"     << endl; }
        else if (other == (symtabimpl::Predefined::short_type)    ) { out << "short_type"    << endl; }
        else if (other == (symtabimpl::Predefined::int_type)      ) { out << "int_type"      << endl; }
        else if (other == (symtabimpl::Predefined::long_type)     ) { out << "long_type"     << endl; }
        else if (other == (symtabimpl::Predefined::float_type)    ) { out << "float_type"    << endl; }
        else if (other == (symtabimpl::Predefined::double_type)   ) { out << "double_type"   << endl; }
        else if (other == (symtabimpl::Predefined::signed_type)   ) { out << "signed_type"   << endl; }
        else if (other == (symtabimpl::Predefined::unsigned_type) ) { out << "unsigned_type" << endl; }
        else if (other == (symtabimpl::Predefined::uint32_t_type) ) { out << "uint32_t_type" << endl; }
        else if (other == (symtabimpl::Predefined::int32_t_type)  ) { out << "int32_t_type"  << endl; }
        else                                                        { out << "???"           << endl; }
    }
    catch (const char * msg)
    {
        cout << msg << endl;
        exit(-1);
    }
}

}}