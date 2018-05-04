#ifndef PASS1VISITOR_H_
#define PASS1VISITOR_H_

#include <iostream>

#include "wci/intermediate/SymTabStack.h"
#include "wci/intermediate/SymTabEntry.h"
#include "wci/intermediate/TypeSpec.h"

#include "Pcl2BaseVisitor.h"
#include "antlr4-runtime.h"
#include "Pcl2Visitor.h"

using namespace wci;
using namespace wci::intermediate;

class Pass1Visitor : public Pcl2BaseVisitor
{
private:
    SymTabStack *symtab_stack;
    SymTabEntry *program_id;
    vector<SymTabEntry *> variable_id_list;
    ofstream j_file;

public:
    Pass1Visitor();
    virtual ~Pass1Visitor();

    ostream& get_assembly_file();

    antlrcpp::Any visitProgram(Pcl2Parser::ProgramContext *ctx) override;
    antlrcpp::Any visitHeader(Pcl2Parser::HeaderContext *ctx) override;
    antlrcpp::Any visitDeclarations(Pcl2Parser::DeclarationsContext *ctx) override;
    antlrcpp::Any visitDecl(Pcl2Parser::DeclContext *ctx) override;
    antlrcpp::Any visitVarList(Pcl2Parser::VarListContext *ctx) override;
    antlrcpp::Any visitVarId(Pcl2Parser::VarIdContext *ctx) override;
    antlrcpp::Any visitTypeId(Pcl2Parser::TypeIdContext *ctx) override;
    antlrcpp::Any visitAddSubExpr(Pcl2Parser::AddSubExprContext *ctx) override;
    antlrcpp::Any visitMulDivExpr(Pcl2Parser::MulDivExprContext *ctx) override;
    antlrcpp::Any visitVariableExpr(Pcl2Parser::VariableExprContext *ctx) override;
    antlrcpp::Any visitSignedNumberExpr(Pcl2Parser::SignedNumberExprContext *ctx) override;
    antlrcpp::Any visitSignedNumber(Pcl2Parser::SignedNumberContext *ctx) override;
    antlrcpp::Any visitUnsignedNumberExpr(Pcl2Parser::UnsignedNumberExprContext *ctx) override;
    antlrcpp::Any visitIntegerConst(Pcl2Parser::IntegerConstContext *ctx) override;
    antlrcpp::Any visitFloatConst(Pcl2Parser::FloatConstContext *ctx) override;
    antlrcpp::Any visitParenExpr(Pcl2Parser::ParenExprContext *ctx) override;
};

#endif /* PASS1VISITOR_H_ */
