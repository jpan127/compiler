#pragma once

#include "../Parser.h"
#include "../Scanner.h"
#include "JavaErrorHandler.hpp"

namespace wci::frontend::java 
{

    using namespace std;
    using namespace wci::frontend;

    class JavaParserTD : public Parser
    {
    public:

        /**
         * Constructor.
         * @param scanner the scanner to be used with this parser.
         */
        JavaParserTD(Scanner *scanner);

        /**
         * Constructor for subclasses.
         * @param parent the parent parser.
         */
        JavaParserTD(JavaParserTD *parent);

        /**
         * Parse a Java source program and generate the symbol table
         * and the intermediate code.
         * Implementation of wci::frontend::Parser.
         * @throw a string message if an error occurred.
         */
        void parse();

        /**
         * Return the number of syntax errors found by the parser.
         * Implementation of wci::frontend::Parser.
         * @return the error count.
         */
        int get_error_count() const;

    protected:

        static JavaErrorHandler error_handler;
    };

} /// namespace wci::frontend::java
