#include "Pass1Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass1Visitor::visitFunctionParameterList(CmmParser::FunctionParameterListContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Loop through each parameter
        const std::vector <CmmParser::TypeSpecifierContext *> type_specifiers = context->typeSpecifier();
        for (uint32_t i = 0; i < type_specifiers.size(); ++i)
        {
            // Set the type members
            const std::string type = type_specifiers[i]->getText();
            cout << TAB << type << endl;
            context->type = backend::TypeSpecifier(type);
            context->type_letter = context->type.get_letter();

            const std::string variable_name = context->Identifier(i)->getText();

            // Create and push a new symbol into the local table
            symbol_table_stack.push_symbol_locally(variable_name, context->type);

            if (PassVisitor::variable_id_map.find(PassVisitor::current_function) == PassVisitor::variable_id_map.end())
            {
                THROW_EXCEPTION(MissingSymbol, "Function is not in variable_id_map : " + PassVisitor::current_function);
            }
            else
            {
                PassVisitor::variable_id_map[PassVisitor::current_function].emplace(
                    variable_name,
                    intermediate::Symbol(
                        symbol_table_stack.get_last_symbol_id_locally(),
                        context->type
                    )
                );
            }

            cout << TAB << "Symbol created for : " << variable_name << endl;
        }

        return visitChildren(context);
    }

    /// @TODO : This function needs to be simplified / cleaned up
    antlrcpp::Any Pass1Visitor::visitFunctionDefinition(CmmParser::FunctionDefinitionContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        PassVisitor::current_function = context->Identifier()->toString();
        const std::string function_return_type(1, toupper(context->typeSpecifier()->getText()[0]));
        std::string function_parameters;

        // Checks to see if function has already been defined
        if (PassVisitor::variable_id_map.find(PassVisitor::current_function)         != PassVisitor::variable_id_map.end() &&
            PassVisitor::function_definition_map.find(PassVisitor::current_function) != PassVisitor::function_definition_map.end())
        {
            THROW_EXCEPTION(CompilerError, "Function already defined : " + PassVisitor::current_function);
        }
        // Stores function declaration and registers the function into the map
        else
        {
            PassVisitor::variable_id_map[PassVisitor::current_function] = std::unordered_map<std::string, intermediate::Symbol>();
            PassVisitor::function_definition_map[PassVisitor::current_function] = PassVisitor::current_function + "(";
        }

        // Set the compound statement's scope name as the function name
        context->compoundStatement()->scope_name = context->Identifier()->getText();

        // Create a header for pass2visitor to use when creating the method
        context->function_header = "\n.method public static " + PassVisitor::current_function + "(";

        if (context->parameterTypeList()->functionParameterList())
        {
            // Add each function parameter to jasmin function header
            for (auto variable : context->parameterTypeList()->functionParameterList()->typeSpecifier())
            {
                const std::string var_type = variable->getText();
                function_parameters += toupper(var_type[0]);
            }
        }

        // Close parameter parenthesis and declare function return type
        context->function_header += function_parameters + ")" + function_return_type;
        if (PassVisitor::current_function == "main")
        {
            PassVisitor::function_definition_map[PassVisitor::current_function] += "[Ljava/lang/String;)";
        }
        else
        {
            PassVisitor::function_definition_map[PassVisitor::current_function] += function_parameters + ")" + function_return_type;
        }

        // Add comment of function signature for jasmin file
        context->function_header += "\n; " + context->getText() + "\n";

        // Create new symbol table and push it before visiting children
        intermediate::SymbolTablePtr table_ptr = std::make_shared <intermediate::SymbolTable>
        (
            intermediate::SymbolTableScope::function,
            PassVisitor::current_function,
            symbol_table_stack.get_current_nesting_level()
        );
        symbol_table_stack.push_symbol_table(table_ptr);

        // Allow parameterTypeList to add function parameters to symtab
        visit(context->parameterTypeList());
        visit(context->compoundStatement());

        context->num_local_vars = symbol_table_stack.get_local_symbol_table()->get_size() - 1;
        context->stack_size     = context->num_local_vars * 8;

        // Pop the local table after visiting child nodes
        symbol_table_stack.pop_symbol_table();

        PassVisitor::current_function = "global";

        return nullptr;
    }

} /// backend
