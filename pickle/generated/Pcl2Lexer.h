
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from grammars/Pcl2.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  Pcl2Lexer : public antlr4::Lexer {
public:
  enum {
    Identifier = 1, ConditionalConnectOperator = 2, ConditionalOperator = 3, 
    Coalescing = 4, Bit = 5, Power = 6, IgnoreWildCard = 7, Namespace = 8, 
    ScopeResolution = 9, String = 10, Break = 11, Case = 12, Char = 13, 
    Const = 14, Continue = 15, Bool = 16, Default = 17, Double = 18, Else = 19, 
    Extern = 20, Float = 21, For = 22, If = 23, Int = 24, Uint32 = 25, Int32 = 26, 
    Long = 27, Return = 28, Short = 29, Signed = 30, Sizeof = 31, Static = 32, 
    Switch = 33, Typedef = 34, Unsigned = 35, Void = 36, While = 37, LeftParen = 38, 
    RightParen = 39, LeftBracket = 40, RightBracket = 41, LeftBrace = 42, 
    RightBrace = 43, Less = 44, LessEqual = 45, Greater = 46, GreaterEqual = 47, 
    LeftShift = 48, RightShift = 49, Plus = 50, PlusPlus = 51, Minus = 52, 
    MinusMinus = 53, Star = 54, Div = 55, Mod = 56, And = 57, Or = 58, Negate = 59, 
    Caret = 60, Question = 61, Colon = 62, Semi = 63, Comma = 64, Assign = 65, 
    StarAssign = 66, DivAssign = 67, ModAssign = 68, PlusAssign = 69, MinusAssign = 70, 
    LeftShiftAssign = 71, RightShiftAssign = 72, AndAssign = 73, XorAssign = 74, 
    OrAssign = 75, NegateAssign = 76, Arrow = 77, Dot = 78, Ellipsis = 79, 
    IntegerConstant = 80, FloatConstant = 81, AndAnd = 82, OrOr = 83, Not = 84, 
    Equal = 85, NotEqual = 86, Whitespace = 87, Newline = 88, BlockComment = 89, 
    LineComment = 90
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

