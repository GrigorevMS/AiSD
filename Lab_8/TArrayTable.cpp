#pragma once
#include"TArrayTable.h"
#include"TTabRecord.h"
#include"TDataCom.h"


// ����������� ������
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


// ������� ���������?
bool TArrayTable::IsFull() const {
	if (this->DataCount < this->TabSize)
		return false;
	else
		return true;
}


// �������� ���� ������� ������
TKey TArrayTable::GetKey(void) const {
	return this->pRecs[this->CurrPos].GetKey();
}


// �������� ��������� �� ��������� ������
TDatValue* TArrayTable::GetpValue(void) const {
	return this->pRecs[this->CurrPos].GetpValue();
}


// �������� ���� ������� ������
TKey TArrayTable::GetKey(TDataPos mode) const {
	int OutPos = 0;
	if (mode == FIRST_POS)
		OutPos = 0;
	else if (mode == CURRENT_POS)
		OutPos = this->CurrPos;
	else if (mode == LAST_POS)
		OutPos = this->DataCount - 1;
	return this->pRecs[OutPos].GetKey();
}


// �������� ��������� �� ��������� ������
TDatValue* TArrayTable::GetpValue(TDataPos mode) const {
	int OutPos = 0;
	if (mode == FIRST_POS)
		OutPos = 0;
	else if (mode == CURRENT_POS)
		OutPos = this->CurrPos;
	else if (mode == LAST_POS)
		OutPos = this->DataCount - 1;
	return this->pRecs[OutPos].GetpValue();
}


// ���������� ����� ������� ������� �� ������ ������
void TArrayTable::Reset(void) {
	this->CurrPos = 0;
}


// ����� ������� ������� �� ��������� ������
bool TArrayTable::IsTabEnded(void) const {
	if (this->CurrPos >= this->DataCount - 1)
		return true;
	else
		return false;
}


// ����������� ����� ������� ������ �� ��������� ������
/*
		true - ����� ������ ������� � ��������� �������
		false - ����� ��������� �����
*/
bool TArrayTable::GoNext(void) {
	if (!(this->IsTabEnded())) {
		this->CurrPos += 1;
		return true;
	}
	else
		return false;
}


// ���������� ����� ������� ������
bool TArrayTable::SetCurrPos(int pos) {
	if ((pos >= 0) && (pos < this->DataCount)) {
		this->CurrPos = pos;
		return true;
	}
	else
		return false;
}


// �������� ����� ������� ������
int TArrayTable::GetCurrPos(void) const {
	return this->CurrPos;
}