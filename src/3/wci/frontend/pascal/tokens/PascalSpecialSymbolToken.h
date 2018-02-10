/**
 * <h1>PascalSpecialSymbolToken</h1>
 *
 * <p> Pascal special symbol tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_PASCAL_TOKENS_PASCALSPECIALSYMBOLTOKEN_H_
#define WCI_FRONTEND_PASCAL_TOKENS_PASCALSPECIALSYMBOLTOKEN_H_

#include <string>
#include "../PascalToken.h"

namespace wci { namespace frontend { namespace pascal { namespace tokens {

using namespace std;
using namespace wci::frontend::pascal;

class PascalSpecialSymbolToken : public PascalToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    PascalSpecialSymbolToken(Source *source) throw (string);

protected:
    /**
     * Extract a Pascal special symbol token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::pascal::tokens

#endif /* WCI_FRONTEND_PASCAL_TOKENS_PASCALSPECIALSYMBOLTOKEN_H_ */
