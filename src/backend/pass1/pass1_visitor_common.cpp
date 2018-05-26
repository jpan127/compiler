#include "Pass1Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass1Visitor::visitCompilationUnit(CmmParser::CompilationUnitContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        // Open output stream file
        try
        {
            j_file.open(program_name + ".j");
            if (j_file.fail())
            {
                throw FileOpenError("Failed to open file :" + program_name + ".j");
            }
        }
        CATCH_CUSTOM_EXCEPTION_PRINT_AND_EXIT(FileOpenError);

        // Emit the program header
        j_file << ".class public " << program_name             << endl;
        j_file << ".super java/lang/Object"                    << endl;
        j_file                                                 << endl;
        j_file << ".field private static _runTimer LRunTimer;" << endl;

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
