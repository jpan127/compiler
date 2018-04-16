/**
 * <h1>EnumerationTypeParser</h1>
 *
 * <p>Parse a Pascal enumeration type specification.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef ENUMERATIONTYPEPARSER_H_
#define ENUMERATIONTYPEPARSER_H_

#include <vector>
#include <set>
#include "TypeSpecificationParser.h"
#include "../../../intermediate/TypeSpec.h"
#include "../../../intermediate/SymTabEntry.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class EnumerationTypeParser : public TypeSpecificationParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    EnumerationTypeParser(PascalParserTD *parent);

    /**
     * Parse a simple Pascal type specification.
     * @param token the current token.
     * @return the simple type specification.
     * @throw a string message if an error occurred.
     */
    TypeSpec *parse_declaration(Token *token) throw (string);

private:
    // Synchronization set to start an enumeration constant.
    static set<PascalTokenType> ENUM_CONSTANT_START_SET;

    // Synchronization set to follow an enumeration definition.
    static set<PascalTokenType> ENUM_DEFINITION_FOLLOW_SET;

    static bool INITIALIZED;

    /**
     * Initialize the synchronization set.
     */
    static void initialize();

    /**
     * Parse an enumeration identifier.
     * @param token the current token.
     * @param value the identifier's integer value (sequence number).
     * @param enum_typespec the enumeration type specification.
     * @param constants the array of symbol table entries for the
     * enumeration constants.
     * @throw a string message if an error occurred.
     */
    void parse_enumeration_identifier(Token *token, int value,
                                      TypeSpec *enum_typespec,
                                      vector<SymTabEntry *>& constants)
        throw (string);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* ENUMERATIONTYPEPARSER_H_ */
