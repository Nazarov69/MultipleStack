#pragma once
#include "NewStack.h"
#include "MyException.h"

template <class ValType>
class TMStack{
protected:
	int count;
	int length;
	ValType* mas;
	TNewStack<ValType>** mStack;
	int CountFree();
	void Repack(int num);
public:
	TMStack(int count = 1, int length = 5);
	TMStack(TMStack<ValType>& v);
	~TMStack();

	int GetLength();
	void SetElem(int count, ValType elem);
	ValType GetElem(int count);

	bool IsFull(int count);
	bool IsEmpty(int count);
};

template <class ValType>
TMStack<ValType>::TMStack(int count, int length){
	if (count <= 0 || length <= 0)
		throw TMyException("Error! Incorrect size or number of stack! \n");
	else{
		this->count = count;
		this->length = length;
		mStack = new TNewStack<ValType> * [count];
		mas = new ValType[length];
		int* tmp1 = new int[count];

		for (int i = 0; i < count; i++)
			tmp1[i] = length / count;

		tmp1[0] += length % count;
		ValType** tmp2 = new ValType * [count];
		tmp2[0] = mas;

		for (int i = 1; i < count; i++)
			tmp2[i] = tmp2[i - 1] + tmp1[i - 1];

		for (int i = 0; i < count; i++)
			mStack[i] = new TNewStack<ValType>(tmp1[i], tmp2[i]);
	}
}

template <class ValType>
TMStack<ValType>::TMStack(TMStack<ValType>& v){
	this->count = v.count;
	this->length = v.length;
	if (length == 0){
		mas = nullptr;
		mStack = nullptr;
	}
	else{
		mas = new ValType[length];
		for (int i = 0; i < length; i++)
			this->mas[i] = v.mas[i];

		mStack = new TNewStack<ValType> * [count];
		int* tmp1 = new int[count];
		for (int i = 0; i < count; i++)
			tmp1[i] = v.mStack[i]->GetLength();

		ValType** tmp2 = new ValType * [count];
		tmp2[0] = mas;
		for (int i = 0; i < count; i++)
			tmp2[i] = tmp1[i - 1] + tmp2[i - 1];
		for (int i = 0; i < count; i++){
			mStack[i] = new TNewStack<ValType>(*v.mStack[i]);
			mStack[i]->SetM(tmp1[i], tmp2[i]);
		}
	}
}

template <class ValType>
TMStack<ValType>::~TMStack(){
	if (mas != 0)
		delete[] mas;
	mas = nullptr;
}

template <class ValType>
int TMStack<ValType>::GetLength(){
	return length;
}

template <class ValType>
void TMStack<ValType>::SetElem(int count, ValType elem){
	if (count < 0 || count >= this->count)
		throw TMyException("Error! Index is out of range!\n");
	else if (this->CountFree() == 0)
		throw TMyException("Error! No free mem!\n");
	else if (IsFull(count))
		Repack(count);
	mStack[count]->PutElem(elem);
}

template <class ValType>
ValType TMStack<ValType>::GetElem(int count){
	if (count < 0 || count >= this->count)
		throw TMyException("Error! Index is out of range!\n");
	if (IsEmpty(count))
		throw TMyException("Error! MultiStack is empty!\n");
	return mStack[count]->Get();
}

template <class ValType>
bool TMStack<ValType>::IsFull(int count){
	if (count < 0 || count >= this->count)
		throw TMyException("Error! Index is out of range!\n");
	else
		return (mStack[count]->GetFreeMem() == 0);
}

template <class ValType>
bool TMStack<ValType>::IsEmpty(int count){
	if (count < 0 || count >= this->count)
		throw TMyException("Error! Index is out of range!\n");
	else
		return (mStack[count]->GetFreeMem() == mStack[count]->GetLength());
}

template <class ValType>
int TMStack<ValType>::CountFree()
{
	int tmp = 0;
	for (int i = 0; i < count; i++)
		tmp += mStack[i]->GetFreeMem();
	return tmp;
}

template <class ValType>
void TMStack<ValType>::Repack(int num){
	int fMem = CountFree();
	int addEv = fMem / count;
	int addFull = fMem % count;
	int* newSize = new int[count];
	ValType** newStart = new ValType * [count];
	ValType** oldStart = new ValType * [count];
	for (int i = 0; i < count; i++)
		newSize[i] = addEv + mStack[i]->GetTop();
	newSize[num] += addFull;
	newStart[0] = oldStart[0] = mas;
	for (int i = 1; i < count; i++){
		newStart[i] = newStart[i - 1] + newSize[i - 1];
		oldStart[i] = oldStart[i - 1] + mStack[i - 1]->GetLength();
	}
	for (int i = 0; i < count; i++){
		if (newStart[i] <= oldStart[i])
			for (int j = 0; j < mStack[i]->GetTop(); j++)
				newStart[i][j] = oldStart[i][j];
		else{
			int s;
			for (s = i + 1; s < count; s++)
				if (newStart[s] <= oldStart[s])
					break;
			for (int j = count - 1; j >= i; j--)
				for (int r = mStack[j]->GetTop() - 1; r >= 0; r--)
					newStart[j][r] = oldStart[j][r];
			i = s - 1;
		}
	}
	for (int i = 0; i < count; i++)
		mStack[i]->SetM(newSize[i], newStart[i]);
	delete[] newSize;
	delete[] newStart;
	delete[] oldStart;
}
