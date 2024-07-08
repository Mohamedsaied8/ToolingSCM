#include "gtest/gtest.h"
#include "LambdaDemo.h"
#include <functional>

class Func
{
	int value;
public:
	Func(int v) : value(v) {}
	int operator()() {return value;}
};

TEST(Module1,FunctionalObject)
{
	Func x(10);
	ASSERT_EQ(x(),10);
}
//-------------------------------------------------------------------------------------------------
TEST(Module1,SimpleLambda)
{
	int value=5;
	auto f1 = [&](int k) { return (value = k),k+2;};
	ASSERT_EQ(f1(2),4);
	ASSERT_EQ(value,2);

	auto f2 = [=](int k) { return k-2+value;};
	ASSERT_EQ(f2(4),4);
}
//-------------------------------------------------------------------------------------------------
class FooLambda
{
	int value;
public:
	FooLambda(int v) : value(v) {}
    std::function<int()> GetLambda();
};

std::function<int()> FooLambda::GetLambda()
{
	return [this]() { return value;};
}

TEST(Module1,LambdaCaptureProperties)
{
	FooLambda a(2),b(3);
	auto f1 = a.GetLambda();
	auto f2 = b.GetLambda();
	ASSERT_EQ(f1(),2);
	ASSERT_EQ(f2(),3);
}
//---------------------------------------
class FooAuto
{
public:
	int k;
	FooAuto(int a): k(a) {}
	FooAuto operator+(int v) {return FooAuto(k + v);}
};
TEST(Module1,LambdaWithAuto)
{
	auto f = [] (auto x) { return x+2;};
	int actualInt = f(2);
	ASSERT_EQ(actualInt,4);
	FooAuto actualFoo = f(FooAuto(3));
	ASSERT_EQ(actualFoo.k,5);
}

TEST(Module1, LamdaAsTemplateParameter)
{
	bool flag = false;
	Process p([&] { flag = true; });
	p.Exec();
	ASSERT_TRUE(flag);
}