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
// DisplayControllerConfiguration.cpp - Contains the CDisplayControllerConfiguration's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------


#include "stdafx.h"

#include "WMIWrapper.h"

#include "GeneralDescriptions.h"

VideoMonitor::CDisplayControllerConfiguration::CDisplayControllerConfiguration(){

	return;
}

std::list<VideoMonitor::DisplayControllerConfigurationData*> VideoMonitor::CDisplayControllerConfiguration::GetData(){

	IWbemClassObject *pclsObj = NULL;
	ULONG uReturn = 0;

	std::list<VideoMonitor::DisplayControllerConfigurationData*> displayControllerConfiguration;

	VideoMonitor::DisplayControllerConfigurationData* displayControllerConfigurationData;

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_DisplayControllerConfiguration"))
		return displayControllerConfiguration;

	while(this->PEnumerator){
		this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

		if(0 == uReturn)
            break;

		displayControllerConfigurationData = new VideoMonitor::DisplayControllerConfigurationData;

		displayControllerConfigurationData->BitsPerPixel = this->GetUIntValue(pclsObj, L"BitsPerPixel");

		displayControllerConfigurationData->Caption = this->GetStringValue(pclsObj, L"Caption");
		
		displayControllerConfigurationData->ColorPlanes = this->GetUIntValue(pclsObj, L"ColorPlanes");

		displayControllerConfigurationData->Description = this->GetStringValue(pclsObj, L"Description");

		displayControllerConfigurationData->DeviceEntriesInAColorTable = this->GetUIntValue(pclsObj, L"DeviceEntriesInAColorTable");

		displayControllerConfigurationData->DeviceSpecificPens = this->GetUIntValue(pclsObj, L"DeviceSpecificPens");

		displayControllerConfigurationData->HorizontalResolution = this->GetUIntValue(pclsObj, L"HorizontalResolution");

		displayControllerConfigurationData->Name = this->GetStringValue(pclsObj, L"Name");

		displayControllerConfigurationData->RefreshRate = this->GetUIntValue(pclsObj, L"RefreshRate");

		displayControllerConfigurationData->ReservedSystemPaletteEntries = this->GetUIntValue(pclsObj, L"ReservedSystemPaletteEntries");

		displayControllerConfigurationData->SettingID = this->GetStringValue(pclsObj, L"SettingID");
		
		displayControllerConfigurationData->SystemPaletteEntries = this->GetUIntValue(pclsObj, L"SystemPaletteEntries");

		displayControllerConfigurationData->VerticalResolution = this->GetUIntValue(pclsObj, L"VerticalResolution");

		displayControllerConfigurationData->VideoMode = this->GetStringValue(pclsObj, L"VideoMode");


		displayControllerConfiguration.push_back(displayControllerConfigurationData);

		pclsObj->Release();
	}

	return displayControllerConfiguration;
}