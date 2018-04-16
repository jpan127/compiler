/**
 * <h1>ICodeFactory</h1>
 *
 * <p>A factory for creating objects that implement the intermediate code.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "ICode.h"
#include "ICodeNode.h"

#ifndef ICODEFACTORY_H_
#define ICODEFACTORY_H_

namespace wci { namespace intermediate {

class ICodeFactory
{
public:
    /**
     * Create and return an intermediate code implementation.
     * @return the intermediate code implementation.
     */
    static ICode *create_icode();

    /**
     * Create and return a node implementation.
     * @param type the node type.
     * @return the node implementation.
     */
    static ICodeNode *create_icode_node(const ICodeNodeType type);
};

}} // namespace wci::intermediate

#endif /* ICODEFACTORY_H_ */
