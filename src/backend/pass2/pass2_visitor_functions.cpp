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
        current_function = context->Identifier()->toString();

        bool is_main = context->Identifier()->getText() == "main";

        if (!is_main)
        {
            j_file << context->function_header << endl;
        }
        else
        {
            // Emit the main program header
            j_file                                                                          << endl;
            j_file << ".method public static main([Ljava/lang/String;)V"                    << endl;
            j_file                                                                          << endl;
            j_file << "\t; Timer Module Instantiation"                                      << endl;
            j_file << "\tnew RunTimer"                                                      << endl;
            j_file << "\tdup"                                                               << endl;
            j_file << "\tinvokenonvirtual RunTimer/<init>()V"                               << endl;
            j_file << "\tputstatic        " << program_name << "/_runTimer LRunTimer;"      << endl;
            j_file                                                                          << endl;

            // Output all buffered instructions
            for (auto instruction : instruction_buffer)
            {
                j_file << instruction << endl;
            }
        }

        visit(context->parameterTypeList());
        visit(context->compoundStatement());

        j_file << ".limit locals " << (context->num_local_vars+10) * 2                  << endl;
        j_file << ".limit stack " << context->stack_size                                << endl;
        j_file << ".end method" << endl;

        current_function = "global";
        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitFunctionCall(CmmParser::FunctionCallContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        if (context->identifierList())
        {
            visit(context->identifierList());
        }

        j_file << TAB << "invokestatic " << program_name << "/";
        j_file << PassVisitor::function_definition_map[context->Identifier()->toString()] << endl;

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitFunctionReturn(CmmParser::FunctionReturnContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        if (context->identifierList())
        {
            visit(context->identifierList());
        }

        j_file << TAB << "invokestatic " << program_name << "/";
        j_file << PassVisitor::function_definition_map[context->Identifier()->toString()] << endl;

        return nullptr;
    }

} /// backend
