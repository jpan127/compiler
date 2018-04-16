/**
 * <h1>TypeSpecificationParser</h1>
 *
 * <p>Parse a Pascal type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <set>
#include "TypeSpecificationParser.h"
#include "SimpleTypeParser.h"
#include "ArrayTypeParser.h"
#include "RecordTypeParser.h"
#include "../PascalParserTD.h"
#include "../../../frontend/Token.h"
#include "../../../frontend/pascal/PascalToken.h"
#include "../../../frontend/pascal/PascalError.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::frontend::pascal::parsers;
using namespace wci::intermediate;

bool TypeSpecificationParser::INITIALIZED = false;

set<PascalTokenType> TypeSpecificationParser::TYPE_START_SET;

void TypeSpecificationParser::initialize()
{
    if (INITIALIZED) return;

    SimpleTypeParser::initialize();
    TYPE_START_SET = SimpleTypeParser::SIMPLE_TYPE_START_SET;
    TYPE_START_SET.insert(PascalTokenType::ARRAY);
    TYPE_START_SET.insert(PascalTokenType::RECORD);
    TYPE_START_SET.insert(PascalTokenType::SEMICOLON);

    INITIALIZED = true;
}

/**
 * Constructor.
 * @param parent the parent parser.
 */
TypeSpecificationParser::TypeSpecificationParser(PascalParserTD *parent)
    : PascalParserTD(parent)
{
    initialize();
}

TypeSpec *TypeSpecificationParser::parse_declaration(Token *token) throw (string)
{
    // Synchronize at the start of a type specification.
    token = synchronize(TYPE_START_SET);

    switch ((PascalTokenType) token->get_type())
    {
        case PT_ARRAY:
        {
            ArrayTypeParser array_type_parser(this);
            return array_type_parser.parse_declaration(token);
        }

///////// This is NEVER set anywhere
        case PT_RECORD:
        {
cout << ">>> PT_RECORD : " << token->get_text() << " " << PascalToken::token_to_string_map[(PascalTokenType)token->get_type()] << endl;
            RecordTypeParser record_type_parser(this);
            return record_type_parser.parse_declaration(token);
        }

        default:
        {
cout << ">>> DEFAULT : '" << token->get_text() << "' " << PascalToken::token_to_string_map[(PascalTokenType)token->get_type()] << endl;
            SimpleTypeParser simple_type_parser(this);
            return simple_type_parser.parse_declaration(token);
        }
    }
}

}}}}  // namespace wci::frontend::pascal::parsers
