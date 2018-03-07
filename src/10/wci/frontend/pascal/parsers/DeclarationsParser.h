/**
 * <h1>DeclarationsParser</h1>
 *
 * <p>Parse Pascal declarations.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef DECLARATIONSPARSER_H_
#define DECLARATIONSPARSER_H_

#include <string>
#include <set>
#include "../PascalParserTD.h"
#include "../../../frontend/Token.h"
#include "../../../frontend/pascal/PascalToken.h"
#include "../../../intermediate/TypeSpec.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class DeclarationsParser : public PascalParserTD
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    DeclarationsParser(PascalParserTD *parent);

    /**
     * Parse a declaration.
     * To be overridden by the specialized declarations parser subclasses.
     * @param token the initial token.
     * @throw a string message if an error occurred.
     */
    void parse_declaration(Token *token) throw (string);

    // Synchronization set for starting a variable declaration.
    static set<PascalTokenType> VAR_START_SET;

    /**
     * Initialize the synchronization set.
     */
    static void initialize();

protected:
    // Synchronization set for starting a declaration.
    static set<PascalTokenType> DECLARATION_START_SET;

    // Synchronization set for starting a type definition.
    static set<PascalTokenType> TYPE_START_SET;

    // Synchronization set for starting a procedure or function.
    static set<PascalTokenType> ROUTINE_START_SET;

    static bool INITIALIZED;
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* DECLARATIONSPARSER_H_ */
