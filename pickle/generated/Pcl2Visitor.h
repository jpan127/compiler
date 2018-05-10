
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

    virtual antlrcpp::Any visitDeclaration(Pcl2Parser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclaratorList(Pcl2Parser::InitDeclaratorListContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclarator(Pcl2Parser::InitDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitInitializer(Pcl2Parser::InitializerContext *context) = 0;

    virtual antlrcpp::Any visitVoidType(Pcl2Parser::VoidTypeContext *context) = 0;

    virtual antlrcpp::Any visitBoolType(Pcl2Parser::BoolTypeContext *context) = 0;

    virtual antlrcpp::Any visitCharType(Pcl2Parser::CharTypeContext *context) = 0;

    virtual antlrcpp::Any visitShortType(Pcl2Parser::ShortTypeContext *context) = 0;

    virtual antlrcpp::Any visitIntType(Pcl2Parser::IntTypeContext *context) = 0;

    virtual antlrcpp::Any visitLongType(Pcl2Parser::LongTypeContext *context) = 0;

    virtual antlrcpp::Any visitFloatType(Pcl2Parser::FloatTypeContext *context) = 0;

    virtual antlrcpp::Any visitDoubleType(Pcl2Parser::DoubleTypeContext *context) = 0;

    virtual antlrcpp::Any visitSignedType(Pcl2Parser::SignedTypeContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedType(Pcl2Parser::UnsignedTypeContext *context) = 0;

    virtual antlrcpp::Any visitUint32_tType(Pcl2Parser::Uint32_tTypeContext *context) = 0;

    virtual antlrcpp::Any visitInt32_tType(Pcl2Parser::Int32_tTypeContext *context) = 0;

    virtual antlrcpp::Any visitDeclarator(Pcl2Parser::DeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(Pcl2Parser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitParameterTypeList(Pcl2Parser::ParameterTypeListContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(Pcl2Parser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOperator(Pcl2Parser::UnaryOperatorContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentOperator(Pcl2Parser::AssignmentOperatorContext *context) = 0;

    virtual antlrcpp::Any visitExpression(Pcl2Parser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConditionalExpression(Pcl2Parser::ConditionalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentExpressionList(Pcl2Parser::ArgumentExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpression(Pcl2Parser::UnaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPostfixExpression(Pcl2Parser::PostfixExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeExpression(Pcl2Parser::MultiplicativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpression(Pcl2Parser::AdditiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitShiftExpression(Pcl2Parser::ShiftExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationalExpression(Pcl2Parser::RelationalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityExpression(Pcl2Parser::EqualityExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAndExpression(Pcl2Parser::AndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExclusiveOrExpression(Pcl2Parser::ExclusiveOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitInclusiveOrExpression(Pcl2Parser::InclusiveOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalAndExpression(Pcl2Parser::LogicalAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOrExpression(Pcl2Parser::LogicalOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitStatement(Pcl2Parser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(Pcl2Parser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockItemList(Pcl2Parser::BlockItemListContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(Pcl2Parser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitIterationStatement(Pcl2Parser::IterationStatementContext *context) = 0;

    virtual antlrcpp::Any visitForCondition(Pcl2Parser::ForConditionContext *context) = 0;

    virtual antlrcpp::Any visitForDeclaration(Pcl2Parser::ForDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitForExpression(Pcl2Parser::ForExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(Pcl2Parser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitSelectionStatement(Pcl2Parser::SelectionStatementContext *context) = 0;


};

