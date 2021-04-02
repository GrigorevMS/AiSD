#pragma once
#include<iostream>
#include"TMonom.h"
#include"TDatList.h"
#include"TDatValue.h"

class TPolinom {

protected:
	TDatList* List; // список

public:
	TPolinom(float Coeff_mas[] = nullptr, int Index_mas[] = nullptr, int monom_len = 0); // конструктор
	TPolinom(const TPolinom& q); // конструктор копирования
	
	TPolinom operator+(TPolinom& q); // сложение полиномов
	TPolinom operator-(TPolinom& q); // вычитание полиномов
	TPolinom operator=(const TPolinom& q); // присваивание

	friend std::ostream& operator<<(std::ostream& os, TPolinom& q);

};