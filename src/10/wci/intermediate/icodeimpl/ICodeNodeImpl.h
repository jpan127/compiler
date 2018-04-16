/**
 * <h1>ICodeNodeImpl</h1>
 *
 * <p>An implementation of a node of the intermediate code.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef ICODENODEIMPL_H_
#define ICODENODEIMPL_H_

#include <map>
#include "../ICodeNode.h"

namespace wci { namespace intermediate { namespace icodeimpl {

/**
 * Intermediate code node types.
 */
enum class ICodeNodeTypeImpl
{
    // Program structure
    PROGRAM, PROCEDURE, FUNCTION,

    // Statements
    COMPOUND, ASSIGN, LOOP, TEST, CALL, PARAMETERS,
    IF, SELECT, SELECT_BRANCH, SELECT_CONSTANTS, NO_OP,

    // Relational operators
    EQ, NE, LT, LE, GT, GE, NOT,

    // Additive operators
    ADD, SUBTRACT, OR, NEGATE,

    // Multiplicative operators
    MULTIPLY, INTEGER_DIVIDE, FLOAT_DIVIDE, MOD, AND,

    // Operands
    VARIABLE, SUBSCRIPTS, FIELD,
    INTEGER_CONSTANT, REAL_CONSTANT,
    STRING_CONSTANT, BOOLEAN_CONSTANT,

    // WRITE parameter
    WRITE_PARM,
};

constexpr ICodeNodeTypeImpl NT_PROGRAM = ICodeNodeTypeImpl::PROGRAM;
constexpr ICodeNodeTypeImpl NT_PROCEDURE = ICodeNodeTypeImpl::PROCEDURE;
constexpr ICodeNodeTypeImpl NT_FUNCTION = ICodeNodeTypeImpl::FUNCTION;

constexpr ICodeNodeTypeImpl NT_COMPOUND = ICodeNodeTypeImpl::COMPOUND;
constexpr ICodeNodeTypeImpl NT_ASSIGN = ICodeNodeTypeImpl::ASSIGN;
constexpr ICodeNodeTypeImpl NT_LOOP = ICodeNodeTypeImpl::LOOP;
constexpr ICodeNodeTypeImpl NT_TEST = ICodeNodeTypeImpl::TEST;
constexpr ICodeNodeTypeImpl NT_CALL = ICodeNodeTypeImpl::CALL;
constexpr ICodeNodeTypeImpl NT_PARAMETERS = ICodeNodeTypeImpl::PARAMETERS;
constexpr ICodeNodeTypeImpl NT_IF = ICodeNodeTypeImpl::IF;
constexpr ICodeNodeTypeImpl NT_SELECT = ICodeNodeTypeImpl::SELECT;
constexpr ICodeNodeTypeImpl NT_SELECT_BRANCH =
                                        ICodeNodeTypeImpl::SELECT_BRANCH;
constexpr ICodeNodeTypeImpl NT_SELECT_CONSTANTS =
                                     ICodeNodeTypeImpl::SELECT_CONSTANTS;
constexpr ICodeNodeTypeImpl NT_NO_OP = ICodeNodeTypeImpl::NO_OP;

constexpr ICodeNodeTypeImpl NT_EQ = ICodeNodeTypeImpl::EQ;
constexpr ICodeNodeTypeImpl NT_NE = ICodeNodeTypeImpl::NE;
constexpr ICodeNodeTypeImpl NT_LT = ICodeNodeTypeImpl::LT;
constexpr ICodeNodeTypeImpl NT_LE = ICodeNodeTypeImpl::LE;
constexpr ICodeNodeTypeImpl NT_GT = ICodeNodeTypeImpl::GT;
constexpr ICodeNodeTypeImpl NT_GE = ICodeNodeTypeImpl::GE;
constexpr ICodeNodeTypeImpl NT_NOT = ICodeNodeTypeImpl::NOT;

constexpr ICodeNodeTypeImpl NT_ADD = ICodeNodeTypeImpl::ADD;
constexpr ICodeNodeTypeImpl NT_SUBTRACT = ICodeNodeTypeImpl::SUBTRACT;
constexpr ICodeNodeTypeImpl NT_OR = ICodeNodeTypeImpl::OR;
constexpr ICodeNodeTypeImpl NT_NEGATE = ICodeNodeTypeImpl::NEGATE;

constexpr ICodeNodeTypeImpl NT_MULTIPLY = ICodeNodeTypeImpl::MULTIPLY;
constexpr ICodeNodeTypeImpl NT_INTEGER_DIVIDE = ICodeNodeTypeImpl::INTEGER_DIVIDE;
constexpr ICodeNodeTypeImpl NT_FLOAT_DIVIDE = ICodeNodeTypeImpl::FLOAT_DIVIDE;
constexpr ICodeNodeTypeImpl NT_MOD = ICodeNodeTypeImpl::MOD;
constexpr ICodeNodeTypeImpl NT_AND = ICodeNodeTypeImpl::AND;

constexpr ICodeNodeTypeImpl NT_VARIABLE = ICodeNodeTypeImpl::VARIABLE;
constexpr ICodeNodeTypeImpl NT_SUBSCRIPTS = ICodeNodeTypeImpl::SUBSCRIPTS;
constexpr ICodeNodeTypeImpl NT_FIELD = ICodeNodeTypeImpl::FIELD;
constexpr ICodeNodeTypeImpl NT_INTEGER_CONSTANT = ICodeNodeTypeImpl::INTEGER_CONSTANT;
constexpr ICodeNodeTypeImpl NT_REAL_CONSTANT = ICodeNodeTypeImpl::REAL_CONSTANT;
constexpr ICodeNodeTypeImpl NT_STRING_CONSTANT = ICodeNodeTypeImpl::STRING_CONSTANT;
constexpr ICodeNodeTypeImpl NT_BOOLEAN_CONSTANT = ICodeNodeTypeImpl::BOOLEAN_CONSTANT;

constexpr ICodeNodeTypeImpl NT_WRITE_PARM = ICodeNodeTypeImpl::WRITE_PARM;

/**
 * Intermediate code node keys.
 */
enum class ICodeKeyImpl
{
    LINE, ID, LEVEL, VALUE, TYPE_ID,
};

constexpr ICodeKeyImpl LINE = ICodeKeyImpl::LINE;
constexpr ICodeKeyImpl ID = ICodeKeyImpl::ID;
constexpr ICodeKeyImpl LEVEL = ICodeKeyImpl::LEVEL;
constexpr ICodeKeyImpl VALUE = ICodeKeyImpl::VALUE;
constexpr ICodeKeyImpl TYPE_ID = ICodeKeyImpl::TYPE_ID;

class ICodeNodeImpl : public ICodeNode
{
public:
    /**
     * Constructor.
     * @param type the node type whose name will be the name of this node.
     */
    ICodeNodeImpl(const ICodeNodeType type);

    /**
     * Destructor.
     */
    virtual ~ICodeNodeImpl();

    /**
     * Getter.
     * @return the node type.
     */
    ICodeNodeType get_type() const;

    /**
     * Return the parent of this node.
     * @return the parent node.
     */
    ICodeNode *get_parent();

    /**
     * Return the type specification of this node.
     * @return the type specification.
     */
    TypeSpec *get_typespec() const;

    /**
     * Set the type specification of this node.
     * @param spec the type specification to set.
     */
    void set_typespec(TypeSpec *spec);

    /**
     * Return an array list of this node's children.
     * @return the array list of children.
     */
    vector<ICodeNode *> get_children();

    /**
     * Getter.
     * @return the node contents.
     */
    map<ICodeKey, Object>& get_contents();

    /**
     * Add a child node.
     * @param node the child node.
     * @return the child node.
     */
    ICodeNode *add_child(ICodeNode *node);

    /**
     * Get the value of a node attribute.
     * Implementation of wci::intermediate::ICodeNode.
     * @param key the attribute key.
     * @return the attribute value.
     */
    Object get_attribute(const ICodeKey key);

    /**
     * Set a node attribute.
     * Implementation of wci::intermediate::ICodeNode.
     * @param key the attribute key.
     * @param value the attribute value.
     */
    void set_attribute(const ICodeKey key, Object value);

    /**
     * Make a copy of this node.
     * Implementation of wci::intermediate::ICodeNode.
     * @return the copy.
     */
    ICodeNode *copy();

    static map<ICodeNodeTypeImpl, string> NODE_TYPE_NAMES;
    static map<ICodeKeyImpl, string> NODE_KEY_NAMES;

private:
    ICodeNodeType type;            // node type
    ICodeNode *parent;             // node's parent
    vector<ICodeNode *> children;  // node's children
    TypeSpec *typespec;            // data type specification
    map<ICodeKey, Object> contents;

    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::intermediate::icodeimpl

#endif /* ICODENODEIMPL_H_ */
