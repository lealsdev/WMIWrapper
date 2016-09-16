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
// NetworkAdapter.cpp - Contains the CNetworkAdapter's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "WMIWrapper.h"

#include "GeneralDescriptions.h"

NetworkingDevice::CNetworkAdapter::CNetworkAdapter(){

	return;

}

std::list<NetworkingDevice::NetworkAdapterData*> NetworkingDevice::CNetworkAdapter::GetData(){

	IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;

	std::list<NetworkingDevice::NetworkAdapterData*> networkAdapters;

	NetworkingDevice::NetworkAdapterData* networkAdapterData;

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_NetworkAdapter"))
		return networkAdapters;

	while (this->PEnumerator){
	    this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

        if(0 == uReturn)
            break;

		networkAdapterData = new NetworkingDevice::NetworkAdapterData;

		this->GetStringValue(pclsObj, L"NetworkAdresses");

		networkAdapterData->AdapterType = this->GetStringValue(pclsObj, L"AdapterType");

		networkAdapterData->AdapterTypeID = this->GetUShortValue(pclsObj, L"AdapterTypeID");

		networkAdapterData->AutoSense = this->GetBoolValue(pclsObj, L"AutoSense");

		networkAdapterData->Availability = this->GetUShortValue(pclsObj, L"Availability");
		networkAdapterData->AvailabilityDesc = CGeneralDescriptions::GetAvailabilityDescription(networkAdapterData->Availability);

		networkAdapterData->Caption = this->GetStringValue(pclsObj, L"Caption");

		networkAdapterData->ConfigManagerErrorCode = this->GetUIntValue(pclsObj, L"ConfigManagerErrorCode");
		networkAdapterData->ConfigManagerErrorCodeDesc = CGeneralDescriptions::GetConfigManagerErrorCodeDescription(networkAdapterData->ConfigManagerErrorCode);

		networkAdapterData->ConfigManagerUserConfig = this->GetBoolValue(pclsObj, L"ConfigManagerUserConfig");

		networkAdapterData->CreationClassName = this->GetStringValue(pclsObj, L"CreationClassName");

		networkAdapterData->Description = this->GetStringValue(pclsObj, L"Description");

		networkAdapterData->DeviceID = this->GetStringValue(pclsObj, L"DeviceID");
		
		networkAdapterData->ErrorCleared = this->GetBoolValue(pclsObj, L"ErrorCleared");

		networkAdapterData->ErrorDescription = this->GetStringValue(pclsObj, L"DeviceID");

		networkAdapterData->GUID = this->GetStringValue(pclsObj, L"GUID");

		networkAdapterData->Index = this->GetUIntValue(pclsObj, L"Index");

		networkAdapterData->InstallDate = this->GetStringValue(pclsObj, L"InstallDate");

		networkAdapterData->Installed = this->GetBoolValue(pclsObj, L"Installed");

		networkAdapterData->InterfaceIndex = this->GetUIntValue(pclsObj, L"InterfaceIndex");
		
		networkAdapterData->LastErrorCode = this->GetUIntValue(pclsObj, L"LastErrorCode");

		networkAdapterData->MACAddress = this->GetStringValue(pclsObj, L"MACAddress");

		networkAdapterData->Manufacturer = this->GetStringValue(pclsObj, L"Manufacturer");

		networkAdapterData->MaxNumberControlled = this->GetUIntValue(pclsObj, L"MaxNumberControlled");

		networkAdapterData->MaxSpeed = this->GetUIntValue(pclsObj, L"MaxSpeed");

		networkAdapterData->Name = this->GetStringValue(pclsObj, L"Name");

		networkAdapterData->NetConnectionID = this->GetStringValue(pclsObj, L"NetConnectionID");

		networkAdapterData->NetConnectionStatus = this->GetUShortValue(pclsObj, L"NetConnectionStatus");
		networkAdapterData->NetConnectionStatusDesc = CGeneralDescriptions::GetNetConnectionStatusDescription(networkAdapterData->NetConnectionStatus);

		networkAdapterData->NetEnabled = this->GetBoolValue(pclsObj, L"NetEnabled");

		networkAdapterData->PermanentAddress = this->GetStringValue(pclsObj, L"PermanentAddress");

		networkAdapterData->PNPDeviceID = this->GetStringValue(pclsObj, L"PNPDeviceID");

		networkAdapterData->PowerManagementSupported = this->GetBoolValue(pclsObj, L"PowerManagementSupported");

		networkAdapterData->ProductName = this->GetStringValue(pclsObj, L"ProductName");

		networkAdapterData->ServiceName = this->GetStringValue(pclsObj, L"ServiceName");

		networkAdapterData->Speed = this->GetULongValue(pclsObj, L"Speed");

		networkAdapterData->Status = this->GetStringValue(pclsObj, L"Status");

		networkAdapterData->StatusInfo = this->GetUShortValue(pclsObj, L"StatusInfo");
		networkAdapterData->StatusInfoDesc = CGeneralDescriptions::GetStatusInfoDescription(networkAdapterData->StatusInfo);
		
		networkAdapterData->SystemCreationClassName = this->GetStringValue(pclsObj, L"SystemCreationClassName");

		networkAdapterData->SystemName = this->GetStringValue(pclsObj, L"SystemName");

		networkAdapterData->TimeOfLastReset = this->GetStringValue(pclsObj, L"TimeOfLastReset");
		
		networkAdapters.push_back(networkAdapterData);

		pclsObj->Release();
	}

	return networkAdapters;
}