
// Generated from C.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "CListener.h"


/**
 * This class provides an empty implementation of CListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CBaseListener : public CListener {
public:

  virtual void enterPrimaryExpression(CParser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(CParser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterGenericSelection(CParser::GenericSelectionContext * /*ctx*/) override { }
  virtual void exitGenericSelection(CParser::GenericSelectionContext * /*ctx*/) override { }

  virtual void enterGenericAssocList(CParser::GenericAssocListContext * /*ctx*/) override { }
  virtual void exitGenericAssocList(CParser::GenericAssocListContext * /*ctx*/) override { }

  virtual void enterGenericAssociation(CParser::GenericAssociationContext * /*ctx*/) override { }
  virtual void exitGenericAssociation(CParser::GenericAssociationContext * /*ctx*/) override { }

  virtual void enterPostfixExpression(CParser::PostfixExpressionContext * /*ctx*/) override { }
  virtual void exitPostfixExpression(CParser::PostfixExpressionContext * /*ctx*/) override { }

  virtual void enterArgumentExpressionList(CParser::ArgumentExpressionListContext * /*ctx*/) override { }
  virtual void exitArgumentExpressionList(CParser::ArgumentExpressionListContext * /*ctx*/) override { }

  virtual void enterUnaryExpression(CParser::UnaryExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryExpression(CParser::UnaryExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryOperator(CParser::UnaryOperatorContext * /*ctx*/) override { }
  virtual void exitUnaryOperator(CParser::UnaryOperatorContext * /*ctx*/) override { }

  virtual void enterCastExpression(CParser::CastExpressionContext * /*ctx*/) override { }
  virtual void exitCastExpression(CParser::CastExpressionContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpression(CParser::MultiplicativeExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpression(CParser::MultiplicativeExpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveExpression(CParser::AdditiveExpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveExpression(CParser::AdditiveExpressionContext * /*ctx*/) override { }

  virtual void enterShiftExpression(CParser::ShiftExpressionContext * /*ctx*/) override { }
  virtual void exitShiftExpression(CParser::ShiftExpressionContext * /*ctx*/) override { }

  virtual void enterRelationalExpression(CParser::RelationalExpressionContext * /*ctx*/) override { }
  virtual void exitRelationalExpression(CParser::RelationalExpressionContext * /*ctx*/) override { }

  virtual void enterEqualityExpression(CParser::EqualityExpressionContext * /*ctx*/) override { }
  virtual void exitEqualityExpression(CParser::EqualityExpressionContext * /*ctx*/) override { }

  virtual void enterAndExpression(CParser::AndExpressionContext * /*ctx*/) override { }
  virtual void exitAndExpression(CParser::AndExpressionContext * /*ctx*/) override { }

  virtual void enterExclusiveOrExpression(CParser::ExclusiveOrExpressionContext * /*ctx*/) override { }
  virtual void exitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext * /*ctx*/) override { }

  virtual void enterInclusiveOrExpression(CParser::InclusiveOrExpressionContext * /*ctx*/) override { }
  virtual void exitInclusiveOrExpression(CParser::InclusiveOrExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpression(CParser::LogicalAndExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpression(CParser::LogicalAndExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalOrExpression(CParser::LogicalOrExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalOrExpression(CParser::LogicalOrExpressionContext * /*ctx*/) override { }

  virtual void enterConditionalExpression(CParser::ConditionalExpressionContext * /*ctx*/) override { }
  virtual void exitConditionalExpression(CParser::ConditionalExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(CParser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(CParser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(CParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(CParser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterExpression(CParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(CParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterConstantExpression(CParser::ConstantExpressionContext * /*ctx*/) override { }
  virtual void exitConstantExpression(CParser::ConstantExpressionContext * /*ctx*/) override { }

  virtual void enterDeclaration(CParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(CParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifiers(CParser::DeclarationSpecifiersContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifiers2(CParser::DeclarationSpecifiers2Context * /*ctx*/) override { }
  virtual void exitDeclarationSpecifiers2(CParser::DeclarationSpecifiers2Context * /*ctx*/) override { }

  virtual void enterDeclarationSpecifier(CParser::DeclarationSpecifierContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifier(CParser::DeclarationSpecifierContext * /*ctx*/) override { }

  virtual void enterInitDeclaratorList(CParser::InitDeclaratorListContext * /*ctx*/) override { }
  virtual void exitInitDeclaratorList(CParser::InitDeclaratorListContext * /*ctx*/) override { }

  virtual void enterInitDeclarator(CParser::InitDeclaratorContext * /*ctx*/) override { }
  virtual void exitInitDeclarator(CParser::InitDeclaratorContext * /*ctx*/) override { }

  virtual void enterStorageClassSpecifier(CParser::StorageClassSpecifierContext * /*ctx*/) override { }
  virtual void exitStorageClassSpecifier(CParser::StorageClassSpecifierContext * /*ctx*/) override { }

  virtual void enterTypeSpecifier(CParser::TypeSpecifierContext * /*ctx*/) override { }
  virtual void exitTypeSpecifier(CParser::TypeSpecifierContext * /*ctx*/) override { }

  virtual void enterStructOrUnionSpecifier(CParser::StructOrUnionSpecifierContext * /*ctx*/) override { }
  virtual void exitStructOrUnionSpecifier(CParser::StructOrUnionSpecifierContext * /*ctx*/) override { }

  virtual void enterStructOrUnion(CParser::StructOrUnionContext * /*ctx*/) override { }
  virtual void exitStructOrUnion(CParser::StructOrUnionContext * /*ctx*/) override { }

  virtual void enterStructDeclarationList(CParser::StructDeclarationListContext * /*ctx*/) override { }
  virtual void exitStructDeclarationList(CParser::StructDeclarationListContext * /*ctx*/) override { }

  virtual void enterStructDeclaration(CParser::StructDeclarationContext * /*ctx*/) override { }
  virtual void exitStructDeclaration(CParser::StructDeclarationContext * /*ctx*/) override { }

  virtual void enterSpecifierQualifierList(CParser::SpecifierQualifierListContext * /*ctx*/) override { }
  virtual void exitSpecifierQualifierList(CParser::SpecifierQualifierListContext * /*ctx*/) override { }

  virtual void enterStructDeclaratorList(CParser::StructDeclaratorListContext * /*ctx*/) override { }
  virtual void exitStructDeclaratorList(CParser::StructDeclaratorListContext * /*ctx*/) override { }

  virtual void enterStructDeclarator(CParser::StructDeclaratorContext * /*ctx*/) override { }
  virtual void exitStructDeclarator(CParser::StructDeclaratorContext * /*ctx*/) override { }

  virtual void enterEnumSpecifier(CParser::EnumSpecifierContext * /*ctx*/) override { }
  virtual void exitEnumSpecifier(CParser::EnumSpecifierContext * /*ctx*/) override { }

  virtual void enterEnumeratorList(CParser::EnumeratorListContext * /*ctx*/) override { }
  virtual void exitEnumeratorList(CParser::EnumeratorListContext * /*ctx*/) override { }

  virtual void enterEnumerator(CParser::EnumeratorContext * /*ctx*/) override { }
  virtual void exitEnumerator(CParser::EnumeratorContext * /*ctx*/) override { }

  virtual void enterEnumerationConstant(CParser::EnumerationConstantContext * /*ctx*/) override { }
  virtual void exitEnumerationConstant(CParser::EnumerationConstantContext * /*ctx*/) override { }

  virtual void enterAtomicTypeSpecifier(CParser::AtomicTypeSpecifierContext * /*ctx*/) override { }
  virtual void exitAtomicTypeSpecifier(CParser::AtomicTypeSpecifierContext * /*ctx*/) override { }

  virtual void enterTypeQualifier(CParser::TypeQualifierContext * /*ctx*/) override { }
  virtual void exitTypeQualifier(CParser::TypeQualifierContext * /*ctx*/) override { }

  virtual void enterFunctionSpecifier(CParser::FunctionSpecifierContext * /*ctx*/) override { }
  virtual void exitFunctionSpecifier(CParser::FunctionSpecifierContext * /*ctx*/) override { }

  virtual void enterAlignmentSpecifier(CParser::AlignmentSpecifierContext * /*ctx*/) override { }
  virtual void exitAlignmentSpecifier(CParser::AlignmentSpecifierContext * /*ctx*/) override { }

  virtual void enterDeclarator(CParser::DeclaratorContext * /*ctx*/) override { }
  virtual void exitDeclarator(CParser::DeclaratorContext * /*ctx*/) override { }

  virtual void enterDirectDeclarator(CParser::DirectDeclaratorContext * /*ctx*/) override { }
  virtual void exitDirectDeclarator(CParser::DirectDeclaratorContext * /*ctx*/) override { }

  virtual void enterGccDeclaratorExtension(CParser::GccDeclaratorExtensionContext * /*ctx*/) override { }
  virtual void exitGccDeclaratorExtension(CParser::GccDeclaratorExtensionContext * /*ctx*/) override { }

  virtual void enterGccAttributeSpecifier(CParser::GccAttributeSpecifierContext * /*ctx*/) override { }
  virtual void exitGccAttributeSpecifier(CParser::GccAttributeSpecifierContext * /*ctx*/) override { }

  virtual void enterGccAttributeList(CParser::GccAttributeListContext * /*ctx*/) override { }
  virtual void exitGccAttributeList(CParser::GccAttributeListContext * /*ctx*/) override { }

  virtual void enterGccAttribute(CParser::GccAttributeContext * /*ctx*/) override { }
  virtual void exitGccAttribute(CParser::GccAttributeContext * /*ctx*/) override { }

  virtual void enterNestedParenthesesBlock(CParser::NestedParenthesesBlockContext * /*ctx*/) override { }
  virtual void exitNestedParenthesesBlock(CParser::NestedParenthesesBlockContext * /*ctx*/) override { }

  virtual void enterPointer(CParser::PointerContext * /*ctx*/) override { }
  virtual void exitPointer(CParser::PointerContext * /*ctx*/) override { }

  virtual void enterTypeQualifierList(CParser::TypeQualifierListContext * /*ctx*/) override { }
  virtual void exitTypeQualifierList(CParser::TypeQualifierListContext * /*ctx*/) override { }

  virtual void enterParameterTypeList(CParser::ParameterTypeListContext * /*ctx*/) override { }
  virtual void exitParameterTypeList(CParser::ParameterTypeListContext * /*ctx*/) override { }

  virtual void enterParameterList(CParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(CParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameterDeclaration(CParser::ParameterDeclarationContext * /*ctx*/) override { }
  virtual void exitParameterDeclaration(CParser::ParameterDeclarationContext * /*ctx*/) override { }

  virtual void enterIdentifierList(CParser::IdentifierListContext * /*ctx*/) override { }
  virtual void exitIdentifierList(CParser::IdentifierListContext * /*ctx*/) override { }

  virtual void enterTypeName(CParser::TypeNameContext * /*ctx*/) override { }
  virtual void exitTypeName(CParser::TypeNameContext * /*ctx*/) override { }

  virtual void enterAbstractDeclarator(CParser::AbstractDeclaratorContext * /*ctx*/) override { }
  virtual void exitAbstractDeclarator(CParser::AbstractDeclaratorContext * /*ctx*/) override { }

  virtual void enterDirectAbstractDeclarator(CParser::DirectAbstractDeclaratorContext * /*ctx*/) override { }
  virtual void exitDirectAbstractDeclarator(CParser::DirectAbstractDeclaratorContext * /*ctx*/) override { }

  virtual void enterTypedefName(CParser::TypedefNameContext * /*ctx*/) override { }
  virtual void exitTypedefName(CParser::TypedefNameContext * /*ctx*/) override { }

  virtual void enterInitializer(CParser::InitializerContext * /*ctx*/) override { }
  virtual void exitInitializer(CParser::InitializerContext * /*ctx*/) override { }

  virtual void enterInitializerList(CParser::InitializerListContext * /*ctx*/) override { }
  virtual void exitInitializerList(CParser::InitializerListContext * /*ctx*/) override { }

  virtual void enterDesignation(CParser::DesignationContext * /*ctx*/) override { }
  virtual void exitDesignation(CParser::DesignationContext * /*ctx*/) override { }

  virtual void enterDesignatorList(CParser::DesignatorListContext * /*ctx*/) override { }
  virtual void exitDesignatorList(CParser::DesignatorListContext * /*ctx*/) override { }

  virtual void enterDesignator(CParser::DesignatorContext * /*ctx*/) override { }
  virtual void exitDesignator(CParser::DesignatorContext * /*ctx*/) override { }

  virtual void enterStaticAssertDeclaration(CParser::StaticAssertDeclarationContext * /*ctx*/) override { }
  virtual void exitStaticAssertDeclaration(CParser::StaticAssertDeclarationContext * /*ctx*/) override { }

  virtual void enterStatement(CParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(CParser::StatementContext * /*ctx*/) override { }

  virtual void enterLabeledStatement(CParser::LabeledStatementContext * /*ctx*/) override { }
  virtual void exitLabeledStatement(CParser::LabeledStatementContext * /*ctx*/) override { }

  virtual void enterCompoundStatement(CParser::CompoundStatementContext * /*ctx*/) override { }
  virtual void exitCompoundStatement(CParser::CompoundStatementContext * /*ctx*/) override { }

  virtual void enterBlockItemList(CParser::BlockItemListContext * /*ctx*/) override { }
  virtual void exitBlockItemList(CParser::BlockItemListContext * /*ctx*/) override { }

  virtual void enterBlockItem(CParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(CParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(CParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(CParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterSelectionStatement(CParser::SelectionStatementContext * /*ctx*/) override { }
  virtual void exitSelectionStatement(CParser::SelectionStatementContext * /*ctx*/) override { }

  virtual void enterIterationStatement(CParser::IterationStatementContext * /*ctx*/) override { }
  virtual void exitIterationStatement(CParser::IterationStatementContext * /*ctx*/) override { }

  virtual void enterForCondition(CParser::ForConditionContext * /*ctx*/) override { }
  virtual void exitForCondition(CParser::ForConditionContext * /*ctx*/) override { }

  virtual void enterForDeclaration(CParser::ForDeclarationContext * /*ctx*/) override { }
  virtual void exitForDeclaration(CParser::ForDeclarationContext * /*ctx*/) override { }

  virtual void enterForExpression(CParser::ForExpressionContext * /*ctx*/) override { }
  virtual void exitForExpression(CParser::ForExpressionContext * /*ctx*/) override { }

  virtual void enterJumpStatement(CParser::JumpStatementContext * /*ctx*/) override { }
  virtual void exitJumpStatement(CParser::JumpStatementContext * /*ctx*/) override { }

  virtual void enterCompilationUnit(CParser::CompilationUnitContext * /*ctx*/) override { }
  virtual void exitCompilationUnit(CParser::CompilationUnitContext * /*ctx*/) override { }

  virtual void enterTranslationUnit(CParser::TranslationUnitContext * /*ctx*/) override { }
  virtual void exitTranslationUnit(CParser::TranslationUnitContext * /*ctx*/) override { }

  virtual void enterExternalDeclaration(CParser::ExternalDeclarationContext * /*ctx*/) override { }
  virtual void exitExternalDeclaration(CParser::ExternalDeclarationContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(CParser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(CParser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterDeclarationList(CParser::DeclarationListContext * /*ctx*/) override { }
  virtual void exitDeclarationList(CParser::DeclarationListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

