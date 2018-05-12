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

Pass2Visitor::Pass2Visitor(const string fname, ofstream & j_file, const bool debug) : program_name(fname), j_file(j_file), debug_flag(debug), scope_counter(0)
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
            case '*': opcode = "lmul";          break;
            case '/': opcode = "ldiv";          break;
            case '%': opcode = "lrem";          break;
            case '+': opcode = "ladd";          break;
            case '-': opcode = "lsub";          break;
            default : throw out_of_range(&opr); break;
        }
    }
    else if (Predefined::float_type == type)
    {
        switch (opr)
        {
            case '*': opcode = "fmul";          break;
            case '/': opcode = "fdiv";          break;
            case '%': opcode = "frem";          break;
            case '+': opcode = "fadd";          break;
            case '-': opcode = "fsub";          break;
            default : throw out_of_range(&opr); break;
        }
    }
    else
    {
        switch (opr)
        {
            case '*': opcode = "imul";          break;
            case '/': opcode = "idiv";          break;
            case '%': opcode = "irem";          break;
            case '+': opcode = "iadd";          break;
            case '-': opcode = "isub";          break;
            default : throw out_of_range(&opr); break;
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

    j_file << endl << "; " + context->getText() << endl << endl;

    // Get value of the right hand side expression first
    auto expression_result = visit(context->expression());

    try
    {
        char letter = '?';

        cout << "******************** " << context->type_letter << endl;
        
        // // Get type set by first pass
        // if (auto base = dynamic_cast<Pcl2Parser::DeclarationContext *>(context->parent))
        // {
        //     letter = base->type_letter;
        // }
        // else if (auto base = dynamic_cast <Pcl2Parser::AssignmentStatementContext *>(context->parent))
        // {
        //     letter = base->type_letter;
        // }
        // else
        // {
        //     throw bad_cast();
        // }

        // Emit a field put instruction.
        j_file << "\tputstatic\t" 
               << program_name
               << "/" 
               << context->Identifier()->toString()
               << " " 
               << context->type_letter 
               << endl;
    }
    catch (std::bad_cast & msg)
    {
        cerr << "Assignment parent is not castable to declaration or AssignmentStatement : " << msg.what() << endl;
        exit(-1);
    }

    return expression_result;
}

antlrcpp::Any Pass2Visitor::visitPrimExpr(Pcl2Parser::PrimExprContext *context)
{
    print_debug_context(2, context, "visitPrimExpr");
    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitMulDivExpr(Pcl2Parser::MulDivExprContext *context)
{
    print_debug_context(2, context, "visitMulDivExpr");

    const string lhs_name = context->expression(0)->getText();
    const string rhs_name = context->expression(1)->getText();

    const TypeSpec * lhs_type = context->expression(0)->type;
    const TypeSpec * rhs_type = context->expression(1)->type;

    if (!lhs_type)
    {
        cerr << "lhs_type is NULL" << endl;
        exit(-1);
    }
    else
    {
        j_file << "\tgetstatic\t" 
               << program_name
               << "/" 
               << lhs_name 
               << " " 
               << letter_map_lookup(lhs_type)
               << endl;
    }

    if (!rhs_type)
    {
        cerr << "rhs_type is NULL" << endl;
        exit(-1);
    }
    else
    {
        j_file << "\tgetstatic\t" 
               << program_name
               << "/" 
               << rhs_name 
               << " " 
               << letter_map_lookup(rhs_type)
               << endl;
    }

    string opcode;

    try
    {
        switch (context->expr_operator)
        {
            case '*': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            case '/': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            case '%': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            default : throw invalid_argument(&context->expr_operator);                                break;
        }
    }
    catch (out_of_range & exception)
    {
        cerr << "[resolve_expression_instruction] Impossible operator found : " << context->expr_operator << " " << exception.what() << endl;
        exit(-1);
    }
    catch (invalid_argument & exception)
    {
        cerr << "[visitMulDivExpr] Impossible operator found : " << context->expr_operator << " " << exception.what() << endl;
        exit(-1);
    }

    j_file << "\t" << opcode << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitAddminExpr(Pcl2Parser::AddminExprContext *context)
{
    print_debug_context(2, context, "visitAddminExpr");

    const string lhs_name = context->expression(0)->getText();
    const string rhs_name = context->expression(1)->getText();

    const TypeSpec * lhs_type = context->expression(0)->type;
    const TypeSpec * rhs_type = context->expression(1)->type;

    if (!lhs_type)
    {
        cerr << "lhs_type is NULL" << endl;
        exit(-1);
    }
    else
    {
        j_file << "\tgetstatic\t" 
               << program_name
               << "/" 
               << lhs_name 
               << " " 
               << letter_map_lookup(lhs_type)
               << endl;
    }

    if (!rhs_type)
    {
        cerr << "rhs_type is NULL" << endl;
        exit(-1);
    }
    else
    {
        j_file << "\tgetstatic\t" 
               << program_name
               << "/" 
               << rhs_name 
               << " " 
               << letter_map_lookup(rhs_type)
               << endl;
    }

    string opcode;

    try
    {
        switch (context->expr_operator)
        {
            case '+': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            case '-': opcode = resolve_expression_instruction(context->type, context->expr_operator); break;
            default : throw invalid_argument(&context->expr_operator);                                break;
        }
    }
    catch (out_of_range & exception)
    {
        cerr << "[resolve_expression_instruction] Impossible operator found : " << context->expr_operator << " " << exception.what() << endl;
        exit(-1);
    }
    catch (invalid_argument & exception)
    {
        cerr << "[visitAddminExpr] Impossible operator found : " << context->expr_operator << " " << exception.what() << endl;
        exit(-1);
    }

    j_file << "\t" << opcode << endl;

    return visitChildren(context);
}

#if 0

    antlrcpp::Any Pass2Visitor::visitSignedNumber(Pcl2Parser::SignedNumberContext *ctx)
    {
        auto value = visitChildren(ctx);
        TypeSpec *type = ctx->number()->type;

        if (ctx->sign()->children[0] == ctx->sign()->SUB_OP())
        {
            string opcode = (type == Predefined::integer_type) ? "ineg"
                          : (type == Predefined::float_type)    ? "fneg"
                          :                                      "?neg";

            // Emit a negate instruction.
            j_file << "\t" << opcode << endl;
        }

        return value;
    }

    antlrcpp::Any Pass2Visitor::visitIntegerConst(Pcl2Parser::IntegerConstContext *ctx)
    {
        j_file << "\tldc\t" << ctx->getText() << endl;
        return visitChildren(ctx);
    }

    antlrcpp::Any Pass2Visitor::visitFloatConst(Pcl2Parser::FloatConstContext *ctx)
    {
        j_file << "\tldc\t" << ctx->getText() << endl;
        return visitChildren(ctx);
    }

#endif


/*////////////////////////////////////////////////////////////
 *                                                           *
 *                     S T A T E M E N T S                   *
 *                                                           *
 */////////////////////////////////////////////////////////////

antlrcpp::Any Pass2Visitor::visitAssignmentStatement(Pcl2Parser::AssignmentStatementContext *context)
{

}

antlrcpp::Any Pass2Visitor::visitIterationStatement(Pcl2Parser::IterationStatementContext *context)
{
    print_debug_context(2, context, "visitIterationStatement");

    // Store iteration name
    context->conditionalExpression()->iteration_name = "while" + std::to_string(scope_counter++);

    // Emit the iteration label
    j_file << endl 
           << context->conditionalExpression()->iteration_name 
           << ":" 
           << endl;

    auto value = visitChildren(context);

    // Emit comment saying end of loop
    j_file << "; End : "
           << context->conditionalExpression()->iteration_name
           << endl;

    return value;
}

antlrcpp::Any Pass2Visitor::visitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext *context)
{
    print_debug_context(2, context, "visitBasicConditionalExpr");

    // ConditionalOperator
    const string opr = context->ConditionalOperator()->getText();
    const string lhs_name = context->expression(0)->getText();
    const string rhs_name = context->expression(1)->getText();

    string opcode;

    try
    {
             if (opr == "<")                     { opcode = "if_icmplt"; }
        else if (opr == "<=")                    { opcode = "if_icmple"; }
        else if (opr == ">")                     { opcode = "if_icmpgt"; }
        else if (opr == ">=")                    { opcode = "if_icmpge"; }
        else if (opr == "==" || opr == "is")     { opcode = "if_icmpeq"; }
        else if (opr == "!=" || opr == "is not") { opcode = "if_icmpne"; }
        else                                     { throw invalid_argument(opr); }
    }
    catch (invalid_argument const & exception)
    {
        cerr << exception.what() << endl;
        exit(-1);
    }

    // Emit an explanation comment
    j_file << TAB 
           << "; "
           << lhs_name
           << " "
           << opr
           << " "
           << rhs_name
           << endl;

    // auto lhs_result = visit(context->expression(0));
    // auto rhs_result = visit(context->expression(1));

    // If right operand is a variable
    if (PassVisitor::is_digit(rhs_name))
    {
        j_file << TAB
               << "ldc "
               << rhs_name
               << endl;
    }
    else
    {
        // context->expression(0)->expression(0)->Identifier()->getText()
        j_file << TAB
               << "getstatic"
               << TAB
               << program_name
               << "/"
               << rhs_name
               << " "
               << context->expression(0)->type
               << endl;
    }

    // If left operand is a variable
    if (PassVisitor::is_digit(lhs_name))
    {
        j_file << TAB
               << "ldc "
               << lhs_name
               << endl;
    }
    else
    {
        // context->expression(0)->expression(0)->Identifier()->getText()
        j_file << TAB
               << "getstatic"
               << TAB
               << program_name
               << "/"
               << lhs_name
               << " "
               << context->expression(0)->type
               << endl;
    }

    // Emit the instruction
    j_file << TAB
           << opcode
           << " "
           << context->iteration_name
           << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext *context)
{
    print_debug_context(2, context, "visitNegatedConditionalExpr");
    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext *context)
{
    print_debug_context(2, context, "visitConnectedConditionalExpr");
    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext *context)
{
    print_debug_context(2, context, "visitParenthesizedConditionalExpr");
    return visitChildren(context);
}
