#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"
#include"TDatLink.h"
#include"TDatList.h"

// конструктор
TDatList::TDatList() {
	this->pFirst = nullptr;
	this->pLast = nullptr;
	this->pCurr = nullptr;
	this->pPrev = nullptr;
	this->CurrPos = -1;
	this->ListLen = 0;
}

// конструктор преобразования типов
TDatList::TDatList(TDatValue** list, int listlen) {
	for (int i = 0; i < listlen; i++) {
		this->InsLast(list[i]);
	}
}

// деструктор
TDatList::~TDatList() {
	DelList();
}

// получить значение( 0 - первого, 1 - текущего, 2 - последнего )
TDatValue* TDatList::GetValue(int mode) const {
	if (mode == 0)
		return this->pFirst->GetValue();
	else if (mode == 1)
		return this->pCurr->GetValue();
	else if (mode == 2)
		return this->pLast->GetValue();
}

// получить длину
int TDatList::GetListLen(void) const {
	return this->ListLen;
}

// проверка списка на пустоту
bool TDatList::IsEmpty() const {
	if (this->pFirst == nullptr)
		return true;
	return false;
}

//установить текущий
void TDatList::SetCurrPos(int pos) {
	if (pos == -1) {
		this->pCurr = nullptr;
		this->pPrev = nullptr;
		this->CurrPos = -1;
	}
	else if (pos == 0) {
		this->pCurr = this->pFirst;
		this->pPrev = nullptr;
		this->CurrPos = 0;
	}
	else {
		TDatLink* temp = this->pFirst;
		int itr = 0;
		while (itr < pos - 1) {
			temp = temp->GetNext();
			itr++;
		}
		this->pPrev = temp;
		temp = temp->GetNext();
		this->pCurr = temp;
		this->CurrPos = pos;
	}
}

// получить номер текущего
int TDatList::GetCurrPos(void) const {
	return CurrPos;
}

// переместить текущий вперед
void TDatList::GoNext(void) {
	if (IsListEnded()) {
		this->CurrPos++;
		this->SetCurrPos(this->CurrPos);
	}
}

// переместить текущий назад
void TDatList::GoBack(void) {
	if (IsListStarted()) {
		this->CurrPos--;
		this->SetCurrPos(this->CurrPos);
	}
}

// установить текущий на начало
void TDatList::Reset(void) {
	this->SetCurrPos(0);
}

// true - если можно применить GoNext, false - если нельзя
bool TDatList::IsListEnded(void) const {
	if (this->pCurr == this->pLast)
		return false;
	return true;
}

// true - если можно применить GoBack, false - если нельзя
bool TDatList::IsListStarted(void) const {
	if (this->pCurr == this->pFirst)
		return false;
	return true;
}

// вставка в первый раз
void TDatList::InsFirstTime(TDatValue* pValue_copy) {
	TDatLink* temp = new TDatLink(pValue_copy->GetCopy());
	this->pFirst = temp;
	this->pLast = temp;
	this->ListLen = 1;
	this->SetCurrPos(0);
}

// вставить перед первым
void TDatList::InsFirst(TDatValue* pValue_copy) {
	if (this->IsEmpty())
		InsFirstTime(pValue_copy);
	else {
		TDatLink* temp = new TDatLink(pValue_copy->GetCopy());
		temp->SetNext(this->pFirst);
		this->pFirst = temp;
		this->ListLen++;
		this->SetCurrPos(this->CurrPos);
	}
}

// вставить последним
void TDatList::InsLast(TDatValue* pValue_copy) {
	if (this->IsEmpty())
		InsFirstTime(pValue_copy);
	else {
		TDatLink* temp = new TDatLink(pValue_copy->GetCopy());
		this->pLast->SetNext(temp);
		this->pLast = temp;
		this->ListLen++;
		this->SetCurrPos(this->CurrPos);
	}
}

// вставить перед текущим
void TDatList::InsCurrent(TDatValue* pValue_copy) {
	if (this->IsEmpty())
		InsFirstTime(pValue_copy);
	else if (this->GetCurrPos() == 0) {
		this->InsFirst(pValue_copy);
	}
	else if (this->GetCurrPos() != -1) {
		TDatLink* temp = new TDatLink(pValue_copy->GetCopy());
		temp->SetNext(this->pCurr);
		this->pPrev->SetNext(temp);
		this->pCurr = temp;
		this->ListLen++;
		this->SetCurrPos(this->CurrPos);
	}
}

// удалить первое звено
void TDatList::DelFirst(void) {
	if (!this->IsEmpty()) {
		TDatLink* temp = this->pFirst;
		this->pFirst = this->pFirst->GetNext();
		this->ListLen--;
		delete temp;
		int pos = this->CurrPos;
		if (this->IsEmpty())
			this->SetCurrPos(-1);
		while(pos >= this->ListLen)
			pos--;
		this->SetCurrPos(pos);
	}
}

// удалить текущее звено
void TDatList::DelCurrent(void) {
	if (!this->IsEmpty() && pCurr != nullptr) {
		if (this->pCurr == this->pFirst) {
			this->DelFirst();
		}
		else {
			TDatLink* temp = this->pCurr;
			this->pPrev->SetNext(this->pCurr->GetNext());
			this->ListLen--;
			delete temp;
			int pos = this->CurrPos;
			if (this->IsEmpty())
				this->SetCurrPos(-1);
			while (pos >= this->ListLen)
				pos--;
			this->SetCurrPos(pos);
		}
	}
}

// удалить весь список
void TDatList::DelList(void) {
	while (!this->IsEmpty()) {
		this->DelFirst();
	}
}

std::ostream& operator<<(std::ostream& os, TDatList& q) {
	os << "[";
	TDatLink* temp = q.pFirst;
	for (int i = 0; i < q.ListLen; i++) {
		os << " " << temp->GetValue()->ToStr();
		temp = temp->GetNext();
	}
	os << " ]";
	return os;
}