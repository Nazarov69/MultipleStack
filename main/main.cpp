#include <iostream>
#include "MultiStack.h"
#include "Stack.h"
#include "NewStack.h"
int main(){
	try{
		TMStack<int> multistack(2, 10);
		int k = 0;
		int tmp = 0;
		std::cout << "Filling the multistack with values from 1 to 10... "<<endl;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 5; j++){
				k++;
				multistack.SetElem(i, k);
			}
		std::cout << "First stack is: ";
		if (multistack.IsEmpty(0))
			std::cout << "empty."<<endl;
		else if (multistack.IsFull(0))
			std::cout << "full."<<endl;
		else
			std::cout << "not empty and not full."<<endl;
		std::cout << "Getting element from first stack..." << endl;;
		tmp = multistack.GetElem(0);
		std::cout << "Element from first stack equals: " << tmp << endl;;
		std::cout << "First stack is: ";
		if (multistack.IsEmpty(0))
			std::cout << "empty."<<endl;
		else if (multistack.IsFull(0))
			std::cout << "full." << endl;
		else
			std::cout << "not empty and not full." << endl;
		std::cout << "Second stack is: ";
		if (multistack.IsEmpty(1))
			std::cout << "empty."<<endl;
		else if (multistack.IsFull(1))
			std::cout << "full."<<endl;
		else
			std::cout << "not empty and not full."<<endl;
		std::cout << "Getting element from second stack..."<<endl;
		tmp = multistack.GetElem(1);
		std::cout << "Element from second stack equals: " << tmp << endl;
		std::cout << "First stack is: ";
		if (multistack.IsEmpty(1))
			std::cout << "empty."<<endl;
		else if (multistack.IsFull(1))
			std::cout << "full."<<endl;
		else
			std::cout << "not empty and not full."<<endl;
	}

	catch (TMyException& ex){
		ex.What();
	}
	return 0;

	/*Filling the multistack with values from 1 to 10...
First stack is: full.
Getting element from first stack...
Element from first stack equals: 5
First stack is: full.
Second stack is: full.
Getting element from second stack...
Element from second stack equals: 10
First stack is: full.*/
}