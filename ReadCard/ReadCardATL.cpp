// ReadCardATL.cpp : Implementation of CReadCard
#include "stdafx.h"
#include "ReadCardATL.h"
#include <comutil.h>
#include <json/json.h>


// CReadCard
int __stdcall readyktcard(int , unsigned char * );

STDMETHODIMP CReadCard::readyktcard(LONG port, BSTR* result)
{
	// TODO: Add your implementation code here
	Json::Value jresult;
	unsigned char CardData[MAX_PATH]={0};
	int ret =  ::readyktcard(port,CardData);
	std::string strData(CardData, CardData+16);
	
	jresult["retrunVal"] = ret;
	jresult["CardData"] = strData;
	std::string str = jresult.toStyledString();
	*result = SysAllocString(CComBSTR(str.c_str()));
	return S_OK;
}
