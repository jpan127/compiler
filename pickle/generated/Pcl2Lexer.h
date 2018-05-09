
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from grammars/Pcl2.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  Pcl2Lexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, Constant = 10, DigitSequence = 11, StringLiteral = 12, 
    Coalescing = 13, Bit = 14, Power = 15, IgnoreWildCard = 16, Namespace = 17, 
    ScopeResolution = 18, String = 19, Break = 20, Case = 21, Char = 22, 
    Const = 23, Continue = 24, Bool = 25, Default = 26, Double = 27, Else = 28, 
    Extern = 29, Float = 30, For = 31, If = 32, Int = 33, Uint32 = 34, Int32 = 35, 
    Long = 36, Return = 37, Short = 38, Signed = 39, Sizeof = 40, Static = 41, 
    Switch = 42, Typedef = 43, Unsigned = 44, Void = 45, While = 46, LeftParen = 47, 
    RightParen = 48, LeftBracket = 49, RightBracket = 50, LeftBrace = 51, 
    RightBrace = 52, Less = 53, LessEqual = 54, Greater = 55, GreaterEqual = 56, 
    LeftShift = 57, RightShift = 58, Plus = 59, PlusPlus = 60, Minus = 61, 
    MinusMinus = 62, Star = 63, Div = 64, Mod = 65, And = 66, Or = 67, Negate = 68, 
    Caret = 69, Question = 70, Colon = 71, Semi = 72, Comma = 73, Assign = 74, 
    StarAssign = 75, DivAssign = 76, ModAssign = 77, PlusAssign = 78, MinusAssign = 79, 
    LeftShiftAssign = 80, RightShiftAssign = 81, AndAssign = 82, XorAssign = 83, 
    OrAssign = 84, NegateAssign = 85, Arrow = 86, Dot = 87, Ellipsis = 88, 
    AndAnd = 89, OrOr = 90, Not = 91, Equal = 92, NotEqual = 93, Identifier = 94, 
    Whitespace = 95, Newline = 96, BlockComment = 97, LineComment = 98
  };

  Pcl2Lexer(antlr4::CharStream *input);
  ~Pcl2Lexer();

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

