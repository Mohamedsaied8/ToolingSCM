#include "gtest/gtest.h"
#include "integral-type.h"

template <typename T>
struct is_lvalue_reference : false_type {};

template <typename T>
struct is_lvalue_reference<T&> : true_type {};

template <typename T>
struct is_rvalue_reference : false_type {};

template <typename T>
struct is_rvalue_reference<T&&> : true_type {};

TEST(Module2, LValueReferenceTest)
{
	ASSERT_EQ(is_lvalue_reference<int>::value, false);
	ASSERT_EQ(is_lvalue_reference<int&>::value, true);
	ASSERT_EQ(is_lvalue_reference<int&&>::value, false);
}

TEST(Module2, RValueReferenceTest)
{
	ASSERT_EQ(is_rvalue_reference<int>::value, false);
	ASSERT_EQ(is_rvalue_reference<int&>::value, false);
	ASSERT_EQ(is_rvalue_reference<int&&>::value, true);
}