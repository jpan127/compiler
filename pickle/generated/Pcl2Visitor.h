
#include "wci/intermediate/symtab.h"
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from grammars/Pcl2.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "Pcl2Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by Pcl2Parser.
 */
class  Pcl2Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by Pcl2Parser.
   */
    virtual antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context) = 0;

    virtual antlrcpp::Any visitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(Pcl2Parser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(Pcl2Parser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(Pcl2Parser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitFunctionReturn(Pcl2Parser::FunctionReturnContext *context) = 0;

    virtual antlrcpp::Any visitJumpStatement(Pcl2Parser::JumpStatementContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(Pcl2Parser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(Pcl2Parser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockItemList(Pcl2Parser::BlockItemListContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(Pcl2Parser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitStatement(Pcl2Parser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitUnaryIncrementStatement(Pcl2Parser::UnaryIncrementStatementContext *context) = 0;

    virtual antlrcpp::Any visitUnaryDecrementStatement(Pcl2Parser::UnaryDecrementStatementContext *context) = 0;

    virtual antlrcpp::Any visitUnarySquareStatement(Pcl2Parser::UnarySquareStatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(Pcl2Parser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(Pcl2Parser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitSelectionStatement(Pcl2Parser::SelectionStatementContext *context) = 0;

    virtual antlrcpp::Any visitIterationStatement(Pcl2Parser::IterationStatementContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBitExpr(Pcl2Parser::BitExprContext *context) = 0;

    virtual antlrcpp::Any visitPrimExpr(Pcl2Parser::PrimExprContext *context) = 0;

    virtual antlrcpp::Any visitMulDivExpr(Pcl2Parser::MulDivExprContext *context) = 0;

    virtual antlrcpp::Any visitAddminExpr(Pcl2Parser::AddminExprContext *context) = 0;

    virtual antlrcpp::Any visitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext *context) = 0;

    virtual antlrcpp::Any visitNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext *context) = 0;

    virtual antlrcpp::Any visitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitParameterTypeList(Pcl2Parser::ParameterTypeListContext *context) = 0;


};

