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
// Keyboard.cpp - Contains the CKeyboard's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "WMIWrapper.h"

#include "GeneralDescriptions.h"

InputDevices::CKeyboard::CKeyboard(){

	return;
}

std::list<InputDevices::KeyboardData*> InputDevices::CKeyboard::GetData(){

	IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;

	std::list<InputDevices::KeyboardData*> keyboards;
	
	InputDevices::KeyboardData* keyboardData;	

	if(!this->MakeWMIRequest(L"SELECT * FROM Win32_Keyboard"))
		return keyboards;
	
    while (this->PEnumerator){
	    this->PEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

        if(0 == uReturn)
            break;

		keyboardData = new InputDevices::KeyboardData;

		keyboardData->Availability = this->GetUShortValue(pclsObj, L"Availability");
		keyboardData->AvailabilityDesc = CGeneralDescriptions::GetAvailabilityDescription(keyboardData->Availability);

		keyboardData->Caption = this->GetStringValue(pclsObj, L"Caption");
		
		keyboardData->ConfigManagerErrorCode = this->GetUIntValue(pclsObj, L"ConfigManagerErrorCode");
		keyboardData->ConfigManagerErrorCodeDesc = CGeneralDescriptions::GetConfigManagerErrorCodeDescription(keyboardData->ConfigManagerErrorCode);

		keyboardData->ConfigManagerUserConfig = this->GetBoolValue(pclsObj, L"ConfigManagerUserConfig");

		keyboardData->CreationClassName = this->GetStringValue(pclsObj, L"CreationClassName");

		keyboardData->Description = this->GetStringValue(pclsObj, L"Description");

		keyboardData->DeviceID = this->GetStringValue(pclsObj, L"DeviceID");

		keyboardData->ErrorCleared = this->GetBoolValue(pclsObj, L"ErrorCleared");

		keyboardData->ErrorDescription = this->GetStringValue(pclsObj, L"DeviceID");

		keyboardData->InstallDate = this->GetStringValue(pclsObj, L"InstallDate");

		keyboardData->IsLocked = this->GetBoolValue(pclsObj, L"IsLocked");

		keyboardData->LastErrorCode = this->GetUIntValue(pclsObj, L"LastErrorCode");

		keyboardData->Layout = this->GetStringValue(pclsObj, L"Layout");

		keyboardData->Name = this->GetStringValue(pclsObj, L"Name");

		keyboardData->NumberOfFunctionKeys = this->GetUShortValue(pclsObj, L"NumberOfFunctionKeys");

		keyboardData->Password = this->GetUShortValue(pclsObj, L"Password");
		keyboardData->PasswordDesc = CGeneralDescriptions::GetPasswordDescription(keyboardData->Password);

		keyboardData->PNPDeviceID = this->GetStringValue(pclsObj, L"PNPDeviceID");

		keyboardData->PowerManagementSupported = this->GetBoolValue(pclsObj, L"PowerManagementSupported");

		keyboardData->Status = this->GetStringValue(pclsObj, L"Status");

		keyboardData->StatusInfo = this->GetUShortValue(pclsObj, L"StatusInfo");
		keyboardData->StatusInfoDesc = CGeneralDescriptions::GetStatusInfoDescription(keyboardData->StatusInfo);

		keyboardData->SystemCreationClassName = this->GetStringValue(pclsObj, L"SystemCreationClassName");

		keyboardData->SystemName = this->GetStringValue(pclsObj, L"SystemName");

		keyboards.push_back(keyboardData);

		pclsObj->Release();
    }

	return keyboards;
}