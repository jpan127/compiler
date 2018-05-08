#ifndef PASS2VISITOR_H_
#define PASS2VISITOR_H_

#include <iostream>
#include <string>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "Pcl2BaseVisitor.h"
#include "antlr4-runtime.h"
#include "Pcl2Visitor.h"

using namespace wci;
using namespace wci::intermediate;

class Pass2Visitor : public Pcl2BaseVisitor
{
private:
	string program_name;
	ostream& j_file;
    const bool debug_flag;

    void print_debug_context(const std::string & msg) const;

public:
	Pass2Visitor(ostream& j_file, const bool debug=false);
    virtual ~Pass2Visitor();

    /// @ { Overriding all visit functions
#if 0
    antlrcpp::Any visitProgram(Pcl2Parser::ProgramContext *ctx) override;
    antlrcpp::Any visitHeader(Pcl2Parser::HeaderContext *ctx) override;
    antlrcpp::Any visitMainBlock(Pcl2Parser::MainBlockContext *ctx) override;
    antlrcpp::Any visitStmt(Pcl2Parser::StmtContext *ctx) override;
    antlrcpp::Any visitAssignmentStmt(Pcl2Parser::AssignmentStmtContext *ctx) override;
    antlrcpp::Any visitAddSubExpr(Pcl2Parser::AddSubExprContext *ctx) override;
    antlrcpp::Any visitMulDivExpr(Pcl2Parser::MulDivExprContext *ctx) override;
    antlrcpp::Any visitVariableExpr(Pcl2Parser::VariableExprContext *ctx) override;
    antlrcpp::Any visitSignedNumber(Pcl2Parser::SignedNumberContext *ctx) override;
    antlrcpp::Any visitIntegerConst(Pcl2Parser::IntegerConstContext *ctx) override;
    antlrcpp::Any visitFloatConst(Pcl2Parser::FloatConstContext *ctx) override;
#else
    antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context) override;
    antlrcpp::Any visitStatement(Pcl2Parser::StatementContext *context) override;
    antlrcpp::Any visitCompoundStatement(Pcl2Parser::CompoundStatementContext *context) override;
#endif
    /// @ }
};

#endif /* PASS2VISITOR_H_ */
