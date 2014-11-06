// ReadCardATL.cpp : Implementation of CReadCard
#include "stdafx.h"
#include "ReadCardATL.h"
#include <comutil.h>
#include <json/json.h>


// CReadCard


STDMETHODIMP CReadCard::readyktcard(LONG port, BSTR* result)
{
	// TODO: Add your implementation code here
	Json::Value jresult;
	unsigned char CardData[MAX_PATH]={0};
	int ret = 0;
	if (myreadyktcard)
	{
		ret = myreadyktcard(1,2);
	}
	jresult["retrunVal"] = ret;
	jresult["CardData"] = (char *)CardData;
	std::string str = jresult.toStyledString();
	*result = SysAllocString(CComBSTR(str.c_str()));
	return S_OK;
}
