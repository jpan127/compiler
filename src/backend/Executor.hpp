#pragma once

#include "ExecutorErrorHandler.hpp"



/**
 *  Create one executor that will build up the symbol table, manage the symbol table stack,
 *  organize the intermediate code, and execute statements
 *  This class is to be inherited into different executors:
 *      - StatementExecutor
 *      - ExpressionExecutor
 */

class Executor
{
public:

    /**
     *  Constructor
     *  @param icode : Intermediate code object passed from parser
     *  @param stack : Symbol table stack passed from parser
     */
    Executor(IntermediateCode * icode, SymbolTableStack * stack, ExecutorErrorHandler * error_handler);

    /// Returns a pointer to the symbol table stack object
    SymbolTableStack * get_symbol_table_stack() const;

    /// Returns a pointer to the intermediate code object
    IntermediateCode * get_intermediate_code() const;

    /// Processes the intermediate code by executing the tree from the root
    void process_icode(void);

private:

    /// Handles execution errors
    ExecutorErrorHandler * error_handler;

    /// Keeps track of how many instructions were executed
    uint32_t execution_count;

};
