// Generated from C:/Users/JP/Desktop/compiler/pickle/grammars/Pcl2.g4 by ANTLR 4.7

#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link Pcl2Parser}.
 */
public interface Pcl2Listener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(Pcl2Parser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(Pcl2Parser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#header}.
	 * @param ctx the parse tree
	 */
	void enterHeader(Pcl2Parser.HeaderContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#header}.
	 * @param ctx the parse tree
	 */
	void exitHeader(Pcl2Parser.HeaderContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#mainBlock}.
	 * @param ctx the parse tree
	 */
	void enterMainBlock(Pcl2Parser.MainBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#mainBlock}.
	 * @param ctx the parse tree
	 */
	void exitMainBlock(Pcl2Parser.MainBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(Pcl2Parser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(Pcl2Parser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#declarations}.
	 * @param ctx the parse tree
	 */
	void enterDeclarations(Pcl2Parser.DeclarationsContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#declarations}.
	 * @param ctx the parse tree
	 */
	void exitDeclarations(Pcl2Parser.DeclarationsContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#varList}.
	 * @param ctx the parse tree
	 */
	void enterVarList(Pcl2Parser.VarListContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#varList}.
	 * @param ctx the parse tree
	 */
	void exitVarList(Pcl2Parser.VarListContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#varId}.
	 * @param ctx the parse tree
	 */
	void enterVarId(Pcl2Parser.VarIdContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#varId}.
	 * @param ctx the parse tree
	 */
	void exitVarId(Pcl2Parser.VarIdContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#typeId}.
	 * @param ctx the parse tree
	 */
	void enterTypeId(Pcl2Parser.TypeIdContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#typeId}.
	 * @param ctx the parse tree
	 */
	void exitTypeId(Pcl2Parser.TypeIdContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#compoundStmt}.
	 * @param ctx the parse tree
	 */
	void enterCompoundStmt(Pcl2Parser.CompoundStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#compoundStmt}.
	 * @param ctx the parse tree
	 */
	void exitCompoundStmt(Pcl2Parser.CompoundStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(Pcl2Parser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(Pcl2Parser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#stmtList}.
	 * @param ctx the parse tree
	 */
	void enterStmtList(Pcl2Parser.StmtListContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#stmtList}.
	 * @param ctx the parse tree
	 */
	void exitStmtList(Pcl2Parser.StmtListContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#assignmentStmt}.
	 * @param ctx the parse tree
	 */
	void enterAssignmentStmt(Pcl2Parser.AssignmentStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#assignmentStmt}.
	 * @param ctx the parse tree
	 */
	void exitAssignmentStmt(Pcl2Parser.AssignmentStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(Pcl2Parser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(Pcl2Parser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by the {@code variableExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void enterVariableExpr(Pcl2Parser.VariableExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code variableExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void exitVariableExpr(Pcl2Parser.VariableExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code addSubExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAddSubExpr(Pcl2Parser.AddSubExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code addSubExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAddSubExpr(Pcl2Parser.AddSubExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code unsignedNumberExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void enterUnsignedNumberExpr(Pcl2Parser.UnsignedNumberExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code unsignedNumberExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void exitUnsignedNumberExpr(Pcl2Parser.UnsignedNumberExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code mulDivExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void enterMulDivExpr(Pcl2Parser.MulDivExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code mulDivExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void exitMulDivExpr(Pcl2Parser.MulDivExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code parenExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParenExpr(Pcl2Parser.ParenExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code parenExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParenExpr(Pcl2Parser.ParenExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code signedNumberExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSignedNumberExpr(Pcl2Parser.SignedNumberExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code signedNumberExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSignedNumberExpr(Pcl2Parser.SignedNumberExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#mulDivOp}.
	 * @param ctx the parse tree
	 */
	void enterMulDivOp(Pcl2Parser.MulDivOpContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#mulDivOp}.
	 * @param ctx the parse tree
	 */
	void exitMulDivOp(Pcl2Parser.MulDivOpContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#addSubOp}.
	 * @param ctx the parse tree
	 */
	void enterAddSubOp(Pcl2Parser.AddSubOpContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#addSubOp}.
	 * @param ctx the parse tree
	 */
	void exitAddSubOp(Pcl2Parser.AddSubOpContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#signedNumber}.
	 * @param ctx the parse tree
	 */
	void enterSignedNumber(Pcl2Parser.SignedNumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#signedNumber}.
	 * @param ctx the parse tree
	 */
	void exitSignedNumber(Pcl2Parser.SignedNumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link Pcl2Parser#sign}.
	 * @param ctx the parse tree
	 */
	void enterSign(Pcl2Parser.SignContext ctx);
	/**
	 * Exit a parse tree produced by {@link Pcl2Parser#sign}.
	 * @param ctx the parse tree
	 */
	void exitSign(Pcl2Parser.SignContext ctx);
	/**
	 * Enter a parse tree produced by the {@code integerConst}
	 * labeled alternative in {@link Pcl2Parser#number}.
	 * @param ctx the parse tree
	 */
	void enterIntegerConst(Pcl2Parser.IntegerConstContext ctx);
	/**
	 * Exit a parse tree produced by the {@code integerConst}
	 * labeled alternative in {@link Pcl2Parser#number}.
	 * @param ctx the parse tree
	 */
	void exitIntegerConst(Pcl2Parser.IntegerConstContext ctx);
	/**
	 * Enter a parse tree produced by the {@code floatConst}
	 * labeled alternative in {@link Pcl2Parser#number}.
	 * @param ctx the parse tree
	 */
	void enterFloatConst(Pcl2Parser.FloatConstContext ctx);
	/**
	 * Exit a parse tree produced by the {@code floatConst}
	 * labeled alternative in {@link Pcl2Parser#number}.
	 * @param ctx the parse tree
	 */
	void exitFloatConst(Pcl2Parser.FloatConstContext ctx);
}