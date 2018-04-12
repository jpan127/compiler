
// Generated from C.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "CParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CParser.
 */
class  CListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterPrimaryExpression(CParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(CParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterGenericSelection(CParser::GenericSelectionContext *ctx) = 0;
  virtual void exitGenericSelection(CParser::GenericSelectionContext *ctx) = 0;

  virtual void enterGenericAssocList(CParser::GenericAssocListContext *ctx) = 0;
  virtual void exitGenericAssocList(CParser::GenericAssocListContext *ctx) = 0;

  virtual void enterGenericAssociation(CParser::GenericAssociationContext *ctx) = 0;
  virtual void exitGenericAssociation(CParser::GenericAssociationContext *ctx) = 0;

  virtual void enterPostfixExpression(CParser::PostfixExpressionContext *ctx) = 0;
  virtual void exitPostfixExpression(CParser::PostfixExpressionContext *ctx) = 0;

  virtual void enterArgumentExpressionList(CParser::ArgumentExpressionListContext *ctx) = 0;
  virtual void exitArgumentExpressionList(CParser::ArgumentExpressionListContext *ctx) = 0;

  virtual void enterUnaryExpression(CParser::UnaryExpressionContext *ctx) = 0;
  virtual void exitUnaryExpression(CParser::UnaryExpressionContext *ctx) = 0;

  virtual void enterUnaryOperator(CParser::UnaryOperatorContext *ctx) = 0;
  virtual void exitUnaryOperator(CParser::UnaryOperatorContext *ctx) = 0;

  virtual void enterCastExpression(CParser::CastExpressionContext *ctx) = 0;
  virtual void exitCastExpression(CParser::CastExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(CParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(CParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterShiftExpression(CParser::ShiftExpressionContext *ctx) = 0;
  virtual void exitShiftExpression(CParser::ShiftExpressionContext *ctx) = 0;

  virtual void enterRelationalExpression(CParser::RelationalExpressionContext *ctx) = 0;
  virtual void exitRelationalExpression(CParser::RelationalExpressionContext *ctx) = 0;

  virtual void enterEqualityExpression(CParser::EqualityExpressionContext *ctx) = 0;
  virtual void exitEqualityExpression(CParser::EqualityExpressionContext *ctx) = 0;

  virtual void enterAndExpression(CParser::AndExpressionContext *ctx) = 0;
  virtual void exitAndExpression(CParser::AndExpressionContext *ctx) = 0;

  virtual void enterExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *ctx) = 0;
  virtual void exitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *ctx) = 0;

  virtual void enterInclusiveOrExpression(CParser::InclusiveOrExpressionContext *ctx) = 0;
  virtual void exitInclusiveOrExpression(CParser::InclusiveOrExpressionContext *ctx) = 0;

  virtual void enterLogicalAndExpression(CParser::LogicalAndExpressionContext *ctx) = 0;
  virtual void exitLogicalAndExpression(CParser::LogicalAndExpressionContext *ctx) = 0;

  virtual void enterLogicalOrExpression(CParser::LogicalOrExpressionContext *ctx) = 0;
  virtual void exitLogicalOrExpression(CParser::LogicalOrExpressionContext *ctx) = 0;

  virtual void enterConditionalExpression(CParser::ConditionalExpressionContext *ctx) = 0;
  virtual void exitConditionalExpression(CParser::ConditionalExpressionContext *ctx) = 0;

  virtual void enterAssignmentExpression(CParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(CParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterAssignmentOperator(CParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(CParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterExpression(CParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(CParser::ExpressionContext *ctx) = 0;

  virtual void enterConstantExpression(CParser::ConstantExpressionContext *ctx) = 0;
  virtual void exitConstantExpression(CParser::ConstantExpressionContext *ctx) = 0;

  virtual void enterDeclaration(CParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(CParser::DeclarationContext *ctx) = 0;

  virtual void enterDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) = 0;
  virtual void exitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) = 0;

  virtual void enterDeclarationSpecifiers2(CParser::DeclarationSpecifiers2Context *ctx) = 0;
  virtual void exitDeclarationSpecifiers2(CParser::DeclarationSpecifiers2Context *ctx) = 0;

  virtual void enterDeclarationSpecifier(CParser::DeclarationSpecifierContext *ctx) = 0;
  virtual void exitDeclarationSpecifier(CParser::DeclarationSpecifierContext *ctx) = 0;

  virtual void enterInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) = 0;
  virtual void exitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) = 0;

  virtual void enterInitDeclarator(CParser::InitDeclaratorContext *ctx) = 0;
  virtual void exitInitDeclarator(CParser::InitDeclaratorContext *ctx) = 0;

  virtual void enterStorageClassSpecifier(CParser::StorageClassSpecifierContext *ctx) = 0;
  virtual void exitStorageClassSpecifier(CParser::StorageClassSpecifierContext *ctx) = 0;

  virtual void enterTypeSpecifier(CParser::TypeSpecifierContext *ctx) = 0;
  virtual void exitTypeSpecifier(CParser::TypeSpecifierContext *ctx) = 0;

  virtual void enterStructOrUnionSpecifier(CParser::StructOrUnionSpecifierContext *ctx) = 0;
  virtual void exitStructOrUnionSpecifier(CParser::StructOrUnionSpecifierContext *ctx) = 0;

  virtual void enterStructOrUnion(CParser::StructOrUnionContext *ctx) = 0;
  virtual void exitStructOrUnion(CParser::StructOrUnionContext *ctx) = 0;

  virtual void enterStructDeclarationList(CParser::StructDeclarationListContext *ctx) = 0;
  virtual void exitStructDeclarationList(CParser::StructDeclarationListContext *ctx) = 0;

  virtual void enterStructDeclaration(CParser::StructDeclarationContext *ctx) = 0;
  virtual void exitStructDeclaration(CParser::StructDeclarationContext *ctx) = 0;

  virtual void enterSpecifierQualifierList(CParser::SpecifierQualifierListContext *ctx) = 0;
  virtual void exitSpecifierQualifierList(CParser::SpecifierQualifierListContext *ctx) = 0;

  virtual void enterStructDeclaratorList(CParser::StructDeclaratorListContext *ctx) = 0;
  virtual void exitStructDeclaratorList(CParser::StructDeclaratorListContext *ctx) = 0;

  virtual void enterStructDeclarator(CParser::StructDeclaratorContext *ctx) = 0;
  virtual void exitStructDeclarator(CParser::StructDeclaratorContext *ctx) = 0;

  virtual void enterEnumSpecifier(CParser::EnumSpecifierContext *ctx) = 0;
  virtual void exitEnumSpecifier(CParser::EnumSpecifierContext *ctx) = 0;

  virtual void enterEnumeratorList(CParser::EnumeratorListContext *ctx) = 0;
  virtual void exitEnumeratorList(CParser::EnumeratorListContext *ctx) = 0;

  virtual void enterEnumerator(CParser::EnumeratorContext *ctx) = 0;
  virtual void exitEnumerator(CParser::EnumeratorContext *ctx) = 0;

  virtual void enterEnumerationConstant(CParser::EnumerationConstantContext *ctx) = 0;
  virtual void exitEnumerationConstant(CParser::EnumerationConstantContext *ctx) = 0;

  virtual void enterAtomicTypeSpecifier(CParser::AtomicTypeSpecifierContext *ctx) = 0;
  virtual void exitAtomicTypeSpecifier(CParser::AtomicTypeSpecifierContext *ctx) = 0;

  virtual void enterTypeQualifier(CParser::TypeQualifierContext *ctx) = 0;
  virtual void exitTypeQualifier(CParser::TypeQualifierContext *ctx) = 0;

  virtual void enterFunctionSpecifier(CParser::FunctionSpecifierContext *ctx) = 0;
  virtual void exitFunctionSpecifier(CParser::FunctionSpecifierContext *ctx) = 0;

  virtual void enterAlignmentSpecifier(CParser::AlignmentSpecifierContext *ctx) = 0;
  virtual void exitAlignmentSpecifier(CParser::AlignmentSpecifierContext *ctx) = 0;

  virtual void enterDeclarator(CParser::DeclaratorContext *ctx) = 0;
  virtual void exitDeclarator(CParser::DeclaratorContext *ctx) = 0;

  virtual void enterDirectDeclarator(CParser::DirectDeclaratorContext *ctx) = 0;
  virtual void exitDirectDeclarator(CParser::DirectDeclaratorContext *ctx) = 0;

  virtual void enterGccDeclaratorExtension(CParser::GccDeclaratorExtensionContext *ctx) = 0;
  virtual void exitGccDeclaratorExtension(CParser::GccDeclaratorExtensionContext *ctx) = 0;

  virtual void enterGccAttributeSpecifier(CParser::GccAttributeSpecifierContext *ctx) = 0;
  virtual void exitGccAttributeSpecifier(CParser::GccAttributeSpecifierContext *ctx) = 0;

  virtual void enterGccAttributeList(CParser::GccAttributeListContext *ctx) = 0;
  virtual void exitGccAttributeList(CParser::GccAttributeListContext *ctx) = 0;

  virtual void enterGccAttribute(CParser::GccAttributeContext *ctx) = 0;
  virtual void exitGccAttribute(CParser::GccAttributeContext *ctx) = 0;

  virtual void enterNestedParenthesesBlock(CParser::NestedParenthesesBlockContext *ctx) = 0;
  virtual void exitNestedParenthesesBlock(CParser::NestedParenthesesBlockContext *ctx) = 0;

  virtual void enterPointer(CParser::PointerContext *ctx) = 0;
  virtual void exitPointer(CParser::PointerContext *ctx) = 0;

  virtual void enterTypeQualifierList(CParser::TypeQualifierListContext *ctx) = 0;
  virtual void exitTypeQualifierList(CParser::TypeQualifierListContext *ctx) = 0;

  virtual void enterParameterTypeList(CParser::ParameterTypeListContext *ctx) = 0;
  virtual void exitParameterTypeList(CParser::ParameterTypeListContext *ctx) = 0;

  virtual void enterParameterList(CParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(CParser::ParameterListContext *ctx) = 0;

  virtual void enterParameterDeclaration(CParser::ParameterDeclarationContext *ctx) = 0;
  virtual void exitParameterDeclaration(CParser::ParameterDeclarationContext *ctx) = 0;

  virtual void enterIdentifierList(CParser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(CParser::IdentifierListContext *ctx) = 0;

  virtual void enterTypeName(CParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(CParser::TypeNameContext *ctx) = 0;

  virtual void enterAbstractDeclarator(CParser::AbstractDeclaratorContext *ctx) = 0;
  virtual void exitAbstractDeclarator(CParser::AbstractDeclaratorContext *ctx) = 0;

  virtual void enterDirectAbstractDeclarator(CParser::DirectAbstractDeclaratorContext *ctx) = 0;
  virtual void exitDirectAbstractDeclarator(CParser::DirectAbstractDeclaratorContext *ctx) = 0;

  virtual void enterTypedefName(CParser::TypedefNameContext *ctx) = 0;
  virtual void exitTypedefName(CParser::TypedefNameContext *ctx) = 0;

  virtual void enterInitializer(CParser::InitializerContext *ctx) = 0;
  virtual void exitInitializer(CParser::InitializerContext *ctx) = 0;

  virtual void enterInitializerList(CParser::InitializerListContext *ctx) = 0;
  virtual void exitInitializerList(CParser::InitializerListContext *ctx) = 0;

  virtual void enterDesignation(CParser::DesignationContext *ctx) = 0;
  virtual void exitDesignation(CParser::DesignationContext *ctx) = 0;

  virtual void enterDesignatorList(CParser::DesignatorListContext *ctx) = 0;
  virtual void exitDesignatorList(CParser::DesignatorListContext *ctx) = 0;

  virtual void enterDesignator(CParser::DesignatorContext *ctx) = 0;
  virtual void exitDesignator(CParser::DesignatorContext *ctx) = 0;

  virtual void enterStaticAssertDeclaration(CParser::StaticAssertDeclarationContext *ctx) = 0;
  virtual void exitStaticAssertDeclaration(CParser::StaticAssertDeclarationContext *ctx) = 0;

  virtual void enterStatement(CParser::StatementContext *ctx) = 0;
  virtual void exitStatement(CParser::StatementContext *ctx) = 0;

  virtual void enterLabeledStatement(CParser::LabeledStatementContext *ctx) = 0;
  virtual void exitLabeledStatement(CParser::LabeledStatementContext *ctx) = 0;

  virtual void enterCompoundStatement(CParser::CompoundStatementContext *ctx) = 0;
  virtual void exitCompoundStatement(CParser::CompoundStatementContext *ctx) = 0;

  virtual void enterBlockItemList(CParser::BlockItemListContext *ctx) = 0;
  virtual void exitBlockItemList(CParser::BlockItemListContext *ctx) = 0;

  virtual void enterBlockItem(CParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(CParser::BlockItemContext *ctx) = 0;

  virtual void enterExpressionStatement(CParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(CParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterSelectionStatement(CParser::SelectionStatementContext *ctx) = 0;
  virtual void exitSelectionStatement(CParser::SelectionStatementContext *ctx) = 0;

  virtual void enterIterationStatement(CParser::IterationStatementContext *ctx) = 0;
  virtual void exitIterationStatement(CParser::IterationStatementContext *ctx) = 0;

  virtual void enterForCondition(CParser::ForConditionContext *ctx) = 0;
  virtual void exitForCondition(CParser::ForConditionContext *ctx) = 0;

  virtual void enterForDeclaration(CParser::ForDeclarationContext *ctx) = 0;
  virtual void exitForDeclaration(CParser::ForDeclarationContext *ctx) = 0;

  virtual void enterForExpression(CParser::ForExpressionContext *ctx) = 0;
  virtual void exitForExpression(CParser::ForExpressionContext *ctx) = 0;

  virtual void enterJumpStatement(CParser::JumpStatementContext *ctx) = 0;
  virtual void exitJumpStatement(CParser::JumpStatementContext *ctx) = 0;

  virtual void enterCompilationUnit(CParser::CompilationUnitContext *ctx) = 0;
  virtual void exitCompilationUnit(CParser::CompilationUnitContext *ctx) = 0;

  virtual void enterTranslationUnit(CParser::TranslationUnitContext *ctx) = 0;
  virtual void exitTranslationUnit(CParser::TranslationUnitContext *ctx) = 0;

  virtual void enterExternalDeclaration(CParser::ExternalDeclarationContext *ctx) = 0;
  virtual void exitExternalDeclaration(CParser::ExternalDeclarationContext *ctx) = 0;

  virtual void enterFunctionDefinition(CParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterDeclarationList(CParser::DeclarationListContext *ctx) = 0;
  virtual void exitDeclarationList(CParser::DeclarationListContext *ctx) = 0;


};

