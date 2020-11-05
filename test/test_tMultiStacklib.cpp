#include <../gtest/gtest.h>
#include "MultiStack.h"

TEST(MultiStack, can_create_MultiStack_with_positive_length) {
	ASSERT_NO_THROW(MultiStack<int> tmp(5, 4));
}

TEST(MultiStack, cant_create_MultiStack_with_null) {
	ASSERT_ANY_THROW(MultiStack<int> tmp(0));
}

TEST(MultiStack, check_empty_MultiStack) {
	MultiStack<int> tmp(5, 4);
	EXPECT_EQ(true, tmp.IsEmpty(1));
}

TEST(MultiStack, check_for_non_existent_empty_MultiStack) {
	MultiStack<int> tmp(5, 4);
	ASSERT_ANY_THROW(tmp.IsEmpty(5));
}

TEST(MultiStack, check_negative_empty_MultiStack) {
	MultiStack<int> tmp(5, 4);
	ASSERT_ANY_THROW(tmp.IsEmpty(-5));
}

TEST(MultiStack, check_IsFull_MultiStack) {
	MultiStack<int> tmp(5, 4);
	EXPECT_EQ(false, tmp.IsFull(1));
}

TEST(MultiStack, check_for_non_existent_IsFull_MultiStack) {
	MultiStack<int> tmp(5, 4);
	ASSERT_ANY_THROW(tmp.IsFull(5));
}

TEST(MultiStack, check_negative_IsFull_MultiStack) {
	MultiStack<int> tmp(5, 4);
	ASSERT_ANY_THROW(tmp.IsFull(-5));
}

TEST(MultiStack, can_push_with_mem) {
	MultiStack<int> tmp(5, 4);
	ASSERT_NO_THROW(tmp.PushMultiStack(10, 1));
}

TEST(MultiStack, cant_push_with_no_mem) {
	MultiStack<int> tmp(5, 4);
	ASSERT_ANY_THROW(tmp.PushMultiStack(10, 5));
}

TEST(MultiStack, can_copy_stack) {
	MultiStack<int> tmp1(5, 4);
	tmp1.PushMultiStack(10, 1);

	ASSERT_NO_THROW(MultiStack<int> tmp2(tmp1));
}

TEST(MultiStack, can_assing_stack) {
	MultiStack<int> tmp1(5, 4);
	tmp1.PushMultiStack(10, 1);
	MultiStack<int> tmp2(5, 4);
	tmp2 = tmp1;

	EXPECT_EQ(10, tmp2.GetMultiStack(1));
}

TEST(MultiStack, can_get) {
	MultiStack<int> tmp(5, 4);
	tmp.PushMultiStack(10, 1);

	ASSERT_NO_THROW(tmp.GetMultiStack(1));
}

TEST(MultiStack, cant_get_nonexistent) {
	MultiStack<int> tmp(5, 4);
	tmp.PushMultiStack(10, 1);

	ASSERT_ANY_THROW(tmp.GetMultiStack(-4));
}

TEST(MultiStack, cant_get_negative) {
	MultiStack<int> tmp1(5, 4);
	tmp1.PushMultiStack(10, 1);

	ASSERT_ANY_THROW(tmp1.GetMultiStack(5));
}

TEST(MultiStack, can_GetLen) {
	MultiStack<int> tmp1(5, 4);
	ASSERT_NO_THROW(tmp1.GetLen());
}

TEST(MultiStack, can_Relength) {
	MultiStack<int> tmp1(1, 1);
	tmp1.PushMultiStack(10, 0);

	ASSERT_NO_THROW(tmp1.Relength(5, 0));
}

TEST(MultiStack, cant_Relength_negative) {
	MultiStack<int> tmp1(1, 1);
	tmp1.PushMultiStack(10, 0);

	ASSERT_ANY_THROW(tmp1.Relength(-1, 0));
}

TEST(MultiStack, can_Relocation) {
	MultiStack<int> tmp(9, 3);
	tmp.PushMultiStack(11, 0);
	tmp.PushMultiStack(12, 1);
	tmp.PushMultiStack(12, 1);
	tmp.PushMultiStack(12, 1);

	ASSERT_NO_THROW(tmp.PushMultiStack(15, 1));
}
