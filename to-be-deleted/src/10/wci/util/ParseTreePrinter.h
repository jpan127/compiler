/**
 * <h1>ParseTreePrinter</h1>
 *
 * <p>Print a parse tree.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef PARSETREEPRINTER_H_
#define PARSETREEPRINTER_H_

#include <iostream>
#include <string>
#include <vector>
#include "../intermediate/ICode.h"
#include "../intermediate/ICodeNode.h"
#include "../intermediate/SymTabStack.h"

namespace wci { namespace util {

using namespace std;
using namespace wci::intermediate;

class ParseTreePrinter
{
public:
    /**
     * Constructor
     * @param ps the output print stream.
     */
    ParseTreePrinter();

    /**
     * Print the intermediate code as a parse tree.
     * @param symTabStack the symbol table stack.
     */
    void print(SymTabStack *symtab_stack);

private:
    static const int INDENT_WIDTH;
    static const int LINE_WIDTH;
    static string INDENT;          // indent spaces

    int length;          // output line length
    string indentation;  // indentation of a line
    string line;         // output line

    /**
     * Print the parse tree for a routine.
     * @param routine_id the routine identifier's symbol table entry.
     */
    void print_routine(SymTabEntry *routine_id);

    /**
     * Print a parse tree node.
     * @param node the parse tree node.
     */
    void print_node(ICodeNode *node);

    /**
     * Print a parse tree node's attributes.
     * @param node the parse tree node.
     */
    void print_attributes(ICodeNode *node);

    /**
     * Print a node attribute as key="value".
     * @param key the key.
     * @param value the value.
     */
    void print_attribute(ICodeKey key, Object node_value);

    /**
     * Print a parse tree node's child nodes.
     * @param child_nodes the vector of child nodes.
     */
    void print_child_nodes(vector<ICodeNode *> child_nodes);

    /**
     * Print a parse tree node's type specification.
     * @param node the parse tree node.
     */
    void print_type_spec(ICodeNode *node);

    /**
     * Append text to the output line.
     * @param text the text to append.
     */
    void append(string text);

    /**
     * Print an output line.
     */
    void print_line();
};

}}  // namespace wci::util

#endif /* PARSETREEPRINTER_H_ */
