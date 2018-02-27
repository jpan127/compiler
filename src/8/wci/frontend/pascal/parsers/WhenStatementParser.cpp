#include "WhenStatementParser.hpp"

#include <iostream>
#include <set>

#include "ExpressionParser.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"



namespace wci::frontend::pascal::parsers
{

WhenStatementParser::WhenStatementParser(PascalParserTD *parent) : StatementParser(parent)
{

}

ICodeNode * WhenStatementParser::parse_statement(Token * token)
{
    /**
     *  @example:
     *  WHEN
     *      i = 1 => f := 10;
     *      i = 2 => f := 20;
     *  OTHERWISE => f := -1;
     *  END
     *
     *  1. Parse the WHEN
     *  2. Parse condition until allow operator '=>'
     *  3. Parse assignment statement until semicolon
     *  4. Check if OTHERWISE, if yes, go to (5) else go back to (2)
     *  5. Parse OTHERWISE condition until allow operator
     *  6. Parse OTHERWISE assignment statement
     *  7. Parse semicolon if exists
     *  8. Parse END, parse semicolon
     */

    // cout << "[F] " << __FILE__ << "::" << __FUNCTION__ << endl;

    // Set of possible tokens
    std::set <PascalTokenType> when_set; // = { PT_WHEN, PT_OTHERWISE, PT_ALLOW };
    when_set.insert(StatementParser::STMT_START_SET.begin(),  StatementParser::STMT_START_SET.end());
    when_set.insert(StatementParser::STMT_FOLLOW_SET.begin(), StatementParser::STMT_FOLLOW_SET.end());
    
    // Parse WHEN
    token = next_token(token);

    // New node
    ICodeNode * when_node = ICodeFactory::create_icode_node(static_cast<ICodeNodeType>(NT_WHEN));
    
    // Statement and expression parsers
    StatementParser statement_parser(this);
    ExpressionParser expression_parser(this);

    // Parse until OTHERWISE, no more tokens, or found an END (should not before OTHERWSIE)
    while ((token != nullptr)                                          && 
           (token->get_type() != static_cast<TokenType>(PT_OTHERWISE)) && 
           (token->get_type() != static_cast<TokenType>(PT_END)))
    {
        // Parse expression
        ICodeNode * node = expression_parser.parse_statement(token);
        token = current_token();

        // If the current token is := that means that the LHS of the WHEN statement is incorrectly an assignment statement
        if (nullptr != node && (token->get_type() == static_cast<TokenType>(PT_COLON_EQUALS)))
        {
            error_handler.flag(token, WHEN_LHS_SHOULD_BE_CONDITION, this);
            error_handler.flag(token, WHEN_SKIPPING_STATEMENT, this);
            
            // Skip current statement
            while ((nullptr != token) && (token->get_type() != static_cast<TokenType>(PT_SEMICOLON)))
            {
                token = next_token(token);
            }
            token = next_token(token);

            continue;
        }
        else
        {
            when_node->add_child(node);
        }

        // Parse the allow operator : =>
        token = synchronize(when_set);
        if (token->get_type() == static_cast<TokenType>(PT_ALLOW))
        {
            token = next_token(token);
        }
        else
        {
            error_handler.flag(token, MISSING_ALLOW, this);
        }

        // Parse the allowed statement
        when_node->add_child(statement_parser.parse_statement(token));
        token = current_token();

        // Parse semicolon
        if (token->get_type() == (TokenType) PT_SEMICOLON)
        {
            token = next_token(token);
        }
        else
        {
            error_handler.flag(token, MISSING_SEMICOLON, this);
        }
    }

    // Never found OTHERWISE
    if (nullptr == token)
    {
        error_handler.flag(token, MISSING_OTHERWISE, this);

        // Find last END
        if (token->get_type() == static_cast<TokenType>(PT_END))
        {
            token = next_token(token);
        }
        else
        {
            error_handler.flag(token, MISSING_END, this);
        }
    }
    // Premature END without OTHERWISE
    else if (token->get_type() == static_cast<TokenType>(PT_END))
    {
        error_handler.flag(token, MISSING_OTHERWISE, this);

        // Semicolon
        token = next_token(token);
    }
    // Found OTHERWISE
    else
    {
        token = next_token(token);
    
        // Found OTHERWISE and found last =>
        if (token->get_type() == static_cast<TokenType>(PT_ALLOW))
        {
            token = next_token(token);
            when_node->add_child(statement_parser.parse_statement(token));
            token = current_token();

            // Parse semicolon, which is optional
            if (token->get_type() == (TokenType) PT_SEMICOLON)
            {
                token = next_token(token);
            }

            // Find last END
            if (token->get_type() == static_cast<TokenType>(PT_END))
            {
                token = next_token(token);
            }
            else
            {
                error_handler.flag(token, MISSING_END, this);
            }
        }
        // Found OTHERWISE but did not find last =>
        else
        {
            error_handler.flag(token, MISSING_ALLOW, this);
        }
    }

    return when_node;
}

} /// wci::frontend::pascal::parsers