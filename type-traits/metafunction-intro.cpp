#include "gtest/gtest.h"

template <int X>
struct IntIdentity
{
	static constexpr int value = X;
};

template <typename T>
struct Echo
{
	using type = T;
};

template <typename T, T Value>
struct ValueIndentity
{
	static constexpr T value = Value;
	using type = T;
};

template <auto X>
struct ValueIdentityAuto
{
	static constexpr auto value = X;
};

TEST(Module2, IntIdentityTest)
{
	ASSERT_EQ(IntIdentity<42>::value, 42);
}
TEST(Module2, EchoTest)
{
	ASSERT_EQ(typeid(Echo<int>::type), typeid(int));
}

TEST(Module2, ValueIndentityTest)
{
	auto actualValue = ValueIndentity<int, 42>::value;
	ASSERT_EQ(actualValue, 42);
	ASSERT_EQ(typeid(ValueIndentity<int, 42>::type), typeid(int));
}
TEST(Module2, ValueIdentityAutoTest)
{
	auto actualValue = ValueIdentityAuto<42>::value;
	ASSERT_EQ(actualValue, 42);
}