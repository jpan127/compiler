/**
 * <h1>Scanner</h1>
 *
 * <p>A language-independent framework class.  This abstract scanner class
 * will be implemented by language-specific subclasses.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "Scanner.h"
#include "Source.h"
#include "Token.h"

namespace wci { namespace frontend {

using namespace std;

Scanner::Scanner(Source *source) : source(source), token(nullptr)
{
}

Scanner::~Scanner()
{
}

Token *Scanner::current_token() { return token; }

Token *Scanner::next_token(Token *prev_token)
{
    if (prev_token != nullptr) delete prev_token;
    token = extract_token();
    return token;
}

char Scanner::current_char()
{
    return source->current_char();
}

char Scanner::next_char()
{
    return source->next_char();
}

int Scanner::get_position()
{
    return source->get_position();
}

}} // namespace wci::frontend
