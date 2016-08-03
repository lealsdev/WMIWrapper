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
// GeneralDescriptions.cpp - Contains the CGeneralDescription's implementation.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------

#include "stdafx.h"

#include "GeneralDescriptions.h"

char* CGeneralDescriptions::GetArchitectureDescription(unsigned short architecture){

	switch(architecture){
		case 0:
			return "x86";
		case 1:
			return "MIPS";
		case 2:
			return "Alpha";
		case 3:
			return "PowerPC";
		case 5:
			return "ARM";
		case 6:
			return "ia64";
		case 9:
			return "x64";		
		default:
			return "";
	}
}

char* CGeneralDescriptions::GetAvailabilityDescription(unsigned short availability){

	switch(availability){
		case 1:
			return "Other";
		case 2:
			return "Unknown ";
		case 3:
			return "Running/Full Power";
		case 4:
			return "Warning";
		case 5:
			return "In Test";
		case 6:
			return "Not Applicable";
		case 7:
			return "Power Off";
		case 8:
			return "Off Line";
		case 9:
			return "Off Duty";
		case 10:
			return "Degraded";
		case 11:
			return "Not Installed";
		case 12:
			return "Install Error";
		case 13:
			return "Power Save - Unknown";
		case 14:
			return "Power Save - Low Power Mode";
		case 15:
			return "Power Save - Standby";
		case 16:
			return "Power Cycle";
		case 17:
			return "Power Save - Warning";
		case 18:
			return "Paused";
		case 19:
			return "Not Ready";
		case 20:
			return "Not Configured";
		case 21:
			return "Quiesced";
		default:
			return "";
	}
}

char* CGeneralDescriptions::GetConfigManagerErrorCodeDescription(unsigned short configManagerErrorCode){

	switch(configManagerErrorCode)
	{
	case 0:
		return "This device is working properly";
	case 1:
		return "This device is not configured correctly";
	case 2:
		return "Windows cannot load the driver for this device";
	case 3:
		return "The driver for this device might be corrupted, or your system may be running low on memory or other resources";
	case 4:
		return "This device is not working properly. One of its drivers or your registry might be corrupted";
	case 5:
		return "The driver for this device needs a resource that Windows cannot manage";
	case 6:
		return "The boot configuration for this device conflicts with other devices";
	case 7:
		return "Cannot filter";
	case 8:
		return "The driver loader for the device is missing";
	case 9:
		return "This device is not working properly because the controlling firmware is reporting the resources for the device incorrectly";
	case 10:
		return "This device cannot start";
	case 11:
		return "This device failed";
	case 12:
		return "This device cannot find enough free resources that it can use";
	case 13:
		return "Windows cannot verify this device's resources";
	case 14:
		return "This device cannot work properly until you restart your computer";
	case 15:
		return "This device is not working properly because there is probably a re-enumeration problem";
	case 16:
		return "Windows cannot identify all the resources this device uses";
	case 17:
		return "This device is asking for an unknown resource type";
	case 18:
		return "Reinstall the drivers for this device";
	case 19:
		return "Failure using the VxD loader";
	case 20:
		return "Your registry might be corrupted";
	case 21:
		return "System failure: Try changing the driver for this device. If that does not work, see your hardware documentation. Windows is removing this device";
	case 22:
		return "This device is disabled";
	case 23:
		return "System failure: Try changing the driver for this device. If that doesn't work, see your hardware documentation";
	case 24:
		return "This device is not present, is not working properly, or does not have all its drivers installed";
	case 25:
	case 26:
		return "Windows is still setting up this device";
	case 27:
		return "This device does not have valid log configuration";
	case 28:
		return "The drivers for this device are not installed";
	case 29:
		return "This device is disabled because the firmware of the device did not give it the required resources";
	case 30:
		return "This device is using an Interrupt Request (IRQ) resource that another device is using";
	case 31:
		return "This device is not working properly because Windows cannot load the drivers required for this device";
	default:
		return "";
	}

}

char* CGeneralDescriptions::GetCpuStatusDescription(unsigned short cpuStatus){

	switch(cpuStatus){
		case 0:
			return "Unknown";
		case 1:
			return "CPU Enabled";
		case 2:
			return "CPU Disabled by User via BIOS Setup";
		case 3:
			return "CPU Disabled By BIOS (POST Error)";
		case 4:
			return "CPU is Idle";
		case 5:
			return "Reserved";
		case 6:
			return "Reserved";
		case 7:
			return "Other";
		default:
			return "";
	}
}

char* CGeneralDescriptions::GetFamilyDescription(unsigned short family){

	switch(family){
		case 1:
			return "Other";
		case 2:
			return "Unknown";
		case 3:
			return "8086";
		case 4:
			return "80286";
		case 5:
			return "80386";
		case 6:
			return "80486";
		case 7:
			return "8087";
		case 8:
			return "80287";
		case 9:
			return "80387";
		case 10:
			return "80487";
		case 11:
			return "Pentium(R) brand";
		case 12:
			return "Pentium(R) Pro";
		case 13:
			return "Pentium(R) II";
		case 14:
			return "Pentium(R) processor with MMX(TM) technology";
		case 15:
			return "Celeron(TM)";
		case 16:
			return "Pentium(R) II Xeon(TM)";
		case 17:
			return "Pentium(R) III";
		case 18:
			return "M1 Family";
		case 19:
			return "M2 Family";
		case 24:
			return "K5 Family";
		case 25:
			return "K6 Family";
		case 26:
			return "K6-2";
		case 27:
			return "K6-3";
		case 28:
			return "AMD Athlon(TM) Processor Family";
		case 29:
			return "AMD(R) Duron(TM) Processor";
		case 30:
			return "AMD29000 Family";
		case 31:
			return "K6-2+";
		case 32:
			return "Power PC Family";
		case 33:
			return "Power PC 601";
		case 34:
			return "Power PC 603";
		case 35:
			return "Power PC 603+";
		case 36:
			return "Power PC 604";
		case 37:
			return "Power PC 620";
		case 38:
			return "Power PC X704";
		case 39:
			return "Power PC 750";
		case 48:
			return "Alpha Family";
		case 49:
			return "Alpha 21064";
		case 50:
			return "Alpha 21066";
		case 51:
			return "Alpha 21164";
		case 52:
			return "Alpha 21164PC";
		case 53:
			return "Alpha 21164a";
		case 54:
			return "Alpha 21264";
		case 55:
			return "Alpha 21364";
		case 64:
			return "MIPS Family";
		case 65:
			return "MIPS R4000";
		case 66:
			return "MIPS R4200";
		case 67:
			return "MIPS R4400";
		case 68:
			return "MIPS R4600";
		case 69:
			return "MIPS R10000";
		case 80:
			return "SPARC Family";
		case 81:
			return "SuperSPARC";
		case 82:
			return "microSPARC II";
		case 83:
			return "microSPARC IIep";
		case 84:
			return "UltraSPARC";
		case 85:
			return "UltraSPARC II";
		case 86:
			return "UltraSPARC IIi";
		case 87:
			return "UltraSPARC III";
		case 88:
			return "UltraSPARC IIIi";
		case 96:
			return "68040";
		case 97:
			return "68xxx Family";
		case 98:
			return "68000";
		case 99:
			return "68010";
		case 100:
			return "68020";
		case 101:
			return "68030";
		case 112:
			return "Hobbit Family";
		case 120:
			return "Crusoe(TM) TM5000 Family";
		case 121:
			return "Crusoe(TM) TM3000 Family";
		case 122:
			return "Efficeon(TM) TM8000 Family";
		case 128:
			return "Weitek";
		case 130:
			return "Itanium(TM) Processor";
		case 131:
			return "AMD Athlon(TM) 64 Processor Family";
		case 132:
			return "AMD Opteron(TM) Family";
		case 144:
			return "PA-RISC Family";
		case 145:
			return "PA-RISC 8500";
		case 146:
			return "PA-RISC 8000";
		case 147:
			return "PA-RISC 7300LC";
		case 148:
			return "PA-RISC 7200";
		case 149:
			return "PA-RISC 7100LC";
		case 150:
			return "PA-RISC 7100";
		case 160:
			return "V30 Family";
		case 176:
			return "Pentium(R) III Xeon(TM)";
		case 177:
			return "Pentium(R) III Processor with Intel(R) SpeedStep(TM) Technology";
		case 178:
			return "Pentium(R) 4";
		case 179:
			return "Intel(R) Xeon(TM)";
		case 180:
			return "AS400 Family";
		case 181:
			return "Intel(R) Xeon(TM) processor MP";
		case 182:
			return "AMD AthlonXP(TM) Family";
		case 183:
			return "AMD AthlonMP(TM) Family";
		case 184:
			return "Intel(R) Itanium(R) 2";
		case 185:
			return "Intel Pentium M Processor";
		case 190:
			return "K7";
		case 198:
			return "Intel Core™ i7-2760QM";
		case 200:
			return "IBM390 Family";
		case 201:
			return "G4";
		case 202:
			return "G5";
		case 203:
			return "G6";
		case 204:
			return "z/Architecture base";
		case 250:
			return "i860";
		case 251:
			return "i960";
		case 260:
			return "SH-3";
		case 261:
			return "SH-4";
		case 280:
			return "ARM";
		case 281:
			return "StrongARM";
		case 300:
			return "6x86";
		case 301:
			return "MediaGX";
		case 302:
			return "MII";
		case 320:
			return "WinChip";
		case 350:
			return "DSP";
		case 500:
			return "Video Processor";
		default:
			return "";
	}
}

char* CGeneralDescriptions::GetProcessorTypeDescription(unsigned short family){

	switch(family){
		case 1:
			return "Other";
		case 2:
			return "Unknown";
		case 3:
			return "Central Processor";
		case 4:
			return "Math Processor";
		case 5:
			return "DSP Processor";
		case 6:
			return "Video Processor";
		default:
			return "";
	}
}

char* CGeneralDescriptions::GetStatusInfoDescription(unsigned short statusInfo){

	switch(statusInfo)
	{
	case 1:
		return "Other";
	case 2:
		return "Unknown";
	case 3:
		return "Enabled";
	case 4:
		return "Disabled";
	case 5:
		return "Not Applicable";
	default:
		return "";
	}

}

char* CGeneralDescriptions::GetUpgradeMethodDescription(unsigned short upgradeMethod){

	switch(upgradeMethod)
	{
	case 1:
		return "Other";
	case 2:
		return "Unknown";
	case 3:
		return "Daughter Board";
	case 4:
		return "ZIF Socket";
	case 5:
		return "Replacement/Piggy Back";
	case 6:
		return "None";
	case 7:
		return "LIF Socket";
	case 8:
		return "Slot 1";
	case 9:
		return "Slot 2";
	case 10:
		return "370 Pin Socket";
	case 11:
		return "Slot A";
	case 12:
		return "Slot M";
	case 13:
		return "Socket 423";
	case 14:
		return "Socket A (Socket 462)";
	case 15:
		return "Socket 478";
	case 16:
		return "Socket 754";
	case 17:
		return "Socket 940";
	case 18:
		return "Socket 939";
	default:
		return "";
	}

}

char* CGeneralDescriptions::GetVoltageCapsDescription(unsigned short statusInfo){

	switch(statusInfo)
	{
	case 1:
		return "5 volts";
	case 2:
		return "3.3 volts";
	case 3:
		return "2.9 volts";
	default:
		return "";
	}

}

char* CGeneralDescriptions::GetPasswordDescription(unsigned short password){
	
	switch(password)
	{
	case 1:
		return "Other";
	case 2:
		return "Unknown";
	case 3:
		return "Disabled";
	case 4:
		return "Enabled";
	case 5:
		return "Not Implemented";
	default:
		return "";
	}
}

char* CGeneralDescriptions::GetDeviceInterfaceDescription(unsigned short deviceInterface){
	
	switch(deviceInterface)
	{
	case 1:
		return "Other";
	case 2:
		return "Unknown";
	case 3:
		return "Serial";
	case 4:
		return "PS/2";
	case 5:
		return "Infrared";
	case 6:
		return "HP-HIL";
	case 7:
		return "Bus mouse";
	case 8:
		return "ADB (Apple Desktop Bus)";
	case 160:
		return "Bus mouse DB-9";
	case 161:
		return "Bus mouse micro-DIN";
	case 162:
		return "USB";
	default:
		return "";
	}
}

char* CGeneralDescriptions::GetHandednessDescription(unsigned short handedness){

	switch(handedness)
	{
	case 0:
		return "Unknown";
	case 1:
		return "Not Applicable";
	case 2:
		return "Right Handed Operation";
	case 3:
		return "Left Handed Operation";
	default:
		return "";
	}

}

char* CGeneralDescriptions::GetPointingTypeDescription(unsigned short handedness){

	switch(handedness)
	{
	case 1:
		return "Other";
	case 2:
		return "Unknown";
	case 3:
		return "Mouse";
	case 4:
		return "Track Ball";
	case 5:
		return "Track Point";
	case 6:
		return "Glide Point";
	case 7:
		return "Touch Pad";
	case 8:
		return "Touch Screen";
	case 9:
		return "Mouse - Optical Sensor";
	default:
		return "";
	}


}

char* CGeneralDescriptions::GetDisplayTypeDescription(unsigned short displayType){
	
	switch(displayType)
	{
	case 0:
		return "Unknown";
	case 1:
		return "Other";
	case 2:
		return "Multiscan Color";
	case 3:
		return "Multiscan Monochrome";
	case 4:
		return "Fixed Frequency Color";
	case 5:
		return "Fixed Frequency Monochrome";
	default:
		return "";
	}

}

char* CGeneralDescriptions::GetNetConnectionStatusDescription(unsigned short networkConnectionStatus){
	
	switch(networkConnectionStatus)
	{
	case 0:
		return "Disconnected";
	case 1:
		return "Connecting";
	case 2:
		return "Connected";
	case 3:
		return "Disconnecting";
	case 4:
		return "Hardware Not Present";
	case 5:
		return "Hardware Disabled";
	case 6:
		return "Hardware Malfunction";
	case 7:
		return "Media Disconnected";
	case 8:
		return "Authenticating";
	case 9:
		return "Authentication Succeeded";
	case 10:
		return "Authentication Failed";
	case 11:
		return "Invalid Address";
	case 12:
		return "Credentials Required";
	case 13:
		return "Other";
	default:
		return "";
	}

}