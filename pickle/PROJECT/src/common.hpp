#pragma once

#include <iostream>
#include <fstream>
#include <exception>

class CustomException : public std::exception
{
public:
    CustomException(const std::string & msg) : error(msg) { }
    void print_and_exit() const
    {
        std::cerr << "----------------------------------------------------------------"
                  << std::endl
                  << "Exception : " 
                  << error 
                  << std::endl
                  << "----------------------------------------------------------------"
                  << std::endl
                  << std::endl;
        exit(-1);
    }
protected:
    const std::string error;
};

class InvalidCase : public CustomException
{
public:
    InvalidCase(const std::string msg) : CustomException("[InvalidCase] " + msg) { }
    friend std::ostream & operator << (std::ostream & out, const InvalidCase & e);
};

class FileOpenError : public CustomException
{
public:
    FileOpenError(const std::string msg) : CustomException("[FileOpenError] " + msg) { }
    friend std::ostream & operator << (std::ostream & out, const FileOpenError & e);
};

class InvalidOperator : public CustomException
{
public:
    InvalidOperator(const std::string msg) : CustomException("[InvalidOperator] " + msg) { }
    friend std::ostream & operator << (std::ostream & out, const InvalidOperator & e);
};

class MissingSymbol : public CustomException
{
public:
    MissingSymbol(const std::string msg) : CustomException("[MissingSymbol] " + msg) { }
    friend std::ostream & operator << (std::ostream & out, const MissingSymbol & e);
};

class InvalidType : public CustomException
{
public:
    InvalidType(const std::string msg) : CustomException("[InvalidType] " + msg) { }
    friend std::ostream & operator << (std::ostream & out, const InvalidType & e);
};

class AntlrParsedIncorrectly : public CustomException
{
public:
    AntlrParsedIncorrectly(const std::string msg) : CustomException("[AntlrParsedIncorrectly] " + msg) { }
    friend std::ostream & operator << (std::ostream & out, const AntlrParsedIncorrectly & e);
};

class CompilerError : public CustomException
{
public:
    CompilerError(const std::string msg) : CustomException("[CompilerError] " + msg) { }
    friend std::ostream & operator << (std::ostream & out, const CompilerError & e);
};
