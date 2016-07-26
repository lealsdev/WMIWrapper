// WMITest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

//#include "Keyboard.h"

#include "WMIWrapper.h"

using namespace std;

void WriteKeyboardData()
{
	InputDevices::CKeyboard keyboard;
	list<InputDevices::CKeyboardData*> data = keyboard.GetData();

	list<InputDevices::CKeyboardData*>::iterator iterator;

	for(iterator = data.begin(); iterator != data.end(); ++iterator)
	{
		cout << "Availability: " << (*iterator)->Availability << std::endl;
		cout << "AvailabilityDesc: " << (*iterator)->AvailabilityDesc << std::endl;
		cout << "Caption: " << (*iterator)->Caption << std::endl;
		cout << "ConfigManagerErrorCode: " << (*iterator)->ConfigManagerErrorCode << std::endl;
		cout << "ConfigManagerErrorCodeDesc: " << (*iterator)->ConfigManagerErrorCodeDesc << std::endl;
		cout << "ConfigManagerUserConfig: " << (*iterator)->ConfigManagerUserConfig << std::endl;
		cout << "CreationClassName: " << (*iterator)->CreationClassName << std::endl;
		cout << "Description: " << (*iterator)->Description << std::endl;
		cout << "DeviceID: " << (*iterator)->DeviceID << std::endl;
		cout << "ErrorCleared: " << (*iterator)->ErrorCleared << std::endl;
		cout << "ErrorDescription: " << (*iterator)->ErrorDescription << std::endl;
		cout << "InstallDate: " << (*iterator)->InstallDate << std::endl;
		cout << "IsLocked: " << (*iterator)->IsLocked << std::endl;
		cout << "LastErrorCode: " << (*iterator)->LastErrorCode << std::endl;
		cout << "Layout: " << (*iterator)->Layout << std::endl;
		cout << "Name: " << (*iterator)->Name << std::endl;
		cout << "NumberOfFunctionKeys: " << (*iterator)->NumberOfFunctionKeys << std::endl;
		cout << "Password: " << (*iterator)->Password << std::endl;
		cout << "PasswordDesc: " << (*iterator)->PasswordDesc << std::endl;
		cout << "PNPDeviceID: " << (*iterator)->PNPDeviceID << std::endl;
		cout << "PowerManagementSupported: " << (*iterator)->PowerManagementSupported << std::endl;
		cout << "Status: " << (*iterator)->Status << std::endl;
		cout << "StatusInfo: " << (*iterator)->StatusInfo << std::endl;
		cout << "StatusInfoDesc: " << (*iterator)->StatusInfoDesc << std::endl;
		cout << "SystemCreationClassName: " << (*iterator)->SystemCreationClassName << std::endl;
		cout << "SystemName: " << (*iterator)->SystemName << std::endl;

	}
}

void WritePointingDeviceData()
{
	InputDevices::CPointingDevice* pointingDevice = new InputDevices::CPointingDevice;
	list<InputDevices::CPointingDeviceData*> data = pointingDevice->GetData();

	list<InputDevices::CPointingDeviceData*>::iterator iterator;

	for(iterator = data.begin(); iterator != data.end(); ++iterator)
	{
		cout << "Availability: " << (*iterator)->Availability << endl;
		cout << "AvailabilityDesc: " << (*iterator)->AvailabilityDesc << endl;
		cout << "Caption: " << (*iterator)->Caption << endl;
		cout << "ConfigManagerErrorCode: " << (*iterator)->ConfigManagerErrorCode << endl;
		cout << "ConfigManagerErrorCodeDesc: " << (*iterator)->ConfigManagerErrorCodeDesc << endl;
		cout << "ConfigManagerUserConfig: " << (*iterator)->ConfigManagerUserConfig << endl;
		cout << "CreationClassName: " << (*iterator)->CreationClassName << endl;
		cout << "Description: " << (*iterator)->Description << endl;
		cout << "DeviceID: " << (*iterator)->DeviceID << endl;
		cout << "DeviceInterface: " << (*iterator)->DeviceInterface << endl;
		cout << "DeviceInterfaceDesc: " << (*iterator)->DeviceInterfaceDesc << endl;
		cout << "DoubleSpeedThreshold: " << (*iterator)->DoubleSpeedThreshold << endl;
		cout << "ErrorCleared: " << (*iterator)->ErrorCleared << endl;
		cout << "ErrorDescription: " << (*iterator)->ErrorDescription << endl;
		cout << "Handedness: " << (*iterator)->Handedness << endl;
		cout << "HandednessDesc: " << (*iterator)->HandednessDesc << endl;
		cout << "HardwareType: " << (*iterator)->HardwareType << endl;
		cout << "InfFileName: " << (*iterator)->InfFileName << endl;
		cout << "InfSection: " << (*iterator)->InfSection << endl;
		cout << "InstallDate: " << (*iterator)->InstallDate << endl;
		cout << "IsLocked: " << (*iterator)->IsLocked << endl;
		cout << "LastErrorCode: " << (*iterator)->LastErrorCode << endl;
		cout << "Manufacturer: " << (*iterator)->Manufacturer << endl;
		cout << "Name: " << (*iterator)->Name << endl;
		cout << "NumberOfButtons: " << (*iterator)->NumberOfButtons << endl;			
		cout << "PNPDeviceID: " << (*iterator)->PNPDeviceID << endl;
		cout << "PointingType: " << (*iterator)->PointingType << endl;
		cout << "PointingTypeDesc: " << (*iterator)->PointingTypeDesc << endl;
		cout << "PowerManagementSupported: " << (*iterator)->PowerManagementSupported << endl;
		cout << "QuadSpeedThreshold: " << (*iterator)->QuadSpeedThreshold << endl;
		cout << "Resolution: " << (*iterator)->Resolution << endl;
		cout << "SampleRate: " << (*iterator)->SampleRate << endl;
		cout << "Status: " << (*iterator)->Status << endl;
		cout << "StatusInfo: " << (*iterator)->StatusInfo << endl;
		cout << "StatusInfoDesc: " << (*iterator)->StatusInfoDesc << endl;
		cout << "Synch: " << (*iterator)->Synch << endl;
		cout << "SystemCreationClassName: " <<(*iterator)->SystemCreationClassName << endl;
		cout << "SystemName: " << (*iterator)->SystemName << endl;
	}

	delete pointingDevice;

}

void WriteProcessorData()
{
	MotherboardControllerPort::CProcessor processor;
	list<MotherboardControllerPort::CProcessorData*> data = processor.GetData();

	list<MotherboardControllerPort::CProcessorData*>::iterator iterator;

	for(iterator = data.begin(); iterator != data.end(); ++iterator)
	{
		cout << "AddressWidth: "							<<	(*iterator)->AddressWidth								<< endl;
		cout << "Architecture: "							<<	(*iterator)->Architecture								<< endl;
		cout << "ArchitectureDesc: "						<<	(*iterator)->ArchitectureDesc							<< endl;
		cout << "AssetTag: "								<<	(*iterator)->AssetTag									<< endl;
		cout << "Availability: "							<<	(*iterator)->Availability								<< endl;
		cout << "AvailabilityDesc: "						<<	(*iterator)->AvailabilityDesc							<< endl;
		cout << "Caption: "									<<	(*iterator)->Caption									<< endl;
		cout << "Characteristics: "							<<	(*iterator)->Characteristics							<< endl;
		cout << "ConfigManagerErrorCode: "					<<	(*iterator)->ConfigManagerErrorCode						<< endl;
		cout << "ConfigManagerErrorCodeDesc: "				<<	(*iterator)->ConfigManagerErrorCodeDesc					<< endl;
		cout << "ConfigManagerUserConfig: "					<<	(*iterator)->ConfigManagerUserConfig					<< endl;
		cout << "CpuStatus: "								<<	(*iterator)->CpuStatus									<< endl;
		cout << "CpuStatusDesc: "							<<	(*iterator)->CpuStatusDesc								<< endl;
		cout << "CreationClassName: "						<<	(*iterator)->CreationClassName							<< endl;
		cout << "CurrentClockSpeed: "						<<	(*iterator)->CurrentClockSpeed							<< endl;
		cout << "CurrentVoltage: "							<<	(*iterator)->CurrentVoltage								<< endl;
		cout << "DataWidth: "								<<	(*iterator)->DataWidth									<< endl;
		cout << "Description: "								<<	(*iterator)->Description								<< endl;
		cout << "DeviceID: "								<<	(*iterator)->DeviceID									<< endl;
		cout << "ErrorCleared: "							<<	(*iterator)->ErrorCleared								<< endl;
		cout << "ErrorDescription: "						<<	(*iterator)->ErrorDescription							<< endl;
		cout << "ExtClock: "								<<	(*iterator)->ExtClock									<< endl;
		cout << "Family: "									<<	(*iterator)->Family										<< endl;
		cout << "FamilyDesc: "								<<	(*iterator)->FamilyDesc									<< endl;
		cout << "InstallDate: "								<<	(*iterator)->InstallDate								<< endl;
		cout << "L2CacheSize: "								<<	(*iterator)->L2CacheSize								<< endl;
		cout << "L2CacheSpeed: "							<<	(*iterator)->L2CacheSpeed								<< endl;
		cout << "L3CacheSize: "								<<	(*iterator)->L3CacheSize								<< endl;
		cout << "L3CacheSpeed: "							<<	(*iterator)->L3CacheSpeed								<< endl;
		cout << "LastErrorCode: "							<<	(*iterator)->LastErrorCode								<< endl;
		cout << "Level: "									<<	(*iterator)->Level										<< endl;
		cout << "LoadPercentage: "							<<	(*iterator)->LoadPercentage								<< endl;
		cout << "Manufacturer: "							<<	(*iterator)->Manufacturer								<< endl;
		cout << "MaxClockSpeed: "							<<	(*iterator)->MaxClockSpeed								<< endl;
		cout << "Name: "									<<	(*iterator)->Name										<< endl;
		cout << "NumberOfCores: "							<<	(*iterator)->NumberOfCores								<< endl;
		cout << "NumberOfEnabledCore: "						<<	(*iterator)->NumberOfEnabledCore						<< endl;
		cout << "NumberOfLogicalProcessors: "				<<	(*iterator)->NumberOfLogicalProcessors					<< endl;
		cout << "OtherFamilyDescription: "					<<	(*iterator)->OtherFamilyDescription						<< endl;
		cout << "PartNumber: "								<<	(*iterator)->PartNumber									<< endl;
		cout << "PNPDeviceID: "								<<	(*iterator)->PNPDeviceID								<< endl;
		cout << "PowerManagementSupported: "				<<	(*iterator)->PowerManagementSupported					<< endl;
		cout << "ProcessorId: "								<<	(*iterator)->ProcessorId								<< endl;
		cout << "ProcessorType: "							<<	(*iterator)->ProcessorType								<< endl;
		cout << "ProcessorTypeDesc: "						<<	(*iterator)->ProcessorTypeDesc							<< endl;
		cout << "Revision: "								<<	(*iterator)->Revision									<< endl;
		cout << "Role: "									<<	(*iterator)->Role										<< endl;
		cout << "SecondLevelAddressTranslationExtensions: "	<<	(*iterator)->SecondLevelAddressTranslationExtensions	<< endl;
		cout << "SerialNumber: "							<<	(*iterator)->SerialNumber								<< endl;
		cout << "SocketDesignation: "						<<	(*iterator)->SocketDesignation							<< endl;
		cout << "Status: "									<<	(*iterator)->Status										<< endl;
		cout << "StatusInfo: "								<<	(*iterator)->StatusInfo									<< endl;
		cout << "StatusInfoDesc: "							<<	(*iterator)->StatusInfoDesc								<< endl;
		cout << "Stepping: "								<<	(*iterator)->Stepping									<< endl;
		cout << "SystemCreationClassName: "					<<	(*iterator)->SystemCreationClassName					<< endl;
		cout << "SystemName: "								<<	(*iterator)->SystemName									<< endl;
		cout << "ThreadCount: "								<<	(*iterator)->ThreadCount								<< endl;
		cout << "UniqueId: "								<<	(*iterator)->UniqueId									<< endl;
		cout << "UpgradeMethod: "							<<	(*iterator)->UpgradeMethod								<< endl;
		cout << "UpgradeMethodDesc: "						<<	(*iterator)->UpgradeMethodDesc							<< endl;
		cout << "Version: "									<<	(*iterator)->Version									<< endl;
		cout << "VirtualizationFirmwareEnabled: "			<<	(*iterator)->VirtualizationFirmwareEnabled				<< endl;
		cout << "VMMonitorModeExtensions: "					<<	(*iterator)->VMMonitorModeExtensions					<< endl;
		cout << "VoltageCaps: "								<<	(*iterator)->VoltageCaps								<< endl;
		cout << "VoltageCapsDesc: "							<<	(*iterator)->VoltageCapsDesc							<< endl;
	}
}

void WriteDesktopMonitor()
{
	VideoMonitor::CDesktopMonitor monitor;

	list<VideoMonitor::CDesktopMonitorData*> data = monitor.GetData();

	list<VideoMonitor::CDesktopMonitorData*>::iterator iterator;

	for(iterator = data.begin(); iterator != data.end(); ++iterator)
	{
		cout << "Availability: "				<<	(*iterator)->Availability								<< endl;
		cout << "AvailabilityDesc: "			<<	(*iterator)->AvailabilityDesc							<< endl;
		cout << "Bandwidth: "					<<	(*iterator)->Bandwidth								<< endl;
		cout << "Caption: "						<<	(*iterator)->Caption									<< endl;
		cout << "ConfigManagerErrorCode: "		<<	(*iterator)->ConfigManagerErrorCode					<< endl;
		cout << "ConfigManagerErrorCodeDesc: "	<<	(*iterator)->ConfigManagerErrorCodeDesc				<< endl;
		cout << "ConfigManagerUserConfig: "		<<	(*iterator)->ConfigManagerUserConfig					<< endl;
		cout << "CreationClassName: "			<<	(*iterator)->CreationClassName						<< endl;
		cout << "Description: "					<<	(*iterator)->Description								<< endl;
		cout << "DeviceID: "					<<	(*iterator)->DeviceID									<< endl;
		cout << "DisplayType: "					<<	(*iterator)->DisplayType								<< endl;
		cout << "DisplayTypeDesc: "				<<	(*iterator)->DisplayTypeDesc							<< endl;
		cout << "ErrorCleared: "				<<	(*iterator)->ErrorCleared								<< endl;
		cout << "ErrorDescription: "			<<	(*iterator)->ErrorDescription							<< endl;
		cout << "InstallDate: "					<<	(*iterator)->InstallDate								<< endl;
		cout << "IsLocked: "					<<	(*iterator)->IsLocked									<< endl;
		cout << "LastErrorCode: "				<<	(*iterator)->LastErrorCode							<< endl;
		cout << "MonitorManufacturer: "			<<	(*iterator)->MonitorManufacturer						<< endl;
		cout << "MonitorType: "					<<	(*iterator)->MonitorType								<< endl;
		cout << "Name: "						<<	(*iterator)->Name										<< endl;
		cout << "PixelsPerXLogicalInch: "		<<	(*iterator)->PixelsPerXLogicalInch					<< endl;
		cout << "PixelsPerYLogicalInch: "		<<	(*iterator)->PixelsPerYLogicalInch					<< endl;
		cout << "PNPDeviceID: "					<<	(*iterator)->PNPDeviceID								<< endl;
		cout << "PowerManagementSupported: "	<<	(*iterator)->PowerManagementSupported					<< endl;
		cout << "ScreenHeight: "				<<	(*iterator)->ScreenHeight								<< endl;
		cout << "ScreenWidth: "					<<	(*iterator)->ScreenWidth								<< endl;
		cout << "Status: "						<<	(*iterator)->Status									<< endl;
		cout << "StatusInfo: "					<<	(*iterator)->StatusInfo								<< endl;
		cout << "StatusInfoDesc: "				<<	(*iterator)->StatusInfoDesc							<< endl;
		cout << "SystemCreationClassName: "		<<	(*iterator)->SystemCreationClassName					<< endl;
		cout << "SystemName: "					<<	(*iterator)->SystemName								<< endl;
		
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	cout << "#########################################" << endl;
	cout << "KeyBoard data" << endl;
	cout << "#########################################" << endl;
	WriteKeyboardData();
	cout << endl << endl << endl;

	cout << "#########################################" << endl;
	cout << "Pointing device data" << endl;
	cout << "#########################################" << endl;
	WritePointingDeviceData();
	cout << endl << endl << endl;

	cout << "#########################################" << endl;
	cout << "Processor data" << endl;
	cout << "#########################################" << endl;
	WriteProcessorData();
	cout << endl << endl << endl;

	cout << "#########################################" << endl;
	cout << "Desktop monitor data" << endl;
	cout << "#########################################" << endl;
	WriteDesktopMonitor();
	cout << endl << endl << endl;

	int i = 0;
	std::cin >> i;

	return 0;
}

