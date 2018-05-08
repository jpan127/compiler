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
    vector <SymTabEntry *> variable_id_list;
    ofstream j_file;
    const bool debug_flag;
    TypeSpec * current_type;
    string current_type_indicator;

    /// Prints the current visit context information if [debug_flag] is true
    void print_debug_context(const std::string & msg) const;

public:

    /// Constructor
    Pass1Visitor(const bool debug=false);
    
    /// Destructor
    virtual ~Pass1Visitor();

    /// Returns the output file
    ostream& get_assembly_file();

    /// @ { Overriding all visit functions
#if 0
    antlrcpp::Any visitAddSubExpr(Pcl2Parser::AddSubExprContext *ctx) override;
    antlrcpp::Any visitDecl(Pcl2Parser::DeclContext *ctx) override;
    antlrcpp::Any visitDeclarations(Pcl2Parser::DeclarationsContext *ctx) override;
    antlrcpp::Any visitFloatConst(Pcl2Parser::FloatConstContext *ctx) override;
    antlrcpp::Any visitHeader(Pcl2Parser::HeaderContext *ctx) override;
    antlrcpp::Any visitIntegerConst(Pcl2Parser::IntegerConstContext *ctx) override;
    antlrcpp::Any visitMulDivExpr(Pcl2Parser::MulDivExprContext *ctx) override;
    antlrcpp::Any visitParenExpr(Pcl2Parser::ParenExprContext *ctx) override;
    antlrcpp::Any visitProgram(Pcl2Parser::ProgramContext *ctx) override;
    antlrcpp::Any visitSignedNumber(Pcl2Parser::SignedNumberContext *ctx) override;
    antlrcpp::Any visitSignedNumberExpr(Pcl2Parser::SignedNumberExprContext *ctx) override;
    antlrcpp::Any visitTypeId(Pcl2Parser::TypeIdContext *ctx) override;
    antlrcpp::Any visitUnsignedNumberExpr(Pcl2Parser::UnsignedNumberExprContext *ctx) override;
    antlrcpp::Any visitVarId(Pcl2Parser::VarIdContext *ctx) override;
    antlrcpp::Any visitVariableExpr(Pcl2Parser::VariableExprContext *ctx) override;
    antlrcpp::Any visitVarList(Pcl2Parser::VarListContext *ctx) override;
#else
    antlrcpp::Any visitDeclaration(Pcl2Parser::DeclarationContext *context) override;
    antlrcpp::Any visitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *context) override;
    antlrcpp::Any visitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *context) override;
    antlrcpp::Any visitDeclarator(Pcl2Parser::DeclaratorContext *context) override;
    antlrcpp::Any visitTypeSpecifier(Pcl2Parser::TypeSpecifierContext *context) override;
    antlrcpp::Any visitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *context) override;
    antlrcpp::Any visitParameterTypeList(Pcl2Parser::ParameterTypeListContext *context) override;
    antlrcpp::Any visitParameterList(Pcl2Parser::ParameterListContext *context) override;
    antlrcpp::Any visitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *context) override;
    antlrcpp::Any visitIdentifierList(Pcl2Parser::IdentifierListContext *context) override;
    antlrcpp::Any visitStatement(Pcl2Parser::StatementContext *context) override;
    antlrcpp::Any visitCompoundStatement(Pcl2Parser::CompoundStatementContext *context) override;
    antlrcpp::Any visitBlockItemList(Pcl2Parser::BlockItemListContext *context) override;
    antlrcpp::Any visitBlockItem(Pcl2Parser::BlockItemContext *context) override;
    antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context) override;
    antlrcpp::Any visitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *context) override;
    antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context) override;
#endif
    /// @ }
};

#endif /* PASS1VISITOR_H_ */
