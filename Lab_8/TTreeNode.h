#pragma once
#include"TDatValue.h"
#include"TTabRecord.h"


// Класс объектов дерева
class TTreeNode : public TTabRecord {
	// Поля классов-предков
	/*
		int Type; // тип представляемого классом значения
		int Size; // количество хранимых значений
		TKey Key; // ключ записи
		TDatValue* pValue; // аргументы (значения, тело) записи
	*/

protected:
	TTreeNode* pLeft; // Указатель на левое поддерево
	TTreeNode* pRight; // Указатель на правое поддерево

public:
	TTreeNode(TKey key_copy = "", TDatValue* pvalue_copy = nullptr,
		TTreeNode* pleft_copy = nullptr, TTreeNode* pright_copy = nullptr); // конструктор класса

	TTreeNode* GetLeft(void) const; // получить указатель на левое поддерево
	void SetLeft(TTreeNode* pleft_copy); // задать указатель на левое поддерево
	TTreeNode* GetRight(void) const; // получить указатель на правое поддерево
	void SetRight(TTreeNode* pright_copy); // задать указатель на правое поддерево

	virtual TDatValue* GetCopy(void) const; // изготовить и вернуть копию

	virtual std::string ToStr(void) const; // получить содержимое готовое к выводу в виде строки
	/*
		Формат вывода: |      ключ|  аргумент|  аргумент|
		Ширина поля задается макросом WIDTH
	*/
	virtual std::string ToFileString(void) const; // получить содержимое готовое к выводу в виде строки
};