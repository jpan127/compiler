/**
 * <h1>TypeSpecImpl</h1>
 *
 * <p>A Pascal type specification implementation.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <map>
#include "TypeSpecImpl.h"
#include "../TypeSpec.h"
#include "../symtabimpl/Predefined.h"

namespace wci { namespace intermediate { namespace typeimpl {

using namespace std;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;

bool TypeSpecImpl::INITIALIZED = false;

map<TypeFormImpl, string> TypeSpecImpl::TYPE_FORM_NAMES;
map<TypeKeyImpl,  string> TypeSpecImpl::TYPE_KEY_NAMES;

void TypeSpecImpl::initialize()
{
    if (INITIALIZED) return;

    vector<TypeFormImpl> form_keys =
    {
        TypeFormImpl::SCALAR,
        TypeFormImpl::ENUMERATION,
        TypeFormImpl::SUBRANGE,
        TypeFormImpl::ARRAY,
        TypeFormImpl::RECORD,
    };

    vector<string> form_names =
    {
        "scalar", "enumeration", "subrange", "array", "record",
    };

    for (int i = 0; i < form_keys.size(); i++)
    {
        TYPE_FORM_NAMES[form_keys[i]] = form_names[i];
    }

    INITIALIZED = true;
}

TypeSpecImpl::TypeSpecImpl() : form((TypeForm) -1), type_id(nullptr)
{
    initialize();
}

TypeSpecImpl::TypeSpecImpl(TypeForm form) : form(form), type_id(nullptr)
{
    initialize();
}

TypeSpecImpl::TypeSpecImpl(string value)
{
    initialize();
    form = (TypeForm) TF_ARRAY;

    TypeSpec *index_type = new TypeSpecImpl((TypeForm) TF_SUBRANGE);
    index_type->set_attribute((TypeKey) SUBRANGE_BASE_TYPE,
                              Predefined::integer_type);
    index_type->set_attribute((TypeKey) SUBRANGE_MIN_VALUE, 1);

    int length = value.length();
    index_type->set_attribute((TypeKey) SUBRANGE_MAX_VALUE, length);

    set_attribute((TypeKey) ARRAY_INDEX_TYPE, index_type);
    set_attribute((TypeKey) ARRAY_ELEMENT_TYPE, Predefined::char_type);
    set_attribute((TypeKey) ARRAY_ELEMENT_COUNT, length);
}

TypeSpecImpl::~TypeSpecImpl()
{
}

TypeForm TypeSpecImpl::get_form() const { return form; }

SymTabEntry *TypeSpecImpl::get_identifier() { return type_id; }

void TypeSpecImpl::set_identifier(SymTabEntry *id) { type_id = id; }

void TypeSpecImpl::set_attribute(TypeKey key, Object value)
{
    contents[key] = value;
}

Object TypeSpecImpl::get_attribute(TypeKey key)
{
    return contents[key];
}

bool TypeSpecImpl::is_pascal_string()
{
    if (form == (TypeForm) TF_ARRAY)
    {
        Object type_value = get_attribute((TypeKey) ARRAY_ELEMENT_TYPE);
        TypeSpec *elmt_type = cast(type_value, TypeSpec*);

        type_value = this->get_attribute((TypeKey) ARRAY_INDEX_TYPE);
        TypeSpec *index_type = cast(type_value, TypeSpec*);

        return (elmt_type->base_type()  == Predefined::char_type) &&
               (index_type->base_type() == Predefined::integer_type);
    }
    else
    {
        return false;
    }
}

/**
 * @return the base type of this type.
 */
TypeSpec *TypeSpecImpl::base_type()
{
    if (form == (TypeForm) TF_SUBRANGE)
    {
        Object type_value = get_attribute((TypeKey) SUBRANGE_BASE_TYPE);
        return cast(type_value, TypeSpec*);
    }
    else return this;
}

}}}  // namespace wci::intermediate::typeimpl
