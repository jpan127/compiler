/**
 * <h1>ParseTreePrinter</h1>
 *
 * <p>Print a parse tree.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include "ParseTreePrinter.h"
#include "../intermediate/SymTab.h"
#include "../intermediate/SymTabEntry.h"
#include "../intermediate/symtabimpl/SymTabImpl.h"
#include "../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../intermediate/ICode.h"
#include "../intermediate/ICodeNode.h"
#include "../intermediate/icodeimpl/ICodeNodeImpl.h"
#include "../intermediate/TypeSpec.h"
#include "../intermediate/typeimpl/TypeSpecImpl.h"

namespace wci { namespace util {

using namespace std;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::icodeimpl;
using namespace wci::intermediate::typeimpl;

const int ParseTreePrinter::INDENT_WIDTH = 4;
const int ParseTreePrinter::LINE_WIDTH = 80;
string ParseTreePrinter::INDENT = string(INDENT_WIDTH, ' ');

ParseTreePrinter::ParseTreePrinter() : length(0), indentation("")
{
}

void ParseTreePrinter::print(SymTabStack *symtab_stack)
{
    cout << endl << "===== INTERMEDIATE CODE =====" << endl;

    line = "";
    indentation = "";

    SymTabEntry *program_id = symtab_stack->get_program_id();
    print_routine(program_id);
}

void ParseTreePrinter::print_routine(SymTabEntry *routine_id)
{
    Definition defn = routine_id->get_definition();
    cout << endl << "*** "
         << SymTabEntryImpl::DEFINITION_WORDS[(DefinitionImpl) defn]
         << " " << routine_id->get_name() << " ***" << endl << endl;

    // Print the intermediate code in the routine's symbol table entry.
    EntryValue *entry_value = routine_id->get_attribute(
                                              (SymTabKey) ROUTINE_ICODE);
    ICode *icode = entry_value->icode;
    if (icode->get_root() != nullptr)
    {
        print_node(icode->get_root());
    }

    // Print any procedures and functions defined in the routine.
    entry_value =
        routine_id->get_attribute((SymTabKey) ROUTINE_ROUTINES);
    if ((entry_value != nullptr) && (entry_value->v.size() > 0))
    {
        for (SymTabEntry *routine_id : entry_value->v)
        {
            print_routine(routine_id);
        }
    }
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

    // Print the node's children followed by the closing tag.
    vector<ICodeNode *> child_nodes = node->get_children();
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

/**
 * Print a parse tree node's attributes.
 * @param node the parse tree node.
 */
void ParseTreePrinter::print_attributes(ICodeNode *node)
{
    string save_indentation = indentation;
    indentation += INDENT;

    map<ICodeKey, NodeValue *>& contents =
            ((ICodeNodeImpl *) node)->get_contents();
    map<ICodeKey, NodeValue *>::iterator it;
    for (it = contents.begin(); it != contents.end(); it++)
    {
        print_attribute((ICodeKey) it->first, it->second);
    }

    indentation = save_indentation;
}

void ParseTreePrinter::print_attribute(ICodeKey key, NodeValue *node_value)
{
    DataValue *data_value = node_value->value;
    string key_name = ICodeNodeImpl::NODE_KEY_NAMES[(ICodeKeyImpl) key];
    string value_string;

    switch ((ICodeKeyImpl) key)
    {
        case ID:
        {
            value_string = node_value->id->get_name();
            break;
        }

        case LINE:
        case LEVEL:
        case VALUE:
        case TYPE_ID:
        {
            value_string = data_value->display();
            break;
        }
    }

    string text = key_name + "=\"" + value_string + "\"";
    append(" "); append(text);

    // Include an identifier's nesting level.
    if (key == (ICodeKey) ID)
    {
        int level = node_value->id->get_symtab()->get_nesting_level();
        NodeValue v;
        v.value = new DataValue(level);
        print_attribute((ICodeKey) LEVEL, &v);
    }
}

/**
 * Print a parse tree node's child nodes.
 * @param child_nodes the array list of child nodes.
 */
void ParseTreePrinter::print_child_nodes(vector<ICodeNode *> child_nodes)
{
    string saveIndentation = indentation;
    indentation += INDENT;

    for (ICodeNode *child : child_nodes) print_node(child);

    indentation = saveIndentation;
}

/**
 * Print a parse tree node's type specification.
 * @param node the parse tree node.
 */
void ParseTreePrinter::print_type_spec(ICodeNode *node)
{
    TypeSpec *typespec = node->get_typespec();

    if (typespec != nullptr)
    {
        string save_margin = indentation;
        indentation += INDENT;

        string type_name;
        SymTabEntry *type_id = typespec->get_identifier();

        // Named type: Print the type identifier's name.
        if (type_id != nullptr) type_name = type_id->get_name();

        // Unnamed type: Print an artificial type identifier name.
        else
        {
            hash<TypeSpec *> typespec_hash;
            hash<string>     form_hash;
            TypeFormImpl form = (TypeFormImpl) typespec->get_form();
            string form_name = TypeSpecImpl::TYPE_FORM_NAMES[form];
            stringstream stream;
            stream << hex << abs((int) (  typespec_hash(typespec)
                                        + form_hash(form_name)));
            type_name = "$anon_" + stream.str();
        }

        NodeValue *node_value = new NodeValue(new DataValue(type_name));
        print_attribute((ICodeKey) TYPE_ID, node_value);
        indentation = save_margin;
    }
}

/**
 * Append text to the output line.
 * @param text the text to append.
 */
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

/**
 * Print an output line.
 */
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
