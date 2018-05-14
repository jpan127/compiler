/**
 * <h1>ParseTreePrinter</h1>
 *
 * <p>Print a parse tree.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <iostream>
#include <string>
#include <vector>
#include "ParseTreePrinter.h"
#include "../Object.h"
#include "../intermediate/ICode.h"
#include "../intermediate/ICodeNode.h"
#include "../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace util {

using namespace std;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

const int ParseTreePrinter::INDENT_WIDTH = 4;
const int ParseTreePrinter::LINE_WIDTH = 80;
string ParseTreePrinter::INDENT = string(INDENT_WIDTH, ' ');

ParseTreePrinter::ParseTreePrinter() : length(0), indentation("")
{
}

void ParseTreePrinter::print(ICode *icode)
{
    cout << endl << "===== INTERMEDIATE CODE =====" << endl << endl;

    line = "";
    indentation = "";
    print_node(icode->get_root());
    print_line();
}

void ParseTreePrinter::print_node(ICodeNode *node)
{
    // Opening tag.
    string type_name =
            ICodeNodeImpl::NODE_TYPE_NAMES[
                           (ICodeNodeTypeImpl) node->get_type()];
    append(indentation);
    append("<" + type_name);

    print_attributes(node);
    print_type_spec(node);

    vector<ICodeNode *> child_nodes = node->get_children();

    // Print the node's children followed by the closing tag.
    if (child_nodes.size() > 0)
    {
        append(">");
        print_line();

        print_child_nodes(child_nodes);
        append(indentation); append("</" + type_name + ">");
    }

    // No children: Close off the tag.
    else
    {
        append(" "); append("/>");
    }

    print_line();
}

void ParseTreePrinter::print_attributes(ICodeNode *node)
{
    string save_indentation = indentation;
    indentation += INDENT;

    map<ICodeKey, Object>& contents =
            ((ICodeNodeImpl *) node)->get_contents();
    map<ICodeKey, Object>::iterator it;
    for (it = contents.begin(); it != contents.end(); it++)
    {
        print_attribute((ICodeKey) it->first, it->second);
    }

    indentation = save_indentation;
}

void ParseTreePrinter::print_attribute(ICodeKey key, Object node_value)
{
    string key_name = ICodeNodeImpl::NODE_KEY_NAMES[(ICodeKeyImpl) key];
    string value_string;

    switch ((ICodeKeyImpl) key)
    {
        case ID:
        {
            value_string = cast(node_value, SymTabEntry*)->get_name();
            break;
        }

        case LINE:
        case LEVEL:
        case VALUE:
        {
            value_string = stringify(node_value);
            break;
        }
    }

    string text = key_name + "=\"" + value_string + "\"";
    append(" "); append(text);

    // Include an identifier's nesting level.
    if (key == (ICodeKey) ID)
    {
        int level = cast(node_value, SymTabEntry*)->get_symtab()->get_nesting_level();
        print_attribute((ICodeKey) LEVEL, level);
    }
}

void ParseTreePrinter::print_child_nodes(vector<ICodeNode *> child_nodes)
{
    string saveIndentation = indentation;
    indentation += INDENT;

    for (ICodeNode *child : child_nodes) print_node(child);

    indentation = saveIndentation;
}

void ParseTreePrinter::print_type_spec(ICodeNode *node)
{
}

void ParseTreePrinter::append(string text)
{
    int text_length = text.length();
    bool line_break = false;

    // Wrap lines that are too long.
    if (length + text_length > LINE_WIDTH)
    {
        print_line();
        line += indentation;
        length = indentation.length();
        line_break = true;
    }

    // Append the text.
    if (!(line_break && (text == " ")))
    {
        line += text;
        length += text_length;
    }
}

void ParseTreePrinter::print_line()
{
    if (length > 0)
    {
        cout << line << endl;
        line = "";
        length = 0;
    }
}

}}  // namespace wci::util
