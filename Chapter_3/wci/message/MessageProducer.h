/**
 * <h1>MessageProducer</h1>
 *
 * <p>All classes that produce messages must implement this interface.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_MESSAGE_MESSAGEPRODUCER_H_
#define WCI_MESSAGE_MESSAGEPRODUCER_H_

#include "MessageListener.h"

namespace wci { namespace message {

class MessageProducer
{
public:
    virtual ~MessageProducer() {}

    /**
     * Add a message listener to the listener list.
     * @param listener the message listener to add.
     */
    virtual void add_message_listener(MessageListener *listener) = 0;

    /**
     * Send a message.
     * @param message the message to send.
     */
    virtual void send_message(Message& message) const = 0;
};

}} // namespace wci::message

#endif /* WCI_MESSAGE_MESSAGEPRODUCER_H_ */
