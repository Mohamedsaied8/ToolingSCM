#include "gtest/gtest.h"
#include "is-same.h"
TEST(Module2, IsSameTest)
{
	auto actualTrue = is_same_v<int, int>;
	ASSERT_EQ(actualTrue , true);
	auto actualFalse = is_same_v<int, char>;
	ASSERT_EQ(actualFalse, false);
}

TEST(Module2, IsSameRawTest)
{
	auto actualCVTrue = is_same_raw_v<int, int const volatile>;
	ASSERT_EQ(actualCVTrue, true);
}