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
bool mods()
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

void drive_on_water(Ped ped, Entity& waterobject)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
		if (!ENTITY::DOES_ENTITY_EXIST(waterobject))
		{
			Object objModel = 0xC42C019A; // prop_ld_ferris_wheel
			LoadAndChill(objModel);
			Vector3& Pos = GetOffsetInWorldCoords(playerPed, 0, 4.0f, 0);
			float whh = 0.0f;
			if (WATER::GET_WATER_HEIGHT_NO_WAVES(Pos.x, Pos.y, Pos.z, &whh))
			{
				RequestControlOfEnt(playerPed);
				ENTITY::SET_ENTITY_COORDS(playerPed, Pos.x, Pos.y, whh, 0, 0, 0, 1);
			}
			waterobject = OBJECT::CREATE_OBJECT(objModel, Pos.x, Pos.y, whh - 4.0f, 1, 1, 1);
			NETWORK::SET_NETWORK_ID_CAN_MIGRATE(NETWORK::OBJ_TO_NET(waterobject), ped != playerPed);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(waterobject, Pos.x, Pos.y, whh, 0, 0, 0);
			ENTITY::SET_ENTITY_ROTATION(waterobject, 0, 90, 0, 2, 1);
			ENTITY::FREEZE_ENTITY_POSITION(waterobject, true);
			//Game::Print::PrintBottomCentre("~b~Note:~s~ Enable again if water level is incorrect/changes.");
			WAIT(0);
			return;
		}

		Vector3& myPos = playerPosition();
		Vector3& Pos = ENTITY::GET_ENTITY_COORDS(waterobject, 1);

		if (isplayerinwater())
		{
			float whh = 0.0f;
			if (WATER::GET_WATER_HEIGHT_NO_WAVES(Pos.x, Pos.y, Pos.z, &whh))
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(waterobject, Pos.x, Pos.y, whh, 0, 0, 0);
			}
		}

		if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(waterobject))
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(waterobject);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(waterobject, myPos.x, myPos.y, Pos.z, 1, 1, 1);
		ENTITY::SET_ENTITY_ROTATION(waterobject, 180.0f, 90.0f, 180.0f, 2, 1);
		set_entity_as_visible(waterobject, false);
		ENTITY::FREEZE_ENTITY_POSITION(waterobject, true);
}