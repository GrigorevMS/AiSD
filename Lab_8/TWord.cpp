#pragma once
#include"TDatValue.h"
#include"TWord.h"


// ������������� ������������ �������� ��� ������ TDatValue::GetType()
/*
	0 - NONE
	1 - TAB_RECORD
	2 - TREE_NODE
	3 - WORD
	4 - DOUBLE
*/


// ����������� ������
TWord::TWord(std::string* word_copy, int size_copy) {
	this->Type = 3;
	this->Size = size_copy;
	this->Word = word_copy;
}


// �������� ��������� �� ������ �������� �����
std::string* TWord::GetWord(void) {
	return this->Word;
}


// ������ ��������� �� ������ �������� �����
void TWord::SetWord(std::string* word_copy) {
	this->Word = word_copy;
}


// �������� ����� ������ ������
TDatValue* TWord::GetCopy(void) const {
	std::string* value = new std::string[this->Size];
	for (int i = 0; i < this->Size; i++) {
		value[i] = this->Word[i];
	}
	TWord* temp = new TWord(value, this->Size);
	return temp;
}


// �������� ���������� ������� � ������ � ���� ������
/*
		������ ������: |      ����|  ��������|  ��������|
		������ ���� �������� �������� WIDTH
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


// �������� ���������� ������� � ������ � ���� ������
std::string TWord::ToFileString(void) const {
	std::string out = "";
	for (int i = 0; i < this->Size; i++) {
		out = out + this->Word[i] + " ";
	}
	return out;
}