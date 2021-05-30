#pragma once
#include"TTable.h"


// ����������� ������
TTable::TTable() {
	this->RetCode = 0;
	this->DataCount = 0;
	this->ColumnCount = 0;
	this->Efficiency = 0;
	this->ColumnName = nullptr;
}


// ������� ���������� �������
int TTable::GetDataCount(void) const {
	return this->DataCount;
}


// �������� ���������� �������
int TTable::GetColumnCount(void) const {
	return this->ColumnCount;
}


// �������� ���������� ������������� ���������� ��������
int TTable::GetEfficiency(void) const {
	return this->Efficiency;
}


// �������� �������� ��������
std::string* TTable::GetColumnName(void) const {
	return this->ColumnName;
}


// ������ �������� ��������
void TTable::SetColumnName(std::string* columnname_copy) {
	this->ColumnName = columnname_copy;
}


// ������� �����?
bool TTable::IsEmpty(void) const {
	if (this->DataCount == 0)
		return true;
	else
		return false;
}