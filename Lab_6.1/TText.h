#pragma once
#include"TTextLink.h"
#include"TStack.h"
#include<cstring>

class TText {

protected:
	TTextLink* pFirst; // ��������� �� ������ ������
	TTextLink* pCurrent; // ��������� ������� ������
	TStack<TTextLink*> Path; // ���� ���������� �������� �� ������
	TStack<TTextLink*> Up; // ���� ��������� �� down

	TTextLink* pIter; // ��������� ���������
	TStack<TTextLink*> St; // ���� ��� ���������

	//TTextLink* ReadText(std::ifstream& TxtFile); // ������ ������ �� ����� (��������� �����)

public:
	TText(); // ����������� (+)
	TText(const TText& temp); // ����������� ����������� (+)
	TText(TTextLink* temp); // ����������� �������������� �����
	~TText(); // ���������� 

	TText GetCopy(); // ������� ����� (+)
	TTextLink* GetpFirst() const; // ������� ��������� �� ������ (+)
	TTextLink* GetpCurrent() const; // ������� ��������� �� ������� (+)
	TTextLink* GetIterator(void) const; // �������� ��������� ��3 �������� (+)

	// ���������
	bool GoFirstLink(void); // ������� � ������ ������ (+)
	bool GoDownLink(void); // ������� � ��������� ������ �� pDown (+)
	bool GoNextLink(void); // ������� � ��������� ������ �� pNext (+)
	bool GoPrevLink(void); // ������� � ���������� ������� ������ (+)
	bool GoUpLink(void); // ������� � �������� (+)

	// ����������� ��������� ������
	TTextLink* GetLink(void); // ������ ������� ������� (��� ��� ���������)
	void DelLink(void); // ������� ������� ������� (��� ��� ���������)
	void DelSubTree(TTextLink* pTl); // �������� �������� ���������
	void InsNextLnk(TTextLink* pl); // �������� ������� pl (��� ��� ���������) ��������� �� ������� (+)
	void InsPrevLnk(TTextLink* pl); // �������� ������� pl (��� ��� ���������)����� ����-��� (+)
	void InsDownLink(TTextLink* pd); // �������� ������� pd (��� ��� ���������) ���� �� ������� (+)
	void InsUpLink(TTextLink* pd); // �������� ������� pd (��� ��� ���������) ����� ����� ������� (+)

	// ������
	std::string GetLine(void);  // ������ ������� ������ (+)
	void SetLine(string s); // ������ ������� ������ (+)

	// ��������
	void Reset(void); // ���������� �� ������ ������ (+)
	bool IsTextEnded(void) const; // ����� ��������? (+)
	bool GoNext(void); // ������� � ��������� ������ (+)
	
	// ������ � �������
	void Read(std::string pFileName); // ���� ������ �� ����� (+)
	void Write(std::string pFileName); // ���������� ������ � ���� (+)

	// ������
	void Print(void); // ������ ������ (+)
	void PrintText(TTextLink* ptl, int level = 0); // ������ ������ �� ����� ptl (��������) (+)

	// ���������
	TText& operator=(const TText& c);

};