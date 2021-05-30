#pragma once
#include<string>
using namespace std;


void Sep(string input, string* mas, int count = 3);


/*
	Интерпретация возвращаемых значений:
		-1 - unknown error
		0 - a == b
		1 - a < b
		2 - a > b
*/
int CompareString(string a, string b);