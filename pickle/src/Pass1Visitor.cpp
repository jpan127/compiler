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



const map <string, TypeSpec **> Pass1Visitor::type_map =
{
    { "void"    , &Predefined::void_type   },
    { "bool"    , &Predefined::bool_type   },
    { "char"    , &Predefined::char_type   },
    { "int"     , &Predefined::int_type    },
    { "float"   , &Predefined::float_type  },
    { "double"  , &Predefined::double_type },
};

Pass1Visitor::~Pass1Visitor() 
{
    j_file.flush();
    j_file.close();
}

Pass1Visitor::Pass1Visitor(const string fname, const std::vector<std::string> & rule_names, const bool debug) : program_name(fname), rule_names(rule_names), program_id(nullptr), j_file(nullptr), debug_flag(debug)
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

void Pass1Visitor::print_debug_context(antlr4::ParserRuleContext * context, const std::string & rule_name) const
{
    constexpr size_t longest_name = 35;
    const string space_padding(longest_name - rule_name.length(), ' ');
    
    if (debug_flag)
    {
        cout << "[PASS2][" 
             << context->children.size() 
             << "] " 
             << rule_name 
             << space_padding 
             << " : " 
             << context->getText() 
             << endl;
    }
}

TypeSpec * Pass1Visitor::set_expression_type(TypeSpec * lhs_type, TypeSpec * rhs_type)
{
    // If any are double then result is double
    if (Predefined::double_type == lhs_type || Predefined::double_type == rhs_type)
    {
        return Predefined::double_type;
    }
    // If any are not real and neither are double then result is real
    else if (Predefined::real_type == lhs_type || Predefined::real_type == rhs_type)
    {
        return Predefined::real_type;
    }
    // Otherwise integer
    else
    {
        return Predefined::int_type;
    }
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
    auto value = visitChildren(context);
    print_debug_context(context, "visitCompilationUnit");

    // Print the cross-reference table
    CrossReferencer cross_referencer;
    cross_referencer.print(symtab_stack);
    
    return value;
}

antlrcpp::Any Pass1Visitor::visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context)
{
    print_debug_context(context, "visitTranslationUnit");

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

    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *               T Y P E  S P E C I F I E R S                *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context)
{
    print_debug_context(context, "visitTypeSpecifier");

    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   D E C L A R A T I O N S                 *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitDeclaration(Pcl2Parser::DeclarationContext *context)
{
    print_debug_context(context, "visitDeclaration"); 

    // Make a comment as to what the declaration is
    j_file << "\n; " << context->getText() << "\n" << endl;

    TypeSpec * type = nullptr;
    char type_letter = 0;

    try
    { 
        if (type_map.find(context->typeSpecifier()->getText()) != type_map.end())
        {
            cout << TAB << context->typeSpecifier()->getText() << endl;
            type = *(type_map.at(context->typeSpecifier()->getText()));
            type_letter = toupper(context->typeSpecifier()->getText()[0]);
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
    variable_id->set_typespec(type);
    cout << TAB << "Symbol table created for : " << variable_name << endl;

    // Output the variable declaration leaving room for the initial value if there is one
    j_file << ".field private static "
           << variable_name
           << " " 
           << type_letter
           << " "
           << variable_initial_value
           << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * context)
{
    print_debug_context(context, "visitFunctionDefinition");
    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   E X P R E S S I O N S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass1Visitor::visitPrimExpr(Pcl2Parser::PrimExprContext *context)
{
    /// Do we need to even support this?
    print_debug_context(context, "visitPrimExpr");
    return visitChildren(context);   
}

antlrcpp::Any Pass1Visitor::visitMulDivExpr(Pcl2Parser::MulDivExprContext *context)
{
    print_debug_context(context, "visitMulDivExpr");
    
    try
    {
        if (nullptr != context->opr)
        {
            switch (context->opr->getText()[0])
            {
                case '*': break; ///< Do nothing for now
                case '/': break; ///< Do nothing for now
                case '%': break; ///< Do nothing for now
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

    cout << TAB << lhs_name << context->opr->getText() << rhs_name << endl;

    return visitChildren(context);   
}

antlrcpp::Any Pass1Visitor::visitAddminExpr(Pcl2Parser::AddminExprContext *context)
{
    print_debug_context(context, "visitAddminExpr");

    try
    {
        if (nullptr != context->opr)
        {
            switch (context->opr->getText()[0])
            {
                case '+': break; ///< Do nothing for now
                case '-': break; ///< Do nothing for now
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
        auto lhs_id = symtab_stack->lookup(lhs_name);
        auto rhs_id = symtab_stack->lookup(rhs_name);

        if (!lhs_id)
        {
            throw "[visitAddminExpr] Could not find symbol : " + lhs_name;
        }

        if (!rhs_id)
        {
            throw "[visitAddminExpr] Could not find symbol : " + rhs_name;
        }

        context->type = set_expression_type(lhs_id->get_typespec(), rhs_id->get_typespec());
    }
    catch (string msg)
    {
        cout << msg << endl;
        exit(-1);
    }

    cout << TAB << lhs_name << context->opr->getText() << rhs_name << endl;

    return visitChildren(context);   
}
