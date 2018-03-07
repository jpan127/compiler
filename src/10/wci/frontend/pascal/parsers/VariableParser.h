/**
 * <h1>VariableParser</h1>
 *
 * <p>Parse a Pascal variable.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef VARIABLEPARSER_H_
#define VARIABLEPARSER_H_

#include <string>
#include "StatementParser.h"
#include "../PascalParserTD.h"
#include "../../../frontend/Token.h"
#include "../../../intermediate/TypeSpec.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;

class VariableParser : public StatementParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    VariableParser(PascalParserTD *parent);

    /**
     * Parse a variable.
     * @param token the initial token.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_variable(Token *token) throw (string);

    /**
     * Parse a variable.
     * @param token the initial token.
     * @param variable_id the symbol table entry of the variable identifier.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_variable(Token *token, SymTabEntry *variable_id)
        throw (string);

private:
    // Synchronization set to start a subscript or a field.
    static set<PascalTokenType> SUBSCRIPT_FIELD_START_SET;

    // Synchronization set for the ] token.
    static set<PascalTokenType> RIGHT_BRACKET_SET;

    /**
     * Parse a set of comma-separated subscript expressions.
     * @param variable_typespec the type of the array variable.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_subscripts(TypeSpec *variable_typespec) throw (string);

    /**
     * Parse a record field.
     * @param variable_typespec the type of the record variable.
     * @return the root node of the generated parse tree.
     * @throw a string message if an error occurred.
     */
    ICodeNode *parse_field(TypeSpec *variable_typespec);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* VARIABLEPARSER_H_ */
