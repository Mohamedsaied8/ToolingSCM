#include "gtest/gtest.h"
#include "is-same.h"
#include "integral-type.h"
#include "is-arithmetic.h"
#include "is-null-pointer.h"
#include "remove-cv.h"

template <typename T>
struct is_fundamental : integral_const<bool,
    is_arithmetic<T>::value ||
    is_void<T>::value ||
    is_same<is_null_pointer<T>, remove_cv_t<T> >::value> {};

class A {};

TEST(Module2, IsFundamentalTest)
{
    ASSERT_EQ(is_fundamental<A>::value, false);
    ASSERT_EQ(is_fundamental<int>::value, true);
    ASSERT_EQ(is_fundamental<int*>::value, false);
    ASSERT_EQ(is_fundamental<int&>::value, false);
    ASSERT_EQ(is_fundamental<float>::value, true);
    ASSERT_EQ(is_fundamental<float*>::value, false);
    ASSERT_EQ(is_fundamental<float&>::value, false);
}
