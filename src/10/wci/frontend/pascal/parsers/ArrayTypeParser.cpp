/**
 * <h1>ArrayTypeParser</h1>
 *
 * <p>Parse a Pascal array type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include <set>
#include "ArrayTypeParser.h"
#include "TypeSpecificationParser.h"
#include "ConstantDefinitionsParser.h"
#include "SimpleTypeParser.h"
#include "../PascalParserTD.h"
#include "../../../frontend/Token.h"
#include "../../../frontend/pascal/PascalToken.h"
#include "../../../frontend/pascal/PascalError.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/SymTabStack.h"
#include "../../../intermediate/symtabimpl/Predefined.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../../../intermediate/TypeFactory.h"
#include "../../../intermediate/typeimpl/TypeSpecImpl.h"
#include "../../../Object.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::frontend::pascal::parsers;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::typeimpl;

bool ArrayTypeParser::INITIALIZED = false;

set<PascalTokenType> ArrayTypeParser::LEFT_BRACKET_SET;
set<PascalTokenType> ArrayTypeParser::OF_SET;
set<PascalTokenType> ArrayTypeParser::INDEX_START_SET;
set<PascalTokenType> ArrayTypeParser::INDEX_FOLLOW_SET;

set<PascalTokenType> ArrayTypeParser::RIGHT_BRACKET_SET =
{
    PT_RIGHT_BRACKET, PT_OF, PT_SEMICOLON,
};

set<PascalTokenType> ArrayTypeParser::INDEX_END_SET =
{
    PT_RIGHT_BRACKET, PT_OF, PT_SEMICOLON,
};

void ArrayTypeParser::initialize()
{
    if (INITIALIZED) return;

    SimpleTypeParser::initialize();
    LEFT_BRACKET_SET = SimpleTypeParser::SIMPLE_TYPE_START_SET;
    LEFT_BRACKET_SET.insert(PT_LEFT_BRACKET);
    LEFT_BRACKET_SET.insert(PT_RIGHT_BRACKET);

    TypeSpecificationParser::initialize();
    OF_SET = TypeSpecificationParser::TYPE_START_SET;
    OF_SET.insert(PT_OF);
    OF_SET.insert(PT_SEMICOLON);

    SimpleTypeParser::initialize();
    INDEX_START_SET = SimpleTypeParser::SIMPLE_TYPE_START_SET;
    INDEX_START_SET.insert(PT_COMMA);

    INDEX_FOLLOW_SET = INDEX_START_SET;
    for (set<PascalTokenType>::iterator it = INDEX_END_SET.begin();
         it != INDEX_END_SET.end(); it++)
    {
        INDEX_FOLLOW_SET.insert(*it);
    }

    INITIALIZED = true;
}

ArrayTypeParser::ArrayTypeParser(PascalParserTD *parent)
    : TypeSpecificationParser(parent)
{
    initialize();
}

TypeSpec *ArrayTypeParser::parse_declaration(Token *token) throw (string)
{
    TypeSpec *array_typespec =
                           TypeFactory::create_type((TypeForm) TF_ARRAY);
    token = next_token(token);  // consume ARRAY

    // Synchronize at the [ token.
    token = synchronize(LEFT_BRACKET_SET);
    if (token->get_type() != (TokenType) PT_LEFT_BRACKET)
    {
        error_handler.flag(token, MISSING_LEFT_BRACKET, this);
    }

    // Parse the list of index types.
    TypeSpec *elmt_typespec = parse_index_type_list(token, array_typespec);

    // Synchronize at the ] token.
    token = synchronize(RIGHT_BRACKET_SET);
    if (token->get_type() == (TokenType) PT_RIGHT_BRACKET)
    {
        token = next_token(token);  // consume ]
    }
    else
    {
        error_handler.flag(token, MISSING_RIGHT_BRACKET, this);
    }

    // Synchronize at OF.
    token = synchronize(OF_SET);
    if (token->get_type() == (TokenType) PT_OF)
    {
        token = next_token(token);  // consume OF
    }
    else
    {
        error_handler.flag(token, MISSING_OF, this);
    }

    // Parse the element type.
    elmt_typespec->set_attribute((TypeKey) ARRAY_ELEMENT_TYPE,
                                 parse_element_type(token));

    return array_typespec;
}

TypeSpec *ArrayTypeParser::parse_index_type_list(Token *token,
                                                 TypeSpec *array_typespec)
    throw (string)
{
    TypeSpec *elmt_typespec = array_typespec;
    bool another_index = false;

    token = next_token(token);  // consume the [ token

    // Parse the list of index type specifications.
    do {
        another_index = false;

        // Parse the index type.
        token = synchronize(INDEX_START_SET);
        parse_index_type(token, elmt_typespec);

        // Synchronize at the , token.
        token = synchronize(INDEX_FOLLOW_SET);
        TokenType token_type = token->get_type();
        if (   (token_type != (TokenType) PT_COMMA)
            && (token_type != (TokenType) PT_RIGHT_BRACKET))
        {
            if (INDEX_START_SET.find((PascalTokenType) token_type)
                    != INDEX_START_SET.end())
            {
                error_handler.flag(token, MISSING_COMMA, this);
                another_index = true;
            }
        }

        // Create an ARRAY element type object
        // for each subsequent index type.
        else if (token_type == (TokenType) PT_COMMA)
        {
            TypeSpec *new_elmt_typespec =
                           TypeFactory::create_type((TypeForm) TF_ARRAY);
            elmt_typespec->set_attribute((TypeKey) ARRAY_ELEMENT_TYPE,
                                         new_elmt_typespec);
            elmt_typespec = new_elmt_typespec;

            token = next_token(token);  // consume the , token
            another_index = true;
        }
    } while (another_index);

    return elmt_typespec;
}

void ArrayTypeParser::parse_index_type(Token *token,
                                       TypeSpec *array_typespec)
        throw (string)
{
    SimpleTypeParser simple_type_parser(this);
    Token *index_token = new Token(*token);

    TypeSpec *index_typespec = simple_type_parser.parse_declaration(token);
    array_typespec->set_attribute((TypeKey) ARRAY_INDEX_TYPE,
                                  index_typespec);

    if (index_typespec == nullptr)
    {
        delete index_token;
        return;
    }

    TypeForm form = index_typespec->get_form();
    int count = 0;

    // Check the index type and set the element count.
    if (form == (TypeForm) TF_SUBRANGE)
    {
        Object min_type_value =
            index_typespec->get_attribute((TypeKey) SUBRANGE_MIN_VALUE);
        Object max_type_value =
            index_typespec->get_attribute((TypeKey) SUBRANGE_MAX_VALUE);

        if ((!min_type_value.empty()) && (!max_type_value.empty()))
        {
            int min_value = cast(min_type_value, int);
            int max_value = cast(max_type_value, int);
            count = max_value - min_value + 1;
        }
    }
    else if (form == (TypeForm) TF_ENUMERATION)
    {
        Object type_value =
            index_typespec->get_attribute((TypeKey) ENUMERATION_CONSTANTS);
        vector<SymTabEntry *> constants =
            cast(type_value, vector<SymTabEntry *>);
        count = constants.size();
    }
    else
    {
        error_handler.flag(index_token, INVALID_INDEX_TYPE, this);
    }

    array_typespec->set_attribute((TypeKey) ARRAY_ELEMENT_COUNT, count);
    delete index_token;
}

TypeSpec *ArrayTypeParser::parse_element_type(Token *token) throw (string)
{
    TypeSpecificationParser type_specification_parser(this);
    return type_specification_parser.parse_declaration(token);
}

}}}}  // namespace wci::frontend::pascal::parsers
