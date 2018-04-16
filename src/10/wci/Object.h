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

#define Object boost::any
#define instanceof(v, t) (v.type() == typeid(t))
#define cast(v, t) boost::any_cast<t>(v)

std::string stringify(const Object& obj);
std::string to_upper(const std::string str);
std::string to_lower(const std::string str);

#endif /* OBJECT_H_ */
