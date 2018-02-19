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
    SYNTAX_ERROR_MESSAGES[ALREADY_FORWARDED]       = "Already specified in FORWARD";
    SYNTAX_ERROR_MESSAGES[CASE_CONSTANT_REUSED]    = "CASE constant reused";
    SYNTAX_ERROR_MESSAGES[IDENTIFIER_REDEFINED]    = "Redefined identifier";
    SYNTAX_ERROR_MESSAGES[IDENTIFIER_UNDEFINED]    = "Undefined identifier";
    SYNTAX_ERROR_MESSAGES[INCOMPATIBLE_ASSIGNMENT] = "Incompatible assignment";
    SYNTAX_ERROR_MESSAGES[INCOMPATIBLE_TYPES]      = "Incompatible types";
    SYNTAX_ERROR_MESSAGES[INVALID_ASSIGNMENT]      = "Invalid assignment statement";
    SYNTAX_ERROR_MESSAGES[INVALID_CHARACTER]       = "Invalid character";
    SYNTAX_ERROR_MESSAGES[INVALID_CONSTANT]        = "Invalid constant";
    SYNTAX_ERROR_MESSAGES[INVALID_EXPONENT]        = "Invalid exponent";
    SYNTAX_ERROR_MESSAGES[INVALID_EXPRESSION]      = "Invalid expression";
    SYNTAX_ERROR_MESSAGES[INVALID_FIELD]           = "Invalid field";
    SYNTAX_ERROR_MESSAGES[INVALID_FRACTION]        = "Invalid fraction";
    SYNTAX_ERROR_MESSAGES[INVALID_IDENTIFIER_USAGE]= "Invalid identifier usage";
    SYNTAX_ERROR_MESSAGES[INVALID_INDEX_TYPE]      = "Invalid index type";
    SYNTAX_ERROR_MESSAGES[INVALID_NUMBER]          = "Invalid number";
    SYNTAX_ERROR_MESSAGES[INVALID_STATEMENT]       = "Invalid statement";
    SYNTAX_ERROR_MESSAGES[INVALID_SUBRANGE_TYPE]   = "Invalid subrange type";
    SYNTAX_ERROR_MESSAGES[INVALID_TARGET]          = "Invalid assignment target";
    SYNTAX_ERROR_MESSAGES[INVALID_TYPE]            = "Invalid type";
    SYNTAX_ERROR_MESSAGES[INVALID_VAR_PARM]        = "Invalid VAR parameter";
    SYNTAX_ERROR_MESSAGES[MIN_GT_MAX]              = "Min limit greater than max limit";
    SYNTAX_ERROR_MESSAGES[MISSING_BEGIN]           = "Missing BEGIN";
    SYNTAX_ERROR_MESSAGES[MISSING_COLON]           = "Missing :";
    SYNTAX_ERROR_MESSAGES[MISSING_COLON_EQUALS]    = "Missing :=";
    SYNTAX_ERROR_MESSAGES[MISSING_COMMA]           = "Missing ,";
    SYNTAX_ERROR_MESSAGES[MISSING_CONSTANT]        = "Missing constant";
    SYNTAX_ERROR_MESSAGES[MISSING_DO]              = "Missing DO";
    SYNTAX_ERROR_MESSAGES[MISSING_DOT_DOT]         = "Missing ..";
    SYNTAX_ERROR_MESSAGES[MISSING_END]             = "Missing END";
    SYNTAX_ERROR_MESSAGES[MISSING_EQUALS]          = "Missing =";
    SYNTAX_ERROR_MESSAGES[MISSING_FOR_CONTROL]     = "Invalid FOR control variable";
    SYNTAX_ERROR_MESSAGES[MISSING_IDENTIFIER]      = "Missing identifier";
    SYNTAX_ERROR_MESSAGES[MISSING_LEFT_BRACKET]    = "Missing [";
    SYNTAX_ERROR_MESSAGES[MISSING_OF]              = "Missing OF";
    SYNTAX_ERROR_MESSAGES[MISSING_PERIOD]          = "Missing .";
    SYNTAX_ERROR_MESSAGES[MISSING_PROGRAM]         = "Missing PROGRAM";
    SYNTAX_ERROR_MESSAGES[MISSING_RIGHT_BRACKET]   = "Missing ]";
    SYNTAX_ERROR_MESSAGES[MISSING_RIGHT_PAREN]     = "Missing )";
    SYNTAX_ERROR_MESSAGES[MISSING_SEMICOLON]       = "Missing ;";
    SYNTAX_ERROR_MESSAGES[MISSING_THEN]            = "Missing THEN";
    SYNTAX_ERROR_MESSAGES[MISSING_TO_DOWNTO]       = "Missing TO or DOWNTO";
    SYNTAX_ERROR_MESSAGES[MISSING_UNTIL]           = "Missing UNTIL";
    SYNTAX_ERROR_MESSAGES[MISSING_VARIABLE]        = "Missing variable";
    SYNTAX_ERROR_MESSAGES[NOT_CONSTANT_IDENTIFIER] = "Not a constant identifier";
    SYNTAX_ERROR_MESSAGES[NOT_RECORD_VARIABLE]     = "Not a record variable";
    SYNTAX_ERROR_MESSAGES[NOT_TYPE_IDENTIFIER]     = "Not a type identifier";
    SYNTAX_ERROR_MESSAGES[RANGE_INTEGER]           = "Integer literal out of range";
    SYNTAX_ERROR_MESSAGES[RANGE_REAL]              = "Real literal out of range";
    SYNTAX_ERROR_MESSAGES[STACK_OVERFLOW]          = "Stack overflow";
    SYNTAX_ERROR_MESSAGES[TOO_MANY_LEVELS]         = "Nesting level too deep";
    SYNTAX_ERROR_MESSAGES[TOO_MANY_SUBSCRIPTS]     = "Too many subscripts";
    SYNTAX_ERROR_MESSAGES[UNEXPECTED_EOF]          = "Unexpected end of file";
    SYNTAX_ERROR_MESSAGES[UNEXPECTED_TOKEN]        = "Unexpected token";
    SYNTAX_ERROR_MESSAGES[UNIMPLEMENTED]           = "Unimplemented feature";
    SYNTAX_ERROR_MESSAGES[UNRECOGNIZABLE]          = "Unrecognizable input";
    SYNTAX_ERROR_MESSAGES[WRONG_NUMBER_OF_PARMS]   = "Wrong number of actual parameters";
    SYNTAX_ERROR_MESSAGES[IO_ERROR]                = "Object I/O error";
    SYNTAX_ERROR_MESSAGES[TOO_MANY_ERRORS]         = "Too many syntax errors";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SYNTAX_ERROR_MESSAGES[MISSING_WHEN]                  = "Missing WHEN";
    SYNTAX_ERROR_MESSAGES[MISSING_ALLOW]                 = "Missing =>";
    SYNTAX_ERROR_MESSAGES[MISSING_OTHERWISE]             = "Missing OTHERWISE";
    SYNTAX_ERROR_MESSAGES[WHEN_LHS_SHOULD_BE_CONDITION]  = "WHEN statements should have a boolean condition on the LHS of the allow '=>' operator";
    SYNTAX_ERROR_MESSAGES[WHEN_RHS_SHOULD_BE_ASSIGNMENT] = "WHEN statements should have an assignment statement on the RHS of the allow '=>' operator";
    SYNTAX_ERROR_MESSAGES[WHEN_SKIPPING_STATEMENT]       = "Error parsing a WHEN statement, skipping to next statement";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    INITIALIZED = true;
}

}}}  // namespace wci::frontend::pascal
