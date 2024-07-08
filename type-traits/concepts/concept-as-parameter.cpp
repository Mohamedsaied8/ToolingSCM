#include "gtest/gtest.h"

#include <stdexcept>
#include <concepts>

auto divideConceptAsParameter(std::integral auto numerator,
	std::integral auto denominator) {
	// is integer division
	if (denominator == 0) {
		throw std::runtime_error("divide by 0!");
	}	
		return numerator / denominator;
}
auto divideConceptAsParameter(auto numerator, auto denominator) {
	// is floating point division
	return numerator / denominator;
}

TEST(Module3, ConceptAsParameterTest)
{
	ASSERT_ANY_THROW(divideConceptAsParameter(2, 0));
	auto actual = divideConceptAsParameter(2.0, 0.0);
	ASSERT_EQ(std::numeric_limits<double>::infinity(), actual);
}