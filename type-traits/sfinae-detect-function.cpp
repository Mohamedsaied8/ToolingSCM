#include "gtest/gtest.h"
#include "is-same.h"
#include <typeinfo>
#include <iostream>

template <typename T>
struct has_func
{
private: 
	static int detect(...);
public:
	template <typename U>
	static auto detect(U) -> decltype(std::declval<U>().foo(std::declval<U>()));
    
	static constexpr bool value = is_same_v<void, decltype(detect(std::declval<T>()))>;

};

class A
{

};

class B
{
	public:
	void foo(B) {}
};

TEST(Module3, SfinaeDetectFunctionTest)
{
	ASSERT_EQ(false, has_func<A>::value);
	std::cout << "typename " << typeid(decltype(has_func<B>::detect<B>(std::forward<B>(std::declval<B>())))).name() <<"\n";
	ASSERT_EQ(true, has_func<B>::value);
}
