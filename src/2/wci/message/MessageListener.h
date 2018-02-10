/**
 * <h1>MessageListener</h1>
 *
 * <p>All classes that listen to messages must implement this interface.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_MESSAGE_MESSAGELISTENER_H_
#define WCI_MESSAGE_MESSAGELISTENER_H_

#include "Message.h"

namespace wci { namespace message {

class MessageListener
{
public:
    virtual ~MessageListener() {}

    /**
     * Receive a message sent by a message producer.
     * @param message the message that was received.
     */
    virtual void message_received(Message& message) = 0;
};

}} // namespace wci::message

#endif /* WCI_MESSAGE_MESSAGELISTENER_H_ */
