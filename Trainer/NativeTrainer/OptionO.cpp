#include "MAIN.h"
bool spam = false;
bool Spectate = false;

char* yoinkrid()
{
	int netHandle[13];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(selectedPlayer, netHandle, 13);
	char* UserID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&netHandle[0]);
	return (char*)netHandle[13];
}
int ExplosionTypes_ = ExplosionTypeStickyBomb;
std::vector<std::string> ExplosionTypes // no point tbh
{
"Grenade",
//"GrenadeL",,
"StickyBomb",
"Molotov",
"Rocket",
"TankShell",
//"Hioctane",
"Car",
"Plane",
"PetrolPump",
"Bike",
"Steam",
"Flame",
//"WaterHydrant",
"GasCanister",
"Boat",
"ShipDestroy",
"Truck",
"Bullet",
"SmokeGL",
"SmokeG",
"BZGas",
"Flare",
"GasCanister2",
"Extinguisher",
"ProgramAR",
"Train",
"Barrel",
"Propane",
"Blimp",
"FlameExplode",
"Tanker",
"PlaneRocket",
"VehicleBullet",
"GasTank",
"FireWork",
"SnowBall",
"ProxMine",
"Valkyrie",
};



void OnlineFuctions()
{
	if (spam)
	{
		Vector3 player_pos = Get_Position(targetPlayer());
		FIRE::ADD_EXPLOSION(player_pos.x, player_pos.y, player_pos.z, ExplosionTypes_, 0.0f, true, false, true);//just in case a player dont pick a explosion type 
	}
	if (Spectate) {
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(true, targetPlayer());
	}
}
void selected()
{
	
	Menu::Title("");
	Menu::Subtitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
	Menu::Toggle("Sound Spam", spam);
	Set_PFX_Player("Clown Appears", "scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", targetPlayer());
	Set_Player_Animation("Push Ups", "amb@world_human_push_ups@male@base", "base", targetPlayer());
	Attach_Object_Player("EMP", "hei_prop_heist_emp", targetPlayer());
	Ram_Player_With_Veh("Nero", "nero", targetPlayer());
	Shoot_Player("AirStrike", "WEAPON_AIRSTRIKE_ROCKET", targetPlayer());
}

void Vehselected()
{
	Menu::Title("");
	Menu::Subtitle("Vehicle Trolling");
	if (Menu::Option("Slingshot Car")) {
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(targetPlayer(), true));
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(targetPlayer(), true)));
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(targetPlayer(), true), 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
		}
	}
	if (Menu::Option("Kick him out of Car")) {
		Ped playerPed = targetPlayer();
		RequestControlOfEnt(playerPed);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
		AI::CLEAR_PED_TASKS(playerPed);
		AI::CLEAR_PED_SECONDARY_TASK(playerPed);
	}
	if (Menu::Option("Explode Vehicle")) {
		Ped selectedplayer = targetPlayer();
		if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
		FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 29, 0.5f, true, false, 5.0f);
	}
	if (Menu::Option("Launch Vehicle")) {
		Player playerPed = targetPlayer();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
		{
			RequestControlOfEnt(veh);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 300.0);
		}
	}
	if (Menu::Option("Push Vehicle")) {
		Player playerPed = targetPlayer();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
		{
			RequestControlOfEnt(veh);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 120.0);

		}
	}
	if (Menu::Option("Pop Tires")) {
		Vehicle selectedlPlayerveh = PED::GET_VEHICLE_PED_IS_IN(targetPlayer(), FALSE);
		bool isveh = PED::IS_PED_IN_ANY_VEHICLE(targetPlayer(), FALSE);
		if (isveh)
		{
			RequestControlOfEnt(selectedlPlayerveh);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(selectedlPlayerveh, TRUE);
			for (int i = 30; i--;)
				VEHICLE::SET_VEHICLE_TYRE_BURST(selectedlPlayerveh, i, TRUE, 1000.f);

		}
	}
}

/*char* message = "Boo";
	char buff[255];
	sprintf(buff, "%s", GetPlayerNetworkHandle(selectedPlayer));
	if (Menu::Option("~r~Send Text"))
	{
		int handle;
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(selectedPlayer, &handle, 13);
		NETWORK::NETWORK_SEND_TEXT_MESSAGE(message, &handle);

	}
	std::vector<UINT64> GetPlayerNetworkHandle(Player player) {
	const int size = 13;
	uint64_t* buffer = std::make_unique<uint64_t[]>(size).get();
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, reinterpret_cast<int*>(buffer), 13);
	std::vector<UINT64> result(buffer, buffer + sizeof(buffer));
	return result;
}
//auto GetPlayerNetworkHandle(Player player)
//{
//	int handle;
//	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle, 13);
//    return handle;
//}
	*/