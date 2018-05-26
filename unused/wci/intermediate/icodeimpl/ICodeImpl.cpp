/**
 * <h1>ICodeImpl</h1>
 *
 * <p>An implementation of the intermediate code as a parse tree.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "ICodeImpl.h"
#include "../ICodeNode.h"

namespace wci { namespace intermediate { namespace icodeimpl {

using namespace wci::intermediate;

ICodeNode *ICodeImpl::get_root() const { return root; }

ICodeNode *ICodeImpl::set_root(ICodeNode *node)
{
    root = node;
    return node;
}

}}} // namespace wci::intermediate::icodeimpl
