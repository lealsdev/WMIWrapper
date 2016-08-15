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
// WMIBase.h - The base class for all WMI classes.
// 
// Email: lealves_82@yahoo.com.br
// --------------------------------------------------------------------------------------------------------------------


#include <comdef.h>
#include <Wbemidl.h>

using namespace std;

//**************************************************
// Exporting macro.
//**************************************************
#ifdef WMIWRAPPER_EXPORTS
#define WMIWRAPPER_API __declspec(dllexport)
#else
#define WMIWRAPPER_API __declspec(dllimport)
#endif


//**************************************************
// This class is the base class for all WMI
// classes.
//**************************************************
class WMIWRAPPER_API CWMIBase {	
public:		
	//**************************************************
	// The HRESULT is defined as public so class's users 
	// have the opportunity to saw the process result.
	//**************************************************
	HRESULT HResult;

	//**************************************************
	// Pure virtual destructor to make the class
	// abstract.
	//**************************************************
	virtual ~CWMIBase() = 0;

protected:
	//**************************************************
	// Required to get the IWbemServices.
	//**************************************************
	IWbemLocator* PLocator;

	//**************************************************
	// The interface that will execute the query.
	//**************************************************
	IWbemServices* PServices;

	//**************************************************
	// Will store the data returned by _pServices.
	//**************************************************
	IEnumWbemClassObject* PEnumerator;

	//**************************************************
	// Method that executes the query and populates
	// _pEnumerator with the results.
	// LPCWSTR: WQL
	//**************************************************
	bool MakeWMIRequest(LPCWSTR);

	//**************************************************
	// Returns a char* value.
	//
	// IWbemClassObject*: Contains the property value.
	// LPCWSTR: The WMI property name.
	//**************************************************
	char* GetStringValue(IWbemClassObject*, LPCWSTR);

	//**************************************************
	// Returns an unsigned short value.
	//
	// IWbemClassObject*: Contains the property value.
	// LPCWSTR: The WMI property name.
	//**************************************************
	unsigned short GetUShortValue(IWbemClassObject*, LPCWSTR);

	//**************************************************
	// Returns an unsigned int value.
	//
	// IWbemClassObject*: Contains the property value.
	// LPCWSTR: The WMI property name.
	//**************************************************
	unsigned int GetUIntValue(IWbemClassObject*, LPCWSTR);

	//**************************************************
	// Returns an unsigned long value.
	//
	// IWbemClassObject*: Contains the property value.
	// LPCWSTR: The WMI property name.
	//**************************************************
	unsigned int GetULongValue(IWbemClassObject*, LPCWSTR);

	//**************************************************
	// Returns a BOOL value.
	//
	// IWbemClassObject*: Contains the property value.
	// LPCWSTR: The WMI property name.
	//**************************************************
	BOOL GetBoolValue(IWbemClassObject*, LPCWSTR);		

	//**************************************************
	// Populates a char**.
	//
	// IWbemClassObject*: Contains the property value.
	// LPCWSTR: The WMI property name.
	// char**: Pointer to a char array.
	//**************************************************
	void GetCharArrayPointer(IWbemClassObject*, LPCWSTR, char**);

	//**************************************************
	// Returns a double value.
	//
	// IWbemClassObject*: Contains the property value.
	// LPCWSTR: The WMI property name.
	//**************************************************
	double GetDoubleValue(IWbemClassObject*, LPCWSTR);

	//**************************************************
	// Returns a long array.
	//
	// IWbemClassObject*: Contains the property value.
	// LPCWSTR: The WMI property name.
	//**************************************************
	long* GetLongArray(IWbemClassObject*, LPCWSTR);

	//**************************************************
	// Returns a SafeArray length.
	//
	// IWbemClassObject*: Contains the property value.
	// LPCWSTR: The WMI property name.
	//**************************************************
	int GetSafeArrayPropertyLength(IWbemClassObject*, LPCWSTR);

private:
	//**************************************************
	// Initializes the COM library. 
	//**************************************************
	void InitializeCOM();

	//**************************************************
	// Registers security.
	//**************************************************
	void SetSecurityLevel();

	//**************************************************
	// Creates a instance of WbemLocator.
	//**************************************************
	void ObtainWMILocator();

	//**************************************************
	// Connect to WMI.
	//**************************************************
	void Connect();

	//**************************************************
	// Set security levels.
	//**************************************************
	void SetProxySecurityLevels();

	//**************************************************
	// Calls the private configuration methods.
	//**************************************************
	BOOL ConfigureWMI();
};

extern WMIWRAPPER_API int nWMIWRAPPER;

WMIWRAPPER_API int fnWMIWRAPPER(void);
