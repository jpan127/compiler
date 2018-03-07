/**
 * <h1>RecordTypeParser</h1>
 *
 * <p>Parse a Pascal record type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef RECORDTYPEPARSER_H_
#define RECORDTYPEPARSER_H_

#include <set>
#include "TypeSpecificationParser.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;

class RecordTypeParser : public TypeSpecificationParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    RecordTypeParser(PascalParserTD *parent);

    /**
     * Parse a simple Pascal type specification.
     * @param token the current token.
     * @return the simple type specification.
     * @throw a string message if an error occurred.
     */
    TypeSpec *parse_declaration(Token *token) throw (string);

private:
    // Synchronization set for the END.
    static set<PascalTokenType> END_SET;

    static bool INITIALIZED;

    /**
     * Initialize the synchronization set.
     */
    static void initialize();
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* RECORDTYPEPARSER_H_ */
