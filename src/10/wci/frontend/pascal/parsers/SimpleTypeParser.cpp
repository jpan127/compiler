/**
 * <h1>SimpleTypeParser</h1>
 *
 * <p>Parse a simple Pascal type (identifier, subrange, enumeration)
 * specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <set>
#include "SimpleTypeParser.h"
#include "EnumerationTypeParser.h"
#include "SubrangeTypeParser.h"
#include "TypeSpecificationParser.h"
#include "ConstantDefinitionsParser.h"
#include "../PascalParserTD.h"
#include "../../../frontend/Token.h"
#include "../../../frontend/pascal/PascalToken.h"
#include "../../../frontend/pascal/PascalError.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::frontend::pascal::parsers;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

bool SimpleTypeParser::INITIALIZED = false;

set<PascalTokenType> SimpleTypeParser::SIMPLE_TYPE_START_SET;

void SimpleTypeParser::initialize()
{
    if (INITIALIZED) return;

    ConstantDefinitionsParser::initialize();
    SIMPLE_TYPE_START_SET = ConstantDefinitionsParser::CONSTANT_START_SET;
    SIMPLE_TYPE_START_SET.insert(PascalTokenType::LEFT_PAREN);
    SIMPLE_TYPE_START_SET.insert(PascalTokenType::COMMA);
    SIMPLE_TYPE_START_SET.insert(PascalTokenType::SEMICOLON);

    INITIALIZED = true;
}

SimpleTypeParser::SimpleTypeParser(PascalParserTD *parent)
    : TypeSpecificationParser(parent)
{
    initialize();
}

TypeSpec *SimpleTypeParser::parse_declaration(Token *token) throw (string)
{
    // Synchronize at the start of a simple type specification.
    token = synchronize(SIMPLE_TYPE_START_SET);

// cout << "<<< " << token->get_text() << " " << PascalToken::token_to_string_map[(PascalTokenType)token->get_type()] << endl;
    
    switch ((PascalTokenType) token->get_type())
    {
        case PT_IDENTIFIER:
        {
            string name = to_lower(token->get_text());
            SymTabEntry *id = symtab_stack->lookup(name);

            if (id != nullptr)
            {
                Definition defn = id->get_definition();

                // It's either a type identifier
                // or the start of a subrange type.
                if (defn == (Definition) DF_TYPE)
                {
                    id->append_line_number(token->get_line_number());
                    token = next_token(token);  // consume the identifier

                    // Return the type of the referent type.
                    return id->get_typespec();
                }
                else if (   (defn != (Definition) DF_CONSTANT)
                         && (defn != (Definition) DF_ENUMERATION_CONSTANT))
                {
                    error_handler.flag(token, NOT_TYPE_IDENTIFIER, this);
                    token = next_token(token);  // consume the identifier
                    return nullptr;
                }
                else
                {
                    SubrangeTypeParser subrange_type_parser(this);
                    return subrange_type_parser.parse_declaration(token);
                }
            }
            else
            {
                error_handler.flag(token, IDENTIFIER_UNDEFINED, this);
                token = next_token(token);  // consume the identifier
                return nullptr;
            }
        }

        case PT_LEFT_PAREN:
        {
            EnumerationTypeParser enumeration_type_parser(this);
            return enumeration_type_parser.parse_declaration(token);
        }

        case PT_COMMA:
        case PT_SEMICOLON:
        {
            error_handler.flag(token, INVALID_TYPE, this);
            return nullptr;
        }

        default:
        {
            SubrangeTypeParser subrange_type_parser(this);
            return subrange_type_parser.parse_declaration(token);
        }
    }
}

}}}}  // namespace wci::frontend::pascal::parsers

