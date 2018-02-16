/**
 * <h1>MessageHandler</h1>
 *
 * <p>A helper class to which message producer classes delegate the task of
 * maintaining and notifying listeners.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_MESSAGE_MESSAGEHANDLER_H_
#define WCI_MESSAGE_MESSAGEHANDLER_H_

#include <vector>
#include "MessageListener.h"

namespace wci { namespace message {

using namespace std;

class MessageHandler
{
public:
    /**
     * Add a listener to the listener list.
     * @param listener the listener to add.
     */
    void add_listener(MessageListener *listener);

    /**
     * Send a message.
     * @param message the message to send.
     */
    void send_message(Message& message) const;

private:
    vector<MessageListener *> listeners;

    /**
     * Notify each listener in the listener list by calling the listener's
     * messageReceived() method.
     * @param message the message to be received.
     */
    void notify_listeners(Message& message) const;
};

}} // namespace wci::message

#endif /* WCI_MESSAGE_MESSAGEHANDLER_H_ */
