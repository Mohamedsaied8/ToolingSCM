#pragma once

template <typename T, T V>
struct integral_const
{
	static constexpr T value = V;
	using value_type = T;
	using type = integral_const<T, V>;

	constexpr operator value_type() const noexcept
	{
		return value;
	}
	constexpr value_type operator()() const noexcept
	{
		return value;
	}
};
template<bool B>
using bool_constant = integral_const<bool, B>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template <typename T>
struct is_void : false_type {};

template <>
struct is_void<void> : true_type {};

template<>
struct is_void<void const> : true_type {};

template<>
struct is_void<void volatile> : true_type {};
