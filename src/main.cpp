#include "antlr4-runtime.h"
#include "CmmLexer.h"
#include "CmmParser.h"

#include "common.hpp"
#include "Pass1Visitor.hpp"
#include "Pass2Visitor.hpp"



static const char * pass1_msg = "\n"
                                "------------------------------------------------\n"
                                "|                   P A S S  1                 |\n"
                                "------------------------------------------------\n";

static const char * pass2_msg = "\n"
                                "------------------------------------------------\n"
                                "|                   P A S S  2                 |\n"
                                "------------------------------------------------\n";

int main(int argc, const char *args[])
{
    try
    {
        /// Make sure argument exists
        if (argc < 2)
        {
            THROW_EXCEPTION(MissingArgument, "Missing argument : path to sample program");
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

        /// Get file name and strip rest of string
        std::string program_name = args[1];
        program_name = program_name.substr(0, program_name.find_last_of("."));
        program_name = program_name.substr(program_name.find_last_of("/") + 1);

        /// Output Stream
        std::ofstream j_file(program_name + ".j");
        if (j_file.fail())
        {
            THROW_EXCEPTION(FileOpenError, "Failed to open file :" + program_name + ".j");
        }

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

        delete tree;
    }
    catch (const CustomException & e)
    {
        e.print_and_exit();
    }
    catch (...)
    {
        cerr << "Unknown exception..." << endl;
    }

    return 0;
}
