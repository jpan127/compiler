#pragma once

#include "PassVisitor.hpp"



namespace backend
{

    class Pass2Visitor : public PassVisitor, public CmmBaseVisitor
    {

    public:

        /// Constructor
        Pass2Visitor(const std::string fname, std::ofstream & j_file, JasminEmitter & j_emitter, const bool debug=false);

        /// Destructor
        virtual ~Pass2Visitor();

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
        antlrcpp::Any visitFunctionCall(CmmParser::FunctionCallContext *context) override;
        antlrcpp::Any visitFunctionReturn(CmmParser::FunctionReturnContext *context) override;
        /// @ }

        /// @ { Statements
        antlrcpp::Any visitIfElseStatement(CmmParser::IfElseStatementContext *context) override;
        antlrcpp::Any visitIfStatement(CmmParser::IfStatementContext *context) override;
        antlrcpp::Any visitElseIfStatement(CmmParser::ElseIfStatementContext *context) override;
        antlrcpp::Any visitElseStatement(CmmParser::ElseStatementContext *context) override;
        antlrcpp::Any visitIterationStatement(CmmParser::IterationStatementContext *context) override;
        antlrcpp::Any visitAssignmentStatement(CmmParser::AssignmentStatementContext * context) override;
        antlrcpp::Any visitJumpStatement(CmmParser::JumpStatementContext *ctx) override;
        antlrcpp::Any visitUnaryIncrementStatement(CmmParser::UnaryIncrementStatementContext *context) override;
        antlrcpp::Any visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context) override;
        antlrcpp::Any visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context) override;
        /// @ }

        /// @ { Expressions
        antlrcpp::Any visitMulDivExpr(CmmParser::MulDivExprContext *context) override;
        antlrcpp::Any visitAddminExpr(CmmParser::AddminExprContext *context) override;
        antlrcpp::Any visitPrimExpr(CmmParser::PrimExprContext *context) override;
        antlrcpp::Any visitBitExpr(CmmParser::BitExprContext *context) override;
        antlrcpp::Any visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext * context) override;
        antlrcpp::Any visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext * context) override;
        antlrcpp::Any visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context) override;
        antlrcpp::Any visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context) override;
        antlrcpp::Any visitAssignmentExpression(CmmParser::AssignmentExpressionContext *context) override;
        /// @ }

    private:

        /// Name of the program under compilation
        std::string program_name;

        /// Flag for print debug messages or not
        const bool debug_flag;

        /// Stores the current function name
        std::string current_function = "global";

        /// @note : Currently only used for global expressions
        std::vector <backend::string_JasminEmitter_FUNCT> instruction_buffer;

        /// Responsible for handling the details of the code generation
        JasminEmitter & j_emitter;

        /**
         *  Emits the appropriate arithmetic instruction
         *  @param type : Type of the current node
         *  @param opr  : Operator for the current expression
         */
        void emit_expression_instruction(const backend::TypeSpecifier & type, const std::string & opr);

        /// Emits all the symbols to be printed at the end of the program
        void emit_symbol_table();

        /**
         *  Helper for all expression nodes
         *  @param context       : Context object of the current node
         *  @param expressions   : The various expression children of the current expression node
         *  @param expr_operator : Operator of the current expression
         */
        void visit_expression(CmmParser::ExpressionContext * context,
            const std::vector <CmmParser::ExpressionContext *> & expressions,
            const std::string & expr_operator);

        /**
         *  Helper for all unary statement nodes
         *  @param context      : Context object of the current node
         *  @param identifier   : Name of the variable
         *  @param opr          : Operator of the unary statement
         *  @param is_duplicate : Some unary statements require a duplicate expression
         */
        void visit_unary_statement(CmmParser::UnaryStatementContext * context,
            const std::string & identifier,
            const std::string & opr,
            const bool is_duplicate);

        /**
         *  Determines if a type conversion is necessary, and if so, emit
         *  @param start : The type of the variable to convert from
         *  @param end   : The type of the variable to convert to
         */
        void convert_if_necessary(const backend::TypeSpecifier & start, const backend::TypeSpecifier & end);

    };

} /// backend
