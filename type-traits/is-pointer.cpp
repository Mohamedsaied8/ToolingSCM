#include "gtest/gtest.h"
#include "is-pointer.h"

TEST(Module2, IsPointerTest)
{
	ASSERT_EQ(is_pointer<char>::value, false);
	ASSERT_EQ(is_pointer<char*>::value, true);
	ASSERT_EQ(is_pointer<char const>::value, false);
	ASSERT_EQ(is_pointer<char* const>::value, true);
}