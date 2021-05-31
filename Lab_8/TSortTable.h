#pragma once
#include"TTable.h"
#include"TArrayTable.h"


// Класс сортируемых таблиц
class TSortTable : public TArrayTable {

	// поля классов-родителей
	/*
		int TDataCom::RetCode; // код завершения операции
		int TTable::DataCount; // количество записей в таблице
		int TTable::ColumnCount;// количество колонок таблицы
		int TTable::Efficiency; // показатель эффективности выполнения операции
		TWord* TTable::ColumnName; // названия столбцов
		TTabRecord* pRecs; // записи (строки) таблицы
		int TabSize; // максимально возможное количество записей таблицы
		int CurrPos; // номер текущей записи
	*/

	// методы класса
public:
	TSortTable(int tabsize_copy = TABMAXSIZE, int columncount_copy = 1, std::string* columnname_copy = nullptr); // конструктор класса

	virtual int GetType() const; // получить тип таблицы

	// основные методы
	virtual TDatValue* FindRecord(TKey key_copy); // найти запись по ключу
	virtual void InsRecord(TKey key_copy, TDatValue* pvalue_copy); // вставить запись в таблицу
	virtual void DelRecord(TKey key_copy); // удалить запись по ключу

	// методы ввода-вывода
	virtual void Read(std::string pFileName); // ввод Таблицы из файла
	/*
		Формат файла:
			Количество записей
			количество колонок
			Названия колонок
			Записи в виде:
				ключ
				аргуметы
	*/
	virtual void Write(std::string pFileName); // сохранение Таблицы в файл
	/*
		Формат файла:
			Количество записей
			количество колонок
			Названия колонок
			Записи в виде:
				ключ
				аргуметы
	*/

	virtual void Print(std::ostream& out = std::cout); // вывод таблицы в консоль
	virtual void PrintHead(std::ostream& out = std::cout); // вывести названия столбцов Таблицы ( шапку )
};