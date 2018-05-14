/**
 * <h1>AssignmentExecutor</h1>
 *
 * <p>Execute an assignment statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "AssignmentExecutor.h"
#include "StatementExecutor.h"
#include "ExpressionExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../../../message/Message.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::message;

AssignmentExecutor::AssignmentExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

Object AssignmentExecutor::execute(ICodeNode *node)
{
    // The ASSIGN node's children are the target variable
    // and the expression.
    vector<ICodeNode *> children = node->get_children();
    ICodeNode *variable_node = children[0];
    ICodeNode *expression_node = children[1];

    // Execute the expression and get its value.
    ExpressionExecutor expression_executor(this);
    Object result_value = expression_executor.execute(expression_node);

    // Set the value as an attribute of the
    // target variable's symbol table entry.
    SymTabEntry *id = cast(variable_node->get_attribute((ICodeKey) ID),
                           SymTabEntry*);
    id->set_attribute((SymTabKey) DATA_VALUE, result_value);

    // Send a message about the assignment.
    send_assignment_message(node, id->get_name(), result_value);

    ++execution_count;
    return Object();  // empty
}

void AssignmentExecutor::send_assignment_message(ICodeNode *node,
                                                 string variable_name,
                                                 Object data_value)
{
    Object line_number = node->get_attribute((ICodeKey) LINE);

    // Send an ASSIGN message.
    if (!line_number.empty())
    {
        Message message(ASSIGN,
                        LINE_NUMBER, stringify(line_number),
                        VARIABLE_NAME, variable_name,
                        RESULT_VALUE, stringify(data_value));
        send_message(message);
    }
}

}}}}  // namespace wci::backend::interpreter::executors
