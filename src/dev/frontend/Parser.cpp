#include "Parser.hpp"
#include "TokenTypes.hpp"



void Parser::init(const string path, const uint32_t _capacity)
{
    // Hard limit to vector size
    const uint32_t max_capacity = 100000;

    file.open(path);
    if (!file.good())
    {
        cout << "Error opening file: " << path << endl;
        cout << "Terminating program..." << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "------------------------------" << endl;
        cout << "Opened file: " << path << endl;
        cout << "------------------------------" << endl;
    }

    capacity = MIN(_capacity, max_capacity);

    line_num    = 0;
    column_num  = 0;
    token       = nullptr;
    end_of_file = false;

    // Pre-allocate vector size to minimize dynamic allocation
    lines.reserve(capacity);

    read_from_file();
}

Parser::~Parser(void)
{
    if (nullptr != token)
    {
        delete token;
    }

    close();
}

uint32_t Parser::get_line_num(void) const
{
    return line_num;
}

uint32_t Parser::get_column_num(void) const
{
    return column_num;
}

char Parser::get_current_char(void)
{
// cout << "1: " << column_num << endl;
    return lines[line_num][column_num];
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
        c = lines[line_num][++column_num];
// cout << "2: " << column_num << endl;
    }

    update_char_indices();

    return c;
}

char Parser::peek_next_char(void)
{
    // Peek current line, next char
    if (column_num + 1 < lines[line_num].length())
    {
        return lines[line_num][column_num + 1];
    }
    // Peek next line, first char
    else if (line_num + 1 < lines.size())
    {
        return lines[line_num + 1][0];
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
        else if (line_num - 1 >= 0)
        {
            --line_num;
        }
        else
        {
            throw "Not implemented, cannot put_back past the first character of the vector";
        }
    }
    catch (string & msg)
    {
        cout << msg << endl;
    }
}

void Parser::close(void)
{
    if (file.is_open())
    {
        file.close();
    }
}

void Parser::ignore_all_whitespaces(char &c)
{
    const char eof = 0;
    while (isspace(c) && c != eof)
    {
        c = get_next_char();
    }
}

void Parser::find_next_token(void)
{
    // Syntactical symbols
    const char slash    = '/';
    const char asterisk = '*';
    const char new_line = '\n';
    const char eof      = 0;

    /**
     *  @NOTE:
     *  If the scanner encounters a slash, but it is not proceeded by another slash or asterisk,
     *  then there is most likely a syntax issue.  The slash should have been preceeded by a left hand operator.
     */

    ScannerState state = ScannerState::ignoring_characters;
    char c = get_current_char();

    while (c != eof)
    {
        // Read all preceeding spaces
        ignore_all_whitespaces(c);

        // Finding the first slash
        if (c == slash)
        {
            c = get_next_char();

            // Finds a second slash, so it is a single line comment
            if (c == slash)
            {
                // Ignore all characters of the current line
                while (c != new_line && c != eof)
                {
                    c = get_next_char();
                }

                // Read all subsequent spaces
                c = get_next_char();
                ignore_all_whitespaces(c);

            }
            // Finds an asterisk, so it is a multi line comment
            else if (c == asterisk)
            {
                // Search for next asterisk that is proceeded by a slash
                while (c != eof)
                {
                    c = get_next_char();

                    // If parsing the comment and finds an asterisk
                    if (state == ScannerState::ignoring_characters && c == asterisk)
                    {
                        state = ScannerState::ending_asterisk;
                    }
                    // If just found an asterisk and finds another slash
                    else if (state == ScannerState::ending_asterisk && c == slash)
                    {
                        break;
                    }
                    // If just found an asterisk, and ending slash not found
                    else if (state == ScannerState::ending_asterisk && c != slash)
                    {
                        state = ScannerState::ignoring_characters;
                    }
                }

                // Read all subsequent spaces
                c = get_next_char();
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

Token * Parser::get_next_token(Token * old_token)
{
    find_next_token();

    char c = get_current_char();
    string str;
    str += c;
    const string & const_str = str;

    // Recycle tokens in a loop, return the old one to create a new one
    Token * new_token = nullptr;
    if (nullptr != old_token)
    {
        delete old_token;
    }

    if (c == EOF)                           new_token = nullptr;
    else if (isalpha(c))                    new_token = new WordToken();
    else if (isdigit(c))                    new_token = new NumberToken();
    else if (c == '\'' || c == '\"')        new_token = new StringToken();
    else if (Token::is_symbol(const_str))   new_token = new SymbolToken();
    else                                    new_token = new ErrorToken();

    // Store address of current token
    // token = new_token;

    return new_token;
}

void Parser::parse_file(void)
{
    /// To be implemented
    for (auto line : lines)
    {
        cout << line << endl;
    }

    uint32_t count = 0;
    while (!end_of_file)
    {
        token = get_next_token(token);
        cout << "\t" << token->get_text() << endl;
        if (++count == 10) break;
    }
}

void Parser::read_from_file(void)
{
    lines.clear();

    for (uint32_t i=0; i<capacity; i++)
    {
        string line;
        getline(file, line);
        if (line.size() > 0)
        {
            lines.push_back(line);
        }
        else
        {
            break;
        }
        if (file.eof())
        {
            break;
        }
    }

    // Set flag if nothing more to read
    if (0 == lines.size())
    {
        end_of_file = true;
    }
}

void Parser::update_char_indices(void)
{
    // If reached end of line, go to next line
    if (column_num >= lines[line_num].length())
    {
        column_num = 0;
        ++line_num;
    }

    // If reached end of vector, read from file again
    if (line_num >= lines.size())
    {
        read_from_file();
        line_num   = 0;
        column_num = 0;
    }
}