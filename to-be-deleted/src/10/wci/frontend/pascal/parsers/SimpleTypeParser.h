/**
 * <h1>SimpleTypeParser</h1>
 *
 * <p>Parse a simple Pascal type (identifier, subrange, enumeration)
 * specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef SIMPLETYPEPARSER_H_
#define SIMPLETYPEPARSER_H_

#include <set>
#include "TypeSpecificationParser.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;

class SimpleTypeParser : public TypeSpecificationParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    SimpleTypeParser(PascalParserTD *parent);

    /**
     * Parse a simple Pascal type specification.
     * @param token the current token.
     * @return the simple type specification.
     * @throw a string message if an error occurred.
     */
    TypeSpec *parse_declaration(Token *token) throw (string);

    // Synchronization set for starting a simple type specification.
    static set<PascalTokenType> SIMPLE_TYPE_START_SET;

    /**
     * Initialize the synchronization set.
     */
    static void initialize();

private:
    static bool INITIALIZED;
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* SIMPLETYPEPARSER_H_ */
