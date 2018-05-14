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

    vector <string> instruction_buffer;

    string resolve_expression_instruction(TypeSpec * type, string const & opr);

    void emit_symbol_table();

public:

    /// Constructor
    Pass2Visitor(const string fname, ofstream & j_file, const bool debug=false);

    /// Destructor
    virtual ~Pass2Visitor();

    antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context) override;
    antlrcpp::Any visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context) override;

    antlrcpp::Any visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context) override;
    antlrcpp::Any visitDeclaration(Pcl2Parser::DeclarationContext *context) override;
    antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context) override;

    antlrcpp::Any visitPrimExpr(Pcl2Parser::PrimExprContext *context) override;
    antlrcpp::Any visitMulDivExpr(Pcl2Parser::MulDivExprContext *context) override;
    antlrcpp::Any visitAddminExpr(Pcl2Parser::AddminExprContext *context) override;
    antlrcpp::Any visitBitExpr(Pcl2Parser::BitExprContext *context) override;

    antlrcpp::Any visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *context) override;
    antlrcpp::Any visitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext *context) override;
    antlrcpp::Any visitNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext *context) override;
    antlrcpp::Any visitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext *context) override;
    antlrcpp::Any visitParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext *context) override;

    antlrcpp::Any visitIterationStatement(Pcl2Parser::IterationStatementContext *context) override;
    antlrcpp::Any visitAssignmentStatement(Pcl2Parser::AssignmentStatementContext *context) override;

    antlrcpp::Any visitIfElseStatement(Pcl2Parser::IfElseStatementContext *context) override;
    antlrcpp::Any visitIfStatement(Pcl2Parser::IfStatementContext *context) override;
    antlrcpp::Any visitElseIfStatement(Pcl2Parser::ElseIfStatementContext *context) override;
    antlrcpp::Any visitElseStatement(Pcl2Parser::ElseStatementContext *context) override;

    antlrcpp::Any visitUnaryIncrementStatement(Pcl2Parser::UnaryIncrementStatementContext *context) override;
    antlrcpp::Any visitUnaryDecrementStatement(Pcl2Parser::UnaryDecrementStatementContext *context) override;
    antlrcpp::Any visitUnarySquareStatement(Pcl2Parser::UnarySquareStatementContext *context) override;

};

#endif /* PASS2VISITOR_H_ */
