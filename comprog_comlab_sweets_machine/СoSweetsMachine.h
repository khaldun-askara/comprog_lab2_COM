#pragma once
#include "interfaces.h"
const int MAX_VALUE = 500;
const int MAX_NAME_LENGTH = 100;

class �oSweetsMachine : public ICoinAcceptor, public ICreateMachine, public IStats
{
public:
	�oSweetsMachine();
	virtual ~�oSweetsMachine();

	// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void** pIFace);
	STDMETHODIMP_(DWORD)AddRef();
	STDMETHODIMP_(DWORD)Release();

	// ICoinAcceptor
	STDMETHODIMP BuyCandy();
	STDMETHODIMP GetMaxValue(int* maxSpeed);
	STDMETHODIMP GetCurValue(int* curSpeed);

	// IStats
	STDMETHODIMP DisplayStats();
	STDMETHODIMP GetSerialNumber(BSTR* petName);

	// ICreateMachine
	STDMETHODIMP SetSerialNumber(BSTR petName);
	STDMETHODIMP SetMaxValue(int maxSp);

private:
	unsigned long int m_refCount;
	BSTR	m_SerialNumber; // ������������� ����� SysAllocString(), 
	// �������� � ����� ����� SysFreeString()
	int		m_maxValue; // ������������ ����������� �����
	int		m_currValue; // ������� ���������� �����

};