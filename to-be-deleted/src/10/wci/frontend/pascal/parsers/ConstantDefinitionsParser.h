/**
 * <h1>ConstantDefinitionsParser</h1>
 *
 * <p>Parse Pascal constant definitions.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef CONSTANTDEFINITIONSPARSER_H_
#define CONSTANTDEFINITIONSPARSER_H_

#include <string>
#include <set>
#include "DeclarationsParser.h"
#include "../PascalParserTD.h"
#include "../../../frontend/Token.h"
#include "../../../frontend/pascal/PascalToken.h"
#include "../../../Object.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;

class ConstantDefinitionsParser : public DeclarationsParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    ConstantDefinitionsParser(PascalParserTD *parent);

    /**
     * Parse a constant definition.
     * @param token the initial token.
     * @throw a string message if an error occurred.
     */
    void parse_declaration(Token *token) throw (string);

    /**
     * Parse a constant value.
     * @param token the current token.
     * @return the constant value.
     * @throw a string message if an error occurred.
     */
    Object parse_constant(Token *token) throw (string);

    /**
     * Parse an identifier constant.
     * @param token the current token.
     * @param minus_sign true if leading minus sign.
     * @return the constant value.
     * @throw a string message if an error occurred.
     */
    Object parse_identifier_constant(Token *token, const bool minus_sign)
        throw (string);

    /**
     * Return the type of a constant given its value.
     * @param data_value the constant value
     * @return the type specification.
     */
    TypeSpec *get_constant_type(Object data_value);

    /**
     * Return the type of a constant given its identifier.
     * @param identifier_token the constant's identifier token.
     * @return the type specification.
     */
    TypeSpec *get_constant_type(Token *id_token);

    // Synchronization set for starting a constant.
    static set<PascalTokenType> CONSTANT_START_SET;

    /**
     * Initialize the synchronization set.
     */
    static void initialize();

private:
    // Synchronization set for a constant identifier.
    static set<PascalTokenType> IDENTIFIER_SET;

    // Synchronization set for the = token.
    static set<PascalTokenType> EQUALS_SET;

    // Synchronization set for the start of the next definition or declaration.
    static set<PascalTokenType> NEXT_START_SET;

    static bool INITIALIZED;
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* CONSTANTDEFINITIONSPARSER_H_ */
