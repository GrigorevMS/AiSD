#pragma once
#define WIDTH 15 // ������ ���� ��������� � ������ ������ �� ������
#include<iostream>


// ������������� ������������ �������� ��� ������ TDatValue::GetType()
/*
	0 - NONE
	1 - TAB_RECORD
	2 - TREE_NODE
	3 - WORD
	4 - DOUBLE
*/


// ����� ����� ������������
/*
    TDatValue->|                (������� ����������� �����)(+)
               |->TTabRecord    (������ �������)(+)
			   |->TTreeNode     (���� ������)
			   |->TWord         (������ �����)(+)
			   |->TDouble       (������ ������������ �����)
			   |->TVed          (��������������� ���������)
*/


// ������� ����������� ����� �������� ��������
class TDatValue {

	 // ���� ������
protected:
	int Type; // ��� ��������������� ������� ��������
	int Size; // ���������� �������� ��������

	// ������ ������
public:
	TDatValue(int type_copy = 0, int size_copy = 1); // ����������� ������
	virtual ~TDatValue() {}; // ���������� ������
	
	int GetType(void) const; // �������� ��� ��������� ��������
	void SetType(int type_copy); // ������ ��� ��������� ��������

	int GetSize(void) const; // �������� ���������� �������� ��������
	void SetSize(int size_copy); // ������ ���������� �������� ��������

	// ������� ������������� ����������� � ������� �����������
	virtual TDatValue* GetCopy(void) const = 0; // �������� ����� ������ ������
	virtual std::string ToStr(void) const = 0; // �������� ���������� ������� � ������ � ���� ������
    /*
	    ������ ������: |      ����|  ��������|  ��������|
		������ ���� �������� �������� WIDTH
	*/
	virtual std::string ToFileString(void) const = 0; // �������� ���������� ������� � ������ � ���� ������

};