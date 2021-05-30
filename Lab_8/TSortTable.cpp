#pragma once
#include"TTable.h"
#include"TArrayTable.h"
#include"TSortTable.h"
#include"ExtraFunctions.h"
#include<string>


// ����������� ������
TSortTable::TSortTable(int tabsize_copy, int columncount_copy, std::string* columnname_copy) {
	this->RetCode = 0;
	this->DataCount = 0;
	this->ColumnCount = columncount_copy;
	this->Efficiency = 0;
	this->TabSize = tabsize_copy;
	this->CurrPos = 0;
	this->pRecs = new TTabRecord[tabsize_copy];
	this->ColumnName = columnname_copy;
}


// �������� ��� �������
int TSortTable::GetType() const {
	return 1;
}


// ����� ������ �� �����
TDatValue* TSortTable::FindRecord(TKey key_copy) {
	int l = 0;
	int r = this->DataCount - 1;
	int m = 0;
	while (l <= r) {
		m = (l + r) / 2;
		if (key_copy < this->pRecs[m].GetKey()) {
			r = m - 1;
		}
		else if (this->pRecs[m].GetKey() < key_copy) {
			l = m + 1;
		}
		else {
			this->SetRetCode(0);
			return this->pRecs[m].GetCopy();
		}
	}
	this->SetRetCode(2);
	return nullptr;
}


// �������� ������ � �������
void TSortTable::InsRecord(TKey key_copy, TDatValue* pvalue_copy) {
	int pos = 0;
	while (this->pRecs[pos].GetKey() < key_copy && pos < this->DataCount) {
		pos++;
	}
	if (this->DataCount < this->TabSize) {
		for (int i = this->DataCount - 1; i >= pos; i--) {
			this->pRecs[i + 1] = this->pRecs[i];
		}
		this->pRecs[pos].SetKey(key_copy);
		this->pRecs[pos].SetpValue(pvalue_copy);
		this->SetRetCode(0);
		this->DataCount++;
	}
	else
		this->SetRetCode(4);
}


// ������� ������ �� �����
void TSortTable::DelRecord(TKey key_copy) {
	if (this->FindRecord(key_copy) != nullptr) {
		// ���� ����������� �������
		int pos = 0;
		while (this->pRecs[pos].GetKey() != key_copy)
			pos++;
		// �������� ���� �������
		this->pRecs[pos].SetKey("");
		this->pRecs[pos].SetpValue(nullptr);
		// �������� ��������
		for (int i = pos; i < this->DataCount - 1; i++) {
			this->pRecs[i] = this->pRecs[i + 1];
		}
		// �������� ��������� �������
		this->pRecs[this->DataCount - 1].SetKey("");
		this->pRecs[this->DataCount - 1].SetpValue(nullptr);
		// ��������� ���������� ������� � �������
		this->DataCount--;

		this->RetCode = 0; // OK
	}
	else
		this->RetCode = 2; // NO_SUCH_RECORD
}


// ���� ������� �� �����
/*
	������ �����:
		���������� �������
		���������� �������
		�������� �������
		������ � ����:
			����
			��������
*/
void TSortTable::Read(std::string pFileName) {
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
/*
	������ �����:
		���������� �������
		���������� �������
		�������� �������
		������ � ����:
			����
			��������
*/
void TSortTable::Write(std::string pFileName) const {
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
	for (int i = 0; i < this->DataCount; i++) {
		fout << this->pRecs[i].GetKey() << std::endl;
		fout << this->pRecs[i].GetpValue()->ToFileString() << std::endl;
	}
}


// ����� ������� � �������
void TSortTable::Print(std::ostream& out) const {
	this->PrintHead();
	for (int i = 0; i < this->DataCount; i++) {
		out << this->pRecs[i].ToStr() << std::endl;
	}
}


// ������� �������� �������� ������� ( ����� )
void TSortTable::PrintHead(std::ostream& out) const {
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