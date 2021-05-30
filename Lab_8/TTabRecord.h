#pragma once
#include"TDatValue.h"
#include<iostream>


typedef std::string TKey; // тип ключа записи


// класс строки таблицы
class TTabRecord : public TDatValue {

	// поля класса
protected:
	TKey Key; // ключ записи
	TDatValue* pValue; // аргументы (значения, тело) записи

	// методы класса
public:
	TTabRecord(TKey key_copy = "", TDatValue* pvalue_copy = nullptr); // конструктор класса

	virtual TDatValue* GetCopy(void) const; // получить копию объета класса
	virtual std::string ToStr(void) const; // получить содержимое готовое к выводу в виде строки
	virtual std::string ToFileString(void) const; // получить содержимое готовое к выводу в виде строки

	TKey GetKey(void) const; // получить ключ записи
	void SetKey(TKey key_copy); // задать ключ записи

	TDatValue* GetpValue(void) const; // получить указатель на арггуенты записи
	void SetpValue(TDatValue* pValue); // задать указатель на арггуенты записи

	TTabRecord& operator= (TTabRecord& tr); // оператор присваивания

	virtual bool operator ==(const TTabRecord& tr) const; // сравнение "="
	virtual bool operator <(const TTabRecord& tr) const; // сравнение "<"
	virtual bool operator >(const TTabRecord& tr) const; // сравнение ">"

};