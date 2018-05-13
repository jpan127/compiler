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



Pass1Visitor::~Pass1Visitor() 
{
    /// Empty
}

Pass1Visitor::Pass1Visitor(const string fname, const bool debug) : PassVisitor(), program_name(fname), program_id(nullptr), j_file(nullptr), debug_flag(debug)
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

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   C O M P I L A T I O N                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context)
{
    print_debug_context(1, context, "visitCompilationUnit");

    // Open output stream file
    try
    {
        j_file.open(program_name + ".j");
        if (j_file.fail())
        {
            throw FileOpenError("Failed to open file");
        }
    }
    catch (FileOpenError const & error)
    {
        error.print_and_exit();
    }

    // Emit the program header
    j_file << ".class public " << program_name                      << endl;
    j_file << ".super java/lang/Object"                             << endl;

    // Emit the RunTimer and PascalTextIn fields
    j_file                                                          << endl;
    j_file << ".field private static _runTimer LRunTimer;"          << endl;
    j_file << ".field private static _standardIn LPascalTextIn;"    << endl;

    // Emit the class constructor.
    j_file                                                          << endl;
    j_file << ".method public <init>()V"                            << endl;
    j_file                                                          << endl;
    j_file << "\taload_0"                                           << endl;
    j_file << "\tinvokenonvirtual    java/lang/Object/<init>()V"    << endl;
    j_file << "\treturn"                                            << endl;
    j_file                                                          << endl;
    j_file << ".limit locals 1"                                     << endl;
    j_file << ".limit stack 1"                                      << endl;
    j_file << ".end method"                                         << endl;
    j_file                                                          << endl;

    auto value = visitChildren(context);

    // Print the cross-reference table
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);
    
    return value;
}

antlrcpp::Any Pass1Visitor::visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context)
{
    print_debug_context(1, context, "visitTranslationUnit");
    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *               T Y P E  S P E C I F I E R S                *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context)
{
    print_debug_context(1, context, "visitTypeSpecifier");
    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   D E C L A R A T I O N S                 *
 *                     S T A T E M E N T S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitDeclaration(Pcl2Parser::DeclarationContext *context)
{
    print_debug_context(1, context, "visitDeclaration"); 

    // Make a comment as to what the declaration is
    j_file << "\n; " << context->getText() << "\n" << endl;

    try
    { 
        if (type_map.find(context->typeSpecifier()->getText()) != type_map.end())
        {
            cout << TAB << context->typeSpecifier()->getText() << endl;
            context->type = *(type_map.at(context->typeSpecifier()->getText()));
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
    string variable_initial_value;

    context->type_letter = toupper(context->typeSpecifier()->getText()[0]);
    
    if (context->assignmentExpression(0))
    {
        cout << TAB << "Has assignment\n";
        variable_name = context->assignmentExpression(0)->Identifier()->getText();

        // Save type letter inside assignmentExpression
        context->assignmentExpression(0)->type_letter = context->type_letter;
    
        if (context->assignmentExpression(0)->expression())
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
    cout << TAB << "Symbol table created for : " << variable_name << endl;

    // Output the variable declaration leaving room for the initial value if there is one
    // @example : .field private static c D = 0
    j_file << ".field private static "
           << variable_name
           << " " 
           << context->type_letter;

    if ("" != variable_initial_value)
    {
        j_file  << " = "
                << variable_initial_value;
    }

    j_file << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitCompoundStatement(Pcl2Parser::CompoundStatementContext * context)
{
    print_debug_context(1, context, "visitCompoundStatement");

    SymTab * function_symtab = symtab_stack->push();
    SymTabEntry * function_name_entry = function_symtab->enter(context->scope_name);
    function_name_entry->set_definition((Definition) DF_FUNCTION);
    cout << TAB << "Symbol table created for : " << context->scope_name << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * context)
{
    print_debug_context(1, context, "visitFunctionDefinition");

    // Set the compound statement's scope name as the function name
    context->compoundStatement()->scope_name = context->Identifier()->getText();

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitIterationStatement(Pcl2Parser::IterationStatementContext *context)
{
    print_debug_context(1, context, "visitIterationStatement");

    /**
     *  Sets the iteration name to while_N where N is the current scope number
     */

    context->conditionalExpression()->iteration_name = "while_" + std::to_string(scope_counter++);

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitSelectionStatement(Pcl2Parser::SelectionStatementContext *context)
{
    print_debug_context(1, context, "visitSelectionStatement");

    /**
     *  Sets the iteration name to if_N where N is the current scope number
     */

    context->conditionalExpression()->iteration_name = "if_" + std::to_string(scope_counter++);

    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   E X P R E S S I O N S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitPrimExpr(Pcl2Parser::PrimExprContext *context)
{
    print_debug_context(1, context, "visitPrimExpr");

    context->expression_type = expr_primary;

    if (context->primaryExpression()->Identifier())
    {
        // Look up type of this expression in the symbol table stack
        try
        {
            auto id = symtab_stack->lookup(context->getText());

            if (!id)
            {
                throw "[visitPrimExpr] Could not find symbol : " + context->getText();
            }

            TypeSpec * type = id->get_typespec();

            bool found = false;
            for (auto x : letter_map)
            {
                if (*x.first == type)
                {
                    context->type_letter = x.second;
                    context->type = type;
                    context->primaryExpression()->type_letter = x.second;
                    cout << TAB << type                 << endl;
                    cout << TAB << *x.first             << endl;
                    cout << TAB << context->type_letter << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                const string error = string("[visitPrimExpr] Could not find type : ") + type->to_string();
                throw InvalidType("[visitPrimExpr] Could not find type : " + type->to_string());
            }
        }
        catch (InvalidType const & error)
        {
            error.print_and_exit();
        }
    }
    else if (context->primaryExpression()->IntegerConstant())
    {
        context->type_letter = 'I';
        context->type = Predefined::integer_type;
    }
    else if (context->primaryExpression()->FloatConstant())
    {
        context->type_letter = 'F';
        context->type = Predefined::float_type;
    }

    return visitChildren(context);   
}

antlrcpp::Any Pass1Visitor::visitMulDivExpr(Pcl2Parser::MulDivExprContext *context)
{
    print_debug_context(1, context, "visitMulDivExpr");
    
    context->expression_type = expr_mul_div;

    try
    {
        if (nullptr != context->opr)
        {
            switch (context->opr->getText()[0])
            {
                case '*': /// No break
                case '/': /// No break
                case '%':
                    context->expr_operator = context->opr->getText()[0];
                    break;
                default:
                    throw InvalidOperator("MulDivExpr received impossible operator : " + context->opr->getText()[0]);
                    break;
            }
        }
        else
        {
            throw InvalidOperator("MulDivExpr missing operator");
        }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    const string lhs_name = context->expression(0)->getText();
    const string rhs_name = context->expression(1)->getText();

    try
    {
        auto lhs_id = symtab_stack->lookup(lhs_name);
        auto rhs_id = symtab_stack->lookup(rhs_name);

        if (!lhs_id)
        {
            throw MissingSymbol("[visitMulDivExpr] Could not find symbol : " + lhs_name);
        }

        if (!rhs_id)
        {
            throw MissingSymbol("[visitMulDivExpr] Could not find symbol : " + rhs_name);
        }

        context->type = resolve_expression_type(lhs_id->get_typespec(), rhs_id->get_typespec());
    }
    catch (MissingSymbol const & error)
    {
        error.print_and_exit();
    }

    cout << TAB << lhs_name << context->opr->getText() << rhs_name << endl;

    return visitChildren(context);   
}

antlrcpp::Any Pass1Visitor::visitAddminExpr(Pcl2Parser::AddminExprContext *context)
{
    print_debug_context(1, context, "visitAddminExpr");

    context->expression_type = expr_add_min;

    try
    {
        if (nullptr != context->opr)
        {
            switch (context->opr->getText()[0])
            {
                case '+': /// No break
                case '-':
                    context->expr_operator = context->opr->getText()[0];
                    break;
                default:
                    throw InvalidOperator("[visitAddminExpr] received impossible operator : " + context->opr->getText()[0]);
                    break;
            }
        }
        else
        {
            throw InvalidOperator("[visitAddminExpr] missing operator");
        }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    const string lhs_name = context->expression(0)->getText();
    const string rhs_name = context->expression(1)->getText();

    try
    {
        auto lhs_id = symtab_stack->lookup(lhs_name);
        auto rhs_id = symtab_stack->lookup(rhs_name);

        if (!lhs_id)
        {
            throw MissingSymbol("[visitAddminExpr] Could not find symbol : " + lhs_name);
        }

        if (!rhs_id)
        {
            throw MissingSymbol("[visitAddminExpr] Could not find symbol : " + rhs_name);
        }

        context->type = resolve_expression_type(lhs_id->get_typespec(), rhs_id->get_typespec());
    }
    catch (MissingSymbol const & error)
    {
        error.print_and_exit();
    }

    cout << TAB << lhs_name << context->opr->getText() << rhs_name << endl;

    return visitChildren(context);   
}

antlrcpp::Any Pass1Visitor::visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *context)
{
    print_debug_context(1, context, "visitAssignmentExpression");

    const string variable = context->Identifier()->getText();
    TypeSpec * type = symtab_stack->lookup(variable)->get_typespec();

    try
    {
        if (type)
        {
            context->type = type;

            bool found = false;
            for (auto x : letter_map)
            {
                if (*x.first == type)
                {
                    context->type_letter = x.second;
                    context->type = type;
                    cout << TAB << type                   << endl;
                    cout << TAB << *x.first               << endl;
                    cout << TAB << context->type_letter   << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                throw InvalidType(type->to_string());
            }
        }
        else
        {
            throw MissingSymbol("Missing symbol table : " + variable);
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

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext * context)
{
    print_debug_context(1, context, "visitBasicConditionalExpr");

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
        else if (opr == "==" || opr == "is")     { opcode = "if_icmpeq"; }  ///< (x == y) branch if ==
        else if (opr == "!=" || opr == "is not") { opcode = "if_icmpne"; }  ///< (x != y) branch if !=
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

antlrcpp::Any Pass1Visitor::visitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext * context)
{
    print_debug_context(1, context, "visitConnectedConditionalExpr");

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

    return visitChildren(context);
}
