#include "WhenExecutor.hpp"

#include <vector>
#include <string>

#include "StatementExecutor.h"
#include "ExpressionExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"



namespace wci::backend::interpreter::executors
{

WhenExecutor::WhenExecutor(Executor *parent) : StatementExecutor(parent)
{

}

Object WhenExecutor::execute(ICodeNode *node)
{
    std::vector <ICodeNode *> statements = node->get_children();

    ExpressionExecutor expression_executor(this);
    StatementExecutor  statement_executor(this);

    /**
     *  There will always be an odd number of statements because OTHERWISE is 1 statement
     *  and everything else is a pair of conditional statement and assignment statement
     *
     *  This loop will loop through all statements until OTHERWISE
     *  If the even statement is evaluated to be true, the odd statement is executed
     *  Speaking in terms of starting from the 0th statement
     */

    // Only match one condition, if this flag is set, other conditions are ignored
    bool matched = false;

    for (uint32_t i = 0; i < statements.size()-1; i += 2)
    {
        Object result = expression_executor.execute(statements[i]);
    
        if (true == cast(result, bool))
        {
            statement_executor.execute(statements[i+1]);
            matched = true;
            break;
        }
    }

    // If none of the conditions were matched, execute the OTHERWISE statement
    if (!matched)
    {
        statement_executor.execute(statements[statements.size() - 1]);
    }

    ++execution_count;

    return Object();
}

} /// wci::backend::interpreter::executors