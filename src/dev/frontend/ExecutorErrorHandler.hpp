#pragma once

#include "globals.hpp"
#include "ErrorHandler.hpp"



class ExecutorErrorHandler : public ErrorHandler
{
public:

    /// Constructor
    ExecutorErrorHandler(uint32_t threshold=10) : ErrorHandler(threshold)
    {
        // Initialize map
        error_messages = 
        {

        };
    }

    /// @TODO : Some unique way to print out errors that's more legible than how C++ does it
    ///         Python does it ok, but we can do better

    void print_error(Token * token, ErrorCode code)
    {
        // So if there are endless errors in the program, the compiler stops before freaking out and burying
        // the first offending errors
        if (++error_count >= threshold)
        {
            exit(EXIT_FAILURE);
        }
    }

    void print_error(ErrorCode code)
    {
        printf(">>>> %s\n", error_messages[code]);

        // So if there are endless errors in the program, the compiler stops before freaking out and burying
        // the first offending errors
        if (++error_count >= threshold)
        {
            exit(EXIT_FAILURE);
        }
    }

};
