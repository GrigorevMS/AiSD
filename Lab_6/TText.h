#pragma once
#include"TTextLink.h"
#include"TStack.h"

class TText {

protected:
	TTextLink* pFirst; // указатель на корень дерева
	TTextLink* pCurrent; // указатель текущей строки
	TStack<TTextLink*> Path; // стек траекторий движения по тексту

	TStack<TTextLink*> St; // стек для итератора

	TTextLink* ReadText(std::ifstream& TxtFile); // чтение текста из файла

public:
	TText(TTextLink* pl = nullptr); // конструктор
	//~TText(); // деструктор

	//TText GetCopy(); // вернуть копию
	//TTextLink* GetpFirst(); // вернуть указатель на первый
	//TTextLink* GetpCurrent(); // вернуть указатель на текущий

	// навигация
	//bool GoFirstLink(void); // переход к первой строке
	//bool GoDownLink(void); // переход к следующей строке по pDown
	//bool GoNextLink(void); // переход к следующей строке по pNext
	//bool GoPrevLink(void); // переход к предыдущей позиции текста

	// модификация структуры текста
	//TTextLink* GetLink(void); // изъять текущий элемент (или его поддерево)
	//void DelLink(void); // удалить текущий элемент (или его поддерево)
	//void DelSubTree(TTextLink* pTl); // рекурсия удаления поддерева
	//void InsNextLnk(TTextLink* pl); // вставить элемент pl (или его поддерево) следующим за текущим
	//void InsPrevLnk(TTextLink* pl); // вставить элемент pl (или его поддерево)перед теку-щим
	//void InsDownLink(TTextLink* pd); // вставить элемент pd (или его поддерево) вниз за текущим
	//void InsUpLink(TTextLink* pd); // вставить элемент pd (или его поддерево) вверх перед текущим

	// доступ
	//string GetLine(void);  // чтение текущей строки
	//void SetLine(string s); // замена текущей строки

	// итератор
	//int Reset(void); // установить на первую запись
	//int IsTextEnded(void) const; // текст завершен?
	//int GoNext(void); // переход к следующей записи

	// Работа с файлами
	//void Read(char* pFileName); // ввод текста из файла
	//void Write(char* pFileName); // вывод текста в файл

	// Печать
	//void Print(void); // печать текста
	//void PrintText(TTextLink* ptl); // печать текста со звена ptl (рекурсия)

};