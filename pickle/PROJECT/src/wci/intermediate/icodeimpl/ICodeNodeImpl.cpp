/**
 * <h1>ICodeNodeImpl</h1>
 *
 * <p>An implementation of a node of the intermediate code.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include <map>
#include "ICodeNodeImpl.h"
#include "../ICodeNode.h"
#include "../ICodeFactory.h"

namespace wci { namespace intermediate { namespace icodeimpl {

using namespace wci::intermediate;

bool ICodeNodeImpl::INITIALIZED = false;

map<ICodeNodeTypeImpl, string> ICodeNodeImpl::NODE_TYPE_NAMES;
map<ICodeKeyImpl, string> ICodeNodeImpl::NODE_KEY_NAMES;

void ICodeNodeImpl::initialize()
{
    if (INITIALIZED) return;

    vector<ICodeNodeTypeImpl> types =
    {
        // Program structure
        NT_PROGRAM,
        NT_PROCEDURE,
        NT_FUNCTION,

        // Statements
        NT_COMPOUND,
        NT_ASSIGN,
        NT_LOOP,
        NT_TEST,
        NT_CALL,
        NT_PARAMETERS,
        NT_IF,
        NT_SELECT,
        NT_SELECT_BRANCH,
        NT_SELECT_CONSTANTS,
        NT_NO_OP,

        // Relational operators
        NT_EQ,
        NT_NE,
        NT_LT,
        NT_LE,
        NT_GT,
        NT_GE,
        NT_NOT,

        // Additive operators
        NT_ADD,
        NT_SUBTRACT,
        NT_OR,
        NT_NEGATE,

        // Multiplicative operators
        NT_MULTIPLY,
        NT_INTEGER_DIVIDE,
        NT_FLOAT_DIVIDE,
        NT_MOD,
        NT_AND,

        // Operands
        NT_VARIABLE,
        NT_SUBSCRIPTS,
        NT_FIELD,
        NT_INTEGER_CONSTANT,
        NT_REAL_CONSTANT,
        NT_STRING_CONSTANT,
        NT_BOOLEAN_CONSTANT,

        // WRITE parameter
        NT_WRITE_PARM,
    };

    vector<string> type_names =
    {
        // Program structure
        "PROGRAM", "PROCEDURE", "FUNCTION",

        // Statements
        "COMPOUND", "ASSIGN", "LOOP", "TEST", "CALL", "PARAMETERS",
        "IF", "SELECT", "SELECT_BRANCH", "SELECT_CONSTANTS", "NO_OP",

        // Relational operators
        "EQ", "NE", "LT", "LE", "GT", "GE", "NOT",

        // Additive operators
        "ADD", "SUBTRACT", "OR", "NEGATE",

        // Multiplicative operators
        "MULTIPLY", "INTEGER_DIVIDE", "FLOAT_DIVIDE", "MOD", "AND",

        // Operands
        "VARIABLE", "SUBSCRIPTS", "FIELD",
        "INTEGER_CONSTANT", "REAL_CONSTANT",
        "STRING_CONSTANT", "BOOLEAN_CONSTANT",

        // WRITE parameter
        "WRITE_PARM",
    };

    for (int i = 0; i < types.size(); i++)
    {
        NODE_TYPE_NAMES[types[i]] = type_names[i];
    }

    vector<ICodeKeyImpl> keys =
    {
        ICodeKeyImpl::LINE,
        ICodeKeyImpl::ID,
        ICodeKeyImpl::LEVEL,
        ICodeKeyImpl::VALUE,
        ICodeKeyImpl::TYPE_ID,
    };

    vector<string> key_names =
    {
        "line", "id", "level", "value", "type_id",
    };

    for (int i = 0; i < keys.size(); i++)
    {
        NODE_KEY_NAMES[keys[i]] = key_names[i];
    }

    INITIALIZED = true;
}

ICodeNodeImpl::ICodeNodeImpl(const ICodeNodeType type)
    : type(type), parent(nullptr), typespec(nullptr)
{
    initialize();
}

ICodeNodeImpl::~ICodeNodeImpl()
{
    for (ICodeNode *node : children) if (node != nullptr) delete node;

    for (pair<ICodeKey, NodeValue *> p : contents)
    {
        if (p.second != nullptr)
        {
            if (p.second->id != nullptr)    delete p.second->id;
            if (p.second->value != nullptr) delete p.second->value;
            delete p.second;
        }
    }
}

ICodeNodeType ICodeNodeImpl::get_type() const { return type; }

ICodeNode *ICodeNodeImpl::get_parent() { return parent; }

TypeSpec *ICodeNodeImpl::get_typespec() const { return typespec; }

void ICodeNodeImpl::set_typespec(TypeSpec *spec) { typespec = spec; }

vector<ICodeNode *> ICodeNodeImpl::get_children() { return children; }

map<ICodeKey, NodeValue *>& ICodeNodeImpl::get_contents()
{
    return contents;
}

NodeValue *ICodeNodeImpl::get_attribute(const ICodeKey key)
{
    return contents.find(key) != contents.end() ? contents[key]
                                                : nullptr;
}

void ICodeNodeImpl::set_attribute(const ICodeKey key, NodeValue *value)
{
    contents[key] = value;
}

ICodeNode *ICodeNodeImpl::add_child(ICodeNode *node)
{
    if (node != nullptr)
    {
        children.push_back(node);
        ((ICodeNodeImpl *) node)->parent = this;
    }
    return node;
}

ICodeNode *ICodeNodeImpl::copy()
{
    // Create a copy with the same type.
    ICodeNodeImpl *copy =
        (ICodeNodeImpl *) ICodeFactory::create_icode_node(type);

    // Copy the contents.
    for (map<ICodeKey, NodeValue *>::iterator it = contents.begin();
         it != contents.end(); it++)
    {
        NodeValue *orig_node_value = it->second;
        DataValue *orig_data_value = orig_node_value->value;
        NodeValue *copy_node_value = new NodeValue();

        // Just copy the type specification pointer
        // and the symbol table entry pointer.
        copy->set_typespec(typespec);
        copy_node_value->id = orig_node_value->id;

        // Make a clone of the data value.
        if (orig_data_value != nullptr)
        {
            DataValue *copy_data_value;

            switch (orig_data_value->type)
            {
                case INTEGER:
                {
                    copy_data_value = new DataValue(orig_data_value->i);
                    break;
                }

                case FLOAT:
                {
                    copy_data_value = new DataValue(orig_data_value->f);
                    break;
                }

                case CHAR:
                {
                    copy_data_value = new DataValue(orig_data_value->c);
                    break;
                }

                case BOOLEAN:
                {
                    copy_data_value = new DataValue(orig_data_value->b);
                    break;
                }

                case STRING:
                {
                    copy_data_value = new DataValue(orig_data_value->s);
                    break;
                }
            }

            copy_node_value->value = copy_data_value;
        }
        else copy_node_value->value = nullptr;

        copy->set_attribute(it->first, copy_node_value);
    }

    return copy;
}

}}}  // namespace wci::intermediate::icodeimpl
