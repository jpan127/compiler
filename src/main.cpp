#include "antlr4-runtime.h"
#include "CmmLexer.h"
#include "CmmParser.h"

#include "common.hpp"
#include "Pass1Visitor.hpp"
#include "Pass2Visitor.hpp"



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
    antlr4::ANTLRInputStream input(ins);

    /// Lexer
    CmmLexer lexer(&input);

    /// Tokenizer
    antlr4::CommonTokenStream tokens(&lexer);

    /// Parser
    CmmParser parser(&tokens);

    /// Parse Tree
    antlr4::tree::ParseTree *tree = parser.compilationUnit();


    std::string file_name = args[1];
    file_name = file_name.substr(0, file_name.find_last_of("."));
    file_name = file_name.substr(file_name.find_last_of("/") + 1);
    const std::string program_name = file_name;

    /// Output Stream
    std::ofstream j_file;

    // Open output stream file
    try
    {
        j_file.open(program_name + ".j");
        if (j_file.fail())
        {
            throw FileOpenError("Failed to open file :" + program_name + ".j");
        }
    }
    CATCH_CUSTOM_EXCEPTION_PRINT_AND_EXIT(FileOpenError);

    try
    {
        constexpr bool debug = true;

        /// First Pass
        std::cout << pass1_msg << std::endl;
        backend::Pass1Visitor pass1(program_name, j_file, debug);
        pass1.visit(tree);

        /// Second Pass
        std::cout << pass2_msg << std::endl;
        backend::Pass2Visitor pass2(program_name, j_file, debug);
        pass2.visit(tree);

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
