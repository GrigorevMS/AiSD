#pragma once
#include"TTextLink.h"
#include"TStack.h"

class TText {

protected:
	TTextLink* pFirst; // ��������� �� ������ ������
	TTextLink* pCurrent; // ��������� ������� ������
	TStack<TTextLink*> Path; // ���� ���������� �������� �� ������

	TStack<TTextLink*> St; // ���� ��� ���������

	TTextLink* ReadText(std::ifstream& TxtFile); // ������ ������ �� �����

public:
	TText(TTextLink* pl = nullptr); // �����������
	//~TText(); // ����������

	//TText GetCopy(); // ������� �����
	//TTextLink* GetpFirst(); // ������� ��������� �� ������
	//TTextLink* GetpCurrent(); // ������� ��������� �� �������

	// ���������
	//bool GoFirstLink(void); // ������� � ������ ������
	//bool GoDownLink(void); // ������� � ��������� ������ �� pDown
	//bool GoNextLink(void); // ������� � ��������� ������ �� pNext
	//bool GoPrevLink(void); // ������� � ���������� ������� ������

	// ����������� ��������� ������
	//TTextLink* GetLink(void); // ������ ������� ������� (��� ��� ���������)
	//void DelLink(void); // ������� ������� ������� (��� ��� ���������)
	//void DelSubTree(TTextLink* pTl); // �������� �������� ���������
	//void InsNextLnk(TTextLink* pl); // �������� ������� pl (��� ��� ���������) ��������� �� �������
	//void InsPrevLnk(TTextLink* pl); // �������� ������� pl (��� ��� ���������)����� ����-���
	//void InsDownLink(TTextLink* pd); // �������� ������� pd (��� ��� ���������) ���� �� �������
	//void InsUpLink(TTextLink* pd); // �������� ������� pd (��� ��� ���������) ����� ����� �������

	// ������
	//string GetLine(void);  // ������ ������� ������
	//void SetLine(string s); // ������ ������� ������

	// ��������
	//int Reset(void); // ���������� �� ������ ������
	//int IsTextEnded(void) const; // ����� ��������?
	//int GoNext(void); // ������� � ��������� ������

	// ������ � �������
	//void Read(char* pFileName); // ���� ������ �� �����
	//void Write(char* pFileName); // ����� ������ � ����

	// ������
	//void Print(void); // ������ ������
	//void PrintText(TTextLink* ptl); // ������ ������ �� ����� ptl (��������)

};