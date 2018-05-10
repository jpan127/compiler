
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

  virtual void enterDeclaration(Pcl2Parser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(Pcl2Parser::DeclarationContext *ctx) = 0;

  virtual void enterDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *ctx) = 0;
  virtual void exitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *ctx) = 0;

  virtual void enterDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *ctx) = 0;
  virtual void exitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *ctx) = 0;

  virtual void enterInitDeclaratorList(Pcl2Parser::InitDeclaratorListContext *ctx) = 0;
  virtual void exitInitDeclaratorList(Pcl2Parser::InitDeclaratorListContext *ctx) = 0;

  virtual void enterInitDeclarator(Pcl2Parser::InitDeclaratorContext *ctx) = 0;
  virtual void exitInitDeclarator(Pcl2Parser::InitDeclaratorContext *ctx) = 0;

  virtual void enterInitializer(Pcl2Parser::InitializerContext *ctx) = 0;
  virtual void exitInitializer(Pcl2Parser::InitializerContext *ctx) = 0;

  virtual void enterVoidType(Pcl2Parser::VoidTypeContext *ctx) = 0;
  virtual void exitVoidType(Pcl2Parser::VoidTypeContext *ctx) = 0;

  virtual void enterBoolType(Pcl2Parser::BoolTypeContext *ctx) = 0;
  virtual void exitBoolType(Pcl2Parser::BoolTypeContext *ctx) = 0;

  virtual void enterCharType(Pcl2Parser::CharTypeContext *ctx) = 0;
  virtual void exitCharType(Pcl2Parser::CharTypeContext *ctx) = 0;

  virtual void enterShortType(Pcl2Parser::ShortTypeContext *ctx) = 0;
  virtual void exitShortType(Pcl2Parser::ShortTypeContext *ctx) = 0;

  virtual void enterIntType(Pcl2Parser::IntTypeContext *ctx) = 0;
  virtual void exitIntType(Pcl2Parser::IntTypeContext *ctx) = 0;

  virtual void enterLongType(Pcl2Parser::LongTypeContext *ctx) = 0;
  virtual void exitLongType(Pcl2Parser::LongTypeContext *ctx) = 0;

  virtual void enterFloatType(Pcl2Parser::FloatTypeContext *ctx) = 0;
  virtual void exitFloatType(Pcl2Parser::FloatTypeContext *ctx) = 0;

  virtual void enterDoubleType(Pcl2Parser::DoubleTypeContext *ctx) = 0;
  virtual void exitDoubleType(Pcl2Parser::DoubleTypeContext *ctx) = 0;

  virtual void enterSignedType(Pcl2Parser::SignedTypeContext *ctx) = 0;
  virtual void exitSignedType(Pcl2Parser::SignedTypeContext *ctx) = 0;

  virtual void enterUnsignedType(Pcl2Parser::UnsignedTypeContext *ctx) = 0;
  virtual void exitUnsignedType(Pcl2Parser::UnsignedTypeContext *ctx) = 0;

  virtual void enterUint32_tType(Pcl2Parser::Uint32_tTypeContext *ctx) = 0;
  virtual void exitUint32_tType(Pcl2Parser::Uint32_tTypeContext *ctx) = 0;

  virtual void enterInt32_tType(Pcl2Parser::Int32_tTypeContext *ctx) = 0;
  virtual void exitInt32_tType(Pcl2Parser::Int32_tTypeContext *ctx) = 0;

  virtual void enterDeclarator(Pcl2Parser::DeclaratorContext *ctx) = 0;
  virtual void exitDeclarator(Pcl2Parser::DeclaratorContext *ctx) = 0;

  virtual void enterDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *ctx) = 0;
  virtual void exitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *ctx) = 0;

  virtual void enterIdentifierList(Pcl2Parser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(Pcl2Parser::IdentifierListContext *ctx) = 0;

  virtual void enterParameterTypeList(Pcl2Parser::ParameterTypeListContext *ctx) = 0;
  virtual void exitParameterTypeList(Pcl2Parser::ParameterTypeListContext *ctx) = 0;

  virtual void enterParameterList(Pcl2Parser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(Pcl2Parser::ParameterListContext *ctx) = 0;

  virtual void enterParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *ctx) = 0;
  virtual void exitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *ctx) = 0;

  virtual void enterUnaryOperator(Pcl2Parser::UnaryOperatorContext *ctx) = 0;
  virtual void exitUnaryOperator(Pcl2Parser::UnaryOperatorContext *ctx) = 0;

  virtual void enterAssignmentOperator(Pcl2Parser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(Pcl2Parser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterExpression(Pcl2Parser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(Pcl2Parser::ExpressionContext *ctx) = 0;

  virtual void enterAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterConditionalExpression(Pcl2Parser::ConditionalExpressionContext *ctx) = 0;
  virtual void exitConditionalExpression(Pcl2Parser::ConditionalExpressionContext *ctx) = 0;

  virtual void enterArgumentExpressionList(Pcl2Parser::ArgumentExpressionListContext *ctx) = 0;
  virtual void exitArgumentExpressionList(Pcl2Parser::ArgumentExpressionListContext *ctx) = 0;

  virtual void enterUnaryExpression(Pcl2Parser::UnaryExpressionContext *ctx) = 0;
  virtual void exitUnaryExpression(Pcl2Parser::UnaryExpressionContext *ctx) = 0;

  virtual void enterPostfixExpression(Pcl2Parser::PostfixExpressionContext *ctx) = 0;
  virtual void exitPostfixExpression(Pcl2Parser::PostfixExpressionContext *ctx) = 0;

  virtual void enterPrimaryExpression(Pcl2Parser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(Pcl2Parser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(Pcl2Parser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterShiftExpression(Pcl2Parser::ShiftExpressionContext *ctx) = 0;
  virtual void exitShiftExpression(Pcl2Parser::ShiftExpressionContext *ctx) = 0;

  virtual void enterRelationalExpression(Pcl2Parser::RelationalExpressionContext *ctx) = 0;
  virtual void exitRelationalExpression(Pcl2Parser::RelationalExpressionContext *ctx) = 0;

  virtual void enterEqualityExpression(Pcl2Parser::EqualityExpressionContext *ctx) = 0;
  virtual void exitEqualityExpression(Pcl2Parser::EqualityExpressionContext *ctx) = 0;

  virtual void enterAndExpression(Pcl2Parser::AndExpressionContext *ctx) = 0;
  virtual void exitAndExpression(Pcl2Parser::AndExpressionContext *ctx) = 0;

  virtual void enterExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext *ctx) = 0;
  virtual void exitExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext *ctx) = 0;

  virtual void enterInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext *ctx) = 0;
  virtual void exitInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext *ctx) = 0;

  virtual void enterLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext *ctx) = 0;
  virtual void exitLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext *ctx) = 0;

  virtual void enterLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext *ctx) = 0;
  virtual void exitLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext *ctx) = 0;

  virtual void enterStatement(Pcl2Parser::StatementContext *ctx) = 0;
  virtual void exitStatement(Pcl2Parser::StatementContext *ctx) = 0;

  virtual void enterCompoundStatement(Pcl2Parser::CompoundStatementContext *ctx) = 0;
  virtual void exitCompoundStatement(Pcl2Parser::CompoundStatementContext *ctx) = 0;

  virtual void enterBlockItemList(Pcl2Parser::BlockItemListContext *ctx) = 0;
  virtual void exitBlockItemList(Pcl2Parser::BlockItemListContext *ctx) = 0;

  virtual void enterBlockItem(Pcl2Parser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(Pcl2Parser::BlockItemContext *ctx) = 0;

  virtual void enterIterationStatement(Pcl2Parser::IterationStatementContext *ctx) = 0;
  virtual void exitIterationStatement(Pcl2Parser::IterationStatementContext *ctx) = 0;

  virtual void enterForCondition(Pcl2Parser::ForConditionContext *ctx) = 0;
  virtual void exitForCondition(Pcl2Parser::ForConditionContext *ctx) = 0;

  virtual void enterForDeclaration(Pcl2Parser::ForDeclarationContext *ctx) = 0;
  virtual void exitForDeclaration(Pcl2Parser::ForDeclarationContext *ctx) = 0;

  virtual void enterForExpression(Pcl2Parser::ForExpressionContext *ctx) = 0;
  virtual void exitForExpression(Pcl2Parser::ForExpressionContext *ctx) = 0;

  virtual void enterExpressionStatement(Pcl2Parser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(Pcl2Parser::ExpressionStatementContext *ctx) = 0;

  virtual void enterSelectionStatement(Pcl2Parser::SelectionStatementContext *ctx) = 0;
  virtual void exitSelectionStatement(Pcl2Parser::SelectionStatementContext *ctx) = 0;


};

