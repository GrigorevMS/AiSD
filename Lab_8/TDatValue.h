#pragma once
#define WIDTH 15 // ширина поля аргумента в строке выдачи на экране
#include<iostream>


// Интерпретация возвращаемых значений для метода TDatValue::GetType()
/*
	0 - NONE
	1 - TAB_RECORD
	2 - TREE_NODE
	3 - WORD
	4 - DOUBLE
*/


// общая схема наследования
/*
    TDatValue->|                (базовый абстрактный класс)(+)
               |->TTabRecord    (строка таблицы)(+)
			   |->TTreeNode     (узел дерева)
			   |->TWord         (массив строк)(+)
			   |->TDouble       (массив вещественных чисел)
			   |->TVed          (экзаменационная ведомость)
*/


// базовый абстрактный класс хранимых значений
class TDatValue {

	 // поля класса
protected:
	int Type; // тип представляемого классом значения
	int Size; // количество хранимых значений

	// методы класса
public:
	TDatValue(int type_copy = 0, int size_copy = 1); // конструктор класса
	virtual ~TDatValue() {}; // деструктор класса
	
	int GetType(void) const; // получить тип хранимого значения
	void SetType(int type_copy); // задать тип хранимого значения

	int GetSize(void) const; // получить количество хранимых значений
	void SetSize(int size_copy); // задать количество хранимых значений

	// требуют обязательного определения в классах наследниках
	virtual TDatValue* GetCopy(void) const = 0; // получить копию объета класса
	virtual std::string ToStr(void) const = 0; // получить содержимое готовое к выводу в виде строки
    /*
	    Формат вывода: |      ключ|  аргумент|  аргумент|
		Ширина поля задается макросом WIDTH
	*/
	virtual std::string ToFileString(void) const = 0; // получить содержимое готовое к выводу в виде строки

};