#pragma once

#include "integral-type.h"

template <typename T> struct is_null_pointer : false_type {};

template<> struct is_null_pointer<std::nullptr_t> : true_type {};

template<> struct is_null_pointer<std::nullptr_t const> : true_type {};

template <> struct is_null_pointer<std::nullptr_t volatile> : true_type {};

template <> struct is_null_pointer<std::nullptr_t const volatile> : true_type {};

template <typename T>
inline constexpr bool is_null_pointer_t = is_null_pointer<T>::value;

