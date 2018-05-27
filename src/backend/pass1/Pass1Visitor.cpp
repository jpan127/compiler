#include "Pass1Visitor.hpp"



namespace backend
{

    Pass1Visitor::Pass1Visitor(const std::string fname, const bool debug) :
        PassVisitor(1),
        program_name(fname),
        symbol_table_stack(),
        j_file(nullptr),
        debug_flag(debug)
    {
        cout << "Pass1Visitor: symtab stack initialized" << endl;
    }

    std::ofstream & Pass1Visitor::get_assembly_file()
    {
        return j_file;
    }

    void Pass1Visitor::lookup_symbol_type(std::string const & variable, backend::TypeSpecifier & type, char & type_letter)
    {
        try
        {
            if (auto symbol = symbol_table_stack.lookup_symbol_globally(variable))
            {
                type.set_type(symbol->get_type());
                type_letter = letter_map_lookup(type);
            }
            else
            {
                throw MissingSymbol(variable);
            }
        }
        CATCH_CUSTOM_EXCEPTIONS_PRINT_AND_EXIT(InvalidType, MissingSymbol);
    }

} /// backend
