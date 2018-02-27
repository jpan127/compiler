/**
 * <h1>RuntimeError</h1>
 *
 * <p>Runtime error codes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef RUNTIMEERROR_H_
#define RUNTIMEERROR_H_

#include <string>
#include <map>

namespace wci { namespace backend { namespace interpreter {

using namespace std;

/**
 * Runtime error codes.
 */
enum class RuntimeErrorCode
{
    UNINITIALIZED_VALUE,
    VALUE_RANGE,
    INVALID_CASE_EXPRESSION_VALUE,
    DIVISION_BY_ZERO,
    INVALID_STANDARD_FUNCTION_ARGUMENT,
    INVALID_INPUT,
    STACK_OVERFLOW,
    UNIMPLEMENTED_FEATURE,
};

constexpr RuntimeErrorCode UNINITIALIZED_VALUE =
        RuntimeErrorCode::UNINITIALIZED_VALUE;
constexpr RuntimeErrorCode VALUE_RANGE =
        RuntimeErrorCode::VALUE_RANGE;
constexpr RuntimeErrorCode INVALID_CASE_EXPRESSION_VALUE =
        RuntimeErrorCode::INVALID_CASE_EXPRESSION_VALUE;
constexpr RuntimeErrorCode DIVISION_BY_ZERO =
        RuntimeErrorCode::DIVISION_BY_ZERO;
constexpr RuntimeErrorCode INVALID_STANDARD_FUNCTION_ARGUMENT =
        RuntimeErrorCode::INVALID_STANDARD_FUNCTION_ARGUMENT;
constexpr RuntimeErrorCode INVALID_INPUT =
        RuntimeErrorCode::INVALID_INPUT;
constexpr RuntimeErrorCode STACK_OVERFLOW =
        RuntimeErrorCode::STACK_OVERFLOW;
constexpr RuntimeErrorCode UNIMPLEMENTED_FEATURE =
        RuntimeErrorCode::UNIMPLEMENTED_FEATURE;

class RuntimeError
{
public:
    static map<RuntimeErrorCode, string> RUNTIME_ERROR_MESSAGES;

    /**
     * Initialize the static map.
     */
    static void initialize();

private:
    static bool INITIALIZED;
};

}}}  // wci::backend::interpreter

#endif /* RUNTIMEERROR_H_ */
