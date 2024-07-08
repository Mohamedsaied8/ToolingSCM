#include "gtest/gtest.h"
#include <stdexcept>
#include <type_traits>
#include <utility>
template <typename Numerator, typename Denominator,
	std::enable_if_t<std::is_integral_v<Numerator>&&
	std::is_integral_v<Denominator>,
	int> = 0>
auto divide(Numerator numerator, Denominator denominator) {
	// is integer division
	if (denominator == 0) {
		throw std::runtime_error("divide by 0!");
	}
	return numerator / denominator;
}
template <typename Numerator, typename Denominator,
	std::enable_if_t<std::is_floating_point_v<Numerator> ||
	std::is_floating_point_v<Denominator>,
	int> = 0>
auto divide(Numerator numerator, Denominator denominator) {
	// is floating point division
	return numerator / denominator;
}

TEST(Module3, SfinaeDivide)
{
	ASSERT_ANY_THROW(divide(2, 0));
	ASSERT_EQ(std::numeric_limits<double>::infinity() , divide(2.0, 0.0));
}