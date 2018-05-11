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

/**
 *  Pass1Visitor << Pcl2BaseVisitor << Pcl2Visitor << AbstractParseTreeVisitor << ParseTreeVisitor
 *  Pass1Visitor:
 *      - Overrides all visit functions
 *  Pcl2BaseVisitor:
 *      - Virtual visit functions
 *  Pcl2Visitor:
 *      - Abstract visit functions
 *  AbstractParseTreeVisitor:
 *      - visitChildren()
 *      - visit()
 *      - visitTerminal()
 *      - visitErrorNode()
 *      - Some useless default functions that are never overridden
 *  ParseTreeVisitor:
 *      - Abstract visit functions
 */

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

Pass1Visitor::~Pass1Visitor() 
{
    j_file.flush();
    j_file.close();
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

/// @ { Stores type in context
antlrcpp::Any Pass1Visitor::visitVoidType(Pcl2Parser::VoidTypeContext *context)         { print_debug_context(context, "visitVoidType");     current_type = Predefined::void_type;       context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitBoolType(Pcl2Parser::BoolTypeContext *context)         { print_debug_context(context, "visitBoolType");     current_type = Predefined::bool_type;       context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitCharType(Pcl2Parser::CharTypeContext *context)         { print_debug_context(context, "visitCharType");     current_type = Predefined::char_type;       context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitShortType(Pcl2Parser::ShortTypeContext *context)       { print_debug_context(context, "visitShortType");    current_type = Predefined::short_type;      context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitIntType(Pcl2Parser::IntTypeContext *context)           { print_debug_context(context, "visitIntType");      current_type = Predefined::int_type;        context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitLongType(Pcl2Parser::LongTypeContext *context)         { print_debug_context(context, "visitLongType");     current_type = Predefined::long_type;       context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitFloatType(Pcl2Parser::FloatTypeContext *context)       { print_debug_context(context, "visitFloatType");    current_type = Predefined::float_type;      context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitDoubleType(Pcl2Parser::DoubleTypeContext *context)     { print_debug_context(context, "visitDoubleType");   current_type = Predefined::double_type;     context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitSignedType(Pcl2Parser::SignedTypeContext *context)     { print_debug_context(context, "visitSignedType");   current_type = Predefined::signed_type;     context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitUnsignedType(Pcl2Parser::UnsignedTypeContext *context) { print_debug_context(context, "visitUnsignedType"); current_type = Predefined::unsigned_type;   context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitUint32_tType(Pcl2Parser::Uint32_tTypeContext *context) { print_debug_context(context, "visitUint32_tType"); current_type = Predefined::uint32_t_type;   context->type = current_type;   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitInt32_tType(Pcl2Parser::Int32_tTypeContext *context)   { print_debug_context(context, "visitInt32_tType");  current_type = Predefined::int32_t_type;    context->type = current_type;   return visitChildren(context); }
/// @ }

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   D E C L A R A T I O N S                 *
 *                                                           *
 */////////////////////////////////////////////////////////////

/**
 *  Typical Order:
 *      - BlockItem
 *      - Declaration
 *      - DeclarationSpecifiers
 *      - DeclarationSpecifier
 *      - CharType
 *      - InitDeclaratorList
 *      - InitDeclarator
 *      - Declarator
 *      - DirectDeclarator
 *      - Initializer
 */

antlrcpp::Any Pass1Visitor::visitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *context)
{
    print_debug_context(context, "visitDirectDeclarator");

    // Create a symbol table for a new declaration
    const string variable_name = context->Identifier()->getText();
    SymTabEntry * variable_id = symtab_stack->enter_local(variable_name);
    variable_id->set_definition((Definition) DF_VARIABLE);
    variable_id->set_typespec(current_type);
    cout << "\tSymbol table created for : " << variable_name << endl;

    string current_type_indicator = "?";

         if (current_type == (symtabimpl::Predefined::void_type)     ) { current_type_indicator = "V"; }
    else if (current_type == (symtabimpl::Predefined::bool_type)     ) { current_type_indicator = "B"; }
    else if (current_type == (symtabimpl::Predefined::char_type)     ) { current_type_indicator = "C"; }
    else if (current_type == (symtabimpl::Predefined::short_type)    ) { current_type_indicator = "S"; }
    else if (current_type == (symtabimpl::Predefined::int_type)      ) { current_type_indicator = "I"; }
    else if (current_type == (symtabimpl::Predefined::long_type)     ) { current_type_indicator = "L"; }
    else if (current_type == (symtabimpl::Predefined::float_type)    ) { current_type_indicator = "F"; }
    else if (current_type == (symtabimpl::Predefined::double_type)   ) { current_type_indicator = "D"; }
    else if (current_type == (symtabimpl::Predefined::signed_type)   ) { current_type_indicator = "I"; }
    else if (current_type == (symtabimpl::Predefined::unsigned_type) ) { current_type_indicator = "I"; }
    else if (current_type == (symtabimpl::Predefined::uint32_t_type) ) { current_type_indicator = "I"; }
    else if (current_type == (symtabimpl::Predefined::int32_t_type)  ) { current_type_indicator = "I"; }

    // Output the variable declaration leaving room for the initial value if there is one
    j_file << ".field private static "
           << variable_id->get_name() 
           << " " 
           << current_type_indicator
           << " ";

    // If there is not an initial value, then don't leave room and just print a new line
    if (!has_initializer)
    {
        j_file << endl;
    }

    return visitChildren(context);
}


antlrcpp::Any Pass1Visitor::visitDeclaration(Pcl2Parser::DeclarationContext *context)
{
    print_debug_context(context, "visitDeclaration"); 

    // Make a comment as to what the declaration is
    j_file << "\n; " << context->getText() << "\n" << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitInitializer(Pcl2Parser::InitializerContext * context)
{
    print_debug_context(context, "visitInitializer");
    // Output initial value, then print the new line waived in DirectDeclarator
    j_file << context->getText() << "\n" << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitInitDeclarator(Pcl2Parser::InitDeclaratorContext *context)
{
    print_debug_context(context, "visitInitDeclarator"); 
    // Set flag whether there is an initial value or not
    has_initializer = (NULL != context->initializer());
    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * context)
{
    print_debug_context(context, "visitFunctionDefinition");
    next_declaration_is_function = true;
    return visitChildren(context);
}

/// @ { Currently don't care about these
antlrcpp::Any Pass1Visitor::visitDeclarator(Pcl2Parser::DeclaratorContext *context)                        { print_debug_context(context, "visitDeclarator");            return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *context)    { print_debug_context(context, "visitDeclarationSpecifier");  return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *context)  { print_debug_context(context, "visitDeclarationSpecifiers"); return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *context)    { print_debug_context(context, "visitParameterDeclaration");  return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *context)      { print_debug_context(context, "visitExternalDeclaration");   return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitInitDeclaratorList(Pcl2Parser::InitDeclaratorListContext *context)        { print_debug_context(context, "visitInitDeclaratorList");    return visitChildren(context); }
/// @ }

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                          L I S T S                        *
 *                                                           *
 */////////////////////////////////////////////////////////////

/// @ { Currently don't care about these
antlrcpp::Any Pass1Visitor::visitParameterTypeList(Pcl2Parser::ParameterTypeListContext *context)   { print_debug_context(context, "visitParameterTypeList"); return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitParameterList(Pcl2Parser::ParameterListContext *context)           { print_debug_context(context, "visitParameterList");     return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitIdentifierList(Pcl2Parser::IdentifierListContext *context)         { print_debug_context(context, "visitIdentifierList");    return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitBlockItemList(Pcl2Parser::BlockItemListContext *context)           { print_debug_context(context, "visitBlockItemList");     return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitBlockItem(Pcl2Parser::BlockItemContext *context)                   { print_debug_context(context, "visitBlockItem");         return visitChildren(context); }
/// @ }

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   E X P R E S S I O N S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

/**
 *  Identifier
 *  primaryExpression
 *  postfixExpression
 *  unaryExpression
 *  multiplicativeExpression
 *  additiveExpression
 *  assignmentExpression
 *  expression
 */

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
        return Predefined::int32_t_type;
    }
}

antlrcpp::Any Pass1Visitor::visitExpression(Pcl2Parser::ExpressionContext *context)
{
    print_debug_context(context, "visitExpression"); 
    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext *context)
{
    print_debug_context(context, "visitMultiplicativeExpression");

    // Only the first multiplicativeExpression has both left and right operands for some reason
    if (nullptr != context->multiplicativeExpression())
    {
        const string lhs_name = context->multiplicativeExpression()->getText();
        const string rhs_name = context->unaryExpression()->postfixExpression()->getText();
        
        cout << TAB << lhs_name << " * " << rhs_name << endl;

        try
        {
            auto lhs_id = symtab_stack->lookup(lhs_name);
            auto rhs_id = symtab_stack->lookup(rhs_name);

            if (!lhs_id)
            {
                throw "[ERROR] Could not find symbol : " + lhs_name;
            }

            if (!rhs_id)
            {
                throw "[ERROR] Could not find symbol : " + rhs_name;
            }

            context->type = set_expression_type(lhs_id->get_typespec(), rhs_id->get_typespec());
            cout << TAB << context->type << endl;
        }
        catch (string msg)
        {
            cout << msg << endl;
            exit(-1);
        }
    }

    return visitChildren(context);
}

antlrcpp::Any Pass1Visitor::visitAdditiveExpression(Pcl2Parser::AdditiveExpressionContext *context)
{ 
    print_debug_context(context, "visitAdditiveExpression"); 

    // Only the first additiveExpression has both left and right operands for some reason
    if (nullptr != context->additiveExpression())
    {
        const string lhs_name = context->additiveExpression()->getText();
        const string rhs_name = context->multiplicativeExpression()->unaryExpression()->postfixExpression()->getText();
        
        cout << TAB << lhs_name << " + " << rhs_name << endl;

        try
        {
            auto lhs_id = symtab_stack->lookup(lhs_name);
            auto rhs_id = symtab_stack->lookup(rhs_name);

            if (!lhs_id)
            {
                throw "[ERROR] Could not find symbol : " + lhs_name;
            }

            if (!rhs_id)
            {
                throw "[ERROR] Could not find symbol : " + rhs_name;
            }

            context->type = set_expression_type(lhs_id->get_typespec(), rhs_id->get_typespec());
            cout << TAB << context->type << endl;
        }
        catch (string msg)
        {
            cout << msg << endl;
            exit(-1);
        }
    }

    return visitChildren(context); 
}

/// @ { Currently don't care about these
antlrcpp::Any Pass1Visitor::visitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext *context)         { print_debug_context(context, "visitPrimaryExpression"); return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitPostfixExpression(Pcl2Parser::PostfixExpressionContext *context)         { print_debug_context(context, "visitPostfixExpression"); return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitUnaryExpression(Pcl2Parser::UnaryExpressionContext *context)             { print_debug_context(context, "visitUnaryExpression"); return visitChildren(context); }
antlrcpp::Any Pass1Visitor::visitShiftExpression(Pcl2Parser::ShiftExpressionContext *context)             { print_debug_context(context, "visitShiftExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitRelationalExpression(Pcl2Parser::RelationalExpressionContext *context)   { print_debug_context(context, "visitRelationalExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitEqualityExpression(Pcl2Parser::EqualityExpressionContext *context)       { print_debug_context(context, "visitEqualityExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitAndExpression(Pcl2Parser::AndExpressionContext *context)                 { print_debug_context(context, "visitAndExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext *context) { print_debug_context(context, "visitExclusiveOrExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext *context) { print_debug_context(context, "visitInclusiveOrExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext *context)   { print_debug_context(context, "visitLogicalAndExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext *context)     { print_debug_context(context, "visitLogicalOrExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitConditionalExpression(Pcl2Parser::ConditionalExpressionContext *context) { print_debug_context(context, "visitConditionalExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *context)   { print_debug_context(context, "visitAssignmentExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
antlrcpp::Any Pass1Visitor::visitForExpression(Pcl2Parser::ForExpressionContext *context)                 { print_debug_context(context, "visitForExpression"); return visitChildren(context); } /// context->type = set_expression_type(context->) return visitChildren(context); };
/// @ }
