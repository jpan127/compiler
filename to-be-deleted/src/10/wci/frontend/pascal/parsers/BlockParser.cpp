/**
 * <h1>BlockParser</h1>
 *
 * <p>Parse a Pascal block.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <set>
#include "BlockParser.h"
#include "DeclarationsParser.h"
#include "StatementParser.h"
#include "../PascalParserTD.h"
#include "../../../frontend/pascal/PascalError.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::frontend::pascal::parsers;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

BlockParser::BlockParser(PascalParserTD *parent) : PascalParserTD(parent)
{
}

ICodeNode *BlockParser::parse_block(Token *token, SymTabEntry *routine_id)
    throw (string)
{
    DeclarationsParser declarations_parser(this);
    StatementParser statement_parser(this);

    // Parse any declarations.
    declarations_parser.parse_declaration(token);

    token = synchronize(StatementParser::STMT_START_SET);
    TokenType token_type = token->get_type();
    ICodeNode *root_node = nullptr;

    // Look for the BEGIN token to parse a compound statement.
    if (token_type == (TokenType) PT_BEGIN)
    {
        root_node = statement_parser.parse_statement(token);
    }

    // Missing BEGIN: Attempt to parse anyway if possible.
    else {
        error_handler.flag(token, MISSING_BEGIN, this);

        if (StatementParser::STMT_START_SET.find((PascalTokenType) token_type)
                != StatementParser::STMT_START_SET.end())
        {
            root_node = ICodeFactory::create_icode_node(
                                            (ICodeNodeType) NT_COMPOUND);
            statement_parser.parse_list(token, root_node,
                                        PT_END, MISSING_END);
        }
    }

    return root_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
