#include "Pass1Visitor.hpp"



namespace backend
{

    void Pass1Visitor::visit_expression(CmmParser::ExpressionContext * context,
        const std::set <std::string> & operator_set,
        const bool is_bit_expr,
        std::string & expr_operator,
        const std::string opr,
        const backend::TypeSpecifier & lhs_type,
        const backend::TypeSpecifier & rhs_type)
    {
        /**
         *  Determines the expression operator
         *  Determines the type of the resulting expression
         *  Stores it for pass 2
         */

        if (operator_set.find(opr) != operator_set.end())
        {
            expr_operator = opr;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperator, "Operator does not match : " + opr);
        }

        visitChildren(context);

        if (is_bit_expr)
        {
            if ((backend::Type::t_float == lhs_type.get_type()) ||
                (backend::Type::t_float == rhs_type.get_type()))
            {
                THROW_EXCEPTION(CompilerError, "Bit operations cannot be performed on floating point types : " + context->getText());
            }
        }

        context->type = resolve_expression_type(lhs_type, rhs_type);

        logger->debug("LHS : {}, RHS : {}", lhs_type.to_string(), rhs_type.to_string());
    }

    antlrcpp::Any Pass1Visitor::visitMulDivExpr(CmmParser::MulDivExprContext *context)
    {
        static const std::set <std::string> operator_set = { "*", "/", "%" };

        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        visit_expression(
            context,
            operator_set,
            false,
            context->expr_operator,
            context->opr->getText(),
            context->expression(0)->type,
            context->expression(1)->type
        );

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitAddminExpr(CmmParser::AddminExprContext *context)
    {
        static const std::set <std::string> operator_set = { "+", "-" };

        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        visit_expression(
            context,
            operator_set,
            false,
            context->expr_operator,
            context->opr->getText(),
            context->expression(0)->type,
            context->expression(1)->type
        );

        return nullptr;
    }

    antlrcpp::Any Pass1Visitor::visitBitExpr(CmmParser::BitExprContext *context)
    {
        static const std::set <std::string> operator_set = { "<<" , ">>" , "&"  , "|"  , "~"  , "^" };

        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        visit_expression(
            context,
            operator_set,
            true,
            context->expr_operator,
            context->opr->getText(),
            context->expression(0)->type,
            context->expression(1)->type
        );

        return nullptr;
    }

    antlrcpp::Any Pass1Visitor::visitPrimExpr(CmmParser::PrimExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Determines the type + type letter of the identifier
         *  Stores it for Pass 2
         */

        // If parent has not set this node's type, set it
        if (context->type.is_null())
        {
            if (context->primaryExpression()->Identifier())
            {
                // Look up type of this expression in the symbol table stack
                lookup_symbol_type(context->primaryExpression()->Identifier()->getText(), context->type, context->type_letter);
            }
            else if (context->primaryExpression()->IntegerConstant())
            {
                context->type_letter = 'I';
                context->type.set_type(backend::Type::t_int);
            }
            else if (context->primaryExpression()->FloatConstant())
            {
                context->type_letter = 'F';
                context->type.set_type(backend::Type::t_float);
            }
        }

        visitChildren(context);

        context->primaryExpression()->current_nesting_level = symbol_table_stack.get_current_nesting_level();

        return context->type;
    }

    antlrcpp::Any Pass1Visitor::visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Saves the operator characters
         *  Saves the opcode
         */

        context->opr = context->ConditionalOperator()->getText();

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Saves the operator characters
         */

        // Left and right operands should have pushed values to the stack
        if ("||" == context->ConditionalConnectOperator()->getText() ||
            "or" == context->ConditionalConnectOperator()->getText())
        {
            context->opr = "or";
        }
        else if ("&&"  == context->ConditionalConnectOperator()->getText() ||
                 "and" == context->ConditionalConnectOperator()->getText())
        {
           context->opr = "and";
        }
        else
        {
            THROW_EXCEPTION(AntlrParsedIncorrectly, "Does not have proper operands");
        }

        // Set operand expressions to be the same iteration name
        context->conditionalExpression(0)->iteration_name = context->iteration_name;
        context->conditionalExpression(1)->iteration_name = context->iteration_name;

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Set operand expression to be the same iteration name
        context->conditionalExpression()->iteration_name = context->iteration_name;

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Set operand expression to be the same iteration name
        context->conditionalExpression()->iteration_name = context->iteration_name;

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitAssignmentExpression(CmmParser::AssignmentExpressionContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Determines the type + type letter of the identifier
         *  Stores it for Pass 2
         */

        const std::string variable = context->Identifier()->getText();

        lookup_symbol_type(variable, context->type, context->type_letter);
        logger->debug("Variable : {}, Type : {}", variable, context->type.to_string());

        context->current_nesting_level = symbol_table_stack.get_current_nesting_level();

        return visitChildren(context);
    }

} /// backend
