/**
 * <h1>LoopExecutor</h1>
 *
 * <p>Execute a loop statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include "LoopExecutor.h"
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

LoopExecutor::LoopExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

Object LoopExecutor::execute(ICodeNode *node)
{
    bool exit_loop = false;
    ICodeNode *expr_node = nullptr;
    vector<ICodeNode *> loop_children = node->get_children();

    ExpressionExecutor expression_executor(this);
    StatementExecutor statement_executor(this);

    // Loop until the TEST expression value is true.
    while (!exit_loop)
    {
        ++execution_count;  // count the loop statement itself

        // Execute the children of the LOOP node.
        for (ICodeNode *child : loop_children) {
            ICodeNodeTypeImpl child_type =
                                  (ICodeNodeTypeImpl) child->get_type();

            // TEST node?
            if (child_type == NT_TEST)
            {
                if (expr_node == nullptr)
                {
                    expr_node = child->get_children()[0];
                }

                Object data_value = expression_executor.execute(expr_node);
                exit_loop = cast(data_value, bool);
            }

            // Statement node.
            else
            {
                statement_executor.execute(child);
            }

            // Exit if the TEST expression value is true,
            if (exit_loop) break;
        }
    }

    return Object();  // empty
}

}}}}  // namespace wci::backend::interpreter::executors
