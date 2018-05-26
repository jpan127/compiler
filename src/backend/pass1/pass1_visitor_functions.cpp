#include "Pass1Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass1Visitor::visitFunctionParameterList(CmmParser::FunctionParameterListContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Make a comment as to what the declaration is
        j_file << "\n; " << context->getText() << "\n" << endl;

        const std::vector <CmmParser::TypeSpecifierContext *> type_specifiers = context->typeSpecifier();
        for (uint32_t i = 0; i < type_specifiers.size(); ++i)
        {

            try
            {
                const std::string type = type_specifiers[i]->getText();
                cout << TAB << type << endl;
                context->type = backend::TypeSpecifier(type);
                context->type_letter = context->type.get_letter();
            }
            CATCH_CUSTOM_EXCEPTION_PRINT_AND_EXIT(InvalidType);

            std::string variable_name = context->Identifier(i)->getText();
            std::string variable_initial_value;

            try
            {
                symbol_table_stack.push_symbol_locally(variable_name, context->type);

                if (PassVisitor::variable_id_map.find(PassVisitor::current_function) == PassVisitor::variable_id_map.end())
                {
                    throw MissingSymbol("Function is not in variable_id_map : " + PassVisitor::current_function);
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
            }
            CATCH_CUSTOM_EXCEPTIONS_PRINT_AND_EXIT(InvalidType, MissingSymbol);

            cout << TAB << "Symbol created for : " << variable_name << endl;
        }

        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitFunctionDefinition(CmmParser::FunctionDefinitionContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        std::string function_name = context->Identifier()->toString();
        std::string function_return_type, function_parameters;
        function_return_type = (char) toupper(context->typeSpecifier()->getText()[0]);

        PassVisitor::current_function = function_name;

        try
        {
            if (PassVisitor::variable_id_map.find(PassVisitor::current_function)         != PassVisitor::variable_id_map.end() &&
                PassVisitor::function_definition_map.find(PassVisitor::current_function) != PassVisitor::function_definition_map.end())
            {
                throw CompilerError("Function already defined : " + PassVisitor::current_function);
            }
            else
            {
                PassVisitor::variable_id_map[PassVisitor::current_function] = std::unordered_map<std::string, intermediate::Symbol>();
                PassVisitor::function_definition_map[PassVisitor::current_function] = PassVisitor::current_function + "(";
            }
        }
        CATCH_CUSTOM_EXCEPTION_PRINT_AND_EXIT(CompilerError);

        // Set the compound statement's scope name as the function name
        context->compoundStatement()->scope_name = context->Identifier()->getText();

        //create a header for pass2visitor to use when creating the method
        context->function_header = ".method public static " + function_name + "(";

        if (context->parameterTypeList()->functionParameterList())
        {
            //add each function parameter to jasmin function header
            for (auto variable: context->parameterTypeList()->functionParameterList()->typeSpecifier())
            {
                std::string var_type = variable->getText();
                function_parameters += (char) toupper(var_type[0]);
            }
        }

        //close parameter parenthesis and declare function return type
        context->function_header += function_parameters + ")" + function_return_type;
        if (PassVisitor::current_function!= "main")
        {
            PassVisitor::function_definition_map[PassVisitor::current_function] += function_parameters + ")" + function_return_type;
        }
        else
        {
            PassVisitor::function_definition_map[PassVisitor::current_function] += "[Ljava/lang/String;)";
        }
        //add comment of function signature for jasmin file
        context->function_header += "\n; " + context->getText() + "\n";

        // Create new symbol table
        intermediate::SymbolTablePtr table_ptr = std::make_shared <intermediate::SymbolTable>
        (
            intermediate::SymbolTableScope::function,
            function_name,
            symbol_table_stack.get_current_nesting_level()
        );
        symbol_table_stack.push_symbol_table(table_ptr);

        //allow parameterTypeList to add function parameters to symtab
        visit(context->parameterTypeList());
        visit(context->compoundStatement());

        context->num_local_vars = symbol_table_stack.get_local_symbol_table()->get_size() - 1; /// symtab_stack->get_local_symtab()->get_size() - 1;
        context->stack_size     = context->num_local_vars * 8;

        symbol_table_stack.pop_symbol_table();
        cout << "Popped" << endl;

        PassVisitor::current_function = "global";

        return nullptr;
    }

} /// backend
