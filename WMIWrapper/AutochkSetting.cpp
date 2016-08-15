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
// AutochkSetting.cpp - Contains the CAutochkSetting's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "WMIWrapper.h"

MassStorage::CAutochkSetting::CAutochkSetting(){
	return;
}

std::list<MassStorage::AutochkSettingData*> MassStorage::CAutochkSetting::GetData(){

	IWbemClassObject *pclsObj = NULL;
	ULONG uReturn = 0;

	std::list<MassStorage::AutochkSettingData*> autochkSettings;

	MassStorage::AutochkSettingData* autochkSettingData;

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_AutochkSetting"))
		return autochkSettings;

	while (this->PEnumerator){
		this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

		if(0 == uReturn)
            break;

		autochkSettingData = new MassStorage::AutochkSettingData;

		autochkSettingData->Caption = this->GetStringValue(pclsObj, L"Caption");
		autochkSettingData->Description = this->GetStringValue(pclsObj, L"Description");
		autochkSettingData->SettingID = this->GetStringValue(pclsObj, L"SettingID");
		autochkSettingData->UserInputDelay = this->GetUIntValue(pclsObj, L"UserInputDelay");

		autochkSettings.push_back(autochkSettingData);
	}

	pclsObj->Release();

	return autochkSettings;
}