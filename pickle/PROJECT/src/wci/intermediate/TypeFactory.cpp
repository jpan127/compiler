/**
 * <h1>TypeFactory</h1>
 *
 * <p>A factory for creating type specifications.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "TypeFactory.h"
#include "TypeSpec.h"
#include "typeimpl/TypeSpecImpl.h"

namespace wci { namespace intermediate {

using namespace std;
using namespace wci::intermediate::typeimpl;

TypeSpec *TypeFactory::create_type(const TypeForm form)
{
    return new TypeSpecImpl(form);
}

TypeSpec *TypeFactory::create_string_type(const string value)
{
    return new TypeSpecImpl(value);
}

}}  // namespace wci::intermediate
