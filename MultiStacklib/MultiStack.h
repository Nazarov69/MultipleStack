#ifndef _MultiStack_
#define _MultiStack_
#include <iostream>
#include <math.h>
#include "Stack.h"
using namespace std;

template <class ValType>
class MultiStack : public Stack<Stack<ValType> > {
protected:
    int count; // количество stack
    int len; // длина
    ValType* pMultiStack;
    Stack<ValType>* pS;
    void Relocation(int index);
    ValType** mas2;
public:
    MultiStack(int len = 1, int count = 1);
    MultiStack(MultiStack<ValType>& v);
    void PushMultiStack(ValType temp, int index);
    ValType GetMultiStack(int index);
    ~MultiStack();

    bool IsEmpty(int index);
    bool IsFull(int index);

    MultiStack<ValType>& operator=(MultiStack<ValType>& v);
    void Relength(int len = 1, int count = 1);
    int GetLen() {
        return len;
  }
};

template<class ValType>
inline void MultiStack<ValType>::Relength(int len, int count){
    pS[count].Relength(len);
}

template<class ValType>
inline void MultiStack<ValType>::Relocation(int index){
    int Size = 0;
    for (int i = 0; i < count; i++)
        Size += pS[i].GetLength() - pS[i].GetTop();

    if (Size == 0)
        throw logic_error("Input error: invalide value of MultiStack length in Relocation");

    int parts = int(floor(double(Size) / count));
    
    int* array = new int[count];
    for (int i = 0; i < count - 1; i++)
        array[i] = pS[i].GetTop() + parts;
    
    int a = pS[count - 1].GetTop();
    array[count - 1] = a + (Size - (parts * (count - 1)));

    int temp = 0;
    ValType** mas1 = new ValType * [count];
    for (int i = 0; i < count; i++){
        mas1[i] = &(pMultiStack[temp]);
        temp += array[i];
    }

    for (int i = 0; i < count; i++){
        if (mas1[i] == mas2[i])
            pS[i].SetpStack(mas1[i], array[i], pS[i].GetTop());
 
        else if (mas1[i] < mas2[i]){
            for (int j = 0; j < pS[i].GetTop(); j++)
                mas1[i][j] = mas2[i][j];
            
            pS[i].SetpStack(mas1[i], array[i], pS[i].GetTop());
        }

        else if (mas1[i] > mas2[i]){
            int tpk = i;
            for (; tpk < count; tpk++)
                if (mas1[tpk] > mas2[tpk]) continue;
                else break;
            tpk--;

            for (int j = tpk; j <= i; j--){
                for (int jj = pS[j].GetTop() - 1; jj >= 0; jj--)
                    mas1[j][jj] = mas2[j][jj];

                pS[j].SetpStack(mas1[j], array[j], pS[j].GetTop());
            }

        }
    }

    ValType** mas = mas2;
    mas2 = mas1;
    delete[] mas;
    delete[] array;
}

template <class ValType>
MultiStack<ValType>::MultiStack(int len, int count) {
    if (size > 0 && count > 0) {
        this->len = len;
        this->count = count;

        pMultiStack = new ValType[len];
        for (int i = 0; i < len; i++)
            pMultiStack[i] = 0;

        int parts = int(floor(double(len) / count));

        int* array = new int[count];
        for (int i = 0; i < count - 1; i++)
            array[i] = parts;

        array[count - 1] = len - (parts * (count - 1));

        int tmp = 0;
        mas2 = new ValType * [count];
        this->pS = new Stack<ValType>[count];
        for (int i = 0; i < count; i++) {
            this->pS[i].SetpStack(&(pStack[tmp]), array[i], 0);
            this->mas2[i] = &(pMultiStack[tmp]);
            tmp += array[i];
        }
    }
    else
        throw logic_error("Input error: invalide value of MultiStack length in constructor");
}

template <class ValType>
MultiStack<ValType>::MultiStack(MultiStack<ValType>& v) {
    len = v.len;
    count = v.count;
    pMultiStack = new ValType[len];
    for (int i = 0; i < len; i++)
        pMultiStack[i] = v.pMultiStack[i];

    pS = new Stack<ValType>[count];
    for (int i = 0; i < count; i++)
        pS[i] = v.pS[i];

    mas2 = v.mas2;
}

template <class ValType>
MultiStack<ValType>::~MultiStack()
{
    len = 0;
    count = 0;
    if (pMultiStack != 0) {
        delete[] pMultiStack;
        delete[] pS;
    }
}

template <class ValType>
bool MultiStack<ValType>::IsEmpty(int index) {
    if (index < 0 || index >= count)
        throw logic_error("IsEmpty");
    return pS[index].IsEmpty();

}

template <class ValType>
bool MultiStack<ValType>::IsFull(int index) {
    if (index < 0 || index >= count)
        throw logic_error("IsFull");
    return pS[index].IsFull();
}

template <class ValType>
MultiStack<ValType>& MultiStack<ValType>::operator=(MultiStack<ValType>& v)
{
    if (this == &v)
        return *this;

    len = v.len;
    delete[] pMutliStack;
    delete[] pS;

    pMultiStack = new ValType[len];
    for (int i = 0; i < len; i++)
        pMutliStack[i] = v.pMultiStack[i];

    pS = new Stack<ValType>[count];
    for (int i = 0; i < count; i++)
        pS[i] = v.pS[i];

    return *this;
}

template<class ValType>
inline void MultiStack<ValType>::PushMultiStack(ValType temp, int index) {
    if (index < 0 || index >= count)
        throw logic_error("Input error: invalide value of Stack length in PushMStack");
    if (pS[index].IsFull()) Relocation(index);

    pS[index].PushStack(temp);
}

template<class ValType>
inline ValType MultiStack<ValType>::GetMultiStack(int index) {
    if (index < 0 || index >= count || pS[index].IsEmpty())
        throw logic_error("Input error: invalide value of Stack length in PushMStack");
    return pS[index].GetStack();
}

#endif