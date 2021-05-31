#pragma once
#include"TTable.h"
#include"TTreeNode.h"
#include"TStack.h"


//  ласс деревьев поиска
class TTreeTable : public TTable {

	// пол€ классов-предков
	/*
		int DataCount; // количество записей в таблице
		int ColumnCount;// количество колонок таблицы
		int Efficiency; // показатель эффективности выполнени€ операции

		std::string* ColumnName; // названи€ столбцов
	*/

	// пол€ класса
protected:
	TTreeNode* pRoot; // указатель на корень дерева
	TTreeNode** ppRef; // адрес указател€ на вершину-результата в FindRecord
	TTreeNode* pCurrent; // указатель на текущую вершину
	int CurrPos; // номер текущей вершины
	TStack<TTreeNode*> Stack; // стек дл€ итератора

	// методы класса
public:
	TTreeTable(int columncount_copy = 1, std::string* columnname_copy = nullptr); // конструктор класса
	~TTreeTable(); // деструктор класса
	void DelTreeTab(TTreeNode pNode); // удаление

	virtual int GetType() const; // получить тип таблицы
	
	// информационные методы
	virtual bool IsFull() const; // заполнена ли таблица?

	// основные методв
	virtual TDatValue* FindRecord(TKey key_copy); // найти запись по ключу
	virtual void InsRecord(TKey key_copy, TDatValue* pvalue_copy); // вставить запись в таблицу
	virtual void DelRecord(TKey key_copy); // удалить запись по ключу

	// доступ
	virtual TKey GetKey(void) const; // получить ключ записи
	virtual TDatValue* GetpValue(void) const; // получить указатель на аргументы записи

	// навигаци€
	virtual void Reset(void); // установить номер текущей позиции на первую запись
	virtual bool IsTabEnded(void) const; // номер текущей позиции на последней записи?
	virtual bool GoNext(void); // переместить номер текущей записи на следующую запись

	// методы ввода-вывода
	virtual void Read(std::string pFileName); // ввод “аблицы из файла
	virtual void Write(std::string pFileName); // сохранение “аблицы в файл

	virtual void Print(std::ostream& out = std::cout); // вывод таблицы в консоль
	virtual void PrintHead(std::ostream& out = std::cout); // вывести названи€ столбцов “аблицы ( шапку )
};