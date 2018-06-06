#include "Pass1Visitor.hpp"



namespace backend
{

    Pass1Visitor::Pass1Visitor(const std::string fname, std::ofstream & j_file, JasminEmitter & j_emitter, const bool debug) :
        PassVisitor(1, j_file),
        program_name(fname),
        debug_flag(debug),
        j_emitter(j_emitter)
    {
        // Store the global symbol table, created in the constructor of symbol table stack, inside the symbol store
        PassVisitor::store.register_symbol_table(symbol_table_stack.get_local_symbol_table());
        cout << "Pass1Visitor: symtab stack initialized" << endl;
    }

    void Pass1Visitor::lookup_symbol_type(const std::string & variable, backend::TypeSpecifier & type, char & type_letter)
    {
        if (auto symbol = symbol_table_stack.lookup_symbol_globally(variable))
        {
            type.set_type(symbol->get_type());
            type_letter = letter_map_lookup(type);
        }
        else
        {
            THROW_EXCEPTION(MissingSymbol, variable);
        }
    }

} /// backend
