#pragma once

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"

namespace wci::frontend::java
{

using namespace std;;
using namespace wci::frontend;

class JavaScanner : public Scanner
{
public:

    JavaScanner(Source *source);

protected:

    Token * get_next_token();

private:

    enum class scanner_state_E
    {
        ignoring_characters,
        ending_asterisk,
    };

    void ignore_all_whitespaces();
};

} /// wci::frontend::java