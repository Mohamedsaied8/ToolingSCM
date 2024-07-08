#include "gtest/gtest.h"

template <typename T> concept has_call_operator = requires
{
	&T::operator();
};

template <typename FO>
auto use_function_object(FO obj) requires has_call_operator<FO>
{
	return obj();
}

class FunctionObject
{
public:
	int operator()() { return 2; }
};

TEST(Module3, DefineOwnConceptTest)
{
	FunctionObject x;

	ASSERT_EQ(2, use_function_object(x));
}