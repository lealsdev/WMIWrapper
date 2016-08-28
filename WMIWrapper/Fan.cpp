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
// Fan.cpp - Contains the CFan's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "WMIWrapper.h"

#include "GeneralDescriptions.h"

CoolingDevice::CFan::CFan(){

	return;

}

std::list<CoolingDevice::FanData*> CoolingDevice::CFan::GetData(){

	IWbemClassObject *pclsObj = NULL;
	ULONG uReturn = 0;

	std::list<CoolingDevice::FanData*> fanlst;

	CoolingDevice::FanData* fanData;

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_Fan"))
		return fanlst;

	while (this->PEnumerator){
		this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

		if(0 == uReturn)
            break;

		fanData = new CoolingDevice::FanData;

		fanData->ActiveCooling = this->GetBoolValue(pclsObj, L"ActiveCooling");
		
		fanData->Availability = this->GetUShortValue(pclsObj, L"Availability");
		fanData->AvailabilityDesc = CGeneralDescriptions::GetAvailabilityDescription(fanData->Availability);
		
		fanData->Caption = this->GetStringValue(pclsObj, L"Caption");

		fanData->ConfigManagerErrorCode = this->GetUIntValue(pclsObj, L"ConfigManagerErrorCode");
		fanData->ConfigManagerErrorCodeDesc = CGeneralDescriptions::GetConfigManagerErrorCodeDescription(fanData->ConfigManagerErrorCode);

		fanData->ConfigManagerUserConfig = this->GetBoolValue(pclsObj, L"ConfigManagerUserConfig");

		fanData->CreationClassName = this->GetStringValue(pclsObj, L"CreationClassName");

		fanData->Description = this->GetStringValue(pclsObj, L"Description");

		fanData->DesiredSpeed = this->GetULongValue(pclsObj, L"DesiredSpeed");

		fanData->DeviceID = this->GetStringValue(pclsObj, L"DeviceID");

		fanData->ErrorCleared = this->GetBoolValue(pclsObj, L"ErrorCleared");

		fanData->ErrorDescription = this->GetStringValue(pclsObj, L"ErrorDescription");

		fanData->InstallDate = this->GetStringValue(pclsObj, L"InstallDate");

		fanData->LastErrorCode = this->GetUIntValue(pclsObj, L"LastErrorCode");

		fanData->Name = this->GetStringValue(pclsObj, L"Name");

		fanData->PNPDeviceID = this->GetStringValue(pclsObj, L"PNPDeviceID");

		fanData->PowerManagementSupported = this->GetBoolValue(pclsObj, L"PowerManagementSupported");

		fanData->Status = this->GetStringValue(pclsObj, L"Status");

		fanData->StatusInfo = this->GetUShortValue(pclsObj, L"StatusInfo");

		fanData->SystemCreationClassName = this->GetStringValue(pclsObj, L"SystemCreationClassName");

		fanData->SystemName = this->GetStringValue(pclsObj, L"SystemName");

		fanData->VariableSpeed = this->GetBoolValue(pclsObj, L"VariableSpeed");

		fanlst.push_back(fanData);

		pclsObj->Release();
	}

	return fanlst;
}