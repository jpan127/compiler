#include "Pass1Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass1Visitor::visitCompilationUnit(CmmParser::CompilationUnitContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Emit the program header
        j_emitter.emit_main_class(program_name);
        j_emitter.emit_class_variable("_runTimer", "LRunTimer;");
        j_emitter.emit_box_comment("Global Variables");

        auto value = visitChildren(context);

    #if 0
        // Print the cross-reference table
        CrossReferencer cross_referencer;
        cross_referencer.print(symtab_stack);
    #endif

        return value;
    }

    antlrcpp::Any Pass1Visitor::visitTranslationUnit(CmmParser::TranslationUnitContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass1Visitor::visitTypeSpecifier(CmmParser::TypeSpecifierContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

} /// backend
