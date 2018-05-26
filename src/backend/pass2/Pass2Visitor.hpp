#pragma once

#include "PassVisitor.hpp"



namespace backend
{

    class Pass2Visitor : public PassVisitor, public CmmBaseVisitor
    {

    public:

        /// Constructor
        Pass2Visitor(const std::string fname, std::ofstream & j_file, const bool debug=false);

        /// Destructor
        virtual ~Pass2Visitor();

        antlrcpp::Any visitCompilationUnit(CmmParser::CompilationUnitContext *context) override;
        antlrcpp::Any visitTranslationUnit(CmmParser::TranslationUnitContext *context) override;

        antlrcpp::Any visitTypeSpecifier(CmmParser::TypeSpecifierContext *context) override;
        antlrcpp::Any visitDeclaration(CmmParser::DeclarationContext *context) override;
        antlrcpp::Any visitFunctionDefinition(CmmParser::FunctionDefinitionContext *context) override;
        antlrcpp::Any visitFunctionCall(CmmParser::FunctionCallContext *context) override;
        antlrcpp::Any visitFunctionDeclaration(CmmParser::FunctionDeclarationContext *context) override;
        antlrcpp::Any visitFunctionReturn(CmmParser::FunctionReturnContext *context) override;

        antlrcpp::Any visitPrimExpr(CmmParser::PrimExprContext *context) override;
        antlrcpp::Any visitMulDivExpr(CmmParser::MulDivExprContext *context) override;
        antlrcpp::Any visitAddminExpr(CmmParser::AddminExprContext *context) override;
        antlrcpp::Any visitBitExpr(CmmParser::BitExprContext *context) override;

        antlrcpp::Any visitAssignmentExpression(CmmParser::AssignmentExpressionContext *context) override;
        antlrcpp::Any visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext *context) override;
        antlrcpp::Any visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext *context) override;
        antlrcpp::Any visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context) override;
        antlrcpp::Any visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context) override;
        antlrcpp::Any visitJumpStatement(CmmParser::JumpStatementContext *ctx) override;

        antlrcpp::Any visitIterationStatement(CmmParser::IterationStatementContext *context) override;
        antlrcpp::Any visitAssignmentStatement(CmmParser::AssignmentStatementContext *context) override;

        antlrcpp::Any visitIfElseStatement(CmmParser::IfElseStatementContext *context) override;
        antlrcpp::Any visitIfStatement(CmmParser::IfStatementContext *context) override;
        antlrcpp::Any visitElseIfStatement(CmmParser::ElseIfStatementContext *context) override;
        antlrcpp::Any visitElseStatement(CmmParser::ElseStatementContext *context) override;

        antlrcpp::Any visitUnaryIncrementStatement(CmmParser::UnaryIncrementStatementContext *context) override;
        antlrcpp::Any visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context) override;
        antlrcpp::Any visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context) override;

    private:

        std::string program_name;

        std::ofstream & j_file;

        const bool debug_flag;

        std::vector <std::string> instruction_buffer;

        std::string resolve_expression_instruction(const backend::TypeSpecifier & type, std::string const & opr);

        void emit_symbol_table();

    };

} /// backend