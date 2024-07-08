#include "gtest/gtest.h"
#include "folding-expression.h"

TEST(Module1, UnaryFoldingExpression)
{
	int actual = FoldingSum1(1, 2, 3, 4, 5);
	ASSERT_EQ(15, actual);
}

TEST(Module1, BinaryFoldingExpression)
{
	int actual = FoldingSum2(1, 2, 3, 4, 5);
	ASSERT_EQ(15, actual);
}