/**
 * <h1>RecordTypeParser</h1>
 *
 * <p>Parse a Pascal record type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <set>
#include "RecordTypeParser.h"
#include "DeclarationsParser.h"
#include "TypeSpecificationParser.h"
#include "VariableDeclarationsParser.h"
#include "../../../frontend/Token.h"
#include "../../../frontend/pascal/PascalToken.h"
#include "../../../frontend/pascal/PascalError.h"
#include "../../../intermediate/TypeFactory.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../../../intermediate/typeimpl/TypeSpecImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::typeimpl;

bool RecordTypeParser::INITIALIZED = false;

set<PascalTokenType> RecordTypeParser::END_SET;

void RecordTypeParser::initialize()
{
    if (INITIALIZED) return;

    DeclarationsParser::initialize();
    END_SET = DeclarationsParser::VAR_START_SET;
    END_SET.insert(PascalTokenType::END);
    END_SET.insert(PascalTokenType::SEMICOLON);

    INITIALIZED = true;
}

RecordTypeParser::RecordTypeParser(PascalParserTD *parent)
    : TypeSpecificationParser(parent)
{
    initialize();
}

TypeSpec *RecordTypeParser::parse_declaration(Token *token) throw (string)
{
cout << "!!!!! " << token->get_text() << endl;
    TypeSpec *record_typespec =
        TypeFactory::create_type((TypeForm) TypeFormImpl::RECORD);
    token = next_token(token);  // consume RECORD

    // Push a symbol table for the RECORD type specification.
    record_typespec->set_attribute((TypeKey) RECORD_SYMTAB,
                                   symtab_stack->push());

    // Parse the field declarations.
    VariableDeclarationsParser variable_declarations_parser(this);
    variable_declarations_parser.set_definition((Definition) DF_FIELD);
    variable_declarations_parser.parse_declaration(token);

    // Pop off the record's symbol table.
    symtab_stack->pop();

    // Synchronize at the END.
    token = synchronize(END_SET);

    // Look for the END.
    if (token->get_type() == (TokenType) PT_END)
    {
        token = next_token(token);  // consume END
    }
    else
    {
        error_handler.flag(token, MISSING_END, this);
    }

    return record_typespec;
}

}}}}  // namespace wci::frontend::pascal::parsers
