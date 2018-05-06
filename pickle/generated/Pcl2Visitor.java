// Generated from C:/Users/JP/Desktop/compiler/pickle/grammars/Pcl2.g4 by ANTLR 4.7

#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;

import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link Pcl2Parser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface Pcl2Visitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(Pcl2Parser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#header}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitHeader(Pcl2Parser.HeaderContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#mainBlock}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMainBlock(Pcl2Parser.MainBlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock(Pcl2Parser.BlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#declarations}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclarations(Pcl2Parser.DeclarationsContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#varList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVarList(Pcl2Parser.VarListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#varId}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVarId(Pcl2Parser.VarIdContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#typeId}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeId(Pcl2Parser.TypeIdContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#compoundStmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCompoundStmt(Pcl2Parser.CompoundStmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStmt(Pcl2Parser.StmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#stmtList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStmtList(Pcl2Parser.StmtListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#assignmentStmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignmentStmt(Pcl2Parser.AssignmentStmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#variable}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariable(Pcl2Parser.VariableContext ctx);
	/**
	 * Visit a parse tree produced by the {@code variableExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableExpr(Pcl2Parser.VariableExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code addSubExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAddSubExpr(Pcl2Parser.AddSubExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code unsignedNumberExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnsignedNumberExpr(Pcl2Parser.UnsignedNumberExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code mulDivExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMulDivExpr(Pcl2Parser.MulDivExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code parenExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParenExpr(Pcl2Parser.ParenExprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code signedNumberExpr}
	 * labeled alternative in {@link Pcl2Parser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSignedNumberExpr(Pcl2Parser.SignedNumberExprContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#mulDivOp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMulDivOp(Pcl2Parser.MulDivOpContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#addSubOp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAddSubOp(Pcl2Parser.AddSubOpContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#signedNumber}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSignedNumber(Pcl2Parser.SignedNumberContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pcl2Parser#sign}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSign(Pcl2Parser.SignContext ctx);
	/**
	 * Visit a parse tree produced by the {@code integerConst}
	 * labeled alternative in {@link Pcl2Parser#number}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIntegerConst(Pcl2Parser.IntegerConstContext ctx);
	/**
	 * Visit a parse tree produced by the {@code floatConst}
	 * labeled alternative in {@link Pcl2Parser#number}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFloatConst(Pcl2Parser.FloatConstContext ctx);
}