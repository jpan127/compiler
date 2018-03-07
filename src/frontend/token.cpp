#include "Token.hpp"
#include "Parser.hpp"



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

Token::Token(void)
{
    type       = first_invalid;
    text       = "";
    line_num   = Parser::instance().get_line_num();
    column_num = Parser::instance().get_column_num();
}

Token::Token(const Token &rhs)
{
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