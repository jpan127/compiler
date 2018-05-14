/**
 * <h1>AssignmentExecutor</h1>
 *
 * <p>Execute an assignment statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef ASSIGNMENTEXECUTOR_H_
#define ASSIGNMENTEXECUTOR_H_

#include <string>
#include "StatementExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../message/Message.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::message;

class AssignmentExecutor : public StatementExecutor
{
public:
    /**
     * Constructor.
     * @param the parent executor.
     */
    AssignmentExecutor(Executor *parent);

    /**
     * Execute an assignmnent statement.
     * @param node the root node of the compound statement.
     * @return an empty Object.
     */
    Object execute(ICodeNode *node);

    /**
     * Send a message about the assignment operation.
     * @param node the ASSIGN node.
     * @param variable_name the name of the target variable.
     * @param data_value the value of the expression.
     */
    void send_assignment_message(ICodeNode *node, string variable_name,
                                 Object data_value);
};

}}}}  // namespace wci::backend::interpreter::executors

#endif /* ASSIGNMENTEXECUTOR_H_ */
