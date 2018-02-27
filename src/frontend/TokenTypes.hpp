#pragma once

#include "globals.hpp"
#include "Token.hpp"
#include "Parser.hpp"



/**
 *  Each of these 5 classes are a type of token
 *  They all have their own method of extracting the next sequence of characters to match their
 *  respective token type
 *  For example a word extracts until the end of the word, delimited by a symbol or space
 *  A number extract until the next character is not numerical, not a decimal point, not an exponent, etc.
 */

class WordToken : public Token
{
public:

    WordToken(Parser * parser) : Token(parser)
    {
        char c = parser->get_current_char();

        // Parse until not a letter
        while (c != EOF && isalnum(c))
        {
            text += c;
            if (isalnum(parser->peek_char()))
            {
                c = parser->get_next_char();
            }
            else
            {
                break;
            }
        }

        const string token = "token_" + text;

        // Look it up, if it is not a keyword
        type = (keywords.count(token) > 0) ? (keywords[token]) : (TokenType::identifier);
    }

};

class SymbolToken : public Token
{
public:

    SymbolToken(Parser * parser) : Token(parser)
    {
        char curr = parser->get_current_char();
        text = curr;

        // See if any of the symbols match
        switch (curr)
        {
            // To be implemented

            default:
                parser->get_next_char();
                type  = TokenType::error;
                value = ErrorCode::invalid_character;
                break;
        }

        // If something matches, look it up in the table
        if (TokenType::error != type)
        {
            type = Token::symbols[text];
        }
    }

};

class StringToken : public Token
{
public:

    inline bool JavaStringToken::is_double_quote(char c) const
    {
        const char double_quote = '"';

        return (double_quote == c);
    }

    inline bool JavaStringToken::is_single_quote(char c) const
    {
        const char single_quote = '\'';

        return (single_quote == c);
    }

    void JavaStringToken::replace_escape_sequences(char &c, string &str)
    {
        static const map <string, string> escape_sequences =
        {
            { "\n", "\n"   },
            { "\t", "    " },
            { "\'", "'"    },
            { "\"", "\""   },
            { "\\", "\\"   },
        };

        c = next_char();

        // @note : Using a string = '\' + 'n' does not equal "\n" so cannot do a straight lookup
        switch (c)
        {
            case 'n'  :   text += escape_sequences.at("\n");   str += escape_sequences.at("\n");   break;
            case 't'  :   text += escape_sequences.at("\t");   str += escape_sequences.at("\t");   break;
            case '\'' :   text += escape_sequences.at("\'");   str += escape_sequences.at("\'");   break;
            case '\"' :   text += escape_sequences.at("\"");   str += escape_sequences.at("\"");   break;
            case '\\' :   text += escape_sequences.at("\\");   str += escape_sequences.at("\\");   break;
            default   :                                                                            break;
        }
    }

    StringToken(Parser * parser) : Token(parser)
    {
        /**
         *  1. Current char should either be a single quote or a double quote, otherwise parsing or syntax error
         *  2. If single quote, get character or get escaped character
         *  3. If double quote, parse the entire string, until before the closing quote
         *  4. Consume the closing quote and exit
         */

        const char escape = '\\';
        const char eof    = 0;
     
        string value_str;
        char current_ch = current_char();
        bool exit_condition = false;

        if (is_single_quote(current_ch))
        {
            if (peek_char() == escape)
            {
                next_char();
                replace_escape_sequences(current_ch, value_str);
            }
            else
            {
                current_ch = next_char();
                text      += current_ch;
                value_str += current_ch;
            }
            next_char();
        }
        else if (is_double_quote(current_ch))
        {
            do
            {
                current_ch = next_char();

                // EOF, exit
                if (eof == current_ch)
                {
                    break;
                }
                // Replace any whitespace character with a blank.
                else if (isspace(current_ch))
                {
                    text       += ' ';
                    value_str  += ' ';
                }
                // Replace any escape sequences
                else if (escape == current_ch)
                {
                    replace_escape_sequences(current_ch, value_str);
                    // Skip exit condition check
                    continue;
                }
                // Normal character
                else if (!is_double_quote(current_ch))
                {
                    text       += current_ch;
                    value_str  += current_ch;
                }

                // The condition to exit loop is if next character is closing quote AND current character is not a slash
                // Because if current character is a slash then the next quote character is escaped
                exit_condition = (is_double_quote(current_char()));

            } while ((!exit_condition) && (current_ch != eof));
        }
        else
        {
            type  = (TokenType) JavaTokenType::token_error;
            value = (int) JavaErrorCode::INVALID_STRING;
            return;
        }

        if (is_double_quote(current_char()) || is_single_quote(current_char()))
        {
            // Throw away closing single or double quote
            next_char();
            type   = (TokenType) JavaTokenType::token_string;
            value  = value_str;
        }
        else
        {
            type = (TokenType) JavaTokenType::token_error;
            value = (int) JavaErrorCode::UNEXPECTED_EOS;
        }
    }

};

class NumberToken : public Token
{
public:

    NumberToken(Parser * parser) : Token(parser), type(TokenType::integer)
    {
        /**
         *  Possibilities:
         *      A   1       +1      -1
         *      B   1.2     +1.2    -1.2
         *      C   1e2     +1e2    -1e2
         *      D   1E2     +1E2    -1E2
         *      E   1.2E3   +1.2E3  -1.2E3
         *      F   1.2e3   +1.2e3  -1.2e3
         */

        char c = get_current_char();

        // If there is a sign, parse that first
        if (c == '+' || c == '-')
        {
            text += c;
            c = get_next_char();
        }

        // Case A : get everything up to the decimal / exponent splitter, or a space
        parse_digits();

        // Case B
        if (is_decimal(c))
        {
            type = TokenType::fpoint;
            text += c;
            c = get_next_char();

            parse_digits();

            // Case E + F
            if (is_exponent(c))
            {
                parse_digits();
            }
            // Cannot happen after a decimal
            else if (is_decimal(c))
            {
                ParserErrorHandler::instance().print_error(this, ErrorCode::error_parsing_fpoint);
                return;
            }
        }
        // Case C + D
        else if (is_exponent(c))
        {
            type = TokenType::fpoint;
            text += c;
            c = get_next_char();

            parse_digits();

            // Cannot happen after an exponent
            if (is_decimal(c) || is_exponent(c))
            {
                ParserErrorHandler::instance().print_error(this, ErrorCode::error_parsing_fpoint);
                return;
            }
        }

        if (TokenType::integer == type)
        {
            value = std::stoi(text);
        }
        else if (TokenType::fpoint == type)
        {
            value = std::stof(text);
        }
        else
        {
            ParserErrorHandler::instance().print_error(this, ErrorCode::parser_invalid_state);
        }
    }

private:

    inline bool is_exponent(char c)
    {
        return (c == 'e' || c == 'E');
    }

    inline bool is_decimal(char c)
    {
        return (c == '.');
    }

    inline void parse_digits(void)
    {
        while (isdigit(c))
        {
            text += c;
            c = get_next_char();
        }
    }

};

/// This token is to signify 
class ErrorToken : public Token
{
public:

    ErrorToken(Parser * parser) : Token(parser)
    {
        type = TokenType::invalid_character;
    }

};