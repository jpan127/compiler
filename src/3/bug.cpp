/**
 *  Found a small bug that skips the last line when the input text does not have a trailing new line
 *  For example if a file only contained "Hello World" on either 1 line or 1 line and a newline
 *  No problem  : Hello world\nEOF
 *  Yes problem : Hello worldEOF
 *
 *  I believe I found a fix, detailed below
 */

/**
 *  Currently [Source::current_char] exits immediately when reader has the EOF bit set
 *  This ignores everything in the current string [line_text]
 */
char Source::current_char() throw (string)
{
    // First time?
    if (current_pos == -2) {
        read_line();
        return next_char();
    }

    // At end of file?
    else if (reader.eof()) return END_OF_FILE;                                  ///< Problem, returns too early

    // At end of line?
    else if ((current_pos == -1) || (current_pos == line_text.length())) {
        return END_OF_LINE;
    }

    // Need to read the next line?
    else if (current_pos > line_text.length()) {
        read_line();
        return next_char();
    }

    // Return the character at the current position.
    else return line_text[current_pos];
}

/**
 *  Fix:
 *  Keep reading the chars in [line_text] even if the EOF bit has been set,
 *  until the entire string is read
 */
char Source::current_char()
{
    // Read next line if necessary
    if (-2 == current_pos || current_pos >= line_text.length())
    {
        read_line();
        ++current_pos;                                                          ///< This also does not need to depend on [Source::next_char]
    }

    // If EOF bit is set AND finished reading the current line
    if (reader.eof() && current_pos >= line_text.length())
    {
        return END_OF_FILE;
    }
    else
    {
        return line_text[current_pos];
    }
}
