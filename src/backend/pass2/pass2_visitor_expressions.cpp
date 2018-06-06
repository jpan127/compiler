#include "Pass2Visitor.hpp"
#include "TypeResolver.hpp"



namespace backend
{

    void Pass2Visitor::convert_if_necessary(const backend::TypeSpecifier & start, const backend::TypeSpecifier & end)
    {
        // Type mismatches need to be converted
        const utils::TypeConversion conversion = utils::determine_conversion_requirement(start, end);
        switch (conversion)
        {
            case utils::TypeConversion::d2l  : j_emitter.emit_d2l(); break;
            case utils::TypeConversion::d2f  : j_emitter.emit_d2f(); break;
            case utils::TypeConversion::d2i  : j_emitter.emit_d2i(); break;
            case utils::TypeConversion::l2d  : j_emitter.emit_l2d(); break;
            case utils::TypeConversion::l2f  : j_emitter.emit_l2f(); break;
            case utils::TypeConversion::l2i  : j_emitter.emit_l2i(); break;
            case utils::TypeConversion::f2d  : j_emitter.emit_f2d(); break;
            case utils::TypeConversion::f2l  : j_emitter.emit_f2l(); break;
            case utils::TypeConversion::f2i  : j_emitter.emit_f2i(); break;
            case utils::TypeConversion::i2d  : j_emitter.emit_i2d(); break;
            case utils::TypeConversion::i2l  : j_emitter.emit_i2l(); break;
            case utils::TypeConversion::i2f  : j_emitter.emit_i2f(); break;
            case utils::TypeConversion::none :                       break;
            default                          :                       break;
        }
    }

    void Pass2Visitor::visit_expression(CmmParser::ExpressionContext * context,
        const std::vector <CmmParser::ExpressionContext *> & expressions,
        const std::string & expr_operator)
    {
        constexpr uint8_t num_expressions = 2;
        for (uint8_t i = 0; i < num_expressions; i++)
        {
            visit(expressions[i]);

            // Type mismatches need to be converted
            convert_if_necessary(expressions[i]->type, context->type);
        }

        emit_expression_instruction(context->type, expr_operator);
    }

    antlrcpp::Any Pass2Visitor::visitMulDivExpr(CmmParser::MulDivExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        const std::vector <CmmParser::ExpressionContext *> & expressions = context->expression();
        visit_expression(
            context,
            expressions,
            context->expr_operator
        );

        return context->type;
    }

    antlrcpp::Any Pass2Visitor::visitAddminExpr(CmmParser::AddminExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        const std::vector <CmmParser::ExpressionContext *> & expressions = context->expression();
        visit_expression(
            context,
            expressions,
            context->expr_operator
        );

        return context->type;
    }

    antlrcpp::Any Pass2Visitor::visitBitExpr(CmmParser::BitExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        const std::vector <CmmParser::ExpressionContext *> & expressions = context->expression();
        visit_expression(
            context,
            expressions,
            context->expr_operator
        );

        return context->type;
    }

    antlrcpp::Any Pass2Visitor::visitPrimExpr(CmmParser::PrimExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  If variable : emit getstatic
         *  If integer  : emit ldc
         *  If float    : emit ldc
         */

        string_JasminEmitter_FUNCT emit_callback = EMPTY_STRING_CALLBACK;
        string_JasminEmitter_FPTR emit_fptr = nullptr;
        std::string value;

        if (context->primaryExpression()->Identifier())
        {
            emit_callback = create_get_variable_instruction(
                program_name,
                context->primaryExpression()->Identifier()->getText(),
                context->type_letter
            );
        }
        else if (context->primaryExpression()->IntegerConstant() ||
                (context->primaryExpression()->FloatConstant()))
        {
            cout << TAB << context->type << endl;
            // Doubles need to be treated differently
            if (backend::Type::t_double == context->type.get_type())
            {
                // If integer constant add decimal
                if (context->primaryExpression()->IntegerConstant())
                {
                    value += context->primaryExpression()->IntegerConstant()->getText();
                    value += ".0";
                }
                else
                {
                    value += context->primaryExpression()->FloatConstant()->getText();
                }

                emit_fptr = &backend::JasminEmitter::emit_ldc2_w;
            }
            else if (backend::Type::t_float == context->type.get_type())
            {
                // If integer constant add decimal
                if (context->primaryExpression()->IntegerConstant())
                {
                    value += context->primaryExpression()->IntegerConstant()->getText();
                    value += ".0";
                }
                else
                {
                    value += context->primaryExpression()->FloatConstant()->getText();
                }

                emit_fptr = &backend::JasminEmitter::emit_ldc;
            }
            else
            {
                emit_fptr = &backend::JasminEmitter::emit_ldc;
                value = context->primaryExpression()->IntegerConstant()->getText();
            }

            emit_callback = std::make_pair(
                std::move(emit_fptr),
                std::move(value)
            );
        }

        if (context->primaryExpression()->current_nesting_level == 1)
        {
            instruction_buffer.push_back(emit_callback);
        }
        else
        {
            emit_callback.first(&j_emitter, emit_callback.second);
        }

        visitChildren(context);

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Children emit instructions first
         *  Emits branch instruction for exiting the current branch
         */

        const std::string lhs_name = context->expression(0)->getText();
        const std::string rhs_name = context->expression(1)->getText();

        // Emit an explanation comment for condition
        j_emitter.emit_comment(lhs_name + " " + context->opr + " " + rhs_name);

        // Visit both operands
        constexpr uint8_t num_operands = 2;
        for (uint8_t i = 0; i < num_operands; i++)
        {
            visit(context->expression(i));
            // Doubles and floats need to be converted before jump comparison instruction
            if (backend::Type::t_double == context->expression(i)->type.get_type())
            {
                j_emitter.emit_d2i();
            }
            else if (backend::Type::t_float  == context->expression(i)->type.get_type())
            {
                j_emitter.emit_f2i();
            }
        }

        // Emit an explanation comment for exit
        j_emitter.emit_comment("Exit [" + context->iteration_name + "] condition");

        const std::string branch_target = context->iteration_name + "_end";
        // Emit the instruction
             if (context->opr == "<")                              { j_emitter.emit_if_icmpge(branch_target); }  ///< (x <  y) branch if >=
        else if (context->opr == "<=")                             { j_emitter.emit_if_icmpgt(branch_target); }  ///< (x <= y) branch if >
        else if (context->opr == ">")                              { j_emitter.emit_if_icmple(branch_target); }  ///< (x >  y) branch if <=
        else if (context->opr == ">=")                             { j_emitter.emit_if_icmplt(branch_target); }  ///< (x >= y) branch if <
        else if (context->opr == "==" || context->opr == "is")     { j_emitter.emit_if_icmpne(branch_target); }  ///< (x == y) branch if !=
        else if (context->opr == "!=" || context->opr == "is not") { j_emitter.emit_if_icmpeq(branch_target); }  ///< (x != y) branch if ==
        else                                                       { THROW_EXCEPTION(InvalidOperator, context->opr); }

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Top level conditional expression
         *  Responsible for only checking the top 2 values on the stack
         *  For an OR operation, if any of them are nonzero positive, jump
         *  For an AND operation, if both of them are nonzero positive, jump
         *  @note : Nothing needs to be done because for AND conditions both must be met,
         *          and both are checked previously in child nodes
         */

        // Visit children first
        visitChildren(context);

        // Left and right operands should have pushed values to the stack
        if ("or" == context->opr)
        {
            // If left condition is > 0, jump
            j_emitter.emit_ifgt(context->iteration_name);

            // If right condition is > 0, jump
            j_emitter.emit_ifgt(context->iteration_name);
        }

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitAssignmentExpression(CmmParser::AssignmentExpressionContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  RHS expression will take care of emitting its own instructions
         *  This node will just load the value into the assigned variable
         */

        // Add a comment
        if (context->current_nesting_level == 1)
        {
            const backend::string_JasminEmitter_FPTR emit_fptr = &backend::JasminEmitter::emit_comment;
            const std::string value = context->getText();
            const backend::string_JasminEmitter_FUNCT emit_comment_callback = std::make_pair(emit_fptr, value);
            instruction_buffer.push_back(emit_comment_callback);
        }
        else
        {
            j_emitter.emit_comment(context->getText());
        }

        if (context->expression())
        {
            // Visit right hand side expression first
            visit(context->expression());

            // Types might need to be converted
            convert_if_necessary(context->expression()->type, context->type);
        }
        else if (context->functionReturn())
        {
            visit(context->functionReturn());
        }

        const backend::string_JasminEmitter_FUNCT emit_put_callback = create_put_variable_instruction(
            program_name,
            context->Identifier()->toString(),
            context->type_letter
        );

        if (context->current_nesting_level == 1)
        {
            instruction_buffer.push_back(emit_put_callback);
        }
        else
        {
            emit_put_callback.first(&j_emitter, emit_put_callback.second);
        }

        return nullptr;
    }

} /// backend
