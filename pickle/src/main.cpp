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

    /// File Stream
    ifstream ins(args[1]);

    /// ANLTR Input Stream
    ANTLRInputStream input(ins);

    /// Lexer
    Pcl2Lexer lexer(&input);

    /// Tokenizer
    CommonTokenStream tokens(&lexer);

    /// Parser
    Pcl2Parser parser(&tokens);

    /// Parse Tree
    tree::ParseTree *tree = parser.compilationUnit();

    /// First Pass
    Pass1Visitor *pass1 = new Pass1Visitor(true);
    pass1->visit(tree);

    /**
     *  Pass2Visitor => visit
     *  AbstractParseTreeVisitor => visit
     *   
     */

    /// Second Pass
    ostream& j_file = pass1->get_assembly_file();
    Pass2Visitor *pass2 = new Pass2Visitor(j_file, true);
    pass2->visit(tree);

    delete tree;
    return 0;
}
