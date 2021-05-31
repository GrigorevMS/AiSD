#pragma once
#include"TDatValue.h"
#include"TTabRecord.h"
#include"TTreeNode.h"


// ����������� ������
TTreeNode::TTreeNode(TKey key_copy, TDatValue* pvalue_copy,
	TTreeNode* pleft_copy, TTreeNode* pright_copy) {
	this->Type = 2;
	this->Size = 1;
	this->Key = key_copy;
	this->pValue = pvalue_copy;
	this->pLeft = pleft_copy;
	this->pRight = pright_copy;
}


// �������� ��������� �� ����� ���������
TTreeNode* TTreeNode::GetLeft(void) const {
	return this->pLeft;
}


// ������ ��������� �� ����� ���������
void TTreeNode::SetLeft(TTreeNode* pleft_copy) {
	this->pLeft = pleft_copy;
}


// �������� ��������� �� ������ ���������
TTreeNode* TTreeNode::GetRight(void) const {
	return this->pRight;
}


// ������ ��������� �� ������ ���������
void TTreeNode::SetRight(TTreeNode* pright_copy){
	this->pRight = pright_copy;
}


// ���������� � ������� �����
TDatValue* TTreeNode::GetCopy(void) const {
	TTreeNode* temp = new TTreeNode(this->Key, this->pValue->GetCopy(), nullptr, nullptr);
	return temp;
}


// �������� ���������� ������� � ������ � ���� ������
/*
	������ ������: |      ����|  ��������|  ��������|
	������ ���� �������� �������� WIDTH
*/
std::string TTreeNode::ToStr(void) const {
	std::string out = "|";
	for (int i = 0; i < WIDTH - this->Key.size(); i++) {
		out += ' ';
	}
	out = out + this->Key + '|';
	out += this->pValue->ToStr(); // this->pValue ��� �� �������� ����������� TDatValue
								  // � � ���� ��� �� ���� ���� ������ ToStr()
	return out;
}


// �������� ���������� ������� � ������ � ���� ������
std::string TTreeNode::ToFileString(void) const {
	std::string out = "";
	out = out + this->Key + '\n';
	out = out + this->pValue->ToFileString();
	return out;
}