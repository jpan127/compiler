#include <iostream>
#include <string>
#include <vector>

#include "Pass1Visitor.hpp"
#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;



Pass1Visitor::Pass1Visitor(const string fname, const bool debug) : 
    PassVisitor(1),
    program_name(fname),
    symbol_table_stack(),
    j_file(nullptr), 
    debug_flag(debug)
{
    cout << "Pass1Visitor: symtab stack initialized" << endl;
}

ofstream & Pass1Visitor::get_assembly_file()
{ 
    return j_file; 
}

void Pass1Visitor::lookup_symbol_type(string const & variable, Type & type, char & type_letter)
{
    if (auto symbol = symbol_table_stack.lookup_symbol_globally(variable))
    {
        type = symbol->get_type();
        type_letter = letter_map_lookup(type);
    }
    else
    {
        throw MissingSymbol(variable);
    }
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   C O M P I L A T I O N                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitCompilationUnit(CmmParser::CompilationUnitContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Open output stream file
    try
    {
        j_file.open(program_name + ".j");
        if (j_file.fail())
        {
            throw FileOpenError("Failed to open file :" + program_name + ".j");
        }
    }
    catch (FileOpenError const & error)
    {
        error.print_and_exit();
    }

    // Emit the program header
    j_file << ".class public " << program_name             << endl;
    j_file << ".super java/lang/Object"                    << endl;
    j_file                                                 << endl;
    j_file << ".field private static _runTimer LRunTimer;" << endl;

    auto value = visitChildren(context);

#if 0
    // Print the cross-reference table
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);
#endif

    return value;
}

antlrcpp::Any Pass1Visitor::visitTranslationUnit(CmmParser::TranslationUnitContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *               T Y P E  S P E C I F I E R S                *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitTypeSpecifier(CmmParser::TypeSpecifierContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   D E C L A R A T I O N S                 *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitDeclaration(CmmParser::DeclarationContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    try
    {
        const string type = context->typeSpecifier()->getText();
        if (type_map.find(type) != type_map.end())
        {
            cout << TAB << type << endl;
            context->type = type_map.at(type);
            context->type_letter = toupper(type[0]);
        }
        else
        {
            throw InvalidType("Type not supported : " + context->getText());
        }
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }

    string variable_name;
    string variable_initial_value = "0";

    context->type_letter = toupper(context->typeSpecifier()->getText()[0]);
    
    if (context->assignmentExpression(0))
    {
        variable_name = context->assignmentExpression(0)->Identifier()->getText();
        cout << TAB << "Has assignment\n";
        cout << TAB << variable_name << endl;

        // Save type letter inside assignmentExpression
        // @TODO : See if this is necessary
        context->assignmentExpression(0)->type_letter = context->type_letter;
        context->assignmentExpression(0)->type = context->type;
    
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

    try
    {
        cout << TAB << context->type << " " << context->type_letter << endl;
        
        symbol_table_stack.push_symbol_locally(variable_name, context->type);
        
        // Find function in map
        if (PassVisitor::variable_id_map.find(PassVisitor::current_function) == PassVisitor::variable_id_map.end())
        {
            throw MissingSymbol("Function is not in variable_id_map : " + PassVisitor::current_function);
        }
        else
        {
            PassVisitor::variable_id_map[PassVisitor::current_function].emplace(
                variable_name,
                ::intermediate::Symbol(
                    symbol_table_stack.get_last_symbol_id_locally(), 
                    context->type
                )
            );
        }
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }
    catch (MissingSymbol const & error)
    {
        error.print_and_exit();
    }

    cout << TAB << "Symbol created for : " << variable_name << endl;

    // Depending which scope this is in, emit declaration
    if (symbol_table_stack.get_current_nesting_level() == 1)
    {
        // Make a comment as to what the declaration is
        j_file << "\n; " << context->getText() << endl;

        // Output the variable declaration
        // @example : .field private static c D = 0
        j_file << ".field private static "
               << variable_name
               << " " 
               << context->type_letter
               << endl
               << endl;
    }

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitFunctionDeclaration(CmmParser::FunctionDeclarationContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Make a comment as to what the declaration is
    j_file << "\n; " << context->getText() << "\n" << endl;

    vector <CmmParser::TypeSpecifierContext *> type_specifiers = context->typeSpecifier();
    for (uint32_t i = 0; i < type_specifiers.size(); ++i)
    {

        try 
        {
            const string type = type_specifiers[i]->getText();
            if (type_map.find(type) != type_map.end()) 
            {
                cout << TAB << type << endl;
                context->type = type_map.at(type);
                context->type_letter = toupper(type[0]);
            } 
            else 
            {
                throw InvalidType("Type not supported : " + context->getText());
            }
        }
        catch (InvalidType const &error) 
        {
            error.print_and_exit();
        }

        string variable_name = context->Identifier(i)->getText();
        string variable_initial_value;

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
                    ::intermediate::Symbol(
                        symbol_table_stack.get_last_symbol_id_locally(), 
                        context->type
                    )
                );
            }
        }
        catch (InvalidType const & error)
        {
            error.print_and_exit();
        }
        catch (MissingSymbol const & error)
        {
            error.print_and_exit();
        }

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
            PassVisitor::variable_id_map[PassVisitor::current_function] = unordered_map<string, ::intermediate::Symbol>();
            PassVisitor::function_definition_map[PassVisitor::current_function] = PassVisitor::current_function + "(";
        }
    }
    catch (CompilerError const &error) 
    {
        error.print_and_exit();
    }

    // Set the compound statement's scope name as the function name
    context->compoundStatement()->scope_name = context->Identifier()->getText();

    //create a header for pass2visitor to use when creating the method
    context->function_header = ".method public static " + function_name + "(";

    if (context->parameterTypeList()->functionDeclaration()) 
    {
        //add each function parameter to jasmin function header
        for (auto variable: context->parameterTypeList()->functionDeclaration()->typeSpecifier()) 
        {
            string var_type = variable->getText();
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
    ::intermediate::SymbolTablePtr table_ptr = std::make_shared <::intermediate::SymbolTable>
    (
        ::intermediate::SymbolTableScope::function, 
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

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   E X P R E S S I O N S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitPrimExpr(CmmParser::PrimExprContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    /**
     *  Determines the type + type letter of the identifier
     *  Stores it for Pass 2
     */

    // If parent has not set this node's type, set it
    if (Type::t_null == context->type)
    {
        if (context->primaryExpression()->Identifier())
        {
            // Look up type of this expression in the symbol table stack
            try
            {
                lookup_symbol_type(context->getText(), context->type, context->type_letter);
            }
            catch (MissingSymbol const & error)
            {
                error.print_and_exit();
            }
            catch (InvalidType const & error)
            {
                error.print_and_exit();
            }
        }
        else if (context->primaryExpression()->IntegerConstant())
        {
            context->type_letter = 'I';
            context->type = Type::t_int;
        }
        else if (context->primaryExpression()->FloatConstant())
        {
            context->type_letter = 'F';
            context->type = Type::t_float;
        }        
    }

    visitChildren(context);

    // context->primaryExpression()->current_nesting_level = symtab_stack->get_local_symtab()->get_nesting_level();
    context->primaryExpression()->current_nesting_level = symbol_table_stack.get_current_nesting_level();

    return context->type;
}

antlrcpp::Any Pass1Visitor::visitMulDivExpr(CmmParser::MulDivExprContext *context)
{
    static const set <string> operator_set = 
    {
        "*", "/", "%"
    };

    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    /**
     *  Determines the expression operator
     *  Determines the type of the resulting expression
     *  Stores it for pass 2
     */
    
    try
    {
        if (operator_set.find(context->opr->getText()) != operator_set.end())
        {
            context->expr_operator = context->opr->getText();
        }
        else
        {
            throw InvalidOperator("Operator does not match : " + context->opr->getText());
        }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    // Only instance of actually returning a value from a child node
    Type lhs_type = static_cast <Type> (visit(context->expression(0)));
    Type rhs_type = static_cast <Type> (visit(context->expression(1)));

    context->type = resolve_expression_type(lhs_type, rhs_type);

    cout << TAB
         << to_string(lhs_type)
         << " " 
         << to_string(rhs_type)
         << endl;

    return visitChildren(context);   
}

antlrcpp::Any Pass1Visitor::visitAddminExpr(CmmParser::AddminExprContext *context)
{
    static const set <string> operator_set = 
    {
        "+", "-"
    };

    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    /**
     *  Determines the expression operator
     *  Determines the type of the resulting expression
     *  Stores it for pass 2
     */

    try
    {
        if (operator_set.find(context->opr->getText()) != operator_set.end())
        {
            context->expr_operator = context->opr->getText();
        }
        else
        {
            throw InvalidOperator("Operator does not match : " + context->opr->getText());
        }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    Type lhs_type = static_cast <Type> (visit(context->expression(0)));
    Type rhs_type = static_cast <Type> (visit(context->expression(1)));

    context->type = resolve_expression_type(lhs_type, rhs_type);

    cout << TAB
         << to_string(lhs_type) 
         << " " 
         << to_string(rhs_type) 
         << endl;

    return nullptr;
}

antlrcpp::Any Pass1Visitor::visitBitExpr(CmmParser::BitExprContext *context)
{
    static const set <string> operator_set = 
    {
        "<<" , ">>" , "&"  , "|"  , "~"  , "^" 
    };

    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    /**
     *  Determines the expression operator
     *  Determines the type of the resulting expression
     *  Stores it for pass 2
     */

    try
    {
        if (operator_set.find(context->opr->getText()) != operator_set.end())
        {
            context->expr_operator = context->opr->getText();
        }
        else
        {
            throw InvalidOperator("Operator does not match : " + context->opr->getText());
        }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    try
    {
        Type lhs_type = static_cast <Type> (visit(context->expression(0)));
        Type rhs_type = static_cast <Type> (visit(context->expression(1)));

        if ((Type::t_float == lhs_type) ||
            (Type::t_float == rhs_type))
        {
            throw CompilerError("Bit operations cannot be performed on floating point types : " + context->getText());
        }

        context->type = resolve_expression_type(lhs_type, rhs_type);
        
        cout << TAB
             << to_string(lhs_type) 
             << " " 
             << to_string(rhs_type) 
             << endl;
    }
    catch (CompilerError const & error)
    {
        error.print_and_exit();
    }

    return nullptr;
}

antlrcpp::Any Pass1Visitor::visitAssignmentExpression(CmmParser::AssignmentExpressionContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    /**
     *  Determines the type + type letter of the identifier
     *  Stores it for Pass 2
     */

    const string variable = context->Identifier()->getText();

    try
    {
        cout << variable << context->type << endl;
        lookup_symbol_type(variable, context->type, context->type_letter);
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }
    catch (MissingSymbol const & error)
    {
        error.print_and_exit();
    }

    // context->current_nesting_level = symtab_stack->get_local_symtab()->get_nesting_level();
    context->current_nesting_level = symbol_table_stack.get_current_nesting_level();

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext * context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    /**
     *  Saves the operator characters
     *  Saves the opcode
     */

    const string opr = context->ConditionalOperator()->getText();

    string opcode;

    try
    {
             if (opr == "<")                     { opcode = "if_icmpge"; }  ///< (x <  y) branch if >=
        else if (opr == "<=")                    { opcode = "if_icmpgt"; }  ///< (x <= y) branch if >
        else if (opr == ">")                     { opcode = "if_icmple"; }  ///< (x >  y) branch if <=
        else if (opr == ">=")                    { opcode = "if_icmplt"; }  ///< (x >= y) branch if <
        else if (opr == "==" || opr == "is")     { opcode = "if_icmpne"; }  ///< (x == y) branch if !=
        else if (opr == "!=" || opr == "is not") { opcode = "if_icmpeq"; }  ///< (x != y) branch if ==
        else                                     { throw InvalidOperator(opr); }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    context->opr = opr;
    context->opcode = opcode;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext * context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    /**
     *  Saves the operator characters
     */

    // Left and right operands should have pushed values to the stack
    if ("||" == context->ConditionalConnectOperator()->getText() ||
        "or" == context->ConditionalConnectOperator()->getText())
    {
        context->opr = "or";
    }
    else if ("&&"  == context->ConditionalConnectOperator()->getText() ||
             "and" == context->ConditionalConnectOperator()->getText())
    {
       context->opr = "and";
    }
    else
    {
        throw AntlrParsedIncorrectly("[visitConnectedConditionalExpr] Does not have proper operands");
    }

    // Set operand expressions to be the same iteration name
    context->conditionalExpression(0)->iteration_name = context->iteration_name;
    context->conditionalExpression(1)->iteration_name = context->iteration_name;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Set operand expression to be the same iteration name
    context->conditionalExpression()->iteration_name = context->iteration_name;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Set operand expression to be the same iteration name
    context->conditionalExpression()->iteration_name = context->iteration_name;

    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                     S T A T E M E N T S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitAssignmentStatement(CmmParser::AssignmentStatementContext * context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitCompoundStatement(CmmParser::CompoundStatementContext * context)
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

antlrcpp::Any Pass1Visitor::visitIfElseStatement(CmmParser::IfElseStatementContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Enumerate each else if statement
    vector <CmmParser::ElseIfStatementContext *> else_ifs = context->elseIfStatement();
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

antlrcpp::Any Pass1Visitor::visitUnaryIncrementStatement(CmmParser::UnaryIncrementStatementContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Look up type of this expression in the symbol table stack
    try
    {
        lookup_symbol_type(context->Identifier()->getText(), context->type, context->type_letter);
    }
    catch (MissingSymbol const & error)
    {
        error.print_and_exit();
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Look up type of this expression in the symbol table stack
    try
    {
        lookup_symbol_type(context->Identifier()->getText(), context->type, context->type_letter);
    }
    catch (MissingSymbol const & error)
    {
        error.print_and_exit();
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Look up type of this expression in the symbol table stack
    try
    {
        lookup_symbol_type(context->Identifier()->getText(), context->type, context->type_letter);
    }
    catch (MissingSymbol const & error)
    {
        error.print_and_exit();
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }

    return visitChildren(context);
}
