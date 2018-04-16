/**
 * <h1>CompoundStatementParser</h1>
 *
 * <p>Parse a Pascal compound statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "CompoundStatementParser.h"
#include "StatementParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

CompoundStatementParser::CompoundStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
}

ICodeNode *CompoundStatementParser::parse_statement(Token *token)
    throw (string)
{
    // Create the COMPOUND node.
    ICodeNode *compound_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_COMPOUND);

    token = next_token(token);  // consume the BEGIN

    // Parse the statement list terminated by the END token.
    StatementParser statement_parser(this);
    statement_parser.parse_list(token, compound_node,
                                PT_END, MISSING_END);

    return compound_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
