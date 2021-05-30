#pragma once
#include<fstream>
#include<string>
#include"TScanTable.h"


// ��������������� �������
void SepScan(std::string input, std::string* mas, int count = 3) {
	for (int i = 0; i < count; i++) {
		mas[i] = "";
	}
	int high = 0; // ������ ��������� ������� � �������� ��������
	int pos = 0; // ������ ��� ����������� ������� ������
	std::string temp = "";
	while (pos < input.size() && high < count) {
		temp = "";
		while (input[pos] != ' ' && pos < input.size()) {
			temp = temp + input[pos];
			pos += 1;
		}
		mas[high] = temp;
		high += 1;
		while (input[pos] == ' ' && pos < input.size()) {
			pos += 1;
		}
	}
}


// ����������� ������
TScanTable::TScanTable(int tabsize_copy, int columncount_copy, std::string* columnname_copy) {
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
int TScanTable::GetType() const {
	return 0;
}


// ����� ������ �� �����
TDatValue* TScanTable::FindRecord(TKey key_copy) {
	for (int i = 0; i < this->DataCount; i++) {
		if (this->pRecs[i].GetKey() == key_copy) {
			this->RetCode = 0; // OK
			return &this->pRecs[i];
		}
	}
	this->RetCode = 2; // NO_SUCH_RECORD
	return nullptr;
}


// �������� ������ � �������
void TScanTable::InsRecord(TKey key_copy, TDatValue* pvalue_copy) {
	if (this->FindRecord(key_copy) == nullptr) {
		if (!this->IsFull()) {
			this->pRecs[this->DataCount].SetKey(key_copy);
			this->pRecs[this->DataCount].SetpValue(pvalue_copy);
			this->RetCode = 0; // OK
			this->DataCount++;
		}
		else
			this->RetCode = 4; // NOT_ENOUGH_MEMORY
	}
	else
		this->RetCode = 3; // SUCH_RECORD_ALREADY_EXISTS
}


// ������� ������ �� �����
void TScanTable::DelRecord(TKey key_copy) {
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
void TScanTable::Read(std::string pFileName) {
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
	SepScan(temp, mas, columncount_copy);
	delete[] this->GetColumnName();
	this->SetColumnName(mas);

	// ������ ������
	for (int i = 0; i < datacount_copy; i++) {
		mas = new std::string[columncount_copy];
		// ������ ����
		getline(fin, key_copy); 
		// ������ ���������
		getline(fin, temp); 
		SepScan(temp, mas, columncount_copy);
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
void TScanTable::Write(std::string pFileName) const {
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
void TScanTable::Print(std::ostream& out) const {
	this->PrintHead();
	for (int i = 0; i < this->DataCount; i++) {
		out << this->pRecs[i].ToStr() << std::endl;
	}
}

// ������� �������� �������� ������� ( ����� )
void TScanTable::PrintHead(std::ostream& out) const {
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