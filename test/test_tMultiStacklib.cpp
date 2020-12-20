#include <../gtest/gtest.h>
#include "MultiStack.h"

TEST(NewStack, Newstack){
	int* tmp = 0;

	ASSERT_NO_THROW(TNewStack<int>(5, tmp));
}

TEST(NewStack, NewstackNegativeLength){
	int* tmp = 0;
	ASSERT_ANY_THROW(TNewStack<int>(-5, tmp));
}

TEST(NewStack, NewstackCOP){
	int* tmp = 0;
	TNewStack<int> newstack1(5, tmp);

	ASSERT_NO_THROW(TNewStack<int> newstack2(newstack1));
}

TEST(NewStack, SetMultistack){
	int* tmp1 = new int[5];
	int* tmp2 = new int[5];
	TNewStack<int> newstack(5, tmp1);

	newstack.SetM(6, tmp2);

	EXPECT_EQ(6, newstack.GetLength());
}

TEST(NewStack, GetFreeMem){
	int* tmp = new int[5];
	TNewStack<int> newstack(5, tmp);

	newstack.Push(1);
	newstack.Push(2);
	newstack.Push(3);

	EXPECT_EQ(2, newstack.GetFreeMem());
}

TEST(NewStack, GetLength){
	int* tmp = 0;
	TNewStack<int> newstack(5, tmp);

	EXPECT_EQ(5, newstack.GetLength());
}

TEST(MultiStack, Multistack){
	ASSERT_NO_THROW(TMStack<int>(5, 10));
}

TEST(MultiStack, MultistackNegariveLength){
	ASSERT_ANY_THROW(TMStack<int>(5, -10));
}

TEST(MultiStack, MultistackCOP){
	TMStack<int> multistack1(5, 10);

	ASSERT_NO_THROW(TMStack<int>multistack2(multistack1));
}

TEST(MultiStack, PushElem){
	TMStack<int> multistack(5, 25);

	ASSERT_NO_THROW(multistack.SetElem(1, 2));
}

TEST(MultiStack, GetLength){
	TMStack<int> multistack(5, 10);

	EXPECT_EQ(10, multistack.GetLength());
}

TEST(MultiStack, GetElem){
	TMStack<int> multistack(5, 10);

	multistack.SetElem(1, 6);

	EXPECT_EQ(6, multistack.GetElem(1));
}

TEST(MultiStack, Repack){
	TMStack<int> multistack(2, 6);

	multistack.SetElem(0, 6);
	multistack.SetElem(0, 5);
	multistack.SetElem(1, 2);

	ASSERT_NO_THROW(multistack.SetElem(0, 4));
	EXPECT_EQ(4, multistack.GetElem(0));
}

TEST(MultiStack, IsEmpty){
	TMStack<int> multistack(5, 10);

	ASSERT_TRUE(multistack.IsEmpty(0));
}

TEST(MultiStack, NoIsEmpty){
	TMStack<int> multistack(5, 10);

	multistack.SetElem(0, 1);

	ASSERT_FALSE(multistack.IsEmpty(0));
}

TEST(MultiStack, IsFull){
	TMStack<int> multistack(5, 25);

	multistack.SetElem(0, 1);
	multistack.SetElem(0, 2);
	multistack.SetElem(0, 3);
	multistack.SetElem(0, 4);
	multistack.SetElem(0, 5);

	ASSERT_TRUE(multistack.IsFull(0));
}

TEST(MultiStack, NoIsFull){
	TMStack<int> multistack(5);

	ASSERT_FALSE(multistack.IsFull(0));
}

TEST(MultiStack, GetElement){
	TMStack<int> multistack(5, 10);

	multistack.SetElem(0, 10);
	multistack.SetElem(0, 9);
	multistack.SetElem(0, 8);

	EXPECT_EQ(8, multistack.GetElem(0));
}