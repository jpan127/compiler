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
#include "../frontend/Token.h"
#include "../Object.h"

namespace wci { namespace intermediate {

using namespace std;
using namespace wci;
using namespace wci::frontend;

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
    virtual Object get_attribute(const ICodeKey key) = 0;

    /**
     * Set a node attribute.
     * To be defined by an implementation subclass.
     * @param key the attribute key.
     * @param value the attribute value.
     */
    virtual void set_attribute(const ICodeKey key, Object value) = 0;

    /**
     * Make a copy of this node.
     * To be defined by an implementation subclass.
     * @return the copy.
     */
    virtual ICodeNode *copy() = 0;
};

}}  // namespace wci::intermediate

#endif /* ICODENODE_H_ */
