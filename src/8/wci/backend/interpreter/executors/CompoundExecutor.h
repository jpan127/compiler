/**
 * <h1>CompoundExecutor</h1>
 *
 * <p>Execute a compound statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef COMPOUNDEXECUTOR_H_
#define COMPOUNDEXECUTOR_H_

#include "StatementExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;

class CompoundExecutor : public StatementExecutor
{
public:
    /**
     * Constructor.
     * @param the parent executor.
     */
    CompoundExecutor(Executor *parent);

    /**
     * Execute a compound statement.
     * @param node the root node of the compound statement.
     * @return an empty Object.
     */
    Object execute(ICodeNode *node);
};

}}}}  // namespace wci::backend::interpreter::executors

#endif /* COMPOUNDEXECUTOR_H_ */
