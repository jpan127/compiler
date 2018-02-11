#pragma once

#include <string>
#include <map>

namespace wci::frontend::java 
{

    using namespace std;

    enum class JavaErrorCode
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
        INVALID_STRING,
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
        UNEXPECTED_EOS,
        UNEXPECTED_TOKEN,
        UNIMPLEMENTED,
        UNRECOGNIZABLE,
        WRONG_NUMBER_OF_PARMS,
        IO_ERROR,
        TOO_MANY_ERRORS,
    };

    class JavaError
    {
    public:

        static map <const JavaErrorCode, string> error_messages;

        /// Initialize error_messages
        static void initialize();

    private:

        static bool is_initialized;
    };

}  /// namespace wci::frontend::java
