#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"
#include "Pcl2Lexer.h"
#include "Pcl2Parser.h"
#include "Pass1Visitor.hpp"
#include "Pass2Visitor.h"

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

    /// Input Stream
    ifstream ins(args[1]);

    /// ANLTR Input Stream
    ANTLRInputStream input(ins);

    /// Lexer
    Pcl2Lexer lexer(&input);

    /// Tokenizer
    CommonTokenStream tokens(&lexer);

    /// Parser
    Pcl2Parser parser(&tokens);

    const std::vector<std::string> & rule_names = parser.getRuleNames();

    /// Parse Tree
    tree::ParseTree *tree = parser.compilationUnit();

    cout << pass1_msg << endl;

    const string program_name = "HELLOOOOOOO_WORRRRRLD";

    /// First Pass
    Pass1Visitor *pass1 = new Pass1Visitor(program_name, rule_names, true);
    pass1->visit(tree);

    cout << pass2_msg << endl;

    /// Output Stream
    ofstream& j_file = pass1->get_assembly_file();

    /// Second Pass
    Pass2Visitor *pass2 = new Pass2Visitor(program_name, j_file, true);
    pass2->visit(tree);

    delete tree;
    return 0;
}
