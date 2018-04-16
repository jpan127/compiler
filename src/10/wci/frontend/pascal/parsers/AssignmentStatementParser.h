/**
 * <h1>AssignmentStatementParser</h1>
 *
 * <p>Parse a Pascal assignment statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef ASSIGNMENTSTATEMENTPARSER_H_
#define ASSIGNMENTSTATEMENTPARSER_H_

#include <string>
#include "StatementParser.h"
#include "../PascalToken.h"
#include "../../../intermediate/ICodeNode.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class AssignmentStatementParser : public StatementParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    AssignmentStatementParser(PascalParserTD *parent);

    /**
     * Parse an assignment statement.
     * @param token the initial token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_statement(Token *token) throw (string);

private:
    static set<PascalTokenType> COLON_EQUALS_SET;

    static bool INITIALIZED;

    /**
     * Initialize the synchronization set.
     */
    static void initialize();
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* ASSIGNMENTSTATEMENTPARSER_H_ */
