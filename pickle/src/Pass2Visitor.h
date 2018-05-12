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

	ostream & j_file;

    const bool debug_flag;

    void print_debug_context(antlr4::ParserRuleContext * context, const std::string & msg) const;

    string opcode_to_instruction(const string opcode, const bool is_fpoint);

    string determine_type(TypeSpec * lhs);

public:

    /// Constructor
	Pass2Visitor(const string fname, ostream& j_file, const bool debug=false);

    /// Destructor
    virtual ~Pass2Visitor();

    // /// @ { Compilation Unit
    // antlrcpp::Any visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context) override;
    // antlrcpp::Any visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context) override;
    // antlrcpp::Any visitFunctionDefinition(Pcl2Parser::FunctionDefinitionContext *context) override;
    // /// @ }

};

#endif /* PASS2VISITOR_H_ */
