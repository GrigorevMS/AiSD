#pragma once
#include"TDatValue.h"
#include<iostream>


// класс-наследник TDatValue реализующий хранение массива строк
class TWord : public TDatValue {

	// поля класса
protected:
	std::string* Word; // массив хранимых строк
	// также используется поле TDatValue::Size

	// методы класса
public:
	TWord(std::string* word_copy = nullptr, int size_copy = 1); // конструктор класса
	virtual ~TWord() {}; // деструктор класса

	std::string* GetWord(void); // получить указатель на массив хранимых строк
	void SetWord(std::string* word_copy); // задать указатель на массив хранимых строк

	virtual TDatValue* GetCopy(void) const; // получить копию объета класса
	virtual std::string ToStr(void) const; // получить содержимое готовое к выводу в виде строки
	/*
		Формат вывода: |      ключ|  аргумент|  аргумент|
		Ширина поля задается макросом WIDTH
	*/
	virtual std::string ToFileString(void) const; // получить содержимое готовое к выводу в виде строки

};