#pragma once
#include <iostream>
#include "Stack.h"
#include "MyException.h"

template <class ValType>
class TNewStack :public TStack<ValType>
{
public:
    TNewStack(int length, ValType* mas);
    TNewStack(TNewStack<ValType>& v);
    void SetM(int length, ValType* mas);
    int GetFreeMem();
    int GetLength();
    int GetTop();
    void PutElem(ValType elem);
    ValType Get();
};

template <class ValType>
TNewStack<ValType>::TNewStack(int length, ValType* mas){
    if (length <= 0)
        throw TMyException("Error! Size must be positive!\n");
    else{
        TStack<ValType>::top = 0;
        TStack<ValType>::length = length;
        TStack<ValType>::mas = mas;
    }
}

template <class ValType>
TNewStack<ValType>::TNewStack(TNewStack<ValType>& v){
    TStack<ValType>::length = v.length;
    TStack<ValType>::top = v.top;
    TStack<ValType>::mas = v.mas;
}

template <class ValType>
void TNewStack<ValType>::SetM(int length, ValType* mas){
    if (length <= 0)
        throw TMyException("Error! Size must be positive!/n");
    TStack<ValType>::length = length;
    TStack<ValType>::mas = mas;
}

template <class ValType>
int TNewStack<ValType>::GetFreeMem(){
    return TStack<ValType>::length - TStack<ValType>::top;
}

template <class ValType>
int TNewStack<ValType>::GetLength(){
    return TStack<ValType>::length;
}

template <class ValType>
int TNewStack<ValType>::GetTop(){
    return TStack<ValType>::top;
}

template <class ValType>
void TNewStack<ValType>::PutElem(ValType elem){
    TStack<ValType>::top++;
    TStack<ValType>::mas[TStack<ValType>::top] = elem;
   
}

template <class ValType>
ValType TNewStack<ValType>::Get(){
    return TStack<ValType>::mas[TStack<ValType>::top];
    TStack<ValType>::top--;
}