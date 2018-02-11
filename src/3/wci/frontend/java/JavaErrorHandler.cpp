#include "JavaErrorHandler.hpp"

#include "../Token.h"
#include "../Parser.h"
#include "JavaError.hpp"
#include "../../message/Message.h"

namespace wci::frontend::java 
{

    using namespace std;
    using namespace wci::frontend;

    /// Static variables
    const int JavaErrorHandler::MAX_ERRORS = 25;
    int JavaErrorHandler::error_count = 0;

    int JavaErrorHandler::get_error_count() const
    {
        return error_count;
    }

    void JavaErrorHandler::flag(Token *token, JavaErrorCode error_code, Parser *parser)
    {
        // Notify the parser's listeners.
        string error_message = JavaError::error_messages[error_code];
        
        Message message(SYNTAX_ERROR,
                        LINE_NUMBER   , to_string(token->get_line_number()),
                        POSITION      , to_string(token->get_position()),
                        TOKEN_TEXT    , token->get_text(),
                        ERROR_MESSAGE , error_message);

        parser->send_message(message);

        if (++error_count > MAX_ERRORS)
        {
            abort_translation(JavaErrorCode::TOO_MANY_ERRORS, parser);
        }
    }

    void JavaErrorHandler::abort_translation(JavaErrorCode error_code, Parser *parser)
    {
        // Notify the parser's listeners and then abort.
        string error_message = "FATAL ERROR: " + JavaError::error_messages[error_code];

        Message message(SYNTAX_ERROR,
                        LINE_NUMBER, "0",
                        POSITION, "0",
                        TOKEN_TEXT, "",
                        ERROR_MESSAGE, error_message);
        
        parser->send_message(message);
        exit(-2);
    }

} /// namespace wci::frontend::java
