
#include "wci/intermediate/symtab.h"
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from grammars/Pcl2.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "Pcl2Parser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by Pcl2Parser.
 */
class  Pcl2Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompilationUnit(Pcl2Parser::CompilationUnitContext *ctx) = 0;
  virtual void exitCompilationUnit(Pcl2Parser::CompilationUnitContext *ctx) = 0;

  virtual void enterTranslationUnit(Pcl2Parser::TranslationUnitContext *ctx) = 0;
  virtual void exitTranslationUnit(Pcl2Parser::TranslationUnitContext *ctx) = 0;

  virtual void enterExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *ctx) = 0;
  virtual void exitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *ctx) = 0;

  virtual void enterFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterFunctionDeclaration(Pcl2Parser::FunctionDeclarationContext *ctx) = 0;
  virtual void exitFunctionDeclaration(Pcl2Parser::FunctionDeclarationContext *ctx) = 0;

  virtual void enterDeclaration(Pcl2Parser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(Pcl2Parser::DeclarationContext *ctx) = 0;

  virtual void enterTypeSpecifier(Pcl2Parser::TypeSpecifierContext *ctx) = 0;
  virtual void exitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *ctx) = 0;

  virtual void enterFunctionCall(Pcl2Parser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(Pcl2Parser::FunctionCallContext *ctx) = 0;

  virtual void enterFunctionReturn(Pcl2Parser::FunctionReturnContext *ctx) = 0;
  virtual void exitFunctionReturn(Pcl2Parser::FunctionReturnContext *ctx) = 0;

  virtual void enterJumpStatement(Pcl2Parser::JumpStatementContext *ctx) = 0;
  virtual void exitJumpStatement(Pcl2Parser::JumpStatementContext *ctx) = 0;

  virtual void enterIdentifierList(Pcl2Parser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(Pcl2Parser::IdentifierListContext *ctx) = 0;

  virtual void enterCompoundStatement(Pcl2Parser::CompoundStatementContext *ctx) = 0;
  virtual void exitCompoundStatement(Pcl2Parser::CompoundStatementContext *ctx) = 0;

  virtual void enterBlockItemList(Pcl2Parser::BlockItemListContext *ctx) = 0;
  virtual void exitBlockItemList(Pcl2Parser::BlockItemListContext *ctx) = 0;

  virtual void enterBlockItem(Pcl2Parser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(Pcl2Parser::BlockItemContext *ctx) = 0;

  virtual void enterStatement(Pcl2Parser::StatementContext *ctx) = 0;
  virtual void exitStatement(Pcl2Parser::StatementContext *ctx) = 0;

  virtual void enterAssignmentStatement(Pcl2Parser::AssignmentStatementContext *ctx) = 0;
  virtual void exitAssignmentStatement(Pcl2Parser::AssignmentStatementContext *ctx) = 0;

  virtual void enterExpressionStatement(Pcl2Parser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(Pcl2Parser::ExpressionStatementContext *ctx) = 0;

  virtual void enterSelectionStatement(Pcl2Parser::SelectionStatementContext *ctx) = 0;
  virtual void exitSelectionStatement(Pcl2Parser::SelectionStatementContext *ctx) = 0;

  virtual void enterIterationStatement(Pcl2Parser::IterationStatementContext *ctx) = 0;
  virtual void exitIterationStatement(Pcl2Parser::IterationStatementContext *ctx) = 0;

  virtual void enterPrimaryExpression(Pcl2Parser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterPrimExpr(Pcl2Parser::PrimExprContext *ctx) = 0;
  virtual void exitPrimExpr(Pcl2Parser::PrimExprContext *ctx) = 0;

  virtual void enterMulDivExpr(Pcl2Parser::MulDivExprContext *ctx) = 0;
  virtual void exitMulDivExpr(Pcl2Parser::MulDivExprContext *ctx) = 0;

  virtual void enterAddminExpr(Pcl2Parser::AddminExprContext *ctx) = 0;
  virtual void exitAddminExpr(Pcl2Parser::AddminExprContext *ctx) = 0;

  virtual void enterBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext *ctx) = 0;
  virtual void exitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext *ctx) = 0;

  virtual void enterNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext *ctx) = 0;
  virtual void exitNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext *ctx) = 0;

  virtual void enterConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext *ctx) = 0;
  virtual void exitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext *ctx) = 0;

  virtual void enterParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext *ctx) = 0;
  virtual void exitParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext *ctx) = 0;

  virtual void enterAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterParameterTypeList(Pcl2Parser::ParameterTypeListContext *ctx) = 0;
  virtual void exitParameterTypeList(Pcl2Parser::ParameterTypeListContext *ctx) = 0;


};

