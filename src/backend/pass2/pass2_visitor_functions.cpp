#include "Pass2Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass2Visitor::visitFunctionParameterList(CmmParser::FunctionParameterListContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitFunctionDefinition(CmmParser::FunctionDefinitionContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        const bool is_main = (context->Identifier()->getText() == "main");

        current_function = context->Identifier()->toString();

        if (!is_main)
        {
            j_emitter.emit_public_method_signature(
                current_function,
                context->args,
                context->return_type
            );
        }
        else
        {
            const std::vector <std::string> parameter_types = { "[Ljava/lang/String;" };

            // Emit the main program header
            j_emitter.emit_new_line();
            j_emitter.emit_public_method_signature(
                "main",
                parameter_types,
                "V"
            );
            j_emitter.emit_new_line();
            j_emitter.emit_comment("Timer Module Instantiation");
            j_emitter.emit_new("RunTimer");
            j_emitter.emit_dup();
            j_emitter.emit_invokenonvirtual("RunTimer/<init>()V");
            j_emitter.emit_putstatic(program_name + "/_runTimer LRunTimer;");
            j_emitter.emit_new_line();
            j_emitter.emit_box_comment("Global Variables");

            // Output all buffered instructions
            for (const auto & instruction : instruction_buffer)
            {
                const backend::string_JasminEmitter_FPTR & emit_fptr = instruction.first;
                const std::string & value = instruction.second;
                emit_fptr(&j_emitter, value);
            }

            j_emitter.emit_line();
        }

        // Visit children
        visit(context->parameterTypeList());
        visit(context->compoundStatement());

        j_emitter.emit_function_end(
            (context->num_local_vars+10) * 2,
            context->stack_size
        );

        current_function = "global";
        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitFunctionCall(CmmParser::FunctionCallContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Visit identifier list first
        visitChildren(context);

        const std::string function_name = context->Identifier()->toString();
        if (PassVisitor::function_definition_map.find(function_name) != PassVisitor::function_definition_map.end())
        {
            j_emitter.emit_invokestatic(program_name + "/" + PassVisitor::function_definition_map[context->Identifier()->toString()]);
        }
        else
        {
            throw MissingFunction(function_name);
        }

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitFunctionReturn(CmmParser::FunctionReturnContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Visit identifier list first
        visitChildren(context);

        const std::string function_name = context->Identifier()->toString();
        if (PassVisitor::function_definition_map.find(function_name) != PassVisitor::function_definition_map.end())
        {
            j_emitter.emit_invokestatic(program_name + "/" + PassVisitor::function_definition_map[context->Identifier()->toString()]);
        }
        else
        {
            throw MissingFunction(function_name);
        }

        return nullptr;
    }

} /// backend
