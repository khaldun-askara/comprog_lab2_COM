#pragma once
#include "interfaces.h"
const int MAX_VALUE = 500;
const int MAX_NAME_LENGTH = 100;

class СoSweetsMachine : public ICoinAcceptor, public ICreateMachine, public IStats
{
public:
	СoSweetsMachine();
	virtual ~СoSweetsMachine();

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
	BSTR	m_SerialNumber; // Инициализация через SysAllocString(), 
	// удаление — через вызов SysFreeString()
	int		m_maxValue; // Максимальная вместимость монет
	int		m_currValue; // Текущее количество монет

};