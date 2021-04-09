#pragma once
#define TextLineLength 20
#include<iostream>
#include<string>

class TTextLink {

protected:
	std::string Str[TextLineLength];// хранимое значение
	TTextLink* pNext; // указатель на следующий элемент на том же уровне
	TTextLink* pDown; // указатель на элемент ниже уровнем

	void Print(std::ostream& os); // печать содержимого

public:
	TTextLink(std::string s[TextLineLength] = nullptr, TTextLink* pNext_copy = nullptr, TTextLink* pDown_copy = nullptr); // конструктор
	~TTextLink() {}

	bool IsAtom(); // проверка звена на атомарность

	TTextLink* GetNext(); // получить указатель на следующий
	TTextLink* GetDown(); // получить указатель на элеемент ниже уровнем

	friend std::ostream& operator<<(std::ostream& os, const TTextLink& tl);
	friend class TText;

};