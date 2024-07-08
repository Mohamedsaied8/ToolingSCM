#include "gtest/gtest.h"
#include "is-integral.h"
#include "enable-if.h"
struct A { int v; };

template <typename T>
enable_if<is_integral<T>::value, T>::type DoIt()
{
	return 1;
}


template <typename T>
enable_if<!is_integral<T>::value, T>::type DoIt()
{
	A x{ 2 };
	return x;
}

TEST(Module3, EnableIfAndSfinae)
{
	ASSERT_EQ(1, DoIt<int>());
	ASSERT_EQ(2, DoIt<A>().v);
}