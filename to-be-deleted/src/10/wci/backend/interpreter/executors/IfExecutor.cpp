/**
 * <h1>IfExecutor</h1>
 *
 * <p>Execute an IF statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include "IfExecutor.h"
#include "StatementExecutor.h"
#include "ExpressionExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

IfExecutor::IfExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

Object IfExecutor::execute(ICodeNode *node)
{
    // Get the IF node's children.
    vector<ICodeNode *> children = node->get_children();
    ICodeNode *expr_node = children[0];
    ICodeNode *then_stmt_node = children[1];
    ICodeNode *else_stmt_node = children.size() > 2 ? children[2] : nullptr;

    ExpressionExecutor expression_executor(this);
    StatementExecutor statement_executor(this);

    // Evaluate the expression to determine which statement to execute.
    Object data_value = expression_executor.execute(expr_node);
    if (cast(data_value, bool))
    {
        statement_executor.execute(then_stmt_node);
    }
    else if (else_stmt_node != nullptr)
    {
        statement_executor.execute(else_stmt_node);
    }

    ++execution_count;  // count the IF statement itself
    return Object();    // empty
}

}}}}  // namespace wci::backend::interpreter::executors
