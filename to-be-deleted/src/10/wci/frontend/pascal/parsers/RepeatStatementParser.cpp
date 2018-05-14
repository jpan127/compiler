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
#include "../../../intermediate/symtabimpl/Predefined.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"
#include "../../../intermediate/TypeSpec.h"
#include "../../../intermediate/typeimpl/TypeChecker.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::icodeimpl;
using namespace wci::intermediate::typeimpl;

RepeatStatementParser::RepeatStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
}

ICodeNode *RepeatStatementParser::parse_statement(Token *token)
    throw (string)
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
    Token *expr_token = new Token(*token);

    // Parse the expression.
    // The TEST node adopts the expression subtree as its only child.
    // The LOOP node adopts the TEST node.
    ExpressionParser expression_parser(this);
    ICodeNode *expr_node = expression_parser.parse_statement(token);
    test_node->add_child(expr_node);
    loop_node->add_child(test_node);

    // Type check: The test expression must be boolean.
    TypeSpec *expr_typespec = expr_node != nullptr
                                  ? expr_node->get_typespec()
                                  : Predefined::undefined_type;
    if (!TypeChecker::is_boolean(expr_typespec))
    {
        error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
    }

    delete expr_token;
    return loop_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
