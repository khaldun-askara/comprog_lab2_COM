#include "СoSweetsMachine.h"

#include "iid.h"
#include <cstdio>

extern DWORD g_objCount;

STDMETHODIMP_(DWORD) СoSweetsMachine::AddRef()
{
	++m_refCount;
	++g_objCount;
	return m_refCount;
}

STDMETHODIMP_(DWORD) СoSweetsMachine::Release()
{
	if (--m_refCount == 0)
	{
		delete this;
		--g_objCount;
		return 0;
	}
	else
		return m_refCount;
}

STDMETHODIMP СoSweetsMachine::QueryInterface(REFIID riid, void** pIFace)
{
	// Which aspect of me do they want?
	if (riid == IID_IUnknown)
	{
		*pIFace = (IUnknown*)(ICoinAcceptor*)this;
		MessageBox(NULL, L"Handed out IUnknown", L"QI", MB_OK |
			MB_SETFOREGROUND);
	}

	else if (riid == IID_ICoinAcceptor)
	{
		*pIFace = (ICoinAcceptor*)this;
		MessageBox(NULL, L"Handed out ICoinAcceptor", L"QI", MB_OK |
			MB_SETFOREGROUND);
	}

	else if (riid == IID_IStats)
	{
		*pIFace = (IStats*)this;
		MessageBox(NULL, L"Handed out IStats", L"QI", MB_OK |
			MB_SETFOREGROUND);
	}

	else if (riid == IID_ICreateMachine)
	{
		*pIFace = (ICreateMachine*)this;
		MessageBox(NULL, L"Handed out ICreateMachine", L"QI", MB_OK |
			MB_SETFOREGROUND);
	}
	else
	{
		*pIFace = NULL;
		return E_NOINTERFACE;
	}

	((IUnknown*)(*pIFace))->AddRef();
	return S_OK;
}

// Конструктор и деструктор СoSweetsMachine
СoSweetsMachine::СoSweetsMachine() : m_refCount(0), m_currValue(0), m_maxValue(0)
{
	m_SerialNumber = SysAllocString(L"Default Serial Number");
}

СoSweetsMachine::~СoSweetsMachine()
{
	if (m_SerialNumber)
		SysFreeString(m_SerialNumber);
	MessageBox(NULL, L"SweetsMachine is full", L"Destructor", MB_OK |
		MB_SETFOREGROUND);
}

// Реализация ICoinAcceptor
// одна конфетка стоит 10 монет!
STDMETHODIMP СoSweetsMachine::BuyCandy()
{
	m_currValue += 10;
	return S_OK;
}

STDMETHODIMP СoSweetsMachine::GetMaxValue(int* maxValue)
{
	*maxValue = m_maxValue;
	return S_OK;
}

STDMETHODIMP СoSweetsMachine::GetCurValue(int* curValue)
{
	*curValue = m_currValue;
	return S_OK;
}

// Реализация ICreateMachine
STDMETHODIMP СoSweetsMachine::SetSerialNumber(BSTR petName)
{
	SysReAllocString(&m_SerialNumber, petName);
	return S_OK;
}

STDMETHODIMP СoSweetsMachine::SetMaxValue(int maxValue)
{
	if (maxValue < MAX_VALUE)
		m_maxValue = maxValue;
	return S_OK;
}

// Реализация IStats
// Возвращает клиенту копию внутреннего буфера BSTR 
STDMETHODIMP СoSweetsMachine::GetSerialNumber(BSTR* serialNumber)
{
	*serialNumber = SysAllocString(m_SerialNumber);
	return S_OK;
}

// Информация о СoSweetsMachiner помещается в блоки сообщений
STDMETHODIMP СoSweetsMachine::DisplayStats()
{
	// Need to transfer a BSTR to a char array.
	char buff[MAX_NAME_LENGTH];
	WideCharToMultiByte(CP_ACP, NULL, m_SerialNumber, -1, buff,
		MAX_NAME_LENGTH, NULL, NULL);

	MessageBoxA(NULL, buff, "Serial number", MB_OK | MB_SETFOREGROUND);
	memset(buff, 0, sizeof(buff));
	sprintf_s(buff, "%d", m_maxValue);
	MessageBoxA(NULL, buff, "Max value", MB_OK |
		MB_SETFOREGROUND);
	return S_OK;
}
