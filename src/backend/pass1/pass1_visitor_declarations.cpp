#include "Pass1Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass1Visitor::visitDeclaration(CmmParser::DeclarationContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        const std::string type = context->typeSpecifier()->getText();
        logger->debug("Type : {}", type);
        context->type = backend::TypeSpecifier(type);
        context->type_letter = context->type.get_letter();

        std::string variable_name;
        std::string variable_initial_value = "0";

        if (context->assignmentExpression(0))
        {
            variable_name = context->assignmentExpression(0)->Identifier()->getText();
            logger->debug("Has assignment : {}", variable_name);

            if (context->assignmentExpression(0)->expression() &&
                PassVisitor::is_digit(context->assignmentExpression(0)->expression()->getText()))
            {
                variable_initial_value = context->assignmentExpression(0)->expression()->getText();
                context->assignmentExpression(0)->expression()->type_letter = context->type_letter;
                context->assignmentExpression(0)->expression()->type = context->type;
            }
        }
        else
        {
            variable_name = context->Identifier(0)->getText();
        }

        logger->debug("Type : {}, Letter : {}", context->type.to_string(), context->type_letter);

        symbol_table_stack.push_symbol_locally(variable_name, context->type);

        logger->debug("Symbol created for : {}", variable_name);

        // Depending which scope this is in, emit declaration
        if (symbol_table_stack.get_current_nesting_level() == 1)
        {
            j_emitter.emit_comment_custom(context->getText(), 0);
            j_emitter.emit_class_variable(variable_name, string(1, context->type_letter));
        }

        return visitChildren(context);
    }

} /// backend
