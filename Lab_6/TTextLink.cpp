#pragma once
#define TextLineLength 20
#include"TTextLink.h"
#include<iostream>
#include<string>

// печать содержимого
void TTextLink::Print(std::ostream& os) {

}

// конструктор
TTextLink::TTextLink(std::string s[TextLineLength] = nullptr, TTextLink* pNext_copy = nullptr, TTextLink* pDown_copy = nullptr) {
	for (int i = 0; i < TextLineLength; i++) {
		this->Str[i] = s[i];
	}
	this->pNext = pNext_copy;
	this->pDown = pDown_copy;
}

// проверка звена на атомарность
bool TTextLink::IsAtom() {
	if (this->pDown == nullptr)
		return true;
	return false;
}

// получить указатель на следующий
TTextLink* TTextLink::GetNext() {
	return this->pNext;
}

// получить указатель на элеемент ниже уровнем
TTextLink* TTextLink::GetDown() {
	return this->pDown;
}

std::ostream& operator<<(std::ostream& os, const TTextLink& tl) {
	os << tl.Str;
	return os;
}