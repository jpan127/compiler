#pragma once

#include <cstdint>
#include <typeinfo>
#include <boost/any.hpp>
#include <boost/algorithm/string/replace.hpp>

#define Object                   boost::any
#define INSTANCE_OF(v, T)        (v.type() == typeid(T))
#define CAST(v, T)               boost::any_cast<T>(v)
#define REPLACE(str, p1, p2)     boost::replace_all(str, p1, p2)
#define STRINGIFY(enum)          (#enum)

std::string stringify(const Object& obj);
std::string to_upper(const std::string str);
std::string to_lower(const std::string str);
