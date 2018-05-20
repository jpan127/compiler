#include <iostream>
#include <string>
#include <vector>

#include "Pass1Visitor.hpp"
#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"
#include "wci/util/CrossReferencer.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::util;



Pass1Visitor::~Pass1Visitor() = default;

Pass1Visitor::Pass1Visitor(const string fname, const bool debug) : 
    PassVisitor(1),
    program_name(fname),
    symtab_stack(nullptr),
    program_id(nullptr), 
    j_file(nullptr), 
    debug_flag(debug)
{
    // Create and initialize the symbol table stack.
    symtab_stack = SymTabFactory::create_symtab_stack();
    Predefined::initialize(symtab_stack);

    program_id = symtab_stack->enter_local(program_name);
    program_id->set_definition((Definition) DF_PROGRAM);
    program_id->set_attribute((SymTabKey) ROUTINE_SYMTAB, new EntryValue(symtab_stack->push()));
    symtab_stack->set_program_id(program_id);

    cout << "Pass1Visitor: symtab stack initialized" << endl;
}

ofstream & Pass1Visitor::get_assembly_file()
{ 
    return j_file; 
}

void Pass1Visitor::lookup_symbol_type(string const & variable, TypeSpec ** type, char & type_letter)
{
    try
    {
        const SymTabEntry * entry = symtab_stack->lookup(variable);

        if (!entry)
        {
            throw MissingSymbol(variable);
        }

        *type = entry->get_typespec();

        if (nullptr == *type)
        {
            cerr << "Missing type : " << variable << endl;
            exit(-1);
        }

        type_letter = letter_map_lookup(*type);
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
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

    // Print the cross-reference table
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);
    
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
        if (type_map.find(context->typeSpecifier()->getText()) != type_map.end())
        {
            cout << TAB << context->typeSpecifier()->getText() << endl;
            context->type = *(type_map.at(context->typeSpecifier()->getText()));
            context->type_letter = (char)toupper(context->typeSpecifier()->getText()[0]);
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
        cout << TAB << "Has assignment\n";
        variable_name = context->assignmentExpression(0)->Identifier()->getText();

        // Save type letter inside assignmentExpression
        context->assignmentExpression(0)->type_letter = context->type_letter;
    
        if (context->assignmentExpression(0)->expression() &&
            PassVisitor::is_digit(context->assignmentExpression(0)->expression()->getText()))
        {
            variable_initial_value = context->assignmentExpression(0)->expression()->getText();
        }
    }
    else
    {
        cout << TAB << "No assignment\n";
        variable_name = context->Identifier(0)->getText();
    }

    // Create a symbol table for a new declaration
    SymTabEntry * variable_id = symtab_stack->enter_local(variable_name);
    variable_id->set_definition((Definition) DF_VARIABLE);
    variable_id->set_typespec(context->type);

    if (Predefined::double_type == context->type)
    {
        // Create a symbol table for a dummy for the second symbol asdfakfds;ksad;fasdf
        SymTabEntry *variable_id = symtab_stack->enter_local(variable_name + "_dummy");
        variable_id->set_definition((Definition) DF_VARIABLE);
        variable_id->set_typespec(context->type);
    }

    try
    {
        // Find function in map
        if (PassVisitor::variable_id_map.find(PassVisitor::current_function) == PassVisitor::variable_id_map.end())
        {
            throw MissingSymbol("Function is not in variable_id_map : " + PassVisitor::current_function);
        }
        else
        {
            PassVisitor::variable_id_map[PassVisitor::current_function].emplace(
                variable_name,
                ::intermediate::Symbol(variable_id->id, context->type_letter, context->type)
            );
        }
    }
    catch (MissingSymbol const & error)
    {
        error.print_and_exit();
    }

    cout << TAB << "Symbol table created for : " << variable_name << endl;

    // Determine if current symbol table is global
    SymTab * const local_symbol_table = symtab_stack->get_local_symtab();
    // Depending which scope this is in, emit declaration
    if (local_symbol_table->get_nesting_level() == 1)
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
            if (type_map.find(type_specifiers[i]->getText()) != type_map.end()) 
            {
                cout << TAB << type_specifiers[i]->getText() << endl;
                context->type = *(type_map.at(type_specifiers[i]->getText()));
                context->type_letter = (char) toupper(type_specifiers[i]->getText()[0]);
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

        string variable_name;
        string variable_initial_value;

        variable_name = context->Identifier(i)->getText();

        // Create a symbol table for a new declaration
        SymTabEntry *variable_id = symtab_stack->enter_local(variable_name);
        variable_id->set_definition((Definition) DF_VARIABLE);
        variable_id->set_typespec(context->type);

        if (Predefined::double_type == context->type)
        {
            // Create a symbol table for a dummy for the second symbol asdfakfds;ksad;fasdf
            SymTabEntry *variable_id = symtab_stack->enter_local(variable_name + "_dummy");
            variable_id->set_definition((Definition) DF_VARIABLE);
            variable_id->set_typespec(context->type);
        }

        try
        {
            if (PassVisitor::variable_id_map.find(PassVisitor::current_function) == PassVisitor::variable_id_map.end())
            {
                throw MissingSymbol("Function is not in variable_id_map : " + PassVisitor::current_function);
            }
            else
            {
                PassVisitor::variable_id_map[PassVisitor::current_function].emplace(
                    variable_name,
                    ::intermediate::Symbol(variable_id->id, context->type_letter, context->type)
                );
            }
        }
        catch (MissingSymbol const & error)
        {
            error.print_and_exit();
        }

        cout << TAB << "Symbol table created for : " << variable_name << endl;
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

    //create a local symbal table for the function
    symtab_stack->push();

    //allow parameterTypeList to add function parameters to symtab
    visit(context->parameterTypeList());

    std::cout << TAB << "Size of local symtab" << symtab_stack->get_local_symtab()->sorted_entries().size() << std::endl;
    for (auto variable:symtab_stack->get_local_symtab()->sorted_entries()) 
    {
        std::cout << TAB << variable->get_name() << endl;
    }

    visit(context->compoundStatement());

    context->num_local_vars = symtab_stack->get_local_symtab()->get_size() - 1;
    context->stack_size = context->num_local_vars * 8;

    symtab_stack->pop();

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

    context->expression_type = expr_primary;

    // If parent has not set this node's type, set it
    if (nullptr == context->type)
    {
        if (context->primaryExpression()->Identifier())
        {
            // Look up type of this expression in the symbol table stack
            try
            {
                const string variable = context->getText();

                const SymTabEntry * entry = symtab_stack->lookup(variable);

                if (!entry)
                {
                    throw MissingSymbol(variable);
                }

                TypeSpec * type = entry->get_typespec();

                if (type)
                {
                    context->type_letter = letter_map_lookup(type);
                    context->type = type;
                }
                else
                {
                    throw MissingSymbol("Symbol missing type : " + variable);
                }
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
            context->type = Predefined::int_type;
        }
        else if (context->primaryExpression()->FloatConstant())
        {
            context->type_letter = 'F';
            context->type = Predefined::float_type;
        }        
    }

    visitChildren(context);

    context->primaryExpression()->current_nesting_level = symtab_stack->get_local_symtab()->get_nesting_level();

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
    
    context->expression_type = expr_mul_div;

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

    TypeSpec * lhs_type = static_cast <TypeSpec *> (visit(context->expression(0)));
    TypeSpec * rhs_type = static_cast <TypeSpec *> (visit(context->expression(1)));

    context->type = resolve_expression_type(lhs_type, rhs_type);

    cout << TAB
         << lhs_type 
         << " " 
         << rhs_type 
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

    context->expression_type = expr_add_min;

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

    TypeSpec * lhs_type = static_cast <TypeSpec *> (visit(context->expression(0)));
    TypeSpec * rhs_type = static_cast <TypeSpec *> (visit(context->expression(1)));

    context->type = resolve_expression_type(lhs_type, rhs_type);

    cout << TAB
         << lhs_type 
         << " " 
         << rhs_type 
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

    context->expression_type = expr_add_min;

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
        TypeSpec * lhs_type = static_cast <TypeSpec *> (visit(context->expression(0)));
        TypeSpec * rhs_type = static_cast <TypeSpec *> (visit(context->expression(1)));

        if ((Predefined::float_type == lhs_type) ||
            (Predefined::float_type == rhs_type))
        {
            throw CompilerError("Bit operations cannot be performed on floating point types : " + context->getText());
        }

        context->type = resolve_expression_type(lhs_type, rhs_type);
        
        cout << TAB
             << lhs_type 
             << " " 
             << rhs_type 
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
        SymTabEntry * entry = symtab_stack->lookup(variable);

        if (!entry)
        {
            throw MissingSymbol("Missing symbol table : " + variable);
        }

        TypeSpec * type = entry->get_typespec();
    
        if (type)
        {
            context->type_letter = letter_map_lookup(type);
            context->type = type;

            if (context->expression())
            {
                context->expression()->type = context->type;
                context->expression()->type_letter = context->type_letter;
            }
        }
        else
        {
            throw MissingSymbol("Symbol missing type : " + variable);
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

    context->current_nesting_level = symtab_stack->get_local_symtab()->get_nesting_level();

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
    lookup_symbol_type(context->Identifier()->getText(), &context->type, context->type_letter);

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Look up type of this expression in the symbol table stack
    lookup_symbol_type(context->Identifier()->getText(), &context->type, context->type_letter);

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context)
{
    PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

    // Look up type of this expression in the symbol table stack
    lookup_symbol_type(context->Identifier()->getText(), &context->type, context->type_letter);

    return visitChildren(context);
}
