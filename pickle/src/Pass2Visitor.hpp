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
#include "PassVisitor.hpp"

using namespace wci;
using namespace wci::intermediate;

class Pass2Visitor : public PassVisitor, public Pcl2BaseVisitor
{
private:

	string program_name;

	ofstream & j_file;

    const bool debug_flag;

    string resolve_expression_instruction(TypeSpec * type, char opr);

    uint64_t scope_counter;

public:

    /// Constructor
	Pass2Visitor(string fname, ofstream & j_file, bool debug=false);

    /// Destructor
	~Pass2Visitor() override;

    antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context) override;
    antlrcpp::Any visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context) override;

    antlrcpp::Any visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context) override;
    antlrcpp::Any visitDeclaration(Pcl2Parser::DeclarationContext *context) override;
    antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context) override;

    antlrcpp::Any visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *context) override;
    antlrcpp::Any visitPrimExpr(Pcl2Parser::PrimExprContext *context) override;
    antlrcpp::Any visitMulDivExpr(Pcl2Parser::MulDivExprContext *context) override;
    antlrcpp::Any visitAddminExpr(Pcl2Parser::AddminExprContext *context) override;

    antlrcpp::Any visitIterationStatement(Pcl2Parser::IterationStatementContext *context) override;

    antlrcpp::Any visitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext *context) override;
    antlrcpp::Any visitNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext *context) override;
    antlrcpp::Any visitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext *context) override;
    antlrcpp::Any visitParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext *context) override;

    // antlrcpp::Any visitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *context);
    // antlrcpp::Any visitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext *context);
    // antlrcpp::Any visitFunctionCall(Pcl2Parser::FunctionCallContext *context);
    // antlrcpp::Any visitFunctionReturn(Pcl2Parser::FunctionReturnContext *context);
    // antlrcpp::Any visitIdentifierList(Pcl2Parser::IdentifierListContext *context);
    // antlrcpp::Any visitCompoundStatement(Pcl2Parser::CompoundStatementContext *context);
    // antlrcpp::Any visitBlockItemList(Pcl2Parser::BlockItemListContext *context);
    // antlrcpp::Any visitBlockItem(Pcl2Parser::BlockItemContext *context);
    // antlrcpp::Any visitStatement(Pcl2Parser::StatementContext *context);
    // antlrcpp::Any visitAssignmentStatement(Pcl2Parser::AssignmentStatementContext *context);
    // antlrcpp::Any visitExpressionStatement(Pcl2Parser::ExpressionStatementContext *context);
    // antlrcpp::Any visitSelectionStatement(Pcl2Parser::SelectionStatementContext *context);
    // antlrcpp::Any visitIterationStatement(Pcl2Parser::IterationStatementContext *context);
    // antlrcpp::Any visitConditionalExpression(Pcl2Parser::ConditionalExpressionContext *context);
    // antlrcpp::Any visitParamaterTypeList(Pcl2Parser::ParamaterTypeListContext *context);

};

#endif /* PASS2VISITOR_H_ */
