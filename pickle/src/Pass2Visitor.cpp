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

void Pass2Visitor::emit_symbol_table()
{
    // j_file                                                                          << endl;
    // j_file << "; Printing results of the program below" << endl;
    // j_file << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;
    // j_file << "print_results:" << endl << endl;
    // j_file << TAB << "getstatic java/lang/System/out Ljava/io/PrintStream;" << endl;

    // for (auto function : PassVisitor::variable_id_map)
    // {
    //     for (auto symbol : function.second)
    //     {
    //         j_file << TAB << "ldc \"" + symbol.first << " : " << 
    //     }
    // }

    // j_file << TAB << "ldc \"Start:%f d:%f e:%f fizz_counter:%d buzz_counter:%d fizz_buzz:%d\"" << endl;
    // j_file << TAB << "ldc 6" << endl;
    // j_file << TAB << "anewarray java/lang/Object" << endl << endl;

    // j_file << TAB << "dup" << endl;
    // j_file << TAB << "iconst_0" << endl;
    // j_file << TAB << "ldc2_w 100.0" << endl;
    // j_file << TAB << "invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;" << endl;
    // j_file << TAB << "aastore" << endl << endl;

    // j_file << TAB << "dup" << endl;
    // j_file << TAB << "iconst_1" << endl;
    // j_file << TAB << "dload 9" << endl;
    // j_file << TAB << "invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;" << endl;
    // j_file << TAB << "aastore" << endl << endl;

    // j_file << TAB << "dup" << endl;
    // j_file << TAB << "iconst_2" << endl;
    // j_file << TAB << "dload 11" << endl;
    // j_file << TAB << "invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;" << endl;
    // j_file << TAB << "aastore" << endl << endl;

    // j_file << TAB << "dup" << endl;
    // j_file << TAB << "iconst_3" << endl;
    // j_file << TAB << "iload 4" << endl;
    // j_file << TAB << "invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;" << endl;
    // j_file << TAB << "aastore" << endl << endl;

    // j_file << TAB << "dup" << endl;
    // j_file << TAB << "iconst_4" << endl;
    // j_file << TAB << "iload 5" << endl;
    // j_file << TAB << "invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;" << endl;
    // j_file << TAB << "aastore" << endl << endl;

    // j_file << TAB << "dup" << endl;
    // j_file << TAB << "iconst_5" << endl;
    // j_file << TAB << "iload 8" << endl;
    // j_file << TAB << "invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;" << endl;
    // j_file << TAB << "aastore" << endl << endl;

    // j_file << TAB << "invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;" << endl << endl;
    // j_file << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;
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
    return visitChildren(context);
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

    if (!is_main)
    {
        j_file << context->function_header << endl;
    }
    else
    {
        // Emit the main program header
        j_file                                                                          << endl;
        j_file << ".method public static main([Ljava/lang/String;)V"                    << endl;
        j_file                                                                          << endl;
        j_file << "\tnew RunTimer"                                                      << endl;
        j_file << "\tdup"                                                               << endl;
        j_file << "\tinvokenonvirtual RunTimer/<init>()V"                               << endl;
        j_file << "\tputstatic        " << program_name << "/_runTimer LRunTimer;"      << endl;

        // Output all buffered instructions
        for (auto instruction : instruction_buffer)
        {
            j_file << instruction << endl;
        }
    }
    visit(context->compoundStatement());

    j_file << ".limit locals " << (context->num_local_vars+10) * 2                  << endl;
    j_file << ".limit stack " << context->stack_size                                << endl;
    j_file << ".end method" << endl;

    //return visitChildren(context); todo: double check return, nothing else has to be done
    return nullptr;
}

antlrcpp::Any Pass2Visitor::visitFunctionCall(Pcl2Parser::FunctionCallContext *context){
    print_debug_context(2, context, "visitFunctionCall");

    if (context->identifierList())
    {
        visit(context->identifierList());
    }


    j_file << TAB << "invokestatic " << program_name << "/";
    j_file << PassVisitor::function_definition_map[context->Identifier()->toString()] << endl;

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

    // Add a comment
    const string comment = "\t; " + context->getText();
    if (context->current_nesting_level == 1)
    {
        instruction_buffer.push_back(comment);
    }
    else
    {
        j_file << comment << endl;
    }

    // Visit right hand side expression first
    auto expression_result = visit(context->expression());

    string instruction;

    instruction += create_put_variable_instruction(program_name, context->Identifier()->toString(), context->type_letter) + "\n";

    // // Emit a field put instruction
    // instruction += "\tputstatic\t";
    // instruction += program_name;
    // instruction += "/";
    // instruction += context->Identifier()->toString();
    // instruction += " ";
    // instruction += context->type_letter;

    if (context->current_nesting_level == 1)
    {
        instruction_buffer.push_back(instruction);
    }
    else
    {
        j_file << instruction << endl;
    }

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

    string instruction = "";

    if (context->primaryExpression()->Identifier())
    {
        instruction += create_get_variable_instruction(program_name, context->primaryExpression()->Identifier()->getText(), context->type_letter);

        // instruction += "\t";
        // instruction += "getstatic";
        // instruction += "\t";
        // instruction += program_name;
        // instruction += "/";
        // instruction += context->primaryExpression()->Identifier()->getText();
        // instruction += " ";
        // instruction += context->type_letter;
    }
    else if (context->primaryExpression()->IntegerConstant() ||
            (context->primaryExpression()->FloatConstant()))
    {
        // Doubles need to be treated differently
        if (Predefined::double_type == context->type)
        {
            string double_value;

            // If integer constant add decimal
            if (context->primaryExpression()->IntegerConstant())
            {
                double_value += context->primaryExpression()->IntegerConstant()->getText();
                double_value += ".0";
            }
            else
            {
                double_value += context->primaryExpression()->FloatConstant()->getText();
            }

            instruction += "\t";
            instruction += "ldc2_w ";
            instruction += double_value;
        }
        else
        {
            instruction += "\t";
            instruction += "ldc ";
            instruction += context->primaryExpression()->IntegerConstant()->getText();
        }
    }

    instruction += "\n";

    cout << context->getText() << "****** current nesting level is " << context->primaryExpression()->current_nesting_level << endl;

    if (context->primaryExpression()->current_nesting_level == 1)
    {
        instruction_buffer.push_back(instruction);
    }
    else
    {
        j_file << instruction << endl;
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

    // @TODO : Clean up
    for (uint8_t i = 0; i < 2; i++)
    {
        visit(context->expression(i));
        TypeSpec * operand_type = context->expression(i)->type;
    
        // Type mismatches need to be converted
        if (context->type != operand_type)
        {
            if (context->type == Predefined::double_type)
            {
                if (operand_type == Predefined::int_type)
                {
                    j_file << TAB << "i2d" << endl;
                }
                else if (operand_type == Predefined::float_type)
                {
                    j_file << TAB << "f2d" << endl;
                }
            }
            else if (context->type == Predefined::float_type)
            {
                if (operand_type == Predefined::int_type)
                {
                    j_file << TAB << "i2f" << endl;
                }
                else if (operand_type == Predefined::double_type)
                {
                    j_file << TAB << "d2f" << endl;
                }
            }
            else if (context->type == Predefined::int_type)
            {
                if (operand_type == Predefined::float_type)
                {
                    j_file << TAB << "f2i" << endl;
                }
                else if (operand_type == Predefined::double_type)
                {
                    j_file << TAB << "d2i" << endl;
                }
            }
        }
    }

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

    // Visit both operands
    for (uint8_t i = 0; i < 2; i++)
    {
        visit(context->expression(i));
        // Doubles and floats need to be converted before jump comparison instruction
        if (Predefined::double_type == context->expression(i)->type)
        {
            j_file << TAB
                   << "d2i"
                   << endl;
        }
        else if (Predefined::float_type  == context->expression(i)->type)
        {
            j_file << TAB
                   << "f2i"
                   << endl;
        }
    }

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

antlrcpp::Any Pass2Visitor::visitJumpStatement(Pcl2Parser::JumpStatementContext *context){
    if( PassVisitor::current_function == "main"){
        // Emit the main program epilogue
        j_file                                                                          << endl;
        j_file << "\tgetstatic     " << program_name << "/_runTimer LRunTimer;"         << endl;
        j_file << "\tinvokevirtual RunTimer.printElapsedTime()V"                        << endl;

    }

    if (context->expression()) visit(context->expression());
    j_file  << TAB                                                                  ;
    if (context->expression()) j_file << context->expression()->type->to_string()[0];
    j_file << "return"                                                              << endl;
    j_file                                                                          << endl;
    return nullptr;
}

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

    j_file << endl 
           << "; "
           << context->getText()
           << endl;

    // Emit the iteration label
    j_file << context->conditionalExpression()->iteration_name 
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

antlrcpp::Any Pass2Visitor::visitIfElseStatement(Pcl2Parser::IfElseStatementContext *context)
{
    print_debug_context(2, context, "visitIfElseStatement");

    /**
     *  Top level if else statement node
     *  Visits children first to get the different branches emitted
     *  Then emit the final label that all branches will branch to
     */

    visitChildren(context);

    // Only increment scope_counter at the end of the entire statement
    const string end_label = "if_else_end_" + std::to_string(PassVisitor::scope_counter++);

    // Add label to branch to for exiting the loop
    j_file << end_label
           << ":"
           << endl
           << endl;

    return nullptr;
}

antlrcpp::Any Pass2Visitor::visitIfStatement(Pcl2Parser::IfStatementContext *context)
{
    print_debug_context(2, context, "visitIfStatement");

    /**
     *  Emit start of if label
     *  Visit children which will emit the instructions internal to the branch
     *  Emit a label for the end of if
     *  @note : If condition is true continues into the branch
     *          If condition is false, branch to next branch
     *          At the end of the inside of the branch, jumps to end of the entire if-else statement
     */

    j_file << "; "
           << context->getText()
           << endl;

    // Emit start label
    j_file << context->conditionalExpression()->iteration_name
           << ":"
           << endl;

    // Visit expression child first
    visit(context->conditionalExpression());

    // Visit children inside the if block
    visit(context->statement());

    j_file << TAB
           << "; Exit if-else statement"
           << endl
           << TAB
           << "goto "
           << "if_else_end_" + std::to_string(PassVisitor::scope_counter)
           << endl;

    // Emit end label
    j_file << context->conditionalExpression()->iteration_name
           << "_end"
           << ":"
           << endl
           << endl;

    return nullptr;
}

antlrcpp::Any Pass2Visitor::visitElseIfStatement(Pcl2Parser::ElseIfStatementContext *context)
{
    print_debug_context(2, context, "visitElseIfStatement");

    /**
     *  Emit start of else if label
     *  Visit children which will emit the instructions internal to the branch
     *  Emit a label for the end of else if
     *  @note : If condition is true continues into the branch
     *          If condition is false, branch to next branch
     *          At the end of the inside of the branch, jumps to end of the entire if-else statement
     */

    j_file << "; "
           << context->getText()
           << endl;

    // Emit start label
    j_file << context->conditionalExpression()->iteration_name
           << ":"
           << endl;

    // Visit expression child first
    visit(context->conditionalExpression());

    // Visit children inside the if block
    visit(context->statement());

    j_file << TAB
           << "; Exit if-else statement"
           << endl
           << TAB
           << "goto "
           << "if_else_end_" + std::to_string(PassVisitor::scope_counter)
           << endl;

    // Emit end label
    j_file << context->conditionalExpression()->iteration_name
           << "_end"
           << ":"
           << endl
           << endl;

    return nullptr;
}

antlrcpp::Any Pass2Visitor::visitElseStatement(Pcl2Parser::ElseStatementContext *context)
{
    print_debug_context(2, context, "visitElseStatement");

    /**
     *  Emit start of else label
     *  Visit children which will emit the instructions internal to the branch
     *  Emit a label for the end of else
     *  @note : If condition is true continues into the branch
     *          If condition is false, branch to next branch
     *          At the end of the inside of the branch, jumps to end of the entire if-else statement
     */

    j_file << "; "
           << context->getText()
           << endl;

    // Emit start label
    j_file << "else_"
           << std::to_string(scope_counter)
           << ":"
           << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitUnaryIncrementStatement(Pcl2Parser::UnaryIncrementStatementContext *context)
{
    print_debug_context(2, context, "visitUnaryIncrementStatement");

    /**
     *  Retrieve variable
     *  Load a constant one
     *  Emit an ADD instruction
     *  Write back variable
     */

    j_file << TAB
           << "; "
           << context->getText()
           << endl;

    j_file << create_get_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

    // // Get variable
    // j_file << TAB
    //        << "getstatic"
    //        << TAB
    //        << program_name
    //        << "/"
    //        << context->Identifier()->getText()
    //        << " "
    //        << context->type_letter
    //        << endl;

    // Load one
    j_file << TAB
           << "iconst_1"
           << endl;

    // ADD
    j_file << TAB
           << resolve_expression_instruction(context->type, "+")
           << endl;

    j_file << create_put_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

    // // Write back the variable
    // j_file << TAB
    //        << "putstatic"
    //        << TAB
    //        << program_name
    //        << "/"
    //        << context->Identifier()->getText()
    //        << " "
    //        << context->type_letter
    //        << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitUnaryDecrementStatement(Pcl2Parser::UnaryDecrementStatementContext *context)
{
    print_debug_context(2, context, "visitUnaryDecrementStatement");

    /**
     *  Retrieve variable
     *  Load a constant one
     *  Emit a SUB instruction
     *  Write back variable
     *  @note : First variable pushed onto stack will be the LHS of a sub operation
     */

    j_file << TAB
           << "; "
           << context->getText()
           << endl;

    j_file << create_get_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

    // // Get variable
    // j_file << TAB
    //        << "getstatic"
    //        << TAB
    //        << program_name
    //        << "/"
    //        << context->Identifier()->getText()
    //        << " "
    //        << context->type_letter
    //        << endl;

    // Load one @TODO : Clean up
    if (context->type == Predefined::double_type)
    {
        j_file << TAB
               << "dconst_1"
               << endl;
    }
    else if (context->type == Predefined::float_type)
    {
        j_file << TAB
               << "fconst_1"
               << endl;
    }
    if (context->type == Predefined::int_type)
    {
        j_file << TAB
               << "iconst_1"
               << endl;
    }

    // SUB
    j_file << TAB
           << resolve_expression_instruction(context->type, "-")
           << endl;

    j_file << create_put_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

    // // Write back the variable
    // j_file << TAB
    //        << "putstatic"
    //        << TAB
    //        << program_name
    //        << "/"
    //        << context->Identifier()->getText()
    //        << " "
    //        << context->type_letter
    //        << endl;

    return visitChildren(context);
}

antlrcpp::Any Pass2Visitor::visitUnarySquareStatement(Pcl2Parser::UnarySquareStatementContext *context)
{
    print_debug_context(2, context, "visitUnarySquareStatement");

    /**
     *  Retrieve variable twice
     *  Multiply them together = square
     *  Write back variable
     */

    j_file << TAB
           << "; "
           << context->getText()
           << endl;

    j_file << create_get_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

    // // Get variable twice
    // j_file << TAB
    //        << "getstatic"
    //        << TAB
    //        << program_name
    //        << "/"
    //        << context->Identifier()->getText()
    //        << " "
    //        << context->type_letter
    //        << endl;

    j_file << TAB
           << ((context->type == Predefined::double_type) ? ("dup2") : ("dup"))
           << endl;

    // Multiply
    j_file << TAB
           << resolve_expression_instruction(context->type, "*")
           << endl;

    j_file << create_put_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

    // // Write back the variable
    // j_file << TAB
    //        << "putstatic"
    //        << TAB
    //        << program_name
    //        << "/"
    //        << context->Identifier()->getText()
    //        << " "
    //        << context->type_letter
    //        << endl;

    return visitChildren(context);
}
