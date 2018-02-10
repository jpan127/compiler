/**
 * <h1>Source</h1>
 *
 * <p>The framework class that represents the source program.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_SOURCE_H_
#define WCI_FRONTEND_SOURCE_H_

#include <iostream>
#include <fstream>
#include <string>
#include "../message/MessageHandler.h"
#include "../message/MessageProducer.h"
#include "../message/MessageListener.h"

namespace wci { namespace frontend {

using namespace std;
using namespace wci::message;

class Source : public MessageProducer
{
public:
    /**
     * Constructor.
     * @param reader the reader for the source program
     */
    Source(ifstream &reader);

    /**
     * Getter.
     * @return the current source line number.
     */
    int get_line_number() const;

    /**
     * Getter.
     * @return the position of the next source character in the
     * current source line.
     */
    int get_position() const;

    /**
     * Return the source character at the current position.
     * @return the source character at the current position.
     * @throw a string message if an error occurred.
     */
    char current_char() throw (string);

    /**
     * Consume the current source character and return the next character.
     * @return the next source character.
     * @throw a string message if an error occurred.
     */
    char next_char() throw (string);

    /**
     * Return the source character following the current character without
     * consuming the current character.
     * @return the following character.
     * @throw a string message if an error occurred.
     */
    char peek_char() throw (string);

    /**
     * Close the source.
     * @throw a string message if an error occurred.
     */
    void close() throw (string);

    /**
     * Add a message listener to the listener list.
     * Implementation of wci::message::MessageProducer.
     * @param listener the message listener to add.
     */
    void add_message_listener(MessageListener *listener);

    /**
     * Send a message.
     * Implementation of wci::message::MessageProducer.
     * @param message the message to send.
     */
    void send_message(Message& message) const;

    static const char END_OF_LINE;
    static const char END_OF_FILE;

private:
    ifstream& reader;                 // reader for the source program
    string line_text;                 // source line text
    int line_number;                  // current source line number
    int current_pos;                  // current source line position
    MessageHandler message_handler;

    /**
     * Read the next source line.
     * @throw a string message if an error occurred.
     */
    void read_line() throw (string);
};

}} // namespace wci::frontend

#endif /* WCI_FRONTEND_SOURCE_H_ */
