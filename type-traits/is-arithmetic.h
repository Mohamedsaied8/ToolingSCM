#pragma once
#include "is-floating-point.h"
#include "is-integral.h"

template <typename T>
struct is_arithmetic : integral_const<bool,
	is_floating_point<T>::value ||
	is_integral<T>::value> {};

