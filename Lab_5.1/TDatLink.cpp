#pragma once
#include"TDatLink.h"
#include"TDatValue.h"

// �����������
TDatLink::TDatLink(TDatValue* pValue_copy, TDatLink* pNext_copy) {
	this->pValue = pValue_copy;
	this->pNext = pNext_copy;
}

// ������ ��������
void TDatLink::SetValue(TDatValue* pValue_copy) {
	this->pValue = pValue_copy;
}

// ������� ��������
TDatValue* TDatLink::GetValue(void) {
	if (this != nullptr)
		return this->pValue;
	else
		return nullptr;
}

// ������ ��������� �������
void TDatLink::SetNext(TDatLink* pNext_copy) {
	this->pNext = pNext_copy;
}

// ������� ��������� �� ���������
TDatLink* TDatLink::GetNext(void) {
	if (this != nullptr)
		return this->pNext;
	else
		return nullptr;
}