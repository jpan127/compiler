/**
 * <h1>IfExecutor</h1>
 *
 * <p>Execute an IF statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include <map>
#include "SelectExecutor.h"
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

JumpCache SelectExecutor::jump_cache;

SelectExecutor::SelectExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

Object SelectExecutor::execute(ICodeNode *node)
{
    // Is there already an entry for this SELECT node in the
    // jump table cache? If not, create a jump table entry.
    JumpTable *jump_table = jump_cache[node];
    if (jump_table == nullptr)
    {
        jump_table = create_jump_table(node);
        jump_cache[node] = jump_table;
    }

    // Get the SELECT node's children.
    vector<ICodeNode *> select_children = node->get_children();
    ICodeNode *expr_node = select_children[0];

    // Evaluate the SELECT expression.
    ExpressionExecutor expression_executor(this);
    Object select_value = expression_executor.execute(expr_node);

    // If there is a selection, execute the SELECT_BRANCH's statement.
    int key = instanceof(select_value, int)
                                    ? cast(select_value, int)
                                    : cast(select_value, string)[0];
    ICodeNode *statement_node = (*jump_table)[key];
    if (statement_node != nullptr)
    {
        StatementExecutor statement_executor(this);
        statement_executor.execute(statement_node);
    }

    ++execution_count;  // count the SELECT statement itself
    return Object();    // empty
}

JumpTable *SelectExecutor::create_jump_table(ICodeNode *node)
{
    JumpTable *jump_table = new JumpTable();

    // Loop over children that are SELECT_BRANCH nodes.
    vector<ICodeNode *> select_children = node->get_children();
    for (int i = 1; i < select_children.size(); ++i)
    {
        ICodeNode *branch_node = select_children[i];
        ICodeNode *constants_node = branch_node->get_children()[0];
        ICodeNode *statement_node = branch_node->get_children()[1];

        // Loop over the constants children of the branch's CONSTANTS_NODE.
        vector<ICodeNode *> constants_list = constants_node->get_children();
        for (ICodeNode *constants_node : constants_list)
        {
            // Create a jump table entry.
            Object data_value =
                    constants_node->get_attribute((ICodeKey) VALUE);
            int value = cast(data_value, int);
            (*jump_table)[value] = statement_node;
        }
    }

    return jump_table;
}

}}}}  // namespace wci::backend::interpreter::executors
