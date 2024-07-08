#pragma once

template<typename T>
struct TypeIndentity
{
	using type = T;
};

template <typename T>
using TypeIndentity_t = typename TypeIndentity<T>::type;