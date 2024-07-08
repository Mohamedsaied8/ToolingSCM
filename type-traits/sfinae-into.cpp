#include "gtest/gtest.h"

struct Foo
{
	typedef int bar;
};

template <typename T>
int DoIt(typename T::bar)
{
	return 0;
}

template <typename T>
int DoIt(T)
{
	return 2;
}

TEST(Module3, SfinaeIntroTest)
{
	ASSERT_EQ(DoIt<Foo>(10), 0);
	ASSERT_EQ(DoIt<int>(10), 2);
}