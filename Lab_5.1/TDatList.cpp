#pragma once
#include<string>
#include<iostream>
#include"TDatValue.h"
#include"TDatLink.h"
#include"TDatList.h"

// �����������
TDatList::TDatList() {
	this->pFirst = nullptr;
	this->pLast = nullptr;
	this->pCurr = nullptr;
	this->pPrev = nullptr;
	this->CurrPos = -1;
	this->ListLen = 0;
}

// ����������� �������������� �����
TDatList::TDatList(TDatValue** list, int listlen) {
	for (int i = 0; i < listlen; i++) {
		this->InsLast(list[i]);
	}
}

// ����������
TDatList::~TDatList() {
	DelList();
}

// �������� ��������( 0 - �������, 1 - ��������, 2 - ���������� )
TDatValue* TDatList::GetValue(int mode) const {
	if (mode == 0)
		return this->pFirst->GetValue();
	else if (mode == 1)
		return this->pCurr->GetValue();
	else if (mode == 2)
		return this->pLast->GetValue();
}

// �������� �����
int TDatList::GetListLen(void) const {
	return this->ListLen;
}

// �������� ������ �� �������
bool TDatList::IsEmpty() const {
	if (this->pFirst == nullptr)
		return true;
	return false;
}

//���������� �������
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

// �������� ����� ��������
int TDatList::GetCurrPos(void) const {
	return CurrPos;
}

// ����������� ������� ������
void TDatList::GoNext(void) {
	if (IsListEnded()) {
		this->CurrPos++;
		this->SetCurrPos(this->CurrPos);
	}
}

// ����������� ������� �����
void TDatList::GoBack(void) {
	if (IsListStarted()) {
		this->CurrPos--;
		this->SetCurrPos(this->CurrPos);
	}
}

// ���������� ������� �� ������
void TDatList::Reset(void) {
	this->SetCurrPos(0);
}

// true - ���� ����� ��������� GoNext, false - ���� ������
bool TDatList::IsListEnded(void) const {
	if (this->pCurr == this->pLast)
		return false;
	return true;
}

// true - ���� ����� ��������� GoBack, false - ���� ������
bool TDatList::IsListStarted(void) const {
	if (this->pCurr == this->pFirst)
		return false;
	return true;
}

// ������� � ������ ���
void TDatList::InsFirstTime(TDatValue* pValue_copy) {
	TDatLink* temp = new TDatLink(pValue_copy->GetCopy());
	this->pFirst = temp;
	this->pLast = temp;
	this->ListLen = 1;
	this->SetCurrPos(0);
}

// �������� ����� ������
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

// �������� ���������
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

// �������� ����� �������
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

// ������� ������ �����
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

// ������� ������� �����
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

// ������� ���� ������
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