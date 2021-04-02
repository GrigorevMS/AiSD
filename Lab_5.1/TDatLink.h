#pragma once
#include"TDatValue.h"

class TDatLink {

protected:
	TDatValue* pValue; // указатель на значение
	TDatLink* pNext; // указатель на следующее звено
public:
	TDatLink(TDatValue* pValue_copy = nullptr, TDatLink* pNext_copy = nullptr); // конструктор

	void SetValue(TDatValue* pValue_copy); // задать значение
	TDatValue* GetValue(void); // вернуть значение

	void SetNext(TDatLink* pNext_copy); // задать следующий элемент
	TDatLink* GetNext(void); // вернуть указатель на следующий
	friend class TDatlist;
};