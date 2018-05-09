#include <iostream>
#include <string>

#include "Pass2Visitor.h"
#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"
#include "wci/intermediate/symtabimpl/Predefined.h"

using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

Pass2Visitor::Pass2Visitor(ostream& j_file, const bool debug) : program_name(""), j_file(j_file), debug_flag(debug)
{
    /// Empty
}

Pass2Visitor::~Pass2Visitor()
{
    /// Empty
}

void Pass2Visitor::print_debug_context(const std::string & msg) const
{
    if (debug_flag)
    {
        cout << msg << endl;
    }
}

#if 0
    antlrcpp::Any Pass2Visitor::visitProgram(Pcl2Parser::ProgramContext *ctx)
    {
        auto value = visitChildren(ctx);
        //j_file.close();
        return value;
    }

    antlrcpp::Any Pass2Visitor::visitHeader(Pcl2Parser::HeaderContext *ctx)
    {
        program_name = ctx->IDENTIFIER()->toString();
        return visitChildren(ctx);
    }

    antlrcpp::Any Pass2Visitor::visitMainBlock(Pcl2Parser::MainBlockContext *ctx)
    {
        // Emit the main program header.
        j_file << endl;
        j_file << ".method public static main([Ljava/lang/String;)V" << endl;
        j_file << endl;
        j_file << "\tnew RunTimer" << endl;
        j_file << "\tdup" << endl;
        j_file << "\tinvokenonvirtual RunTimer/<init>()V" << endl;
        j_file << "\tputstatic        " << program_name
               << "/_runTimer LRunTimer;" << endl;
        j_file << "\tnew PascalTextIn" << endl;
        j_file << "\tdup" << endl;
        j_file << "\tinvokenonvirtual PascalTextIn/<init>()V" << endl;
        j_file << "\tputstatic        " + program_name
               << "/_standardIn LPascalTextIn;" << endl;

        auto value = visitChildren(ctx);

        // Emit the main program epilogue.
        j_file << endl;
        j_file << "\tgetstatic     " << program_name
                   << "/_runTimer LRunTimer;" << endl;
        j_file << "\tinvokevirtual RunTimer.printElapsedTime()V" << endl;
        j_file << endl;
        j_file << "\treturn" << endl;
        j_file << endl;
        j_file << ".limit locals 16" << endl;
        j_file << ".limit stack 16" << endl;
        j_file << ".end method" << endl;

        return value;
    }

    antlrcpp::Any Pass2Visitor::visitStmt(Pcl2Parser::StmtContext *ctx)
    {
        j_file << endl << "; " + ctx->getText() << endl << endl;

        return visitChildren(ctx);
    }

    antlrcpp::Any Pass2Visitor::visitAssignmentStmt(Pcl2Parser::AssignmentStmtContext *ctx)
    {
        auto value = visit(ctx->expr());

        string type_indicator =
                      (ctx->expr()->type == Predefined::integer_type) ? "I"
                    : (ctx->expr()->type == Predefined::real_type)    ? "F"
                    :                                                   "?";

        // Emit a field put instruction.
        j_file << "\tputstatic\t" << program_name
               << "/" << ctx->variable()->IDENTIFIER()->toString()
               << " " << type_indicator << endl;

        return value;
    }

    antlrcpp::Any Pass2Visitor::visitAddSubExpr(Pcl2Parser::AddSubExprContext *ctx)
    {
        auto value = visitChildren(ctx);

        TypeSpec *type1 = ctx->expr(0)->type;
        TypeSpec *type2 = ctx->expr(1)->type;

        bool integer_mode =    (type1 == Predefined::integer_type)
                            && (type2 == Predefined::integer_type);
        bool real_mode    =    (type1 == Predefined::real_type)
                            && (type2 == Predefined::real_type);

        string op = ctx->addSubOp()->getText();
        string opcode;

        if (op == "+")
        {
            opcode = integer_mode ? "iadd"
                   : real_mode    ? "fadd"
                   :                "????";
        }
        else
        {
            opcode = integer_mode ? "isub"
                   : real_mode    ? "fsub"
                   :                "????";
        }

        // Emit an add or subtract instruction.
        j_file << "\t" << opcode << endl;

        return value;
    }

    antlrcpp::Any Pass2Visitor::visitMulDivExpr(Pcl2Parser::MulDivExprContext *ctx)
    {
        auto value = visitChildren(ctx);

        TypeSpec *type1 = ctx->expr(0)->type;
        TypeSpec *type2 = ctx->expr(1)->type;

        bool integer_mode =    (type1 == Predefined::integer_type)
                            && (type2 == Predefined::integer_type);
        bool real_mode    =    (type1 == Predefined::real_type)
                            && (type2 == Predefined::real_type);

        string op = ctx->mulDivOp()->getText();
        string opcode;

        if (op == "*")
        {
            opcode = integer_mode ? "imul"
                   : real_mode    ? "fmul"
                   :                "????";
        }
        else
        {
            opcode = integer_mode ? "idpv"
                   : real_mode    ? "fdiv"
                   :                "????";
        }

        // Emit a multiply or divide instruction.
        j_file << "\t" << opcode << endl;

        return value;
    }

    antlrcpp::Any Pass2Visitor::visitVariableExpr(Pcl2Parser::VariableExprContext *ctx)
    {
        string variable_name = ctx->variable()->IDENTIFIER()->toString();
        TypeSpec *type = ctx->type;

        string type_indicator = (type == Predefined::integer_type) ? "I"
                              : (type == Predefined::real_type)    ? "F"
                              :                                      "?";

        // Emit a field get instruction.
        j_file << "\tgetstatic\t" << program_name
               << "/" << variable_name << " " << type_indicator << endl;

        return visitChildren(ctx);
    }

    antlrcpp::Any Pass2Visitor::visitSignedNumber(Pcl2Parser::SignedNumberContext *ctx)
    {
        auto value = visitChildren(ctx);
        TypeSpec *type = ctx->number()->type;

        if (ctx->sign()->children[0] == ctx->sign()->SUB_OP())
        {
            string opcode = (type == Predefined::integer_type) ? "ineg"
                          : (type == Predefined::real_type)    ? "fneg"
                          :                                      "?neg";

            // Emit a negate instruction.
            j_file << "\t" << opcode << endl;
        }

        return value;
    }

    antlrcpp::Any Pass2Visitor::visitIntegerConst(Pcl2Parser::IntegerConstContext *ctx)
    {
        // Emit a load constant instruction.
        j_file << "\tldc\t" << ctx->getText() << endl;

        return visitChildren(ctx);
    }

    antlrcpp::Any Pass2Visitor::visitFloatConst(Pcl2Parser::FloatConstContext *ctx)
    {
        // Emit a load constant instruction.
        j_file << "\tldc\t" << ctx->getText() << endl;

        return visitChildren(ctx);
    }
#else

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                   C O M P I L A T I O N                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitCompilationUnit(Pcl2Parser::CompilationUnitContext * context)
    {
        print_debug_context("[PASS2] visitCompilationUnit: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitTranslationUnit(Pcl2Parser::TranslationUnitContext * context)
    {
        print_debug_context("[PASS2] visitTranslationUnit: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * context)
    {
        print_debug_context("[PASS2] visitFunctionDefinition: " + context->getText());
        return visitChildren(context);
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                   E X P R E S S I O N S                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext * context)
    {
        print_debug_context("[PASS2] visitPrimaryExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitPostfixExpression(Pcl2Parser::PostfixExpressionContext * context)
    {
        print_debug_context("[PASS2] visitPostfixExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitArgumentExpressionList(Pcl2Parser::ArgumentExpressionListContext * context)
    {
        print_debug_context("[PASS2] visitArgumentExpressionList: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitUnaryExpression(Pcl2Parser::UnaryExpressionContext * context)
    {
        print_debug_context("[PASS2] visitUnaryExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitUnaryOperator(Pcl2Parser::UnaryOperatorContext * context)
    {
        print_debug_context("[PASS2] visitUnaryOperator: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext * context)
    {
        print_debug_context("[PASS2] visitMultiplicativeExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitAdditiveExpression(Pcl2Parser::AdditiveExpressionContext * context)
    {
        print_debug_context("[PASS2] visitAdditiveExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitShiftExpression(Pcl2Parser::ShiftExpressionContext * context)
    {
        print_debug_context("[PASS2] visitShiftExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitRelationalExpression(Pcl2Parser::RelationalExpressionContext * context)
    {
        print_debug_context("[PASS2] visitRelationalExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitEqualityExpression(Pcl2Parser::EqualityExpressionContext * context)
    {
        print_debug_context("[PASS2] visitEqualityExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitAndExpression(Pcl2Parser::AndExpressionContext * context)
    {
        print_debug_context("[PASS2] visitAndExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext * context)
    {
        print_debug_context("[PASS2] visitExclusiveOrExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext * context)
    {
        print_debug_context("[PASS2] visitInclusiveOrExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext * context)
    {
        print_debug_context("[PASS2] visitLogicalAndExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext * context)
    {
        print_debug_context("[PASS2] visitLogicalOrExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitConditionalExpression(Pcl2Parser::ConditionalExpressionContext * context)
    {
        print_debug_context("[PASS2] visitConditionalExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext * context)
    {
        print_debug_context("[PASS2] visitAssignmentExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitAssignmentOperator(Pcl2Parser::AssignmentOperatorContext * context)
    {
        print_debug_context("[PASS2] visitAssignmentOperator: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitExpression(Pcl2Parser::ExpressionContext * context)
    {
        print_debug_context("[PASS2] visitExpression: " + context->getText());
        return visitChildren(context);
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                     S T A T E M E N T S                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitStatement(Pcl2Parser::StatementContext * context)
    {
        print_debug_context("[PASS2] visitStatement: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitCompoundStatement(Pcl2Parser::CompoundStatementContext * context)
    {
        print_debug_context("[PASS2] visitCompoundStatement: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitIterationStatement(Pcl2Parser::IterationStatementContext * context)
    {
        print_debug_context("[PASS2] visitIterationStatement: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitForCondition(Pcl2Parser::ForConditionContext * context)
    {
        print_debug_context("[PASS2] visitForCondition: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitForDeclaration(Pcl2Parser::ForDeclarationContext * context)
    {
        print_debug_context("[PASS2] visitForDeclaration: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitForExpression(Pcl2Parser::ForExpressionContext * context)
    {
        print_debug_context("[PASS2] visitForExpression: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitInitializer(Pcl2Parser::InitializerContext * context)
    {
        print_debug_context("[PASS2] visitInitializer: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitExpressionStatement(Pcl2Parser::ExpressionStatementContext * context)
    {
        print_debug_context("[PASS2] visitExpressionStatement: " + context->getText());
        return visitChildren(context);
    }
    antlrcpp::Any Pass2Visitor::visitSelectionStatement(Pcl2Parser::SelectionStatementContext * context)
    {
        print_debug_context("[PASS2] visitSelectionStatement: " + context->getText());
        return visitChildren(context);
    }

#endif
