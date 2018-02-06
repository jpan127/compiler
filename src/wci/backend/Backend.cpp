/**
 * <h1>Backend</h1>
 *
 * <p>The framework class that represents the back end component.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "Backend.h"

namespace wci { namespace backend {

using namespace std;
using namespace wci::message;
using namespace wci::intermediate;

MessageHandler Backend::message_handler;

SymTab *Backend::get_symtab() const { return symtab; }

ICode *Backend::get_icode() const { return icode; }

MessageHandler& Backend::get_message_handler() const
{
    return message_handler;
}

void Backend::add_message_listener(MessageListener *listener)
{
    message_handler.add_listener(listener);
}

void Backend::send_message(Message& message) const
{
    message_handler.send_message(message);
}

}} // namespace wci::backend
