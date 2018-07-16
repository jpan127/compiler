#include "Pass1Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass1Visitor::visitCompoundStatement(CmmParser::CompoundStatementContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitIfElseStatement(CmmParser::IfElseStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Enumerate each else if statement
        const std::vector <CmmParser::ElseIfStatementContext *> else_ifs = context->elseIfStatement();
        for (uint32_t i = 0; i < else_ifs.size(); i++)
        {
            else_ifs[i]->id = i;
        }

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitIfStatement(CmmParser::IfStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Sets the iteration name to if_N where N is the current scope number
         */

        context->conditionalExpression()->iteration_name = "if_" + std::to_string(PassVisitor::scope_counter);

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitElseIfStatement(CmmParser::ElseIfStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Sets the iteration name to else_if_N where N is the current scope number
         */

        context->conditionalExpression()->iteration_name = "else_if_"                                 +
                                                           std::to_string(PassVisitor::scope_counter) +
                                                           "_"                                        +
                                                           std::to_string(context->id);

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitElseStatement(CmmParser::ElseStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitIterationStatement(CmmParser::IterationStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Sets the iteration name to while_N where N is the current scope number
         */

        context->conditionalExpression()->iteration_name = "while_" + std::to_string(PassVisitor::scope_counter++);

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitAssignmentStatement(CmmParser::AssignmentStatementContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitUnaryIncrementStatement(CmmParser::UnaryIncrementStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Look up type of this expression in the symbol table stack
        lookup_symbol_type(context->Identifier()->getText(), context->type, context->type_letter);

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Look up type of this expression in the symbol table stack
        lookup_symbol_type(context->Identifier()->getText(), context->type, context->type_letter);

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Look up type of this expression in the symbol table stack
        lookup_symbol_type(context->Identifier()->getText(), context->type, context->type_letter);

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitPrintfStatement(CmmParser::PrintfStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Get all format value substitutions and store it
        const std::vector <CmmParser::ValueContext *> values = context->value();
        for (const auto & v : values)
        {
            context->args.push_back(v->getText());
        }

        // Save the format string
        context->format_string = context->String()->getText();

        logger->debug("{}", context->format_string);

        return visitChildren(context);
    }

} /// backend
