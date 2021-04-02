#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"

class TMonom : public TDatValue {

protected:
	float Coeff; //коэфицент монома
	int Index; // индекс ( свертка степеней )

public:
	TMonom(float coeff_copy = 1, int index_copy = 0); // конструктор
	virtual ~TMonom() {} // деструктор

	virtual TDatValue* GetCopy(void); // создание копии
	virtual std::string ToStr(void); // возврат содержимого в виде строки (type = 1 - со знаком коэфицента, type = 0 - без)

	void SetCoeff(float coeff_copy); // задать коэфицент
	float GetCoeff(void); // получить коэфицент
	void SetIndex(int index_copy); // задать индекс
	int GetIndex(void); // получить индекс

	TMonom& operator=(const TMonom& tm);
	bool operator==(const TMonom& tm);
	bool operator<(const TMonom& tm);
	bool operator>(const TMonom& tm);

	friend std::ostream& operator<<(std::ostream& os, TMonom& tm);
	friend class TPolinom;
};