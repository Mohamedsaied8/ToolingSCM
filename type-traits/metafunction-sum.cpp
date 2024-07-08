#include "gtest/gtest.h"

template <int X,int Y>
struct IntSum
{
	static constexpr int value = X + Y;
};

template <auto X, auto Y>
struct Sum
{
	static constexpr auto value = X + Y;
};

template<int ...>                                                
struct SumV;

template<>                                                        
struct SumV<> {
	static const int value = 0;
};

template<int i, int ... tail>                                     
struct SumV<i, tail ...> {
	static const int value = i + SumV<tail ...>::value;
};


TEST(Module2, IntSumTest)
{
	auto actualValue = IntSum<5, 2>::value;
	ASSERT_EQ(actualValue, 7);
}

TEST(Module2, SumTest)
{
	auto actualValue = Sum<5, 2>::value;
	ASSERT_EQ(actualValue, 7);
}

TEST(Module2, SumVTest)
{
	auto actualValue = SumV<5, 4, 1>::value;
	ASSERT_EQ(actualValue, 10);
}