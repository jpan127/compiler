
#include "wci/intermediate/symtab.h"
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

  virtual void enterFunctionDeclaration(Pcl2Parser::FunctionDeclarationContext * /*ctx*/) override { }
  virtual void exitFunctionDeclaration(Pcl2Parser::FunctionDeclarationContext * /*ctx*/) override { }

  virtual void enterDeclaration(Pcl2Parser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(Pcl2Parser::DeclarationContext * /*ctx*/) override { }

  virtual void enterTypeSpecifier(Pcl2Parser::TypeSpecifierContext * /*ctx*/) override { }
  virtual void exitTypeSpecifier(Pcl2Parser::TypeSpecifierContext * /*ctx*/) override { }

  virtual void enterFunctionCall(Pcl2Parser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(Pcl2Parser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterFunctionReturn(Pcl2Parser::FunctionReturnContext * /*ctx*/) override { }
  virtual void exitFunctionReturn(Pcl2Parser::FunctionReturnContext * /*ctx*/) override { }

  virtual void enterJumpStatement(Pcl2Parser::JumpStatementContext * /*ctx*/) override { }
  virtual void exitJumpStatement(Pcl2Parser::JumpStatementContext * /*ctx*/) override { }

  virtual void enterIdentifierList(Pcl2Parser::IdentifierListContext * /*ctx*/) override { }
  virtual void exitIdentifierList(Pcl2Parser::IdentifierListContext * /*ctx*/) override { }

  virtual void enterCompoundStatement(Pcl2Parser::CompoundStatementContext * /*ctx*/) override { }
  virtual void exitCompoundStatement(Pcl2Parser::CompoundStatementContext * /*ctx*/) override { }

  virtual void enterBlockItemList(Pcl2Parser::BlockItemListContext * /*ctx*/) override { }
  virtual void exitBlockItemList(Pcl2Parser::BlockItemListContext * /*ctx*/) override { }

  virtual void enterBlockItem(Pcl2Parser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(Pcl2Parser::BlockItemContext * /*ctx*/) override { }

  virtual void enterStatement(Pcl2Parser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(Pcl2Parser::StatementContext * /*ctx*/) override { }

  virtual void enterAssignmentStatement(Pcl2Parser::AssignmentStatementContext * /*ctx*/) override { }
  virtual void exitAssignmentStatement(Pcl2Parser::AssignmentStatementContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(Pcl2Parser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(Pcl2Parser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterSelectionStatement(Pcl2Parser::SelectionStatementContext * /*ctx*/) override { }
  virtual void exitSelectionStatement(Pcl2Parser::SelectionStatementContext * /*ctx*/) override { }

  virtual void enterIterationStatement(Pcl2Parser::IterationStatementContext * /*ctx*/) override { }
  virtual void exitIterationStatement(Pcl2Parser::IterationStatementContext * /*ctx*/) override { }

  virtual void enterPrimaryExpression(Pcl2Parser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(Pcl2Parser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterPrimExpr(Pcl2Parser::PrimExprContext * /*ctx*/) override { }
  virtual void exitPrimExpr(Pcl2Parser::PrimExprContext * /*ctx*/) override { }

  virtual void enterMulDivExpr(Pcl2Parser::MulDivExprContext * /*ctx*/) override { }
  virtual void exitMulDivExpr(Pcl2Parser::MulDivExprContext * /*ctx*/) override { }

  virtual void enterAddminExpr(Pcl2Parser::AddminExprContext * /*ctx*/) override { }
  virtual void exitAddminExpr(Pcl2Parser::AddminExprContext * /*ctx*/) override { }

  virtual void enterBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext * /*ctx*/) override { }
  virtual void exitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext * /*ctx*/) override { }

  virtual void enterNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext * /*ctx*/) override { }
  virtual void exitNegatedConditionalExpr(Pcl2Parser::NegatedConditionalExprContext * /*ctx*/) override { }

  virtual void enterConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext * /*ctx*/) override { }
  virtual void exitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext * /*ctx*/) override { }

  virtual void enterParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext * /*ctx*/) override { }
  virtual void exitParenthesizedConditionalExpr(Pcl2Parser::ParenthesizedConditionalExprContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(Pcl2Parser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterParameterTypeList(Pcl2Parser::ParameterTypeListContext * /*ctx*/) override { }
  virtual void exitParameterTypeList(Pcl2Parser::ParameterTypeListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

