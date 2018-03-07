/**
 * <h1>BackendFactory</h1>
 *
 * <p>A factory class that creates compiler and interpreter components.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "BackendFactory.h"
#include "compiler/CodeGenerator.h"
#include "interpreter/Executor.h"

namespace wci { namespace backend {

using namespace std;
using namespace wci::backend::compiler;
using namespace wci::backend::interpreter;

Backend *BackendFactory::create_backend(string operation) throw (string)
{
    if (operation == "compile") {
        return new CodeGenerator();
    }
    else if (operation == "execute") {
        return new Executor();
    }
    else {
        throw new string("Backend factory: Invalid operation '" +
                         operation + "'");
    }
}

}} // namespace wci::backend
