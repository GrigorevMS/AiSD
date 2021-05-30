#pragma once


// ������������ �������� RetCode
/*
	0 - OK
	1 - UNKNOWN_ERROR
	2 - NO_SUCH_RECORD
	3 - SUCH_RECORD_ALREADY_EXISTS
	4 - NOT_ENOUGH_MEMORY
*/


// ������� ����������� ����� �������� � ��������� ����� ���������� ��������
class TDataCom {

	// ���� ������
protected:
	int RetCode; // ��� ���������� ��������

	// ������ ������
protected:
	void SetRetCode(int retcode_copy); //  ������ ��� ���������� ��������

public:
	TDataCom(); // ����������� ������
	virtual ~TDataCom() = 0 {} // ���������� ������

	int GetRetCode(void); // �������� ��� ���������� ��������

};