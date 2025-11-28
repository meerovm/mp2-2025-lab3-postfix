// тесты для стека

#include "stack.h"
#include <gtest.h>
TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> q());
}

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> q(100));
}
TEST(Stack, can_push_element_to_stack)
{
	Stack<int> q(1);
	ASSERT_NO_THROW(q.Push(12));
}
TEST(Stack, can_check_element_to_stack)
{
	Stack<int> q(1);
	q.Push(1);
	ASSERT_NO_THROW(q.Check());
}
TEST(Stack, can_push_and_check_element_to_stack)
{
	Stack<int> q(1);
	q.Push(1);
	EXPECT_EQ(q.Check(), 1);
}

TEST(Stack, can_push_and_check_element_to_stack_2)
{
	Stack<double> q(1);
	q.Push(2.5);
	double r = q.Check();
	EXPECT_EQ(r, 2.5);
}

TEST(Stack, can_pop_element_to_stack)
{
	Stack<double> q(1);
	q.Push(2.5);
	EXPECT_EQ(q.Pop(), 2.5);
}

TEST(Stack, throw_when_pop_element_to_empty_stack)
{
	Stack<double> q(1);
	ASSERT_ANY_THROW(q.Pop());
}
TEST(Stack, throw_when_check_element_to_empty_stack)
{
	Stack<double> q(1);
	ASSERT_ANY_THROW(q.Check());
}
TEST(Stack, can_get_size)
{
	Stack<double> q(1);
	q.Push(2.5);
	q.Push(2.5);
	EXPECT_EQ(q.CheckSize(), 2);
}

TEST(Stack, correct_get_empty_to_empty_stack)
{
	Stack<double> q(1);
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Stack, correct_get_empty_to_not_empty_stack)
{
	Stack<double> q(1);
	q.Push(2.5);
	EXPECT_EQ(q.IsEmpty(), 0);
}

TEST(Stack, when_pop_element_size_decrease)
{
	Stack<double> q(1);
	q.Push(2.5);
	q.Push(2.5);
	q.Pop();
	EXPECT_EQ(q.CheckSize(), 1);
}

TEST(Stack, correct_clear)
{
	Stack<double> q(1);
	q.Push(2.5);
	q.Clear();
	EXPECT_EQ(q.IsEmpty(), 1);
}
