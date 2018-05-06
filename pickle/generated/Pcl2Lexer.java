// Generated from C:/Users/JP/Desktop/compiler/pickle/grammars/Pcl2.g4 by ANTLR 4.7

#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class Pcl2Lexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, PROGRAM=7, VAR=8, BEGIN=9, 
		END=10, IDENTIFIER=11, INTEGER=12, FLOAT=13, MUL_OP=14, DIV_OP=15, ADD_OP=16, 
		SUB_OP=17, CARET=18, LESS_THAN=19, LESS_THAN_EQUAL=20, GREATER_THAN=21, 
		GREATER_THAN_EQUAL=22, NEWLINE=23, WS=24;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "PROGRAM", "VAR", "BEGIN", 
		"END", "IDENTIFIER", "INTEGER", "FLOAT", "MUL_OP", "DIV_OP", "ADD_OP", 
		"SUB_OP", "CARET", "LESS_THAN", "LESS_THAN_EQUAL", "GREATER_THAN", "GREATER_THAN_EQUAL", 
		"NEWLINE", "WS"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'.'", "';'", "','", "':='", "'('", "')'", "'PROGRAM'", "'VAR'", 
		"'BEGIN'", "'END'", null, null, null, "'*'", "'/'", "'+'", "'-'", "'^'", 
		"'<'", "'<='", "'>'", "'>='"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, null, "PROGRAM", "VAR", "BEGIN", "END", 
		"IDENTIFIER", "INTEGER", "FLOAT", "MUL_OP", "DIV_OP", "ADD_OP", "SUB_OP", 
		"CARET", "LESS_THAN", "LESS_THAN_EQUAL", "GREATER_THAN", "GREATER_THAN_EQUAL", 
		"NEWLINE", "WS"
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


	public Pcl2Lexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Pcl2.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\32\u008f\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\n\3\13\3\13"+
		"\3\13\3\13\3\f\3\f\7\fY\n\f\f\f\16\f\\\13\f\3\r\6\r_\n\r\r\r\16\r`\3\16"+
		"\6\16d\n\16\r\16\16\16e\3\16\3\16\6\16j\n\16\r\16\16\16k\3\17\3\17\3\20"+
		"\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\25\3\25\3\25\3\26\3\26"+
		"\3\27\3\27\3\27\3\30\5\30\u0083\n\30\3\30\3\30\3\30\3\30\3\31\6\31\u008a"+
		"\n\31\r\31\16\31\u008b\3\31\3\31\2\2\32\3\3\5\4\7\5\t\6\13\7\r\b\17\t"+
		"\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27"+
		"-\30/\31\61\32\3\2\6\4\2C\\c|\5\2\62;C\\c|\3\2\62;\4\2\13\13\"\"\2\u0094"+
		"\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2"+
		"\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2"+
		"\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2"+
		"\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2"+
		"\2\2\61\3\2\2\2\3\63\3\2\2\2\5\65\3\2\2\2\7\67\3\2\2\2\t9\3\2\2\2\13<"+
		"\3\2\2\2\r>\3\2\2\2\17@\3\2\2\2\21H\3\2\2\2\23L\3\2\2\2\25R\3\2\2\2\27"+
		"V\3\2\2\2\31^\3\2\2\2\33c\3\2\2\2\35m\3\2\2\2\37o\3\2\2\2!q\3\2\2\2#s"+
		"\3\2\2\2%u\3\2\2\2\'w\3\2\2\2)y\3\2\2\2+|\3\2\2\2-~\3\2\2\2/\u0082\3\2"+
		"\2\2\61\u0089\3\2\2\2\63\64\7\60\2\2\64\4\3\2\2\2\65\66\7=\2\2\66\6\3"+
		"\2\2\2\678\7.\2\28\b\3\2\2\29:\7<\2\2:;\7?\2\2;\n\3\2\2\2<=\7*\2\2=\f"+
		"\3\2\2\2>?\7+\2\2?\16\3\2\2\2@A\7R\2\2AB\7T\2\2BC\7Q\2\2CD\7I\2\2DE\7"+
		"T\2\2EF\7C\2\2FG\7O\2\2G\20\3\2\2\2HI\7X\2\2IJ\7C\2\2JK\7T\2\2K\22\3\2"+
		"\2\2LM\7D\2\2MN\7G\2\2NO\7I\2\2OP\7K\2\2PQ\7P\2\2Q\24\3\2\2\2RS\7G\2\2"+
		"ST\7P\2\2TU\7F\2\2U\26\3\2\2\2VZ\t\2\2\2WY\t\3\2\2XW\3\2\2\2Y\\\3\2\2"+
		"\2ZX\3\2\2\2Z[\3\2\2\2[\30\3\2\2\2\\Z\3\2\2\2]_\t\4\2\2^]\3\2\2\2_`\3"+
		"\2\2\2`^\3\2\2\2`a\3\2\2\2a\32\3\2\2\2bd\t\4\2\2cb\3\2\2\2de\3\2\2\2e"+
		"c\3\2\2\2ef\3\2\2\2fg\3\2\2\2gi\7\60\2\2hj\t\4\2\2ih\3\2\2\2jk\3\2\2\2"+
		"ki\3\2\2\2kl\3\2\2\2l\34\3\2\2\2mn\7,\2\2n\36\3\2\2\2op\7\61\2\2p \3\2"+
		"\2\2qr\7-\2\2r\"\3\2\2\2st\7/\2\2t$\3\2\2\2uv\7`\2\2v&\3\2\2\2wx\7>\2"+
		"\2x(\3\2\2\2yz\7>\2\2z{\7?\2\2{*\3\2\2\2|}\7@\2\2},\3\2\2\2~\177\7@\2"+
		"\2\177\u0080\7?\2\2\u0080.\3\2\2\2\u0081\u0083\7\17\2\2\u0082\u0081\3"+
		"\2\2\2\u0082\u0083\3\2\2\2\u0083\u0084\3\2\2\2\u0084\u0085\7\f\2\2\u0085"+
		"\u0086\3\2\2\2\u0086\u0087\b\30\2\2\u0087\60\3\2\2\2\u0088\u008a\t\5\2"+
		"\2\u0089\u0088\3\2\2\2\u008a\u008b\3\2\2\2\u008b\u0089\3\2\2\2\u008b\u008c"+
		"\3\2\2\2\u008c\u008d\3\2\2\2\u008d\u008e\b\31\2\2\u008e\62\3\2\2\2\t\2"+
		"Z`ek\u0082\u008b\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}