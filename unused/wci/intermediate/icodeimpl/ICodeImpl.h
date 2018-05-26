/**
 * <h1>ICodeImpl</h1>
 *
 * <p>An implementation of the intermediate code as a parse tree.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef ICODEIMPL_H_
#define ICODEIMPL_H_

#include "../ICode.h"

namespace wci { namespace intermediate { namespace icodeimpl {

class ICodeImpl : public ICode
{
public:
    /**
     * Get the root node.
     * @return the root node.
     */
    ICodeNode *get_root() const;

    /**
     * Set and return the root node.
     * @param node the node to set as root.
     * @return the root node.
     */
    ICodeNode *set_root(ICodeNode *node);

private:
    ICodeNode *root;
};

}}}  // namespace wci::intermediate::icodeimpl

#endif /* ICODEIMPL_H_ */
