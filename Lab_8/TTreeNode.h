#pragma once
#include"TDatValue.h"
#include"TTabRecord.h"


// ����� �������� ������
class TTreeNode : public TTabRecord {
	// ���� �������-�������
	/*
		int Type; // ��� ��������������� ������� ��������
		int Size; // ���������� �������� ��������
		TKey Key; // ���� ������
		TDatValue* pValue; // ��������� (��������, ����) ������
	*/

protected:
	TTreeNode* pLeft; // ��������� �� ����� ���������
	TTreeNode* pRight; // ��������� �� ������ ���������

public:
	TTreeNode(TKey key_copy = "", TDatValue* pvalue_copy = nullptr,
		TTreeNode* pleft_copy = nullptr, TTreeNode* pright_copy = nullptr); // ����������� ������

	TTreeNode* GetLeft(void) const; // �������� ��������� �� ����� ���������
	void SetLeft(TTreeNode* pleft_copy); // ������ ��������� �� ����� ���������
	TTreeNode* GetRight(void) const; // �������� ��������� �� ������ ���������
	void SetRight(TTreeNode* pright_copy); // ������ ��������� �� ������ ���������

	virtual TDatValue* GetCopy(void) const; // ���������� � ������� �����

	virtual std::string ToStr(void) const; // �������� ���������� ������� � ������ � ���� ������
	/*
		������ ������: |      ����|  ��������|  ��������|
		������ ���� �������� �������� WIDTH
	*/
	virtual std::string ToFileString(void) const; // �������� ���������� ������� � ������ � ���� ������
};