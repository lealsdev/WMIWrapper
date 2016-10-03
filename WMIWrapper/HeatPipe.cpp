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
// Fan.cpp - Contains the CHeatPipe's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "WMIWrapper.h"

#include "GeneralDescriptions.h"


CoolingDevice::CHeatPipe::CHeatPipe(){

	return;

}

std::list<CoolingDevice::HeatPipeData*> CoolingDevice::CHeatPipe::GetData(){

	IWbemClassObject *pclsObj = NULL;
	ULONG uReturn = 0;

	std::list<CoolingDevice::HeatPipeData*> heatPipelst;

	CoolingDevice::HeatPipeData* heatPipeData;

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_HeatPipe"))
		return heatPipelst;

	while (this->PEnumerator){
		this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

		if(0 == uReturn)
            break;

		heatPipeData = new CoolingDevice::HeatPipeData;

		heatPipeData->ActiveCooling = this->GetBoolValue(pclsObj, L"ActiveCooling");
		
		heatPipeData->Availability = this->GetUShortValue(pclsObj, L"Availability");
		heatPipeData->AvailabilityDesc = CGeneralDescriptions::GetAvailabilityDescription(heatPipeData->Availability);
		
		heatPipeData->Caption = this->GetStringValue(pclsObj, L"Caption");

		heatPipeData->ConfigManagerErrorCode = this->GetUIntValue(pclsObj, L"ConfigManagerErrorCode");
		heatPipeData->ConfigManagerErrorCodeDesc = CGeneralDescriptions::GetConfigManagerErrorCodeDescription(heatPipeData->ConfigManagerErrorCode);

		heatPipeData->ConfigManagerUserConfig = this->GetBoolValue(pclsObj, L"ConfigManagerUserConfig");

		heatPipeData->CreationClassName = this->GetStringValue(pclsObj, L"CreationClassName");

		heatPipeData->Description = this->GetStringValue(pclsObj, L"Description");

		heatPipeData->DeviceID = this->GetStringValue(pclsObj, L"DeviceID");

		heatPipeData->ErrorCleared = this->GetBoolValue(pclsObj, L"ErrorCleared");

		heatPipeData->ErrorDescription = this->GetStringValue(pclsObj, L"ErrorDescription");

		heatPipeData->InstallDate = this->GetStringValue(pclsObj, L"InstallDate");

		heatPipeData->LastErrorCode = this->GetUIntValue(pclsObj, L"LastErrorCode");

		heatPipeData->Name = this->GetStringValue(pclsObj, L"Name");

		heatPipeData->PNPDeviceID = this->GetStringValue(pclsObj, L"PNPDeviceID");

		heatPipeData->PowerManagementSupported = this->GetBoolValue(pclsObj, L"PowerManagementSupported");

		heatPipeData->Status = this->GetStringValue(pclsObj, L"Status");

		heatPipeData->StatusInfo = this->GetUShortValue(pclsObj, L"StatusInfo");

		heatPipeData->SystemCreationClassName = this->GetStringValue(pclsObj, L"SystemCreationClassName");

		heatPipeData->SystemName = this->GetStringValue(pclsObj, L"SystemName");

		heatPipelst.push_back(heatPipeData);

		pclsObj->Release();


	}

	return heatPipelst;

}