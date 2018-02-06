/**
 * <h1>PascalScanner</h1>
 *
 * <p>The Pascal scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_PASCAL_PASCALSCANNER_H_
#define WCI_FRONTEND_PASCAL_PASCALSCANNER_H_

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;
using namespace wci::frontend;

class PascalScanner : public Scanner
{
public:
    /**
     * Constructor
     * @param source the source to be used with this scanner.
     */
    PascalScanner(Source *source);

protected:
    /**
     * Extract and return the next Pascal token from the source.
     * @return the next token.
     * @throw a string message if an error occurred.
     */
    Token *extract_token() throw (string);
};

}}} // namespace wci::frontend::pascal

#endif /* WCI_FRONTEND_PASCAL_PASCALSCANNER_H_ */
