#include "Token.hpp"



/// Token:: protected static members
const map <const string, const TokenType> Token::keywords = 
{

};

const map <const string, const TokenType> Token::symbols = 
{

};

const map <const TokenType, const string> Token::symbol_names = 
{

};

Token::Token(Parser * parser)
{
    parser     = parser;
    type       = first_invalid;
    text       = "";
    line_num   = parser->get_line_num();
    column_num = parser->get_column_num();
}

Token::Token(const Token &rhs)
{
    parser     = rhs.parser;
    type       = rhs.type;
    text       = rhs.text;
    line_num   = rhs.line_num;
    column_num = rhs.column_num;
}

TokenType Token::get_type(void) const
{
    return type;
}

string Token::get_text(void) const
{
    return text;
}

uint32_t Token::get_line_num(void) const
{
    return line_num;
}

uint32_t Token::get_column_num(void) const
{
    return column_num;
}