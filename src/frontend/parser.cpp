#include "Parser.hpp"



Parser::Parser(const string path, const uint32_t capacity) : file(path)
{
    if (!file.good())
    {
        printf("Error opening file: %s\n", path);
        printf("Terminating program...\n");
        exit(EXIT_FAILURE);
    }

    const uint32_t max_capacity = 100;

    capacity   = MIN(capacity, max_capacity);
    vindex     = 0;
    line_num   = 0;
    column_num = 0;
    token      = NULL;

    // Pre-allocate vector size to minimize dynamic allocation
    lines.reserve(capacity);

    read_from_file();
}

uint32_t Parser::get_line_number(void) const
{
    return line_num;
}

uint32_t Parser::get_column_number(void) const
{
    return column_num;
}

char Parser::get_current_char(void)
{
    return lines[vindex][column_num];
}

char Parser::get_next_char(void)
{
    char c = EOF;

    /**
     * If not EOF, should always match this condition
     * Indices are updated at the end of the function so they are up to date
     * at the start of each function call
     */

    if (line_num < lines.size() && column_num < lines[line_num].length())
    {
        // Only increment column_num if reading
        c = lines[line_num][column_num++];
    }

    update_char_indices();

    return c;
}

char Parser::peek_next_char(void)
{
    // Peek current line, next char
    if (column_num + 1 < lines[vindex].length())
    {
        return lines[vindex][column_num + 1];
    }
    // Peek next line, first char
    else if (vindex + 1 < lines.size())
    {
        return lines[vindex + 1][0];
    }
    // Vector all read, peek from file
    else
    {
        return file.peek();
    }
}

void Parser::put_back(void)
{
    try
    {
        if (column_num - 1 >= 0)
        {
            --column_num;
        }
        else if (vindex - 1 >= 0)
        {
            --vindex;
        }
        else
        {
            throw "Not implemented, cannot put_back past the first character of the vector";
        }
    }
    catch (string & msg)
    {
        printf("%s\n", msg);
    }
}

void Parser::close(void)
{
    // @TODO : I see no benefit to this function for now, delete later maybe
    file.close();
}

/// White space + comment skipping functions, to be implemented when comment style is finalized
#if 0
void JavaScanner::ignore_all_whitespaces(char &c)
{
    const char eof = 0;
    while (isspace(c) && c != eof)
    {
        c = next_char();
    }
}

void JavaScanner::find_next_token()
{
    // Syntactical symbols
    const char slash    = '/';
    const char asterisk = '*';
    const char new_line = '\n';
    const char eof      = 0;

    /**
     *  @note:
     *  If the scanner encounters a slash, but it is not proceeded by another slash or asterisk,
     *  then there is most likely a syntax issue.  The slash should have been preceeded by a left hand operator.
     */

    scanner_state_E state = scanner_state_E::ignoring_characters;
    char c = ' ';

    while (c != eof)
    {
        // Read all preceeding spaces
        ignore_all_whitespaces(c);

        // Finding the first slash
        if (c == slash)
        {
            c = next_char();

            // Finds a second slash, so it is a single line comment
            if (c == slash)
            {
                // Ignore all characters of the current line
                while (c != new_line && c != eof)
                {
                    c = next_char();
                }

                // Read all subsequent spaces
                c = next_char();
                ignore_all_whitespaces(c);

            }
            // Finds an asterisk, so it is a multi line comment
            else if (c == asterisk)
            {
                // Search for next asterisk that is proceeded by a slash
                while (c != eof)
                {
                    c = next_char();

                    // If parsing the comment and finds an asterisk
                    if (state == scanner_state_E::ignoring_characters && c == asterisk)
                    {
                        state = scanner_state_E::ending_asterisk;
                    }
                    // If just found an asterisk and finds another slash
                    else if (state == scanner_state_E::ending_asterisk && c == slash)
                    {
                        break;
                    }
                    // If just found an asterisk, and ending slash not found
                    else if (state == scanner_state_E::ending_asterisk && c != slash)
                    {
                        state = scanner_state_E::ignoring_characters;
                    }
                }

                // Read all subsequent spaces
                c = next_char();
                ignore_all_whitespaces(c);
            }
            else
            {
                put_back();
                break;
            }
        }
        // If the next character is not a space or a slash then it must be a token
        else if (!isspace(c))
        {
            break;
        }
    }
}
#endif

Token * Parser::get_next_token(Token * old_token)
{
    // find_next_token();

    char c = get_current_char();
    string str;
    str += c;

    // Recycle tokens in a loop, return the old one to create a new one
    Token * new_token = nullptr;
    if (nullptr != old_token)
    {
        delete old_token;
    }

    if (c == EOF)                           new_token = nullptr;
    else if (isalpha(c))                    new_token = new JavaWordToken(source);
    else if (isdigit(c))                    new_token = new JavaNumberToken(source);
    else if (c == '\'' || c == '\"')        new_token = new JavaStringToken(source);
    else if (token::symbols.count(str) > 0) new_token = new JavaSpecialSymbolToken(source);
    else                                    new_token = new JavaErrorToken(source, JavaErrorCode::INVALID_CHARACTER, str);

    // Store address of current token
    token = new_token;

    return new_token;
}

void Parser::parse_file(void)
{
    /// To be implemented
}

void read_from_file(void)
{
    lines.clear();

    string line;
    for (uint32_t i=0; i<capacity; i++)
    {
        getline(file, line);
        lines.push_back(line);
        if (file.eof())
        {
            break;
        }
    }
}

void update_char_indices(void)
{
    // If reached end of line, go to next line
    if (column_num >= lines[vindex].length())
    {
        column_num = 0;
        ++vindex;
    }

    // If reached end of vector, read from file again
    if (vindex >= lines.size())
    {
        read_from_file();
        ++line_num;
        vindex     = 0;
        column_num = 0;
    }
}