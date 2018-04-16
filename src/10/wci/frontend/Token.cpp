/**
 * <h1>Token</h1>
 *
 * <p>The framework class that represents a token returned by the scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "Token.h"
#include "Source.h"

namespace wci { namespace frontend {

using namespace std;

Token::Token(Source *source) throw (string)
    : type((TokenType) 0), text(""), source(source),
      line_number(source->get_line_number()),
      position(source->get_position())
{
    value.clear();
}

Token::Token(const Token& orig) { *this = orig; }

Token::~Token()
{
}

TokenType Token::get_type() const { return type; }

string Token::get_text() const { return text; }

Object Token::get_value() { return value; }

int Token::get_line_number() const { return line_number; }

/**
 * Getter.
 * @return the position.
 */
int Token::get_position() const { return position; }

void Token::extract() throw (string)
{
    text = to_string(current_char());
    next_char();  // consume current character
}

char Token::current_char() const throw (string)
{
    return source->current_char();
}

char Token::next_char() const throw (string)
{
    return source->next_char();
}

char Token::peek_char() const throw (string)
{
    return source->peek_char();
}

}} // namespace wci::frontend
