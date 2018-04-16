#pragma once



class StatementExecutor /// : public Executor
{
public: /// @TODO : protected?

    /**
     *  Constructor
     *  @param error_handler : Pointer to an executor error handler
     */
    StatementExecutor(ExecutorErrorHandler * error_handler) { } /// : Executor() { }

    /**
     *  Executes a statement
     *  @param node : Intermediate code tree node to execute from
     *  @note       : Function to be overridden by derived classes
     */
    virtual void * execute_statement(IntermediateCodeNode * node);

};
