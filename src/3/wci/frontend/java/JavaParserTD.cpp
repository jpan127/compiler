#include "JavaParserTD.hpp"

#include <chrono>

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"
#include "JavaToken.hpp"
#include "JavaError.hpp"
#include "../../message/Message.h"

namespace wci::frontend::java 
{

    using namespace std;
    using namespace std::chrono;
    using namespace wci::frontend;
    using namespace wci::message;

    JavaErrorHandler JavaParserTD::error_handler;

    JavaParserTD::JavaParserTD(Scanner *scanner) : Parser(scanner)
    {
        JavaError::initialize();
    }

    JavaParserTD::JavaParserTD(JavaParserTD *parent) : Parser(parent->get_scanner())
    {
        /* Empty */
    }

    void JavaParserTD::parse()
    {
        Token *token = nullptr;
        int last_line_number = -1;
        const steady_clock::time_point start_time = steady_clock::now();

        // Loop over each token until the end of file.
        while ((token = next_token(token)) != nullptr)
        {
            TokenType token_type = token->get_type();
            last_line_number     = token->get_line_number();
            Object value         = token->get_value();

            string type_str;
            string value_str;

            switch (static_cast<JavaTokenType>(token_type))
            {
                case JavaTokenType::token_string      : type_str = "STRING";      value_str = CAST(value, string);            break;
                case JavaTokenType::token_identifier  : type_str = "IDENTIFIER";  value_str = "";                             break;
                case JavaTokenType::token_character   : type_str = "CHAR";        value_str = CAST(value, string);            break;
                case JavaTokenType::token_integer     : type_str = "INTEGER";     value_str = to_string(CAST(value, int));    break;
                case JavaTokenType::token_fpoint      : type_str = "REAL";        value_str = to_string(CAST(value, float));  break;
                case JavaTokenType::token_error       :                                                                       break;

                // reserved word or special character
                default:
                    // Reserved word
                    if (!value.empty())
                    {
                        type_str = value_str;
                        value_str = CAST(value, string);
                    }
                    // Special symbol
                    else
                    {
                        type_str = JavaToken::SPECIAL_SYMBOL_NAMES[static_cast <JavaTokenType> (token_type)];
                    }
                    break;
            }

            if (token_type != static_cast <TokenType> (JavaTokenType::token_error))
            {
                // Format and send a message about each token.
                Message message(TOKEN,
                                LINE_NUMBER , to_string(token->get_line_number()),
                                POSITION    , to_string(token->get_position()),
                                TOKEN_TYPE  , type_str,
                                TOKEN_TEXT  , token->get_text(),
                                TOKEN_VALUE , value_str);

                send_message(message);
            }
            else
            {
                // @TODO: Cast directly instead of double casting?
                JavaErrorCode error_code = (JavaErrorCode) CAST(value, int);
                error_handler.flag(token, error_code, this);
            }
        }

        // Send the parser summary message.
        const steady_clock::time_point end_time = steady_clock::now();
        const double elapsed_time = (duration_cast <duration<double>> (end_time - start_time)).count();

        Message message(PARSER_SUMMARY,
                        LINE_COUNT,   to_string(last_line_number),
                        ERROR_COUNT,  to_string(get_error_count()),
                        ELAPSED_TIME, to_string(elapsed_time));
        
        send_message(message);
    }

    int JavaParserTD::get_error_count() const
    {
        return error_handler.get_error_count();
    }

} /// namespace wci::frontend::java
