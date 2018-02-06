/**
 * <h1>Pascal</h1>
 *
 * <p>Compile or interpret a Pascal source program.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef PASCAL_H_
#define PASCAL_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "wci/frontend/Parser.h"
#include "wci/frontend/Scanner.h"
#include "wci/frontend/Source.h"
#include "wci/intermediate/SymTab.h"
#include "wci/intermediate/ICode.h"
#include "wci/backend/Backend.h"
#include "wci/message/Message.h"
#include "wci/message/MessageListener.h"

using namespace std;
using namespace wci::frontend;
using namespace wci::intermediate;
using namespace wci::backend;
using namespace wci::message;

class Pascal : public MessageListener
{
public:
    /**
     * Constructor.
     * Compile or interpret a Pascal source program.
     * @param operation either "compile" or "execute".
     * @param filePath the source file path.
     * @param flags the command line flags.
     */
    Pascal(string operation, string file_path, string flags)
        throw (string);

    /**
     * Destructor.
     */
    virtual ~Pascal();

    /**
     * Receive a message sent by a message producer.
     * Implementation of wci::message::MessageListener.
     * @param message the message that was received.
     */
    void message_received(Message& message);

private:
    Parser  *parser;    // language-independent parser
    Source  *source;    // input file source
    ICode   *icode;     // generated intermediate code
    SymTab  *symtab;    // generated symbol table
    Backend *backend;   // backend

    static const string SOURCE_LINE_FORMAT;
    static const string PARSER_SUMMARY_FORMAT;
    static const string INTERPRETER_SUMMARY_FORMAT;
    static const string COMPILER_SUMMARY_FORMAT;
};

#endif /* PASCAL_H_ */
