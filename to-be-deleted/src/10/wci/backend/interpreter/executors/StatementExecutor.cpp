/**
 * <h1>StatementExecutor</h1>
 *
 * <p>Execute a statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "StatementExecutor.h"
#include "CompoundExecutor.h"
#include "AssignmentExecutor.h"
#include "LoopExecutor.h"
#include "IfExecutor.h"
#include "SelectExecutor.h"
#include "../Executor.h"
#include "../RuntimeError.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"
#include "../../../message/Message.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;
using namespace wci::message;

StatementExecutor::StatementExecutor(Executor *parent)
    : parent(parent)
{
}

Object StatementExecutor::execute(ICodeNode *node)
{
    ICodeNodeTypeImpl node_type = (ICodeNodeTypeImpl) node->get_type();

    // Send a message about the current source line.
    send_at_line_message(node);

    switch (node_type)
    {
        case NT_COMPOUND:
        {
            CompoundExecutor compound_executor(this);
            return compound_executor.execute(node);
        }

        case NT_ASSIGN:
        {
            AssignmentExecutor assignment_executor(this);
            return assignment_executor.execute(node);
        }

        case NT_LOOP:
        {
            LoopExecutor loop_executor(this);
            return loop_executor.execute(node);
        }

        case NT_IF:
        {
            IfExecutor if_executor(this);
            return if_executor.execute(node);
        }

        case NT_SELECT:
        {
            SelectExecutor select_executor(this);
            return select_executor.execute(node);
        }

        case NT_NO_OP: return Object();  // empty

        default:
        {
            error_handler.flag(node, UNIMPLEMENTED_FEATURE, this);
            return Object();  // empty
        }
    }
}

void StatementExecutor::send_at_line_message(ICodeNode *node)
{
    Object line_number = node->get_attribute((ICodeKey) LINE);

    // Send the SOURCE_LINE message.
    if (!line_number.empty())
    {
        Message message(AT_LINE, LINE_NUMBER, stringify(line_number));
        send_message(message);
    }
}

}}}}  // namespace wci::backend::interpreter::executors
