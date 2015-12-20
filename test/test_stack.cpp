#include "stack.h"

#include <gtest.h>

TEST(Stack, can_create_stack)
{
  ASSERT_NO_THROW( Stack<int> *s = new Stack<int>() );
}

TEST(Stack, throws_then_show_top_in_empty_stack)
{
	Stack<int> *s1 = new Stack<int>();
	ASSERT_ANY_THROW(s1->top());
}

TEST(Stack, throws_then_pop_in_empty_stack)
{
	Stack<int> *s1 = new Stack<int>();
	ASSERT_ANY_THROW(s1->pop());
}


TEST(Stack, can_show_top)
{
	Stack<int> *s1 = new Stack<int>();
	s1->push(5);
	EXPECT_EQ(s1->top(), 5);
}

TEST(Stack, can_copy_stack)
{
	Stack<int> *s1 = new Stack<int>();
	s1->push(5);
	Stack<int> *s2 = new Stack<int>(*s1);
	s1->pop();
	ASSERT_NO_THROW(s2->top());
	//EXPECT_EQ(s2.top(), 5);
}



