#include "gtest/gtest.h"
#include "is-null-pointer.h"
TEST(Module2, NullPointerTest)
{
	ASSERT_EQ(is_null_pointer_t<int*>, false);
	ASSERT_EQ(is_null_pointer_t<nullptr_t>, true);
	ASSERT_EQ(is_null_pointer_t<nullptr_t const>, true);
	ASSERT_EQ(is_null_pointer_t<nullptr_t const volatile>, true);
	ASSERT_EQ(is_null_pointer_t<nullptr_t volatile>, true);
}