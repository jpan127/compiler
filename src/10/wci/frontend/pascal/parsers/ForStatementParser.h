/**
 * <h1>ForStatementParser</h1>
 *
 * <p>Parse a FOR statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef FORSTATEMENTPARSER_H_
#define FORSTATEMENTPARSER_H_

#include <string>
#include <set>
#include "StatementParser.h"
#include "../../Token.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class ForStatementParser : public StatementParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    ForStatementParser(PascalParserTD *parent);

    /**
     * Parse a FOR statement.
     * @param token the initial token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_statement(Token *token) throw (string);

private:
    // Synchronization set for TO or DOWNTO.
    static set<PascalTokenType> TO_DOWNTO_SET;

    // Synchronization set for DO.
    static set<PascalTokenType> DO_SET;

    static bool INITIALIZED;

    /**
     * Initialize the synchronization sets.
     */
    static void initialize();
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* FORSTATEMENTPARSER_H_ */
