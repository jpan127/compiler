/**
 * <h1>ExpressionExecutor</h1>
 *
 * <p>Execute an expression.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <set>
#include "ExpressionExecutor.h"
#include "StatementExecutor.h"
#include "../RuntimeError.h"
#include "../../../Object.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../../../message/Message.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::icodeimpl;
using namespace wci::message;

set<ICodeNodeTypeImpl> ExpressionExecutor::ARITH_OPS =
{
    NT_ADD, NT_SUBTRACT, NT_MULTIPLY,
    NT_FLOAT_DIVIDE, NT_INTEGER_DIVIDE, NT_MOD,
};

ExpressionExecutor::ExpressionExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

Object ExpressionExecutor::execute(ICodeNode *node)
{
    ICodeNodeTypeImpl node_type = (ICodeNodeTypeImpl) node->get_type();

    switch (node_type)
    {
        case NT_VARIABLE:
        {
            // Get the variable's symbol table entry.
            SymTabEntry *id = cast(node->get_attribute((ICodeKey) ID),
                                   SymTabEntry*);

            // Return the variable's value.
            return id->get_attribute((SymTabKey) DATA_VALUE);
        }

        case NT_INTEGER_CONSTANT:
        case NT_REAL_CONSTANT:
        case NT_STRING_CONSTANT:
        {
            // Return the data value.
            return node->get_attribute((ICodeKey) VALUE);
        }

        case NT_NEGATE:
        {
            // Get the NEGATE node's expression node child.
            vector<ICodeNode *> children = node->get_children();
            ICodeNode *expression_node = children[0];

            // Execute the expression and return the negative of its value.
            Object result_value = execute(expression_node);
            if (instanceof(result_value, int))
            {
                return -cast(result_value, int);
            }
            else
            {
                return -cast(result_value, float);
            }
        }

        case NT_NOT:
        {
            // Get the NOT node's expression node child.
            vector<ICodeNode *> children = node->get_children();
            ICodeNode *expression_node = children[0];

            // Execute the expression and return the "not" of its value.
            Object result_value = execute(expression_node);
            return !cast(result_value, bool);
        }

        // Must be a binary operator.
        default: return execute_binary_operator(node, node_type);
    }
}

Object ExpressionExecutor::execute_binary_operator(
                      ICodeNode *node, const ICodeNodeTypeImpl node_type)
{
    // Get the two operand children of the operator node.
    vector<ICodeNode *> children = node->get_children();
    ICodeNode *operand_node1 = children[0];
    ICodeNode *operand_node2 = children[1];

    // Operands.
    Object operand1 = execute(operand_node1);
    Object operand2 = execute(operand_node2);

    bool integer_mode = instanceof(operand1, int) &&
                        instanceof(operand2, int);

    // ====================
    // Arithmetic operators
    // ====================

    if (ARITH_OPS.find(node_type) != ARITH_OPS.end())
    {
        if (integer_mode)
        {
            int value1 = cast(operand1, int);
            int value2 = cast(operand2, int);

            // Integer operations.
            switch (node_type)
            {
                case NT_ADD:      return value1 + value2;
                case NT_SUBTRACT: return value1 - value2;
                case NT_MULTIPLY: return value1 * value2;

                case NT_FLOAT_DIVIDE:
                {
                    // Check for division by zero.
                    if (value2 != 0)
                    {
                        return ((float) value1)/((float) value2);
                    }
                    else
                    {
                        error_handler.flag(node, DIVISION_BY_ZERO, this);
                        return 0;
                    }
                }

                case NT_INTEGER_DIVIDE:
                {
                    // Check for division by zero.
                    if (value2 != 0)
                    {
                        return value1/value2;
                    }
                    else
                    {
                        error_handler.flag(node, DIVISION_BY_ZERO, this);
                        return 0;
                    }
                }

                case NT_MOD:
                {
                    // Check for division by zero.
                    if (value2 != 0)
                    {
                        return value1%value2;
                    }
                    else
                    {
                        error_handler.flag(node, DIVISION_BY_ZERO, this);
                        return 0;
                    }
                }

                default: return Object();  // empty -- shouldn't get here
            }
        }
        else
        {
            float value1 = instanceof(operand1, int) ? cast(operand1, int)
                                                     : cast(operand1, float);
            float value2 = instanceof(operand2, int) ? cast(operand2, int)
                                                     : cast(operand2, float);

            // Float operations.
            switch (node_type)
            {
                case NT_ADD:      return value1 + value2;
                case NT_SUBTRACT: return value1 - value2;
                case NT_MULTIPLY: return value1 * value2;

                case NT_FLOAT_DIVIDE:
                {
                    // Check for division by zero.
                    if (value2 != 0.0f)
                    {
                        return value1/value2;
                    }
                    else {
                        error_handler.flag(node, DIVISION_BY_ZERO, this);
                        return 0.0f;
                    }
                }

                default: return Object();  // empty -- shouldn't get here
            }
        }
    }

    // ==========
    // AND and OR
    // ==========

    else if ((node_type == NT_AND) || (node_type == NT_OR))
    {
        bool value1 = cast(operand1, bool);
        bool value2 = cast(operand2, bool);

        switch (node_type)
        {
            case NT_AND: return value1 && value2;
            case NT_OR:  return value1 || value2;

            default: return Object();  // empty -- shouldn't get here
        }
    }

    // ====================
    // Relational operators
    // ====================

    else if (integer_mode)
    {
        int value1 = cast(operand1, int);
        int value2 = cast(operand2, int);

        // Integer operands.
        switch (node_type)
        {
            case NT_EQ: return value1 == value2;
            case NT_NE: return value1 != value2;
            case NT_LT: return value1 <  value2;
            case NT_LE: return value1 <= value2;
            case NT_GT: return value1 >  value2;
            case NT_GE: return value1 >= value2;

            default: return Object();  // empty -- shouldn't get here
        }
    }
    else
    {
        float value1 = instanceof(operand1, int) ? cast(operand1, int)
                                                 : cast(operand1, float);
        float value2 = instanceof(operand2, int) ? cast(operand2, int)
                                                 : cast(operand2, float);

        // Float operands.
        switch (node_type)
        {
            case NT_EQ: return value1 == value2;
            case NT_NE: return value1 != value2;
            case NT_LT: return value1 <  value2;
            case NT_LE: return value1 <= value2;
            case NT_GT: return value1 >  value2;
            case NT_GE: return value1 >= value2;

            default: return Object();  // empty -- shouldn't get here
        }
    }
}

}}}}  // namespace wci::backend::interpreter::executors
