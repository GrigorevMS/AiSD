#pragma once
#include"TTable.h"
#include"TTreeNode.h"
#include"TStack.h"


// ����� �������� ������
class TTreeTable : public TTable {

	// ���� �������-�������
	/*
		int DataCount; // ���������� ������� � �������
		int ColumnCount;// ���������� ������� �������
		int Efficiency; // ���������� ������������� ���������� ��������

		std::string* ColumnName; // �������� ��������
	*/

	// ���� ������
protected:
	TTreeNode* pRoot; // ��������� �� ������ ������
	TTreeNode** ppRef; // ����� ��������� �� �������-���������� � FindRecord
	TTreeNode* pCurrent; // ��������� �� ������� �������
	int CurrPos; // ����� ������� �������
	TStack<TTreeNode*> Stack; // ���� ��� ���������

	// ������ ������
public:
	TTreeTable(int columncount_copy = 1, std::string* columnname_copy = nullptr); // ����������� ������
	~TTreeTable(); // ���������� ������
	void DelTreeTab(TTreeNode pNode); // ��������

	virtual int GetType() const; // �������� ��� �������
	
	// �������������� ������
	virtual bool IsFull() const; // ��������� �� �������?

	// �������� ������
	virtual TDatValue* FindRecord(TKey key_copy); // ����� ������ �� �����
	virtual void InsRecord(TKey key_copy, TDatValue* pvalue_copy); // �������� ������ � �������
	virtual void DelRecord(TKey key_copy); // ������� ������ �� �����

	// ������
	virtual TKey GetKey(void) const; // �������� ���� ������
	virtual TDatValue* GetpValue(void) const; // �������� ��������� �� ��������� ������

	// ���������
	virtual void Reset(void); // ���������� ����� ������� ������� �� ������ ������
	virtual bool IsTabEnded(void) const; // ����� ������� ������� �� ��������� ������?
	virtual bool GoNext(void); // ����������� ����� ������� ������ �� ��������� ������

	// ������ �����-������
	virtual void Read(std::string pFileName); // ���� ������� �� �����
	virtual void Write(std::string pFileName); // ���������� ������� � ����

	virtual void Print(std::ostream& out = std::cout); // ����� ������� � �������
	virtual void PrintHead(std::ostream& out = std::cout); // ������� �������� �������� ������� ( ����� )
};