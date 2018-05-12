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

Pass1Visitor::Pass1Visitor(const string fname, const bool debug) : program_name(fname), program_id(nullptr), j_file(nullptr), debug_flag(debug)
{
    // Create and initialize the symbol table stack.
    symtab_stack = SymTabFactory::create_symtab_stack();
    Predefined::initialize(symtab_stack);

    program_id = symtab_stack->enter_local(program_name);
    program_id->set_definition((Definition)DF_PROGRAM);
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
            throw "***** Failed to open file";
        }
    }
    catch (const char * exception)
    {
        cerr << exception << endl;
        exit(-1);
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
            context->type_letter = toupper(context->typeSpecifier()->getText()[0]);
        }
        else
        {
        #ifdef TESTING
            throw "Type not supported : " + context->getText();
        #else
            cerr << "Type not supported : " << context->getText() << endl;
        #endif
        }
    }
    catch (const string msg)
    {
        cerr << msg << endl;
        exit(-1);
    }

    string variable_name;
    string variable_initial_value;
    
    if (context->assignmentExpression(0))
    {
        cout << TAB << "Has assignment\n";
        variable_name = context->assignmentExpression(0)->Identifier()->getText();
    
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

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   E X P R E S S I O N S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitPrimExpr(Pcl2Parser::PrimExprContext *context)
{
    print_debug_context(1, context, "visitPrimExpr");

    if (context->primaryExpression()->Identifier())
    {
        // Look up type of this expression in the symbol table stack
        try
        {
            auto id = symtab_stack->lookup_local(context->getText());

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
                    context->expr_operator = x.second;
                    context->type = type;
                    cout << TAB << type                   << endl;
                    cout << TAB << *x.first               << endl;
                    cout << TAB << context->expr_operator << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                const string error = string("[visitPrimExpr] Could not find type : ") + type->to_string();
                throw error;
            }
        }
        catch (const string & msg)
        {
            cerr << msg << endl;
            exit(-1);
        }
    }
    else if (context->primaryExpression()->IntegerConstant())
    {
        context->expr_operator = 'I';
        context->type = Predefined::integer_type;
    }
    else if (context->primaryExpression()->FloatConstant())
    {
        context->expr_operator = 'F';
        context->type = Predefined::float_type;
    }

    return visitChildren(context);   
}

antlrcpp::Any Pass1Visitor::visitMulDivExpr(Pcl2Parser::MulDivExprContext *context)
{
    print_debug_context(1, context, "visitMulDivExpr");
    
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
                    throw "MulDivExpr received impossible operator : " + context->opr->getText()[0];
                    break;
            }
        }
        else
        {
            throw "MulDivExpr missing operator";
        }
    }
    catch (const string msg)
    {
        cout << msg << endl;
        exit(-1);
    }

    const string lhs_name = context->expression(0)->getText();
    const string rhs_name = context->expression(1)->getText();

    try
    {
        auto lhs_id = symtab_stack->lookup_local(lhs_name);
        auto rhs_id = symtab_stack->lookup_local(rhs_name);

        if (!lhs_id)
        {
            throw "[visitMulDivExpr] Could not find symbol : " + lhs_name;
        }

        if (!rhs_id)
        {
            throw "[visitMulDivExpr] Could not find symbol : " + rhs_name;
        }

        context->type = resolve_expression_type(lhs_id->get_typespec(), rhs_id->get_typespec());
    }
    catch (const char * msg)
    {
        cout << msg << endl;
        exit(-1);
    }

    cout << TAB << lhs_name << context->opr->getText() << rhs_name << endl;

    return visitChildren(context);   
}

antlrcpp::Any Pass1Visitor::visitAddminExpr(Pcl2Parser::AddminExprContext *context)
{
    print_debug_context(1, context, "visitAddminExpr");

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
                    throw "[visitAddminExpr] received impossible operator : " + context->opr->getText()[0];
                    break;
            }
        }
        else
        {
            throw "[visitAddminExpr] missing operator";
        }
    }
    catch (const string msg)
    {
        cout << msg << endl;
        exit(-1);
    }

    const string lhs_name = context->expression(0)->getText();
    const string rhs_name = context->expression(1)->getText();

    try
    {
        auto lhs_id = symtab_stack->lookup_local(lhs_name);
        auto rhs_id = symtab_stack->lookup_local(rhs_name);

        if (!lhs_id)
        {
            throw "[visitAddminExpr] Could not find symbol : " + lhs_name;
        }

        if (!rhs_id)
        {
            throw "[visitAddminExpr] Could not find symbol : " + rhs_name;
        }

        context->type = resolve_expression_type(lhs_id->get_typespec(), rhs_id->get_typespec());
    }
    catch (const char * msg)
    {
        cout << msg << endl;
        exit(-1);
    }

    cout << TAB << lhs_name << context->opr->getText() << rhs_name << endl;

    return visitChildren(context);   
}
