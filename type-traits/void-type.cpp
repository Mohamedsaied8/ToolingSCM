#include "gtest/gtest.h"
#include "integral-type.h"


TEST(Module2, VoidTest)
{
	ASSERT_EQ(is_void<int>::value, false);
	ASSERT_EQ(is_void<void>::value, true);
}

TEST(Module2, VoidConstVolatileTest)
{
	ASSERT_EQ(is_void<void const>::value, true);
	ASSERT_EQ(is_void<void volatile>::value, true);
}