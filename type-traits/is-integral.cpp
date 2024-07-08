#include "gtest/gtest.h"
#include "integral-type.h"

template <typename T>
struct is_integral : false_type {};

template <> struct is_integral<char> : true_type {};
//...
template <> struct is_integral<unsigned int> : true_type {};
//...

template <typename T>
inline constexpr bool is_integral_v = is_integral<T>::value;

TEST(Module2, IsIntegralTest)
{
	ASSERT_EQ(is_integral_v<char*>, false);
	ASSERT_EQ(is_integral_v<char>, true);
	ASSERT_EQ(is_integral_v<unsigned int>, true);
}