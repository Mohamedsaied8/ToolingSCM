#pragma once
#include "remove-const.h"
#include "type-indentity.h"

template <typename T>
struct remove_volatile : TypeIndentity<T> {};

template <typename T>
struct remove_volatile<T volatile> : TypeIndentity<T> {};

template <typename T>
using remove_volatile_t = remove_volatile<T>::type;

template <typename T>
using remove_cv = remove_const<remove_volatile_t<T>>;

template <typename T>
using remove_cv_t = remove_cv<T>::type;
