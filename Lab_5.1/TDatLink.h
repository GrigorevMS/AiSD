#pragma once
#include"TDatValue.h"

class TDatLink {

protected:
	TDatValue* pValue; // ��������� �� ��������
	TDatLink* pNext; // ��������� �� ��������� �����
public:
	TDatLink(TDatValue* pValue_copy = nullptr, TDatLink* pNext_copy = nullptr); // �����������

	void SetValue(TDatValue* pValue_copy); // ������ ��������
	TDatValue* GetValue(void); // ������� ��������

	void SetNext(TDatLink* pNext_copy); // ������ ��������� �������
	TDatLink* GetNext(void); // ������� ��������� �� ���������
	friend class TDatlist;
};