/**
 * <h1>RepeatStatementParser</h1>
 *
 * <p>Parse a Pascal REPEAT statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "RepeatStatementParser.h"
#include "StatementParser.h"
#include "ExpressionParser.h"
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

RepeatStatementParser::RepeatStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
}

ICodeNode *RepeatStatementParser::parse_statement(Token *token)
    
{
    // Create the LOOP and TEST nodes.
    ICodeNode *loop_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_LOOP);
    ICodeNode *test_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_TEST);

    token = next_token(token);  // consume the REPEAT

    // Parse the statement list terminated by the UNTIL token.
    // The LOOP node is the parent of the statement subtrees.
    StatementParser statement_parser(this);
    statement_parser.parse_list(token, loop_node, PT_UNTIL, MISSING_UNTIL);

    token = current_token();

    // Parse the expression.
    // The TEST node adopts the expression subtree as its only child.
    // The LOOP node adopts the TEST node.
    ExpressionParser expression_parser(this);
    test_node->add_child(expression_parser.parse_statement(token));
    loop_node->add_child(test_node);

    return loop_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
