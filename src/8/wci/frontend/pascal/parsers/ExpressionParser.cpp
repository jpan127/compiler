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
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

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

ICodeNode *ExpressionParser::parse_statement(Token *token) 
{
    return parse_expression(token);
}

ICodeNode *ExpressionParser::parse_expression(Token *token) 
{
    // Parse a simple expression and make the root of its tree
    // the root node.
    ICodeNode *root_node = parse_simple_expression(token);

    if (nullptr == root_node) return nullptr;

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

        // Parse the second simple expression.  The operator node adopts
        // the simple expression's tree as its second child.
        op_node->add_child(parse_simple_expression(token));

        // The operator node becomes the new root node.
        root_node = op_node;
    }

    return root_node;
}

ICodeNode *ExpressionParser::parse_simple_expression(Token *token)
    
{
    TokenType token_type = token->get_type();

    // Look for a leading + or - sign.
    bool leading_plus_sign  = token_type == (TokenType) PT_PLUS;
    bool leading_minus_sign = token_type == (TokenType) PT_MINUS;
    bool leading_sign = leading_plus_sign || leading_minus_sign;

    if (leading_sign)
    {
        token = next_token(token);  // consume the + or -
    }

    // Parse a term and make the root of its tree the root node.
    ICodeNode *root_node = parse_term(token);

    if (nullptr == root_node) return nullptr;

    // Was there a leading - sign?
    if (leading_minus_sign)
    {
        // Create a NEGATE node and adopt the current tree
        // as its child. The NEGATE node becomes the new root node.
        ICodeNode *negate_node =
                ICodeFactory::create_icode_node((ICodeNodeType) NT_NEGATE);
        negate_node->add_child(root_node);
        root_node = negate_node;
    }

    token = current_token();
    token_type = token->get_type();

    // Loop over additive operators.
    map<PascalTokenType, ICodeNodeTypeImpl>::iterator it;
    while ((it = ADD_OPS_MAP.find((PascalTokenType) token_type)) != ADD_OPS_MAP.end())
    {
        // Create a new operator node and adopt the current tree
        // as its first child.
        ICodeNodeType node_type = (ICodeNodeType) it->second;
        ICodeNode *op_node = ICodeFactory::create_icode_node(node_type);
        op_node->add_child(root_node);

        token = next_token(token);  // consume the operator

        // Parse another term.  The operator node adopts
        // the term's tree as its second child.
        op_node->add_child(parse_term(token));

        // The operator node becomes the new root node.
        root_node = op_node;

        token = current_token();
        token_type = token->get_type();
    }

    return root_node;
}

ICodeNode *ExpressionParser::parse_term(Token *token) 
{
    // Parse a factor and make its node the root node.
    ICodeNode *root_node = parse_factor(token);

    if (nullptr == root_node) return nullptr;

    token = current_token();
    TokenType token_type = token->get_type();

    // Loop over multiplicative operators.
    map<PascalTokenType, ICodeNodeTypeImpl>::iterator it;
    while ((it = MULT_OPS_MAP.find((PascalTokenType) token_type)) != MULT_OPS_MAP.end())
    {
        // Create a new operator node and adopt the current tree
        // as its first child.
        ICodeNodeType node_type = (ICodeNodeType) it->second;
        ICodeNode *op_node = ICodeFactory::create_icode_node(node_type);
        op_node->add_child(root_node);

        token = next_token(token);  // consume the operator

        // Parse another factor.  The operator node adopts
        // the term's tree as its second child.
        op_node->add_child(parse_factor(token));

        // The operator node becomes the new root node.
        root_node = op_node;

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
ICodeNode *ExpressionParser::parse_factor(Token *token) 
{
    TokenType token_type = token->get_type();
    ICodeNode *root_node = nullptr;

    // cout << "[F] " << __FILE__ << "::" << __FUNCTION__ << endl;
    // cout << "[T] " << token->get_text() << endl;

    switch ((PascalTokenType) token_type)
    {
        case PT_IDENTIFIER:
        {
            // Look up the identifier in the symbol table stack.
            // Flag the identifier as undefined if it's not found.
            string name = to_lower(token->get_text());
            SymTabEntry *id = symtab_stack->lookup(name);
            if (id == nullptr)
            {
                error_handler.flag(token, IDENTIFIER_UNDEFINED, this);
                id = symtab_stack->enter_local(name);
            }

            root_node =
                    ICodeFactory::create_icode_node(
                                         (ICodeNodeType) NT_VARIABLE);
            root_node->set_attribute((ICodeKey) ID, id);
            id->append_line_number(token->get_line_number());

            token = next_token(token);  // consume the identifier
            break;
        }

        case PT_INTEGER:
        {
            // Create an INTEGER_CONSTANT node as the root node.
            root_node = ICodeFactory::create_icode_node(
                                    (ICodeNodeType) NT_INTEGER_CONSTANT);
            root_node->set_attribute((ICodeKey) VALUE, token->get_value());

            token = next_token(token);  // consume the number
            break;
        }

        case PT_REAL:
        {
            // Create an REAL_CONSTANT node as the root node.
            root_node = ICodeFactory::create_icode_node(
                                       (ICodeNodeType) NT_REAL_CONSTANT);
            root_node->set_attribute((ICodeKey) VALUE, token->get_value());

            token = next_token(token);  // consume the number
            break;
        }

        case PT_STRING:
        {
            string value = cast(token->get_value(), string);

            // Create a STRING_CONSTANT node as the root node.
            root_node = ICodeFactory::create_icode_node(
                                     (ICodeNodeType) NT_STRING_CONSTANT);
            root_node->set_attribute((ICodeKey) VALUE, value);

            token = next_token(token);  // consume the string
            break;
        }

        case PT_NOT:
        {
            token = next_token(token);  // consume the NOT

            // Create a NOT node as the root node.
            root_node = ICodeFactory::create_icode_node(
                                                 (ICodeNodeType) NT_NOT);

            // Parse the factor.  The NOT node adopts the
            // factor node as its child.
            root_node->add_child(parse_factor(token));

            break;
        }

        case PT_LEFT_PAREN:
        {
            token = next_token(token);      // consume the (

            // Parse an expression and make its node the root node.
            root_node = parse_expression(token);

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

}}}}  // namespace wci::frontend::pascal::parsers
