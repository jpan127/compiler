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

        Token * extract_token();

    private:

        enum class scanner_state_E
        {
            ignoring_characters,
            ending_asterisk,
        };

        void ignore_all_whitespaces(char &c);

        void find_next_token();
    };

} /// wci::frontend::java