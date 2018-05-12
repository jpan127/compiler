
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from grammars/Pcl2.g4 by ANTLR 4.7


#include "Pcl2Listener.h"
#include "Pcl2Visitor.h"

#include "Pcl2Parser.h"


using namespace antlrcpp;
using namespace antlr4;

Pcl2Parser::Pcl2Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

Pcl2Parser::~Pcl2Parser() {
  delete _interpreter;
}

std::string Pcl2Parser::getGrammarFileName() const {
  return "Pcl2.g4";
}

const std::vector<std::string>& Pcl2Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& Pcl2Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

Pcl2Parser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::CompilationUnitContext::EOF() {
  return getToken(Pcl2Parser::EOF, 0);
}

Pcl2Parser::TranslationUnitContext* Pcl2Parser::CompilationUnitContext::translationUnit() {
  return getRuleContext<Pcl2Parser::TranslationUnitContext>(0);
}


size_t Pcl2Parser::CompilationUnitContext::getRuleIndex() const {
  return Pcl2Parser::RuleCompilationUnit;
}

void Pcl2Parser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void Pcl2Parser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any Pcl2Parser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::CompilationUnitContext* Pcl2Parser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, Pcl2Parser::RuleCompilationUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Void)
      | (1ULL << Pcl2Parser::Semi))) != 0)) {
      setState(44);
      translationUnit(0);
    }
    setState(47);
    match(Pcl2Parser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranslationUnitContext ------------------------------------------------------------------

Pcl2Parser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::ExternalDeclarationContext* Pcl2Parser::TranslationUnitContext::externalDeclaration() {
  return getRuleContext<Pcl2Parser::ExternalDeclarationContext>(0);
}

Pcl2Parser::TranslationUnitContext* Pcl2Parser::TranslationUnitContext::translationUnit() {
  return getRuleContext<Pcl2Parser::TranslationUnitContext>(0);
}


size_t Pcl2Parser::TranslationUnitContext::getRuleIndex() const {
  return Pcl2Parser::RuleTranslationUnit;
}

void Pcl2Parser::TranslationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranslationUnit(this);
}

void Pcl2Parser::TranslationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranslationUnit(this);
}


antlrcpp::Any Pcl2Parser::TranslationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitTranslationUnit(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::TranslationUnitContext* Pcl2Parser::translationUnit() {
   return translationUnit(0);
}

Pcl2Parser::TranslationUnitContext* Pcl2Parser::translationUnit(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, parentState);
  Pcl2Parser::TranslationUnitContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, Pcl2Parser::RuleTranslationUnit, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(50);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(56);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(52);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(53);
        externalDeclaration(); 
      }
      setState(58);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
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

Pcl2Parser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::FunctionDefinitionContext* Pcl2Parser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<Pcl2Parser::FunctionDefinitionContext>(0);
}

Pcl2Parser::DeclarationContext* Pcl2Parser::ExternalDeclarationContext::declaration() {
  return getRuleContext<Pcl2Parser::DeclarationContext>(0);
}

tree::TerminalNode* Pcl2Parser::ExternalDeclarationContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}


size_t Pcl2Parser::ExternalDeclarationContext::getRuleIndex() const {
  return Pcl2Parser::RuleExternalDeclaration;
}

void Pcl2Parser::ExternalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternalDeclaration(this);
}

void Pcl2Parser::ExternalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternalDeclaration(this);
}


antlrcpp::Any Pcl2Parser::ExternalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitExternalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ExternalDeclarationContext* Pcl2Parser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, Pcl2Parser::RuleExternalDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(59);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(60);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(61);
      match(Pcl2Parser::Semi);
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

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

Pcl2Parser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::IntegerConstant() {
  return getToken(Pcl2Parser::IntegerConstant, 0);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::FloatConstant() {
  return getToken(Pcl2Parser::FloatConstant, 0);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::PrimaryExpressionContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}


size_t Pcl2Parser::PrimaryExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RulePrimaryExpression;
}

void Pcl2Parser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void Pcl2Parser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


antlrcpp::Any Pcl2Parser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::PrimaryExpressionContext* Pcl2Parser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, Pcl2Parser::RulePrimaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(64);
        match(Pcl2Parser::Identifier);
        break;
      }

      case Pcl2Parser::IntegerConstant: {
        enterOuterAlt(_localctx, 2);
        setState(65);
        match(Pcl2Parser::IntegerConstant);
        break;
      }

      case Pcl2Parser::FloatConstant: {
        enterOuterAlt(_localctx, 3);
        setState(66);
        match(Pcl2Parser::FloatConstant);
        break;
      }

      case Pcl2Parser::LeftParen: {
        enterOuterAlt(_localctx, 4);
        setState(67);
        match(Pcl2Parser::LeftParen);
        setState(68);
        expression(0);
        setState(69);
        match(Pcl2Parser::RightParen);
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

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

Pcl2Parser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::TypeSpecifierContext* Pcl2Parser::FunctionDefinitionContext::typeSpecifier() {
  return getRuleContext<Pcl2Parser::TypeSpecifierContext>(0);
}

tree::TerminalNode* Pcl2Parser::FunctionDefinitionContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

Pcl2Parser::ParamaterTypeListContext* Pcl2Parser::FunctionDefinitionContext::paramaterTypeList() {
  return getRuleContext<Pcl2Parser::ParamaterTypeListContext>(0);
}

Pcl2Parser::CompoundStatementContext* Pcl2Parser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<Pcl2Parser::CompoundStatementContext>(0);
}


size_t Pcl2Parser::FunctionDefinitionContext::getRuleIndex() const {
  return Pcl2Parser::RuleFunctionDefinition;
}

void Pcl2Parser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void Pcl2Parser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


antlrcpp::Any Pcl2Parser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::FunctionDefinitionContext* Pcl2Parser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 8, Pcl2Parser::RuleFunctionDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    typeSpecifier();
    setState(74);
    match(Pcl2Parser::Identifier);
    setState(75);
    paramaterTypeList();
    setState(76);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

Pcl2Parser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::FunctionCallContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionCallContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionCallContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionCallContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}

Pcl2Parser::IdentifierListContext* Pcl2Parser::FunctionCallContext::identifierList() {
  return getRuleContext<Pcl2Parser::IdentifierListContext>(0);
}


size_t Pcl2Parser::FunctionCallContext::getRuleIndex() const {
  return Pcl2Parser::RuleFunctionCall;
}

void Pcl2Parser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void Pcl2Parser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


antlrcpp::Any Pcl2Parser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::FunctionCallContext* Pcl2Parser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 10, Pcl2Parser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(Pcl2Parser::Identifier);
    setState(79);
    match(Pcl2Parser::LeftParen);
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Pcl2Parser::Identifier) {
      setState(80);
      identifierList();
    }
    setState(83);
    match(Pcl2Parser::RightParen);
    setState(84);
    match(Pcl2Parser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionReturnContext ------------------------------------------------------------------

Pcl2Parser::FunctionReturnContext::FunctionReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::FunctionReturnContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionReturnContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

tree::TerminalNode* Pcl2Parser::FunctionReturnContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

Pcl2Parser::IdentifierListContext* Pcl2Parser::FunctionReturnContext::identifierList() {
  return getRuleContext<Pcl2Parser::IdentifierListContext>(0);
}


size_t Pcl2Parser::FunctionReturnContext::getRuleIndex() const {
  return Pcl2Parser::RuleFunctionReturn;
}

void Pcl2Parser::FunctionReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionReturn(this);
}

void Pcl2Parser::FunctionReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionReturn(this);
}


antlrcpp::Any Pcl2Parser::FunctionReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitFunctionReturn(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::FunctionReturnContext* Pcl2Parser::functionReturn() {
  FunctionReturnContext *_localctx = _tracker.createInstance<FunctionReturnContext>(_ctx, getState());
  enterRule(_localctx, 12, Pcl2Parser::RuleFunctionReturn);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(Pcl2Parser::Identifier);
    setState(87);
    match(Pcl2Parser::LeftParen);
    setState(89);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Pcl2Parser::Identifier) {
      setState(88);
      identifierList();
    }
    setState(91);
    match(Pcl2Parser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

Pcl2Parser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> Pcl2Parser::IdentifierListContext::Identifier() {
  return getTokens(Pcl2Parser::Identifier);
}

tree::TerminalNode* Pcl2Parser::IdentifierListContext::Identifier(size_t i) {
  return getToken(Pcl2Parser::Identifier, i);
}

std::vector<tree::TerminalNode *> Pcl2Parser::IdentifierListContext::Comma() {
  return getTokens(Pcl2Parser::Comma);
}

tree::TerminalNode* Pcl2Parser::IdentifierListContext::Comma(size_t i) {
  return getToken(Pcl2Parser::Comma, i);
}


size_t Pcl2Parser::IdentifierListContext::getRuleIndex() const {
  return Pcl2Parser::RuleIdentifierList;
}

void Pcl2Parser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void Pcl2Parser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}


antlrcpp::Any Pcl2Parser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::IdentifierListContext* Pcl2Parser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 14, Pcl2Parser::RuleIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(Pcl2Parser::Identifier);
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Pcl2Parser::Comma) {
      setState(94);
      match(Pcl2Parser::Comma);
      setState(95);
      match(Pcl2Parser::Identifier);
      setState(100);
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

//----------------- CompoundStatementContext ------------------------------------------------------------------

Pcl2Parser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::CompoundStatementContext::LeftBrace() {
  return getToken(Pcl2Parser::LeftBrace, 0);
}

tree::TerminalNode* Pcl2Parser::CompoundStatementContext::RightBrace() {
  return getToken(Pcl2Parser::RightBrace, 0);
}

Pcl2Parser::BlockItemListContext* Pcl2Parser::CompoundStatementContext::blockItemList() {
  return getRuleContext<Pcl2Parser::BlockItemListContext>(0);
}


size_t Pcl2Parser::CompoundStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleCompoundStatement;
}

void Pcl2Parser::CompoundStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void Pcl2Parser::CompoundStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}


antlrcpp::Any Pcl2Parser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::CompoundStatementContext* Pcl2Parser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, Pcl2Parser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(Pcl2Parser::LeftBrace);
    setState(103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::If)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Void)
      | (1ULL << Pcl2Parser::While)
      | (1ULL << Pcl2Parser::LeftParen)
      | (1ULL << Pcl2Parser::LeftBrace)
      | (1ULL << Pcl2Parser::Semi))) != 0) || ((((_la - 79) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 79)) & ((1ULL << (Pcl2Parser::IntegerConstant - 79))
      | (1ULL << (Pcl2Parser::FloatConstant - 79))
      | (1ULL << (Pcl2Parser::Identifier - 79)))) != 0)) {
      setState(102);
      blockItemList(0);
    }
    setState(105);
    match(Pcl2Parser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemListContext ------------------------------------------------------------------

Pcl2Parser::BlockItemListContext::BlockItemListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::BlockItemContext* Pcl2Parser::BlockItemListContext::blockItem() {
  return getRuleContext<Pcl2Parser::BlockItemContext>(0);
}

Pcl2Parser::BlockItemListContext* Pcl2Parser::BlockItemListContext::blockItemList() {
  return getRuleContext<Pcl2Parser::BlockItemListContext>(0);
}


size_t Pcl2Parser::BlockItemListContext::getRuleIndex() const {
  return Pcl2Parser::RuleBlockItemList;
}

void Pcl2Parser::BlockItemListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItemList(this);
}

void Pcl2Parser::BlockItemListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItemList(this);
}


antlrcpp::Any Pcl2Parser::BlockItemListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitBlockItemList(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::BlockItemListContext* Pcl2Parser::blockItemList() {
   return blockItemList(0);
}

Pcl2Parser::BlockItemListContext* Pcl2Parser::blockItemList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::BlockItemListContext *_localctx = _tracker.createInstance<BlockItemListContext>(_ctx, parentState);
  Pcl2Parser::BlockItemListContext *previousContext = _localctx;
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, Pcl2Parser::RuleBlockItemList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(108);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(114);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(110);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(111);
        blockItem(); 
      }
      setState(116);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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

Pcl2Parser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::StatementContext* Pcl2Parser::BlockItemContext::statement() {
  return getRuleContext<Pcl2Parser::StatementContext>(0);
}

Pcl2Parser::DeclarationContext* Pcl2Parser::BlockItemContext::declaration() {
  return getRuleContext<Pcl2Parser::DeclarationContext>(0);
}


size_t Pcl2Parser::BlockItemContext::getRuleIndex() const {
  return Pcl2Parser::RuleBlockItem;
}

void Pcl2Parser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void Pcl2Parser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}


antlrcpp::Any Pcl2Parser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::BlockItemContext* Pcl2Parser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 20, Pcl2Parser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::If:
      case Pcl2Parser::While:
      case Pcl2Parser::LeftParen:
      case Pcl2Parser::LeftBrace:
      case Pcl2Parser::Semi:
      case Pcl2Parser::IntegerConstant:
      case Pcl2Parser::FloatConstant:
      case Pcl2Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(117);
        statement();
        break;
      }

      case Pcl2Parser::Char:
      case Pcl2Parser::Bool:
      case Pcl2Parser::Double:
      case Pcl2Parser::Float:
      case Pcl2Parser::Int:
      case Pcl2Parser::Void: {
        enterOuterAlt(_localctx, 2);
        setState(118);
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

//----------------- StatementContext ------------------------------------------------------------------

Pcl2Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::CompoundStatementContext* Pcl2Parser::StatementContext::compoundStatement() {
  return getRuleContext<Pcl2Parser::CompoundStatementContext>(0);
}

Pcl2Parser::ExpressionStatementContext* Pcl2Parser::StatementContext::expressionStatement() {
  return getRuleContext<Pcl2Parser::ExpressionStatementContext>(0);
}

Pcl2Parser::SelectionStatementContext* Pcl2Parser::StatementContext::selectionStatement() {
  return getRuleContext<Pcl2Parser::SelectionStatementContext>(0);
}

Pcl2Parser::IterationStatementContext* Pcl2Parser::StatementContext::iterationStatement() {
  return getRuleContext<Pcl2Parser::IterationStatementContext>(0);
}

Pcl2Parser::AssignmentStatementContext* Pcl2Parser::StatementContext::assignmentStatement() {
  return getRuleContext<Pcl2Parser::AssignmentStatementContext>(0);
}


size_t Pcl2Parser::StatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleStatement;
}

void Pcl2Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void Pcl2Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any Pcl2Parser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::StatementContext* Pcl2Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, Pcl2Parser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(121);
      compoundStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(122);
      expressionStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(123);
      selectionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(124);
      iterationStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(125);
      assignmentStatement();
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

//----------------- AssignmentStatementContext ------------------------------------------------------------------

Pcl2Parser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::AssignmentStatementContext::assignmentExpression() {
  return getRuleContext<Pcl2Parser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::AssignmentStatementContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}


size_t Pcl2Parser::AssignmentStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleAssignmentStatement;
}

void Pcl2Parser::AssignmentStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentStatement(this);
}

void Pcl2Parser::AssignmentStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentStatement(this);
}


antlrcpp::Any Pcl2Parser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::AssignmentStatementContext* Pcl2Parser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, Pcl2Parser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    assignmentExpression();
    setState(129);
    match(Pcl2Parser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

Pcl2Parser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::ExpressionStatementContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::ExpressionStatementContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}


size_t Pcl2Parser::ExpressionStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleExpressionStatement;
}

void Pcl2Parser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void Pcl2Parser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


antlrcpp::Any Pcl2Parser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ExpressionStatementContext* Pcl2Parser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, Pcl2Parser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 37) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 37)) & ((1ULL << (Pcl2Parser::LeftParen - 37))
      | (1ULL << (Pcl2Parser::IntegerConstant - 37))
      | (1ULL << (Pcl2Parser::FloatConstant - 37))
      | (1ULL << (Pcl2Parser::Identifier - 37)))) != 0)) {
      setState(131);
      expression(0);
    }
    setState(134);
    match(Pcl2Parser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

Pcl2Parser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::SelectionStatementContext::If() {
  return getToken(Pcl2Parser::If, 0);
}

tree::TerminalNode* Pcl2Parser::SelectionStatementContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::SelectionStatementContext::conditionalExpression() {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::SelectionStatementContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

Pcl2Parser::StatementContext* Pcl2Parser::SelectionStatementContext::statement() {
  return getRuleContext<Pcl2Parser::StatementContext>(0);
}


size_t Pcl2Parser::SelectionStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleSelectionStatement;
}

void Pcl2Parser::SelectionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectionStatement(this);
}

void Pcl2Parser::SelectionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectionStatement(this);
}


antlrcpp::Any Pcl2Parser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::SelectionStatementContext* Pcl2Parser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, Pcl2Parser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(Pcl2Parser::If);
    setState(137);
    match(Pcl2Parser::LeftParen);
    setState(138);
    conditionalExpression(0);
    setState(139);
    match(Pcl2Parser::RightParen);
    setState(140);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

Pcl2Parser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::IterationStatementContext::While() {
  return getToken(Pcl2Parser::While, 0);
}

tree::TerminalNode* Pcl2Parser::IterationStatementContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::IterationStatementContext::conditionalExpression() {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::IterationStatementContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

Pcl2Parser::StatementContext* Pcl2Parser::IterationStatementContext::statement() {
  return getRuleContext<Pcl2Parser::StatementContext>(0);
}


size_t Pcl2Parser::IterationStatementContext::getRuleIndex() const {
  return Pcl2Parser::RuleIterationStatement;
}

void Pcl2Parser::IterationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStatement(this);
}

void Pcl2Parser::IterationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStatement(this);
}


antlrcpp::Any Pcl2Parser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::IterationStatementContext* Pcl2Parser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, Pcl2Parser::RuleIterationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(Pcl2Parser::While);
    setState(143);
    match(Pcl2Parser::LeftParen);
    setState(144);
    conditionalExpression(0);
    setState(145);
    match(Pcl2Parser::RightParen);
    setState(146);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

Pcl2Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Pcl2Parser::ExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleExpression;
}

void Pcl2Parser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- PrimExprContext ------------------------------------------------------------------

Pcl2Parser::PrimaryExpressionContext* Pcl2Parser::PrimExprContext::primaryExpression() {
  return getRuleContext<Pcl2Parser::PrimaryExpressionContext>(0);
}

Pcl2Parser::PrimExprContext::PrimExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::PrimExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimExpr(this);
}
void Pcl2Parser::PrimExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimExpr(this);
}

antlrcpp::Any Pcl2Parser::PrimExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitPrimExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivExprContext ------------------------------------------------------------------

std::vector<Pcl2Parser::ExpressionContext *> Pcl2Parser::MulDivExprContext::expression() {
  return getRuleContexts<Pcl2Parser::ExpressionContext>();
}

Pcl2Parser::ExpressionContext* Pcl2Parser::MulDivExprContext::expression(size_t i) {
  return getRuleContext<Pcl2Parser::ExpressionContext>(i);
}

Pcl2Parser::MulDivExprContext::MulDivExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::MulDivExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDivExpr(this);
}
void Pcl2Parser::MulDivExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDivExpr(this);
}

antlrcpp::Any Pcl2Parser::MulDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitMulDivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddminExprContext ------------------------------------------------------------------

std::vector<Pcl2Parser::ExpressionContext *> Pcl2Parser::AddminExprContext::expression() {
  return getRuleContexts<Pcl2Parser::ExpressionContext>();
}

Pcl2Parser::ExpressionContext* Pcl2Parser::AddminExprContext::expression(size_t i) {
  return getRuleContext<Pcl2Parser::ExpressionContext>(i);
}

Pcl2Parser::AddminExprContext::AddminExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::AddminExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddminExpr(this);
}
void Pcl2Parser::AddminExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddminExpr(this);
}

antlrcpp::Any Pcl2Parser::AddminExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitAddminExpr(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::expression() {
   return expression(0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  Pcl2Parser::ExpressionContext *previousContext = _localctx;
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, Pcl2Parser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<PrimExprContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(149);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(159);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(157);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(151);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(152);
          dynamic_cast<MulDivExprContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << Pcl2Parser::Star)
            | (1ULL << Pcl2Parser::Div)
            | (1ULL << Pcl2Parser::Mod))) != 0))) {
            dynamic_cast<MulDivExprContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(153);
          expression(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddminExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(154);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(155);
          dynamic_cast<AddminExprContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == Pcl2Parser::Plus

          || _la == Pcl2Parser::Minus)) {
            dynamic_cast<AddminExprContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(156);
          expression(3);
          break;
        }

        } 
      }
      setState(161);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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

Pcl2Parser::ConditionalExpressionContext::ConditionalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Pcl2Parser::ExpressionContext *> Pcl2Parser::ConditionalExpressionContext::expression() {
  return getRuleContexts<Pcl2Parser::ExpressionContext>();
}

Pcl2Parser::ExpressionContext* Pcl2Parser::ConditionalExpressionContext::expression(size_t i) {
  return getRuleContext<Pcl2Parser::ExpressionContext>(i);
}

tree::TerminalNode* Pcl2Parser::ConditionalExpressionContext::ConditionalOperator() {
  return getToken(Pcl2Parser::ConditionalOperator, 0);
}

tree::TerminalNode* Pcl2Parser::ConditionalExpressionContext::Not() {
  return getToken(Pcl2Parser::Not, 0);
}

tree::TerminalNode* Pcl2Parser::ConditionalExpressionContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

std::vector<Pcl2Parser::ConditionalExpressionContext *> Pcl2Parser::ConditionalExpressionContext::conditionalExpression() {
  return getRuleContexts<Pcl2Parser::ConditionalExpressionContext>();
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::ConditionalExpressionContext::conditionalExpression(size_t i) {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(i);
}

tree::TerminalNode* Pcl2Parser::ConditionalExpressionContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

tree::TerminalNode* Pcl2Parser::ConditionalExpressionContext::ConditionalConnectOperator() {
  return getToken(Pcl2Parser::ConditionalConnectOperator, 0);
}


size_t Pcl2Parser::ConditionalExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleConditionalExpression;
}

void Pcl2Parser::ConditionalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalExpression(this);
}

void Pcl2Parser::ConditionalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalExpression(this);
}


antlrcpp::Any Pcl2Parser::ConditionalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitConditionalExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::conditionalExpression() {
   return conditionalExpression(0);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::conditionalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::ConditionalExpressionContext *_localctx = _tracker.createInstance<ConditionalExpressionContext>(_ctx, parentState);
  Pcl2Parser::ConditionalExpressionContext *previousContext = _localctx;
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, Pcl2Parser::RuleConditionalExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::LeftParen:
      case Pcl2Parser::IntegerConstant:
      case Pcl2Parser::FloatConstant:
      case Pcl2Parser::Identifier: {
        setState(163);
        expression(0);
        setState(164);
        match(Pcl2Parser::ConditionalOperator);
        setState(165);
        expression(0);
        break;
      }

      case Pcl2Parser::Not: {
        setState(167);
        match(Pcl2Parser::Not);
        setState(168);
        match(Pcl2Parser::LeftParen);
        setState(169);
        conditionalExpression(0);
        setState(170);
        match(Pcl2Parser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(179);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ConditionalExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleConditionalExpression);
        setState(174);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(175);
        match(Pcl2Parser::ConditionalConnectOperator);
        setState(176);
        conditionalExpression(3); 
      }
      setState(181);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
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

Pcl2Parser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::AssignmentExpressionContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::AssignmentExpressionContext::Assign() {
  return getToken(Pcl2Parser::Assign, 0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::AssignmentExpressionContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}

Pcl2Parser::FunctionReturnContext* Pcl2Parser::AssignmentExpressionContext::functionReturn() {
  return getRuleContext<Pcl2Parser::FunctionReturnContext>(0);
}


size_t Pcl2Parser::AssignmentExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleAssignmentExpression;
}

void Pcl2Parser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void Pcl2Parser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}


antlrcpp::Any Pcl2Parser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 36, Pcl2Parser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(188);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(182);
      match(Pcl2Parser::Identifier);
      setState(183);
      match(Pcl2Parser::Assign);
      setState(184);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(185);
      match(Pcl2Parser::Identifier);
      setState(186);
      match(Pcl2Parser::Assign);
      setState(187);
      functionReturn();
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

//----------------- TypeSpecifierContext ------------------------------------------------------------------

Pcl2Parser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Void() {
  return getToken(Pcl2Parser::Void, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Bool() {
  return getToken(Pcl2Parser::Bool, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Char() {
  return getToken(Pcl2Parser::Char, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Int() {
  return getToken(Pcl2Parser::Int, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Float() {
  return getToken(Pcl2Parser::Float, 0);
}

tree::TerminalNode* Pcl2Parser::TypeSpecifierContext::Double() {
  return getToken(Pcl2Parser::Double, 0);
}


size_t Pcl2Parser::TypeSpecifierContext::getRuleIndex() const {
  return Pcl2Parser::RuleTypeSpecifier;
}

void Pcl2Parser::TypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void Pcl2Parser::TypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}


antlrcpp::Any Pcl2Parser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::TypeSpecifierContext* Pcl2Parser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 38, Pcl2Parser::RuleTypeSpecifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Void))) != 0))) {
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

//----------------- ParamaterTypeListContext ------------------------------------------------------------------

Pcl2Parser::ParamaterTypeListContext::ParamaterTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::ParamaterTypeListContext::LeftParen() {
  return getToken(Pcl2Parser::LeftParen, 0);
}

tree::TerminalNode* Pcl2Parser::ParamaterTypeListContext::RightParen() {
  return getToken(Pcl2Parser::RightParen, 0);
}

std::vector<Pcl2Parser::DeclarationContext *> Pcl2Parser::ParamaterTypeListContext::declaration() {
  return getRuleContexts<Pcl2Parser::DeclarationContext>();
}

Pcl2Parser::DeclarationContext* Pcl2Parser::ParamaterTypeListContext::declaration(size_t i) {
  return getRuleContext<Pcl2Parser::DeclarationContext>(i);
}


size_t Pcl2Parser::ParamaterTypeListContext::getRuleIndex() const {
  return Pcl2Parser::RuleParamaterTypeList;
}

void Pcl2Parser::ParamaterTypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamaterTypeList(this);
}

void Pcl2Parser::ParamaterTypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamaterTypeList(this);
}


antlrcpp::Any Pcl2Parser::ParamaterTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitParamaterTypeList(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ParamaterTypeListContext* Pcl2Parser::paramaterTypeList() {
  ParamaterTypeListContext *_localctx = _tracker.createInstance<ParamaterTypeListContext>(_ctx, getState());
  enterRule(_localctx, 40, Pcl2Parser::RuleParamaterTypeList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(Pcl2Parser::LeftParen);
    setState(196);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Void))) != 0)) {
      setState(193);
      declaration();
      setState(198);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(199);
    match(Pcl2Parser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

Pcl2Parser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::TypeSpecifierContext* Pcl2Parser::DeclarationContext::typeSpecifier() {
  return getRuleContext<Pcl2Parser::TypeSpecifierContext>(0);
}

std::vector<tree::TerminalNode *> Pcl2Parser::DeclarationContext::Identifier() {
  return getTokens(Pcl2Parser::Identifier);
}

tree::TerminalNode* Pcl2Parser::DeclarationContext::Identifier(size_t i) {
  return getToken(Pcl2Parser::Identifier, i);
}

tree::TerminalNode* Pcl2Parser::DeclarationContext::Semi() {
  return getToken(Pcl2Parser::Semi, 0);
}

std::vector<tree::TerminalNode *> Pcl2Parser::DeclarationContext::Comma() {
  return getTokens(Pcl2Parser::Comma);
}

tree::TerminalNode* Pcl2Parser::DeclarationContext::Comma(size_t i) {
  return getToken(Pcl2Parser::Comma, i);
}

std::vector<Pcl2Parser::AssignmentExpressionContext *> Pcl2Parser::DeclarationContext::assignmentExpression() {
  return getRuleContexts<Pcl2Parser::AssignmentExpressionContext>();
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::DeclarationContext::assignmentExpression(size_t i) {
  return getRuleContext<Pcl2Parser::AssignmentExpressionContext>(i);
}


size_t Pcl2Parser::DeclarationContext::getRuleIndex() const {
  return Pcl2Parser::RuleDeclaration;
}

void Pcl2Parser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void Pcl2Parser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any Pcl2Parser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::DeclarationContext* Pcl2Parser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 42, Pcl2Parser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(201);
      typeSpecifier();
      setState(202);
      match(Pcl2Parser::Identifier);
      setState(207);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Pcl2Parser::Comma) {
        setState(203);
        match(Pcl2Parser::Comma);
        setState(204);
        match(Pcl2Parser::Identifier);
        setState(209);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(210);
      match(Pcl2Parser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(212);
      typeSpecifier();
      setState(213);
      assignmentExpression();
      setState(218);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Pcl2Parser::Comma) {
        setState(214);
        match(Pcl2Parser::Comma);
        setState(215);
        assignmentExpression();
        setState(220);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(221);
      match(Pcl2Parser::Semi);
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

bool Pcl2Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return translationUnitSempred(dynamic_cast<TranslationUnitContext *>(context), predicateIndex);
    case 9: return blockItemListSempred(dynamic_cast<BlockItemListContext *>(context), predicateIndex);
    case 16: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 17: return conditionalExpressionSempred(dynamic_cast<ConditionalExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::translationUnitSempred(TranslationUnitContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::conditionalExpressionSempred(ConditionalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> Pcl2Parser::_decisionToDFA;
atn::PredictionContextCache Pcl2Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN Pcl2Parser::_atn;
std::vector<uint16_t> Pcl2Parser::_serializedATN;

std::vector<std::string> Pcl2Parser::_ruleNames = {
  "compilationUnit", "translationUnit", "externalDeclaration", "primaryExpression", 
  "functionDefinition", "functionCall", "functionReturn", "identifierList", 
  "compoundStatement", "blockItemList", "blockItem", "statement", "assignmentStatement", 
  "expressionStatement", "selectionStatement", "iterationStatement", "expression", 
  "conditionalExpression", "assignmentExpression", "typeSpecifier", "paramaterTypeList", 
  "declaration"
};

std::vector<std::string> Pcl2Parser::_literalNames = {
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

std::vector<std::string> Pcl2Parser::_symbolicNames = {
  "", "ConditionalConnectOperator", "ConditionalOperator", "Coalescing", 
  "Bit", "Power", "IgnoreWildCard", "Namespace", "ScopeResolution", "String", 
  "Break", "Case", "Char", "Const", "Continue", "Bool", "Default", "Double", 
  "Else", "Extern", "Float", "For", "If", "Int", "Uint32", "Int32", "Long", 
  "Return", "Short", "Signed", "Sizeof", "Static", "Switch", "Typedef", 
  "Unsigned", "Void", "While", "LeftParen", "RightParen", "LeftBracket", 
  "RightBracket", "LeftBrace", "RightBrace", "Less", "LessEqual", "Greater", 
  "GreaterEqual", "LeftShift", "RightShift", "Plus", "PlusPlus", "Minus", 
  "MinusMinus", "Star", "Div", "Mod", "And", "Or", "Negate", "Caret", "Question", 
  "Colon", "Semi", "Comma", "Assign", "StarAssign", "DivAssign", "ModAssign", 
  "PlusAssign", "MinusAssign", "LeftShiftAssign", "RightShiftAssign", "AndAssign", 
  "XorAssign", "OrAssign", "NegateAssign", "Arrow", "Dot", "Ellipsis", "IntegerConstant", 
  "FloatConstant", "AndAnd", "OrOr", "Not", "Equal", "NotEqual", "Identifier", 
  "Whitespace", "Newline", "BlockComment", "LineComment"
};

dfa::Vocabulary Pcl2Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> Pcl2Parser::_tokenNames;

Pcl2Parser::Initializer::Initializer() {
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
    0x3, 0x5c, 0xe4, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x5, 0x2, 
    0x30, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x7, 0x3, 0x39, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3c, 0xb, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x41, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x4a, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x54, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x5c, 0xa, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x63, 0xa, 0x9, 
    0xc, 0x9, 0xe, 0x9, 0x66, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x6a, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0x73, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x76, 0xb, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x7a, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x81, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xf, 0x5, 0xf, 0x87, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x7, 0x12, 0xa0, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xa3, 0xb, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xaf, 0xa, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xb4, 0xa, 0x13, 0xc, 0x13, 
    0xe, 0x13, 0xb7, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xbf, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xc5, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 
    0xc8, 0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x7, 0x17, 0xd0, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0xd3, 0xb, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x7, 0x17, 0xdb, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0xde, 0xb, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x5, 0x17, 0xe2, 0xa, 0x17, 0x3, 0x17, 0x2, 0x6, 0x4, 
    0x14, 0x22, 0x24, 0x18, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2, 0x5, 0x3, 0x2, 0x37, 0x39, 0x4, 0x2, 0x33, 0x33, 0x35, 0x35, 
    0x8, 0x2, 0xe, 0xe, 0x11, 0x11, 0x13, 0x13, 0x16, 0x16, 0x19, 0x19, 
    0x25, 0x25, 0x2, 0xe8, 0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x40, 0x3, 0x2, 0x2, 0x2, 0x8, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x4b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x50, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x16, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x80, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x86, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x90, 0x3, 0x2, 0x2, 0x2, 0x22, 0x96, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0xae, 0x3, 0x2, 0x2, 0x2, 0x26, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xe1, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x4, 0x3, 0x2, 0x2f, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x32, 0x7, 0x2, 0x2, 0x3, 0x32, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x34, 0x8, 0x3, 0x1, 0x2, 0x34, 0x35, 0x5, 0x6, 0x4, 0x2, 
    0x35, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0xc, 0x3, 0x2, 0x2, 0x37, 
    0x39, 0x5, 0x6, 0x4, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x3b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x41, 0x5, 0xa, 0x6, 0x2, 0x3e, 0x41, 0x5, 0x2c, 0x17, 
    0x2, 0x3f, 0x41, 0x7, 0x40, 0x2, 0x2, 0x40, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x42, 0x4a, 0x7, 0x58, 0x2, 0x2, 0x43, 0x4a, 
    0x7, 0x51, 0x2, 0x2, 0x44, 0x4a, 0x7, 0x52, 0x2, 0x2, 0x45, 0x46, 0x7, 
    0x27, 0x2, 0x2, 0x46, 0x47, 0x5, 0x22, 0x12, 0x2, 0x47, 0x48, 0x7, 0x28, 
    0x2, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 0x42, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x43, 0x3, 0x2, 0x2, 0x2, 0x49, 0x44, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x45, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x4c, 0x5, 0x28, 0x15, 0x2, 0x4c, 0x4d, 0x7, 0x58, 0x2, 0x2, 0x4d, 0x4e, 
    0x5, 0x2a, 0x16, 0x2, 0x4e, 0x4f, 0x5, 0x12, 0xa, 0x2, 0x4f, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x58, 0x2, 0x2, 0x51, 0x53, 0x7, 0x27, 
    0x2, 0x2, 0x52, 0x54, 0x5, 0x10, 0x9, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x56, 0x7, 0x28, 0x2, 0x2, 0x56, 0x57, 0x7, 0x40, 0x2, 0x2, 0x57, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0x58, 0x2, 0x2, 0x59, 0x5b, 
    0x7, 0x27, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0x10, 0x9, 0x2, 0x5b, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x5e, 0x7, 0x28, 0x2, 0x2, 0x5e, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x64, 0x7, 0x58, 0x2, 0x2, 0x60, 0x61, 0x7, 0x41, 0x2, 0x2, 
    0x61, 0x63, 0x7, 0x58, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x11, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x69, 0x7, 0x2b, 0x2, 0x2, 0x68, 0x6a, 0x5, 0x14, 
    0xb, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x2c, 0x2, 0x2, 
    0x6c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x8, 0xb, 0x1, 0x2, 0x6e, 
    0x6f, 0x5, 0x16, 0xc, 0x2, 0x6f, 0x74, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 
    0xc, 0x3, 0x2, 0x2, 0x71, 0x73, 0x5, 0x16, 0xc, 0x2, 0x72, 0x70, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x76, 0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7a, 0x5, 0x18, 0xd, 0x2, 
    0x78, 0x7a, 0x5, 0x2c, 0x17, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x17, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x81, 
    0x5, 0x12, 0xa, 0x2, 0x7c, 0x81, 0x5, 0x1c, 0xf, 0x2, 0x7d, 0x81, 0x5, 
    0x1e, 0x10, 0x2, 0x7e, 0x81, 0x5, 0x20, 0x11, 0x2, 0x7f, 0x81, 0x5, 
    0x1a, 0xe, 0x2, 0x80, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x83, 0x5, 0x26, 0x14, 0x2, 0x83, 0x84, 0x7, 0x40, 0x2, 0x2, 0x84, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x5, 0x22, 0x12, 0x2, 0x86, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x40, 0x2, 0x2, 0x89, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x8b, 0x7, 0x18, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x27, 0x2, 
    0x2, 0x8c, 0x8d, 0x5, 0x24, 0x13, 0x2, 0x8d, 0x8e, 0x7, 0x28, 0x2, 0x2, 
    0x8e, 0x8f, 0x5, 0x18, 0xd, 0x2, 0x8f, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x91, 0x7, 0x26, 0x2, 0x2, 0x91, 0x92, 0x7, 0x27, 0x2, 0x2, 0x92, 0x93, 
    0x5, 0x24, 0x13, 0x2, 0x93, 0x94, 0x7, 0x28, 0x2, 0x2, 0x94, 0x95, 0x5, 
    0x18, 0xd, 0x2, 0x95, 0x21, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x8, 0x12, 
    0x1, 0x2, 0x97, 0x98, 0x5, 0x8, 0x5, 0x2, 0x98, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x9a, 0xc, 0x5, 0x2, 0x2, 0x9a, 0x9b, 0x9, 0x2, 0x2, 0x2, 
    0x9b, 0xa0, 0x5, 0x22, 0x12, 0x6, 0x9c, 0x9d, 0xc, 0x4, 0x2, 0x2, 0x9d, 
    0x9e, 0x9, 0x3, 0x2, 0x2, 0x9e, 0xa0, 0x5, 0x22, 0x12, 0x5, 0x9f, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa3, 0x3, 
    0x2, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0x23, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa5, 0x8, 0x13, 0x1, 0x2, 0xa5, 0xa6, 0x5, 0x22, 0x12, 0x2, 
    0xa6, 0xa7, 0x7, 0x4, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x22, 0x12, 0x2, 0xa8, 
    0xaf, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x55, 0x2, 0x2, 0xaa, 0xab, 
    0x7, 0x27, 0x2, 0x2, 0xab, 0xac, 0x5, 0x24, 0x13, 0x2, 0xac, 0xad, 0x7, 
    0x28, 0x2, 0x2, 0xad, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xae, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb5, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xb1, 0xc, 0x4, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x3, 0x2, 0x2, 
    0xb2, 0xb4, 0x5, 0x24, 0x13, 0x5, 0xb3, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0xb7, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0xb6, 0x25, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x58, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x42, 
    0x2, 0x2, 0xba, 0xbf, 0x5, 0x22, 0x12, 0x2, 0xbb, 0xbc, 0x7, 0x58, 0x2, 
    0x2, 0xbc, 0xbd, 0x7, 0x42, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0xe, 0x8, 0x2, 
    0xbe, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x9, 0x4, 0x2, 0x2, 0xc1, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xc6, 0x7, 0x27, 0x2, 0x2, 0xc3, 0xc5, 0x5, 
    0x2c, 0x17, 0x2, 0xc4, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc8, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 
    0xc9, 0xca, 0x7, 0x28, 0x2, 0x2, 0xca, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xcc, 0x5, 0x28, 0x15, 0x2, 0xcc, 0xd1, 0x7, 0x58, 0x2, 0x2, 0xcd, 0xce, 
    0x7, 0x41, 0x2, 0x2, 0xce, 0xd0, 0x7, 0x58, 0x2, 0x2, 0xcf, 0xcd, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd4, 0x3, 0x2, 0x2, 
    0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x40, 0x2, 0x2, 
    0xd5, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x5, 0x28, 0x15, 0x2, 0xd7, 
    0xdc, 0x5, 0x26, 0x14, 0x2, 0xd8, 0xd9, 0x7, 0x41, 0x2, 0x2, 0xd9, 0xdb, 
    0x5, 0x26, 0x14, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 
    0x2, 0x2, 0xdd, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xe0, 0x7, 0x40, 0x2, 0x2, 0xe0, 0xe2, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xe2, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x17, 0x2f, 0x3a, 0x40, 0x49, 0x53, 0x5b, 
    0x64, 0x69, 0x74, 0x79, 0x80, 0x86, 0x9f, 0xa1, 0xae, 0xb5, 0xbe, 0xc6, 
    0xd1, 0xdc, 0xe1, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

Pcl2Parser::Initializer Pcl2Parser::_init;
