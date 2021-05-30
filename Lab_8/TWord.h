#pragma once
#include"TDatValue.h"
#include<iostream>


// �����-��������� TDatValue ����������� �������� ������� �����
class TWord : public TDatValue {

	// ���� ������
protected:
	std::string* Word; // ������ �������� �����
	// ����� ������������ ���� TDatValue::Size

	// ������ ������
public:
	TWord(std::string* word_copy = nullptr, int size_copy = 1); // ����������� ������
	virtual ~TWord() {}; // ���������� ������

	std::string* GetWord(void); // �������� ��������� �� ������ �������� �����
	void SetWord(std::string* word_copy); // ������ ��������� �� ������ �������� �����

	virtual TDatValue* GetCopy(void) const; // �������� ����� ������ ������
	virtual std::string ToStr(void) const; // �������� ���������� ������� � ������ � ���� ������
	/*
		������ ������: |      ����|  ��������|  ��������|
		������ ���� �������� �������� WIDTH
	*/
	virtual std::string ToFileString(void) const; // �������� ���������� ������� � ������ � ���� ������

};