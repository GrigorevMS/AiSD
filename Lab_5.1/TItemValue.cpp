#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"
#include"TItemValue.h"

// �����������
TItemValue::TItemValue(int value_copy) {
	Value = value_copy;
}

// ����������� �����������
TItemValue::TItemValue(const TItemValue& temp) {
	Value = temp.Value;
}

// �������� �����
TDatValue* TItemValue::GetCopy() {
	TDatValue* result = new TItemValue(this->Value);
	return result;
}

// ������� ����������� � ���� ������
std::string TItemValue::ToStr() {
	return std::to_string(this->Value);
}

// ������ ��������
void TItemValue::SetValue(int value_copy) {
	this->Value = value_copy;
}

// ������� ��������
int TItemValue::GetValue(void) {
	if (this != nullptr)
		return this->Value;
}

// ���������

TItemValue& TItemValue::operator=(const TItemValue& temp) {
	this->Value = temp.Value;
	return *this;
}

bool TItemValue::operator==(const TItemValue& temp) {
	if (this->Value == temp.Value)
		return true;
	return false;
}

bool TItemValue::operator<(const TItemValue& temp) {
	if (this->Value < temp.Value)
		return true;
	return false;
}

bool TItemValue::operator>(const TItemValue& temp) {
	if (this->Value > temp.Value)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, TItemValue& temp) {
	os << temp.Value;
	return os;
}