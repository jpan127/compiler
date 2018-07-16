#pragma once

/// Common STL includes
#include <iostream>
#include <fstream>
#include <exception>
#include <string>

#include "logger.hpp"



/// Base class for custom exceptions
class CustomException : public std::exception
{

private:

    std::string create_error_message(const std::string & error) const
    {
        const std::string message =
            "----------------------------------------------------------------\n"
            "Exception : " + error + "\n"
            "----------------------------------------------------------------\n";
        return message;
    }

public:

    /// Prints the error message then exits the program
    void print_and_exit() const
    {
        const auto logger = spdlog::get("logger");
        const std::string message = create_error_message(error);

        if (logger)
        {
            logger->error(message);
        }
        else
        {
            std::cerr << message;
        }

        std::terminate();
    }

    /// Overloading output stream operator to print the same as print_and_exit()
    friend std::ostream & operator << (std::ostream & out, const CustomException & e)
    {
        out << e.create_error_message(e.error);
        return out;
    }

protected:

    /**
     *  Protected constructor
     *  @param msg : Error message
     */
    CustomException(const std::string & msg) : error(msg) { }

    /// The error message explaining the exception
    const std::string error;

};

/**
 *  Helper macro for creating a new custom exception class
 *  It is too verbose for a declaration + definition that only varies from the class name
 *  @note : Purposely left out the semicolon so macro calls keep the semicolon
 */
#define DEFINE_CUSTOM_EXCEPTION(name)                                         \
    class name : public CustomException                                       \
    {                                                                         \
    public:                                                                   \
        name(const std::string msg) : CustomException("["#name"] " + msg) { } \
    }

/**
 *  Throws an exception but logs the function name too
 *  @note : Purposely left out the semicolon so macro calls keep the semicolon
 */
#define THROW_EXCEPTION(exception, message)                                 \
    throw exception(string(__PRETTY_FUNCTION__) + string(" : ") + message)

/// @ { Custom exception classes
DEFINE_CUSTOM_EXCEPTION(InvalidCase);
DEFINE_CUSTOM_EXCEPTION(FileOpenError);
DEFINE_CUSTOM_EXCEPTION(InvalidOperator);
DEFINE_CUSTOM_EXCEPTION(MissingSymbol);
DEFINE_CUSTOM_EXCEPTION(MissingFunction);
DEFINE_CUSTOM_EXCEPTION(InvalidType);
DEFINE_CUSTOM_EXCEPTION(AntlrParsedIncorrectly);
DEFINE_CUSTOM_EXCEPTION(CompilerError);
DEFINE_CUSTOM_EXCEPTION(MissingArgument);
/// @ }
