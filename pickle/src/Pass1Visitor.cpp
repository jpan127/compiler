#include <iostream>
#include <string>
#include <vector>

#include "Pass1Visitor.hpp"
#include "wci/intermediate/SymTabFactory.h"
#include "wci/intermediate/symtabimpl/Predefined.h"
#include "wci/util/CrossReferencer.h"

using namespace std;
using namespace wci;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::util;

/**
 *  Pass1Visitor << Pcl2BaseVisitor << Pcl2Visitor << AbstractParseTreeVisitor << ParseTreeVisitor
 *  Pass1Visitor:
 *      - Overrides all visit functions
 *  Pcl2BaseVisitor:
 *      - Virtual visit functions
 *  Pcl2Visitor:
 *      - Abstract visit functions
 *  AbstractParseTreeVisitor:
 *      - visitChildren()
 *      - visit()
 *      - visitTerminal()
 *      - visitErrorNode()
 *      - Some useless default functions that are never overridden
 *  ParseTreeVisitor:
 *      - Abstract visit functions
 */

void Pass1Visitor::print_debug_context(const std::string & msg) const
{
    if (debug_flag)
    {
        cout << msg << endl;
    }
}

Pass1Visitor::Pass1Visitor(const bool debug) : program_id(nullptr), j_file(nullptr), debug_flag(debug)
{
    // Create and initialize the symbol table stack.
    symtab_stack = SymTabFactory::create_symtab_stack();
    Predefined::initialize(symtab_stack);

    print_debug_context("=== Pass1Visitor(): symtab stack initialized.");
}

Pass1Visitor::~Pass1Visitor() 
{
    j_file.close();
}

ostream& Pass1Visitor::get_assembly_file()
{ 
    return j_file; 
}

#if 0
    antlrcpp::Any Pass1Visitor::visitProgram(Pcl2Parser::ProgramContext *ctx)
    {
        auto value = visitChildren(ctx);
        print_debug_context("=== visitProgram: Printing xref table.");

        // Print the cross-reference table.
        CrossReferencer cross_referencer;
        cross_referencer.print(symtab_stack);

        return value;
    }

    antlrcpp::Any Pass1Visitor::visitHeader(Pcl2Parser::HeaderContext *ctx)
    {
        print_debug_context("=== visitHeader: " + ctx->getText());

        const string program_name = ctx->IDENTIFIER()->toString();

        program_id = symtab_stack->enter_local(program_name);
        program_id->set_definition((Definition)DF_PROGRAM);
        program_id->set_attribute((SymTabKey) ROUTINE_SYMTAB, new EntryValue(symtab_stack->push()));
        
        symtab_stack->set_program_id(program_id);

        try
        {
            if (j_file && !j_file.is_open())
            {
                // Create the assembly output file.
                j_file.open(program_name + ".j");
                if (j_file.fail())
                {
                    throw "***** Cannot open assembly file";
                }
            }
        }
        catch (const char * exception)
        {
            cerr << exception << endl;
            exit(-1);
        }

        // Emit the program header.
        j_file << ".class public " << program_name                      << endl;
        j_file << ".super java/lang/Object"                             << endl;

        // Emit the RunTimer and PascalTextIn fields.
        j_file                                                          << endl;
        j_file << ".field private static _runTimer LRunTimer;"          << endl;
        j_file << ".field private static _standardIn LPascalTextIn;"    << endl;

        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitDeclarations(Pcl2Parser::DeclarationsContext *ctx)
    {
        print_debug_context("=== visitDeclarations: " + ctx->getText());

        // Emit the class constructor.
        j_file                                                          << endl;
        j_file << ".method public <init>()V"                            << endl;
        j_file                                                          << endl;
        j_file << "\taload_0"                                           << endl;
        j_file << "\tinvokenonvirtual    java/lang/Object/<init>()V"    << endl;
        j_file << "\treturn"                                            << endl;
        j_file                                                          << endl;
        j_file << ".limit locals 1"                                     << endl;
        j_file << ".limit stack 1"                                      << endl;
        j_file << ".end method"                                         << endl;

        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitDecl(Pcl2Parser::DeclContext *ctx)
    {
        print_debug_context("=== visitDecl: " + ctx->getText());

        j_file << "\n; " << ctx->getText() << "\n" << endl;
        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitVarList(Pcl2Parser::VarListContext *ctx)
    {
        print_debug_context("=== visitVarList: " + ctx->getText());

        variable_id_list.resize(0);
        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitVarId(Pcl2Parser::VarIdContext *ctx)
    {
        print_debug_context("=== visitVarId: " + ctx->getText());

        const string variable_name = ctx->IDENTIFIER()->toString();
        SymTabEntry * variable_id = symtab_stack->enter_local(variable_name);
        variable_id->set_definition((Definition) DF_VARIABLE);
        // variable_id_list.push_back(variable_id);

        variable_id->set_typespec(current_type);
        // Emit a field declaration.
        j_file << ".field private static "
               << variable_id->get_name() 
               << " " 
               << current_type_indicator 
               << endl;


        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitTypeId(Pcl2Parser::TypeIdContext *ctx)
    {
        print_debug_context("=== visitTypeId: " + ctx->getText());

        // TypeSpec * type = nullptr;
        // string type_indicator;

        const string type_name = ctx->IDENTIFIER()->toString();
        if (type_name == "integer")
        {
            current_type = Predefined::integer_type;
            current_type_indicator = "I";
        }
        else if (type_name == "real")
        {
            current_type = Predefined::real_type;
            current_type_indicator = "F";
        }
        else
        {
            current_type_indicator = "?";
        }

        cout << "Size of variable_id_list: " << variable_id_list.size() << endl;

        // for (SymTabEntry * id : variable_id_list)
        // {
        //     id->set_typespec(type);

        //     // Emit a field declaration.
        //     j_file << ".field private static "
        //            << id->get_name() 
        //            << " " 
        //            << type_indicator 
        //            << endl;
        // }

        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitAddSubExpr(Pcl2Parser::AddSubExprContext *ctx)
    {
        print_debug_context("=== visitAddSubExpr: " + ctx->getText());

        const TypeSpec * type1 = ctx->expr(0)->type;
        const TypeSpec * type2 = ctx->expr(1)->type;

        const bool integer_mode = (type1 == Predefined::integer_type) &&
                                  (type2 == Predefined::integer_type);
        const bool real_mode    = (type1 == Predefined::real_type) &&
                                  (type2 == Predefined::real_type);

        ctx->type = (integer_mode)             ? 
                    (Predefined::integer_type) : 
                    (real_mode ? Predefined::real_type : nullptr);

        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitMulDivExpr(Pcl2Parser::MulDivExprContext *ctx)
    {
        print_debug_context("=== visitMulDivExpr: " + ctx->getText());

        const TypeSpec * type1 = ctx->expr(0)->type;
        const TypeSpec * type2 = ctx->expr(1)->type;

        const bool integer_mode = (type1 == Predefined::integer_type) &&
                                  (type2 == Predefined::integer_type);
        const bool real_mode    = (type1 == Predefined::real_type) &&
                                  (type2 == Predefined::real_type);

        ctx->type = (integer_mode)             ? 
                    (Predefined::integer_type) : 
                    (real_mode ? Predefined::real_type : nullptr);

        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitVariableExpr(Pcl2Parser::VariableExprContext *ctx)
    {
        print_debug_context("=== visitVariableExpr: " + ctx->getText());

        const string variable_name = ctx->variable()->IDENTIFIER()->toString();
        const SymTabEntry * variable_id = symtab_stack->lookup(variable_name);

        ctx->type = variable_id->get_typespec();
        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitSignedNumberExpr(Pcl2Parser::SignedNumberExprContext *ctx)
    {
        print_debug_context("=== visitSignedNumberExpr: " + ctx->getText());

        ctx->type = ctx->signedNumber()->type;
        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitSignedNumber(Pcl2Parser::SignedNumberContext *ctx)
    {
        print_debug_context("=== visitSignedNumber: " + ctx->getText());

        ctx->type = ctx->number()->type;
        return visit(ctx->number());
    }

    antlrcpp::Any Pass1Visitor::visitUnsignedNumberExpr(Pcl2Parser::UnsignedNumberExprContext *ctx)
    {
        print_debug_context("=== visitUnsignedNumberExpr: " + ctx->getText());

        ctx->type = ctx->number()->type;
        return visit(ctx->number());
    }

    antlrcpp::Any Pass1Visitor::visitIntegerConst(Pcl2Parser::IntegerConstContext *ctx)
    {
        print_debug_context("=== visitIntegerConst: " + ctx->getText());

        ctx->type = Predefined::integer_type;
        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitFloatConst(Pcl2Parser::FloatConstContext *ctx)
    {
        print_debug_context("=== visitFloatConst: " + ctx->getText());

        ctx->type = Predefined::real_type;
        return visitChildren(ctx);
    }

    antlrcpp::Any Pass1Visitor::visitParenExpr(Pcl2Parser::ParenExprContext *ctx)
    {
        print_debug_context("=== visitParenExpr: " + ctx->getText());

        ctx->type = ctx->expr()->type;
        return visitChildren(ctx);
    }
#else

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                   C O M P I L A T I O N                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass1Visitor::visitCompilationUnit(Pcl2Parser::CompilationUnitContext *context)
    {
        auto value = visitChildren(context);
        print_debug_context("[PASS1] visitCompilationUnit: Printing xref table.");

        #if 0
        const string program_name = context->externalDeclaration()->declaration()->Identifier()->toString();

        cout << "************************* " << program_name << endl;

        program_id = symtab_stack->enter_local(program_name);
        program_id->set_definition((Definition)DF_PROGRAM);
        program_id->set_attribute((SymTabKey) ROUTINE_SYMTAB, new EntryValue(symtab_stack->push()));
        symtab_stack->set_program_id(program_id);

        try
        {
            if (j_file && !j_file.is_open())
            {
                // Create the assembly output file.
                j_file.open(program_name + ".j");
                if (j_file.fail())
                {
                    throw "***** Cannot open assembly file";
                }
            }
        }
        catch (const char * exception)
        {
            cerr << exception << endl;
            exit(-1);
        }

        // Emit the program header.
        j_file << ".class public " << program_name                      << endl;
        j_file << ".super java/lang/Object"                             << endl;

        // Emit the RunTimer and PascalTextIn fields.
        j_file                                                          << endl;
        j_file << ".field private static _runTimer LRunTimer;"          << endl;
        j_file << ".field private static _standardIn LPascalTextIn;"    << endl;


        // Print the cross-reference table
        CrossReferencer cross_referencer;
        cross_referencer.print(symtab_stack);
        #endif
        
        return value;
    }
    antlrcpp::Any Pass1Visitor::visitTranslationUnit(Pcl2Parser::TranslationUnitContext *context)
    {
        print_debug_context("[PASS1] visitTranslationUnit: Printing xref table.");
        return visitChildren(context);
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *               T Y P E  S P E C I F I E R S                *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass1Visitor::visitVoidType(Pcl2Parser::VoidTypeContext *context)
    {
        print_debug_context("[PASS1] visitVoidType: " + context->getText());
        context->type = Predefined::void_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitBoolType(Pcl2Parser::BoolTypeContext *context)
    {
        print_debug_context("[PASS1] visitBoolType: " + context->getText());
        context->type = Predefined::bool_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitCharType(Pcl2Parser::CharTypeContext *context)
    {
        print_debug_context("[PASS1] visitCharType: " + context->getText());
        context->type = Predefined::char_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitShortType(Pcl2Parser::ShortTypeContext *context)
    {
        print_debug_context("[PASS1] visitShortType: " + context->getText());
        context->type = Predefined::short_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitIntType(Pcl2Parser::IntTypeContext *context)
    {
        print_debug_context("[PASS1] visitIntType: " + context->getText());
        context->type = Predefined::int_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitLongType(Pcl2Parser::LongTypeContext *context)
    {
        print_debug_context("[PASS1] visitLongType: " + context->getText());
        context->type = Predefined::long_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitFloatType(Pcl2Parser::FloatTypeContext *context)
    {
        print_debug_context("[PASS1] visitFloatType: " + context->getText());
        context->type = Predefined::float_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitDoubleType(Pcl2Parser::DoubleTypeContext *context)
    {
        print_debug_context("[PASS1] visitDoubleType: " + context->getText());
        context->type = Predefined::double_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitSignedType(Pcl2Parser::SignedTypeContext *context)
    {
        print_debug_context("[PASS1] visitSignedType: " + context->getText());
        context->type = Predefined::signed_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitUnsignedType(Pcl2Parser::UnsignedTypeContext *context)
    {
        print_debug_context("[PASS1] visitUnsignedType: " + context->getText());
        context->type = Predefined::unsigned_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitUint32_tType(Pcl2Parser::Uint32_tTypeContext *context)
    {
        print_debug_context("[PASS1] visitUint32_tType: " + context->getText());
        context->type = Predefined::uint32_t_type;
        return visitChildren(context);
    }
    antlrcpp::Any Pass1Visitor::visitInt32_tType(Pcl2Parser::Int32_tTypeContext *context)
    {
        print_debug_context("[PASS1] visitInt32_tType: " + context->getText());
        context->type = Predefined::int32_t_type;
        return visitChildren(context);
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                   D E C L A R A T I O N S                 *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass1Visitor::visitDeclaration(Pcl2Parser::DeclarationContext *context)
    {
        print_debug_context("[PASS1] visitDeclaration: " + context->getText());

        const string variable_name = context->declarationSpecifiers()->declarationSpecifier()[0]->typeSpecifier()->toString();
        SymTabEntry * variable_id = symtab_stack->enter_local(variable_name);
        variable_id->set_definition((Definition) DF_VARIABLE);

        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitDeclarationSpecifiers(Pcl2Parser::DeclarationSpecifiersContext *context)
    {
        print_debug_context("[PASS1] visitDeclarationSpecifiers: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitDeclarationSpecifier(Pcl2Parser::DeclarationSpecifierContext *context)
    {
        print_debug_context("[PASS1] visitDeclarationSpecifier: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitDeclarator(Pcl2Parser::DeclaratorContext *context)
    {
        print_debug_context("[PASS1] visitDeclarator: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitDirectDeclarator(Pcl2Parser::DirectDeclaratorContext *context)
    {
        print_debug_context("[PASS1] visitDirectDeclarator: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitParameterDeclaration(Pcl2Parser::ParameterDeclarationContext *context)
    {
        print_debug_context("[PASS1] visitParameterDeclaration: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitExternalDeclaration(Pcl2Parser::ExternalDeclarationContext *context)
    {
        print_debug_context("[PASS1] visitExternalDeclaration: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitInitDeclaratorList(Pcl2Parser::InitDeclaratorListContext *context)
    {
        print_debug_context("[PASS1] visitInitDeclaratorList: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitInitDeclarator(Pcl2Parser::InitDeclaratorContext *context)
    {
        print_debug_context("[PASS1] visitInitDeclarator: " + context->getText());
        return visitChildren(context);        
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                          L I S T S                        *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass1Visitor::visitParameterTypeList(Pcl2Parser::ParameterTypeListContext *context)
    {
        print_debug_context("[PASS1] visitParameterTypeList: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitParameterList(Pcl2Parser::ParameterListContext *context)
    {
        print_debug_context("[PASS1] visitParameterList: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitIdentifierList(Pcl2Parser::IdentifierListContext *context)
    {
        print_debug_context("[PASS1] visitIdentifierList: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitBlockItemList(Pcl2Parser::BlockItemListContext *context)
    {
        print_debug_context("[PASS1] visitBlockItemList: " + context->getText());
        return visitChildren(context);        
    }
    antlrcpp::Any Pass1Visitor::visitBlockItem(Pcl2Parser::BlockItemContext *context)
    {
        print_debug_context("[PASS1] visitBlockItem: " + context->getText());
        return visitChildren(context);        
    }
#endif
