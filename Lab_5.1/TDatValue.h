#pragma once
#include<string>
class TDatValue {
public:
	virtual TDatValue* GetCopy() = 0; // �������� �����
	virtual std::string ToStr() = 0; // ������� ����������� � ���� ������
	virtual ~TDatValue() { } // ����������
};