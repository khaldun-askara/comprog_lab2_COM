#pragma once
#ifndef _INTERFACES
#define _INTERFACES

#include <windows.h>

//IStats ������������ ��� ��������� ��������� ������ ��������, � ����� 
//��� ����������� ���������� ��������� ������������ �������
DECLARE_INTERFACE_(IStats, IUnknown)
{
	STDMETHOD(DisplayStats)() PURE;
	STDMETHOD(GetSerialNumber)(BSTR * serialNumber) PURE;
};

//ICoinAcceptor ���������� ��������� ��������. ����� ��������� ���������� ������� (+10 �� ��������), 
//�������� �������� ������������ ����������� ����� � �������� ����������
DECLARE_INTERFACE_(ICoinAcceptor, IUnknown)
{
	STDMETHOD(BuyCandy)() PURE;
	STDMETHOD(GetMaxValue)(int* maxValue) PURE;
	STDMETHOD(GetCurValue)(int* curValue) PURE;
};

//ICreateMachine ������������ ��� ���������� ����� ������������  
//������� � ������� ������������ ����������� �����
DECLARE_INTERFACE_(ICreateMachine, IUnknown)
{
	STDMETHOD(SetSerialNumber)(BSTR serialNumber) PURE;
	STDMETHOD(SetMaxValue)(int maxValue) PURE;
};

#endif // _INTERFACES
