#include "Pass2Visitor.hpp"



/**
 *  @note:
 *      Good resource for Jasmin instructions except this https://cs.au.dk/~mis/dOvs/jvmspec/ref-Java.html
 *      XSUB instructions will subtract bottom operand - top operand, with bottom operand as the first operand pushed onto the stack
 */

namespace backend
{

    Pass2Visitor::Pass2Visitor(const std::string fname, std::ofstream & j_file, const bool debug) : PassVisitor(2), program_name(fname), j_file(j_file), debug_flag(debug)
    {
        /// Empty
    }

    Pass2Visitor::~Pass2Visitor()
    {
        j_file.flush();
        j_file.close();
    }

    std::string Pass2Visitor::resolve_expression_instruction(const backend::TypeSpecifier & type, std::string const & opr)
    {
        static const std::map <const std::string, const std::string> operator_to_opcode_map =
        {
            { "*"  , "mul" },
            { "/"  , "div" },
            { "%"  , "rem" },
            { "+"  , "add" },
            { "-"  , "sub" },
            { "<<" , "shl" },
            { ">>" , "shr" },
            { "&"  , "and" },
            { "|"  , "or"  },
            { "~"  , "neg" },
            { "^"  , "xor" },
        };

        // Get opcode prefix
        std::string opcode(1, instruction_prefix_map_lookup(type));

        // Get opcode
        if (operator_to_opcode_map.find(opr) != operator_to_opcode_map.end())
        {
            opcode += operator_to_opcode_map.at(opr);
        }
        else
        {
            throw InvalidOperator(opr);
        }

        return opcode;
    }

    void Pass2Visitor::emit_symbol_table()
    {
        j_file                                                                                       << endl;
        j_file << "; Printing results of the program below"                                          << endl;
        j_file << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;
        j_file << "print_results:"                                                                   << endl << endl;
        j_file << TAB << "getstatic java/lang/System/out Ljava/io/PrintStream;"                      << endl;

        j_file << TAB << "dup"                                                                       << endl;
        j_file << TAB << "ldc \"-----------------------------------------------------------------\"" << endl;
        j_file << TAB << "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V"            << endl;
        j_file                                                                                       << endl;

        for (auto function : PassVisitor::variable_id_map)
        {
            // Only print symbols in global or main
            if (function.first == "global" || function.first == "main")
            {
                for (auto symbol : function.second)
                {
                    j_file << TAB << "; Printing symbol - " << symbol.first << endl;
                    j_file << TAB << "ldc \"" + symbol.first << " : ";

                    switch (symbol.second.get_type_letter())
                    {
                        case 'F': j_file << "%f\\n\"" << endl; break;
                        case 'D': j_file << "%f\\n\"" << endl; break;
                        case 'I': j_file << "%d\\n\"" << endl; break;
                        case 'L': j_file << "%d\\n\"" << endl; break;
                        default :
                            throw InvalidType(std::string("Invalid type letter found : ") + std::string(1, symbol.second.get_type_letter()));
                    }

                    j_file << TAB << "ldc 1"                      << endl;
                    j_file << TAB << "anewarray java/lang/Object" << endl;
                    j_file << TAB << "dup"                        << endl;
                    j_file << TAB << "iconst_0"                   << endl;

                    j_file << create_get_variable_instruction(program_name, symbol.first, symbol.second.get_type_letter()) << endl;

                    switch (symbol.second.get_type_letter())
                    {
                        case 'F': j_file << TAB << "invokestatic java/lang/Float/valueOf(F)Ljava/lang/Float;"     << endl; break;
                        case 'D': j_file << TAB << "invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;"   << endl; break;
                        case 'I': j_file << TAB << "invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;" << endl; break;
                        case 'L': j_file << TAB << "invokestatic java/lang/Long/valueOf(L)Ljava/lang/Long;"       << endl; break;
                        default : 
                            throw InvalidType(std::string("Invalid type letter found : ") + std::string(1, symbol.second.get_type_letter()));
                    }

                    j_file << TAB << "aastore" << endl;
                    j_file << TAB << "invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;" << endl;
                    j_file << endl;
                }
            }
        }

        j_file << TAB << "dup"                                                                       << endl;
        j_file << TAB << "ldc \"-----------------------------------------------------------------\"" << endl;
        j_file << TAB << "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V"            << endl;
        j_file                                                                                       << endl;
        j_file << ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;" << endl;
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                   C O M P I L A T I O N                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

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

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *               T Y P E  S P E C I F I E R S                *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitTypeSpecifier(CmmParser::TypeSpecifierContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Nothing yet
         */

        return visitChildren(context);
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                   D E C L A R A T I O N S                 *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitDeclaration(CmmParser::DeclarationContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Nothing yet
         */

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitFunctionDeclaration(CmmParser::FunctionDeclarationContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitFunctionDefinition(CmmParser::FunctionDefinitionContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();
        current_function = context->Identifier()->toString();

        bool is_main = context->Identifier()->getText() == "main";

        if (!is_main)
        {
            j_file << context->function_header << endl;
        }
        else
        {
            // Emit the main program header
            j_file                                                                          << endl;
            j_file << ".method public static main([Ljava/lang/String;)V"                    << endl;
            j_file                                                                          << endl;
            j_file << "\t; Timer Module Instantiation"                                      << endl;
            j_file << "\tnew RunTimer"                                                      << endl;
            j_file << "\tdup"                                                               << endl;
            j_file << "\tinvokenonvirtual RunTimer/<init>()V"                               << endl;
            j_file << "\tputstatic        " << program_name << "/_runTimer LRunTimer;"      << endl;
            j_file                                                                          << endl;

            // Output all buffered instructions
            for (auto instruction : instruction_buffer)
            {
                j_file << instruction << endl;
            }
        }

        visit(context->parameterTypeList());
        visit(context->compoundStatement());

        j_file << ".limit locals " << (context->num_local_vars+10) * 2                  << endl;
        j_file << ".limit stack " << context->stack_size                                << endl;
        j_file << ".end method" << endl;

        current_function = "global";
        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitFunctionCall(CmmParser::FunctionCallContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        if (context->identifierList())
        {
            visit(context->identifierList());
        }

        j_file << TAB << "invokestatic " << program_name << "/";
        j_file << PassVisitor::function_definition_map[context->Identifier()->toString()] << endl;

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitFunctionReturn(CmmParser::FunctionReturnContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        if (context->identifierList())
        {
            visit(context->identifierList());
        }

        j_file << TAB << "invokestatic " << program_name << "/";
        j_file << PassVisitor::function_definition_map[context->Identifier()->toString()] << endl;

        return nullptr;
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                   E X P R E S S I O N S                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitAssignmentExpression(CmmParser::AssignmentExpressionContext * context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  RHS expression will take care of emitting its own instructions
         *  This node will just load the value into the assigned variable
         */

        // Add a comment
        const std::string comment = "\t; " + context->getText();
        if (context->current_nesting_level == 1)
        {
            instruction_buffer.push_back(comment);
        }
        else
        {
            j_file << comment << endl;
        }

        backend::TypeSpecifier expression_type;

        try
        {
            if (context->expression())
            {
                // Visit right hand side expression first
                visit(context->expression());
                expression_type = context->expression()->type;

                const std::string type_convert_instruction = convert_type_if_neccessary(expression_type, context->type);
                if (type_convert_instruction.size() > 0)
                {
                    j_file << TAB << type_convert_instruction << endl;
                }
            }
            else if (context->functionReturn())
            {
                visit(context->functionReturn());
            }
            else
            {
                throw AntlrParsedIncorrectly("Assignment expression did not match any case");
            }
        }
        CATCH_CUSTOM_EXCEPTION_PRINT_AND_EXIT(AntlrParsedIncorrectly)

        std::string instruction = create_put_variable_instruction(program_name, context->Identifier()->toString(), context->type_letter);

        if (context->current_nesting_level == 1)
        {
            instruction_buffer.push_back(instruction);
        }
        else
        {
            j_file << instruction << endl;
        }

        return expression_type;
    }

    antlrcpp::Any Pass2Visitor::visitPrimExpr(CmmParser::PrimExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  If variable : emit getstatic
         *  If integer  : emit ldc
         *  If float    : emit ldc
         */

        std::string instruction;

        if (context->primaryExpression()->Identifier())
        {
            try
            {
                instruction += create_get_variable_instruction(program_name, context->primaryExpression()->Identifier()->getText(), context->type_letter);
            }
            catch (InvalidType const & error)
            {
                error.print_and_exit();
            }
        }
        else if (context->primaryExpression()->IntegerConstant() ||
                (context->primaryExpression()->FloatConstant()))
        {
            cout << TAB << context->type << endl;
            // Doubles need to be treated differently
            if (backend::Type::t_double == context->type.get_type())
            {
                std::string double_value;

                // If integer constant add decimal
                if (context->primaryExpression()->IntegerConstant())
                {
                    double_value += context->primaryExpression()->IntegerConstant()->getText();
                    double_value += ".0";
                }
                else
                {
                    double_value += context->primaryExpression()->FloatConstant()->getText();
                }

                instruction += "\t";
                instruction += "ldc2_w ";
                instruction += double_value;
            }
            else if (backend::Type::t_float == context->type.get_type())
            {
                std::string float_value;

                // If integer constant add decimal
                if (context->primaryExpression()->IntegerConstant())
                {
                    float_value += context->primaryExpression()->IntegerConstant()->getText();
                    float_value += ".0";
                }
                else
                {
                    float_value += context->primaryExpression()->FloatConstant()->getText();
                }

                instruction += "\t";
                instruction += "ldc ";
                instruction += float_value;
            }
            else
            {
                instruction += "\t";
                instruction += "ldc ";
                instruction += context->primaryExpression()->IntegerConstant()->getText();
            }
        }

        if (context->primaryExpression()->current_nesting_level == 1)
        {
            instruction_buffer.push_back(instruction);
        }
        else
        {
            j_file << instruction << endl;
        }

        visitChildren(context);

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitMulDivExpr(CmmParser::MulDivExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Visits children expressions first which will push to stack
         *  Then this node will emit an instruction using the previously pushed values
         */

        for (uint8_t i = 0; i < 2; i++)
        {
            visit(context->expression(i));

            // Type mismatches need to be converted
            const std::string type_convert_instruction = convert_type_if_neccessary(context->expression(i)->type, context->type);
            if (type_convert_instruction.size() > 0)
            {
                j_file << TAB << type_convert_instruction << endl;
            }
        }

        std::string opcode;

        try
        {
            opcode = resolve_expression_instruction(context->type, context->expr_operator);
        }
        catch (InvalidType const & error)
        {
            error.print_and_exit();
        }
        catch (InvalidOperator const & error)
        {
            error.print_and_exit();
        }

        j_file << "\t" << opcode << endl;

        return context->type;
    }

    antlrcpp::Any Pass2Visitor::visitAddminExpr(CmmParser::AddminExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Visits children expressions first which will push to stack
         *  Then this node will emit an instruction using the previously pushed values
         */

        for (uint8_t i = 0; i < 2; i++)
        {
            visit(context->expression(i));

            // Type mismatches need to be converted
            const std::string type_convert_instruction = convert_type_if_neccessary(context->expression(i)->type, context->type);
            if (type_convert_instruction.size() > 0)
            {
                j_file << TAB << type_convert_instruction << endl;
            }
        }

        std::string opcode;

        try
        {
            opcode = resolve_expression_instruction(context->type, context->expr_operator);
        }
        catch (InvalidType const & error)
        {
            error.print_and_exit();
        }
        catch (InvalidOperator const & error)
        {
            error.print_and_exit();
        }

        j_file << "\t" << opcode << endl;

        return context->type;
    }

    antlrcpp::Any Pass2Visitor::visitBitExpr(CmmParser::BitExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Visits children expressions first which will push to stack
         *  Then this node will emit an instruction using the previously pushed values
         */

        for (uint8_t i = 0; i < 2; i++)
        {
            visit(context->expression(i));

            // Type mismatches need to be converted
            const std::string type_convert_instruction = convert_type_if_neccessary(context->expression(i)->type, context->type);
            if (type_convert_instruction.size() > 0)
            {
                j_file << TAB << type_convert_instruction << endl;
            }
        }

        std::string opcode;

        try
        {
            opcode = resolve_expression_instruction(context->type, context->expr_operator);
        }
        catch (InvalidType const & error)
        {
            error.print_and_exit();
        }
        catch (InvalidOperator const & error)
        {
            error.print_and_exit();
        }

        j_file << "\t" << opcode << endl;

        return context->type;
    }

    antlrcpp::Any Pass2Visitor::visitBasicConditionalExpr(CmmParser::BasicConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Children emit instructions first
         *  Emits branch instruction for exiting the current branch
         */

        const std::string lhs_name = context->expression(0)->getText();
        const std::string rhs_name = context->expression(1)->getText();

        // Emit an explanation comment for condition
        j_file << TAB
               << "; "
               << lhs_name
               << " "
               << context->opr
               << " "
               << rhs_name
               << endl;

        // Visit both operands
        for (uint8_t i = 0; i < 2; i++)
        {
            visit(context->expression(i));
            // Doubles and floats need to be converted before jump comparison instruction
            if (backend::Type::t_double == context->expression(i)->type.get_type())
            {
                j_file << TAB
                       << "d2i"
                       << endl;
            }
            else if (backend::Type::t_float  == context->expression(i)->type.get_type())
            {
                j_file << TAB
                       << "f2i"
                       << endl;
            }
        }

        // Emit an explanation comment for exit
        j_file << TAB
               << "; Exit ["
               << context->iteration_name
               << "] condition"
               << endl;

        // Emit the instruction
        j_file << TAB
               << context->opcode
               << " "
               << context->iteration_name + "_end"
               << endl;

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitConnectedConditionalExpr(CmmParser::ConnectedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Top level conditional expression
         *  Responsible for only checking the top 2 values on the stack
         *  For an OR operation, if any of them are nonzero positive, jump
         *  For an AND operation, if both of them are nonzero positive, jump
         */

        // Visit left and right sides first
        auto lhs_result = visit(context->conditionalExpression(0));
        auto rhs_result = visit(context->conditionalExpression(1));

        // Left and right operands should have pushed values to the stack
        if ("or" == context->opr)
        {
            // If left condition is > 0, jump
            j_file << TAB
                   << "ifgt "
                   << context->iteration_name
                   << endl;
            // If right condition is > 0, jump
            j_file << TAB
                   << "ifgt "
                   << context->iteration_name
                   << endl;
        }
        else if ("and" == context->opr)
        {
            // Nothing needs to be done because for AND conditions both must be met, and both are checked previously in child nodes
        }

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitNegatedConditionalExpr(CmmParser::NegatedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Nothing yet
         */

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitParenthesizedConditionalExpr(CmmParser::ParenthesizedConditionalExprContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Nothing yet
         */

        return visitChildren(context);
    }

    /*////////////////////////////////////////////////////////////
     *                                                           *
     *                     S T A T E M E N T S                   *
     *                                                           *
     */////////////////////////////////////////////////////////////

    antlrcpp::Any Pass2Visitor::visitJumpStatement(CmmParser::JumpStatementContext *context)
    {
        if (PassVisitor::current_function == "main")
        {
            try
            {
                emit_symbol_table();
            }
            catch (InvalidType const & error)
            {
                error.print_and_exit();
            }
            // Emit the main program epilogue
            j_file                                                                       << endl;
            j_file << TAB << "; Print Elapsed Time"                                      << endl;
            j_file << TAB << "getstatic     " << program_name << "/_runTimer LRunTimer;" << endl;
            j_file << TAB << "invokevirtual RunTimer.printElapsedTime()V"                << endl;
        }

        if (context->expression())
        {
            visit(context->expression());
        }

        try
        {
            if (context->expression())
            {
                j_file << TAB << instruction_prefix_map_lookup(context->expression()->type);
            }
        }
        CATCH_CUSTOM_EXCEPTION_PRINT_AND_EXIT(InvalidType);

        j_file << TAB << "return" << endl << endl;

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitAssignmentStatement(CmmParser::AssignmentStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Nothing yet
         */

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitIterationStatement(CmmParser::IterationStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Emit start of loop label
         *  Visit children which will emit the instructions internal to the loop
         *  Emit a jump to start of loop
         *  Emit a label for the end of loop
         */

        j_file << endl
               << "; "
               << context->getText()
               << endl;

        // Emit the iteration label
        j_file << context->conditionalExpression()->iteration_name
               << ":"
               << endl;

        // Emit while loop
        auto value = visitChildren(context);

        // Emit a jump to start of loop
        j_file << TAB
               << "; Jump to start of loop"
               << endl
               << TAB
               << "goto "
               << context->conditionalExpression()->iteration_name
               << endl;

        // Add label to branch to for exiting the loop
        j_file << context->conditionalExpression()->iteration_name
               << "_end"
               << ":"
               << endl
               << endl;

        return value;
    }

    antlrcpp::Any Pass2Visitor::visitIfElseStatement(CmmParser::IfElseStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Top level if else statement node
         *  Visits children first to get the different branches emitted
         *  Then emit the final label that all branches will branch to
         */

        visitChildren(context);

        // Only increment scope_counter at the end of the entire statement
        const std::string end_label = "if_else_end_" + std::to_string(PassVisitor::scope_counter++);

        // Add label to branch to for exiting the loop
        j_file << end_label
               << ":"
               << endl
               << endl;

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitIfStatement(CmmParser::IfStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Emit start of if label
         *  Visit children which will emit the instructions internal to the branch
         *  Emit a label for the end of if
         *  @note : If condition is true continues into the branch
         *          If condition is false, branch to next branch
         *          At the end of the inside of the branch, jumps to end of the entire if-else statement
         */

        j_file << "; "
               << context->getText()
               << endl;

        // Emit start label
        j_file << context->conditionalExpression()->iteration_name
               << ":"
               << endl;

        // Visit expression child first
        visit(context->conditionalExpression());

        // Visit children inside the if block
        visit(context->statement());

        j_file << TAB
               << "; Exit if-else statement"
               << endl
               << TAB
               << "goto "
               << "if_else_end_" + std::to_string(PassVisitor::scope_counter)
               << endl;

        // Emit end label
        j_file << context->conditionalExpression()->iteration_name
               << "_end"
               << ":"
               << endl
               << endl;

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitElseIfStatement(CmmParser::ElseIfStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Emit start of else if label
         *  Visit children which will emit the instructions internal to the branch
         *  Emit a label for the end of else if
         *  @note : If condition is true continues into the branch
         *          If condition is false, branch to next branch
         *          At the end of the inside of the branch, jumps to end of the entire if-else statement
         */

        j_file << "; "
               << context->getText()
               << endl;

        // Emit start label
        j_file << context->conditionalExpression()->iteration_name
               << ":"
               << endl;

        // Visit expression child first
        visit(context->conditionalExpression());

        // Visit children inside the if block
        visit(context->statement());

        j_file << TAB
               << "; Exit if-else statement"
               << endl
               << TAB
               << "goto "
               << "if_else_end_" + std::to_string(PassVisitor::scope_counter)
               << endl;

        // Emit end label
        j_file << context->conditionalExpression()->iteration_name
               << "_end"
               << ":"
               << endl
               << endl;

        return nullptr;
    }

    antlrcpp::Any Pass2Visitor::visitElseStatement(CmmParser::ElseStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Emit start of else label
         *  Visit children which will emit the instructions internal to the branch
         *  Emit a label for the end of else
         *  @note : If condition is true continues into the branch
         *          If condition is false, branch to next branch
         *          At the end of the inside of the branch, jumps to end of the entire if-else statement
         */

        j_file << "; "
               << context->getText()
               << endl;

        // Emit start label
        j_file << "else_"
               << std::to_string(scope_counter)
               << ":"
               << endl;

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitUnaryIncrementStatement(CmmParser::UnaryIncrementStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Retrieve variable
         *  Load a constant one
         *  Emit an ADD instruction
         *  Write back variable
         */

        j_file << TAB
               << "; "
               << context->getText()
               << endl;

        j_file << create_get_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

        // Load one
        j_file << TAB
               << "iconst_1"
               << endl;

        // ADD
        j_file << TAB
               << resolve_expression_instruction(context->type, "+")
               << endl;

        j_file << create_put_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitUnaryDecrementStatement(CmmParser::UnaryDecrementStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Retrieve variable
         *  Load a constant one
         *  Emit a SUB instruction
         *  Write back variable
         *  @note : First variable pushed onto stack will be the LHS of a sub operation
         */

        j_file << TAB
               << "; "
               << context->getText()
               << endl;

        j_file << create_get_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

        switch (context->type.get_type())
        {
            case backend::Type::t_double : j_file << TAB << "dconst_1" << endl; break;
            case backend::Type::t_float  : j_file << TAB << "fconst_1" << endl; break;
            case backend::Type::t_int    : j_file << TAB << "iconst_1" << endl; break;
            default                      :                                      break;
        }

        // SUB
        j_file << TAB
               << resolve_expression_instruction(context->type, "-")
               << endl;

        j_file << create_put_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

        return visitChildren(context);
    }

    antlrcpp::Any Pass2Visitor::visitUnarySquareStatement(CmmParser::UnarySquareStatementContext *context)
    {
        PRINT_CONTEXT_AND_EXIT_IF_PARSE_ERROR();

        /**
         *  Retrieve variable twice
         *  Multiply them together = square
         *  Write back variable
         */

        j_file << TAB
               << "; "
               << context->getText()
               << endl;

        j_file << create_get_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

        j_file << TAB
               << ((context->type.get_type() == backend::Type::t_double) ? ("dup2") : ("dup"))
               << endl;

        // Multiply
        j_file << TAB
               << resolve_expression_instruction(context->type, "*")
               << endl;

        j_file << create_put_variable_instruction(program_name, context->Identifier()->getText(), context->type_letter) << endl;

        return visitChildren(context);
    }

} /// backend
