#pragma once
#ifndef _INTERFACES
#define _INTERFACES

#include <windows.h>

//IStats используется для получения серийного номера автомата, а также 
//для отображения параметров состояния реализуемого объекта
DECLARE_INTERFACE_(IStats, IUnknown)
{
	STDMETHOD(DisplayStats)() PURE;
	STDMETHOD(GetSerialNumber)(BSTR * serialNumber) PURE;
};

//ICoinAcceptor моделирует поведение автомата. Можем добавлять количество монеток (+10 за конфетку), 
//получать значения максимальной вместимости монет и текущего наполнения
DECLARE_INTERFACE_(ICoinAcceptor, IUnknown)
{
	STDMETHOD(BuyCandy)() PURE;
	STDMETHOD(GetMaxValue)(int* maxValue) PURE;
	STDMETHOD(GetCurValue)(int* curValue) PURE;
};

//ICreateMachine используется для присвоения имени реализуемому  
//объекту и задания максимальной вместимости монет
DECLARE_INTERFACE_(ICreateMachine, IUnknown)
{
	STDMETHOD(SetSerialNumber)(BSTR serialNumber) PURE;
	STDMETHOD(SetMaxValue)(int maxValue) PURE;
};

#endif // _INTERFACES
