#pragma once

#include "integral-type.h"
#include "remove-cv.h"

template <typename T>
struct is_pointer_impl : false_type {};

template <typename T>
struct is_pointer_impl<T*> : true_type {};

template <typename T>
using is_pointer = is_pointer_impl<remove_cv_t<T>>;
