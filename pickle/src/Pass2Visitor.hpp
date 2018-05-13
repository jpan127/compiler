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

    string resolve_expression_instruction(TypeSpec * type, const char opr);

public:

    /// Constructor
	Pass2Visitor(const string fname, ofstream & j_file, const bool debug=false);

    /// Destructor
    virtual ~Pass2Visitor();

    antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context);
    antlrcpp::Any visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context);

    antlrcpp::Any visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context);
    antlrcpp::Any visitDeclaration(Pcl2Parser::DeclarationContext *context);
    antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context);

    antlrcpp::Any visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *context);
    antlrcpp::Any visitPrimExpr(Pcl2Parser::PrimExprContext *context);
    antlrcpp::Any visitMulDivExpr(Pcl2Parser::MulDivExprContext *context);
    antlrcpp::Any visitAddminExpr(Pcl2Parser::AddminExprContext *context);
    antlrcpp::Any visitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext *context);
    antlrcpp::Any visitNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext *context);
    antlrcpp::Any visitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext *context);
    antlrcpp::Any visitParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext *context);

    antlrcpp::Any visitIterationStatement(Pcl2Parser::IterationStatementContext *context);
    antlrcpp::Any visitAssignmentStatement(Pcl2Parser::AssignmentStatementContext *context);
    antlrcpp::Any visitSelectionStatement(Pcl2Parser::SelectionStatementContext *context);

};

#endif /* PASS2VISITOR_H_ */
