#include "gtest/gtest.h"
#include <type_traits>

template <typename T>
struct TypeIdentity
{
	using type = T;
};

TEST(Module2, TypeIdentityTest)
{
	ASSERT_EQ(typeid(TypeIdentity<int>::type), typeid(int));
	ASSERT_EQ(typeid(std::type_identity<int>::type), typeid(int));
}