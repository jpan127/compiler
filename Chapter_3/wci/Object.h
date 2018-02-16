/**
 * <h1>Object</h1>
 *
 * <p>A generic data value.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef OBJECT_H_
#define OBJECT_H_

#include <typeinfo>
#include <boost/any.hpp>
#include <boost/algorithm/string/replace.hpp>

#define Object boost::any
#define instanceof(v, T) (v.type() == typeid(T))
#define cast(v, T) boost::any_cast<T>(v)
#define replace(str, p1, p2) boost::replace_all(str, p1, p2)

std::string stringify(const Object& obj);
std::string to_upper(const std::string str);
std::string to_lower(const std::string str);

#endif /* OBJECT_H_ */
