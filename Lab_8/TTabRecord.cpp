#pragma once
#include<iostream>
#include"TDatValue.h"
#include"TTabRecord.h"


// ������������� ������������ �������� ��� ������ TDatValue::GetType()
/*
	0 - NONE
	1 - TAB_RECORD
	2 - TREE_NODE
	3 - WORD
	4 - DOUBLE
*/


// ����������� ������
TTabRecord::TTabRecord(TKey key_copy, TDatValue* pvalue_copy) {
	this->Type = 1;
	this->Size = 1;
	this->Key = key_copy;
	this->pValue = pvalue_copy;
}


// �������� ����� ������ ������
TDatValue* TTabRecord::GetCopy(void) const {
	TTabRecord* temp = new TTabRecord();
	temp->Type = this->Type;
	temp->Key = this->Key;
	temp->pValue = this->pValue->GetCopy(); // this->pValue ��� �� �������� ����������� TDatValue
	                                        // � � ���� ��� �� ���� ���� ������ GetCopy()
	return temp;
}


// �������� ���������� ������� � ������ � ���� ������
/*
		������ ������: |      ����|  ��������|  ��������|
		������ ���� �������� �������� WIDTH
*/
std::string TTabRecord::ToStr(void) const {
	std::string out = "|";
	for (int i = 0; i < WIDTH - this->Key.size(); i++) {
		out += ' ';
	}
	out = out + this->Key + '|';
	out += this->pValue->ToStr(); // this->pValue ��� �� �������� ����������� TDatValue
	                              // � � ���� ��� �� ���� ���� ������ ToStr()
	return out;
}


// �������� ���������� ������� � ������ � ���� ������
std::string TTabRecord::ToFileString(void) const {
	std::string out = "";
	out = out + this->Key + '\n';
	out = out + this->pValue->ToFileString();
	return out;
}


// �������� ���� ������
TKey TTabRecord::GetKey(void) const {
	return this->Key;
}


// ������ ���� ������
void TTabRecord::SetKey(TKey key_copy) {
	this->Key = key_copy;
}


// �������� ��������� �� ��������� ������
TDatValue* TTabRecord::GetpValue(void) const {
	return this->pValue;
}


// ������ ��������� �� ��������� ������
void TTabRecord::SetpValue(TDatValue* pValue) {
	this->pValue = pValue;
}


// �������� ������������
TTabRecord& TTabRecord::operator= (TTabRecord& tr) {
	this->Type = tr.Type;
	this->Key = tr.Key;
	this->pValue = tr.pValue->GetCopy();
	return *this;
}


// ��������� "="
bool TTabRecord::operator ==(const TTabRecord& tr) const {
	if (this->Key == tr.Key)
		return true;
	else
		return false;
}


// ��������� "<"
bool TTabRecord::operator <(const TTabRecord& tr) const {
	if (this->Key < tr.Key)
		return true;
	else
		return false;
}


// ��������� ">"
bool TTabRecord::operator >(const TTabRecord& tr) const {
	if (this->Key > tr.Key)
		return true;
	else
		return false;
}