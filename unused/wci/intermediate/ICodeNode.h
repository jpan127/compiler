/**
 * <h1>ICodeNode</h1>
 *
 * <p>The interface for a node of the intermediate code.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef ICODENODE_H_
#define ICODENODE_H_

#include <string>
#include <vector>
#include "ICode.h"
#include "SymTabEntry.h"
#include "TypeSpec.h"
#include "../DataValue.h"

namespace wci { namespace intermediate {

using namespace std;
using namespace wci;

/**
 * Intermediate code node types.
 */
enum class ICodeNodeType
{
    // to be "subclassed" by implementation-specific icode node keys
};

/**
 * Intermediate code node keys.
 */
enum class ICodeKey
{
    // to be "subclassed" by implementation-specific icode node keys
};

/**
 * Node value.
 */
struct NodeValue
{
    DataValue   *value;
    SymTabEntry *id;

    NodeValue()                   : value(nullptr), id(nullptr) {};
    NodeValue(DataValue   *value) : value(value), id(nullptr) {};
    NodeValue(SymTabEntry *id)    : value(nullptr), id(id) {};

    ~NodeValue()
    {
        if (value != nullptr) delete value;
        if (id    != nullptr) delete id;
    };
};

class ICodeNode
{
public:
    /**
     * Destructor.
     */
    virtual ~ICodeNode() {};

    /**
     * Getter.
     * @return the node type.
     */
    virtual ICodeNodeType get_type() const = 0;

    /**
     * Return the parent of this node.
     * @return the parent node.
     */
    virtual ICodeNode *get_parent() = 0;

    /**
     * Return the type specification of this node.
     * @return the type specification.
     */
    virtual TypeSpec *get_typespec() const = 0;

    /**
     * Set the type specification of this node.
     * @param spec the type specification to set.
     */
    virtual void set_typespec(TypeSpec *spec) = 0;

    /**
     * Return an array list of this node's children.
     * @return the array list of children.
     */
    virtual vector<ICodeNode *> get_children() = 0;

    /**
     * Add a child node.
     * @param node the child node.
     * @return the child node.
     */
    virtual ICodeNode *add_child(ICodeNode *node) = 0;

    /**
     * Get the value of a node attribute.
     * To be defined by an implementation subclass.
     * @param key the attribute key.
     * @return the attribute value.
     */
    virtual NodeValue *get_attribute(const ICodeKey key) = 0;

    /**
     * Set a node attribute.
     * To be defined by an implementation subclass.
     * @param key the attribute key.
     * @param value the attribute value.
     */
    virtual void set_attribute(const ICodeKey key, NodeValue *value) = 0;

    /**
     * Make a copy of this node.
     * To be defined by an implementation subclass.
     * @return the copy.
     */
    virtual ICodeNode *copy() = 0;
};

}}  // namespace wci::intermediate

#endif /* ICODENODE_H_ */
