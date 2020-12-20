#pragma once
#include <iostream>
#include <string>
using namespace std;

class TMyException {
	string str;
public:
	TMyException(string _str) : str(_str) {}
	void What() {
		cout << str << endl;
	}
};