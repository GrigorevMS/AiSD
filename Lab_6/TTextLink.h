#pragma once
#define TextLineLength 20
#include<iostream>
#include<string>

class TTextLink {

protected:
	std::string Str[TextLineLength];// �������� ��������
	TTextLink* pNext; // ��������� �� ��������� ������� �� ��� �� ������
	TTextLink* pDown; // ��������� �� ������� ���� �������

	void Print(std::ostream& os); // ������ �����������

public:
	TTextLink(std::string s[TextLineLength] = nullptr, TTextLink* pNext_copy = nullptr, TTextLink* pDown_copy = nullptr); // �����������
	~TTextLink() {}

	bool IsAtom(); // �������� ����� �� �����������

	TTextLink* GetNext(); // �������� ��������� �� ���������
	TTextLink* GetDown(); // �������� ��������� �� �������� ���� �������

	friend std::ostream& operator<<(std::ostream& os, const TTextLink& tl);
	friend class TText;

};