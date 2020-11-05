#ifndef _Stack_
#define _Stack_
#include <iostream>
using namespace std;

template <class ValType>
class Stack {
protected:
    int top;
    int length;
    ValType* pStack;
public:
    Stack(int length = 1);
    Stack(Stack<ValType>& v);
    void PushStack(ValType temp);
    ValType GetStack();
    ~Stack();

    Stack<ValType>& operator=(Stack<ValType>& v);

    bool IsFull();
    bool IsEmpty();

    template <class ValType1>
    friend ostream& operator<< (ostream& ostr, const Stack<ValType1>& A);
    template <class ValType1>
    friend istream& operator >> (istream& istr, Stack<ValType1>& A);

    int GetLength() {return length;}
    int GetTop() {return top;}

    void SetpStack(ValType* pStack, int length, int top);
    void Relength(int length);
};

template<class ValType>
inline void Stack<ValType>::SetpStack(ValType* pStack, int length, int top){
    if (pStack != 0)
        delete[] pStack;
    
    this->length = length;
    this->pStack = pStack;
    this->top = top;
}

template<class ValType>
inline void Stack<ValType>::Relength(int length) {
    if (length <= 0)  throw logic_error("Input error: invalide value of Stack length in Resize");

    if (pStack == 0) {
        delete[] pStack;
        pStack = new ValType[length];
    }

    else {
        ValType* temp = new ValType[length];
        for (int i = 0; i < GetTop(); i++)
            temp[i] = GetStack();

        delete[] pStack;

        pStack = new ValType[length];
        for (int i = 0; i < 1; i++)
            pStack[i] = temp[i];
    }
}


template <class ValType1>
ostream& operator<< (ostream& ostr, const Stack<ValType1>& p) {
    for (int i = 0; i < p.length; i++)
        ostr << p.pStack[i] << endl;
    return ostr;
}

template <class ValType1>
istream& operator >> (istream& istr, Stack<ValType1>& p) {
    int count;
    istr >> count;
    for (int i = 0; i < count; i++) {
        ValType1 time;
        istr >> time;
        p.PushStack(time);
    }
    return istr;
}

template <class ValType>
Stack<ValType>::Stack(int length = 1) {
    if (length > 0) {
        this->length = length;
        pStack = new ValType[length];
        for (int i = 0; i < length; i++)
            pStack[i] = 0;
        this->top = -1;
    }
    else
        throw logic_error("Input error: invalide value of Stack length in constructor");
}

template <class ValType>
Stack<ValType>::Stack(Stack<ValType>& v) {
    length = v.length;
    top = v.top;
    pStack = new ValType[length];
    for (int i = 0; i < top + 1; i++)
        pStack[i] = v.pStack[i];
}

template <class T>
Stack<T>::~Stack(){
    length = 0;
    if (pStack != 0) 
        delete[] pStack;
}

template <class ValType>
Stack<ValType>& Stack<ValType>::operator=(Stack<ValType>& v){
    if (this == &v)
        return *this;
    length = v.length;
    top = v.top;
    delete[] pStack;

    pStack = new ValType[length];
    for (int i = 0; i < top + 1; i++)
        pStack[i] = v.pStack[i];
    return *this;
}

template<class ValType>
inline bool Stack<ValType>::IsFull(){
    return (top >= length - 1);
}

template<class ValType>
inline bool Stack<ValType>::IsEmpty(){
    return (top == -1)
}


template<class ValType>
inline void Stack<ValType>::PushStack(ValType temp) {
    if (top >= length - 1)
        throw logic_error("Input error: invalide value of Stack length in PushStack");
    top++;
    pStack[top] = temp;
}

template<class ValType>
inline ValType Stack<ValType>::GetStack() {
    if (top == -1)
        throw logic_error("Input error: invalide value of Stack length in GetStack");
    ValType temp = pStack[top];
    top--;
    return temp;
}
#endif