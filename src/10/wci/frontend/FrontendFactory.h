/**
 * <h1>FrontendFactory</h1>
 *
 * <p>A factory class that creates parsers for specific source languages.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_FRONTENDFACTORY_H_
#define WCI_FRONTEND_FRONTENDFACTORY_H_

#include <string>
#include "Parser.h"
#include "Source.h"

namespace wci { namespace frontend {

class FrontendFactory
{
public:
    /**
     * Create a parser.
     * @param language the name of the source language (e.g., "Pascal").
     * @param type the type of parser (e.g., "top-down").
     * @param source the source object.
     * @return the parser.
     * @throws a string message if an error occurred.
     */
    static Parser *create_parser(string language, string type,
                                 Source *source)
        throw (string);
};

}} // namespace wci::frontend

#endif /* WCI_FRONTEND_FRONTENDFACTORY_H_ */
