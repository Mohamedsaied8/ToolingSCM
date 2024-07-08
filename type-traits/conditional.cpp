#include "gtest/gtest.h"
#include "type-indentity.h"
#include "integral-type.h"

template <bool Condition, typename T, typename F>
struct conditional : TypeIndentity<T> {};

template <typename T, typename F>
struct conditional<false, T, F> : TypeIndentity<F> {};

TEST(Module2, ConditionalTest)
{
	ASSERT_EQ(typeid(conditional<is_void<void>::value, int, long>::type), typeid(int));
	ASSERT_EQ(typeid(conditional<is_void<int>::value, int, long>::type), typeid(long));
}