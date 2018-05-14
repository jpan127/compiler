/**
 * <h1>TypeSpecImpl</h1>
 *
 * <p>A Pascal type specification implementation.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef TYPESPECIMPL_H_
#define TYPESPECIMPL_H_

#include <string>
#include <map>
#include "../TypeSpec.h"

namespace wci { namespace intermediate { namespace typeimpl {

using namespace std;

/**
 * Type specification form implementation
 */
enum class TypeFormImpl
{
    SCALAR, ENUMERATION, SUBRANGE, ARRAY, RECORD,
};

constexpr TypeFormImpl TF_SCALAR = TypeFormImpl::SCALAR;
constexpr TypeFormImpl TF_ENUMERATION = TypeFormImpl::ENUMERATION;
constexpr TypeFormImpl TF_SUBRANGE = TypeFormImpl::SUBRANGE;
constexpr TypeFormImpl TF_ARRAY = TypeFormImpl::ARRAY;
constexpr TypeFormImpl TF_RECORD = TypeFormImpl::RECORD;

/**
 * Type specification key implementation
 */
enum class TypeKeyImpl
{
    // Enumeration
    ENUMERATION_CONSTANTS,

    // Subrange
    SUBRANGE_BASE_TYPE, SUBRANGE_MIN_VALUE, SUBRANGE_MAX_VALUE,

    // Array
    ARRAY_INDEX_TYPE, ARRAY_ELEMENT_TYPE, ARRAY_ELEMENT_COUNT,

    // Record
    RECORD_SYMTAB,
};

constexpr TypeKeyImpl ENUMERATION_CONSTANTS = TypeKeyImpl::ENUMERATION_CONSTANTS;
constexpr TypeKeyImpl SUBRANGE_BASE_TYPE = TypeKeyImpl::SUBRANGE_BASE_TYPE;
constexpr TypeKeyImpl SUBRANGE_MIN_VALUE = TypeKeyImpl::SUBRANGE_MIN_VALUE;
constexpr TypeKeyImpl SUBRANGE_MAX_VALUE = TypeKeyImpl::SUBRANGE_MAX_VALUE;
constexpr TypeKeyImpl ARRAY_INDEX_TYPE = TypeKeyImpl::ARRAY_INDEX_TYPE;
constexpr TypeKeyImpl ARRAY_ELEMENT_TYPE = TypeKeyImpl::ARRAY_ELEMENT_TYPE;
constexpr TypeKeyImpl ARRAY_ELEMENT_COUNT = TypeKeyImpl::ARRAY_ELEMENT_COUNT;
constexpr TypeKeyImpl RECORD_SYMTAB = TypeKeyImpl::RECORD_SYMTAB;

class TypeSpecImpl : public TypeSpec
{
public:
    /**
     * Constructor.
     * @param form the type form.
     */
    TypeSpecImpl();

    /**
     * Constructor.
     * @param form the type form.
     */
    TypeSpecImpl(TypeForm form);

    /**
     * Constructor.
     * @param value a string value.
     */
    TypeSpecImpl(string value);

    /**
     * Destructor.
     */
    ~TypeSpecImpl();

    /**
     * Getter
     * @return the type form.
     */
    TypeForm get_form() const;

    /**
     * Getter.
     * @return the type identifier (symbol table entry).
     */
    SymTabEntry *get_identifier();

    /**
     * Setter.
     * @param id the type identifier (symbol table entry).
     */
    void set_identifier(SymTabEntry *id);

    /**
     * Set an attribute of the specification.
     * @param key the attribute key.
     * @param value the attribute value.
     */
    void set_attribute(TypeKey key, Object value);

    /**
     * Get the value of an attribute of the specification.
     * @param key the attribute key.
     * @return the attribute value.
     */
    Object get_attribute(TypeKey key);

    /**
     * Implementation of wci::intermediate::TypeSpec.
     * @return true if this is a Pascal string type.
     */
    bool is_pascal_string();

    /**
     * Implementation of wci::intermediate::TypeSpec.
     * @return the base type of this type.
     */
    TypeSpec *base_type();

    static map<TypeFormImpl, string> TYPE_FORM_NAMES;
    static map<TypeKeyImpl,  string> TYPE_KEY_NAMES;

private:
    TypeForm form;
    SymTabEntry *type_id;  // type identifier
    map<TypeKey, Object> contents;

    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::intermediate::typeimpl

#endif /* TYPESPECIMPL_H_ */
