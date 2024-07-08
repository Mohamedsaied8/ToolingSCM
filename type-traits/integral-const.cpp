#include "gtest/gtest.h"
#include "integral-type.h"

TEST(Module2, integral_constTest)
{
	auto actual = integral_const<int, 42>();
	ASSERT_EQ(actual, 42);
	ASSERT_EQ(actual(), 42);
	ASSERT_EQ((integral_const<int, 42>)actual,42);
	ASSERT_EQ(typeid(integral_const<int, 42>::type), typeid(integral_const<int,42>));
}
 
TEST(Module2, TypeConvernsion)
{
	auto actual = integral_const<int, 11>();
	int value = actual; //int value = actual.operator_value_type();

	ASSERT_EQ(value, 11);
}

TEST(Module2, BoolTest)
{
	ASSERT_EQ(true_type(), true);
	ASSERT_EQ(false_type(), false);
	ASSERT_EQ(true_type::value, true);
	ASSERT_EQ(false_type::value, false);
}

TEST(Module2, UseExlamationMark)
{
	ASSERT_EQ(!true_type(), false);
}