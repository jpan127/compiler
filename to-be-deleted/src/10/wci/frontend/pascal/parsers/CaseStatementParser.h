/**
 * <h1>CaseStatementParser</h1>
 *
 * <p>Parse a Pascal CASE statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef CASESTATEMENTPARSER_H_
#define CASESTATEMENTPARSER_H_

#include <string>
#include <set>
#include "StatementParser.h"
#include "../../Token.h"
#include "../../../intermediate/TypeSpec.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class CaseStatementParser : public StatementParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    CaseStatementParser(PascalParserTD *parent);

    /**
     * Parse an IF statement.
     * @param token the initial token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_statement(Token *token) throw (string);

private:
    // Synchronization set for starting a CASE option constant.
    static set<PascalTokenType> CONSTANT_START_SET;

    // Synchronization set for OF.
    static set<PascalTokenType> OF_SET;

    // Synchronization set for COMMA.
    static set<PascalTokenType> COMMA_SET;

    static bool INITIALIZED;

    /**
     * Initialize the synchronization sets.
     */
    static void initialize();

    /**
     * Parse a CASE branch.
     * @param token the current token.
     * @param expr_typespec the CASE expression type.
     * @param constant_set the set of CASE branch constants.
     * @return the root SELECT_BRANCH node of the subtree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_branch(Token *token, TypeSpec *expr_typespec,
                            set<int>& constant_set)
        throw (string);

    /**
     * Parse a list of CASE branch constants.
     * @param token the current token.
     * @param expr_typespec the CASE expression type.
     * @param constants_node the parent SELECT_CONSTANTS node.
     * @param constant_set the set of CASE branch constants.
     * @throw a string message if an error occurred.
     */
    void parse_constant_list(Token *token, TypeSpec *expr_typespec,
                             ICodeNode *constants_node,
                             set<int>& constant_set)
        throw (string);

    /**
     * Parse a CASE branch constant.
     * @param token the current token.
     * @param expr_typespec the CASE expression type.
     * @param constant_set the set of CASE branch constants.
     * @return the constant node.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_constant(Token *token, TypeSpec *expr_typespec,
                              set<int>& constant_set)
        throw (string);

    /**
     * Parse an identifier CASE constant.
     * @param value the current token value string.
     * @param minus_sign true if there was a minus sign.
     * @return the constant node.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_identifier_constant(Token *token, const bool minus_sign)
        throw (string);

    /**
     * Parse an integer CASE constant.
     * @param value the current token value string.
     * @param minus_sign true if there was a minus sign.
     * @return the constant node.
     */
    ICodeNode *parse_integer_constant(const string value,
                                      const bool minus_sign);

    /**
     * Parse a character CASE constant.
     * @param token the current token.
     * @param value the token value string.
     * @param sign the sign, if any.
     * @return the constant node.
     */
    ICodeNode *parse_character_constant(Token *token, const string value,
                                        const bool minus_sign);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* CASESTATEMENTPARSER_H_ */
