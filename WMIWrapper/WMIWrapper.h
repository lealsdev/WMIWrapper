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
// WMIWrapper.h - Contains the WMI classes definitions.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "WMIBase.h"
#include <list>


namespace InputDevices{

	//**************************************************
	// This struct contains all Keyboard values.
	//**************************************************
	struct WMIWRAPPER_API CKeyboardData{
	public:
		unsigned short	Availability;
		char*			AvailabilityDesc;
		char*			Caption;
		unsigned int	ConfigManagerErrorCode;
		char*			ConfigManagerErrorCodeDesc;
		BOOL			ConfigManagerUserConfig;
		char*			CreationClassName;
		char*			Description;
		char*			DeviceID;
		BOOL			ErrorCleared;
		char*			ErrorDescription;
		char*			InstallDate;
		BOOL			IsLocked;
		unsigned int	LastErrorCode;
		char*			Layout;
		char*			Name;
		unsigned short	NumberOfFunctionKeys;
		unsigned short	Password;
		char*			PasswordDesc;
		char*			PNPDeviceID;
		BOOL			PowerManagementSupported;
		char*			Status;
		unsigned short	StatusInfo;
		char*			StatusInfoDesc;
		char*			SystemCreationClassName;
		char*			SystemName;
	};

	//**************************************************
	// This class contains all necessary methods to get
	// WMI's keyboard's data.
	//**************************************************
	class WMIWRAPPER_API CKeyboard : CWMIBase {
	public:
		//**************************************************
		// Constructor.
		//**************************************************
		CKeyboard(void);	

		//**************************************************
		// Populates a list of keyboard structures and 
		// returns that list.
		//**************************************************
		std::list<InputDevices::CKeyboardData*> GetData();
	};

	//**************************************************
	// This struct contains all pointing device values.
	//**************************************************
	struct WMIWRAPPER_API CPointingDeviceData{
		
		unsigned short	Availability;
		char*			AvailabilityDesc;
		char*			Caption;
		unsigned int	ConfigManagerErrorCode;
		char*			ConfigManagerErrorCodeDesc;
		BOOL			ConfigManagerUserConfig;
		char*			CreationClassName;
		char*			Description;
		char*			DeviceID;
		unsigned short	DeviceInterface;
		char*			DeviceInterfaceDesc;
		unsigned int	DoubleSpeedThreshold;
		BOOL			ErrorCleared;
		char*			ErrorDescription;
		unsigned short	Handedness;
		char*			HandednessDesc;
		char*			HardwareType;
		char*			InfFileName;
		char*			InfSection;
		char*			InstallDate;
		BOOL			IsLocked;
		unsigned int	LastErrorCode;
		char*			Manufacturer;
		char*			Name;
		unsigned short	NumberOfButtons;			
		char*			PNPDeviceID;
		unsigned short	PointingType;
		char*			PointingTypeDesc;
		BOOL			PowerManagementSupported;
		unsigned int	QuadSpeedThreshold;
		unsigned int	Resolution;
		unsigned int	SampleRate;
		char*			Status;
		unsigned short	StatusInfo;
		char*			StatusInfoDesc;
		unsigned int	Synch;
		char*			SystemCreationClassName;
		char*			SystemName;

	};

	//**************************************************
	// This class contains all necessary methods to get
	// WMI's PointingDevice's data.
	//**************************************************
	class WMIWRAPPER_API CPointingDevice : CWMIBase {
	public:
		//**************************************************
		// Constructor.
		//**************************************************
		CPointingDevice(void);	

		//**************************************************
		// Populates a list of Pointing Device structures and 
		// returns that list.
		//**************************************************
		std::list<InputDevices::CPointingDeviceData*> GetData();

	};
}

namespace MotherboardControllerPort{

	//**************************************************
	// This struct contains all processor values.
	//**************************************************
	struct WMIWRAPPER_API CProcessorData{

		unsigned short	AddressWidth;
		unsigned short	Architecture;
		char*			ArchitectureDesc;
		char*			AssetTag;
		unsigned short	Availability;
		char*			AvailabilityDesc;
		char*			Caption;
		unsigned int	Characteristics;
		unsigned int	ConfigManagerErrorCode;
		char*			ConfigManagerErrorCodeDesc;
		BOOL			ConfigManagerUserConfig;
		unsigned short  CpuStatus;
		char*			CpuStatusDesc;
		char*			CreationClassName;
		unsigned int	CurrentClockSpeed;
		unsigned short  CurrentVoltage;
		unsigned short  DataWidth;
		char*			Description;
		char*			DeviceID;
		BOOL			ErrorCleared;
		char*			ErrorDescription;
		unsigned int	ExtClock;
		unsigned short  Family;
		char*			FamilyDesc;
		char*			InstallDate;
		unsigned int	L2CacheSize;
		unsigned int	L2CacheSpeed;
		unsigned int	L3CacheSize;
		unsigned int	L3CacheSpeed;
		unsigned int	LastErrorCode;
		unsigned short  Level;
		unsigned short  LoadPercentage;
		char*			Manufacturer;
		unsigned int	MaxClockSpeed;
		char*			Name;
		unsigned int	NumberOfCores;
		unsigned int	NumberOfEnabledCore;
		unsigned int	NumberOfLogicalProcessors;
		char*			OtherFamilyDescription;
		char*			PartNumber;
		char*			PNPDeviceID;
		BOOL			PowerManagementSupported;
		char*			ProcessorId;
		unsigned short  ProcessorType;
		char*			ProcessorTypeDesc;
		unsigned short  Revision;
		char*			Role;
		BOOL			SecondLevelAddressTranslationExtensions;
		char*			SerialNumber;
		char*			SocketDesignation;
		char*			Status;
		unsigned short  StatusInfo;
		char*			StatusInfoDesc;
		char*			Stepping;
		char*			SystemCreationClassName;
		char*			SystemName;
		unsigned int	ThreadCount;
		char*			UniqueId;
		unsigned short  UpgradeMethod;
		char*			UpgradeMethodDesc;
		char*			Version;
		BOOL			VirtualizationFirmwareEnabled;
		BOOL			VMMonitorModeExtensions;
		unsigned int	VoltageCaps;
		char*			VoltageCapsDesc;

	};

	//**************************************************
	// This class contains all necessary methods to get
	// WMI's Processor's data.
	//**************************************************
	class WMIWRAPPER_API CProcessor : CWMIBase {
	public:
		//**************************************************
		// Constructor.
		//**************************************************
		CProcessor(void);

		//**************************************************
		// Populates a list of Processor structures and 
		// returns that list.
		//**************************************************
		std::list<MotherboardControllerPort::CProcessorData*> GetData();
		
	};
}

namespace VideoMonitor{

	//**************************************************
	// This struct contains all desktop monitor values.
	//**************************************************
	struct WMIWRAPPER_API CDesktopMonitorData{
	
		unsigned short	Availability;
		char*			AvailabilityDesc;
		unsigned int	Bandwidth;
		char*			Caption;
		unsigned int	ConfigManagerErrorCode;
		char*			ConfigManagerErrorCodeDesc;
		BOOL			ConfigManagerUserConfig;
		char*			CreationClassName;
		char*			Description;
		char*			DeviceID;
		unsigned short  DisplayType;
		char*			DisplayTypeDesc;
		BOOL			ErrorCleared;
		char*			ErrorDescription;
		char*			InstallDate;
		BOOL			IsLocked;
		unsigned int	LastErrorCode;
		char*			MonitorManufacturer;
		char*			MonitorType;
		char*			Name;
		unsigned int	PixelsPerXLogicalInch;
		unsigned int	PixelsPerYLogicalInch;
		char*			PNPDeviceID;
		BOOL			PowerManagementSupported;
		unsigned int	ScreenHeight;
		unsigned int	ScreenWidth;
		char*			Status;
		unsigned short  StatusInfo;
		char*			StatusInfoDesc;
		char*			SystemCreationClassName;
		char*			SystemName;

	};

	//**************************************************
	// This class contains all necessary methods to get
	// WMI's Desktop Monitor's data.
	//**************************************************
	class WMIWRAPPER_API CDesktopMonitor : CWMIBase {
	public:
		//**************************************************
		// Constructor.
		//**************************************************
		CDesktopMonitor(void);

		//**************************************************
		// Populates a list of Desktop monitor structures 
		// and returns that list.
		//**************************************************
		std::list<VideoMonitor::CDesktopMonitorData*> GetData();		
	};

}

namespace NetworkingDevice{

	struct WMIWRAPPER_API CNetworkAdapterData{
	
		char*			AdapterType;
		unsigned short	AdapterTypeID;
		BOOL			AutoSense;
		unsigned short  Availability;
		char*			AvailabilityDesc;
		char*			Caption;
		unsigned int	ConfigManagerErrorCode;
		char*			ConfigManagerErrorCodeDesc;
		BOOL			ConfigManagerUserConfig;
		char*			CreationClassName;
		char*			Description;
		char*			DeviceID;
		BOOL			ErrorCleared;
		char*			ErrorDescription;
		char*			GUID;
		unsigned int	Index;
		char*			InstallDate;
		BOOL			Installed;
		unsigned int	InterfaceIndex;
		unsigned int	LastErrorCode;
		char*			MACAddress;
		char*			Manufacturer;
		unsigned int	MaxNumberControlled;
		unsigned long	MaxSpeed;
		char*			Name;
		char*			NetConnectionID;
		unsigned short  NetConnectionStatus;
		char*			NetConnectionStatusDesc;
		BOOL			NetEnabled;
		char*			PermanentAddress;
		BOOL			PhysicalAdapter;
		char*			PNPDeviceID;
		BOOL			PowerManagementSupported;
		char*			ProductName;
		char*			ServiceName;
		unsigned long   Speed;
		char*			Status;
		unsigned short  StatusInfo;
		char*			StatusInfoDesc;
		char*			SystemCreationClassName;
		char*			SystemName;
		char*			TimeOfLastReset;

	};

	//**************************************************
	// This class contains all necessary methods to get
	// WMI's Network adapter's data.
	//**************************************************
	class WMIWRAPPER_API CNetworkAdapter : CWMIBase {
	public:
		//**************************************************
		// Constructor.
		//**************************************************
		CNetworkAdapter(void);

		//**************************************************
		// Populates a list of Desktop monitor structures 
		// and returns that list.
		//**************************************************
		std::list<CNetworkAdapterData*> GetData();		
	};

}