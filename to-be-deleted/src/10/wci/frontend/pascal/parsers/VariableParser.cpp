/**
 * <h1>VariableParser</h1>
 *
 * <p>Parse a Pascal variable.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <set>
#include "VariableParser.h"
#include "StatementParser.h"
#include "../PascalParserTD.h"
#include "../../pascal/PascalToken.h"
#include "../../pascal/PascalError.h"
#include "../../pascal/parsers/ExpressionParser.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../../../intermediate/symtabimpl/Predefined.h"
#include "../../../intermediate/typeimpl/TypeSpecImpl.h"
#include "../../../intermediate/typeimpl/TypeChecker.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::icodeimpl;
using namespace wci::intermediate::typeimpl;

set<PascalTokenType> VariableParser::SUBSCRIPT_FIELD_START_SET =
{
    PT_LEFT_BRACKET, PT_DOT,
};

set<PascalTokenType> VariableParser::RIGHT_BRACKET_SET =
{
    PT_RIGHT_BRACKET, PT_EQUALS, PT_SEMICOLON,
};

VariableParser::VariableParser(PascalParserTD *parent)
    : StatementParser(parent)
{
}

ICodeNode *VariableParser::parse_variable(Token *token) throw (string)
{
    // Look up the identifier in the symbol table stack.
    string name = to_lower(token->get_text());
    SymTabEntry *variable_id = symtab_stack->lookup(name);

cout << ">>> " << variable_id->get_name() << endl;

    // If not found, flag the error and enter the identifier
    // as an undefined identifier with an undefined type.
    if (variable_id == nullptr)
    {
        error_handler.flag(token, IDENTIFIER_UNDEFINED, this);
        variable_id = symtab_stack->enter_local(name);
        variable_id->set_definition((Definition) DF_UNDEFINED);
        variable_id->set_typespec(Predefined::undefined_type);
    }

    return parse_variable(token, variable_id);
}

ICodeNode *VariableParser::parse_variable(Token *token,
                                          SymTabEntry *variable_id)
    throw (string)
{
    // Check how the variable is defined.
    Definition defn = variable_id->get_definition();
    if (   (defn != (Definition) DF_VARIABLE)
        && (defn != (Definition) DF_VALUE_PARM)
        && (defn != (Definition) DF_VAR_PARM))
    {
        error_handler.flag(token, INVALID_IDENTIFIER_USAGE, this);
    }

    variable_id->append_line_number(token->get_line_number());

    ICodeNode *variable_node =
        ICodeFactory::create_icode_node((ICodeNodeType) NT_VARIABLE);
    variable_node->set_attribute((ICodeKey) ID, variable_id);

    token = next_token(token);  // consume the identifier

cout << "<<< " << token->get_text() << " " << PascalToken::token_to_string_map[(PascalTokenType)token->get_type()] << endl;

///////////// variable_typespec is wrong?
    // Parse array subscripts or record fields.
    TypeSpec *variable_typespec = variable_id->get_typespec();


    while (SUBSCRIPT_FIELD_START_SET.find((PascalTokenType) token->get_type()) != SUBSCRIPT_FIELD_START_SET.end())
    {
        ICodeNode *sub_fld_node = NULL;

        if (token->get_type() == (TokenType)PT_LEFT_BRACKET)
        {
            sub_fld_node = parse_subscripts(variable_typespec);
        }
        else
        {
            sub_fld_node = parse_field(variable_typespec);
        }

        token = current_token();

        // Update the variable's type.
        // The variable node adopts the SUBSCRIPTS or FIELD node.
        variable_typespec = sub_fld_node->get_typespec();
        variable_node->add_child(sub_fld_node);
    }

    variable_node->set_typespec(variable_typespec);
    return variable_node;
}

ICodeNode *VariableParser::parse_subscripts(TypeSpec *variable_typespec)
    throw (string)
{
    Token *token = current_token();
    ExpressionParser expression_parser(this);

    // Create a SUBSCRIPTS node.
    ICodeNode *subscripts_node =
        ICodeFactory::create_icode_node((ICodeNodeType) NT_SUBSCRIPTS);

    do {
        token = next_token(token);  // consume the [ or , token
        Token *expr_token = new Token(*token);

        // The current variable is an array.
        if (variable_typespec->get_form() == (TypeForm) TypeFormImpl::ARRAY)
        {
            // Parse the subscript expression.
            ICodeNode *expr_node = expression_parser.parse_statement(token);
            TypeSpec *expr_typespec =
                    expr_node != nullptr ? expr_node->get_typespec()
                                         : Predefined::undefined_type;

            // The subscript expression type must be assignment
            // compatible with the array index type.
            Object attribute =
                variable_typespec->get_attribute(
                                             (TypeKey) ARRAY_INDEX_TYPE);
            TypeSpec *index_typespec = cast(attribute, TypeSpec*);

            if (!TypeChecker::are_assignment_compatible(index_typespec,
                                                        expr_typespec))
            {
                error_handler.flag(expr_token, INCOMPATIBLE_TYPES, this);
            }

            // The SUBSCRIPTS node adopts the subscript expression tree.
            subscripts_node->add_child(expr_node);

            // Update the variable's type.
            attribute = variable_typespec->get_attribute(
                                           (TypeKey) ARRAY_ELEMENT_TYPE);
            variable_typespec = cast(attribute, TypeSpec*);
        }

        // Not an array type, so too many subscripts.
        else
        {
            error_handler.flag(token, TOO_MANY_SUBSCRIPTS, this);
            expression_parser.parse_statement(token);
        }

        delete expr_token;
        token = current_token();
    } while (token->get_type() == (TokenType) PT_COMMA);

    // Synchronize at the ] token.
    token = synchronize(RIGHT_BRACKET_SET);
    if (token->get_type() == (TokenType) PT_RIGHT_BRACKET)
    {
        token = next_token(token);  // consume the ] token
    }
    else {
        error_handler.flag(token, MISSING_RIGHT_BRACKET, this);
    }

    subscripts_node->set_typespec(variable_typespec);
    return subscripts_node;
}

ICodeNode *VariableParser::parse_field(TypeSpec *variable_typespec)
{
    // Create a FIELD node.
    ICodeNode *field_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_FIELD);

    Token *token = next_token(nullptr);  // consume the . token
    Token *field_token = current_token();

    TokenType token_type = token->get_type();
    TypeForm variable_form = variable_typespec->get_form();

    if (   (token_type == (TokenType) PT_IDENTIFIER)
        && (variable_form == (TypeForm) TypeFormImpl::RECORD))
    {
//////// Attribute is wrong
        Object attribute =
                variable_typespec->get_attribute((TypeKey) RECORD_SYMTAB);
        SymTab *symtab = cast(attribute, SymTab*);
        string name = to_lower(token->get_text());
        SymTabEntry *field_id = symtab->lookup(name);

        if (field_id != nullptr)
        {
            variable_typespec = field_id->get_typespec();
            field_id->append_line_number(token->get_line_number());

            // Set the field identifier's name.
            field_node->set_attribute((ICodeKey) ID, field_id);
        }
        else
        {
            error_handler.flag(field_token, INVALID_FIELD, this);
        }
    }
    else
    {
        error_handler.flag(field_token, INVALID_FIELD, this);
    }

    token = next_token(token);  // consume the field identifier

    field_node->set_typespec(variable_typespec);
    return field_node;
}

}}}}  // namespace wci::frontend::pascal::parsers
