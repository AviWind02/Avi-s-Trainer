#include "MAIN.h"



//=================
// PED FUNCTIONS
//=================
void set_ped_seatbelt_on(Ped ped, bool toggle)
{
	if (toggle)
	{
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(ped, 1);
		PED::SET_PED_CONFIG_FLAG(ped, 32, false);
	}
	else
	{
		//boo
	}
}
void network_set_everyone_ignore_player(Player player)
{
	PLAYER::SET_POLICE_IGNORE_PLAYER(player, 1);
	PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, 1);
	PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, 0);
	PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, 1);
}
Ped nearbypeds()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	//Start at index 2, and the odd elements are padding    
	int peds[arrSize];
	//0 index is the size of the array    
	peds[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
	for (int i = 0; i < count; ++i)
	{
		int offsettedID = i * 2 + 2;
		if (ENTITY::DOES_ENTITY_EXIST(peds[offsettedID]))
		{
			return peds[offsettedID];
		}
	}
}
void check_player_model()
{
	// common variables
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

	Hash model = ENTITY::GET_ENTITY_MODEL(playerPed);
	if (ENTITY::IS_ENTITY_DEAD(playerPed) || PLAYER::IS_PLAYER_BEING_ARRESTED(player, true))
		if (model != GAMEPLAY::GET_HASH_KEY("player_zero") &&
			model != GAMEPLAY::GET_HASH_KEY("player_one") &&
			model != GAMEPLAY::GET_HASH_KEY("player_two"))
		{
			notifyMap("turning to ~g~normal~w~..");
			WAIT(1000);

			model = GAMEPLAY::GET_HASH_KEY("player_zero");
			STREAMING::REQUEST_MODEL(model);
			while (!STREAMING::HAS_MODEL_LOADED(model))
				WAIT(0);
			PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
			PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

			// wait until player is ressurected
			while (ENTITY::IS_ENTITY_DEAD(PLAYER::PLAYER_PED_ID()) || PLAYER::IS_PLAYER_BEING_ARRESTED(player, true))
				WAIT(0);

		}
}
Ped ClonePed(Ped ped)
{
	if (ENTITY::DOES_ENTITY_EXIST(ped) && !ENTITY::IS_ENTITY_DEAD(ped))
	{
		return PED::CLONE_PED(ped, ENTITY::GET_ENTITY_HEADING(ped), 1, 1);
	}

	return 0;
}

Ped CreatePed(char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle)
{
	Ped NewPed;
	int PedHash = GAMEPLAY::GET_HASH_KEY(PedName);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(PedHash))
	{
		if (STREAMING::IS_MODEL_VALID(PedHash))
		{
			STREAMING::REQUEST_MODEL(PedHash);
			while (!STREAMING::HAS_MODEL_LOADED(PedHash)) WAIT(0);

			NewPed = PED::CREATE_PED(ped_type, PedHash, SpawnCoordinates.x, SpawnCoordinates.y, SpawnCoordinates.z, 0, network_handle, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PedHash);
			return NewPed;
		}
	}

	return -1;
}
void set_self_nearby_peds_calm()
{
	int ped = nearbypeds();
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(ped);
	PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(ped, 1);
	PED::SET_PED_FLEE_ATTRIBUTES(ped, 0, 0);
	PED::SET_PED_COMBAT_ATTRIBUTES(ped, 17, 1);

}
//Animations
void LoadAnim(char* dict)
{
	int tick = 0;
	STREAMING::REQUEST_ANIM_DICT(dict);
	while (tick < 100 && !STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		tick++;
		WAIT(0);
	}
}

void playAnimation(Ped ped, bool loop, char* dict, char* anim)
{
	LoadAnim(dict);
	int a = -1;
	int b = 1;

	if (!loop)
	{
		a = 1;
		b = 0;
	}

	AI::TASK_PLAY_ANIM(ped, dict, anim, 10000.0f, -1.5f, a, b, 0.445f, false, false, false);

}

//Skins
bool applyChosenSkin(DWORD model)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model))
		{
			WAIT(0);
		}

		Vehicle veh = NULL;
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		}

		PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
		//PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), FALSE);
		PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
		WAIT(0);

		if (veh != NULL)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}

		WAIT(100);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

		return true;
	}
	return false;
}

bool applyChosenSkin(std::string skinName)
{
	DWORD model = GAMEPLAY::GET_HASH_KEY((char*)skinName.c_str());
	return applyChosenSkin(model);
}