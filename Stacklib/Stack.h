#pragma once
#include <iostream>
#include "MyException.h"


template <class ValType>
class TStack{
protected:
    int top;
    int length;
    ValType* mas;
public:
    TStack(int length = 0);
    TStack(TStack<ValType>& v);
    ~TStack();

    void Push(ValType elem);
    ValType Get();
    ValType ShowTop();
    int GetLength();

    bool IsEmpty();
    bool IsFull();

    TStack<ValType>& operator=(const TStack<ValType>& v);
    int operator!=(const TStack<ValType>& stack) const;
    int operator==(const TStack<ValType>& stack) const;
};

template <class ValType>
TStack<ValType>::TStack(int length){
    if (length < 0)
        throw TMyException("Error! Size must be positive!\n");
    else if (length == 0){
        length = 0;
        top = -1;
        mas = nullptr;
    }
    else{
        this->length = length;
        top = 0;
        mas = new ValType[length];
        for (int i = 0; i < length; i++)
            mas[i] = 0;
    }
}

template <class ValType>
TStack<ValType>::TStack(TStack<ValType>& v){
    this->length = v.length;
    this->top = v.top;
    if (length == 0)
        mas = nullptr;
    else{
        mas = new ValType[length];
        for (int i = 0; i < length; i++)
            this->mas[i] = v.mas[i];
    }
}

template <class ValType>
TStack<ValType>::~TStack(){
    if (mas != 0)
        delete[] mas;
    mas = nullptr;
}

template <class ValType>
TStack<ValType>& TStack<ValType>::operator=(const TStack<ValType>& v){
    if (this != &v){
        delete[] mas;
        this->top = v.top;
        this->length = v.length;
        mas = new ValType[length];
        for (int i = 0; i < length; i++)
            this->mas[i] = v.mas[i];
    }
    return *this;
}

template <class ValType>
ValType TStack<ValType>::ShowTop(){
    if (IsEmpty())
        throw TMyException("Error! Stack is empty!\n");
    else
        return mas[top - 1];
}

template <class ValType>
int TStack<ValType>::GetLength(){
    return length;
}

template <class ValType>
void TStack<ValType>::Push(ValType elem){
    if (IsFull())
        throw TMyException("Error! Stack is full!\n");
    else{
        top++;
        mas[top] = elem;
    }
}

template <class ValType>
ValType TStack<ValType>::Get(){
    if (IsEmpty())
        throw TMyException("Error! Stack is empty!\n");
    else{
        return mas[top];
        top--;
    }
}

template <class ValType>
bool TStack<ValType>::IsEmpty(){
    return (top == -1);
    
}

template <class ValType>
bool TStack<ValType>::IsFull(){
    return (top >= length - 1);
  
}

template <class ValType>
int TStack<ValType>::operator!=(const TStack<ValType>& v) const
{
    return !(this == &v);
}

template <class ValType>
int TStack<ValType>::operator==(const TStack<ValType>& v) const{
    if (this->top != v.top)
        return 0;
    if (this->length != v.length)
        return 0;
    for (int i = 0; i < top + 1; i++)
        if (this->mas[i] != v.mas[i])
            return 0;
    return 1;
}
