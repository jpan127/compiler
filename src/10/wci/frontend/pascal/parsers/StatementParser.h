/**
 * <h1>StatementParser</h1>
 *
 * <p>Parse a Pascal statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef STATEMENTPARSER_H_
#define STATEMENTPARSER_H_

#include <string>
#include <set>
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../../../intermediate/ICodeNode.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class StatementParser : public PascalParserTD
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    StatementParser(PascalParserTD *parent);

    /**
     * Parse a statement.
     * @param token the initial token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    virtual ICodeNode *parse_statement(Token *token) throw (string);

    /**
     * Parse a statement list.
     * @param token the curent token.
     * @param parent_node the parent node of the statement list.
     * @param terminator the token type of the node that terminates the list.
     * @param error_code the error code if the terminator token is missing.
     * @throw a string message if an error occurred.
     */
    void parse_list(Token *token, ICodeNode *parent_node,
                    const PascalTokenType terminator,
                    const PascalErrorCode error_code)
        throw (string);

    // Synchronization set for starting a statement.
    static set<PascalTokenType> STMT_START_SET;

    // Synchronization set for following a statement.
    static set<PascalTokenType> STMT_FOLLOW_SET;

protected:
    /**
     * Set the current line number as a statement node attribute.
     * @param node statement node
     * @param line_number the current line number
     */
    void set_line_number(ICodeNode *node, int line_number);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* STATEMENTPARSER_H_ */
