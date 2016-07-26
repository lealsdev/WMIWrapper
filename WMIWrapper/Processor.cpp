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
// Keyboard.cpp - Contains the CProcessor's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "WMIWrapper.h"

#include "GeneralDescriptions.h"

MotherboardControllerPort::CProcessor::CProcessor(){

	return;
}

std::list<MotherboardControllerPort::CProcessorData*> MotherboardControllerPort::CProcessor::GetData(){

	IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;

	std::list<MotherboardControllerPort::CProcessorData*> processors;
	
	MotherboardControllerPort::CProcessorData* processorsData;	

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_Processor"))
		return processors;
	
    while (this->PEnumerator){
	    this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

        if(0 == uReturn)
            break;

		processorsData = new MotherboardControllerPort::CProcessorData;

		processorsData->AddressWidth = this->GetUShortValue(pclsObj, L"AddressWidth");

		processorsData->Architecture = this->GetUShortValue(pclsObj, L"Architecture");
		processorsData->ArchitectureDesc = CGeneralDescriptions::GetArchitectureDescription(processorsData->Architecture);

		processorsData->AssetTag = this->GetStringValue(pclsObj, L"AssetTag");

		processorsData->Availability = this->GetUShortValue(pclsObj, L"Availability");
		processorsData->AvailabilityDesc = CGeneralDescriptions::GetAvailabilityDescription(processorsData->Availability);

		processorsData->Caption = this->GetStringValue(pclsObj, L"Caption");

		processorsData->Characteristics = this->GetUIntValue(pclsObj, L"Characteristics");

		processorsData->ConfigManagerErrorCode = this->GetUIntValue(pclsObj, L"ConfigManagerErrorCode");
		processorsData->ConfigManagerErrorCodeDesc = CGeneralDescriptions::GetConfigManagerErrorCodeDescription(processorsData->ConfigManagerErrorCode);

		processorsData->ConfigManagerUserConfig = this->GetBoolValue(pclsObj, L"ConfigManagerUserConfig");

		processorsData->CpuStatus = this->GetUShortValue(pclsObj, L"CpuStatus");
		processorsData->CpuStatusDesc = CGeneralDescriptions::GetCpuStatusDescription(processorsData->CpuStatus);

		processorsData->CreationClassName = this->GetStringValue(pclsObj, L"CreationClassName");

		processorsData->CurrentClockSpeed = this->GetUIntValue(pclsObj, L"CurrentClockSpeed");

		processorsData->CurrentVoltage = this->GetUShortValue(pclsObj, L"CurrentVoltage");

		processorsData->DataWidth = this->GetUShortValue(pclsObj, L"DataWidth");

		processorsData->Description = this->GetStringValue(pclsObj, L"Description");

		processorsData->DeviceID = this->GetStringValue(pclsObj, L"DeviceID");
		
		processorsData->ErrorCleared = this->GetBoolValue(pclsObj, L"ErrorCleared");

		processorsData->ErrorDescription = this->GetStringValue(pclsObj, L"DeviceID");

		processorsData->ExtClock = this->GetUIntValue(pclsObj, L"ExtClock");

		processorsData->Family = this->GetUShortValue(pclsObj, L"Family");
		processorsData->FamilyDesc = CGeneralDescriptions::GetFamilyDescription(processorsData->Family);

		processorsData->InstallDate = this->GetStringValue(pclsObj, L"InstallDate");

		processorsData->L2CacheSize = this->GetUIntValue(pclsObj, L"L2CacheSize");

		processorsData->L2CacheSpeed = this->GetUIntValue(pclsObj, L"L2CacheSpeed");

		processorsData->L3CacheSize = this->GetUIntValue(pclsObj, L"L3CacheSize");

		processorsData->L3CacheSpeed = this->GetUIntValue(pclsObj, L"L3CacheSpeed");
		
		processorsData->LastErrorCode = this->GetUIntValue(pclsObj, L"LastErrorCode");

		processorsData->Level = this->GetUShortValue(pclsObj, L"Level");

		processorsData->LoadPercentage = this->GetUShortValue(pclsObj, L"LoadPercentage");

		processorsData->Manufacturer = this->GetStringValue(pclsObj, L"Manufacturer");

		processorsData->MaxClockSpeed = this->GetUIntValue(pclsObj, L"MaxClockSpeed");

		processorsData->Name = this->GetStringValue(pclsObj, L"Name");

		processorsData->NumberOfCores = this->GetUIntValue(pclsObj, L"NumberOfCores");

		processorsData->NumberOfEnabledCore = this->GetUIntValue(pclsObj, L"NumberOfEnabledCore");

		processorsData->NumberOfLogicalProcessors = this->GetUIntValue(pclsObj, L"NumberOfLogicalProcessors");

		processorsData->OtherFamilyDescription = this->GetStringValue(pclsObj, L"OtherFamilyDescription");

		processorsData->PartNumber = this->GetStringValue(pclsObj, L"PartNumber");

		processorsData->PNPDeviceID = this->GetStringValue(pclsObj, L"PNPDeviceID");

		processorsData->PowerManagementSupported = this->GetBoolValue(pclsObj, L"PowerManagementSupported");

		processorsData->ProcessorId = this->GetStringValue(pclsObj, L"ProcessorId");

		processorsData->ProcessorType = this->GetUShortValue(pclsObj, L"ProcessorType");
		processorsData->ProcessorTypeDesc = CGeneralDescriptions::GetProcessorTypeDescription(processorsData->ProcessorType);

		processorsData->Revision = this->GetUShortValue(pclsObj, L"Revision");

		processorsData->Role = this->GetStringValue(pclsObj, L"Role");

		processorsData->SecondLevelAddressTranslationExtensions = this->GetBoolValue(pclsObj, L"SecondLevelAddressTranslationExtensions");

		processorsData->SerialNumber = this->GetStringValue(pclsObj, L"SerialNumber");

		processorsData->SocketDesignation = this->GetStringValue(pclsObj, L"SocketDesignation");

		processorsData->Status = this->GetStringValue(pclsObj, L"Status");

		processorsData->StatusInfo = this->GetUShortValue(pclsObj, L"StatusInfo");
		processorsData->StatusInfoDesc = CGeneralDescriptions::GetStatusInfoDescription(processorsData->StatusInfo);

		processorsData->Stepping = this->GetStringValue(pclsObj, L"Stepping");

		processorsData->SystemCreationClassName = this->GetStringValue(pclsObj, L"SystemCreationClassName");

		processorsData->SystemName = this->GetStringValue(pclsObj, L"SystemName");

		processorsData->ThreadCount = this->GetUIntValue(pclsObj, L"ThreadCount");

		processorsData->UniqueId = this->GetStringValue(pclsObj, L"UniqueId");

		processorsData->UpgradeMethod = this->GetUShortValue(pclsObj, L"UpgradeMethod");
        processorsData->UpgradeMethodDesc = CGeneralDescriptions::GetUpgradeMethodDescription(processorsData->UpgradeMethod);

		processorsData->Version = this->GetStringValue(pclsObj, L"Version");

		processorsData->VirtualizationFirmwareEnabled = this->GetBoolValue(pclsObj, L"VirtualizationFirmwareEnabled");

		processorsData->VMMonitorModeExtensions = this->GetBoolValue(pclsObj, L"VMMonitorModeExtensions");

		processorsData->VoltageCaps = this->GetUIntValue(pclsObj, L"VoltageCaps");
		processorsData->VoltageCapsDesc = CGeneralDescriptions::GetVoltageCapsDescription(processorsData->VoltageCaps);

		processors.push_back(processorsData);
    }

	pclsObj->Release();	

	return processors;
}