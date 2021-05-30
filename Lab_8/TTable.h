#pragma once
#include"TDataCom.h"
#include"TDatValue.h"
#include"TTabRecord.h"
#include"TWord.h"
#include<iostream>
#include<fstream>


/*
    TDataCom->|                                             (��������� ����� ����������)(+)
	          |->TTable->|                                  (����������� ����� ������������� ������)(+)
			             |->TArrayTable->|                  (����������� ����� ������������� ������ �� ��������)(+)
						 |               |->TScanTable      (��������������� �������)(+)
						 |				 |->TSortTable      (������������� �������)
						 |->TTreeTable                      (����� �������� ������)  
						 |->THashTable->|                   (����������� ����� ������������� ���-������)
						                |->TArrayHash       (� �������� ��������������)
										|->TListHash        (� ������� �������)
*/


// ������������� ������������ �������� ��� ������ TTable::GetType()
/*
	0 - SCAN_TABLE
	1 - SORT_TABLE
	2 - TREE_TABLE
	3 - ARRAY_HASH
	4 - LIST_HASH
*/


// ������� ����������� ����� ������������ ������
class TTable : public TDataCom {

	//���� ������
protected:
	int DataCount; // ���������� ������� � �������
	int ColumnCount;// ���������� ������� �������
	int Efficiency; // ���������� ������������� ���������� ��������

	std::string* ColumnName; // �������� ��������

	// ������ ������
public:
	TTable(); // ����������� ������
	virtual ~TTable() {} // ���������� ������
	virtual int GetType() const = 0; // �������� ��� �������

	// �������������� ������
	int GetDataCount(void) const; // ������� ���������� �������
	int GetColumnCount(void) const; // �������� ���������� �������
	int GetEfficiency(void) const; // �������� ���������� ������������� ���������� ��������

	std::string* GetColumnName(void) const; // �������� �������� ��������
	void SetColumnName(std::string* columnname_copy); // ������ �������� ��������

	bool IsEmpty(void) const; // ������� �����?
	virtual bool IsFull() const = 0; // ������� ���������?


	// !!!!!!!!!!! ��������� ����� ��� �����, ������ ���� ����� ��� ������ !!!!!!!!!!!
	// ������ 
	virtual TKey GetKey(void) const = 0; // �������� ���� ������
	virtual TDatValue* GetpValue(void) const = 0; // �������� ��������� �� ��������� ������

	// �������� ������
	virtual TDatValue* FindRecord(TKey key_copy) = 0; // ����� ������ �� �����
	virtual void InsRecord(TKey key_copy, TDatValue* pvalue_copy) = 0; // �������� ������ � �������
	virtual void DelRecord(TKey key_copy) = 0; // ������� ������ �� �����

	// ������ �����-������
	virtual void Read(std::string pFileName)  = 0; // ���� ������� �� �����
	virtual void Write(std::string pFileName) const = 0; // ���������� ������� � ����

	virtual void Print(std::ostream& out = std::cout) const = 0; // ����� ������� � �������
	virtual void PrintHead(std::ostream& out = std::cout) const = 0; // ������� �������� �������� ������� ( ����� )

};