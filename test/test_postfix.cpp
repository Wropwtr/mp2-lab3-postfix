#include "postfix.h"
#include <gtest.h>

map<char, double> getTestMap(){
    map<char, double> testMap;
	testMap['A'] = 1;
	testMap['B'] = 2;
	testMap['C'] = 3;
	testMap['D'] = 4;
	testMap['F'] = 7;
	testMap['G'] = 2;
	testMap['H'] = 5;

    return testMap;
}

TEST(Postfix, can_get_priority)
{
	EXPECT_EQ( getPriority('*'), 3);
}

TEST(Postfix, can_return_one_char)
{
	EXPECT_EQ("5", toPost("5"));
}

TEST(Postfix, throws_then_few_brackets)
{
	ASSERT_ANY_THROW(toPost("A+(B-C"));
}

TEST(Postfix, throws_then_many_brackets)
{
	ASSERT_ANY_THROW(toPost("A+(B-C))"));
}

TEST(Postfix, can_return_postfix_1)
{
	EXPECT_EQ("AB+", toPost("A+B"));
}

TEST(Postfix, can_return_postfix_2)
{
	EXPECT_EQ("AB3/+", toPost("A+B/3"));
}

TEST(Postfix, can_return_postfix_3)
{
	EXPECT_EQ("ABC-D*+FGH+/-", toPost("A+(B-C)*D-F/(G+H)"));
}

// END of "toPost" tests

TEST(Postfix, throw_then_get_bad_string)
{
	ASSERT_ANY_THROW(postRez(" # % @",getTestMap()));
}

TEST(Postfix, throw_then_many_operands_1)
{
	string s = toPost("A++B");
	ASSERT_ANY_THROW(postRez(s, getTestMap()));
}

TEST(Postfix, throw_then_many_operands_2)
{
	string s = toPost("A+B+");
	ASSERT_ANY_THROW(postRez(s, getTestMap()));
}

TEST(Postfix, throw_then_many_operands_3)
{
	string s = toPost("+A+B");
	ASSERT_ANY_THROW(postRez(s, getTestMap()));
}

TEST(Postfix, throw_then_few_operands)
{
	string s = toPost("A+BC");
	ASSERT_ANY_THROW(postRez(s, getTestMap()));
}

TEST(Postfix, throws_then_get_empty_string)
{
	ASSERT_ANY_THROW(postRez("",getTestMap()));
}

TEST(Postfix, throws_then_get_bad_postfix_string_1)
{
	ASSERT_ANY_THROW(postRez("@# ",getTestMap()));
}

TEST(Postfix, throws_then_get_bad_postfix_string_2)
{
	ASSERT_ANY_THROW(postRez("A+",getTestMap()));
}

TEST(Postfix, throws_then_divide_on_zero)
{
	ASSERT_ANY_THROW(postRez("5/0",getTestMap()));
}

TEST(Postfix, can_calculate_1)
{
	EXPECT_EQ(5, postRez("51*",getTestMap()));
}

TEST(Postfix, can_calculate_2)
{
	EXPECT_EQ(3, postRez("AB+",getTestMap()));
}

TEST(Postfix, can_calculate_3)
{
	EXPECT_EQ(7, postRez("ABC*+",getTestMap()));
}

TEST(Postfix, can_calculate_4)
{
	string s = toPost("A+(B-C)*D-F/(G+H)");
	EXPECT_EQ(-4, postRez(s, getTestMap()));
}

TEST(Postfix, test_string_with_equal_char)
{
	string s = toPost("X=A+B");
	EXPECT_EQ(3, postRez(s, getTestMap()));
}