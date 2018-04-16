
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
            | (1ULL << CParser::LeftParen)
            | (1ULL << CParser::Plus)
            | (1ULL << CParser::PlusPlus)
            | (1ULL << CParser::Minus)
            | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
            | (1ULL << (CParser::And - 64))
            | (1ULL << (CParser::Tilde - 64))
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
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__3)
      | (1ULL << CParser::Plus)
      | (1ULL << CParser::Minus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Tilde - 64)))) != 0))) {
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
    setState(333);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(331);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(325);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
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

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(329);
          match(CParser::T__5);
          setState(330);
          relationalExpression(0);
          break;
        }

        } 
      }
      setState(335);
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
    setState(337);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(344);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndExpression);
        setState(339);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(340);
        match(CParser::And);
        setState(341);
        equalityExpression(0); 
      }
      setState(346);
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
    setState(348);
    andExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(355);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExclusiveOrExpression);
        setState(350);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(351);
        match(CParser::Caret);
        setState(352);
        andExpression(0); 
      }
      setState(357);
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
    setState(359);
    exclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(366);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInclusiveOrExpression);
        setState(361);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(362);
        match(CParser::Or);
        setState(363);
        exclusiveOrExpression(0); 
      }
      setState(368);
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
    setState(370);
    inclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(377);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(372);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(373);
        match(CParser::T__2);
        setState(374);
        inclusiveOrExpression(0); 
      }
      setState(379);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
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
    setState(381);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(388);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
        setState(383);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(384);
        match(CParser::T__6);
        setState(385);
        logicalAndExpression(0); 
      }
      setState(390);
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
    setState(391);
    logicalOrExpression(0);
    setState(397);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(392);
      match(CParser::Question);
      setState(393);
      expression(0);
      setState(394);
      match(CParser::Colon);
      setState(395);
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
    setState(405);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(399);
      conditionalExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(400);
      unaryExpression();
      setState(401);
      assignmentOperator();
      setState(402);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(404);
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
    setState(407);
    _la = _input->LA(1);
    if (!(((((_la - 74) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 74)) & ((1ULL << (CParser::Assign - 74))
      | (1ULL << (CParser::StarAssign - 74))
      | (1ULL << (CParser::DivAssign - 74))
      | (1ULL << (CParser::ModAssign - 74))
      | (1ULL << (CParser::PlusAssign - 74))
      | (1ULL << (CParser::MinusAssign - 74))
      | (1ULL << (CParser::LeftShiftAssign - 74))
      | (1ULL << (CParser::RightShiftAssign - 74))
      | (1ULL << (CParser::AndAssign - 74))
      | (1ULL << (CParser::XorAssign - 74))
      | (1ULL << (CParser::OrAssign - 74)))) != 0))) {
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
    setState(410);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(417);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(412);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(413);
        match(CParser::Comma);
        setState(414);
        assignmentExpression(); 
      }
      setState(419);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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
    setState(420);
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
    setState(429);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(422);
      declarationSpecifiers();
      setState(423);
      initDeclaratorList(0);
      setState(424);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(426);
      declarationSpecifiers();
      setState(427);
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
    setState(432); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(431);
      declarationSpecifier();
      setState(434); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
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
    setState(437); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(436);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(439); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
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
    setState(444);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__7:
      case CParser::T__8:
      case CParser::Extern:
      case CParser::Static:
      case CParser::Typedef: {
        enterOuterAlt(_localctx, 1);
        setState(441);
        storageClassSpecifier();
        break;
      }

      case CParser::Char:
      case CParser::Bool:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Unsigned:
      case CParser::Void: {
        enterOuterAlt(_localctx, 2);
        setState(442);
        typeSpecifier();
        break;
      }

      case CParser::Const: {
        enterOuterAlt(_localctx, 3);
        setState(443);
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
    setState(447);
    initDeclarator();
    _ctx->stop = _input->LT(-1);
    setState(454);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitDeclaratorList);
        setState(449);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(450);
        match(CParser::Comma);
        setState(451);
        initDeclarator(); 
      }
      setState(456);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
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
    setState(462);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(457);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(458);
      declarator();
      setState(459);
      match(CParser::Assign);
      setState(460);
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
    setState(464);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
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
    setState(466);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Char)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
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
    setState(476);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Char:
      case CParser::Bool:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Unsigned:
      case CParser::Void: {
        enterOuterAlt(_localctx, 1);
        setState(468);
        typeSpecifier();
        setState(470);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::Char)
          | (1ULL << CParser::Const)
          | (1ULL << CParser::Bool)
          | (1ULL << CParser::Double)
          | (1ULL << CParser::Float)
          | (1ULL << CParser::Int)
          | (1ULL << CParser::Long)
          | (1ULL << CParser::Short)
          | (1ULL << CParser::Signed)
          | (1ULL << CParser::Unsigned)
          | (1ULL << CParser::Void))) != 0)) {
          setState(469);
          specifierQualifierList();
        }
        break;
      }

      case CParser::Const: {
        enterOuterAlt(_localctx, 2);
        setState(472);
        typeQualifier();
        setState(474);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::Char)
          | (1ULL << CParser::Const)
          | (1ULL << CParser::Bool)
          | (1ULL << CParser::Double)
          | (1ULL << CParser::Float)
          | (1ULL << CParser::Int)
          | (1ULL << CParser::Long)
          | (1ULL << CParser::Short)
          | (1ULL << CParser::Signed)
          | (1ULL << CParser::Unsigned)
          | (1ULL << CParser::Void))) != 0)) {
          setState(473);
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
    setState(478);
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
    setState(481);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Star

    || _la == CParser::Caret) {
      setState(480);
      pointer();
    }
    setState(483);
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
    setState(502);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(486);
      match(CParser::Identifier);
      break;
    }

    case 2: {
      setState(487);
      match(CParser::LeftParen);
      setState(488);
      declarator();
      setState(489);
      match(CParser::RightParen);
      break;
    }

    case 3: {
      setState(491);
      match(CParser::Identifier);
      setState(492);
      match(CParser::Colon);
      setState(493);
      match(CParser::DigitSequence);
      break;
    }

    case 4: {
      setState(494);
      match(CParser::LeftParen);
      setState(496);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::Char)
        | (1ULL << CParser::Bool)
        | (1ULL << CParser::Double)
        | (1ULL << CParser::Float)
        | (1ULL << CParser::Int)
        | (1ULL << CParser::Long)
        | (1ULL << CParser::Short)
        | (1ULL << CParser::Signed)
        | (1ULL << CParser::Unsigned)
        | (1ULL << CParser::Void))) != 0)) {
        setState(495);
        typeSpecifier();
      }
      setState(498);
      pointer();
      setState(499);
      directDeclarator(0);
      setState(500);
      match(CParser::RightParen);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(549);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(547);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(504);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(505);
          match(CParser::LeftBracket);
          setState(507);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(506);
            typeQualifierList(0);
          }
          setState(510);
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
            | (1ULL << CParser::LeftParen)
            | (1ULL << CParser::Plus)
            | (1ULL << CParser::PlusPlus)
            | (1ULL << CParser::Minus)
            | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
            | (1ULL << (CParser::And - 64))
            | (1ULL << (CParser::Tilde - 64))
            | (1ULL << (CParser::Identifier - 64)))) != 0)) {
            setState(509);
            assignmentExpression();
          }
          setState(512);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(513);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(514);
          match(CParser::LeftBracket);
          setState(515);
          match(CParser::Static);
          setState(517);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(516);
            typeQualifierList(0);
          }
          setState(519);
          assignmentExpression();
          setState(520);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(522);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(523);
          match(CParser::LeftBracket);
          setState(524);
          typeQualifierList(0);
          setState(525);
          match(CParser::Static);
          setState(526);
          assignmentExpression();
          setState(527);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(529);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(530);
          match(CParser::LeftBracket);
          setState(532);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(531);
            typeQualifierList(0);
          }
          setState(534);
          match(CParser::Star);
          setState(535);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(536);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(537);
          match(CParser::LeftParen);
          setState(538);
          parameterTypeList();
          setState(539);
          match(CParser::RightParen);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(541);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(542);
          match(CParser::LeftParen);
          setState(544);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Identifier) {
            setState(543);
            identifierList(0);
          }
          setState(546);
          match(CParser::RightParen);
          break;
        }

        } 
      }
      setState(551);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
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
    setState(559);
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
      | (1ULL << CParser::RightShift)
      | (1ULL << CParser::Plus)
      | (1ULL << CParser::PlusPlus)
      | (1ULL << CParser::Minus)
      | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::Div - 64))
      | (1ULL << (CParser::Mod - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Or - 64))
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
      | (1ULL << (CParser::Arrow - 64))
      | (1ULL << (CParser::Dot - 64))
      | (1ULL << (CParser::Ellipsis - 64))
      | (1ULL << (CParser::Tilde - 64))
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
      setState(557);
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
        case CParser::Arrow:
        case CParser::Dot:
        case CParser::Ellipsis:
        case CParser::Tilde:
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
          setState(552);
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
          setState(553);
          match(CParser::LeftParen);
          setState(554);
          nestedParenthesesBlock();
          setState(555);
          match(CParser::RightParen);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(561);
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
    setState(580);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(562);
      match(CParser::Star);
      setState(564);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
      case 1: {
        setState(563);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(566);
      match(CParser::Star);
      setState(568);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Const) {
        setState(567);
        typeQualifierList(0);
      }
      setState(570);
      pointer();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(571);
      match(CParser::Caret);
      setState(573);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
      case 1: {
        setState(572);
        typeQualifierList(0);
        break;
      }

      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(575);
      match(CParser::Caret);
      setState(577);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Const) {
        setState(576);
        typeQualifierList(0);
      }
      setState(579);
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
    setState(583);
    typeQualifier();
    _ctx->stop = _input->LT(-1);
    setState(589);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeQualifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTypeQualifierList);
        setState(585);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(586);
        typeQualifier(); 
      }
      setState(591);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
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
    setState(597);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(592);
      parameterList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(593);
      parameterList(0);
      setState(594);
      match(CParser::Comma);
      setState(595);
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
    setState(600);
    parameterDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(607);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterList);
        setState(602);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(603);
        match(CParser::Comma);
        setState(604);
        parameterDeclaration(); 
      }
      setState(609);
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
    setState(617);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(610);
      declarationSpecifiers();
      setState(611);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(613);
      declarationSpecifiers2();
      setState(615);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
      case 1: {
        setState(614);
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
    setState(620);
    match(CParser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(627);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(622);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(623);
        match(CParser::Comma);
        setState(624);
        match(CParser::Identifier); 
      }
      setState(629);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
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
    setState(630);
    specifierQualifierList();
    setState(632);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 48) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 48)) & ((1ULL << (CParser::LeftParen - 48))
      | (1ULL << (CParser::LeftBracket - 48))
      | (1ULL << (CParser::Star - 48))
      | (1ULL << (CParser::Caret - 48)))) != 0)) {
      setState(631);
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
    setState(639);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(634);
      pointer();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(636);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Star

      || _la == CParser::Caret) {
        setState(635);
        pointer();
      }
      setState(638);
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
    setState(676);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      setState(642);
      match(CParser::LeftParen);
      setState(643);
      abstractDeclarator();
      setState(644);
      match(CParser::RightParen);
      break;
    }

    case 2: {
      setState(646);
      match(CParser::LeftBracket);
      setState(648);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Const) {
        setState(647);
        typeQualifierList(0);
      }
      setState(651);
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
        | (1ULL << CParser::LeftParen)
        | (1ULL << CParser::Plus)
        | (1ULL << CParser::PlusPlus)
        | (1ULL << CParser::Minus)
        | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
        | (1ULL << (CParser::And - 64))
        | (1ULL << (CParser::Tilde - 64))
        | (1ULL << (CParser::Identifier - 64)))) != 0)) {
        setState(650);
        assignmentExpression();
      }
      setState(653);
      match(CParser::RightBracket);
      break;
    }

    case 3: {
      setState(654);
      match(CParser::LeftBracket);
      setState(655);
      match(CParser::Static);
      setState(657);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Const) {
        setState(656);
        typeQualifierList(0);
      }
      setState(659);
      assignmentExpression();
      setState(660);
      match(CParser::RightBracket);
      break;
    }

    case 4: {
      setState(662);
      match(CParser::LeftBracket);
      setState(663);
      typeQualifierList(0);
      setState(664);
      match(CParser::Static);
      setState(665);
      assignmentExpression();
      setState(666);
      match(CParser::RightBracket);
      break;
    }

    case 5: {
      setState(668);
      match(CParser::LeftBracket);
      setState(669);
      match(CParser::Star);
      setState(670);
      match(CParser::RightBracket);
      break;
    }

    case 6: {
      setState(671);
      match(CParser::LeftParen);
      setState(673);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::T__7)
        | (1ULL << CParser::T__8)
        | (1ULL << CParser::Char)
        | (1ULL << CParser::Const)
        | (1ULL << CParser::Bool)
        | (1ULL << CParser::Double)
        | (1ULL << CParser::Extern)
        | (1ULL << CParser::Float)
        | (1ULL << CParser::Int)
        | (1ULL << CParser::Long)
        | (1ULL << CParser::Short)
        | (1ULL << CParser::Signed)
        | (1ULL << CParser::Static)
        | (1ULL << CParser::Typedef)
        | (1ULL << CParser::Unsigned)
        | (1ULL << CParser::Void))) != 0)) {
        setState(672);
        parameterTypeList();
      }
      setState(675);
      match(CParser::RightParen);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(715);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(713);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(678);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(679);
          match(CParser::LeftBracket);
          setState(681);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(680);
            typeQualifierList(0);
          }
          setState(684);
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
            | (1ULL << CParser::LeftParen)
            | (1ULL << CParser::Plus)
            | (1ULL << CParser::PlusPlus)
            | (1ULL << CParser::Minus)
            | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
            | (1ULL << (CParser::And - 64))
            | (1ULL << (CParser::Tilde - 64))
            | (1ULL << (CParser::Identifier - 64)))) != 0)) {
            setState(683);
            assignmentExpression();
          }
          setState(686);
          match(CParser::RightBracket);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(687);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(688);
          match(CParser::LeftBracket);
          setState(689);
          match(CParser::Static);
          setState(691);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Const) {
            setState(690);
            typeQualifierList(0);
          }
          setState(693);
          assignmentExpression();
          setState(694);
          match(CParser::RightBracket);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(696);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(697);
          match(CParser::LeftBracket);
          setState(698);
          typeQualifierList(0);
          setState(699);
          match(CParser::Static);
          setState(700);
          assignmentExpression();
          setState(701);
          match(CParser::RightBracket);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(703);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(704);
          match(CParser::LeftBracket);
          setState(705);
          match(CParser::Star);
          setState(706);
          match(CParser::RightBracket);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectAbstractDeclarator);
          setState(707);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(708);
          match(CParser::LeftParen);
          setState(710);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::T__7)
            | (1ULL << CParser::T__8)
            | (1ULL << CParser::Char)
            | (1ULL << CParser::Const)
            | (1ULL << CParser::Bool)
            | (1ULL << CParser::Double)
            | (1ULL << CParser::Extern)
            | (1ULL << CParser::Float)
            | (1ULL << CParser::Int)
            | (1ULL << CParser::Long)
            | (1ULL << CParser::Short)
            | (1ULL << CParser::Signed)
            | (1ULL << CParser::Static)
            | (1ULL << CParser::Typedef)
            | (1ULL << CParser::Unsigned)
            | (1ULL << CParser::Void))) != 0)) {
            setState(709);
            parameterTypeList();
          }
          setState(712);
          match(CParser::RightParen);
          break;
        }

        } 
      }
      setState(717);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
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
    setState(728);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(718);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(719);
      match(CParser::LeftBrace);
      setState(720);
      initializerList(0);
      setState(721);
      match(CParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(723);
      match(CParser::LeftBrace);
      setState(724);
      initializerList(0);
      setState(725);
      match(CParser::Comma);
      setState(726);
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
    setState(732);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::LeftBracket

    || _la == CParser::Dot) {
      setState(731);
      designation();
    }
    setState(734);
    initializer();
    _ctx->stop = _input->LT(-1);
    setState(744);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitializerListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitializerList);
        setState(736);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(737);
        match(CParser::Comma);
        setState(739);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftBracket

        || _la == CParser::Dot) {
          setState(738);
          designation();
        }
        setState(741);
        initializer(); 
      }
      setState(746);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx);
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
    setState(747);
    designatorList(0);
    setState(748);
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
    setState(751);
    designator();
    _ctx->stop = _input->LT(-1);
    setState(757);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DesignatorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDesignatorList);
        setState(753);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(754);
        designator(); 
      }
      setState(759);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
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
    setState(766);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::LeftBracket: {
        enterOuterAlt(_localctx, 1);
        setState(760);
        match(CParser::LeftBracket);
        setState(761);
        constantExpression();
        setState(762);
        match(CParser::RightBracket);
        break;
      }

      case CParser::Dot: {
        enterOuterAlt(_localctx, 2);
        setState(764);
        match(CParser::Dot);
        setState(765);
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
    setState(774);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(768);
      labeledStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(769);
      compoundStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(770);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(771);
      selectionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(772);
      iterationStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(773);
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
    setState(787);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(776);
        match(CParser::Identifier);
        setState(777);
        match(CParser::Colon);
        setState(778);
        statement();
        break;
      }

      case CParser::Case: {
        enterOuterAlt(_localctx, 2);
        setState(779);
        match(CParser::Case);
        setState(780);
        constantExpression();
        setState(781);
        match(CParser::Colon);
        setState(782);
        statement();
        break;
      }

      case CParser::Default: {
        enterOuterAlt(_localctx, 3);
        setState(784);
        match(CParser::Default);
        setState(785);
        match(CParser::Colon);
        setState(786);
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
    setState(789);
    match(CParser::LeftBrace);
    setState(791);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__1)
      | (1ULL << CParser::T__2)
      | (1ULL << CParser::T__3)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::T__9)
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
      | (1ULL << CParser::LeftBrace)
      | (1ULL << CParser::Plus)
      | (1ULL << CParser::PlusPlus)
      | (1ULL << CParser::Minus)
      | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Semi - 64))
      | (1ULL << (CParser::Tilde - 64))
      | (1ULL << (CParser::Identifier - 64)))) != 0)) {
      setState(790);
      blockItemList(0);
    }
    setState(793);
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
    setState(796);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(802);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(798);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(799);
        blockItem(); 
      }
      setState(804);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
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
    setState(807);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__0:
      case CParser::T__1:
      case CParser::T__2:
      case CParser::T__3:
      case CParser::T__9:
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
      case CParser::Semi:
      case CParser::Tilde:
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(805);
        statement();
        break;
      }

      case CParser::T__7:
      case CParser::T__8:
      case CParser::Char:
      case CParser::Const:
      case CParser::Bool:
      case CParser::Double:
      case CParser::Extern:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Static:
      case CParser::Typedef:
      case CParser::Unsigned:
      case CParser::Void: {
        enterOuterAlt(_localctx, 2);
        setState(806);
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
    setState(810);
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
      | (1ULL << CParser::LeftParen)
      | (1ULL << CParser::Plus)
      | (1ULL << CParser::PlusPlus)
      | (1ULL << CParser::Minus)
      | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Tilde - 64))
      | (1ULL << (CParser::Identifier - 64)))) != 0)) {
      setState(809);
      expression(0);
    }
    setState(812);
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
    setState(829);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(814);
        match(CParser::If);
        setState(815);
        match(CParser::LeftParen);
        setState(816);
        expression(0);
        setState(817);
        match(CParser::RightParen);
        setState(818);
        statement();
        setState(821);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
        case 1: {
          setState(819);
          match(CParser::Else);
          setState(820);
          statement();
          break;
        }

        }
        break;
      }

      case CParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(823);
        match(CParser::Switch);
        setState(824);
        match(CParser::LeftParen);
        setState(825);
        expression(0);
        setState(826);
        match(CParser::RightParen);
        setState(827);
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
    setState(843);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(831);
        match(CParser::While);
        setState(832);
        match(CParser::LeftParen);
        setState(833);
        expression(0);
        setState(834);
        match(CParser::RightParen);
        setState(835);
        statement();
        break;
      }

      case CParser::For: {
        enterOuterAlt(_localctx, 2);
        setState(837);
        match(CParser::For);
        setState(838);
        match(CParser::LeftParen);
        setState(839);
        forCondition();
        setState(840);
        match(CParser::RightParen);
        setState(841);
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
    setState(865);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__7:
      case CParser::T__8:
      case CParser::Char:
      case CParser::Const:
      case CParser::Bool:
      case CParser::Double:
      case CParser::Extern:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Static:
      case CParser::Typedef:
      case CParser::Unsigned:
      case CParser::Void: {
        enterOuterAlt(_localctx, 1);
        setState(845);
        forDeclaration();
        setState(846);
        match(CParser::Semi);
        setState(848);
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
          | (1ULL << CParser::LeftParen)
          | (1ULL << CParser::Plus)
          | (1ULL << CParser::PlusPlus)
          | (1ULL << CParser::Minus)
          | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Tilde - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(847);
          forExpression(0);
        }
        setState(850);
        match(CParser::Semi);
        setState(852);
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
          | (1ULL << CParser::LeftParen)
          | (1ULL << CParser::Plus)
          | (1ULL << CParser::PlusPlus)
          | (1ULL << CParser::Minus)
          | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Tilde - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(851);
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
      case CParser::Semi:
      case CParser::Tilde:
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(855);
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
          | (1ULL << CParser::LeftParen)
          | (1ULL << CParser::Plus)
          | (1ULL << CParser::PlusPlus)
          | (1ULL << CParser::Minus)
          | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Tilde - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(854);
          expression(0);
        }
        setState(857);
        match(CParser::Semi);
        setState(859);
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
          | (1ULL << CParser::LeftParen)
          | (1ULL << CParser::Plus)
          | (1ULL << CParser::PlusPlus)
          | (1ULL << CParser::Minus)
          | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Tilde - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(858);
          forExpression(0);
        }
        setState(861);
        match(CParser::Semi);
        setState(863);
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
          | (1ULL << CParser::LeftParen)
          | (1ULL << CParser::Plus)
          | (1ULL << CParser::PlusPlus)
          | (1ULL << CParser::Minus)
          | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
          | (1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Tilde - 64))
          | (1ULL << (CParser::Identifier - 64)))) != 0)) {
          setState(862);
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
    setState(871);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(867);
      declarationSpecifiers();
      setState(868);
      initDeclaratorList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(870);
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
    setState(874);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(881);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ForExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleForExpression);
        setState(876);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(877);
        match(CParser::Comma);
        setState(878);
        assignmentExpression(); 
      }
      setState(883);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx);
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
    setState(900);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(884);
      match(CParser::T__9);
      setState(885);
      match(CParser::Identifier);
      setState(886);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(887);
      match(CParser::Continue);
      setState(888);
      match(CParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(889);
      match(CParser::Break);
      setState(890);
      match(CParser::Semi);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(891);
      match(CParser::Return);
      setState(893);
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
        | (1ULL << CParser::LeftParen)
        | (1ULL << CParser::Plus)
        | (1ULL << CParser::PlusPlus)
        | (1ULL << CParser::Minus)
        | (1ULL << CParser::MinusMinus))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
        | (1ULL << (CParser::And - 64))
        | (1ULL << (CParser::Tilde - 64))
        | (1ULL << (CParser::Identifier - 64)))) != 0)) {
        setState(892);
        expression(0);
      }
      setState(895);
      match(CParser::Semi);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(896);
      match(CParser::T__9);
      setState(897);
      unaryExpression();
      setState(898);
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
    setState(903);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::LeftParen))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::Star - 64))
      | (1ULL << (CParser::Caret - 64))
      | (1ULL << (CParser::Semi - 64))
      | (1ULL << (CParser::Identifier - 64)))) != 0)) {
      setState(902);
      translationUnit(0);
    }
    setState(905);
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
    setState(908);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(914);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(910);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(911);
        externalDeclaration(); 
      }
      setState(916);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
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
    setState(920);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(917);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(918);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(919);
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
    setState(923);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void))) != 0)) {
      setState(922);
      declarationSpecifiers();
    }
    setState(925);
    declarator();
    setState(927);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__7)
      | (1ULL << CParser::T__8)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Const)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Static)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void))) != 0)) {
      setState(926);
      declarationList(0);
    }
    setState(929);
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
    setState(932);
    declaration();
    _ctx->stop = _input->LT(-1);
    setState(938);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDeclarationList);
        setState(934);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(935);
        declaration(); 
      }
      setState(940);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
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
    case 18: return precpred(_ctx, 2);
    case 19: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::andExpressionSempred(AndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 20: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::exclusiveOrExpressionSempred(ExclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 21: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::inclusiveOrExpressionSempred(InclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 22: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 23: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::logicalOrExpressionSempred(LogicalOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 24: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 25: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::initDeclaratorListSempred(InitDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 8);
    case 28: return precpred(_ctx, 7);
    case 29: return precpred(_ctx, 6);
    case 30: return precpred(_ctx, 5);
    case 31: return precpred(_ctx, 4);
    case 32: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CParser::typeQualifierListSempred(TypeQualifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 33: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::parameterListSempred(ParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 34: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 35: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::directAbstractDeclaratorSempred(DirectAbstractDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 36: return precpred(_ctx, 5);
    case 37: return precpred(_ctx, 4);
    case 38: return precpred(_ctx, 3);
    case 39: return precpred(_ctx, 2);
    case 40: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::initializerListSempred(InitializerListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 41: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::designatorListSempred(DesignatorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 42: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 43: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::forExpressionSempred(ForExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 44: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::translationUnitSempred(TranslationUnitContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 45: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CParser::declarationListSempred(DeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 46: return precpred(_ctx, 1);

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
  "", "'__extension__'", "'_Alignof'", "'&&'", "'!'", "'=='", "'!='", "'||'", 
  "'auto'", "'register'", "'goto'", "", "", "", "'??'", "'@'", "'**'", "'_'", 
  "'namespace'", "'::'", "'string'", "'break'", "'case'", "'char'", "'const'", 
  "'continue'", "'bool'", "'default'", "'double'", "'else'", "'extern'", 
  "'float'", "'for'", "'if'", "'int'", "'uint32_t'", "'int32_t'", "'long'", 
  "'return'", "'short'", "'signed'", "'sizeof'", "'static'", "'switch'", 
  "'typedef'", "'unsigned'", "'void'", "'while'", "'('", "')'", "'['", "']'", 
  "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", "'<<'", "'>>'", "'+'", "'++'", 
  "'-'", "'--'", "'*'", "'/'", "'%'", "'&'", "'|'", "'^'", "'?'", "':'", 
  "';'", "','", "'='", "'*='", "'/='", "'%='", "'+='", "'-='", "'<<='", 
  "'>>='", "'&='", "'^='", "'|='", "'->'", "'.'", "'...'", "'~'"
};

std::vector<std::string> CParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "Constant", "DigitSequence", 
  "StringLiteral", "Coalescing", "Bit", "Power", "IgnoreWildCard", "Namespace", 
  "ScopeResolution", "String", "Break", "Case", "Char", "Const", "Continue", 
  "Bool", "Default", "Double", "Else", "Extern", "Float", "For", "If", "Int", 
  "Uint32", "Int32", "Long", "Return", "Short", "Signed", "Sizeof", "Static", 
  "Switch", "Typedef", "Unsigned", "Void", "While", "LeftParen", "RightParen", 
  "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", "Less", "LessEqual", 
  "Greater", "GreaterEqual", "LeftShift", "RightShift", "Plus", "PlusPlus", 
  "Minus", "MinusMinus", "Star", "Div", "Mod", "And", "Or", "Caret", "Question", 
  "Colon", "Semi", "Comma", "Assign", "StarAssign", "DivAssign", "ModAssign", 
  "PlusAssign", "MinusAssign", "LeftShiftAssign", "RightShiftAssign", "AndAssign", 
  "XorAssign", "OrAssign", "Arrow", "Dot", "Ellipsis", "Tilde", "AndAnd", 
  "OrOr", "Not", "Equal", "NotEqual", "Identifier", "Whitespace", "Newline", 
  "BlockComment", "LineComment"
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
    0x3, 0x64, 0x3b0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0xc, 0x3, 0xc, 0x7, 0xc, 0x14e, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x151, 
    0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x7, 0xd, 0x159, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x15c, 0xb, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x164, 
    0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x167, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x16f, 0xa, 0xf, 0xc, 0xf, 
    0xe, 0xf, 0x172, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x17a, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
    0x17d, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x185, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x188, 
    0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x5, 0x12, 0x190, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x198, 0xa, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x7, 0x15, 0x1a2, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x1a5, 0xb, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1b0, 0xa, 0x17, 0x3, 0x18, 
    0x6, 0x18, 0x1b3, 0xa, 0x18, 0xd, 0x18, 0xe, 0x18, 0x1b4, 0x3, 0x19, 
    0x6, 0x19, 0x1b8, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0x1b9, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x1bf, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x1c7, 0xa, 0x1b, 
    0xc, 0x1b, 0xe, 0x1b, 0x1ca, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1d1, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1d9, 0xa, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1dd, 0xa, 0x1f, 0x5, 0x1f, 0x1df, 
    0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x5, 0x21, 0x1e4, 0xa, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x5, 0x22, 0x1f3, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x5, 0x22, 0x1f9, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 
    0x1fe, 0xa, 0x22, 0x3, 0x22, 0x5, 0x22, 0x201, 0xa, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x208, 0xa, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x5, 0x22, 0x217, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 
    0x22, 0x223, 0xa, 0x22, 0x3, 0x22, 0x7, 0x22, 0x226, 0xa, 0x22, 0xc, 
    0x22, 0xe, 0x22, 0x229, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x230, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 
    0x233, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x237, 0xa, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x23b, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x240, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
    0x244, 0xa, 0x24, 0x3, 0x24, 0x5, 0x24, 0x247, 0xa, 0x24, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x24e, 0xa, 0x25, 
    0xc, 0x25, 0xe, 0x25, 0x251, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x258, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x260, 0xa, 0x27, 
    0xc, 0x27, 0xe, 0x27, 0x263, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x26a, 0xa, 0x28, 0x5, 0x28, 0x26c, 
    0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x7, 0x29, 0x274, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x277, 0xb, 
    0x29, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x27b, 0xa, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x5, 0x2b, 0x27f, 0xa, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x282, 
    0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x28b, 0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x28e, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x294, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2a4, 0xa, 0x2c, 0x3, 0x2c, 
    0x5, 0x2c, 0x2a7, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x2ac, 0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2af, 0xa, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2b6, 0xa, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2c9, 0xa, 0x2c, 
    0x3, 0x2c, 0x7, 0x2c, 0x2cc, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x2cf, 
    0xb, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x2db, 
    0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x2df, 0xa, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x2e6, 0xa, 0x2e, 
    0x3, 0x2e, 0x7, 0x2e, 0x2e9, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x2ec, 
    0xb, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 
    0x30, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x2f6, 0xa, 0x30, 0xc, 0x30, 
    0xe, 0x30, 0x2f9, 0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x301, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x309, 0xa, 0x32, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x316, 
    0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x31a, 0xa, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 
    0x35, 0x323, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x326, 0xb, 0x35, 0x3, 
    0x36, 0x3, 0x36, 0x5, 0x36, 0x32a, 0xa, 0x36, 0x3, 0x37, 0x5, 0x37, 
    0x32d, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x338, 0xa, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 
    0x38, 0x340, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
    0x39, 0x3, 0x39, 0x5, 0x39, 0x34e, 0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x5, 0x3a, 0x353, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 
    0x357, 0xa, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x35a, 0xa, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x5, 0x3a, 0x35e, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 
    0x362, 0xa, 0x3a, 0x5, 0x3a, 0x364, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x36a, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 0x372, 0xa, 0x3c, 
    0xc, 0x3c, 0xe, 0x3c, 0x375, 0xb, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 
    0x3d, 0x380, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
    0x3, 0x3d, 0x5, 0x3d, 0x387, 0xa, 0x3d, 0x3, 0x3e, 0x5, 0x3e, 0x38a, 
    0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 
    0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x393, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 
    0x396, 0xb, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x39b, 
    0xa, 0x40, 0x3, 0x41, 0x5, 0x41, 0x39e, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x5, 0x41, 0x3a2, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x3ab, 0xa, 0x42, 0xc, 0x42, 
    0xe, 0x42, 0x3ae, 0xb, 0x42, 0x3, 0x42, 0x2, 0x1b, 0x4, 0x6, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x28, 0x34, 0x42, 0x48, 
    0x4c, 0x50, 0x56, 0x5a, 0x5e, 0x68, 0x76, 0x7c, 0x82, 0x43, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
    0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 
    0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 
    0x80, 0x82, 0x2, 0x7, 0x8, 0x2, 0x6, 0x6, 0x3e, 0x3e, 0x40, 0x40, 0x42, 
    0x42, 0x45, 0x45, 0x5a, 0x5a, 0x3, 0x2, 0x4c, 0x56, 0x6, 0x2, 0xa, 0xb, 
    0x20, 0x20, 0x2c, 0x2c, 0x2e, 0x2e, 0xa, 0x2, 0x19, 0x19, 0x1c, 0x1c, 
    0x1e, 0x1e, 0x21, 0x21, 0x24, 0x24, 0x27, 0x27, 0x29, 0x2a, 0x2f, 0x30, 
    0x3, 0x2, 0x32, 0x33, 0x2, 0x405, 0x2, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0x6, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x8, 0xf0, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xc, 0x101, 0x3, 
    0x2, 0x2, 0x2, 0xe, 0x103, 0x3, 0x2, 0x2, 0x2, 0x10, 0x114, 0x3, 0x2, 
    0x2, 0x2, 0x12, 0x122, 0x3, 0x2, 0x2, 0x2, 0x14, 0x130, 0x3, 0x2, 0x2, 
    0x2, 0x16, 0x144, 0x3, 0x2, 0x2, 0x2, 0x18, 0x152, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x168, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x173, 0x3, 0x2, 0x2, 0x2, 0x20, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x22, 0x189, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x197, 0x3, 0x2, 0x2, 0x2, 0x26, 0x199, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x1a6, 0x3, 0x2, 
    0x2, 0x2, 0x2c, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x1b2, 0x3, 0x2, 0x2, 
    0x2, 0x30, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x32, 0x1be, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x1d2, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x1de, 
    0x3, 0x2, 0x2, 0x2, 0x3e, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1e3, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x44, 0x231, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x246, 0x3, 0x2, 0x2, 0x2, 0x48, 0x248, 0x3, 0x2, 0x2, 
    0x2, 0x4a, 0x257, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x259, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x50, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x52, 
    0x278, 0x3, 0x2, 0x2, 0x2, 0x54, 0x281, 0x3, 0x2, 0x2, 0x2, 0x56, 0x2a6, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x2dc, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x2f0, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x300, 0x3, 0x2, 0x2, 0x2, 0x62, 0x308, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x315, 0x3, 0x2, 0x2, 0x2, 0x66, 0x317, 0x3, 0x2, 0x2, 0x2, 
    0x68, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x329, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x32c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x70, 0x34d, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x363, 0x3, 0x2, 0x2, 0x2, 0x74, 0x369, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x78, 0x386, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x389, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x38d, 0x3, 0x2, 0x2, 
    0x2, 0x7e, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x80, 0x39d, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x84, 0x90, 0x7, 0x60, 0x2, 0x2, 0x85, 
    0x90, 0x7, 0xd, 0x2, 0x2, 0x86, 0x88, 0x7, 0xf, 0x2, 0x2, 0x87, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8c, 0x7, 0x32, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x28, 0x15, 
    0x2, 0x8d, 0x8e, 0x7, 0x33, 0x2, 0x2, 0x8e, 0x90, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0x84, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x90, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x8, 0x3, 0x1, 0x2, 0x92, 0xb4, 0x5, 
    0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x32, 0x2, 0x2, 0x94, 0x95, 0x5, 0x52, 
    0x2a, 0x2, 0x95, 0x96, 0x7, 0x33, 0x2, 0x2, 0x96, 0x97, 0x7, 0x36, 0x2, 
    0x2, 0x97, 0x98, 0x5, 0x5a, 0x2e, 0x2, 0x98, 0x99, 0x7, 0x37, 0x2, 0x2, 
    0x99, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x32, 0x2, 0x2, 0x9b, 
    0x9c, 0x5, 0x52, 0x2a, 0x2, 0x9c, 0x9d, 0x7, 0x33, 0x2, 0x2, 0x9d, 0x9e, 
    0x7, 0x36, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0x5a, 0x2e, 0x2, 0x9f, 0xa0, 0x7, 
    0x4b, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x37, 0x2, 0x2, 0xa1, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa3, 0x7, 0x3, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x32, 0x2, 
    0x2, 0xa4, 0xa5, 0x5, 0x52, 0x2a, 0x2, 0xa5, 0xa6, 0x7, 0x33, 0x2, 0x2, 
    0xa6, 0xa7, 0x7, 0x36, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x5a, 0x2e, 0x2, 0xa8, 
    0xa9, 0x7, 0x37, 0x2, 0x2, 0xa9, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 
    0x7, 0x3, 0x2, 0x2, 0xab, 0xac, 0x7, 0x32, 0x2, 0x2, 0xac, 0xad, 0x5, 
    0x52, 0x2a, 0x2, 0xad, 0xae, 0x7, 0x33, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x36, 
    0x2, 0x2, 0xaf, 0xb0, 0x5, 0x5a, 0x2e, 0x2, 0xb0, 0xb1, 0x7, 0x4b, 0x2, 
    0x2, 0xb1, 0xb2, 0x7, 0x37, 0x2, 0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0x91, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x93, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0xc, 
    0xc, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x34, 0x2, 0x2, 0xb7, 0xb8, 0x5, 0x28, 
    0x15, 0x2, 0xb8, 0xb9, 0x7, 0x35, 0x2, 0x2, 0xb9, 0xcb, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0xbb, 0xc, 0xb, 0x2, 0x2, 0xbb, 0xbd, 0x7, 0x32, 0x2, 0x2, 
    0xbc, 0xbe, 0x5, 0x6, 0x4, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xcb, 
    0x7, 0x33, 0x2, 0x2, 0xc0, 0xc1, 0xc, 0xa, 0x2, 0x2, 0xc1, 0xc2, 0x7, 
    0x58, 0x2, 0x2, 0xc2, 0xcb, 0x7, 0x60, 0x2, 0x2, 0xc3, 0xc4, 0xc, 0x9, 
    0x2, 0x2, 0xc4, 0xc5, 0x7, 0x57, 0x2, 0x2, 0xc5, 0xcb, 0x7, 0x60, 0x2, 
    0x2, 0xc6, 0xc7, 0xc, 0x8, 0x2, 0x2, 0xc7, 0xcb, 0x7, 0x3f, 0x2, 0x2, 
    0xc8, 0xc9, 0xc, 0x7, 0x2, 0x2, 0xc9, 0xcb, 0x7, 0x41, 0x2, 0x2, 0xca, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xca, 0xba, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xce, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0x5, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xd0, 0x8, 0x4, 0x1, 0x2, 0xd0, 0xd1, 0x5, 0x24, 0x13, 0x2, 0xd1, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0xc, 0x3, 0x2, 0x2, 0xd3, 0xd4, 
    0x7, 0x4b, 0x2, 0x2, 0xd4, 0xd6, 0x5, 0x24, 0x13, 0x2, 0xd5, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xf1, 0x5, 0x4, 0x3, 0x2, 
    0xdb, 0xdc, 0x7, 0x3f, 0x2, 0x2, 0xdc, 0xf1, 0x5, 0x8, 0x5, 0x2, 0xdd, 
    0xde, 0x7, 0x41, 0x2, 0x2, 0xde, 0xf1, 0x5, 0x8, 0x5, 0x2, 0xdf, 0xe0, 
    0x5, 0xa, 0x6, 0x2, 0xe0, 0xe1, 0x5, 0xc, 0x7, 0x2, 0xe1, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x2b, 0x2, 0x2, 0xe3, 0xf1, 0x5, 0x8, 
    0x5, 0x2, 0xe4, 0xe5, 0x7, 0x2b, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x32, 0x2, 
    0x2, 0xe6, 0xe7, 0x5, 0x52, 0x2a, 0x2, 0xe7, 0xe8, 0x7, 0x33, 0x2, 0x2, 
    0xe8, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x4, 0x2, 0x2, 0xea, 
    0xeb, 0x7, 0x32, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x52, 0x2a, 0x2, 0xec, 0xed, 
    0x7, 0x33, 0x2, 0x2, 0xed, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 
    0x5, 0x2, 0x2, 0xef, 0xf1, 0x7, 0x60, 0x2, 0x2, 0xf0, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xf0, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xe2, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0x9, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 
    0x9, 0x2, 0x2, 0x2, 0xf3, 0xb, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x7, 
    0x32, 0x2, 0x2, 0xf5, 0xf6, 0x5, 0x52, 0x2a, 0x2, 0xf6, 0xf7, 0x7, 0x33, 
    0x2, 0x2, 0xf7, 0xf8, 0x5, 0xc, 0x7, 0x2, 0xf8, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xfa, 0x7, 0x3, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x32, 0x2, 0x2, 
    0xfb, 0xfc, 0x5, 0x52, 0x2a, 0x2, 0xfc, 0xfd, 0x7, 0x33, 0x2, 0x2, 0xfd, 
    0xfe, 0x5, 0xc, 0x7, 0x2, 0xfe, 0x102, 0x3, 0x2, 0x2, 0x2, 0xff, 0x102, 
    0x5, 0x8, 0x5, 0x2, 0x100, 0x102, 0x7, 0xe, 0x2, 0x2, 0x101, 0xf4, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 0x3, 0x2, 
    0x2, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x103, 0x104, 0x8, 0x8, 0x1, 0x2, 0x104, 0x105, 0x5, 0xc, 0x7, 
    0x2, 0x105, 0x111, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0xc, 0x5, 0x2, 
    0x2, 0x107, 0x108, 0x7, 0x42, 0x2, 0x2, 0x108, 0x110, 0x5, 0xc, 0x7, 
    0x2, 0x109, 0x10a, 0xc, 0x4, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x43, 0x2, 
    0x2, 0x10b, 0x110, 0x5, 0xc, 0x7, 0x2, 0x10c, 0x10d, 0xc, 0x3, 0x2, 
    0x2, 0x10d, 0x10e, 0x7, 0x44, 0x2, 0x2, 0x10e, 0x110, 0x5, 0xc, 0x7, 
    0x2, 0x10f, 0x106, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x109, 0x3, 0x2, 0x2, 
    0x2, 0x10f, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x110, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0xf, 0x3, 0x2, 0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x114, 0x115, 0x8, 0x9, 0x1, 0x2, 0x115, 0x116, 0x5, 0xe, 0x8, 0x2, 
    0x116, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0xc, 0x4, 0x2, 0x2, 
    0x118, 0x119, 0x7, 0x3e, 0x2, 0x2, 0x119, 0x11e, 0x5, 0xe, 0x8, 0x2, 
    0x11a, 0x11b, 0xc, 0x3, 0x2, 0x2, 0x11b, 0x11c, 0x7, 0x40, 0x2, 0x2, 
    0x11c, 0x11e, 0x5, 0xe, 0x8, 0x2, 0x11d, 0x117, 0x3, 0x2, 0x2, 0x2, 
    0x11d, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x120, 0x11, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x122, 
    0x123, 0x8, 0xa, 0x1, 0x2, 0x123, 0x124, 0x5, 0x10, 0x9, 0x2, 0x124, 
    0x12d, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0xc, 0x4, 0x2, 0x2, 0x126, 
    0x127, 0x7, 0x3c, 0x2, 0x2, 0x127, 0x12c, 0x5, 0x10, 0x9, 0x2, 0x128, 
    0x129, 0xc, 0x3, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x3d, 0x2, 0x2, 0x12a, 
    0x12c, 0x5, 0x10, 0x9, 0x2, 0x12b, 0x125, 0x3, 0x2, 0x2, 0x2, 0x12b, 
    0x128, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12d, 
    0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 
    0x8, 0xb, 0x1, 0x2, 0x131, 0x132, 0x5, 0x12, 0xa, 0x2, 0x132, 0x141, 
    0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0xc, 0x6, 0x2, 0x2, 0x134, 0x135, 
    0x7, 0x38, 0x2, 0x2, 0x135, 0x140, 0x5, 0x12, 0xa, 0x2, 0x136, 0x137, 
    0xc, 0x5, 0x2, 0x2, 0x137, 0x138, 0x7, 0x3a, 0x2, 0x2, 0x138, 0x140, 
    0x5, 0x12, 0xa, 0x2, 0x139, 0x13a, 0xc, 0x4, 0x2, 0x2, 0x13a, 0x13b, 
    0x7, 0x39, 0x2, 0x2, 0x13b, 0x140, 0x5, 0x12, 0xa, 0x2, 0x13c, 0x13d, 
    0xc, 0x3, 0x2, 0x2, 0x13d, 0x13e, 0x7, 0x3b, 0x2, 0x2, 0x13e, 0x140, 
    0x5, 0x12, 0xa, 0x2, 0x13f, 0x133, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x136, 
    0x3, 0x2, 0x2, 0x2, 0x13f, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 
    0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x8, 
    0xc, 0x1, 0x2, 0x145, 0x146, 0x5, 0x14, 0xb, 0x2, 0x146, 0x14f, 0x3, 
    0x2, 0x2, 0x2, 0x147, 0x148, 0xc, 0x4, 0x2, 0x2, 0x148, 0x149, 0x7, 
    0x7, 0x2, 0x2, 0x149, 0x14e, 0x5, 0x14, 0xb, 0x2, 0x14a, 0x14b, 0xc, 
    0x3, 0x2, 0x2, 0x14b, 0x14c, 0x7, 0x8, 0x2, 0x2, 0x14c, 0x14e, 0x5, 
    0x14, 0xb, 0x2, 0x14d, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14a, 0x3, 
    0x2, 0x2, 0x2, 0x14e, 0x151, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 
    0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x8, 0xd, 
    0x1, 0x2, 0x153, 0x154, 0x5, 0x16, 0xc, 0x2, 0x154, 0x15a, 0x3, 0x2, 
    0x2, 0x2, 0x155, 0x156, 0xc, 0x3, 0x2, 0x2, 0x156, 0x157, 0x7, 0x45, 
    0x2, 0x2, 0x157, 0x159, 0x5, 0x16, 0xc, 0x2, 0x158, 0x155, 0x3, 0x2, 
    0x2, 0x2, 0x159, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x8, 0xe, 0x1, 
    0x2, 0x15e, 0x15f, 0x5, 0x18, 0xd, 0x2, 0x15f, 0x165, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x161, 0xc, 0x3, 0x2, 0x2, 0x161, 0x162, 0x7, 0x47, 0x2, 
    0x2, 0x162, 0x164, 0x5, 0x18, 0xd, 0x2, 0x163, 0x160, 0x3, 0x2, 0x2, 
    0x2, 0x164, 0x167, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 
    0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x167, 0x165, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x8, 0xf, 0x1, 0x2, 
    0x169, 0x16a, 0x5, 0x1a, 0xe, 0x2, 0x16a, 0x170, 0x3, 0x2, 0x2, 0x2, 
    0x16b, 0x16c, 0xc, 0x3, 0x2, 0x2, 0x16c, 0x16d, 0x7, 0x46, 0x2, 0x2, 
    0x16d, 0x16f, 0x5, 0x1a, 0xe, 0x2, 0x16e, 0x16b, 0x3, 0x2, 0x2, 0x2, 
    0x16f, 0x172, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x171, 0x3, 0x2, 0x2, 0x2, 0x171, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x172, 
    0x170, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x8, 0x10, 0x1, 0x2, 0x174, 
    0x175, 0x5, 0x1c, 0xf, 0x2, 0x175, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x176, 
    0x177, 0xc, 0x3, 0x2, 0x2, 0x177, 0x178, 0x7, 0x5, 0x2, 0x2, 0x178, 
    0x17a, 0x5, 0x1c, 0xf, 0x2, 0x179, 0x176, 0x3, 0x2, 0x2, 0x2, 0x17a, 
    0x17d, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 
    0x17c, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17b, 
    0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x8, 0x11, 0x1, 0x2, 0x17f, 0x180, 
    0x5, 0x1e, 0x10, 0x2, 0x180, 0x186, 0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 
    0xc, 0x3, 0x2, 0x2, 0x182, 0x183, 0x7, 0x9, 0x2, 0x2, 0x183, 0x185, 
    0x5, 0x1e, 0x10, 0x2, 0x184, 0x181, 0x3, 0x2, 0x2, 0x2, 0x185, 0x188, 
    0x3, 0x2, 0x2, 0x2, 0x186, 0x184, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 
    0x3, 0x2, 0x2, 0x2, 0x187, 0x21, 0x3, 0x2, 0x2, 0x2, 0x188, 0x186, 0x3, 
    0x2, 0x2, 0x2, 0x189, 0x18f, 0x5, 0x20, 0x11, 0x2, 0x18a, 0x18b, 0x7, 
    0x48, 0x2, 0x2, 0x18b, 0x18c, 0x5, 0x28, 0x15, 0x2, 0x18c, 0x18d, 0x7, 
    0x49, 0x2, 0x2, 0x18d, 0x18e, 0x5, 0x22, 0x12, 0x2, 0x18e, 0x190, 0x3, 
    0x2, 0x2, 0x2, 0x18f, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 
    0x2, 0x2, 0x2, 0x190, 0x23, 0x3, 0x2, 0x2, 0x2, 0x191, 0x198, 0x5, 0x22, 
    0x12, 0x2, 0x192, 0x193, 0x5, 0x8, 0x5, 0x2, 0x193, 0x194, 0x5, 0x26, 
    0x14, 0x2, 0x194, 0x195, 0x5, 0x24, 0x13, 0x2, 0x195, 0x198, 0x3, 0x2, 
    0x2, 0x2, 0x196, 0x198, 0x7, 0xe, 0x2, 0x2, 0x197, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x197, 0x192, 0x3, 0x2, 0x2, 0x2, 0x197, 0x196, 0x3, 0x2, 
    0x2, 0x2, 0x198, 0x25, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x9, 0x3, 0x2, 
    0x2, 0x19a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x8, 0x15, 0x1, 
    0x2, 0x19c, 0x19d, 0x5, 0x24, 0x13, 0x2, 0x19d, 0x1a3, 0x3, 0x2, 0x2, 
    0x2, 0x19e, 0x19f, 0xc, 0x3, 0x2, 0x2, 0x19f, 0x1a0, 0x7, 0x4b, 0x2, 
    0x2, 0x1a0, 0x1a2, 0x5, 0x24, 0x13, 0x2, 0x1a1, 0x19e, 0x3, 0x2, 0x2, 
    0x2, 0x1a2, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a1, 0x3, 0x2, 0x2, 
    0x2, 0x1a3, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x5, 0x22, 0x12, 0x2, 
    0x1a7, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x5, 0x2e, 0x18, 0x2, 
    0x1a9, 0x1aa, 0x5, 0x34, 0x1b, 0x2, 0x1aa, 0x1ab, 0x7, 0x4a, 0x2, 0x2, 
    0x1ab, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x5, 0x2e, 0x18, 0x2, 
    0x1ad, 0x1ae, 0x7, 0x4a, 0x2, 0x2, 0x1ae, 0x1b0, 0x3, 0x2, 0x2, 0x2, 
    0x1af, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ac, 0x3, 0x2, 0x2, 0x2, 
    0x1b0, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b3, 0x5, 0x32, 0x1a, 0x2, 
    0x1b2, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 0x3, 0x2, 0x2, 0x2, 
    0x1b4, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 0x2, 
    0x1b5, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b8, 0x5, 0x32, 0x1a, 0x2, 
    0x1b7, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x3, 0x2, 0x2, 0x2, 
    0x1b9, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x3, 0x2, 0x2, 0x2, 
    0x1ba, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bf, 0x5, 0x38, 0x1d, 0x2, 
    0x1bc, 0x1bf, 0x5, 0x3a, 0x1e, 0x2, 0x1bd, 0x1bf, 0x5, 0x3e, 0x20, 0x2, 
    0x1be, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 0x3, 0x2, 0x2, 0x2, 
    0x1be, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1c0, 
    0x1c1, 0x8, 0x1b, 0x1, 0x2, 0x1c1, 0x1c2, 0x5, 0x36, 0x1c, 0x2, 0x1c2, 
    0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0xc, 0x3, 0x2, 0x2, 0x1c4, 
    0x1c5, 0x7, 0x4b, 0x2, 0x2, 0x1c5, 0x1c7, 0x5, 0x36, 0x1c, 0x2, 0x1c6, 
    0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1c8, 
    0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1d1, 
    0x5, 0x40, 0x21, 0x2, 0x1cc, 0x1cd, 0x5, 0x40, 0x21, 0x2, 0x1cd, 0x1ce, 
    0x7, 0x4c, 0x2, 0x2, 0x1ce, 0x1cf, 0x5, 0x58, 0x2d, 0x2, 0x1cf, 0x1d1, 
    0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1cc, 
    0x3, 0x2, 0x2, 0x2, 0x1d1, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x9, 
    0x4, 0x2, 0x2, 0x1d3, 0x39, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 0x9, 0x5, 
    0x2, 0x2, 0x1d5, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d8, 0x5, 0x3a, 
    0x1e, 0x2, 0x1d7, 0x1d9, 0x5, 0x3c, 0x1f, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 
    0x2, 0x2, 0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1df, 0x3, 0x2, 
    0x2, 0x2, 0x1da, 0x1dc, 0x5, 0x3e, 0x20, 0x2, 0x1db, 0x1dd, 0x5, 0x3c, 
    0x1f, 0x2, 0x1dc, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 0x3, 0x2, 
    0x2, 0x2, 0x1dd, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1d6, 0x3, 0x2, 
    0x2, 0x2, 0x1de, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x1e0, 0x1e1, 0x7, 0x1a, 0x2, 0x2, 0x1e1, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x1e2, 0x1e4, 0x5, 0x46, 0x24, 0x2, 0x1e3, 0x1e2, 0x3, 0x2, 0x2, 
    0x2, 0x1e3, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x3, 0x2, 0x2, 
    0x2, 0x1e5, 0x1e6, 0x5, 0x42, 0x22, 0x2, 0x1e6, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x1e7, 0x1e8, 0x8, 0x22, 0x1, 0x2, 0x1e8, 0x1f9, 0x7, 0x60, 0x2, 
    0x2, 0x1e9, 0x1ea, 0x7, 0x32, 0x2, 0x2, 0x1ea, 0x1eb, 0x5, 0x40, 0x21, 
    0x2, 0x1eb, 0x1ec, 0x7, 0x33, 0x2, 0x2, 0x1ec, 0x1f9, 0x3, 0x2, 0x2, 
    0x2, 0x1ed, 0x1ee, 0x7, 0x60, 0x2, 0x2, 0x1ee, 0x1ef, 0x7, 0x49, 0x2, 
    0x2, 0x1ef, 0x1f9, 0x7, 0xe, 0x2, 0x2, 0x1f0, 0x1f2, 0x7, 0x32, 0x2, 
    0x2, 0x1f1, 0x1f3, 0x5, 0x3a, 0x1e, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 0x2, 
    0x2, 0x1f2, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x3, 0x2, 0x2, 
    0x2, 0x1f4, 0x1f5, 0x5, 0x46, 0x24, 0x2, 0x1f5, 0x1f6, 0x5, 0x42, 0x22, 
    0x2, 0x1f6, 0x1f7, 0x7, 0x33, 0x2, 0x2, 0x1f7, 0x1f9, 0x3, 0x2, 0x2, 
    0x2, 0x1f8, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1e9, 0x3, 0x2, 0x2, 
    0x2, 0x1f8, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f0, 0x3, 0x2, 0x2, 
    0x2, 0x1f9, 0x227, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0xc, 0xa, 0x2, 
    0x2, 0x1fb, 0x1fd, 0x7, 0x34, 0x2, 0x2, 0x1fc, 0x1fe, 0x5, 0x48, 0x25, 
    0x2, 0x1fd, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x3, 0x2, 0x2, 
    0x2, 0x1fe, 0x200, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x201, 0x5, 0x24, 0x13, 
    0x2, 0x200, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 
    0x2, 0x201, 0x202, 0x3, 0x2, 0x2, 0x2, 0x202, 0x226, 0x7, 0x35, 0x2, 
    0x2, 0x203, 0x204, 0xc, 0x9, 0x2, 0x2, 0x204, 0x205, 0x7, 0x34, 0x2, 
    0x2, 0x205, 0x207, 0x7, 0x2c, 0x2, 0x2, 0x206, 0x208, 0x5, 0x48, 0x25, 
    0x2, 0x207, 0x206, 0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x3, 0x2, 0x2, 
    0x2, 0x208, 0x209, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x5, 0x24, 0x13, 
    0x2, 0x20a, 0x20b, 0x7, 0x35, 0x2, 0x2, 0x20b, 0x226, 0x3, 0x2, 0x2, 
    0x2, 0x20c, 0x20d, 0xc, 0x8, 0x2, 0x2, 0x20d, 0x20e, 0x7, 0x34, 0x2, 
    0x2, 0x20e, 0x20f, 0x5, 0x48, 0x25, 0x2, 0x20f, 0x210, 0x7, 0x2c, 0x2, 
    0x2, 0x210, 0x211, 0x5, 0x24, 0x13, 0x2, 0x211, 0x212, 0x7, 0x35, 0x2, 
    0x2, 0x212, 0x226, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0xc, 0x7, 0x2, 
    0x2, 0x214, 0x216, 0x7, 0x34, 0x2, 0x2, 0x215, 0x217, 0x5, 0x48, 0x25, 
    0x2, 0x216, 0x215, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x3, 0x2, 0x2, 
    0x2, 0x217, 0x218, 0x3, 0x2, 0x2, 0x2, 0x218, 0x219, 0x7, 0x42, 0x2, 
    0x2, 0x219, 0x226, 0x7, 0x35, 0x2, 0x2, 0x21a, 0x21b, 0xc, 0x6, 0x2, 
    0x2, 0x21b, 0x21c, 0x7, 0x32, 0x2, 0x2, 0x21c, 0x21d, 0x5, 0x4a, 0x26, 
    0x2, 0x21d, 0x21e, 0x7, 0x33, 0x2, 0x2, 0x21e, 0x226, 0x3, 0x2, 0x2, 
    0x2, 0x21f, 0x220, 0xc, 0x5, 0x2, 0x2, 0x220, 0x222, 0x7, 0x32, 0x2, 
    0x2, 0x221, 0x223, 0x5, 0x50, 0x29, 0x2, 0x222, 0x221, 0x3, 0x2, 0x2, 
    0x2, 0x222, 0x223, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 
    0x2, 0x224, 0x226, 0x7, 0x33, 0x2, 0x2, 0x225, 0x1fa, 0x3, 0x2, 0x2, 
    0x2, 0x225, 0x203, 0x3, 0x2, 0x2, 0x2, 0x225, 0x20c, 0x3, 0x2, 0x2, 
    0x2, 0x225, 0x213, 0x3, 0x2, 0x2, 0x2, 0x225, 0x21a, 0x3, 0x2, 0x2, 
    0x2, 0x225, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x226, 0x229, 0x3, 0x2, 0x2, 
    0x2, 0x227, 0x225, 0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 0x3, 0x2, 0x2, 
    0x2, 0x228, 0x43, 0x3, 0x2, 0x2, 0x2, 0x229, 0x227, 0x3, 0x2, 0x2, 0x2, 
    0x22a, 0x230, 0xa, 0x6, 0x2, 0x2, 0x22b, 0x22c, 0x7, 0x32, 0x2, 0x2, 
    0x22c, 0x22d, 0x5, 0x44, 0x23, 0x2, 0x22d, 0x22e, 0x7, 0x33, 0x2, 0x2, 
    0x22e, 0x230, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x22a, 0x3, 0x2, 0x2, 0x2, 
    0x22f, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x230, 0x233, 0x3, 0x2, 0x2, 0x2, 
    0x231, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 0x3, 0x2, 0x2, 0x2, 
    0x232, 0x45, 0x3, 0x2, 0x2, 0x2, 0x233, 0x231, 0x3, 0x2, 0x2, 0x2, 0x234, 
    0x236, 0x7, 0x42, 0x2, 0x2, 0x235, 0x237, 0x5, 0x48, 0x25, 0x2, 0x236, 
    0x235, 0x3, 0x2, 0x2, 0x2, 0x236, 0x237, 0x3, 0x2, 0x2, 0x2, 0x237, 
    0x247, 0x3, 0x2, 0x2, 0x2, 0x238, 0x23a, 0x7, 0x42, 0x2, 0x2, 0x239, 
    0x23b, 0x5, 0x48, 0x25, 0x2, 0x23a, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23a, 
    0x23b, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23c, 
    0x247, 0x5, 0x46, 0x24, 0x2, 0x23d, 0x23f, 0x7, 0x47, 0x2, 0x2, 0x23e, 
    0x240, 0x5, 0x48, 0x25, 0x2, 0x23f, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x23f, 
    0x240, 0x3, 0x2, 0x2, 0x2, 0x240, 0x247, 0x3, 0x2, 0x2, 0x2, 0x241, 
    0x243, 0x7, 0x47, 0x2, 0x2, 0x242, 0x244, 0x5, 0x48, 0x25, 0x2, 0x243, 
    0x242, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 0x3, 0x2, 0x2, 0x2, 0x244, 
    0x245, 0x3, 0x2, 0x2, 0x2, 0x245, 0x247, 0x5, 0x46, 0x24, 0x2, 0x246, 
    0x234, 0x3, 0x2, 0x2, 0x2, 0x246, 0x238, 0x3, 0x2, 0x2, 0x2, 0x246, 
    0x23d, 0x3, 0x2, 0x2, 0x2, 0x246, 0x241, 0x3, 0x2, 0x2, 0x2, 0x247, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x248, 0x249, 0x8, 0x25, 0x1, 0x2, 0x249, 
    0x24a, 0x5, 0x3e, 0x20, 0x2, 0x24a, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24b, 
    0x24c, 0xc, 0x3, 0x2, 0x2, 0x24c, 0x24e, 0x5, 0x3e, 0x20, 0x2, 0x24d, 
    0x24b, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x251, 0x3, 0x2, 0x2, 0x2, 0x24f, 
    0x24d, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 0x3, 0x2, 0x2, 0x2, 0x250, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x251, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x252, 0x258, 
    0x5, 0x4c, 0x27, 0x2, 0x253, 0x254, 0x5, 0x4c, 0x27, 0x2, 0x254, 0x255, 
    0x7, 0x4b, 0x2, 0x2, 0x255, 0x256, 0x7, 0x59, 0x2, 0x2, 0x256, 0x258, 
    0x3, 0x2, 0x2, 0x2, 0x257, 0x252, 0x3, 0x2, 0x2, 0x2, 0x257, 0x253, 
    0x3, 0x2, 0x2, 0x2, 0x258, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 0x8, 
    0x27, 0x1, 0x2, 0x25a, 0x25b, 0x5, 0x4e, 0x28, 0x2, 0x25b, 0x261, 0x3, 
    0x2, 0x2, 0x2, 0x25c, 0x25d, 0xc, 0x3, 0x2, 0x2, 0x25d, 0x25e, 0x7, 
    0x4b, 0x2, 0x2, 0x25e, 0x260, 0x5, 0x4e, 0x28, 0x2, 0x25f, 0x25c, 0x3, 
    0x2, 0x2, 0x2, 0x260, 0x263, 0x3, 0x2, 0x2, 0x2, 0x261, 0x25f, 0x3, 
    0x2, 0x2, 0x2, 0x261, 0x262, 0x3, 0x2, 0x2, 0x2, 0x262, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x263, 0x261, 0x3, 0x2, 0x2, 0x2, 0x264, 0x265, 0x5, 0x2e, 
    0x18, 0x2, 0x265, 0x266, 0x5, 0x40, 0x21, 0x2, 0x266, 0x26c, 0x3, 0x2, 
    0x2, 0x2, 0x267, 0x269, 0x5, 0x30, 0x19, 0x2, 0x268, 0x26a, 0x5, 0x54, 
    0x2b, 0x2, 0x269, 0x268, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x3, 0x2, 
    0x2, 0x2, 0x26a, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x264, 0x3, 0x2, 
    0x2, 0x2, 0x26b, 0x267, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x26d, 0x26e, 0x8, 0x29, 0x1, 0x2, 0x26e, 0x26f, 0x7, 0x60, 0x2, 
    0x2, 0x26f, 0x275, 0x3, 0x2, 0x2, 0x2, 0x270, 0x271, 0xc, 0x3, 0x2, 
    0x2, 0x271, 0x272, 0x7, 0x4b, 0x2, 0x2, 0x272, 0x274, 0x7, 0x60, 0x2, 
    0x2, 0x273, 0x270, 0x3, 0x2, 0x2, 0x2, 0x274, 0x277, 0x3, 0x2, 0x2, 
    0x2, 0x275, 0x273, 0x3, 0x2, 0x2, 0x2, 0x275, 0x276, 0x3, 0x2, 0x2, 
    0x2, 0x276, 0x51, 0x3, 0x2, 0x2, 0x2, 0x277, 0x275, 0x3, 0x2, 0x2, 0x2, 
    0x278, 0x27a, 0x5, 0x3c, 0x1f, 0x2, 0x279, 0x27b, 0x5, 0x54, 0x2b, 0x2, 
    0x27a, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27b, 0x3, 0x2, 0x2, 0x2, 
    0x27b, 0x53, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x282, 0x5, 0x46, 0x24, 0x2, 
    0x27d, 0x27f, 0x5, 0x46, 0x24, 0x2, 0x27e, 0x27d, 0x3, 0x2, 0x2, 0x2, 
    0x27e, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x280, 0x3, 0x2, 0x2, 0x2, 
    0x280, 0x282, 0x5, 0x56, 0x2c, 0x2, 0x281, 0x27c, 0x3, 0x2, 0x2, 0x2, 
    0x281, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x282, 0x55, 0x3, 0x2, 0x2, 0x2, 0x283, 
    0x284, 0x8, 0x2c, 0x1, 0x2, 0x284, 0x285, 0x7, 0x32, 0x2, 0x2, 0x285, 
    0x286, 0x5, 0x54, 0x2b, 0x2, 0x286, 0x287, 0x7, 0x33, 0x2, 0x2, 0x287, 
    0x2a7, 0x3, 0x2, 0x2, 0x2, 0x288, 0x28a, 0x7, 0x34, 0x2, 0x2, 0x289, 
    0x28b, 0x5, 0x48, 0x25, 0x2, 0x28a, 0x289, 0x3, 0x2, 0x2, 0x2, 0x28a, 
    0x28b, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28c, 
    0x28e, 0x5, 0x24, 0x13, 0x2, 0x28d, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28d, 
    0x28e, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x28f, 
    0x2a7, 0x7, 0x35, 0x2, 0x2, 0x290, 0x291, 0x7, 0x34, 0x2, 0x2, 0x291, 
    0x293, 0x7, 0x2c, 0x2, 0x2, 0x292, 0x294, 0x5, 0x48, 0x25, 0x2, 0x293, 
    0x292, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 0x2, 0x2, 0x294, 
    0x295, 0x3, 0x2, 0x2, 0x2, 0x295, 0x296, 0x5, 0x24, 0x13, 0x2, 0x296, 
    0x297, 0x7, 0x35, 0x2, 0x2, 0x297, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x298, 
    0x299, 0x7, 0x34, 0x2, 0x2, 0x299, 0x29a, 0x5, 0x48, 0x25, 0x2, 0x29a, 
    0x29b, 0x7, 0x2c, 0x2, 0x2, 0x29b, 0x29c, 0x5, 0x24, 0x13, 0x2, 0x29c, 
    0x29d, 0x7, 0x35, 0x2, 0x2, 0x29d, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x29e, 
    0x29f, 0x7, 0x34, 0x2, 0x2, 0x29f, 0x2a0, 0x7, 0x42, 0x2, 0x2, 0x2a0, 
    0x2a7, 0x7, 0x35, 0x2, 0x2, 0x2a1, 0x2a3, 0x7, 0x32, 0x2, 0x2, 0x2a2, 
    0x2a4, 0x5, 0x4a, 0x26, 0x2, 0x2a3, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a3, 
    0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a5, 
    0x2a7, 0x7, 0x33, 0x2, 0x2, 0x2a6, 0x283, 0x3, 0x2, 0x2, 0x2, 0x2a6, 
    0x288, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x290, 0x3, 0x2, 0x2, 0x2, 0x2a6, 
    0x298, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a6, 
    0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2a8, 
    0x2a9, 0xc, 0x7, 0x2, 0x2, 0x2a9, 0x2ab, 0x7, 0x34, 0x2, 0x2, 0x2aa, 
    0x2ac, 0x5, 0x48, 0x25, 0x2, 0x2ab, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2ab, 
    0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ad, 
    0x2af, 0x5, 0x24, 0x13, 0x2, 0x2ae, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ae, 
    0x2af, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
    0x2cc, 0x7, 0x35, 0x2, 0x2, 0x2b1, 0x2b2, 0xc, 0x6, 0x2, 0x2, 0x2b2, 
    0x2b3, 0x7, 0x34, 0x2, 0x2, 0x2b3, 0x2b5, 0x7, 0x2c, 0x2, 0x2, 0x2b4, 
    0x2b6, 0x5, 0x48, 0x25, 0x2, 0x2b5, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b5, 
    0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b7, 
    0x2b8, 0x5, 0x24, 0x13, 0x2, 0x2b8, 0x2b9, 0x7, 0x35, 0x2, 0x2, 0x2b9, 
    0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 0xc, 0x5, 0x2, 0x2, 0x2bb, 
    0x2bc, 0x7, 0x34, 0x2, 0x2, 0x2bc, 0x2bd, 0x5, 0x48, 0x25, 0x2, 0x2bd, 
    0x2be, 0x7, 0x2c, 0x2, 0x2, 0x2be, 0x2bf, 0x5, 0x24, 0x13, 0x2, 0x2bf, 
    0x2c0, 0x7, 0x35, 0x2, 0x2, 0x2c0, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2c1, 
    0x2c2, 0xc, 0x4, 0x2, 0x2, 0x2c2, 0x2c3, 0x7, 0x34, 0x2, 0x2, 0x2c3, 
    0x2c4, 0x7, 0x42, 0x2, 0x2, 0x2c4, 0x2cc, 0x7, 0x35, 0x2, 0x2, 0x2c5, 
    0x2c6, 0xc, 0x3, 0x2, 0x2, 0x2c6, 0x2c8, 0x7, 0x32, 0x2, 0x2, 0x2c7, 
    0x2c9, 0x5, 0x4a, 0x26, 0x2, 0x2c8, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
    0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2ca, 
    0x2cc, 0x7, 0x33, 0x2, 0x2, 0x2cb, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2cb, 
    0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2cb, 
    0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2cc, 
    0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cd, 
    0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x57, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2cd, 
    0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2db, 0x5, 0x24, 0x13, 0x2, 0x2d1, 0x2d2, 
    0x7, 0x36, 0x2, 0x2, 0x2d2, 0x2d3, 0x5, 0x5a, 0x2e, 0x2, 0x2d3, 0x2d4, 
    0x7, 0x37, 0x2, 0x2, 0x2d4, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d6, 
    0x7, 0x36, 0x2, 0x2, 0x2d6, 0x2d7, 0x5, 0x5a, 0x2e, 0x2, 0x2d7, 0x2d8, 
    0x7, 0x4b, 0x2, 0x2, 0x2d8, 0x2d9, 0x7, 0x37, 0x2, 0x2, 0x2d9, 0x2db, 
    0x3, 0x2, 0x2, 0x2, 0x2da, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2d1, 
    0x3, 0x2, 0x2, 0x2, 0x2da, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x2dc, 0x2de, 0x8, 0x2e, 0x1, 0x2, 0x2dd, 0x2df, 0x5, 
    0x5c, 0x2f, 0x2, 0x2de, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x3, 
    0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e1, 0x5, 
    0x58, 0x2d, 0x2, 0x2e1, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e3, 0xc, 
    0x3, 0x2, 0x2, 0x2e3, 0x2e5, 0x7, 0x4b, 0x2, 0x2, 0x2e4, 0x2e6, 0x5, 
    0x5c, 0x2f, 0x2, 0x2e5, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0x3, 
    0x2, 0x2, 0x2, 0x2e6, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e9, 0x5, 
    0x58, 0x2d, 0x2, 0x2e8, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2ec, 0x3, 
    0x2, 0x2, 0x2, 0x2ea, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 0x3, 
    0x2, 0x2, 0x2, 0x2eb, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ea, 0x3, 0x2, 
    0x2, 0x2, 0x2ed, 0x2ee, 0x5, 0x5e, 0x30, 0x2, 0x2ee, 0x2ef, 0x7, 0x4c, 
    0x2, 0x2, 0x2ef, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 0x8, 0x30, 
    0x1, 0x2, 0x2f1, 0x2f2, 0x5, 0x60, 0x31, 0x2, 0x2f2, 0x2f7, 0x3, 0x2, 
    0x2, 0x2, 0x2f3, 0x2f4, 0xc, 0x3, 0x2, 0x2, 0x2f4, 0x2f6, 0x5, 0x60, 
    0x31, 0x2, 0x2f5, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f9, 0x3, 0x2, 
    0x2, 0x2, 0x2f7, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 
    0x2, 0x2, 0x2f8, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2f7, 0x3, 0x2, 0x2, 
    0x2, 0x2fa, 0x2fb, 0x7, 0x34, 0x2, 0x2, 0x2fb, 0x2fc, 0x5, 0x2a, 0x16, 
    0x2, 0x2fc, 0x2fd, 0x7, 0x35, 0x2, 0x2, 0x2fd, 0x301, 0x3, 0x2, 0x2, 
    0x2, 0x2fe, 0x2ff, 0x7, 0x58, 0x2, 0x2, 0x2ff, 0x301, 0x7, 0x60, 0x2, 
    0x2, 0x300, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x300, 0x2fe, 0x3, 0x2, 0x2, 
    0x2, 0x301, 0x61, 0x3, 0x2, 0x2, 0x2, 0x302, 0x309, 0x5, 0x64, 0x33, 
    0x2, 0x303, 0x309, 0x5, 0x66, 0x34, 0x2, 0x304, 0x309, 0x5, 0x6c, 0x37, 
    0x2, 0x305, 0x309, 0x5, 0x6e, 0x38, 0x2, 0x306, 0x309, 0x5, 0x70, 0x39, 
    0x2, 0x307, 0x309, 0x5, 0x78, 0x3d, 0x2, 0x308, 0x302, 0x3, 0x2, 0x2, 
    0x2, 0x308, 0x303, 0x3, 0x2, 0x2, 0x2, 0x308, 0x304, 0x3, 0x2, 0x2, 
    0x2, 0x308, 0x305, 0x3, 0x2, 0x2, 0x2, 0x308, 0x306, 0x3, 0x2, 0x2, 
    0x2, 0x308, 0x307, 0x3, 0x2, 0x2, 0x2, 0x309, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x30a, 0x30b, 0x7, 0x60, 0x2, 0x2, 0x30b, 0x30c, 0x7, 0x49, 0x2, 0x2, 
    0x30c, 0x316, 0x5, 0x62, 0x32, 0x2, 0x30d, 0x30e, 0x7, 0x18, 0x2, 0x2, 
    0x30e, 0x30f, 0x5, 0x2a, 0x16, 0x2, 0x30f, 0x310, 0x7, 0x49, 0x2, 0x2, 
    0x310, 0x311, 0x5, 0x62, 0x32, 0x2, 0x311, 0x316, 0x3, 0x2, 0x2, 0x2, 
    0x312, 0x313, 0x7, 0x1d, 0x2, 0x2, 0x313, 0x314, 0x7, 0x49, 0x2, 0x2, 
    0x314, 0x316, 0x5, 0x62, 0x32, 0x2, 0x315, 0x30a, 0x3, 0x2, 0x2, 0x2, 
    0x315, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x315, 0x312, 0x3, 0x2, 0x2, 0x2, 
    0x316, 0x65, 0x3, 0x2, 0x2, 0x2, 0x317, 0x319, 0x7, 0x36, 0x2, 0x2, 
    0x318, 0x31a, 0x5, 0x68, 0x35, 0x2, 0x319, 0x318, 0x3, 0x2, 0x2, 0x2, 
    0x319, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31b, 0x3, 0x2, 0x2, 0x2, 
    0x31b, 0x31c, 0x7, 0x37, 0x2, 0x2, 0x31c, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x31d, 0x31e, 0x8, 0x35, 0x1, 0x2, 0x31e, 0x31f, 0x5, 0x6a, 0x36, 0x2, 
    0x31f, 0x324, 0x3, 0x2, 0x2, 0x2, 0x320, 0x321, 0xc, 0x3, 0x2, 0x2, 
    0x321, 0x323, 0x5, 0x6a, 0x36, 0x2, 0x322, 0x320, 0x3, 0x2, 0x2, 0x2, 
    0x323, 0x326, 0x3, 0x2, 0x2, 0x2, 0x324, 0x322, 0x3, 0x2, 0x2, 0x2, 
    0x324, 0x325, 0x3, 0x2, 0x2, 0x2, 0x325, 0x69, 0x3, 0x2, 0x2, 0x2, 0x326, 
    0x324, 0x3, 0x2, 0x2, 0x2, 0x327, 0x32a, 0x5, 0x62, 0x32, 0x2, 0x328, 
    0x32a, 0x5, 0x2c, 0x17, 0x2, 0x329, 0x327, 0x3, 0x2, 0x2, 0x2, 0x329, 
    0x328, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32d, 
    0x5, 0x28, 0x15, 0x2, 0x32c, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32d, 
    0x3, 0x2, 0x2, 0x2, 0x32d, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32f, 
    0x7, 0x4a, 0x2, 0x2, 0x32f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x330, 0x331, 
    0x7, 0x23, 0x2, 0x2, 0x331, 0x332, 0x7, 0x32, 0x2, 0x2, 0x332, 0x333, 
    0x5, 0x28, 0x15, 0x2, 0x333, 0x334, 0x7, 0x33, 0x2, 0x2, 0x334, 0x337, 
    0x5, 0x62, 0x32, 0x2, 0x335, 0x336, 0x7, 0x1f, 0x2, 0x2, 0x336, 0x338, 
    0x5, 0x62, 0x32, 0x2, 0x337, 0x335, 0x3, 0x2, 0x2, 0x2, 0x337, 0x338, 
    0x3, 0x2, 0x2, 0x2, 0x338, 0x340, 0x3, 0x2, 0x2, 0x2, 0x339, 0x33a, 
    0x7, 0x2d, 0x2, 0x2, 0x33a, 0x33b, 0x7, 0x32, 0x2, 0x2, 0x33b, 0x33c, 
    0x5, 0x28, 0x15, 0x2, 0x33c, 0x33d, 0x7, 0x33, 0x2, 0x2, 0x33d, 0x33e, 
    0x5, 0x62, 0x32, 0x2, 0x33e, 0x340, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x330, 
    0x3, 0x2, 0x2, 0x2, 0x33f, 0x339, 0x3, 0x2, 0x2, 0x2, 0x340, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x341, 0x342, 0x7, 0x31, 0x2, 0x2, 0x342, 0x343, 0x7, 
    0x32, 0x2, 0x2, 0x343, 0x344, 0x5, 0x28, 0x15, 0x2, 0x344, 0x345, 0x7, 
    0x33, 0x2, 0x2, 0x345, 0x346, 0x5, 0x62, 0x32, 0x2, 0x346, 0x34e, 0x3, 
    0x2, 0x2, 0x2, 0x347, 0x348, 0x7, 0x22, 0x2, 0x2, 0x348, 0x349, 0x7, 
    0x32, 0x2, 0x2, 0x349, 0x34a, 0x5, 0x72, 0x3a, 0x2, 0x34a, 0x34b, 0x7, 
    0x33, 0x2, 0x2, 0x34b, 0x34c, 0x5, 0x62, 0x32, 0x2, 0x34c, 0x34e, 0x3, 
    0x2, 0x2, 0x2, 0x34d, 0x341, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x347, 0x3, 
    0x2, 0x2, 0x2, 0x34e, 0x71, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x350, 0x5, 0x74, 
    0x3b, 0x2, 0x350, 0x352, 0x7, 0x4a, 0x2, 0x2, 0x351, 0x353, 0x5, 0x76, 
    0x3c, 0x2, 0x352, 0x351, 0x3, 0x2, 0x2, 0x2, 0x352, 0x353, 0x3, 0x2, 
    0x2, 0x2, 0x353, 0x354, 0x3, 0x2, 0x2, 0x2, 0x354, 0x356, 0x7, 0x4a, 
    0x2, 0x2, 0x355, 0x357, 0x5, 0x76, 0x3c, 0x2, 0x356, 0x355, 0x3, 0x2, 
    0x2, 0x2, 0x356, 0x357, 0x3, 0x2, 0x2, 0x2, 0x357, 0x364, 0x3, 0x2, 
    0x2, 0x2, 0x358, 0x35a, 0x5, 0x28, 0x15, 0x2, 0x359, 0x358, 0x3, 0x2, 
    0x2, 0x2, 0x359, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35b, 0x3, 0x2, 
    0x2, 0x2, 0x35b, 0x35d, 0x7, 0x4a, 0x2, 0x2, 0x35c, 0x35e, 0x5, 0x76, 
    0x3c, 0x2, 0x35d, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 0x3, 0x2, 
    0x2, 0x2, 0x35e, 0x35f, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x361, 0x7, 0x4a, 
    0x2, 0x2, 0x360, 0x362, 0x5, 0x76, 0x3c, 0x2, 0x361, 0x360, 0x3, 0x2, 
    0x2, 0x2, 0x361, 0x362, 0x3, 0x2, 0x2, 0x2, 0x362, 0x364, 0x3, 0x2, 
    0x2, 0x2, 0x363, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x363, 0x359, 0x3, 0x2, 
    0x2, 0x2, 0x364, 0x73, 0x3, 0x2, 0x2, 0x2, 0x365, 0x366, 0x5, 0x2e, 
    0x18, 0x2, 0x366, 0x367, 0x5, 0x34, 0x1b, 0x2, 0x367, 0x36a, 0x3, 0x2, 
    0x2, 0x2, 0x368, 0x36a, 0x5, 0x2e, 0x18, 0x2, 0x369, 0x365, 0x3, 0x2, 
    0x2, 0x2, 0x369, 0x368, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x36b, 0x36c, 0x8, 0x3c, 0x1, 0x2, 0x36c, 0x36d, 0x5, 0x24, 0x13, 
    0x2, 0x36d, 0x373, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36f, 0xc, 0x3, 0x2, 
    0x2, 0x36f, 0x370, 0x7, 0x4b, 0x2, 0x2, 0x370, 0x372, 0x5, 0x24, 0x13, 
    0x2, 0x371, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x372, 0x375, 0x3, 0x2, 0x2, 
    0x2, 0x373, 0x371, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x3, 0x2, 0x2, 
    0x2, 0x374, 0x77, 0x3, 0x2, 0x2, 0x2, 0x375, 0x373, 0x3, 0x2, 0x2, 0x2, 
    0x376, 0x377, 0x7, 0xc, 0x2, 0x2, 0x377, 0x378, 0x7, 0x60, 0x2, 0x2, 
    0x378, 0x387, 0x7, 0x4a, 0x2, 0x2, 0x379, 0x37a, 0x7, 0x1b, 0x2, 0x2, 
    0x37a, 0x387, 0x7, 0x4a, 0x2, 0x2, 0x37b, 0x37c, 0x7, 0x17, 0x2, 0x2, 
    0x37c, 0x387, 0x7, 0x4a, 0x2, 0x2, 0x37d, 0x37f, 0x7, 0x28, 0x2, 0x2, 
    0x37e, 0x380, 0x5, 0x28, 0x15, 0x2, 0x37f, 0x37e, 0x3, 0x2, 0x2, 0x2, 
    0x37f, 0x380, 0x3, 0x2, 0x2, 0x2, 0x380, 0x381, 0x3, 0x2, 0x2, 0x2, 
    0x381, 0x387, 0x7, 0x4a, 0x2, 0x2, 0x382, 0x383, 0x7, 0xc, 0x2, 0x2, 
    0x383, 0x384, 0x5, 0x8, 0x5, 0x2, 0x384, 0x385, 0x7, 0x4a, 0x2, 0x2, 
    0x385, 0x387, 0x3, 0x2, 0x2, 0x2, 0x386, 0x376, 0x3, 0x2, 0x2, 0x2, 
    0x386, 0x379, 0x3, 0x2, 0x2, 0x2, 0x386, 0x37b, 0x3, 0x2, 0x2, 0x2, 
    0x386, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x386, 0x382, 0x3, 0x2, 0x2, 0x2, 
    0x387, 0x79, 0x3, 0x2, 0x2, 0x2, 0x388, 0x38a, 0x5, 0x7c, 0x3f, 0x2, 
    0x389, 0x388, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38a, 0x3, 0x2, 0x2, 0x2, 
    0x38a, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x38b, 0x38c, 0x7, 0x2, 0x2, 0x3, 
    0x38c, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x38e, 0x8, 0x3f, 0x1, 0x2, 
    0x38e, 0x38f, 0x5, 0x7e, 0x40, 0x2, 0x38f, 0x394, 0x3, 0x2, 0x2, 0x2, 
    0x390, 0x391, 0xc, 0x3, 0x2, 0x2, 0x391, 0x393, 0x5, 0x7e, 0x40, 0x2, 
    0x392, 0x390, 0x3, 0x2, 0x2, 0x2, 0x393, 0x396, 0x3, 0x2, 0x2, 0x2, 
    0x394, 0x392, 0x3, 0x2, 0x2, 0x2, 0x394, 0x395, 0x3, 0x2, 0x2, 0x2, 
    0x395, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x396, 0x394, 0x3, 0x2, 0x2, 0x2, 0x397, 
    0x39b, 0x5, 0x80, 0x41, 0x2, 0x398, 0x39b, 0x5, 0x2c, 0x17, 0x2, 0x399, 
    0x39b, 0x7, 0x4a, 0x2, 0x2, 0x39a, 0x397, 0x3, 0x2, 0x2, 0x2, 0x39a, 
    0x398, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x399, 0x3, 0x2, 0x2, 0x2, 0x39b, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39e, 0x5, 0x2e, 0x18, 0x2, 0x39d, 
    0x39c, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x39e, 
    0x39f, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a1, 0x5, 0x40, 0x21, 0x2, 0x3a0, 
    0x3a2, 0x5, 0x82, 0x42, 0x2, 0x3a1, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a1, 
    0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3a2, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a3, 
    0x3a4, 0x5, 0x66, 0x34, 0x2, 0x3a4, 0x81, 0x3, 0x2, 0x2, 0x2, 0x3a5, 
    0x3a6, 0x8, 0x42, 0x1, 0x2, 0x3a6, 0x3a7, 0x5, 0x2c, 0x17, 0x2, 0x3a7, 
    0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a9, 0xc, 0x3, 0x2, 0x2, 0x3a9, 
    0x3ab, 0x5, 0x2c, 0x17, 0x2, 0x3aa, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3ac, 
    0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x83, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3ac, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x89, 0x8f, 0xb3, 0xbd, 0xca, 0xcc, 0xd7, 
    0xf0, 0x101, 0x10f, 0x111, 0x11d, 0x11f, 0x12b, 0x12d, 0x13f, 0x141, 
    0x14d, 0x14f, 0x15a, 0x165, 0x170, 0x17b, 0x186, 0x18f, 0x197, 0x1a3, 
    0x1af, 0x1b4, 0x1b9, 0x1be, 0x1c8, 0x1d0, 0x1d8, 0x1dc, 0x1de, 0x1e3, 
    0x1f2, 0x1f8, 0x1fd, 0x200, 0x207, 0x216, 0x222, 0x225, 0x227, 0x22f, 
    0x231, 0x236, 0x23a, 0x23f, 0x243, 0x246, 0x24f, 0x257, 0x261, 0x269, 
    0x26b, 0x275, 0x27a, 0x27e, 0x281, 0x28a, 0x28d, 0x293, 0x2a3, 0x2a6, 
    0x2ab, 0x2ae, 0x2b5, 0x2c8, 0x2cb, 0x2cd, 0x2da, 0x2de, 0x2e5, 0x2ea, 
    0x2f7, 0x300, 0x308, 0x315, 0x319, 0x324, 0x329, 0x32c, 0x337, 0x33f, 
    0x34d, 0x352, 0x356, 0x359, 0x35d, 0x361, 0x363, 0x369, 0x373, 0x37f, 
    0x386, 0x389, 0x394, 0x39a, 0x39d, 0x3a1, 0x3ac, 
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
