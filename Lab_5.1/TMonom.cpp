#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"
#include"TMonom.h"

// конструктор
TMonom::TMonom(float coeff_copy, int index_copy) {
	this->Coeff = coeff_copy;
	this->Index = index_copy;
}

// создание копии
TDatValue* TMonom::GetCopy(void) {
	TDatValue* temp = new TMonom(this->Coeff, this->Index);
	return temp;
}

// возврат содержимого в виде строки (type = 1 - со знаком коэфицента, type = 0 - без)
std::string TMonom::ToStr(void) {
	std::string result = "";
	result += std::to_string(this->Coeff);
	result = result + "(" + std::to_string(this->Index) + ")";
	return result;
}

// задать коэфицент
void TMonom::SetCoeff(float coeff_copy) {
	this->Coeff = coeff_copy;
}

// получить коэфицент
float TMonom::GetCoeff(void) {
	return this->Coeff;
}

// задать индекс
void TMonom::SetIndex(int index_copy) {
	this->Index = index_copy;
}

// получить индекс
int TMonom::GetIndex(void) {
	return this->Index;
}

TMonom& TMonom::operator=(const TMonom& tm) {
	this->Coeff = tm.Coeff;
	this->Index = tm.Index;
	return *this;
}

bool TMonom::operator==(const TMonom& tm) {
	if (this->Index == tm.Index)
		return true;
	return false;
}

bool TMonom::operator<(const TMonom& tm) {
	if (this->Index < tm.Index)
		return true;
	else
		return false;
}

bool TMonom::operator>(const TMonom& tm) {
	if (this->Index > tm.Index)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, TMonom& tm) {
	os << tm.ToStr();
	return os;
}