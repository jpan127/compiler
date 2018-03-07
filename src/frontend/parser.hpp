#pragma once

#include <fstream>

#include "globals.hpp"
#include "Token.hpp"



/**
 *  Parses the input source file, responsible for reading sequentially by characters
 *  Retrieves character or tokens and stores them in private member variables
 *  The main parsing of the file is done through [Parser::parse]
 *  @note : This class is a singleton
 */

/// Forward declare Token to enable circular dependency
class Token;

class Parser
{
public:

    /// Singleton get instance
    static Parser & instance(void)
    {
        static Parser singleton;
        return singleton;
    }

    /**
     *  Initializes the singleton
     *  @param path     : Path to input file
     *  @param capacity : Size of vector [lines]
     */
    init(const string path, const uint32_t capacity=100);

    /// Returns the current line / row number
    uint32_t get_line_number(void) const;

    /// Returns the current column or character number
    uint32_t get_column_number(void) const;

    /// Returns the current character
    char get_current_char(void);

    /// Increments the pointer to the next character and returns it
    char get_next_char(void);

    /// Returns the next character without changing the pointers
    char peek_next_char(void);

    /// Decrements the pointer to the previous character
    void put_back(void);

    /// Closes the input stream
    void close(void);

    /// Scans for the next token and returns it
    Token * get_next_token(void);

    /// Main function, loops through entire file and parses every token
    void parse_file(void);

private:

    /// Private constructor
    Parser(void);

    /// Private destructor
    ~Parser(void);

    /// File handle
    std::ifstream file;

    /// Max capacity of vector [lines]
    uint32_t capacity;

    /// Stores the next <capacity> lines to keep file reads to a minimum
    vector <string> lines;

    /// Tracks which index of the vector the parser is currently on
    uint32_t vindex;

    /// The current line number or row number, zero indexed
    uint32_t line_num;

    /// The number of the character, or column number, starting from the left, zero indexed
    uint32_t column_num;

    /// Holds an intermediary token value
    Token * token;

    /// Parses whitespace, newlines, and comments, until it reaches the first character of the next token
    void seek_to_next_token(void);

    /// Reads the next [capacity] number of lines into the vector from the input file
    void read_from_file(void);

    /// If the line and / or column indices are past bounds, increment and update them
    void update_char_indices(void);

};