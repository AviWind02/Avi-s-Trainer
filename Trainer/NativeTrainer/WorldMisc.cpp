#include "MAIN.h"

bool _BOATS = false; bool brecklose = false;
bool snow = false;
bool _TRUCKS = false;
bool speed = false;
bool cruise_speed = false;
bool blow_up_veh = false;
bool detele_cars = false;
bool maxveharound = false;
bool showcords = false;
bool grav = true;
bool Sync_Time = false;
bool world_speed = false;
bool customDirection = false;
bool loopclear = false;
bool ClearCops = false;
bool ClearObjects = false;
bool ClearVehicles = false;
bool ClearPeds = false;
bool ClearProjectiles = false;
bool ClearArea = false;
bool mobile_radio = false;
bool nophone = false;
bool dispatch = false; bool flything = false;
bool outofcontroll = false;
bool kill, hell = false;
bool threedwaypoint = true; 
bool emp = false;
bool madpeds = false;
float scaleX = 50, scaleY = 50, scaleZ = 999999999;// Z 999999999 just to be safe!!!
float world__speed;
float train_speed;
float train_cruise_speed;
float wavesHeight;
float WindSpeed;
float Rainintensity;
float Gravity;
float Direction;
int time_h;
int time_m;
int time_s;
int day;
int month;
int year;
int ObjMeteor;
bool RequestNetworkControl1(uint vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	if (giveUp)
		return false;
	else return true;
}




void VectorToFloat(Vector3 unk, float* Out)
{
	Out[0] = unk.x;
	Out[1] = unk.y;
	Out[2] = unk.z;
}

void offset_from_entity(int entity, float X, float Y, float Z, float* Out)
{
	VectorToFloat(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity, X, Y, Z), Out);
}

void MaxUpgrades(uint veh)
{

	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	VEHICLE::SET_VEHICLE_COLOURS(veh, 0, 32);
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "Avi");
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, 1);
	VEHICLE::SET_VEHICLE_MOD(veh, 16, 5, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 12, 2, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 11, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 14, 14, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 15, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 13, 2, 0);
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 6);
	VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, 5);
	VEHICLE::SET_VEHICLE_MOD(veh, 23, 19, 1);
	VEHICLE::SET_VEHICLE_MOD(veh, 0, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 1, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 2, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 3, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 4, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 5, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 6, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 7, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 8, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 9, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 10, 1, 0);
	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 4, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 5, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 6, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 7, 1);
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 0, 255, 0);
}
int rw = 255, gw = 0, bw = 0;
void RGBFadee()
{
	if (rw > 0 && bw == 0) {
		rw--;
		gw++;
	}
	if (gw > 0 && rw == 0) {
		gw--;
		bw++;
	}
	if (bw > 0 && gw == 0) {
		rw++;
		bw--;
	}
}
int  teleports_outside_door_kept_closed = 16;
void world_misc_functions()
{
	if (madpeds)
	{
		Hash firingPattern = key("FIRING_PATTERN_FULL_AUTO");
		Player playerPed = PLAYER::PLAYER_PED_ID();
		Vector3 pos = Get_Position(playerPed);
		int Trick = rndInt(0, 2);
		if (Trick == 0)
		PED::CREATE_RANDOM_PED(pos.x + rndInt(1, 200), pos.y + rndInt(1, 200), pos.z + rndInt(1, 200));// there may not be a lot near you 
		//AI::TASK_EVERYONE_LEAVE_VEHICLE(nearbyveh());// if in veh idk
		AI::TASK_VEHICLE_CHASE(nearbypeds(), playerPed);//boo
		AI::TASK_LEAVE_VEHICLE(nearbypeds(), nearbyveh(), teleports_outside_door_kept_closed);
		WEAPON::GIVE_WEAPON_TO_PED(nearbypeds(), GAMEPLAY::GET_HASH_KEY("WEAPON_RAYCARBINE"), 9999, 1, 1);
		AI::TASK_SHOOT_AT_ENTITY(nearbypeds(), playerPed, 500000, firingPattern);// may not work for long
	}
	if (threedwaypoint)
	{
		RGBFadee();
		Player playerPed = PLAYER::PLAYER_PED_ID();
		Vector3 pos = get_blip_marker();
		if(waypoint)
		GRAPHICS::DRAW_MARKER(1, pos.x, pos.y,
			pos.z - 1, 0, 0, 0, 0, 0, 0, scaleX, scaleY, scaleZ, rw, gw, bw, 255, 0, 0, 2, 0, 0, 0, 0);
	}
	if (grav)
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_GRAVITY(playerPed, true);

	}
	else
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_GRAVITY(playerPed, false);

	}
	if (emp)
	{
		GRAPHICS::_SET_BLACKOUT(true);
		RequestControlOfEnt(nearbyveh());
		int Trick = rndInt(0, 5);
		if (Trick == 0)
			VEHICLE::SET_VEHICLE_ENGINE_ON(nearbyveh(), false, true, false);
		else
			VEHICLE::SET_VEHICLE_OUT_OF_CONTROL(nearbyveh(), false, false);

	}
	else
		GRAPHICS::_SET_BLACKOUT(false);

	if (_BOATS) { VEHICLE::SET_RANDOM_BOATS(true); }
	if (_TRUCKS) { VEHICLE::SET_GARBAGE_TRUCKS(true); }

	if (blow_up_veh)
	{

		RequestControlOfEnt(nearbyveh());
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(nearbyveh(), false);
		FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 0.f);

	}
	if (detele_cars)
	{
		RequestControlOfEnt(nearbyveh());
		ENTITY::SET_ENTITY_COORDS(nearbyveh(), 6400.f, 6400.f, 0.f, false, false, false, false);
	}
	if (outofcontroll)
	{

		RequestNetworkControl1(nearbyveh());
		VEHICLE::SET_VEHICLE_OUT_OF_CONTROL(nearbyveh(), true, true);
	}
	if (maxveharound)
	{

		RequestNetworkControl1(nearbyveh());
		MaxUpgrades(nearbyveh());
	}
	if (showcords)
	{

		Vector3 playerCoord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
		std::string xMsg = "~HUD_COLOUR_GREEN~X " + std::to_string(playerCoord.x);
		std::string yMsg = " Y " + std::to_string(playerCoord.y);
		std::string zMsg = " Z " + std::to_string(playerCoord.z);
		std::string coordMessage = xMsg + yMsg + zMsg;
		char* xCoord = strcpy((char*)malloc(coordMessage.length() + 1), coordMessage.c_str());
		UI::SET_TEXT_FONT(7);
		UI::_SET_TEXT_ENTRY_2("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(xCoord);
		UI::_DRAW_SUBTITLE_TIMED(1, 1);
	}
	if (Sync_Time) { time_t now = time(0); tm t; localtime_s(&t, &now); TIME::SET_CLOCK_TIME(t.tm_hour, t.tm_min, t.tm_sec); }
	if (customDirection)
	{
		GAMEPLAY::SET_WIND_DIRECTION(Direction);
	}
	if (loopclear)
	{
		ClearCops = true;
		ClearObjects = true;
		ClearVehicles = true;
		ClearPeds = true;
		ClearProjectiles = true;
		ClearArea = true;
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA(Pos.x, Pos.y, Pos.z, 250, true, true, true, true);
		GAMEPLAY::CLEAR_AREA_OF_COPS(Pos.x, Pos.y, Pos.z, 250, 0);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(Pos.x, Pos.y, Pos.z, 250, 0);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(Pos.x, Pos.y, Pos.z, 250, 1, 1, 0, 0, 1);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(Pos.x, Pos.y, Pos.z, 250, 0);
		GAMEPLAY::CLEAR_AREA_OF_PROJECTILES(Pos.x, Pos.y, Pos.z, 250, 0);
	}
	if (ClearCops)
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_COPS(Pos.x, Pos.y, Pos.z, 250, 0);
	}
	if (ClearObjects)
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(Pos.x, Pos.y, Pos.z, 250, 0);
	}
	if (ClearVehicles)
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(Pos.x, Pos.y, Pos.z, 250, 1, 1, 0, 0, 1);
	}
	if (ClearPeds)
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(Pos.x, Pos.y, Pos.z, 250, 0);

	}
	if (ClearProjectiles)
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_PROJECTILES(Pos.x, Pos.y, Pos.z, 250, 0);
	}
	if (ClearArea)
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA(Pos.x, Pos.y, Pos.z, 250, true, true, true, true);
	}
	if (mobile_radio)
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		AUDIO::SET_FRONTEND_RADIO_ACTIVE(true);
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(1);
		//AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Radio_On", playerPed, "TAXI_SOUNDS", 0, 0);

	}
	else
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(0);
		//AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Radio_Off", playerPed, "TAXI_SOUNDS", 0, 0);
	}
	if (nophone)
	{
		if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(0xF292D030) > 0) // cellphone_controller
		{
			GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("cellphone_controller");
		}
		else
		{
			SCRIPT::REQUEST_SCRIPT_WITH_NAME_HASH(GAMEPLAY::GET_HASH_KEY("cellphone_controller"));
		}
	}
	if (dispatch)
	{
		PLAYER::SET_DISPATCH_COPS_FOR_PLAYER(PLAYER::PLAYER_PED_ID(), true);
	}
	else
	{
		PLAYER::SET_DISPATCH_COPS_FOR_PLAYER(PLAYER::PLAYER_PED_ID(), false);
	}
	if (flything)
	{

		int Objhash = GAMEPLAY::GET_HASH_KEY("PROP_ASTEROID_01");
		Vector3 Myc = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		float MyCR = (Myc.x, Myc.y, Myc.z);
		float Random = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(MyCR, 10000.0);
		if (!STREAMING::HAS_MODEL_LOADED(Objhash))
			STREAMING::REQUEST_MODEL(Objhash);
		else
		{
			ObjMeteor = OBJECT::CREATE_OBJECT(Objhash, Myc.x + Random, Myc.y + Random, Myc.z + 100 + Random, 1, 1, 1);
			if (ENTITY::DOES_ENTITY_EXIST(ObjMeteor))
			{
				ENTITY::SET_ENTITY_COLLISION(ObjMeteor, 1, 1);
				ENTITY::FREEZE_ENTITY_POSITION(ObjMeteor, false);
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&ObjMeteor);
			}
		}

		if (ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(ObjMeteor)) {
			Vector3 AstroidCoord = ENTITY::GET_ENTITY_COORDS(ObjMeteor, FALSE);
			FIRE::ADD_EXPLOSION(AstroidCoord.x, AstroidCoord.y, AstroidCoord.z, eExplosionType::ExplosionTypePlane, 20, TRUE, FALSE, 0.5f);
			ENTITY::SET_OBJECT_AS_NO_LONGER_NEEDED(&ObjMeteor);
		}

	}
	if (kill)
	{

		PED::EXPLODE_PED_HEAD(nearbypeds(), 0x5FC3C11);
	}
	if (hell)
	{
		AI::TASK_VEHICLE_CHASE(nearbypeds(), nearbypeds());

	}
	if (brecklose)
	{

		float tempCoords1[3];
		DWORD tempHash;
		DWORD tempPed = PLAYER::PLAYER_PED_ID();
		DWORD tempVehicle;
		bool tick = 0;

		offset_from_entity(tempPed, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);


		// Kick away nearest vehicle
		tempVehicle = VEHICLE::GET_CLOSEST_VEHICLE(tempCoords1[0], tempCoords1[1], tempCoords1[2], 400.0f, 0, 4);
		if (ENTITY::DOES_ENTITY_EXIST(tempVehicle)) ENTITY::APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);

		// Exploding vehicles
		switch (GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1, 10))
		{
		case 1: tempHash = 3945366167; break;
		case 2: tempHash = 92612664; break;
		case 3: tempHash = 1488164764; break;
		case 4: tempHash = 117401876; break;
		case 5: tempHash = 408192225; break;
		case 6: tempHash = 3863274624; break;
		case 7: tempHash = 165154707; break;
		case 8: tempHash = 1011753235; break;
		case 9: tempHash = 941800958; break;
		case 10: tempHash = 970385471; break;
		}

		tempVehicle = VEHICLE::CREATE_VEHICLE(tempHash, tempCoords1[0], tempCoords1[1], tempCoords1[2], GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
		ENTITY::APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
		NETWORK::NETWORK_EXPLODE_VEHICLE(tempVehicle, 1, 1, 1);

		// Dying peds
		switch (GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1, 10))
		{
		case 1: tempHash = 1682622302; break;
		case 2: tempHash = 113504370; break;
		case 3: tempHash = 4244282910; break;
		case 4: tempHash = 808859815; break;
		case 5: tempHash = 1004114196; break;
		case 6: tempHash = 3696858125; break;
		case 7: tempHash = 921110016; break;
		case 8: tempHash = 880829941; break;
		case 9: tempHash = 1462895032; break;
		case 10: tempHash = 773063444; break;
		}

		offset_from_entity(tempPed, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
		tempPed = PED::CREATE_PED(22, tempHash, tempCoords1[0], tempCoords1[1], tempCoords1[2], GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
		ENTITY::APPLY_FORCE_TO_ENTITY(tempPed, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
		PED::EXPLODE_PED_HEAD(tempPed, 324506233);
		FIRE::ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], 26, 4.0f, 1, 0, 3.0f);

		// Water hydrants
		offset_from_entity(tempPed, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
		FIRE::ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], 13, 8.0f, 1, 0, 3.0f);

		// Zombies
		offset_from_entity(tempPed, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
		tempPed = PED::CREATE_PED(22, -1404353274, tempCoords1[0], tempCoords1[1], tempCoords1[2], GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
		NETWORK::PED_TO_NET(tempPed);
		PED::SET_PED_COMBAT_ABILITY(tempPed, 100);
		AI::TASK_COMBAT_HATED_TARGETS_AROUND_PED(tempPed, 400.0f, 0);
	}
}

void World_Radio()
{
	Menu::Title("");
	Menu::Subtitle("Radio");
	Menu::MenuOption("Radio Stations", worldradios);
	Menu::Toggle("Mobile Radio", mobile_radio);
	if (Menu::Option("Skip Radio (Forward)")) { AUDIO::SKIP_RADIO_FORWARD(); }
	if (Menu::Option("Freeze Radio Station")) { AUDIO::FREEZE_RADIO_STATION(AUDIO::GET_PLAYER_RADIO_STATION_NAME()); }
	if (Menu::Option("Unfreeze Radio Station")) { AUDIO::UNFREEZE_RADIO_STATION(AUDIO::GET_PLAYER_RADIO_STATION_NAME()); }

}

void World_Stations()
{
	Menu::Title("");
	Menu::Subtitle("Radio Stations");
	if (Menu::Option("Los Santos Rock Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_01_CLASS_ROCK"); }
	if (Menu::Option("Non-Stop-Pop FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_02_POP"); }
	if (Menu::Option("Radio Los Santos")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_03_HIPHOP_NEW"); }
	if (Menu::Option("Channel X")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_04_PUNK"); }
	if (Menu::Option("West Coast Talk Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_05_TALK_01"); }
	if (Menu::Option("Rebel Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_06_COUNTRY"); }
	if (Menu::Option("Soulwax FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_07_DANCE_01"); }
	if (Menu::Option("East Los FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_08_MEXICAN"); }
	if (Menu::Option("West Coast Classics")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_09_HIPHOP_OLD"); }
	if (Menu::Option("Blue Ark")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_12_REGGAE"); }
	if (Menu::Option("Worldwide FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_13_JAZZ"); }
	if (Menu::Option("FlyLo FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_14_DANCE_02"); }
	if (Menu::Option("The Lowdown 91.1")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_15_MOTOWN"); }
	if (Menu::Option("The Lab")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_20_THELAB"); }
	if (Menu::Option("Radio Mirror Park")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_16_SILVERLAKE"); }
	if (Menu::Option("Space 103.2")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_17_FUNK"); }
	if (Menu::Option("Vinewood Boulevard Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_18_90S_ROCK"); }
	if (Menu::Option("Blonded Los Santos 97.8 FM")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_21_DLC_XM17"); }
	if (Menu::Option("Blaine County Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_11_TALK_02"); }
	if (Menu::Option("Los Santos Underground Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_22_DLC_BATTLE_MIX1_RADIO"); }
	if (Menu::Option("Self Radio")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_19_USER"); }
	Menu::Break("Hidden Radio Stations");
	if (Menu::Option("HIDDEN_RADIO_01_CLASS_ROCK")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_01_CLASS_ROCK"); }
	if (Menu::Option("HIDDEN_RADIO_AMBIENT_TV_BRIGHT")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_AMBIENT_TV_BRIGHT"); }
	if (Menu::Option("HIDDEN_RADIO_AMBIENT_TV")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_AMBIENT_TV"); }
	if (Menu::Option("HIDDEN_RADIO_ADVERTS")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_ADVERTS"); }
	if (Menu::Option("HIDDEN_RADIO_02_POP")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_02_POP"); }
	if (Menu::Option("HIDDEN_RADIO_03_HIPHOP_NEW")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_03_HIPHOP_NEW"); }
	if (Menu::Option("HIDDEN_RADIO_04_PUNK")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_04_PUNK"); }
	if (Menu::Option("HIDDEN_RADIO_06_COUNTRY")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_06_COUNTRY"); }
	if (Menu::Option("HIDDEN_RADIO_07_DANCE_01")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_07_DANCE_01"); }
	if (Menu::Option("HIDDEN_RADIO_09_HIPHOP_OLD")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_09_HIPHOP_OLD"); }
	if (Menu::Option("HIDDEN_RADIO_12_REGGAE")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_12_REGGAE"); }
	if (Menu::Option("HIDDEN_RADIO_15_MOTOWN")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_15_MOTOWN"); }
	if (Menu::Option("HIDDEN_RADIO_16_SILVERLAKE")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_16_SILVERLAKE"); }
	if (Menu::Option("HIDDEN_RADIO_STRIP_CLUB")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_STRIP_CLUB"); }
	if (Menu::Option("HIDDEN_RADIO_BIKER_CLASSIC_ROCK")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_BIKER_CLASSIC_ROCK"); }
	if (Menu::Option("HIDDEN_RADIO_BIKER_MODERN_ROCK")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_BIKER_MODERN_ROCK"); }
	if (Menu::Option("HIDDEN_RADIO_BIKER_PUNK")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_BIKER_PUNK"); }
	if (Menu::Option("HIDDEN_RADIO_BIKER_HIP_HOP")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_BIKER_HIP_HOP"); }
	Menu::Break("Other Radio Stations");
	if (Menu::Option("HIDDEN_RADIO_STRIP_CLUB")) { AUDIO::SET_RADIO_TO_STATION_NAME("HIDDEN_RADIO_STRIP_CLUB"); }
	if (Menu::Option("RADIO_22_DLC_BATTLE_MIX1_CLUB")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_22_DLC_BATTLE_MIX1_CLUB"); }
	if (Menu::Option("DLC_BATTLE_MIX1_CLUB_PRIV")) { AUDIO::SET_RADIO_TO_STATION_NAME("DLC_BATTLE_MIX1_CLUB_PRIV"); }
	if (Menu::Option("DLC_BATTLE_MIX2_CLUB_PRIV")) { AUDIO::SET_RADIO_TO_STATION_NAME("DLC_BATTLE_MIX2_CLUB_PRIV"); }
	if (Menu::Option("RADIO_23_DLC_BATTLE_MIX2_CLUB")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_23_DLC_BATTLE_MIX2_CLUB"); }
	if (Menu::Option("RADIO_25_DLC_BATTLE_MIX4_CLUB")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_25_DLC_BATTLE_MIX4_CLUB"); }
	if (Menu::Option("RADIO_26_DLC_BATTLE_CLUB_WARMUP")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_26_DLC_BATTLE_CLUB_WARMUP"); }
	if (Menu::Option("DLC_BATTLE_MIX4_CLUB_PRIV")) { AUDIO::SET_RADIO_TO_STATION_NAME("DLC_BATTLE_MIX4_CLUB_PRIV"); }
	if (Menu::Option("RADIO_24_DLC_BATTLE_MIX3_CLUB")) { AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_24_DLC_BATTLE_MIX3_CLUB"); }
	if (Menu::Option("DLC_BATTLE_MIX3_CLUB_PRIV")) { AUDIO::SET_RADIO_TO_STATION_NAME("DLC_BATTLE_MIX3_CLUB_PRIV"); }
}

void World_Clear()
{
	Menu::Title("");
	Menu::Subtitle("Clear");
	if (Menu::Option("Clear All"))
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA(Pos.x, Pos.y, Pos.z, 250, true, true, true, true);
		GAMEPLAY::CLEAR_AREA_OF_COPS(Pos.x, Pos.y, Pos.z, 250, 0);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(Pos.x, Pos.y, Pos.z, 250, 0);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(Pos.x, Pos.y, Pos.z, 250, 1, 1, 0, 0, 1);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(Pos.x, Pos.y, Pos.z, 250, 0);
		GAMEPLAY::CLEAR_AREA_OF_PROJECTILES(Pos.x, Pos.y, Pos.z, 250, 0);
	}
	if (Menu::Option("Clear Cops"))
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_COPS(Pos.x, Pos.y, Pos.z, 250, 0);
	}
	if (Menu::Option("Clear Objects"))
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(Pos.x, Pos.y, Pos.z, 250, 0);
	}
	if (Menu::Option("Clear Vehicles"))
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(Pos.x, Pos.y, Pos.z, 250, 1, 1, 0, 0, 1);
	}
	if (Menu::Option("Clear peds"))
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(Pos.x, Pos.y, Pos.z, 250, 0);

	}
	if (Menu::Option("Clear Projectiles"))
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA_OF_PROJECTILES(Pos.x, Pos.y, Pos.z, 250, 0);
	}
	if (Menu::Option("Clear Area"))
	{
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		GAMEPLAY::CLEAR_AREA(Pos.x, Pos.y, Pos.z, 250, true, true, true, true);

	}
	Menu::Break("Loop");
	Menu::Toggle("Clear All", loopclear);
	Menu::Toggle("Clear Cops", ClearCops);
	Menu::Toggle("Clear Objects", ClearObjects);
	Menu::Toggle("Clear Vehicles", ClearVehicles);
	Menu::Toggle("Clear Peds", ClearPeds);
	Menu::Toggle("Clear Projectiles", ClearProjectiles);
	Menu::Toggle("Clear Area", ClearArea);




}
void world_wind()
{
	Menu::Title("");
	Menu::Subtitle("Wind");
	if (Menu::Option("Wind Speed Plus")) { WindSpeed += 0.1f; GAMEPLAY::SET_WIND_SPEED(WindSpeed); }
	if (Menu::Option("Wind Speed Minus")) { WindSpeed -= 0.1f; GAMEPLAY::SET_WIND_SPEED(WindSpeed); }
	if (Menu::Option("Reset")) { GAMEPLAY::SET_WIND_SPEED(0.0); }
	if (Menu::Option("North")) { GAMEPLAY::SET_WIND_SPEED(0.0); }
	if (Menu::Option("North East")) { GAMEPLAY::SET_WIND_DIRECTION(1.0); }
	if (Menu::Option("East")) { GAMEPLAY::SET_WIND_DIRECTION(2.0); }
	if (Menu::Option("South East")) { GAMEPLAY::SET_WIND_DIRECTION(3.0); }
	if (Menu::Option("South")) { GAMEPLAY::SET_WIND_DIRECTION(4.0); }
	if (Menu::Option("South West")) { GAMEPLAY::SET_WIND_DIRECTION(5.0); }
	if (Menu::Option("West")) { GAMEPLAY::SET_WIND_DIRECTION(6.0); }
	if (Menu::Option("North West")) { GAMEPLAY::SET_WIND_DIRECTION(7.0); }
	Menu::Toggle("Custom Direction", customDirection);
	if (customDirection) { Menu::Float("Custom Direction(f)", Direction, 0.0, 7.0); }



}

void wether()
{
	Menu::Title("");
	Menu::Subtitle("Weather Options");
	if (Menu::Option("Force Lighning")) { GAMEPLAY::FORCE_LIGHTNING_FLASH(); }
	if (Menu::Option("Clear")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("CLEAR"); }
	if (Menu::Option("Extra Sunny")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("EXTRASUNNY"); }
	if (Menu::Option("Clouds")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("CLOUDS"); }
	if (Menu::Option("Over Cast")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("OVERCAST"); }
	if (Menu::Option("Rain")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("RAIN"); }
	if (Menu::Option("Clearing")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("CLEARING"); }
	if (Menu::Option("Thunder")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("THUNDER"); }
	if (Menu::Option("Smog")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("SMOG"); }
	if (Menu::Option("Foggy")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("FOGGY"); }
	if (Menu::Option("Xmas")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("XMAS"); }
	if (Menu::Option("Light Snow")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("SNOWLIGHT"); }
	if (Menu::Option("Blizzard")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("BLIZZARD"); }
	if (Menu::Option("Random")) { GAMEPLAY::SET_RANDOM_WEATHER_TYPE(); }
	Menu::Toggle("Snow", snow);
	Menu::Break("Rain Intensity");
	if (Menu::Option("Rain Intensity FX Plus")) { Rainintensity += 2.8f; GAMEPLAY::_SET_RAIN_FX_INTENSITY(Rainintensity); }
	if (Menu::Option("Rain Intensity FX Minus")) { Rainintensity -= 2.8f; GAMEPLAY::_SET_RAIN_FX_INTENSITY(Rainintensity); }
	if (Menu::Option("Reset Rain Intensity FX Speed")) { GAMEPLAY::_SET_RAIN_FX_INTENSITY(0.0); }
	Menu::Break("Wave");
	if (Menu::Option("Waves Height Plus")) { wavesHeight += 2.8f; WATER::_SET_CURRENT_INTENSITY(wavesHeight); }
	if (Menu::Option("Waves Height Minus")) { wavesHeight -= 2.8f; WATER::_SET_CURRENT_INTENSITY(wavesHeight); }
	if (Menu::Option("Reset Waves Height")) { wavesHeight -= 0.1f; WATER::_RESET_CURRENT_INTENSITY(); }

}


void Worldspeed()
{
	Menu::Title("");
	Menu::Subtitle("World Speed");
	if (Menu::Option("Slow World Speed")) { GAMEPLAY::SET_TIME_SCALE(0.6); }
	if (Menu::Option("Slower World Speed")) { GAMEPLAY::SET_TIME_SCALE(0.4); }
	if (Menu::Option("Even Slower World Speed")) { GAMEPLAY::SET_TIME_SCALE(0.2); }
	if (Menu::Option("Even Even Slower World Speed")) { GAMEPLAY::SET_TIME_SCALE(0.0); }
	if (Menu::Option("Reset/Normal World Speed")) { GAMEPLAY::SET_TIME_SCALE(1.0); }
	Menu::Toggle("Custom World Speed", world_speed);
	if (world_speed) { Menu::Float("Csutom World Speed", world__speed, 0.0, 1.0); GAMEPLAY::SET_TIME_SCALE(world__speed); }

}




void World_Vehicle_Options()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	Menu::Title("");
	Menu::Subtitle("World Vehicle Options");
	Menu::Toggle("Explode Vehicle", blow_up_veh);
	Menu::Toggle("Vehicle Hell", hell);
	Menu::Toggle("Delete Vehicle", detele_cars);
	Menu::Toggle("Upgrade Vehicle", maxveharound);
	Menu::Toggle("Out Of Control", outofcontroll);
	if (Menu::Option("Delete All Trains")) { VEHICLE::DELETE_ALL_TRAINS(); }
	Menu::Toggle("Random boats", _BOATS);
	Menu::Toggle("Set Garbage Trucks", _TRUCKS);
	Menu::Toggle("Train Speeds", speed);
	if (speed) { Menu::Float("Train Speed", train_speed, 1.0, 10.0); }
	Menu::Toggle("Train Cruise Speeds", cruise_speed);
	if (cruise_speed) { Menu::Float("Train Cruise Speed", train_cruise_speed, 1.0, 10.0); }

}


void World_Gravity()
{
	Menu::Title("");
	Menu::Subtitle("Gravity");
	if (Menu::Option("Zero G")) { GAMEPLAY::SET_GRAVITY_LEVEL(1.0f); }
	if (Menu::Option("Pluto")) { GAMEPLAY::SET_GRAVITY_LEVEL(0.6f); }
	if (Menu::Option("Earth's Moon")) { GAMEPLAY::SET_GRAVITY_LEVEL(1.6f); }
	if (Menu::Option("Mercury/Mars")) { GAMEPLAY::SET_GRAVITY_LEVEL(3.7f); }
	if (Menu::Option("Venus/Uranus")) { GAMEPLAY::SET_GRAVITY_LEVEL(8.9f); }
	if (Menu::Option("Earth")) { GAMEPLAY::SET_GRAVITY_LEVEL(9.8f); }
	if (Menu::Option("Saturn")) { GAMEPLAY::SET_GRAVITY_LEVEL(10.4f); }
	if (Menu::Option("Neptune")) { GAMEPLAY::SET_GRAVITY_LEVEL(11.2f); }
	if (Menu::Option("Jupiter")) { GAMEPLAY::SET_GRAVITY_LEVEL(24.9f); }
	if (Menu::Option("Sun")) { GAMEPLAY::SET_GRAVITY_LEVEL(274.0f); }
	Menu::Toggle("Game Gravity", grav);
	Menu::Break("Gravity Custom");
	if (Menu::Option("Gravity Plus")) { Gravity += 0.1f; GAMEPLAY::SET_GRAVITY_LEVEL(Gravity); }
	if (Menu::Option("Gravity Minus")) { Gravity -= 0.1f; GAMEPLAY::SET_GRAVITY_LEVEL(Gravity); }
	if (Menu::Option("Reset Gravity")) { GAMEPLAY::SET_GRAVITY_LEVEL(9.8); }
}
void world_cloud()
{
	Menu::Title("");
	Menu::Subtitle("Clouds");
	if (Menu::Option("Altostratus")) { GAMEPLAY::LOAD_CLOUD_HAT("Altostratus", 1.9f); }
	if (Menu::Option("Cirrocumulus")) { GAMEPLAY::LOAD_CLOUD_HAT("Cirrocumulus", 1.9f); }
	if (Menu::Option("Cirrus")) { GAMEPLAY::LOAD_CLOUD_HAT("Cirrus", 1.9f); }
	if (Menu::Option("Clear 01")) { GAMEPLAY::LOAD_CLOUD_HAT("Clear 01", 1.9f); }
	if (Menu::Option("Cloudy 01")) { GAMEPLAY::LOAD_CLOUD_HAT("Cloudy 01", 1.9f); }
	if (Menu::Option("Contrails")) { GAMEPLAY::LOAD_CLOUD_HAT("Contrails", 1.9f); }
	if (Menu::Option("NoClouds")) { GAMEPLAY::LOAD_CLOUD_HAT("NoClouds", 1.9f); }
	if (Menu::Option("Puffs")) { GAMEPLAY::LOAD_CLOUD_HAT("Puffs", 1.9f); }
	if (Menu::Option("Rain")) { GAMEPLAY::LOAD_CLOUD_HAT("Rain", 1.9f); }
	if (Menu::Option("Shower")) { GAMEPLAY::LOAD_CLOUD_HAT("Shower", 1.9f); }
	if (Menu::Option("Snowy 01")) { GAMEPLAY::LOAD_CLOUD_HAT("Snowy 01", 1.9f); }
	if (Menu::Option("Stormy 01")) { GAMEPLAY::LOAD_CLOUD_HAT("Stormy 01", 1.9f); }
	if (Menu::Option("Stratoscumulus")) { GAMEPLAY::LOAD_CLOUD_HAT("Stratoscumulus", 1.9f); }
	if (Menu::Option("Stripey")) { GAMEPLAY::LOAD_CLOUD_HAT("Stripey", 1.9f); }
	if (Menu::Option("Wispy")) { GAMEPLAY::LOAD_CLOUD_HAT("Wispy", 1.9f); }
	if (Menu::Option("Reset Clouds")) { GAMEPLAY::_CLEAR_CLOUD_HAT(); }

}
void world_time()
{
	Menu::Title("");
	Menu::Subtitle("Time");
	Menu::Int("Hour", time_h, 0, 23);
	Menu::Int("Minutes", time_m, 0, 59);
	Menu::Int("Seconds", time_s, 0, 59);
	Menu::Toggle("Sync Time", Sync_Time);
	if (Menu::Option("Set Time")) { TIME::SET_CLOCK_TIME(time_h, time_m, time_s); }
	Menu::Break("Date");
	Menu::Int("Day", day, 0, 365);
	Menu::Int("Month", month, 0, 12);
	Menu::Int("Year", year, 0, 2067);
	if (Menu::Option("Set Time")) { TIME::SET_CLOCK_DATE(day, month, year); }

}
void misc_world_Sub()
{
	Menu::Title("");
	Menu::Subtitle("World/Misc Options");
	Menu::MenuOption("World Vehicle Options", worldvheoptions);
	Menu::MenuOption("World Speed", worldspeedchnage);
	Menu::MenuOption("Weather", worldwether);
	Menu::MenuOption("Cloud", Worldclouds);
	Menu::MenuOption("Gravity", worldgrav);
	Menu::MenuOption("Wind", WorldWind);
	Menu::MenuOption("Time", worldTime);
	Menu::MenuOption("Clear", Worldclear);
	Menu::MenuOption("Radio", worldradio);
	Menu::Toggle("EMP", emp);
	Menu::Toggle("Mady Pedy", madpeds);
	Menu::Toggle("World War 3", brecklose);
	Menu::Toggle("Blow up Ped Heads", kill);
	Menu::Toggle("Show Player coordinates", showcords);
	Menu::Toggle("3D Waypoint", threedwaypoint);
	Menu::Toggle("Flything", flything); 
}
