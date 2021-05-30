#pragma once
#include"TDatValue.h"


// конструктор класса
TDatValue::TDatValue(int type_copy, int size_copy) {
	this->Type = type_copy;
	this->Size = size_copy;
}


// получить тип хранимого значения
int TDatValue::GetType(void) const {
	return this->Type;
}


// задать тип хранимого значения
void TDatValue::SetType(int type_copy) {
	this->Type = type_copy;
}


// получить количество хранимых значений
int TDatValue::GetSize(void) const {
	return this->Size;
}


// задать количество хранимых значений
void TDatValue::SetSize(int size_copy) {
	this->Size = size_copy;
}