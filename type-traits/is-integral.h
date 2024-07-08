#pragma once

#include "integral-type.h"

template <typename T>
struct is_integral : false_type {};

template <>
struct is_integral<bool> : true_type {};

template <>
struct is_integral<char> : true_type {};

template <>
struct is_integral<short> : true_type {};

template <>
struct is_integral<int> : true_type {};

template <>
struct is_integral<long> : true_type {};

template <>
struct is_integral<long long> : true_type {};

