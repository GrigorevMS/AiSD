#pragma once
#include"TDataCom.h"


//  ������ ��� ���������� ��������
void TDataCom::SetRetCode(int retcode_copy) {
	this->RetCode = retcode_copy;
}


// ����������� ������
TDataCom::TDataCom() {
	this->RetCode = 0;
}


// �������� ��� ���������� ��������
int TDataCom::GetRetCode(void) {
	int temp = RetCode;
	RetCode = 0;
	return temp;
}
