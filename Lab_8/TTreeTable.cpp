#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"TTreeNode.h"
#include"TTable.h"
#include"TTreeTable.h"
#include"ExtraFunctions.h"


// ����������� ������
TTreeTable::TTreeTable(int columncount_copy, std::string* columnname_copy) {
	this->RetCode = 0;
	this->DataCount = 0;
	this->ColumnCount = columncount_copy;
	this->Efficiency = 0;
	this->CurrPos = 0;
	this->ColumnName = columnname_copy;
	this->pRoot = nullptr;
	this->ppRef = nullptr;
	this->pCurrent = nullptr;
	this->CurrPos = 0;
}


// ���������� ������
TTreeTable::~TTreeTable() {
	this->DelTreeTab(*this->pRoot);
}


// ��������
void TTreeTable::DelTreeTab(TTreeNode pNode) {
	if (pNode.GetLeft() != nullptr)
		this->DelTreeTab(*pNode.GetLeft());
	else if (pNode.GetRight() != nullptr)
		this->DelTreeTab(*pNode.GetRight());
	delete this->GetpValue();
}


// �������� ��� �������
int TTreeTable::GetType() const {
	return 2;
}


// ��������� �� �������?
bool TTreeTable::IsFull() const {
	return false;
}


// ����� ������ �� �����
TDatValue* TTreeTable::FindRecord(TKey key_copy) {
	TTreeNode* cursor = this->pRoot;
	while (cursor != nullptr) {
		if (key_copy < cursor->GetKey()) {
			cursor = cursor->GetLeft();
		}
		else if (cursor->GetKey() < key_copy) {
			cursor = cursor->GetRight();
		}
		else if (cursor->GetKey() == key_copy) {
			this->RetCode = 0; // OK
			return cursor;
		}
	}
	this->RetCode = 2; // NO_SUCH_RECORD
	return nullptr;
}


// �������� ������ � �������
void TTreeTable::InsRecord(TKey key_copy, TDatValue* pvalue_copy) {
	if (this->pRoot == nullptr) {
		this->pRoot = new TTreeNode(key_copy, pvalue_copy);
		this->RetCode = 0; // OK
		this->DataCount += 1;
	}
	else {
		TTreeNode* cursor = this->pRoot;
		bool check = true;
		while (cursor->GetKey() != key_copy) {
			if (key_copy < cursor->GetKey()) {
				if (cursor->GetLeft() != nullptr) {
					cursor = cursor->GetLeft();
				}
				else {
					cursor->SetLeft(new TTreeNode(key_copy, pvalue_copy));
					cursor = cursor->GetLeft();
					this->DataCount += 1;
					this->RetCode = 0; // OK
					check = false;
				}
			}
			else if (cursor->GetKey() < key_copy) {
				if (cursor->GetRight() != nullptr) {
					cursor = cursor->GetRight();
				}
				else {
					cursor->SetRight(new TTreeNode(key_copy, pvalue_copy));
					cursor = cursor->GetRight();
					this->DataCount += 1;
					this->RetCode = 0; // OK
					check = false;
				}
			}
		}
		if (check)
			this->RetCode = 3; // SUCH_RECORD_ALREADY_EXISTS
	}
}


// ������� ������ �� �����
void TTreeTable::DelRecord(TKey key_copy) {

}


// �������� ���� ������
TKey TTreeTable::GetKey(void) const {
	return this->pCurrent->GetKey();
}


// �������� ��������� �� ��������� ������
TDatValue* TTreeTable::GetpValue(void) const {
	return this->pCurrent->GetpValue();
}


// ���������� ����� ������� ������� �� ������ ������
void TTreeTable::Reset(void) {
	this->pCurrent = this->pRoot;
	while (this->pCurrent != nullptr) {
		this->Stack.Put(this->pCurrent);
		this->pCurrent = this->pCurrent->GetLeft();
	}
	this->GoNext();
}


// ����� ������� ������� �� ��������� ������?
bool TTreeTable::IsTabEnded(void) const {
	if (this->Stack.IsEmpty() && this->pCurrent == nullptr)
		return true;
	return false;
}


// ����������� ����� ������� ������ �� ��������� ������
bool TTreeTable::GoNext(void) {
	if (!this->Stack.IsEmpty()) {
		this->pCurrent = this->Stack.Get();
		TTreeNode* temp = this->pCurrent->GetRight();
		while (temp != nullptr) {
			this->Stack.Put(temp);
			temp = temp->GetLeft();
		}
		return true;
	}
	this->pCurrent = nullptr;
	return false;
}


// ���� ������� �� �����
void TTreeTable::Read(std::string pFileName) {
	std::fstream fin;
	fin.open(pFileName);

	int datacount_copy = 0;
	int columncount_copy = 0;
	TKey key_copy = "";
	std::string temp = "";
	std::string* mas = nullptr;

	// ������ ���������� �������
	getline(fin, temp);
	datacount_copy = stoi(temp);
	// ������ ���������� �������
	getline(fin, temp);
	columncount_copy = stoi(temp);

	this->ColumnCount = columncount_copy;
	mas = new std::string[columncount_copy];

	// ������ �������� �������
	getline(fin, temp);
	Sep(temp, mas, columncount_copy);
	delete[] this->GetColumnName();
	this->SetColumnName(mas);

	// ������ ������
	for (int i = 0; i < datacount_copy; i++) {
		mas = new std::string[columncount_copy];
		// ������ ����
		getline(fin, key_copy);
		// ������ ���������
		getline(fin, temp);
		Sep(temp, mas, columncount_copy);
		this->InsRecord(key_copy, new TWord(mas, columncount_copy));
	}
}


// ���������� ������� � ����
void TTreeTable::Write(std::string pFileName) {
	std::ofstream fout;
	fout.open(pFileName);

	// ������ ���������� �������
	fout << this->DataCount << std::endl;

	// ������ ���������� �������
	fout << this->ColumnCount << std::endl;

	// ������ �������� �������
	for (int i = 0; i < this->ColumnCount; i++) {
		fout << this->ColumnName[i] << " ";
	}
	fout << std::endl;

	// ������ ������
	this->Reset();
	while (!this->IsTabEnded()) {
		fout << this->pCurrent->GetKey() << std::endl;
		fout << this->pCurrent->GetpValue()->ToFileString() << std::endl;
		this->GoNext();
	}
}


// ����� ������� � �������
void TTreeTable::Print(std::ostream& out) {
	this->PrintHead(out);
	this->Reset();
	while (!this->IsTabEnded()) {
		out << this->pCurrent->ToStr() << std::endl;
		this->GoNext();
	}
}


// ������� �������� �������� ������� ( ����� )
void TTreeTable::PrintHead(std::ostream& out) {
	out << '|';
	for (int j = 0; j < WIDTH - 3; j++) {
		out << " ";
	}
	out << "Key|";
	for (int i = 0; i < this->ColumnCount; i++) {
		for (int j = 0; j < WIDTH - this->ColumnName[i].size(); j++) {
			out << " ";
		}
		out << this->ColumnName[i] << '|';
	}
	out << std::endl;
	out << "+";
	for (int i = 0; i < this->ColumnCount + 1; i++) {
		for (int j = 0; j < WIDTH; j++) {
			out << "-";
		}
		out << "+";
	}
	out << std::endl;
}