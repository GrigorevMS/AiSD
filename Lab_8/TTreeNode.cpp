#pragma once
#include"TDatValue.h"
#include"TTabRecord.h"
#include"TTreeNode.h"


// конструктор класса
TTreeNode::TTreeNode(TKey key_copy, TDatValue* pvalue_copy,
	TTreeNode* pleft_copy, TTreeNode* pright_copy) {
	this->Type = 2;
	this->Size = 1;
	this->Key = key_copy;
	this->pValue = pvalue_copy;
	this->pLeft = pleft_copy;
	this->pRight = pright_copy;
}


// получить указатель на левое поддерево
TTreeNode* TTreeNode::GetLeft(void) const {
	return this->pLeft;
}


// задать указатель на левое поддерево
void TTreeNode::SetLeft(TTreeNode* pleft_copy) {
	this->pLeft = pleft_copy;
}


// получить указатель на правое поддерево
TTreeNode* TTreeNode::GetRight(void) const {
	return this->pRight;
}


// задать указатель на правое поддерево
void TTreeNode::SetRight(TTreeNode* pright_copy){
	this->pRight = pright_copy;
}


// изготовить и вернуть копию
TDatValue* TTreeNode::GetCopy(void) const {
	TTreeNode* temp = new TTreeNode(this->Key, this->pValue->GetCopy(), nullptr, nullptr);
	return temp;
}


// получить содержимое готовое к выводу в виде строки
/*
	Формат вывода: |      ключ|  аргумент|  аргумент|
	Ширина поля задается макросом WIDTH
*/
std::string TTreeNode::ToStr(void) const {
	std::string out = "|";
	for (int i = 0; i < WIDTH - this->Key.size(); i++) {
		out += ' ';
	}
	out = out + this->Key + '|';
	out += this->pValue->ToStr(); // this->pValue так же является наследником TDatValue
								  // и у него так же есть своя версия ToStr()
	return out;
}


// получить содержимое готовое к выводу в виде строки
std::string TTreeNode::ToFileString(void) const {
	std::string out = "";
	out = out + this->Key + '\n';
	out = out + this->pValue->ToFileString();
	return out;
}