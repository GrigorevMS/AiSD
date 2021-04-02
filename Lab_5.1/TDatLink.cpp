#pragma once
#include"TDatLink.h"
#include"TDatValue.h"

// конструктор
TDatLink::TDatLink(TDatValue* pValue_copy, TDatLink* pNext_copy) {
	this->pValue = pValue_copy;
	this->pNext = pNext_copy;
}

// задать значение
void TDatLink::SetValue(TDatValue* pValue_copy) {
	this->pValue = pValue_copy;
}

// вернуть значение
TDatValue* TDatLink::GetValue(void) {
	if (this != nullptr)
		return this->pValue;
	else
		return nullptr;
}

// задать следующий элемент
void TDatLink::SetNext(TDatLink* pNext_copy) {
	this->pNext = pNext_copy;
}

// вернуть указатель на следующий
TDatLink* TDatLink::GetNext(void) {
	if (this != nullptr)
		return this->pNext;
	else
		return nullptr;
}