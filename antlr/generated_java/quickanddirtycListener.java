// Generated from quickanddirtyc.g4 by ANTLR 4.7
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link quickanddirtycParser}.
 */
public interface quickanddirtycListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#primaryExpression}.
	 * @param ctx the parse tree
	 */
	void enterPrimaryExpression(quickanddirtycParser.PrimaryExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#primaryExpression}.
	 * @param ctx the parse tree
	 */
	void exitPrimaryExpression(quickanddirtycParser.PrimaryExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#postfixExpression}.
	 * @param ctx the parse tree
	 */
	void enterPostfixExpression(quickanddirtycParser.PostfixExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#postfixExpression}.
	 * @param ctx the parse tree
	 */
	void exitPostfixExpression(quickanddirtycParser.PostfixExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#argumentExpressionList}.
	 * @param ctx the parse tree
	 */
	void enterArgumentExpressionList(quickanddirtycParser.ArgumentExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#argumentExpressionList}.
	 * @param ctx the parse tree
	 */
	void exitArgumentExpressionList(quickanddirtycParser.ArgumentExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#unaryExpression}.
	 * @param ctx the parse tree
	 */
	void enterUnaryExpression(quickanddirtycParser.UnaryExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#unaryExpression}.
	 * @param ctx the parse tree
	 */
	void exitUnaryExpression(quickanddirtycParser.UnaryExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#unaryOperator}.
	 * @param ctx the parse tree
	 */
	void enterUnaryOperator(quickanddirtycParser.UnaryOperatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#unaryOperator}.
	 * @param ctx the parse tree
	 */
	void exitUnaryOperator(quickanddirtycParser.UnaryOperatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#castExpression}.
	 * @param ctx the parse tree
	 */
	void enterCastExpression(quickanddirtycParser.CastExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#castExpression}.
	 * @param ctx the parse tree
	 */
	void exitCastExpression(quickanddirtycParser.CastExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#multiplicativeExpression}.
	 * @param ctx the parse tree
	 */
	void enterMultiplicativeExpression(quickanddirtycParser.MultiplicativeExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#multiplicativeExpression}.
	 * @param ctx the parse tree
	 */
	void exitMultiplicativeExpression(quickanddirtycParser.MultiplicativeExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#additiveExpression}.
	 * @param ctx the parse tree
	 */
	void enterAdditiveExpression(quickanddirtycParser.AdditiveExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#additiveExpression}.
	 * @param ctx the parse tree
	 */
	void exitAdditiveExpression(quickanddirtycParser.AdditiveExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#shiftExpression}.
	 * @param ctx the parse tree
	 */
	void enterShiftExpression(quickanddirtycParser.ShiftExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#shiftExpression}.
	 * @param ctx the parse tree
	 */
	void exitShiftExpression(quickanddirtycParser.ShiftExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#relationalExpression}.
	 * @param ctx the parse tree
	 */
	void enterRelationalExpression(quickanddirtycParser.RelationalExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#relationalExpression}.
	 * @param ctx the parse tree
	 */
	void exitRelationalExpression(quickanddirtycParser.RelationalExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#equalityExpression}.
	 * @param ctx the parse tree
	 */
	void enterEqualityExpression(quickanddirtycParser.EqualityExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#equalityExpression}.
	 * @param ctx the parse tree
	 */
	void exitEqualityExpression(quickanddirtycParser.EqualityExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#andExpression}.
	 * @param ctx the parse tree
	 */
	void enterAndExpression(quickanddirtycParser.AndExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#andExpression}.
	 * @param ctx the parse tree
	 */
	void exitAndExpression(quickanddirtycParser.AndExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#exclusiveOrExpression}.
	 * @param ctx the parse tree
	 */
	void enterExclusiveOrExpression(quickanddirtycParser.ExclusiveOrExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#exclusiveOrExpression}.
	 * @param ctx the parse tree
	 */
	void exitExclusiveOrExpression(quickanddirtycParser.ExclusiveOrExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#inclusiveOrExpression}.
	 * @param ctx the parse tree
	 */
	void enterInclusiveOrExpression(quickanddirtycParser.InclusiveOrExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#inclusiveOrExpression}.
	 * @param ctx the parse tree
	 */
	void exitInclusiveOrExpression(quickanddirtycParser.InclusiveOrExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#logicalAndExpression}.
	 * @param ctx the parse tree
	 */
	void enterLogicalAndExpression(quickanddirtycParser.LogicalAndExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#logicalAndExpression}.
	 * @param ctx the parse tree
	 */
	void exitLogicalAndExpression(quickanddirtycParser.LogicalAndExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#logicalOrExpression}.
	 * @param ctx the parse tree
	 */
	void enterLogicalOrExpression(quickanddirtycParser.LogicalOrExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#logicalOrExpression}.
	 * @param ctx the parse tree
	 */
	void exitLogicalOrExpression(quickanddirtycParser.LogicalOrExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#conditionalExpression}.
	 * @param ctx the parse tree
	 */
	void enterConditionalExpression(quickanddirtycParser.ConditionalExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#conditionalExpression}.
	 * @param ctx the parse tree
	 */
	void exitConditionalExpression(quickanddirtycParser.ConditionalExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#assignmentExpression}.
	 * @param ctx the parse tree
	 */
	void enterAssignmentExpression(quickanddirtycParser.AssignmentExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#assignmentExpression}.
	 * @param ctx the parse tree
	 */
	void exitAssignmentExpression(quickanddirtycParser.AssignmentExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#assignmentOperator}.
	 * @param ctx the parse tree
	 */
	void enterAssignmentOperator(quickanddirtycParser.AssignmentOperatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#assignmentOperator}.
	 * @param ctx the parse tree
	 */
	void exitAssignmentOperator(quickanddirtycParser.AssignmentOperatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(quickanddirtycParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(quickanddirtycParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#constantExpression}.
	 * @param ctx the parse tree
	 */
	void enterConstantExpression(quickanddirtycParser.ConstantExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#constantExpression}.
	 * @param ctx the parse tree
	 */
	void exitConstantExpression(quickanddirtycParser.ConstantExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration(quickanddirtycParser.DeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration(quickanddirtycParser.DeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#declarationSpecifiers}.
	 * @param ctx the parse tree
	 */
	void enterDeclarationSpecifiers(quickanddirtycParser.DeclarationSpecifiersContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#declarationSpecifiers}.
	 * @param ctx the parse tree
	 */
	void exitDeclarationSpecifiers(quickanddirtycParser.DeclarationSpecifiersContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#declarationSpecifiers2}.
	 * @param ctx the parse tree
	 */
	void enterDeclarationSpecifiers2(quickanddirtycParser.DeclarationSpecifiers2Context ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#declarationSpecifiers2}.
	 * @param ctx the parse tree
	 */
	void exitDeclarationSpecifiers2(quickanddirtycParser.DeclarationSpecifiers2Context ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#declarationSpecifier}.
	 * @param ctx the parse tree
	 */
	void enterDeclarationSpecifier(quickanddirtycParser.DeclarationSpecifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#declarationSpecifier}.
	 * @param ctx the parse tree
	 */
	void exitDeclarationSpecifier(quickanddirtycParser.DeclarationSpecifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#initDeclaratorList}.
	 * @param ctx the parse tree
	 */
	void enterInitDeclaratorList(quickanddirtycParser.InitDeclaratorListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#initDeclaratorList}.
	 * @param ctx the parse tree
	 */
	void exitInitDeclaratorList(quickanddirtycParser.InitDeclaratorListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#initDeclarator}.
	 * @param ctx the parse tree
	 */
	void enterInitDeclarator(quickanddirtycParser.InitDeclaratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#initDeclarator}.
	 * @param ctx the parse tree
	 */
	void exitInitDeclarator(quickanddirtycParser.InitDeclaratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#storageClassSpecifier}.
	 * @param ctx the parse tree
	 */
	void enterStorageClassSpecifier(quickanddirtycParser.StorageClassSpecifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#storageClassSpecifier}.
	 * @param ctx the parse tree
	 */
	void exitStorageClassSpecifier(quickanddirtycParser.StorageClassSpecifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#typeSpecifier}.
	 * @param ctx the parse tree
	 */
	void enterTypeSpecifier(quickanddirtycParser.TypeSpecifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#typeSpecifier}.
	 * @param ctx the parse tree
	 */
	void exitTypeSpecifier(quickanddirtycParser.TypeSpecifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#specifierQualifierList}.
	 * @param ctx the parse tree
	 */
	void enterSpecifierQualifierList(quickanddirtycParser.SpecifierQualifierListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#specifierQualifierList}.
	 * @param ctx the parse tree
	 */
	void exitSpecifierQualifierList(quickanddirtycParser.SpecifierQualifierListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#typeQualifier}.
	 * @param ctx the parse tree
	 */
	void enterTypeQualifier(quickanddirtycParser.TypeQualifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#typeQualifier}.
	 * @param ctx the parse tree
	 */
	void exitTypeQualifier(quickanddirtycParser.TypeQualifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#declarator}.
	 * @param ctx the parse tree
	 */
	void enterDeclarator(quickanddirtycParser.DeclaratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#declarator}.
	 * @param ctx the parse tree
	 */
	void exitDeclarator(quickanddirtycParser.DeclaratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#directDeclarator}.
	 * @param ctx the parse tree
	 */
	void enterDirectDeclarator(quickanddirtycParser.DirectDeclaratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#directDeclarator}.
	 * @param ctx the parse tree
	 */
	void exitDirectDeclarator(quickanddirtycParser.DirectDeclaratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#nestedParenthesesBlock}.
	 * @param ctx the parse tree
	 */
	void enterNestedParenthesesBlock(quickanddirtycParser.NestedParenthesesBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#nestedParenthesesBlock}.
	 * @param ctx the parse tree
	 */
	void exitNestedParenthesesBlock(quickanddirtycParser.NestedParenthesesBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#pointer}.
	 * @param ctx the parse tree
	 */
	void enterPointer(quickanddirtycParser.PointerContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#pointer}.
	 * @param ctx the parse tree
	 */
	void exitPointer(quickanddirtycParser.PointerContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#typeQualifierList}.
	 * @param ctx the parse tree
	 */
	void enterTypeQualifierList(quickanddirtycParser.TypeQualifierListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#typeQualifierList}.
	 * @param ctx the parse tree
	 */
	void exitTypeQualifierList(quickanddirtycParser.TypeQualifierListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#parameterTypeList}.
	 * @param ctx the parse tree
	 */
	void enterParameterTypeList(quickanddirtycParser.ParameterTypeListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#parameterTypeList}.
	 * @param ctx the parse tree
	 */
	void exitParameterTypeList(quickanddirtycParser.ParameterTypeListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void enterParameterList(quickanddirtycParser.ParameterListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void exitParameterList(quickanddirtycParser.ParameterListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#parameterDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterParameterDeclaration(quickanddirtycParser.ParameterDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#parameterDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitParameterDeclaration(quickanddirtycParser.ParameterDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#identifierList}.
	 * @param ctx the parse tree
	 */
	void enterIdentifierList(quickanddirtycParser.IdentifierListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#identifierList}.
	 * @param ctx the parse tree
	 */
	void exitIdentifierList(quickanddirtycParser.IdentifierListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#typeName}.
	 * @param ctx the parse tree
	 */
	void enterTypeName(quickanddirtycParser.TypeNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#typeName}.
	 * @param ctx the parse tree
	 */
	void exitTypeName(quickanddirtycParser.TypeNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#abstractDeclarator}.
	 * @param ctx the parse tree
	 */
	void enterAbstractDeclarator(quickanddirtycParser.AbstractDeclaratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#abstractDeclarator}.
	 * @param ctx the parse tree
	 */
	void exitAbstractDeclarator(quickanddirtycParser.AbstractDeclaratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#directAbstractDeclarator}.
	 * @param ctx the parse tree
	 */
	void enterDirectAbstractDeclarator(quickanddirtycParser.DirectAbstractDeclaratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#directAbstractDeclarator}.
	 * @param ctx the parse tree
	 */
	void exitDirectAbstractDeclarator(quickanddirtycParser.DirectAbstractDeclaratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#initializer}.
	 * @param ctx the parse tree
	 */
	void enterInitializer(quickanddirtycParser.InitializerContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#initializer}.
	 * @param ctx the parse tree
	 */
	void exitInitializer(quickanddirtycParser.InitializerContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#initializerList}.
	 * @param ctx the parse tree
	 */
	void enterInitializerList(quickanddirtycParser.InitializerListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#initializerList}.
	 * @param ctx the parse tree
	 */
	void exitInitializerList(quickanddirtycParser.InitializerListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#designation}.
	 * @param ctx the parse tree
	 */
	void enterDesignation(quickanddirtycParser.DesignationContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#designation}.
	 * @param ctx the parse tree
	 */
	void exitDesignation(quickanddirtycParser.DesignationContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#designatorList}.
	 * @param ctx the parse tree
	 */
	void enterDesignatorList(quickanddirtycParser.DesignatorListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#designatorList}.
	 * @param ctx the parse tree
	 */
	void exitDesignatorList(quickanddirtycParser.DesignatorListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#designator}.
	 * @param ctx the parse tree
	 */
	void enterDesignator(quickanddirtycParser.DesignatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#designator}.
	 * @param ctx the parse tree
	 */
	void exitDesignator(quickanddirtycParser.DesignatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(quickanddirtycParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(quickanddirtycParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#labeledStatement}.
	 * @param ctx the parse tree
	 */
	void enterLabeledStatement(quickanddirtycParser.LabeledStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#labeledStatement}.
	 * @param ctx the parse tree
	 */
	void exitLabeledStatement(quickanddirtycParser.LabeledStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#compoundStatement}.
	 * @param ctx the parse tree
	 */
	void enterCompoundStatement(quickanddirtycParser.CompoundStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#compoundStatement}.
	 * @param ctx the parse tree
	 */
	void exitCompoundStatement(quickanddirtycParser.CompoundStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#blockItemList}.
	 * @param ctx the parse tree
	 */
	void enterBlockItemList(quickanddirtycParser.BlockItemListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#blockItemList}.
	 * @param ctx the parse tree
	 */
	void exitBlockItemList(quickanddirtycParser.BlockItemListContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#blockItem}.
	 * @param ctx the parse tree
	 */
	void enterBlockItem(quickanddirtycParser.BlockItemContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#blockItem}.
	 * @param ctx the parse tree
	 */
	void exitBlockItem(quickanddirtycParser.BlockItemContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#expressionStatement}.
	 * @param ctx the parse tree
	 */
	void enterExpressionStatement(quickanddirtycParser.ExpressionStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#expressionStatement}.
	 * @param ctx the parse tree
	 */
	void exitExpressionStatement(quickanddirtycParser.ExpressionStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#selectionStatement}.
	 * @param ctx the parse tree
	 */
	void enterSelectionStatement(quickanddirtycParser.SelectionStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#selectionStatement}.
	 * @param ctx the parse tree
	 */
	void exitSelectionStatement(quickanddirtycParser.SelectionStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#iterationStatement}.
	 * @param ctx the parse tree
	 */
	void enterIterationStatement(quickanddirtycParser.IterationStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#iterationStatement}.
	 * @param ctx the parse tree
	 */
	void exitIterationStatement(quickanddirtycParser.IterationStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#forCondition}.
	 * @param ctx the parse tree
	 */
	void enterForCondition(quickanddirtycParser.ForConditionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#forCondition}.
	 * @param ctx the parse tree
	 */
	void exitForCondition(quickanddirtycParser.ForConditionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#forDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterForDeclaration(quickanddirtycParser.ForDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#forDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitForDeclaration(quickanddirtycParser.ForDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#forExpression}.
	 * @param ctx the parse tree
	 */
	void enterForExpression(quickanddirtycParser.ForExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#forExpression}.
	 * @param ctx the parse tree
	 */
	void exitForExpression(quickanddirtycParser.ForExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#jumpStatement}.
	 * @param ctx the parse tree
	 */
	void enterJumpStatement(quickanddirtycParser.JumpStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#jumpStatement}.
	 * @param ctx the parse tree
	 */
	void exitJumpStatement(quickanddirtycParser.JumpStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void enterCompilationUnit(quickanddirtycParser.CompilationUnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void exitCompilationUnit(quickanddirtycParser.CompilationUnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#translationUnit}.
	 * @param ctx the parse tree
	 */
	void enterTranslationUnit(quickanddirtycParser.TranslationUnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#translationUnit}.
	 * @param ctx the parse tree
	 */
	void exitTranslationUnit(quickanddirtycParser.TranslationUnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#externalDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterExternalDeclaration(quickanddirtycParser.ExternalDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#externalDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitExternalDeclaration(quickanddirtycParser.ExternalDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#functionDefinition}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDefinition(quickanddirtycParser.FunctionDefinitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#functionDefinition}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDefinition(quickanddirtycParser.FunctionDefinitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link quickanddirtycParser#declarationList}.
	 * @param ctx the parse tree
	 */
	void enterDeclarationList(quickanddirtycParser.DeclarationListContext ctx);
	/**
	 * Exit a parse tree produced by {@link quickanddirtycParser#declarationList}.
	 * @param ctx the parse tree
	 */
	void exitDeclarationList(quickanddirtycParser.DeclarationListContext ctx);
}