/**
 * <h1>Message</h1>
 *
 * <p>Message format.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <map>
#include "Message.h"

namespace wci { namespace message {

using namespace std;

Message::Message(const MessageType type,
                 const MessageKey key1, const string value1)
    : type(type)
{
    body[key1] = value1;
}

Message::Message(const MessageType type,
                 const MessageKey key1, const string value1,
                 const MessageKey key2, const string value2)
    : type(type)
{
    body[key1] = value1;
    body[key2] = value2;
}

Message::Message(const MessageType type,
                 const MessageKey key1, const string value1,
                 const MessageKey key2, const string value2,
                 const MessageKey key3, const string value3)
    : type(type)
{
    body[key1] = value1;
    body[key2] = value2;
    body[key3] = value3;
}

Message::Message(const MessageType type,
                 const MessageKey key1, const string value1,
                 const MessageKey key2, const string value2,
                 const MessageKey key3, const string value3,
                 const MessageKey key4, const string value4)
    : type(type)
{
    body[key1] = value1;
    body[key2] = value2;
    body[key3] = value3;
    body[key4] = value4;
}

Message::Message(const MessageType type,
                 const MessageKey key1, const string value1,
                 const MessageKey key2, const string value2,
                 const MessageKey key3, const string value3,
                 const MessageKey key4, const string value4,
                 const MessageKey key5, const string value5)
    : type(type)
{
    body[key1] = value1;
    body[key2] = value2;
    body[key3] = value3;
    body[key4] = value4;
    body[key5] = value5;
}

MessageType Message::get_type() const { return type; }

string Message::operator [](const MessageKey key)
{
    return body[key];
}

}} // namespace wci::message
