
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from grammars/Pcl2.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "Pcl2Listener.h"


/**
 * This class provides an empty implementation of Pcl2Listener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  Pcl2BaseListener : public Pcl2Listener {
public:

  virtual void enterCompilationUnit(Pcl2Parser::CompilationUnitContext * /*ctx*/) override { }
  virtual void exitCompilationUnit(Pcl2Parser::CompilationUnitContext * /*ctx*/) override { }

  virtual void enterTranslationUnit(Pcl2Parser::TranslationUnitContext * /*ctx*/) override { }
  virtual void exitTranslationUnit(Pcl2Parser::TranslationUnitContext * /*ctx*/) override { }

  virtual void enterExternalDeclaration(Pcl2Parser::ExternalDeclarationContext * /*ctx*/) override { }
  virtual void exitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterDeclaration(Pcl2Parser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(Pcl2Parser::DeclarationContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext * /*ctx*/) override { }

  virtual void enterInitDeclaratorList(Pcl2Parser::InitDeclaratorListContext * /*ctx*/) override { }
  virtual void exitInitDeclaratorList(Pcl2Parser::InitDeclaratorListContext * /*ctx*/) override { }

  virtual void enterInitDeclarator(Pcl2Parser::InitDeclaratorContext * /*ctx*/) override { }
  virtual void exitInitDeclarator(Pcl2Parser::InitDeclaratorContext * /*ctx*/) override { }

  virtual void enterVoidType(Pcl2Parser::VoidTypeContext * /*ctx*/) override { }
  virtual void exitVoidType(Pcl2Parser::VoidTypeContext * /*ctx*/) override { }

  virtual void enterBoolType(Pcl2Parser::BoolTypeContext * /*ctx*/) override { }
  virtual void exitBoolType(Pcl2Parser::BoolTypeContext * /*ctx*/) override { }

  virtual void enterCharType(Pcl2Parser::CharTypeContext * /*ctx*/) override { }
  virtual void exitCharType(Pcl2Parser::CharTypeContext * /*ctx*/) override { }

  virtual void enterShortType(Pcl2Parser::ShortTypeContext * /*ctx*/) override { }
  virtual void exitShortType(Pcl2Parser::ShortTypeContext * /*ctx*/) override { }

  virtual void enterIntType(Pcl2Parser::IntTypeContext * /*ctx*/) override { }
  virtual void exitIntType(Pcl2Parser::IntTypeContext * /*ctx*/) override { }

  virtual void enterLongType(Pcl2Parser::LongTypeContext * /*ctx*/) override { }
  virtual void exitLongType(Pcl2Parser::LongTypeContext * /*ctx*/) override { }

  virtual void enterFloatType(Pcl2Parser::FloatTypeContext * /*ctx*/) override { }
  virtual void exitFloatType(Pcl2Parser::FloatTypeContext * /*ctx*/) override { }

  virtual void enterDoubleType(Pcl2Parser::DoubleTypeContext * /*ctx*/) override { }
  virtual void exitDoubleType(Pcl2Parser::DoubleTypeContext * /*ctx*/) override { }

  virtual void enterSignedType(Pcl2Parser::SignedTypeContext * /*ctx*/) override { }
  virtual void exitSignedType(Pcl2Parser::SignedTypeContext * /*ctx*/) override { }

  virtual void enterUnsignedType(Pcl2Parser::UnsignedTypeContext * /*ctx*/) override { }
  virtual void exitUnsignedType(Pcl2Parser::UnsignedTypeContext * /*ctx*/) override { }

  virtual void enterUint32_tType(Pcl2Parser::Uint32_tTypeContext * /*ctx*/) override { }
  virtual void exitUint32_tType(Pcl2Parser::Uint32_tTypeContext * /*ctx*/) override { }

  virtual void enterInt32_tType(Pcl2Parser::Int32_tTypeContext * /*ctx*/) override { }
  virtual void exitInt32_tType(Pcl2Parser::Int32_tTypeContext * /*ctx*/) override { }

  virtual void enterDeclarator(Pcl2Parser::DeclaratorContext * /*ctx*/) override { }
  virtual void exitDeclarator(Pcl2Parser::DeclaratorContext * /*ctx*/) override { }

  virtual void enterDirectDeclarator(Pcl2Parser::DirectDeclaratorContext * /*ctx*/) override { }
  virtual void exitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext * /*ctx*/) override { }

  virtual void enterParameterTypeList(Pcl2Parser::ParameterTypeListContext * /*ctx*/) override { }
  virtual void exitParameterTypeList(Pcl2Parser::ParameterTypeListContext * /*ctx*/) override { }

  virtual void enterParameterList(Pcl2Parser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(Pcl2Parser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameterDeclaration(Pcl2Parser::ParameterDeclarationContext * /*ctx*/) override { }
  virtual void exitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext * /*ctx*/) override { }

  virtual void enterPrimaryExpression(Pcl2Parser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterPostfixExpression(Pcl2Parser::PostfixExpressionContext * /*ctx*/) override { }
  virtual void exitPostfixExpression(Pcl2Parser::PostfixExpressionContext * /*ctx*/) override { }

  virtual void enterArgumentExpressionList(Pcl2Parser::ArgumentExpressionListContext * /*ctx*/) override { }
  virtual void exitArgumentExpressionList(Pcl2Parser::ArgumentExpressionListContext * /*ctx*/) override { }

  virtual void enterUnaryExpression(Pcl2Parser::UnaryExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryExpression(Pcl2Parser::UnaryExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryOperator(Pcl2Parser::UnaryOperatorContext * /*ctx*/) override { }
  virtual void exitUnaryOperator(Pcl2Parser::UnaryOperatorContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveExpression(Pcl2Parser::AdditiveExpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveExpression(Pcl2Parser::AdditiveExpressionContext * /*ctx*/) override { }

  virtual void enterShiftExpression(Pcl2Parser::ShiftExpressionContext * /*ctx*/) override { }
  virtual void exitShiftExpression(Pcl2Parser::ShiftExpressionContext * /*ctx*/) override { }

  virtual void enterRelationalExpression(Pcl2Parser::RelationalExpressionContext * /*ctx*/) override { }
  virtual void exitRelationalExpression(Pcl2Parser::RelationalExpressionContext * /*ctx*/) override { }

  virtual void enterEqualityExpression(Pcl2Parser::EqualityExpressionContext * /*ctx*/) override { }
  virtual void exitEqualityExpression(Pcl2Parser::EqualityExpressionContext * /*ctx*/) override { }

  virtual void enterAndExpression(Pcl2Parser::AndExpressionContext * /*ctx*/) override { }
  virtual void exitAndExpression(Pcl2Parser::AndExpressionContext * /*ctx*/) override { }

  virtual void enterExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext * /*ctx*/) override { }
  virtual void exitExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext * /*ctx*/) override { }

  virtual void enterInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext * /*ctx*/) override { }
  virtual void exitInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext * /*ctx*/) override { }

  virtual void enterConditionalExpression(Pcl2Parser::ConditionalExpressionContext * /*ctx*/) override { }
  virtual void exitConditionalExpression(Pcl2Parser::ConditionalExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(Pcl2Parser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(Pcl2Parser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(Pcl2Parser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterExpression(Pcl2Parser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(Pcl2Parser::ExpressionContext * /*ctx*/) override { }

  virtual void enterIdentifierList(Pcl2Parser::IdentifierListContext * /*ctx*/) override { }
  virtual void exitIdentifierList(Pcl2Parser::IdentifierListContext * /*ctx*/) override { }

  virtual void enterStatement(Pcl2Parser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(Pcl2Parser::StatementContext * /*ctx*/) override { }

  virtual void enterCompoundStatement(Pcl2Parser::CompoundStatementContext * /*ctx*/) override { }
  virtual void exitCompoundStatement(Pcl2Parser::CompoundStatementContext * /*ctx*/) override { }

  virtual void enterBlockItemList(Pcl2Parser::BlockItemListContext * /*ctx*/) override { }
  virtual void exitBlockItemList(Pcl2Parser::BlockItemListContext * /*ctx*/) override { }

  virtual void enterBlockItem(Pcl2Parser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(Pcl2Parser::BlockItemContext * /*ctx*/) override { }

  virtual void enterIterationStatement(Pcl2Parser::IterationStatementContext * /*ctx*/) override { }
  virtual void exitIterationStatement(Pcl2Parser::IterationStatementContext * /*ctx*/) override { }

  virtual void enterForCondition(Pcl2Parser::ForConditionContext * /*ctx*/) override { }
  virtual void exitForCondition(Pcl2Parser::ForConditionContext * /*ctx*/) override { }

  virtual void enterForDeclaration(Pcl2Parser::ForDeclarationContext * /*ctx*/) override { }
  virtual void exitForDeclaration(Pcl2Parser::ForDeclarationContext * /*ctx*/) override { }

  virtual void enterForExpression(Pcl2Parser::ForExpressionContext * /*ctx*/) override { }
  virtual void exitForExpression(Pcl2Parser::ForExpressionContext * /*ctx*/) override { }

  virtual void enterInitializer(Pcl2Parser::InitializerContext * /*ctx*/) override { }
  virtual void exitInitializer(Pcl2Parser::InitializerContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(Pcl2Parser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(Pcl2Parser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterSelectionStatement(Pcl2Parser::SelectionStatementContext * /*ctx*/) override { }
  virtual void exitSelectionStatement(Pcl2Parser::SelectionStatementContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

