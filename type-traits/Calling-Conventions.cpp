#include "gtest/gtest.h"

template <auto X>
struct ValueIndentity
{
	static constexpr auto value = X;
};

template <auto X>
inline constexpr auto ValueIdentity_v = ValueIndentity<X>::value;

template<typename T>
struct TypeIndentity
{
	using type =  T;
};

template <typename T>
using TypeIndentity_t = typename TypeIndentity<T>::type;

TEST(Module2, CallingConventions_V)
{
	ASSERT_EQ(ValueIdentity_v<42>, 42);
}

TEST(Module2, CallingConventions_T)
{
	ASSERT_EQ(typeid(TypeIndentity_t<int>), typeid(int));
}