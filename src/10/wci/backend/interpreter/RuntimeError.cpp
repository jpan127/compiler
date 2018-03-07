/**
 * <h1>RuntimeError</h1>
 *
 * <p>Runtime error codes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "RuntimeError.h"

namespace wci { namespace backend { namespace interpreter {

using namespace std;

bool RuntimeError::INITIALIZED = false;

map<RuntimeErrorCode, string> RuntimeError::RUNTIME_ERROR_MESSAGES;

void RuntimeError::initialize()
{
    if (INITIALIZED) return;

    vector<RuntimeErrorCode> error_codes =
    {
        RuntimeErrorCode::UNINITIALIZED_VALUE,
        RuntimeErrorCode::VALUE_RANGE,
        RuntimeErrorCode::INVALID_CASE_EXPRESSION_VALUE,
        RuntimeErrorCode::DIVISION_BY_ZERO,
        RuntimeErrorCode::INVALID_STANDARD_FUNCTION_ARGUMENT,
        RuntimeErrorCode::INVALID_INPUT,
        RuntimeErrorCode::STACK_OVERFLOW,
        RuntimeErrorCode::UNIMPLEMENTED_FEATURE,
    };

    vector<string> error_messages =
    {
        "Uninitialized value",
        "Value out of range",
        "Invalid CASE expression value",
        "Division by zero",
        "Invalid standard function argument",
        "Invalid input",
        "Runtime stack overflow",
        "Unimplemented runtime feature",
    };

    for (int i = 0; i < error_codes.size(); i++)
    {
        RUNTIME_ERROR_MESSAGES[error_codes[i]] = error_messages[i];
    }

    INITIALIZED = true;
}

}}}  // wci::backend::interpreter
