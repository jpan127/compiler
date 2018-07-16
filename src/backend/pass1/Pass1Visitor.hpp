#pragma once

#include "PassVisitor.hpp"
#include "SymbolTableStack.hpp"
#include "logger.hpp"



namespace backend
{

    class Pass1Visitor : public PassVisitor, public CmmBaseVisitor
    {

    public:

        /// Constructor
        Pass1Visitor(const std::string fname,
            std::ofstream & j_file,
            JasminEmitter & j_emitter,
            SpeedLoggerPtr logger);

        /// Destructor
        ~Pass1Visitor() { }

        /// @ { Common
        antlrcpp::Any visitCompilationUnit(CmmParser::CompilationUnitContext *context) override;
        antlrcpp::Any visitTranslationUnit(CmmParser::TranslationUnitContext *context) override;
        antlrcpp::Any visitTypeSpecifier(CmmParser::TypeSpecifierContext *context) override;
        /// @ }

        /// @ { Declarations
        antlrcpp::Any visitDeclaration(CmmParser::DeclarationContext *context) override;
        /// @ }

        /// @ { Functions
        antlrcpp::Any visitFunctionParameterList(CmmParser::FunctionParameterListContext *context) override;
        antlrcpp::Any visitFunctionDefinition(CmmParser::FunctionDefinitionContext *context) override;
        /// @ }

        /// @ { Statements
        antlrcpp::Any visitCompoundStatement(CmmParser::CompoundStatementContext *context) override;
        antlrcpp::Any visitIfElseStatement(CmmParser::IfElseStatementContext *context) override;
        antlrcpp::Any visitIfStatement(CmmParser::IfStatementContext *context) override;
        antlrcpp::Any visitElseIfStatement(CmmParser::ElseIfStatementContext *context) override;
        antlrcpp::Any visitElseStatement(CmmParser::ElseStatementContext *context) override;
        antlrcpp::Any visitIterationStatement(CmmParser::IterationStatementContext *context) override;
        antlrcpp::Any visitAssignmentStatement(CmmParser::AssignmentStatementContext * context) override;
        antlrcpp::Any visitUnaryIncrementStatement(CmmParser::UnaryIncrementStatementContext *context) override;
        antlrcpp::Any visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context) override;
        antlrcpp::Any visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context) override;
        antlrcpp::Any visitPrintfStatement(CmmParser::PrintfStatementContext *context) override;
        /// @ }

        /// @ { Expressions
        antlrcpp::Any visitMulDivExpr(CmmParser::MulDivExprContext *context) override;
        antlrcpp::Any visitAddminExpr(CmmParser::AddminExprContext *context) override;
        antlrcpp::Any visitBitExpr(CmmParser::BitExprContext *context) override;
        antlrcpp::Any visitPrimExpr(CmmParser::PrimExprContext *context) override;
        antlrcpp::Any visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext * context) override;
        antlrcpp::Any visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext * context) override;
        antlrcpp::Any visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context) override;
        antlrcpp::Any visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context) override;
        antlrcpp::Any visitAssignmentExpression(CmmParser::AssignmentExpressionContext *context) override;
        /// @ }

    private:

        /// Name of current program
        const std::string program_name;

        /// Symbol Table Stack
        intermediate::SymbolTableStack symbol_table_stack;

        /// Responsible for handling the details of the code generation
        JasminEmitter & j_emitter;

        /// Logger
        SpeedLoggerPtr logger;

        /**
         *  Looks up the symbol type of context->Identifier()->getText()
         *  Stores [context->type] and [context->type_letter]
         *  @param context : The context object to look up and modify
         *  @throws        : InvalidType
         */
        void lookup_symbol_type(const std::string & variable, backend::TypeSpecifier & type, char & type_letter);

        /**
         *  Visits a generic expression node
         *  Sets the expression operator, visits children, and resolves expression type
         *  @param context      : The context object to look up and modify
         *  @param operator_set : The set of operators that are allowed in the current context
         *  @param is_bit_expr  : Flag to show that the node is a bitExpr expression node, which checks for disallowed float operands
         */
        void visit_expression(CmmParser::ExpressionContext * context,
            const std::set <std::string> & operator_set,
            const bool is_bit_expr,
            std::string & expr_operator,
            const std::string opr,
            const backend::TypeSpecifier & lhs_type,
            const backend::TypeSpecifier & rhs_type);
    };

} /// backend
