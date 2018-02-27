/**
 * <h1>SelectExecutor</h1>
 *
 * <p>Execute a SELECT statement. Optimized.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef SELECTEXECUTOR_H_
#define SELECTEXECUTOR_H_

#include <map>
#include "StatementExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;

typedef map<int, ICodeNode *> JumpTable;
typedef map<ICodeNode *, JumpTable *> JumpCache;

class SelectExecutor : public StatementExecutor
{
public:
    /**
     * Constructor.
     * @param the parent executor.
     */
    SelectExecutor(Executor *parent);

    /**
     * Execute a compound statement.
     * @param node the root node of the compound statement.
     * @return nullptr.
     */
    Object execute(ICodeNode *node);

private:
    static JumpCache jump_cache;

    /**
     * Create a jump table for a SELECT node.
     * @param node the SELECT node.
     * @return the jump table.
     */
    JumpTable *create_jump_table(ICodeNode *node);
};

}}}}  // namespace wci::backend::interpreter::executors

#endif /* SELECTEXECUTOR_H_ */
