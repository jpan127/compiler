/**
 * <h1>ExpressionExecutor</h1>
 *
 * <p>Execute an expression.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef EXPRESSIONEXECUTOR_H_
#define EXPRESSIONEXECUTOR_H_

#include <set>
#include "StatementExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

class ExpressionExecutor : public StatementExecutor
{
public:
    /**
     * Constructor.
     * @param the parent executor.
     */
    ExpressionExecutor(Executor *parent);

    /**
     * Execute an expression.
     * @param node the root intermediate code node of the compound statement.
     * @return the computed value of the expression.
     */
    Object execute(ICodeNode *node);

private:
    static set<ICodeNodeTypeImpl> ARITH_OPS;

    /**
     * Execute a binary operator.
     * @param node the root node of the expression.
     * @param node_type the node type.
     * @return the computed value of the expression.
     */
    Object execute_binary_operator(ICodeNode *node,
                                       const ICodeNodeTypeImpl node_type);
};

}}}}  // namespace wci::backend::interpreter::executors

#endif /* EXPRESSIONEXECUTOR_H_ */
