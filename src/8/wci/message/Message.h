/**
 * <h1>Message</h1>
 *
 * <p>Message format.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_MESSAGE_MESSAGE_H_
#define WCI_MESSAGE_MESSAGE_H_

#include <string>
#include <map>

namespace wci { namespace message {

using namespace std;

/**
 * Types of messages.
 */
enum class MessageType
{
    SOURCE_LINE, SYNTAX_ERROR,
    PARSER_SUMMARY, INTERPRETER_SUMMARY, COMPILER_SUMMARY,
    MISCELLANEOUS, TOKEN,
    AT_LINE, ASSIGN, FETCH, BREAKPOINT, RUNTIME_ERROR,
    CALL, RETURN,
};

constexpr MessageType SOURCE_LINE = MessageType::SOURCE_LINE;
constexpr MessageType SYNTAX_ERROR = MessageType::SYNTAX_ERROR;
constexpr MessageType PARSER_SUMMARY = MessageType::PARSER_SUMMARY;
constexpr MessageType INTERPRETER_SUMMARY = MessageType::INTERPRETER_SUMMARY;
constexpr MessageType COMPILER_SUMMARY = MessageType::COMPILER_SUMMARY;
constexpr MessageType MISCELLANEOUS = MessageType::MISCELLANEOUS;
constexpr MessageType TOKEN = MessageType::TOKEN;
constexpr MessageType AT_LINE = MessageType::AT_LINE;
constexpr MessageType ASSIGN = MessageType::ASSIGN;
constexpr MessageType FETCH = MessageType::FETCH;
constexpr MessageType BREAKPOINT = MessageType::BREAKPOINT;
constexpr MessageType RUNTIME_ERROR = MessageType::RUNTIME_ERROR;
constexpr MessageType CALL = MessageType::CALL;
constexpr MessageType RETURN = MessageType::RETURN;

/**
 * Keys for the message values.
 */
enum class MessageKey
{
    LINE_NUMBER, LINE_TEXT, LINE_COUNT,
    POSITION, TOKEN_TYPE, TOKEN_TEXT, TOKEN_VALUE,
    EXECUTION_COUNT, INSTRUCTION_COUNT,
    ERROR_MESSAGE, ERROR_COUNT, ELAPSED_TIME,
    VARIABLE_NAME, RESULT_VALUE,
};

constexpr MessageKey LINE_NUMBER = MessageKey::LINE_NUMBER;
constexpr MessageKey LINE_TEXT = MessageKey::LINE_TEXT;
constexpr MessageKey LINE_COUNT = MessageKey::LINE_COUNT;
constexpr MessageKey POSITION = MessageKey::POSITION;
constexpr MessageKey TOKEN_TYPE = MessageKey::TOKEN_TYPE;
constexpr MessageKey TOKEN_TEXT = MessageKey::TOKEN_TEXT;
constexpr MessageKey TOKEN_VALUE = MessageKey::TOKEN_VALUE;
constexpr MessageKey EXECUTION_COUNT = MessageKey::EXECUTION_COUNT;
constexpr MessageKey INSTRUCTION_COUNT = MessageKey::INSTRUCTION_COUNT;
constexpr MessageKey ERROR_MESSAGE = MessageKey::ERROR_MESSAGE;
constexpr MessageKey ERROR_COUNT = MessageKey::ERROR_COUNT;
constexpr MessageKey ELAPSED_TIME = MessageKey::ELAPSED_TIME;
constexpr MessageKey VARIABLE_NAME = MessageKey::VARIABLE_NAME;
constexpr MessageKey RESULT_VALUE = MessageKey::RESULT_VALUE;

class Message
{
public:
    /**
     * Constructor.
     * @param type the message type.
     * @param key1 a message key.
     * @param value1 the associated message value.
     */
    Message(const MessageType type,
            const MessageKey key1, const string value1);

    /**
     * Constructor.
     * @param type the message type.
     * @param key1 a message key.
     * @param value1 the associated message value.
     * @param key2 a message key.
     * @param value2 the associated message value.
     */
    Message(const MessageType type,
            const MessageKey key1, const string value1,
            const MessageKey key2, const string value2);

    /**
     * Constructor.
     * @param type the message type.
     * @param key1 a message key.
     * @param value1 the associated message value.
     * @param key2 a message key.
     * @param value2 the associated message value.
     * @param key3 a message key.
     * @param value3 the associated message value.
     */
    Message(const MessageType type,
            const MessageKey key1, const string value1,
            const MessageKey key2, const string value2,
            const MessageKey key3, const string value3);

    /**
     * Constructor.
     * @param type the message type.
     * @param key1 a message key.
     * @param value1 the associated message value.
     * @param key2 a message key.
     * @param value2 the associated message value.
     * @param key3 a message key.
     * @param value3 the associated message value.
     * @param key4 a message key.
     * @param value4 the associated message value.
     */
    Message(const MessageType type,
            const MessageKey key1, const string value1,
            const MessageKey key2, const string value2,
            const MessageKey key3, const string value3,
            const MessageKey key4, const string value4);

    /**
     * Constructor.
     * @param type the message type.
     * @param key1 a message key.
     * @param value1 the associated message value.
     * @param key2 a message key.
     * @param value2 the associated message value.
     * @param key3 a message key.
     * @param value3 the associated message value.
     * @param key4 a message key.
     * @param value4 the associated message value.
     * @param key5 a message key.
     * @param value5 the associated message value.
     */
    Message(const MessageType type,
            const MessageKey key1, const string value1,
            const MessageKey key2, const string value2,
            const MessageKey key3, const string value3,
            const MessageKey key4, const string value4,
            const MessageKey key5, const string value5);

    /**
     * Getter.
     * @return the message type.
     */
    MessageType get_type() const;

    /**
     * Overloaded [] operator.
     * @param key a message key.
     * @return the value associated with the key.
     */
    string operator [](const MessageKey key);

private:
    MessageType type;
    map<MessageKey, string> body;
};

}} // namespace wci::message

#endif /* WCI_MESSAGE_MESSAGE_H_ */
