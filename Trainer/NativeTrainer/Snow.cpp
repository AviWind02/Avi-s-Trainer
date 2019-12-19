/*
	* Copyright (C) GTA:Multiplayer Team (https://wiki.gta-mp.net/index.php/Team)
	*
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are
	* met:
	*
	*     * Redistributions of source code must retain the above copyright
	*		notice, this list of conditions and the following disclaimer.
	*     * Redistributions in binary form must reproduce the above
	*		copyright notice, this list of conditions and the following disclaimer
	*		in the documentation and/or other materials provided with the
	*		distribution.
	*     * Neither the name of GTA-Network nor the names of its
	*		contributors may be used to endorse or promote products derived from
	*		this software without specific prior written permission.
	*
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES INCLUDING, BUT NOT
	* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	* DATA, OR PROFITS; OR BUSINESS INTERRUPTION HOWEVER CAUSED AND ON ANY
	* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY OUT OF THE USE
	* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <cstdint>
#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include <vector>
#include <cstdio>
#include <Psapi.h>
#include "MAIN.h"
// ScriptHookV
//#include "scripthookv/main.h"
//#include "scripthookv/natives.h"
//#pragma comment(lib, "lib/scripthookv.lib")












/*
	* Copyright (C) GTA:Multiplayer Team (https://wiki.gta-mp.net/index.php/Team)
	*
	* Redistribution and use in source and binary forms, with or without
	* modification, are permitted provided that the following conditions are
	* met:
	*
	*     * Redistributions of source code must retain the above copyright
	*		notice, this list of conditions and the following disclaimer.
	*     * Redistributions in binary form must reproduce the above
	*		copyright notice, this list of conditions and the following disclaimer
	*		in the documentation and/or other materials provided with the
	*		distribution.
	*     * Neither the name of GTA-Network nor the names of its
	*		contributors may be used to endorse or promote products derived from
	*		this software without specific prior written permission.
	*
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES INCLUDING, BUT NOT
	* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	* DATA, OR PROFITS; OR BUSINESS INTERRUPTION HOWEVER CAUSED AND ON ANY
	* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	* INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY OUT OF THE USE
	* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once



const char default_config[] =
"--Should the mod be enabled by default?\n"
"enableDefault=1\n"
"--\n"
"--Should vehicle tracks be drawn when snow is active?\n"
"vehicleTracks=1\n"
"--\n"
"--Should pedTracks be drawn when snow is active ?\n"
"pedTracks=1\n"
"--\n"
"--vehicleTrackDepth : 0 means light snow depth, 1 heavy depth\n"
"vehicleTrackDepth=1\n"
"--\n"
"--vehicleTrackDepth : 0 means light snow depth, 1 heavy depth\n"
"pedTrackDepth=1\n"
"--\n"
"--toggle key : you can change that on your own, default is NUMBER 0\n"
"--https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx?f=255&MSPPError=-2147217396\n"
"--Please note that the keys there are in hexadecimal format, you have to convert it to decimal!\n"
"--You can use this converter : http://www.binaryhexconverter.com/hex-to-decimal-converter\n"
"toggleKey=48";

CFGParser::CFGParser(const std::string& strName)
{
	this->strName.append(strName.c_str());
}

void CFGParser::Parse()
{
	char szExePath[MAX_PATH] = { 0 };
	GetModuleFileNameA(GetModuleHandle(NULL), szExePath, MAX_PATH);

	// Fix path in string
	for (size_t i = strlen(szExePath); i > 0; --i)
	{
		if (szExePath[i] == '\\')
		{
			szExePath[i + 1] = '\0';
			break;
		}
	}

	std::string strAbsolutePath;
	strAbsolutePath.append(szExePath);
	strAbsolutePath.append(this->strName);
	this->strName = strAbsolutePath;
	this->ExtractKeys();
}

bool CFGParser::KeyExists(const std::string& strKey)
{
	return this->mapContents.find(strKey) != this->mapContents.end();
}

void CFGParser::RemoveComment(std::string& strLine)
{
	if (strLine.find(';') != strLine.npos)
		strLine.erase(strLine.find(';'));
}

bool CFGParser::OnlyWhitespace(const std::string& strLine)
{
	return (strLine.find_first_not_of(' ') == strLine.npos);
}

bool CFGParser::ValidLine(const std::string& strLine)
{
	std::string strTemp = strLine;
	strTemp.erase(0, strTemp.find_first_not_of("\t "));
	if (strTemp[0] == '=')
		return false;

	for (size_t i = strTemp.find('=') + 1; i < strTemp.length(); i++)
		if (strTemp[i] != ' ')
			return true;

	return false;
}

void CFGParser::ExtractKey(std::string& strKey, size_t const& sepPos, const std::string& strLine)
{
	strKey = strLine.substr(0, sepPos);
	if (strKey.find('\t') != strLine.npos || strKey.find(' ') != strLine.npos)
		strKey.erase(strKey.find_first_of("\t "));
}

void CFGParser::ExtractValue(std::string& strValue, size_t const& sepPos, const std::string& strLine)
{
	strValue = strLine.substr(sepPos + 1);
	strValue.erase(0, strValue.find_first_not_of("\t "));
	strValue.erase(strValue.find_last_not_of("\t ") + 1);
}

void CFGParser::ExtractContents(const std::string& strLine)
{
	std::string strTemp = strLine;
	strTemp.erase(0, strTemp.find_first_not_of("\t "));
	size_t sepPos = strTemp.find('=');

	std::string strKey, strValue;
	this->ExtractKey(strKey, sepPos, strTemp);
	this->ExtractValue(strValue, sepPos, strTemp);

	if (strKey.find("--") != strKey.npos)
		return;

	if (!this->KeyExists(strKey))
		this->mapContents.insert(std::pair<std::string, std::string>(strKey, strValue));
	else
		return;
}

void CFGParser::ParseLine(const std::string& strLine, size_t const lineNo)
{
	if (strLine.find('=') == strLine.npos && strLine.find("--") == strLine.npos)
		return;

	if (!this->ValidLine(strLine))
		return;

	this->ExtractContents(strLine);
}

bool CFGParser::DoesFileExist()
{
	std::ifstream pFile;
	pFile.open(this->strName.c_str());
	if (!pFile)
		return false;
	else
		return true;
}

void CFGParser::ExtractKeys()
{
	std::ifstream pFile;
	pFile.open(this->strName.c_str());
	if (!pFile)
	{
		FILE* file = nullptr;
		fopen_s(&file, "snow.cfg", "w");
		if (!file)
			return;

		fwrite(default_config, sizeof(char), sizeof(default_config) - 1, file);
		fclose(file);

		ExtractKeys();
	}

	std::string strLine;
	size_t lineNo = 0;
	while (std::getline(pFile, strLine))
	{
		lineNo++;
		std::string strTemp = strLine;

		if (strTemp.empty())
			continue;

		this->RemoveComment(strTemp);
		if (this->OnlyWhitespace(strTemp))
			continue;

		this->ParseLine(strTemp, lineNo);
	}

	pFile.close();
}

// Find Pattern
bool CompareMemory(const uint8_t* pData, const uint8_t* bMask, const char* sMask)
{
	for (; *sMask; ++sMask, ++pData, ++bMask)
		if (*sMask == 'x' && *pData != *bMask)
			return false;

	return *sMask == NULL;
}


intptr_t FindPattern(const char* bMask, const char* sMask)
{
	// Game Base & Size
	static intptr_t pGameBase = (intptr_t)GetModuleHandle(nullptr);
	static uint32_t pGameSize = 0;
	if (!pGameSize)
	{
		MODULEINFO info;
		GetModuleInformation(GetCurrentProcess(), (HMODULE)pGameBase, &info, sizeof(MODULEINFO));
		pGameSize = info.SizeOfImage;
	}

	// Scan
	for (uint32_t i = 0; i < pGameSize; i++)
		if (CompareMemory((uint8_t*)(pGameBase + i), (uint8_t*)bMask, sMask))
			return pGameBase + i;

	return 0;
}







// Map Notification
void PushMapNotification(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(msg);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);
}

// Tracks
void EnableTracks(bool tracksVehicle = false, bool tracksPeds = false, bool deepTracksVehicle = false, bool deepTracksPed = false)
{
	static auto VAR_FeetSnowTracks_call = FindPattern("\x80\x3D\x00\x00\x00\x00\x00\x48\x8B\xD9\x74\x37", "xx?????xxxxx");
	if (!VAR_FeetSnowTracks_call)
	{
		PushMapNotification("Snow Mod is ~r~not compatible ~s~with this GTA Version #1!");
		return;
	}
	static auto VAR_FeetSnowTracks = VAR_FeetSnowTracks_call + (*(int32_t*)(VAR_FeetSnowTracks_call + 2)) + 7;
	//
	static auto VAR_VehicleSnowTracks_call = FindPattern("\x40\x38\x3D\x00\x00\x00\x00\x48\x8B\x42\x20", "xxx????xxxx");
	if (!VAR_VehicleSnowTracks_call)
	{
		PushMapNotification("Snow Mod is ~r~not compatible ~s~with this GTA Version #2!");
		return;
	}
	static auto VAR_VehicleSnowTracks = VAR_VehicleSnowTracks_call + (*(int32_t*)(VAR_VehicleSnowTracks_call + 3)) + 7;
	//

	VirtualProtect((void*)VAR_FeetSnowTracks, 1, PAGE_EXECUTE_READWRITE, nullptr);
	VirtualProtect((void*)VAR_VehicleSnowTracks, 1, PAGE_EXECUTE_READWRITE, nullptr);

	// Enable/Disable Vehicle/Foot Snow tracks
	*(uint8_t*)VAR_FeetSnowTracks = tracksVehicle;
	*(uint8_t*)VAR_VehicleSnowTracks = tracksPeds;

	// Switch for big/small tracks
	static auto vehicleTrackTypes = FindPattern("\xB9\x00\x00\x00\x00\x84\xC0\x44\x0F\x44\xF1", "x????xxxxxx");
	if (!vehicleTrackTypes)
	{
		PushMapNotification("Snow Mod is ~r~not compatible ~s~with this GTA Version #3!");
		return;
	}

	VirtualProtect((void*)vehicleTrackTypes, 1, PAGE_EXECUTE_READWRITE, nullptr);
	*(uint8_t*)(vehicleTrackTypes + 1) = deepTracksVehicle ? 0x13 : 0x14;

	static auto pedTrackTypes = FindPattern("\xB9\x00\x00\x00\x00\x84\xC0\x0F\x44\xD9\x48\x8B\x4F\x30", "x????xxxxxxxxx");
	if (!pedTrackTypes)
	{
		PushMapNotification("Snow Mod is ~r~not compatible ~s~with this GTA Version #4!");
		return;
	}
	VirtualProtect((void*)pedTrackTypes, 1, PAGE_EXECUTE_READWRITE, nullptr);
	*(uint8_t*)(pedTrackTypes + 1) = deepTracksPed ? 0x13 : 0x14;
}
bool bUseAddr13, bUseAddr22;

// Snow
void EnableSnow(bool bEnable)
{
	if (bEnable)
		EnableTracks(configVehicleTracks, configPedTracks, configVehicleTrackDepth, configPedTrackDepth);
	else
		EnableTracks();



	// Adresses
	static auto addr1 = FindPattern("\x80\x3D\x00\x00\x00\x00\x00\x74\x27\x84\xC0", "xx?????xxxx");
	static auto addr2 = FindPattern("\x44\x38\x3D\x00\x00\x00\x00\x74\x0F", "xxx????xx");
	static auto addr12 = FindPattern("\x40\x38\x35\x00\x00\x00\x00\x74\x18\x84\xdb\x74\x14", "xxx????xxxxxx");
	static auto addr13 = FindPattern("\x80\x3D\x00\x00\x00\x00\x00\x74\x25\xB9\x40\x00\x00\x00", "xx????xxxxxxxx");
	static auto addr22 = FindPattern("\x44\x38\x3D\x00\x00\x00\x00\x74\x1D\xB9\x40\x00\x00\x00", "xxx????xxxxxxx");


	//// Outdated
	//// In future the patterns might change
	//if (!addr1 || !addr2)
	//{
	//	PushMapNotification("Snow Mod is ~r~not compatible ~s~with this GTA Version #5!");
	//	return;
	//}
		// Patterns may change
	if (!addr1)
	{
		if (!addr12)
		{
			if (!addr13)
			{
				PushMapNotification("~r~Error:~s~ Snow is not compatible with this GTA Version.");
				//auto snow_ptr = GetTunablePtr<INT32>(RawTunableIndex::TURN_SNOW_ON_OFF);
				//*snow_ptr = bEnable ? 1 : 0;
				return;
			}
			else
			{
				addr1 = addr13;
				bUseAddr13 = true;
			}
		}
		else
		{
			addr1 = addr12;
		}
	}

	if (!addr2)
	{
		if (!addr22)
		{
			PushMapNotification("~r~Error:~s~ Snow is not compatible with this GTA Version.");
			//auto snow_ptr = GetTunablePtr<INT32>(RawTunableIndex::TURN_SNOW_ON_OFF);
			//*snow_ptr = bEnable ? 1 : 0;
			return;
		}
		else
		{
			addr2 = addr22;
			bUseAddr22 = true;
		}
	}
	// Original Memory
	static uint8_t original1[14] = { 0 };
	static uint8_t original2[15] = { 0 };

	// Initialize
	static bool bInitialized = false;
	if (!bInitialized)
	{
		bInitialized = true;

		// Unprotect Memory
		VirtualProtect((void*)addr1, 13, PAGE_EXECUTE_READWRITE, nullptr);
		VirtualProtect((void*)addr2, 14, PAGE_EXECUTE_READWRITE, nullptr);

		// Copy original Memory
		memcpy(&original1, (void*)addr1, 13);
		memcpy(&original2, (void*)addr2, 14);
	}

	// Toggle
	if (bEnable)
	{
		// Weather
		GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("XMAS");

		// NOP checks
		//memset((void*)addr1, 0x90, 13);
		//memset((void*)addr2, 0x90, 14);
		if (bUseAddr13)
		{
			BYTE* pFrom = (BYTE*)addr1;
			BYTE* pTo = (BYTE*)addr1 + 0x1B;
			DWORD protect;
			VirtualProtect(pFrom, 16, PAGE_EXECUTE_READWRITE, &protect);
			pFrom[0] = 0x48;  // mov rax, func
			pFrom[1] = 0xB8;
			*reinterpret_cast<BYTE**>(&pFrom[2]) = pTo;
			pFrom[10] = 0x50; // push rax
			pFrom[11] = 0xC3; // ret
			VirtualProtect(pFrom, 16, protect, &protect);
		}
		else
		{
			memset((void*)addr1, 0x90, 13);
		}

		if (bUseAddr22)
		{
			BYTE* pFrom = (BYTE*)addr2;
			BYTE* pTo = (BYTE*)addr2 + 0x1C;
			DWORD protect;
			VirtualProtect(pFrom, 16, PAGE_EXECUTE_READWRITE, &protect);
			pFrom[0] = 0x48;  // mov rax, func
			pFrom[1] = 0xB8;
			*reinterpret_cast<BYTE**>(&pFrom[2]) = pTo;
			pFrom[10] = 0x50; // push rax
			pFrom[11] = 0xC3; // ret
			VirtualProtect(pFrom, 16, protect, &protect);
		}
		else
		{
			memset((void*)addr2, 0x90, 14);
		}

		// Notification
		PushMapNotification("Snow ~g~ON");
	}
	else
	{
		//// Copy original memory
		//memcpy((void*)addr1, &original1, 13);
		//memcpy((void*)addr2, &original2, 14);

		//// Weather
		//GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST();
		//GAMEPLAY::SET_WEATHER_TYPE_NOW("CLEAR");

		//// Notification
		PushMapNotification("Snow ~r~OFF");

		// Copy original bytes back
		memcpy((void*)addr1, &original1, 13);
		memcpy((void*)addr2, &original2, 14);

		// Weather
		//CLEAR_WEATHER_TYPE_PERSIST();
		//SET_WEATHER_TYPE_NOW("Sunny");

		//*snow_ptr = 0;

		//_SET_FORCE_PED_FOOTSTEPS_TRACKS(false);
		//_SET_FORCE_VEHICLE_TRAILS(false);
		EnableTracks(false, false, false, false);
		// Now off

	}
}

//// Main
//void snowscript()
//{
//	static bool bSnowEnabled = false;
//
//	// Config
//	static bool bConfigParsed = false;
//
//	if (!bConfigParsed)
//	{
//		static CFGParser parser("snow.cfg");
//		parser.Parse();
//
//		if (parser.KeyExists("enableDefault"))
//			configEnableDefault = static_cast<char>(atoi(parser.GetValueOfKey<std::string>("enableDefault").c_str()) != 0);
//
//		if (parser.KeyExists("vehicleTracks"))
//			configVehicleTracks = static_cast<char>(atoi(parser.GetValueOfKey<std::string>("vehicleTracks").c_str())) != 0;
//
//		if (parser.KeyExists("pedTracks"))
//			configPedTracks = static_cast<char>(atoi(parser.GetValueOfKey<std::string>("pedTracks").c_str())) != 0;
//
//		if (parser.KeyExists("vehicleTrackDepth"))
//			configVehicleTrackDepth = static_cast<char>(atoi(parser.GetValueOfKey<std::string>("vehicleTrackDepth").c_str())) != 0;
//
//		if (parser.KeyExists("pedTrackDepth"))
//			configPedTrackDepth = static_cast<char>(atoi(parser.GetValueOfKey<std::string>("pedTrackDepth").c_str())) != 0;
//
//		if (parser.KeyExists("toggleKey"))
//			toggleKey = static_cast<int32_t>(atoi(parser.GetValueOfKey<std::string>("toggleKey").c_str()));
//
//		bConfigParsed = true;
//	}
//
//	// Default
//	if (configEnableDefault)
//	{
//		bSnowEnabled = true;
//		EnableSnow(true);
//	}
//
//	// Process
//	for (;;)
//	{
//		if (GetAsyncKeyState(toggleKey) & 1)
//		{
//		{
//			bSnowEnabled = !bSnowEnabled;
//			EnableSnow(bSnowEnabled);
//		}
//
//		WAIT(1);
//	}
//}