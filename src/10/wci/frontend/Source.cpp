/**
 * <h1>Source</h1>
 *
 * <p>The framework class that represents the source program.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <iostream>
#include <fstream>
#include <string>
#include "Source.h"
#include "../message/Message.h"
#include "../message/MessageHandler.h"
#include "../message/MessageListener.h"

namespace wci { namespace frontend {

using namespace std;
using namespace wci::message;

const char Source::END_OF_LINE = '\n';
const char Source::END_OF_FILE = (char) 0;

Source::Source(ifstream &reader)
    : reader(reader), line_number(0), current_pos(-2)
    // set position to -2 to read the first source line
{
}

int Source::get_line_number() const { return line_number; }

int Source::get_position() const { return current_pos; }

char Source::current_char() throw (string)
{
    // First time?
    if (current_pos == -2) {
        read_line();
        return next_char();
    }

    // At end of file?
    else if (reader.eof()) return END_OF_FILE;

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

char Source::next_char() throw (string)
{
    ++current_pos;
    return current_char();
}

char Source::peek_char() throw (string)
{
    current_char();

    if (reader.eof()) return END_OF_FILE;

    int next_pos = current_pos + 1;
    return next_pos < line_text.length() ? line_text[next_pos]
                                         : END_OF_LINE;
}

void Source::read_line() throw (string)
{
    getline(reader, line_text);

    if (reader.eof()) return;
    if (reader.fail() || reader.bad()) throw string("Source input failure.");

    current_pos = -1;

    if (reader.good())
    {
        int line_length = line_text.length();
        if ((line_length > 0) && (line_text[line_length - 1] == '\r'))
        {
            line_text.resize(--line_length);
        }

        ++line_number;

        // Send a source line message containing the line number
        // and the line text to all the listeners.
        Message message(SOURCE_LINE,
                        LINE_NUMBER, to_string(line_number),
                        LINE_TEXT, line_text);
        send_message(message);
    }
}

void Source::close() throw (string)
{
    reader.close();
}

void Source::add_message_listener(MessageListener *listener)
{
    message_handler.add_listener(listener);
}

void Source::send_message(Message& message) const
{
    message_handler.send_message(message);
}

}} // namespace wci::frontend
