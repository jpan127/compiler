
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from C:/Users/JP/Desktop/compiler/pickle/grammars/Pcl2.g4 by ANTLR 4.7

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

  virtual void enterDeclaration(Pcl2Parser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(Pcl2Parser::DeclarationContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext * /*ctx*/) override { }

  virtual void enterDeclarator(Pcl2Parser::DeclaratorContext * /*ctx*/) override { }
  virtual void exitDeclarator(Pcl2Parser::DeclaratorContext * /*ctx*/) override { }

  virtual void enterTypeSpecifier(Pcl2Parser::TypeSpecifierContext * /*ctx*/) override { }
  virtual void exitTypeSpecifier(Pcl2Parser::TypeSpecifierContext * /*ctx*/) override { }

  virtual void enterDirectDeclarator(Pcl2Parser::DirectDeclaratorContext * /*ctx*/) override { }
  virtual void exitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext * /*ctx*/) override { }

  virtual void enterParameterTypeList(Pcl2Parser::ParameterTypeListContext * /*ctx*/) override { }
  virtual void exitParameterTypeList(Pcl2Parser::ParameterTypeListContext * /*ctx*/) override { }

  virtual void enterParameterList(Pcl2Parser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(Pcl2Parser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameterDeclaration(Pcl2Parser::ParameterDeclarationContext * /*ctx*/) override { }
  virtual void exitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext * /*ctx*/) override { }

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

  virtual void enterExternalDeclaration(Pcl2Parser::ExternalDeclarationContext * /*ctx*/) override { }
  virtual void exitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

