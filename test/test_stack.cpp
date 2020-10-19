
#include <gtest.h>

#include "Stack.h"
TEST(Stack, can_create_stack)
{
    ASSERT_NO_THROW(TStack<int>(5));
}

TEST(Stack, cant_create_stack_with_zero_capacity)
{
    ASSERT_ANY_THROW(TStack<int>(0));
}

TEST(Stack, can_push_item_to_stack)
{
    TStack<int> s(5);
    ASSERT_NO_THROW(s.push(1));
}


TEST(Stack, can_pop_item_from_stack)
{
    TStack<int> s(5);
    s.push(1);
    int number = s.pop();
    EXPECT_EQ(number, 1);
}

TEST(Stack, default_stack_is_empty)
{
    TStack<int> s(5);
    EXPECT_EQ(s.is_empty(), true);
}

TEST(Stack, item_pop_makes_stack_empty)
{
    TStack<int> s(5);
    s.push(1);
    int number = s.pop();
    EXPECT_EQ(s.is_empty(), true);
}

TEST(Stack, stack_with_items_is_not_empty)
{
    TStack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.is_empty(), false);
}

TEST(Stack, item_push_makes_stack_full)
{
    TStack<int> s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.is_full(), true);
}

TEST(Stack, cant_add_item_to_full_stack)
{
    TStack<int> s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    ASSERT_ANY_THROW(s.push(4));
}

TEST(Stack, cant_pop_item_from_empty_stack)
{
    TStack<int> s(1);
    s.push(1);
    s.pop();
    ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_get_max_element)
{
    TStack<int> s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.get_max(), 3);

}

TEST(Stack, can_get_least_element)
{
    TStack<int> s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.get_least(), 1);
}

