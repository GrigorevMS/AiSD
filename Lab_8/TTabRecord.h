#pragma once
#include"TDatValue.h"
#include<iostream>


typedef std::string TKey; // ��� ����� ������


// ����� ������ �������
class TTabRecord : public TDatValue {

	// ���� ������
protected:
	TKey Key; // ���� ������
	TDatValue* pValue; // ��������� (��������, ����) ������

	// ������ ������
public:
	TTabRecord(TKey key_copy = "", TDatValue* pvalue_copy = nullptr); // ����������� ������

	virtual TDatValue* GetCopy(void) const; // �������� ����� ������ ������
	virtual std::string ToStr(void) const; // �������� ���������� ������� � ������ � ���� ������
	virtual std::string ToFileString(void) const; // �������� ���������� ������� � ������ � ���� ������

	TKey GetKey(void) const; // �������� ���� ������
	void SetKey(TKey key_copy); // ������ ���� ������

	TDatValue* GetpValue(void) const; // �������� ��������� �� ��������� ������
	void SetpValue(TDatValue* pValue); // ������ ��������� �� ��������� ������

	TTabRecord& operator= (TTabRecord& tr); // �������� ������������

	virtual bool operator ==(const TTabRecord& tr) const; // ��������� "="
	virtual bool operator <(const TTabRecord& tr) const; // ��������� "<"
	virtual bool operator >(const TTabRecord& tr) const; // ��������� ">"

};