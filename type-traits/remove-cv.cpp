#include "gtest/gtest.h"
#include "type-indentity.h"
#include "remove-cv.h"
TEST(Module2, RemoveVolatileTest)
{
	ASSERT_EQ(typeid(remove_volatile_t<int>), typeid(int));
	ASSERT_EQ(typeid(remove_volatile_t<int volatile>), typeid(int));
}

TEST(Module2, RemoveCVTest)
{
	ASSERT_EQ(typeid(remove_cv_t<int const>), typeid(int));
	ASSERT_EQ(typeid(remove_cv_t<int volatile>), typeid(int));
	ASSERT_EQ(typeid(remove_cv_t<int volatile const>), typeid(int));
}