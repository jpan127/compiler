/**
 * <h1>BackendFactory</h1>
 *
 * <p>A factory class that creates compiler and interpreter components.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_BACKEND_BACKENDFACTORY_H_
#define WCI_BACKEND_BACKENDFACTORY_H_

#include <string>
#include "Backend.h"

namespace wci { namespace backend {

using namespace std;

class BackendFactory
{
public:
    /**
     * Create a compiler or an interpreter back end component.
     * @param operation either "compile" or "execute"
     * @return a compiler or an interpreter back end component.
     * @throws Exception if an error occurred.
     */
    static Backend *create_backend(string operation) throw (string);
};

}} // namespace wci::backend

#endif /* WCI_BACKEND_BACKENDFACTORY_H_ */
