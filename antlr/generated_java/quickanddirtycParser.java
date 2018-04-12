// Generated from quickanddirtyc.g4 by ANTLR 4.7
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class quickanddirtycParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, Break=6, Case=7, Char=8, Const=9, 
		Continue=10, Default=11, Double=12, Else=13, Extern=14, Float=15, For=16, 
		If=17, Int=18, Long=19, Return=20, Short=21, Signed=22, Sizeof=23, Static=24, 
		Switch=25, Typedef=26, Unsigned=27, Void=28, While=29, LeftParen=30, RightParen=31, 
		LeftBracket=32, RightBracket=33, LeftBrace=34, RightBrace=35, Less=36, 
		LessEqual=37, Greater=38, GreaterEqual=39, LeftShift=40, RightShift=41, 
		Plus=42, PlusPlus=43, Minus=44, MinusMinus=45, Star=46, Div=47, Mod=48, 
		And=49, Or=50, AndAnd=51, OrOr=52, Caret=53, Not=54, Tilde=55, Question=56, 
		Colon=57, Semi=58, Comma=59, Assign=60, StarAssign=61, DivAssign=62, ModAssign=63, 
		PlusAssign=64, MinusAssign=65, LeftShiftAssign=66, RightShiftAssign=67, 
		AndAssign=68, XorAssign=69, OrAssign=70, Equal=71, NotEqual=72, Arrow=73, 
		Dot=74, Ellipsis=75, Identifier=76, Constant=77, DigitSequence=78, StringLiteral=79, 
		Whitespace=80, Newline=81, BlockComment=82, LineComment=83;
	public static final int
		RULE_primaryExpression = 0, RULE_postfixExpression = 1, RULE_argumentExpressionList = 2, 
		RULE_unaryExpression = 3, RULE_unaryOperator = 4, RULE_castExpression = 5, 
		RULE_multiplicativeExpression = 6, RULE_additiveExpression = 7, RULE_shiftExpression = 8, 
		RULE_relationalExpression = 9, RULE_equalityExpression = 10, RULE_andExpression = 11, 
		RULE_exclusiveOrExpression = 12, RULE_inclusiveOrExpression = 13, RULE_logicalAndExpression = 14, 
		RULE_logicalOrExpression = 15, RULE_conditionalExpression = 16, RULE_assignmentExpression = 17, 
		RULE_assignmentOperator = 18, RULE_expression = 19, RULE_constantExpression = 20, 
		RULE_declaration = 21, RULE_declarationSpecifiers = 22, RULE_declarationSpecifiers2 = 23, 
		RULE_declarationSpecifier = 24, RULE_initDeclaratorList = 25, RULE_initDeclarator = 26, 
		RULE_storageClassSpecifier = 27, RULE_typeSpecifier = 28, RULE_specifierQualifierList = 29, 
		RULE_typeQualifier = 30, RULE_declarator = 31, RULE_directDeclarator = 32, 
		RULE_nestedParenthesesBlock = 33, RULE_pointer = 34, RULE_typeQualifierList = 35, 
		RULE_parameterTypeList = 36, RULE_parameterList = 37, RULE_parameterDeclaration = 38, 
		RULE_identifierList = 39, RULE_typeName = 40, RULE_abstractDeclarator = 41, 
		RULE_directAbstractDeclarator = 42, RULE_initializer = 43, RULE_initializerList = 44, 
		RULE_designation = 45, RULE_designatorList = 46, RULE_designator = 47, 
		RULE_statement = 48, RULE_labeledStatement = 49, RULE_compoundStatement = 50, 
		RULE_blockItemList = 51, RULE_blockItem = 52, RULE_expressionStatement = 53, 
		RULE_selectionStatement = 54, RULE_iterationStatement = 55, RULE_forCondition = 56, 
		RULE_forDeclaration = 57, RULE_forExpression = 58, RULE_jumpStatement = 59, 
		RULE_compilationUnit = 60, RULE_translationUnit = 61, RULE_externalDeclaration = 62, 
		RULE_functionDefinition = 63, RULE_declarationList = 64;
	public static final String[] ruleNames = {
		"primaryExpression", "postfixExpression", "argumentExpressionList", "unaryExpression", 
		"unaryOperator", "castExpression", "multiplicativeExpression", "additiveExpression", 
		"shiftExpression", "relationalExpression", "equalityExpression", "andExpression", 
		"exclusiveOrExpression", "inclusiveOrExpression", "logicalAndExpression", 
		"logicalOrExpression", "conditionalExpression", "assignmentExpression", 
		"assignmentOperator", "expression", "constantExpression", "declaration", 
		"declarationSpecifiers", "declarationSpecifiers2", "declarationSpecifier", 
		"initDeclaratorList", "initDeclarator", "storageClassSpecifier", "typeSpecifier", 
		"specifierQualifierList", "typeQualifier", "declarator", "directDeclarator", 
		"nestedParenthesesBlock", "pointer", "typeQualifierList", "parameterTypeList", 
		"parameterList", "parameterDeclaration", "identifierList", "typeName", 
		"abstractDeclarator", "directAbstractDeclarator", "initializer", "initializerList", 
		"designation", "designatorList", "designator", "statement", "labeledStatement", 
		"compoundStatement", "blockItemList", "blockItem", "expressionStatement", 
		"selectionStatement", "iterationStatement", "forCondition", "forDeclaration", 
		"forExpression", "jumpStatement", "compilationUnit", "translationUnit", 
		"externalDeclaration", "functionDefinition", "declarationList"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'__extension__'", "'_Alignof'", "'auto'", "'register'", "'goto'", 
		"'break'", "'case'", "'char'", "'const'", "'continue'", "'default'", "'double'", 
		"'else'", "'extern'", "'float'", "'for'", "'if'", "'int'", "'long'", "'return'", 
		"'short'", "'signed'", "'sizeof'", "'static'", "'switch'", "'typedef'", 
		"'unsigned'", "'void'", "'while'", "'('", "')'", "'['", "']'", "'{'", 
		"'}'", "'<'", "'<='", "'>'", "'>='", "'<<'", "'>>'", "'+'", "'++'", "'-'", 
		"'--'", "'*'", "'/'", "'%'", "'&'", "'|'", "'&&'", "'||'", "'^'", "'!'", 
		"'~'", "'?'", "':'", "';'", "','", "'='", "'*='", "'/='", "'%='", "'+='", 
		"'-='", "'<<='", "'>>='", "'&='", "'^='", "'|='", "'=='", "'!='", "'->'", 
		"'.'", "'...'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, "Break", "Case", "Char", "Const", 
		"Continue", "Default", "Double", "Else", "Extern", "Float", "For", "If", 
		"Int", "Long", "Return", "Short", "Signed", "Sizeof", "Static", "Switch", 
		"Typedef", "Unsigned", "Void", "While", "LeftParen", "RightParen", "LeftBracket", 
		"RightBracket", "LeftBrace", "RightBrace", "Less", "LessEqual", "Greater", 
		"GreaterEqual", "LeftShift", "RightShift", "Plus", "PlusPlus", "Minus", 
		"MinusMinus", "Star", "Div", "Mod", "And", "Or", "AndAnd", "OrOr", "Caret", 
		"Not", "Tilde", "Question", "Colon", "Semi", "Comma", "Assign", "StarAssign", 
		"DivAssign", "ModAssign", "PlusAssign", "MinusAssign", "LeftShiftAssign", 
		"RightShiftAssign", "AndAssign", "XorAssign", "OrAssign", "Equal", "NotEqual", 
		"Arrow", "Dot", "Ellipsis", "Identifier", "Constant", "DigitSequence", 
		"StringLiteral", "Whitespace", "Newline", "BlockComment", "LineComment"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "quickanddirtyc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public quickanddirtycParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class PrimaryExpressionContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(quickanddirtycParser.Identifier, 0); }
		public TerminalNode Constant() { return getToken(quickanddirtycParser.Constant, 0); }
		public List<TerminalNode> StringLiteral() { return getTokens(quickanddirtycParser.StringLiteral); }
		public TerminalNode StringLiteral(int i) {
			return getToken(quickanddirtycParser.StringLiteral, i);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public PrimaryExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primaryExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterPrimaryExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitPrimaryExpression(this);
		}
	}

	public final PrimaryExpressionContext primaryExpression() throws RecognitionException {
		PrimaryExpressionContext _localctx = new PrimaryExpressionContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_primaryExpression);
		try {
			int _alt;
			setState(141);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(130);
				match(Identifier);
				}
				break;
			case Constant:
				enterOuterAlt(_localctx, 2);
				{
				setState(131);
				match(Constant);
				}
				break;
			case StringLiteral:
				enterOuterAlt(_localctx, 3);
				{
				setState(133); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(132);
						match(StringLiteral);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(135); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case LeftParen:
				enterOuterAlt(_localctx, 4);
				{
				setState(137);
				match(LeftParen);
				setState(138);
				expression(0);
				setState(139);
				match(RightParen);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PostfixExpressionContext extends ParserRuleContext {
		public PrimaryExpressionContext primaryExpression() {
			return getRuleContext(PrimaryExpressionContext.class,0);
		}
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public InitializerListContext initializerList() {
			return getRuleContext(InitializerListContext.class,0);
		}
		public PostfixExpressionContext postfixExpression() {
			return getRuleContext(PostfixExpressionContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ArgumentExpressionListContext argumentExpressionList() {
			return getRuleContext(ArgumentExpressionListContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(quickanddirtycParser.Identifier, 0); }
		public PostfixExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_postfixExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterPostfixExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitPostfixExpression(this);
		}
	}

	public final PostfixExpressionContext postfixExpression() throws RecognitionException {
		return postfixExpression(0);
	}

	private PostfixExpressionContext postfixExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		PostfixExpressionContext _localctx = new PostfixExpressionContext(_ctx, _parentState);
		PostfixExpressionContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_postfixExpression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(177);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				{
				setState(144);
				primaryExpression();
				}
				break;
			case 2:
				{
				setState(145);
				match(LeftParen);
				setState(146);
				typeName();
				setState(147);
				match(RightParen);
				setState(148);
				match(LeftBrace);
				setState(149);
				initializerList(0);
				setState(150);
				match(RightBrace);
				}
				break;
			case 3:
				{
				setState(152);
				match(LeftParen);
				setState(153);
				typeName();
				setState(154);
				match(RightParen);
				setState(155);
				match(LeftBrace);
				setState(156);
				initializerList(0);
				setState(157);
				match(Comma);
				setState(158);
				match(RightBrace);
				}
				break;
			case 4:
				{
				setState(160);
				match(T__0);
				setState(161);
				match(LeftParen);
				setState(162);
				typeName();
				setState(163);
				match(RightParen);
				setState(164);
				match(LeftBrace);
				setState(165);
				initializerList(0);
				setState(166);
				match(RightBrace);
				}
				break;
			case 5:
				{
				setState(168);
				match(T__0);
				setState(169);
				match(LeftParen);
				setState(170);
				typeName();
				setState(171);
				match(RightParen);
				setState(172);
				match(LeftBrace);
				setState(173);
				initializerList(0);
				setState(174);
				match(Comma);
				setState(175);
				match(RightBrace);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(202);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(200);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(179);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(180);
						match(LeftBracket);
						setState(181);
						expression(0);
						setState(182);
						match(RightBracket);
						}
						break;
					case 2:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(184);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(185);
						match(LeftParen);
						setState(187);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
							{
							setState(186);
							argumentExpressionList(0);
							}
						}

						setState(189);
						match(RightParen);
						}
						break;
					case 3:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(190);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(191);
						match(Dot);
						setState(192);
						match(Identifier);
						}
						break;
					case 4:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(193);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(194);
						match(Arrow);
						setState(195);
						match(Identifier);
						}
						break;
					case 5:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(196);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(197);
						match(PlusPlus);
						}
						break;
					case 6:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(198);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(199);
						match(MinusMinus);
						}
						break;
					}
					} 
				}
				setState(204);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ArgumentExpressionListContext extends ParserRuleContext {
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public ArgumentExpressionListContext argumentExpressionList() {
			return getRuleContext(ArgumentExpressionListContext.class,0);
		}
		public ArgumentExpressionListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argumentExpressionList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterArgumentExpressionList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitArgumentExpressionList(this);
		}
	}

	public final ArgumentExpressionListContext argumentExpressionList() throws RecognitionException {
		return argumentExpressionList(0);
	}

	private ArgumentExpressionListContext argumentExpressionList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentExpressionListContext _localctx = new ArgumentExpressionListContext(_ctx, _parentState);
		ArgumentExpressionListContext _prevctx = _localctx;
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_argumentExpressionList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(206);
			assignmentExpression();
			}
			_ctx.stop = _input.LT(-1);
			setState(213);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentExpressionListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_argumentExpressionList);
					setState(208);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(209);
					match(Comma);
					setState(210);
					assignmentExpression();
					}
					} 
				}
				setState(215);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class UnaryExpressionContext extends ParserRuleContext {
		public PostfixExpressionContext postfixExpression() {
			return getRuleContext(PostfixExpressionContext.class,0);
		}
		public UnaryExpressionContext unaryExpression() {
			return getRuleContext(UnaryExpressionContext.class,0);
		}
		public UnaryOperatorContext unaryOperator() {
			return getRuleContext(UnaryOperatorContext.class,0);
		}
		public CastExpressionContext castExpression() {
			return getRuleContext(CastExpressionContext.class,0);
		}
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(quickanddirtycParser.Identifier, 0); }
		public UnaryExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unaryExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterUnaryExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitUnaryExpression(this);
		}
	}

	public final UnaryExpressionContext unaryExpression() throws RecognitionException {
		UnaryExpressionContext _localctx = new UnaryExpressionContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_unaryExpression);
		try {
			setState(238);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(216);
				postfixExpression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(217);
				match(PlusPlus);
				setState(218);
				unaryExpression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(219);
				match(MinusMinus);
				setState(220);
				unaryExpression();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(221);
				unaryOperator();
				setState(222);
				castExpression();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(224);
				match(Sizeof);
				setState(225);
				unaryExpression();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(226);
				match(Sizeof);
				setState(227);
				match(LeftParen);
				setState(228);
				typeName();
				setState(229);
				match(RightParen);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(231);
				match(T__1);
				setState(232);
				match(LeftParen);
				setState(233);
				typeName();
				setState(234);
				match(RightParen);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(236);
				match(AndAnd);
				setState(237);
				match(Identifier);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnaryOperatorContext extends ParserRuleContext {
		public UnaryOperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unaryOperator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterUnaryOperator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitUnaryOperator(this);
		}
	}

	public final UnaryOperatorContext unaryOperator() throws RecognitionException {
		UnaryOperatorContext _localctx = new UnaryOperatorContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_unaryOperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(240);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Plus) | (1L << Minus) | (1L << Star) | (1L << And) | (1L << Not) | (1L << Tilde))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CastExpressionContext extends ParserRuleContext {
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public CastExpressionContext castExpression() {
			return getRuleContext(CastExpressionContext.class,0);
		}
		public UnaryExpressionContext unaryExpression() {
			return getRuleContext(UnaryExpressionContext.class,0);
		}
		public TerminalNode DigitSequence() { return getToken(quickanddirtycParser.DigitSequence, 0); }
		public CastExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_castExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterCastExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitCastExpression(this);
		}
	}

	public final CastExpressionContext castExpression() throws RecognitionException {
		CastExpressionContext _localctx = new CastExpressionContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_castExpression);
		try {
			setState(255);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(242);
				match(LeftParen);
				setState(243);
				typeName();
				setState(244);
				match(RightParen);
				setState(245);
				castExpression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(247);
				match(T__0);
				setState(248);
				match(LeftParen);
				setState(249);
				typeName();
				setState(250);
				match(RightParen);
				setState(251);
				castExpression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(253);
				unaryExpression();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(254);
				match(DigitSequence);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MultiplicativeExpressionContext extends ParserRuleContext {
		public CastExpressionContext castExpression() {
			return getRuleContext(CastExpressionContext.class,0);
		}
		public MultiplicativeExpressionContext multiplicativeExpression() {
			return getRuleContext(MultiplicativeExpressionContext.class,0);
		}
		public MultiplicativeExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiplicativeExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterMultiplicativeExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitMultiplicativeExpression(this);
		}
	}

	public final MultiplicativeExpressionContext multiplicativeExpression() throws RecognitionException {
		return multiplicativeExpression(0);
	}

	private MultiplicativeExpressionContext multiplicativeExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		MultiplicativeExpressionContext _localctx = new MultiplicativeExpressionContext(_ctx, _parentState);
		MultiplicativeExpressionContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_multiplicativeExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(258);
			castExpression();
			}
			_ctx.stop = _input.LT(-1);
			setState(271);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(269);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
					case 1:
						{
						_localctx = new MultiplicativeExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_multiplicativeExpression);
						setState(260);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(261);
						match(Star);
						setState(262);
						castExpression();
						}
						break;
					case 2:
						{
						_localctx = new MultiplicativeExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_multiplicativeExpression);
						setState(263);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(264);
						match(Div);
						setState(265);
						castExpression();
						}
						break;
					case 3:
						{
						_localctx = new MultiplicativeExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_multiplicativeExpression);
						setState(266);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(267);
						match(Mod);
						setState(268);
						castExpression();
						}
						break;
					}
					} 
				}
				setState(273);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class AdditiveExpressionContext extends ParserRuleContext {
		public MultiplicativeExpressionContext multiplicativeExpression() {
			return getRuleContext(MultiplicativeExpressionContext.class,0);
		}
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public AdditiveExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_additiveExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterAdditiveExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitAdditiveExpression(this);
		}
	}

	public final AdditiveExpressionContext additiveExpression() throws RecognitionException {
		return additiveExpression(0);
	}

	private AdditiveExpressionContext additiveExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		AdditiveExpressionContext _localctx = new AdditiveExpressionContext(_ctx, _parentState);
		AdditiveExpressionContext _prevctx = _localctx;
		int _startState = 14;
		enterRecursionRule(_localctx, 14, RULE_additiveExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(275);
			multiplicativeExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(285);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(283);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
					case 1:
						{
						_localctx = new AdditiveExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_additiveExpression);
						setState(277);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(278);
						match(Plus);
						setState(279);
						multiplicativeExpression(0);
						}
						break;
					case 2:
						{
						_localctx = new AdditiveExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_additiveExpression);
						setState(280);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(281);
						match(Minus);
						setState(282);
						multiplicativeExpression(0);
						}
						break;
					}
					} 
				}
				setState(287);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ShiftExpressionContext extends ParserRuleContext {
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public ShiftExpressionContext shiftExpression() {
			return getRuleContext(ShiftExpressionContext.class,0);
		}
		public ShiftExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shiftExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterShiftExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitShiftExpression(this);
		}
	}

	public final ShiftExpressionContext shiftExpression() throws RecognitionException {
		return shiftExpression(0);
	}

	private ShiftExpressionContext shiftExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ShiftExpressionContext _localctx = new ShiftExpressionContext(_ctx, _parentState);
		ShiftExpressionContext _prevctx = _localctx;
		int _startState = 16;
		enterRecursionRule(_localctx, 16, RULE_shiftExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(289);
			additiveExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(299);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(297);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
					case 1:
						{
						_localctx = new ShiftExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_shiftExpression);
						setState(291);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(292);
						match(LeftShift);
						setState(293);
						additiveExpression(0);
						}
						break;
					case 2:
						{
						_localctx = new ShiftExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_shiftExpression);
						setState(294);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(295);
						match(RightShift);
						setState(296);
						additiveExpression(0);
						}
						break;
					}
					} 
				}
				setState(301);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class RelationalExpressionContext extends ParserRuleContext {
		public ShiftExpressionContext shiftExpression() {
			return getRuleContext(ShiftExpressionContext.class,0);
		}
		public RelationalExpressionContext relationalExpression() {
			return getRuleContext(RelationalExpressionContext.class,0);
		}
		public RelationalExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relationalExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterRelationalExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitRelationalExpression(this);
		}
	}

	public final RelationalExpressionContext relationalExpression() throws RecognitionException {
		return relationalExpression(0);
	}

	private RelationalExpressionContext relationalExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		RelationalExpressionContext _localctx = new RelationalExpressionContext(_ctx, _parentState);
		RelationalExpressionContext _prevctx = _localctx;
		int _startState = 18;
		enterRecursionRule(_localctx, 18, RULE_relationalExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(303);
			shiftExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(319);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(317);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
					case 1:
						{
						_localctx = new RelationalExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_relationalExpression);
						setState(305);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(306);
						match(Less);
						setState(307);
						shiftExpression(0);
						}
						break;
					case 2:
						{
						_localctx = new RelationalExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_relationalExpression);
						setState(308);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(309);
						match(Greater);
						setState(310);
						shiftExpression(0);
						}
						break;
					case 3:
						{
						_localctx = new RelationalExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_relationalExpression);
						setState(311);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(312);
						match(LessEqual);
						setState(313);
						shiftExpression(0);
						}
						break;
					case 4:
						{
						_localctx = new RelationalExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_relationalExpression);
						setState(314);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(315);
						match(GreaterEqual);
						setState(316);
						shiftExpression(0);
						}
						break;
					}
					} 
				}
				setState(321);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class EqualityExpressionContext extends ParserRuleContext {
		public RelationalExpressionContext relationalExpression() {
			return getRuleContext(RelationalExpressionContext.class,0);
		}
		public EqualityExpressionContext equalityExpression() {
			return getRuleContext(EqualityExpressionContext.class,0);
		}
		public EqualityExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_equalityExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterEqualityExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitEqualityExpression(this);
		}
	}

	public final EqualityExpressionContext equalityExpression() throws RecognitionException {
		return equalityExpression(0);
	}

	private EqualityExpressionContext equalityExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		EqualityExpressionContext _localctx = new EqualityExpressionContext(_ctx, _parentState);
		EqualityExpressionContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_equalityExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(323);
			relationalExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(333);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(331);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
					case 1:
						{
						_localctx = new EqualityExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_equalityExpression);
						setState(325);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(326);
						match(Equal);
						setState(327);
						relationalExpression(0);
						}
						break;
					case 2:
						{
						_localctx = new EqualityExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_equalityExpression);
						setState(328);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(329);
						match(NotEqual);
						setState(330);
						relationalExpression(0);
						}
						break;
					}
					} 
				}
				setState(335);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class AndExpressionContext extends ParserRuleContext {
		public EqualityExpressionContext equalityExpression() {
			return getRuleContext(EqualityExpressionContext.class,0);
		}
		public AndExpressionContext andExpression() {
			return getRuleContext(AndExpressionContext.class,0);
		}
		public AndExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_andExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterAndExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitAndExpression(this);
		}
	}

	public final AndExpressionContext andExpression() throws RecognitionException {
		return andExpression(0);
	}

	private AndExpressionContext andExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		AndExpressionContext _localctx = new AndExpressionContext(_ctx, _parentState);
		AndExpressionContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_andExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(337);
			equalityExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(344);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new AndExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_andExpression);
					setState(339);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(340);
					match(And);
					setState(341);
					equalityExpression(0);
					}
					} 
				}
				setState(346);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ExclusiveOrExpressionContext extends ParserRuleContext {
		public AndExpressionContext andExpression() {
			return getRuleContext(AndExpressionContext.class,0);
		}
		public ExclusiveOrExpressionContext exclusiveOrExpression() {
			return getRuleContext(ExclusiveOrExpressionContext.class,0);
		}
		public ExclusiveOrExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exclusiveOrExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterExclusiveOrExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitExclusiveOrExpression(this);
		}
	}

	public final ExclusiveOrExpressionContext exclusiveOrExpression() throws RecognitionException {
		return exclusiveOrExpression(0);
	}

	private ExclusiveOrExpressionContext exclusiveOrExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExclusiveOrExpressionContext _localctx = new ExclusiveOrExpressionContext(_ctx, _parentState);
		ExclusiveOrExpressionContext _prevctx = _localctx;
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_exclusiveOrExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(348);
			andExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(355);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExclusiveOrExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_exclusiveOrExpression);
					setState(350);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(351);
					match(Caret);
					setState(352);
					andExpression(0);
					}
					} 
				}
				setState(357);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class InclusiveOrExpressionContext extends ParserRuleContext {
		public ExclusiveOrExpressionContext exclusiveOrExpression() {
			return getRuleContext(ExclusiveOrExpressionContext.class,0);
		}
		public InclusiveOrExpressionContext inclusiveOrExpression() {
			return getRuleContext(InclusiveOrExpressionContext.class,0);
		}
		public InclusiveOrExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inclusiveOrExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterInclusiveOrExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitInclusiveOrExpression(this);
		}
	}

	public final InclusiveOrExpressionContext inclusiveOrExpression() throws RecognitionException {
		return inclusiveOrExpression(0);
	}

	private InclusiveOrExpressionContext inclusiveOrExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		InclusiveOrExpressionContext _localctx = new InclusiveOrExpressionContext(_ctx, _parentState);
		InclusiveOrExpressionContext _prevctx = _localctx;
		int _startState = 26;
		enterRecursionRule(_localctx, 26, RULE_inclusiveOrExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(359);
			exclusiveOrExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(366);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new InclusiveOrExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_inclusiveOrExpression);
					setState(361);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(362);
					match(Or);
					setState(363);
					exclusiveOrExpression(0);
					}
					} 
				}
				setState(368);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class LogicalAndExpressionContext extends ParserRuleContext {
		public InclusiveOrExpressionContext inclusiveOrExpression() {
			return getRuleContext(InclusiveOrExpressionContext.class,0);
		}
		public LogicalAndExpressionContext logicalAndExpression() {
			return getRuleContext(LogicalAndExpressionContext.class,0);
		}
		public LogicalAndExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicalAndExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterLogicalAndExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitLogicalAndExpression(this);
		}
	}

	public final LogicalAndExpressionContext logicalAndExpression() throws RecognitionException {
		return logicalAndExpression(0);
	}

	private LogicalAndExpressionContext logicalAndExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		LogicalAndExpressionContext _localctx = new LogicalAndExpressionContext(_ctx, _parentState);
		LogicalAndExpressionContext _prevctx = _localctx;
		int _startState = 28;
		enterRecursionRule(_localctx, 28, RULE_logicalAndExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(370);
			inclusiveOrExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(377);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new LogicalAndExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_logicalAndExpression);
					setState(372);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(373);
					match(AndAnd);
					setState(374);
					inclusiveOrExpression(0);
					}
					} 
				}
				setState(379);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class LogicalOrExpressionContext extends ParserRuleContext {
		public LogicalAndExpressionContext logicalAndExpression() {
			return getRuleContext(LogicalAndExpressionContext.class,0);
		}
		public LogicalOrExpressionContext logicalOrExpression() {
			return getRuleContext(LogicalOrExpressionContext.class,0);
		}
		public LogicalOrExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicalOrExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterLogicalOrExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitLogicalOrExpression(this);
		}
	}

	public final LogicalOrExpressionContext logicalOrExpression() throws RecognitionException {
		return logicalOrExpression(0);
	}

	private LogicalOrExpressionContext logicalOrExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		LogicalOrExpressionContext _localctx = new LogicalOrExpressionContext(_ctx, _parentState);
		LogicalOrExpressionContext _prevctx = _localctx;
		int _startState = 30;
		enterRecursionRule(_localctx, 30, RULE_logicalOrExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(381);
			logicalAndExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(388);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new LogicalOrExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_logicalOrExpression);
					setState(383);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(384);
					match(OrOr);
					setState(385);
					logicalAndExpression(0);
					}
					} 
				}
				setState(390);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ConditionalExpressionContext extends ParserRuleContext {
		public LogicalOrExpressionContext logicalOrExpression() {
			return getRuleContext(LogicalOrExpressionContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ConditionalExpressionContext conditionalExpression() {
			return getRuleContext(ConditionalExpressionContext.class,0);
		}
		public ConditionalExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditionalExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterConditionalExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitConditionalExpression(this);
		}
	}

	public final ConditionalExpressionContext conditionalExpression() throws RecognitionException {
		ConditionalExpressionContext _localctx = new ConditionalExpressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_conditionalExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(391);
			logicalOrExpression(0);
			setState(397);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				{
				setState(392);
				match(Question);
				setState(393);
				expression(0);
				setState(394);
				match(Colon);
				setState(395);
				conditionalExpression();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentExpressionContext extends ParserRuleContext {
		public ConditionalExpressionContext conditionalExpression() {
			return getRuleContext(ConditionalExpressionContext.class,0);
		}
		public UnaryExpressionContext unaryExpression() {
			return getRuleContext(UnaryExpressionContext.class,0);
		}
		public AssignmentOperatorContext assignmentOperator() {
			return getRuleContext(AssignmentOperatorContext.class,0);
		}
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public TerminalNode DigitSequence() { return getToken(quickanddirtycParser.DigitSequence, 0); }
		public AssignmentExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignmentExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterAssignmentExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitAssignmentExpression(this);
		}
	}

	public final AssignmentExpressionContext assignmentExpression() throws RecognitionException {
		AssignmentExpressionContext _localctx = new AssignmentExpressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_assignmentExpression);
		try {
			setState(405);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(399);
				conditionalExpression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(400);
				unaryExpression();
				setState(401);
				assignmentOperator();
				setState(402);
				assignmentExpression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(404);
				match(DigitSequence);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentOperatorContext extends ParserRuleContext {
		public AssignmentOperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignmentOperator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterAssignmentOperator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitAssignmentOperator(this);
		}
	}

	public final AssignmentOperatorContext assignmentOperator() throws RecognitionException {
		AssignmentOperatorContext _localctx = new AssignmentOperatorContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_assignmentOperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(407);
			_la = _input.LA(1);
			if ( !(((((_la - 60)) & ~0x3f) == 0 && ((1L << (_la - 60)) & ((1L << (Assign - 60)) | (1L << (StarAssign - 60)) | (1L << (DivAssign - 60)) | (1L << (ModAssign - 60)) | (1L << (PlusAssign - 60)) | (1L << (MinusAssign - 60)) | (1L << (LeftShiftAssign - 60)) | (1L << (RightShiftAssign - 60)) | (1L << (AndAssign - 60)) | (1L << (XorAssign - 60)) | (1L << (OrAssign - 60)))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitExpression(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(410);
			assignmentExpression();
			}
			_ctx.stop = _input.LT(-1);
			setState(417);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_expression);
					setState(412);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(413);
					match(Comma);
					setState(414);
					assignmentExpression();
					}
					} 
				}
				setState(419);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ConstantExpressionContext extends ParserRuleContext {
		public ConditionalExpressionContext conditionalExpression() {
			return getRuleContext(ConditionalExpressionContext.class,0);
		}
		public ConstantExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterConstantExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitConstantExpression(this);
		}
	}

	public final ConstantExpressionContext constantExpression() throws RecognitionException {
		ConstantExpressionContext _localctx = new ConstantExpressionContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_constantExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(420);
			conditionalExpression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationContext extends ParserRuleContext {
		public DeclarationSpecifiersContext declarationSpecifiers() {
			return getRuleContext(DeclarationSpecifiersContext.class,0);
		}
		public InitDeclaratorListContext initDeclaratorList() {
			return getRuleContext(InitDeclaratorListContext.class,0);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDeclaration(this);
		}
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_declaration);
		try {
			setState(429);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,27,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(422);
				declarationSpecifiers();
				setState(423);
				initDeclaratorList(0);
				setState(424);
				match(Semi);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(426);
				declarationSpecifiers();
				setState(427);
				match(Semi);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationSpecifiersContext extends ParserRuleContext {
		public List<DeclarationSpecifierContext> declarationSpecifier() {
			return getRuleContexts(DeclarationSpecifierContext.class);
		}
		public DeclarationSpecifierContext declarationSpecifier(int i) {
			return getRuleContext(DeclarationSpecifierContext.class,i);
		}
		public DeclarationSpecifiersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarationSpecifiers; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDeclarationSpecifiers(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDeclarationSpecifiers(this);
		}
	}

	public final DeclarationSpecifiersContext declarationSpecifiers() throws RecognitionException {
		DeclarationSpecifiersContext _localctx = new DeclarationSpecifiersContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_declarationSpecifiers);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(432); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(431);
				declarationSpecifier();
				}
				}
				setState(434); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__3) | (1L << Char) | (1L << Const) | (1L << Double) | (1L << Extern) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Static) | (1L << Typedef) | (1L << Unsigned) | (1L << Void))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationSpecifiers2Context extends ParserRuleContext {
		public List<DeclarationSpecifierContext> declarationSpecifier() {
			return getRuleContexts(DeclarationSpecifierContext.class);
		}
		public DeclarationSpecifierContext declarationSpecifier(int i) {
			return getRuleContext(DeclarationSpecifierContext.class,i);
		}
		public DeclarationSpecifiers2Context(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarationSpecifiers2; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDeclarationSpecifiers2(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDeclarationSpecifiers2(this);
		}
	}

	public final DeclarationSpecifiers2Context declarationSpecifiers2() throws RecognitionException {
		DeclarationSpecifiers2Context _localctx = new DeclarationSpecifiers2Context(_ctx, getState());
		enterRule(_localctx, 46, RULE_declarationSpecifiers2);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(437); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(436);
					declarationSpecifier();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(439); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationSpecifierContext extends ParserRuleContext {
		public StorageClassSpecifierContext storageClassSpecifier() {
			return getRuleContext(StorageClassSpecifierContext.class,0);
		}
		public TypeSpecifierContext typeSpecifier() {
			return getRuleContext(TypeSpecifierContext.class,0);
		}
		public TypeQualifierContext typeQualifier() {
			return getRuleContext(TypeQualifierContext.class,0);
		}
		public DeclarationSpecifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarationSpecifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDeclarationSpecifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDeclarationSpecifier(this);
		}
	}

	public final DeclarationSpecifierContext declarationSpecifier() throws RecognitionException {
		DeclarationSpecifierContext _localctx = new DeclarationSpecifierContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_declarationSpecifier);
		try {
			setState(444);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__3:
			case Extern:
			case Static:
			case Typedef:
				enterOuterAlt(_localctx, 1);
				{
				setState(441);
				storageClassSpecifier();
				}
				break;
			case Char:
			case Double:
			case Float:
			case Int:
			case Long:
			case Short:
			case Signed:
			case Unsigned:
			case Void:
				enterOuterAlt(_localctx, 2);
				{
				setState(442);
				typeSpecifier();
				}
				break;
			case Const:
				enterOuterAlt(_localctx, 3);
				{
				setState(443);
				typeQualifier();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InitDeclaratorListContext extends ParserRuleContext {
		public InitDeclaratorContext initDeclarator() {
			return getRuleContext(InitDeclaratorContext.class,0);
		}
		public InitDeclaratorListContext initDeclaratorList() {
			return getRuleContext(InitDeclaratorListContext.class,0);
		}
		public InitDeclaratorListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initDeclaratorList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterInitDeclaratorList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitInitDeclaratorList(this);
		}
	}

	public final InitDeclaratorListContext initDeclaratorList() throws RecognitionException {
		return initDeclaratorList(0);
	}

	private InitDeclaratorListContext initDeclaratorList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		InitDeclaratorListContext _localctx = new InitDeclaratorListContext(_ctx, _parentState);
		InitDeclaratorListContext _prevctx = _localctx;
		int _startState = 50;
		enterRecursionRule(_localctx, 50, RULE_initDeclaratorList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(447);
			initDeclarator();
			}
			_ctx.stop = _input.LT(-1);
			setState(454);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new InitDeclaratorListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_initDeclaratorList);
					setState(449);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(450);
					match(Comma);
					setState(451);
					initDeclarator();
					}
					} 
				}
				setState(456);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class InitDeclaratorContext extends ParserRuleContext {
		public DeclaratorContext declarator() {
			return getRuleContext(DeclaratorContext.class,0);
		}
		public InitializerContext initializer() {
			return getRuleContext(InitializerContext.class,0);
		}
		public InitDeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initDeclarator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterInitDeclarator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitInitDeclarator(this);
		}
	}

	public final InitDeclaratorContext initDeclarator() throws RecognitionException {
		InitDeclaratorContext _localctx = new InitDeclaratorContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_initDeclarator);
		try {
			setState(462);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,32,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(457);
				declarator();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(458);
				declarator();
				setState(459);
				match(Assign);
				setState(460);
				initializer();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StorageClassSpecifierContext extends ParserRuleContext {
		public StorageClassSpecifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_storageClassSpecifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterStorageClassSpecifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitStorageClassSpecifier(this);
		}
	}

	public final StorageClassSpecifierContext storageClassSpecifier() throws RecognitionException {
		StorageClassSpecifierContext _localctx = new StorageClassSpecifierContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_storageClassSpecifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(464);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__3) | (1L << Extern) | (1L << Static) | (1L << Typedef))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeSpecifierContext extends ParserRuleContext {
		public TypeSpecifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeSpecifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterTypeSpecifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitTypeSpecifier(this);
		}
	}

	public final TypeSpecifierContext typeSpecifier() throws RecognitionException {
		TypeSpecifierContext _localctx = new TypeSpecifierContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_typeSpecifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(466);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Char) | (1L << Double) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Unsigned) | (1L << Void))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SpecifierQualifierListContext extends ParserRuleContext {
		public TypeSpecifierContext typeSpecifier() {
			return getRuleContext(TypeSpecifierContext.class,0);
		}
		public SpecifierQualifierListContext specifierQualifierList() {
			return getRuleContext(SpecifierQualifierListContext.class,0);
		}
		public TypeQualifierContext typeQualifier() {
			return getRuleContext(TypeQualifierContext.class,0);
		}
		public SpecifierQualifierListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_specifierQualifierList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterSpecifierQualifierList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitSpecifierQualifierList(this);
		}
	}

	public final SpecifierQualifierListContext specifierQualifierList() throws RecognitionException {
		SpecifierQualifierListContext _localctx = new SpecifierQualifierListContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_specifierQualifierList);
		int _la;
		try {
			setState(476);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Char:
			case Double:
			case Float:
			case Int:
			case Long:
			case Short:
			case Signed:
			case Unsigned:
			case Void:
				enterOuterAlt(_localctx, 1);
				{
				setState(468);
				typeSpecifier();
				setState(470);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Char) | (1L << Const) | (1L << Double) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Unsigned) | (1L << Void))) != 0)) {
					{
					setState(469);
					specifierQualifierList();
					}
				}

				}
				break;
			case Const:
				enterOuterAlt(_localctx, 2);
				{
				setState(472);
				typeQualifier();
				setState(474);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Char) | (1L << Const) | (1L << Double) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Unsigned) | (1L << Void))) != 0)) {
					{
					setState(473);
					specifierQualifierList();
					}
				}

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeQualifierContext extends ParserRuleContext {
		public TypeQualifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeQualifier; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterTypeQualifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitTypeQualifier(this);
		}
	}

	public final TypeQualifierContext typeQualifier() throws RecognitionException {
		TypeQualifierContext _localctx = new TypeQualifierContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_typeQualifier);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(478);
			match(Const);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclaratorContext extends ParserRuleContext {
		public DirectDeclaratorContext directDeclarator() {
			return getRuleContext(DirectDeclaratorContext.class,0);
		}
		public PointerContext pointer() {
			return getRuleContext(PointerContext.class,0);
		}
		public DeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDeclarator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDeclarator(this);
		}
	}

	public final DeclaratorContext declarator() throws RecognitionException {
		DeclaratorContext _localctx = new DeclaratorContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_declarator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(481);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Star || _la==Caret) {
				{
				setState(480);
				pointer();
				}
			}

			setState(483);
			directDeclarator(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DirectDeclaratorContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(quickanddirtycParser.Identifier, 0); }
		public DeclaratorContext declarator() {
			return getRuleContext(DeclaratorContext.class,0);
		}
		public TerminalNode DigitSequence() { return getToken(quickanddirtycParser.DigitSequence, 0); }
		public PointerContext pointer() {
			return getRuleContext(PointerContext.class,0);
		}
		public DirectDeclaratorContext directDeclarator() {
			return getRuleContext(DirectDeclaratorContext.class,0);
		}
		public TypeSpecifierContext typeSpecifier() {
			return getRuleContext(TypeSpecifierContext.class,0);
		}
		public TypeQualifierListContext typeQualifierList() {
			return getRuleContext(TypeQualifierListContext.class,0);
		}
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public ParameterTypeListContext parameterTypeList() {
			return getRuleContext(ParameterTypeListContext.class,0);
		}
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public DirectDeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_directDeclarator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDirectDeclarator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDirectDeclarator(this);
		}
	}

	public final DirectDeclaratorContext directDeclarator() throws RecognitionException {
		return directDeclarator(0);
	}

	private DirectDeclaratorContext directDeclarator(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		DirectDeclaratorContext _localctx = new DirectDeclaratorContext(_ctx, _parentState);
		DirectDeclaratorContext _prevctx = _localctx;
		int _startState = 64;
		enterRecursionRule(_localctx, 64, RULE_directDeclarator, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(502);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,38,_ctx) ) {
			case 1:
				{
				setState(486);
				match(Identifier);
				}
				break;
			case 2:
				{
				setState(487);
				match(LeftParen);
				setState(488);
				declarator();
				setState(489);
				match(RightParen);
				}
				break;
			case 3:
				{
				setState(491);
				match(Identifier);
				setState(492);
				match(Colon);
				setState(493);
				match(DigitSequence);
				}
				break;
			case 4:
				{
				setState(494);
				match(LeftParen);
				setState(496);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Char) | (1L << Double) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Unsigned) | (1L << Void))) != 0)) {
					{
					setState(495);
					typeSpecifier();
					}
				}

				setState(498);
				pointer();
				setState(499);
				directDeclarator(0);
				setState(500);
				match(RightParen);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(549);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(547);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,44,_ctx) ) {
					case 1:
						{
						_localctx = new DirectDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directDeclarator);
						setState(504);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(505);
						match(LeftBracket);
						setState(507);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==Const) {
							{
							setState(506);
							typeQualifierList(0);
							}
						}

						setState(510);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
							{
							setState(509);
							assignmentExpression();
							}
						}

						setState(512);
						match(RightBracket);
						}
						break;
					case 2:
						{
						_localctx = new DirectDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directDeclarator);
						setState(513);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(514);
						match(LeftBracket);
						setState(515);
						match(Static);
						setState(517);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==Const) {
							{
							setState(516);
							typeQualifierList(0);
							}
						}

						setState(519);
						assignmentExpression();
						setState(520);
						match(RightBracket);
						}
						break;
					case 3:
						{
						_localctx = new DirectDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directDeclarator);
						setState(522);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(523);
						match(LeftBracket);
						setState(524);
						typeQualifierList(0);
						setState(525);
						match(Static);
						setState(526);
						assignmentExpression();
						setState(527);
						match(RightBracket);
						}
						break;
					case 4:
						{
						_localctx = new DirectDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directDeclarator);
						setState(529);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(530);
						match(LeftBracket);
						setState(532);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==Const) {
							{
							setState(531);
							typeQualifierList(0);
							}
						}

						setState(534);
						match(Star);
						setState(535);
						match(RightBracket);
						}
						break;
					case 5:
						{
						_localctx = new DirectDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directDeclarator);
						setState(536);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(537);
						match(LeftParen);
						setState(538);
						parameterTypeList();
						setState(539);
						match(RightParen);
						}
						break;
					case 6:
						{
						_localctx = new DirectDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directDeclarator);
						setState(541);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(542);
						match(LeftParen);
						setState(544);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==Identifier) {
							{
							setState(543);
							identifierList(0);
							}
						}

						setState(546);
						match(RightParen);
						}
						break;
					}
					} 
				}
				setState(551);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,45,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class NestedParenthesesBlockContext extends ParserRuleContext {
		public List<NestedParenthesesBlockContext> nestedParenthesesBlock() {
			return getRuleContexts(NestedParenthesesBlockContext.class);
		}
		public NestedParenthesesBlockContext nestedParenthesesBlock(int i) {
			return getRuleContext(NestedParenthesesBlockContext.class,i);
		}
		public NestedParenthesesBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nestedParenthesesBlock; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterNestedParenthesesBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitNestedParenthesesBlock(this);
		}
	}

	public final NestedParenthesesBlockContext nestedParenthesesBlock() throws RecognitionException {
		NestedParenthesesBlockContext _localctx = new NestedParenthesesBlockContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_nestedParenthesesBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(559);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << T__2) | (1L << T__3) | (1L << T__4) | (1L << Break) | (1L << Case) | (1L << Char) | (1L << Const) | (1L << Continue) | (1L << Default) | (1L << Double) | (1L << Else) | (1L << Extern) | (1L << Float) | (1L << For) | (1L << If) | (1L << Int) | (1L << Long) | (1L << Return) | (1L << Short) | (1L << Signed) | (1L << Sizeof) | (1L << Static) | (1L << Switch) | (1L << Typedef) | (1L << Unsigned) | (1L << Void) | (1L << While) | (1L << LeftParen) | (1L << LeftBracket) | (1L << RightBracket) | (1L << LeftBrace) | (1L << RightBrace) | (1L << Less) | (1L << LessEqual) | (1L << Greater) | (1L << GreaterEqual) | (1L << LeftShift) | (1L << RightShift) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << Div) | (1L << Mod) | (1L << And) | (1L << Or) | (1L << AndAnd) | (1L << OrOr) | (1L << Caret) | (1L << Not) | (1L << Tilde) | (1L << Question) | (1L << Colon) | (1L << Semi) | (1L << Comma) | (1L << Assign) | (1L << StarAssign) | (1L << DivAssign) | (1L << ModAssign))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (PlusAssign - 64)) | (1L << (MinusAssign - 64)) | (1L << (LeftShiftAssign - 64)) | (1L << (RightShiftAssign - 64)) | (1L << (AndAssign - 64)) | (1L << (XorAssign - 64)) | (1L << (OrAssign - 64)) | (1L << (Equal - 64)) | (1L << (NotEqual - 64)) | (1L << (Arrow - 64)) | (1L << (Dot - 64)) | (1L << (Ellipsis - 64)) | (1L << (Identifier - 64)) | (1L << (Constant - 64)) | (1L << (DigitSequence - 64)) | (1L << (StringLiteral - 64)) | (1L << (Whitespace - 64)) | (1L << (Newline - 64)) | (1L << (BlockComment - 64)) | (1L << (LineComment - 64)))) != 0)) {
				{
				setState(557);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case T__0:
				case T__1:
				case T__2:
				case T__3:
				case T__4:
				case Break:
				case Case:
				case Char:
				case Const:
				case Continue:
				case Default:
				case Double:
				case Else:
				case Extern:
				case Float:
				case For:
				case If:
				case Int:
				case Long:
				case Return:
				case Short:
				case Signed:
				case Sizeof:
				case Static:
				case Switch:
				case Typedef:
				case Unsigned:
				case Void:
				case While:
				case LeftBracket:
				case RightBracket:
				case LeftBrace:
				case RightBrace:
				case Less:
				case LessEqual:
				case Greater:
				case GreaterEqual:
				case LeftShift:
				case RightShift:
				case Plus:
				case PlusPlus:
				case Minus:
				case MinusMinus:
				case Star:
				case Div:
				case Mod:
				case And:
				case Or:
				case AndAnd:
				case OrOr:
				case Caret:
				case Not:
				case Tilde:
				case Question:
				case Colon:
				case Semi:
				case Comma:
				case Assign:
				case StarAssign:
				case DivAssign:
				case ModAssign:
				case PlusAssign:
				case MinusAssign:
				case LeftShiftAssign:
				case RightShiftAssign:
				case AndAssign:
				case XorAssign:
				case OrAssign:
				case Equal:
				case NotEqual:
				case Arrow:
				case Dot:
				case Ellipsis:
				case Identifier:
				case Constant:
				case DigitSequence:
				case StringLiteral:
				case Whitespace:
				case Newline:
				case BlockComment:
				case LineComment:
					{
					setState(552);
					_la = _input.LA(1);
					if ( _la <= 0 || (_la==LeftParen || _la==RightParen) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
					break;
				case LeftParen:
					{
					setState(553);
					match(LeftParen);
					setState(554);
					nestedParenthesesBlock();
					setState(555);
					match(RightParen);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(561);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PointerContext extends ParserRuleContext {
		public TypeQualifierListContext typeQualifierList() {
			return getRuleContext(TypeQualifierListContext.class,0);
		}
		public PointerContext pointer() {
			return getRuleContext(PointerContext.class,0);
		}
		public PointerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pointer; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterPointer(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitPointer(this);
		}
	}

	public final PointerContext pointer() throws RecognitionException {
		PointerContext _localctx = new PointerContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_pointer);
		int _la;
		try {
			setState(580);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,52,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(562);
				match(Star);
				setState(564);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,48,_ctx) ) {
				case 1:
					{
					setState(563);
					typeQualifierList(0);
					}
					break;
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(566);
				match(Star);
				setState(568);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Const) {
					{
					setState(567);
					typeQualifierList(0);
					}
				}

				setState(570);
				pointer();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(571);
				match(Caret);
				setState(573);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,50,_ctx) ) {
				case 1:
					{
					setState(572);
					typeQualifierList(0);
					}
					break;
				}
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(575);
				match(Caret);
				setState(577);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Const) {
					{
					setState(576);
					typeQualifierList(0);
					}
				}

				setState(579);
				pointer();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeQualifierListContext extends ParserRuleContext {
		public TypeQualifierContext typeQualifier() {
			return getRuleContext(TypeQualifierContext.class,0);
		}
		public TypeQualifierListContext typeQualifierList() {
			return getRuleContext(TypeQualifierListContext.class,0);
		}
		public TypeQualifierListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeQualifierList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterTypeQualifierList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitTypeQualifierList(this);
		}
	}

	public final TypeQualifierListContext typeQualifierList() throws RecognitionException {
		return typeQualifierList(0);
	}

	private TypeQualifierListContext typeQualifierList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TypeQualifierListContext _localctx = new TypeQualifierListContext(_ctx, _parentState);
		TypeQualifierListContext _prevctx = _localctx;
		int _startState = 70;
		enterRecursionRule(_localctx, 70, RULE_typeQualifierList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(583);
			typeQualifier();
			}
			_ctx.stop = _input.LT(-1);
			setState(589);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,53,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TypeQualifierListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_typeQualifierList);
					setState(585);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(586);
					typeQualifier();
					}
					} 
				}
				setState(591);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,53,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ParameterTypeListContext extends ParserRuleContext {
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public ParameterTypeListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterTypeList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterParameterTypeList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitParameterTypeList(this);
		}
	}

	public final ParameterTypeListContext parameterTypeList() throws RecognitionException {
		ParameterTypeListContext _localctx = new ParameterTypeListContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_parameterTypeList);
		try {
			setState(597);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,54,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(592);
				parameterList(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(593);
				parameterList(0);
				setState(594);
				match(Comma);
				setState(595);
				match(Ellipsis);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterListContext extends ParserRuleContext {
		public ParameterDeclarationContext parameterDeclaration() {
			return getRuleContext(ParameterDeclarationContext.class,0);
		}
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public ParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterParameterList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitParameterList(this);
		}
	}

	public final ParameterListContext parameterList() throws RecognitionException {
		return parameterList(0);
	}

	private ParameterListContext parameterList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ParameterListContext _localctx = new ParameterListContext(_ctx, _parentState);
		ParameterListContext _prevctx = _localctx;
		int _startState = 74;
		enterRecursionRule(_localctx, 74, RULE_parameterList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(600);
			parameterDeclaration();
			}
			_ctx.stop = _input.LT(-1);
			setState(607);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,55,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ParameterListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_parameterList);
					setState(602);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(603);
					match(Comma);
					setState(604);
					parameterDeclaration();
					}
					} 
				}
				setState(609);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,55,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ParameterDeclarationContext extends ParserRuleContext {
		public DeclarationSpecifiersContext declarationSpecifiers() {
			return getRuleContext(DeclarationSpecifiersContext.class,0);
		}
		public DeclaratorContext declarator() {
			return getRuleContext(DeclaratorContext.class,0);
		}
		public DeclarationSpecifiers2Context declarationSpecifiers2() {
			return getRuleContext(DeclarationSpecifiers2Context.class,0);
		}
		public AbstractDeclaratorContext abstractDeclarator() {
			return getRuleContext(AbstractDeclaratorContext.class,0);
		}
		public ParameterDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterParameterDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitParameterDeclaration(this);
		}
	}

	public final ParameterDeclarationContext parameterDeclaration() throws RecognitionException {
		ParameterDeclarationContext _localctx = new ParameterDeclarationContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_parameterDeclaration);
		try {
			setState(617);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,57,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(610);
				declarationSpecifiers();
				setState(611);
				declarator();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(613);
				declarationSpecifiers2();
				setState(615);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,56,_ctx) ) {
				case 1:
					{
					setState(614);
					abstractDeclarator();
					}
					break;
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentifierListContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(quickanddirtycParser.Identifier, 0); }
		public IdentifierListContext identifierList() {
			return getRuleContext(IdentifierListContext.class,0);
		}
		public IdentifierListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifierList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterIdentifierList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitIdentifierList(this);
		}
	}

	public final IdentifierListContext identifierList() throws RecognitionException {
		return identifierList(0);
	}

	private IdentifierListContext identifierList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		IdentifierListContext _localctx = new IdentifierListContext(_ctx, _parentState);
		IdentifierListContext _prevctx = _localctx;
		int _startState = 78;
		enterRecursionRule(_localctx, 78, RULE_identifierList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(620);
			match(Identifier);
			}
			_ctx.stop = _input.LT(-1);
			setState(627);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,58,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new IdentifierListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_identifierList);
					setState(622);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(623);
					match(Comma);
					setState(624);
					match(Identifier);
					}
					} 
				}
				setState(629);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,58,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class TypeNameContext extends ParserRuleContext {
		public SpecifierQualifierListContext specifierQualifierList() {
			return getRuleContext(SpecifierQualifierListContext.class,0);
		}
		public AbstractDeclaratorContext abstractDeclarator() {
			return getRuleContext(AbstractDeclaratorContext.class,0);
		}
		public TypeNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeName; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterTypeName(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitTypeName(this);
		}
	}

	public final TypeNameContext typeName() throws RecognitionException {
		TypeNameContext _localctx = new TypeNameContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_typeName);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(630);
			specifierQualifierList();
			setState(632);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LeftParen) | (1L << LeftBracket) | (1L << Star) | (1L << Caret))) != 0)) {
				{
				setState(631);
				abstractDeclarator();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AbstractDeclaratorContext extends ParserRuleContext {
		public PointerContext pointer() {
			return getRuleContext(PointerContext.class,0);
		}
		public DirectAbstractDeclaratorContext directAbstractDeclarator() {
			return getRuleContext(DirectAbstractDeclaratorContext.class,0);
		}
		public AbstractDeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_abstractDeclarator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterAbstractDeclarator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitAbstractDeclarator(this);
		}
	}

	public final AbstractDeclaratorContext abstractDeclarator() throws RecognitionException {
		AbstractDeclaratorContext _localctx = new AbstractDeclaratorContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_abstractDeclarator);
		int _la;
		try {
			setState(639);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,61,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(634);
				pointer();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(636);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Star || _la==Caret) {
					{
					setState(635);
					pointer();
					}
				}

				setState(638);
				directAbstractDeclarator(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DirectAbstractDeclaratorContext extends ParserRuleContext {
		public AbstractDeclaratorContext abstractDeclarator() {
			return getRuleContext(AbstractDeclaratorContext.class,0);
		}
		public TypeQualifierListContext typeQualifierList() {
			return getRuleContext(TypeQualifierListContext.class,0);
		}
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public ParameterTypeListContext parameterTypeList() {
			return getRuleContext(ParameterTypeListContext.class,0);
		}
		public DirectAbstractDeclaratorContext directAbstractDeclarator() {
			return getRuleContext(DirectAbstractDeclaratorContext.class,0);
		}
		public DirectAbstractDeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_directAbstractDeclarator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDirectAbstractDeclarator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDirectAbstractDeclarator(this);
		}
	}

	public final DirectAbstractDeclaratorContext directAbstractDeclarator() throws RecognitionException {
		return directAbstractDeclarator(0);
	}

	private DirectAbstractDeclaratorContext directAbstractDeclarator(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		DirectAbstractDeclaratorContext _localctx = new DirectAbstractDeclaratorContext(_ctx, _parentState);
		DirectAbstractDeclaratorContext _prevctx = _localctx;
		int _startState = 84;
		enterRecursionRule(_localctx, 84, RULE_directAbstractDeclarator, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(676);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,66,_ctx) ) {
			case 1:
				{
				setState(642);
				match(LeftParen);
				setState(643);
				abstractDeclarator();
				setState(644);
				match(RightParen);
				}
				break;
			case 2:
				{
				setState(646);
				match(LeftBracket);
				setState(648);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Const) {
					{
					setState(647);
					typeQualifierList(0);
					}
				}

				setState(651);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
					{
					setState(650);
					assignmentExpression();
					}
				}

				setState(653);
				match(RightBracket);
				}
				break;
			case 3:
				{
				setState(654);
				match(LeftBracket);
				setState(655);
				match(Static);
				setState(657);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Const) {
					{
					setState(656);
					typeQualifierList(0);
					}
				}

				setState(659);
				assignmentExpression();
				setState(660);
				match(RightBracket);
				}
				break;
			case 4:
				{
				setState(662);
				match(LeftBracket);
				setState(663);
				typeQualifierList(0);
				setState(664);
				match(Static);
				setState(665);
				assignmentExpression();
				setState(666);
				match(RightBracket);
				}
				break;
			case 5:
				{
				setState(668);
				match(LeftBracket);
				setState(669);
				match(Star);
				setState(670);
				match(RightBracket);
				}
				break;
			case 6:
				{
				setState(671);
				match(LeftParen);
				setState(673);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__3) | (1L << Char) | (1L << Const) | (1L << Double) | (1L << Extern) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Static) | (1L << Typedef) | (1L << Unsigned) | (1L << Void))) != 0)) {
					{
					setState(672);
					parameterTypeList();
					}
				}

				setState(675);
				match(RightParen);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(715);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,72,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(713);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,71,_ctx) ) {
					case 1:
						{
						_localctx = new DirectAbstractDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directAbstractDeclarator);
						setState(678);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(679);
						match(LeftBracket);
						setState(681);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==Const) {
							{
							setState(680);
							typeQualifierList(0);
							}
						}

						setState(684);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
							{
							setState(683);
							assignmentExpression();
							}
						}

						setState(686);
						match(RightBracket);
						}
						break;
					case 2:
						{
						_localctx = new DirectAbstractDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directAbstractDeclarator);
						setState(687);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(688);
						match(LeftBracket);
						setState(689);
						match(Static);
						setState(691);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==Const) {
							{
							setState(690);
							typeQualifierList(0);
							}
						}

						setState(693);
						assignmentExpression();
						setState(694);
						match(RightBracket);
						}
						break;
					case 3:
						{
						_localctx = new DirectAbstractDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directAbstractDeclarator);
						setState(696);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(697);
						match(LeftBracket);
						setState(698);
						typeQualifierList(0);
						setState(699);
						match(Static);
						setState(700);
						assignmentExpression();
						setState(701);
						match(RightBracket);
						}
						break;
					case 4:
						{
						_localctx = new DirectAbstractDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directAbstractDeclarator);
						setState(703);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(704);
						match(LeftBracket);
						setState(705);
						match(Star);
						setState(706);
						match(RightBracket);
						}
						break;
					case 5:
						{
						_localctx = new DirectAbstractDeclaratorContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_directAbstractDeclarator);
						setState(707);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(708);
						match(LeftParen);
						setState(710);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__3) | (1L << Char) | (1L << Const) | (1L << Double) | (1L << Extern) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Static) | (1L << Typedef) | (1L << Unsigned) | (1L << Void))) != 0)) {
							{
							setState(709);
							parameterTypeList();
							}
						}

						setState(712);
						match(RightParen);
						}
						break;
					}
					} 
				}
				setState(717);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,72,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class InitializerContext extends ParserRuleContext {
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public InitializerListContext initializerList() {
			return getRuleContext(InitializerListContext.class,0);
		}
		public InitializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initializer; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterInitializer(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitInitializer(this);
		}
	}

	public final InitializerContext initializer() throws RecognitionException {
		InitializerContext _localctx = new InitializerContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_initializer);
		try {
			setState(728);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,73,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(718);
				assignmentExpression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(719);
				match(LeftBrace);
				setState(720);
				initializerList(0);
				setState(721);
				match(RightBrace);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(723);
				match(LeftBrace);
				setState(724);
				initializerList(0);
				setState(725);
				match(Comma);
				setState(726);
				match(RightBrace);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InitializerListContext extends ParserRuleContext {
		public InitializerContext initializer() {
			return getRuleContext(InitializerContext.class,0);
		}
		public DesignationContext designation() {
			return getRuleContext(DesignationContext.class,0);
		}
		public InitializerListContext initializerList() {
			return getRuleContext(InitializerListContext.class,0);
		}
		public InitializerListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initializerList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterInitializerList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitInitializerList(this);
		}
	}

	public final InitializerListContext initializerList() throws RecognitionException {
		return initializerList(0);
	}

	private InitializerListContext initializerList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		InitializerListContext _localctx = new InitializerListContext(_ctx, _parentState);
		InitializerListContext _prevctx = _localctx;
		int _startState = 88;
		enterRecursionRule(_localctx, 88, RULE_initializerList, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(732);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LeftBracket || _la==Dot) {
				{
				setState(731);
				designation();
				}
			}

			setState(734);
			initializer();
			}
			_ctx.stop = _input.LT(-1);
			setState(744);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,76,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new InitializerListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_initializerList);
					setState(736);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(737);
					match(Comma);
					setState(739);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==LeftBracket || _la==Dot) {
						{
						setState(738);
						designation();
						}
					}

					setState(741);
					initializer();
					}
					} 
				}
				setState(746);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,76,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class DesignationContext extends ParserRuleContext {
		public DesignatorListContext designatorList() {
			return getRuleContext(DesignatorListContext.class,0);
		}
		public DesignationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_designation; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDesignation(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDesignation(this);
		}
	}

	public final DesignationContext designation() throws RecognitionException {
		DesignationContext _localctx = new DesignationContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_designation);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(747);
			designatorList(0);
			setState(748);
			match(Assign);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DesignatorListContext extends ParserRuleContext {
		public DesignatorContext designator() {
			return getRuleContext(DesignatorContext.class,0);
		}
		public DesignatorListContext designatorList() {
			return getRuleContext(DesignatorListContext.class,0);
		}
		public DesignatorListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_designatorList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDesignatorList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDesignatorList(this);
		}
	}

	public final DesignatorListContext designatorList() throws RecognitionException {
		return designatorList(0);
	}

	private DesignatorListContext designatorList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		DesignatorListContext _localctx = new DesignatorListContext(_ctx, _parentState);
		DesignatorListContext _prevctx = _localctx;
		int _startState = 92;
		enterRecursionRule(_localctx, 92, RULE_designatorList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(751);
			designator();
			}
			_ctx.stop = _input.LT(-1);
			setState(757);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,77,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new DesignatorListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_designatorList);
					setState(753);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(754);
					designator();
					}
					} 
				}
				setState(759);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,77,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class DesignatorContext extends ParserRuleContext {
		public ConstantExpressionContext constantExpression() {
			return getRuleContext(ConstantExpressionContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(quickanddirtycParser.Identifier, 0); }
		public DesignatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_designator; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDesignator(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDesignator(this);
		}
	}

	public final DesignatorContext designator() throws RecognitionException {
		DesignatorContext _localctx = new DesignatorContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_designator);
		try {
			setState(766);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LeftBracket:
				enterOuterAlt(_localctx, 1);
				{
				setState(760);
				match(LeftBracket);
				setState(761);
				constantExpression();
				setState(762);
				match(RightBracket);
				}
				break;
			case Dot:
				enterOuterAlt(_localctx, 2);
				{
				setState(764);
				match(Dot);
				setState(765);
				match(Identifier);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public LabeledStatementContext labeledStatement() {
			return getRuleContext(LabeledStatementContext.class,0);
		}
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
		}
		public ExpressionStatementContext expressionStatement() {
			return getRuleContext(ExpressionStatementContext.class,0);
		}
		public SelectionStatementContext selectionStatement() {
			return getRuleContext(SelectionStatementContext.class,0);
		}
		public IterationStatementContext iterationStatement() {
			return getRuleContext(IterationStatementContext.class,0);
		}
		public JumpStatementContext jumpStatement() {
			return getRuleContext(JumpStatementContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitStatement(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_statement);
		try {
			setState(774);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,79,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(768);
				labeledStatement();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(769);
				compoundStatement();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(770);
				expressionStatement();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(771);
				selectionStatement();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(772);
				iterationStatement();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(773);
				jumpStatement();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LabeledStatementContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(quickanddirtycParser.Identifier, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public ConstantExpressionContext constantExpression() {
			return getRuleContext(ConstantExpressionContext.class,0);
		}
		public LabeledStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_labeledStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterLabeledStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitLabeledStatement(this);
		}
	}

	public final LabeledStatementContext labeledStatement() throws RecognitionException {
		LabeledStatementContext _localctx = new LabeledStatementContext(_ctx, getState());
		enterRule(_localctx, 98, RULE_labeledStatement);
		try {
			setState(787);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(776);
				match(Identifier);
				setState(777);
				match(Colon);
				setState(778);
				statement();
				}
				break;
			case Case:
				enterOuterAlt(_localctx, 2);
				{
				setState(779);
				match(Case);
				setState(780);
				constantExpression();
				setState(781);
				match(Colon);
				setState(782);
				statement();
				}
				break;
			case Default:
				enterOuterAlt(_localctx, 3);
				{
				setState(784);
				match(Default);
				setState(785);
				match(Colon);
				setState(786);
				statement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CompoundStatementContext extends ParserRuleContext {
		public BlockItemListContext blockItemList() {
			return getRuleContext(BlockItemListContext.class,0);
		}
		public CompoundStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compoundStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterCompoundStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitCompoundStatement(this);
		}
	}

	public final CompoundStatementContext compoundStatement() throws RecognitionException {
		CompoundStatementContext _localctx = new CompoundStatementContext(_ctx, getState());
		enterRule(_localctx, 100, RULE_compoundStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(789);
			match(LeftBrace);
			setState(791);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << T__2) | (1L << T__3) | (1L << T__4) | (1L << Break) | (1L << Case) | (1L << Char) | (1L << Const) | (1L << Continue) | (1L << Default) | (1L << Double) | (1L << Extern) | (1L << Float) | (1L << For) | (1L << If) | (1L << Int) | (1L << Long) | (1L << Return) | (1L << Short) | (1L << Signed) | (1L << Sizeof) | (1L << Static) | (1L << Switch) | (1L << Typedef) | (1L << Unsigned) | (1L << Void) | (1L << While) | (1L << LeftParen) | (1L << LeftBrace) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde) | (1L << Semi))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
				{
				setState(790);
				blockItemList(0);
				}
			}

			setState(793);
			match(RightBrace);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockItemListContext extends ParserRuleContext {
		public BlockItemContext blockItem() {
			return getRuleContext(BlockItemContext.class,0);
		}
		public BlockItemListContext blockItemList() {
			return getRuleContext(BlockItemListContext.class,0);
		}
		public BlockItemListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockItemList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterBlockItemList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitBlockItemList(this);
		}
	}

	public final BlockItemListContext blockItemList() throws RecognitionException {
		return blockItemList(0);
	}

	private BlockItemListContext blockItemList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		BlockItemListContext _localctx = new BlockItemListContext(_ctx, _parentState);
		BlockItemListContext _prevctx = _localctx;
		int _startState = 102;
		enterRecursionRule(_localctx, 102, RULE_blockItemList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(796);
			blockItem();
			}
			_ctx.stop = _input.LT(-1);
			setState(802);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,82,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new BlockItemListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_blockItemList);
					setState(798);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(799);
					blockItem();
					}
					} 
				}
				setState(804);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,82,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class BlockItemContext extends ParserRuleContext {
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public BlockItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockItem; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterBlockItem(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitBlockItem(this);
		}
	}

	public final BlockItemContext blockItem() throws RecognitionException {
		BlockItemContext _localctx = new BlockItemContext(_ctx, getState());
		enterRule(_localctx, 104, RULE_blockItem);
		try {
			setState(807);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
			case T__1:
			case T__4:
			case Break:
			case Case:
			case Continue:
			case Default:
			case For:
			case If:
			case Return:
			case Sizeof:
			case Switch:
			case While:
			case LeftParen:
			case LeftBrace:
			case Plus:
			case PlusPlus:
			case Minus:
			case MinusMinus:
			case Star:
			case And:
			case AndAnd:
			case Not:
			case Tilde:
			case Semi:
			case Identifier:
			case Constant:
			case DigitSequence:
			case StringLiteral:
				enterOuterAlt(_localctx, 1);
				{
				setState(805);
				statement();
				}
				break;
			case T__2:
			case T__3:
			case Char:
			case Const:
			case Double:
			case Extern:
			case Float:
			case Int:
			case Long:
			case Short:
			case Signed:
			case Static:
			case Typedef:
			case Unsigned:
			case Void:
				enterOuterAlt(_localctx, 2);
				{
				setState(806);
				declaration();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionStatementContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExpressionStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expressionStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterExpressionStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitExpressionStatement(this);
		}
	}

	public final ExpressionStatementContext expressionStatement() throws RecognitionException {
		ExpressionStatementContext _localctx = new ExpressionStatementContext(_ctx, getState());
		enterRule(_localctx, 106, RULE_expressionStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(810);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
				{
				setState(809);
				expression(0);
				}
			}

			setState(812);
			match(Semi);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SelectionStatementContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public SelectionStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_selectionStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterSelectionStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitSelectionStatement(this);
		}
	}

	public final SelectionStatementContext selectionStatement() throws RecognitionException {
		SelectionStatementContext _localctx = new SelectionStatementContext(_ctx, getState());
		enterRule(_localctx, 108, RULE_selectionStatement);
		try {
			setState(829);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case If:
				enterOuterAlt(_localctx, 1);
				{
				setState(814);
				match(If);
				setState(815);
				match(LeftParen);
				setState(816);
				expression(0);
				setState(817);
				match(RightParen);
				setState(818);
				statement();
				setState(821);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,85,_ctx) ) {
				case 1:
					{
					setState(819);
					match(Else);
					setState(820);
					statement();
					}
					break;
				}
				}
				break;
			case Switch:
				enterOuterAlt(_localctx, 2);
				{
				setState(823);
				match(Switch);
				setState(824);
				match(LeftParen);
				setState(825);
				expression(0);
				setState(826);
				match(RightParen);
				setState(827);
				statement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IterationStatementContext extends ParserRuleContext {
		public TerminalNode While() { return getToken(quickanddirtycParser.While, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public TerminalNode For() { return getToken(quickanddirtycParser.For, 0); }
		public ForConditionContext forCondition() {
			return getRuleContext(ForConditionContext.class,0);
		}
		public IterationStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_iterationStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterIterationStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitIterationStatement(this);
		}
	}

	public final IterationStatementContext iterationStatement() throws RecognitionException {
		IterationStatementContext _localctx = new IterationStatementContext(_ctx, getState());
		enterRule(_localctx, 110, RULE_iterationStatement);
		try {
			setState(843);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case While:
				enterOuterAlt(_localctx, 1);
				{
				setState(831);
				match(While);
				setState(832);
				match(LeftParen);
				setState(833);
				expression(0);
				setState(834);
				match(RightParen);
				setState(835);
				statement();
				}
				break;
			case For:
				enterOuterAlt(_localctx, 2);
				{
				setState(837);
				match(For);
				setState(838);
				match(LeftParen);
				setState(839);
				forCondition();
				setState(840);
				match(RightParen);
				setState(841);
				statement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ForConditionContext extends ParserRuleContext {
		public ForDeclarationContext forDeclaration() {
			return getRuleContext(ForDeclarationContext.class,0);
		}
		public List<ForExpressionContext> forExpression() {
			return getRuleContexts(ForExpressionContext.class);
		}
		public ForExpressionContext forExpression(int i) {
			return getRuleContext(ForExpressionContext.class,i);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ForConditionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forCondition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterForCondition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitForCondition(this);
		}
	}

	public final ForConditionContext forCondition() throws RecognitionException {
		ForConditionContext _localctx = new ForConditionContext(_ctx, getState());
		enterRule(_localctx, 112, RULE_forCondition);
		int _la;
		try {
			setState(865);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__2:
			case T__3:
			case Char:
			case Const:
			case Double:
			case Extern:
			case Float:
			case Int:
			case Long:
			case Short:
			case Signed:
			case Static:
			case Typedef:
			case Unsigned:
			case Void:
				enterOuterAlt(_localctx, 1);
				{
				setState(845);
				forDeclaration();
				setState(846);
				match(Semi);
				setState(848);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
					{
					setState(847);
					forExpression(0);
					}
				}

				setState(850);
				match(Semi);
				setState(852);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
					{
					setState(851);
					forExpression(0);
					}
				}

				}
				break;
			case T__0:
			case T__1:
			case Sizeof:
			case LeftParen:
			case Plus:
			case PlusPlus:
			case Minus:
			case MinusMinus:
			case Star:
			case And:
			case AndAnd:
			case Not:
			case Tilde:
			case Semi:
			case Identifier:
			case Constant:
			case DigitSequence:
			case StringLiteral:
				enterOuterAlt(_localctx, 2);
				{
				setState(855);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
					{
					setState(854);
					expression(0);
					}
				}

				setState(857);
				match(Semi);
				setState(859);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
					{
					setState(858);
					forExpression(0);
					}
				}

				setState(861);
				match(Semi);
				setState(863);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
					{
					setState(862);
					forExpression(0);
					}
				}

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ForDeclarationContext extends ParserRuleContext {
		public DeclarationSpecifiersContext declarationSpecifiers() {
			return getRuleContext(DeclarationSpecifiersContext.class,0);
		}
		public InitDeclaratorListContext initDeclaratorList() {
			return getRuleContext(InitDeclaratorListContext.class,0);
		}
		public ForDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterForDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitForDeclaration(this);
		}
	}

	public final ForDeclarationContext forDeclaration() throws RecognitionException {
		ForDeclarationContext _localctx = new ForDeclarationContext(_ctx, getState());
		enterRule(_localctx, 114, RULE_forDeclaration);
		try {
			setState(871);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,94,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(867);
				declarationSpecifiers();
				setState(868);
				initDeclaratorList(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(870);
				declarationSpecifiers();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ForExpressionContext extends ParserRuleContext {
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public ForExpressionContext forExpression() {
			return getRuleContext(ForExpressionContext.class,0);
		}
		public ForExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forExpression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterForExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitForExpression(this);
		}
	}

	public final ForExpressionContext forExpression() throws RecognitionException {
		return forExpression(0);
	}

	private ForExpressionContext forExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ForExpressionContext _localctx = new ForExpressionContext(_ctx, _parentState);
		ForExpressionContext _prevctx = _localctx;
		int _startState = 116;
		enterRecursionRule(_localctx, 116, RULE_forExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(874);
			assignmentExpression();
			}
			_ctx.stop = _input.LT(-1);
			setState(881);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,95,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ForExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_forExpression);
					setState(876);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(877);
					match(Comma);
					setState(878);
					assignmentExpression();
					}
					} 
				}
				setState(883);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,95,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class JumpStatementContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(quickanddirtycParser.Identifier, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public UnaryExpressionContext unaryExpression() {
			return getRuleContext(UnaryExpressionContext.class,0);
		}
		public JumpStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_jumpStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterJumpStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitJumpStatement(this);
		}
	}

	public final JumpStatementContext jumpStatement() throws RecognitionException {
		JumpStatementContext _localctx = new JumpStatementContext(_ctx, getState());
		enterRule(_localctx, 118, RULE_jumpStatement);
		int _la;
		try {
			setState(900);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,97,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(884);
				match(T__4);
				setState(885);
				match(Identifier);
				setState(886);
				match(Semi);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(887);
				match(Continue);
				setState(888);
				match(Semi);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(889);
				match(Break);
				setState(890);
				match(Semi);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(891);
				match(Return);
				setState(893);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__1) | (1L << Sizeof) | (1L << LeftParen) | (1L << Plus) | (1L << PlusPlus) | (1L << Minus) | (1L << MinusMinus) | (1L << Star) | (1L << And) | (1L << AndAnd) | (1L << Not) | (1L << Tilde))) != 0) || ((((_la - 76)) & ~0x3f) == 0 && ((1L << (_la - 76)) & ((1L << (Identifier - 76)) | (1L << (Constant - 76)) | (1L << (DigitSequence - 76)) | (1L << (StringLiteral - 76)))) != 0)) {
					{
					setState(892);
					expression(0);
					}
				}

				setState(895);
				match(Semi);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(896);
				match(T__4);
				setState(897);
				unaryExpression();
				setState(898);
				match(Semi);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CompilationUnitContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(quickanddirtycParser.EOF, 0); }
		public TranslationUnitContext translationUnit() {
			return getRuleContext(TranslationUnitContext.class,0);
		}
		public CompilationUnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compilationUnit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterCompilationUnit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitCompilationUnit(this);
		}
	}

	public final CompilationUnitContext compilationUnit() throws RecognitionException {
		CompilationUnitContext _localctx = new CompilationUnitContext(_ctx, getState());
		enterRule(_localctx, 120, RULE_compilationUnit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(903);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__3) | (1L << Char) | (1L << Const) | (1L << Double) | (1L << Extern) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Static) | (1L << Typedef) | (1L << Unsigned) | (1L << Void) | (1L << LeftParen) | (1L << Star) | (1L << Caret) | (1L << Semi))) != 0) || _la==Identifier) {
				{
				setState(902);
				translationUnit(0);
				}
			}

			setState(905);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TranslationUnitContext extends ParserRuleContext {
		public ExternalDeclarationContext externalDeclaration() {
			return getRuleContext(ExternalDeclarationContext.class,0);
		}
		public TranslationUnitContext translationUnit() {
			return getRuleContext(TranslationUnitContext.class,0);
		}
		public TranslationUnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_translationUnit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterTranslationUnit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitTranslationUnit(this);
		}
	}

	public final TranslationUnitContext translationUnit() throws RecognitionException {
		return translationUnit(0);
	}

	private TranslationUnitContext translationUnit(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TranslationUnitContext _localctx = new TranslationUnitContext(_ctx, _parentState);
		TranslationUnitContext _prevctx = _localctx;
		int _startState = 122;
		enterRecursionRule(_localctx, 122, RULE_translationUnit, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(908);
			externalDeclaration();
			}
			_ctx.stop = _input.LT(-1);
			setState(914);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,99,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TranslationUnitContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_translationUnit);
					setState(910);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(911);
					externalDeclaration();
					}
					} 
				}
				setState(916);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,99,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ExternalDeclarationContext extends ParserRuleContext {
		public FunctionDefinitionContext functionDefinition() {
			return getRuleContext(FunctionDefinitionContext.class,0);
		}
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public ExternalDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_externalDeclaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterExternalDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitExternalDeclaration(this);
		}
	}

	public final ExternalDeclarationContext externalDeclaration() throws RecognitionException {
		ExternalDeclarationContext _localctx = new ExternalDeclarationContext(_ctx, getState());
		enterRule(_localctx, 124, RULE_externalDeclaration);
		try {
			setState(920);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,100,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(917);
				functionDefinition();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(918);
				declaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(919);
				match(Semi);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionDefinitionContext extends ParserRuleContext {
		public DeclaratorContext declarator() {
			return getRuleContext(DeclaratorContext.class,0);
		}
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
		}
		public DeclarationSpecifiersContext declarationSpecifiers() {
			return getRuleContext(DeclarationSpecifiersContext.class,0);
		}
		public DeclarationListContext declarationList() {
			return getRuleContext(DeclarationListContext.class,0);
		}
		public FunctionDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDefinition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterFunctionDefinition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitFunctionDefinition(this);
		}
	}

	public final FunctionDefinitionContext functionDefinition() throws RecognitionException {
		FunctionDefinitionContext _localctx = new FunctionDefinitionContext(_ctx, getState());
		enterRule(_localctx, 126, RULE_functionDefinition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(923);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__3) | (1L << Char) | (1L << Const) | (1L << Double) | (1L << Extern) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Static) | (1L << Typedef) | (1L << Unsigned) | (1L << Void))) != 0)) {
				{
				setState(922);
				declarationSpecifiers();
				}
			}

			setState(925);
			declarator();
			setState(927);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__3) | (1L << Char) | (1L << Const) | (1L << Double) | (1L << Extern) | (1L << Float) | (1L << Int) | (1L << Long) | (1L << Short) | (1L << Signed) | (1L << Static) | (1L << Typedef) | (1L << Unsigned) | (1L << Void))) != 0)) {
				{
				setState(926);
				declarationList(0);
				}
			}

			setState(929);
			compoundStatement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationListContext extends ParserRuleContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public DeclarationListContext declarationList() {
			return getRuleContext(DeclarationListContext.class,0);
		}
		public DeclarationListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarationList; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).enterDeclarationList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof quickanddirtycListener ) ((quickanddirtycListener)listener).exitDeclarationList(this);
		}
	}

	public final DeclarationListContext declarationList() throws RecognitionException {
		return declarationList(0);
	}

	private DeclarationListContext declarationList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		DeclarationListContext _localctx = new DeclarationListContext(_ctx, _parentState);
		DeclarationListContext _prevctx = _localctx;
		int _startState = 128;
		enterRecursionRule(_localctx, 128, RULE_declarationList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(932);
			declaration();
			}
			_ctx.stop = _input.LT(-1);
			setState(938);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,103,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new DeclarationListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_declarationList);
					setState(934);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(935);
					declaration();
					}
					} 
				}
				setState(940);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,103,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return postfixExpression_sempred((PostfixExpressionContext)_localctx, predIndex);
		case 2:
			return argumentExpressionList_sempred((ArgumentExpressionListContext)_localctx, predIndex);
		case 6:
			return multiplicativeExpression_sempred((MultiplicativeExpressionContext)_localctx, predIndex);
		case 7:
			return additiveExpression_sempred((AdditiveExpressionContext)_localctx, predIndex);
		case 8:
			return shiftExpression_sempred((ShiftExpressionContext)_localctx, predIndex);
		case 9:
			return relationalExpression_sempred((RelationalExpressionContext)_localctx, predIndex);
		case 10:
			return equalityExpression_sempred((EqualityExpressionContext)_localctx, predIndex);
		case 11:
			return andExpression_sempred((AndExpressionContext)_localctx, predIndex);
		case 12:
			return exclusiveOrExpression_sempred((ExclusiveOrExpressionContext)_localctx, predIndex);
		case 13:
			return inclusiveOrExpression_sempred((InclusiveOrExpressionContext)_localctx, predIndex);
		case 14:
			return logicalAndExpression_sempred((LogicalAndExpressionContext)_localctx, predIndex);
		case 15:
			return logicalOrExpression_sempred((LogicalOrExpressionContext)_localctx, predIndex);
		case 19:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 25:
			return initDeclaratorList_sempred((InitDeclaratorListContext)_localctx, predIndex);
		case 32:
			return directDeclarator_sempred((DirectDeclaratorContext)_localctx, predIndex);
		case 35:
			return typeQualifierList_sempred((TypeQualifierListContext)_localctx, predIndex);
		case 37:
			return parameterList_sempred((ParameterListContext)_localctx, predIndex);
		case 39:
			return identifierList_sempred((IdentifierListContext)_localctx, predIndex);
		case 42:
			return directAbstractDeclarator_sempred((DirectAbstractDeclaratorContext)_localctx, predIndex);
		case 44:
			return initializerList_sempred((InitializerListContext)_localctx, predIndex);
		case 46:
			return designatorList_sempred((DesignatorListContext)_localctx, predIndex);
		case 51:
			return blockItemList_sempred((BlockItemListContext)_localctx, predIndex);
		case 58:
			return forExpression_sempred((ForExpressionContext)_localctx, predIndex);
		case 61:
			return translationUnit_sempred((TranslationUnitContext)_localctx, predIndex);
		case 64:
			return declarationList_sempred((DeclarationListContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean postfixExpression_sempred(PostfixExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 10);
		case 1:
			return precpred(_ctx, 9);
		case 2:
			return precpred(_ctx, 8);
		case 3:
			return precpred(_ctx, 7);
		case 4:
			return precpred(_ctx, 6);
		case 5:
			return precpred(_ctx, 5);
		}
		return true;
	}
	private boolean argumentExpressionList_sempred(ArgumentExpressionListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean multiplicativeExpression_sempred(MultiplicativeExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 7:
			return precpred(_ctx, 3);
		case 8:
			return precpred(_ctx, 2);
		case 9:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean additiveExpression_sempred(AdditiveExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 10:
			return precpred(_ctx, 2);
		case 11:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean shiftExpression_sempred(ShiftExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 12:
			return precpred(_ctx, 2);
		case 13:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean relationalExpression_sempred(RelationalExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 14:
			return precpred(_ctx, 4);
		case 15:
			return precpred(_ctx, 3);
		case 16:
			return precpred(_ctx, 2);
		case 17:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean equalityExpression_sempred(EqualityExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 18:
			return precpred(_ctx, 2);
		case 19:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean andExpression_sempred(AndExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 20:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean exclusiveOrExpression_sempred(ExclusiveOrExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 21:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean inclusiveOrExpression_sempred(InclusiveOrExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 22:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean logicalAndExpression_sempred(LogicalAndExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 23:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean logicalOrExpression_sempred(LogicalOrExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 24:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 25:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean initDeclaratorList_sempred(InitDeclaratorListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 26:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean directDeclarator_sempred(DirectDeclaratorContext _localctx, int predIndex) {
		switch (predIndex) {
		case 27:
			return precpred(_ctx, 8);
		case 28:
			return precpred(_ctx, 7);
		case 29:
			return precpred(_ctx, 6);
		case 30:
			return precpred(_ctx, 5);
		case 31:
			return precpred(_ctx, 4);
		case 32:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean typeQualifierList_sempred(TypeQualifierListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 33:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean parameterList_sempred(ParameterListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 34:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean identifierList_sempred(IdentifierListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 35:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean directAbstractDeclarator_sempred(DirectAbstractDeclaratorContext _localctx, int predIndex) {
		switch (predIndex) {
		case 36:
			return precpred(_ctx, 5);
		case 37:
			return precpred(_ctx, 4);
		case 38:
			return precpred(_ctx, 3);
		case 39:
			return precpred(_ctx, 2);
		case 40:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean initializerList_sempred(InitializerListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 41:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean designatorList_sempred(DesignatorListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 42:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean blockItemList_sempred(BlockItemListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 43:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean forExpression_sempred(ForExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 44:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean translationUnit_sempred(TranslationUnitContext _localctx, int predIndex) {
		switch (predIndex) {
		case 45:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean declarationList_sempred(DeclarationListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 46:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3U\u03b0\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\3\2\3\2\3\2\6\2\u0088\n\2\r\2\16\2\u0089"+
		"\3\2\3\2\3\2\3\2\5\2\u0090\n\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3\u00b4\n\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\5\3\u00be\n\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\7\3\u00cb"+
		"\n\3\f\3\16\3\u00ce\13\3\3\4\3\4\3\4\3\4\3\4\3\4\7\4\u00d6\n\4\f\4\16"+
		"\4\u00d9\13\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\5\5\u00f1\n\5\3\6\3\6\3\7\3\7\3\7\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\5\7\u0102\n\7\3\b\3\b\3\b\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\3\b\3\b\7\b\u0110\n\b\f\b\16\b\u0113\13\b\3\t\3\t"+
		"\3\t\3\t\3\t\3\t\3\t\3\t\3\t\7\t\u011e\n\t\f\t\16\t\u0121\13\t\3\n\3\n"+
		"\3\n\3\n\3\n\3\n\3\n\3\n\3\n\7\n\u012c\n\n\f\n\16\n\u012f\13\n\3\13\3"+
		"\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\7"+
		"\13\u0140\n\13\f\13\16\13\u0143\13\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f"+
		"\3\f\7\f\u014e\n\f\f\f\16\f\u0151\13\f\3\r\3\r\3\r\3\r\3\r\3\r\7\r\u0159"+
		"\n\r\f\r\16\r\u015c\13\r\3\16\3\16\3\16\3\16\3\16\3\16\7\16\u0164\n\16"+
		"\f\16\16\16\u0167\13\16\3\17\3\17\3\17\3\17\3\17\3\17\7\17\u016f\n\17"+
		"\f\17\16\17\u0172\13\17\3\20\3\20\3\20\3\20\3\20\3\20\7\20\u017a\n\20"+
		"\f\20\16\20\u017d\13\20\3\21\3\21\3\21\3\21\3\21\3\21\7\21\u0185\n\21"+
		"\f\21\16\21\u0188\13\21\3\22\3\22\3\22\3\22\3\22\3\22\5\22\u0190\n\22"+
		"\3\23\3\23\3\23\3\23\3\23\3\23\5\23\u0198\n\23\3\24\3\24\3\25\3\25\3\25"+
		"\3\25\3\25\3\25\7\25\u01a2\n\25\f\25\16\25\u01a5\13\25\3\26\3\26\3\27"+
		"\3\27\3\27\3\27\3\27\3\27\3\27\5\27\u01b0\n\27\3\30\6\30\u01b3\n\30\r"+
		"\30\16\30\u01b4\3\31\6\31\u01b8\n\31\r\31\16\31\u01b9\3\32\3\32\3\32\5"+
		"\32\u01bf\n\32\3\33\3\33\3\33\3\33\3\33\3\33\7\33\u01c7\n\33\f\33\16\33"+
		"\u01ca\13\33\3\34\3\34\3\34\3\34\3\34\5\34\u01d1\n\34\3\35\3\35\3\36\3"+
		"\36\3\37\3\37\5\37\u01d9\n\37\3\37\3\37\5\37\u01dd\n\37\5\37\u01df\n\37"+
		"\3 \3 \3!\5!\u01e4\n!\3!\3!\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3"+
		"\"\5\"\u01f3\n\"\3\"\3\"\3\"\3\"\5\"\u01f9\n\"\3\"\3\"\3\"\5\"\u01fe\n"+
		"\"\3\"\5\"\u0201\n\"\3\"\3\"\3\"\3\"\3\"\5\"\u0208\n\"\3\"\3\"\3\"\3\""+
		"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\5\"\u0217\n\"\3\"\3\"\3\"\3\"\3\""+
		"\3\"\3\"\3\"\3\"\3\"\5\"\u0223\n\"\3\"\7\"\u0226\n\"\f\"\16\"\u0229\13"+
		"\"\3#\3#\3#\3#\3#\7#\u0230\n#\f#\16#\u0233\13#\3$\3$\5$\u0237\n$\3$\3"+
		"$\5$\u023b\n$\3$\3$\3$\5$\u0240\n$\3$\3$\5$\u0244\n$\3$\5$\u0247\n$\3"+
		"%\3%\3%\3%\3%\7%\u024e\n%\f%\16%\u0251\13%\3&\3&\3&\3&\3&\5&\u0258\n&"+
		"\3\'\3\'\3\'\3\'\3\'\3\'\7\'\u0260\n\'\f\'\16\'\u0263\13\'\3(\3(\3(\3"+
		"(\3(\5(\u026a\n(\5(\u026c\n(\3)\3)\3)\3)\3)\3)\7)\u0274\n)\f)\16)\u0277"+
		"\13)\3*\3*\5*\u027b\n*\3+\3+\5+\u027f\n+\3+\5+\u0282\n+\3,\3,\3,\3,\3"+
		",\3,\3,\5,\u028b\n,\3,\5,\u028e\n,\3,\3,\3,\3,\5,\u0294\n,\3,\3,\3,\3"+
		",\3,\3,\3,\3,\3,\3,\3,\3,\3,\3,\5,\u02a4\n,\3,\5,\u02a7\n,\3,\3,\3,\5"+
		",\u02ac\n,\3,\5,\u02af\n,\3,\3,\3,\3,\3,\5,\u02b6\n,\3,\3,\3,\3,\3,\3"+
		",\3,\3,\3,\3,\3,\3,\3,\3,\3,\3,\3,\5,\u02c9\n,\3,\7,\u02cc\n,\f,\16,\u02cf"+
		"\13,\3-\3-\3-\3-\3-\3-\3-\3-\3-\3-\5-\u02db\n-\3.\3.\5.\u02df\n.\3.\3"+
		".\3.\3.\3.\5.\u02e6\n.\3.\7.\u02e9\n.\f.\16.\u02ec\13.\3/\3/\3/\3\60\3"+
		"\60\3\60\3\60\3\60\7\60\u02f6\n\60\f\60\16\60\u02f9\13\60\3\61\3\61\3"+
		"\61\3\61\3\61\3\61\5\61\u0301\n\61\3\62\3\62\3\62\3\62\3\62\3\62\5\62"+
		"\u0309\n\62\3\63\3\63\3\63\3\63\3\63\3\63\3\63\3\63\3\63\3\63\3\63\5\63"+
		"\u0316\n\63\3\64\3\64\5\64\u031a\n\64\3\64\3\64\3\65\3\65\3\65\3\65\3"+
		"\65\7\65\u0323\n\65\f\65\16\65\u0326\13\65\3\66\3\66\5\66\u032a\n\66\3"+
		"\67\5\67\u032d\n\67\3\67\3\67\38\38\38\38\38\38\38\58\u0338\n8\38\38\3"+
		"8\38\38\38\58\u0340\n8\39\39\39\39\39\39\39\39\39\39\39\39\59\u034e\n"+
		"9\3:\3:\3:\5:\u0353\n:\3:\3:\5:\u0357\n:\3:\5:\u035a\n:\3:\3:\5:\u035e"+
		"\n:\3:\3:\5:\u0362\n:\5:\u0364\n:\3;\3;\3;\3;\5;\u036a\n;\3<\3<\3<\3<"+
		"\3<\3<\7<\u0372\n<\f<\16<\u0375\13<\3=\3=\3=\3=\3=\3=\3=\3=\3=\5=\u0380"+
		"\n=\3=\3=\3=\3=\3=\5=\u0387\n=\3>\5>\u038a\n>\3>\3>\3?\3?\3?\3?\3?\7?"+
		"\u0393\n?\f?\16?\u0396\13?\3@\3@\3@\5@\u039b\n@\3A\5A\u039e\nA\3A\3A\5"+
		"A\u03a2\nA\3A\3A\3B\3B\3B\3B\3B\7B\u03ab\nB\fB\16B\u03ae\13B\3B\2\33\4"+
		"\6\16\20\22\24\26\30\32\34\36 (\64BHLPVZ^hv|\u0082C\2\4\6\b\n\f\16\20"+
		"\22\24\26\30\32\34\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\^`bdfhj"+
		"lnprtvxz|~\u0080\u0082\2\7\7\2,,..\60\60\63\6389\3\2>H\6\2\5\6\20\20\32"+
		"\32\34\34\b\2\n\n\16\16\21\21\24\25\27\30\35\36\3\2 !\2\u0405\2\u008f"+
		"\3\2\2\2\4\u00b3\3\2\2\2\6\u00cf\3\2\2\2\b\u00f0\3\2\2\2\n\u00f2\3\2\2"+
		"\2\f\u0101\3\2\2\2\16\u0103\3\2\2\2\20\u0114\3\2\2\2\22\u0122\3\2\2\2"+
		"\24\u0130\3\2\2\2\26\u0144\3\2\2\2\30\u0152\3\2\2\2\32\u015d\3\2\2\2\34"+
		"\u0168\3\2\2\2\36\u0173\3\2\2\2 \u017e\3\2\2\2\"\u0189\3\2\2\2$\u0197"+
		"\3\2\2\2&\u0199\3\2\2\2(\u019b\3\2\2\2*\u01a6\3\2\2\2,\u01af\3\2\2\2."+
		"\u01b2\3\2\2\2\60\u01b7\3\2\2\2\62\u01be\3\2\2\2\64\u01c0\3\2\2\2\66\u01d0"+
		"\3\2\2\28\u01d2\3\2\2\2:\u01d4\3\2\2\2<\u01de\3\2\2\2>\u01e0\3\2\2\2@"+
		"\u01e3\3\2\2\2B\u01f8\3\2\2\2D\u0231\3\2\2\2F\u0246\3\2\2\2H\u0248\3\2"+
		"\2\2J\u0257\3\2\2\2L\u0259\3\2\2\2N\u026b\3\2\2\2P\u026d\3\2\2\2R\u0278"+
		"\3\2\2\2T\u0281\3\2\2\2V\u02a6\3\2\2\2X\u02da\3\2\2\2Z\u02dc\3\2\2\2\\"+
		"\u02ed\3\2\2\2^\u02f0\3\2\2\2`\u0300\3\2\2\2b\u0308\3\2\2\2d\u0315\3\2"+
		"\2\2f\u0317\3\2\2\2h\u031d\3\2\2\2j\u0329\3\2\2\2l\u032c\3\2\2\2n\u033f"+
		"\3\2\2\2p\u034d\3\2\2\2r\u0363\3\2\2\2t\u0369\3\2\2\2v\u036b\3\2\2\2x"+
		"\u0386\3\2\2\2z\u0389\3\2\2\2|\u038d\3\2\2\2~\u039a\3\2\2\2\u0080\u039d"+
		"\3\2\2\2\u0082\u03a5\3\2\2\2\u0084\u0090\7N\2\2\u0085\u0090\7O\2\2\u0086"+
		"\u0088\7Q\2\2\u0087\u0086\3\2\2\2\u0088\u0089\3\2\2\2\u0089\u0087\3\2"+
		"\2\2\u0089\u008a\3\2\2\2\u008a\u0090\3\2\2\2\u008b\u008c\7 \2\2\u008c"+
		"\u008d\5(\25\2\u008d\u008e\7!\2\2\u008e\u0090\3\2\2\2\u008f\u0084\3\2"+
		"\2\2\u008f\u0085\3\2\2\2\u008f\u0087\3\2\2\2\u008f\u008b\3\2\2\2\u0090"+
		"\3\3\2\2\2\u0091\u0092\b\3\1\2\u0092\u00b4\5\2\2\2\u0093\u0094\7 \2\2"+
		"\u0094\u0095\5R*\2\u0095\u0096\7!\2\2\u0096\u0097\7$\2\2\u0097\u0098\5"+
		"Z.\2\u0098\u0099\7%\2\2\u0099\u00b4\3\2\2\2\u009a\u009b\7 \2\2\u009b\u009c"+
		"\5R*\2\u009c\u009d\7!\2\2\u009d\u009e\7$\2\2\u009e\u009f\5Z.\2\u009f\u00a0"+
		"\7=\2\2\u00a0\u00a1\7%\2\2\u00a1\u00b4\3\2\2\2\u00a2\u00a3\7\3\2\2\u00a3"+
		"\u00a4\7 \2\2\u00a4\u00a5\5R*\2\u00a5\u00a6\7!\2\2\u00a6\u00a7\7$\2\2"+
		"\u00a7\u00a8\5Z.\2\u00a8\u00a9\7%\2\2\u00a9\u00b4\3\2\2\2\u00aa\u00ab"+
		"\7\3\2\2\u00ab\u00ac\7 \2\2\u00ac\u00ad\5R*\2\u00ad\u00ae\7!\2\2\u00ae"+
		"\u00af\7$\2\2\u00af\u00b0\5Z.\2\u00b0\u00b1\7=\2\2\u00b1\u00b2\7%\2\2"+
		"\u00b2\u00b4\3\2\2\2\u00b3\u0091\3\2\2\2\u00b3\u0093\3\2\2\2\u00b3\u009a"+
		"\3\2\2\2\u00b3\u00a2\3\2\2\2\u00b3\u00aa\3\2\2\2\u00b4\u00cc\3\2\2\2\u00b5"+
		"\u00b6\f\f\2\2\u00b6\u00b7\7\"\2\2\u00b7\u00b8\5(\25\2\u00b8\u00b9\7#"+
		"\2\2\u00b9\u00cb\3\2\2\2\u00ba\u00bb\f\13\2\2\u00bb\u00bd\7 \2\2\u00bc"+
		"\u00be\5\6\4\2\u00bd\u00bc\3\2\2\2\u00bd\u00be\3\2\2\2\u00be\u00bf\3\2"+
		"\2\2\u00bf\u00cb\7!\2\2\u00c0\u00c1\f\n\2\2\u00c1\u00c2\7L\2\2\u00c2\u00cb"+
		"\7N\2\2\u00c3\u00c4\f\t\2\2\u00c4\u00c5\7K\2\2\u00c5\u00cb\7N\2\2\u00c6"+
		"\u00c7\f\b\2\2\u00c7\u00cb\7-\2\2\u00c8\u00c9\f\7\2\2\u00c9\u00cb\7/\2"+
		"\2\u00ca\u00b5\3\2\2\2\u00ca\u00ba\3\2\2\2\u00ca\u00c0\3\2\2\2\u00ca\u00c3"+
		"\3\2\2\2\u00ca\u00c6\3\2\2\2\u00ca\u00c8\3\2\2\2\u00cb\u00ce\3\2\2\2\u00cc"+
		"\u00ca\3\2\2\2\u00cc\u00cd\3\2\2\2\u00cd\5\3\2\2\2\u00ce\u00cc\3\2\2\2"+
		"\u00cf\u00d0\b\4\1\2\u00d0\u00d1\5$\23\2\u00d1\u00d7\3\2\2\2\u00d2\u00d3"+
		"\f\3\2\2\u00d3\u00d4\7=\2\2\u00d4\u00d6\5$\23\2\u00d5\u00d2\3\2\2\2\u00d6"+
		"\u00d9\3\2\2\2\u00d7\u00d5\3\2\2\2\u00d7\u00d8\3\2\2\2\u00d8\7\3\2\2\2"+
		"\u00d9\u00d7\3\2\2\2\u00da\u00f1\5\4\3\2\u00db\u00dc\7-\2\2\u00dc\u00f1"+
		"\5\b\5\2\u00dd\u00de\7/\2\2\u00de\u00f1\5\b\5\2\u00df\u00e0\5\n\6\2\u00e0"+
		"\u00e1\5\f\7\2\u00e1\u00f1\3\2\2\2\u00e2\u00e3\7\31\2\2\u00e3\u00f1\5"+
		"\b\5\2\u00e4\u00e5\7\31\2\2\u00e5\u00e6\7 \2\2\u00e6\u00e7\5R*\2\u00e7"+
		"\u00e8\7!\2\2\u00e8\u00f1\3\2\2\2\u00e9\u00ea\7\4\2\2\u00ea\u00eb\7 \2"+
		"\2\u00eb\u00ec\5R*\2\u00ec\u00ed\7!\2\2\u00ed\u00f1\3\2\2\2\u00ee\u00ef"+
		"\7\65\2\2\u00ef\u00f1\7N\2\2\u00f0\u00da\3\2\2\2\u00f0\u00db\3\2\2\2\u00f0"+
		"\u00dd\3\2\2\2\u00f0\u00df\3\2\2\2\u00f0\u00e2\3\2\2\2\u00f0\u00e4\3\2"+
		"\2\2\u00f0\u00e9\3\2\2\2\u00f0\u00ee\3\2\2\2\u00f1\t\3\2\2\2\u00f2\u00f3"+
		"\t\2\2\2\u00f3\13\3\2\2\2\u00f4\u00f5\7 \2\2\u00f5\u00f6\5R*\2\u00f6\u00f7"+
		"\7!\2\2\u00f7\u00f8\5\f\7\2\u00f8\u0102\3\2\2\2\u00f9\u00fa\7\3\2\2\u00fa"+
		"\u00fb\7 \2\2\u00fb\u00fc\5R*\2\u00fc\u00fd\7!\2\2\u00fd\u00fe\5\f\7\2"+
		"\u00fe\u0102\3\2\2\2\u00ff\u0102\5\b\5\2\u0100\u0102\7P\2\2\u0101\u00f4"+
		"\3\2\2\2\u0101\u00f9\3\2\2\2\u0101\u00ff\3\2\2\2\u0101\u0100\3\2\2\2\u0102"+
		"\r\3\2\2\2\u0103\u0104\b\b\1\2\u0104\u0105\5\f\7\2\u0105\u0111\3\2\2\2"+
		"\u0106\u0107\f\5\2\2\u0107\u0108\7\60\2\2\u0108\u0110\5\f\7\2\u0109\u010a"+
		"\f\4\2\2\u010a\u010b\7\61\2\2\u010b\u0110\5\f\7\2\u010c\u010d\f\3\2\2"+
		"\u010d\u010e\7\62\2\2\u010e\u0110\5\f\7\2\u010f\u0106\3\2\2\2\u010f\u0109"+
		"\3\2\2\2\u010f\u010c\3\2\2\2\u0110\u0113\3\2\2\2\u0111\u010f\3\2\2\2\u0111"+
		"\u0112\3\2\2\2\u0112\17\3\2\2\2\u0113\u0111\3\2\2\2\u0114\u0115\b\t\1"+
		"\2\u0115\u0116\5\16\b\2\u0116\u011f\3\2\2\2\u0117\u0118\f\4\2\2\u0118"+
		"\u0119\7,\2\2\u0119\u011e\5\16\b\2\u011a\u011b\f\3\2\2\u011b\u011c\7."+
		"\2\2\u011c\u011e\5\16\b\2\u011d\u0117\3\2\2\2\u011d\u011a\3\2\2\2\u011e"+
		"\u0121\3\2\2\2\u011f\u011d\3\2\2\2\u011f\u0120\3\2\2\2\u0120\21\3\2\2"+
		"\2\u0121\u011f\3\2\2\2\u0122\u0123\b\n\1\2\u0123\u0124\5\20\t\2\u0124"+
		"\u012d\3\2\2\2\u0125\u0126\f\4\2\2\u0126\u0127\7*\2\2\u0127\u012c\5\20"+
		"\t\2\u0128\u0129\f\3\2\2\u0129\u012a\7+\2\2\u012a\u012c\5\20\t\2\u012b"+
		"\u0125\3\2\2\2\u012b\u0128\3\2\2\2\u012c\u012f\3\2\2\2\u012d\u012b\3\2"+
		"\2\2\u012d\u012e\3\2\2\2\u012e\23\3\2\2\2\u012f\u012d\3\2\2\2\u0130\u0131"+
		"\b\13\1\2\u0131\u0132\5\22\n\2\u0132\u0141\3\2\2\2\u0133\u0134\f\6\2\2"+
		"\u0134\u0135\7&\2\2\u0135\u0140\5\22\n\2\u0136\u0137\f\5\2\2\u0137\u0138"+
		"\7(\2\2\u0138\u0140\5\22\n\2\u0139\u013a\f\4\2\2\u013a\u013b\7\'\2\2\u013b"+
		"\u0140\5\22\n\2\u013c\u013d\f\3\2\2\u013d\u013e\7)\2\2\u013e\u0140\5\22"+
		"\n\2\u013f\u0133\3\2\2\2\u013f\u0136\3\2\2\2\u013f\u0139\3\2\2\2\u013f"+
		"\u013c\3\2\2\2\u0140\u0143\3\2\2\2\u0141\u013f\3\2\2\2\u0141\u0142\3\2"+
		"\2\2\u0142\25\3\2\2\2\u0143\u0141\3\2\2\2\u0144\u0145\b\f\1\2\u0145\u0146"+
		"\5\24\13\2\u0146\u014f\3\2\2\2\u0147\u0148\f\4\2\2\u0148\u0149\7I\2\2"+
		"\u0149\u014e\5\24\13\2\u014a\u014b\f\3\2\2\u014b\u014c\7J\2\2\u014c\u014e"+
		"\5\24\13\2\u014d\u0147\3\2\2\2\u014d\u014a\3\2\2\2\u014e\u0151\3\2\2\2"+
		"\u014f\u014d\3\2\2\2\u014f\u0150\3\2\2\2\u0150\27\3\2\2\2\u0151\u014f"+
		"\3\2\2\2\u0152\u0153\b\r\1\2\u0153\u0154\5\26\f\2\u0154\u015a\3\2\2\2"+
		"\u0155\u0156\f\3\2\2\u0156\u0157\7\63\2\2\u0157\u0159\5\26\f\2\u0158\u0155"+
		"\3\2\2\2\u0159\u015c\3\2\2\2\u015a\u0158\3\2\2\2\u015a\u015b\3\2\2\2\u015b"+
		"\31\3\2\2\2\u015c\u015a\3\2\2\2\u015d\u015e\b\16\1\2\u015e\u015f\5\30"+
		"\r\2\u015f\u0165\3\2\2\2\u0160\u0161\f\3\2\2\u0161\u0162\7\67\2\2\u0162"+
		"\u0164\5\30\r\2\u0163\u0160\3\2\2\2\u0164\u0167\3\2\2\2\u0165\u0163\3"+
		"\2\2\2\u0165\u0166\3\2\2\2\u0166\33\3\2\2\2\u0167\u0165\3\2\2\2\u0168"+
		"\u0169\b\17\1\2\u0169\u016a\5\32\16\2\u016a\u0170\3\2\2\2\u016b\u016c"+
		"\f\3\2\2\u016c\u016d\7\64\2\2\u016d\u016f\5\32\16\2\u016e\u016b\3\2\2"+
		"\2\u016f\u0172\3\2\2\2\u0170\u016e\3\2\2\2\u0170\u0171\3\2\2\2\u0171\35"+
		"\3\2\2\2\u0172\u0170\3\2\2\2\u0173\u0174\b\20\1\2\u0174\u0175\5\34\17"+
		"\2\u0175\u017b\3\2\2\2\u0176\u0177\f\3\2\2\u0177\u0178\7\65\2\2\u0178"+
		"\u017a\5\34\17\2\u0179\u0176\3\2\2\2\u017a\u017d\3\2\2\2\u017b\u0179\3"+
		"\2\2\2\u017b\u017c\3\2\2\2\u017c\37\3\2\2\2\u017d\u017b\3\2\2\2\u017e"+
		"\u017f\b\21\1\2\u017f\u0180\5\36\20\2\u0180\u0186\3\2\2\2\u0181\u0182"+
		"\f\3\2\2\u0182\u0183\7\66\2\2\u0183\u0185\5\36\20\2\u0184\u0181\3\2\2"+
		"\2\u0185\u0188\3\2\2\2\u0186\u0184\3\2\2\2\u0186\u0187\3\2\2\2\u0187!"+
		"\3\2\2\2\u0188\u0186\3\2\2\2\u0189\u018f\5 \21\2\u018a\u018b\7:\2\2\u018b"+
		"\u018c\5(\25\2\u018c\u018d\7;\2\2\u018d\u018e\5\"\22\2\u018e\u0190\3\2"+
		"\2\2\u018f\u018a\3\2\2\2\u018f\u0190\3\2\2\2\u0190#\3\2\2\2\u0191\u0198"+
		"\5\"\22\2\u0192\u0193\5\b\5\2\u0193\u0194\5&\24\2\u0194\u0195\5$\23\2"+
		"\u0195\u0198\3\2\2\2\u0196\u0198\7P\2\2\u0197\u0191\3\2\2\2\u0197\u0192"+
		"\3\2\2\2\u0197\u0196\3\2\2\2\u0198%\3\2\2\2\u0199\u019a\t\3\2\2\u019a"+
		"\'\3\2\2\2\u019b\u019c\b\25\1\2\u019c\u019d\5$\23\2\u019d\u01a3\3\2\2"+
		"\2\u019e\u019f\f\3\2\2\u019f\u01a0\7=\2\2\u01a0\u01a2\5$\23\2\u01a1\u019e"+
		"\3\2\2\2\u01a2\u01a5\3\2\2\2\u01a3\u01a1\3\2\2\2\u01a3\u01a4\3\2\2\2\u01a4"+
		")\3\2\2\2\u01a5\u01a3\3\2\2\2\u01a6\u01a7\5\"\22\2\u01a7+\3\2\2\2\u01a8"+
		"\u01a9\5.\30\2\u01a9\u01aa\5\64\33\2\u01aa\u01ab\7<\2\2\u01ab\u01b0\3"+
		"\2\2\2\u01ac\u01ad\5.\30\2\u01ad\u01ae\7<\2\2\u01ae\u01b0\3\2\2\2\u01af"+
		"\u01a8\3\2\2\2\u01af\u01ac\3\2\2\2\u01b0-\3\2\2\2\u01b1\u01b3\5\62\32"+
		"\2\u01b2\u01b1\3\2\2\2\u01b3\u01b4\3\2\2\2\u01b4\u01b2\3\2\2\2\u01b4\u01b5"+
		"\3\2\2\2\u01b5/\3\2\2\2\u01b6\u01b8\5\62\32\2\u01b7\u01b6\3\2\2\2\u01b8"+
		"\u01b9\3\2\2\2\u01b9\u01b7\3\2\2\2\u01b9\u01ba\3\2\2\2\u01ba\61\3\2\2"+
		"\2\u01bb\u01bf\58\35\2\u01bc\u01bf\5:\36\2\u01bd\u01bf\5> \2\u01be\u01bb"+
		"\3\2\2\2\u01be\u01bc\3\2\2\2\u01be\u01bd\3\2\2\2\u01bf\63\3\2\2\2\u01c0"+
		"\u01c1\b\33\1\2\u01c1\u01c2\5\66\34\2\u01c2\u01c8\3\2\2\2\u01c3\u01c4"+
		"\f\3\2\2\u01c4\u01c5\7=\2\2\u01c5\u01c7\5\66\34\2\u01c6\u01c3\3\2\2\2"+
		"\u01c7\u01ca\3\2\2\2\u01c8\u01c6\3\2\2\2\u01c8\u01c9\3\2\2\2\u01c9\65"+
		"\3\2\2\2\u01ca\u01c8\3\2\2\2\u01cb\u01d1\5@!\2\u01cc\u01cd\5@!\2\u01cd"+
		"\u01ce\7>\2\2\u01ce\u01cf\5X-\2\u01cf\u01d1\3\2\2\2\u01d0\u01cb\3\2\2"+
		"\2\u01d0\u01cc\3\2\2\2\u01d1\67\3\2\2\2\u01d2\u01d3\t\4\2\2\u01d39\3\2"+
		"\2\2\u01d4\u01d5\t\5\2\2\u01d5;\3\2\2\2\u01d6\u01d8\5:\36\2\u01d7\u01d9"+
		"\5<\37\2\u01d8\u01d7\3\2\2\2\u01d8\u01d9\3\2\2\2\u01d9\u01df\3\2\2\2\u01da"+
		"\u01dc\5> \2\u01db\u01dd\5<\37\2\u01dc\u01db\3\2\2\2\u01dc\u01dd\3\2\2"+
		"\2\u01dd\u01df\3\2\2\2\u01de\u01d6\3\2\2\2\u01de\u01da\3\2\2\2\u01df="+
		"\3\2\2\2\u01e0\u01e1\7\13\2\2\u01e1?\3\2\2\2\u01e2\u01e4\5F$\2\u01e3\u01e2"+
		"\3\2\2\2\u01e3\u01e4\3\2\2\2\u01e4\u01e5\3\2\2\2\u01e5\u01e6\5B\"\2\u01e6"+
		"A\3\2\2\2\u01e7\u01e8\b\"\1\2\u01e8\u01f9\7N\2\2\u01e9\u01ea\7 \2\2\u01ea"+
		"\u01eb\5@!\2\u01eb\u01ec\7!\2\2\u01ec\u01f9\3\2\2\2\u01ed\u01ee\7N\2\2"+
		"\u01ee\u01ef\7;\2\2\u01ef\u01f9\7P\2\2\u01f0\u01f2\7 \2\2\u01f1\u01f3"+
		"\5:\36\2\u01f2\u01f1\3\2\2\2\u01f2\u01f3\3\2\2\2\u01f3\u01f4\3\2\2\2\u01f4"+
		"\u01f5\5F$\2\u01f5\u01f6\5B\"\2\u01f6\u01f7\7!\2\2\u01f7\u01f9\3\2\2\2"+
		"\u01f8\u01e7\3\2\2\2\u01f8\u01e9\3\2\2\2\u01f8\u01ed\3\2\2\2\u01f8\u01f0"+
		"\3\2\2\2\u01f9\u0227\3\2\2\2\u01fa\u01fb\f\n\2\2\u01fb\u01fd\7\"\2\2\u01fc"+
		"\u01fe\5H%\2\u01fd\u01fc\3\2\2\2\u01fd\u01fe\3\2\2\2\u01fe\u0200\3\2\2"+
		"\2\u01ff\u0201\5$\23\2\u0200\u01ff\3\2\2\2\u0200\u0201\3\2\2\2\u0201\u0202"+
		"\3\2\2\2\u0202\u0226\7#\2\2\u0203\u0204\f\t\2\2\u0204\u0205\7\"\2\2\u0205"+
		"\u0207\7\32\2\2\u0206\u0208\5H%\2\u0207\u0206\3\2\2\2\u0207\u0208\3\2"+
		"\2\2\u0208\u0209\3\2\2\2\u0209\u020a\5$\23\2\u020a\u020b\7#\2\2\u020b"+
		"\u0226\3\2\2\2\u020c\u020d\f\b\2\2\u020d\u020e\7\"\2\2\u020e\u020f\5H"+
		"%\2\u020f\u0210\7\32\2\2\u0210\u0211\5$\23\2\u0211\u0212\7#\2\2\u0212"+
		"\u0226\3\2\2\2\u0213\u0214\f\7\2\2\u0214\u0216\7\"\2\2\u0215\u0217\5H"+
		"%\2\u0216\u0215\3\2\2\2\u0216\u0217\3\2\2\2\u0217\u0218\3\2\2\2\u0218"+
		"\u0219\7\60\2\2\u0219\u0226\7#\2\2\u021a\u021b\f\6\2\2\u021b\u021c\7 "+
		"\2\2\u021c\u021d\5J&\2\u021d\u021e\7!\2\2\u021e\u0226\3\2\2\2\u021f\u0220"+
		"\f\5\2\2\u0220\u0222\7 \2\2\u0221\u0223\5P)\2\u0222\u0221\3\2\2\2\u0222"+
		"\u0223\3\2\2\2\u0223\u0224\3\2\2\2\u0224\u0226\7!\2\2\u0225\u01fa\3\2"+
		"\2\2\u0225\u0203\3\2\2\2\u0225\u020c\3\2\2\2\u0225\u0213\3\2\2\2\u0225"+
		"\u021a\3\2\2\2\u0225\u021f\3\2\2\2\u0226\u0229\3\2\2\2\u0227\u0225\3\2"+
		"\2\2\u0227\u0228\3\2\2\2\u0228C\3\2\2\2\u0229\u0227\3\2\2\2\u022a\u0230"+
		"\n\6\2\2\u022b\u022c\7 \2\2\u022c\u022d\5D#\2\u022d\u022e\7!\2\2\u022e"+
		"\u0230\3\2\2\2\u022f\u022a\3\2\2\2\u022f\u022b\3\2\2\2\u0230\u0233\3\2"+
		"\2\2\u0231\u022f\3\2\2\2\u0231\u0232\3\2\2\2\u0232E\3\2\2\2\u0233\u0231"+
		"\3\2\2\2\u0234\u0236\7\60\2\2\u0235\u0237\5H%\2\u0236\u0235\3\2\2\2\u0236"+
		"\u0237\3\2\2\2\u0237\u0247\3\2\2\2\u0238\u023a\7\60\2\2\u0239\u023b\5"+
		"H%\2\u023a\u0239\3\2\2\2\u023a\u023b\3\2\2\2\u023b\u023c\3\2\2\2\u023c"+
		"\u0247\5F$\2\u023d\u023f\7\67\2\2\u023e\u0240\5H%\2\u023f\u023e\3\2\2"+
		"\2\u023f\u0240\3\2\2\2\u0240\u0247\3\2\2\2\u0241\u0243\7\67\2\2\u0242"+
		"\u0244\5H%\2\u0243\u0242\3\2\2\2\u0243\u0244\3\2\2\2\u0244\u0245\3\2\2"+
		"\2\u0245\u0247\5F$\2\u0246\u0234\3\2\2\2\u0246\u0238\3\2\2\2\u0246\u023d"+
		"\3\2\2\2\u0246\u0241\3\2\2\2\u0247G\3\2\2\2\u0248\u0249\b%\1\2\u0249\u024a"+
		"\5> \2\u024a\u024f\3\2\2\2\u024b\u024c\f\3\2\2\u024c\u024e\5> \2\u024d"+
		"\u024b\3\2\2\2\u024e\u0251\3\2\2\2\u024f\u024d\3\2\2\2\u024f\u0250\3\2"+
		"\2\2\u0250I\3\2\2\2\u0251\u024f\3\2\2\2\u0252\u0258\5L\'\2\u0253\u0254"+
		"\5L\'\2\u0254\u0255\7=\2\2\u0255\u0256\7M\2\2\u0256\u0258\3\2\2\2\u0257"+
		"\u0252\3\2\2\2\u0257\u0253\3\2\2\2\u0258K\3\2\2\2\u0259\u025a\b\'\1\2"+
		"\u025a\u025b\5N(\2\u025b\u0261\3\2\2\2\u025c\u025d\f\3\2\2\u025d\u025e"+
		"\7=\2\2\u025e\u0260\5N(\2\u025f\u025c\3\2\2\2\u0260\u0263\3\2\2\2\u0261"+
		"\u025f\3\2\2\2\u0261\u0262\3\2\2\2\u0262M\3\2\2\2\u0263\u0261\3\2\2\2"+
		"\u0264\u0265\5.\30\2\u0265\u0266\5@!\2\u0266\u026c\3\2\2\2\u0267\u0269"+
		"\5\60\31\2\u0268\u026a\5T+\2\u0269\u0268\3\2\2\2\u0269\u026a\3\2\2\2\u026a"+
		"\u026c\3\2\2\2\u026b\u0264\3\2\2\2\u026b\u0267\3\2\2\2\u026cO\3\2\2\2"+
		"\u026d\u026e\b)\1\2\u026e\u026f\7N\2\2\u026f\u0275\3\2\2\2\u0270\u0271"+
		"\f\3\2\2\u0271\u0272\7=\2\2\u0272\u0274\7N\2\2\u0273\u0270\3\2\2\2\u0274"+
		"\u0277\3\2\2\2\u0275\u0273\3\2\2\2\u0275\u0276\3\2\2\2\u0276Q\3\2\2\2"+
		"\u0277\u0275\3\2\2\2\u0278\u027a\5<\37\2\u0279\u027b\5T+\2\u027a\u0279"+
		"\3\2\2\2\u027a\u027b\3\2\2\2\u027bS\3\2\2\2\u027c\u0282\5F$\2\u027d\u027f"+
		"\5F$\2\u027e\u027d\3\2\2\2\u027e\u027f\3\2\2\2\u027f\u0280\3\2\2\2\u0280"+
		"\u0282\5V,\2\u0281\u027c\3\2\2\2\u0281\u027e\3\2\2\2\u0282U\3\2\2\2\u0283"+
		"\u0284\b,\1\2\u0284\u0285\7 \2\2\u0285\u0286\5T+\2\u0286\u0287\7!\2\2"+
		"\u0287\u02a7\3\2\2\2\u0288\u028a\7\"\2\2\u0289\u028b\5H%\2\u028a\u0289"+
		"\3\2\2\2\u028a\u028b\3\2\2\2\u028b\u028d\3\2\2\2\u028c\u028e\5$\23\2\u028d"+
		"\u028c\3\2\2\2\u028d\u028e\3\2\2\2\u028e\u028f\3\2\2\2\u028f\u02a7\7#"+
		"\2\2\u0290\u0291\7\"\2\2\u0291\u0293\7\32\2\2\u0292\u0294\5H%\2\u0293"+
		"\u0292\3\2\2\2\u0293\u0294\3\2\2\2\u0294\u0295\3\2\2\2\u0295\u0296\5$"+
		"\23\2\u0296\u0297\7#\2\2\u0297\u02a7\3\2\2\2\u0298\u0299\7\"\2\2\u0299"+
		"\u029a\5H%\2\u029a\u029b\7\32\2\2\u029b\u029c\5$\23\2\u029c\u029d\7#\2"+
		"\2\u029d\u02a7\3\2\2\2\u029e\u029f\7\"\2\2\u029f\u02a0\7\60\2\2\u02a0"+
		"\u02a7\7#\2\2\u02a1\u02a3\7 \2\2\u02a2\u02a4\5J&\2\u02a3\u02a2\3\2\2\2"+
		"\u02a3\u02a4\3\2\2\2\u02a4\u02a5\3\2\2\2\u02a5\u02a7\7!\2\2\u02a6\u0283"+
		"\3\2\2\2\u02a6\u0288\3\2\2\2\u02a6\u0290\3\2\2\2\u02a6\u0298\3\2\2\2\u02a6"+
		"\u029e\3\2\2\2\u02a6\u02a1\3\2\2\2\u02a7\u02cd\3\2\2\2\u02a8\u02a9\f\7"+
		"\2\2\u02a9\u02ab\7\"\2\2\u02aa\u02ac\5H%\2\u02ab\u02aa\3\2\2\2\u02ab\u02ac"+
		"\3\2\2\2\u02ac\u02ae\3\2\2\2\u02ad\u02af\5$\23\2\u02ae\u02ad\3\2\2\2\u02ae"+
		"\u02af\3\2\2\2\u02af\u02b0\3\2\2\2\u02b0\u02cc\7#\2\2\u02b1\u02b2\f\6"+
		"\2\2\u02b2\u02b3\7\"\2\2\u02b3\u02b5\7\32\2\2\u02b4\u02b6\5H%\2\u02b5"+
		"\u02b4\3\2\2\2\u02b5\u02b6\3\2\2\2\u02b6\u02b7\3\2\2\2\u02b7\u02b8\5$"+
		"\23\2\u02b8\u02b9\7#\2\2\u02b9\u02cc\3\2\2\2\u02ba\u02bb\f\5\2\2\u02bb"+
		"\u02bc\7\"\2\2\u02bc\u02bd\5H%\2\u02bd\u02be\7\32\2\2\u02be\u02bf\5$\23"+
		"\2\u02bf\u02c0\7#\2\2\u02c0\u02cc\3\2\2\2\u02c1\u02c2\f\4\2\2\u02c2\u02c3"+
		"\7\"\2\2\u02c3\u02c4\7\60\2\2\u02c4\u02cc\7#\2\2\u02c5\u02c6\f\3\2\2\u02c6"+
		"\u02c8\7 \2\2\u02c7\u02c9\5J&\2\u02c8\u02c7\3\2\2\2\u02c8\u02c9\3\2\2"+
		"\2\u02c9\u02ca\3\2\2\2\u02ca\u02cc\7!\2\2\u02cb\u02a8\3\2\2\2\u02cb\u02b1"+
		"\3\2\2\2\u02cb\u02ba\3\2\2\2\u02cb\u02c1\3\2\2\2\u02cb\u02c5\3\2\2\2\u02cc"+
		"\u02cf\3\2\2\2\u02cd\u02cb\3\2\2\2\u02cd\u02ce\3\2\2\2\u02ceW\3\2\2\2"+
		"\u02cf\u02cd\3\2\2\2\u02d0\u02db\5$\23\2\u02d1\u02d2\7$\2\2\u02d2\u02d3"+
		"\5Z.\2\u02d3\u02d4\7%\2\2\u02d4\u02db\3\2\2\2\u02d5\u02d6\7$\2\2\u02d6"+
		"\u02d7\5Z.\2\u02d7\u02d8\7=\2\2\u02d8\u02d9\7%\2\2\u02d9\u02db\3\2\2\2"+
		"\u02da\u02d0\3\2\2\2\u02da\u02d1\3\2\2\2\u02da\u02d5\3\2\2\2\u02dbY\3"+
		"\2\2\2\u02dc\u02de\b.\1\2\u02dd\u02df\5\\/\2\u02de\u02dd\3\2\2\2\u02de"+
		"\u02df\3\2\2\2\u02df\u02e0\3\2\2\2\u02e0\u02e1\5X-\2\u02e1\u02ea\3\2\2"+
		"\2\u02e2\u02e3\f\3\2\2\u02e3\u02e5\7=\2\2\u02e4\u02e6\5\\/\2\u02e5\u02e4"+
		"\3\2\2\2\u02e5\u02e6\3\2\2\2\u02e6\u02e7\3\2\2\2\u02e7\u02e9\5X-\2\u02e8"+
		"\u02e2\3\2\2\2\u02e9\u02ec\3\2\2\2\u02ea\u02e8\3\2\2\2\u02ea\u02eb\3\2"+
		"\2\2\u02eb[\3\2\2\2\u02ec\u02ea\3\2\2\2\u02ed\u02ee\5^\60\2\u02ee\u02ef"+
		"\7>\2\2\u02ef]\3\2\2\2\u02f0\u02f1\b\60\1\2\u02f1\u02f2\5`\61\2\u02f2"+
		"\u02f7\3\2\2\2\u02f3\u02f4\f\3\2\2\u02f4\u02f6\5`\61\2\u02f5\u02f3\3\2"+
		"\2\2\u02f6\u02f9\3\2\2\2\u02f7\u02f5\3\2\2\2\u02f7\u02f8\3\2\2\2\u02f8"+
		"_\3\2\2\2\u02f9\u02f7\3\2\2\2\u02fa\u02fb\7\"\2\2\u02fb\u02fc\5*\26\2"+
		"\u02fc\u02fd\7#\2\2\u02fd\u0301\3\2\2\2\u02fe\u02ff\7L\2\2\u02ff\u0301"+
		"\7N\2\2\u0300\u02fa\3\2\2\2\u0300\u02fe\3\2\2\2\u0301a\3\2\2\2\u0302\u0309"+
		"\5d\63\2\u0303\u0309\5f\64\2\u0304\u0309\5l\67\2\u0305\u0309\5n8\2\u0306"+
		"\u0309\5p9\2\u0307\u0309\5x=\2\u0308\u0302\3\2\2\2\u0308\u0303\3\2\2\2"+
		"\u0308\u0304\3\2\2\2\u0308\u0305\3\2\2\2\u0308\u0306\3\2\2\2\u0308\u0307"+
		"\3\2\2\2\u0309c\3\2\2\2\u030a\u030b\7N\2\2\u030b\u030c\7;\2\2\u030c\u0316"+
		"\5b\62\2\u030d\u030e\7\t\2\2\u030e\u030f\5*\26\2\u030f\u0310\7;\2\2\u0310"+
		"\u0311\5b\62\2\u0311\u0316\3\2\2\2\u0312\u0313\7\r\2\2\u0313\u0314\7;"+
		"\2\2\u0314\u0316\5b\62\2\u0315\u030a\3\2\2\2\u0315\u030d\3\2\2\2\u0315"+
		"\u0312\3\2\2\2\u0316e\3\2\2\2\u0317\u0319\7$\2\2\u0318\u031a\5h\65\2\u0319"+
		"\u0318\3\2\2\2\u0319\u031a\3\2\2\2\u031a\u031b\3\2\2\2\u031b\u031c\7%"+
		"\2\2\u031cg\3\2\2\2\u031d\u031e\b\65\1\2\u031e\u031f\5j\66\2\u031f\u0324"+
		"\3\2\2\2\u0320\u0321\f\3\2\2\u0321\u0323\5j\66\2\u0322\u0320\3\2\2\2\u0323"+
		"\u0326\3\2\2\2\u0324\u0322\3\2\2\2\u0324\u0325\3\2\2\2\u0325i\3\2\2\2"+
		"\u0326\u0324\3\2\2\2\u0327\u032a\5b\62\2\u0328\u032a\5,\27\2\u0329\u0327"+
		"\3\2\2\2\u0329\u0328\3\2\2\2\u032ak\3\2\2\2\u032b\u032d\5(\25\2\u032c"+
		"\u032b\3\2\2\2\u032c\u032d\3\2\2\2\u032d\u032e\3\2\2\2\u032e\u032f\7<"+
		"\2\2\u032fm\3\2\2\2\u0330\u0331\7\23\2\2\u0331\u0332\7 \2\2\u0332\u0333"+
		"\5(\25\2\u0333\u0334\7!\2\2\u0334\u0337\5b\62\2\u0335\u0336\7\17\2\2\u0336"+
		"\u0338\5b\62\2\u0337\u0335\3\2\2\2\u0337\u0338\3\2\2\2\u0338\u0340\3\2"+
		"\2\2\u0339\u033a\7\33\2\2\u033a\u033b\7 \2\2\u033b\u033c\5(\25\2\u033c"+
		"\u033d\7!\2\2\u033d\u033e\5b\62\2\u033e\u0340\3\2\2\2\u033f\u0330\3\2"+
		"\2\2\u033f\u0339\3\2\2\2\u0340o\3\2\2\2\u0341\u0342\7\37\2\2\u0342\u0343"+
		"\7 \2\2\u0343\u0344\5(\25\2\u0344\u0345\7!\2\2\u0345\u0346\5b\62\2\u0346"+
		"\u034e\3\2\2\2\u0347\u0348\7\22\2\2\u0348\u0349\7 \2\2\u0349\u034a\5r"+
		":\2\u034a\u034b\7!\2\2\u034b\u034c\5b\62\2\u034c\u034e\3\2\2\2\u034d\u0341"+
		"\3\2\2\2\u034d\u0347\3\2\2\2\u034eq\3\2\2\2\u034f\u0350\5t;\2\u0350\u0352"+
		"\7<\2\2\u0351\u0353\5v<\2\u0352\u0351\3\2\2\2\u0352\u0353\3\2\2\2\u0353"+
		"\u0354\3\2\2\2\u0354\u0356\7<\2\2\u0355\u0357\5v<\2\u0356\u0355\3\2\2"+
		"\2\u0356\u0357\3\2\2\2\u0357\u0364\3\2\2\2\u0358\u035a\5(\25\2\u0359\u0358"+
		"\3\2\2\2\u0359\u035a\3\2\2\2\u035a\u035b\3\2\2\2\u035b\u035d\7<\2\2\u035c"+
		"\u035e\5v<\2\u035d\u035c\3\2\2\2\u035d\u035e\3\2\2\2\u035e\u035f\3\2\2"+
		"\2\u035f\u0361\7<\2\2\u0360\u0362\5v<\2\u0361\u0360\3\2\2\2\u0361\u0362"+
		"\3\2\2\2\u0362\u0364\3\2\2\2\u0363\u034f\3\2\2\2\u0363\u0359\3\2\2\2\u0364"+
		"s\3\2\2\2\u0365\u0366\5.\30\2\u0366\u0367\5\64\33\2\u0367\u036a\3\2\2"+
		"\2\u0368\u036a\5.\30\2\u0369\u0365\3\2\2\2\u0369\u0368\3\2\2\2\u036au"+
		"\3\2\2\2\u036b\u036c\b<\1\2\u036c\u036d\5$\23\2\u036d\u0373\3\2\2\2\u036e"+
		"\u036f\f\3\2\2\u036f\u0370\7=\2\2\u0370\u0372\5$\23\2\u0371\u036e\3\2"+
		"\2\2\u0372\u0375\3\2\2\2\u0373\u0371\3\2\2\2\u0373\u0374\3\2\2\2\u0374"+
		"w\3\2\2\2\u0375\u0373\3\2\2\2\u0376\u0377\7\7\2\2\u0377\u0378\7N\2\2\u0378"+
		"\u0387\7<\2\2\u0379\u037a\7\f\2\2\u037a\u0387\7<\2\2\u037b\u037c\7\b\2"+
		"\2\u037c\u0387\7<\2\2\u037d\u037f\7\26\2\2\u037e\u0380\5(\25\2\u037f\u037e"+
		"\3\2\2\2\u037f\u0380\3\2\2\2\u0380\u0381\3\2\2\2\u0381\u0387\7<\2\2\u0382"+
		"\u0383\7\7\2\2\u0383\u0384\5\b\5\2\u0384\u0385\7<\2\2\u0385\u0387\3\2"+
		"\2\2\u0386\u0376\3\2\2\2\u0386\u0379\3\2\2\2\u0386\u037b\3\2\2\2\u0386"+
		"\u037d\3\2\2\2\u0386\u0382\3\2\2\2\u0387y\3\2\2\2\u0388\u038a\5|?\2\u0389"+
		"\u0388\3\2\2\2\u0389\u038a\3\2\2\2\u038a\u038b\3\2\2\2\u038b\u038c\7\2"+
		"\2\3\u038c{\3\2\2\2\u038d\u038e\b?\1\2\u038e\u038f\5~@\2\u038f\u0394\3"+
		"\2\2\2\u0390\u0391\f\3\2\2\u0391\u0393\5~@\2\u0392\u0390\3\2\2\2\u0393"+
		"\u0396\3\2\2\2\u0394\u0392\3\2\2\2\u0394\u0395\3\2\2\2\u0395}\3\2\2\2"+
		"\u0396\u0394\3\2\2\2\u0397\u039b\5\u0080A\2\u0398\u039b\5,\27\2\u0399"+
		"\u039b\7<\2\2\u039a\u0397\3\2\2\2\u039a\u0398\3\2\2\2\u039a\u0399\3\2"+
		"\2\2\u039b\177\3\2\2\2\u039c\u039e\5.\30\2\u039d\u039c\3\2\2\2\u039d\u039e"+
		"\3\2\2\2\u039e\u039f\3\2\2\2\u039f\u03a1\5@!\2\u03a0\u03a2\5\u0082B\2"+
		"\u03a1\u03a0\3\2\2\2\u03a1\u03a2\3\2\2\2\u03a2\u03a3\3\2\2\2\u03a3\u03a4"+
		"\5f\64\2\u03a4\u0081\3\2\2\2\u03a5\u03a6\bB\1\2\u03a6\u03a7\5,\27\2\u03a7"+
		"\u03ac\3\2\2\2\u03a8\u03a9\f\3\2\2\u03a9\u03ab\5,\27\2\u03aa\u03a8\3\2"+
		"\2\2\u03ab\u03ae\3\2\2\2\u03ac\u03aa\3\2\2\2\u03ac\u03ad\3\2\2\2\u03ad"+
		"\u0083\3\2\2\2\u03ae\u03ac\3\2\2\2j\u0089\u008f\u00b3\u00bd\u00ca\u00cc"+
		"\u00d7\u00f0\u0101\u010f\u0111\u011d\u011f\u012b\u012d\u013f\u0141\u014d"+
		"\u014f\u015a\u0165\u0170\u017b\u0186\u018f\u0197\u01a3\u01af\u01b4\u01b9"+
		"\u01be\u01c8\u01d0\u01d8\u01dc\u01de\u01e3\u01f2\u01f8\u01fd\u0200\u0207"+
		"\u0216\u0222\u0225\u0227\u022f\u0231\u0236\u023a\u023f\u0243\u0246\u024f"+
		"\u0257\u0261\u0269\u026b\u0275\u027a\u027e\u0281\u028a\u028d\u0293\u02a3"+
		"\u02a6\u02ab\u02ae\u02b5\u02c8\u02cb\u02cd\u02da\u02de\u02e5\u02ea\u02f7"+
		"\u0300\u0308\u0315\u0319\u0324\u0329\u032c\u0337\u033f\u034d\u0352\u0356"+
		"\u0359\u035d\u0361\u0363\u0369\u0373\u037f\u0386\u0389\u0394\u039a\u039d"+
		"\u03a1\u03ac";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}