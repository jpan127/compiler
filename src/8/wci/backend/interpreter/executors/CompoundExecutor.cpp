/**
 * <h1>CompoundExecutor</h1>
 *
 * <p>Execute a compound statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include "CompoundExecutor.h"
#include "StatementExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;

CompoundExecutor::CompoundExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

Object CompoundExecutor::execute(ICodeNode *node)
{
    // Loop over the children of the COMPOUND node and execute each child.
    StatementExecutor statement_executor(this);
    vector<ICodeNode *> children = node->get_children();
    for (ICodeNode *child : children) statement_executor.execute(child);

    return Object();  // empty
}

}}}}  // namespace wci::backend::interpreter::executors
