// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "ReadCard_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CReadCardModule _AtlModule;
TCHAR szPath[MAX_PATH];
// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(hInstance, dwReason, lpReserved))
		return FALSE;
#endif
	hInstance;
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		GetModuleFileName(hInstance,szPath,MAX_PATH);
	}
	return _AtlModule.DllMain(dwReason, lpReserved); 
}
