/**
 * <h1>PascalError</h1>
 *
 * <p>Pascal translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_PASCAL_PASCALERROR_H_
#define WCI_FRONTEND_PASCAL_PASCALERROR_H_

#include <string>
#include <map>

namespace wci { namespace frontend { namespace pascal {

using namespace std;

/**
 * Pascal error codes.
 */
enum class PascalErrorCode
{
    ALREADY_FORWARDED,
    CASE_CONSTANT_REUSED,
    IDENTIFIER_REDEFINED,
    IDENTIFIER_UNDEFINED,
    INCOMPATIBLE_ASSIGNMENT,
    INCOMPATIBLE_TYPES,
    INVALID_ASSIGNMENT,
    INVALID_CHARACTER,
    INVALID_CONSTANT,
    INVALID_EXPONENT,
    INVALID_EXPRESSION,
    INVALID_FIELD,
    INVALID_FRACTION,
    INVALID_IDENTIFIER_USAGE,
    INVALID_INDEX_TYPE,
    INVALID_NUMBER,
    INVALID_STATEMENT,
    INVALID_SUBRANGE_TYPE,
    INVALID_TARGET,
    INVALID_TYPE,
    INVALID_VAR_PARM,
    MIN_GT_MAX,
    MISSING_BEGIN,
    MISSING_COLON,
    MISSING_COLON_EQUALS,
    MISSING_COMMA,
    MISSING_CONSTANT,
    MISSING_DO,
    MISSING_DOT_DOT,
    MISSING_END,
    MISSING_EQUALS,
    MISSING_FOR_CONTROL,
    MISSING_IDENTIFIER,
    MISSING_LEFT_BRACKET,
    MISSING_OF,
    MISSING_PERIOD,
    MISSING_PROGRAM,
    MISSING_RIGHT_BRACKET,
    MISSING_RIGHT_PAREN,
    MISSING_SEMICOLON,
    MISSING_THEN,
    MISSING_TO_DOWNTO,
    MISSING_UNTIL,
    MISSING_VARIABLE,
    NOT_CONSTANT_IDENTIFIER,
    NOT_RECORD_VARIABLE,
    NOT_TYPE_IDENTIFIER,
    RANGE_INTEGER,
    RANGE_REAL,
    STACK_OVERFLOW,
    TOO_MANY_LEVELS,
    TOO_MANY_SUBSCRIPTS,
    UNEXPECTED_EOF,
    UNEXPECTED_TOKEN,
    UNIMPLEMENTED,
    UNRECOGNIZABLE,
    WRONG_NUMBER_OF_PARMS,

    // Fatal errors.
    IO_ERROR,
    TOO_MANY_ERRORS
};

constexpr PascalErrorCode ALREADY_FORWARDED = PascalErrorCode::ALREADY_FORWARDED;
constexpr PascalErrorCode CASE_CONSTANT_REUSED = PascalErrorCode::CASE_CONSTANT_REUSED;
constexpr PascalErrorCode IDENTIFIER_REDEFINED = PascalErrorCode::IDENTIFIER_REDEFINED;
constexpr PascalErrorCode IDENTIFIER_UNDEFINED = PascalErrorCode::IDENTIFIER_UNDEFINED;
constexpr PascalErrorCode INCOMPATIBLE_ASSIGNMENT = PascalErrorCode::INCOMPATIBLE_ASSIGNMENT;
constexpr PascalErrorCode INCOMPATIBLE_TYPES = PascalErrorCode::INCOMPATIBLE_TYPES;
constexpr PascalErrorCode INVALID_ASSIGNMENT = PascalErrorCode::INVALID_ASSIGNMENT;
constexpr PascalErrorCode INVALID_CHARACTER = PascalErrorCode::INVALID_CHARACTER;
constexpr PascalErrorCode INVALID_CONSTANT = PascalErrorCode::INVALID_CONSTANT;
constexpr PascalErrorCode INVALID_EXPONENT = PascalErrorCode::INVALID_EXPONENT;
constexpr PascalErrorCode INVALID_EXPRESSION = PascalErrorCode::INVALID_EXPRESSION;
constexpr PascalErrorCode INVALID_FIELD = PascalErrorCode::INVALID_FIELD;
constexpr PascalErrorCode INVALID_FRACTION = PascalErrorCode::INVALID_FRACTION;
constexpr PascalErrorCode INVALID_IDENTIFIER_USAGE = PascalErrorCode::INVALID_IDENTIFIER_USAGE;
constexpr PascalErrorCode INVALID_INDEX_TYPE = PascalErrorCode::INVALID_INDEX_TYPE;
constexpr PascalErrorCode INVALID_NUMBER = PascalErrorCode::INVALID_NUMBER;
constexpr PascalErrorCode INVALID_STATEMENT = PascalErrorCode::INVALID_STATEMENT;
constexpr PascalErrorCode INVALID_SUBRANGE_TYPE = PascalErrorCode::INVALID_SUBRANGE_TYPE;
constexpr PascalErrorCode INVALID_TARGET = PascalErrorCode::INVALID_TARGET;
constexpr PascalErrorCode INVALID_TYPE = PascalErrorCode::INVALID_TYPE;
constexpr PascalErrorCode INVALID_VAR_PARM = PascalErrorCode::INVALID_VAR_PARM;
constexpr PascalErrorCode MIN_GT_MAX = PascalErrorCode::MIN_GT_MAX;
constexpr PascalErrorCode MISSING_BEGIN = PascalErrorCode::MISSING_BEGIN;
constexpr PascalErrorCode MISSING_COLON = PascalErrorCode::MISSING_COLON;
constexpr PascalErrorCode MISSING_COMMA = PascalErrorCode::MISSING_COMMA;
constexpr PascalErrorCode MISSING_CONSTANT = PascalErrorCode::MISSING_CONSTANT;
constexpr PascalErrorCode MISSING_DO = PascalErrorCode::MISSING_DO;
constexpr PascalErrorCode MISSING_DOT_DOT = PascalErrorCode::MISSING_DOT_DOT;
constexpr PascalErrorCode MISSING_END = PascalErrorCode::MISSING_END;
constexpr PascalErrorCode MISSING_EQUALS = PascalErrorCode::MISSING_EQUALS;
constexpr PascalErrorCode MISSING_COLON_EQUALS = PascalErrorCode::MISSING_COLON_EQUALS;
constexpr PascalErrorCode MISSING_FOR_CONTROL = PascalErrorCode::MISSING_FOR_CONTROL;
constexpr PascalErrorCode MISSING_IDENTIFIER = PascalErrorCode::MISSING_IDENTIFIER;
constexpr PascalErrorCode MISSING_LEFT_BRACKET = PascalErrorCode::MISSING_LEFT_BRACKET;
constexpr PascalErrorCode MISSING_OF = PascalErrorCode::MISSING_OF;
constexpr PascalErrorCode MISSING_PERIOD = PascalErrorCode::MISSING_PERIOD;
constexpr PascalErrorCode MISSING_PROGRAM = PascalErrorCode::MISSING_PROGRAM;
constexpr PascalErrorCode MISSING_RIGHT_BRACKET = PascalErrorCode::MISSING_RIGHT_BRACKET;
constexpr PascalErrorCode MISSING_RIGHT_PAREN = PascalErrorCode::MISSING_RIGHT_PAREN;
constexpr PascalErrorCode MISSING_SEMICOLON = PascalErrorCode::MISSING_SEMICOLON;
constexpr PascalErrorCode MISSING_THEN = PascalErrorCode::MISSING_THEN;
constexpr PascalErrorCode MISSING_TO_DOWNTO = PascalErrorCode::MISSING_TO_DOWNTO;
constexpr PascalErrorCode MISSING_UNTIL = PascalErrorCode::MISSING_UNTIL;
constexpr PascalErrorCode MISSING_VARIABLE = PascalErrorCode::MISSING_VARIABLE;
constexpr PascalErrorCode NOT_CONSTANT_IDENTIFIER = PascalErrorCode::NOT_CONSTANT_IDENTIFIER;
constexpr PascalErrorCode NOT_RECORD_VARIABLE = PascalErrorCode::NOT_RECORD_VARIABLE;
constexpr PascalErrorCode NOT_TYPE_IDENTIFIER = PascalErrorCode::NOT_TYPE_IDENTIFIER;
constexpr PascalErrorCode RANGE_INTEGER = PascalErrorCode::RANGE_INTEGER;
constexpr PascalErrorCode RANGE_REAL = PascalErrorCode::RANGE_REAL;
constexpr PascalErrorCode STACK_OVERFLOW = PascalErrorCode::STACK_OVERFLOW;
constexpr PascalErrorCode TOO_MANY_LEVELS = PascalErrorCode::TOO_MANY_LEVELS;
constexpr PascalErrorCode TOO_MANY_SUBSCRIPTS = PascalErrorCode::TOO_MANY_SUBSCRIPTS;
constexpr PascalErrorCode UNEXPECTED_EOF = PascalErrorCode::UNEXPECTED_EOF;
constexpr PascalErrorCode UNEXPECTED_TOKEN = PascalErrorCode::UNEXPECTED_TOKEN;
constexpr PascalErrorCode UNIMPLEMENTED = PascalErrorCode::UNIMPLEMENTED;
constexpr PascalErrorCode UNRECOGNIZABLE = PascalErrorCode::UNRECOGNIZABLE;
constexpr PascalErrorCode WRONG_NUMBER_OF_PARMS = PascalErrorCode::WRONG_NUMBER_OF_PARMS;

constexpr PascalErrorCode IO_ERROR = PascalErrorCode::IO_ERROR;
constexpr PascalErrorCode TOO_MANY_ERRORS = PascalErrorCode::TOO_MANY_ERRORS;

class PascalError
{
public:
    static map<PascalErrorCode, string> SYNTAX_ERROR_MESSAGES;

    /**
     * Initialize the static map.
     */
    static void initialize();

private:
    static bool INITIALIZED;
};

}}}  // namespace wci::frontend::pascal

#endif /* WCI_FRONTEND_PASCAL_PASCALERROR_H_ */
