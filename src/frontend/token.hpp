#pragma once

#include "globals.hpp"



/// An enum class for all the potential types of tokens
enum class TokenType
{
    first_invalid = 0,

    identifier,
    integer,
    fpoint,
    string,
    symbol,
    error,
};

/// Contains information about an individual token, whether an identifier, number, symbol, etc.
/// @TODO : Evaluate if this should be an abstract base class
class Token
{
public:

    /**
     *  Constructor
     *  @param parser : Handle to the parser in which this class can use to parse the rest of the token
     */
    Token(Parser * parser);

    /// Copy constructor
    Token(const Token &rhs);

    /// Virtual destructor
    virtual ~Token(void);

    /// Returns the type of the token
    TokenType get_type(void) const;

    /// Returns the string value of the token
    string get_text(void) const;

    /// Returns the line number the token was found at
    uint32_t get_line_num(void) const;

    /// Returns the position the token was found at
    uint32_t get_column_num(void) const;

protected:

    /// Handle to the parser object
    Parser * parser;

    /// Type of token
    TokenType type;

    /// Text value of token
    string text;

    /// Line number token was found at
    uint32_t line_num;

    /// Column number token was found at
    uint32_t column_num;

    /**
     *  Map of reserved keywords 
     *  @key   : String of keyword
     *  @value : TokenType corresponding to keyword
     */
    static const map <const string, const TokenType> keywords;

    /**
     *  Map of symbols
     *  @key   : String of symbol
     *  @value : TokenType corresponding to the symbol
     */
    static const map <const string, const TokenType> symbols;

    /**
     *  Map of names of symbols
     *  @key   : TokenType corresponding to the symbol
     *  @value : Word description of the symbol
     */
    static const map <const TokenType, const string> symbol_names;

};
