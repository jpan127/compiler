
// Generated from C:/Users/JP/Desktop/compiler/antlr/grammars/C.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  CLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    Constant = 15, DigitSequence = 16, StringLiteral = 17, Coalescing = 18, 
    Bit = 19, Power = 20, IgnoreWildCard = 21, Namespace = 22, ScopeResolution = 23, 
    String = 24, Break = 25, Case = 26, Char = 27, Const = 28, Continue = 29, 
    Bool = 30, Default = 31, Double = 32, Else = 33, Extern = 34, Float = 35, 
    For = 36, If = 37, Int = 38, Uint32 = 39, Int32 = 40, Long = 41, Return = 42, 
    Short = 43, Signed = 44, Sizeof = 45, Static = 46, Switch = 47, Typedef = 48, 
    Unsigned = 49, Void = 50, While = 51, LeftParen = 52, RightParen = 53, 
    LeftBracket = 54, RightBracket = 55, LeftBrace = 56, RightBrace = 57, 
    Less = 58, LessEqual = 59, Greater = 60, GreaterEqual = 61, LeftShift = 62, 
    RightShift = 63, Plus = 64, PlusPlus = 65, Minus = 66, MinusMinus = 67, 
    Star = 68, Div = 69, Mod = 70, And = 71, Or = 72, Negate = 73, Caret = 74, 
    Question = 75, Colon = 76, Semi = 77, Comma = 78, Assign = 79, StarAssign = 80, 
    DivAssign = 81, ModAssign = 82, PlusAssign = 83, MinusAssign = 84, LeftShiftAssign = 85, 
    RightShiftAssign = 86, AndAssign = 87, XorAssign = 88, OrAssign = 89, 
    NegateAssign = 90, Arrow = 91, Dot = 92, Ellipsis = 93, AndAnd = 94, 
    OrOr = 95, Not = 96, Equal = 97, NotEqual = 98, Identifier = 99, Whitespace = 100, 
    Newline = 101, BlockComment = 102, LineComment = 103
  };

  CLexer(antlr4::CharStream *input);
  ~CLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

