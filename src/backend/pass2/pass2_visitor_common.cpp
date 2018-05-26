#include "Pass2Visitor.hpp"



namespace backend
{

    antlrcpp::Any Pass2Visitor::visitCompilationUnit(CmmParser::CompilationUnitContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitTranslationUnit(CmmParser::TranslationUnitContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitTypeSpecifier(CmmParser::TypeSpecifierContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        return visitChildren(context);
    }

} /// backend
