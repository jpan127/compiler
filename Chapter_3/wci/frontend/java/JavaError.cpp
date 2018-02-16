#include "JavaError.hpp"

#include <string>
#include <vector>
#include <map>

namespace wci::frontend::java {

using namespace std;

/// PascalError static variables
bool PascalError::is_initialized = false;
map <PascalErrorCode, string> PascalError::SYNTAX_ERROR_MESSAGES;

void PascalError::initialize()
{
    if (!is_initialized)
    {
        vector <JavaErrorCode> error_codes;

        for (JavaErrorCode code = JAVA_ERROR_CODE_FIRST_INVALID + 1; code < JAVA_ERROR_CODE_LAST_INVALID; code++)
        {
            error_codes.push_back(code);
        }

        vector <string> error_messages =
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

        is_initialized = true;        
    }
}

}  /// namespace wci::frontend::java
