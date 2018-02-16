/**
 * <h1>PascalParserTD</h1>
 *
 * <p>The top-down Pascal parser.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_PASCAL_PASCALPARSERTD_H_
#define WCI_FRONTEND_PASCAL_PASCALPARSERTD_H_

#include "../Parser.h"
#include "../Scanner.h"
#include "PascalErrorHandler.h"

namespace wci { namespace frontend { namespace pascal {

using namespace std;
using namespace wci::frontend;

class PascalParserTD : public Parser
{
public:
    /**
     * Constructor.
     * @param scanner the scanner to be used with this parser.
     */
    PascalParserTD(Scanner *scanner);

    /**
     * Constructor for subclasses.
     * @param parent the parent parser.
     */
    PascalParserTD(PascalParserTD *parent);

    /**
     * Parse a Pascal source program and generate the symbol table
     * and the intermediate code.
     * Implementation of wci::frontend::Parser.
     * @throw a string message if an error occurred.
     */
    void parse() throw (string);

    /**
     * Return the number of syntax errors found by the parser.
     * Implementation of wci::frontend::Parser.
     * @return the error count.
     */
    int get_error_count() const;

protected:
    static PascalErrorHandler error_handler;
};

}}} // namespace wci::frontend::pascal


#endif /* WCI_FRONTEND_PASCAL_PASCALPARSERTD_H_ */
