/**
 * <h1>ArrayTypeParser</h1>
 *
 * <p>Parse a Pascal array type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef ARRAYTYPEPARSER_H_
#define ARRAYTYPEPARSER_H_

#include <set>
#include "TypeSpecificationParser.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;

class ArrayTypeParser : public TypeSpecificationParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    ArrayTypeParser(PascalParserTD *parent);

    /**
     * Parse a simple Pascal type specification.
     * @param token the current token.
     * @return the simple type specification.
     * @throw a string message if an error occurred.
     */
    TypeSpec *parse_declaration(Token *token) throw (string);

private:
    // Synchronization set for the [ token.
    static set<PascalTokenType> LEFT_BRACKET_SET;

    // Synchronization set for the ] token.
    static set<PascalTokenType> RIGHT_BRACKET_SET;

    // Synchronization set for OF.
    static set<PascalTokenType> OF_SET;

    // Synchronization set to start an index type.
    static set<PascalTokenType> INDEX_START_SET;

    // Synchronization set to end an index type.
    static set<PascalTokenType> INDEX_END_SET;

    // Synchronization set to follow an index type.
    static set<PascalTokenType> INDEX_FOLLOW_SET;

    static bool INITIALIZED;

    /**
     * Initialize the synchronization set.
     */
    static void initialize();

    /**
     * Parse the list of index type specifications.
     * @param token the current token.
     * @param array_type the current array type specification.
     * @return the element type specification.
     * @throw a string message if an error occurred.
     */
    TypeSpec *parse_index_type_list(Token *token, TypeSpec *array_type)
        throw (string);

    /**
     * Parse an index type specification.
     * @param token the current token.
     * @param array_type the current array type specification.
     * @throw a string message if an error occurred.
     */
    void parse_index_type(Token *token, TypeSpec *array_type)
        throw (string);

    /**
     * Parse the element type specification.
     * @param token the current token.
     * @return the element type specification.
     * @throw a string message if an error occurred.
     */
    TypeSpec *parse_element_type(Token *token) throw (string);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* ARRAYTYPEPARSER_H_ */
