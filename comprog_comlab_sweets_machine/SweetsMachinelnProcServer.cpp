#include <Windows.h>
#include "CoSweetsMachineClassFactory.h"
#include "iid.h"
ULONG g_lockCount = 0; // Количество блокировок сервера
ULONG g_objCount = 0; // Количество "живых" объектов в сервере

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	HRESULT hr;
	CoSweetsMachineClassFactory* pSMFact = NULL;

	if (rclsid != CLSID_CoSweetsMachine)
		return CLASS_E_CLASSNOTAVAILABLE;

	pSMFact = new CoSweetsMachineClassFactory;

	hr = pSMFact->QueryInterface(riid, ppv);

	if (FAILED(hr))
		delete pSMFact;

	return hr;
}

STDAPI DllCanUnloadNow()
{
	if (g_lockCount == 0 && g_objCount == 0)
	{
		return S_OK;
	}
	else
		return S_FALSE;
}

