// --------------------------------------------------------------------------------------------------------------------
// Copyright (C) 2016 L.A.S - LAS Soft
//
// This program is free software: you can redistribute it and/or modify
// it under the +terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/. 
//
// Keyboard.cpp - Contains the WMIBase's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include <comdef.h>
#include <string.h>
#include <Wbemidl.h>

#include "WMIBase.h"

#pragma comment(lib, "wbemuuid.lib")

CWMIBase::~CWMIBase(){
	this->PEnumerator->Release();
	this->PServices->Release();
    this->PLocator->Release();
}

void CWMIBase::InitializeCOM(){

	this->HResult = CoInitializeEx(0, COINIT_MULTITHREADED);
}

void CWMIBase::SetSecurityLevel(){

	this->HResult = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
}

void CWMIBase::ObtainWMILocator(){

	this->HResult = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*) &this->PLocator);
}

void CWMIBase::Connect(){

	this->HResult = this->PLocator->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &this->PServices);
}

void CWMIBase::SetProxySecurityLevels(){

	this->HResult = 
		CoSetProxyBlanket(this->PServices, 
							RPC_C_AUTHN_WINNT, 
							RPC_C_AUTHZ_NONE, 
							NULL, 
							RPC_C_AUTHN_LEVEL_CALL, 
							RPC_C_IMP_LEVEL_IMPERSONATE, 
							NULL, 
							EOAC_NONE);
}

BOOL CWMIBase::ConfigureWMI(){

	this->InitializeCOM();
	if(FAILED(this->HResult)){

		CoUninitialize();
		return FALSE;
	}

	this->SetSecurityLevel();

	this->ObtainWMILocator();
	if(FAILED(this->HResult)){

		CoUninitialize();
		return FALSE;
	}

	this->Connect();
	if(FAILED(this->HResult)){

		CoUninitialize();
		this->PLocator->Release();
		return FALSE;
	}

	this->SetProxySecurityLevels();
	if(FAILED(this->HResult)){

		CoUninitialize();
		this->PServices->Release();
		this->PLocator->Release();
		return FALSE;
	}

	return TRUE;
}

bool CWMIBase::MakeWMIRequest(LPCWSTR wql){

	this->ConfigureWMI();

	if(FAILED(this->HResult))
		return FALSE;
	
	this->PEnumerator = NULL;
    this->HResult = this->PServices->ExecQuery(
        bstr_t("WQL"), 
        bstr_t(wql),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, 
        NULL,
        &this->PEnumerator);
    
    if (FAILED(this->HResult)){
        this->PServices->Release();
        this->PLocator->Release();
        CoUninitialize(); 

		return FALSE;
    }

	return TRUE;
}

char* CWMIBase::GetStringValue(IWbemClassObject* pclsObj, LPCWSTR propertyName){

	VARIANT variantValue;
	
	this->HResult = pclsObj->Get(propertyName, 0, &variantValue, 0, 0);
	
	if(FAILED(this->HResult) || variantValue.vt != VT_BSTR)
	{
		VariantClear(&variantValue);
		return "";
	}

	_bstr_t value = variantValue.bstrVal;

	const size_t length = (value.length()+1)*2;
	char *chPropName = new char[length];
	strcpy_s(chPropName, length, (char *)value);

	VariantClear(&variantValue);

	return chPropName; 
}

unsigned short CWMIBase::GetUShortValue(IWbemClassObject* pclsObj, LPCWSTR propertyName){

	VARIANT variantValue;

	this->HResult = pclsObj->Get(propertyName, 0, &variantValue, 0, 0);
	
	if(FAILED(this->HResult))
	{
		VariantClear(&variantValue);
		return 0;
	}
	
	unsigned short value = variantValue.uiVal;

	VariantClear(&variantValue);

	return value; 
}

unsigned int CWMIBase::GetUIntValue(IWbemClassObject* pclsObj, LPCWSTR propertyName){

	VARIANT variantValue;
	this->HResult = pclsObj->Get(propertyName, 0, &variantValue, 0, 0);

	if(FAILED(this->HResult))
	{
		VariantClear(&variantValue);
		return 0;
	}

	unsigned int value = variantValue.uiVal;

	VariantClear(&variantValue);

	return value; 
}

unsigned int CWMIBase::GetULongValue(IWbemClassObject* pclsObj, LPCWSTR propertyName){

	VARIANT variantValue;
	this->HResult = pclsObj->Get(propertyName, 0, &variantValue, 0, 0);

	if(FAILED(this->HResult))
	{
		VariantClear(&variantValue);
		return 0;
	}

	unsigned long value = variantValue.uiVal;

	VariantClear(&variantValue);

	return value; 
}

BOOL CWMIBase::GetBoolValue(IWbemClassObject* pclsObj, LPCWSTR propertyName){
	
	VARIANT variantValue;
	this->HResult = pclsObj->Get(propertyName, 0, &variantValue, 0, 0);

	if(FAILED(this->HResult))
	{
		VariantClear(&variantValue);
		return 0;
	}

	BOOL value = variantValue.boolVal;

	VariantClear(&variantValue);

	return value; 
}

void CWMIBase::GetCharArrayPointer(IWbemClassObject* pclsObj, LPCWSTR propertyName, char** words)
{
	VARIANT variantValue;

	this->HResult = pclsObj->Get(propertyName, 0, &variantValue, 0, 0);

	if(FAILED(this->HResult))
	{
		VariantClear(&variantValue);
		return;
	}
	
	SAFEARRAY* arr = variantValue.parray;

	void *pVoid = 0;

	SafeArrayLock(arr);

	LONG uBound = -1, lBound = 0;
	SafeArrayGetUBound(arr,1,&uBound);
	SafeArrayGetLBound(arr,1,&lBound);
	int nCount = uBound - lBound + 1;

	BSTR stringValue;	
	for(int i = 0; i<nCount; ++i)
	{	
		stringValue = ((BSTR*)(arr->pvData))[i];
		char* lpszText = _com_util::ConvertBSTRToString(stringValue);
		words[i] = lpszText;
	}

	SafeArrayUnlock(arr);
	VariantClear(&variantValue);
}

double CWMIBase::GetDoubleValue(IWbemClassObject* pclsObj, LPCWSTR propertyName){

	VARIANT variantValue;
	this->HResult = pclsObj->Get(propertyName, 0, &variantValue, 0, 0);

	if(FAILED(this->HResult))
	{
		VariantClear(&variantValue);
		return 0;
	}

	double value = variantValue.dblVal;

	VariantClear(&variantValue);

	return value; 
}

long* CWMIBase::GetLongArray(IWbemClassObject* pclsObj, LPCWSTR propertyName)
{
	VARIANT variantValue;
	this->HResult = pclsObj->Get(propertyName, 0, &variantValue, 0, 0);

	if(FAILED(this->HResult))
	{
		VariantClear(&variantValue);
		return NULL;
	}

	void *pVoid = 0;

	SafeArrayAccessData(variantValue.parray, &pVoid);

	long *pLong = reinterpret_cast<long*>(pVoid);

	VariantClear(&variantValue);

	return pLong;
}

int CWMIBase::GetSafeArrayPropertyLength(IWbemClassObject* pclsObj, LPCWSTR propertyName){

	VARIANT variantValue;

	this->HResult = pclsObj->Get(propertyName, 0, &variantValue, 0, 0);

	if(FAILED(this->HResult))
	{
		VariantClear(&variantValue);
		return 0;
	}
	
	SAFEARRAY* arr = variantValue.parray;

	SafeArrayLock(arr);

	LONG uBound = -1, lBound = 0;
	SafeArrayGetUBound(arr,1,&uBound);
	SafeArrayGetLBound(arr,1,&lBound);

	SafeArrayUnlock(arr);
	VariantClear(&variantValue);
	

	return uBound - lBound + 1;

}