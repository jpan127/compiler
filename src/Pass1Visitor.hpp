#ifndef PASS1VISITOR_H_
#define PASS1VISITOR_H_

#include <iostream>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"

#include "CmmBaseVisitor.h"
#include "antlr4-runtime.h"
#include "CmmVisitor.h"
#include "PassVisitor.hpp"

#include "SymbolTableStack.hpp"

using namespace wci;
using namespace wci::intermediate;



class Pass1Visitor : public PassVisitor, public CmmBaseVisitor
{

public:

    /// Constructor
    explicit Pass1Visitor(const string fname, const bool debug=false);

    /// Destructor
    ~Pass1Visitor() { }

    /// Returns the output file
    ofstream & get_assembly_file();

    antlrcpp::Any visitCompilationUnit(CmmParser::CompilationUnitContext *context) override;
    antlrcpp::Any visitTranslationUnit(CmmParser::TranslationUnitContext *context) override;

    antlrcpp::Any visitTypeSpecifier(CmmParser::TypeSpecifierContext *context) override;
    antlrcpp::Any visitDeclaration(CmmParser::DeclarationContext *context) override;
    antlrcpp::Any visitFunctionDeclaration(CmmParser::FunctionDeclarationContext *ctx) override;

    antlrcpp::Any visitFunctionDefinition(CmmParser::FunctionDefinitionContext *context) override;
    antlrcpp::Any visitCompoundStatement(CmmParser::CompoundStatementContext *context) override;

    antlrcpp::Any visitIfElseStatement(CmmParser::IfElseStatementContext *context) override;
    antlrcpp::Any visitIfStatement(CmmParser::IfStatementContext *context) override;
    antlrcpp::Any visitElseIfStatement(CmmParser::ElseIfStatementContext *context) override;
    antlrcpp::Any visitElseStatement(CmmParser::ElseStatementContext *context) override;

    antlrcpp::Any visitIterationStatement(CmmParser::IterationStatementContext *context) override;
    antlrcpp::Any visitUnaryIncrementStatement(CmmParser::UnaryIncrementStatementContext *context) override;
    antlrcpp::Any visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context) override;
    antlrcpp::Any visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context) override;
    antlrcpp::Any visitAssignmentStatement(CmmParser::AssignmentStatementContext * context) override;

    antlrcpp::Any visitPrimExpr(CmmParser::PrimExprContext *context) override;
    antlrcpp::Any visitMulDivExpr(CmmParser::MulDivExprContext *context) override;
    antlrcpp::Any visitAddminExpr(CmmParser::AddminExprContext *context) override;
    antlrcpp::Any visitBitExpr(CmmParser::BitExprContext *context) override;
    antlrcpp::Any visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext * context) override;
    antlrcpp::Any visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext * context) override;
    antlrcpp::Any visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context) override;
    antlrcpp::Any visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context) override;

    antlrcpp::Any visitAssignmentExpression(CmmParser::AssignmentExpressionContext *context) override;

private:

    /// Name of current program
    const string program_name;

    /// Symbol Table Stack
    ::intermediate::SymbolTableStack symbol_table_stack;

    /// Program ID
    SymTabEntry *program_id;

    /// Output file
    ofstream j_file;

    /// Flag to print debug messages or not
    const bool debug_flag;

    /**
     *  Looks up the symbol type of context->Identifier()->getText()
     *  Stores [context->type] and [context->type_letter]
     *  @param context : The context object to look up and modify
     *  @throws        : InvalidType
     */
    void lookup_symbol_type(string const & variable, backend::TypeSpecifier & type, char & type_letter);

};

#endif /* PASS1VISITOR_H_ */
