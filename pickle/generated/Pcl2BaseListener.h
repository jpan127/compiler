
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

  virtual void enterProgram(Pcl2Parser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(Pcl2Parser::ProgramContext * /*ctx*/) override { }

  virtual void enterHeader(Pcl2Parser::HeaderContext * /*ctx*/) override { }
  virtual void exitHeader(Pcl2Parser::HeaderContext * /*ctx*/) override { }

  virtual void enterMainBlock(Pcl2Parser::MainBlockContext * /*ctx*/) override { }
  virtual void exitMainBlock(Pcl2Parser::MainBlockContext * /*ctx*/) override { }

  virtual void enterBlock(Pcl2Parser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(Pcl2Parser::BlockContext * /*ctx*/) override { }

  virtual void enterDeclarations(Pcl2Parser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(Pcl2Parser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterDeclList(Pcl2Parser::DeclListContext * /*ctx*/) override { }
  virtual void exitDeclList(Pcl2Parser::DeclListContext * /*ctx*/) override { }

  virtual void enterDecl(Pcl2Parser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(Pcl2Parser::DeclContext * /*ctx*/) override { }

  virtual void enterVarList(Pcl2Parser::VarListContext * /*ctx*/) override { }
  virtual void exitVarList(Pcl2Parser::VarListContext * /*ctx*/) override { }

  virtual void enterVarId(Pcl2Parser::VarIdContext * /*ctx*/) override { }
  virtual void exitVarId(Pcl2Parser::VarIdContext * /*ctx*/) override { }

  virtual void enterTypeId(Pcl2Parser::TypeIdContext * /*ctx*/) override { }
  virtual void exitTypeId(Pcl2Parser::TypeIdContext * /*ctx*/) override { }

  virtual void enterCompoundStmt(Pcl2Parser::CompoundStmtContext * /*ctx*/) override { }
  virtual void exitCompoundStmt(Pcl2Parser::CompoundStmtContext * /*ctx*/) override { }

  virtual void enterStmt(Pcl2Parser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(Pcl2Parser::StmtContext * /*ctx*/) override { }

  virtual void enterStmtList(Pcl2Parser::StmtListContext * /*ctx*/) override { }
  virtual void exitStmtList(Pcl2Parser::StmtListContext * /*ctx*/) override { }

  virtual void enterAssignmentStmt(Pcl2Parser::AssignmentStmtContext * /*ctx*/) override { }
  virtual void exitAssignmentStmt(Pcl2Parser::AssignmentStmtContext * /*ctx*/) override { }

  virtual void enterVariable(Pcl2Parser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(Pcl2Parser::VariableContext * /*ctx*/) override { }

  virtual void enterVariableExpr(Pcl2Parser::VariableExprContext * /*ctx*/) override { }
  virtual void exitVariableExpr(Pcl2Parser::VariableExprContext * /*ctx*/) override { }

  virtual void enterAddSubExpr(Pcl2Parser::AddSubExprContext * /*ctx*/) override { }
  virtual void exitAddSubExpr(Pcl2Parser::AddSubExprContext * /*ctx*/) override { }

  virtual void enterUnsignedNumberExpr(Pcl2Parser::UnsignedNumberExprContext * /*ctx*/) override { }
  virtual void exitUnsignedNumberExpr(Pcl2Parser::UnsignedNumberExprContext * /*ctx*/) override { }

  virtual void enterMulDivExpr(Pcl2Parser::MulDivExprContext * /*ctx*/) override { }
  virtual void exitMulDivExpr(Pcl2Parser::MulDivExprContext * /*ctx*/) override { }

  virtual void enterParenExpr(Pcl2Parser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(Pcl2Parser::ParenExprContext * /*ctx*/) override { }

  virtual void enterSignedNumberExpr(Pcl2Parser::SignedNumberExprContext * /*ctx*/) override { }
  virtual void exitSignedNumberExpr(Pcl2Parser::SignedNumberExprContext * /*ctx*/) override { }

  virtual void enterMulDivOp(Pcl2Parser::MulDivOpContext * /*ctx*/) override { }
  virtual void exitMulDivOp(Pcl2Parser::MulDivOpContext * /*ctx*/) override { }

  virtual void enterAddSubOp(Pcl2Parser::AddSubOpContext * /*ctx*/) override { }
  virtual void exitAddSubOp(Pcl2Parser::AddSubOpContext * /*ctx*/) override { }

  virtual void enterSignedNumber(Pcl2Parser::SignedNumberContext * /*ctx*/) override { }
  virtual void exitSignedNumber(Pcl2Parser::SignedNumberContext * /*ctx*/) override { }

  virtual void enterSign(Pcl2Parser::SignContext * /*ctx*/) override { }
  virtual void exitSign(Pcl2Parser::SignContext * /*ctx*/) override { }

  virtual void enterIntegerConst(Pcl2Parser::IntegerConstContext * /*ctx*/) override { }
  virtual void exitIntegerConst(Pcl2Parser::IntegerConstContext * /*ctx*/) override { }

  virtual void enterFloatConst(Pcl2Parser::FloatConstContext * /*ctx*/) override { }
  virtual void exitFloatConst(Pcl2Parser::FloatConstContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

