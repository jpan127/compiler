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
    if (argc < 2)
    {
        throw "Missing argument : path to sample program";
        return -1;
    }

    ifstream ins(args[1]);

    ANTLRInputStream input(ins);
    Pcl2Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    Pcl2Parser parser(&tokens);
    tree::ParseTree *tree = parser.program();

    Pass1Visitor *pass1 = new Pass1Visitor(true);
    pass1->visit(tree);

    ostream& j_file = pass1->get_assembly_file();

    Pass2Visitor *pass2 = new Pass2Visitor(j_file);
    pass2->visit(tree);

    delete tree;
    return 0;
}
