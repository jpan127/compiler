/**
 * <h1>LoopExecutor</h1>
 *
 * <p>Execute a loop statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef LOOPEXECUTOR_H_
#define LOOPEXECUTOR_H_

#include "StatementExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;

class LoopExecutor : public StatementExecutor
{
public:
    /**
     * Constructor.
     * @param the parent executor.
     */
    LoopExecutor(Executor *parent);

    /**
     * Execute a compound statement.
     * @param node the root node of the compound statement.
     * @return nullptr.
     */
    Object execute(ICodeNode *node);
};

}}}}  // namespace wci::backend::interpreter::executors

#endif /* LOOPEXECUTOR_H_ */
