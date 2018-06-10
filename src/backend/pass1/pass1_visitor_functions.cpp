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

            cout << TAB << "Symbol created for : " << variable_name << endl;
        }

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitFunctionDefinition(CmmParser::FunctionDefinitionContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  1. Create new symbol table and add to the stack + the store
         *  2. Create a list of all the function's parameters
         *  3. Store the function prototype into the map
         *  4. Visit children
         *  5. Pop symbol table from the stack
         */

        // Create new symbol table and push it before visiting children
        intermediate::SymbolTablePtr table_ptr = std::make_shared <intermediate::SymbolTable> (
            intermediate::SymbolTableScope::function,
            context->Identifier()->getText(),
            symbol_table_stack.get_current_nesting_level()
        );

        symbol_table_stack.push_symbol_table(table_ptr);
        PassVisitor::store.register_symbol_table(table_ptr);

        const std::string & current_function = symbol_table_stack.get_local_symbol_table()->get_table_name();
        const std::string function_return_type(1, toupper(context->typeSpecifier()->getText()[0]));

        // Create parameter list
        std::string function_parameters;
        if (context->parameterTypeList()->functionParameterList())
        {
            // Add each function parameter to jasmin function header
            for (const auto & variable : context->parameterTypeList()->functionParameterList()->typeSpecifier())
            {
                const std::string var_type = variable->getText();
                function_parameters += toupper(var_type[0]);
                context->args.push_back(string(1, toupper(var_type[0])));
            }
        }

        // Checks to see if function has already been defined
        if (PassVisitor::function_definition_map.find(current_function) != PassVisitor::function_definition_map.end())
        {
            THROW_EXCEPTION(CompilerError, "Function already defined : " + current_function);
        }
        // Stores function declaration and registers the function into the map
        else
        {
            const std::string prototype = (current_function == "main") ?
                          (current_function + "([Ljava/lang/String;)") :
                          (current_function + "(" + function_parameters + ")" + function_return_type);
            PassVisitor::function_definition_map[current_function] = prototype;
        }

        // Allow parameterTypeList to add function parameters to symtab
        visit(context->parameterTypeList());
        visit(context->compoundStatement());

        // Set the compound statement's scope name as the function name
        context->compoundStatement()->scope_name = context->Identifier()->getText();

        context->num_local_vars = symbol_table_stack.get_local_symbol_table()->get_size() - 1;
        context->stack_size     = context->num_local_vars * 8;
        context->return_type    = function_return_type;

        // Pop the local table after visiting child nodes
        symbol_table_stack.pop_symbol_table();

        return nullptr;
    }

} /// backend
