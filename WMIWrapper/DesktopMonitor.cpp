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
// Keyboard.cpp - Contains the CDesktopMonitor's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "WMIWrapper.h"

#include "GeneralDescriptions.h"

VideoMonitor::CDesktopMonitor::CDesktopMonitor(){

	return;
}

std::list<VideoMonitor::DesktopMonitorData*> VideoMonitor::CDesktopMonitor::GetData(){

	IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;

	std::list<VideoMonitor::DesktopMonitorData*> desktopMonitors;
	
	VideoMonitor::DesktopMonitorData* desktopMonitorsData;	

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_DesktopMonitor"))
		return desktopMonitors;
	
    while (this->PEnumerator){
	    this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

        if(0 == uReturn)
            break;

		desktopMonitorsData = new VideoMonitor::DesktopMonitorData;

		desktopMonitorsData->Availability = this->GetUShortValue(pclsObj, L"Availability");
		desktopMonitorsData->AvailabilityDesc = CGeneralDescriptions::GetAvailabilityDescription(desktopMonitorsData->Availability);

		desktopMonitorsData->Bandwidth = this->GetUIntValue(pclsObj, L"Bandwidth");

		desktopMonitorsData->Caption = this->GetStringValue(pclsObj, L"Caption");

		desktopMonitorsData->ConfigManagerErrorCode = this->GetUIntValue(pclsObj, L"ConfigManagerErrorCode");
		desktopMonitorsData->ConfigManagerErrorCodeDesc = CGeneralDescriptions::GetConfigManagerErrorCodeDescription(desktopMonitorsData->ConfigManagerErrorCode);

		desktopMonitorsData->ConfigManagerUserConfig = this->GetBoolValue(pclsObj, L"ConfigManagerUserConfig");

		desktopMonitorsData->CreationClassName = this->GetStringValue(pclsObj, L"CreationClassName");
		
		desktopMonitorsData->Description = this->GetStringValue(pclsObj, L"Description");

		desktopMonitorsData->DeviceID = this->GetStringValue(pclsObj, L"DeviceID");
		
		desktopMonitorsData->DisplayType = this->GetUShortValue(pclsObj, L"DisplayType");
		desktopMonitorsData->DisplayTypeDesc = CGeneralDescriptions::GetDisplayTypeDescription(desktopMonitorsData->DisplayType);

		desktopMonitorsData->ErrorCleared = this->GetBoolValue(pclsObj, L"ErrorCleared");

		desktopMonitorsData->ErrorDescription = this->GetStringValue(pclsObj, L"ErrorDescription");

		desktopMonitorsData->InstallDate = this->GetStringValue(pclsObj, L"InstallDate");
		
		desktopMonitorsData->IsLocked = this->GetBoolValue(pclsObj, L"IsLocked");

		desktopMonitorsData->LastErrorCode = this->GetUIntValue(pclsObj, L"LastErrorCode");

		desktopMonitorsData->MonitorManufacturer = this->GetStringValue(pclsObj, L"MonitorManufacturer");

		desktopMonitorsData->MonitorType = this->GetStringValue(pclsObj, L"MonitorType");

		desktopMonitorsData->Name = this->GetStringValue(pclsObj, L"Name");

		desktopMonitorsData->PixelsPerXLogicalInch = this->GetUIntValue(pclsObj, L"PixelsPerXLogicalInch");

		desktopMonitorsData->PixelsPerYLogicalInch = this->GetUIntValue(pclsObj, L"PixelsPerYLogicalInch");

		desktopMonitorsData->PNPDeviceID = this->GetStringValue(pclsObj, L"PNPDeviceID");

		desktopMonitorsData->PowerManagementSupported = this->GetBoolValue(pclsObj, L"PowerManagementSupported");

		desktopMonitorsData->ScreenWidth = this->GetUIntValue(pclsObj, L"ScreenWidth");

		desktopMonitorsData->ScreenHeight = this->GetUIntValue(pclsObj, L"ScreenHeight");

		desktopMonitorsData->Status = this->GetStringValue(pclsObj, L"Status");

		desktopMonitorsData->StatusInfo = this->GetUShortValue(pclsObj, L"StatusInfo");
		desktopMonitorsData->StatusInfoDesc = CGeneralDescriptions::GetStatusInfoDescription(desktopMonitorsData->StatusInfo);

		desktopMonitorsData->SystemCreationClassName = this->GetStringValue(pclsObj, L"SystemCreationClassName");

		desktopMonitorsData->SystemName = this->GetStringValue(pclsObj, L"SystemName");

		
		desktopMonitors.push_back(desktopMonitorsData);

		pclsObj->Release();
    }

	return desktopMonitors;
}

