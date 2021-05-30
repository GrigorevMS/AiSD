#pragma once
#include"TTable.h"
#include"TArrayTable.h"

// ����� ����������� ��������������� �������
class TScanTable : public TArrayTable {

	// ���� �������-���������
	/*
	    int TDataCom::RetCode; // ��� ���������� ��������
		int TTable::DataCount; // ���������� ������� � �������
	    int TTable::ColumnCount;// ���������� ������� �������
	    int TTable::Efficiency; // ���������� ������������� ���������� ��������
		TWord* TTable::ColumnName; // �������� ��������
		TTabRecord* pRecs; // ������ (������) �������
	    int TabSize; // ����������� ��������� ���������� ������� �������
	    int CurrPos; // ����� ������� ������
	*/

	// ������ ������
public:
	TScanTable(int tabsize_copy = TABMAXSIZE, int columncount_copy = 1, std::string * columnname_copy = nullptr); // ����������� ������

	virtual int GetType() const; // �������� ��� �������

	// �������� ������
	virtual TDatValue* FindRecord(TKey key_copy); // ����� ������ �� �����
	virtual void InsRecord(TKey key_copy, TDatValue* pvalue_copy); // �������� ������ � �������
	virtual void DelRecord(TKey key_copy); // ������� ������ �� �����

	// ������ �����-������
	virtual void Read(std::string pFileName) ; // ���� ������� �� �����
	/*
		������ �����:
			���������� �������
			���������� �������
			�������� �������
			������ � ����:
				����
				��������
	*/
	virtual void Write(std::string pFileName) const ; // ���������� ������� � ����
	/*
		������ �����:
			���������� �������
			���������� �������
			�������� �������
			������ � ����:
				����
				��������
	*/

	virtual void Print(std::ostream& out = std::cout) const; // ����� ������� � �������
	virtual void PrintHead(std::ostream& out = std::cout) const; // ������� �������� �������� ������� ( ����� )
};