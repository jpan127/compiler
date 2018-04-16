/**
 * <h1>BlockParser</h1>
 *
 * <p>Parse a Pascal block.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef BLOCKPARSER_H_
#define BLOCKPARSER_H_

#include <string>
#include <set>
#include "../PascalParserTD.h"
#include "../../../frontend/Token.h"
#include "../../../intermediate/ICodeNode.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;

class BlockParser : public PascalParserTD
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    BlockParser(PascalParserTD *parent);

    /**
     * Parse a block.
     * @param token the initial token.
     * @param routine_id the symbol table entry of the routine name.
     * @return the root node of the parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_block(Token *token, SymTabEntry *routine_id)
        throw (string);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* BLOCKPARSER_H_ */
