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
// PointingDevice.cpp - Contains the CPointingDevice's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "WMIWrapper.h"

#include "GeneralDescriptions.h"

InputDevices::CPointingDevice::CPointingDevice(){

	return;
}

std::list<InputDevices::PointingDeviceData*> InputDevices::CPointingDevice::GetData(){

	IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;

	std::list<InputDevices::PointingDeviceData*> pointingDevices;
	
	InputDevices::PointingDeviceData* pointingDeviceData;	

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_PointingDevice"))
		return pointingDevices;
	
    while (this->PEnumerator){
	    this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

        if(0 == uReturn)
            break;

		pointingDeviceData = new InputDevices::PointingDeviceData;

		pointingDeviceData->Availability = this->GetUShortValue(pclsObj, L"Availability");
		pointingDeviceData->AvailabilityDesc = CGeneralDescriptions::GetAvailabilityDescription(pointingDeviceData->Availability);

		pointingDeviceData->Caption = this->GetStringValue(pclsObj, L"Caption");
		
		pointingDeviceData->ConfigManagerErrorCode = this->GetUIntValue(pclsObj, L"ConfigManagerErrorCode");
		pointingDeviceData->ConfigManagerErrorCodeDesc = CGeneralDescriptions::GetConfigManagerErrorCodeDescription(pointingDeviceData->ConfigManagerErrorCode);

		pointingDeviceData->ConfigManagerUserConfig = this->GetBoolValue(pclsObj, L"ConfigManagerUserConfig");

		pointingDeviceData->CreationClassName = this->GetStringValue(pclsObj, L"CreationClassName");

		pointingDeviceData->Description = this->GetStringValue(pclsObj, L"Description");

		pointingDeviceData->DeviceID = this->GetStringValue(pclsObj, L"DeviceID");

		pointingDeviceData->DeviceInterface = this->GetUShortValue(pclsObj, L"DeviceInterface");
		pointingDeviceData->DeviceInterfaceDesc = CGeneralDescriptions::GetDeviceInterfaceDescription(pointingDeviceData->DeviceInterface);

		pointingDeviceData->DoubleSpeedThreshold = this->GetUIntValue(pclsObj, L"DoubleSpeedThreshold");

		pointingDeviceData->ErrorCleared = this->GetBoolValue(pclsObj, L"ErrorCleared");

		pointingDeviceData->ErrorDescription = this->GetStringValue(pclsObj, L"DeviceID");

		pointingDeviceData->Handedness = this->GetUShortValue(pclsObj, L"Handedness");
		pointingDeviceData->HandednessDesc = CGeneralDescriptions::GetHandednessDescription(pointingDeviceData->Handedness);		
		
		pointingDeviceData->HardwareType = this->GetStringValue(pclsObj, L"HardwareType");
		
		pointingDeviceData->InfFileName = this->GetStringValue(pclsObj, L"InfFileName");
		
		pointingDeviceData->InfSection = this->GetStringValue(pclsObj, L"InfSection");

		pointingDeviceData->InstallDate = this->GetStringValue(pclsObj, L"InstallDate");

		pointingDeviceData->IsLocked = this->GetBoolValue(pclsObj, L"IsLocked");

		pointingDeviceData->LastErrorCode = this->GetUIntValue(pclsObj, L"LastErrorCode");

		pointingDeviceData->Manufacturer = this->GetStringValue(pclsObj, L"Manufacturer");

		pointingDeviceData->Name = this->GetStringValue(pclsObj, L"Name");

		pointingDeviceData->NumberOfButtons = this->GetUShortValue(pclsObj, L"NumberOfButtons");

		pointingDeviceData->PNPDeviceID = this->GetStringValue(pclsObj, L"PNPDeviceID");

		pointingDeviceData->PointingType = this->GetUShortValue(pclsObj, L"PointingType");
		pointingDeviceData->PointingTypeDesc = CGeneralDescriptions::GetPointingTypeDescription(pointingDeviceData->PointingType);

		pointingDeviceData->PowerManagementSupported = this->GetBoolValue(pclsObj, L"PowerManagementSupported");

		pointingDeviceData->QuadSpeedThreshold = this->GetUIntValue(pclsObj, L"QuadSpeedThreshold");

		pointingDeviceData->Resolution = this->GetUIntValue(pclsObj, L"Resolution");

		pointingDeviceData->SampleRate = this->GetUIntValue(pclsObj, L"SampleRate");

		pointingDeviceData->Status = this->GetStringValue(pclsObj, L"Status");

		pointingDeviceData->StatusInfo = this->GetUShortValue(pclsObj, L"StatusInfo");
		pointingDeviceData->StatusInfoDesc = CGeneralDescriptions::GetStatusInfoDescription(pointingDeviceData->StatusInfo);

		pointingDeviceData->Synch = this->GetUIntValue(pclsObj, L"Synch");

		pointingDeviceData->SystemCreationClassName = this->GetStringValue(pclsObj, L"SystemCreationClassName");

		pointingDeviceData->SystemName = this->GetStringValue(pclsObj, L"SystemName");

		pointingDevices.push_back(pointingDeviceData);

		pclsObj->Release();
    }

	return pointingDevices;
}


