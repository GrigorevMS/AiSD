#pragma once
#include"TTextLink.h"
#include"TStack.h"
#include<cstring>

class TText {

protected:
	TTextLink* pFirst; // указатель на корень дерева
	TTextLink* pCurrent; // указатель текущей строки
	TStack<TTextLink*> Path; // стек траекторий движени€ по тексту
	TStack<TTextLink*> Up; // стек переходов по down

	TTextLink* pIter; // указатель итератора
	TStack<TTextLink*> St; // стек дл€ итератора

	//TTextLink* ReadText(std::ifstream& TxtFile); // чтение текста из файла (непон€тно зачем)

public:
	TText(); // конструктор (+)
	TText(const TText& temp); // конструктор копировани€ (+)
	TText(TTextLink* temp); // конструктор преобразовани€ типов
	~TText(); // деструктор 

	TText GetCopy(); // вернуть копию (+)
	TTextLink* GetpFirst() const; // вернуть указатель на первый (+)
	TTextLink* GetpCurrent() const; // вернуть указатель на текущий (+)
	TTextLink* GetIterator(void) const; // получить указатель на3 итератор (+)

	// навигаци€
	bool GoFirstLink(void); // переход к первой строке (+)
	bool GoDownLink(void); // переход к следующей строке по pDown (+)
	bool GoNextLink(void); // переход к следующей строке по pNext (+)
	bool GoPrevLink(void); // переход к предыдущей позиции текста (+)
	bool GoUpLink(void); // переход к родителю (+)

	// модификаци€ структуры текста
	TTextLink* GetLink(void); // изъ€ть текущий элемент (или его поддерево)
	void DelLink(void); // удалить текущий элемент (или его поддерево)
	void DelSubTree(TTextLink* pTl); // рекурси€ удалени€ поддерева
	void InsNextLnk(TTextLink* pl); // вставить элемент pl (или его поддерево) следующим за текущим (+)
	void InsPrevLnk(TTextLink* pl); // вставить элемент pl (или его поддерево)перед теку-щим (+)
	void InsDownLink(TTextLink* pd); // вставить элемент pd (или его поддерево) вниз за текущим (+)
	void InsUpLink(TTextLink* pd); // вставить элемент pd (или его поддерево) вверх перед текущим (+)

	// доступ
	std::string GetLine(void);  // чтение текущей строки (+)
	void SetLine(string s); // замена текущей строки (+)

	// итератор
	void Reset(void); // установить на первую запись (+)
	bool IsTextEnded(void) const; // текст завершен? (+)
	bool GoNext(void); // переход к следующей записи (+)
	
	// –абота с файлами
	void Read(std::string pFileName); // ввод текста из файла (+)
	void Write(std::string pFileName); // сохранение текста в файл (+)

	// ѕечать
	void Print(void); // печать текста (+)
	void PrintText(TTextLink* ptl, int level = 0); // печать текста со звена ptl (рекурси€) (+)

	// ќператоры
	TText& operator=(const TText& c);

};