#include <iostream>
#include <objbase.h>
#include "../comprog_comlab_sweets_machine/interfaces.h"
#include "../comprog_comlab_sweets_machine/iid.h"
using namespace std;



int main()
{
	CoInitialize(NULL); // This parameter is reserved, 
					   // and should be NULL

	HRESULT hr;
	IClassFactory* pCF = NULL;
	ICreateMachine* pICreateSM = NULL;
	IStats* pStats = NULL;
	ICoinAcceptor* pAcceptor = NULL;

	hr = CoGetClassObject(CLSID_CoSweetsMachine, CLSCTX_INPROC_SERVER,
		NULL, IID_IClassFactory, (void**)&pCF);

	// Make a CoSweetsMachine & get ICreateMachine.
	hr = pCF->CreateInstance(NULL, IID_ICreateMachine,
		(void**)&pICreateSM);
	pCF->Release();

	if (SUCCEEDED(hr))
	{
		pICreateSM->SetMaxValue(100);
		BSTR serialNumber = SysAllocString(L"SM666");
		pICreateSM->SetSerialNumber(serialNumber);
		SysFreeString(serialNumber);

		// Now get IStats
		hr = pICreateSM->QueryInterface(IID_IStats,
			(void**)&pStats);
		pICreateSM->Release();
	}

	if (SUCCEEDED(hr))
	{
		// Show my machine!
		pStats->DisplayStats();
		hr = pStats->QueryInterface(IID_ICoinAcceptor,
			(void**)&pAcceptor);
	}

	if (SUCCEEDED(hr))
	{
		int curSp = 0;
		int maxSp = 0;
		pAcceptor->GetMaxValue(&maxSp);

		do
		{
			pAcceptor->BuyCandy();
			pAcceptor->GetCurValue(&curSp);
			cout << "+1 candy in your inventory. Coins in machine: " << curSp << endl;
		} while (curSp < maxSp);

		// Gotta convert to char array.
		char buff[80];
		BSTR bstr;
		pStats->GetSerialNumber(&bstr);
		WideCharToMultiByte(CP_ACP, NULL, bstr, -1, buff,
			80, NULL, NULL);
		cout << "You bought all sweets from " << buff << "." << endl << endl;
		SysFreeString(bstr);

		if (pAcceptor) pAcceptor->Release();
		if (pStats) pStats->Release();
	}

	CoUninitialize();
	return 0;
}
