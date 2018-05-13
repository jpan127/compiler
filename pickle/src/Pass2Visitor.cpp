#include <iostream>
#include <string>
#include <typeinfo>

#include "Pass2Visitor.hpp"
#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;



/// @NOTE : There's no fucking good resources for Jasmin instructions except this https://cs.au.dk/~mis/dOvs/jvmspec/ref-Java.html

Pass2Visitor::Pass2Visitor(const string fname, ofstream & j_file, const bool debug) : PassVisitor(), program_name(fname), j_file(j_file), debug_flag(debug)
{
    /// Empty
}

Pass2Visitor::~Pass2Visitor()
{
    j_file.flush();
    j_file.close();
}

string Pass2Visitor::resolve_expression_instruction(TypeSpec * type, const char opr)
{
    string opcode;

    if (Predefined::double_type == type)
    {
        switch (opr)
        {
            case '*': opcode = "lmul";             break;
            case '/': opcode = "ldiv";             break;
            case '%': opcode = "lrem";             break;
            case '+': opcode = "ladd";             break;
            case '-': opcode = "lsub";             break;
            default : throw InvalidOperator(&opr); break;
        }
    }
    else if (Predefined::float_type == type)
    {
        switch (opr)
        {
            case '*': opcode = "fmul";             break;
            case '/': opcode = "fdiv";             break;
            case '%': opcode = "frem";             break;
            case '+': opcode = "fadd";             break;
            case '-': opcode = "fsub";             break;
            default : throw InvalidOperator(&opr); break;
        }
    }
    else
    {
        switch (opr)
        {
            case '*': opcode = "imul";             break;
            case '/': opcode = "idiv";             break;
            case '%': opcode = "irem";             break;
            case '+': opcode = "iadd";             break;
            case '-': opcode = "isub";             break;
            default : throw InvalidOperator(&opr); break;
        }            
    }

    return opcode;
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   C O M P I L A T I O N                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass2Visitor::visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context)
{
    print_debug_context(2, context, "visitCompilationUnit");
    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitTranslationUnit(Pcl2Parser::TranslationUnitContext * context)
{
    print_debug_context(2, context, "visitTranslationUnit");

    // Emit the main program header
    j_file                                                                          << endl;
    j_file << ".method public static main([Ljava/lang/String;)V"                    << endl;
    j_file                                                                          << endl;
    j_file << "\tnew RunTimer"                                                      << endl;
    j_file << "\tdup"                                                               << endl;
    j_file << "\tinvokenonvirtual RunTimer/<init>()V"                               << endl;
    j_file << "\tputstatic        " << program_name << "/_runTimer LRunTimer;"      << endl;
    j_file << "\tnew PascalTextIn"                                                  << endl;
    j_file << "\tdup"                                                               << endl;
    j_file << "\tinvokenonvirtual PascalTextIn/<init>()V"                           << endl;
    j_file << "\tputstatic        " + program_name << "/_standardIn LPascalTextIn;" << endl;
    j_file                                                                          << endl;

    // We want to vist the children and traverse the entire tree before printing the next epilogue
    auto value = visitChildren(context);

    // Emit the main program epilogue
    j_file                                                                          << endl;
    j_file << "\tgetstatic     " << program_name << "/_runTimer LRunTimer;"         << endl;
    j_file << "\tinvokevirtual RunTimer.printElapsedTime()V"                        << endl;
    j_file                                                                          << endl;
    j_file << "\treturn"                                                            << endl;
    j_file                                                                          << endl;
    j_file << ".limit locals 16"                                                    << endl;
    j_file << ".limit stack 16"                                                     << endl;
    j_file << ".end method"                                                         << endl;

    return value;
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *               T Y P E  S P E C I F I E R S                *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass2Visitor::visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context)
{
    print_debug_context(2, context, "visitTypeSpecifier");
    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   D E C L A R A T I O N S                 *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass2Visitor::visitDeclaration(Pcl2Parser::DeclarationContext *context)
{
    print_debug_context(2, context, "visitDeclaration");
    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context)
{
    print_debug_context(2, context, "visitFunctionDefinition");
    return visitChildren(context);
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                   E X P R E S S I O N S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass2Visitor::visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext * context)
{
    print_debug_context(2, context, "visitAssignmentExpression");

    /**
     *  RHS expression will take care of emitting its own instructions
     *  This node will just load the value into the assigned variable
     */

    j_file << TAB << "; " + context->getText() << endl;

    // Visit right hand side expression first
    auto expression_result = visit(context->expression());

    // Emit a field put instruction.
    j_file << "\tputstatic\t" 
           << program_name
           << "/" 
           << context->Identifier()->toString()
           << " " 
           << context->type_letter 
           << endl;

    return expression_result;
}

antlrcpp::Any Pass2Visitor::visitPrimExpr(Pcl2Parser::PrimExprContext *context)
{
    print_debug_context(2, context, "visitPrimExpr");

    /**
     *  If variable : emit getstatic
     *  If integer  : emit iconst
     *  If float    : emit fconst
     */

    if (context->primaryExpression()->Identifier())
    {
        j_file << TAB
               << "getstatic"
               << TAB
               << program_name
               << "/"
               << context->primaryExpression()->Identifier()->getText()
               << " "
               << context->type_letter
               << endl;
    }
    else if (context->primaryExpression()->IntegerConstant())
    {
        j_file << TAB
               << "iconst "
               << context->primaryExpression()->IntegerConstant()->getText()
               << endl;
    }
    else if (context->primaryExpression()->FloatConstant())
    {
        j_file << TAB
               << "fconst "
               << context->primaryExpression()->FloatConstant()->getText()
               << endl;
    }

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitMulDivExpr(Pcl2Parser::MulDivExprContext *context)
{
    print_debug_context(2, context, "visitMulDivExpr");

    /**
     *  Visits children expressions first which will push to stack
     *  Then this node will emit an instruction using the previously pushed values
     */

    visit(context->expression(0));
    visit(context->expression(1));

    string opcode;

    try
    {
        switch (context->expr_operator)
        {
            case '*': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            case '/': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            case '%': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            default : throw InvalidOperator(&context->expr_operator);                                 break;
        }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    j_file << "\t" << opcode << endl;

    return nullptr;
}

antlrcpp::Any Pass2Visitor::visitAddminExpr(Pcl2Parser::AddminExprContext *context)
{
    print_debug_context(2, context, "visitAddminExpr");

    /**
     *  Visits children expressions first which will push to stack
     *  Then this node will emit an instruction using the previously pushed values
     */

    visit(context->expression(0));
    visit(context->expression(1));

    string opcode;

    try
    {
        switch (context->expr_operator)
        {
            case '+': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            case '-': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            default : throw InvalidOperator(&context->expr_operator);                                 break;
        }
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    j_file << "\t" << opcode << endl;

    return nullptr;
}

/*////////////////////////////////////////////////////////////
 *                                                           *
 *                     S T A T E M E N T S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass2Visitor::visitAssignmentStatement(Pcl2Parser::AssignmentStatementContext *context)
{
    print_debug_context(2, context, "visitAssignmentStatement");

    /**
     *  Nothing yet
     */

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitIterationStatement(Pcl2Parser::IterationStatementContext *context)
{
    print_debug_context(2, context, "visitIterationStatement");

    /**
     *  Emit start of loop label
     *  Visit children which will emit the instructions internal to the loop
     *  Emit a jump to start of loop
     *  Emit a label for the end of loop
     */

    // Emit the iteration label
    j_file << endl 
           << context->conditionalExpression()->iteration_name 
           << ":" 
           << endl;

    // Emit while loop
    auto value = visitChildren(context);

    // Emit a jump to start of loop
    j_file << TAB
           << "; Jump to start of loop"
           << endl
           << TAB
           << "goto "
           << context->conditionalExpression()->iteration_name
           << endl;

    // Add label to branch to for exiting the loop
    j_file << context->conditionalExpression()->iteration_name
           << "_end"
           << ":"
           << endl;

    return value;
}

antlrcpp::Any Pass2Visitor::visitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext *context)
{
    print_debug_context(2, context, "visitBasicConditionalExpr");

    /**
     *  Children emit instructions first
     *  Emits branch instruction for exiting the current branch
     */

    const string lhs_name = context->expression(0)->getText();
    const string rhs_name = context->expression(1)->getText();

    // Emit an explanation comment for condition
    j_file << TAB 
           << "; "
           << lhs_name
           << " "
           << context->opr
           << " "
           << rhs_name
           << endl;

    auto lhs_result = visit(context->expression(0));
    auto rhs_result = visit(context->expression(1));

    // Emit an explanation comment for exit
    j_file << TAB
           << "; Exit ["
           << context->iteration_name
           << "] condition"
           << endl;

    // Emit the instruction
    j_file << TAB
           << context->opcode
           << " "
           << context->iteration_name + "_end"
           << endl;

    // return visitChildren(context);
    return nullptr;
}

antlrcpp::Any Pass2Visitor::visitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext *context)
{
    print_debug_context(2, context, "visitConnectedConditionalExpr");

    /**
     *  Top level conditional expression
     *  Responsible for only checking the top 2 values on the stack
     *  For an OR operation, if any of them are nonzero positive, jump
     *  For an AND operation, if both of them are nonzero positive, jump
     */

    // Visit left and right sides first
    auto lhs_result = visit(context->conditionalExpression(0));
    auto rhs_result = visit(context->conditionalExpression(1));

    // Left and right operands should have pushed values to the stack
    if ("or" == context->opr)
    {
        // If left condition is > 0, jump 
        j_file << TAB
               << "ifgt "
               << context->iteration_name
               << endl;
        // If right condition is > 0, jump
        j_file << TAB
               << "ifgt "
               << context->iteration_name
               << endl;
    }
    else if ("and" == context->opr)
    {
        // If both conditions are > 0, then multiplying them will be > 0
        j_file << TAB
               << "imul "
               << endl;
        j_file << TAB
               << "ifgt "
               << context->iteration_name
               << endl;
    }

    // Return visiting the middle
    return nullptr;
}

antlrcpp::Any Pass2Visitor::visitNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext *context)
{
    print_debug_context(2, context, "visitNegatedConditionalExpr");

    /**
     *  Nothing yet
     */

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext *context)
{
    print_debug_context(2, context, "visitParenthesizedConditionalExpr");

    /**
     *  Nothing yet
     */

    return visitChildren(context);
}
