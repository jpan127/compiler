#ifndef PASS1VISITOR_H_
#define PASS1VISITOR_H_

#include <iostream>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "Pcl2BaseVisitor.h"
#include "antlr4-runtime.h"
#include "Pcl2Visitor.h"
#include "PassVisitor.hpp"

using namespace wci;
using namespace wci::intermediate;



class Pass1Visitor : public PassVisitor, public Pcl2BaseVisitor
{
private:

    /// Symbol Table Stack
    SymTabStack *symtab_stack;

    /// Program ID
    SymTabEntry *program_id;

    /// Output file    
    ofstream j_file;

    /// Flag to print debug messages or not
    const bool debug_flag;

    /// Name of current program
    const string program_name;

public:

    /// Constructor
    explicit Pass1Visitor(const string fname, const bool debug=false);
    
    /// Destructor
    ~Pass1Visitor();

    /// Returns the output file
    ofstream & get_assembly_file();

    antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context) override;
    antlrcpp::Any visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context) override;

    antlrcpp::Any visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context) override;
    antlrcpp::Any visitDeclaration(Pcl2Parser::DeclarationContext *context) override;

    antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context) override;
    antlrcpp::Any visitCompoundStatement(Pcl2Parser::CompoundStatementContext *context) override;
    antlrcpp::Any visitSelectionStatement(Pcl2Parser::SelectionStatementContext *context) override;
    antlrcpp::Any visitIterationStatement(Pcl2Parser::IterationStatementContext *context) override;
    antlrcpp::Any visitJumpStatement(Pcl2Parser::JumpStatementContext *context) override;

    antlrcpp::Any visitPrimExpr(Pcl2Parser::PrimExprContext *context) override;
    antlrcpp::Any visitMulDivExpr(Pcl2Parser::MulDivExprContext *context) override;
    antlrcpp::Any visitAddminExpr(Pcl2Parser::AddminExprContext *context) override;
    antlrcpp::Any visitBasicConditionalExpr(Pcl2Parser::BasicConditionalExprContext * context) override;
    antlrcpp::Any visitConnectedConditionalExpr(Pcl2Parser::ConnectedConditionalExprContext * context) override;

    antlrcpp::Any visitAssignmentExpression(Pcl2Parser::AssignmentExpressionContext *context) override;

};

#endif /* PASS1VISITOR_H_ */
