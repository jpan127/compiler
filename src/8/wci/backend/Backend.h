/**
 * <h1>Backend</h1>
 *
 * <p>The framework class that represents the back end component.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_BACKEND_BACKEND_H_
#define WCI_BACKEND_BACKEND_H_

#include "../message/MessageProducer.h"
#include "../message/MessageHandler.h"
#include "../intermediate/SymTabStack.h"
#include "../intermediate/ICode.h"

namespace wci { namespace backend {

using namespace std;
using namespace wci::message;
using namespace wci::intermediate;

class Backend : public MessageProducer
{
public:
    /**
     * Getter.
     * @return the symbol table stack generated by this parser.
     */
    SymTabStack *get_symtab_stack() const;

    /**
     * Getter.
     * @return the intermediate code generated by this parser.
     */
    ICode *get_icode() const;

    /**
     * Getter.
     * @return the message handler.
     */
    MessageHandler& get_message_handler() const;

    /**
     * Process the intermediate code and the symbol table created by the
     * parser.  To be implemented by a compiler or an interpreter subclass.
     * @param icode the intermediate code.
     * @param symtab_stack the symbol table stack.
     * @throw a string message if an error occurred.
     */
    virtual void process(ICode *icode, SymTabStack *symtab_stack)  = 0;

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

protected:
    SymTabStack *symtab_stack;  // symbol table stack
    ICode       *icode;         // intermediate code

    static MessageHandler message_handler;
};

}} // namespace wci::backend

#endif /* WCI_BACKEND_BACKEND_H_ */
