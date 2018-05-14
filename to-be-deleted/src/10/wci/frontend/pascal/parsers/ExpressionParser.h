/**
 * <h1>ExpressionParser</h1>
 *
 * <p>Parse a Pascal expression.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef EXPRESSIONPARSER_H_
#define EXPRESSIONPARSER_H_

#include <string>
#include <map>
#include <set>
#include "StatementParser.h"
#include "../PascalToken.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

class ExpressionParser : public StatementParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    ExpressionParser(PascalParserTD *parent);

    /**
     * Parse an expression.
     * @param token the initial token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_statement(Token *token) throw (string);

    // Synchronization set for starting an expression.
    static set<PascalTokenType> EXPR_START_SET;

private:
    static map<PascalTokenType, ICodeNodeTypeImpl> REL_OPS_MAP;
    static map<PascalTokenType, ICodeNodeTypeImpl> ADD_OPS_MAP;
    static map<PascalTokenType, ICodeNodeTypeImpl> MULT_OPS_MAP;

    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();

    /**
     * Parse an expression.
     * @param token the initial token.
     * @return the root of the generated parse subtree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_expression(Token *token) throw (string);

    /**
     * Parse a simple expression.
     * @param token the initial token.
     * @return the root of the generated parse subtree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_simple_expression(Token *token) throw (string);

    /**
     * Parse a term.
     * @param token the initial token.
     * @return the root of the generated parse subtree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_term(Token *token) throw (string);

    /**
     * Parse a factor.
     * @param token the initial token.
     * @return the root of the generated parse subtree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_factor(Token *token) throw (string);

    /**
     * Parse an identifier.
     * @param token the current token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_identifier(Token *token) throw (string);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* EXPRESSIONPARSER_H_ */
