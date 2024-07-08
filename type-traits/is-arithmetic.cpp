#include "gtest/gtest.h"
#include "is-arithmetic.h"

TEST(Module2, IsArithmeticTest)
{
	ASSERT_EQ(is_arithmetic<int>::value, true);
	ASSERT_EQ(is_arithmetic<long>::value, true);
	ASSERT_EQ(is_arithmetic<float>::value, true);
	ASSERT_EQ(is_arithmetic<char*>::value, false);
	ASSERT_EQ(is_arithmetic<char&>::value, false);
}