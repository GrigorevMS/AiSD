#pragma once
#include"TArrayTable.h"
#include"TTabRecord.h"
#include"TDataCom.h"


// конструктор класса
TArrayTable::TArrayTable(int tabsize_copy, int columncount_copy, std::string* columnname_copy) {
	this->RetCode = 0;
	this->DataCount = 0;
	this->ColumnCount = columncount_copy;
	this->Efficiency = 0;
	this->TabSize = tabsize_copy;
	this->CurrPos = 0;
	this->pRecs = new TTabRecord[tabsize_copy];
	this->ColumnName = columnname_copy;
}


// таблица заполнена?
bool TArrayTable::IsFull() const {
	if (this->DataCount < this->TabSize)
		return false;
	else
		return true;
}


// получить ключ текущей записи
TKey TArrayTable::GetKey(void) const {
	return this->pRecs[this->CurrPos].GetKey();
}


// получить указатель на аргументы записи
TDatValue* TArrayTable::GetpValue(void) const {
	return this->pRecs[this->CurrPos].GetpValue();
}


// получить ключ текущей записи
TKey TArrayTable::GetKey(int mode) const {
	int OutPos = 0;
	if (mode == 1)
		OutPos = 0;
	else if (mode == 0)
		OutPos = this->CurrPos;
	else if (mode == 2)
		OutPos = this->DataCount - 1;
	return this->pRecs[OutPos].GetKey();
}


// получить указатель на аргументы записи
TDatValue* TArrayTable::GetpValue(int mode) const {
	int OutPos = 0;
	if (mode == 1)
		OutPos = 0;
	else if (mode == 0)
		OutPos = this->CurrPos;
	else if (mode == 2)
		OutPos = this->DataCount - 1;
	return this->pRecs[OutPos].GetpValue();
}


// получить максимальный размер таблицы
int TArrayTable::GetSize(void) const {
	return this->TabSize;
}


// установить максимальный размер таблицы
void TArrayTable::SetSize(int size_copy) {
	this->TabSize = size_copy;
}


// установить номер текущей позиции на первую запись
void TArrayTable::Reset(void) {
	this->CurrPos = 0;
}


// номер текущей позиции на последней записи
bool TArrayTable::IsTabEnded(void) const {
	if (this->CurrPos >= this->DataCount - 1)
		return true;
	else
		return false;
}


// переместить номер текущей записи на следующую запись
/*
		true - когда смогли перейти к следующей позиции
		false - когда завершили обход
*/
bool TArrayTable::GoNext(void) {
	if (!(this->IsTabEnded())) {
		this->CurrPos += 1;
		return true;
	}
	else
		return false;
}


// установить номер текущей позции
bool TArrayTable::SetCurrPos(int pos) {
	if ((pos >= 0) && (pos < this->DataCount)) {
		this->CurrPos = pos;
		return true;
	}
	else
		return false;
}


// получить номер текущей записи
int TArrayTable::GetCurrPos(void) const {
	return this->CurrPos;
}