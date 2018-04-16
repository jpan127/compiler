/**
 * <h1>IfStatementParser</h1>
 *
 * <p>Parse a Pascal IF statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef IFSTATEMENTPARSER_H_
#define IFSTATEMENTPARSER_H_

#include <string>
#include <set>
#include "StatementParser.h"
#include "../../Token.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class IfStatementParser : public StatementParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    IfStatementParser(PascalParserTD *parent);

    /**
     * Parse an IF statement.
     * @param token the initial token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_statement(Token *token) throw (string);

private:
    // Synchronization set for THEN.
    static set<PascalTokenType> THEN_SET;

    static bool INITIALIZED;

    /**
     * Initialize the synchronization set.
     */
    static void initialize();
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* IFSTATEMENTPARSER_H_ */
