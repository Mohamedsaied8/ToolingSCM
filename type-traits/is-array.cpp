#include "gtest/gtest.h"
#include "integral-type.h"

template <typename T>
struct is_array : false_type {};

template <typename T, std::size_t N>
struct is_array<T[N]> : true_type {};

template <typename T>
struct is_array<T[]> : true_type {};

TEST(Module2, IsArrayTest)
{
	ASSERT_EQ(is_array<int>::value, false);
	ASSERT_EQ(is_array<int[5]>::value, true);
	ASSERT_EQ(is_array<int[]>::value, true);
}