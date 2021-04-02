#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"
#include"TDatLink.h"

class TDatList {

protected:
	TDatLink* pFirst; // ������ �����
	TDatLink* pLast; // ��������� �����
	TDatLink* pCurr; // ������� ����� 
	TDatLink* pPrev; // ���������� �����
	int CurrPos; // ����� �������� (���� -1, ������ �� ���� �� ��������������. ����� �������������� ������� Reset())
	int ListLen; // ����� ������

	void InsFirstTime(TDatValue* pValue_copy = nullptr); // ������� � ������ ���

public:

	TDatList(); // �����������
	TDatList(TDatValue** list, int listlen); // ����������� �������������� �����
	~TDatList(); // ����������

	// Get
	TDatLink* GetFirst(void); // �������� ������
	TDatLink* GetLast(void); // �������� ���������
	TDatLink* GetCurr(void); // �������� �������
	TDatLink* GetPrev(void); // �������� ����������

	// ������
	TDatValue* GetValue(int mode = 1) const; // �������� ��������( 0 - �����������, 1 - ��������, 2 - ���������� )
	int GetListLen(void) const; // �������� �����
	bool IsEmpty() const; // �������� ������ �� �������

	// ���������
	void SetCurrPos(int pos); // ���������� �������
	int GetCurrPos(void) const; // �������� ����� ��������

	void GoNext(void); // ����������� ������� ������
	void GoBack(void); // ����������� ������� �����
	void Reset(void); // ���������� ������� �� ������

	bool IsListEnded(void) const; // true - ���� ����� ��������� GoNext, false - ���� ������
	bool IsListStarted(void) const; // true - ���� ����� ��������� GoBack, false - ���� ������

	// ������� �������
	void InsFirst(TDatValue* pValue_copy = nullptr); // �������� ����� ������
	void InsLast(TDatValue* pValue_copy = nullptr); // �������� ���������
	void InsCurrent(TDatValue* pValue_copy = nullptr); // �������� ����� �������
	
	// �������� �������
	void DelFirst(void); // ������� ������ �����
	void DelCurrent(void); // ������� ������� �����
	void DelList(void); // ������� ���� ������

	friend std::ostream& operator<<(std::ostream& os, TDatList& q);
};