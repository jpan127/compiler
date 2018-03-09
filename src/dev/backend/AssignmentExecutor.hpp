#pragma once

#include "StatementExecutor.hpp"



class AssignmentExecutor : public StatementExecutor
{
public:

    /**
     *  Constructor
     *  @param error_handler : Pointer to an executor error handler
     */
    AssignmentExecutor(ExecutorErrorHandler * error_handler) { }

    /**
     *  Executes a statement
     *  @param node : Intermediate code tree node to execute from
     */
    void * execute_statement(IntermediateCodeNode * node)
    {
        vector <IntermediateCodeNode *> children = node->get_children();

        if (children.size() != correct_num_children)
        {
            error_handler.print_error(error_executing_assignment);
        }
        else
        {
#if 0
/// IDK what im doing, just an executor example
            // Execute assignment
            ExpressionExecutor executor;
            const uint32_t result = executor.execute(children[1]);

            // Change the symbol table entry to reflect the result
            SymbolTableEntry * new_entry = children[0]->get_attribute(IntermediateCodeKey::id);
            new_entry->set_attribute(SymbolTableKey::data, result);
#endif
        }
    }

private:

    const uint8_t correct_num_children = 2;
}