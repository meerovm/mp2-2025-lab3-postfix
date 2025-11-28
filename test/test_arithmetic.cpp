// тесты для вычисления арифметических выражений

#include <gtest.h>
#include <arithmetic.h>
#include <math.h>
TEST(arithmetic, can_create_arithmetic)
{
	ASSERT_NO_THROW(arithmetic("x"));
}

TEST(arithmetic, can_create_arithmetic_1)
{
	ASSERT_NO_THROW(arithmetic("2"));
}

TEST(arithmetic, can_create_arithmetic_2)
{
	ASSERT_NO_THROW(arithmetic("-2"));
}

TEST(arithmetic, can_create_arithmetic_3)
{
	ASSERT_NO_THROW(arithmetic("2.15"));
}

TEST(arithmetic, can_create_arithmetic_4)
{
	ASSERT_NO_THROW(arithmetic("0.15"));
}

TEST(arithmetic, can_create_arithmetic_5)
{
	ASSERT_NO_THROW(arithmetic("-0.123"));
}

TEST(arithmetic, can_create_arithmetic_6)
{
	ASSERT_NO_THROW(arithmetic("2+3"));
}

TEST(arithmetic, can_create_arithmetic_7)
{
	ASSERT_NO_THROW(arithmetic("2-3"));
}

TEST(arithmetic, can_create_arithmetic_8)
{
	ASSERT_NO_THROW(arithmetic("2*3"));
}

TEST(arithmetic, can_create_arithmetic_9)
{
	ASSERT_NO_THROW(arithmetic("2/3"));
}

TEST(arithmetic, can_create_arithmetic_10)
{
	ASSERT_NO_THROW(arithmetic("sin(2)"));
}

TEST(arithmetic, can_create_arithmetic_11)
{
	ASSERT_NO_THROW(arithmetic("cos(2)"));
}

TEST(arithmetic, can_create_arithmetic_12)
{
	ASSERT_NO_THROW(arithmetic("log(2)"));
}

TEST(arithmetic, can_create_arithmetic_13)
{
	ASSERT_NO_THROW(arithmetic("exp(2)"));
}

TEST(arithmetic, can_create_arithmetic_14)
{
	ASSERT_NO_THROW(arithmetic("sin(cos(2)+1)"));
}

TEST(arithmetic, can_create_arithmetic_15)
{
	ASSERT_NO_THROW(arithmetic("3*(2+2)"));
}

TEST(arithmetic, can_create_arithmetic_16)
{
	ASSERT_NO_THROW(arithmetic("(2+2)*3"));
}

TEST(arithmetic, can_calc_1)
{
	auto q = arithmetic("2");
	EXPECT_EQ(q.calc(), 2);
}

TEST(arithmetic, can_calc_2)
{
	auto q = arithmetic("-2");
	EXPECT_EQ(q.calc(), -2);
}

TEST(arithmetic, can_calc_3)
{
	auto q = arithmetic("0.123");
	EXPECT_EQ(q.calc(), 0.123);
}

TEST(arithmetic, can_calc_4)
{
	auto q = arithmetic("2+3");
	EXPECT_EQ(q.calc(), 5);
}

TEST(arithmetic, can_calc_5)
{
	auto q = arithmetic("2-3");
	EXPECT_EQ(q.calc(), -1);
}

TEST(arithmetic, can_calc_6)
{
	auto q = arithmetic("2*3");
	EXPECT_EQ(q.calc(), 6);
}

TEST(arithmetic, can_calc_7)
{
	auto q = arithmetic("2/3");
	EXPECT_EQ(q.calc(), ((double) 2)/3);
}

TEST(arithmetic, can_calc_8)
{
	auto q = arithmetic("2+3/4");
	EXPECT_EQ(q.calc(), 2+ ((double)3) / 4);
}

TEST(arithmetic, can_calc_9)
{
	auto q = arithmetic("2/(3+4)");
	EXPECT_EQ(q.calc(), ((double)2) / (3 + 4));
}

TEST(arithmetic, can_calc_10)
{
	auto q = arithmetic("sin(0)");
	EXPECT_EQ(q.calc(), 0);
}

TEST(arithmetic, can_calc_11)
{
	auto q = arithmetic("cos(0)");
	EXPECT_EQ(q.calc(), 1);
}

TEST(arithmetic, can_calc_12)
{
	auto q = arithmetic("exp(2)");
	EXPECT_EQ(q.calc(), exp(2));
}

TEST(arithmetic, can_calc_13)
{
	auto q = arithmetic("exp(1+2)");
	EXPECT_EQ(q.calc(), exp(3));
}

TEST(arithmetic, can_calc_14)
{
	auto q = arithmetic("log(1+2)");
	EXPECT_EQ(q.calc(), log(3));
}

TEST(arithmetic, can_calc_15)
{
	auto q = arithmetic("x-z");
	q.x = 1;
	q.z = 12;
	q.flag_x = 1;
	q.flag_z = 1;
	EXPECT_EQ(q.calc(), 1 - 12);
}

TEST(arithmetic, can_calc_16)
{
	auto q = arithmetic("cos(sin(z/(x-z)))");
	q.x = 1;
	q.z = 12;
	q.flag_x = 1;
	q.flag_z = 1;
	double x = 1;
	double z = 12;
	EXPECT_EQ(q.calc(), cos(sin(z / (x - z))));
}
