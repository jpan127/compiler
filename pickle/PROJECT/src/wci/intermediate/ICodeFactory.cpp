/**
 * <h1>ICodeFactory</h1>
 *
 * <p>A factory for creating objects that implement the intermediate code.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "ICodeFactory.h"
#include "ICode.h"
#include "ICodeNode.h"
#include "icodeimpl/ICodeImpl.h"
#include "icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace intermediate {

using namespace wci::intermediate::icodeimpl;

ICode *ICodeFactory::create_icode()
{
    return new ICodeImpl();
}

ICodeNode *ICodeFactory::create_icode_node(const ICodeNodeType type)
{
    return new ICodeNodeImpl(type);
}

}} // namespace wci::intermediate
