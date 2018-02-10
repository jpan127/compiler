/**
 * <h1>Executor</h1>
 *
 * <p>The executor for an interpreter back end.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <chrono>
#include "Executor.h"
#include "../Backend.h"
#include "../../message/Message.h"

namespace wci { namespace backend { namespace interpreter {

using namespace std;
using namespace std::chrono;
using namespace wci::backend;
using namespace wci::message;

void Executor::process(ICode *icode, SymTab *symtab) throw (string)
{
    steady_clock::time_point start_time = steady_clock::now();
    int execution_count = 0;
    int runtime_errors = 0;

    // Send the interpreter summary message.
    steady_clock::time_point end_time = steady_clock::now();
    double elapsed_time =
            duration_cast<duration<double>>(end_time - start_time).count();
    Message message(INTERPRETER_SUMMARY,
                    EXECUTION_COUNT, to_string(execution_count),
                    ERROR_COUNT, to_string(runtime_errors),
                    ELAPSED_TIME, to_string(elapsed_time));
    send_message(message);
}

}}} // namespace wci::backend::interpreter

