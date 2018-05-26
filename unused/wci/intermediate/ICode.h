/**
 * <h1>ICode</h1>
 *
 * <p>The framework interface that represents the intermediate code.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_INTERMEDIATE_ICODE_H_
#define WCI_INTERMEDIATE_ICODE_H_

namespace wci { namespace intermediate {

class ICodeNode;  // forward declaration

class ICode
{
public:
    /**
     * Destructor.
     */
    virtual ~ICode() {};

    /**
     * Get the root node.
     * @return the root node.
     */
    virtual ICodeNode *get_root() const = 0;

    /**
     * Set and return the root node.
     * @param node the node to set as root.
     * @return the root node.
     */
    virtual ICodeNode *set_root(ICodeNode *node) = 0;
};

}} // namespace wci::intermediate

#endif /* WCI_INTERMEDIATE_ICODE_H_ */
