#pragma once

#include "globals.hpp"
#include "Token.hpp"
#include "Parser.hpp"
#include "ParserErrorHandler.hpp"
#include "ErrorHandler.hpp"



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

    WordToken() : Token()
    {
        cout << "WordToken\n";
        char c = Parser::instance().get_current_char();

        // Parse until not a letter
        while (c != EOF && isalnum(c))
        {
            text += c;
// cout << text << endl;
            if (isalnum(Parser::instance().peek_next_char()))
            {
                c = Parser::instance().get_next_char();
            }
            else
            {
                break;
            }
        }

        const string token_name = "token_" + text;

        // Look it up, if it is not a keyword
        type = (keywords.count(token_name) > 0) ? (keywords.at(token_name)) : (TokenType::identifier);
        
        // Continue
        Parser::instance().get_next_char();
    }

};

class SymbolToken : public Token
{
public:

    SymbolToken() : Token()
    {
        cout << "SymbolToken\n";
        // char curr = Parser::instance().get_current_char();
        // text = curr;

        // // See if any of the symbols match
        // switch (curr)
        // {
        //     // To be implemented

        //     default:

        //         Parser::instance().get_next_char();
        //         type  = TokenType::error;
        //         value = ErrorCode::invalid_character;
        //         break;
        // }

        // // If something matches, look it up in the table
        // if (TokenType::error != type)
        // {
        //     type = Token::symbols[text];
        // }
    }

};

class StringToken : public Token
{
public:

    StringToken() : Token()
    {
        cout << "StringToken\n";
        /**
         *  1. Current char should either be a single quote or a double quote, otherwise parsing or syntax error
         *  2. If single quote, get character or get escaped character
         *  3. If double quote, parse the entire string, until before the closing quote
         *  4. Consume the closing quote and exit
         */

        const char escape = '\\';
        const char eof    = 0;
     
        char current_ch = Parser::instance().get_current_char();
        bool exit_condition = false;

        if (is_single_quote(current_ch))
        {
            if (Parser::instance().peek_next_char() == escape)
            {
                Parser::instance().get_next_char();
                replace_escape_sequences(current_ch);
            }
            else
            {
                current_ch = Parser::instance().get_next_char();
                text += current_ch;
            }
            Parser::instance().get_next_char();
        }
        else if (is_double_quote(current_ch))
        {
            do
            {
                current_ch = Parser::instance().get_next_char();

                // EOF, exit
                if (eof == current_ch)
                {
                    break;
                }
                // Replace any whitespace character with a blank.
                else if (isspace(current_ch))
                {
                    text += ' ';
                }
                // Replace any escape sequences
                else if (escape == current_ch)
                {
                    replace_escape_sequences(current_ch);
                    // Skip exit condition check
                    continue;
                }
                // Normal character
                else if (!is_double_quote(current_ch))
                {
                    text += current_ch;
                }

                // The condition to exit loop is if next character is closing quote AND current character is not a slash
                // Because if current character is a slash then the next quote character is escaped
                exit_condition = (is_double_quote(Parser::instance().get_current_char()));

            } while ((!exit_condition) && (current_ch != eof));
        }
        else
        {
            type = (TokenType) TokenType::error;
            return;
        }

        if (is_double_quote(Parser::instance().get_current_char()) || is_single_quote(Parser::instance().get_current_char()))
        {
            // Throw away closing single or double quote
            Parser::instance().get_next_char();
            type = (TokenType) TokenType::string;
        }
        else
        {
            type = (TokenType) TokenType::error;
        }
    }

private:

    inline bool is_double_quote(char c) const
    {
        const char double_quote = '"';

        return (double_quote == c);
    }

    inline bool is_single_quote(char c) const
    {
        const char single_quote = '\'';

        return (single_quote == c);
    }

    void replace_escape_sequences(char &c)
    {
        static const string new_line     = "\n"   ;
        static const string tab          = "    " ;
        static const string single_quote = "'"    ;
        static const string double_quote = "\""   ;
        static const string slash        = "\\"   ;

        string replacement;
        c = Parser::instance().get_next_char();

        // @note : Using a string = '\' + 'n' does not equal "\n" so cannot do a straight lookup
        switch (c)
        {
            case 'n'  : text += new_line;     break;
            case 't'  : text += tab;          break;
            case '\'' : text += single_quote; break;
            case '\"' : text += double_quote; break;
            case '\\' : text += slash;        break;
            default   :                       break;
        }
    }

};

class NumberToken : public Token
{
public:

    NumberToken() : Token(TokenType::integer)
    {
        cout << "NumberToken\n";
        /**
         *  Possibilities:
         *      A   1       +1      -1
         *      B   1.2     +1.2    -1.2
         *      C   1e2     +1e2    -1e2
         *      D   1E2     +1E2    -1E2
         *      E   1.2E3   +1.2E3  -1.2E3
         *      F   1.2e3   +1.2e3  -1.2e3
         */

        char c = Parser::instance().get_current_char();

        // If there is a sign, parse that first
        if (c == '+' || c == '-')
        {
            text += c;
            c = Parser::instance().get_next_char();
        }

        // Case A : get everything up to the decimal / exponent splitter, or a space
        parse_digits(c);

        // Case B
        if (is_decimal(c))
        {
            type = TokenType::fpoint;
            text += c;
            c = Parser::instance().get_next_char();

            parse_digits(c);

            // Case E + F
            if (is_exponent(c))
            {
                parse_digits(c);
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
            c = Parser::instance().get_next_char();

            parse_digits(c);

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

    uint32_t value;

    inline bool is_exponent(char c)
    {
        return (c == 'e' || c == 'E');
    }

    inline bool is_decimal(char c)
    {
        return (c == '.');
    }

    inline void parse_digits(char & c)
    {
        while (isdigit(c))
        {
            text += c;
            c = Parser::instance().get_next_char();
        }
    }

};

/// This token is to signify an error
class ErrorToken : public Token
{
public:

    ErrorToken() : Token()
    {
        cout << "ErrorToken\n";
        type = TokenType::invalid_character;

        ParserErrorHandler::instance().print_error(this, ErrorCode::invalid_character);

        // Continue
        Parser::instance().get_next_char();
    }

};
