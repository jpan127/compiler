#pragma once

#include <cstdio>
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

/// Only import from namespace std what are neccessary
using std::string;
using std::vector;
using std::map;
using std::cout;
using std::endl;

/// Max / Min helpers 
template <typename T> static inline T MAX(T a, T b) { return ((a > b) ? (b) : (a)); }
template <typename T> static inline T MIN(T a, T b) { return ((a < b) ? (b) : (a)); }

/**
 *  Generic constant struct that is meant to contain either a string or an integer, or any type
 *  @note : The value can only be set on construction
 */
template <typename T>
struct data_S
{
public:

    /// Constructor
    data_S(const T value) : value(value) { }

private:

    const T value;

};
