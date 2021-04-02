#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"

class TItemValue : public TDatValue {

protected:
	int Value; // значение
public:
	TItemValue(int value_copy = 0); // конструктор
	TItemValue(const TItemValue& temp); // конструктор копирования
	virtual ~TItemValue(){}

	virtual TDatValue* GetCopy(); // создание копии
	virtual std::string ToStr(); // возврат содержимого в виде строки

	void SetValue(int value_copy = 0); // задать значение
	int GetValue(void); // вернуть значение

	// операторы
	TItemValue& operator=(const TItemValue& temp);
	bool operator==(const TItemValue& temp);
	bool operator<(const TItemValue& temp);
	bool operator>(const TItemValue& temp);
	friend std::ostream& operator<<(std::ostream& os, TItemValue& temp);
};