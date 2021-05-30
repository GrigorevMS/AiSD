#pragma once
#include"TDatValue.h"
#include"TWord.h"


// Интерпретация возвращаемых значений для метода TDatValue::GetType()
/*
	0 - NONE
	1 - TAB_RECORD
	2 - TREE_NODE
	3 - WORD
	4 - DOUBLE
*/


// конструктор класса
TWord::TWord(std::string* word_copy, int size_copy) {
	this->Type = 3;
	this->Size = size_copy;
	this->Word = word_copy;
}


// получить указатель на массив хранимых строк
std::string* TWord::GetWord(void) {
	return this->Word;
}


// задать указатель на массив хранимых строк
void TWord::SetWord(std::string* word_copy) {
	this->Word = word_copy;
}


// получить копию объета класса
TDatValue* TWord::GetCopy(void) const {
	std::string* value = new std::string[this->Size];
	for (int i = 0; i < this->Size; i++) {
		value[i] = this->Word[i];
	}
	TWord* temp = new TWord(value, this->Size);
	return temp;
}


// получить содержимое готовое к выводу в виде строки
/*
		Формат вывода: |      ключ|  аргумент|  аргумент|
		Ширина поля задается макросом WIDTH
*/
std::string TWord::ToStr(void) const {
	std::string out = "";
	for (int i = 0; i < this->Size; i++) {
		for (int j = 0; j < WIDTH - this->Word[i].size(); j++) {
			out += " ";
		}
		out = out + this->Word[i] + '|';
	}
	return out;
}


// получить содержимое готовое к выводу в виде строки
std::string TWord::ToFileString(void) const {
	std::string out = "";
	for (int i = 0; i < this->Size; i++) {
		out = out + this->Word[i] + " ";
	}
	return out;
}