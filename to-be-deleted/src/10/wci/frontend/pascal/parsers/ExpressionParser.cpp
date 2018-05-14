/**
 * <h1>ExpressionParser</h1>
 *
 * <p>Parse a Pascal expression.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "ExpressionParser.h"
#include "VariableParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../frontend/pascal/PascalError.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/symtabimpl/Predefined.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"
#include "../../../intermediate/TypeSpec.h"
#include "../../../intermediate/TypeFactory.h"
#include "../../../intermediate/typeimpl/TypeChecker.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::icodeimpl;
using namespace wci::intermediate::typeimpl;

bool ExpressionParser::INITIALIZED = false;

map<PascalTokenType, ICodeNodeTypeImpl> ExpressionParser::REL_OPS_MAP;
map<PascalTokenType, ICodeNodeTypeImpl> ExpressionParser::ADD_OPS_MAP;
map<PascalTokenType, ICodeNodeTypeImpl> ExpressionParser::MULT_OPS_MAP;

set<PascalTokenType> ExpressionParser::EXPR_START_SET =
{
    PT_PLUS, PT_MINUS, PT_IDENTIFIER, PT_INTEGER, PT_REAL, PT_STRING,
    PT_NOT, PT_LEFT_PAREN,
};

void ExpressionParser::initialize()
{
    if (INITIALIZED) return;

    REL_OPS_MAP[PT_EQUALS]         = NT_EQ;
    REL_OPS_MAP[PT_NOT_EQUALS]     = NT_NE;
    REL_OPS_MAP[PT_LESS_THAN]      = NT_LT;
    REL_OPS_MAP[PT_LESS_EQUALS]    = NT_LE;
    REL_OPS_MAP[PT_GREATER_THAN]   = NT_GT;
    REL_OPS_MAP[PT_GREATER_EQUALS] = NT_GE;

    ADD_OPS_MAP[PT_PLUS]  = NT_ADD;
    ADD_OPS_MAP[PT_MINUS] = NT_SUBTRACT;
    ADD_OPS_MAP[PT_OR]    = NT_OR;

    MULT_OPS_MAP[PT_STAR]  = NT_MULTIPLY;
    MULT_OPS_MAP[PT_SLASH] = NT_FLOAT_DIVIDE;
    MULT_OPS_MAP[PT_DIV]   = NT_INTEGER_DIVIDE;
    MULT_OPS_MAP[PT_MOD]   = NT_MOD;
    MULT_OPS_MAP[PT_AND]   = NT_AND;

    INITIALIZED = true;
}

ExpressionParser::ExpressionParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *ExpressionParser::parse_statement(Token *token) throw (string)
{
    return parse_expression(token);
}

ICodeNode *ExpressionParser::parse_expression(Token *token) throw (string)
{
    // Parse a simple expression and make the root of its tree
    // the root node.
    ICodeNode *root_node = parse_simple_expression(token);
    TypeSpec *result_typespec = root_node != nullptr
                                    ? root_node->get_typespec()
                                    : Predefined::undefined_type;

    token = current_token();
    TokenType token_type = token->get_type();

    // Look for a relational operator.
    map<PascalTokenType, ICodeNodeTypeImpl>::iterator it =
                          REL_OPS_MAP.find((PascalTokenType) token_type);
    if (it != REL_OPS_MAP.end())
    {
        // Create a new operator node and adopt the current tree
        // as its first child.
        ICodeNodeType node_type = (ICodeNodeType) it->second;
        ICodeNode *op_node = ICodeFactory::create_icode_node(node_type);
        op_node->add_child(root_node);

        token = next_token(token);  // consume the operator
        Token *expr_token = new Token(*token);

        // Parse the second simple expression.  The operator node adopts
        // the simple expression's tree as its second child.
        ICodeNode *simexpr_node = parse_simple_expression(token);
        op_node->add_child(simexpr_node);

        // The operator node becomes the new root node.
        root_node = op_node;

        // Type check: The operands must be comparison compatible.
        TypeSpec *sim_expr_typespec = simexpr_node != nullptr
                                         ? simexpr_node->get_typespec()
                                         : Predefined::undefined_type;
        if (TypeChecker::are_comparison_compatible(result_typespec,
                                                   sim_expr_typespec))
        {
            result_typespec = Predefined::boolean_type;
        }
        else {
            token = current_token();
            error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
            result_typespec = Predefined::undefined_type;
        }

        delete expr_token;
    }

    if (root_node != nullptr)
    {
        root_node->set_typespec(result_typespec);
    }

    return root_node;
}

ICodeNode *ExpressionParser::parse_simple_expression(Token *token)
    throw (string)
{
    TokenType token_type = token->get_type();

    // Look for a leading + or - sign.
    bool leading_plus_sign  = token_type == (TokenType) PT_PLUS;
    bool leading_minus_sign = token_type == (TokenType) PT_MINUS;
    bool leading_sign = leading_plus_sign || leading_minus_sign;
    Token *sign_token;

    if (leading_sign)
    {
        sign_token = new Token(*token);
        token = next_token(token);  // consume the + or -
    }

    // Parse a term and make the root of its tree the root node.
    ICodeNode *root_node = parse_term(token);
    TypeSpec *result_typespec = root_node != nullptr
                                    ? root_node->get_typespec()
                                    : Predefined::undefined_type;

    // Type check: Leading sign.
    if (leading_sign && (!TypeChecker::is_integer_or_real(result_typespec)))
    {
        error_handler.flag(sign_token, INCOMPATIBLE_TYPES, this);
    }

    // Was there a leading - sign?
    if (leading_minus_sign)
    {
        // Create a NEGATE node and adopt the current tree
        // as its child. The NEGATE node becomes the new root node.
        ICodeNode *negate_node =
                ICodeFactory::create_icode_node((ICodeNodeType) NT_NEGATE);
        negate_node->add_child(root_node);
        negate_node->set_typespec(root_node->get_typespec());
        root_node = negate_node;
    }

    token = current_token();
    token_type = token->get_type();

    // Loop over additive operators.
    map<PascalTokenType, ICodeNodeTypeImpl>::iterator it;
    while ((it = ADD_OPS_MAP.find((PascalTokenType) token_type))
                                               != ADD_OPS_MAP.end())
    {
        TokenType op = token_type;

        // Create a new operator node and adopt the current tree
        // as its first child.
        ICodeNodeType node_type = (ICodeNodeType) it->second;
        ICodeNode *op_node = ICodeFactory::create_icode_node(node_type);
        op_node->add_child(root_node);

        token = next_token(token);  // consume the operator
        Token *expr_token = new Token(*token);

        // Parse another term.  The operator node adopts
        // the term's tree as its second child.
        ICodeNode *term_node = parse_term(token);
        op_node->add_child(term_node);
        TypeSpec *term_typespec = term_node != nullptr
                                      ? term_node->get_typespec()
                                      : Predefined::undefined_type;

        // The operator node becomes the new root node.
        root_node = op_node;

        // Determine the result type.
        switch ((PascalTokenType) op)
        {

            case PT_PLUS:
            case PT_MINUS:
            {
                // Both operands integer ==> integer result.
                if (TypeChecker::are_both_integer(result_typespec,
                                                  term_typespec))
                {
                    result_typespec = Predefined::integer_type;
                }

                // Both real operands or one real and one integer operand
                // ==> real result.
                else if (TypeChecker::is_at_least_one_real(result_typespec,
                                                           term_typespec))
                {
                    result_typespec = Predefined::real_type;
                }

                else
                {
                    error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
                }

                break;
            }

            case PT_OR:
            {
                // Both operands boolean ==> boolean result.
                if (TypeChecker::are_both_boolean(result_typespec,
                                                  term_typespec))
                {
                    result_typespec = Predefined::boolean_type;
                }
                else
                {
                    error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
                }

                break;
            }

            default:
            {
                // Should never get here ...
                result_typespec = Predefined::undefined_type;
            }
        }

        root_node->set_typespec(result_typespec);

        delete expr_token;
        token = current_token();
        token_type = token->get_type();
    }

    return root_node;
}

ICodeNode *ExpressionParser::parse_term(Token *token) throw (string)
{
    // Parse a factor and make its node the root node.
    ICodeNode *root_node = parse_factor(token);
    TypeSpec *result_typespec = root_node != nullptr
                                    ? root_node->get_typespec()
                                    : Predefined::undefined_type;

    token = current_token();
    TokenType token_type = token->get_type();

    // Loop over multiplicative operators.
    map<PascalTokenType, ICodeNodeTypeImpl>::iterator it;
    while ((it = MULT_OPS_MAP.find((PascalTokenType) token_type))
                                               != MULT_OPS_MAP.end())
    {
        TokenType op = token_type;

        // Create a new operator node and adopt the current tree
        // as its first child.
        ICodeNodeType node_type = (ICodeNodeType) it->second;
        ICodeNode *op_node = ICodeFactory::create_icode_node(node_type);
        op_node->add_child(root_node);

        token = next_token(token);  // consume the operator
        Token *expr_token = new Token(*token);

        // Parse another factor.  The operator node adopts
        // the term's tree as its second child.
        ICodeNode *factor_node = parse_factor(token);
        op_node->add_child(factor_node);
        TypeSpec *factor_typespec = factor_node != nullptr
                                        ? factor_node->get_typespec()
                                        : Predefined::undefined_type;

        // The operator node becomes the new root node.
        root_node = op_node;

        // Determine the result type.
        switch ((PascalTokenType) op)
        {
            case PT_STAR:
            {
                // Both operands integer ==> integer result.
                if (TypeChecker::are_both_integer(result_typespec,
                                                  factor_typespec))
                {
                    result_typespec = Predefined::integer_type;
                }

                // Both real operands or one real and one integer operand
                // ==> real result.
                else if (TypeChecker::is_at_least_one_real(result_typespec,
                                                           factor_typespec))
                {
                    result_typespec = Predefined::real_type;
                }

                else
                {
                    error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
                }

                break;
            }

            case PT_SLASH:
            {
                // All integer and real operand combinations
                // ==> real result.
                if (   TypeChecker::are_both_integer(result_typespec,
                                                     factor_typespec)
                    || TypeChecker::is_at_least_one_real(result_typespec,
                                                         factor_typespec))
                {
                    result_typespec = Predefined::real_type;
                }
                else
                {
                    error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
                }

                break;
            }

            case PT_DIV:
            case PT_MOD:
            {
                // Both operands integer ==> integer result.
                if (TypeChecker::are_both_integer(result_typespec,
                                                  factor_typespec))
                {
                    result_typespec = Predefined::integer_type;
                }
                else
                {
                    error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
                }

                break;
            }

            case PT_AND:
            {
                // Both operands boolean ==> boolean result.
                if (TypeChecker::are_both_boolean(result_typespec,
                                                  factor_typespec))
                {
                    result_typespec = Predefined::boolean_type;
                }
                else
                {
                    error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
                }

                break;
            }

            default:
            {
                // Should never get here ...
                result_typespec = Predefined::undefined_type;
            }
        }

        root_node->set_typespec(result_typespec);

        delete expr_token;
        token = current_token();
        token_type = token->get_type();
    }

    return root_node;
}

/**
 * Parse a factor.
 * @param token the initial token.
 * @return the root of the generated parse subtree.
 * @throws Exception if an error occurred.
 */
ICodeNode *ExpressionParser::parse_factor(Token *token) throw (string)
{
    TokenType token_type = token->get_type();
    ICodeNode *root_node = nullptr;

    switch ((PascalTokenType) token_type)
    {
        case PT_IDENTIFIER:
        {
            return parse_identifier(token);
        }

        case PT_INTEGER:
        {
            // Create an INTEGER_CONSTANT node as the root node.
            root_node = ICodeFactory::create_icode_node(
                                    (ICodeNodeType) NT_INTEGER_CONSTANT);
            root_node->set_attribute((ICodeKey) VALUE, token->get_value());

            token = next_token(token);  // consume the number

            root_node->set_typespec(Predefined::integer_type);
            break;
        }

        case PT_REAL:
        {
            // Create an REAL_CONSTANT node as the root node.
            root_node = ICodeFactory::create_icode_node(
                                       (ICodeNodeType) NT_REAL_CONSTANT);
            root_node->set_attribute((ICodeKey) VALUE, token->get_value());

            token = next_token(token);  // consume the number

            root_node->set_typespec(Predefined::real_type);
            break;
        }

        case PT_STRING:
        {
            string value = cast(token->get_value(), string);

            // Create a STRING_CONSTANT node as the root node.
            root_node = ICodeFactory::create_icode_node(
                                     (ICodeNodeType) NT_STRING_CONSTANT);
            root_node->set_attribute((ICodeKey) VALUE, value);

            TypeSpec *result_typespec = value.length() == 1
                              ? Predefined::char_type
                              : TypeFactory::create_string_type(value);

            token = next_token(token);  // consume the string

            root_node->set_typespec(result_typespec);
            break;
        }

        case PT_NOT:
        {
            token = next_token(token);  // consume the NOT
            Token *expr_token = new Token(*token);

            // Create a NOT node as the root node.
            root_node = ICodeFactory::create_icode_node(
                                                 (ICodeNodeType) NT_NOT);

            // Parse the factor.  The NOT node adopts the
            // factor node as its child.
            ICodeNode *factor_node = parse_factor(token);
            root_node->add_child(factor_node);

            // Type check: The factor must be boolean.
            TypeSpec *factor_typespec = factor_node != nullptr
                                            ? factor_node->get_typespec()
                                            : Predefined::undefined_type;
            if (!TypeChecker::is_boolean(factor_typespec))
            {
                error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
            }

            delete expr_token;
            root_node->set_typespec(Predefined::boolean_type);
            break;
        }

        case PT_LEFT_PAREN:
        {
            token = next_token(token);      // consume the (

            // Parse an expression and make its node the root node.
            root_node = parse_expression(token);
            TypeSpec *result_typespec = root_node != nullptr
                                            ? root_node->get_typespec()
                                            : Predefined::undefined_type;

            // Look for the matching ) token.
            token = current_token();
            if (token->get_type()
                           == (TokenType) PT_RIGHT_PAREN)
            {
                token = next_token(token);  // consume the )
            }
            else
            {
                error_handler.flag(token, MISSING_RIGHT_PAREN, this);
            }

            root_node->set_typespec(result_typespec);
            break;
        }

        default:
        {
            error_handler.flag(token, UNEXPECTED_TOKEN, this);
            break;
        }
    }

    return root_node;
}
ICodeNode *ExpressionParser::parse_identifier(Token *token) throw (string)
{
    ICodeNode *root_node = nullptr;

    // Look up the identifier in the symbol table stack.
    // Flag the identifier as undefined if it's not found.
    string name = to_lower(token->get_text());
    SymTabEntry *variable_id = symtab_stack->lookup(name);

    // Undefined.
    if (variable_id == nullptr)
    {
        error_handler.flag(token, IDENTIFIER_UNDEFINED, this);
        variable_id = symtab_stack->enter_local(name);
        variable_id->set_definition((Definition) DF_UNDEFINED);
        variable_id->set_typespec(Predefined::undefined_type);
    }

    Definition defn = variable_id->get_definition();

    switch ((DefinitionImpl) defn)
    {
        case DF_CONSTANT:
        {
            Object value =
                variable_id->get_attribute((SymTabKey) CONSTANT_VALUE);
            TypeSpec *typespec = variable_id->get_typespec();

            if (instanceof(value, int))
            {
                root_node =
                    ICodeFactory::create_icode_node(
                                   (ICodeNodeType) NT_INTEGER_CONSTANT);
                root_node->set_attribute((ICodeKey) VALUE, value);
            }
            else if (instanceof(value, float))
            {
                root_node =
                    ICodeFactory::create_icode_node(
                                       (ICodeNodeType) NT_REAL_CONSTANT);
                root_node->set_attribute((ICodeKey) VALUE, value);
            }
            else if (instanceof(value, string))
            {
                root_node =
                    ICodeFactory::create_icode_node(
                                     (ICodeNodeType) NT_STRING_CONSTANT);
                root_node->set_attribute((ICodeKey) VALUE, value);
            }

            variable_id->append_line_number(token->get_line_number());
            token = next_token(token);  // consume the constant identifier

            if (root_node != nullptr) root_node->set_typespec(typespec);
            break;
        }

        case DF_ENUMERATION_CONSTANT:
        {
            Object value =
                variable_id->get_attribute((SymTabKey) CONSTANT_VALUE);
            TypeSpec *typespec = variable_id->get_typespec();

            root_node =
                ICodeFactory::create_icode_node(
                                    (ICodeNodeType) NT_INTEGER_CONSTANT);
            root_node->set_attribute((ICodeKey) VALUE, value);

            variable_id->append_line_number(token->get_line_number());
            token = next_token(token);  // consume the enum constant identifier

            root_node->set_typespec(typespec);
            break;
        }

        default:
        {
            VariableParser variable_parser(this);
            root_node = variable_parser.parse_variable(token, variable_id);
            break;
        }
    }

    return root_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
