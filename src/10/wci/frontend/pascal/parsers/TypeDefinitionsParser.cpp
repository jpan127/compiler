/**
 * <h1>TypeDefinitionsParser</h1>
 *
 * <p>Parse Pascal type definitions.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <set>
#include "TypeDefinitionsParser.h"
#include "DeclarationsParser.h"
#include "ConstantDefinitionsParser.h"
#include "../../../frontend/Token.h"
#include "../../../frontend/pascal/PascalToken.h"
#include "../../../frontend/pascal/PascalError.h"
#include "../../../frontend/pascal/parsers/TypeSpecificationParser.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/TypeFactory.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../../../intermediate/symtabimpl/Predefined.h"
#include "../../../Object.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

bool TypeDefinitionsParser::INITIALIZED = false;

set<PascalTokenType> TypeDefinitionsParser::IDENTIFIER_SET;
set<PascalTokenType> TypeDefinitionsParser::EQUALS_SET;
set<PascalTokenType> TypeDefinitionsParser::NEXT_START_SET;

set<PascalTokenType> TypeDefinitionsParser::FOLLOW_SET =
{
    PT_SEMICOLON,
};

/**
 * Initialize the synchronization set.
 */
void TypeDefinitionsParser::initialize()
{
    if (INITIALIZED) return;

    IDENTIFIER_SET = DeclarationsParser::VAR_START_SET;
    IDENTIFIER_SET.insert(PT_IDENTIFIER);

    ConstantDefinitionsParser::initialize();
    EQUALS_SET = ConstantDefinitionsParser::CONSTANT_START_SET;
    EQUALS_SET.insert(PT_EQUALS);
    EQUALS_SET.insert(PT_SEMICOLON);

    NEXT_START_SET = DeclarationsParser::VAR_START_SET;
    NEXT_START_SET.insert(PT_SEMICOLON);
    NEXT_START_SET.insert(PT_IDENTIFIER);

    INITIALIZED = true;
}

TypeDefinitionsParser::TypeDefinitionsParser(PascalParserTD *parent)
    : DeclarationsParser(parent)
{
    initialize();
}

void TypeDefinitionsParser::parse_declaration(Token *token) throw (string)
{
    token = synchronize(IDENTIFIER_SET);

    // Loop to parse a sequence of type definitions
    // separated by semicolons.
    while (token->get_type() == (TokenType) PT_IDENTIFIER)
    {
        string name = to_lower(token->get_text());
        SymTabEntry *type_id = symtab_stack->lookup_local(name);

        // Enter the new identifier into the symbol table
        // but don't set how it's defined yet.
        if (type_id == nullptr)
        {
            type_id = symtab_stack->enter_local(name);
            type_id->append_line_number(token->get_line_number());
        }
        else
        {
            error_handler.flag(token, IDENTIFIER_REDEFINED, this);
            type_id = nullptr;
        }

        token = next_token(token);  // consume the identifier token

        // Synchronize on the = token.
        token = synchronize(EQUALS_SET);
        if (token->get_type() == (TokenType) PT_EQUALS)
        {
            token = next_token(token);  // consume the =
        }
        else {
            error_handler.flag(token, MISSING_EQUALS, this);
        }

        // Parse the type specification.
        TypeSpecificationParser type_specification_parser(this);
        TypeSpec *typespec = type_specification_parser.parse_declaration(token);

        // Set identifier to be a type and set its type specificationt.
        if (type_id != nullptr)
        {
            type_id->set_definition((Definition) DF_TYPE);
        }

        // Cross-link the type identifier and the type specification.
        if ((typespec != nullptr) && (type_id != nullptr))
        {
            if (typespec->get_identifier() == nullptr)
            {
                typespec->set_identifier(type_id);
            }
            type_id->set_typespec(typespec);
        }
        else
        {
            token = synchronize(FOLLOW_SET);
        }

        token = current_token();

        // Look for one or more semicolons after a definition.
        if (token->get_type() == (TokenType) PT_SEMICOLON)
        {
            while (token->get_type() == (TokenType) PT_SEMICOLON)
            {
                token = next_token(token);  // consume the ;
            }
        }

        // If at the start of the next definition or declaration,
        // then missing a semicolon.
        else if (NEXT_START_SET.find((PascalTokenType) token->get_type())
                   != NEXT_START_SET.end())
        {
            error_handler.flag(token, MISSING_SEMICOLON, this);
        }

        token = synchronize(IDENTIFIER_SET);
    }
}

}}}}  // namespace wci::frontend::pascal::parsers
