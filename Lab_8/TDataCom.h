#pragma once


// Интепретация значений RetCode
/*
	0 - OK
	1 - UNKNOWN_ERROR
	2 - NO_SUCH_RECORD
	3 - SUCH_RECORD_ALREADY_EXISTS
	4 - NOT_ENOUGH_MEMORY
*/


// базовый абстрактный класс хранения и обработки кодов завершения операций
class TDataCom {

	// поля класса
protected:
	int RetCode; // код завершения операции

	// методы класса
protected:
	void SetRetCode(int retcode_copy); //  задать код завершения операции

public:
	TDataCom(); // конструктор класса
	virtual ~TDataCom() = 0 {} // деструктор класса

	int GetRetCode(void); // получить код завершения операции

};