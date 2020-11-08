// HWIDLock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <windows.h>

int HardwareID()
{
	std::string YourCustomerGUID = "{6cd003a8-82aa-4c76-96bf-014679a7e922}";

	std::string UserGUID = "";

	HW_PROFILE_INFO hwProfileInfo;

	if (GetCurrentHwProfile(&hwProfileInfo) != NULL)
	{
		UserGUID = hwProfileInfo.szHwProfileGuid; // Fill it with the customers guid
	}

	if (UserGUID == YourCustomerGUID) // See if thats customers guid
	{
		std::cout << "HWID auth success!" << std::endl;
		Sleep(1000);
		system("cls");

		/* code ...
		 ....
		 ....
		 ....
		*/
	}
	else
	{
		char ErrorMsg[50];
		sprintf_s(ErrorMsg, "Error - Contact ivan4games#2281");
		MessageBox(0, ErrorMsg, "HWID auth failed", MB_OK | MB_ICONERROR);
		exit(1);
	}


}