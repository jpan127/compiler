#include "JavaError.hpp"

#include <string>
#include <vector>
#include <map>

#include "../../Globals.h"

namespace wci::frontend::java 
{

    using namespace std;

    /// JavaError static variables
    bool JavaError::is_initialized = false;
    map <const JavaErrorCode, string> JavaError::error_messages;

    /// Post Increment operator
    JavaErrorCode& operator++(JavaErrorCode& code, int)
    {
        code++;
        return code;
    }

    void JavaError::initialize()
    {
        if (!is_initialized)
        {
            error_messages[JavaErrorCode::ALREADY_FORWARDED]        = STRINGIFY(ALREADY_FORWARDED);
            error_messages[JavaErrorCode::CASE_CONSTANT_REUSED]     = STRINGIFY(CASE_CONSTANT_REUSED);
            error_messages[JavaErrorCode::IDENTIFIER_REDEFINED]     = STRINGIFY(IDENTIFIER_REDEFINED);
            error_messages[JavaErrorCode::IDENTIFIER_UNDEFINED]     = STRINGIFY(IDENTIFIER_UNDEFINED);
            error_messages[JavaErrorCode::INCOMPATIBLE_ASSIGNMENT]  = STRINGIFY(INCOMPATIBLE_ASSIGNMENT);
            error_messages[JavaErrorCode::INCOMPATIBLE_TYPES]       = STRINGIFY(INCOMPATIBLE_TYPES);
            error_messages[JavaErrorCode::INVALID_ASSIGNMENT]       = STRINGIFY(INVALID_ASSIGNMENT);
            error_messages[JavaErrorCode::INVALID_CHARACTER]        = STRINGIFY(INVALID_CHARACTER);
            error_messages[JavaErrorCode::INVALID_CONSTANT]         = STRINGIFY(INVALID_CONSTANT);
            error_messages[JavaErrorCode::INVALID_EXPONENT]         = STRINGIFY(INVALID_EXPONENT);
            error_messages[JavaErrorCode::INVALID_EXPRESSION]       = STRINGIFY(INVALID_EXPRESSION);
            error_messages[JavaErrorCode::INVALID_FIELD]            = STRINGIFY(INVALID_FIELD);
            error_messages[JavaErrorCode::INVALID_FRACTION]         = STRINGIFY(INVALID_FRACTION);
            error_messages[JavaErrorCode::INVALID_IDENTIFIER_USAGE] = STRINGIFY(INVALID_IDENTIFIER_USAGE);
            error_messages[JavaErrorCode::INVALID_INDEX_TYPE]       = STRINGIFY(INVALID_INDEX_TYPE);
            error_messages[JavaErrorCode::INVALID_NUMBER]           = STRINGIFY(INVALID_NUMBER);
            error_messages[JavaErrorCode::INVALID_STATEMENT]        = STRINGIFY(INVALID_STATEMENT);
            error_messages[JavaErrorCode::INVALID_SUBRANGE_TYPE]    = STRINGIFY(INVALID_SUBRANGE_TYPE);
            error_messages[JavaErrorCode::INVALID_TARGET]           = STRINGIFY(INVALID_TARGET);
            error_messages[JavaErrorCode::INVALID_TYPE]             = STRINGIFY(INVALID_TYPE);
            error_messages[JavaErrorCode::INVALID_VAR_PARM]         = STRINGIFY(INVALID_VAR_PARM);
            error_messages[JavaErrorCode::INVALID_STRING]           = STRINGIFY(INVALID_STRING);
            error_messages[JavaErrorCode::MIN_GT_MAX]               = STRINGIFY(MIN_GT_MAX);
            error_messages[JavaErrorCode::MISSING_BEGIN]            = STRINGIFY(MISSING_BEGIN);
            error_messages[JavaErrorCode::MISSING_COLON]            = STRINGIFY(MISSING_COLON);
            error_messages[JavaErrorCode::MISSING_COLON_EQUALS]     = STRINGIFY(MISSING_COLON_EQUALS);
            error_messages[JavaErrorCode::MISSING_COMMA]            = STRINGIFY(MISSING_COMMA);
            error_messages[JavaErrorCode::MISSING_CONSTANT]         = STRINGIFY(MISSING_CONSTANT);
            error_messages[JavaErrorCode::MISSING_DO]               = STRINGIFY(MISSING_DO);
            error_messages[JavaErrorCode::MISSING_DOT_DOT]          = STRINGIFY(MISSING_DOT_DOT);
            error_messages[JavaErrorCode::MISSING_END]              = STRINGIFY(MISSING_END);
            error_messages[JavaErrorCode::MISSING_EQUALS]           = STRINGIFY(MISSING_EQUALS);
            error_messages[JavaErrorCode::MISSING_FOR_CONTROL]      = STRINGIFY(MISSING_FOR_CONTROL);
            error_messages[JavaErrorCode::MISSING_IDENTIFIER]       = STRINGIFY(MISSING_IDENTIFIER);
            error_messages[JavaErrorCode::MISSING_LEFT_BRACKET]     = STRINGIFY(MISSING_LEFT_BRACKET);
            error_messages[JavaErrorCode::MISSING_OF]               = STRINGIFY(MISSING_OF);
            error_messages[JavaErrorCode::MISSING_PERIOD]           = STRINGIFY(MISSING_PERIOD);
            error_messages[JavaErrorCode::MISSING_PROGRAM]          = STRINGIFY(MISSING_PROGRAM);
            error_messages[JavaErrorCode::MISSING_RIGHT_BRACKET]    = STRINGIFY(MISSING_RIGHT_BRACKET);
            error_messages[JavaErrorCode::MISSING_RIGHT_PAREN]      = STRINGIFY(MISSING_RIGHT_PAREN);
            error_messages[JavaErrorCode::MISSING_SEMICOLON]        = STRINGIFY(MISSING_SEMICOLON);
            error_messages[JavaErrorCode::MISSING_THEN]             = STRINGIFY(MISSING_THEN);
            error_messages[JavaErrorCode::MISSING_TO_DOWNTO]        = STRINGIFY(MISSING_TO_DOWNTO);
            error_messages[JavaErrorCode::MISSING_UNTIL]            = STRINGIFY(MISSING_UNTIL);
            error_messages[JavaErrorCode::MISSING_VARIABLE]         = STRINGIFY(MISSING_VARIABLE);
            error_messages[JavaErrorCode::NOT_CONSTANT_IDENTIFIER]  = STRINGIFY(NOT_CONSTANT_IDENTIFIER);
            error_messages[JavaErrorCode::NOT_RECORD_VARIABLE]      = STRINGIFY(NOT_RECORD_VARIABLE);
            error_messages[JavaErrorCode::NOT_TYPE_IDENTIFIER]      = STRINGIFY(NOT_TYPE_IDENTIFIER);
            error_messages[JavaErrorCode::RANGE_INTEGER]            = STRINGIFY(RANGE_INTEGER);
            error_messages[JavaErrorCode::RANGE_REAL]               = STRINGIFY(RANGE_REAL);
            error_messages[JavaErrorCode::STACK_OVERFLOW]           = STRINGIFY(STACK_OVERFLOW);
            error_messages[JavaErrorCode::TOO_MANY_LEVELS]          = STRINGIFY(TOO_MANY_LEVELS);
            error_messages[JavaErrorCode::TOO_MANY_SUBSCRIPTS]      = STRINGIFY(TOO_MANY_SUBSCRIPTS);
            error_messages[JavaErrorCode::UNEXPECTED_EOF]           = STRINGIFY(UNEXPECTED_EOF);
            error_messages[JavaErrorCode::UNEXPECTED_EOS]           = STRINGIFY(UNEXPECTED_EOS);
            error_messages[JavaErrorCode::UNEXPECTED_TOKEN]         = STRINGIFY(UNEXPECTED_TOKEN);
            error_messages[JavaErrorCode::UNIMPLEMENTED]            = STRINGIFY(UNIMPLEMENTED);
            error_messages[JavaErrorCode::UNRECOGNIZABLE]           = STRINGIFY(UNRECOGNIZABLE);
            error_messages[JavaErrorCode::WRONG_NUMBER_OF_PARMS]    = STRINGIFY(WRONG_NUMBER_OF_PARMS);
            error_messages[JavaErrorCode::IO_ERROR]                 = STRINGIFY(IO_ERROR);
            error_messages[JavaErrorCode::TOO_MANY_ERRORS]          = STRINGIFY(TOO_MANY_ERRORS);

            is_initialized = true;        
        }
    }

}  /// namespace wci::frontend::java
