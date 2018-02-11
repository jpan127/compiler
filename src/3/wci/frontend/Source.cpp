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

char Source::current_char()
{
    // Read next line if necessary
    if (-2 == current_pos || current_pos >= line_text.length())
    {
        read_line();
        ++current_pos;
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

char Source::next_char()
{
    ++current_pos;
    return current_char();
}

char Source::peek_char()
{
    current_char();

    if (reader.eof() && current_pos >= line_text.length())
    {
        return END_OF_FILE;
    }
    else
    {
        return (current_pos < line_text.length()) ? line_text[current_pos + 1] : END_OF_LINE;
    }
}

void Source::put_back()
{
    current_pos = (current_pos > 0) ? (current_pos - 1) : (0);
}

void Source::read_line()
{
    current_pos = -1;

    // Clear string so string length is reset
    line_text.clear();

    getline(reader, line_text);

    if (reader.eof() && line_text.length() == 0)
    {
        return;
    }
    else if (reader.fail() || reader.bad())
    {
        throw string("Source input failure.");
    }
    else
    {
        // Always add the newline on since getline ignores it
        // Especially if the line is empty
        line_text += "\n";

        const uint32_t line_length = line_text.length();
        if ((line_length > 0) && (line_text[line_length - 1] == '\r'))
        {
            line_text.resize(line_length - 1);
        }

        ++line_number;

        // Send a source line message containing the line number
        // and the line text to all the listeners.
        Message message(SOURCE_LINE,
                        LINE_NUMBER , to_string(line_number), ///< Key : Value
                        LINE_TEXT   , line_text);             ///< Key : Value
        send_message(message);
    }
}

void Source::close()
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
