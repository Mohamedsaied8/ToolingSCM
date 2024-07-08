#include "gtest/gtest.h"
#include "enable-if.h"
#include "is-arithmetic.h"
#include "is-pointer.h"


int flag = 0;

template <typename T>
typename enable_if<is_arithmetic<T>::value, T>::type foo(T t) { flag = t; return 0; }

template <typename T>
typename enable_if<is_pointer<T>::value, T>::type foo(T t) { flag = 2; return nullptr; }


TEST(Module3, EnableIfTest)
{
	foo(1);
	ASSERT_EQ(flag, 1);
	ASSERT_EQ(foo(1), 0);

	foo("TEST");
	ASSERT_EQ(flag, 2);
	ASSERT_EQ(foo("TEST"), nullptr);
}