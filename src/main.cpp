#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"
#include "CmmLexer.h"
#include "CmmParser.h"
#include "Pass1Visitor.hpp"
#include "Pass2Visitor.hpp"

#include "wci/intermediate/typeimpl/TypeSpecImpl.h"
#include "wci/intermediate/TypeSpec.h"
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

using namespace std;
using namespace antlrcpp;
using namespace antlr4;

static const char * pass1_msg = "------------------------------------------------\n"
                                "                   P A S S  1                   \n"
                                "------------------------------------------------\n";

static const char * pass2_msg = "------------------------------------------------\n"
                                "                   P A S S  2                   \n"
                                "------------------------------------------------\n";

int main(int argc, const char *args[])
{
    /// Make sure argument exists
    try
    {
        if (argc < 2)
        {
            throw "Missing argument : path to sample program";
        }
    }
    catch (const char * error)
    {
        cout << error << endl;
        return -1;
    }

    /// @TODO : Remove when integrating TypeSpecifier
    Predefined::void_type   = new wci::intermediate::typeimpl::TypeSpecImpl(wci::intermediate::TypeFormImpl::SCALAR);
    Predefined::bool_type   = new wci::intermediate::typeimpl::TypeSpecImpl(wci::intermediate::TypeFormImpl::SCALAR);
    Predefined::char_type   = new wci::intermediate::typeimpl::TypeSpecImpl(wci::intermediate::TypeFormImpl::SCALAR);
    Predefined::int_type    = new wci::intermediate::typeimpl::TypeSpecImpl(wci::intermediate::TypeFormImpl::SCALAR);
    Predefined::float_type  = new wci::intermediate::typeimpl::TypeSpecImpl(wci::intermediate::TypeFormImpl::SCALAR);
    Predefined::double_type = new wci::intermediate::typeimpl::TypeSpecImpl(wci::intermediate::TypeFormImpl::SCALAR);

    /// Input Stream
    ifstream ins(args[1]);

    /// ANLTR Input Stream
    ANTLRInputStream input(ins);

    /// Lexer
    CmmLexer lexer(&input);

    /// Tokenizer
    CommonTokenStream tokens(&lexer);

    /// Parser
    CmmParser parser(&tokens);

    /// Parse Tree
    tree::ParseTree *tree = parser.compilationUnit();

    cout << pass1_msg << endl;

    string file_name = args[1];
    file_name = file_name.substr(0, file_name.find_last_of("."));
    file_name = file_name.substr(file_name.find_last_of("/") + 1);
    const string program_name = file_name;

    /// First Pass
    Pass1Visitor *pass1 = new Pass1Visitor(program_name, true);
    pass1->visit(tree);

    cout << pass2_msg << endl;

    /// Output Stream
    ofstream& j_file = pass1->get_assembly_file();

    /// Second Pass
    Pass2Visitor *pass2 = new Pass2Visitor(program_name, j_file, true);
    pass2->visit(tree);

    /// Sanity clean up
    if (j_file.is_open())
    {
        j_file.flush();
        j_file.close();
    }

    delete tree;

    return 0;
}
