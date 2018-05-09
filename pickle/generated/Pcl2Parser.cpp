
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
    setState(93);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Uint32)
      | (1ULL << Pcl2Parser::Int32)
      | (1ULL << Pcl2Parser::Long)
      | (1ULL << Pcl2Parser::Short)
      | (1ULL << Pcl2Parser::Signed)
      | (1ULL << Pcl2Parser::Unsigned)
      | (1ULL << Pcl2Parser::Void)
      | (1ULL << Pcl2Parser::Star))) != 0) || _la == Pcl2Parser::Semi

    || _la == Pcl2Parser::Identifier) {
      setState(92);
      translationUnit(0);
    }
    setState(95);
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
    setState(98);
    externalDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(104);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TranslationUnitContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTranslationUnit);
        setState(100);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(101);
        externalDeclaration(); 
      }
      setState(106);
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
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(107);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(108);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(109);
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

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

Pcl2Parser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::DeclaratorContext* Pcl2Parser::FunctionDefinitionContext::declarator() {
  return getRuleContext<Pcl2Parser::DeclaratorContext>(0);
}

Pcl2Parser::CompoundStatementContext* Pcl2Parser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<Pcl2Parser::CompoundStatementContext>(0);
}

Pcl2Parser::DeclarationSpecifiersContext* Pcl2Parser::FunctionDefinitionContext::declarationSpecifiers() {
  return getRuleContext<Pcl2Parser::DeclarationSpecifiersContext>(0);
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
  enterRule(_localctx, 6, Pcl2Parser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Uint32)
      | (1ULL << Pcl2Parser::Int32)
      | (1ULL << Pcl2Parser::Long)
      | (1ULL << Pcl2Parser::Short)
      | (1ULL << Pcl2Parser::Signed)
      | (1ULL << Pcl2Parser::Unsigned)
      | (1ULL << Pcl2Parser::Void))) != 0)) {
      setState(112);
      declarationSpecifiers();
    }
    setState(115);
    declarator();
    setState(116);
    compoundStatement();
   
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

Pcl2Parser::DeclarationSpecifiersContext* Pcl2Parser::DeclarationContext::declarationSpecifiers() {
  return getRuleContext<Pcl2Parser::DeclarationSpecifiersContext>(0);
}

Pcl2Parser::InitDeclaratorListContext* Pcl2Parser::DeclarationContext::initDeclaratorList() {
  return getRuleContext<Pcl2Parser::InitDeclaratorListContext>(0);
}

Pcl2Parser::DeclarationSpecifierContext* Pcl2Parser::DeclarationContext::declarationSpecifier() {
  return getRuleContext<Pcl2Parser::DeclarationSpecifierContext>(0);
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
  enterRule(_localctx, 8, Pcl2Parser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(118);
      declarationSpecifiers();
      setState(119);
      initDeclaratorList(0);
      setState(120);
      match(Pcl2Parser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(122);
      declarationSpecifier();
      setState(123);
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

//----------------- DeclarationSpecifiersContext ------------------------------------------------------------------

Pcl2Parser::DeclarationSpecifiersContext::DeclarationSpecifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Pcl2Parser::DeclarationSpecifierContext *> Pcl2Parser::DeclarationSpecifiersContext::declarationSpecifier() {
  return getRuleContexts<Pcl2Parser::DeclarationSpecifierContext>();
}

Pcl2Parser::DeclarationSpecifierContext* Pcl2Parser::DeclarationSpecifiersContext::declarationSpecifier(size_t i) {
  return getRuleContext<Pcl2Parser::DeclarationSpecifierContext>(i);
}


size_t Pcl2Parser::DeclarationSpecifiersContext::getRuleIndex() const {
  return Pcl2Parser::RuleDeclarationSpecifiers;
}

void Pcl2Parser::DeclarationSpecifiersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifiers(this);
}

void Pcl2Parser::DeclarationSpecifiersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifiers(this);
}


antlrcpp::Any Pcl2Parser::DeclarationSpecifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::DeclarationSpecifiersContext* Pcl2Parser::declarationSpecifiers() {
  DeclarationSpecifiersContext *_localctx = _tracker.createInstance<DeclarationSpecifiersContext>(_ctx, getState());
  enterRule(_localctx, 10, Pcl2Parser::RuleDeclarationSpecifiers);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(128); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(127);
              declarationSpecifier();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(130); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
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

Pcl2Parser::DeclarationSpecifierContext::DeclarationSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::TypeSpecifierContext* Pcl2Parser::DeclarationSpecifierContext::typeSpecifier() {
  return getRuleContext<Pcl2Parser::TypeSpecifierContext>(0);
}


size_t Pcl2Parser::DeclarationSpecifierContext::getRuleIndex() const {
  return Pcl2Parser::RuleDeclarationSpecifier;
}

void Pcl2Parser::DeclarationSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifier(this);
}

void Pcl2Parser::DeclarationSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifier(this);
}


antlrcpp::Any Pcl2Parser::DeclarationSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifier(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::DeclarationSpecifierContext* Pcl2Parser::declarationSpecifier() {
  DeclarationSpecifierContext *_localctx = _tracker.createInstance<DeclarationSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 12, Pcl2Parser::RuleDeclarationSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    typeSpecifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitDeclaratorListContext ------------------------------------------------------------------

Pcl2Parser::InitDeclaratorListContext::InitDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Pcl2Parser::InitDeclaratorContext *> Pcl2Parser::InitDeclaratorListContext::initDeclarator() {
  return getRuleContexts<Pcl2Parser::InitDeclaratorContext>();
}

Pcl2Parser::InitDeclaratorContext* Pcl2Parser::InitDeclaratorListContext::initDeclarator(size_t i) {
  return getRuleContext<Pcl2Parser::InitDeclaratorContext>(i);
}

Pcl2Parser::InitDeclaratorListContext* Pcl2Parser::InitDeclaratorListContext::initDeclaratorList() {
  return getRuleContext<Pcl2Parser::InitDeclaratorListContext>(0);
}


size_t Pcl2Parser::InitDeclaratorListContext::getRuleIndex() const {
  return Pcl2Parser::RuleInitDeclaratorList;
}

void Pcl2Parser::InitDeclaratorListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclaratorList(this);
}

void Pcl2Parser::InitDeclaratorListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclaratorList(this);
}


antlrcpp::Any Pcl2Parser::InitDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitInitDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::InitDeclaratorListContext* Pcl2Parser::initDeclaratorList() {
   return initDeclaratorList(0);
}

Pcl2Parser::InitDeclaratorListContext* Pcl2Parser::initDeclaratorList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::InitDeclaratorListContext *_localctx = _tracker.createInstance<InitDeclaratorListContext>(_ctx, parentState);
  Pcl2Parser::InitDeclaratorListContext *previousContext = _localctx;
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, Pcl2Parser::RuleInitDeclaratorList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(135);
    initDeclarator();
    setState(140);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(136);
        match(Pcl2Parser::Comma);
        setState(137);
        initDeclarator(); 
      }
      setState(142);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
    _ctx->stop = _input->LT(-1);
    setState(148);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InitDeclaratorListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInitDeclaratorList);
        setState(143);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(144);
        match(Pcl2Parser::Comma);
        setState(145);
        initDeclarator(); 
      }
      setState(150);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
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

Pcl2Parser::InitDeclaratorContext::InitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::DeclaratorContext* Pcl2Parser::InitDeclaratorContext::declarator() {
  return getRuleContext<Pcl2Parser::DeclaratorContext>(0);
}

Pcl2Parser::InitializerContext* Pcl2Parser::InitDeclaratorContext::initializer() {
  return getRuleContext<Pcl2Parser::InitializerContext>(0);
}


size_t Pcl2Parser::InitDeclaratorContext::getRuleIndex() const {
  return Pcl2Parser::RuleInitDeclarator;
}

void Pcl2Parser::InitDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclarator(this);
}

void Pcl2Parser::InitDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclarator(this);
}


antlrcpp::Any Pcl2Parser::InitDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitInitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::InitDeclaratorContext* Pcl2Parser::initDeclarator() {
  InitDeclaratorContext *_localctx = _tracker.createInstance<InitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 16, Pcl2Parser::RuleInitDeclarator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(151);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(152);
      declarator();
      setState(153);
      match(Pcl2Parser::Assign);
      setState(154);
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

//----------------- TypeSpecifierContext ------------------------------------------------------------------

Pcl2Parser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Pcl2Parser::TypeSpecifierContext::getRuleIndex() const {
  return Pcl2Parser::RuleTypeSpecifier;
}

void Pcl2Parser::TypeSpecifierContext::copyFrom(TypeSpecifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- CharTypeContext ------------------------------------------------------------------

Pcl2Parser::CharTypeContext::CharTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::CharTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharType(this);
}
void Pcl2Parser::CharTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharType(this);
}

antlrcpp::Any Pcl2Parser::CharTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitCharType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DoubleTypeContext ------------------------------------------------------------------

Pcl2Parser::DoubleTypeContext::DoubleTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::DoubleTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoubleType(this);
}
void Pcl2Parser::DoubleTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoubleType(this);
}

antlrcpp::Any Pcl2Parser::DoubleTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitDoubleType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatTypeContext ------------------------------------------------------------------

Pcl2Parser::FloatTypeContext::FloatTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::FloatTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatType(this);
}
void Pcl2Parser::FloatTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatType(this);
}

antlrcpp::Any Pcl2Parser::FloatTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitFloatType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Uint32_tTypeContext ------------------------------------------------------------------

Pcl2Parser::Uint32_tTypeContext::Uint32_tTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::Uint32_tTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUint32_tType(this);
}
void Pcl2Parser::Uint32_tTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUint32_tType(this);
}

antlrcpp::Any Pcl2Parser::Uint32_tTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitUint32_tType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnsignedTypeContext ------------------------------------------------------------------

Pcl2Parser::UnsignedTypeContext::UnsignedTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::UnsignedTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnsignedType(this);
}
void Pcl2Parser::UnsignedTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnsignedType(this);
}

antlrcpp::Any Pcl2Parser::UnsignedTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitUnsignedType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Int32_tTypeContext ------------------------------------------------------------------

Pcl2Parser::Int32_tTypeContext::Int32_tTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::Int32_tTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt32_tType(this);
}
void Pcl2Parser::Int32_tTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt32_tType(this);
}

antlrcpp::Any Pcl2Parser::Int32_tTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitInt32_tType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntTypeContext ------------------------------------------------------------------

Pcl2Parser::IntTypeContext::IntTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::IntTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntType(this);
}
void Pcl2Parser::IntTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntType(this);
}

antlrcpp::Any Pcl2Parser::IntTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitIntType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShortTypeContext ------------------------------------------------------------------

Pcl2Parser::ShortTypeContext::ShortTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::ShortTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShortType(this);
}
void Pcl2Parser::ShortTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShortType(this);
}

antlrcpp::Any Pcl2Parser::ShortTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitShortType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VoidTypeContext ------------------------------------------------------------------

Pcl2Parser::VoidTypeContext::VoidTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::VoidTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoidType(this);
}
void Pcl2Parser::VoidTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoidType(this);
}

antlrcpp::Any Pcl2Parser::VoidTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitVoidType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LongTypeContext ------------------------------------------------------------------

Pcl2Parser::LongTypeContext::LongTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::LongTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLongType(this);
}
void Pcl2Parser::LongTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLongType(this);
}

antlrcpp::Any Pcl2Parser::LongTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitLongType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolTypeContext ------------------------------------------------------------------

Pcl2Parser::BoolTypeContext::BoolTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::BoolTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolType(this);
}
void Pcl2Parser::BoolTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolType(this);
}

antlrcpp::Any Pcl2Parser::BoolTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitBoolType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SignedTypeContext ------------------------------------------------------------------

Pcl2Parser::SignedTypeContext::SignedTypeContext(TypeSpecifierContext *ctx) { copyFrom(ctx); }

void Pcl2Parser::SignedTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignedType(this);
}
void Pcl2Parser::SignedTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignedType(this);
}

antlrcpp::Any Pcl2Parser::SignedTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitSignedType(this);
  else
    return visitor->visitChildren(this);
}
Pcl2Parser::TypeSpecifierContext* Pcl2Parser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 18, Pcl2Parser::RuleTypeSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::Void: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::VoidTypeContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(158);
        match(Pcl2Parser::Void);
        break;
      }

      case Pcl2Parser::Bool: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::BoolTypeContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(159);
        match(Pcl2Parser::Bool);
        break;
      }

      case Pcl2Parser::Char: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::CharTypeContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(160);
        match(Pcl2Parser::Char);
        break;
      }

      case Pcl2Parser::Short: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::ShortTypeContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(161);
        match(Pcl2Parser::Short);
        break;
      }

      case Pcl2Parser::Int: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::IntTypeContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(162);
        match(Pcl2Parser::Int);
        break;
      }

      case Pcl2Parser::Long: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::LongTypeContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(163);
        match(Pcl2Parser::Long);
        break;
      }

      case Pcl2Parser::Float: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::FloatTypeContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(164);
        match(Pcl2Parser::Float);
        break;
      }

      case Pcl2Parser::Double: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::DoubleTypeContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(165);
        match(Pcl2Parser::Double);
        break;
      }

      case Pcl2Parser::Signed: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::SignedTypeContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(166);
        match(Pcl2Parser::Signed);
        break;
      }

      case Pcl2Parser::Unsigned: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::UnsignedTypeContext>(_localctx));
        enterOuterAlt(_localctx, 10);
        setState(167);
        match(Pcl2Parser::Unsigned);
        break;
      }

      case Pcl2Parser::Uint32: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::Uint32_tTypeContext>(_localctx));
        enterOuterAlt(_localctx, 11);
        setState(168);
        match(Pcl2Parser::Uint32);
        break;
      }

      case Pcl2Parser::Int32: {
        _localctx = dynamic_cast<TypeSpecifierContext *>(_tracker.createInstance<Pcl2Parser::Int32_tTypeContext>(_localctx));
        enterOuterAlt(_localctx, 12);
        setState(169);
        match(Pcl2Parser::Int32);
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

//----------------- DeclaratorContext ------------------------------------------------------------------

Pcl2Parser::DeclaratorContext::DeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::DirectDeclaratorContext* Pcl2Parser::DeclaratorContext::directDeclarator() {
  return getRuleContext<Pcl2Parser::DirectDeclaratorContext>(0);
}


size_t Pcl2Parser::DeclaratorContext::getRuleIndex() const {
  return Pcl2Parser::RuleDeclarator;
}

void Pcl2Parser::DeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarator(this);
}

void Pcl2Parser::DeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarator(this);
}


antlrcpp::Any Pcl2Parser::DeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::DeclaratorContext* Pcl2Parser::declarator() {
  DeclaratorContext *_localctx = _tracker.createInstance<DeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 20, Pcl2Parser::RuleDeclarator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Pcl2Parser::Star) {
      setState(172);
      match(Pcl2Parser::Star);
    }
    setState(175);
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

Pcl2Parser::DirectDeclaratorContext::DirectDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::DirectDeclaratorContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

Pcl2Parser::DirectDeclaratorContext* Pcl2Parser::DirectDeclaratorContext::directDeclarator() {
  return getRuleContext<Pcl2Parser::DirectDeclaratorContext>(0);
}

Pcl2Parser::ParameterTypeListContext* Pcl2Parser::DirectDeclaratorContext::parameterTypeList() {
  return getRuleContext<Pcl2Parser::ParameterTypeListContext>(0);
}

Pcl2Parser::IdentifierListContext* Pcl2Parser::DirectDeclaratorContext::identifierList() {
  return getRuleContext<Pcl2Parser::IdentifierListContext>(0);
}


size_t Pcl2Parser::DirectDeclaratorContext::getRuleIndex() const {
  return Pcl2Parser::RuleDirectDeclarator;
}

void Pcl2Parser::DirectDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectDeclarator(this);
}

void Pcl2Parser::DirectDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectDeclarator(this);
}


antlrcpp::Any Pcl2Parser::DirectDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitDirectDeclarator(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::DirectDeclaratorContext* Pcl2Parser::directDeclarator() {
   return directDeclarator(0);
}

Pcl2Parser::DirectDeclaratorContext* Pcl2Parser::directDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::DirectDeclaratorContext *_localctx = _tracker.createInstance<DirectDeclaratorContext>(_ctx, parentState);
  Pcl2Parser::DirectDeclaratorContext *previousContext = _localctx;
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, Pcl2Parser::RuleDirectDeclarator, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(Pcl2Parser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(193);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(191);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(180);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(181);
          match(Pcl2Parser::LeftParen);
          setState(182);
          parameterTypeList();
          setState(183);
          match(Pcl2Parser::RightParen);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(185);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(186);
          match(Pcl2Parser::LeftParen);
          setState(188);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == Pcl2Parser::Identifier) {
            setState(187);
            identifierList(0);
          }
          setState(190);
          match(Pcl2Parser::RightParen);
          break;
        }

        } 
      }
      setState(195);
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

//----------------- ParameterTypeListContext ------------------------------------------------------------------

Pcl2Parser::ParameterTypeListContext::ParameterTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::ParameterListContext* Pcl2Parser::ParameterTypeListContext::parameterList() {
  return getRuleContext<Pcl2Parser::ParameterListContext>(0);
}


size_t Pcl2Parser::ParameterTypeListContext::getRuleIndex() const {
  return Pcl2Parser::RuleParameterTypeList;
}

void Pcl2Parser::ParameterTypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterTypeList(this);
}

void Pcl2Parser::ParameterTypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterTypeList(this);
}


antlrcpp::Any Pcl2Parser::ParameterTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitParameterTypeList(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ParameterTypeListContext* Pcl2Parser::parameterTypeList() {
  ParameterTypeListContext *_localctx = _tracker.createInstance<ParameterTypeListContext>(_ctx, getState());
  enterRule(_localctx, 24, Pcl2Parser::RuleParameterTypeList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(201);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(196);
      parameterList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(197);
      parameterList(0);
      setState(198);
      match(Pcl2Parser::Comma);
      setState(199);
      match(Pcl2Parser::Ellipsis);
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

Pcl2Parser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::ParameterDeclarationContext* Pcl2Parser::ParameterListContext::parameterDeclaration() {
  return getRuleContext<Pcl2Parser::ParameterDeclarationContext>(0);
}

Pcl2Parser::ParameterListContext* Pcl2Parser::ParameterListContext::parameterList() {
  return getRuleContext<Pcl2Parser::ParameterListContext>(0);
}


size_t Pcl2Parser::ParameterListContext::getRuleIndex() const {
  return Pcl2Parser::RuleParameterList;
}

void Pcl2Parser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void Pcl2Parser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


antlrcpp::Any Pcl2Parser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::ParameterListContext* Pcl2Parser::parameterList() {
   return parameterList(0);
}

Pcl2Parser::ParameterListContext* Pcl2Parser::parameterList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, parentState);
  Pcl2Parser::ParameterListContext *previousContext = _localctx;
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, Pcl2Parser::RuleParameterList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(204);
    parameterDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(211);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterList);
        setState(206);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(207);
        match(Pcl2Parser::Comma);
        setState(208);
        parameterDeclaration(); 
      }
      setState(213);
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

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

Pcl2Parser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::DeclarationSpecifiersContext* Pcl2Parser::ParameterDeclarationContext::declarationSpecifiers() {
  return getRuleContext<Pcl2Parser::DeclarationSpecifiersContext>(0);
}

Pcl2Parser::DeclaratorContext* Pcl2Parser::ParameterDeclarationContext::declarator() {
  return getRuleContext<Pcl2Parser::DeclaratorContext>(0);
}


size_t Pcl2Parser::ParameterDeclarationContext::getRuleIndex() const {
  return Pcl2Parser::RuleParameterDeclaration;
}

void Pcl2Parser::ParameterDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDeclaration(this);
}

void Pcl2Parser::ParameterDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDeclaration(this);
}


antlrcpp::Any Pcl2Parser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ParameterDeclarationContext* Pcl2Parser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 28, Pcl2Parser::RuleParameterDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(218);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(214);
      declarationSpecifiers();
      setState(215);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(217);
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

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

Pcl2Parser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::Constant() {
  return getToken(Pcl2Parser::Constant, 0);
}

std::vector<tree::TerminalNode *> Pcl2Parser::PrimaryExpressionContext::StringLiteral() {
  return getTokens(Pcl2Parser::StringLiteral);
}

tree::TerminalNode* Pcl2Parser::PrimaryExpressionContext::StringLiteral(size_t i) {
  return getToken(Pcl2Parser::StringLiteral, i);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::PrimaryExpressionContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
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
  enterRule(_localctx, 30, Pcl2Parser::RulePrimaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(231);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(220);
        match(Pcl2Parser::Identifier);
        break;
      }

      case Pcl2Parser::Constant: {
        enterOuterAlt(_localctx, 2);
        setState(221);
        match(Pcl2Parser::Constant);
        break;
      }

      case Pcl2Parser::StringLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(223); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(222);
                  match(Pcl2Parser::StringLiteral);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(225); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case Pcl2Parser::LeftParen: {
        enterOuterAlt(_localctx, 4);
        setState(227);
        match(Pcl2Parser::LeftParen);
        setState(228);
        expression(0);
        setState(229);
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

//----------------- PostfixExpressionContext ------------------------------------------------------------------

Pcl2Parser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::PrimaryExpressionContext* Pcl2Parser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<Pcl2Parser::PrimaryExpressionContext>(0);
}

Pcl2Parser::PostfixExpressionContext* Pcl2Parser::PostfixExpressionContext::postfixExpression() {
  return getRuleContext<Pcl2Parser::PostfixExpressionContext>(0);
}

Pcl2Parser::ArgumentExpressionListContext* Pcl2Parser::PostfixExpressionContext::argumentExpressionList() {
  return getRuleContext<Pcl2Parser::ArgumentExpressionListContext>(0);
}


size_t Pcl2Parser::PostfixExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RulePostfixExpression;
}

void Pcl2Parser::PostfixExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpression(this);
}

void Pcl2Parser::PostfixExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpression(this);
}


antlrcpp::Any Pcl2Parser::PostfixExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitPostfixExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::PostfixExpressionContext* Pcl2Parser::postfixExpression() {
   return postfixExpression(0);
}

Pcl2Parser::PostfixExpressionContext* Pcl2Parser::postfixExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, parentState);
  Pcl2Parser::PostfixExpressionContext *previousContext = _localctx;
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, Pcl2Parser::RulePostfixExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(234);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(248);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(246);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(236);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(237);
          match(Pcl2Parser::LeftParen);
          setState(239);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << Pcl2Parser::T__0)
            | (1ULL << Pcl2Parser::Constant)
            | (1ULL << Pcl2Parser::DigitSequence)
            | (1ULL << Pcl2Parser::StringLiteral)
            | (1ULL << Pcl2Parser::LeftParen)
            | (1ULL << Pcl2Parser::Plus)
            | (1ULL << Pcl2Parser::PlusPlus)
            | (1ULL << Pcl2Parser::Minus)
            | (1ULL << Pcl2Parser::MinusMinus)
            | (1ULL << Pcl2Parser::Star))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 66)) & ((1ULL << (Pcl2Parser::And - 66))
            | (1ULL << (Pcl2Parser::Negate - 66))
            | (1ULL << (Pcl2Parser::Identifier - 66)))) != 0)) {
            setState(238);
            argumentExpressionList(0);
          }
          setState(241);
          match(Pcl2Parser::RightParen);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(242);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(243);
          match(Pcl2Parser::PlusPlus);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(244);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(245);
          match(Pcl2Parser::MinusMinus);
          break;
        }

        } 
      }
      setState(250);
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

//----------------- ArgumentExpressionListContext ------------------------------------------------------------------

Pcl2Parser::ArgumentExpressionListContext::ArgumentExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::ArgumentExpressionListContext::assignmentExpression() {
  return getRuleContext<Pcl2Parser::AssignmentExpressionContext>(0);
}

Pcl2Parser::ArgumentExpressionListContext* Pcl2Parser::ArgumentExpressionListContext::argumentExpressionList() {
  return getRuleContext<Pcl2Parser::ArgumentExpressionListContext>(0);
}


size_t Pcl2Parser::ArgumentExpressionListContext::getRuleIndex() const {
  return Pcl2Parser::RuleArgumentExpressionList;
}

void Pcl2Parser::ArgumentExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentExpressionList(this);
}

void Pcl2Parser::ArgumentExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentExpressionList(this);
}


antlrcpp::Any Pcl2Parser::ArgumentExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitArgumentExpressionList(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::ArgumentExpressionListContext* Pcl2Parser::argumentExpressionList() {
   return argumentExpressionList(0);
}

Pcl2Parser::ArgumentExpressionListContext* Pcl2Parser::argumentExpressionList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::ArgumentExpressionListContext *_localctx = _tracker.createInstance<ArgumentExpressionListContext>(_ctx, parentState);
  Pcl2Parser::ArgumentExpressionListContext *previousContext = _localctx;
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, Pcl2Parser::RuleArgumentExpressionList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(252);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(259);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentExpressionListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArgumentExpressionList);
        setState(254);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(255);
        match(Pcl2Parser::Comma);
        setState(256);
        assignmentExpression(); 
      }
      setState(261);
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

//----------------- UnaryExpressionContext ------------------------------------------------------------------

Pcl2Parser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::PostfixExpressionContext* Pcl2Parser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<Pcl2Parser::PostfixExpressionContext>(0);
}

Pcl2Parser::UnaryExpressionContext* Pcl2Parser::UnaryExpressionContext::unaryExpression() {
  return getRuleContext<Pcl2Parser::UnaryExpressionContext>(0);
}

Pcl2Parser::UnaryOperatorContext* Pcl2Parser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<Pcl2Parser::UnaryOperatorContext>(0);
}

tree::TerminalNode* Pcl2Parser::UnaryExpressionContext::DigitSequence() {
  return getToken(Pcl2Parser::DigitSequence, 0);
}


size_t Pcl2Parser::UnaryExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleUnaryExpression;
}

void Pcl2Parser::UnaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpression(this);
}

void Pcl2Parser::UnaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpression(this);
}


antlrcpp::Any Pcl2Parser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::UnaryExpressionContext* Pcl2Parser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 36, Pcl2Parser::RuleUnaryExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(271);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::Constant:
      case Pcl2Parser::StringLiteral:
      case Pcl2Parser::LeftParen:
      case Pcl2Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(262);
        postfixExpression(0);
        break;
      }

      case Pcl2Parser::PlusPlus: {
        enterOuterAlt(_localctx, 2);
        setState(263);
        match(Pcl2Parser::PlusPlus);
        setState(264);
        unaryExpression();
        break;
      }

      case Pcl2Parser::MinusMinus: {
        enterOuterAlt(_localctx, 3);
        setState(265);
        match(Pcl2Parser::MinusMinus);
        setState(266);
        unaryExpression();
        break;
      }

      case Pcl2Parser::T__0:
      case Pcl2Parser::Plus:
      case Pcl2Parser::Minus:
      case Pcl2Parser::Star:
      case Pcl2Parser::And:
      case Pcl2Parser::Negate: {
        enterOuterAlt(_localctx, 4);
        setState(267);
        unaryOperator();
        setState(268);
        unaryExpression();
        break;
      }

      case Pcl2Parser::DigitSequence: {
        enterOuterAlt(_localctx, 5);
        setState(270);
        match(Pcl2Parser::DigitSequence);
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

//----------------- UnaryOperatorContext ------------------------------------------------------------------

Pcl2Parser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t Pcl2Parser::UnaryOperatorContext::getRuleIndex() const {
  return Pcl2Parser::RuleUnaryOperator;
}

void Pcl2Parser::UnaryOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOperator(this);
}

void Pcl2Parser::UnaryOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOperator(this);
}


antlrcpp::Any Pcl2Parser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::UnaryOperatorContext* Pcl2Parser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 38, Pcl2Parser::RuleUnaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::T__0)
      | (1ULL << Pcl2Parser::Plus)
      | (1ULL << Pcl2Parser::Minus)
      | (1ULL << Pcl2Parser::Star))) != 0) || _la == Pcl2Parser::And

    || _la == Pcl2Parser::Negate)) {
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

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

Pcl2Parser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::UnaryExpressionContext* Pcl2Parser::MultiplicativeExpressionContext::unaryExpression() {
  return getRuleContext<Pcl2Parser::UnaryExpressionContext>(0);
}

Pcl2Parser::MultiplicativeExpressionContext* Pcl2Parser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<Pcl2Parser::MultiplicativeExpressionContext>(0);
}


size_t Pcl2Parser::MultiplicativeExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleMultiplicativeExpression;
}

void Pcl2Parser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void Pcl2Parser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}


antlrcpp::Any Pcl2Parser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::MultiplicativeExpressionContext* Pcl2Parser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

Pcl2Parser::MultiplicativeExpressionContext* Pcl2Parser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  Pcl2Parser::MultiplicativeExpressionContext *previousContext = _localctx;
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, Pcl2Parser::RuleMultiplicativeExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(276);
    unaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(289);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(287);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(278);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(279);
          match(Pcl2Parser::Star);
          setState(280);
          unaryExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(281);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(282);
          match(Pcl2Parser::Div);
          setState(283);
          unaryExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(284);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(285);
          match(Pcl2Parser::Mod);
          setState(286);
          unaryExpression();
          break;
        }

        } 
      }
      setState(291);
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

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

Pcl2Parser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::MultiplicativeExpressionContext* Pcl2Parser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<Pcl2Parser::MultiplicativeExpressionContext>(0);
}

Pcl2Parser::AdditiveExpressionContext* Pcl2Parser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<Pcl2Parser::AdditiveExpressionContext>(0);
}


size_t Pcl2Parser::AdditiveExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleAdditiveExpression;
}

void Pcl2Parser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void Pcl2Parser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}


antlrcpp::Any Pcl2Parser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::AdditiveExpressionContext* Pcl2Parser::additiveExpression() {
   return additiveExpression(0);
}

Pcl2Parser::AdditiveExpressionContext* Pcl2Parser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  Pcl2Parser::AdditiveExpressionContext *previousContext = _localctx;
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, Pcl2Parser::RuleAdditiveExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(293);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(303);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(301);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(295);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(296);
          match(Pcl2Parser::Plus);
          setState(297);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(298);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(299);
          match(Pcl2Parser::Minus);
          setState(300);
          multiplicativeExpression(0);
          break;
        }

        } 
      }
      setState(305);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
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

Pcl2Parser::ShiftExpressionContext::ShiftExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::AdditiveExpressionContext* Pcl2Parser::ShiftExpressionContext::additiveExpression() {
  return getRuleContext<Pcl2Parser::AdditiveExpressionContext>(0);
}

Pcl2Parser::ShiftExpressionContext* Pcl2Parser::ShiftExpressionContext::shiftExpression() {
  return getRuleContext<Pcl2Parser::ShiftExpressionContext>(0);
}


size_t Pcl2Parser::ShiftExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleShiftExpression;
}

void Pcl2Parser::ShiftExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShiftExpression(this);
}

void Pcl2Parser::ShiftExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShiftExpression(this);
}


antlrcpp::Any Pcl2Parser::ShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::ShiftExpressionContext* Pcl2Parser::shiftExpression() {
   return shiftExpression(0);
}

Pcl2Parser::ShiftExpressionContext* Pcl2Parser::shiftExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::ShiftExpressionContext *_localctx = _tracker.createInstance<ShiftExpressionContext>(_ctx, parentState);
  Pcl2Parser::ShiftExpressionContext *previousContext = _localctx;
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, Pcl2Parser::RuleShiftExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(307);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(317);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(315);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(309);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(310);
          match(Pcl2Parser::LeftShift);
          setState(311);
          additiveExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ShiftExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleShiftExpression);
          setState(312);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(313);
          match(Pcl2Parser::RightShift);
          setState(314);
          additiveExpression(0);
          break;
        }

        } 
      }
      setState(319);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
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

Pcl2Parser::RelationalExpressionContext::RelationalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::ShiftExpressionContext* Pcl2Parser::RelationalExpressionContext::shiftExpression() {
  return getRuleContext<Pcl2Parser::ShiftExpressionContext>(0);
}

Pcl2Parser::RelationalExpressionContext* Pcl2Parser::RelationalExpressionContext::relationalExpression() {
  return getRuleContext<Pcl2Parser::RelationalExpressionContext>(0);
}


size_t Pcl2Parser::RelationalExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleRelationalExpression;
}

void Pcl2Parser::RelationalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}

void Pcl2Parser::RelationalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}


antlrcpp::Any Pcl2Parser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::RelationalExpressionContext* Pcl2Parser::relationalExpression() {
   return relationalExpression(0);
}

Pcl2Parser::RelationalExpressionContext* Pcl2Parser::relationalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, parentState);
  Pcl2Parser::RelationalExpressionContext *previousContext = _localctx;
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, Pcl2Parser::RuleRelationalExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(321);
    shiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(337);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(335);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(323);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(324);
          match(Pcl2Parser::Less);
          setState(325);
          shiftExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(326);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(327);
          match(Pcl2Parser::Greater);
          setState(328);
          shiftExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(329);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(330);
          match(Pcl2Parser::LessEqual);
          setState(331);
          shiftExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
          setState(332);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(333);
          match(Pcl2Parser::GreaterEqual);
          setState(334);
          shiftExpression(0);
          break;
        }

        } 
      }
      setState(339);
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

//----------------- EqualityExpressionContext ------------------------------------------------------------------

Pcl2Parser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::RelationalExpressionContext* Pcl2Parser::EqualityExpressionContext::relationalExpression() {
  return getRuleContext<Pcl2Parser::RelationalExpressionContext>(0);
}

Pcl2Parser::EqualityExpressionContext* Pcl2Parser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<Pcl2Parser::EqualityExpressionContext>(0);
}


size_t Pcl2Parser::EqualityExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleEqualityExpression;
}

void Pcl2Parser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}

void Pcl2Parser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}


antlrcpp::Any Pcl2Parser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::EqualityExpressionContext* Pcl2Parser::equalityExpression() {
   return equalityExpression(0);
}

Pcl2Parser::EqualityExpressionContext* Pcl2Parser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  Pcl2Parser::EqualityExpressionContext *previousContext = _localctx;
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, Pcl2Parser::RuleEqualityExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(341);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(357);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(355);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(343);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(344);
          match(Pcl2Parser::T__1);
          setState(345);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(346);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(347);
          match(Pcl2Parser::T__2);
          setState(348);
          relationalExpression(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(349);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(350);
          match(Pcl2Parser::T__3);
          setState(351);
          relationalExpression(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(352);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(353);
          match(Pcl2Parser::T__4);
          setState(354);
          relationalExpression(0);
          break;
        }

        } 
      }
      setState(359);
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

//----------------- AndExpressionContext ------------------------------------------------------------------

Pcl2Parser::AndExpressionContext::AndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::EqualityExpressionContext* Pcl2Parser::AndExpressionContext::equalityExpression() {
  return getRuleContext<Pcl2Parser::EqualityExpressionContext>(0);
}

Pcl2Parser::AndExpressionContext* Pcl2Parser::AndExpressionContext::andExpression() {
  return getRuleContext<Pcl2Parser::AndExpressionContext>(0);
}


size_t Pcl2Parser::AndExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleAndExpression;
}

void Pcl2Parser::AndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpression(this);
}

void Pcl2Parser::AndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpression(this);
}


antlrcpp::Any Pcl2Parser::AndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitAndExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::AndExpressionContext* Pcl2Parser::andExpression() {
   return andExpression(0);
}

Pcl2Parser::AndExpressionContext* Pcl2Parser::andExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::AndExpressionContext *_localctx = _tracker.createInstance<AndExpressionContext>(_ctx, parentState);
  Pcl2Parser::AndExpressionContext *previousContext = _localctx;
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, Pcl2Parser::RuleAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(361);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(368);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAndExpression);
        setState(363);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(364);
        match(Pcl2Parser::And);
        setState(365);
        equalityExpression(0); 
      }
      setState(370);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
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

Pcl2Parser::ExclusiveOrExpressionContext::ExclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::AndExpressionContext* Pcl2Parser::ExclusiveOrExpressionContext::andExpression() {
  return getRuleContext<Pcl2Parser::AndExpressionContext>(0);
}

Pcl2Parser::ExclusiveOrExpressionContext* Pcl2Parser::ExclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<Pcl2Parser::ExclusiveOrExpressionContext>(0);
}


size_t Pcl2Parser::ExclusiveOrExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleExclusiveOrExpression;
}

void Pcl2Parser::ExclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExclusiveOrExpression(this);
}

void Pcl2Parser::ExclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExclusiveOrExpression(this);
}


antlrcpp::Any Pcl2Parser::ExclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitExclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::ExclusiveOrExpressionContext* Pcl2Parser::exclusiveOrExpression() {
   return exclusiveOrExpression(0);
}

Pcl2Parser::ExclusiveOrExpressionContext* Pcl2Parser::exclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::ExclusiveOrExpressionContext *_localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(_ctx, parentState);
  Pcl2Parser::ExclusiveOrExpressionContext *previousContext = _localctx;
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, Pcl2Parser::RuleExclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(372);
    andExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(379);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExclusiveOrExpression);
        setState(374);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(375);
        match(Pcl2Parser::Caret);
        setState(376);
        andExpression(0); 
      }
      setState(381);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
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

Pcl2Parser::InclusiveOrExpressionContext::InclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::ExclusiveOrExpressionContext* Pcl2Parser::InclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContext<Pcl2Parser::ExclusiveOrExpressionContext>(0);
}

Pcl2Parser::InclusiveOrExpressionContext* Pcl2Parser::InclusiveOrExpressionContext::inclusiveOrExpression() {
  return getRuleContext<Pcl2Parser::InclusiveOrExpressionContext>(0);
}


size_t Pcl2Parser::InclusiveOrExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleInclusiveOrExpression;
}

void Pcl2Parser::InclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInclusiveOrExpression(this);
}

void Pcl2Parser::InclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInclusiveOrExpression(this);
}


antlrcpp::Any Pcl2Parser::InclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitInclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::InclusiveOrExpressionContext* Pcl2Parser::inclusiveOrExpression() {
   return inclusiveOrExpression(0);
}

Pcl2Parser::InclusiveOrExpressionContext* Pcl2Parser::inclusiveOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::InclusiveOrExpressionContext *_localctx = _tracker.createInstance<InclusiveOrExpressionContext>(_ctx, parentState);
  Pcl2Parser::InclusiveOrExpressionContext *previousContext = _localctx;
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, Pcl2Parser::RuleInclusiveOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(383);
    exclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(390);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<InclusiveOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleInclusiveOrExpression);
        setState(385);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(386);
        match(Pcl2Parser::Or);
        setState(387);
        exclusiveOrExpression(0); 
      }
      setState(392);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
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

Pcl2Parser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::InclusiveOrExpressionContext* Pcl2Parser::LogicalAndExpressionContext::inclusiveOrExpression() {
  return getRuleContext<Pcl2Parser::InclusiveOrExpressionContext>(0);
}

Pcl2Parser::LogicalAndExpressionContext* Pcl2Parser::LogicalAndExpressionContext::logicalAndExpression() {
  return getRuleContext<Pcl2Parser::LogicalAndExpressionContext>(0);
}


size_t Pcl2Parser::LogicalAndExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleLogicalAndExpression;
}

void Pcl2Parser::LogicalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}

void Pcl2Parser::LogicalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}


antlrcpp::Any Pcl2Parser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::LogicalAndExpressionContext* Pcl2Parser::logicalAndExpression() {
   return logicalAndExpression(0);
}

Pcl2Parser::LogicalAndExpressionContext* Pcl2Parser::logicalAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, parentState);
  Pcl2Parser::LogicalAndExpressionContext *previousContext = _localctx;
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, Pcl2Parser::RuleLogicalAndExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(394);
    inclusiveOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(404);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(402);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
          setState(396);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(397);
          match(Pcl2Parser::T__5);
          setState(398);
          inclusiveOrExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
          setState(399);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(400);
          match(Pcl2Parser::T__6);
          setState(401);
          inclusiveOrExpression(0);
          break;
        }

        } 
      }
      setState(406);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
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

Pcl2Parser::LogicalOrExpressionContext::LogicalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::LogicalAndExpressionContext* Pcl2Parser::LogicalOrExpressionContext::logicalAndExpression() {
  return getRuleContext<Pcl2Parser::LogicalAndExpressionContext>(0);
}

Pcl2Parser::LogicalOrExpressionContext* Pcl2Parser::LogicalOrExpressionContext::logicalOrExpression() {
  return getRuleContext<Pcl2Parser::LogicalOrExpressionContext>(0);
}


size_t Pcl2Parser::LogicalOrExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleLogicalOrExpression;
}

void Pcl2Parser::LogicalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpression(this);
}

void Pcl2Parser::LogicalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpression(this);
}


antlrcpp::Any Pcl2Parser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::LogicalOrExpressionContext* Pcl2Parser::logicalOrExpression() {
   return logicalOrExpression(0);
}

Pcl2Parser::LogicalOrExpressionContext* Pcl2Parser::logicalOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::LogicalOrExpressionContext *_localctx = _tracker.createInstance<LogicalOrExpressionContext>(_ctx, parentState);
  Pcl2Parser::LogicalOrExpressionContext *previousContext = _localctx;
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, Pcl2Parser::RuleLogicalOrExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(408);
    logicalAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(418);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(416);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
          setState(410);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(411);
          match(Pcl2Parser::T__7);
          setState(412);
          logicalAndExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicalOrExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalOrExpression);
          setState(413);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(414);
          match(Pcl2Parser::T__8);
          setState(415);
          logicalAndExpression(0);
          break;
        }

        } 
      }
      setState(420);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
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

Pcl2Parser::LogicalOrExpressionContext* Pcl2Parser::ConditionalExpressionContext::logicalOrExpression() {
  return getRuleContext<Pcl2Parser::LogicalOrExpressionContext>(0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::ConditionalExpressionContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::ConditionalExpressionContext::conditionalExpression() {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(0);
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
  ConditionalExpressionContext *_localctx = _tracker.createInstance<ConditionalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 60, Pcl2Parser::RuleConditionalExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    logicalOrExpression(0);
    setState(427);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(422);
      match(Pcl2Parser::Question);
      setState(423);
      expression(0);
      setState(424);
      match(Pcl2Parser::Colon);
      setState(425);
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

Pcl2Parser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::ConditionalExpressionContext* Pcl2Parser::AssignmentExpressionContext::conditionalExpression() {
  return getRuleContext<Pcl2Parser::ConditionalExpressionContext>(0);
}

Pcl2Parser::UnaryExpressionContext* Pcl2Parser::AssignmentExpressionContext::unaryExpression() {
  return getRuleContext<Pcl2Parser::UnaryExpressionContext>(0);
}

Pcl2Parser::AssignmentOperatorContext* Pcl2Parser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<Pcl2Parser::AssignmentOperatorContext>(0);
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::AssignmentExpressionContext::assignmentExpression() {
  return getRuleContext<Pcl2Parser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* Pcl2Parser::AssignmentExpressionContext::DigitSequence() {
  return getToken(Pcl2Parser::DigitSequence, 0);
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
  enterRule(_localctx, 62, Pcl2Parser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(435);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(429);
      conditionalExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(430);
      unaryExpression();
      setState(431);
      assignmentOperator();
      setState(432);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(434);
      match(Pcl2Parser::DigitSequence);
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

Pcl2Parser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::AssignmentOperatorContext::NegateAssign() {
  return getToken(Pcl2Parser::NegateAssign, 0);
}


size_t Pcl2Parser::AssignmentOperatorContext::getRuleIndex() const {
  return Pcl2Parser::RuleAssignmentOperator;
}

void Pcl2Parser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void Pcl2Parser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


antlrcpp::Any Pcl2Parser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::AssignmentOperatorContext* Pcl2Parser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 64, Pcl2Parser::RuleAssignmentOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    _la = _input->LA(1);
    if (!(((((_la - 74) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 74)) & ((1ULL << (Pcl2Parser::Assign - 74))
      | (1ULL << (Pcl2Parser::StarAssign - 74))
      | (1ULL << (Pcl2Parser::DivAssign - 74))
      | (1ULL << (Pcl2Parser::ModAssign - 74))
      | (1ULL << (Pcl2Parser::PlusAssign - 74))
      | (1ULL << (Pcl2Parser::MinusAssign - 74))
      | (1ULL << (Pcl2Parser::LeftShiftAssign - 74))
      | (1ULL << (Pcl2Parser::RightShiftAssign - 74))
      | (1ULL << (Pcl2Parser::AndAssign - 74))
      | (1ULL << (Pcl2Parser::XorAssign - 74))
      | (1ULL << (Pcl2Parser::OrAssign - 74))
      | (1ULL << (Pcl2Parser::NegateAssign - 74)))) != 0))) {
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

Pcl2Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::ExpressionContext::assignmentExpression() {
  return getRuleContext<Pcl2Parser::AssignmentExpressionContext>(0);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::ExpressionContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}


size_t Pcl2Parser::ExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleExpression;
}

void Pcl2Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void Pcl2Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any Pcl2Parser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitExpression(this);
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
  size_t startState = 66;
  enterRecursionRule(_localctx, 66, Pcl2Parser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(440);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(447);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(442);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(443);
        match(Pcl2Parser::Comma);
        setState(444);
        assignmentExpression(); 
      }
      setState(449);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
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

Pcl2Parser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::IdentifierListContext::Identifier() {
  return getToken(Pcl2Parser::Identifier, 0);
}

Pcl2Parser::IdentifierListContext* Pcl2Parser::IdentifierListContext::identifierList() {
  return getRuleContext<Pcl2Parser::IdentifierListContext>(0);
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
   return identifierList(0);
}

Pcl2Parser::IdentifierListContext* Pcl2Parser::identifierList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, parentState);
  Pcl2Parser::IdentifierListContext *previousContext = _localctx;
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, Pcl2Parser::RuleIdentifierList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(451);
    match(Pcl2Parser::Identifier);
    _ctx->stop = _input->LT(-1);
    setState(458);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IdentifierListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIdentifierList);
        setState(453);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(454);
        match(Pcl2Parser::Comma);
        setState(455);
        match(Pcl2Parser::Identifier); 
      }
      setState(460);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
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
  enterRule(_localctx, 70, Pcl2Parser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(465);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::LeftBrace: {
        enterOuterAlt(_localctx, 1);
        setState(461);
        compoundStatement();
        break;
      }

      case Pcl2Parser::T__0:
      case Pcl2Parser::Constant:
      case Pcl2Parser::DigitSequence:
      case Pcl2Parser::StringLiteral:
      case Pcl2Parser::LeftParen:
      case Pcl2Parser::Plus:
      case Pcl2Parser::PlusPlus:
      case Pcl2Parser::Minus:
      case Pcl2Parser::MinusMinus:
      case Pcl2Parser::Star:
      case Pcl2Parser::And:
      case Pcl2Parser::Negate:
      case Pcl2Parser::Semi:
      case Pcl2Parser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(462);
        expressionStatement();
        break;
      }

      case Pcl2Parser::If: {
        enterOuterAlt(_localctx, 3);
        setState(463);
        selectionStatement();
        break;
      }

      case Pcl2Parser::For: {
        enterOuterAlt(_localctx, 4);
        setState(464);
        iterationStatement();
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

Pcl2Parser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 72, Pcl2Parser::RuleCompoundStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    match(Pcl2Parser::LeftBrace);
    setState(469);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::T__0)
      | (1ULL << Pcl2Parser::Constant)
      | (1ULL << Pcl2Parser::DigitSequence)
      | (1ULL << Pcl2Parser::StringLiteral)
      | (1ULL << Pcl2Parser::Char)
      | (1ULL << Pcl2Parser::Bool)
      | (1ULL << Pcl2Parser::Double)
      | (1ULL << Pcl2Parser::Float)
      | (1ULL << Pcl2Parser::For)
      | (1ULL << Pcl2Parser::If)
      | (1ULL << Pcl2Parser::Int)
      | (1ULL << Pcl2Parser::Uint32)
      | (1ULL << Pcl2Parser::Int32)
      | (1ULL << Pcl2Parser::Long)
      | (1ULL << Pcl2Parser::Short)
      | (1ULL << Pcl2Parser::Signed)
      | (1ULL << Pcl2Parser::Unsigned)
      | (1ULL << Pcl2Parser::Void)
      | (1ULL << Pcl2Parser::LeftParen)
      | (1ULL << Pcl2Parser::LeftBrace)
      | (1ULL << Pcl2Parser::Plus)
      | (1ULL << Pcl2Parser::PlusPlus)
      | (1ULL << Pcl2Parser::Minus)
      | (1ULL << Pcl2Parser::MinusMinus)
      | (1ULL << Pcl2Parser::Star))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (Pcl2Parser::And - 66))
      | (1ULL << (Pcl2Parser::Negate - 66))
      | (1ULL << (Pcl2Parser::Semi - 66))
      | (1ULL << (Pcl2Parser::Identifier - 66)))) != 0)) {
      setState(468);
      blockItemList(0);
    }
    setState(471);
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
  size_t startState = 74;
  enterRecursionRule(_localctx, 74, Pcl2Parser::RuleBlockItemList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(474);
    blockItem();
    _ctx->stop = _input->LT(-1);
    setState(480);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BlockItemListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBlockItemList);
        setState(476);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(477);
        blockItem(); 
      }
      setState(482);
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
  enterRule(_localctx, 76, Pcl2Parser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(485);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::T__0:
      case Pcl2Parser::Constant:
      case Pcl2Parser::DigitSequence:
      case Pcl2Parser::StringLiteral:
      case Pcl2Parser::For:
      case Pcl2Parser::If:
      case Pcl2Parser::LeftParen:
      case Pcl2Parser::LeftBrace:
      case Pcl2Parser::Plus:
      case Pcl2Parser::PlusPlus:
      case Pcl2Parser::Minus:
      case Pcl2Parser::MinusMinus:
      case Pcl2Parser::Star:
      case Pcl2Parser::And:
      case Pcl2Parser::Negate:
      case Pcl2Parser::Semi:
      case Pcl2Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(483);
        statement();
        break;
      }

      case Pcl2Parser::Char:
      case Pcl2Parser::Bool:
      case Pcl2Parser::Double:
      case Pcl2Parser::Float:
      case Pcl2Parser::Int:
      case Pcl2Parser::Uint32:
      case Pcl2Parser::Int32:
      case Pcl2Parser::Long:
      case Pcl2Parser::Short:
      case Pcl2Parser::Signed:
      case Pcl2Parser::Unsigned:
      case Pcl2Parser::Void: {
        enterOuterAlt(_localctx, 2);
        setState(484);
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

//----------------- IterationStatementContext ------------------------------------------------------------------

Pcl2Parser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Pcl2Parser::IterationStatementContext::For() {
  return getToken(Pcl2Parser::For, 0);
}

Pcl2Parser::ForConditionContext* Pcl2Parser::IterationStatementContext::forCondition() {
  return getRuleContext<Pcl2Parser::ForConditionContext>(0);
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
  enterRule(_localctx, 78, Pcl2Parser::RuleIterationStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    match(Pcl2Parser::For);
    setState(488);
    match(Pcl2Parser::LeftParen);
    setState(489);
    forCondition();
    setState(490);
    match(Pcl2Parser::RightParen);
    setState(491);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForConditionContext ------------------------------------------------------------------

Pcl2Parser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::ForDeclarationContext* Pcl2Parser::ForConditionContext::forDeclaration() {
  return getRuleContext<Pcl2Parser::ForDeclarationContext>(0);
}

std::vector<Pcl2Parser::ForExpressionContext *> Pcl2Parser::ForConditionContext::forExpression() {
  return getRuleContexts<Pcl2Parser::ForExpressionContext>();
}

Pcl2Parser::ForExpressionContext* Pcl2Parser::ForConditionContext::forExpression(size_t i) {
  return getRuleContext<Pcl2Parser::ForExpressionContext>(i);
}

Pcl2Parser::ExpressionContext* Pcl2Parser::ForConditionContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}


size_t Pcl2Parser::ForConditionContext::getRuleIndex() const {
  return Pcl2Parser::RuleForCondition;
}

void Pcl2Parser::ForConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForCondition(this);
}

void Pcl2Parser::ForConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForCondition(this);
}


antlrcpp::Any Pcl2Parser::ForConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitForCondition(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ForConditionContext* Pcl2Parser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 80, Pcl2Parser::RuleForCondition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(513);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Pcl2Parser::Char:
      case Pcl2Parser::Bool:
      case Pcl2Parser::Double:
      case Pcl2Parser::Float:
      case Pcl2Parser::Int:
      case Pcl2Parser::Uint32:
      case Pcl2Parser::Int32:
      case Pcl2Parser::Long:
      case Pcl2Parser::Short:
      case Pcl2Parser::Signed:
      case Pcl2Parser::Unsigned:
      case Pcl2Parser::Void: {
        enterOuterAlt(_localctx, 1);
        setState(493);
        forDeclaration();
        setState(494);
        match(Pcl2Parser::Semi);
        setState(496);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Pcl2Parser::T__0)
          | (1ULL << Pcl2Parser::Constant)
          | (1ULL << Pcl2Parser::DigitSequence)
          | (1ULL << Pcl2Parser::StringLiteral)
          | (1ULL << Pcl2Parser::LeftParen)
          | (1ULL << Pcl2Parser::Plus)
          | (1ULL << Pcl2Parser::PlusPlus)
          | (1ULL << Pcl2Parser::Minus)
          | (1ULL << Pcl2Parser::MinusMinus)
          | (1ULL << Pcl2Parser::Star))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 66)) & ((1ULL << (Pcl2Parser::And - 66))
          | (1ULL << (Pcl2Parser::Negate - 66))
          | (1ULL << (Pcl2Parser::Identifier - 66)))) != 0)) {
          setState(495);
          forExpression(0);
        }
        setState(498);
        match(Pcl2Parser::Semi);
        setState(500);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Pcl2Parser::T__0)
          | (1ULL << Pcl2Parser::Constant)
          | (1ULL << Pcl2Parser::DigitSequence)
          | (1ULL << Pcl2Parser::StringLiteral)
          | (1ULL << Pcl2Parser::LeftParen)
          | (1ULL << Pcl2Parser::Plus)
          | (1ULL << Pcl2Parser::PlusPlus)
          | (1ULL << Pcl2Parser::Minus)
          | (1ULL << Pcl2Parser::MinusMinus)
          | (1ULL << Pcl2Parser::Star))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 66)) & ((1ULL << (Pcl2Parser::And - 66))
          | (1ULL << (Pcl2Parser::Negate - 66))
          | (1ULL << (Pcl2Parser::Identifier - 66)))) != 0)) {
          setState(499);
          forExpression(0);
        }
        break;
      }

      case Pcl2Parser::T__0:
      case Pcl2Parser::Constant:
      case Pcl2Parser::DigitSequence:
      case Pcl2Parser::StringLiteral:
      case Pcl2Parser::LeftParen:
      case Pcl2Parser::Plus:
      case Pcl2Parser::PlusPlus:
      case Pcl2Parser::Minus:
      case Pcl2Parser::MinusMinus:
      case Pcl2Parser::Star:
      case Pcl2Parser::And:
      case Pcl2Parser::Negate:
      case Pcl2Parser::Semi:
      case Pcl2Parser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(503);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Pcl2Parser::T__0)
          | (1ULL << Pcl2Parser::Constant)
          | (1ULL << Pcl2Parser::DigitSequence)
          | (1ULL << Pcl2Parser::StringLiteral)
          | (1ULL << Pcl2Parser::LeftParen)
          | (1ULL << Pcl2Parser::Plus)
          | (1ULL << Pcl2Parser::PlusPlus)
          | (1ULL << Pcl2Parser::Minus)
          | (1ULL << Pcl2Parser::MinusMinus)
          | (1ULL << Pcl2Parser::Star))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 66)) & ((1ULL << (Pcl2Parser::And - 66))
          | (1ULL << (Pcl2Parser::Negate - 66))
          | (1ULL << (Pcl2Parser::Identifier - 66)))) != 0)) {
          setState(502);
          expression(0);
        }
        setState(505);
        match(Pcl2Parser::Semi);
        setState(507);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Pcl2Parser::T__0)
          | (1ULL << Pcl2Parser::Constant)
          | (1ULL << Pcl2Parser::DigitSequence)
          | (1ULL << Pcl2Parser::StringLiteral)
          | (1ULL << Pcl2Parser::LeftParen)
          | (1ULL << Pcl2Parser::Plus)
          | (1ULL << Pcl2Parser::PlusPlus)
          | (1ULL << Pcl2Parser::Minus)
          | (1ULL << Pcl2Parser::MinusMinus)
          | (1ULL << Pcl2Parser::Star))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 66)) & ((1ULL << (Pcl2Parser::And - 66))
          | (1ULL << (Pcl2Parser::Negate - 66))
          | (1ULL << (Pcl2Parser::Identifier - 66)))) != 0)) {
          setState(506);
          forExpression(0);
        }
        setState(509);
        match(Pcl2Parser::Semi);
        setState(511);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Pcl2Parser::T__0)
          | (1ULL << Pcl2Parser::Constant)
          | (1ULL << Pcl2Parser::DigitSequence)
          | (1ULL << Pcl2Parser::StringLiteral)
          | (1ULL << Pcl2Parser::LeftParen)
          | (1ULL << Pcl2Parser::Plus)
          | (1ULL << Pcl2Parser::PlusPlus)
          | (1ULL << Pcl2Parser::Minus)
          | (1ULL << Pcl2Parser::MinusMinus)
          | (1ULL << Pcl2Parser::Star))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 66)) & ((1ULL << (Pcl2Parser::And - 66))
          | (1ULL << (Pcl2Parser::Negate - 66))
          | (1ULL << (Pcl2Parser::Identifier - 66)))) != 0)) {
          setState(510);
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

Pcl2Parser::ForDeclarationContext::ForDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::DeclarationSpecifiersContext* Pcl2Parser::ForDeclarationContext::declarationSpecifiers() {
  return getRuleContext<Pcl2Parser::DeclarationSpecifiersContext>(0);
}

Pcl2Parser::InitDeclaratorListContext* Pcl2Parser::ForDeclarationContext::initDeclaratorList() {
  return getRuleContext<Pcl2Parser::InitDeclaratorListContext>(0);
}


size_t Pcl2Parser::ForDeclarationContext::getRuleIndex() const {
  return Pcl2Parser::RuleForDeclaration;
}

void Pcl2Parser::ForDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForDeclaration(this);
}

void Pcl2Parser::ForDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForDeclaration(this);
}


antlrcpp::Any Pcl2Parser::ForDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitForDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::ForDeclarationContext* Pcl2Parser::forDeclaration() {
  ForDeclarationContext *_localctx = _tracker.createInstance<ForDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 82, Pcl2Parser::RuleForDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(519);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(515);
      declarationSpecifiers();
      setState(516);
      initDeclaratorList(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(518);
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

Pcl2Parser::ForExpressionContext::ForExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::ForExpressionContext::assignmentExpression() {
  return getRuleContext<Pcl2Parser::AssignmentExpressionContext>(0);
}

Pcl2Parser::ForExpressionContext* Pcl2Parser::ForExpressionContext::forExpression() {
  return getRuleContext<Pcl2Parser::ForExpressionContext>(0);
}


size_t Pcl2Parser::ForExpressionContext::getRuleIndex() const {
  return Pcl2Parser::RuleForExpression;
}

void Pcl2Parser::ForExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForExpression(this);
}

void Pcl2Parser::ForExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForExpression(this);
}


antlrcpp::Any Pcl2Parser::ForExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitForExpression(this);
  else
    return visitor->visitChildren(this);
}


Pcl2Parser::ForExpressionContext* Pcl2Parser::forExpression() {
   return forExpression(0);
}

Pcl2Parser::ForExpressionContext* Pcl2Parser::forExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Pcl2Parser::ForExpressionContext *_localctx = _tracker.createInstance<ForExpressionContext>(_ctx, parentState);
  Pcl2Parser::ForExpressionContext *previousContext = _localctx;
  size_t startState = 84;
  enterRecursionRule(_localctx, 84, Pcl2Parser::RuleForExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(522);
    assignmentExpression();
    _ctx->stop = _input->LT(-1);
    setState(529);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ForExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleForExpression);
        setState(524);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(525);
        match(Pcl2Parser::Comma);
        setState(526);
        assignmentExpression(); 
      }
      setState(531);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
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

Pcl2Parser::InitializerContext::InitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Pcl2Parser::AssignmentExpressionContext* Pcl2Parser::InitializerContext::assignmentExpression() {
  return getRuleContext<Pcl2Parser::AssignmentExpressionContext>(0);
}


size_t Pcl2Parser::InitializerContext::getRuleIndex() const {
  return Pcl2Parser::RuleInitializer;
}

void Pcl2Parser::InitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitializer(this);
}

void Pcl2Parser::InitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Pcl2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitializer(this);
}


antlrcpp::Any Pcl2Parser::InitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Pcl2Visitor*>(visitor))
    return parserVisitor->visitInitializer(this);
  else
    return visitor->visitChildren(this);
}

Pcl2Parser::InitializerContext* Pcl2Parser::initializer() {
  InitializerContext *_localctx = _tracker.createInstance<InitializerContext>(_ctx, getState());
  enterRule(_localctx, 86, Pcl2Parser::RuleInitializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(532);
    assignmentExpression();
   
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
  enterRule(_localctx, 88, Pcl2Parser::RuleExpressionStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(535);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Pcl2Parser::T__0)
      | (1ULL << Pcl2Parser::Constant)
      | (1ULL << Pcl2Parser::DigitSequence)
      | (1ULL << Pcl2Parser::StringLiteral)
      | (1ULL << Pcl2Parser::LeftParen)
      | (1ULL << Pcl2Parser::Plus)
      | (1ULL << Pcl2Parser::PlusPlus)
      | (1ULL << Pcl2Parser::Minus)
      | (1ULL << Pcl2Parser::MinusMinus)
      | (1ULL << Pcl2Parser::Star))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (Pcl2Parser::And - 66))
      | (1ULL << (Pcl2Parser::Negate - 66))
      | (1ULL << (Pcl2Parser::Identifier - 66)))) != 0)) {
      setState(534);
      expression(0);
    }
    setState(537);
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

Pcl2Parser::ExpressionContext* Pcl2Parser::SelectionStatementContext::expression() {
  return getRuleContext<Pcl2Parser::ExpressionContext>(0);
}

std::vector<Pcl2Parser::StatementContext *> Pcl2Parser::SelectionStatementContext::statement() {
  return getRuleContexts<Pcl2Parser::StatementContext>();
}

Pcl2Parser::StatementContext* Pcl2Parser::SelectionStatementContext::statement(size_t i) {
  return getRuleContext<Pcl2Parser::StatementContext>(i);
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
  enterRule(_localctx, 90, Pcl2Parser::RuleSelectionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(539);
    match(Pcl2Parser::If);
    setState(540);
    match(Pcl2Parser::LeftParen);
    setState(541);
    expression(0);
    setState(542);
    match(Pcl2Parser::RightParen);
    setState(543);
    statement();
    setState(546);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      setState(544);
      match(Pcl2Parser::Else);
      setState(545);
      statement();
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
    case 7: return initDeclaratorListSempred(dynamic_cast<InitDeclaratorListContext *>(context), predicateIndex);
    case 11: return directDeclaratorSempred(dynamic_cast<DirectDeclaratorContext *>(context), predicateIndex);
    case 13: return parameterListSempred(dynamic_cast<ParameterListContext *>(context), predicateIndex);
    case 16: return postfixExpressionSempred(dynamic_cast<PostfixExpressionContext *>(context), predicateIndex);
    case 17: return argumentExpressionListSempred(dynamic_cast<ArgumentExpressionListContext *>(context), predicateIndex);
    case 20: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 21: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 22: return shiftExpressionSempred(dynamic_cast<ShiftExpressionContext *>(context), predicateIndex);
    case 23: return relationalExpressionSempred(dynamic_cast<RelationalExpressionContext *>(context), predicateIndex);
    case 24: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 25: return andExpressionSempred(dynamic_cast<AndExpressionContext *>(context), predicateIndex);
    case 26: return exclusiveOrExpressionSempred(dynamic_cast<ExclusiveOrExpressionContext *>(context), predicateIndex);
    case 27: return inclusiveOrExpressionSempred(dynamic_cast<InclusiveOrExpressionContext *>(context), predicateIndex);
    case 28: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 29: return logicalOrExpressionSempred(dynamic_cast<LogicalOrExpressionContext *>(context), predicateIndex);
    case 33: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 34: return identifierListSempred(dynamic_cast<IdentifierListContext *>(context), predicateIndex);
    case 37: return blockItemListSempred(dynamic_cast<BlockItemListContext *>(context), predicateIndex);
    case 42: return forExpressionSempred(dynamic_cast<ForExpressionContext *>(context), predicateIndex);

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

bool Pcl2Parser::initDeclaratorListSempred(InitDeclaratorListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::parameterListSempred(ParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::argumentExpressionListSempred(ArgumentExpressionListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 3);
    case 10: return precpred(_ctx, 2);
    case 11: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 2);
    case 13: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::shiftExpressionSempred(ShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 14: return precpred(_ctx, 2);
    case 15: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::relationalExpressionSempred(RelationalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 4);
    case 17: return precpred(_ctx, 3);
    case 18: return precpred(_ctx, 2);
    case 19: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 20: return precpred(_ctx, 4);
    case 21: return precpred(_ctx, 3);
    case 22: return precpred(_ctx, 2);
    case 23: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::andExpressionSempred(AndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 24: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::exclusiveOrExpressionSempred(ExclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 25: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::inclusiveOrExpressionSempred(InclusiveOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 26: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 27: return precpred(_ctx, 2);
    case 28: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::logicalOrExpressionSempred(LogicalOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 29: return precpred(_ctx, 2);
    case 30: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 31: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::identifierListSempred(IdentifierListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 32: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::blockItemListSempred(BlockItemListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 33: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool Pcl2Parser::forExpressionSempred(ForExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 34: return precpred(_ctx, 1);

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
  "compilationUnit", "translationUnit", "externalDeclaration", "functionDefinition", 
  "declaration", "declarationSpecifiers", "declarationSpecifier", "initDeclaratorList", 
  "initDeclarator", "typeSpecifier", "declarator", "directDeclarator", "parameterTypeList", 
  "parameterList", "parameterDeclaration", "primaryExpression", "postfixExpression", 
  "argumentExpressionList", "unaryExpression", "unaryOperator", "multiplicativeExpression", 
  "additiveExpression", "shiftExpression", "relationalExpression", "equalityExpression", 
  "andExpression", "exclusiveOrExpression", "inclusiveOrExpression", "logicalAndExpression", 
  "logicalOrExpression", "conditionalExpression", "assignmentExpression", 
  "assignmentOperator", "expression", "identifierList", "statement", "compoundStatement", 
  "blockItemList", "blockItem", "iterationStatement", "forCondition", "forDeclaration", 
  "forExpression", "initializer", "expressionStatement", "selectionStatement"
};

std::vector<std::string> Pcl2Parser::_literalNames = {
  "", "'!'", "'is'", "'is not'", "'=='", "'!='", "'&&'", "'and'", "'||'", 
  "'or'", "", "", "", "'??'", "'@'", "'**'", "'_'", "'namespace'", "'::'", 
  "'string'", "'break'", "'case'", "'char'", "'const'", "'continue'", "'bool'", 
  "'default'", "'double'", "'else'", "'extern'", "'float'", "'for'", "'if'", 
  "'int'", "'uint32_t'", "'int32_t'", "'long'", "'return'", "'short'", "'signed'", 
  "'sizeof'", "'static'", "'switch'", "'typedef'", "'unsigned'", "'void'", 
  "'while'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", 
  "'>='", "'<<'", "'>>'", "'+'", "'++'", "'-'", "'--'", "'*'", "'/'", "'%'", 
  "'&'", "'|'", "'~'", "'^'", "'?'", "':'", "';'", "','", "'='", "'*='", 
  "'/='", "'%='", "'+='", "'-='", "'<<='", "'>>='", "'&='", "'^='", "'|='", 
  "'~='", "'->'", "'.'", "'...'"
};

std::vector<std::string> Pcl2Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "Constant", "DigitSequence", "StringLiteral", 
  "Coalescing", "Bit", "Power", "IgnoreWildCard", "Namespace", "ScopeResolution", 
  "String", "Break", "Case", "Char", "Const", "Continue", "Bool", "Default", 
  "Double", "Else", "Extern", "Float", "For", "If", "Int", "Uint32", "Int32", 
  "Long", "Return", "Short", "Signed", "Sizeof", "Static", "Switch", "Typedef", 
  "Unsigned", "Void", "While", "LeftParen", "RightParen", "LeftBracket", 
  "RightBracket", "LeftBrace", "RightBrace", "Less", "LessEqual", "Greater", 
  "GreaterEqual", "LeftShift", "RightShift", "Plus", "PlusPlus", "Minus", 
  "MinusMinus", "Star", "Div", "Mod", "And", "Or", "Negate", "Caret", "Question", 
  "Colon", "Semi", "Comma", "Assign", "StarAssign", "DivAssign", "ModAssign", 
  "PlusAssign", "MinusAssign", "LeftShiftAssign", "RightShiftAssign", "AndAssign", 
  "XorAssign", "OrAssign", "NegateAssign", "Arrow", "Dot", "Ellipsis", "AndAnd", 
  "OrOr", "Not", "Equal", "NotEqual", "Identifier", "Whitespace", "Newline", 
  "BlockComment", "LineComment"
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
    0x3, 0x64, 0x227, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x9, 0x2f, 0x3, 0x2, 0x5, 0x2, 0x60, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x69, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x6c, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x71, 0xa, 0x4, 0x3, 0x5, 0x5, 0x5, 0x74, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x80, 0xa, 0x6, 0x3, 0x7, 0x6, 0x7, 0x83, 0xa, 
    0x7, 0xd, 0x7, 0xe, 0x7, 0x84, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x8d, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x90, 
    0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x95, 0xa, 0x9, 0xc, 
    0x9, 0xe, 0x9, 0x98, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x5, 0xa, 0x9f, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0xad, 0xa, 0xb, 0x3, 0xc, 0x5, 0xc, 0xb0, 0xa, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0xbf, 0xa, 0xd, 0x3, 0xd, 0x7, 0xd, 0xc2, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0xc5, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x5, 0xe, 0xcc, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x7, 0xf, 0xd4, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xd7, 0xb, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xdd, 0xa, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x6, 0x11, 0xe2, 0xa, 0x11, 0xd, 
    0x11, 0xe, 0x11, 0xe3, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 
    0x11, 0xea, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x5, 0x12, 0xf2, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xf9, 0xa, 0x12, 0xc, 0x12, 0xe, 
    0x12, 0xfc, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x7, 0x13, 0x104, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0x107, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x112, 0xa, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x7, 0x16, 0x122, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x125, 
    0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x130, 0xa, 0x17, 
    0xc, 0x17, 0xe, 0x17, 0x133, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 
    0x18, 0x13e, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x141, 0xb, 0x18, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x7, 0x19, 0x152, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
    0x155, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x166, 0xa, 0x1a, 
    0xc, 0x1a, 0xe, 0x1a, 0x169, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x171, 0xa, 0x1b, 0xc, 0x1b, 
    0xe, 0x1b, 0x174, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x17c, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
    0x17f, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x7, 0x1d, 0x187, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x18a, 
    0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x195, 0xa, 0x1e, 
    0xc, 0x1e, 0xe, 0x1e, 0x198, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 
    0x1f, 0x1a3, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x1a6, 0xb, 0x1f, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 
    0x1ae, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x5, 0x21, 0x1b6, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x1c0, 
    0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x1c3, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x1cb, 0xa, 0x24, 
    0xc, 0x24, 0xe, 0x24, 0x1ce, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x5, 0x25, 0x1d4, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 
    0x1d8, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x1e1, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 
    0x1e4, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1e8, 0xa, 0x28, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1f3, 0xa, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x5, 0x2a, 0x1f7, 0xa, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1fa, 
    0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1fe, 0xa, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x5, 0x2a, 0x202, 0xa, 0x2a, 0x5, 0x2a, 0x204, 0xa, 0x2a, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x20a, 0xa, 0x2b, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 
    0x2c, 0x212, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x215, 0xb, 0x2c, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x5, 0x2e, 0x21a, 0xa, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x225, 0xa, 0x2f, 0x3, 0x2f, 0x2, 0x16, 
    0x4, 0x10, 0x18, 0x1c, 0x22, 0x24, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x3c, 0x44, 0x46, 0x4c, 0x56, 0x30, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
    0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x2, 0x4, 0x8, 0x2, 0x3, 0x3, 
    0x3d, 0x3d, 0x3f, 0x3f, 0x41, 0x41, 0x44, 0x44, 0x46, 0x46, 0x3, 0x2, 
    0x4c, 0x57, 0x2, 0x24c, 0x2, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x70, 0x3, 0x2, 0x2, 0x2, 0x8, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x7f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x82, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x10, 0x88, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0xac, 0x3, 0x2, 0x2, 0x2, 0x16, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xdc, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x22, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x26, 0x111, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0x113, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x115, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x126, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x134, 0x3, 0x2, 0x2, 0x2, 0x30, 0x142, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x156, 0x3, 0x2, 0x2, 0x2, 0x34, 0x16a, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x175, 0x3, 0x2, 0x2, 0x2, 0x38, 0x180, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x199, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x1b7, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1c4, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1d5, 0x3, 
    0x2, 0x2, 0x2, 0x4c, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1e7, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x52, 0x203, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x209, 0x3, 0x2, 0x2, 0x2, 0x56, 0x20b, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x216, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x219, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x21d, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x60, 0x5, 0x4, 0x3, 0x2, 0x5f, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0x2, 0x2, 0x3, 0x62, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x63, 0x64, 0x8, 0x3, 0x1, 0x2, 0x64, 0x65, 0x5, 0x6, 0x4, 
    0x2, 0x65, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0xc, 0x3, 0x2, 0x2, 
    0x67, 0x69, 0x5, 0x6, 0x4, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x69, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x6b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x6d, 0x71, 0x5, 0x8, 0x5, 0x2, 0x6e, 0x71, 0x5, 0xa, 
    0x6, 0x2, 0x6f, 0x71, 0x7, 0x4a, 0x2, 0x2, 0x70, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x7, 0x3, 0x2, 0x2, 0x2, 0x72, 0x74, 0x5, 0xc, 0x7, 0x2, 0x73, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 
    0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x5, 0x16, 0xc, 0x2, 0x76, 0x77, 0x5, 
    0x4a, 0x26, 0x2, 0x77, 0x9, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x5, 0xc, 
    0x7, 0x2, 0x79, 0x7a, 0x5, 0x10, 0x9, 0x2, 0x7a, 0x7b, 0x7, 0x4a, 0x2, 
    0x2, 0x7b, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0xe, 0x8, 0x2, 
    0x7d, 0x7e, 0x7, 0x4a, 0x2, 0x2, 0x7e, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x80, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x83, 0x5, 0xe, 0x8, 0x2, 0x82, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x87, 0x5, 0x14, 0xb, 0x2, 0x87, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x89, 0x8, 0x9, 0x1, 0x2, 0x89, 0x8e, 0x5, 0x12, 0xa, 0x2, 0x8a, 
    0x8b, 0x7, 0x4b, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x12, 0xa, 0x2, 0x8c, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x96, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0xc, 0x3, 0x2, 
    0x2, 0x92, 0x93, 0x7, 0x4b, 0x2, 0x2, 0x93, 0x95, 0x5, 0x12, 0xa, 0x2, 
    0x94, 0x91, 0x3, 0x2, 0x2, 0x2, 0x95, 0x98, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9f, 0x5, 
    0x16, 0xc, 0x2, 0x9a, 0x9b, 0x5, 0x16, 0xc, 0x2, 0x9b, 0x9c, 0x7, 0x4c, 
    0x2, 0x2, 0x9c, 0x9d, 0x5, 0x58, 0x2d, 0x2, 0x9d, 0x9f, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9a, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xad, 0x7, 0x2f, 0x2, 0x2, 0xa1, 
    0xad, 0x7, 0x1b, 0x2, 0x2, 0xa2, 0xad, 0x7, 0x18, 0x2, 0x2, 0xa3, 0xad, 
    0x7, 0x28, 0x2, 0x2, 0xa4, 0xad, 0x7, 0x23, 0x2, 0x2, 0xa5, 0xad, 0x7, 
    0x26, 0x2, 0x2, 0xa6, 0xad, 0x7, 0x20, 0x2, 0x2, 0xa7, 0xad, 0x7, 0x1d, 
    0x2, 0x2, 0xa8, 0xad, 0x7, 0x29, 0x2, 0x2, 0xa9, 0xad, 0x7, 0x2e, 0x2, 
    0x2, 0xaa, 0xad, 0x7, 0x24, 0x2, 0x2, 0xab, 0xad, 0x7, 0x25, 0x2, 0x2, 
    0xac, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xb0, 0x7, 0x41, 0x2, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 
    0x5, 0x18, 0xd, 0x2, 0xb2, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x8, 
    0xd, 0x1, 0x2, 0xb4, 0xb5, 0x7, 0x60, 0x2, 0x2, 0xb5, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb7, 0xc, 0x4, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x31, 0x2, 
    0x2, 0xb8, 0xb9, 0x5, 0x1a, 0xe, 0x2, 0xb9, 0xba, 0x7, 0x32, 0x2, 0x2, 
    0xba, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0xc, 0x3, 0x2, 0x2, 0xbc, 
    0xbe, 0x7, 0x31, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0x46, 0x24, 0x2, 0xbe, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc2, 0x7, 0x32, 0x2, 0x2, 0xc1, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xc1, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 
    0xc4, 0x19, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xcc, 0x5, 0x1c, 0xf, 0x2, 0xc7, 0xc8, 0x5, 0x1c, 0xf, 0x2, 0xc8, 0xc9, 
    0x7, 0x4b, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x5a, 0x2, 0x2, 0xca, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0xcb, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x8, 0xf, 0x1, 
    0x2, 0xce, 0xcf, 0x5, 0x1e, 0x10, 0x2, 0xcf, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xd0, 0xd1, 0xc, 0x3, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x4b, 0x2, 0x2, 0xd2, 
    0xd4, 0x5, 0x1e, 0x10, 0x2, 0xd3, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 
    0x2, 0x2, 0xd8, 0xd9, 0x5, 0xc, 0x7, 0x2, 0xd9, 0xda, 0x5, 0x16, 0xc, 
    0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x5, 0xc, 0x7, 0x2, 
    0xdc, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xde, 0xea, 0x7, 0x60, 0x2, 0x2, 0xdf, 0xea, 
    0x7, 0xc, 0x2, 0x2, 0xe0, 0xe2, 0x7, 0xe, 0x2, 0x2, 0xe1, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0xe5, 0xe6, 0x7, 0x31, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x44, 0x23, 0x2, 
    0xe7, 0xe8, 0x7, 0x32, 0x2, 0x2, 0xe8, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xde, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe1, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xea, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0xeb, 0xec, 0x8, 0x12, 0x1, 0x2, 0xec, 0xed, 0x5, 0x20, 
    0x11, 0x2, 0xed, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0xc, 0x5, 0x2, 
    0x2, 0xef, 0xf1, 0x7, 0x31, 0x2, 0x2, 0xf0, 0xf2, 0x5, 0x24, 0x13, 0x2, 
    0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf9, 0x7, 0x32, 0x2, 0x2, 0xf4, 0xf5, 
    0xc, 0x4, 0x2, 0x2, 0xf5, 0xf9, 0x7, 0x3e, 0x2, 0x2, 0xf6, 0xf7, 0xc, 
    0x3, 0x2, 0x2, 0xf7, 0xf9, 0x7, 0x40, 0x2, 0x2, 0xf8, 0xee, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 
    0xfa, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0x23, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0xfa, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x8, 0x13, 0x1, 0x2, 0xfe, 0xff, 
    0x5, 0x40, 0x21, 0x2, 0xff, 0x105, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 
    0xc, 0x3, 0x2, 0x2, 0x101, 0x102, 0x7, 0x4b, 0x2, 0x2, 0x102, 0x104, 
    0x5, 0x40, 0x21, 0x2, 0x103, 0x100, 0x3, 0x2, 0x2, 0x2, 0x104, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x105, 0x103, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x25, 0x3, 0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x112, 0x5, 0x22, 0x12, 0x2, 0x109, 0x10a, 0x7, 
    0x3e, 0x2, 0x2, 0x10a, 0x112, 0x5, 0x26, 0x14, 0x2, 0x10b, 0x10c, 0x7, 
    0x40, 0x2, 0x2, 0x10c, 0x112, 0x5, 0x26, 0x14, 0x2, 0x10d, 0x10e, 0x5, 
    0x28, 0x15, 0x2, 0x10e, 0x10f, 0x5, 0x26, 0x14, 0x2, 0x10f, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0x112, 0x7, 0xd, 0x2, 0x2, 0x111, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x111, 0x109, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x111, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x111, 0x110, 0x3, 
    0x2, 0x2, 0x2, 0x112, 0x27, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x9, 0x2, 
    0x2, 0x2, 0x114, 0x29, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x8, 0x16, 
    0x1, 0x2, 0x116, 0x117, 0x5, 0x26, 0x14, 0x2, 0x117, 0x123, 0x3, 0x2, 
    0x2, 0x2, 0x118, 0x119, 0xc, 0x5, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x41, 
    0x2, 0x2, 0x11a, 0x122, 0x5, 0x26, 0x14, 0x2, 0x11b, 0x11c, 0xc, 0x4, 
    0x2, 0x2, 0x11c, 0x11d, 0x7, 0x42, 0x2, 0x2, 0x11d, 0x122, 0x5, 0x26, 
    0x14, 0x2, 0x11e, 0x11f, 0xc, 0x3, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x43, 
    0x2, 0x2, 0x120, 0x122, 0x5, 0x26, 0x14, 0x2, 0x121, 0x118, 0x3, 0x2, 
    0x2, 0x2, 0x121, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11e, 0x3, 0x2, 
    0x2, 0x2, 0x122, 0x125, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x8, 0x17, 0x1, 
    0x2, 0x127, 0x128, 0x5, 0x2a, 0x16, 0x2, 0x128, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x129, 0x12a, 0xc, 0x4, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x3d, 0x2, 
    0x2, 0x12b, 0x130, 0x5, 0x2a, 0x16, 0x2, 0x12c, 0x12d, 0xc, 0x3, 0x2, 
    0x2, 0x12d, 0x12e, 0x7, 0x3f, 0x2, 0x2, 0x12e, 0x130, 0x5, 0x2a, 0x16, 
    0x2, 0x12f, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12c, 0x3, 0x2, 0x2, 
    0x2, 0x130, 0x133, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 
    0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x8, 0x18, 0x1, 0x2, 
    0x135, 0x136, 0x5, 0x2c, 0x17, 0x2, 0x136, 0x13f, 0x3, 0x2, 0x2, 0x2, 
    0x137, 0x138, 0xc, 0x4, 0x2, 0x2, 0x138, 0x139, 0x7, 0x3b, 0x2, 0x2, 
    0x139, 0x13e, 0x5, 0x2c, 0x17, 0x2, 0x13a, 0x13b, 0xc, 0x3, 0x2, 0x2, 
    0x13b, 0x13c, 0x7, 0x3c, 0x2, 0x2, 0x13c, 0x13e, 0x5, 0x2c, 0x17, 0x2, 
    0x13d, 0x137, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13a, 0x3, 0x2, 0x2, 0x2, 
    0x13e, 0x141, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 
    0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x141, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x8, 0x19, 0x1, 0x2, 0x143, 
    0x144, 0x5, 0x2e, 0x18, 0x2, 0x144, 0x153, 0x3, 0x2, 0x2, 0x2, 0x145, 
    0x146, 0xc, 0x6, 0x2, 0x2, 0x146, 0x147, 0x7, 0x37, 0x2, 0x2, 0x147, 
    0x152, 0x5, 0x2e, 0x18, 0x2, 0x148, 0x149, 0xc, 0x5, 0x2, 0x2, 0x149, 
    0x14a, 0x7, 0x39, 0x2, 0x2, 0x14a, 0x152, 0x5, 0x2e, 0x18, 0x2, 0x14b, 
    0x14c, 0xc, 0x4, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0x38, 0x2, 0x2, 0x14d, 
    0x152, 0x5, 0x2e, 0x18, 0x2, 0x14e, 0x14f, 0xc, 0x3, 0x2, 0x2, 0x14f, 
    0x150, 0x7, 0x3a, 0x2, 0x2, 0x150, 0x152, 0x5, 0x2e, 0x18, 0x2, 0x151, 
    0x145, 0x3, 0x2, 0x2, 0x2, 0x151, 0x148, 0x3, 0x2, 0x2, 0x2, 0x151, 
    0x14b, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x152, 
    0x155, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 
    0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x31, 0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 
    0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x8, 0x1a, 0x1, 0x2, 0x157, 0x158, 
    0x5, 0x30, 0x19, 0x2, 0x158, 0x167, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 
    0xc, 0x6, 0x2, 0x2, 0x15a, 0x15b, 0x7, 0x4, 0x2, 0x2, 0x15b, 0x166, 
    0x5, 0x30, 0x19, 0x2, 0x15c, 0x15d, 0xc, 0x5, 0x2, 0x2, 0x15d, 0x15e, 
    0x7, 0x5, 0x2, 0x2, 0x15e, 0x166, 0x5, 0x30, 0x19, 0x2, 0x15f, 0x160, 
    0xc, 0x4, 0x2, 0x2, 0x160, 0x161, 0x7, 0x6, 0x2, 0x2, 0x161, 0x166, 
    0x5, 0x30, 0x19, 0x2, 0x162, 0x163, 0xc, 0x3, 0x2, 0x2, 0x163, 0x164, 
    0x7, 0x7, 0x2, 0x2, 0x164, 0x166, 0x5, 0x30, 0x19, 0x2, 0x165, 0x159, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x165, 0x15f, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x162, 0x3, 0x2, 0x2, 0x2, 0x166, 0x169, 
    0x3, 0x2, 0x2, 0x2, 0x167, 0x165, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x33, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 
    0x2, 0x2, 0x2, 0x16a, 0x16b, 0x8, 0x1b, 0x1, 0x2, 0x16b, 0x16c, 0x5, 
    0x32, 0x1a, 0x2, 0x16c, 0x172, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0xc, 
    0x3, 0x2, 0x2, 0x16e, 0x16f, 0x7, 0x44, 0x2, 0x2, 0x16f, 0x171, 0x5, 
    0x32, 0x1a, 0x2, 0x170, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x171, 0x174, 0x3, 
    0x2, 0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x3, 
    0x2, 0x2, 0x2, 0x173, 0x35, 0x3, 0x2, 0x2, 0x2, 0x174, 0x172, 0x3, 0x2, 
    0x2, 0x2, 0x175, 0x176, 0x8, 0x1c, 0x1, 0x2, 0x176, 0x177, 0x5, 0x34, 
    0x1b, 0x2, 0x177, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0xc, 0x3, 
    0x2, 0x2, 0x179, 0x17a, 0x7, 0x47, 0x2, 0x2, 0x17a, 0x17c, 0x5, 0x34, 
    0x1b, 0x2, 0x17b, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17f, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x3, 0x2, 
    0x2, 0x2, 0x17e, 0x37, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 
    0x2, 0x180, 0x181, 0x8, 0x1d, 0x1, 0x2, 0x181, 0x182, 0x5, 0x36, 0x1c, 
    0x2, 0x182, 0x188, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0xc, 0x3, 0x2, 
    0x2, 0x184, 0x185, 0x7, 0x45, 0x2, 0x2, 0x185, 0x187, 0x5, 0x36, 0x1c, 
    0x2, 0x186, 0x183, 0x3, 0x2, 0x2, 0x2, 0x187, 0x18a, 0x3, 0x2, 0x2, 
    0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 
    0x2, 0x189, 0x39, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x18c, 0x8, 0x1e, 0x1, 0x2, 0x18c, 0x18d, 0x5, 0x38, 0x1d, 0x2, 
    0x18d, 0x196, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0xc, 0x4, 0x2, 0x2, 
    0x18f, 0x190, 0x7, 0x8, 0x2, 0x2, 0x190, 0x195, 0x5, 0x38, 0x1d, 0x2, 
    0x191, 0x192, 0xc, 0x3, 0x2, 0x2, 0x192, 0x193, 0x7, 0x9, 0x2, 0x2, 
    0x193, 0x195, 0x5, 0x38, 0x1d, 0x2, 0x194, 0x18e, 0x3, 0x2, 0x2, 0x2, 
    0x194, 0x191, 0x3, 0x2, 0x2, 0x2, 0x195, 0x198, 0x3, 0x2, 0x2, 0x2, 
    0x196, 0x194, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x3, 0x2, 0x2, 0x2, 
    0x197, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x198, 0x196, 0x3, 0x2, 0x2, 0x2, 0x199, 
    0x19a, 0x8, 0x1f, 0x1, 0x2, 0x19a, 0x19b, 0x5, 0x3a, 0x1e, 0x2, 0x19b, 
    0x1a4, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19d, 0xc, 0x4, 0x2, 0x2, 0x19d, 
    0x19e, 0x7, 0xa, 0x2, 0x2, 0x19e, 0x1a3, 0x5, 0x3a, 0x1e, 0x2, 0x19f, 
    0x1a0, 0xc, 0x3, 0x2, 0x2, 0x1a0, 0x1a1, 0x7, 0xb, 0x2, 0x2, 0x1a1, 
    0x1a3, 0x5, 0x3a, 0x1e, 0x2, 0x1a2, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x1a2, 
    0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a4, 
    0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a5, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1ad, 
    0x5, 0x3c, 0x1f, 0x2, 0x1a8, 0x1a9, 0x7, 0x48, 0x2, 0x2, 0x1a9, 0x1aa, 
    0x5, 0x44, 0x23, 0x2, 0x1aa, 0x1ab, 0x7, 0x49, 0x2, 0x2, 0x1ab, 0x1ac, 
    0x5, 0x3e, 0x20, 0x2, 0x1ac, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1a8, 
    0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x1af, 0x1b6, 0x5, 0x3e, 0x20, 0x2, 0x1b0, 0x1b1, 0x5, 
    0x26, 0x14, 0x2, 0x1b1, 0x1b2, 0x5, 0x42, 0x22, 0x2, 0x1b2, 0x1b3, 0x5, 
    0x40, 0x21, 0x2, 0x1b3, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b6, 0x7, 
    0xd, 0x2, 0x2, 0x1b5, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b0, 0x3, 
    0x2, 0x2, 0x2, 0x1b5, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x1b7, 0x1b8, 0x9, 0x3, 0x2, 0x2, 0x1b8, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x1b9, 0x1ba, 0x8, 0x23, 0x1, 0x2, 0x1ba, 0x1bb, 0x5, 0x40, 0x21, 
    0x2, 0x1bb, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0xc, 0x3, 0x2, 
    0x2, 0x1bd, 0x1be, 0x7, 0x4b, 0x2, 0x2, 0x1be, 0x1c0, 0x5, 0x40, 0x21, 
    0x2, 0x1bf, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c3, 0x3, 0x2, 0x2, 
    0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 
    0x2, 0x1c2, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c1, 0x3, 0x2, 0x2, 0x2, 
    0x1c4, 0x1c5, 0x8, 0x24, 0x1, 0x2, 0x1c5, 0x1c6, 0x7, 0x60, 0x2, 0x2, 
    0x1c6, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0xc, 0x3, 0x2, 0x2, 
    0x1c8, 0x1c9, 0x7, 0x4b, 0x2, 0x2, 0x1c9, 0x1cb, 0x7, 0x60, 0x2, 0x2, 
    0x1ca, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1ce, 0x3, 0x2, 0x2, 0x2, 
    0x1cc, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x3, 0x2, 0x2, 0x2, 
    0x1cd, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cf, 
    0x1d4, 0x5, 0x4a, 0x26, 0x2, 0x1d0, 0x1d4, 0x5, 0x5a, 0x2e, 0x2, 0x1d1, 
    0x1d4, 0x5, 0x5c, 0x2f, 0x2, 0x1d2, 0x1d4, 0x5, 0x50, 0x29, 0x2, 0x1d3, 
    0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
    0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d7, 0x7, 0x35, 0x2, 0x2, 0x1d6, 
    0x1d8, 0x5, 0x4c, 0x27, 0x2, 0x1d7, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
    0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
    0x1da, 0x7, 0x36, 0x2, 0x2, 0x1da, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1db, 
    0x1dc, 0x8, 0x27, 0x1, 0x2, 0x1dc, 0x1dd, 0x5, 0x4e, 0x28, 0x2, 0x1dd, 
    0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 0xc, 0x3, 0x2, 0x2, 0x1df, 
    0x1e1, 0x5, 0x4e, 0x28, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e1, 
    0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e2, 
    0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e8, 0x5, 0x48, 0x25, 0x2, 0x1e6, 0x1e8, 
    0x5, 0xa, 0x6, 0x2, 0x1e7, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e6, 
    0x3, 0x2, 0x2, 0x2, 0x1e8, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ea, 0x7, 
    0x21, 0x2, 0x2, 0x1ea, 0x1eb, 0x7, 0x31, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 
    0x52, 0x2a, 0x2, 0x1ec, 0x1ed, 0x7, 0x32, 0x2, 0x2, 0x1ed, 0x1ee, 0x5, 
    0x48, 0x25, 0x2, 0x1ee, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 0x5, 
    0x54, 0x2b, 0x2, 0x1f0, 0x1f2, 0x7, 0x4a, 0x2, 0x2, 0x1f1, 0x1f3, 0x5, 
    0x56, 0x2c, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x3, 
    0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f6, 0x7, 
    0x4a, 0x2, 0x2, 0x1f5, 0x1f7, 0x5, 0x56, 0x2c, 0x2, 0x1f6, 0x1f5, 0x3, 
    0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x204, 0x3, 
    0x2, 0x2, 0x2, 0x1f8, 0x1fa, 0x5, 0x44, 0x23, 0x2, 0x1f9, 0x1f8, 0x3, 
    0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x3, 
    0x2, 0x2, 0x2, 0x1fb, 0x1fd, 0x7, 0x4a, 0x2, 0x2, 0x1fc, 0x1fe, 0x5, 
    0x56, 0x2c, 0x2, 0x1fd, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x3, 
    0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x201, 0x7, 
    0x4a, 0x2, 0x2, 0x200, 0x202, 0x5, 0x56, 0x2c, 0x2, 0x201, 0x200, 0x3, 
    0x2, 0x2, 0x2, 0x201, 0x202, 0x3, 0x2, 0x2, 0x2, 0x202, 0x204, 0x3, 
    0x2, 0x2, 0x2, 0x203, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x203, 0x1f9, 0x3, 
    0x2, 0x2, 0x2, 0x204, 0x53, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x5, 0xc, 
    0x7, 0x2, 0x206, 0x207, 0x5, 0x10, 0x9, 0x2, 0x207, 0x20a, 0x3, 0x2, 
    0x2, 0x2, 0x208, 0x20a, 0x5, 0xc, 0x7, 0x2, 0x209, 0x205, 0x3, 0x2, 
    0x2, 0x2, 0x209, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x20b, 0x20c, 0x8, 0x2c, 0x1, 0x2, 0x20c, 0x20d, 0x5, 0x40, 0x21, 
    0x2, 0x20d, 0x213, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20f, 0xc, 0x3, 0x2, 
    0x2, 0x20f, 0x210, 0x7, 0x4b, 0x2, 0x2, 0x210, 0x212, 0x5, 0x40, 0x21, 
    0x2, 0x211, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x212, 0x215, 0x3, 0x2, 0x2, 
    0x2, 0x213, 0x211, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x3, 0x2, 0x2, 
    0x2, 0x214, 0x57, 0x3, 0x2, 0x2, 0x2, 0x215, 0x213, 0x3, 0x2, 0x2, 0x2, 
    0x216, 0x217, 0x5, 0x40, 0x21, 0x2, 0x217, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x218, 0x21a, 0x5, 0x44, 0x23, 0x2, 0x219, 0x218, 0x3, 0x2, 0x2, 0x2, 
    0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21b, 0x3, 0x2, 0x2, 0x2, 
    0x21b, 0x21c, 0x7, 0x4a, 0x2, 0x2, 0x21c, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x21d, 0x21e, 0x7, 0x22, 0x2, 0x2, 0x21e, 0x21f, 0x7, 0x31, 0x2, 0x2, 
    0x21f, 0x220, 0x5, 0x44, 0x23, 0x2, 0x220, 0x221, 0x7, 0x32, 0x2, 0x2, 
    0x221, 0x224, 0x5, 0x48, 0x25, 0x2, 0x222, 0x223, 0x7, 0x1e, 0x2, 0x2, 
    0x223, 0x225, 0x5, 0x48, 0x25, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x224, 0x225, 0x3, 0x2, 0x2, 0x2, 0x225, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x5f, 0x6a, 0x70, 0x73, 0x7f, 0x84, 0x8e, 0x96, 0x9e, 0xac, 0xaf, 0xbe, 
    0xc1, 0xc3, 0xcb, 0xd5, 0xdc, 0xe3, 0xe9, 0xf1, 0xf8, 0xfa, 0x105, 0x111, 
    0x121, 0x123, 0x12f, 0x131, 0x13d, 0x13f, 0x151, 0x153, 0x165, 0x167, 
    0x172, 0x17d, 0x188, 0x194, 0x196, 0x1a2, 0x1a4, 0x1ad, 0x1b5, 0x1c1, 
    0x1cc, 0x1d3, 0x1d7, 0x1e2, 0x1e7, 0x1f2, 0x1f6, 0x1f9, 0x1fd, 0x201, 
    0x203, 0x209, 0x213, 0x219, 0x224, 
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
