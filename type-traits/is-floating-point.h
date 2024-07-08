#pragma once
#include "integral-type.h"

template <typename T> struct is_floating_point : false_type {};
template <> struct is_floating_point<float> : true_type {};
template <> struct is_floating_point<double> : true_type {};
template <> struct is_floating_point<long double> : true_type {};
//...

template <typename T>
inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

