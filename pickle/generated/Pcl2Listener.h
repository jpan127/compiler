
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from C:/Users/JP/Desktop/compiler/pickle/grammars/Pcl2.g4 by ANTLR 4.7

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

  virtual void enterDeclaration(Pcl2Parser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(Pcl2Parser::DeclarationContext *ctx) = 0;

  virtual void enterDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *ctx) = 0;
  virtual void exitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *ctx) = 0;

  virtual void enterDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *ctx) = 0;
  virtual void exitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *ctx) = 0;

  virtual void enterDeclarator(Pcl2Parser::DeclaratorContext *ctx) = 0;
  virtual void exitDeclarator(Pcl2Parser::DeclaratorContext *ctx) = 0;

  virtual void enterTypeSpecifier(Pcl2Parser::TypeSpecifierContext *ctx) = 0;
  virtual void exitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *ctx) = 0;

  virtual void enterDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *ctx) = 0;
  virtual void exitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *ctx) = 0;

  virtual void enterParameterTypeList(Pcl2Parser::ParameterTypeListContext *ctx) = 0;
  virtual void exitParameterTypeList(Pcl2Parser::ParameterTypeListContext *ctx) = 0;

  virtual void enterParameterList(Pcl2Parser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(Pcl2Parser::ParameterListContext *ctx) = 0;

  virtual void enterParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *ctx) = 0;
  virtual void exitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *ctx) = 0;

  virtual void enterIdentifierList(Pcl2Parser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(Pcl2Parser::IdentifierListContext *ctx) = 0;

  virtual void enterStatement(Pcl2Parser::StatementContext *ctx) = 0;
  virtual void exitStatement(Pcl2Parser::StatementContext *ctx) = 0;

  virtual void enterCompoundStatement(Pcl2Parser::CompoundStatementContext *ctx) = 0;
  virtual void exitCompoundStatement(Pcl2Parser::CompoundStatementContext *ctx) = 0;

  virtual void enterBlockItemList(Pcl2Parser::BlockItemListContext *ctx) = 0;
  virtual void exitBlockItemList(Pcl2Parser::BlockItemListContext *ctx) = 0;

  virtual void enterBlockItem(Pcl2Parser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(Pcl2Parser::BlockItemContext *ctx) = 0;

  virtual void enterExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *ctx) = 0;
  virtual void exitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *ctx) = 0;

  virtual void enterFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *ctx) = 0;


};

