
// Generated from C:/Users/JP/Desktop/compiler/antlr/grammars/C.g4 by ANTLR 4.7


#include "CListener.h"

#include "CParser.h"


using namespace antlrcpp;
using namespace antlr4;

CParser::CParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CParser::~CParser() {
  delete _interpreter;
}

std::string CParser::getGrammarFileName() const {
  return "C.g4";
}

const std::vector<std::string>& CParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- PrimaryExpressionContext ------------------------------------------------------------------

CParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::PrimaryExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::Constant() {
  return getToken(CParser::Constant, 0);
}

std::vector<tree::TerminalNode *> CParser::PrimaryExpressionContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}

CParser::ExpressionContext* CParser::PrimaryExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::PrimaryExpressionContext::getRuleIndex() const {
  return CParser::RulePrimaryExpression;
}

void CParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void CParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}

CParser::PrimaryExpressionContext* CParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 0, CParser::RulePrimaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(141);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(130);
        match(CParser::Identifier);
        break;
      }

      case CParser::Constant: {
        enterOuterAlt(_localctx, 2);
        setState(131);
        match(CParser::Constant);
        break;
      }

      case CParser::StringLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(133); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(132);
                  match(CParser::StringLiteral);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(135); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case CParser::LeftParen: {
        enterOuterAlt(_localctx, 4);
        setState(137);
        match(CParser::LeftParen);
        setState(138);
        expression(0);
        setState(139);
        match(CParser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExpressionContext ------------------------------------------------------------------

CParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PrimaryExpressionContext* CParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<CParser::PrimaryExpressionContext>(0);
}

CParser::TypeNameContext* CParser::PostfixExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

CParser::InitializerListContext* CParser::PostfixExpressionContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}

CParser::PostfixExpressionContext* CParser::PostfixExpressionContext::postfixExpression() {
  return getRuleContext<CParser::PostfixExpressionContext>(0);
}

CParser::ExpressionContext* CParser::PostfixExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::ArgumentExpressionListContext* CParser::PostfixExpressionContext::argumentExpressionList() {
  return getRuleContext<CParser::ArgumentExpressionListContext>(0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::PostfixExpressionContext::getRuleIndex() const {
  return CParser::RulePostfixExpression;
}

void CParser::PostfixExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpression(this);
}

void CParser::PostfixExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpression(this);
}


CParser::PostfixExpressionContext* CParser::postfixExpression() {
   return postfixExpression(0);
}

CParser::PostfixExpressionContext* CParser::postfixExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, parentState);
  CParser::PostfixExpressionContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, CParser::RulePostfixExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(177);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(144);
      primaryExpression();
      break;
    }

    case 2: {
      setState(145);
      match(CParser::LeftParen);
      setState(146);
      typeName();
      setState(147);
      match(CParser::RightParen);
      setState(148);
      match(CParser::LeftBrace);
      setState(149);
      initializerList(0);
      setState(150);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      setState(152);
      match(CParser::LeftParen);
      setState(153);
      typeName();
      setState(154);
      match(CParser::RightParen);
      setState(155);
      match(CParser::LeftBrace);
      setState(156);
      initializerList(0);
      setState(157);
      match(CParser::Comma);
      setState(158);
      match(CParser::RightBrace);
      break;
    }

    case 4: {
      setState(160);
      match(CParser::T__0);
      setState(161);
      match(CParser::LeftParen);
      setState(162);
      typeName();
      setState(163);
      match(CParser::RightParen);
      setState(164);
      match(CParser::LeftBrace);
      setState(165);
      initializerList(0);
      setState(166);
      match(CParser::RightBrace);
      break;
    }

    case 5: {
      setState(168);
      match(CParser::T__0);
      setState(169);
      match(CParser::LeftParen);
      setState(170);
      typeName();
      setState(171);
      match(CParser::RightParen);
      setState(172);
      match(CParser::LeftBrace);
      setState(173);
      initializerList(0);
      setState(174);
      match(CParser::Comma);
      setState(175);
      match(CParser::RightBrace);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(202);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(200);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(179);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(180);
          match(CParser::LeftBracket);
          setState(181);
          expression(0);
          setState(182);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(184);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(185);
          match(CParser::LeftParen);
          setState(187);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::Constant)
            | (1ULL << CParser::DigitSequence)
            | (1ULL << CParser::StringLiteral)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
            | (1ULL << (CParser::PlusPlus - 64))
            | (1ULL << (CParser::Minus - 64))
            | (1ULL << (CParser::MinusMinus - 64))
            | (1ULL << (CParser::Star - 64))
            | (1ULL << (CParser::And - 64))
            | (1ULL << (CParser::Negate - 64))
            | (1ULL << (CParser::Identifier - 64)))) != 0)) {
            setState(186);
            argumentExpressionList(0);
          }
          setState(189);
          match(CParser::RightParen);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(190);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(191);
          match(CParser::Dot);
          setState(192);
          match(CParser::Identifier);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(193);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(194);
          match(CParser::Arrow);
          setState(195);
          match(CParser::Identifier);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(196);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(197);
          match(CParser::PlusPlus);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(198);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(199);
          match(CParser::MinusMinus);
          break;
        }

        } 
      }
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgumentExpressionListContext ------------------------------------------------------------------

CParser::ArgumentExpressionListContext::ArgumentExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::ArgumentExpressionListContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ArgumentExpressionListContext* CParser::ArgumentExpressionListContext::argumentExpressionList() {
  return getRuleContext<CParser::ArgumentExpressionListContext>(0);
}


size_t CParser::ArgumentExpressionListContext::getRuleIndex() const {
  return CParser::RuleArgumentExpressionList;
}

void CParser::ArgumentExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentExpressionList(this);
}

void CParser::ArgumentExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentExpressionList(this);
}


CParser::ArgumentExpressionListContext* CParser::argumentExpressionList() {
   return argumentExpressionList(0);
}

CParser::ArgumentExpressionListContext* CParser::argumentExpressionList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ArgumentExpressionListContext *_localctx = _tracker.createInstance<ArgumentExpressionListContext>(_ctx, parentState);
  CParser::ArgumentExpressionListContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, CParser::RuleArgumentExpressionList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(206);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(213);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentExpressionListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgumentExpressionList);
        setState(208);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(209);
        match(CParser::Comma);
        setState(210);
        assignmentExpression(); 
      }
      setState(215);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

CParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PostfixExpressionContext* CParser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<CParser::PostfixExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::UnaryExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

CParser::UnaryOperatorContext* CParser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<CParser::UnaryOperatorContext>(0);
}

CParser::CastExpressionContext* CParser::UnaryExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

CParser::TypeNameContext* CParser::UnaryExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::UnaryExpressionContext::getRuleIndex() const {
  return CParser::RuleUnaryExpression;
}

void CParser::UnaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpression(this);
}

void CParser::UnaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpression(this);
}

CParser::UnaryExpressionContext* CParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, CParser::RuleUnaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(216);
      postfixExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(217);
      match(CParser::PlusPlus);
      setState(218);
      unaryExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(219);
      match(CParser::MinusMinus);
      setState(220);
      unaryExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(221);
      unaryOperator();
      setState(222);
      castExpression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(224);
      match(CParser::Sizeof);
      setState(225);
      unaryExpression();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(226);
      match(CParser::Sizeof);
      setState(227);
      match(CParser::LeftParen);
      setState(228);
      typeName();
      setState(229);
      match(CParser::RightParen);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(231);
      match(CParser::T__1);
      setState(232);
      match(CParser::LeftParen);
      setState(233);
      typeName();
      setState(234);
      match(CParser::RightParen);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(236);
      match(CParser::T__2);
      setState(237);
      match(CParser::Identifier);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOperatorContext ------------------------------------------------------------------

CParser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::UnaryOperatorContext::getRuleIndex() const {
  return CParser::RuleUnaryOperator;
}

void CParser::UnaryOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOperator(this);
}

void CParser::UnaryOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOperator(this);
}

CParser::UnaryOperatorContext* CParser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 8, CParser::RuleUnaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    _la = _input->LA(1);
    if (!(_la == CParser::T__3 || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
      | (1ULL << (CParser::Minus - 64))
      | (1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Negate - 64)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastExpressionContext ------------------------------------------------------------------

CParser::CastExpressionContext::CastExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeNameContext* CParser::CastExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

CParser::CastExpressionContext* CParser::CastExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::CastExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* CParser::CastExpressionContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
}


size_t CParser::CastExpressionContext::getRuleIndex() const {
  return CParser::RuleCastExpression;
}

void CParser::CastExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCastExpression(this);
}

void CParser::CastExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCastExpression(this);
}

CParser::CastExpressionContext* CParser::castExpression() {
  CastExpressionContext *_localctx = _tracker.createInstance<CastExpressionContext>(_ctx, getState());
  enterRule(_localctx, 10, CParser::RuleCastExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(255);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(242);
      match(CParser::LeftParen);
      setState(243);
      typeName();
      setState(244);
      match(CParser::RightParen);
      setState(245);
      castExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(247);
      match(CParser::T__0);
      setState(248);
      match(CParser::LeftParen);
      setState(249);
      typeName();
      setState(250);
      match(CParser::RightParen);
      setState(251);
      castExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(253);
      unaryExpression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(254);
      match(CParser::DigitSequence);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

CParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::CastExpressionContext* CParser::MultiplicativeExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

CParser::MultiplicativeExpressionContext* CParser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<CParser::MultiplicativeExpressionContext>(0);
}


size_t CParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return CParser::RuleMultiplicativeExpression;
}

void CParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void CParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}


CParser::MultiplicativeExpressionContext* CParser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

CParser::MultiplicativeExpressionContext* CParser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  CParser::MultiplicativeExpressionContext *previousContext = _localctx;
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, CParser::RuleMultiplicativeExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(258);
    castExpression();
    _ctx->stop = _input->LT(-1);
    setState(271);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(269);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(260);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(261);
          match(CParser::Star);
          setState(262);
          castExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(263);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(264);
          match(CParser::Div);
          setState(265);
          castExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(266);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(267);
          match(CParser::Mod);
          setState(268);
          castExpression();
          break;
        }

        } 
      }
      setState(273);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

CParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::MultiplicativeExpressionContext* CParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<CParser::MultiplicativeExpressionContext>(0);
}

CParser::AdditiveExpressionContext* CParser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<CParser::AdditiveExpressionContext>(0);
}


size_t CParser::AdditiveExpressionContext::getRuleIndex() const {
  return CParser::RuleAdditiveExpression;
}

void CParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void CParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}


CParser::AdditiveExpressionContext* CParser::additiveExpression() {
   return additiveExpression(0);
}

CParser::AdditiveExpressionContext* CParser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  CParser::AdditiveExpressionContext *previousContext = _localctx;
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, CParser::RuleAdditiveExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(275);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(285);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(283);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(277);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(278);
          match(CParser::Plus);
          setState(279);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(280);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(281);
          match(CParser::Minus);
          setState(282);
          multiplicativeExpression(0);
          break;
        }

        } 
      }
      setState(287);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ShiftExpressionContext ------------------------------------------------------------------

CParser::ShiftExpressionContext::ShiftExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AdditiveExpressionContext* CParser::ShiftExpressionContext::additiveExpression() {
  return getRuleContext<CParser::AdditiveExpressionContext>(0);
}

CParser::ShiftExpressionContext* CParser::ShiftExpressionContext::shiftExpression() {
  return getRuleContext<CParser::ShiftExpressionContext>(0);
}


size_t CParser::ShiftExpressionContext::getRuleIndex() const {
  return CParser::RuleShiftExpression;
}

void CParser::ShiftExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShiftExpression(this);
}

void CParser::ShiftExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShiftExpression(this);
}


CParser::ShiftExpressionContext* CParser::shiftExpression() {
   return shiftExpression(0);
}

CParser::ShiftExpressionContext* CParser::shiftExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ShiftExpressionContext *_localctx = _tracker.createInstance<ShiftExpressionContext>(_ctx, parentState);
  CParser::ShiftExpressionContext *previousContext = _localctx;
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, CParser::RuleShiftExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(289);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(299);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(297);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(291);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(292);
          match(CParser::LeftShift);
          setState(293);
          additiveExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(294);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(295);
          match(CParser::RightShift);
          setState(296);
          additiveExpression(0);
          break;
        }

        } 
      }
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationalExpressionContext ------------------------------------------------------------------

CParser::RelationalExpressionContext::RelationalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ShiftExpressionContext* CParser::RelationalExpressionContext::shiftExpression() {
  return getRuleContext<CParser::ShiftExpressionContext>(0);
}

CParser::RelationalExpressionContext* CParser::RelationalExpressionContext::relationalExpression() {
  return getRuleContext<CParser::RelationalExpressionContext>(0);
}


size_t CParser::RelationalExpressionContext::getRuleIndex() const {
  return CParser::RuleRelationalExpression;
}

void CParser::RelationalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}

void CParser::RelationalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}


CParser::RelationalExpressionContext* CParser::relationalExpression() {
   return relationalExpression(0);
}

CParser::RelationalExpressionContext* CParser::relationalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, parentState);
  CParser::RelationalExpressionContext *previousContext = _localctx;
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, CParser::RuleRelationalExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(303);
    shiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(319);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(317);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(305);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(306);
          match(CParser::Less);
          setState(307);
          shiftExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(308);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(309);
          match(CParser::Greater);
          setState(310);
          shiftExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(311);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(312);
          match(CParser::LessEqual);
          setState(313);
          shiftExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(314);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(315);
          match(CParser::GreaterEqual);
          setState(316);
          shiftExpression(0);
          break;
        }

        } 
      }
      setState(321);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

CParser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::RelationalExpressionContext* CParser::EqualityExpressionContext::relationalExpression() {
  return getRuleContext<CParser::RelationalExpressionContext>(0);
}

CParser::EqualityExpressionContext* CParser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<CParser::EqualityExpressionContext>(0);
}


size_t CParser::EqualityExpressionContext::getRuleIndex() const {
  return CParser::RuleEqualityExpression;
}

void CParser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}

void CParser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}


CParser::EqualityExpressionContext* CParser::equalityExpression() {
   return equalityExpression(0);
}

CParser::EqualityExpressionContext* CParser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  CParser::EqualityExpressionContext *previousContext = _localctx;
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CParser::RuleEqualityExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(323);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(339);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(337);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(325);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(326);
          match(CParser::T__4);
          setState(327);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(328);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(329);
          match(CParser::T__5);
          setState(330);
          relationalExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(331);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(332);
          match(CParser::T__6);
          setState(333);
          relationalExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(334);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(335);
          match(CParser::T__7);
          setState(336);
          relationalExpression(0);
          break;
        }

        } 
      }
      setState(341);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AndExpressionContext ------------------------------------------------------------------

CParser::AndExpressionContext::AndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::EqualityExpressionContext* CParser::AndExpressionContext::equalityExpression() {
  return getRuleContext<CParser::EqualityExpressionContext>(0);
}

CParser::AndExpressionContext* CParser::AndExpressionContext::andExpression() {
  return getRuleContext<CParser::AndExpressionContext>(0);
}


size_t CParser::AndExpressionContext::getRuleIndex() const {
  return CParser::RuleAndExpression;
}

void CParser::AndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpression(this);
}

void CParser::AndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpression(this);
}


CParser::AndExpressionContext* CParser::andExpression() {
   return andExpression(0);
}

CParser::AndExpressionContext* CParser::andExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::AndExpressionContext *_localctx = _tracker.createInstance<AndExpressionContext>(_ctx, parentState);
  CParser::AndExpressionContext *previousContext = _localctx;
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, CParser::RuleAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(343);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(350);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndExpression);
        setState(345);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(346);
        match(CParser::And);
        setState(347);
        equalityExpression(0); 
      }
      setState(352);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExclusiveOrExpressionContext ------------------------------------------------------------------

CParser::ExclusiveOrExpressionContext::ExclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AndExpressionContext* CParser::ExclusiveOrExpressionContext::andExpression() {
  return getRuleContext<CParser::AndExpressionContext>(0);
}

CParser::ExclusiveOrExpressionContext* CParser::ExclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<CParser::ExclusiveOrExpressionContext>(0);
}


size_t CParser::ExclusiveOrExpressionContext::getRuleIndex() const {
  return CParser::RuleExclusiveOrExpression;
}

void CParser::ExclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExclusiveOrExpression(this);
}

void CParser::ExclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExclusiveOrExpression(this);
}


CParser::ExclusiveOrExpressionContext* CParser::exclusiveOrExpression() {
   return exclusiveOrExpression(0);
}

CParser::ExclusiveOrExpressionContext* CParser::exclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ExclusiveOrExpressionContext *_localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(_ctx, parentState);
  CParser::ExclusiveOrExpressionContext *previousContext = _localctx;
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, CParser::RuleExclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(354);
    andExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(361);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExclusiveOrExpression);
        setState(356);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(357);
        match(CParser::Caret);
        setState(358);
        andExpression(0); 
      }
      setState(363);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InclusiveOrExpressionContext ------------------------------------------------------------------

CParser::InclusiveOrExpressionContext::InclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExclusiveOrExpressionContext* CParser::InclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<CParser::ExclusiveOrExpressionContext>(0);
}

CParser::InclusiveOrExpressionContext* CParser::InclusiveOrExpressionContext::inclusiveOrExpression() {
  return getRuleContext<CParser::InclusiveOrExpressionContext>(0);
}


size_t CParser::InclusiveOrExpressionContext::getRuleIndex() const {
  return CParser::RuleInclusiveOrExpression;
}

void CParser::InclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInclusiveOrExpression(this);
}

void CParser::InclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInclusiveOrExpression(this);
}


CParser::InclusiveOrExpressionContext* CParser::inclusiveOrExpression() {
   return inclusiveOrExpression(0);
}

CParser::InclusiveOrExpressionContext* CParser::inclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::InclusiveOrExpressionContext *_localctx = _tracker.createInstance<InclusiveOrExpressionContext>(_ctx, parentState);
  CParser::InclusiveOrExpressionContext *previousContext = _localctx;
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, CParser::RuleInclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(365);
    exclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(372);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInclusiveOrExpression);
        setState(367);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(368);
        match(CParser::Or);
        setState(369);
        exclusiveOrExpression(0); 
      }
      setState(374);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

CParser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::InclusiveOrExpressionContext* CParser::LogicalAndExpressionContext::inclusiveOrExpression() {
  return getRuleContext<CParser::InclusiveOrExpressionContext>(0);
}

CParser::LogicalAndExpressionContext* CParser::LogicalAndExpressionContext::logicalAndExpression() {
  return getRuleContext<CParser::LogicalAndExpressionContext>(0);
}


size_t CParser::LogicalAndExpressionContext::getRuleIndex() const {
  return CParser::RuleLogicalAndExpression;
}

void CParser::LogicalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}

void CParser::LogicalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}


CParser::LogicalAndExpressionContext* CParser::logicalAndExpression() {
   return logicalAndExpression(0);
}

CParser::LogicalAndExpressionContext* CParser::logicalAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, parentState);
  CParser::LogicalAndExpressionContext *previousContext = _localctx;
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, CParser::RuleLogicalAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(376);
    inclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(386);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(384);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
          setState(378);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(379);
          match(CParser::T__2);
          setState(380);
          inclusiveOrExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
          setState(381);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(382);
          match(CParser::T__8);
          setState(383);
          inclusiveOrExpression(0);
          break;
        }

        } 
      }
      setState(388);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

CParser::LogicalOrExpressionContext::LogicalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LogicalAndExpressionContext* CParser::LogicalOrExpressionContext::logicalAndExpression() {
  return getRuleContext<CParser::LogicalAndExpressionContext>(0);
}

CParser::LogicalOrExpressionContext* CParser::LogicalOrExpressionContext::logicalOrExpression() {
  return getRuleContext<CParser::LogicalOrExpressionContext>(0);
}


size_t CParser::LogicalOrExpressionContext::getRuleIndex() const {
  return CParser::RuleLogicalOrExpression;
}

void CParser::LogicalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpression(this);
}

void CParser::LogicalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpression(this);
}


CParser::LogicalOrExpressionContext* CParser::logicalOrExpression() {
   return logicalOrExpression(0);
}

CParser::LogicalOrExpressionContext* CParser::logicalOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::LogicalOrExpressionContext *_localctx = _tracker.createInstance<LogicalOrExpressionContext>(_ctx, parentState);
  CParser::LogicalOrExpressionContext *previousContext = _localctx;
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, CParser::RuleLogicalOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(390);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(400);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(398);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
          setState(392);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(393);
          match(CParser::T__9);
          setState(394);
          logicalAndExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
          setState(395);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(396);
          match(CParser::T__10);
          setState(397);
          logicalAndExpression(0);
          break;
        }

        } 
      }
      setState(402);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConditionalExpressionContext ------------------------------------------------------------------

CParser::ConditionalExpressionContext::ConditionalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LogicalOrExpressionContext* CParser::ConditionalExpressionContext::logicalOrExpression() {
  return getRuleContext<CParser::LogicalOrExpressionContext>(0);
}

CParser::ExpressionContext* CParser::ConditionalExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::ConditionalExpressionContext* CParser::ConditionalExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}


size_t CParser::ConditionalExpressionContext::getRuleIndex() const {
  return CParser::RuleConditionalExpression;
}

void CParser::ConditionalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalExpression(this);
}

void CParser::ConditionalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalExpression(this);
}

CParser::ConditionalExpressionContext* CParser::conditionalExpression() {
  ConditionalExpressionContext *_localctx = _tracker.createInstance<ConditionalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 32, CParser::RuleConditionalExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    logicalOrExpression(0);
    setState(409);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(404);
      match(CParser::Question);
      setState(405);
      expression(0);
      setState(406);
      match(CParser::Colon);
      setState(407);
      conditionalExpression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

CParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConditionalExpressionContext* CParser::AssignmentExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::AssignmentExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

CParser::AssignmentOperatorContext* CParser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<CParser::AssignmentOperatorContext>(0);
}

CParser::AssignmentExpressionContext* CParser::AssignmentExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* CParser::AssignmentExpressionContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
}


size_t CParser::AssignmentExpressionContext::getRuleIndex() const {
  return CParser::RuleAssignmentExpression;
}

void CParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void CParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}

CParser::AssignmentExpressionContext* CParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 34, CParser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(417);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(411);
      conditionalExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(412);
      unaryExpression();
      setState(413);
      assignmentOperator();
      setState(414);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(416);
      match(CParser::DigitSequence);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

CParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::AssignmentOperatorContext::NegateAssign() {
  return getToken(CParser::NegateAssign, 0);
}


size_t CParser::AssignmentOperatorContext::getRuleIndex() const {
  return CParser::RuleAssignmentOperator;
}

void CParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void CParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}

CParser::AssignmentOperatorContext* CParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 36, CParser::RuleAssignmentOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(419);
    _la = _input->LA(1);
    if (!(((((_la - 79) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 79)) & ((1ULL << (CParser::Assign - 79))
      | (1ULL << (CParser::StarAssign - 79))
      | (1ULL << (CParser::DivAssign - 79))
      | (1ULL << (CParser::ModAssign - 79))
      | (1ULL << (CParser::PlusAssign - 79))
      | (1ULL << (CParser::MinusAssign - 79))
      | (1ULL << (CParser::LeftShiftAssign - 79))
      | (1ULL << (CParser::RightShiftAssign - 79))
      | (1ULL << (CParser::AndAssign - 79))
      | (1ULL << (CParser::XorAssign - 79))
      | (1ULL << (CParser::OrAssign - 79))
      | (1ULL << (CParser::NegateAssign - 79)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::ExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ExpressionContext* CParser::ExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ExpressionContext::getRuleIndex() const {
  return CParser::RuleExpression;
}

void CParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void CParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


CParser::ExpressionContext* CParser::expression() {
   return expression(0);
}

CParser::ExpressionContext* CParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  CParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, CParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(422);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(429);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(424);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(425);
        match(CParser::Comma);
        setState(426);
        assignmentExpression(); 
      }
      setState(431);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstantExpressionContext ------------------------------------------------------------------

CParser::ConstantExpressionContext::ConstantExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConditionalExpressionContext* CParser::ConstantExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}


size_t CParser::ConstantExpressionContext::getRuleIndex() const {
  return CParser::RuleConstantExpression;
}

void CParser::ConstantExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantExpression(this);
}

void CParser::ConstantExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantExpression(this);
}

CParser::ConstantExpressionContext* CParser::constantExpression() {
  ConstantExpressionContext *_localctx = _tracker.createInstance<ConstantExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, CParser::RuleConstantExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    conditionalExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

CParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::DeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::InitDeclaratorListContext* CParser::DeclarationContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}


size_t CParser::DeclarationContext::getRuleIndex() const {
  return CParser::RuleDeclaration;
}

void CParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void CParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}

CParser::DeclarationContext* CParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 42, CParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(441);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(434);
      declarationSpecifiers();
      setState(435);
      initDeclaratorList(0);
      setState(436);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(438);
      declarationSpecifiers();
      setState(439);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiersContext ------------------------------------------------------------------

CParser::DeclarationSpecifiersContext::DeclarationSpecifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DeclarationSpecifierContext *> CParser::DeclarationSpecifiersContext::declarationSpecifier() {
  return getRuleContexts<CParser::DeclarationSpecifierContext>();
}

CParser::DeclarationSpecifierContext* CParser::DeclarationSpecifiersContext::declarationSpecifier(size_t i) {
  return getRuleContext<CParser::DeclarationSpecifierContext>(i);
}


size_t CParser::DeclarationSpecifiersContext::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifiers;
}

void CParser::DeclarationSpecifiersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers(this);
}

void CParser::DeclarationSpecifiersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers(this);
}

CParser::DeclarationSpecifiersContext* CParser::declarationSpecifiers() {
  DeclarationSpecifiersContext *_localctx = _tracker.createInstance<DeclarationSpecifiersContext>(_ctx, getState());
  enterRule(_localctx, 44, CParser::RuleDeclarationSpecifiers);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(443);
      declarationSpecifier();
      setState(446); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Uint32)
      | (1ULL << CParser::Int32)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiers2Context ------------------------------------------------------------------

CParser::DeclarationSpecifiers2Context::DeclarationSpecifiers2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DeclarationSpecifierContext *> CParser::DeclarationSpecifiers2Context::declarationSpecifier() {
  return getRuleContexts<CParser::DeclarationSpecifierContext>();
}

CParser::DeclarationSpecifierContext* CParser::DeclarationSpecifiers2Context::declarationSpecifier(size_t i) {
  return getRuleContext<CParser::DeclarationSpecifierContext>(i);
}


size_t CParser::DeclarationSpecifiers2Context::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifiers2;
}

void CParser::DeclarationSpecifiers2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers2(this);
}

void CParser::DeclarationSpecifiers2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers2(this);
}

CParser::DeclarationSpecifiers2Context* CParser::declarationSpecifiers2() {
  DeclarationSpecifiers2Context *_localctx = _tracker.createInstance<DeclarationSpecifiers2Context>(_ctx, getState());
  enterRule(_localctx, 46, CParser::RuleDeclarationSpecifiers2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(449); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(448);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(451); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifierContext ------------------------------------------------------------------

CParser::DeclarationSpecifierContext::DeclarationSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StorageClassSpecifierContext* CParser::DeclarationSpecifierContext::storageClassSpecifier() {
  return getRuleContext<CParser::StorageClassSpecifierContext>(0);
}

CParser::TypeSpecifierContext* CParser::DeclarationSpecifierContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}

CParser::TypeQualifierContext* CParser::DeclarationSpecifierContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}


size_t CParser::DeclarationSpecifierContext::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifier;
}

void CParser::DeclarationSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifier(this);
}

void CParser::DeclarationSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifier(this);
}

CParser::DeclarationSpecifierContext* CParser::declarationSpecifier() {
  DeclarationSpecifierContext *_localctx = _tracker.createInstance<DeclarationSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 48, CParser::RuleDeclarationSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(456);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__11:
      case CParser::T__12:
      case CParser::Extern:
      case CParser::Static:
      case CParser::Typedef: {
        enterOuterAlt(_localctx, 1);
        setState(453);
        storageClassSpecifier();
        break;
      }

      case CParser::Char:
      case CParser::Bool:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Uint32:
      case CParser::Int32:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Unsigned:
      case CParser::Void: {
        enterOuterAlt(_localctx, 2);
        setState(454);
        typeSpecifier();
        break;
      }

      case CParser::Const: {
        enterOuterAlt(_localctx, 3);
        setState(455);
        typeQualifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitDeclaratorListContext ------------------------------------------------------------------

CParser::InitDeclaratorListContext::InitDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::InitDeclaratorContext* CParser::InitDeclaratorListContext::initDeclarator() {
  return getRuleContext<CParser::InitDeclaratorContext>(0);
}

CParser::InitDeclaratorListContext* CParser::InitDeclaratorListContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}


size_t CParser::InitDeclaratorListContext::getRuleIndex() const {
  return CParser::RuleInitDeclaratorList;
}

void CParser::InitDeclaratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclaratorList(this);
}

void CParser::InitDeclaratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclaratorList(this);
}


CParser::InitDeclaratorListContext* CParser::initDeclaratorList() {
   return initDeclaratorList(0);
}

CParser::InitDeclaratorListContext* CParser::initDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::InitDeclaratorListContext *_localctx = _tracker.createInstance<InitDeclaratorListContext>(_ctx, parentState);
  CParser::InitDeclaratorListContext *previousContext = _localctx;
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, CParser::RuleInitDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(459);
    initDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(466);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitDeclaratorList);
        setState(461);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(462);
        match(CParser::Comma);
        setState(463);
        initDeclarator(); 
      }
      setState(468);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InitDeclaratorContext ------------------------------------------------------------------

CParser::InitDeclaratorContext::InitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::InitDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::InitializerContext* CParser::InitDeclaratorContext::initializer() {
  return getRuleContext<CParser::InitializerContext>(0);
}


size_t CParser::InitDeclaratorContext::getRuleIndex() const {
  return CParser::RuleInitDeclarator;
}

void CParser::InitDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclarator(this);
}

void CParser::InitDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclarator(this);
}

CParser::InitDeclaratorContext* CParser::initDeclarator() {
  InitDeclaratorContext *_localctx = _tracker.createInstance<InitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 52, CParser::RuleInitDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(474);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(469);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(470);
      declarator();
      setState(471);
      match(CParser::Assign);
      setState(472);
      initializer();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StorageClassSpecifierContext ------------------------------------------------------------------

CParser::StorageClassSpecifierContext::StorageClassSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::StorageClassSpecifierContext::getRuleIndex() const {
  return CParser::RuleStorageClassSpecifier;
}

void CParser::StorageClassSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStorageClassSpecifier(this);
}

void CParser::StorageClassSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStorageClassSpecifier(this);
}

CParser::StorageClassSpecifierContext* CParser::storageClassSpecifier() {
  StorageClassSpecifierContext *_localctx = _tracker.createInstance<StorageClassSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 54, CParser::RuleStorageClassSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(476);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Typedef))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext ------------------------------------------------------------------

CParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::TypeSpecifierContext::getRuleIndex() const {
  return CParser::RuleTypeSpecifier;
}

void CParser::TypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void CParser::TypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}

CParser::TypeSpecifierContext* CParser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 56, CParser::RuleTypeSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(478);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Char)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Uint32)
      | (1ULL << CParser::Int32)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SpecifierQualifierListContext ------------------------------------------------------------------

CParser::SpecifierQualifierListContext::SpecifierQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeSpecifierContext* CParser::SpecifierQualifierListContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}

CParser::SpecifierQualifierListContext* CParser::SpecifierQualifierListContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

CParser::TypeQualifierContext* CParser::SpecifierQualifierListContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}


size_t CParser::SpecifierQualifierListContext::getRuleIndex() const {
  return CParser::RuleSpecifierQualifierList;
}

void CParser::SpecifierQualifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecifierQualifierList(this);
}

void CParser::SpecifierQualifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecifierQualifierList(this);
}

CParser::SpecifierQualifierListContext* CParser::specifierQualifierList() {
  SpecifierQualifierListContext *_localctx = _tracker.createInstance<SpecifierQualifierListContext>(_ctx, getState());
  enterRule(_localctx, 58, CParser::RuleSpecifierQualifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(488);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Char:
      case CParser::Bool:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Uint32:
      case CParser::Int32:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Unsigned:
      case CParser::Void: {
        enterOuterAlt(_localctx, 1);
        setState(480);
        typeSpecifier();
        setState(482);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::Char)
          | (1ULL << CParser::Const)
          | (1ULL << CParser::Bool)
          | (1ULL << CParser::Double)
          | (1ULL << CParser::Float)
          | (1ULL << CParser::Int)
          | (1ULL << CParser::Uint32)
          | (1ULL << CParser::Int32)
          | (1ULL << CParser::Long)
          | (1ULL << CParser::Short)
          | (1ULL << CParser::Signed)
          | (1ULL << CParser::Unsigned)
          | (1ULL << CParser::Void))) != 0)) {
          setState(481);
          specifierQualifierList();
        }
        break;
      }

      case CParser::Const: {
        enterOuterAlt(_localctx, 2);
        setState(484);
        typeQualifier();
        setState(486);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::Char)
          | (1ULL << CParser::Const)
          | (1ULL << CParser::Bool)
          | (1ULL << CParser::Double)
          | (1ULL << CParser::Float)
          | (1ULL << CParser::Int)
          | (1ULL << CParser::Uint32)
          | (1ULL << CParser::Int32)
          | (1ULL << CParser::Long)
          | (1ULL << CParser::Short)
          | (1ULL << CParser::Signed)
          | (1ULL << CParser::Unsigned)
          | (1ULL << CParser::Void))) != 0)) {
          setState(485);
          specifierQualifierList();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeQualifierContext ------------------------------------------------------------------

CParser::TypeQualifierContext::TypeQualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::TypeQualifierContext::getRuleIndex() const {
  return CParser::RuleTypeQualifier;
}

void CParser::TypeQualifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeQualifier(this);
}

void CParser::TypeQualifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeQualifier(this);
}

CParser::TypeQualifierContext* CParser::typeQualifier() {
  TypeQualifierContext *_localctx = _tracker.createInstance<TypeQualifierContext>(_ctx, getState());
  enterRule(_localctx, 60, CParser::RuleTypeQualifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(490);
    match(CParser::Const);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclaratorContext ------------------------------------------------------------------

CParser::DeclaratorContext::DeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DirectDeclaratorContext* CParser::DeclaratorContext::directDeclarator() {
  return getRuleContext<CParser::DirectDeclaratorContext>(0);
}

CParser::PointerContext* CParser::DeclaratorContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}


size_t CParser::DeclaratorContext::getRuleIndex() const {
  return CParser::RuleDeclarator;
}

void CParser::DeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarator(this);
}

void CParser::DeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarator(this);
}

CParser::DeclaratorContext* CParser::declarator() {
  DeclaratorContext *_localctx = _tracker.createInstance<DeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 62, CParser::RuleDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Star

    || _la == CParser::Caret) {
      setState(492);
      pointer();
    }
    setState(495);
    directDeclarator(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectDeclaratorContext ------------------------------------------------------------------

CParser::DirectDeclaratorContext::DirectDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::DirectDeclaratorContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::DeclaratorContext* CParser::DirectDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
}

CParser::PointerContext* CParser::DirectDeclaratorContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}

CParser::DirectDeclaratorContext* CParser::DirectDeclaratorContext::directDeclarator() {
  return getRuleContext<CParser::DirectDeclaratorContext>(0);
}

CParser::TypeSpecifierContext* CParser::DirectDeclaratorContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}

CParser::TypeQualifierListContext* CParser::DirectDeclaratorContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}

CParser::AssignmentExpressionContext* CParser::DirectDeclaratorContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ParameterTypeListContext* CParser::DirectDeclaratorContext::parameterTypeList() {
  return getRuleContext<CParser::ParameterTypeListContext>(0);
}

CParser::IdentifierListContext* CParser::DirectDeclaratorContext::identifierList() {
  return getRuleContext<CParser::IdentifierListContext>(0);
}


size_t CParser::DirectDeclaratorContext::getRuleIndex() const {
  return CParser::RuleDirectDeclarator;
}

void CParser::DirectDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectDeclarator(this);
}

void CParser::DirectDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectDeclarator(this);
}


CParser::DirectDeclaratorContext* CParser::directDeclarator() {
   return directDeclarator(0);
}

CParser::DirectDeclaratorContext* CParser::directDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DirectDeclaratorContext *_localctx = _tracker.createInstance<DirectDeclaratorContext>(_ctx, parentState);
  CParser::DirectDeclaratorContext *previousContext = _localctx;
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, CParser::RuleDirectDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(514);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(498);
      match(CParser::Identifier);
      break;
    }

    case 2: {
      setState(499);
      match(CParser::LeftParen);
      setState(500);
      declarator();
      setState(501);
      match(CParser::RightParen);
      break;
    }

    case 3: {
      setState(503);
      match(CParser::Identifier);
      setState(504);
      match(CParser::Colon);
      setState(505);
      match(CParser::DigitSequence);
      break;
    }

    case 4: {
      setState(506);
      match(CParser::LeftParen);
      setState(508);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::Char)
        | (1ULL << CParser::Bool)
        | (1ULL << CParser::Double)
        | (1ULL << CParser::Float)
        | (1ULL << CParser::Int)
        | (1ULL << CParser::Uint32)
        | (1ULL << CParser::Int32)
        | (1ULL << CParser::Long)
        | (1ULL << CParser::Short)
        | (1ULL << CParser::Signed)
        | (1ULL << CParser::Unsigned)
        | (1ULL << CParser::Void))) != 0)) {
        setState(507);
        typeSpecifier();
      }
      setState(510);
      pointer();
      setState(511);
      directDeclarator(0);
      setState(512);
      match(CParser::RightParen);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(561);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(559);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(516);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(517);
          match(CParser::LeftBracket);
          setState(519);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(518);
            typeQualifierList(0);
          }
          setState(522);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::Constant)
            | (1ULL << CParser::DigitSequence)
            | (1ULL << CParser::StringLiteral)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
            | (1ULL << (CParser::PlusPlus - 64))
            | (1ULL << (CParser::Minus - 64))
            | (1ULL << (CParser::MinusMinus - 64))
            | (1ULL << (CParser::Star - 64))
            | (1ULL << (CParser::And - 64))
            | (1ULL << (CParser::Negate - 64))
            | (1ULL << (CParser::Identifier - 64)))) != 0)) {
            setState(521);
            assignmentExpression();
          }
          setState(524);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(525);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(526);
          match(CParser::LeftBracket);
          setState(527);
          match(CParser::Static);
          setState(529);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(528);
            typeQualifierList(0);
          }
          setState(531);
          assignmentExpression();
          setState(532);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(534);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(535);
          match(CParser::LeftBracket);
          setState(536);
          typeQualifierList(0);
          setState(537);
          match(CParser::Static);
          setState(538);
          assignmentExpression();
          setState(539);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(541);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(542);
          match(CParser::LeftBracket);
          setState(544);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(543);
            typeQualifierList(0);
          }
          setState(546);
          match(CParser::Star);
          setState(547);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(548);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(549);
          match(CParser::LeftParen);
          setState(550);
          parameterTypeList();
          setState(551);
          match(CParser::RightParen);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(553);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(554);
          match(CParser::LeftParen);
          setState(556);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Identifier) {
            setState(555);
            identifierList(0);
          }
          setState(558);
          match(CParser::RightParen);
          break;
        }

        } 
      }
      setState(563);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NestedParenthesesBlockContext ------------------------------------------------------------------

CParser::NestedParenthesesBlockContext::NestedParenthesesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::NestedParenthesesBlockContext *> CParser::NestedParenthesesBlockContext::nestedParenthesesBlock() {
  return getRuleContexts<CParser::NestedParenthesesBlockContext>();
}

CParser::NestedParenthesesBlockContext* CParser::NestedParenthesesBlockContext::nestedParenthesesBlock(size_t i) {
  return getRuleContext<CParser::NestedParenthesesBlockContext>(i);
}


size_t CParser::NestedParenthesesBlockContext::getRuleIndex() const {
  return CParser::RuleNestedParenthesesBlock;
}

void CParser::NestedParenthesesBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedParenthesesBlock(this);
}

void CParser::NestedParenthesesBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedParenthesesBlock(this);
}

CParser::NestedParenthesesBlockContext* CParser::nestedParenthesesBlock() {
  NestedParenthesesBlockContext *_localctx = _tracker.createInstance<NestedParenthesesBlockContext>(_ctx, getState());
  enterRule(_localctx, 66, CParser::RuleNestedParenthesesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(571);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__4)
      | (1ULL << CParser::T__5)
      | (1ULL << CParser::T__6)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
      | (1ULL << CParser::T__10)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__13)
      | (1ULL << CParser::Constant)
      | (1ULL << CParser::DigitSequence)
      | (1ULL << CParser::StringLiteral)
      | (1ULL << CParser::Coalescing)
      | (1ULL << CParser::Bit)
      | (1ULL << CParser::Power)
      | (1ULL << CParser::IgnoreWildCard)
      | (1ULL << CParser::Namespace)
      | (1ULL << CParser::ScopeResolution)
      | (1ULL << CParser::String)
      | (1ULL << CParser::Break)
      | (1ULL << CParser::Case)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Continue)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Default)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Else)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::For)
      | (1ULL << CParser::If)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Uint32)
      | (1ULL << CParser::Int32)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Return)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Switch)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::While)
      | (1ULL << CParser::LeftParen)
      | (1ULL << CParser::LeftBracket)
      | (1ULL << CParser::RightBracket)
      | (1ULL << CParser::LeftBrace)
      | (1ULL << CParser::RightBrace)
      | (1ULL << CParser::Less)
      | (1ULL << CParser::LessEqual)
      | (1ULL << CParser::Greater)
      | (1ULL << CParser::GreaterEqual)
      | (1ULL << CParser::LeftShift)
      | (1ULL << CParser::RightShift))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
      | (1ULL << (CParser::PlusPlus - 64))
      | (1ULL << (CParser::Minus - 64))
      | (1ULL << (CParser::MinusMinus - 64))
      | (1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::Div - 64))
      | (1ULL << (CParser::Mod - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Or - 64))
      | (1ULL << (CParser::Negate - 64))
      | (1ULL << (CParser::Caret - 64))
      | (1ULL << (CParser::Question - 64))
      | (1ULL << (CParser::Colon - 64))
      | (1ULL << (CParser::Semi - 64))
      | (1ULL << (CParser::Comma - 64))
      | (1ULL << (CParser::Assign - 64))
      | (1ULL << (CParser::StarAssign - 64))
      | (1ULL << (CParser::DivAssign - 64))
      | (1ULL << (CParser::ModAssign - 64))
      | (1ULL << (CParser::PlusAssign - 64))
      | (1ULL << (CParser::MinusAssign - 64))
      | (1ULL << (CParser::LeftShiftAssign - 64))
      | (1ULL << (CParser::RightShiftAssign - 64))
      | (1ULL << (CParser::AndAssign - 64))
      | (1ULL << (CParser::XorAssign - 64))
      | (1ULL << (CParser::OrAssign - 64))
      | (1ULL << (CParser::NegateAssign - 64))
      | (1ULL << (CParser::Arrow - 64))
      | (1ULL << (CParser::Dot - 64))
      | (1ULL << (CParser::Ellipsis - 64))
      | (1ULL << (CParser::AndAnd - 64))
      | (1ULL << (CParser::OrOr - 64))
      | (1ULL << (CParser::Not - 64))
      | (1ULL << (CParser::Equal - 64))
      | (1ULL << (CParser::NotEqual - 64))
      | (1ULL << (CParser::Identifier - 64))
      | (1ULL << (CParser::Whitespace - 64))
      | (1ULL << (CParser::Newline - 64))
      | (1ULL << (CParser::BlockComment - 64))
      | (1ULL << (CParser::LineComment - 64)))) != 0)) {
      setState(569);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CParser::T__0:
        case CParser::T__1:
        case CParser::T__2:
        case CParser::T__3:
        case CParser::T__4:
        case CParser::T__5:
        case CParser::T__6:
        case CParser::T__7:
        case CParser::T__8:
        case CParser::T__9:
        case CParser::T__10:
        case CParser::T__11:
        case CParser::T__12:
        case CParser::T__13:
        case CParser::Constant:
        case CParser::DigitSequence:
        case CParser::StringLiteral:
        case CParser::Coalescing:
        case CParser::Bit:
        case CParser::Power:
        case CParser::IgnoreWildCard:
        case CParser::Namespace:
        case CParser::ScopeResolution:
        case CParser::String:
        case CParser::Break:
        case CParser::Case:
        case CParser::Char:
        case CParser::Const:
        case CParser::Continue:
        case CParser::Bool:
        case CParser::Default:
        case CParser::Double:
        case CParser::Else:
        case CParser::Extern:
        case CParser::Float:
        case CParser::For:
        case CParser::If:
        case CParser::Int:
        case CParser::Uint32:
        case CParser::Int32:
        case CParser::Long:
        case CParser::Return:
        case CParser::Short:
        case CParser::Signed:
        case CParser::Sizeof:
        case CParser::Static:
        case CParser::Switch:
        case CParser::Typedef:
        case CParser::Unsigned:
        case CParser::Void:
        case CParser::While:
        case CParser::LeftBracket:
        case CParser::RightBracket:
        case CParser::LeftBrace:
        case CParser::RightBrace:
        case CParser::Less:
        case CParser::LessEqual:
        case CParser::Greater:
        case CParser::GreaterEqual:
        case CParser::LeftShift:
        case CParser::RightShift:
        case CParser::Plus:
        case CParser::PlusPlus:
        case CParser::Minus:
        case CParser::MinusMinus:
        case CParser::Star:
        case CParser::Div:
        case CParser::Mod:
        case CParser::And:
        case CParser::Or:
        case CParser::Negate:
        case CParser::Caret:
        case CParser::Question:
        case CParser::Colon:
        case CParser::Semi:
        case CParser::Comma:
        case CParser::Assign:
        case CParser::StarAssign:
        case CParser::DivAssign:
        case CParser::ModAssign:
        case CParser::PlusAssign:
        case CParser::MinusAssign:
        case CParser::LeftShiftAssign:
        case CParser::RightShiftAssign:
        case CParser::AndAssign:
        case CParser::XorAssign:
        case CParser::OrAssign:
        case CParser::NegateAssign:
        case CParser::Arrow:
        case CParser::Dot:
        case CParser::Ellipsis:
        case CParser::AndAnd:
        case CParser::OrOr:
        case CParser::Not:
        case CParser::Equal:
        case CParser::NotEqual:
        case CParser::Identifier:
        case CParser::Whitespace:
        case CParser::Newline:
        case CParser::BlockComment:
        case CParser::LineComment: {
          setState(564);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == CParser::LeftParen

          || _la == CParser::RightParen)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case CParser::LeftParen: {
          setState(565);
          match(CParser::LeftParen);
          setState(566);
          nestedParenthesesBlock();
          setState(567);
          match(CParser::RightParen);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(573);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointerContext ------------------------------------------------------------------

CParser::PointerContext::PointerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeQualifierListContext* CParser::PointerContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}

CParser::PointerContext* CParser::PointerContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}


size_t CParser::PointerContext::getRuleIndex() const {
  return CParser::RulePointer;
}

void CParser::PointerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPointer(this);
}

void CParser::PointerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPointer(this);
}

CParser::PointerContext* CParser::pointer() {
  PointerContext *_localctx = _tracker.createInstance<PointerContext>(_ctx, getState());
  enterRule(_localctx, 68, CParser::RulePointer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(592);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(574);
      match(CParser::Star);
      setState(576);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
      case 1: {
        setState(575);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(578);
      match(CParser::Star);
      setState(580);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Const) {
        setState(579);
        typeQualifierList(0);
      }
      setState(582);
      pointer();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(583);
      match(CParser::Caret);
      setState(585);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
      case 1: {
        setState(584);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(587);
      match(CParser::Caret);
      setState(589);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Const) {
        setState(588);
        typeQualifierList(0);
      }
      setState(591);
      pointer();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeQualifierListContext ------------------------------------------------------------------

CParser::TypeQualifierListContext::TypeQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeQualifierContext* CParser::TypeQualifierListContext::typeQualifier() {
  return getRuleContext<CParser::TypeQualifierContext>(0);
}

CParser::TypeQualifierListContext* CParser::TypeQualifierListContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}


size_t CParser::TypeQualifierListContext::getRuleIndex() const {
  return CParser::RuleTypeQualifierList;
}

void CParser::TypeQualifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeQualifierList(this);
}

void CParser::TypeQualifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeQualifierList(this);
}


CParser::TypeQualifierListContext* CParser::typeQualifierList() {
   return typeQualifierList(0);
}

CParser::TypeQualifierListContext* CParser::typeQualifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::TypeQualifierListContext *_localctx = _tracker.createInstance<TypeQualifierListContext>(_ctx, parentState);
  CParser::TypeQualifierListContext *previousContext = _localctx;
  size_t startState = 70;
  enterRecursionRule(_localctx, 70, CParser::RuleTypeQualifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(595);
    typeQualifier();
    _ctx->stop = _input->LT(-1);
    setState(601);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeQualifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeQualifierList);
        setState(597);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(598);
        typeQualifier(); 
      }
      setState(603);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterTypeListContext ------------------------------------------------------------------

CParser::ParameterTypeListContext::ParameterTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ParameterListContext* CParser::ParameterTypeListContext::parameterList() {
  return getRuleContext<CParser::ParameterListContext>(0);
}


size_t CParser::ParameterTypeListContext::getRuleIndex() const {
  return CParser::RuleParameterTypeList;
}

void CParser::ParameterTypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterTypeList(this);
}

void CParser::ParameterTypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterTypeList(this);
}

CParser::ParameterTypeListContext* CParser::parameterTypeList() {
  ParameterTypeListContext *_localctx = _tracker.createInstance<ParameterTypeListContext>(_ctx, getState());
  enterRule(_localctx, 72, CParser::RuleParameterTypeList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(609);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(604);
      parameterList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(605);
      parameterList(0);
      setState(606);
      match(CParser::Comma);
      setState(607);
      match(CParser::Ellipsis);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

CParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ParameterDeclarationContext* CParser::ParameterListContext::parameterDeclaration() {
  return getRuleContext<CParser::ParameterDeclarationContext>(0);
}

CParser::ParameterListContext* CParser::ParameterListContext::parameterList() {
  return getRuleContext<CParser::ParameterListContext>(0);
}


size_t CParser::ParameterListContext::getRuleIndex() const {
  return CParser::RuleParameterList;
}

void CParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void CParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


CParser::ParameterListContext* CParser::parameterList() {
   return parameterList(0);
}

CParser::ParameterListContext* CParser::parameterList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, parentState);
  CParser::ParameterListContext *previousContext = _localctx;
  size_t startState = 74;
  enterRecursionRule(_localctx, 74, CParser::RuleParameterList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(612);
    parameterDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(619);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterList);
        setState(614);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(615);
        match(CParser::Comma);
        setState(616);
        parameterDeclaration(); 
      }
      setState(621);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

CParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::ParameterDeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::DeclaratorContext* CParser::ParameterDeclarationContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::DeclarationSpecifiers2Context* CParser::ParameterDeclarationContext::declarationSpecifiers2() {
  return getRuleContext<CParser::DeclarationSpecifiers2Context>(0);
}

CParser::AbstractDeclaratorContext* CParser::ParameterDeclarationContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}


size_t CParser::ParameterDeclarationContext::getRuleIndex() const {
  return CParser::RuleParameterDeclaration;
}

void CParser::ParameterDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDeclaration(this);
}

void CParser::ParameterDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDeclaration(this);
}

CParser::ParameterDeclarationContext* CParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 76, CParser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(629);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(622);
      declarationSpecifiers();
      setState(623);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(625);
      declarationSpecifiers2();
      setState(627);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
      case 1: {
        setState(626);
        abstractDeclarator();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

CParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::IdentifierListContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::IdentifierListContext* CParser::IdentifierListContext::identifierList() {
  return getRuleContext<CParser::IdentifierListContext>(0);
}


size_t CParser::IdentifierListContext::getRuleIndex() const {
  return CParser::RuleIdentifierList;
}

void CParser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void CParser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}


CParser::IdentifierListContext* CParser::identifierList() {
   return identifierList(0);
}

CParser::IdentifierListContext* CParser::identifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, parentState);
  CParser::IdentifierListContext *previousContext = _localctx;
  size_t startState = 78;
  enterRecursionRule(_localctx, 78, CParser::RuleIdentifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(632);
    match(CParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(639);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(634);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(635);
        match(CParser::Comma);
        setState(636);
        match(CParser::Identifier); 
      }
      setState(641);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

CParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::SpecifierQualifierListContext* CParser::TypeNameContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

CParser::AbstractDeclaratorContext* CParser::TypeNameContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}


size_t CParser::TypeNameContext::getRuleIndex() const {
  return CParser::RuleTypeName;
}

void CParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void CParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}

CParser::TypeNameContext* CParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 80, CParser::RuleTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(642);
    specifierQualifierList();
    setState(644);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & ((1ULL << (CParser::LeftParen - 52))
      | (1ULL << (CParser::LeftBracket - 52))
      | (1ULL << (CParser::Star - 52))
      | (1ULL << (CParser::Caret - 52)))) != 0)) {
      setState(643);
      abstractDeclarator();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AbstractDeclaratorContext ------------------------------------------------------------------

CParser::AbstractDeclaratorContext::AbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PointerContext* CParser::AbstractDeclaratorContext::pointer() {
  return getRuleContext<CParser::PointerContext>(0);
}

CParser::DirectAbstractDeclaratorContext* CParser::AbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<CParser::DirectAbstractDeclaratorContext>(0);
}


size_t CParser::AbstractDeclaratorContext::getRuleIndex() const {
  return CParser::RuleAbstractDeclarator;
}

void CParser::AbstractDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAbstractDeclarator(this);
}

void CParser::AbstractDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAbstractDeclarator(this);
}

CParser::AbstractDeclaratorContext* CParser::abstractDeclarator() {
  AbstractDeclaratorContext *_localctx = _tracker.createInstance<AbstractDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 82, CParser::RuleAbstractDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(651);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(646);
      pointer();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(648);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Star

      || _la == CParser::Caret) {
        setState(647);
        pointer();
      }
      setState(650);
      directAbstractDeclarator(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectAbstractDeclaratorContext ------------------------------------------------------------------

CParser::DirectAbstractDeclaratorContext::DirectAbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AbstractDeclaratorContext* CParser::DirectAbstractDeclaratorContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}

CParser::TypeQualifierListContext* CParser::DirectAbstractDeclaratorContext::typeQualifierList() {
  return getRuleContext<CParser::TypeQualifierListContext>(0);
}

CParser::AssignmentExpressionContext* CParser::DirectAbstractDeclaratorContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ParameterTypeListContext* CParser::DirectAbstractDeclaratorContext::parameterTypeList() {
  return getRuleContext<CParser::ParameterTypeListContext>(0);
}

CParser::DirectAbstractDeclaratorContext* CParser::DirectAbstractDeclaratorContext::directAbstractDeclarator() {
  return getRuleContext<CParser::DirectAbstractDeclaratorContext>(0);
}


size_t CParser::DirectAbstractDeclaratorContext::getRuleIndex() const {
  return CParser::RuleDirectAbstractDeclarator;
}

void CParser::DirectAbstractDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectAbstractDeclarator(this);
}

void CParser::DirectAbstractDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectAbstractDeclarator(this);
}


CParser::DirectAbstractDeclaratorContext* CParser::directAbstractDeclarator() {
   return directAbstractDeclarator(0);
}

CParser::DirectAbstractDeclaratorContext* CParser::directAbstractDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DirectAbstractDeclaratorContext *_localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(_ctx, parentState);
  CParser::DirectAbstractDeclaratorContext *previousContext = _localctx;
  size_t startState = 84;
  enterRecursionRule(_localctx, 84, CParser::RuleDirectAbstractDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(688);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      setState(654);
      match(CParser::LeftParen);
      setState(655);
      abstractDeclarator();
      setState(656);
      match(CParser::RightParen);
      break;
    }

    case 2: {
      setState(658);
      match(CParser::LeftBracket);
      setState(660);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Const) {
        setState(659);
        typeQualifierList(0);
      }
      setState(663);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::Constant)
        | (1ULL << CParser::DigitSequence)
        | (1ULL << CParser::StringLiteral)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
        | (1ULL << (CParser::PlusPlus - 64))
        | (1ULL << (CParser::Minus - 64))
        | (1ULL << (CParser::MinusMinus - 64))
        | (1ULL << (CParser::Star - 64))
        | (1ULL << (CParser::And - 64))
        | (1ULL << (CParser::Negate - 64))
        | (1ULL << (CParser::Identifier - 64)))) != 0)) {
        setState(662);
        assignmentExpression();
      }
      setState(665);
      match(CParser::RightBracket);
      break;
    }

    case 3: {
      setState(666);
      match(CParser::LeftBracket);
      setState(667);
      match(CParser::Static);
      setState(669);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Const) {
        setState(668);
        typeQualifierList(0);
      }
      setState(671);
      assignmentExpression();
      setState(672);
      match(CParser::RightBracket);
      break;
    }

    case 4: {
      setState(674);
      match(CParser::LeftBracket);
      setState(675);
      typeQualifierList(0);
      setState(676);
      match(CParser::Static);
      setState(677);
      assignmentExpression();
      setState(678);
      match(CParser::RightBracket);
      break;
    }

    case 5: {
      setState(680);
      match(CParser::LeftBracket);
      setState(681);
      match(CParser::Star);
      setState(682);
      match(CParser::RightBracket);
      break;
    }

    case 6: {
      setState(683);
      match(CParser::LeftParen);
      setState(685);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__11)
        | (1ULL << CParser::T__12)
        | (1ULL << CParser::Char)
        | (1ULL << CParser::Const)
        | (1ULL << CParser::Bool)
        | (1ULL << CParser::Double)
        | (1ULL << CParser::Extern)
        | (1ULL << CParser::Float)
        | (1ULL << CParser::Int)
        | (1ULL << CParser::Uint32)
        | (1ULL << CParser::Int32)
        | (1ULL << CParser::Long)
        | (1ULL << CParser::Short)
        | (1ULL << CParser::Signed)
        | (1ULL << CParser::Static)
        | (1ULL << CParser::Typedef)
        | (1ULL << CParser::Unsigned)
        | (1ULL << CParser::Void))) != 0)) {
        setState(684);
        parameterTypeList();
      }
      setState(687);
      match(CParser::RightParen);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(727);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(725);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(690);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(691);
          match(CParser::LeftBracket);
          setState(693);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(692);
            typeQualifierList(0);
          }
          setState(696);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__0)
            | (1ULL << CParser::T__1)
            | (1ULL << CParser::T__2)
            | (1ULL << CParser::T__3)
            | (1ULL << CParser::Constant)
            | (1ULL << CParser::DigitSequence)
            | (1ULL << CParser::StringLiteral)
            | (1ULL << CParser::Sizeof)
            | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
            | (1ULL << (CParser::PlusPlus - 64))
            | (1ULL << (CParser::Minus - 64))
            | (1ULL << (CParser::MinusMinus - 64))
            | (1ULL << (CParser::Star - 64))
            | (1ULL << (CParser::And - 64))
            | (1ULL << (CParser::Negate - 64))
            | (1ULL << (CParser::Identifier - 64)))) != 0)) {
            setState(695);
            assignmentExpression();
          }
          setState(698);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(699);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(700);
          match(CParser::LeftBracket);
          setState(701);
          match(CParser::Static);
          setState(703);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(702);
            typeQualifierList(0);
          }
          setState(705);
          assignmentExpression();
          setState(706);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(708);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(709);
          match(CParser::LeftBracket);
          setState(710);
          typeQualifierList(0);
          setState(711);
          match(CParser::Static);
          setState(712);
          assignmentExpression();
          setState(713);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(715);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(716);
          match(CParser::LeftBracket);
          setState(717);
          match(CParser::Star);
          setState(718);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(719);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(720);
          match(CParser::LeftParen);
          setState(722);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__11)
            | (1ULL << CParser::T__12)
            | (1ULL << CParser::Char)
            | (1ULL << CParser::Const)
            | (1ULL << CParser::Bool)
            | (1ULL << CParser::Double)
            | (1ULL << CParser::Extern)
            | (1ULL << CParser::Float)
            | (1ULL << CParser::Int)
            | (1ULL << CParser::Uint32)
            | (1ULL << CParser::Int32)
            | (1ULL << CParser::Long)
            | (1ULL << CParser::Short)
            | (1ULL << CParser::Signed)
            | (1ULL << CParser::Static)
            | (1ULL << CParser::Typedef)
            | (1ULL << CParser::Unsigned)
            | (1ULL << CParser::Void))) != 0)) {
            setState(721);
            parameterTypeList();
          }
          setState(724);
          match(CParser::RightParen);
          break;
        }

        } 
      }
      setState(729);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- InitializerContext ------------------------------------------------------------------

CParser::InitializerContext::InitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::InitializerContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::InitializerListContext* CParser::InitializerContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}


size_t CParser::InitializerContext::getRuleIndex() const {
  return CParser::RuleInitializer;
}

void CParser::InitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializer(this);
}

void CParser::InitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializer(this);
}

CParser::InitializerContext* CParser::initializer() {
  InitializerContext *_localctx = _tracker.createInstance<InitializerContext>(_ctx, getState());
  enterRule(_localctx, 86, CParser::RuleInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(740);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(730);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(731);
      match(CParser::LeftBrace);
      setState(732);
      initializerList(0);
      setState(733);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(735);
      match(CParser::LeftBrace);
      setState(736);
      initializerList(0);
      setState(737);
      match(CParser::Comma);
      setState(738);
      match(CParser::RightBrace);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerListContext ------------------------------------------------------------------

CParser::InitializerListContext::InitializerListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::InitializerContext* CParser::InitializerListContext::initializer() {
  return getRuleContext<CParser::InitializerContext>(0);
}

CParser::DesignationContext* CParser::InitializerListContext::designation() {
  return getRuleContext<CParser::DesignationContext>(0);
}

CParser::InitializerListContext* CParser::InitializerListContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}


size_t CParser::InitializerListContext::getRuleIndex() const {
  return CParser::RuleInitializerList;
}

void CParser::InitializerListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializerList(this);
}

void CParser::InitializerListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializerList(this);
}


CParser::InitializerListContext* CParser::initializerList() {
   return initializerList(0);
}

CParser::InitializerListContext* CParser::initializerList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::InitializerListContext *_localctx = _tracker.createInstance<InitializerListContext>(_ctx, parentState);
  CParser::InitializerListContext *previousContext = _localctx;
  size_t startState = 88;
  enterRecursionRule(_localctx, 88, CParser::RuleInitializerList, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(744);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::LeftBracket

    || _la == CParser::Dot) {
      setState(743);
      designation();
    }
    setState(746);
    initializer();
    _ctx->stop = _input->LT(-1);
    setState(756);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitializerListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitializerList);
        setState(748);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(749);
        match(CParser::Comma);
        setState(751);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftBracket

        || _la == CParser::Dot) {
          setState(750);
          designation();
        }
        setState(753);
        initializer(); 
      }
      setState(758);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignationContext ------------------------------------------------------------------

CParser::DesignationContext::DesignationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DesignatorListContext* CParser::DesignationContext::designatorList() {
  return getRuleContext<CParser::DesignatorListContext>(0);
}


size_t CParser::DesignationContext::getRuleIndex() const {
  return CParser::RuleDesignation;
}

void CParser::DesignationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignation(this);
}

void CParser::DesignationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignation(this);
}

CParser::DesignationContext* CParser::designation() {
  DesignationContext *_localctx = _tracker.createInstance<DesignationContext>(_ctx, getState());
  enterRule(_localctx, 90, CParser::RuleDesignation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(759);
    designatorList(0);
    setState(760);
    match(CParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorListContext ------------------------------------------------------------------

CParser::DesignatorListContext::DesignatorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DesignatorContext* CParser::DesignatorListContext::designator() {
  return getRuleContext<CParser::DesignatorContext>(0);
}

CParser::DesignatorListContext* CParser::DesignatorListContext::designatorList() {
  return getRuleContext<CParser::DesignatorListContext>(0);
}


size_t CParser::DesignatorListContext::getRuleIndex() const {
  return CParser::RuleDesignatorList;
}

void CParser::DesignatorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignatorList(this);
}

void CParser::DesignatorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignatorList(this);
}


CParser::DesignatorListContext* CParser::designatorList() {
   return designatorList(0);
}

CParser::DesignatorListContext* CParser::designatorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DesignatorListContext *_localctx = _tracker.createInstance<DesignatorListContext>(_ctx, parentState);
  CParser::DesignatorListContext *previousContext = _localctx;
  size_t startState = 92;
  enterRecursionRule(_localctx, 92, CParser::RuleDesignatorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(763);
    designator();
    _ctx->stop = _input->LT(-1);
    setState(769);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DesignatorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDesignatorList);
        setState(765);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(766);
        designator(); 
      }
      setState(771);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

CParser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConstantExpressionContext* CParser::DesignatorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* CParser::DesignatorContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::DesignatorContext::getRuleIndex() const {
  return CParser::RuleDesignator;
}

void CParser::DesignatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignator(this);
}

void CParser::DesignatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignator(this);
}

CParser::DesignatorContext* CParser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 94, CParser::RuleDesignator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(778);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::LeftBracket: {
        enterOuterAlt(_localctx, 1);
        setState(772);
        match(CParser::LeftBracket);
        setState(773);
        constantExpression();
        setState(774);
        match(CParser::RightBracket);
        break;
      }

      case CParser::Dot: {
        enterOuterAlt(_localctx, 2);
        setState(776);
        match(CParser::Dot);
        setState(777);
        match(CParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LabeledStatementContext* CParser::StatementContext::labeledStatement() {
  return getRuleContext<CParser::LabeledStatementContext>(0);
}

CParser::CompoundStatementContext* CParser::StatementContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::ExpressionStatementContext* CParser::StatementContext::expressionStatement() {
  return getRuleContext<CParser::ExpressionStatementContext>(0);
}

CParser::SelectionStatementContext* CParser::StatementContext::selectionStatement() {
  return getRuleContext<CParser::SelectionStatementContext>(0);
}

CParser::IterationStatementContext* CParser::StatementContext::iterationStatement() {
  return getRuleContext<CParser::IterationStatementContext>(0);
}

CParser::JumpStatementContext* CParser::StatementContext::jumpStatement() {
  return getRuleContext<CParser::JumpStatementContext>(0);
}


size_t CParser::StatementContext::getRuleIndex() const {
  return CParser::RuleStatement;
}

void CParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void CParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

CParser::StatementContext* CParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 96, CParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(786);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(780);
      labeledStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(781);
      compoundStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(782);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(783);
      selectionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(784);
      iterationStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(785);
      jumpStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabeledStatementContext ------------------------------------------------------------------

CParser::LabeledStatementContext::LabeledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::LabeledStatementContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::StatementContext* CParser::LabeledStatementContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

CParser::ConstantExpressionContext* CParser::LabeledStatementContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::LabeledStatementContext::getRuleIndex() const {
  return CParser::RuleLabeledStatement;
}

void CParser::LabeledStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabeledStatement(this);
}

void CParser::LabeledStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabeledStatement(this);
}

CParser::LabeledStatementContext* CParser::labeledStatement() {
  LabeledStatementContext *_localctx = _tracker.createInstance<LabeledStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, CParser::RuleLabeledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(799);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(788);
        match(CParser::Identifier);
        setState(789);
        match(CParser::Colon);
        setState(790);
        statement();
        break;
      }

      case CParser::Case: {
        enterOuterAlt(_localctx, 2);
        setState(791);
        match(CParser::Case);
        setState(792);
        constantExpression();
        setState(793);
        match(CParser::Colon);
        setState(794);
        statement();
        break;
      }

      case CParser::Default: {
        enterOuterAlt(_localctx, 3);
        setState(796);
        match(CParser::Default);
        setState(797);
        match(CParser::Colon);
        setState(798);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

CParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::BlockItemListContext* CParser::CompoundStatementContext::blockItemList() {
  return getRuleContext<CParser::BlockItemListContext>(0);
}


size_t CParser::CompoundStatementContext::getRuleIndex() const {
  return CParser::RuleCompoundStatement;
}

void CParser::CompoundStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void CParser::CompoundStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}

CParser::CompoundStatementContext* CParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 100, CParser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(801);
    match(CParser::LeftBrace);
    setState(803);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__13)
      | (1ULL << CParser::Constant)
      | (1ULL << CParser::DigitSequence)
      | (1ULL << CParser::StringLiteral)
      | (1ULL << CParser::Break)
      | (1ULL << CParser::Case)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Continue)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Default)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::For)
      | (1ULL << CParser::If)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Uint32)
      | (1ULL << CParser::Int32)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Return)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Switch)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::While)
      | (1ULL << CParser::LeftParen)
      | (1ULL << CParser::LeftBrace))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
      | (1ULL << (CParser::PlusPlus - 64))
      | (1ULL << (CParser::Minus - 64))
      | (1ULL << (CParser::MinusMinus - 64))
      | (1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Negate - 64))
      | (1ULL << (CParser::Semi - 64))
      | (1ULL << (CParser::Identifier - 64)))) != 0)) {
      setState(802);
      blockItemList(0);
    }
    setState(805);
    match(CParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemListContext ------------------------------------------------------------------

CParser::BlockItemListContext::BlockItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::BlockItemContext* CParser::BlockItemListContext::blockItem() {
  return getRuleContext<CParser::BlockItemContext>(0);
}

CParser::BlockItemListContext* CParser::BlockItemListContext::blockItemList() {
  return getRuleContext<CParser::BlockItemListContext>(0);
}


size_t CParser::BlockItemListContext::getRuleIndex() const {
  return CParser::RuleBlockItemList;
}

void CParser::BlockItemListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItemList(this);
}

void CParser::BlockItemListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItemList(this);
}


CParser::BlockItemListContext* CParser::blockItemList() {
   return blockItemList(0);
}

CParser::BlockItemListContext* CParser::blockItemList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::BlockItemListContext *_localctx = _tracker.createInstance<BlockItemListContext>(_ctx, parentState);
  CParser::BlockItemListContext *previousContext = _localctx;
  size_t startState = 102;
  enterRecursionRule(_localctx, 102, CParser::RuleBlockItemList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(808);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(814);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(810);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(811);
        blockItem(); 
      }
      setState(816);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StatementContext* CParser::BlockItemContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

CParser::DeclarationContext* CParser::BlockItemContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}


size_t CParser::BlockItemContext::getRuleIndex() const {
  return CParser::RuleBlockItem;
}

void CParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void CParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}

CParser::BlockItemContext* CParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 104, CParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(819);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::T__1:
      case CParser::T__2:
      case CParser::T__3:
      case CParser::T__13:
      case CParser::Constant:
      case CParser::DigitSequence:
      case CParser::StringLiteral:
      case CParser::Break:
      case CParser::Case:
      case CParser::Continue:
      case CParser::Default:
      case CParser::For:
      case CParser::If:
      case CParser::Return:
      case CParser::Sizeof:
      case CParser::Switch:
      case CParser::While:
      case CParser::LeftParen:
      case CParser::LeftBrace:
      case CParser::Plus:
      case CParser::PlusPlus:
      case CParser::Minus:
      case CParser::MinusMinus:
      case CParser::Star:
      case CParser::And:
      case CParser::Negate:
      case CParser::Semi:
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(817);
        statement();
        break;
      }

      case CParser::T__11:
      case CParser::T__12:
      case CParser::Char:
      case CParser::Const:
      case CParser::Bool:
      case CParser::Double:
      case CParser::Extern:
      case CParser::Float:
      case CParser::Int:
      case CParser::Uint32:
      case CParser::Int32:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Static:
      case CParser::Typedef:
      case CParser::Unsigned:
      case CParser::Void: {
        enterOuterAlt(_localctx, 2);
        setState(818);
        declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

CParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::ExpressionStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ExpressionStatementContext::getRuleIndex() const {
  return CParser::RuleExpressionStatement;
}

void CParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void CParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}

CParser::ExpressionStatementContext* CParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 106, CParser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(822);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::Constant)
      | (1ULL << CParser::DigitSequence)
      | (1ULL << CParser::StringLiteral)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
      | (1ULL << (CParser::PlusPlus - 64))
      | (1ULL << (CParser::Minus - 64))
      | (1ULL << (CParser::MinusMinus - 64))
      | (1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Negate - 64))
      | (1ULL << (CParser::Identifier - 64)))) != 0)) {
      setState(821);
      expression(0);
    }
    setState(824);
    match(CParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

CParser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::SelectionStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

std::vector<CParser::StatementContext *> CParser::SelectionStatementContext::statement() {
  return getRuleContexts<CParser::StatementContext>();
}

CParser::StatementContext* CParser::SelectionStatementContext::statement(size_t i) {
  return getRuleContext<CParser::StatementContext>(i);
}


size_t CParser::SelectionStatementContext::getRuleIndex() const {
  return CParser::RuleSelectionStatement;
}

void CParser::SelectionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectionStatement(this);
}

void CParser::SelectionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectionStatement(this);
}

CParser::SelectionStatementContext* CParser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 108, CParser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(841);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(826);
        match(CParser::If);
        setState(827);
        match(CParser::LeftParen);
        setState(828);
        expression(0);
        setState(829);
        match(CParser::RightParen);
        setState(830);
        statement();
        setState(833);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
        case 1: {
          setState(831);
          match(CParser::Else);
          setState(832);
          statement();
          break;
        }

        }
        break;
      }

      case CParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(835);
        match(CParser::Switch);
        setState(836);
        match(CParser::LeftParen);
        setState(837);
        expression(0);
        setState(838);
        match(CParser::RightParen);
        setState(839);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

CParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::IterationStatementContext::While() {
  return getToken(CParser::While, 0);
}

CParser::ExpressionContext* CParser::IterationStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::StatementContext* CParser::IterationStatementContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

tree::TerminalNode* CParser::IterationStatementContext::For() {
  return getToken(CParser::For, 0);
}

CParser::ForConditionContext* CParser::IterationStatementContext::forCondition() {
  return getRuleContext<CParser::ForConditionContext>(0);
}


size_t CParser::IterationStatementContext::getRuleIndex() const {
  return CParser::RuleIterationStatement;
}

void CParser::IterationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStatement(this);
}

void CParser::IterationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStatement(this);
}

CParser::IterationStatementContext* CParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 110, CParser::RuleIterationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(855);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(843);
        match(CParser::While);
        setState(844);
        match(CParser::LeftParen);
        setState(845);
        expression(0);
        setState(846);
        match(CParser::RightParen);
        setState(847);
        statement();
        break;
      }

      case CParser::For: {
        enterOuterAlt(_localctx, 2);
        setState(849);
        match(CParser::For);
        setState(850);
        match(CParser::LeftParen);
        setState(851);
        forCondition();
        setState(852);
        match(CParser::RightParen);
        setState(853);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForConditionContext ------------------------------------------------------------------

CParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ForDeclarationContext* CParser::ForConditionContext::forDeclaration() {
  return getRuleContext<CParser::ForDeclarationContext>(0);
}

std::vector<CParser::ForExpressionContext *> CParser::ForConditionContext::forExpression() {
  return getRuleContexts<CParser::ForExpressionContext>();
}

CParser::ForExpressionContext* CParser::ForConditionContext::forExpression(size_t i) {
  return getRuleContext<CParser::ForExpressionContext>(i);
}

CParser::ExpressionContext* CParser::ForConditionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ForConditionContext::getRuleIndex() const {
  return CParser::RuleForCondition;
}

void CParser::ForConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForCondition(this);
}

void CParser::ForConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForCondition(this);
}

CParser::ForConditionContext* CParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 112, CParser::RuleForCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(877);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__11:
      case CParser::T__12:
      case CParser::Char:
      case CParser::Const:
      case CParser::Bool:
      case CParser::Double:
      case CParser::Extern:
      case CParser::Float:
      case CParser::Int:
      case CParser::Uint32:
      case CParser::Int32:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Static:
      case CParser::Typedef:
      case CParser::Unsigned:
      case CParser::Void: {
        enterOuterAlt(_localctx, 1);
        setState(857);
        forDeclaration();
        setState(858);
        match(CParser::Semi);
        setState(860);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__0)
          | (1ULL << CParser::T__1)
          | (1ULL << CParser::T__2)
          | (1ULL << CParser::T__3)
          | (1ULL << CParser::Constant)
          | (1ULL << CParser::DigitSequence)
          | (1ULL << CParser::StringLiteral)
          | (1ULL << CParser::Sizeof)
          | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
          | (1ULL << (CParser::PlusPlus - 64))
          | (1ULL << (CParser::Minus - 64))
          | (1ULL << (CParser::MinusMinus - 64))
          | (1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Negate - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(859);
          forExpression(0);
        }
        setState(862);
        match(CParser::Semi);
        setState(864);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__0)
          | (1ULL << CParser::T__1)
          | (1ULL << CParser::T__2)
          | (1ULL << CParser::T__3)
          | (1ULL << CParser::Constant)
          | (1ULL << CParser::DigitSequence)
          | (1ULL << CParser::StringLiteral)
          | (1ULL << CParser::Sizeof)
          | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
          | (1ULL << (CParser::PlusPlus - 64))
          | (1ULL << (CParser::Minus - 64))
          | (1ULL << (CParser::MinusMinus - 64))
          | (1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Negate - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(863);
          forExpression(0);
        }
        break;
      }

      case CParser::T__0:
      case CParser::T__1:
      case CParser::T__2:
      case CParser::T__3:
      case CParser::Constant:
      case CParser::DigitSequence:
      case CParser::StringLiteral:
      case CParser::Sizeof:
      case CParser::LeftParen:
      case CParser::Plus:
      case CParser::PlusPlus:
      case CParser::Minus:
      case CParser::MinusMinus:
      case CParser::Star:
      case CParser::And:
      case CParser::Negate:
      case CParser::Semi:
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(867);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__0)
          | (1ULL << CParser::T__1)
          | (1ULL << CParser::T__2)
          | (1ULL << CParser::T__3)
          | (1ULL << CParser::Constant)
          | (1ULL << CParser::DigitSequence)
          | (1ULL << CParser::StringLiteral)
          | (1ULL << CParser::Sizeof)
          | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
          | (1ULL << (CParser::PlusPlus - 64))
          | (1ULL << (CParser::Minus - 64))
          | (1ULL << (CParser::MinusMinus - 64))
          | (1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Negate - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(866);
          expression(0);
        }
        setState(869);
        match(CParser::Semi);
        setState(871);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__0)
          | (1ULL << CParser::T__1)
          | (1ULL << CParser::T__2)
          | (1ULL << CParser::T__3)
          | (1ULL << CParser::Constant)
          | (1ULL << CParser::DigitSequence)
          | (1ULL << CParser::StringLiteral)
          | (1ULL << CParser::Sizeof)
          | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
          | (1ULL << (CParser::PlusPlus - 64))
          | (1ULL << (CParser::Minus - 64))
          | (1ULL << (CParser::MinusMinus - 64))
          | (1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Negate - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(870);
          forExpression(0);
        }
        setState(873);
        match(CParser::Semi);
        setState(875);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::T__0)
          | (1ULL << CParser::T__1)
          | (1ULL << CParser::T__2)
          | (1ULL << CParser::T__3)
          | (1ULL << CParser::Constant)
          | (1ULL << CParser::DigitSequence)
          | (1ULL << CParser::StringLiteral)
          | (1ULL << CParser::Sizeof)
          | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
          | (1ULL << (CParser::PlusPlus - 64))
          | (1ULL << (CParser::Minus - 64))
          | (1ULL << (CParser::MinusMinus - 64))
          | (1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Negate - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(874);
          forExpression(0);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForDeclarationContext ------------------------------------------------------------------

CParser::ForDeclarationContext::ForDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::ForDeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::InitDeclaratorListContext* CParser::ForDeclarationContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}


size_t CParser::ForDeclarationContext::getRuleIndex() const {
  return CParser::RuleForDeclaration;
}

void CParser::ForDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForDeclaration(this);
}

void CParser::ForDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForDeclaration(this);
}

CParser::ForDeclarationContext* CParser::forDeclaration() {
  ForDeclarationContext *_localctx = _tracker.createInstance<ForDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 114, CParser::RuleForDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(883);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(879);
      declarationSpecifiers();
      setState(880);
      initDeclaratorList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(882);
      declarationSpecifiers();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForExpressionContext ------------------------------------------------------------------

CParser::ForExpressionContext::ForExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::ForExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ForExpressionContext* CParser::ForExpressionContext::forExpression() {
  return getRuleContext<CParser::ForExpressionContext>(0);
}


size_t CParser::ForExpressionContext::getRuleIndex() const {
  return CParser::RuleForExpression;
}

void CParser::ForExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForExpression(this);
}

void CParser::ForExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForExpression(this);
}


CParser::ForExpressionContext* CParser::forExpression() {
   return forExpression(0);
}

CParser::ForExpressionContext* CParser::forExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::ForExpressionContext *_localctx = _tracker.createInstance<ForExpressionContext>(_ctx, parentState);
  CParser::ForExpressionContext *previousContext = _localctx;
  size_t startState = 116;
  enterRecursionRule(_localctx, 116, CParser::RuleForExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(886);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(893);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ForExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleForExpression);
        setState(888);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(889);
        match(CParser::Comma);
        setState(890);
        assignmentExpression(); 
      }
      setState(895);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- JumpStatementContext ------------------------------------------------------------------

CParser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::JumpStatementContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

CParser::ExpressionContext* CParser::JumpStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::UnaryExpressionContext* CParser::JumpStatementContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}


size_t CParser::JumpStatementContext::getRuleIndex() const {
  return CParser::RuleJumpStatement;
}

void CParser::JumpStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpStatement(this);
}

void CParser::JumpStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpStatement(this);
}

CParser::JumpStatementContext* CParser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 118, CParser::RuleJumpStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(912);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(896);
      match(CParser::T__13);
      setState(897);
      match(CParser::Identifier);
      setState(898);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(899);
      match(CParser::Continue);
      setState(900);
      match(CParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(901);
      match(CParser::Break);
      setState(902);
      match(CParser::Semi);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(903);
      match(CParser::Return);
      setState(905);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__0)
        | (1ULL << CParser::T__1)
        | (1ULL << CParser::T__2)
        | (1ULL << CParser::T__3)
        | (1ULL << CParser::Constant)
        | (1ULL << CParser::DigitSequence)
        | (1ULL << CParser::StringLiteral)
        | (1ULL << CParser::Sizeof)
        | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CParser::Plus - 64))
        | (1ULL << (CParser::PlusPlus - 64))
        | (1ULL << (CParser::Minus - 64))
        | (1ULL << (CParser::MinusMinus - 64))
        | (1ULL << (CParser::Star - 64))
        | (1ULL << (CParser::And - 64))
        | (1ULL << (CParser::Negate - 64))
        | (1ULL << (CParser::Identifier - 64)))) != 0)) {
        setState(904);
        expression(0);
      }
      setState(907);
      match(CParser::Semi);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(908);
      match(CParser::T__13);
      setState(909);
      unaryExpression();
      setState(910);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompilationUnitContext ------------------------------------------------------------------

CParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::CompilationUnitContext::EOF() {
  return getToken(CParser::EOF, 0);
}

CParser::TranslationUnitContext* CParser::CompilationUnitContext::translationUnit() {
  return getRuleContext<CParser::TranslationUnitContext>(0);
}


size_t CParser::CompilationUnitContext::getRuleIndex() const {
  return CParser::RuleCompilationUnit;
}

void CParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void CParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}

CParser::CompilationUnitContext* CParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 120, CParser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(915);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Uint32)
      | (1ULL << CParser::Int32)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (CParser::Star - 68))
      | (1ULL << (CParser::Caret - 68))
      | (1ULL << (CParser::Semi - 68))
      | (1ULL << (CParser::Identifier - 68)))) != 0)) {
      setState(914);
      translationUnit(0);
    }
    setState(917);
    match(CParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranslationUnitContext ------------------------------------------------------------------

CParser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExternalDeclarationContext* CParser::TranslationUnitContext::externalDeclaration() {
  return getRuleContext<CParser::ExternalDeclarationContext>(0);
}

CParser::TranslationUnitContext* CParser::TranslationUnitContext::translationUnit() {
  return getRuleContext<CParser::TranslationUnitContext>(0);
}


size_t CParser::TranslationUnitContext::getRuleIndex() const {
  return CParser::RuleTranslationUnit;
}

void CParser::TranslationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranslationUnit(this);
}

void CParser::TranslationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranslationUnit(this);
}


CParser::TranslationUnitContext* CParser::translationUnit() {
   return translationUnit(0);
}

CParser::TranslationUnitContext* CParser::translationUnit(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, parentState);
  CParser::TranslationUnitContext *previousContext = _localctx;
  size_t startState = 122;
  enterRecursionRule(_localctx, 122, CParser::RuleTranslationUnit, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(920);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(926);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(922);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(923);
        externalDeclaration(); 
      }
      setState(928);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExternalDeclarationContext ------------------------------------------------------------------

CParser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::FunctionDefinitionContext* CParser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<CParser::FunctionDefinitionContext>(0);
}

CParser::DeclarationContext* CParser::ExternalDeclarationContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}


size_t CParser::ExternalDeclarationContext::getRuleIndex() const {
  return CParser::RuleExternalDeclaration;
}

void CParser::ExternalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternalDeclaration(this);
}

void CParser::ExternalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternalDeclaration(this);
}

CParser::ExternalDeclarationContext* CParser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 124, CParser::RuleExternalDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(932);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(929);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(930);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(931);
      match(CParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

CParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::FunctionDefinitionContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::CompoundStatementContext* CParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::DeclarationSpecifiersContext* CParser::FunctionDefinitionContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::DeclarationListContext* CParser::FunctionDefinitionContext::declarationList() {
  return getRuleContext<CParser::DeclarationListContext>(0);
}


size_t CParser::FunctionDefinitionContext::getRuleIndex() const {
  return CParser::RuleFunctionDefinition;
}

void CParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void CParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}

CParser::FunctionDefinitionContext* CParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 126, CParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(935);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Uint32)
      | (1ULL << CParser::Int32)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void))) != 0)) {
      setState(934);
      declarationSpecifiers();
    }
    setState(937);
    declarator();
    setState(939);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__11)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Uint32)
      | (1ULL << CParser::Int32)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void))) != 0)) {
      setState(938);
      declarationList(0);
    }
    setState(941);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationListContext ------------------------------------------------------------------

CParser::DeclarationListContext::DeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationContext* CParser::DeclarationListContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}

CParser::DeclarationListContext* CParser::DeclarationListContext::declarationList() {
  return getRuleContext<CParser::DeclarationListContext>(0);
}


size_t CParser::DeclarationListContext::getRuleIndex() const {
  return CParser::RuleDeclarationList;
}

void CParser::DeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationList(this);
}

void CParser::DeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationList(this);
}


CParser::DeclarationListContext* CParser::declarationList() {
   return declarationList(0);
}

CParser::DeclarationListContext* CParser::declarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DeclarationListContext *_localctx = _tracker.createInstance<DeclarationListContext>(_ctx, parentState);
  CParser::DeclarationListContext *previousContext = _localctx;
  size_t startState = 128;
  enterRecursionRule(_localctx, 128, CParser::RuleDeclarationList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(944);
    declaration();
    _ctx->stop = _input->LT(-1);
    setState(950);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDeclarationList);
        setState(946);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(947);
        declaration(); 
      }
      setState(952);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return postfixExpressionSempred(dynamic_cast<PostfixExpressionContext *>(context), predicateIndex);
    case 2: return argumentExpressionListSempred(dynamic_cast<ArgumentExpressionListContext *>(context), predicateIndex);
    case 6: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 7: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 8: return shiftExpressionSempred(dynamic_cast<ShiftExpressionContext *>(context), predicateIndex);
    case 9: return relationalExpressionSempred(dynamic_cast<RelationalExpressionContext *>(context), predicateIndex);
    case 10: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 11: return andExpressionSempred(dynamic_cast<AndExpressionContext *>(context), predicateIndex);
    case 12: return exclusiveOrExpressionSempred(dynamic_cast<ExclusiveOrExpressionContext *>(context), predicateIndex);
    case 13: return inclusiveOrExpressionSempred(dynamic_cast<InclusiveOrExpressionContext *>(context), predicateIndex);
    case 14: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 15: return logicalOrExpressionSempred(dynamic_cast<LogicalOrExpressionContext *>(context), predicateIndex);
    case 19: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 25: return initDeclaratorListSempred(dynamic_cast<InitDeclaratorListContext *>(context), predicateIndex);
    case 32: return directDeclaratorSempred(dynamic_cast<DirectDeclaratorContext *>(context), predicateIndex);
    case 35: return typeQualifierListSempred(dynamic_cast<TypeQualifierListContext *>(context), predicateIndex);
    case 37: return parameterListSempred(dynamic_cast<ParameterListContext *>(context), predicateIndex);
    case 39: return identifierListSempred(dynamic_cast<IdentifierListContext *>(context), predicateIndex);
    case 42: return directAbstractDeclaratorSempred(dynamic_cast<DirectAbstractDeclaratorContext *>(context), predicateIndex);
    case 44: return initializerListSempred(dynamic_cast<InitializerListContext *>(context), predicateIndex);
    case 46: return designatorListSempred(dynamic_cast<DesignatorListContext *>(context), predicateIndex);
    case 51: return blockItemListSempred(dynamic_cast<BlockItemListContext *>(context), predicateIndex);
    case 58: return forExpressionSempred(dynamic_cast<ForExpressionContext *>(context), predicateIndex);
    case 61: return translationUnitSempred(dynamic_cast<TranslationUnitContext *>(context), predicateIndex);
    case 64: return declarationListSempred(dynamic_cast<DeclarationListContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CParser::postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool CParser::argumentExpressionListSempred(ArgumentExpressionListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 3);
    case 8: return precpred(_ctx, 2);
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 2);
    case 11: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::shiftExpressionSempred(ShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 2);
    case 13: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::relationalExpressionSempred(RelationalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 14: return precpred(_ctx, 4);
    case 15: return precpred(_ctx, 3);
    case 16: return precpred(_ctx, 2);
    case 17: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 18: return precpred(_ctx, 4);
    case 19: return precpred(_ctx, 3);
    case 20: return precpred(_ctx, 2);
    case 21: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::andExpressionSempred(AndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 22: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::exclusiveOrExpressionSempred(ExclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 23: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::inclusiveOrExpressionSempred(InclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 24: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 25: return precpred(_ctx, 2);
    case 26: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalOrExpressionSempred(LogicalOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 2);
    case 28: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 29: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::initDeclaratorListSempred(InitDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 30: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 31: return precpred(_ctx, 8);
    case 32: return precpred(_ctx, 7);
    case 33: return precpred(_ctx, 6);
    case 34: return precpred(_ctx, 5);
    case 35: return precpred(_ctx, 4);
    case 36: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CParser::typeQualifierListSempred(TypeQualifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 37: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::parameterListSempred(ParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 38: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 39: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directAbstractDeclaratorSempred(DirectAbstractDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 40: return precpred(_ctx, 5);
    case 41: return precpred(_ctx, 4);
    case 42: return precpred(_ctx, 3);
    case 43: return precpred(_ctx, 2);
    case 44: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::initializerListSempred(InitializerListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 45: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::designatorListSempred(DesignatorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 46: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 47: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::forExpressionSempred(ForExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 48: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::translationUnitSempred(TranslationUnitContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 49: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::declarationListSempred(DeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 50: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CParser::_decisionToDFA;
atn::PredictionContextCache CParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CParser::_atn;
std::vector<uint16_t> CParser::_serializedATN;

std::vector<std::string> CParser::_ruleNames = {
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

std::vector<std::string> CParser::_literalNames = {
  "", "'__extension__'", "'_Alignof'", "'&&'", "'!'", "'is'", "'is not'", 
  "'=='", "'!='", "'and'", "'||'", "'or'", "'auto'", "'register'", "'goto'", 
  "", "", "", "'??'", "'@'", "'**'", "'_'", "'namespace'", "'::'", "'string'", 
  "'break'", "'case'", "'char'", "'const'", "'continue'", "'bool'", "'default'", 
  "'double'", "'else'", "'extern'", "'float'", "'for'", "'if'", "'int'", 
  "'uint32_t'", "'int32_t'", "'long'", "'return'", "'short'", "'signed'", 
  "'sizeof'", "'static'", "'switch'", "'typedef'", "'unsigned'", "'void'", 
  "'while'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", 
  "'>='", "'<<'", "'>>'", "'+'", "'++'", "'-'", "'--'", "'*'", "'/'", "'%'", 
  "'&'", "'|'", "'~'", "'^'", "'?'", "':'", "';'", "','", "'='", "'*='", 
  "'/='", "'%='", "'+='", "'-='", "'<<='", "'>>='", "'&='", "'^='", "'|='", 
  "'~='", "'->'", "'.'", "'...'"
};

std::vector<std::string> CParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "Constant", 
  "DigitSequence", "StringLiteral", "Coalescing", "Bit", "Power", "IgnoreWildCard", 
  "Namespace", "ScopeResolution", "String", "Break", "Case", "Char", "Const", 
  "Continue", "Bool", "Default", "Double", "Else", "Extern", "Float", "For", 
  "If", "Int", "Uint32", "Int32", "Long", "Return", "Short", "Signed", "Sizeof", 
  "Static", "Switch", "Typedef", "Unsigned", "Void", "While", "LeftParen", 
  "RightParen", "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", 
  "Less", "LessEqual", "Greater", "GreaterEqual", "LeftShift", "RightShift", 
  "Plus", "PlusPlus", "Minus", "MinusMinus", "Star", "Div", "Mod", "And", 
  "Or", "Negate", "Caret", "Question", "Colon", "Semi", "Comma", "Assign", 
  "StarAssign", "DivAssign", "ModAssign", "PlusAssign", "MinusAssign", "LeftShiftAssign", 
  "RightShiftAssign", "AndAssign", "XorAssign", "OrAssign", "NegateAssign", 
  "Arrow", "Dot", "Ellipsis", "AndAnd", "OrOr", "Not", "Equal", "NotEqual", 
  "Identifier", "Whitespace", "Newline", "BlockComment", "LineComment"
};

dfa::Vocabulary CParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CParser::_tokenNames;

CParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x69, 0x3bc, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x88, 0xa, 0x2, 0xd, 0x2, 0xe, 
    0x2, 0x89, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x90, 0xa, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0xb4, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0xbe, 0xa, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0xcb, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0xce, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0xd6, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xd9, 0xb, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0xf1, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x102, 0xa, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x110, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0x113, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x11e, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x121, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
    0xa, 0x12c, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x12f, 0xb, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0x140, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x143, 0xb, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x7, 0xc, 0x154, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x157, 0xb, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0x15f, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x162, 0xb, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x16a, 0xa, 0xe, 
    0xc, 0xe, 0xe, 0xe, 0x16d, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x175, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 
    0x178, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x183, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0x186, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 
    0x11, 0x191, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x194, 0xb, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 
    0x19c, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x5, 0x13, 0x1a4, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x1ae, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x1b1, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x5, 0x17, 0x1bc, 0xa, 0x17, 0x3, 0x18, 0x6, 0x18, 0x1bf, 0xa, 
    0x18, 0xd, 0x18, 0xe, 0x18, 0x1c0, 0x3, 0x19, 0x6, 0x19, 0x1c4, 0xa, 
    0x19, 0xd, 0x19, 0xe, 0x19, 0x1c5, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x1cb, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x1d3, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 
    0x1d6, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x5, 0x1c, 0x1dd, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1e5, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x5, 0x1f, 0x1e9, 0xa, 0x1f, 0x5, 0x1f, 0x1eb, 0xa, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x5, 0x21, 0x1f0, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x1ff, 
    0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x205, 
    0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x20a, 0xa, 0x22, 
    0x3, 0x22, 0x5, 0x22, 0x20d, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x214, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x223, 
    0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x22f, 
    0xa, 0x22, 0x3, 0x22, 0x7, 0x22, 0x232, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 
    0x235, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x7, 0x23, 0x23c, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x23f, 0xb, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x243, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x5, 0x24, 0x247, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
    0x24c, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x250, 0xa, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x253, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x25a, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
    0x25d, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x5, 0x26, 0x264, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x26c, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 
    0x26f, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x5, 0x28, 0x276, 0xa, 0x28, 0x5, 0x28, 0x278, 0xa, 0x28, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x280, 
    0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x283, 0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x5, 0x2a, 0x287, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x28b, 
    0xa, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x28e, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x297, 
    0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x29a, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2a0, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x2b0, 0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2b3, 0xa, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2b8, 0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x2bb, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x5, 0x2c, 0x2c2, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x5, 0x2c, 0x2d5, 0xa, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x2d8, 0xa, 0x2c, 
    0xc, 0x2c, 0xe, 0x2c, 0x2db, 0xb, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x5, 0x2d, 0x2e7, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 
    0x2eb, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x5, 0x2e, 0x2f2, 0xa, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x2f5, 0xa, 0x2e, 
    0xc, 0x2e, 0xe, 0x2e, 0x2f8, 0xb, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x302, 
    0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x305, 0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x30d, 0xa, 0x31, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 
    0x32, 0x315, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x5, 0x33, 0x322, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 
    0x326, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x32f, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 
    0x332, 0xb, 0x35, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x336, 0xa, 0x36, 
    0x3, 0x37, 0x5, 0x37, 0x339, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 
    0x38, 0x344, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x34c, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
    0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x35a, 0xa, 0x39, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x35f, 0xa, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x5, 0x3a, 0x363, 0xa, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x366, 
    0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x36a, 0xa, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x5, 0x3a, 0x36e, 0xa, 0x3a, 0x5, 0x3a, 0x370, 0xa, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x376, 0xa, 0x3b, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 
    0x3c, 0x37e, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x381, 0xb, 0x3c, 0x3, 
    0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x38c, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x393, 0xa, 0x3d, 0x3, 0x3e, 
    0x5, 0x3e, 0x396, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x39f, 0xa, 0x3f, 0xc, 0x3f, 
    0xe, 0x3f, 0x3a2, 0xb, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 
    0x3a7, 0xa, 0x40, 0x3, 0x41, 0x5, 0x41, 0x3aa, 0xa, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x5, 0x41, 0x3ae, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x3b7, 0xa, 0x42, 
    0xc, 0x42, 0xe, 0x42, 0x3ba, 0xb, 0x42, 0x3, 0x42, 0x2, 0x1b, 0x4, 0x6, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x28, 0x34, 
    0x42, 0x48, 0x4c, 0x50, 0x56, 0x5a, 0x5e, 0x68, 0x76, 0x7c, 0x82, 0x43, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
    0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 
    0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 
    0x7c, 0x7e, 0x80, 0x82, 0x2, 0x7, 0x8, 0x2, 0x6, 0x6, 0x42, 0x42, 0x44, 
    0x44, 0x46, 0x46, 0x49, 0x49, 0x4b, 0x4b, 0x3, 0x2, 0x51, 0x5c, 0x6, 
    0x2, 0xe, 0xf, 0x24, 0x24, 0x30, 0x30, 0x32, 0x32, 0x9, 0x2, 0x1d, 0x1d, 
    0x20, 0x20, 0x22, 0x22, 0x25, 0x25, 0x28, 0x2b, 0x2d, 0x2e, 0x33, 0x34, 
    0x3, 0x2, 0x36, 0x37, 0x2, 0x415, 0x2, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0x6, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x8, 0xf0, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xc, 0x101, 0x3, 
    0x2, 0x2, 0x2, 0xe, 0x103, 0x3, 0x2, 0x2, 0x2, 0x10, 0x114, 0x3, 0x2, 
    0x2, 0x2, 0x12, 0x122, 0x3, 0x2, 0x2, 0x2, 0x14, 0x130, 0x3, 0x2, 0x2, 
    0x2, 0x16, 0x144, 0x3, 0x2, 0x2, 0x2, 0x18, 0x158, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x163, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x179, 0x3, 0x2, 0x2, 0x2, 0x20, 0x187, 0x3, 0x2, 0x2, 0x2, 0x22, 0x195, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x26, 0x1a5, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x1b2, 0x3, 0x2, 
    0x2, 0x2, 0x2c, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x1be, 0x3, 0x2, 0x2, 
    0x2, 0x30, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x32, 0x1ca, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x1de, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x1ea, 
    0x3, 0x2, 0x2, 0x2, 0x3e, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1ef, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x204, 0x3, 0x2, 0x2, 0x2, 0x44, 0x23d, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x252, 0x3, 0x2, 0x2, 0x2, 0x48, 0x254, 0x3, 0x2, 0x2, 
    0x2, 0x4a, 0x263, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x265, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x277, 0x3, 0x2, 0x2, 0x2, 0x50, 0x279, 0x3, 0x2, 0x2, 0x2, 0x52, 
    0x284, 0x3, 0x2, 0x2, 0x2, 0x54, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x56, 0x2b2, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x2e8, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x2fc, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x62, 0x314, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x321, 0x3, 0x2, 0x2, 0x2, 0x66, 0x323, 0x3, 0x2, 0x2, 0x2, 
    0x68, 0x329, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x335, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x338, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x70, 0x359, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x74, 0x375, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x377, 0x3, 0x2, 0x2, 0x2, 0x78, 0x392, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x395, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x399, 0x3, 0x2, 0x2, 
    0x2, 0x7e, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x80, 0x3a9, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x84, 0x90, 0x7, 0x65, 0x2, 0x2, 0x85, 
    0x90, 0x7, 0x11, 0x2, 0x2, 0x86, 0x88, 0x7, 0x13, 0x2, 0x2, 0x87, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8c, 0x7, 0x36, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x28, 0x15, 
    0x2, 0x8d, 0x8e, 0x7, 0x37, 0x2, 0x2, 0x8e, 0x90, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0x84, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x90, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x8, 0x3, 0x1, 0x2, 0x92, 0xb4, 0x5, 
    0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x36, 0x2, 0x2, 0x94, 0x95, 0x5, 0x52, 
    0x2a, 0x2, 0x95, 0x96, 0x7, 0x37, 0x2, 0x2, 0x96, 0x97, 0x7, 0x3a, 0x2, 
    0x2, 0x97, 0x98, 0x5, 0x5a, 0x2e, 0x2, 0x98, 0x99, 0x7, 0x3b, 0x2, 0x2, 
    0x99, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x36, 0x2, 0x2, 0x9b, 
    0x9c, 0x5, 0x52, 0x2a, 0x2, 0x9c, 0x9d, 0x7, 0x37, 0x2, 0x2, 0x9d, 0x9e, 
    0x7, 0x3a, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0x5a, 0x2e, 0x2, 0x9f, 0xa0, 0x7, 
    0x50, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x3b, 0x2, 0x2, 0xa1, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa3, 0x7, 0x3, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x36, 0x2, 
    0x2, 0xa4, 0xa5, 0x5, 0x52, 0x2a, 0x2, 0xa5, 0xa6, 0x7, 0x37, 0x2, 0x2, 
    0xa6, 0xa7, 0x7, 0x3a, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x5a, 0x2e, 0x2, 0xa8, 
    0xa9, 0x7, 0x3b, 0x2, 0x2, 0xa9, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 
    0x7, 0x3, 0x2, 0x2, 0xab, 0xac, 0x7, 0x36, 0x2, 0x2, 0xac, 0xad, 0x5, 
    0x52, 0x2a, 0x2, 0xad, 0xae, 0x7, 0x37, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x3a, 
    0x2, 0x2, 0xaf, 0xb0, 0x5, 0x5a, 0x2e, 0x2, 0xb0, 0xb1, 0x7, 0x50, 0x2, 
    0x2, 0xb1, 0xb2, 0x7, 0x3b, 0x2, 0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0x91, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x93, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0xc, 
    0xc, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x38, 0x2, 0x2, 0xb7, 0xb8, 0x5, 0x28, 
    0x15, 0x2, 0xb8, 0xb9, 0x7, 0x39, 0x2, 0x2, 0xb9, 0xcb, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0xbb, 0xc, 0xb, 0x2, 0x2, 0xbb, 0xbd, 0x7, 0x36, 0x2, 0x2, 
    0xbc, 0xbe, 0x5, 0x6, 0x4, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xcb, 
    0x7, 0x37, 0x2, 0x2, 0xc0, 0xc1, 0xc, 0xa, 0x2, 0x2, 0xc1, 0xc2, 0x7, 
    0x5e, 0x2, 0x2, 0xc2, 0xcb, 0x7, 0x65, 0x2, 0x2, 0xc3, 0xc4, 0xc, 0x9, 
    0x2, 0x2, 0xc4, 0xc5, 0x7, 0x5d, 0x2, 0x2, 0xc5, 0xcb, 0x7, 0x65, 0x2, 
    0x2, 0xc6, 0xc7, 0xc, 0x8, 0x2, 0x2, 0xc7, 0xcb, 0x7, 0x43, 0x2, 0x2, 
    0xc8, 0xc9, 0xc, 0x7, 0x2, 0x2, 0xc9, 0xcb, 0x7, 0x45, 0x2, 0x2, 0xca, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xca, 0xba, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xce, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0x5, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xd0, 0x8, 0x4, 0x1, 0x2, 0xd0, 0xd1, 0x5, 0x24, 0x13, 0x2, 0xd1, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0xc, 0x3, 0x2, 0x2, 0xd3, 0xd4, 
    0x7, 0x50, 0x2, 0x2, 0xd4, 0xd6, 0x5, 0x24, 0x13, 0x2, 0xd5, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xf1, 0x5, 0x4, 0x3, 0x2, 
    0xdb, 0xdc, 0x7, 0x43, 0x2, 0x2, 0xdc, 0xf1, 0x5, 0x8, 0x5, 0x2, 0xdd, 
    0xde, 0x7, 0x45, 0x2, 0x2, 0xde, 0xf1, 0x5, 0x8, 0x5, 0x2, 0xdf, 0xe0, 
    0x5, 0xa, 0x6, 0x2, 0xe0, 0xe1, 0x5, 0xc, 0x7, 0x2, 0xe1, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x2f, 0x2, 0x2, 0xe3, 0xf1, 0x5, 0x8, 
    0x5, 0x2, 0xe4, 0xe5, 0x7, 0x2f, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x36, 0x2, 
    0x2, 0xe6, 0xe7, 0x5, 0x52, 0x2a, 0x2, 0xe7, 0xe8, 0x7, 0x37, 0x2, 0x2, 
    0xe8, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x4, 0x2, 0x2, 0xea, 
    0xeb, 0x7, 0x36, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x52, 0x2a, 0x2, 0xec, 0xed, 
    0x7, 0x37, 0x2, 0x2, 0xed, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 
    0x5, 0x2, 0x2, 0xef, 0xf1, 0x7, 0x65, 0x2, 0x2, 0xf0, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xe2, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0x9, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 
    0x9, 0x2, 0x2, 0x2, 0xf3, 0xb, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x7, 
    0x36, 0x2, 0x2, 0xf5, 0xf6, 0x5, 0x52, 0x2a, 0x2, 0xf6, 0xf7, 0x7, 0x37, 
    0x2, 0x2, 0xf7, 0xf8, 0x5, 0xc, 0x7, 0x2, 0xf8, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xfa, 0x7, 0x3, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x36, 0x2, 0x2, 
    0xfb, 0xfc, 0x5, 0x52, 0x2a, 0x2, 0xfc, 0xfd, 0x7, 0x37, 0x2, 0x2, 0xfd, 
    0xfe, 0x5, 0xc, 0x7, 0x2, 0xfe, 0x102, 0x3, 0x2, 0x2, 0x2, 0xff, 0x102, 
    0x5, 0x8, 0x5, 0x2, 0x100, 0x102, 0x7, 0x12, 0x2, 0x2, 0x101, 0xf4, 
    0x3, 0x2, 0x2, 0x2, 0x101, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x103, 0x104, 0x8, 0x8, 0x1, 0x2, 0x104, 0x105, 0x5, 0xc, 
    0x7, 0x2, 0x105, 0x111, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0xc, 0x5, 
    0x2, 0x2, 0x107, 0x108, 0x7, 0x46, 0x2, 0x2, 0x108, 0x110, 0x5, 0xc, 
    0x7, 0x2, 0x109, 0x10a, 0xc, 0x4, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x47, 
    0x2, 0x2, 0x10b, 0x110, 0x5, 0xc, 0x7, 0x2, 0x10c, 0x10d, 0xc, 0x3, 
    0x2, 0x2, 0x10d, 0x10e, 0x7, 0x48, 0x2, 0x2, 0x10e, 0x110, 0x5, 0xc, 
    0x7, 0x2, 0x10f, 0x106, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x109, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x110, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0xf, 0x3, 0x2, 0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 
    0x2, 0x114, 0x115, 0x8, 0x9, 0x1, 0x2, 0x115, 0x116, 0x5, 0xe, 0x8, 
    0x2, 0x116, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0xc, 0x4, 0x2, 
    0x2, 0x118, 0x119, 0x7, 0x42, 0x2, 0x2, 0x119, 0x11e, 0x5, 0xe, 0x8, 
    0x2, 0x11a, 0x11b, 0xc, 0x3, 0x2, 0x2, 0x11b, 0x11c, 0x7, 0x44, 0x2, 
    0x2, 0x11c, 0x11e, 0x5, 0xe, 0x8, 0x2, 0x11d, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x11d, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x121, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 
    0x2, 0x120, 0x11, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 
    0x122, 0x123, 0x8, 0xa, 0x1, 0x2, 0x123, 0x124, 0x5, 0x10, 0x9, 0x2, 
    0x124, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0xc, 0x4, 0x2, 0x2, 
    0x126, 0x127, 0x7, 0x40, 0x2, 0x2, 0x127, 0x12c, 0x5, 0x10, 0x9, 0x2, 
    0x128, 0x129, 0xc, 0x3, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x41, 0x2, 0x2, 
    0x12a, 0x12c, 0x5, 0x10, 0x9, 0x2, 0x12b, 0x125, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x130, 
    0x131, 0x8, 0xb, 0x1, 0x2, 0x131, 0x132, 0x5, 0x12, 0xa, 0x2, 0x132, 
    0x141, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0xc, 0x6, 0x2, 0x2, 0x134, 
    0x135, 0x7, 0x3c, 0x2, 0x2, 0x135, 0x140, 0x5, 0x12, 0xa, 0x2, 0x136, 
    0x137, 0xc, 0x5, 0x2, 0x2, 0x137, 0x138, 0x7, 0x3e, 0x2, 0x2, 0x138, 
    0x140, 0x5, 0x12, 0xa, 0x2, 0x139, 0x13a, 0xc, 0x4, 0x2, 0x2, 0x13a, 
    0x13b, 0x7, 0x3d, 0x2, 0x2, 0x13b, 0x140, 0x5, 0x12, 0xa, 0x2, 0x13c, 
    0x13d, 0xc, 0x3, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x3f, 0x2, 0x2, 0x13e, 
    0x140, 0x5, 0x12, 0xa, 0x2, 0x13f, 0x133, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x136, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x13c, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 
    0x8, 0xc, 0x1, 0x2, 0x145, 0x146, 0x5, 0x14, 0xb, 0x2, 0x146, 0x155, 
    0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0xc, 0x6, 0x2, 0x2, 0x148, 0x149, 
    0x7, 0x7, 0x2, 0x2, 0x149, 0x154, 0x5, 0x14, 0xb, 0x2, 0x14a, 0x14b, 
    0xc, 0x5, 0x2, 0x2, 0x14b, 0x14c, 0x7, 0x8, 0x2, 0x2, 0x14c, 0x154, 
    0x5, 0x14, 0xb, 0x2, 0x14d, 0x14e, 0xc, 0x4, 0x2, 0x2, 0x14e, 0x14f, 
    0x7, 0x9, 0x2, 0x2, 0x14f, 0x154, 0x5, 0x14, 0xb, 0x2, 0x150, 0x151, 
    0xc, 0x3, 0x2, 0x2, 0x151, 0x152, 0x7, 0xa, 0x2, 0x2, 0x152, 0x154, 
    0x5, 0x14, 0xb, 0x2, 0x153, 0x147, 0x3, 0x2, 0x2, 0x2, 0x153, 0x14a, 
    0x3, 0x2, 0x2, 0x2, 0x153, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x153, 0x150, 
    0x3, 0x2, 0x2, 0x2, 0x154, 0x157, 0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 
    0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x8, 
    0xd, 0x1, 0x2, 0x159, 0x15a, 0x5, 0x16, 0xc, 0x2, 0x15a, 0x160, 0x3, 
    0x2, 0x2, 0x2, 0x15b, 0x15c, 0xc, 0x3, 0x2, 0x2, 0x15c, 0x15d, 0x7, 
    0x49, 0x2, 0x2, 0x15d, 0x15f, 0x5, 0x16, 0xc, 0x2, 0x15e, 0x15b, 0x3, 
    0x2, 0x2, 0x2, 0x15f, 0x162, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 0x3, 
    0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x8, 0xe, 
    0x1, 0x2, 0x164, 0x165, 0x5, 0x18, 0xd, 0x2, 0x165, 0x16b, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x167, 0xc, 0x3, 0x2, 0x2, 0x167, 0x168, 0x7, 0x4c, 
    0x2, 0x2, 0x168, 0x16a, 0x5, 0x18, 0xd, 0x2, 0x169, 0x166, 0x3, 0x2, 
    0x2, 0x2, 0x16a, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x169, 0x3, 0x2, 
    0x2, 0x2, 0x16b, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x8, 0xf, 0x1, 
    0x2, 0x16f, 0x170, 0x5, 0x1a, 0xe, 0x2, 0x170, 0x176, 0x3, 0x2, 0x2, 
    0x2, 0x171, 0x172, 0xc, 0x3, 0x2, 0x2, 0x172, 0x173, 0x7, 0x4a, 0x2, 
    0x2, 0x173, 0x175, 0x5, 0x1a, 0xe, 0x2, 0x174, 0x171, 0x3, 0x2, 0x2, 
    0x2, 0x175, 0x178, 0x3, 0x2, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 
    0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x8, 0x10, 0x1, 0x2, 
    0x17a, 0x17b, 0x5, 0x1c, 0xf, 0x2, 0x17b, 0x184, 0x3, 0x2, 0x2, 0x2, 
    0x17c, 0x17d, 0xc, 0x4, 0x2, 0x2, 0x17d, 0x17e, 0x7, 0x5, 0x2, 0x2, 
    0x17e, 0x183, 0x5, 0x1c, 0xf, 0x2, 0x17f, 0x180, 0xc, 0x3, 0x2, 0x2, 
    0x180, 0x181, 0x7, 0xb, 0x2, 0x2, 0x181, 0x183, 0x5, 0x1c, 0xf, 0x2, 
    0x182, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x182, 0x17f, 0x3, 0x2, 0x2, 0x2, 
    0x183, 0x186, 0x3, 0x2, 0x2, 0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 
    0x184, 0x185, 0x3, 0x2, 0x2, 0x2, 0x185, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x186, 
    0x184, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x8, 0x11, 0x1, 0x2, 0x188, 
    0x189, 0x5, 0x1e, 0x10, 0x2, 0x189, 0x192, 0x3, 0x2, 0x2, 0x2, 0x18a, 
    0x18b, 0xc, 0x4, 0x2, 0x2, 0x18b, 0x18c, 0x7, 0xc, 0x2, 0x2, 0x18c, 
    0x191, 0x5, 0x1e, 0x10, 0x2, 0x18d, 0x18e, 0xc, 0x3, 0x2, 0x2, 0x18e, 
    0x18f, 0x7, 0xd, 0x2, 0x2, 0x18f, 0x191, 0x5, 0x1e, 0x10, 0x2, 0x190, 
    0x18a, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x191, 
    0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 0x2, 0x192, 
    0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x21, 0x3, 0x2, 0x2, 0x2, 0x194, 0x192, 
    0x3, 0x2, 0x2, 0x2, 0x195, 0x19b, 0x5, 0x20, 0x11, 0x2, 0x196, 0x197, 
    0x7, 0x4d, 0x2, 0x2, 0x197, 0x198, 0x5, 0x28, 0x15, 0x2, 0x198, 0x199, 
    0x7, 0x4e, 0x2, 0x2, 0x199, 0x19a, 0x5, 0x22, 0x12, 0x2, 0x19a, 0x19c, 
    0x3, 0x2, 0x2, 0x2, 0x19b, 0x196, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 
    0x3, 0x2, 0x2, 0x2, 0x19c, 0x23, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a4, 0x5, 
    0x22, 0x12, 0x2, 0x19e, 0x19f, 0x5, 0x8, 0x5, 0x2, 0x19f, 0x1a0, 0x5, 
    0x26, 0x14, 0x2, 0x1a0, 0x1a1, 0x5, 0x24, 0x13, 0x2, 0x1a1, 0x1a4, 0x3, 
    0x2, 0x2, 0x2, 0x1a2, 0x1a4, 0x7, 0x12, 0x2, 0x2, 0x1a3, 0x19d, 0x3, 
    0x2, 0x2, 0x2, 0x1a3, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a2, 0x3, 
    0x2, 0x2, 0x2, 0x1a4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x9, 0x3, 
    0x2, 0x2, 0x1a6, 0x27, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x8, 0x15, 
    0x1, 0x2, 0x1a8, 0x1a9, 0x5, 0x24, 0x13, 0x2, 0x1a9, 0x1af, 0x3, 0x2, 
    0x2, 0x2, 0x1aa, 0x1ab, 0xc, 0x3, 0x2, 0x2, 0x1ab, 0x1ac, 0x7, 0x50, 
    0x2, 0x2, 0x1ac, 0x1ae, 0x5, 0x24, 0x13, 0x2, 0x1ad, 0x1aa, 0x3, 0x2, 
    0x2, 0x2, 0x1ae, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 0x3, 0x2, 
    0x2, 0x2, 0x1af, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x5, 0x22, 0x12, 
    0x2, 0x1b3, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x5, 0x2e, 0x18, 
    0x2, 0x1b5, 0x1b6, 0x5, 0x34, 0x1b, 0x2, 0x1b6, 0x1b7, 0x7, 0x4f, 0x2, 
    0x2, 0x1b7, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x5, 0x2e, 0x18, 
    0x2, 0x1b9, 0x1ba, 0x7, 0x4f, 0x2, 0x2, 0x1ba, 0x1bc, 0x3, 0x2, 0x2, 
    0x2, 0x1bb, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b8, 0x3, 0x2, 0x2, 
    0x2, 0x1bc, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bf, 0x5, 0x32, 0x1a, 
    0x2, 0x1be, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x3, 0x2, 0x2, 
    0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x3, 0x2, 0x2, 
    0x2, 0x1c1, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c4, 0x5, 0x32, 0x1a, 
    0x2, 0x1c3, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 
    0x2, 0x1c5, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x3, 0x2, 0x2, 
    0x2, 0x1c6, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1cb, 0x5, 0x38, 0x1d, 
    0x2, 0x1c8, 0x1cb, 0x5, 0x3a, 0x1e, 0x2, 0x1c9, 0x1cb, 0x5, 0x3e, 0x20, 
    0x2, 0x1ca, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c8, 0x3, 0x2, 0x2, 
    0x2, 0x1ca, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x1cc, 0x1cd, 0x8, 0x1b, 0x1, 0x2, 0x1cd, 0x1ce, 0x5, 0x36, 0x1c, 0x2, 
    0x1ce, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0xc, 0x3, 0x2, 0x2, 
    0x1d0, 0x1d1, 0x7, 0x50, 0x2, 0x2, 0x1d1, 0x1d3, 0x5, 0x36, 0x1c, 0x2, 
    0x1d2, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d6, 0x3, 0x2, 0x2, 0x2, 
    0x1d4, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 0x3, 0x2, 0x2, 0x2, 
    0x1d5, 0x35, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
    0x1dd, 0x5, 0x40, 0x21, 0x2, 0x1d8, 0x1d9, 0x5, 0x40, 0x21, 0x2, 0x1d9, 
    0x1da, 0x7, 0x51, 0x2, 0x2, 0x1da, 0x1db, 0x5, 0x58, 0x2d, 0x2, 0x1db, 
    0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1dc, 
    0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 
    0x9, 0x4, 0x2, 0x2, 0x1df, 0x39, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x9, 
    0x5, 0x2, 0x2, 0x1e1, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e4, 0x5, 0x3a, 
    0x1e, 0x2, 0x1e3, 0x1e5, 0x5, 0x3c, 0x1f, 0x2, 0x1e4, 0x1e3, 0x3, 0x2, 
    0x2, 0x2, 0x1e4, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1eb, 0x3, 0x2, 
    0x2, 0x2, 0x1e6, 0x1e8, 0x5, 0x3e, 0x20, 0x2, 0x1e7, 0x1e9, 0x5, 0x3c, 
    0x1f, 0x2, 0x1e8, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x3, 0x2, 
    0x2, 0x2, 0x1e9, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1e2, 0x3, 0x2, 
    0x2, 0x2, 0x1ea, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x1ec, 0x1ed, 0x7, 0x1e, 0x2, 0x2, 0x1ed, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x1ee, 0x1f0, 0x5, 0x46, 0x24, 0x2, 0x1ef, 0x1ee, 0x3, 0x2, 0x2, 
    0x2, 0x1ef, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0x3, 0x2, 0x2, 
    0x2, 0x1f1, 0x1f2, 0x5, 0x42, 0x22, 0x2, 0x1f2, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x1f3, 0x1f4, 0x8, 0x22, 0x1, 0x2, 0x1f4, 0x205, 0x7, 0x65, 0x2, 
    0x2, 0x1f5, 0x1f6, 0x7, 0x36, 0x2, 0x2, 0x1f6, 0x1f7, 0x5, 0x40, 0x21, 
    0x2, 0x1f7, 0x1f8, 0x7, 0x37, 0x2, 0x2, 0x1f8, 0x205, 0x3, 0x2, 0x2, 
    0x2, 0x1f9, 0x1fa, 0x7, 0x65, 0x2, 0x2, 0x1fa, 0x1fb, 0x7, 0x4e, 0x2, 
    0x2, 0x1fb, 0x205, 0x7, 0x12, 0x2, 0x2, 0x1fc, 0x1fe, 0x7, 0x36, 0x2, 
    0x2, 0x1fd, 0x1ff, 0x5, 0x3a, 0x1e, 0x2, 0x1fe, 0x1fd, 0x3, 0x2, 0x2, 
    0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 0x3, 0x2, 0x2, 
    0x2, 0x200, 0x201, 0x5, 0x46, 0x24, 0x2, 0x201, 0x202, 0x5, 0x42, 0x22, 
    0x2, 0x202, 0x203, 0x7, 0x37, 0x2, 0x2, 0x203, 0x205, 0x3, 0x2, 0x2, 
    0x2, 0x204, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x204, 0x1f5, 0x3, 0x2, 0x2, 
    0x2, 0x204, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x204, 0x1fc, 0x3, 0x2, 0x2, 
    0x2, 0x205, 0x233, 0x3, 0x2, 0x2, 0x2, 0x206, 0x207, 0xc, 0xa, 0x2, 
    0x2, 0x207, 0x209, 0x7, 0x38, 0x2, 0x2, 0x208, 0x20a, 0x5, 0x48, 0x25, 
    0x2, 0x209, 0x208, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 0x2, 
    0x2, 0x20a, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20d, 0x5, 0x24, 0x13, 
    0x2, 0x20c, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x3, 0x2, 0x2, 
    0x2, 0x20d, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x232, 0x7, 0x39, 0x2, 
    0x2, 0x20f, 0x210, 0xc, 0x9, 0x2, 0x2, 0x210, 0x211, 0x7, 0x38, 0x2, 
    0x2, 0x211, 0x213, 0x7, 0x30, 0x2, 0x2, 0x212, 0x214, 0x5, 0x48, 0x25, 
    0x2, 0x213, 0x212, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x3, 0x2, 0x2, 
    0x2, 0x214, 0x215, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x5, 0x24, 0x13, 
    0x2, 0x216, 0x217, 0x7, 0x39, 0x2, 0x2, 0x217, 0x232, 0x3, 0x2, 0x2, 
    0x2, 0x218, 0x219, 0xc, 0x8, 0x2, 0x2, 0x219, 0x21a, 0x7, 0x38, 0x2, 
    0x2, 0x21a, 0x21b, 0x5, 0x48, 0x25, 0x2, 0x21b, 0x21c, 0x7, 0x30, 0x2, 
    0x2, 0x21c, 0x21d, 0x5, 0x24, 0x13, 0x2, 0x21d, 0x21e, 0x7, 0x39, 0x2, 
    0x2, 0x21e, 0x232, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 0xc, 0x7, 0x2, 
    0x2, 0x220, 0x222, 0x7, 0x38, 0x2, 0x2, 0x221, 0x223, 0x5, 0x48, 0x25, 
    0x2, 0x222, 0x221, 0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x3, 0x2, 0x2, 
    0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x7, 0x46, 0x2, 
    0x2, 0x225, 0x232, 0x7, 0x39, 0x2, 0x2, 0x226, 0x227, 0xc, 0x6, 0x2, 
    0x2, 0x227, 0x228, 0x7, 0x36, 0x2, 0x2, 0x228, 0x229, 0x5, 0x4a, 0x26, 
    0x2, 0x229, 0x22a, 0x7, 0x37, 0x2, 0x2, 0x22a, 0x232, 0x3, 0x2, 0x2, 
    0x2, 0x22b, 0x22c, 0xc, 0x5, 0x2, 0x2, 0x22c, 0x22e, 0x7, 0x36, 0x2, 
    0x2, 0x22d, 0x22f, 0x5, 0x50, 0x29, 0x2, 0x22e, 0x22d, 0x3, 0x2, 0x2, 
    0x2, 0x22e, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 
    0x2, 0x230, 0x232, 0x7, 0x37, 0x2, 0x2, 0x231, 0x206, 0x3, 0x2, 0x2, 
    0x2, 0x231, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x218, 0x3, 0x2, 0x2, 
    0x2, 0x231, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x226, 0x3, 0x2, 0x2, 
    0x2, 0x231, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x232, 0x235, 0x3, 0x2, 0x2, 
    0x2, 0x233, 0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 0x2, 
    0x2, 0x234, 0x43, 0x3, 0x2, 0x2, 0x2, 0x235, 0x233, 0x3, 0x2, 0x2, 0x2, 
    0x236, 0x23c, 0xa, 0x6, 0x2, 0x2, 0x237, 0x238, 0x7, 0x36, 0x2, 0x2, 
    0x238, 0x239, 0x5, 0x44, 0x23, 0x2, 0x239, 0x23a, 0x7, 0x37, 0x2, 0x2, 
    0x23a, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x236, 0x3, 0x2, 0x2, 0x2, 
    0x23b, 0x237, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23f, 0x3, 0x2, 0x2, 0x2, 
    0x23d, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23e, 0x3, 0x2, 0x2, 0x2, 
    0x23e, 0x45, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x240, 
    0x242, 0x7, 0x46, 0x2, 0x2, 0x241, 0x243, 0x5, 0x48, 0x25, 0x2, 0x242, 
    0x241, 0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 0x3, 0x2, 0x2, 0x2, 0x243, 
    0x253, 0x3, 0x2, 0x2, 0x2, 0x244, 0x246, 0x7, 0x46, 0x2, 0x2, 0x245, 
    0x247, 0x5, 0x48, 0x25, 0x2, 0x246, 0x245, 0x3, 0x2, 0x2, 0x2, 0x246, 
    0x247, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 0x3, 0x2, 0x2, 0x2, 0x248, 
    0x253, 0x5, 0x46, 0x24, 0x2, 0x249, 0x24b, 0x7, 0x4c, 0x2, 0x2, 0x24a, 
    0x24c, 0x5, 0x48, 0x25, 0x2, 0x24b, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24b, 
    0x24c, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x253, 0x3, 0x2, 0x2, 0x2, 0x24d, 
    0x24f, 0x7, 0x4c, 0x2, 0x2, 0x24e, 0x250, 0x5, 0x48, 0x25, 0x2, 0x24f, 
    0x24e, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x3, 0x2, 0x2, 0x2, 0x250, 
    0x251, 0x3, 0x2, 0x2, 0x2, 0x251, 0x253, 0x5, 0x46, 0x24, 0x2, 0x252, 
    0x240, 0x3, 0x2, 0x2, 0x2, 0x252, 0x244, 0x3, 0x2, 0x2, 0x2, 0x252, 
    0x249, 0x3, 0x2, 0x2, 0x2, 0x252, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x253, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x8, 0x25, 0x1, 0x2, 0x255, 
    0x256, 0x5, 0x3e, 0x20, 0x2, 0x256, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x257, 
    0x258, 0xc, 0x3, 0x2, 0x2, 0x258, 0x25a, 0x5, 0x3e, 0x20, 0x2, 0x259, 
    0x257, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25b, 
    0x259, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25c, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x264, 
    0x5, 0x4c, 0x27, 0x2, 0x25f, 0x260, 0x5, 0x4c, 0x27, 0x2, 0x260, 0x261, 
    0x7, 0x50, 0x2, 0x2, 0x261, 0x262, 0x7, 0x5f, 0x2, 0x2, 0x262, 0x264, 
    0x3, 0x2, 0x2, 0x2, 0x263, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x263, 0x25f, 
    0x3, 0x2, 0x2, 0x2, 0x264, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 0x8, 
    0x27, 0x1, 0x2, 0x266, 0x267, 0x5, 0x4e, 0x28, 0x2, 0x267, 0x26d, 0x3, 
    0x2, 0x2, 0x2, 0x268, 0x269, 0xc, 0x3, 0x2, 0x2, 0x269, 0x26a, 0x7, 
    0x50, 0x2, 0x2, 0x26a, 0x26c, 0x5, 0x4e, 0x28, 0x2, 0x26b, 0x268, 0x3, 
    0x2, 0x2, 0x2, 0x26c, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26b, 0x3, 
    0x2, 0x2, 0x2, 0x26d, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x26f, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x270, 0x271, 0x5, 0x2e, 
    0x18, 0x2, 0x271, 0x272, 0x5, 0x40, 0x21, 0x2, 0x272, 0x278, 0x3, 0x2, 
    0x2, 0x2, 0x273, 0x275, 0x5, 0x30, 0x19, 0x2, 0x274, 0x276, 0x5, 0x54, 
    0x2b, 0x2, 0x275, 0x274, 0x3, 0x2, 0x2, 0x2, 0x275, 0x276, 0x3, 0x2, 
    0x2, 0x2, 0x276, 0x278, 0x3, 0x2, 0x2, 0x2, 0x277, 0x270, 0x3, 0x2, 
    0x2, 0x2, 0x277, 0x273, 0x3, 0x2, 0x2, 0x2, 0x278, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x279, 0x27a, 0x8, 0x29, 0x1, 0x2, 0x27a, 0x27b, 0x7, 0x65, 0x2, 
    0x2, 0x27b, 0x281, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0xc, 0x3, 0x2, 
    0x2, 0x27d, 0x27e, 0x7, 0x50, 0x2, 0x2, 0x27e, 0x280, 0x7, 0x65, 0x2, 
    0x2, 0x27f, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x280, 0x283, 0x3, 0x2, 0x2, 
    0x2, 0x281, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x3, 0x2, 0x2, 
    0x2, 0x282, 0x51, 0x3, 0x2, 0x2, 0x2, 0x283, 0x281, 0x3, 0x2, 0x2, 0x2, 
    0x284, 0x286, 0x5, 0x3c, 0x1f, 0x2, 0x285, 0x287, 0x5, 0x54, 0x2b, 0x2, 
    0x286, 0x285, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 0x3, 0x2, 0x2, 0x2, 
    0x287, 0x53, 0x3, 0x2, 0x2, 0x2, 0x288, 0x28e, 0x5, 0x46, 0x24, 0x2, 
    0x289, 0x28b, 0x5, 0x46, 0x24, 0x2, 0x28a, 0x289, 0x3, 0x2, 0x2, 0x2, 
    0x28a, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28c, 0x3, 0x2, 0x2, 0x2, 
    0x28c, 0x28e, 0x5, 0x56, 0x2c, 0x2, 0x28d, 0x288, 0x3, 0x2, 0x2, 0x2, 
    0x28d, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x55, 0x3, 0x2, 0x2, 0x2, 0x28f, 
    0x290, 0x8, 0x2c, 0x1, 0x2, 0x290, 0x291, 0x7, 0x36, 0x2, 0x2, 0x291, 
    0x292, 0x5, 0x54, 0x2b, 0x2, 0x292, 0x293, 0x7, 0x37, 0x2, 0x2, 0x293, 
    0x2b3, 0x3, 0x2, 0x2, 0x2, 0x294, 0x296, 0x7, 0x38, 0x2, 0x2, 0x295, 
    0x297, 0x5, 0x48, 0x25, 0x2, 0x296, 0x295, 0x3, 0x2, 0x2, 0x2, 0x296, 
    0x297, 0x3, 0x2, 0x2, 0x2, 0x297, 0x299, 0x3, 0x2, 0x2, 0x2, 0x298, 
    0x29a, 0x5, 0x24, 0x13, 0x2, 0x299, 0x298, 0x3, 0x2, 0x2, 0x2, 0x299, 
    0x29a, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29b, 
    0x2b3, 0x7, 0x39, 0x2, 0x2, 0x29c, 0x29d, 0x7, 0x38, 0x2, 0x2, 0x29d, 
    0x29f, 0x7, 0x30, 0x2, 0x2, 0x29e, 0x2a0, 0x5, 0x48, 0x25, 0x2, 0x29f, 
    0x29e, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
    0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x5, 0x24, 0x13, 0x2, 0x2a2, 
    0x2a3, 0x7, 0x39, 0x2, 0x2, 0x2a3, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2a4, 
    0x2a5, 0x7, 0x38, 0x2, 0x2, 0x2a5, 0x2a6, 0x5, 0x48, 0x25, 0x2, 0x2a6, 
    0x2a7, 0x7, 0x30, 0x2, 0x2, 0x2a7, 0x2a8, 0x5, 0x24, 0x13, 0x2, 0x2a8, 
    0x2a9, 0x7, 0x39, 0x2, 0x2, 0x2a9, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2aa, 
    0x2ab, 0x7, 0x38, 0x2, 0x2, 0x2ab, 0x2ac, 0x7, 0x46, 0x2, 0x2, 0x2ac, 
    0x2b3, 0x7, 0x39, 0x2, 0x2, 0x2ad, 0x2af, 0x7, 0x36, 0x2, 0x2, 0x2ae, 
    0x2b0, 0x5, 0x4a, 0x26, 0x2, 0x2af, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2af, 
    0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b1, 
    0x2b3, 0x7, 0x37, 0x2, 0x2, 0x2b2, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x2b2, 
    0x294, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x2b2, 
    0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2b2, 
    0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2b4, 
    0x2b5, 0xc, 0x7, 0x2, 0x2, 0x2b5, 0x2b7, 0x7, 0x38, 0x2, 0x2, 0x2b6, 
    0x2b8, 0x5, 0x48, 0x25, 0x2, 0x2b7, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b7, 
    0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2b9, 
    0x2bb, 0x5, 0x24, 0x13, 0x2, 0x2ba, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2ba, 
    0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2bc, 
    0x2d8, 0x7, 0x39, 0x2, 0x2, 0x2bd, 0x2be, 0xc, 0x6, 0x2, 0x2, 0x2be, 
    0x2bf, 0x7, 0x38, 0x2, 0x2, 0x2bf, 0x2c1, 0x7, 0x30, 0x2, 0x2, 0x2c0, 
    0x2c2, 0x5, 0x48, 0x25, 0x2, 0x2c1, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c1, 
    0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c3, 
    0x2c4, 0x5, 0x24, 0x13, 0x2, 0x2c4, 0x2c5, 0x7, 0x39, 0x2, 0x2, 0x2c5, 
    0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c7, 0xc, 0x5, 0x2, 0x2, 0x2c7, 
    0x2c8, 0x7, 0x38, 0x2, 0x2, 0x2c8, 0x2c9, 0x5, 0x48, 0x25, 0x2, 0x2c9, 
    0x2ca, 0x7, 0x30, 0x2, 0x2, 0x2ca, 0x2cb, 0x5, 0x24, 0x13, 0x2, 0x2cb, 
    0x2cc, 0x7, 0x39, 0x2, 0x2, 0x2cc, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2cd, 
    0x2ce, 0xc, 0x4, 0x2, 0x2, 0x2ce, 0x2cf, 0x7, 0x38, 0x2, 0x2, 0x2cf, 
    0x2d0, 0x7, 0x46, 0x2, 0x2, 0x2d0, 0x2d8, 0x7, 0x39, 0x2, 0x2, 0x2d1, 
    0x2d2, 0xc, 0x3, 0x2, 0x2, 0x2d2, 0x2d4, 0x7, 0x36, 0x2, 0x2, 0x2d3, 
    0x2d5, 0x5, 0x4a, 0x26, 0x2, 0x2d4, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d4, 
    0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d6, 
    0x2d8, 0x7, 0x37, 0x2, 0x2, 0x2d7, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2d7, 
    0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2d7, 
    0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d8, 
    0x2db, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d9, 
    0x2da, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x57, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2d9, 
    0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2e7, 0x5, 0x24, 0x13, 0x2, 0x2dd, 0x2de, 
    0x7, 0x3a, 0x2, 0x2, 0x2de, 0x2df, 0x5, 0x5a, 0x2e, 0x2, 0x2df, 0x2e0, 
    0x7, 0x3b, 0x2, 0x2, 0x2e0, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 
    0x7, 0x3a, 0x2, 0x2, 0x2e2, 0x2e3, 0x5, 0x5a, 0x2e, 0x2, 0x2e3, 0x2e4, 
    0x7, 0x50, 0x2, 0x2, 0x2e4, 0x2e5, 0x7, 0x3b, 0x2, 0x2, 0x2e5, 0x2e7, 
    0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2dd, 
    0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x2e8, 0x2ea, 0x8, 0x2e, 0x1, 0x2, 0x2e9, 0x2eb, 0x5, 
    0x5c, 0x2f, 0x2, 0x2ea, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 0x3, 
    0x2, 0x2, 0x2, 0x2eb, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ed, 0x5, 
    0x58, 0x2d, 0x2, 0x2ed, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 0xc, 
    0x3, 0x2, 0x2, 0x2ef, 0x2f1, 0x7, 0x50, 0x2, 0x2, 0x2f0, 0x2f2, 0x5, 
    0x5c, 0x2f, 0x2, 0x2f1, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 0x3, 
    0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f5, 0x5, 
    0x58, 0x2d, 0x2, 0x2f4, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f8, 0x3, 
    0x2, 0x2, 0x2, 0x2f6, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 0x3, 
    0x2, 0x2, 0x2, 0x2f7, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f6, 0x3, 0x2, 
    0x2, 0x2, 0x2f9, 0x2fa, 0x5, 0x5e, 0x30, 0x2, 0x2fa, 0x2fb, 0x7, 0x51, 
    0x2, 0x2, 0x2fb, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x8, 0x30, 
    0x1, 0x2, 0x2fd, 0x2fe, 0x5, 0x60, 0x31, 0x2, 0x2fe, 0x303, 0x3, 0x2, 
    0x2, 0x2, 0x2ff, 0x300, 0xc, 0x3, 0x2, 0x2, 0x300, 0x302, 0x5, 0x60, 
    0x31, 0x2, 0x301, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x302, 0x305, 0x3, 0x2, 
    0x2, 0x2, 0x303, 0x301, 0x3, 0x2, 0x2, 0x2, 0x303, 0x304, 0x3, 0x2, 
    0x2, 0x2, 0x304, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x305, 0x303, 0x3, 0x2, 0x2, 
    0x2, 0x306, 0x307, 0x7, 0x38, 0x2, 0x2, 0x307, 0x308, 0x5, 0x2a, 0x16, 
    0x2, 0x308, 0x309, 0x7, 0x39, 0x2, 0x2, 0x309, 0x30d, 0x3, 0x2, 0x2, 
    0x2, 0x30a, 0x30b, 0x7, 0x5e, 0x2, 0x2, 0x30b, 0x30d, 0x7, 0x65, 0x2, 
    0x2, 0x30c, 0x306, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30a, 0x3, 0x2, 0x2, 
    0x2, 0x30d, 0x61, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x315, 0x5, 0x64, 0x33, 
    0x2, 0x30f, 0x315, 0x5, 0x66, 0x34, 0x2, 0x310, 0x315, 0x5, 0x6c, 0x37, 
    0x2, 0x311, 0x315, 0x5, 0x6e, 0x38, 0x2, 0x312, 0x315, 0x5, 0x70, 0x39, 
    0x2, 0x313, 0x315, 0x5, 0x78, 0x3d, 0x2, 0x314, 0x30e, 0x3, 0x2, 0x2, 
    0x2, 0x314, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x314, 0x310, 0x3, 0x2, 0x2, 
    0x2, 0x314, 0x311, 0x3, 0x2, 0x2, 0x2, 0x314, 0x312, 0x3, 0x2, 0x2, 
    0x2, 0x314, 0x313, 0x3, 0x2, 0x2, 0x2, 0x315, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x316, 0x317, 0x7, 0x65, 0x2, 0x2, 0x317, 0x318, 0x7, 0x4e, 0x2, 0x2, 
    0x318, 0x322, 0x5, 0x62, 0x32, 0x2, 0x319, 0x31a, 0x7, 0x1c, 0x2, 0x2, 
    0x31a, 0x31b, 0x5, 0x2a, 0x16, 0x2, 0x31b, 0x31c, 0x7, 0x4e, 0x2, 0x2, 
    0x31c, 0x31d, 0x5, 0x62, 0x32, 0x2, 0x31d, 0x322, 0x3, 0x2, 0x2, 0x2, 
    0x31e, 0x31f, 0x7, 0x21, 0x2, 0x2, 0x31f, 0x320, 0x7, 0x4e, 0x2, 0x2, 
    0x320, 0x322, 0x5, 0x62, 0x32, 0x2, 0x321, 0x316, 0x3, 0x2, 0x2, 0x2, 
    0x321, 0x319, 0x3, 0x2, 0x2, 0x2, 0x321, 0x31e, 0x3, 0x2, 0x2, 0x2, 
    0x322, 0x65, 0x3, 0x2, 0x2, 0x2, 0x323, 0x325, 0x7, 0x3a, 0x2, 0x2, 
    0x324, 0x326, 0x5, 0x68, 0x35, 0x2, 0x325, 0x324, 0x3, 0x2, 0x2, 0x2, 
    0x325, 0x326, 0x3, 0x2, 0x2, 0x2, 0x326, 0x327, 0x3, 0x2, 0x2, 0x2, 
    0x327, 0x328, 0x7, 0x3b, 0x2, 0x2, 0x328, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x329, 0x32a, 0x8, 0x35, 0x1, 0x2, 0x32a, 0x32b, 0x5, 0x6a, 0x36, 0x2, 
    0x32b, 0x330, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32d, 0xc, 0x3, 0x2, 0x2, 
    0x32d, 0x32f, 0x5, 0x6a, 0x36, 0x2, 0x32e, 0x32c, 0x3, 0x2, 0x2, 0x2, 
    0x32f, 0x332, 0x3, 0x2, 0x2, 0x2, 0x330, 0x32e, 0x3, 0x2, 0x2, 0x2, 
    0x330, 0x331, 0x3, 0x2, 0x2, 0x2, 0x331, 0x69, 0x3, 0x2, 0x2, 0x2, 0x332, 
    0x330, 0x3, 0x2, 0x2, 0x2, 0x333, 0x336, 0x5, 0x62, 0x32, 0x2, 0x334, 
    0x336, 0x5, 0x2c, 0x17, 0x2, 0x335, 0x333, 0x3, 0x2, 0x2, 0x2, 0x335, 
    0x334, 0x3, 0x2, 0x2, 0x2, 0x336, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x337, 0x339, 
    0x5, 0x28, 0x15, 0x2, 0x338, 0x337, 0x3, 0x2, 0x2, 0x2, 0x338, 0x339, 
    0x3, 0x2, 0x2, 0x2, 0x339, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x33b, 
    0x7, 0x4f, 0x2, 0x2, 0x33b, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33d, 
    0x7, 0x27, 0x2, 0x2, 0x33d, 0x33e, 0x7, 0x36, 0x2, 0x2, 0x33e, 0x33f, 
    0x5, 0x28, 0x15, 0x2, 0x33f, 0x340, 0x7, 0x37, 0x2, 0x2, 0x340, 0x343, 
    0x5, 0x62, 0x32, 0x2, 0x341, 0x342, 0x7, 0x23, 0x2, 0x2, 0x342, 0x344, 
    0x5, 0x62, 0x32, 0x2, 0x343, 0x341, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 
    0x3, 0x2, 0x2, 0x2, 0x344, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x345, 0x346, 
    0x7, 0x31, 0x2, 0x2, 0x346, 0x347, 0x7, 0x36, 0x2, 0x2, 0x347, 0x348, 
    0x5, 0x28, 0x15, 0x2, 0x348, 0x349, 0x7, 0x37, 0x2, 0x2, 0x349, 0x34a, 
    0x5, 0x62, 0x32, 0x2, 0x34a, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x33c, 
    0x3, 0x2, 0x2, 0x2, 0x34b, 0x345, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x34d, 0x34e, 0x7, 0x35, 0x2, 0x2, 0x34e, 0x34f, 0x7, 
    0x36, 0x2, 0x2, 0x34f, 0x350, 0x5, 0x28, 0x15, 0x2, 0x350, 0x351, 0x7, 
    0x37, 0x2, 0x2, 0x351, 0x352, 0x5, 0x62, 0x32, 0x2, 0x352, 0x35a, 0x3, 
    0x2, 0x2, 0x2, 0x353, 0x354, 0x7, 0x26, 0x2, 0x2, 0x354, 0x355, 0x7, 
    0x36, 0x2, 0x2, 0x355, 0x356, 0x5, 0x72, 0x3a, 0x2, 0x356, 0x357, 0x7, 
    0x37, 0x2, 0x2, 0x357, 0x358, 0x5, 0x62, 0x32, 0x2, 0x358, 0x35a, 0x3, 
    0x2, 0x2, 0x2, 0x359, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x359, 0x353, 0x3, 
    0x2, 0x2, 0x2, 0x35a, 0x71, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35c, 0x5, 0x74, 
    0x3b, 0x2, 0x35c, 0x35e, 0x7, 0x4f, 0x2, 0x2, 0x35d, 0x35f, 0x5, 0x76, 
    0x3c, 0x2, 0x35e, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35f, 0x3, 0x2, 
    0x2, 0x2, 0x35f, 0x360, 0x3, 0x2, 0x2, 0x2, 0x360, 0x362, 0x7, 0x4f, 
    0x2, 0x2, 0x361, 0x363, 0x5, 0x76, 0x3c, 0x2, 0x362, 0x361, 0x3, 0x2, 
    0x2, 0x2, 0x362, 0x363, 0x3, 0x2, 0x2, 0x2, 0x363, 0x370, 0x3, 0x2, 
    0x2, 0x2, 0x364, 0x366, 0x5, 0x28, 0x15, 0x2, 0x365, 0x364, 0x3, 0x2, 
    0x2, 0x2, 0x365, 0x366, 0x3, 0x2, 0x2, 0x2, 0x366, 0x367, 0x3, 0x2, 
    0x2, 0x2, 0x367, 0x369, 0x7, 0x4f, 0x2, 0x2, 0x368, 0x36a, 0x5, 0x76, 
    0x3c, 0x2, 0x369, 0x368, 0x3, 0x2, 0x2, 0x2, 0x369, 0x36a, 0x3, 0x2, 
    0x2, 0x2, 0x36a, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36d, 0x7, 0x4f, 
    0x2, 0x2, 0x36c, 0x36e, 0x5, 0x76, 0x3c, 0x2, 0x36d, 0x36c, 0x3, 0x2, 
    0x2, 0x2, 0x36d, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x370, 0x3, 0x2, 
    0x2, 0x2, 0x36f, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x365, 0x3, 0x2, 
    0x2, 0x2, 0x370, 0x73, 0x3, 0x2, 0x2, 0x2, 0x371, 0x372, 0x5, 0x2e, 
    0x18, 0x2, 0x372, 0x373, 0x5, 0x34, 0x1b, 0x2, 0x373, 0x376, 0x3, 0x2, 
    0x2, 0x2, 0x374, 0x376, 0x5, 0x2e, 0x18, 0x2, 0x375, 0x371, 0x3, 0x2, 
    0x2, 0x2, 0x375, 0x374, 0x3, 0x2, 0x2, 0x2, 0x376, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x377, 0x378, 0x8, 0x3c, 0x1, 0x2, 0x378, 0x379, 0x5, 0x24, 0x13, 
    0x2, 0x379, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37b, 0xc, 0x3, 0x2, 
    0x2, 0x37b, 0x37c, 0x7, 0x50, 0x2, 0x2, 0x37c, 0x37e, 0x5, 0x24, 0x13, 
    0x2, 0x37d, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x381, 0x3, 0x2, 0x2, 
    0x2, 0x37f, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 0x3, 0x2, 0x2, 
    0x2, 0x380, 0x77, 0x3, 0x2, 0x2, 0x2, 0x381, 0x37f, 0x3, 0x2, 0x2, 0x2, 
    0x382, 0x383, 0x7, 0x10, 0x2, 0x2, 0x383, 0x384, 0x7, 0x65, 0x2, 0x2, 
    0x384, 0x393, 0x7, 0x4f, 0x2, 0x2, 0x385, 0x386, 0x7, 0x1f, 0x2, 0x2, 
    0x386, 0x393, 0x7, 0x4f, 0x2, 0x2, 0x387, 0x388, 0x7, 0x1b, 0x2, 0x2, 
    0x388, 0x393, 0x7, 0x4f, 0x2, 0x2, 0x389, 0x38b, 0x7, 0x2c, 0x2, 0x2, 
    0x38a, 0x38c, 0x5, 0x28, 0x15, 0x2, 0x38b, 0x38a, 0x3, 0x2, 0x2, 0x2, 
    0x38b, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38d, 0x3, 0x2, 0x2, 0x2, 
    0x38d, 0x393, 0x7, 0x4f, 0x2, 0x2, 0x38e, 0x38f, 0x7, 0x10, 0x2, 0x2, 
    0x38f, 0x390, 0x5, 0x8, 0x5, 0x2, 0x390, 0x391, 0x7, 0x4f, 0x2, 0x2, 
    0x391, 0x393, 0x3, 0x2, 0x2, 0x2, 0x392, 0x382, 0x3, 0x2, 0x2, 0x2, 
    0x392, 0x385, 0x3, 0x2, 0x2, 0x2, 0x392, 0x387, 0x3, 0x2, 0x2, 0x2, 
    0x392, 0x389, 0x3, 0x2, 0x2, 0x2, 0x392, 0x38e, 0x3, 0x2, 0x2, 0x2, 
    0x393, 0x79, 0x3, 0x2, 0x2, 0x2, 0x394, 0x396, 0x5, 0x7c, 0x3f, 0x2, 
    0x395, 0x394, 0x3, 0x2, 0x2, 0x2, 0x395, 0x396, 0x3, 0x2, 0x2, 0x2, 
    0x396, 0x397, 0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 0x7, 0x2, 0x2, 0x3, 
    0x398, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x399, 0x39a, 0x8, 0x3f, 0x1, 0x2, 
    0x39a, 0x39b, 0x5, 0x7e, 0x40, 0x2, 0x39b, 0x3a0, 0x3, 0x2, 0x2, 0x2, 
    0x39c, 0x39d, 0xc, 0x3, 0x2, 0x2, 0x39d, 0x39f, 0x5, 0x7e, 0x40, 0x2, 
    0x39e, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a2, 0x3, 0x2, 0x2, 0x2, 
    0x3a0, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x3a1, 0x3, 0x2, 0x2, 0x2, 
    0x3a1, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x3a2, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a3, 
    0x3a7, 0x5, 0x80, 0x41, 0x2, 0x3a4, 0x3a7, 0x5, 0x2c, 0x17, 0x2, 0x3a5, 
    0x3a7, 0x7, 0x4f, 0x2, 0x2, 0x3a6, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a6, 
    0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a7, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3aa, 0x5, 0x2e, 0x18, 0x2, 0x3a9, 
    0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3aa, 
    0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3ad, 0x5, 0x40, 0x21, 0x2, 0x3ac, 
    0x3ae, 0x5, 0x82, 0x42, 0x2, 0x3ad, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ad, 
    0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x3af, 
    0x3b0, 0x5, 0x66, 0x34, 0x2, 0x3b0, 0x81, 0x3, 0x2, 0x2, 0x2, 0x3b1, 
    0x3b2, 0x8, 0x42, 0x1, 0x2, 0x3b2, 0x3b3, 0x5, 0x2c, 0x17, 0x2, 0x3b3, 
    0x3b8, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b5, 0xc, 0x3, 0x2, 0x2, 0x3b5, 
    0x3b7, 0x5, 0x2c, 0x17, 0x2, 0x3b6, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b7, 
    0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b8, 
    0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b9, 0x83, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3b8, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x89, 0x8f, 0xb3, 0xbd, 0xca, 0xcc, 0xd7, 
    0xf0, 0x101, 0x10f, 0x111, 0x11d, 0x11f, 0x12b, 0x12d, 0x13f, 0x141, 
    0x153, 0x155, 0x160, 0x16b, 0x176, 0x182, 0x184, 0x190, 0x192, 0x19b, 
    0x1a3, 0x1af, 0x1bb, 0x1c0, 0x1c5, 0x1ca, 0x1d4, 0x1dc, 0x1e4, 0x1e8, 
    0x1ea, 0x1ef, 0x1fe, 0x204, 0x209, 0x20c, 0x213, 0x222, 0x22e, 0x231, 
    0x233, 0x23b, 0x23d, 0x242, 0x246, 0x24b, 0x24f, 0x252, 0x25b, 0x263, 
    0x26d, 0x275, 0x277, 0x281, 0x286, 0x28a, 0x28d, 0x296, 0x299, 0x29f, 
    0x2af, 0x2b2, 0x2b7, 0x2ba, 0x2c1, 0x2d4, 0x2d7, 0x2d9, 0x2e6, 0x2ea, 
    0x2f1, 0x2f6, 0x303, 0x30c, 0x314, 0x321, 0x325, 0x330, 0x335, 0x338, 
    0x343, 0x34b, 0x359, 0x35e, 0x362, 0x365, 0x369, 0x36d, 0x36f, 0x375, 
    0x37f, 0x38b, 0x392, 0x395, 0x3a0, 0x3a6, 0x3a9, 0x3ad, 0x3b8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CParser::Initializer CParser::_init;
