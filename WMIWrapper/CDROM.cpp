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
// CDROM.cpp - Contains the CCDROMDrive's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "WMIWrapper.h"

#include "GeneralDescriptions.h"

MassStorage::CCDROMDrive::CCDROMDrive(){
	return;
}

std::list<MassStorage::CDROMDriveData*> MassStorage::CCDROMDrive::GetData(){

	IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;

	std::list<MassStorage::CDROMDriveData*> cdromDrives;
	
	MassStorage::CDROMDriveData* cdromDriveData;	

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_CDROMDrive"))
		return cdromDrives;
	
    while (this->PEnumerator){
	    this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

        if(0 == uReturn)
            break;

		cdromDriveData = new MassStorage::CDROMDriveData;

		cdromDriveData->Availability = this->GetUShortValue(pclsObj, L"Availability");
		cdromDriveData->AvailabilityDesc = CGeneralDescriptions::GetAvailabilityDescription(cdromDriveData->Availability);

		cdromDriveData->Capabilities = this->GetLongArray(pclsObj, L"Capabilities");
		cdromDriveData->CapabilitiesLen = this->GetSafeArrayPropertyLength(pclsObj, L"Capabilities");

		cdromDriveData->CapabilityDescriptions = new char*;
		this->GetCharArrayPointer(pclsObj, L"CapabilityDescriptions", cdromDriveData->CapabilityDescriptions);
		
		cdromDriveData->Caption = this->GetStringValue(pclsObj, L"Caption");

		cdromDriveData->CompressionMethod = this->GetStringValue(pclsObj, L"CompressionMethod");

		cdromDriveData->ConfigManagerErrorCode = this->GetUIntValue(pclsObj, L"ConfigManagerErrorCode");
		cdromDriveData->ConfigManagerErrorCodeDesc = CGeneralDescriptions::GetConfigManagerErrorCodeDescription(cdromDriveData->ConfigManagerErrorCode);

		cdromDriveData->ConfigManagerUserConfig = this->GetBoolValue(pclsObj, L"ConfigManagerUserConfig");

		cdromDriveData->CreationClassName = this->GetStringValue(pclsObj, L"CreationClassName");

		cdromDriveData->DefaultBlockSize = this->GetULongValue(pclsObj, L"DefaultBlockSize");

		cdromDriveData->Description = this->GetStringValue(pclsObj, L"Description");

		cdromDriveData->DeviceID = this->GetStringValue(pclsObj, L"DeviceID");

		cdromDriveData->Drive = this->GetStringValue(pclsObj, L"Drive");

		cdromDriveData->DriveIntegrity = this->GetBoolValue(pclsObj, L"DriveIntegrity");
		
		cdromDriveData->ErrorCleared = this->GetBoolValue(pclsObj, L"ErrorCleared");

		cdromDriveData->ErrorDescription = this->GetStringValue(pclsObj, L"DeviceID");

		cdromDriveData->ErrorMethodology = this->GetStringValue(pclsObj, L"ErrorMethodology");

		cdromDriveData->FileSystemFlagsEx = this->GetUIntValue(pclsObj, L"FileSystemFlagsEx");
		cdromDriveData->FileSystemFlagsExDesc = CGeneralDescriptions::GetFileSystemFlagsExDescription(cdromDriveData->FileSystemFlagsEx);

		cdromDriveData->Id = this->GetStringValue(pclsObj, L"Id");

		cdromDriveData->InstallDate = this->GetStringValue(pclsObj, L"InstallDate");
		
		cdromDriveData->LastErrorCode = this->GetUIntValue(pclsObj, L"LastErrorCode");

		cdromDriveData->Manufacturer = this->GetStringValue(pclsObj, L"Manufacturer");

		cdromDriveData->MaxBlockSize = this->GetULongValue(pclsObj, L"MaxBlockSize");

		cdromDriveData->MaximumComponentLength = this->GetUIntValue(pclsObj, L"MaximumComponentLength");
		
		cdromDriveData->MaxMediaSize = this->GetULongValue(pclsObj, L"MaxMediaSize");

		cdromDriveData->MediaLoaded = this->GetBoolValue(pclsObj, L"MediaLoaded");

		cdromDriveData->MediaType = this->GetStringValue(pclsObj, L"MediaType");

		cdromDriveData->MfrAssignedRevisionLevel = this->GetStringValue(pclsObj, L"MfrAssignedRevisionLevel");

		cdromDriveData->MinBlockSize = this->GetULongValue(pclsObj, L"MinBlockSize");

		cdromDriveData->Name = this->GetStringValue(pclsObj, L"Name");

		cdromDriveData->NeedsCleaning = this->GetBoolValue(pclsObj, L"NeedsCleaning");

		cdromDriveData->NumberOfMediaSupported = this->GetUIntValue(pclsObj, L"NumberOfMediaSupported");

		cdromDriveData->PNPDeviceID = this->GetStringValue(pclsObj, L"PNPDeviceID");

		cdromDriveData->PowerManagementSupported = this->GetBoolValue(pclsObj, L"PowerManagementSupported");

		cdromDriveData->RevisionLevel = this->GetStringValue(pclsObj, L"RevisionLevel");

		cdromDriveData->SCSIBus = this->GetUIntValue(pclsObj, L"SCSIBus");

		cdromDriveData->SCSILogicalUnit = this->GetUShortValue(pclsObj, L"SCSILogicalUnit");

		cdromDriveData->SCSIPort = this->GetUShortValue(pclsObj, L"SCSIPort");

		cdromDriveData->SCSITargetId = this->GetUShortValue(pclsObj, L"SCSITargetId");

		cdromDriveData->SerialNumber = this->GetStringValue(pclsObj, L"SerialNumber");

		cdromDriveData->Size = this->GetULongValue(pclsObj, L"Size");		

		cdromDriveData->Status = this->GetStringValue(pclsObj, L"Status");

		cdromDriveData->StatusInfo = this->GetUShortValue(pclsObj, L"StatusInfo");
		cdromDriveData->StatusInfoDesc = CGeneralDescriptions::GetStatusInfoDescription(cdromDriveData->StatusInfo);

		cdromDriveData->SystemCreationClassName = this->GetStringValue(pclsObj, L"SystemCreationClassName");

		cdromDriveData->SystemName = this->GetStringValue(pclsObj, L"SystemName");

		cdromDriveData->TransferRate = this->GetUIntValue(pclsObj, L"TransferRate");

		cdromDriveData->VolumeName = this->GetStringValue(pclsObj, L"VolumeName");

		cdromDriveData->VolumeSerialNumber = this->GetStringValue(pclsObj, L"VolumeSerialNumber");

		cdromDrives.push_back(cdromDriveData);
    }

	pclsObj->Release();	

	return cdromDrives;
}