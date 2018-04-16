/**
 * <h1>PascalError</h1>
 *
 * <p>Pascal translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "PascalError.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;

bool PascalError::INITIALIZED = false;

map<PascalErrorCode, string> PascalError::SYNTAX_ERROR_MESSAGES;

void PascalError::initialize()
{
    if (INITIALIZED) return;

    vector<PascalErrorCode> error_codes =
    {
        PascalErrorCode::ALREADY_FORWARDED,
        PascalErrorCode::CASE_CONSTANT_REUSED,
        PascalErrorCode::IDENTIFIER_REDEFINED,
        PascalErrorCode::IDENTIFIER_UNDEFINED,
        PascalErrorCode::INCOMPATIBLE_ASSIGNMENT,
        PascalErrorCode::INCOMPATIBLE_TYPES,
        PascalErrorCode::INVALID_ASSIGNMENT,
        PascalErrorCode::INVALID_CHARACTER,
        PascalErrorCode::INVALID_CONSTANT,
        PascalErrorCode::INVALID_EXPONENT,
        PascalErrorCode::INVALID_EXPRESSION,
        PascalErrorCode::INVALID_FIELD,
        PascalErrorCode::INVALID_FRACTION,
        PascalErrorCode::INVALID_IDENTIFIER_USAGE,
        PascalErrorCode::INVALID_INDEX_TYPE,
        PascalErrorCode::INVALID_NUMBER,
        PascalErrorCode::INVALID_STATEMENT,
        PascalErrorCode::INVALID_SUBRANGE_TYPE,
        PascalErrorCode::INVALID_TARGET,
        PascalErrorCode::INVALID_TYPE,
        PascalErrorCode::INVALID_VAR_PARM,
        PascalErrorCode::MIN_GT_MAX,
        PascalErrorCode::MISSING_BEGIN,
        PascalErrorCode::MISSING_COLON,
        PascalErrorCode::MISSING_COLON_EQUALS,
        PascalErrorCode::MISSING_COMMA,
        PascalErrorCode::MISSING_CONSTANT,
        PascalErrorCode::MISSING_DO,
        PascalErrorCode::MISSING_DOT_DOT,
        PascalErrorCode::MISSING_END,
        PascalErrorCode::MISSING_EQUALS,
        PascalErrorCode::MISSING_FOR_CONTROL,
        PascalErrorCode::MISSING_IDENTIFIER,
        PascalErrorCode::MISSING_LEFT_BRACKET,
        PascalErrorCode::MISSING_OF,
        PascalErrorCode::MISSING_PERIOD,
        PascalErrorCode::MISSING_PROGRAM,
        PascalErrorCode::MISSING_RIGHT_BRACKET,
        PascalErrorCode::MISSING_RIGHT_PAREN,
        PascalErrorCode::MISSING_SEMICOLON,
        PascalErrorCode::MISSING_THEN,
        PascalErrorCode::MISSING_TO_DOWNTO,
        PascalErrorCode::MISSING_UNTIL,
        PascalErrorCode::MISSING_VARIABLE,
        PascalErrorCode::NOT_CONSTANT_IDENTIFIER,
        PascalErrorCode::NOT_RECORD_VARIABLE,
        PascalErrorCode::NOT_TYPE_IDENTIFIER,
        PascalErrorCode::RANGE_INTEGER,
        PascalErrorCode::RANGE_REAL,
        PascalErrorCode::STACK_OVERFLOW,
        PascalErrorCode::TOO_MANY_LEVELS,
        PascalErrorCode::TOO_MANY_SUBSCRIPTS,
        PascalErrorCode::UNEXPECTED_EOF,
        PascalErrorCode::UNEXPECTED_TOKEN,
        PascalErrorCode::UNIMPLEMENTED,
        PascalErrorCode::UNRECOGNIZABLE,
        PascalErrorCode::WRONG_NUMBER_OF_PARMS,

        // Fatal errors.
        PascalErrorCode::IO_ERROR,
        PascalErrorCode::TOO_MANY_ERRORS
    };

    vector<string> error_messages =
    {
        "Already specified in FORWARD",
        "CASE constant reused",
        "Redefined identifier",
        "Undefined identifier",
        "Incompatible assignment",
        "Incompatible types",
        "Invalid assignment statement",
        "Invalid character",
        "Invalid constant",
        "Invalid exponent",
        "Invalid expression",
        "Invalid field",
        "Invalid fraction",
        "Invalid identifier usage",
        "Invalid index type",
        "Invalid number",
        "Invalid statement",
        "Invalid subrange type",
        "Invalid assignment target",
        "Invalid type",
        "Invalid VAR parameter",
        "Min limit greater than max limit",
        "Missing BEGIN",
        "Missing :",
        "Missing :=",
        "Missing ,",
        "Missing constant",
        "Missing DO",
        "Missing ..",
        "Missing END",
        "Missing =",
        "Invalid FOR control variable",
        "Missing identifier",
        "Missing [",
        "Missing OF",
        "Missing .",
        "Missing PROGRAM",
        "Missing ]",
        "Missing )",
        "Missing ;",
        "Missing THEN",
        "Missing TO or DOWNTO",
        "Missing UNTIL",
        "Missing variable",
        "Not a constant identifier",
        "Not a record variable",
        "Not a type identifier",
        "Integer literal out of range",
        "Real literal out of range",
        "Stack overflow",
        "Nesting level too deep",
        "Too many subscripts",
        "Unexpected end of file",
        "Unexpected token",
        "Unimplemented feature",
        "Unrecognizable input",
        "Wrong number of actual parameters",

        // Fatal errors.
        "Object I/O error",
        "Too many syntax errors"
    };

    for (int i = 0; i < error_codes.size(); i++)
    {
        SYNTAX_ERROR_MESSAGES[error_codes[i]] = error_messages[i];
    }

    INITIALIZED = true;
}

}}}  // namespace wci::frontend::pascal
