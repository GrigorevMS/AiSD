#include<iostream>
using namespace std;
const int MaxMemSixe = 100; // масимальный размер памяти для стека

template <class Type>
class TStack {

protected:
	Type* pMem; // указатель на массив элементов
	int MaxSize; // размер выделенной памяти
	int MemLen; // количество элементов лежащих в стеке
	int Hi; // индекс вершины стека

public:
	TStack(int Size = MaxMemSixe); // конструткор
	~TStack(); // деструткор

	bool IsEmpty(void) const; // стек пуст?
	bool IsFull(void) const; // стек заполнен?

	void Put(const Type Val); // добавить значение
	Type Get(void); // извлечь значение
	Type See(void); // посмотреть значение

	void Output(void); // вывод на просмотр
	

};



// конструткор
template <typename Type>
TStack<Type>::TStack(int Size) {
	this->pMem = new Type[Size];
	this->MaxSize = Size;
	this->MemLen = 0;
	this->Hi = -1;
}

// деструткор
template <typename Type>
TStack<Type>::~TStack() {
	delete[]this->pMem;
	this->MaxSize = 0;
	this->MemLen = 0;
	this->Hi = -1;
}

// стек пуст?
template <typename Type>
bool TStack<Type>::IsEmpty(void) const {
	if (this->MemLen == 0)
		return true;
	return false;
}

// стек заполнен?
template <typename Type>
bool TStack<Type>::IsFull(void) const {
	if (this->MemLen == this->MaxSize)
		return true;
	return false;
}

// добавить значение
template <typename Type>
void TStack<Type>::Put(const Type Val) {
	if (this->IsFull() == false) {
		this->pMem[this->MemLen] = Val;
		this->MemLen += 1;
		this->Hi += 1;
	}
}

// извлечь значение
template <typename Type>
Type TStack<Type>::Get(void) {
	Type result = this->pMem[this->Hi];
	this->Hi -= 1;
	this->MemLen -= 1;
	return result;
}

// посмотреть значение
template<typename Type>
Type TStack<Type>::See(void) {
	return this->pMem[this->Hi];
}

// вывод на просмотр
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