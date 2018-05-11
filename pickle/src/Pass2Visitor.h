#ifndef PASS2VISITOR_H_
#define PASS2VISITOR_H_

#include <iostream>
#include <string>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "Pcl2BaseVisitor.h"
#include "antlr4-runtime.h"
#include "Pcl2Visitor.h"

using namespace wci;
using namespace wci::intermediate;

class Pass2Visitor : public Pcl2BaseVisitor
{
private:

	string program_name;

	ostream & j_file;

    const bool debug_flag;

    void print_debug_context(antlr4::ParserRuleContext * context, const std::string & msg) const;

    string opcode_to_instruction(const string opcode, const bool is_fpoint);

    string determine_type(TypeSpec * lhs);

public:

    /// Constructor
	Pass2Visitor(const string fname, ostream& j_file, const bool debug=false);

    /// Destructor
    virtual ~Pass2Visitor();

    /// @ { Compilation Unit
    antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context) override;
    antlrcpp::Any visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context) override;
    antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context) override;
    /// @ }

    /// @ { Expressions
    antlrcpp::Any visitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext * context) override;
    antlrcpp::Any visitPostfixExpression(Pcl2Parser::PostfixExpressionContext * context) override;
    antlrcpp::Any visitArgumentExpressionList(Pcl2Parser::ArgumentExpressionListContext * context) override;
    antlrcpp::Any visitUnaryExpression(Pcl2Parser::UnaryExpressionContext * context) override;
    antlrcpp::Any visitUnaryOperator(Pcl2Parser::UnaryOperatorContext * context) override;
    antlrcpp::Any visitMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext * context) override;
    antlrcpp::Any visitAdditiveExpression(Pcl2Parser::AdditiveExpressionContext * context) override;
    antlrcpp::Any visitShiftExpression(Pcl2Parser::ShiftExpressionContext * context) override;
    antlrcpp::Any visitRelationalExpression(Pcl2Parser::RelationalExpressionContext * context) override;
    antlrcpp::Any visitEqualityExpression(Pcl2Parser::EqualityExpressionContext * context) override;
    antlrcpp::Any visitAndExpression(Pcl2Parser::AndExpressionContext * context) override;
    antlrcpp::Any visitExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext * context) override;
    antlrcpp::Any visitInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext * context) override;
    antlrcpp::Any visitLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext * context) override;
    antlrcpp::Any visitLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext * context) override;
    antlrcpp::Any visitConditionalExpression(Pcl2Parser::ConditionalExpressionContext * context) override;
    antlrcpp::Any visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext * context) override;
    antlrcpp::Any visitAssignmentOperator(Pcl2Parser::AssignmentOperatorContext * context) override;
    antlrcpp::Any visitExpression(Pcl2Parser::ExpressionContext * context) override;
    /// @ }

    /// @ { Statements
    antlrcpp::Any visitStatement(Pcl2Parser::StatementContext *context) override;
    antlrcpp::Any visitCompoundStatement(Pcl2Parser::CompoundStatementContext *context) override;
    antlrcpp::Any visitIterationStatement(Pcl2Parser::IterationStatementContext *context) override;
    antlrcpp::Any visitForCondition(Pcl2Parser::ForConditionContext *context) override;
    antlrcpp::Any visitForDeclaration(Pcl2Parser::ForDeclarationContext *context) override;
    antlrcpp::Any visitForExpression(Pcl2Parser::ForExpressionContext *context) override;
    antlrcpp::Any visitExpressionStatement(Pcl2Parser::ExpressionStatementContext *context) override;
    antlrcpp::Any visitSelectionStatement(Pcl2Parser::SelectionStatementContext *context) override;
    /// @ }
};

#endif /* PASS2VISITOR_H_ */
