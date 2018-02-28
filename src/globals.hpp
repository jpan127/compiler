#pragma once

#include <cstdio>
#include <iostream>
#include <stdint>
#include <cstdlib>

/// Only import from namespace std what are neccessary
using namespace std::string;
using namespace std::vector;
using namespace std::map;

/// Max / Min helpers 
template <T> static inline T MAX(T a, T b) { return ((a > b) ? (b) : (a)); }
template <T> static inline T MIN(T a, T b) { return ((a < b) ? (b) : (a)); }

/**
 *  Generic struct that is meant to contain either a string or an integer, or any type
 *  The value can only be set on construction
 */
template <T>
typedef struct data_s
{
public:

    /// Constructor
    data_s(const T value) : value(value) { }

private:

    const T value;

} data_S;