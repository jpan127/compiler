/**
 * <h1>SubrangeTypeParser</h1>
 *
 * <p>Parse a Pascal subrange type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef SUBRANGETYPEPARSER_H_
#define SUBRANGETYPEPARSER_H_

#include "TypeSpecificationParser.h"
#include "../../../intermediate/TypeSpec.h"
#include "../../../Object.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::intermediate;
using namespace wci::frontend::pascal;

class SubrangeTypeParser : public TypeSpecificationParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    SubrangeTypeParser(PascalParserTD *parent);

    /**
     * Parse a simple Pascal type specification.
     * @param token the current token.
     * @return the simple type specification.
     * @throw a string message if an error occurred.
     */
    TypeSpec *parse_declaration(Token *token) throw (string);

private:
    /**
     * Check a value of a type specification.
     * @param token the current token.
     * @param value the value.
     * @param typespec the type specifiction.
     * @return the value.
     */
    Object check_value_type(Token *token, Object data_value,
                            TypeSpec *typespec);
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* SUBRANGETYPEPARSER_H_ */
