#pragma once
#include<string>
class TDatValue {
public:
	virtual TDatValue* GetCopy() = 0; // создание копии
	virtual std::string ToStr() = 0; // возврат содержимого в виде строки
	virtual ~TDatValue() { } // деструктор
};