#pragma once
#include"TDatValue.h"


// ����������� ������
TDatValue::TDatValue(int type_copy, int size_copy) {
	this->Type = type_copy;
	this->Size = size_copy;
}


// �������� ��� ��������� ��������
int TDatValue::GetType(void) const {
	return this->Type;
}


// ������ ��� ��������� ��������
void TDatValue::SetType(int type_copy) {
	this->Type = type_copy;
}


// �������� ���������� �������� ��������
int TDatValue::GetSize(void) const {
	return this->Size;
}


// ������ ���������� �������� ��������
void TDatValue::SetSize(int size_copy) {
	this->Size = size_copy;
}