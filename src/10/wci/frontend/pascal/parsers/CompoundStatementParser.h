/**
 * <h1>CompoundStatementParser</h1>
 *
 * <p>Parse a Pascal compound statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef COMPOUNDSTATEMENTPARSER_H_
#define COMPOUNDSTATEMENTPARSER_H_

#include <string>
#include "StatementParser.h"
#include "../PascalToken.h"
#include "../../../intermediate/ICodeNode.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class CompoundStatementParser : public StatementParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    CompoundStatementParser(PascalParserTD *parent);

    /**
     * Parse a compound statement.
     * @param token the initial token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_statement(Token *token) throw (string);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* COMPOUNDSTATEMENTPARSER_H_ */
