/**
 * <h1>TypeSpecificationParser</h1>
 *
 * <p>Parse a Pascal type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef TYPESPECIFICATIONPARSER_H_
#define TYPESPECIFICATIONPARSER_H_

#include <set>
#include "../PascalParserTD.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;

class TypeSpecificationParser : public PascalParserTD
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    TypeSpecificationParser(PascalParserTD *parent);

    /**
     * Parse a Pascal type specification.
     * @param token the current token.
     * @return the type specification.
     * @throw a string message if an error occurred.
     */
    TypeSpec *parse_declaration(Token *token) throw (string);

    /**
     * Initialize the synchronization set.
     */
    static void initialize();

    // Synchronization set for starting a type specification.
    static set<PascalTokenType> TYPE_START_SET;

private:
    static bool INITIALIZED;
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* TYPESPECIFICATIONPARSER_H_ */
