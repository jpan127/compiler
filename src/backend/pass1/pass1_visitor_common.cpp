#include "Pass1Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass1Visitor::visitCompilationUnit(CmmParser::CompilationUnitContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Emit the program header
        j_file << ".class public " << program_name                              << endl;
        j_file << ".super java/lang/Object"                                     << endl;
        j_file                                                                  << endl;
        j_file << ".field private static _runTimer LRunTimer;"                  << endl;
        j_file << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;
        j_file << ";                     Global Variables                    ;" << endl;
        j_file << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;

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
