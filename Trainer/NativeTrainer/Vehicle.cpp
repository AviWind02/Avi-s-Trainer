#include "MAIN.h"

void deletecar()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(playerVeh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(playerVeh))
		{
			if (ENTITY::DOES_ENTITY_EXIST(playerVeh))
			{
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(playerVeh, 1, 1);
				VEHICLE::DELETE_VEHICLE(&playerVeh);
			}
		}
	}
}
bool isbennys()
{
	Hash carhash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));
	if (carhash == 0x25C5AF13 || carhash == 0xC397F748 || carhash == 0xAED64A63 || carhash == 0x9C669788
		|| carhash == 0x877358AD || carhash == 0x95466BDB || carhash == 0x866BCE26 || carhash == 0xD2D5E00E
		|| carhash == 0x4131F378 || carhash == 0xBCDE91F0 || carhash == 0x710A2B9B || carhash == 0xE33A477B
		|| carhash == 0x86618EDA || carhash == 0x0D4EA603 || carhash == 0x42BC5E19 || carhash == 0x94DA98EF
		|| carhash == 0x00FDFFB0 || carhash == 0x779B4F2D || carhash == 0xEE6024BC)
	{
		if (VEHICLE::IS_VEHICLE_MODEL(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), carhash))
			return true;
	}
	return false;
}
Vehicle getvehpedisin()
{
	return PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
}
bool islsc()
{
	Menu::Title("");
	Menu::Subtitle("Avi's Customs");

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	for (int i = 0; i < 10; i++) // 0 to 10 here since those are the simple not null mods 
	{
		if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) > 0)
		{
			return true;
		}
	}
	return false;
}
Vehicle nearbyveh()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle* vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle nearbyveh_ = vehs[OffsetID];
			return vehs[OffsetID];
			return nearbyveh_;
		}
	}
}
bool setvehmod(char* mod, int type, int index)
{

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Option(mod);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_VEHICLE_MOD(veh, type, index, custom_Wheels);
			return true;
		}
	}
	return false;
}
//VEHICLE
static std::string lastvehmodel("");
bool get_vehicle_keyboard_result(uint* outModel)
{
	std::string result = show_keyboard("FMMC_KEY_TIP", &lastvehmodel[0]);
	if (!result.empty())
	{
		uint model = $(result);
		if (!STREAMING::IS_MODEL_IN_CDIMAGE(model) || !STREAMING::IS_MODEL_A_VEHICLE(model))
		{
			lastvehmodel = "";
			//notifyBottom("~HUD_COLOUR_RED~Not A Valid Model!");
			return false;
		}

		else
		{
			STREAMING::REQUEST_MODEL(model);
			DWORD now = GetTickCount();
			while (!STREAMING::HAS_MODEL_LOADED(model) && GetTickCount() < now + 5000)
			{
				WAIT(0);
			}

			if (!STREAMING::HAS_MODEL_LOADED(model))
			{
				lastvehmodel = "";
				std::ostringstream ss2;
				ss2 << "~HUD_COLOUR_RED~ Timed out requesting  " << result << " : 0x" << model;
				//				notifyBottom(ss2.str());
				return false;
			}

			lastvehmodel = result;
			*outModel = model;
			return true;
		}

	}

	return false;
}

void Set_Veh_Mod_Get_Looped(int modtype)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, modtype);
	if (Menu::Option("Stock"))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, modtype, -1, 1);
	}
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, modtype, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should always be 0
					VEHICLE::SET_VEHICLE_MOD(veh, modtype, i, 1);
					//set the veh mod
				}
			}
		}
	}
}