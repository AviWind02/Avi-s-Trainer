#pragma once
#include "MAIN.h"
#include <iostream>
#include <windows.h>
#pragma once
namespace HARDWAREID// setup for debugging
{
	extern bool USER_HWID;// setup for debugging
}
void HWID_Handler();
void HWID_Checker();
bool HARDWAREID::USER_HWID = false;// setup for debugging
using namespace std;

int Info_1;
int Info_2;
int Info_3;
int Info_4;
int Info_5;
int Info_6;


int HWID;
int HWID_List[5] = { 503316480, -1778384896, 2332, 754974720, -1526726656 };
int HWID_Avi = { 503316480 };

void HWID_Checker() {

	SYSTEM_INFO siSysInfo;

	GetSystemInfo(&siSysInfo);

	Info_1 = siSysInfo.dwOemId;
	Info_2 = siSysInfo.dwNumberOfProcessors;
	Info_3 = siSysInfo.dwProcessorType;
	Info_4 = siSysInfo.dwActiveProcessorMask;
	Info_5 = siSysInfo.wProcessorLevel;
	Info_6 = siSysInfo.wProcessorRevision;

	int HWID_Calculator[6] = { Info_1, Info_2, Info_3, Info_4, Info_5, Info_6 };

	HWID = HWID_Calculator[0, 1, 2, 3, 4, 5] * 2 * 4 * 8 * 16 * 32 * 64 * 120;

	if (HWID == HWID_Avi) {
		//notifyBottom("Welcome Avi Enter Your Password");
		//MENUAUTH::AUTHMenu = false;
		
	}
	else
		//Hooking::Cleanup();

}