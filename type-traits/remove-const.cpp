#include "gtest/gtest.h"
#include "type-indentity.h"
#include "remove-const.h"
TEST(Module2, RemoveConstTest)
{
	ASSERT_EQ(typeid(remove_const<const int>::type), typeid(int));
	ASSERT_EQ(typeid(remove_const<const volatile int>::type), typeid(volatile int));
	ASSERT_EQ(typeid(remove_const<int>::type), typeid(int));

	ASSERT_EQ(typeid(remove_const_t<int>), typeid(int));
	ASSERT_EQ(typeid(remove_const_t<const int>), typeid(int));
}
