
#include "wci/intermediate/TypeSpec.h"
using namespace wci::intermediate;


// Generated from C:/Users/JP/Desktop/compiler/pickle/grammars/Pcl2.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "Pcl2Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by Pcl2Parser.
 */
class  Pcl2Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by Pcl2Parser.
   */
    virtual antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(Pcl2Parser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitDeclarator(Pcl2Parser::DeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitParameterTypeList(Pcl2Parser::ParameterTypeListContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(Pcl2Parser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(Pcl2Parser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitStatement(Pcl2Parser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(Pcl2Parser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockItemList(Pcl2Parser::BlockItemListContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(Pcl2Parser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context) = 0;


};

