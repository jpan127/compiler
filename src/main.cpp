#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"
#include "CmmLexer.h"
#include "CmmParser.h"
#include "Pass1Visitor.hpp"
#include "Pass2Visitor.hpp"

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
            throw MissingArgument("Missing argument : path to sample program");
        }
    }
    catch (MissingArgument const & error)
    {
        error.print_and_exit();
    }

    /// Input Stream
    std::ifstream ins(args[1]);
    std::cout << args[1] << std::endl;

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

    std::cout << pass1_msg << std::endl;

    std::string file_name = args[1];
    file_name = file_name.substr(0, file_name.find_last_of("."));
    file_name = file_name.substr(file_name.find_last_of("/") + 1);
    const std::string program_name = file_name;

    try
    {
        /// First Pass
        Pass1Visitor *pass1 = new Pass1Visitor(program_name, true);
        pass1->visit(tree);

        std::cout << pass2_msg << std::endl;

        /// Output Stream
        std::ofstream & j_file = pass1->get_assembly_file();

        /// Second Pass
        Pass2Visitor *pass2 = new Pass2Visitor(program_name, j_file, true);
        pass2->visit(tree);

        /// Sanity clean up
        if (j_file.is_open())
        {
            j_file.flush();
            j_file.close();
        }
    }
    catch (...)
    {
        cerr << "Uncaught exception..." << endl;
    }

    delete tree;

    return 0;
}
