#pragma once
#include"TDataCom.h"
#include"TDatValue.h"
#include"TTabRecord.h"
#include"TWord.h"
#include<iostream>
#include<fstream>


/*
    TDataCom->|                                             (обработка кодов завершени€)(+)
	          |->TTable->|                                  (абстрактный класс представлени€ таблиц)(+)
			             |->TArrayTable->|                  (абстрактный класс представлени€ таблиц на массивах)(+)
						 |               |->TScanTable      (просматриваемые таблицы)(+)
						 |				 |->TSortTable      (сортированные таблицы)
						 |->TTreeTable                      (класс деревьев поиска)  
						 |->THashTable->|                   (абстрактный класс представлени€ хэш-таблиц)
						                |->TArrayHash       (с открытым перемешиванием)
										|->TListHash        (с методом цепочек)
*/


// »нтерпретаци€ возвращаемых значений дл€ метода TTable::GetType()
/*
	0 - SCAN_TABLE
	1 - SORT_TABLE
	2 - TREE_TABLE
	3 - ARRAY_HASH
	4 - LIST_HASH
*/


// базовый абстрактный класс прдставлени€ таблиц
class TTable : public TDataCom {

	//пол€ класса
protected:
	int DataCount; // количество записей в таблице
	int ColumnCount;// количество колонок таблицы
	int Efficiency; // показатель эффективности выполнени€ операции

	std::string* ColumnName; // названи€ столбцов

	// методы класса
public:
	TTable(); // конструктор класса
	virtual ~TTable() {} // деструктор класса
	virtual int GetType() const = 0; // получить тип таблицы

	// информационные методы
	int GetDataCount(void) const; // полуить количество записей
	int GetColumnCount(void) const; // получить количество колонок
	int GetEfficiency(void) const; // получить показатель эффективности выполнени€ операции

	std::string* GetColumnName(void) const; // получить названи€ столбцов
	void SetColumnName(std::string* columnname_copy); // задать названи€ столбцов

	bool IsEmpty(void) const; // таблица пуста?
	virtual bool IsFull() const = 0; // таблица заполнена?


	// !!!!!!!!!!! непон€тно зачем они нужны, запись сама имеет эти методы !!!!!!!!!!!
	// доступ 
	virtual TKey GetKey(void) const = 0; // получить ключ записи
	virtual TDatValue* GetpValue(void) const = 0; // получить указатель на аргументы записи

	// навигаци€
	virtual void Reset(void) = 0; // установить номер текущей позиции на первую запись
	virtual bool IsTabEnded(void) const = 0; // номер текущей позиции на последней записи?
	virtual bool GoNext(void) = 0; // переместить номер текущей записи на следующую запись

	// основные методы
	virtual TDatValue* FindRecord(TKey key_copy) = 0; // найти запись по ключу
	virtual void InsRecord(TKey key_copy, TDatValue* pvalue_copy) = 0; // вставить запись в таблицу
	virtual void DelRecord(TKey key_copy) = 0; // удалить запись по ключу

	// методы ввода-вывода
	virtual void Read(std::string pFileName)  = 0; // ввод “аблицы из файла
	virtual void Write(std::string pFileName) = 0; // сохранение “аблицы в файл

	virtual void Print(std::ostream& out = std::cout) = 0; // вывод таблицы в консоль
	virtual void PrintHead(std::ostream& out = std::cout) = 0; // вывести названи€ столбцов “аблицы ( шапку )

};