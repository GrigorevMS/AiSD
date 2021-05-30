#pragma once
#define TABMAXSIZE 25 // ������������ ����� ������� � �������
#include"TTable.h"
#include<iostream>


enum TDataPos {
	FIRST_POS, CURRENT_POS, LAST_POS
};


// ����������� ����� ������������� ������ �� ��������
class TArrayTable : public TTable {

	// ���� �������-���������
	/*
		int TDataCom::RetCode; // ��� ���������� ��������
		int TTable::DataCount; // ���������� ������� � �������
		int TTable::ColumnCount;// ���������� ������� �������
		int TTable::Efficiency; // ���������� ������������� ���������� ��������
		TWord* TTable::ColumnName; // �������� ��������
	*/

	// ���� ������
protected:
	TTabRecord* pRecs; // ������ (������) �������
	int TabSize; // ����������� ��������� ���������� ������� �������
	int CurrPos; // ����� ������� ������
	

	// ������ ������
public:
	TArrayTable(int tabsize_copy = TABMAXSIZE, int columncount_copy = 1, std::string * columnname_copy = nullptr); // ����������� ������
	~TArrayTable() {}; // ���������� ������
	virtual bool IsFull() const; // ������� ���������?

	// �������������� ������
	virtual TKey GetKey(void) const; // �������� ���� ������� ������
	virtual TDatValue* GetpValue(void) const; // �������� ��������� �� ��������� ������

	virtual TKey GetKey(TDataPos mode) const; // �������� ���� ������� ������
	virtual TDatValue* GetpValue(TDataPos mode) const; // �������� ��������� �� ��������� ������

	// ���������
	virtual void Reset(void); // ���������� ����� ������� ������� �� ������ ������
	virtual bool IsTabEnded(void) const; // ����� ������� ������� �� ��������� ������?
	virtual bool GoNext(void); // ����������� ����� ������� ������ �� ��������� ������
	/*
	    true - ����� ������ ������� � ��������� �������
		false - ����� ��������� �����
	*/
	bool SetCurrPos(int pos); // ���������� ����� ������� ������
	int GetCurrPos(void) const; // �������� ����� ������� ������
};