#pragma once
#include<iostream>
#include"TMonom.h"
#include"TDatList.h"
#include"TDatValue.h"
#include"TPolinom.h"

// конструктор
TPolinom::TPolinom(float Coeff_mas[], int Index_mas[], int monom_len) {
	int prom;
	for (int i = 0; i < monom_len - 1; i++) {
		for (int j = i + 1; j < monom_len; j++) {
			if (Index_mas[i] == Index_mas[j]) {
				Coeff_mas[i] = Coeff_mas[i] + Coeff_mas[j];
				Coeff_mas[j] = 0;
			}
		}
	}
	for (int i = 0; i < monom_len - 1; i++) {
		for (int j = i + 1; j < monom_len; j++) {
			if (Index_mas[j] > Index_mas[i]) {
				prom = Index_mas[j];
				Index_mas[j] = Index_mas[i];
				Index_mas[i] = prom;
			}
		}
	}
	List = new TDatList();
	TDatValue* temp;
	for (int i = 0; i < monom_len; i++)
	{
		if (Coeff_mas[i] != 0) {
			temp = new TMonom(Coeff_mas[i], Index_mas[i]);
			List->InsLast(temp);
		}
	}
}

// конструктор копирования
TPolinom::TPolinom(const TPolinom& q) {
	List = new TDatList();
	TDatValue* temp;
	TDatLink* curr = q.List->GetFirst();
	int len = q.List->GetListLen();
	for (int i = 0; i < len; i++) {
		temp = curr->GetValue()->GetCopy();
		List->InsLast(temp);
		curr = curr->GetNext();
	}
}

// сложение полиномов
TPolinom TPolinom::operator+(TPolinom& q) {
	TPolinom result;
	TDatValue* el;

	TDatLink* curr1 = this->List->GetFirst();
	TDatLink* curr2 = q.List->GetFirst();
	int len1 = this->List->GetListLen();
	int len2 = q.List->GetListLen();
	int pos1 = 0;
	int pos2 = 0;
	float coeff_result = 0;
	int index_result = 0;

	while (pos1 < len1 && pos2 < len2) {
		coeff_result = 0;
		index_result = 0;
		if (((TMonom*)curr1->GetValue())->GetIndex() == ((TMonom*)curr2->GetValue())->GetIndex()) {
			coeff_result = ((TMonom*)curr1->GetValue())->GetCoeff() + ((TMonom*)curr2->GetValue())->GetCoeff();
			index_result = ((TMonom*)curr1->GetValue())->GetIndex();
			pos1++;
			pos2++;
			curr1 = curr1->GetNext();
			curr2 = curr2->GetNext();
		}
		else if (((TMonom*)curr1->GetValue())->GetIndex() > ((TMonom*)curr2->GetValue())->GetIndex()) {
			coeff_result = ((TMonom*)curr1->GetValue())->GetCoeff();
			index_result = ((TMonom*)curr1->GetValue())->GetIndex();
			pos1++;
			curr1 = curr1->GetNext();
		}
		else {
			coeff_result = ((TMonom*)curr2->GetValue())->GetCoeff();
			index_result = ((TMonom*)curr2->GetValue())->GetIndex();
			pos2++;
			curr2 = curr2->GetNext();
		}
		if (coeff_result != 0) {
			el = new TMonom(coeff_result, index_result);
			result.List->InsLast(el);
		}
	}
	while (pos1 < len1) {
		coeff_result = ((TMonom*)curr1->GetValue())->GetCoeff();
		index_result = ((TMonom*)curr1->GetValue())->GetIndex();
		if (coeff_result != 0) {
			el = new TMonom(coeff_result, index_result);
			result.List->InsLast(el);
		}
		pos1++;
		curr1 = curr1->GetNext();
	}
	while (pos2 < len2) {
		coeff_result = ((TMonom*)curr2->GetValue())->GetCoeff();
		index_result = ((TMonom*)curr2->GetValue())->GetIndex();
		if (coeff_result != 0) {
			el = new TMonom(coeff_result, index_result);
			result.List->InsLast(el);
		}
		pos2++;
		curr2 = curr2->GetNext();
	}
	return result;
}

// вычитание полиномов
TPolinom TPolinom::operator-(TPolinom& q) {
	TPolinom result;
	TDatValue* el;

	TDatLink* curr1 = this->List->GetFirst();
	TDatLink* curr2 = q.List->GetFirst();
	int len1 = this->List->GetListLen();
	int len2 = q.List->GetListLen();
	int pos1 = 0;
	int pos2 = 0;
	float coeff_result = 0;
	int index_result = 0;

	while (pos1 < len1 && pos2 < len2) {
		coeff_result = 0;
		index_result = 0;
		if (((TMonom*)curr1->GetValue())->GetIndex() == ((TMonom*)curr2->GetValue())->GetIndex()) {
			coeff_result = ((TMonom*)curr1->GetValue())->GetCoeff() - ((TMonom*)curr2->GetValue())->GetCoeff();
			index_result = ((TMonom*)curr1->GetValue())->GetIndex();
			pos1++;
			pos2++;
			curr1 = curr1->GetNext();
			curr2 = curr2->GetNext();
		}
		else if (((TMonom*)curr1->GetValue())->GetIndex() > ((TMonom*)curr2->GetValue())->GetIndex()) {
			coeff_result = ((TMonom*)curr1->GetValue())->GetCoeff();
			index_result = ((TMonom*)curr1->GetValue())->GetIndex();
			pos1++;
			curr1 = curr1->GetNext();
		}
		else {
			coeff_result = (-1)*((TMonom*)curr2->GetValue())->GetCoeff();
			index_result = ((TMonom*)curr2->GetValue())->GetIndex();
			pos2++;
			curr2 = curr2->GetNext();
		}
		if (coeff_result != 0) {
			el = new TMonom(coeff_result, index_result);
			result.List->InsLast(el);
		}
	}
	while (pos1 < len1) {
		coeff_result = ((TMonom*)curr1->GetValue())->GetCoeff();
		index_result = ((TMonom*)curr1->GetValue())->GetIndex();
		if (coeff_result != 0) {
			el = new TMonom(coeff_result, index_result);
			result.List->InsLast(el);
		}
		pos1++;
		curr1 = curr1->GetNext();
	}
	while (pos2 < len2) {
		coeff_result = ((TMonom*)curr2->GetValue())->GetCoeff();
		index_result = ((TMonom*)curr2->GetValue())->GetIndex();
		if (coeff_result != 0) {
			el = new TMonom(coeff_result, index_result);
			result.List->InsLast(el);
		}
		pos2++;
		curr2 = curr2->GetNext();
	}
	return result;
}

// присваивание
TPolinom TPolinom::operator=(const TPolinom& q) {
	this->List->DelList();
	TDatLink* curr = q.List->GetFirst();
	int len = q.List->GetListLen();
	TDatValue* temp;
	for (int i = 0; i < len; i++) {
		temp = curr->GetValue()->GetCopy();
		this->List->InsLast(temp);
		curr = curr->GetNext();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, TPolinom& q) {
	TDatLink* curr = q.List->GetFirst();
	int len = q.List->GetListLen();
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			os << curr->GetValue()->ToStr();
		}
		else {
			if (((TMonom*)curr->GetValue())->GetCoeff() > 0)
				os << "+" << curr->GetValue()->ToStr();
			else
				os << curr->GetValue()->ToStr();
		}
		curr = curr->GetNext();
	}
	os << std::endl;
	return os;
}