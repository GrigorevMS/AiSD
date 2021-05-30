#pragma once
#include"TDataCom.h"


//  задать код завершения операции
void TDataCom::SetRetCode(int retcode_copy) {
	this->RetCode = retcode_copy;
}


// конструктор класса
TDataCom::TDataCom() {
	this->RetCode = 0;
}


// получить код завершения операции
int TDataCom::GetRetCode(void) {
	int temp = RetCode;
	RetCode = 0;
	return temp;
}
