#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"

class TItemValue : public TDatValue {

protected:
	int Value; // ��������
public:
	TItemValue(int value_copy = 0); // �����������
	TItemValue(const TItemValue& temp); // ����������� �����������
	virtual ~TItemValue(){}

	virtual TDatValue* GetCopy(); // �������� �����
	virtual std::string ToStr(); // ������� ����������� � ���� ������

	void SetValue(int value_copy = 0); // ������ ��������
	int GetValue(void); // ������� ��������

	// ���������
	TItemValue& operator=(const TItemValue& temp);
	bool operator==(const TItemValue& temp);
	bool operator<(const TItemValue& temp);
	bool operator>(const TItemValue& temp);
	friend std::ostream& operator<<(std::ostream& os, TItemValue& temp);
};