/**
 * <h1>EnumerationTypeParser</h1>
 *
 * <p>Parse a Pascal enumeration type specification.</p>
 *
 * <p>Copyright (c) 2009 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <set>
#include "EnumerationTypeParser.h"
#include "TypeSpecificationParser.h"
#include "DeclarationsParser.h"
#include "../../../frontend/pascal/PascalError.h"
#include "../../../intermediate/TypeFactory.h"
#include "../../../intermediate/TypeSpec.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/typeimpl/TypeSpecImpl.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::intermediate;
using namespace wci::intermediate::typeimpl;
using namespace wci::intermediate::symtabimpl;

bool EnumerationTypeParser::INITIALIZED = false;

set<PascalTokenType> EnumerationTypeParser::ENUM_CONSTANT_START_SET =
{
    PT_IDENTIFIER, PT_COMMA,
};

set<PascalTokenType> EnumerationTypeParser::ENUM_DEFINITION_FOLLOW_SET;

void EnumerationTypeParser::initialize()
{
    if (INITIALIZED) return;

    ENUM_DEFINITION_FOLLOW_SET = DeclarationsParser::VAR_START_SET;
    ENUM_DEFINITION_FOLLOW_SET.insert(PT_RIGHT_PAREN);
    ENUM_DEFINITION_FOLLOW_SET.insert(PT_SEMICOLON);

    INITIALIZED = true;
}

EnumerationTypeParser::EnumerationTypeParser(PascalParserTD *parent)
    : TypeSpecificationParser(parent)
{
    initialize();
}

TypeSpec *EnumerationTypeParser::parse_declaration(Token *token)
    throw (string)
{
    TypeSpec *enum_typespec =
        TypeFactory::create_type((TypeForm) TypeFormImpl::ENUMERATION);
    int value = -1;
    vector<SymTabEntry *> constants;

    token = next_token(token);  // consume the opening (

    do {
        token = synchronize(ENUM_CONSTANT_START_SET);
        parse_enumeration_identifier(token, ++value, enum_typespec,
                                     constants);

        token = current_token();

        // Look for the comma.
        if (token->get_type() == (TokenType) PT_COMMA)
        {
            token = next_token(token);  // consume the comma

            if (ENUM_DEFINITION_FOLLOW_SET.find(
                                   (PascalTokenType) token->get_type())
                    != ENUM_DEFINITION_FOLLOW_SET.end())
            {
                error_handler.flag(token, MISSING_IDENTIFIER, this);
            }
        }
        else if (ENUM_CONSTANT_START_SET.find(
                                  (PascalTokenType) token->get_type())
                != ENUM_CONSTANT_START_SET.end())
        {
            error_handler.flag(token, MISSING_COMMA, this);
        }
    } while (ENUM_DEFINITION_FOLLOW_SET.find(
                                     (PascalTokenType) token->get_type())
                == ENUM_DEFINITION_FOLLOW_SET.end());

    // Look for the closing ).
    if (token->get_type() == (TokenType) PT_RIGHT_PAREN)
    {
        token = next_token(token);  // consume the )
    }
    else
    {
        error_handler.flag(token, MISSING_RIGHT_PAREN, this);
    }

    enum_typespec->set_attribute((TypeKey) ENUMERATION_CONSTANTS,
                                 constants);
    return enum_typespec;
}

void EnumerationTypeParser::parse_enumeration_identifier(
        Token *token, int value,
        TypeSpec *enum_typespec,
        vector<SymTabEntry *>& constants)
    throw (string)
{
    if (token->get_type() == (TokenType) PT_IDENTIFIER)
    {
        string name = to_lower(token->get_text());
        SymTabEntry *constant_id = symtab_stack->lookup_local(name);

        if (constant_id != nullptr)
        {
            error_handler.flag(token, IDENTIFIER_REDEFINED, this);
        }
        else
        {
            constant_id = symtab_stack->enter_local(name);
            constant_id->set_definition(
                                (Definition) DF_ENUMERATION_CONSTANT);
            constant_id->set_typespec(enum_typespec);
            constant_id->set_attribute(
                                (SymTabKey) CONSTANT_VALUE, value);
            constant_id->append_line_number(token->get_line_number());
            constants.push_back(constant_id);
        }

        token = next_token(token);  // consume the identifier
    }
    else
    {
        error_handler.flag(token, MISSING_IDENTIFIER, this);
    }
}

}}}}  // namespace wci::frontend::pascal::parsers
