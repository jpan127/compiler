
// Generated from C:/Users/JP/Desktop/compiler/antlr/grammars/C.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  CLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, Constant = 11, DigitSequence = 12, StringLiteral = 13, 
    Coalescing = 14, Bit = 15, Power = 16, IgnoreWildCard = 17, Namespace = 18, 
    ScopeResolution = 19, String = 20, Break = 21, Case = 22, Char = 23, 
    Const = 24, Continue = 25, Bool = 26, Default = 27, Double = 28, Else = 29, 
    Extern = 30, Float = 31, For = 32, If = 33, Int = 34, Uint32 = 35, Int32 = 36, 
    Long = 37, Return = 38, Short = 39, Signed = 40, Sizeof = 41, Static = 42, 
    Switch = 43, Typedef = 44, Unsigned = 45, Void = 46, While = 47, LeftParen = 48, 
    RightParen = 49, LeftBracket = 50, RightBracket = 51, LeftBrace = 52, 
    RightBrace = 53, Less = 54, LessEqual = 55, Greater = 56, GreaterEqual = 57, 
    LeftShift = 58, RightShift = 59, Plus = 60, PlusPlus = 61, Minus = 62, 
    MinusMinus = 63, Star = 64, Div = 65, Mod = 66, And = 67, Or = 68, Caret = 69, 
    Question = 70, Colon = 71, Semi = 72, Comma = 73, Assign = 74, StarAssign = 75, 
    DivAssign = 76, ModAssign = 77, PlusAssign = 78, MinusAssign = 79, LeftShiftAssign = 80, 
    RightShiftAssign = 81, AndAssign = 82, XorAssign = 83, OrAssign = 84, 
    Arrow = 85, Dot = 86, Ellipsis = 87, Tilde = 88, AndAnd = 89, OrOr = 90, 
    Not = 91, Equal = 92, NotEqual = 93, Identifier = 94, Whitespace = 95, 
    Newline = 96, BlockComment = 97, LineComment = 98
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

