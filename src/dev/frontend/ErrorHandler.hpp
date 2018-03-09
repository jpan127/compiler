#pragma once

#include <map>

#include "globals.hpp"



/// An enum class for each possible error code
enum class ErrorCode
{
    first_invalid = 0,

    /// Parsing errors
    parser_invalid_state,       ///< Parser error, code is in some state it never should be in
    invalid_character,          ///< Found a character that is not supported
    error_parsing_fpoint,       ///< Found a wrong symbol or invalid floating point syntax

    /// Execution errors
    uninitialized_variable,
    division_by_zero,

};

/**
 *  Responsible for notifying errors properly depending on the type
 *  Counts the number of errors that passes through and aborts compilation after a threshold
 *  @note : This is an abstract base class
 */

class ErrorHandler
{
protected:

    /**
     *  Constructor
     *  @param threshold : Maximum errors
     */
    ErrorHandler(uint32_t threshold=10) : threshold(threshold)
    {
        error_count = 0;
    }

    /// Virtual destructor
    virtual ~ ErrorHandler(void) { }

    /// Returns the current number of errors
    uint32_t get_error_count(void) const
    {
        return error_count;
    }

    /**
     *  Prints an error in a formatted style
     *  @param token : The token to print
     *  @param code  : The error code to print
     *  @note        : Pure virtual
     */
    virtual void print_error(Token * token, ErrorCode code) = 0;

    /// Current number of errors
    uint32_t error_count;

    /// Maximum errors this handler receives before terminating compilation
    const uint32_t threshold;

    /**
     *  A map to relate error codes to string messages
     *  @key   : The error code
     *  @value : The string explanation for the error
     */
    map <const ErrorCode, const string> error_messages;

};