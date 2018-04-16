/**
 * <h1>SubrangeTypeParser</h1>
 *
 * <p>Parse a Pascal subrange type specification.</p>
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

SubrangeTypeParser::SubrangeTypeParser(PascalParserTD *parent)
    : TypeSpecificationParser(parent)
{
}

TypeSpec *SubrangeTypeParser::parse_declaration(Token *token)
    throw (string)
{
    TypeSpec *subrange_typespec =
            TypeFactory::create_type((TypeForm) TypeFormImpl::SUBRANGE);

    int min, max;
    Object min_value = Object();  // empty
    Object max_value = Object();  // empty
    TypeSpec *min_typespec = nullptr;
    TypeSpec *max_typespec = nullptr;

    // Parse the minimum constant.
    ConstantDefinitionsParser constant_parser(this);
    Token *constant_token = new Token(*token);
    min_value = constant_parser.parse_constant(constant_token);

    // Set the minimum constant's type.
    if (constant_token->get_type() == (TokenType) PT_IDENTIFIER)
    {
        min_typespec = constant_parser.get_constant_type(constant_token);
    }
    else
    {
        min_typespec = constant_parser.get_constant_type(min_value);
    }

    min_value = check_value_type(constant_token, min_value, min_typespec);

    token = current_token();
    bool saw_dotdot = false;

    // Look for the .. token.
    if (token->get_type() == (TokenType) PT_DOT_DOT)
    {
        token = next_token(token);  // consume the .. token
        saw_dotdot = true;
    }

    // At the start of the maximum constant?
    if (ConstantDefinitionsParser::CONSTANT_START_SET.find(
            (PascalTokenType) token->get_type())
                 != ConstantDefinitionsParser::CONSTANT_START_SET.end())
    {
        if (!saw_dotdot)
        {
            error_handler.flag(token, MISSING_DOT_DOT, this);
        }

        // Parse the maximum constant.
        delete constant_token;
        constant_token = new Token(*token);
        max_value = constant_parser.parse_constant(constant_token);

        // Set the maximum constant's type.
        if (constant_token->get_type() == (TokenType) PT_IDENTIFIER)
        {
            max_typespec = constant_parser.get_constant_type(constant_token);
        }
        else
        {
            max_typespec = constant_parser.get_constant_type(max_value);
        }

        max_value = check_value_type(constant_token,
                                     max_value, max_typespec);

        // Are the min and max value types valid?
        if ((min_typespec == nullptr) || (max_typespec == nullptr))
        {
            error_handler.flag(constant_token, INCOMPATIBLE_TYPES, this);
        }

        // Are the min and max value types the same?
        else if (min_typespec != max_typespec)
        {
            error_handler.flag(constant_token, INCOMPATIBLE_TYPES, this);
        }

        // Min value > max value?
        else if ((!min_value.empty()) && (!max_value.empty()))
        {
            min = cast(min_value, int);
            max = cast(max_value, int);

            if (min >= max)
            {
                error_handler.flag(constant_token, MIN_GT_MAX, this);
            }
        }
    }
    else
    {
        error_handler.flag(constant_token, INVALID_SUBRANGE_TYPE, this);
    }

    subrange_typespec->set_attribute((TypeKey) SUBRANGE_BASE_TYPE,
                                     min_typespec);
    subrange_typespec->set_attribute((TypeKey) SUBRANGE_MIN_VALUE, min);
    subrange_typespec->set_attribute((TypeKey) SUBRANGE_MAX_VALUE, max);

    delete constant_token;
    return subrange_typespec;
}

Object SubrangeTypeParser::check_value_type(
                 Token *token, Object data_value, TypeSpec *typespec)
{
    if (typespec == nullptr)
    {
        return data_value;
    }
    if (typespec == Predefined::integer_type)
    {
        return data_value;
    }
    else if (typespec == Predefined::char_type)
    {
        char ch = cast(data_value, string)[0];
        return (int) ch;
    }
    else if (typespec->get_form() == (TypeForm) TypeFormImpl::ENUMERATION)
    {
        return data_value;
    }
    else
    {
        error_handler.flag(token, INVALID_SUBRANGE_TYPE, this);
        return data_value;
    }
}

}}}}  // namespace wci::frontend::pascal::parsers
