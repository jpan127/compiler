/**
 * <h1>MessageHandler</h1>
 *
 * <p>A helper class to which message producer classes delegate the task of
 * maintaining and notifying listeners.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "MessageHandler.h"
#include "MessageListener.h"

namespace wci { namespace message {

using namespace std;

void MessageHandler::add_listener(MessageListener *listener)
{
    listeners.push_back(listener);
}

void MessageHandler::send_message(Message& message) const
{
    notify_listeners(message);
}

void MessageHandler::notify_listeners(Message& message) const
{
    for (MessageListener *listener : listeners) {
        listener->message_received(message);
    }
}

}} // namespace wci::message
