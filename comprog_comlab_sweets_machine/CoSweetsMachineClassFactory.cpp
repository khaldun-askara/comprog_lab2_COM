#include "CoSweetsMachineClassFactory.h"
#include "ÑoSweetsMachine.h"

STDMETHODIMP_(ULONG) CoSweetsMachineClassFactory::AddRef()
{
	return ++m_refCount;

}

STDMETHODIMP_(ULONG) CoSweetsMachineClassFactory::Release()
{
	if (--m_refCount == 0)
	{
		delete this;
		return 0;
	}
	return m_refCount;
}

STDMETHODIMP CoSweetsMachineClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	// Which aspect of me do they want?
	if (riid == IID_IUnknown)
	{
		*ppv = (IUnknown*)this;
	}
	else if (riid == IID_IClassFactory)
	{
		*ppv = (IClassFactory*)this;
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	((IUnknown*)(*ppv))->AddRef();
	return S_OK;
}

STDMETHODIMP CoSweetsMachineClassFactory::CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, void** ppv)
{
	if (pUnkOuter != NULL)
		return CLASS_E_NOAGGREGATION;

	ÑoSweetsMachine* pSweetsMachineObj = NULL;
	HRESULT hr;

	pSweetsMachineObj = new ÑoSweetsMachine;

	hr = pSweetsMachineObj->QueryInterface(riid, ppv);

	if (FAILED(hr))
		delete pSweetsMachineObj;

	return hr;	// S_OK or E_NOINTERFACE.

}

extern DWORD g_lockCount;
extern DWORD g_objCount;

CoSweetsMachineClassFactory::CoSweetsMachineClassFactory()
{
	m_refCount = 0;
	g_objCount++;
}

CoSweetsMachineClassFactory::~CoSweetsMachineClassFactory()
{
	g_objCount--;
}

STDMETHODIMP CoSweetsMachineClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
		++g_lockCount;
	else
		--g_lockCount;

	return S_OK;
}