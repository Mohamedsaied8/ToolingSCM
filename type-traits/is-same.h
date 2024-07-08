#pragma once
#include "integral-type.h"
#include "integral-type.h"
#include "remove-cv.h"

template <typename T1, typename T2>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T> : true_type {};

template <typename T1, typename T2>
constexpr bool is_same_v = is_same<T1, T2>::value;

template <typename T1, typename T2>
using is_same_raw = is_same<remove_cv_t<T1>, remove_cv_t<T2>>;

template <typename T1, typename T2>
constexpr static bool is_same_raw_v = is_same_raw<T1, T2>::value;
