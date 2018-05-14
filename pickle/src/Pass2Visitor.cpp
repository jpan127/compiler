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



/**
 *  @note:
 *      Good resource for Jasmin instructions except this https://cs.au.dk/~mis/dOvs/jvmspec/ref-Java.html
 *      XSUB instructions will subtract bottom operand - top operand, with bottom operand as the first operand pushed onto the stack
 */

Pass2Visitor::Pass2Visitor(const string fname, ofstream & j_file, const bool debug) : PassVisitor(), program_name(fname), j_file(j_file), debug_flag(debug)
{
    /// Empty
}

Pass2Visitor::~Pass2Visitor()
{
    j_file.flush();
    j_file.close();
}

string Pass2Visitor::resolve_expression_instruction(TypeSpec * type, string const & opr)
{
    static const map <const string, const string> operator_to_opcode_map =
    {
        { "*"  , "mul" },
        { "/"  , "div" },
        { "%"  , "rem" },
        { "+"  , "add" },
        { "-"  , "sub" },
        { "<<" , "shl" },
        { ">>" , "shr" },
        { "&"  , "and" },
        { "|"  , "or"  },
        { "~"  , "neg" },
        { "^"  , "xor" },
    };

    // Get opcode prefix
    string opcode(1, instruction_prefix_map_lookup(type));

    // Get opcode
    if (operator_to_opcode_map.find(opr) != operator_to_opcode_map.end())
    {
        opcode += operator_to_opcode_map.at(opr);
    }
    else
    {
        throw InvalidOperator(opr);
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

    // We want to vist the children and traverse the entire tree before printing the next epilogue
    auto value = visitChildren(context);

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

    /**
     *  Nothing yet
     */

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

    /**
     *  Nothing yet
     */

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context)
{
    print_debug_context(2, context, "visitFunctionDefinition");
    bool is_main = context->Identifier()->getText() == "main";

    j_file << context->function_header;
    if(is_main){
        // Emit the main program header
//        j_file                                                                          << endl;
//        j_file << ".method public static main([Ljava/lang/String;)V"                    << endl;
        j_file                                                                          << endl;
        j_file << "\tnew RunTimer"                                                      << endl;
        j_file << "\tdup"                                                               << endl;
        j_file << "\tinvokenonvirtual RunTimer/<init>()V"                               << endl;
        j_file << "\tputstatic        " << program_name << "/_runTimer LRunTimer;"      << endl;
        j_file << "\tnew PascalTextIn"                                                  << endl;
        j_file << "\tdup"                                                               << endl;
        j_file << "\tinvokenonvirtual PascalTextIn/<init>()V"                           << endl;
        j_file << "\tputstatic        " + program_name << "/_standardIn LPascalTextIn;" << endl;
    }
    visit(context->compoundStatement());

    if(is_main){

        // Emit the main program epilogue
        j_file                                                                          << endl;
        j_file << "\tgetstatic     " << program_name << "/_runTimer LRunTimer;"         << endl;
        j_file << "\tinvokevirtual RunTimer.printElapsedTime()V"                        << endl;
        j_file                                                                          << endl;
        j_file << "\treturn"                                                            << endl;
        j_file                                                                          << endl;
        j_file << ".limit locals 16"                                                    << endl;
        j_file << ".limit stack 16"                                                     << endl;
    }
    j_file << ".end method" << endl;

    //return visitChildren(context); todo: double check return, nothing else has to be done
    return nullptr;
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
     *  If integer  : emit ldc
     *  If float    : emit ldc
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
    else if (context->primaryExpression()->IntegerConstant() ||
            (context->primaryExpression()->FloatConstant()))
    {
        j_file << TAB
               << "ldc "
               << context->primaryExpression()->IntegerConstant()->getText()
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
        opcode = resolve_expression_instruction(context->type, context->expr_operator);
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
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
        opcode = resolve_expression_instruction(context->type, context->expr_operator);
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    j_file << "\t" << opcode << endl;

    return nullptr;
}

antlrcpp::Any Pass2Visitor::visitBitExpr(Pcl2Parser::BitExprContext *context)
{
    print_debug_context(2, context, "visitBitExpr");

    /**
     *  Visits children expressions first which will push to stack
     *  Then this node will emit an instruction using the previously pushed values
     */

    visit(context->expression(0));
    visit(context->expression(1));

    string opcode;

    try
    {
        opcode = resolve_expression_instruction(context->type, context->expr_operator);
    }
    catch (InvalidType const & error)
    {
        error.print_and_exit();
    }
    catch (InvalidOperator const & error)
    {
        error.print_and_exit();
    }

    j_file << "\t" << opcode << endl;

    return nullptr;
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
           << endl
           << endl;

    return value;
}

antlrcpp::Any Pass2Visitor::visitSelectionStatement(Pcl2Parser::SelectionStatementContext *context)
{
    print_debug_context(2, context, "visitSelectionStatement");

    /**
     *  Emit start of if label
     *  Visit children which will emit the instructions internal to the branch
     *  Emit a label for the end of if
     */

    // Emit start label
    j_file << context->conditionalExpression()->iteration_name
           << ":"
           << endl;

    // Visit expression child first
    visit(context->conditionalExpression());

    // Visit children inside the if block
    visit(context->statement());

    // Emit end label
    j_file << context->conditionalExpression()->iteration_name
           << "_end"
           << ":"
           << endl
           << endl;

    return nullptr;
}


antlrcpp::Any Pass2Visitor::visitUnaryIncrementStatement(Pcl2Parser::UnaryIncrementStatementContext *context)
{
    print_debug_context(2, context, "visitUnaryIncrementStatement");

    // Get variable
    j_file << TAB
           << "getstatic"
           << TAB
           << program_name
           << "/"
           << context->Identifier()->getText()
           << " "
           << context->type_letter
           << endl;

    // Load one
    j_file << TAB
           << "iconst_1"
           << endl;

    j_file << TAB
           << resolve_expression_instruction(context->type, "+")
           << endl;

    // Write back the variable
    j_file << TAB
           << "putstatic"
           << TAB
           << program_name
           << "/"
           << context->Identifier()->getText()
           << " "
           << context->type_letter
           << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitUnaryDecrementStatement(Pcl2Parser::UnaryDecrementStatementContext *context)
{
    print_debug_context(2, context, "visitUnaryDecrementStatement");

    // Get variable
    j_file << TAB
           << "getstatic"
           << TAB
           << program_name
           << "/"
           << context->Identifier()->getText()
           << " "
           << context->type_letter
           << endl;

    // Load one
    j_file << TAB
           << "iconst_1"
           << endl;

    j_file << TAB
           << resolve_expression_instruction(context->type, "-")
           << endl;

    // Write back the variable
    j_file << TAB
           << "putstatic"
           << TAB
           << program_name
           << "/"
           << context->Identifier()->getText()
           << " "
           << context->type_letter
           << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitUnarySquareStatement(Pcl2Parser::UnarySquareStatementContext *context)
{
    print_debug_context(2, context, "visitUnarySquareStatement");

    // Get variable twice
    for (uint8_t i = 0; i < 2; i++)
    {
        j_file << TAB
               << "getstatic"
               << TAB
               << program_name
               << "/"
               << context->Identifier()->getText()
               << " "
               << context->type_letter
               << endl;
    }

    // Multiply
    j_file << TAB
           << resolve_expression_instruction(context->type, "*")
           << endl;

    // Write back the variable
    j_file << TAB
           << "putstatic"
           << TAB
           << program_name
           << "/"
           << context->Identifier()->getText()
           << " "
           << context->type_letter
           << endl;

    return visitChildren(context);
}

// antlrcpp::Any Pass2Visitor::visitUnaryStatement(Pcl2Parser::UnaryStatementContext *context)
// {
//     print_debug_context(2, context, "visitUnaryStatement");

//     /**
//      *  Loads the variable and a constant 1
//      *  Emits an add or sub instruction
//      *  Writes the variable back
//      *  @note : First variable pushed onto stack will be the LHS of a sub operation
//      */

//     // Get variable
//     j_file << TAB
//            << "getstatic"
//            << TAB
//            << program_name
//            << "/"
//            << context->Identifier()->getText()
//            << " "
//            << context->type_letter
//            << endl;

//     // Load one
//     j_file << TAB
//            << "iconst_1"
//            << endl;

//     // Emit either add or sub instruction
//     try
//     {
//         if (context->PlusPlus())
//         {
//             j_file << TAB
//                    << resolve_expression_instruction(context->type, '+')
//                    << endl;

//         }
//         else if (context->MinusMinus())
//         {
//             j_file << TAB
//                    << resolve_expression_instruction(context->type, '-')
//                    << endl;
//         }
//         else
//         {
//             throw AntlrParsedIncorrectly("[visitUnaryStatement] Missing operator");
//         }        
//     }
//     catch (AntlrParsedIncorrectly const & error)
//     {
//         error.print_and_exit();
//     }

//     // Write back the variable
//     j_file << TAB
//            << "putstatic"
//            << TAB
//            << program_name
//            << "/"
//            << context->Identifier()->getText()
//            << " "
//            << context->type_letter
//            << endl;

//     return visitChildren(context);
// }
