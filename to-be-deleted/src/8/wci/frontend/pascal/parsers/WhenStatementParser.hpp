#pragma once

#include "StatementParser.h"
#include "../../Token.h"



namespace wci::frontend::pascal::parsers
{

class WhenStatementParser : public StatementParser
{
public:

    WhenStatementParser(PascalParserTD *parent);

    ICodeNode * parse_statement(Token * token);

private:

};

} /// wci::frontend::pascal::parsers