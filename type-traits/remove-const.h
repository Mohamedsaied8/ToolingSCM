#pragma once
#include "type-indentity.h"
#include "remove-const.h"
template <typename T>

struct remove_const : TypeIndentity<T> {};

template <typename T>
struct remove_const<T const> : TypeIndentity<T> {};

template <typename T>
using remove_const_t = typename remove_const<T>::type;
