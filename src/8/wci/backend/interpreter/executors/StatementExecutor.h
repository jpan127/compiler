/**
 * <h1>StatementExecutor</h1>
 *
 * <p>Execute a statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef STATEMENTEXECUTOR_H_
#define STATEMENTEXECUTOR_H_

#include <string>
#include "../Executor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../message/Message.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::message;

class StatementExecutor : public Executor
{
public:
    /**
     * Constructor.
     * @param the parent executor.
     */
    StatementExecutor(Executor *parent);

    /**
     * Execute a statement.
     * To be overridden by the specialized statement executor subclasses.
     * @param node the root node of the statement.
     * @return an empty Object.
     */
    virtual Object execute(ICodeNode *node);

protected:
    Executor *parent;  // parent executor

private:
    /**
     * Send a message about the current source line.
     * @param node the statement node.
     */
    void send_at_line_message(ICodeNode *node);
};

}}}}  // namespace wci::backend::interpreter::executors

#endif /* STATEMENTEXECUTOR_H_ */
