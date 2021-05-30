#pragma once
#include<iostream>
#include"TDatValue.h"
#include"TTabRecord.h"


// »нтерпретаци€ возвращаемых значений дл€ метода TDatValue::GetType()
/*
	0 - NONE
	1 - TAB_RECORD
	2 - TREE_NODE
	3 - WORD
	4 - DOUBLE
*/


// конструктор класса
TTabRecord::TTabRecord(TKey key_copy, TDatValue* pvalue_copy) {
	this->Type = 1;
	this->Size = 1;
	this->Key = key_copy;
	this->pValue = pvalue_copy;
}


// получить копию объета класса
TDatValue* TTabRecord::GetCopy(void) const {
	TTabRecord* temp = new TTabRecord();
	temp->Type = this->Type;
	temp->Key = this->Key;
	temp->pValue = this->pValue->GetCopy(); // this->pValue так же €вл€етс€ наследником TDatValue
	                                        // и у него так же есть сво€ верси€ GetCopy()
	return temp;
}


// получить содержимое готовое к выводу в виде строки
/*
		‘ормат вывода: |      ключ|  аргумент|  аргумент|
		Ўирина пол€ задаетс€ макросом WIDTH
*/
std::string TTabRecord::ToStr(void) const {
	std::string out = "|";
	for (int i = 0; i < WIDTH - this->Key.size(); i++) {
		out += ' ';
	}
	out = out + this->Key + '|';
	out += this->pValue->ToStr(); // this->pValue так же €вл€етс€ наследником TDatValue
	                              // и у него так же есть сво€ верси€ ToStr()
	return out;
}


// получить содержимое готовое к выводу в виде строки
std::string TTabRecord::ToFileString(void) const {
	std::string out = "";
	out = out + this->Key + '\n';
	out = out + this->pValue->ToFileString();
	return out;
}


// получить ключ записи
TKey TTabRecord::GetKey(void) const {
	return this->Key;
}


// задать ключ записи
void TTabRecord::SetKey(TKey key_copy) {
	this->Key = key_copy;
}


// получить указатель на арггуенты записи
TDatValue* TTabRecord::GetpValue(void) const {
	return this->pValue;
}


// задать указатель на арггуенты записи
void TTabRecord::SetpValue(TDatValue* pValue) {
	this->pValue = pValue;
}


// оператор присваивани€
TTabRecord& TTabRecord::operator= (TTabRecord& tr) {
	this->Type = tr.Type;
	this->Key = tr.Key;
	this->pValue = tr.pValue->GetCopy();
	return *this;
}


// сравнение "="
bool TTabRecord::operator ==(const TTabRecord& tr) const {
	if (this->Key == tr.Key)
		return true;
	else
		return false;
}


// сравнение "<"
bool TTabRecord::operator <(const TTabRecord& tr) const {
	if (this->Key < tr.Key)
		return true;
	else
		return false;
}


// сравнение ">"
bool TTabRecord::operator >(const TTabRecord& tr) const {
	if (this->Key > tr.Key)
		return true;
	else
		return false;
}