#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"
#include"TDatLink.h"

class TDatList {

protected:
	TDatLink* pFirst; // первое звено
	TDatLink* pLast; // последнее звено
	TDatLink* pCurr; // текущее звено 
	TDatLink* pPrev; // предыдущее звено
	int CurrPos; // номер текущего (если -1, значит не разу не использовалось. Перед использованием вызвать Reset())
	int ListLen; // длина списка

	void InsFirstTime(TDatValue* pValue_copy = nullptr); // вставка в первый раз

public:

	TDatList(); // конструктор
	TDatList(TDatValue** list, int listlen); // конструктор преобразования типов
	~TDatList(); // деструктор

	// Get
	TDatLink* GetFirst(void); // получить первый
	TDatLink* GetLast(void); // получить последний
	TDatLink* GetCurr(void); // получить текущий
	TDatLink* GetPrev(void); // получить предыдущий

	// доступ
	TDatValue* GetValue(int mode = 1) const; // получить значение( 0 - предыдущего, 1 - текущего, 2 - следующего )
	int GetListLen(void) const; // получить длину
	bool IsEmpty() const; // проверка списка на пустоту

	// навигация
	void SetCurrPos(int pos); // установить текущий
	int GetCurrPos(void) const; // получить номер текущего

	void GoNext(void); // переместить текущий вперед
	void GoBack(void); // переместить текущий назад
	void Reset(void); // установить текущий на начало

	bool IsListEnded(void) const; // true - если можно применить GoNext, false - если нельзя
	bool IsListStarted(void) const; // true - если можно применить GoBack, false - если нельзя

	// вставка звеньев
	void InsFirst(TDatValue* pValue_copy = nullptr); // вставить перед первым
	void InsLast(TDatValue* pValue_copy = nullptr); // вставить последним
	void InsCurrent(TDatValue* pValue_copy = nullptr); // вставить перед текущим
	
	// удаление звеньев
	void DelFirst(void); // удалить первое звено
	void DelCurrent(void); // удалить текущее звено
	void DelList(void); // удалить весь список

	friend std::ostream& operator<<(std::ostream& os, TDatList& q);
};