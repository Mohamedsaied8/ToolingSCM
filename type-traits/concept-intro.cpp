#include "gtest/gtest.h"

#include <stdexcept>
#include <type_traits>
#include <utility>

template <typename Numerator, typename Denominator>
auto divideConcept(Numerator numerator, Denominator denominator) requires
(std::is_integral_v<Numerator>
	&& std::is_integral_v<Denominator>) {
	// is integral division
	if (denominator == 0) {
		throw std::runtime_error("divide by 0!");
	}
	return numerator / denominator;
}
template <typename Numerator, typename Denominator>
auto divideConcept(Numerator numerator, Denominator denominator) {
	return numerator / denominator;
}

TEST(Module3, ConceptIntroTest)
{
	ASSERT_ANY_THROW(divideConcept(2, 0));
	auto actual = divideConcept(2.0, 0.0);
	ASSERT_EQ(std::numeric_limits<double>::infinity(), actual);
}