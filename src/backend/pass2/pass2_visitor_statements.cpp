#include "Pass2Visitor.hpp"



namespace backend
{

    void Pass2Visitor::visit_unary_statement(CmmParser::UnaryStatementContext * context,
        const std::string & identifier,
        const std::string & opr,
        const bool is_duplicate)
    {
        // Comment
        emit_comment(context, 1);

        // Get instruction
        j_file << TAB << create_get_variable_instruction(program_name, identifier, context->type_letter) << endl;

        if (is_duplicate)
        {
            j_file << TAB
                   << ((context->type.get_type() == backend::Type::t_double) ? ("dup2") : ("dup"))
                   << endl;
        }
        else
        {
            // Load 1
            switch (context->type.get_type())
            {
                case backend::Type::t_double : j_file << TAB << "dconst_1" << endl; break;
                case backend::Type::t_float  : j_file << TAB << "fconst_1" << endl; break;
                case backend::Type::t_int    : j_file << TAB << "iconst_1" << endl; break;
                default:
                    throw InvalidType("[visit_unary_statement] Type : " + context->type.to_string());
            }
        }

        // ADD
        j_file << TAB
               << resolve_expression_instruction(context->type, opr)
               << endl;

        // Put instruction
        j_file << create_put_variable_instruction(program_name, identifier, context->type_letter) << endl;
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
        const std::string end_label = "if_else_end_" + std::to_string(PassVisitor::scope_counter++);

        // Add label to branch to for exiting the loop
        j_file << end_label
               << ":"
               << endl
               << endl;

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

        emit_comment(context, 0);

        // Emit start label
        j_file << context->conditionalExpression()->iteration_name
               << ":"
               << endl;

        // Visit expression child first
        visit(context->conditionalExpression());

        // Visit children inside the if block
        visit(context->statement());

        j_file << TAB
               << "; Exit if-else statement"
               << endl
               << TAB
               << "goto "
               << "if_else_end_" + std::to_string(PassVisitor::scope_counter)
               << endl;

        // Emit end label
        j_file << context->conditionalExpression()->iteration_name
               << "_end"
               << ":"
               << endl
               << endl;

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

        emit_comment(context, 0);

        // Emit start label
        j_file << context->conditionalExpression()->iteration_name
               << ":"
               << endl;

        // Visit expression child first
        visit(context->conditionalExpression());

        // Visit children inside the if block
        visit(context->statement());

        j_file << TAB
               << "; Exit if-else statement"
               << endl
               << TAB
               << "goto "
               << "if_else_end_" + std::to_string(PassVisitor::scope_counter)
               << endl;

        // Emit end label
        j_file << context->conditionalExpression()->iteration_name
               << "_end"
               << ":"
               << endl
               << endl;

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

        emit_comment(context, 0);

        // Emit start label
        j_file << "else_"
               << std::to_string(scope_counter)
               << ":"
               << endl;

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

        emit_comment(context, 0);

        // Emit the iteration label
        j_file << context->conditionalExpression()->iteration_name
               << ":"
               << endl;

        // Emit while loop
        auto value = visitChildren(context);

        // Emit a jump to start of loop
        j_file << TAB
               << "; Jump to start of loop"
               << endl
               << TAB
               << "goto "
               << context->conditionalExpression()->iteration_name
               << endl;

        // Add label to branch to for exiting the loop
        j_file << context->conditionalExpression()->iteration_name
               << "_end"
               << ":"
               << endl
               << endl;

        return value;
    }

    antlrcpp::Any Pass2Visitor::visitAssignmentStatement(CmmParser::AssignmentStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitJumpStatement(CmmParser::JumpStatementContext *context)
    {
        if (PassVisitor::current_function == "main")
        {
            emit_symbol_table();

            // Emit the main program epilogue
            j_file                                                                       << endl;
            j_file << TAB << "; Print Elapsed Time"                                      << endl;
            j_file << TAB << "getstatic     " << program_name << "/_runTimer LRunTimer;" << endl;
            j_file << TAB << "invokevirtual RunTimer.printElapsedTime()V"                << endl;
        }

        if (context->expression())
        {
            visit(context->expression());
        }

        try
        {
            if (context->expression())
            {
                j_file << TAB << instruction_prefix_map_lookup(context->expression()->type) << "return" << endl << endl;
            }
            else
            {
                j_file << TAB << "return" << endl << endl;
            }
        }
        CATCH_CUSTOM_EXCEPTION_PRINT_AND_EXIT(InvalidType);

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
