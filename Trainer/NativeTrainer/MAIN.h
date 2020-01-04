#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Library Files:
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Winmm.lib")

// Windows Header Files:
#include <windows.h>
#include <Mmsystem.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <Psapi.h>
#include <timeapi.h>
#include <time.h>
#include <iterator>   


//UI
#include "GUI.h"
//INC Files
#include "..\inc\natives.h"
#include "..\inc\types.h"
#include "..\inc\enums.h"
#include "..\inc\main.h"
//Keys
#include"keyboard.h"
//function
#include"Function.h"
#include "ped.h"
#include "Map.h"
#include "Entity.h"
#include "Vehicle.h"
#include "UI.h"
//Self Sub
#include "Self.h"
//Teleports
#include"Teleport.h"
//Vehicle
#include"Customs.h"
#include"VOptions.h"
#include"Spawner.h"
//Weapons
#include"GunStore.h"
#include "WOptions.h"
//World
#include "WorldMisc.h"
//Menu Settings
#include "Settgins.h"
//player
#include "Model.h"
#include "Clothing.h"
//Snow
#include "snow.h"
//portelgun
#include"Protalgun.h"
//spooner 
#include "Sponner.h"
//block
#include "BlackList.h"
//mapmods
#include "MapMods.h"
//MISSION
#include "missionhelp.h"
//dev
#include "dev.h"
