#include"TStack.h"

// �����������
template <typename Type>
TStack<Type>::TStack(int Size) {
	this->pMem = new Type[Size];
	this->MaxSize = Size;
	this->MemLen = 0;
	this->Hi = -1;
}

// ����������
template <typename Type>
TStack<Type>::~TStack() {
	delete[]this->pMem;
	this->MaxSize = 0;
	this->MemLen = 0;
	this->Hi = -1;
}

// ���� ����?
template <typename Type>
bool TStack<Type>::IsEmpty(void) const {
	if (this->MemLen == 0)
		return true;
	return false;
}

// ���� ��������?
template <typename Type>
bool TStack<Type>::IsFull(void) const {
	if (this->MemLen == this->MaxSize)
		return true;
	return false;
}

// �������� ��������
template <typename Type>
void TStack<Type>::Put(const Type Val) {
	if (this->IsFull() == false) {
		this.pMem[this.MemLen] = Val;
		this->MemLen += 1;
		this->Hi += 1;
	}
}

// ������� ��������
template <typename Type>
Type TStack<Type>::Get(void) {
	Type result = this->pMem[this->Hi];
	this->Hi -= 1;
	this->MemLen -= 1;
	return result;
}