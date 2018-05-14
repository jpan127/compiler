/**
 * <h1>TypeSpec</h1>
 *
 * <p>The interface for a type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef TYPESPEC_H_
#define TYPESPEC_H_

#include <vector>
#include <map>
#include "SymTabEntry.h"
#include "../Object.h"

namespace wci { namespace intermediate {

using namespace std;

/**
 * Type specification form
 */
enum class TypeForm
{
    // to be "subclassed" by implementation-specific type forms
};

/**
 * Type specification key
 */
enum class TypeKey
{
    // to be "subclassed" by implementation-specific type keys
};

class TypeSpec;  // forward declaration

class TypeSpec
{
public:
    /**
     * Destructor.
     */
    virtual ~TypeSpec() {}

    /**
     * Getter
     * @return the type form.
     */
    virtual TypeForm get_form() const = 0;

    /**
     * Getter.
     * @return the type identifier (symbol table entry).
     */
    virtual SymTabEntry *get_identifier() = 0;

    /**
     * Setter.
     * @param id the type identifier (symbol table entry).
     */
    virtual void set_identifier(SymTabEntry *id) = 0;

    /**
     * Set an attribute of the specification.
     * @param key the attribute key.
     * @param value the attribute value.
     */
    virtual void set_attribute(TypeKey key, Object value) = 0;

    /**
     * Get the value of an attribute of the specification.
     * @param key the attribute key.
     * @return the attribute value.
     */
    virtual Object get_attribute(TypeKey key) = 0;

    /**
     * To be defined by an implementation subclass.
     * @return true if this is a Pascal string type.
     */
    virtual bool is_pascal_string() = 0;

    /**
     * To be defined by an implementation subclass.
     * @return the base type of this type.
     */
    virtual TypeSpec *base_type() = 0;
};

}}  // namespace wci::intermediate

#endif /* TYPESPEC_H_ */
