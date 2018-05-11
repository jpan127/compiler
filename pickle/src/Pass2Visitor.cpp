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

Pass2Visitor::Pass2Visitor(const string fname, ostream& j_file, const bool debug) : program_name(fname), j_file(j_file), debug_flag(debug)
{
    /// Empty
}

Pass2Visitor::~Pass2Visitor()
{
    /// Empty
}

void Pass2Visitor::print_debug_context(antlr4::ParserRuleContext * context, const std::string & msg) const
{
    constexpr size_t longest_name = 35;
    const string space_padding(longest_name - msg.length(), ' ');
    if (debug_flag)
    {
        cout << "[PASS2][" << context->children.size() << "] " << msg << space_padding << " : " << context->getText() << endl;
    }
}

#if 1

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                   C O M P I L A T I O N                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * context) { print_debug_context(context, "visitFunctionDefinition"); return visitChildren(context); }

    antlrcpp::Any Pass2Visitor::visitCompilationUnit(Pcl2Parser::CompilationUnitContext * context)
    {
        print_debug_context(context, "visitCompilationUnit");
        return visitChildren(context);
    }
    
    antlrcpp::Any Pass2Visitor::visitTranslationUnit(Pcl2Parser::TranslationUnitContext * context)
    {
        print_debug_context(context, "visitTranslationUnit");

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
     *                   E X P R E S S I O N S                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext * context)               { print_debug_context(context, "visitPrimaryExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitPostfixExpression(Pcl2Parser::PostfixExpressionContext * context)               { print_debug_context(context, "visitPostfixExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitArgumentExpressionList(Pcl2Parser::ArgumentExpressionListContext * context)     { print_debug_context(context, "visitArgumentExpressionList"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitUnaryOperator(Pcl2Parser::UnaryOperatorContext * context)                       { print_debug_context(context, "visitUnaryOperator"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext * context) { print_debug_context(context, "visitMultiplicativeExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitShiftExpression(Pcl2Parser::ShiftExpressionContext * context)                   { print_debug_context(context, "visitShiftExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitRelationalExpression(Pcl2Parser::RelationalExpressionContext * context)         { print_debug_context(context, "visitRelationalExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitEqualityExpression(Pcl2Parser::EqualityExpressionContext * context)             { print_debug_context(context, "visitEqualityExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitAndExpression(Pcl2Parser::AndExpressionContext * context)                       { print_debug_context(context, "visitAndExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext * context)       { print_debug_context(context, "visitExclusiveOrExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext * context)       { print_debug_context(context, "visitInclusiveOrExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext * context)         { print_debug_context(context, "visitLogicalAndExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext * context)           { print_debug_context(context, "visitLogicalOrExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitConditionalExpression(Pcl2Parser::ConditionalExpressionContext * context)       { print_debug_context(context, "visitConditionalExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitAssignmentOperator(Pcl2Parser::AssignmentOperatorContext * context)             { print_debug_context(context, "visitAssignmentOperator"); return visitChildren(context); }

    antlrcpp::Any Pass2Visitor::visitAdditiveExpression(Pcl2Parser::AdditiveExpressionContext * context)
    { 
        print_debug_context(context, "visitAdditiveExpression"); 
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitUnaryExpression(Pcl2Parser::UnaryExpressionContext * context)
    { 
        print_debug_context(context, "visitUnaryExpression"); 
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitExpression(Pcl2Parser::ExpressionContext * context)
    {
        print_debug_context(context, "visitExpression");
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext * context)
    {
        print_debug_context(context, "visitAssignmentExpression");
        j_file << endl << "; " + context->getText() << endl << endl;
        return visitChildren(context);
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                     S T A T E M E N T S                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitStatement(Pcl2Parser::StatementContext * context)                     { print_debug_context(context, "visitStatement"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitCompoundStatement(Pcl2Parser::CompoundStatementContext * context)     { print_debug_context(context, "visitCompoundStatement"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitIterationStatement(Pcl2Parser::IterationStatementContext * context)   { print_debug_context(context, "visitIterationStatement"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitForCondition(Pcl2Parser::ForConditionContext * context)               { print_debug_context(context, "visitForCondition"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitForDeclaration(Pcl2Parser::ForDeclarationContext * context)           { print_debug_context(context, "visitForDeclaration"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitForExpression(Pcl2Parser::ForExpressionContext * context)             { print_debug_context(context, "visitForExpression"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitExpressionStatement(Pcl2Parser::ExpressionStatementContext * context) { print_debug_context(context, "visitExpressionStatement"); return visitChildren(context); }
    antlrcpp::Any Pass2Visitor::visitSelectionStatement(Pcl2Parser::SelectionStatementContext * context)   { print_debug_context(context, "visitSelectionStatement"); return visitChildren(context); }

    string Pass2Visitor::determine_type(TypeSpec * lhs)
    {
        string type = "?";

        //      if (current_type == (symtabimpl::Predefined::void_type)     ) { type = "V"; }
        // else if (current_type == (symtabimpl::Predefined::bool_type)     ) { type = "B"; }
        // else if (current_type == (symtabimpl::Predefined::char_type)     ) { type = "C"; }
        // else if (current_type == (symtabimpl::Predefined::short_type)    ) { type = "S"; }
        // else if (current_type == (symtabimpl::Predefined::int_type)      ) { type = "I"; }
        // else if (current_type == (symtabimpl::Predefined::long_type)     ) { type = "L"; }
        // else if (current_type == (symtabimpl::Predefined::float_type)    ) { type = "F"; }
        // else if (current_type == (symtabimpl::Predefined::double_type)   ) { type = "D"; }
        // else if (current_type == (symtabimpl::Predefined::signed_type)   ) { type = "I"; }
        // else if (current_type == (symtabimpl::Predefined::unsigned_type) ) { type = "I"; }
        // else if (current_type == (symtabimpl::Predefined::uint32_t_type) ) { type = "I"; }
        // else if (current_type == (symtabimpl::Predefined::int32_t_type)  ) { type = "I"; }

        return type;
    }

    // string Pass2Visitor::determine_type(TypeSpec * lhs, TypeSpec * rhs)
    // {

    // }

    string Pass2Visitor::opcode_to_instruction(const string opcode, const bool is_fpoint)
    {
        string instruction = "?";

             if (opcode == "+") { instruction = (is_fpoint) ? ("fadd") : ("iadd"); }
        else if (opcode == "-") { instruction = (is_fpoint) ? ("fsub") : ("isub"); }
        else if (opcode == "*") { instruction = (is_fpoint) ? ("fmul") : ("imul"); }
        else if (opcode == "/") { instruction = (is_fpoint) ? ("fdiv") : ("idiv"); }

        return instruction;
    }

#else

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
        j_file << "\tldc\t" << ctx->getText() << endl;
        return visitChildren(ctx);
    }

    antlrcpp::Any Pass2Visitor::visitFloatConst(Pcl2Parser::FloatConstContext *ctx)
    {
        j_file << "\tldc\t" << ctx->getText() << endl;
        return visitChildren(ctx);
    }

#endif
