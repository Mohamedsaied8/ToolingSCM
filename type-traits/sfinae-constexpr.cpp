#include "gtest/gtest.h"
#include <stdexcept>
#include <type_traits>
#include <utility>
template <typename Numerator, typename Denominator>
auto divide2(Numerator numerator, Denominator denominator) {
	if constexpr (std::is_integral_v<Numerator> &&
		std::is_integral_v<Denominator>) {
		// is integral division
		if (denominator == 0) {
			throw std::runtime_error("divide by 0!");
		}
	}
	return numerator / denominator;
}

TEST(Module3, SfinaeDivideConstExpr)
{
	ASSERT_ANY_THROW(divide2(2, 0));
	ASSERT_EQ(std::numeric_limits<double>::infinity(), divide2(2.0, 0.0));
}