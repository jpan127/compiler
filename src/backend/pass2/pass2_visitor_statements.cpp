#include "Pass2Visitor.hpp"



namespace backend
{

    void Pass2Visitor::visit_unary_statement(CmmParser::UnaryStatementContext * context,
        const std::string & identifier,
        const std::string & opr,
        const bool is_duplicate)
    {
        // Comment
        j_emitter.emit_comment(context->getText());

        // Get instruction
        const backend::string_JasminEmitter_FUNCT emit_get_callback = create_get_variable_instruction(program_name, identifier, context->type_letter);
        emit_get_callback.first(&j_emitter, emit_get_callback.second);

        if (is_duplicate)
        {
            if (context->type.get_type() == backend::Type::t_double)
            {
                j_emitter.emit_dup2();
            }
            else
            {
                j_emitter.emit_dup();
            }
        }
        else
        {
            // Load 1
            switch (context->type.get_type())
            {
                case backend::Type::t_double : j_emitter.emit_dconst_1(); break;
                case backend::Type::t_float  : j_emitter.emit_fconst_1(); break;
                case backend::Type::t_int    : j_emitter.emit_iconst_1(); break;
                default:
                    THROW_EXCEPTION(InvalidType, "Type : " + context->type.to_string());
            }
        }

        // ADD
        emit_expression_instruction(context->type, opr);

        // Put instruction
        const backend::string_JasminEmitter_FUNCT emit_put_callback = create_put_variable_instruction(
            program_name,
            identifier,
            context->type_letter
        );

        emit_put_callback.first(&j_emitter, emit_put_callback.second);
    }

    antlrcpp::Any Pass2Visitor::visitIfElseStatement(CmmParser::IfElseStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Top level if else statement node
         *  Visits children first to get the different branches emitted
         *  Then emit the final label that all branches will branch to
         */

        visitChildren(context);

        // Only increment scope_counter at the end of the entire statement
        // Add label to branch to for exiting the loop
        j_emitter.emit_label("if_else_end_" + std::to_string(PassVisitor::scope_counter++));

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitIfStatement(CmmParser::IfStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Emit start of if label
         *  Visit children which will emit the instructions internal to the branch
         *  Emit a label for the end of if
         *  @note : If condition is true continues into the branch
         *          If condition is false, branch to next branch
         *          At the end of the inside of the branch, jumps to end of the entire if-else statement
         */

        j_emitter.emit_comment_custom(context->getText(), 0);

        // Emit start label
        j_emitter.emit_label(context->conditionalExpression()->iteration_name);

        // Visit expression child first
        visit(context->conditionalExpression());

        // Visit children inside the if block
        visit(context->statement());

        j_emitter.emit_comment("Exit if-else statement");

        j_emitter.emit_goto("if_else_end_" + std::to_string(PassVisitor::scope_counter));

        // Emit end label
        j_emitter.emit_label(context->conditionalExpression()->iteration_name + "_end");

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitElseIfStatement(CmmParser::ElseIfStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Emit start of else if label
         *  Visit children which will emit the instructions internal to the branch
         *  Emit a label for the end of else if
         *  @note : If condition is true continues into the branch
         *          If condition is false, branch to next branch
         *          At the end of the inside of the branch, jumps to end of the entire if-else statement
         */

        j_emitter.emit_comment_custom(context->getText(), 0);

        // Emit start label
        j_emitter.emit_label(context->conditionalExpression()->iteration_name);

        // Visit expression child first
        visit(context->conditionalExpression());

        // Visit children inside the if block
        visit(context->statement());

        j_emitter.emit_comment("Exit if-else statement");

        j_emitter.emit_goto("if_else_end_" + std::to_string(PassVisitor::scope_counter));

        // Emit end label
        j_emitter.emit_label(context->conditionalExpression()->iteration_name + "_end");

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitElseStatement(CmmParser::ElseStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Emit start of else label
         *  Visit children which will emit the instructions internal to the branch
         *  Emit a label for the end of else
         *  @note : If condition is true continues into the branch
         *          If condition is false, branch to next branch
         *          At the end of the inside of the branch, jumps to end of the entire if-else statement
         */

        j_emitter.emit_comment_custom(context->getText(), 0);

        // Emit start label
        j_emitter.emit_label("else_" + std::to_string(scope_counter));

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitIterationStatement(CmmParser::IterationStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Emit start of loop label
         *  Visit children which will emit the instructions internal to the loop
         *  Emit a jump to start of loop
         *  Emit a label for the end of loop
         */

        j_emitter.emit_comment_custom(context->getText(), 0);

        // Emit the iteration label
        j_emitter.emit_label(context->conditionalExpression()->iteration_name);

        // Emit while loop
        auto value = visitChildren(context);

        j_emitter.emit_comment("Jump to start of loop");

        // Emit a jump to start of loop
        j_emitter.emit_goto(context->conditionalExpression()->iteration_name);

        // Add label to branch to for exiting the loop
        j_emitter.emit_label(context->conditionalExpression()->iteration_name + "_end");

        return value;
    }

    antlrcpp::Any Pass2Visitor::visitAssignmentStatement(CmmParser::AssignmentStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitJumpStatement(CmmParser::JumpStatementContext *context)
    {
        if (current_function == "main")
        {
            emit_symbol_table();

            // Emit the main program epilogue
            j_emitter.emit_new_line();
            j_emitter.emit_comment("Print Elapsed Time");
            j_emitter.emit_getstatic(program_name + "/_runTimer LRunTimer;");
            j_emitter.emit_invokevirtual("RunTimer.printElapsedTime()V");
        }

        if (context->expression())
        {
            visit(context->expression());

            switch (instruction_prefix_map_lookup(context->expression()->type))
            {
                case 'i': j_emitter.emit_ireturn(); break;
                case 'f': j_emitter.emit_freturn(); break;
                case 'd': j_emitter.emit_dreturn(); break;
                default :                           break;
            }
        }
        else
        {
            j_emitter.emit_return();
            j_emitter.emit_new_line();
        }

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitUnaryIncrementStatement(CmmParser::UnaryIncrementStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        visit_unary_statement(
            context,
            context->Identifier()->getText(),
            "+",
            false
        );

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        visit_unary_statement(
            context,
            context->Identifier()->getText(),
            "-",
            false
        );

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        visit_unary_statement(
            context,
            context->Identifier()->getText(),
            "*",
            true
        );

        return visitChildren(context);
    }

} /// backend
