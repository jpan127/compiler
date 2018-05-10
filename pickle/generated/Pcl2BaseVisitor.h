
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from grammars/Pcl2.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "Pcl2Visitor.h"


/**
 * This class provides an empty implementation of Pcl2Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  Pcl2BaseVisitor : public Pcl2Visitor {
public:

  virtual antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTranslationUnit(Pcl2Parser::TranslationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(Pcl2Parser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitDeclaratorList(Pcl2Parser::InitDeclaratorListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitDeclarator(Pcl2Parser::InitDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitializer(Pcl2Parser::InitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVoidType(Pcl2Parser::VoidTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolType(Pcl2Parser::BoolTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharType(Pcl2Parser::CharTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShortType(Pcl2Parser::ShortTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntType(Pcl2Parser::IntTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLongType(Pcl2Parser::LongTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatType(Pcl2Parser::FloatTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoubleType(Pcl2Parser::DoubleTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignedType(Pcl2Parser::SignedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedType(Pcl2Parser::UnsignedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUint32_tType(Pcl2Parser::Uint32_tTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt32_tType(Pcl2Parser::Int32_tTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarator(Pcl2Parser::DeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierList(Pcl2Parser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterTypeList(Pcl2Parser::ParameterTypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterList(Pcl2Parser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOperator(Pcl2Parser::UnaryOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperator(Pcl2Parser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(Pcl2Parser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditionalExpression(Pcl2Parser::ConditionalExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentExpressionList(Pcl2Parser::ArgumentExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpression(Pcl2Parser::UnaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostfixExpression(Pcl2Parser::PostfixExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpression(Pcl2Parser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftExpression(Pcl2Parser::ShiftExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationalExpression(Pcl2Parser::RelationalExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityExpression(Pcl2Parser::EqualityExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAndExpression(Pcl2Parser::AndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(Pcl2Parser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompoundStatement(Pcl2Parser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockItemList(Pcl2Parser::BlockItemListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockItem(Pcl2Parser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIterationStatement(Pcl2Parser::IterationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForCondition(Pcl2Parser::ForConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForDeclaration(Pcl2Parser::ForDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForExpression(Pcl2Parser::ForExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(Pcl2Parser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectionStatement(Pcl2Parser::SelectionStatementContext *ctx) override {
    return visitChildren(ctx);
  }


};

