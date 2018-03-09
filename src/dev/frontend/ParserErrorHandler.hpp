#pragma once

#include "globals.hpp"
#include "ErrorHandler.hpp"



/**
 *  Error handler for the parser
 *  @note : This class is a singleton
 */

class ParserErrorHandler : public ErrorHandler
{
public:

    /**
     *  Sole purpose is to print an error in the parser error way
     *  @param token : The token to print
     *  @param code  : The error code to print
     */
    void print_error(Token * token, ErrorCode code)
    {
        /// @TODO : Some unique way to print out errors that's more legible than how C++ does it
        ///         Python does it ok, but we can do better

        cout << ">>> Parser Error : " << token->get_text() << endl;

        // So if there are endless errors in the program, the compiler stops before freaking out and burying
        // the first offending errors
        if (++error_count >= threshold)
        {
            exit(EXIT_FAILURE);
        }
    }

    /// Instance getter
    static ParserErrorHandler & instance(void)
    {
        static ParserErrorHandler singleton;
        return singleton;
    }

    /// Deleted copy constructor
    ParserErrorHandler(const ParserErrorHandler & rhs) = delete;

    /// Deleted assignment operator
    ParserErrorHandler & operator == (const ParserErrorHandler & rhs) = delete;

private:

    /// Constructor
    ParserErrorHandler(uint32_t threshold=10) : ErrorHandler(threshold)
    {
        // Initialize map
        error_messages = 
        {
            { ErrorCode::error_parsing_fpoint, "Error parsing floating point number" },
        };
    }

};
