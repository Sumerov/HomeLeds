#include <iostream>
#include <atlsafe.h>
#include <windows.h>
#include "SDK/MysticLight_SDK.h"

HINSTANCE MLinstance;

struct MysticLight {		//struct grouping all the function pointers under one pseudo-object, ml, for better clarity
	LPMLAPI_Initialize init;
	LPMLAPI_GetErrorMessage errorMsg;
	LPMLAPI_GetDeviceInfo getDevInfo;
	LPMLAPI_GetLedInfo getLedInfo;
	LPMLAPI_GetLedColor getColor;		//coloUr is better tbh..
	LPMLAPI_GetLedStyle	getStyle;
	LPMLAPI_GetLedMaxBright getMaxBright;
	LPMLAPI_GetLedBright getBright;
	LPMLAPI_GetLedMaxSpeed getMaxSpeed;
	LPMLAPI_GetLedSpeed getSpeed;
	LPMLAPI_SetLedColor setColor;
	LPMLAPI_SetLedStyle setStyle;
	LPMLAPI_SetLedBright setBright;
	LPMLAPI_SetLedSpeed setSpeed;
} ml;

int loadLib() {

	MLinstance = LoadLibrary(TEXT("MysticLight_SDK.dll"));
	if (!MLinstance)
		return 0;

	//initialise the struct fields
	ml.init = (LPMLAPI_Initialize)GetProcAddress(MLinstance, "MLAPI_Initialize");
	ml.errorMsg = (LPMLAPI_GetErrorMessage)GetProcAddress(MLinstance, "MLAPI_GetErrorMessage");
	ml.getDevInfo = (LPMLAPI_GetDeviceInfo)GetProcAddress(MLinstance, "MLAPI_GetDeviceInfo");
	ml.getLedInfo = (LPMLAPI_GetLedInfo)GetProcAddress(MLinstance, "MLAPI_GetLedInfo");
	ml.getColor = (LPMLAPI_GetLedColor)GetProcAddress(MLinstance, "MLAPI_GetLedColor");
	ml.getStyle = (LPMLAPI_GetLedStyle)GetProcAddress(MLinstance, "MLAPI_GetLedStyle");
	ml.getMaxBright = (LPMLAPI_GetLedMaxBright)GetProcAddress(MLinstance, "MLAPI_GetLedMaxBright");
	ml.getBright = (LPMLAPI_GetLedBright)GetProcAddress(MLinstance, "MLAPI_GetLedBright");
	ml.getMaxSpeed = (LPMLAPI_GetLedMaxSpeed)GetProcAddress(MLinstance, "MLAPI_GetLedMaxSpeed");
	ml.getSpeed = (LPMLAPI_GetLedSpeed)GetProcAddress(MLinstance, "MLAPI_GetLedSpeed");
	ml.setColor = (LPMLAPI_SetLedColor)GetProcAddress(MLinstance, "MLAPI_SetLedColor");
	ml.setStyle = (LPMLAPI_SetLedStyle)GetProcAddress(MLinstance, "MLAPI_SetLedStyle");
	ml.setBright = (LPMLAPI_SetLedBright)GetProcAddress(MLinstance, "MLAPI_SetLedBright");
	ml.setSpeed = (LPMLAPI_SetLedSpeed)GetProcAddress(MLinstance, "MLAPI_SetLedSpeed");

	return 1;
}

void printStatus(int status) {
	BSTR errStr;

	ml.errorMsg(status, &errStr);
	printf("Function returned status code: %S\n", errStr);
}


int main()
{
    int status;
    CComSafeArray<BSTR> devices;	//Wrapper class to use safearrays in C++ (https://msdn.microsoft.com/en-us/magazine/mt795188.aspx)
									//according to MSI docs GetDeviceInfo should return a safearray of BSTR for the devices..
	CComSafeArray<BSTR> ledCount;	//.. and a safearray of BSTR for the led count in each device
    status = ml.init();
    printStatus(status);
    if (status == 0) {		//initialisation successful

			status = ml.getDevInfo(&(devices.m_psa), &(ledCount.m_psa)); //the function will modify the pointer to the descriptor .m_psa, which is itself a pointer to the actual safearray
			printStatus(status);

			//sample loop to iterate through elements in a safearray
			for (LONG i = devices.GetLowerBound(); i <= devices.GetUpperBound(); i++) {
				printf("Device #%d: %S, Led count: %S\n", i, devices.GetAt(i), ledCount.GetAt(i));		//item count of both safearrays is the same, safe to access ledCount too
			}

			// ... put your code to control leds here
		}
    std::cout << "Hello World" << std::endl;

    return 0;
	getch();
}