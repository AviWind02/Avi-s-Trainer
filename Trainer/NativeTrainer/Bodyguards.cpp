#include "MAIN.h"
// commom
char* BodyguardModel2 = "";
char* WeaponThing2 = "";
char* BodyguardModel = "csb_ramp_marine";
char* WeaponThing = "WEAPON_ASSAULTRIFLE";
int FormationPed = 0;
int Accu = 100;
int CombatRangehe = 500;
int pedattackers;
bool spawnWithBlipPed = false;
bool hostiletank = false;
bool vehspawncheck = false;
// Functions

void Mainbodyguardss()
{
	Menu::Title("Bodyguards");
	Ped group = PED::GET_PED_GROUP_INDEX(PLAYER::PLAYER_PED_ID());
	Menu::Subtitle("BodyGuards");
	Menu::Toggle("Spawn With Blip", spawnWithBlipPed);
	Menu::Int("Formation", FormationPed, 0, 3); { PED::SET_GROUP_FORMATION(group, FormationPed); }
	//Menu::Intstep("Accuracy", Accu, 0, 100, 10);
	//Menu::Intstep("Combat Range", CombatRangehe, 0, 500, 100);
	Menu::MenuOption("Models", modelsub);
	Menu::MenuOption("Weapons", BodyguardWeapons);
	if (Menu::Option("Spawn")) {
		{
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			Vector3 position = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			DWORD pedModel = GAMEPLAY::GET_HASH_KEY(BodyguardModel);
			Vector3 fposition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0.0, 5.0, 0.0);

			// misc topless bodyguards
			if (STREAMING::IS_MODEL_IN_CDIMAGE(pedModel) && STREAMING::IS_MODEL_VALID(pedModel))
			{

				STREAMING::REQUEST_MODEL(pedModel);
				while (!STREAMING::HAS_MODEL_LOADED(pedModel)) WAIT(0);
				Ped spawnedPed = PED::CREATE_PED(1, pedModel, fposition.x, fposition.y, fposition.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);
				//PED::SET_PED_CAN_RAGDOLL(spawnedPed, FALSE);

				PED::SET_PED_AS_GROUP_MEMBER(spawnedPed, group);
				PED::SET_PED_COMBAT_RANGE(spawnedPed, CombatRangehe);
				PED::SET_PED_ALERTNESS(spawnedPed, 100);
				PED::SET_PED_ACCURACY(spawnedPed, Accu);
				PED::SET_PED_CAN_SWITCH_WEAPON(spawnedPed, 1);
				PED::SET_PED_SHOOT_RATE(spawnedPed, 200);
				PED::SET_PED_KEEP_TASK(spawnedPed, true);
				AI::TASK_COMBAT_HATED_TARGETS_AROUND_PED(spawnedPed, 5000.f, 0);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(spawnedPed, GAMEPLAY::GET_HASH_KEY(WeaponThing), 1, 0);
				PED::SET_PED_KEEP_TASK(spawnedPed, true);
				PED::SET_PED_GENERATES_DEAD_BODY_EVENTS(spawnedPed, true);

				{
					/*
					if (featurePedestrianInvincibleBodyguardUpdate)
					{
						if (!featurePedestrianInvincibleBodyguard)
							ENTITY::SET_ENTITY_INVINCIBLE(spawnedPed, FALSE);
						featurePedestrianInvincibleBodyguardUpdate = FALSE;
					}
					if (featurePedestrianInvincibleBodyguard)
					{
						ENTITY::SET_ENTITY_INVINCIBLE(spawnedPed, TRUE);
					}
					*/
					if (spawnWithBlipPed)
					{
						int blip;
						blip = UI::ADD_BLIP_FOR_ENTITY(spawnedPed);
						UI::SET_BLIP_SPRITE(blip, 28);
						UI::SET_BLIP_COLOUR(blip, 3);
						int blip2 = UI::ADD_BLIP_FOR_ENTITY(spawnedPed);
						UI::SET_BLIP_SPRITE(blip2, 1); // REMOVE_BLIP
					}
					char buf[255];
					char buf1[255];
					char buf2[255];
					sprintf(buf, "Weapon: %s", WeaponThing2);//
					sprintf(buf1, "Model: %s", BodyguardModel2);
					sprintf(buf2, "Bodyguard spawned!~n~"
						"%s~n~"
						"%s~n~", buf1, buf);
					notifyBottom(buf2);
				}
			}
		}
	}
}


void Weaponss()
{
	Menu::Title("");
	Menu::Subtitle("Weapons"); // WeaponThing

	if (WeaponThing == "WEAPON_ASSAULTRIFLE")
	{
		WeaponThing2 = "Assault Rifle";
	}
	if (WeaponThing == "WEAPON_CARBINERIFLE")
	{
		WeaponThing2 = "Carbine Rifle";
	}
	if (WeaponThing == "WEAPON_KNIFE")
	{
		WeaponThing2 = "Knife";
	}
	if (WeaponThing == "WEAPON_ASSAULTSHOTGUN")
	{
		WeaponThing2 = "Assault Shotgun";
	}
	if (WeaponThing == "WEAPON_HEAVYSNIPER")
	{
		WeaponThing2 = "Heavy Sniper";
	}
	if (WeaponThing == "WEAPON_RPG")
	{
		WeaponThing2 = "RPG";
	}
	if (WeaponThing == "WEAPON_RAYPISTOL")
	{
		WeaponThing2 = "Ray Pistol";
	}
	if (WeaponThing == "WEAPON_RAYCARBINE")
	{
		WeaponThing2 = "Ray Carbine";
	}
	if (WeaponThing == "WEAPON_PISTOL")
	{
		WeaponThing2 = "Pistol";
	}
	if (WeaponThing == "WEAPON_MICROSMG")
	{
		WeaponThing2 = "Micro SMG";
	}
	if (WeaponThing == "WEAPON_MARKSMANRIFLE")
	{
		WeaponThing2 = "Marksman Rifle";
	}
	if (WeaponThing == "WEAPON_CARBINERIFLE_MK2")
	{
		WeaponThing2 = "Carbinerifle MKII";
	}
	if (WeaponThing == "WEAPON_VINTAGEPISTOL")
	{
		WeaponThing2 = "Silenced Pistol";
	}
	char buf[255];
	sprintf(buf, "Current Weapon: %s", WeaponThing2);//
	Menu::Option(buf);
	Menu::Break("Select Weapons");
	if (Menu::Option("Default")) {
		WeaponThing = "WEAPON_ASSAULTRIFLE";
		notifyBottom("Weapon set to:~n~"
			"Assaultrifle~n~");
	}
	if (Menu::Option("Carbine Rifle")) {
		WeaponThing = "WEAPON_CARBINERIFLE";
		notifyBottom("Weapon set to:~n~"
			"Carbinerifle~n~");
	}
	if (Menu::Option("Knife")) {
		WeaponThing = "WEAPON_KNIFE";
		notifyBottom("Weapon set to:~n~"
			"Knife~n~");
	}
	if (Menu::Option("Assault Shotgun")) {
		WeaponThing = "WEAPON_ASSAULTSHOTGUN";
		notifyBottom("Weapon set to:~n~"
			"Assault Shotgun~n~");
	}
	if (Menu::Option("Heavy Sniper")) {
		WeaponThing = "WEAPON_HEAVYSNIPER";
		notifyBottom("Weapon set to:~n~"
			"Heavy Sniper~n~");
	}
	if (Menu::Option("RPG")) {
		WeaponThing = "WEAPON_RPG";
		notifyBottom("Weapon set to:~n~"
			"RPG~n~");
	}
	if (Menu::Option("Ray Pistol")) {
		WeaponThing = "WEAPON_RAYPISTOL";
		notifyBottom("Weapon set to:~n~"
			"Raypistol~n~");
	}
	if (Menu::Option("Ray Carbine")) {
		WeaponThing = "WEAPON_RAYCARBINE";
		notifyBottom("Weapon set to:~n~"
			"Raycarbine~n~");
	}
	if (Menu::Option("Pistol")) {
		WeaponThing = "WEAPON_PISTOL";
		notifyBottom("Weapon set to:~n~"
			"Pistol~n~");
	}
	if (Menu::Option("Micro SMG")) {
		WeaponThing = "WEAPON_MICROSMG";
		notifyBottom("Weapon set to:~n~"
			"Miscro SMG~n~");
	}
	if (Menu::Option("Marksman Rifle")) {
		WeaponThing = "WEAPON_MARKSMANRIFLE";
		notifyBottom("Weapon set to:~n~"
			"Marksman Rifle~n~");
	}
	if (Menu::Option("Carbinerifle MKII")) {
		WeaponThing = "WEAPON_CARBINERIFLE_MK2";
		notifyBottom("Weapon set to:~n~"
			"Carbinerifle MK2~n~");
	}
}

void Modelss()
{
	Menu::Title("");
	Menu::Subtitle("Models");

	char buf[255];
	sprintf(buf, "Current Model: %s", BodyguardModel2);//

	if (BodyguardModel == "csb_ramp_marine")
	{
		BodyguardModel2 = "Marine";
	}
	if (BodyguardModel == "G_M_Y_Lost_02")
	{
		BodyguardModel2 = "Biker";
	}
	if (BodyguardModel == "S_M_Y_Cop_01")
	{
		BodyguardModel2 = "Cop";
	}
	if (BodyguardModel == "Player_Zero")
	{
		BodyguardModel2 = "Michael";
	}
	if (BodyguardModel == "Player_One")
	{
		BodyguardModel2 = "Franklin";
	}
	if (BodyguardModel == "Player_two")
	{
		BodyguardModel2 = "Trevor";
	}
	if (BodyguardModel == "U_M_Y_ImpoRage")
	{
		BodyguardModel2 = "Impo Rage";
	}
	if (BodyguardModel == "U_M_Y_RSRanger_01")
	{
		BodyguardModel2 = "Space Ranger";
	}
	Menu::Option(buf);
	Menu::Break("Set Models");
	if (Menu::Option("Default")) {
		BodyguardModel = "csb_ramp_marine";
		notifyBottom("Model set to:~n~"
			"Marine~n~");
	}
	if (Menu::Option("Biker")) {
		BodyguardModel = "G_M_Y_Lost_02";
		notifyBottom("Model set to:~n~"
			"Biker~n~");
	}
	if (Menu::Option("Cop")) {
		BodyguardModel = "S_M_Y_Cop_01";
		notifyBottom("Model set to:~n~"
			"Cop~n~");
	}
	if (Menu::Option("Michael")) {
		BodyguardModel = "Player_Zero";
		notifyBottom("Model set to:~n~"
			"Michael~n~");
	}
	if (Menu::Option("Franklin")) {
		BodyguardModel = "Player_One";
		notifyBottom("Model set to:~n~"
			"Franklin~n~");
	}
	if (Menu::Option("Trevor")) {
		BodyguardModel = "Player_two";
		notifyBottom("Model set to:~n~"
			"Trevor~n~");
	}
	if (Menu::Option("Impo Rage")) {
		BodyguardModel = "U_M_Y_ImpoRage";
		notifyBottom("Model set to:~n~"
			"Impo Rage~n~");
	}
	if (Menu::Option("Space Ranger")) {
		BodyguardModel = "U_M_Y_RSRanger_01";
		notifyBottom("Model set to:~n~"
			"Space Ranger~n~");
	}

}











//
//
//
//
//
//// spawn enemy
//
//bool HostileTank()
//{
//	if (hostiletank)
//	{
//		if (vehspawncheck)
//		{
//			int movdel = GAMEPLAY::GET_HASH_KEY("rhino");
//			float speed = ENTITY::GET_ENTITY_SPEED(PLAYER::PLAYER_PED_ID());
//			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("rhino"));
//			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("rhino")))
//			{
//				Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 6.0, 0.0, 0.0);
//				int vehattackers = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY("rhino"), coords.x, coords.y + 10, coords.z, 0, 1, 0);
//				if (ENTITY::DOES_ENTITY_EXIST(vehattackers))
//				{
//					vehspawncheck = false;
//					pedattackers = true;
//					if (pedattackers)
//					{
//						STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01"));
//						if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01")))
//						{
//							Vector3 coords_ = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 6.0, 0.0, 0.0);
//							pedattackers = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01"), coords_.x, coords_.y, coords_.z, 1, 1, 0);
//							if (ENTITY::DOES_ENTITY_EXIST(pedattackers))
//							{
//								PED::SET_PED_INTO_VEHICLE(pedattackers, vehattackers, -1);
//								VEHICLE::SET_VEHICLE_DOORS_LOCKED(vehattackers, true);
//								VEHICLE::SET_VEHICLE_ENGINE_ON(vehattackers, true, true, true);
//								VEHICLE::SET_HELI_BLADES_FULL_SPEED(vehattackers);
//								AI::TASK_VEHICLE_SHOOT_AT_PED(0, 0, 0);
//								AI::TASK_LEAVE_ANY_VEHICLE(pedattackers, true, false);
//								int TargetHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
//								AI::TASK_COMBAT_PED(pedattackers, TargetHandle, 0, 16);
//								AI::TASK_VEHICLE_CHASE(pedattackers, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer));
//								PED::SET_PED_CAN_SWITCH_WEAPON(pedattackers, true);
//								pedattackers = false;
//								return true;
//							}
//							return false;
//						}
//						return false;
//					}
//					return false;
//				}
//				return false;
//			}
//			return false;
//		}
//		return false;
//	}
//	return false;
//}
//void DeletePed(int pedID)
//{
//	if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pedID))
//		while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pedID));
//
//	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(pedID, 1, 1);
//	PED::DELETE_PED(&pedID);
//}
//void makePedHostile(uint Ped, int Target, bool choporswat = false, bool isClone = false)
//{
//	if (choporswat)
//	{
//		AI::TASK_COMBAT_PED(Ped, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 16);
//		PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
//	}
//	else
//	{
//		if (isClone)
//		{
//			int Hash = ENTITY::GET_ENTITY_MODEL(Ped);
//			DeletePed(Ped);
//
//			STREAMING::REQUEST_MODEL(Hash);
//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Target), 1);
//			if (STREAMING::HAS_MODEL_LOADED(Hash))
//			{
//				int newPed = PED::CREATE_PED(21, Hash, coords.x, coords.y, coords.z, 0, 1, 0);
//				if (ENTITY::GET_ENTITY_HEALTH(newPed) == ENTITY::GET_ENTITY_MAX_HEALTH(newPed))
//				{
//					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hash);
//					RequestControlOfEnt(newPed);
//					AI::TASK_COMBAT_PED(newPed, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 16);
//					PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
//				}
//			}
//		}
//		else
//		{
//			int TargetHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Target);
//			AI::TASK_COMBAT_PED(Ped, TargetHandle, 0, 16);
//		}
//	}
//
//}
//void GiveWeaponPed(int Ped, int WeaponHash)
//{
//	WEAPON::GIVE_WEAPON_TO_PED(Ped, WeaponHash, 9999, 1, 1);
//
//}
//
//void Spawnenemyy()
//{
//	Menu::Title("Spawn Enemy");
//
//	Menu::Subtitle("Spawn Enemy");
//	if (ShowInfo)
//	{
//		espnigger(selectedPlayer);
//		auto Plyername = PLAYER::GET_PLAYER_NAME(selectedPlayer);
//		LoadPlayerInfo(Plyername, selectedPlayer);
//		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), false);
//		GRAPHICS::DRAW_MARKER(22, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 0.3, 0.3, 0.3, 255, 0, 0, 200, 1, 1, 1, 0, 0, 0, 0);
//
//	}
//	if (Menu::Option("Tank Enemy")) {
//
//		hostiletank = true;
//		vehspawncheck = true;
//		if (HostileTank());
//		notifyBottom("Might have to press it a few times");
//	}
//	if (Menu::Option("Spawn Enemy")) {
//		int clone[1000];
//		int gcount = 1;
//		int eclone[1000];
//		int egcount = 1;
//		Ped selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
//		if (!ENTITY::DOES_ENTITY_EXIST(selectedPlayer)) return;
//		Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE");
//		Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedPlayer, 1);
//		Hash pedm = GAMEPLAY::GET_HASH_KEY("CSB_MWeather");
//		STREAMING::REQUEST_MODEL(pedm);
//		while (!STREAMING::HAS_MODEL_LOADED(pedm))
//			WAIT(0);
//		eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
//		ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
//		PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
//		WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
//		PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
//		AI::TASK_COMBAT_PED(eclone[egcount], selectedPlayer, 1, 1);
//		PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
//		PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
//		egcount++;
//	}
//	if (Menu::Option("Swat With Flaregun")) {
//		{
//
//			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
//			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01")))
//			{
//				int Ped = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"), coords.x, coords.y, coords.z, 0, 1, 0);
//				if (ENTITY::DOES_ENTITY_EXIST(Ped))
//				{
//					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//					char buf[100];
//					RequestControlOfEnt(Ped);
//					GiveWeaponPed(Ped, 0x47757124);
//					makePedHostile(Ped, selectedPlayer, true);
//				}
//			}
//		}
//	}
//	if (Menu::Option("Swat With Heavy Shotgun")) {
//		{
//
//			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
//			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01")))
//			{
//				int Ped = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"), coords.x, coords.y, coords.z, 0, 1, 0);
//				if (ENTITY::DOES_ENTITY_EXIST(Ped))
//				{
//					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//					char buf[100];
//					RequestControlOfEnt(Ped);
//					GiveWeaponPed(Ped, 0x3AABBBAA);
//					makePedHostile(Ped, selectedPlayer, true);
//				}
//			}
//		}
//	}
//
//	if (Menu::Option("Swat With Railgun")) {
//		{
//
//			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
//			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01")))
//			{
//				int Ped = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"), coords.x, coords.y, coords.z, 0, 1, 0);
//				if (ENTITY::DOES_ENTITY_EXIST(Ped))
//				{
//					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//					char buf[100];
//					RequestControlOfEnt(Ped);
//					GiveWeaponPed(Ped, 0x6D544C99);
//					makePedHostile(Ped, selectedPlayer, true);
//				}
//			}
//		}
//	}
//	if (Menu::Option("Swat With Assault Rifle")) {
//		{
//
//			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
//			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01")))
//			{
//				int Ped = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"), coords.x, coords.y, coords.z, 0, 1, 0);
//				if (ENTITY::DOES_ENTITY_EXIST(Ped))
//				{
//					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//					char buf[100];
//					RequestControlOfEnt(Ped);
//					GiveWeaponPed(Ped, 0xBFEFFF6D);
//					makePedHostile(Ped, selectedPlayer, true);
//				}
//			}
//		}
//	}
//	if (Menu::Option("Swat With Knife")) {
//		{
//
//			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
//			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01")))
//			{
//				int Ped = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"), coords.x, coords.y, coords.z, 0, 1, 0);
//				if (ENTITY::DOES_ENTITY_EXIST(Ped))
//				{
//					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//					char buf[100];
//					RequestControlOfEnt(Ped);
//					GiveWeaponPed(Ped, 2578778090);
//					makePedHostile(Ped, selectedPlayer, true);
//				}
//			}
//		}
//	}
//	if (Menu::Option("Swat With Minigun")) {
//		{
//
//			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
//			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01")))
//			{
//				int Ped = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"), coords.x, coords.y, coords.z, 0, 1, 0);
//				if (ENTITY::DOES_ENTITY_EXIST(Ped))
//				{
//					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01"));
//					char buf[100];
//					RequestControlOfEnt(Ped);
//					GiveWeaponPed(Ped, 0x42BF8A85);
//					makePedHostile(Ped, selectedPlayer, true);
//				}
//			}
//		}
//	}
//}
