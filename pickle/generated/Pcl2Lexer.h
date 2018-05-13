
#include "wci/intermediate/symtab.h"
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from grammars/Pcl2.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  Pcl2Lexer : public antlr4::Lexer {
public:
  enum {
    ConditionalConnectOperator = 1, ConditionalOperator = 2, Coalescing = 3, 
    Bit = 4, Power = 5, IgnoreWildCard = 6, Namespace = 7, ScopeResolution = 8, 
    String = 9, Break = 10, Case = 11, Char = 12, Const = 13, Continue = 14, 
    Bool = 15, Default = 16, Double = 17, Else = 18, Extern = 19, Float = 20, 
    For = 21, If = 22, Int = 23, Uint32 = 24, Int32 = 25, Long = 26, Return = 27, 
    Short = 28, Signed = 29, Sizeof = 30, Static = 31, Switch = 32, Typedef = 33, 
    Unsigned = 34, Void = 35, While = 36, LeftParen = 37, RightParen = 38, 
    LeftBracket = 39, RightBracket = 40, LeftBrace = 41, RightBrace = 42, 
    Less = 43, LessEqual = 44, Greater = 45, GreaterEqual = 46, LeftShift = 47, 
    RightShift = 48, Plus = 49, PlusPlus = 50, Minus = 51, MinusMinus = 52, 
    Star = 53, Div = 54, Mod = 55, And = 56, Or = 57, Negate = 58, Caret = 59, 
    Question = 60, Colon = 61, Semi = 62, Comma = 63, Assign = 64, StarAssign = 65, 
    DivAssign = 66, ModAssign = 67, PlusAssign = 68, MinusAssign = 69, LeftShiftAssign = 70, 
    RightShiftAssign = 71, AndAssign = 72, XorAssign = 73, OrAssign = 74, 
    NegateAssign = 75, Arrow = 76, Dot = 77, Ellipsis = 78, IntegerConstant = 79, 
    FloatConstant = 80, AndAnd = 81, OrOr = 82, Not = 83, Equal = 84, NotEqual = 85, 
    Identifier = 86, Whitespace = 87, Newline = 88, BlockComment = 89, LineComment = 90
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

