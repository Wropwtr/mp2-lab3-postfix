#include <gtest.h>
#include "list.h"

TEST(List, can_create_list)
{
  ASSERT_NO_THROW(List<int> *l1 = new List<int>());
}

TEST(List, can_copy_list)
{
  List<int> *l1 = new List<int>();

  l1->insert(5);
  l1->insert(346);

  List<int> *l2 = new List<int>(*l1);
  EXPECT_EQ( ( l1->getFirst()!=l2->getFirst() && l1->getFirst()->key==l2->getFirst()->key) , true );
}

TEST(List,return_first_0_in_empty_stack)
{
  List<int> *l = new List<int>();
  EXPECT_EQ( 0, l->getFirst());
}

TEST(List, throw_then_insert_in_empty)
{
  List<int> *l = new List<int>();
  ASSERT_ANY_THROW(l->insert_a(5,6));
}

TEST(List, can_insert_before_first)
{
  List<int> *l = new List<int>();
  ASSERT_NO_THROW(l->insert(56));
}

TEST(List, can_show_first_element)
{
  List<int> *l = new List<int>();
  l->insert(5);
  Node<int>* buf = l->getFirst();
  EXPECT_EQ(buf->key,5);
}

TEST(List, can_insert_after_element_with_key)
{
  List<int> *l = new List<int>();

  l->insert(5);
  Node<int>* buf = new Node<int>;
  buf->key = 7;
  l->insert_a(5,buf);
  ASSERT_EQ(buf, l->search(7));
}


TEST(List, can_insert_before_element_with_key)
{
  List<int> *l = new List<int>();

  l->insert(5);
  Node<int>* buf = new Node<int>;
  buf->key = 7;
  l->insert_b(5,buf);
  ASSERT_EQ(buf, l->search(7));
}

TEST(List, can_erase_element_with_key)
{
  List<int> *l = new List<int>();

  l->insert(5);
  l->insert(346);
  l->erase(346);
  ASSERT_EQ(0,l->search(346));
}


