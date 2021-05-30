#pragma once
#define TABMAXSIZE 25 // максимальное число записей в таблице
#include"TTable.h"
#include<iostream>


// Положение элемента
/*
	1 - FIRST_POS
	0 - CURRENT_POS
	2 - LAST_POS
*/


// абстрактный класс представления таблиц на массивах
class TArrayTable : public TTable {

	// поля классов-родителей
	/*
		int TDataCom::RetCode; // код завершения операции
		int TTable::DataCount; // количество записей в таблице
		int TTable::ColumnCount;// количество колонок таблицы
		int TTable::Efficiency; // показатель эффективности выполнения операции
		TWord* TTable::ColumnName; // названия столбцов
	*/

	// поля класса
protected:
	TTabRecord* pRecs; // записи (строки) таблицы
	int TabSize; // максимально возможное количество записей таблицы
	int CurrPos; // номер текущей записи
	

	// методы класса
public:
	TArrayTable(int tabsize_copy = TABMAXSIZE, int columncount_copy = 1, std::string * columnname_copy = nullptr); // конструктор класса
	~TArrayTable() {}; // деструктор класса
	virtual bool IsFull() const; // таблица заполнена?

	// информационные методы
	virtual TKey GetKey(void) const; // получить ключ текущей записи
	virtual TDatValue* GetpValue(void) const; // получить указатель на аргументы записи

	virtual TKey GetKey(int mode) const; // получить ключ записи
	virtual TDatValue* GetpValue(int mode) const; // получить указатель на аргументы записи

	int GetSize(void) const; // получить максимальный размер таблицы
	void SetSize(int size_copy); // установить максимальный размер таблицы

	// навигация
	virtual void Reset(void); // установить номер текущей позиции на первую запись
	virtual bool IsTabEnded(void) const; // номер текущей позиции на последней записи?
	virtual bool GoNext(void); // переместить номер текущей записи на следующую запись
	/*
	    true - когда смогли перейти к следующей позиции
		false - когда завершили обход
	*/
	bool SetCurrPos(int pos); // установить номер текущей позции
	int GetCurrPos(void) const; // получить номер текущей записи

	friend class TTable;
};