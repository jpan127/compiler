#pragma once

/// Common STL includes
#include <iostream>
#include <fstream>
#include <exception>
#include <string>



/// Base class for custom exceptions
class CustomException : public std::exception
{
public:

    /// Prints the error message then exits the program
    void print_and_exit() const
    {
        std::cerr << "----------------------------------------------------------------" << std::endl
                  << "Exception : " << error                                            << std::endl
                  << "----------------------------------------------------------------" << std::endl << std::endl;
        exit(-1);
    }

    /// Overloading output stream operator to print the same as print_and_exit()
    friend std::ostream & operator << (std::ostream & out, const CustomException & e)
    {
        out << "----------------------------------------------------------------" << std::endl
            << "Exception : " << e.error                                          << std::endl
            << "----------------------------------------------------------------" << std::endl << std::endl;
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
#define DEFINE_CUSTOM_EXCEPTION(name)                                      \
    class name : public CustomException                                    \
    {                                                                      \
    public:                                                                \
        name(const std::string msg) : CustomException("["#name"] " + msg) { } \
    }

/// @ { Custom exception classes
DEFINE_CUSTOM_EXCEPTION(InvalidCase);
DEFINE_CUSTOM_EXCEPTION(FileOpenError);
DEFINE_CUSTOM_EXCEPTION(InvalidOperator);
DEFINE_CUSTOM_EXCEPTION(MissingSymbol);
DEFINE_CUSTOM_EXCEPTION(InvalidType);
DEFINE_CUSTOM_EXCEPTION(AntlrParsedIncorrectly);
DEFINE_CUSTOM_EXCEPTION(CompilerError);
DEFINE_CUSTOM_EXCEPTION(MissingArgument);
/// @ }
