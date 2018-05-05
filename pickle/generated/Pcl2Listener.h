
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

  virtual void enterProgram(Pcl2Parser::ProgramContext *ctx) = 0;
  virtual void exitProgram(Pcl2Parser::ProgramContext *ctx) = 0;

  virtual void enterHeader(Pcl2Parser::HeaderContext *ctx) = 0;
  virtual void exitHeader(Pcl2Parser::HeaderContext *ctx) = 0;

  virtual void enterMainBlock(Pcl2Parser::MainBlockContext *ctx) = 0;
  virtual void exitMainBlock(Pcl2Parser::MainBlockContext *ctx) = 0;

  virtual void enterBlock(Pcl2Parser::BlockContext *ctx) = 0;
  virtual void exitBlock(Pcl2Parser::BlockContext *ctx) = 0;

  virtual void enterDeclarations(Pcl2Parser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(Pcl2Parser::DeclarationsContext *ctx) = 0;

  virtual void enterDeclList(Pcl2Parser::DeclListContext *ctx) = 0;
  virtual void exitDeclList(Pcl2Parser::DeclListContext *ctx) = 0;

  virtual void enterDecl(Pcl2Parser::DeclContext *ctx) = 0;
  virtual void exitDecl(Pcl2Parser::DeclContext *ctx) = 0;

  virtual void enterVarList(Pcl2Parser::VarListContext *ctx) = 0;
  virtual void exitVarList(Pcl2Parser::VarListContext *ctx) = 0;

  virtual void enterVarId(Pcl2Parser::VarIdContext *ctx) = 0;
  virtual void exitVarId(Pcl2Parser::VarIdContext *ctx) = 0;

  virtual void enterTypeId(Pcl2Parser::TypeIdContext *ctx) = 0;
  virtual void exitTypeId(Pcl2Parser::TypeIdContext *ctx) = 0;

  virtual void enterCompoundStmt(Pcl2Parser::CompoundStmtContext *ctx) = 0;
  virtual void exitCompoundStmt(Pcl2Parser::CompoundStmtContext *ctx) = 0;

  virtual void enterStmt(Pcl2Parser::StmtContext *ctx) = 0;
  virtual void exitStmt(Pcl2Parser::StmtContext *ctx) = 0;

  virtual void enterStmtList(Pcl2Parser::StmtListContext *ctx) = 0;
  virtual void exitStmtList(Pcl2Parser::StmtListContext *ctx) = 0;

  virtual void enterAssignmentStmt(Pcl2Parser::AssignmentStmtContext *ctx) = 0;
  virtual void exitAssignmentStmt(Pcl2Parser::AssignmentStmtContext *ctx) = 0;

  virtual void enterVariable(Pcl2Parser::VariableContext *ctx) = 0;
  virtual void exitVariable(Pcl2Parser::VariableContext *ctx) = 0;

  virtual void enterVariableExpr(Pcl2Parser::VariableExprContext *ctx) = 0;
  virtual void exitVariableExpr(Pcl2Parser::VariableExprContext *ctx) = 0;

  virtual void enterAddSubExpr(Pcl2Parser::AddSubExprContext *ctx) = 0;
  virtual void exitAddSubExpr(Pcl2Parser::AddSubExprContext *ctx) = 0;

  virtual void enterUnsignedNumberExpr(Pcl2Parser::UnsignedNumberExprContext *ctx) = 0;
  virtual void exitUnsignedNumberExpr(Pcl2Parser::UnsignedNumberExprContext *ctx) = 0;

  virtual void enterMulDivExpr(Pcl2Parser::MulDivExprContext *ctx) = 0;
  virtual void exitMulDivExpr(Pcl2Parser::MulDivExprContext *ctx) = 0;

  virtual void enterParenExpr(Pcl2Parser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(Pcl2Parser::ParenExprContext *ctx) = 0;

  virtual void enterSignedNumberExpr(Pcl2Parser::SignedNumberExprContext *ctx) = 0;
  virtual void exitSignedNumberExpr(Pcl2Parser::SignedNumberExprContext *ctx) = 0;

  virtual void enterMulDivOp(Pcl2Parser::MulDivOpContext *ctx) = 0;
  virtual void exitMulDivOp(Pcl2Parser::MulDivOpContext *ctx) = 0;

  virtual void enterAddSubOp(Pcl2Parser::AddSubOpContext *ctx) = 0;
  virtual void exitAddSubOp(Pcl2Parser::AddSubOpContext *ctx) = 0;

  virtual void enterSignedNumber(Pcl2Parser::SignedNumberContext *ctx) = 0;
  virtual void exitSignedNumber(Pcl2Parser::SignedNumberContext *ctx) = 0;

  virtual void enterSign(Pcl2Parser::SignContext *ctx) = 0;
  virtual void exitSign(Pcl2Parser::SignContext *ctx) = 0;

  virtual void enterIntegerConst(Pcl2Parser::IntegerConstContext *ctx) = 0;
  virtual void exitIntegerConst(Pcl2Parser::IntegerConstContext *ctx) = 0;

  virtual void enterFloatConst(Pcl2Parser::FloatConstContext *ctx) = 0;
  virtual void exitFloatConst(Pcl2Parser::FloatConstContext *ctx) = 0;


};

