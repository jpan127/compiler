#pragma once

#include "StatementExecutor.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"



namespace wci::backend::interpreter::executors
{

class WhenExecutor : public StatementExecutor
{
public:

    WhenExecutor(Executor *parent);

    Object execute(ICodeNode *node);

};

} /// wci::backend::interpreter::executors