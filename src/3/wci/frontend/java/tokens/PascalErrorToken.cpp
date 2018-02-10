/**
 * <h1>PascalErrorToken</h1>
 *
 * <p>Pascal error token.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "PascalErrorToken.h"
#include "../../Token.h"
#include "../PascalToken.h"

namespace wci { namespace frontend { namespace pascal { namespace tokens {

using namespace std;
using namespace wci::frontend::pascal;

PascalErrorToken::PascalErrorToken(Source *source, PascalErrorCode error_code,
                                   string token_text)
    throw (string)
    : PascalToken(source)
{
    type = (TokenType) PT_ERROR;
    text = token_text;
    value = (int) error_code;
}

void PascalErrorToken::extract() throw (string)
{
    // do nothing
}

}}}}  // namespace wci::frontend::pascal::tokens
