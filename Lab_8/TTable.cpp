#pragma once
#include"TTable.h"


// конструктор класса
TTable::TTable() {
	this->RetCode = 0;
	this->DataCount = 0;
	this->ColumnCount = 0;
	this->Efficiency = 0;
	this->ColumnName = nullptr;
}


// полуить количество записей
int TTable::GetDataCount(void) const {
	return this->DataCount;
}


// получить количество колонок
int TTable::GetColumnCount(void) const {
	return this->ColumnCount;
}


// получить показатель эффективности выполнения операции
int TTable::GetEfficiency(void) const {
	return this->Efficiency;
}


// получить названия столбцов
std::string* TTable::GetColumnName(void) const {
	return this->ColumnName;
}


// задать названия столбцов
void TTable::SetColumnName(std::string* columnname_copy) {
	this->ColumnName = columnname_copy;
}


// таблица пуста?
bool TTable::IsEmpty(void) const {
	if (this->DataCount == 0)
		return true;
	else
		return false;
}