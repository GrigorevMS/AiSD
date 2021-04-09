#include<iostream>
using namespace std;
const int MaxMemSixe = 100; // ����������� ������ ������ ��� �����

template <class Type>
class TStack {

protected:
	Type* pMem; // ��������� �� ������ ���������
	int MaxSize; // ������ ���������� ������
	int MemLen; // ���������� ��������� ������� � �����
	int Hi; // ������ ������� �����

public:
	TStack(int Size = MaxMemSixe); // �����������
	~TStack(); // ����������

	bool IsEmpty(void) const; // ���� ����?
	bool IsFull(void) const; // ���� ��������?

	void Put(const Type Val); // �������� ��������
	Type Get(void); // ������� ��������
	Type See(void); // ���������� ��������

	void Output(void); // ����� �� ��������
	

};



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
		this->pMem[this->MemLen] = Val;
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

// ���������� ��������
template<typename Type>
Type TStack<Type>::See(void) {
	return this->pMem[this->Hi];
}

// ����� �� ��������
template<typename Type>
void TStack<Type>::Output(void) {
	cout << endl << "[ ";
	for (int i = 0; i < this->MemLen; i++) {
		cout << this->pMem[i] << " ";
	}
	cout << "]" << endl;
	cout << "MemLen = " << this->MemLen << endl;
	cout << "Hi = " << this->Hi << endl;
}