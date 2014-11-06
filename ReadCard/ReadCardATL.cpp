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
	jresult["retrunVal"] = 0;
	jresult["CardData"] = "abcd";
	*result = SysAllocString(CComBSTR(jresult.toStyledString().c_str()));
	return S_OK;
}
