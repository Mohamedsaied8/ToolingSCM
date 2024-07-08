#include "gtest/gtest.h"
#include "is-floating-point.h"
TEST(Module2, ISFloatingPointTest)
{
	ASSERT_EQ(is_floating_point_v<long>, false);
	ASSERT_EQ(is_floating_point_v<float>, true);
	ASSERT_EQ(is_floating_point_v<long double>, true);
	ASSERT_EQ(is_floating_point_v<double>, true);
}