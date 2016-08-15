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
// GeneralDescriptions.h - Contains all methods that receives a value and return description of something.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

class CGeneralDescriptions{
public:
	//**************************************************
	// Returns the architecture description.
	//**************************************************
	static char* GetArchitectureDescription(unsigned short architecture);

	//**************************************************
	// Returns the availability description.
	//**************************************************
	static char* GetAvailabilityDescription(unsigned short availability);

	//**************************************************
	// Returns the config manager error code description.
	//**************************************************
	static char* GetConfigManagerErrorCodeDescription(unsigned short configManagerErrorCode);

	//**************************************************
	// Returns the CPU status description.
	//**************************************************
	static char* GetCpuStatusDescription(unsigned short cpuStatus);

	//**************************************************
	// Returns the processor's family description.
	//**************************************************
	static char* GetFamilyDescription(unsigned short family);

	//**************************************************
	// Returns the processor's type description.
	//**************************************************
	static char* GetProcessorTypeDescription(unsigned short family);

	//**************************************************
	// Returns the status info description.
	//**************************************************
	static char* GetStatusInfoDescription(unsigned short statusInfo);

	//**************************************************
	// Returns the upgrade method description.
	//**************************************************
	static char* GetUpgradeMethodDescription(unsigned short upgradeMethod);

	//**************************************************
	// Returns the voltage caps description.
	//**************************************************
	static char* GetVoltageCapsDescription(unsigned short statusInfo);

	//**************************************************
	// Returns the password description.
	//**************************************************
	static char* GetPasswordDescription(unsigned short password);

	//**************************************************
	// Returns the device interface description.
	//**************************************************
	static char* GetDeviceInterfaceDescription(unsigned short deviceInterface);

	//**************************************************
	// Returns the handedness description.
	//**************************************************
	static char* GetHandednessDescription(unsigned short handedness);

	//**************************************************
	// Returns the poiting type description.
	//**************************************************
	static char* GetPointingTypeDescription(unsigned short handedness);

	//**************************************************
	// Returns the poiting type description.
	//**************************************************
	static char* GetDisplayTypeDescription(unsigned short displayType);

	//**************************************************
	// Returns the network connection status description.
	//**************************************************
	static char* GetNetConnectionStatusDescription(unsigned short netConnectionStatus);

	//**************************************************
	// Returns the file system flags ex description.
	//**************************************************
	static char* GetFileSystemFlagsExDescription(unsigned int fileSystemFlagsEx);
};