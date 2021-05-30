#pragma once
#include"ExtraFunctions.h"


void Sep(string input, string* mas, int count) {
	for (int i = 0; i < count; i++) {
		mas[i] = "";
	}
	int high = 0; // индекс выходного массива с готовыми строками
	int pos = 0; // индекс для прохождения входной строки
	string temp = "";
	while (pos < input.size() && high < count) {
		temp = "";
		while (input[pos] != ' ' && pos < input.size()) {
			temp = temp + input[pos];
			pos += 1;
		}
		mas[high] = temp;
		high += 1;
		while (input[pos] == ' ' && pos < input.size()) {
			pos += 1;
		}
	}
}


int CompareString(string a, string b) {
	int a_pos = 0;
	int b_pos = 0;

	while (a_pos < a.size() && b_pos < b.size() && a[a_pos] == b[b_pos]) {
		a_pos++;
		b_pos++;
	}

	if (a_pos == a.size() && a_pos == b_pos) {
		return 0;
	}
	else if (a_pos == a.size() && b_pos < b.size()) {
		return 1;
	}
	else if (b_pos == b.size() && a_pos < a.size()) {
		return 2;
	}
	else if (a_pos < a.size() && b_pos < b.size() && a.at(a_pos) < b.at(b_pos)) {
		return 1;
	}
	else if (a_pos < a.size() && b_pos < b.size() && a.at(a_pos) > b.at(b_pos)) {
		return 2;
	}
	return -1;
}