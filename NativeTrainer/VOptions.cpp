#include"MAIN.h"

bool riderC = -false;
bool invinveh = false;
bool driveonwater = false;
bool airdrive = false;
bool Rainbow = false;
bool Rainbowsmoke = false;
bool RainbowNeon = false;
bool flyingcar = false;
bool nowheels = false;
bool autofix = false;
bool RainbowPlate = false;
bool Hook, Hook_On = false;
bool glue = false;
bool carjump = false;
bool superkarmode = false;
bool inv = false;
bool alpha = false;
bool vLASER, vVALKYRIE, vFLAREGUN, vENEMY_LASER, vTURRET_INSURGENT, vTURRET_TECHNICAL, vAIRSTRIKE_ROCKET, vSTUN, vFIREWORK, vSNOWBALL, vBALLss, vFLAREee = false;
float vybullet_speed;
int vybullet_damage;
int CARGOBOB_HOOK = 0;
int CARGOBOB_MAGNET = 1;
int Alpha = 255;
bool heavy_mass = false;
bool DeleteBumper = false;
bool dritlevel = false;
float Drit = 0.0;
void vehguns()
{




}
std::string plateSymbols[35] = {
	"a", "b", "c", "d", "e", "f",
	"g", "h", "i", "j", "k", "l",
	"m", "n", "o", "p", "q",
	"r", "s", "t", "u", "v",
	"w", "x", "y", "z", "1",
	"2", "3", "4", "5", "6", "7",
	"8", "9",
};
bool RequestNetworkControl(uint vehID)
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

void SpawnVehboo(char* toSpawn)
{
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z + 100, heading, true, true);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 0, 0);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 0, 0, 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		ENTITY::_SET_ENTITY_REGISTER(veh, true);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}


Vector3 CombineVector(float x, float y, float z)
{
	Vector3 returnVector;
	returnVector.x = x;
	returnVector.y = y;
	returnVector.z = z;
	return returnVector;
}
Object Create_Obj(char* ObjectName, Vector3 Coordinates)
{
	Object returnObj;
	Hash ObjectHash = GAMEPLAY::GET_HASH_KEY(ObjectName);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash))
	{
		if (STREAMING::IS_MODEL_VALID(ObjectHash))
		{
			STREAMING::REQUEST_MODEL(ObjectHash);
			if (STREAMING::HAS_MODEL_LOADED(ObjectHash))
			{
				returnObj = OBJECT::CREATE_OBJECT(ObjectHash, Coordinates.x, Coordinates.y, Coordinates.z, 1, 1, 0);
			}
			else
			{
				returnObj = NULL;
			}
		}
	}
}

void Vehicle_Gun_Menu(char* boonigga, int Damage, float bulletspeed)
{

	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY(boonigga);
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			Damage, 1, weaponAssetRocket, playerPed, 1, 0, bulletspeed);

	}
}
bool RequestNetworkControlofcar(uint vehID)
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
int r = 255, g = 0, bb = 0;
void RGBFade()
{
	if (r > 0 && bb == 0) {
		r--;
		g++;
	}
	if (g > 0 && r == 0) {
		g--;
		bb++;
	}
	if (bb > 0 && g == 0) {
		r++;
		bb--;
	}
}
bool mynigga = false;
bool aidriver = false;
bool coll = true;
int drivingMode = Normal;
float aispeed = 40.0f;
void vehfunctions()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	if (!coll)
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Ped playerPed = PLAYER::PLAYER_PED_ID();


		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle* vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		//boo
		VEHICLE::SET_VEHICLE_FRICTION_OVERRIDE(veh, 100.0f);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(playerPed, 1);
		PED::SET_PED_CONFIG_FLAG(playerPed, 32, false);
		if (VEHICLE::_IS_VEHICLE_DAMAGED(veh))
			VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(playerPed));
		float speed = ENTITY::GET_ENTITY_SPEED(veh);
		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != veh)
			{
				RequestControlOfEnt(vehs[OffsetID]);
				ENTITY::SET_ENTITY_NO_COLLISION_ENTITY(vehs[OffsetID], veh, 1);

			}
		}

	}
	if (vFLAREGUN) { Vehicle_Gun_Menu("WEAPON_FLAREGUN", vybullet_damage, vybullet_speed); }
	if (vSTUN) { Vehicle_Gun_Menu("WEAPON_STUNGUN", vybullet_damage, vybullet_speed); }
	if (vAIRSTRIKE_ROCKET) { Vehicle_Gun_Menu("WEAPON_AIRSTRIKE_ROCKET", vybullet_damage, vybullet_speed); }
	if (vLASER) { Vehicle_Gun_Menu("VEHICLE_WEAPON_PLAYER_LASER", vybullet_damage, vybullet_speed); }
	if (vVALKYRIE) { Vehicle_Gun_Menu("VEHICLE_WEAPON_NOSE_TURRET_VALKYRIE", vybullet_damage, vybullet_speed); }
	if (vTURRET_INSURGENT) { Vehicle_Gun_Menu("VEHICLE_WEAPON_TURRET_INSURGENT", vybullet_damage, vybullet_speed); }
	if (vTURRET_TECHNICAL) { Vehicle_Gun_Menu("VEHICLE_WEAPON_TURRET_TECHNICAL", vybullet_damage, vybullet_speed); }
	if (vFLAREee) { Vehicle_Gun_Menu("WEAPON_FLARE", vybullet_damage, vybullet_speed); }
	if (vBALLss) { Vehicle_Gun_Menu("WEAPON_BALL", vybullet_damage, vybullet_speed); }
	if (vSNOWBALL) { Vehicle_Gun_Menu("WEAPON_SNOWBALL", vybullet_damage, vybullet_speed); }
	if (vFIREWORK) { Vehicle_Gun_Menu("WEAPON_FIREWORK", vybullet_damage, vybullet_speed); }

	//if (flyingcar)
	//{
	//	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	//	{
	//		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	//		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("W Forward A Left D Right");
	//		UI::_DRAW_NOTIFICATION(2000, 1);
	//		int Vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	//		ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
	//		if (CONTROLS::IS_CONTROL_PRESSED(2, 67) == true) //Forward
	//		{
	//			float Speed = ENTITY::GET_ENTITY_SPEED(Vehid) + 0.5;
	//			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Vehid, 25);

	//		}

	//		if ((CONTROLS::IS_CONTROL_PRESSED(2, 196) == true) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Left
	//		{
	//			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
	//			Rot.z = Rot.z + 1.0;
	//			ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
	//		}

	//		if ((CONTROLS::IS_CONTROL_PRESSED(2, 197) == true) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Right
	//		{
	//			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
	//			Rot.z = Rot.z - 1.0;
	//			ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
	//		}
	//	}

	//}

	if (Rainbow)
	{
		RGBFade();
		DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, r, g, bb);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, r, g, bb);
		}
	}
	if (Rainbowsmoke)
	{
		RGBFade();
		DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, r, g, bb);
		}
	}
	if (RainbowNeon)
	{
		LSC::Neon, LSC::Neonl, LSC::Neonf, LSC::Neonr, LSC::Neonrr = true;
		RGBFade();
		DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			if (VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 0) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 2) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 3))
			{
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, r, g, bb);
			}
			else
			{
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, r, g, bb);
			}
		}
	}
	float Normal = 1.0225;
	float Down = -1.60;
	float Up = +0.40;
	float Walking = 50.0;
	if (airdrive)
	{


		Hash prop = 3665231470;
		Player playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Vector3 PlayerCoord = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		Object DriveAirObject;
		float zPlane;
		spawnobject(prop, DriveAirObject, PlayerCoord);
		if ((!ENTITY::DOES_ENTITY_EXIST(DriveAirObject)))
		{
			spawnobject(prop, DriveAirObject, PlayerCoord);
			//ENTITY::SET_ENTITY_ROTATION(DriveAirObject, 90, 0, 0, 2, true);
			//ENTITY::SET_ENTITY_VISIBLE(DriveAirObject, 0, true);
		}
		else if ((ENTITY::DOES_ENTITY_EXIST(DriveAirObject)))
		{

			ENTITY::FREEZE_ENTITY_POSITION(DriveAirObject, 1);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Q to go up and E down");
			UI::_DRAW_NOTIFICATION(2000, 1);

			if (GetAsyncKeyState(0x45) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_SCRIPT_LS)))      //Down E and L3          
			{
				zPlane = PlayerCoord.z - Down;
			}
			else if (GetAsyncKeyState(0x51) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_SCRIPT_RS)))      //Up Q and R3  
			{
				zPlane = PlayerCoord.z - Up;
			}
			else                                              //Normal
			{
				zPlane = PlayerCoord.z - Normal;
			}

			Vector3 Coord = CombineVector(PlayerCoord.x, PlayerCoord.y, zPlane);
			ENTITY::SET_ENTITY_COORDS(DriveAirObject, Coord.x, Coord.y, Coord.z - 3, 1, 0, 0, 1);
		}


	}


	if (driveonwater)
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
		float height = 0;
		WATER::_SET_CURRENT_INTENSITY(height);
		if ((!(VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)))) && WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) {
			Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(container) && height > -50.0f) {
				Vector3 pRot = ENTITY::GET_ENTITY_ROTATION(playerPed, 0);
				if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 1)) pRot = ENTITY::GET_ENTITY_ROTATION(veh, 0);
				RequestControlOfEnt(container);
				ENTITY::SET_ENTITY_COORDS(container, pos.x, pos.y, height - 1.5f, 0, 0, 0, 1);
				ENTITY::SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
				Vector3 containerCoords = ENTITY::GET_ENTITY_COORDS(container, 1);
				if (pos.z < containerCoords.z) {
					if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {
						ENTITY::SET_ENTITY_COORDS(playerPed, pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
					}
					else {
						RequestControlOfEnt(veh);
						Vector3 vehc = ENTITY::GET_ENTITY_COORDS(veh, 1);
						ENTITY::SET_ENTITY_COORDS(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
					}
				}
			}
			else {
				Hash model = GAMEPLAY::GET_HASH_KEY("prop_container_ld2");
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				container = OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, 1, 1, 0);
				RequestControlOfEnt(container);
				ENTITY::FREEZE_ENTITY_POSITION(container, 1);
				ENTITY::SET_ENTITY_ALPHA(container, 0, 1);
				ENTITY::SET_ENTITY_VISIBLE(container, 0, false);
			}
		}
		else {
			Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(container)) {
				RequestControlOfEnt(container);
				ENTITY::SET_ENTITY_COORDS(container, 0, 0, -1000.0f, 0, 0, 0, 1);
				WAIT(10);
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
				ENTITY::DELETE_ENTITY(&container);
				WATER::_RESET_CURRENT_INTENSITY();
			}
		}
	}
	if (invinveh)
	{
		Player player = PLAYER::PLAYER_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			ENTITY::SET_ENTITY_INVINCIBLE(veh, TRUE);
			ENTITY::SET_ENTITY_PROOFS(veh, 1, 1, 1, 1, 1, 1, 1, 1);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 0);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(veh, 0);
		}
	}
	else
	{

	}
	if (riderC)
	{
		static Object container;
		auto selfVeh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		Vector3 min, max;
		Vector3 cmin, cmax;
		auto c = ENTITY::GET_ENTITY_COORDS(selfVeh, 1);
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(selfVeh), &min, &max);
		GAMEPLAY::GET_MODEL_DIMENSIONS($("prop_container_ld2"), &cmin, &cmax);

		if (!PED::IS_PED_ON_ANY_BIKE(PLAYER::PLAYER_PED_ID())) {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				notifyBottom("~r~Container rider requires a bike.");
				return;
			}
		}

		if (!STREAMING::HAS_MODEL_LOADED($("prop_container_ld2")))
			STREAMING::REQUEST_MODEL($("prop_container_ld2"));

		if (!ENTITY::DOES_ENTITY_EXIST(container) || !VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(selfVeh)) {
			static auto tickeer = GetTickCount();
			if ((GetTickCount() - tickeer) >= 1000) {
				if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_VEH_FLY_PITCH_UP_ONLY)) {
					tickeer = GetTickCount();
					ENTITY::APPLY_FORCE_TO_ENTITY(selfVeh, 0, 0, 0, 1.5, 0, 0, 0, 0, 1, 1, 1, 0, 1);
				}
			}
			static auto ticker = GetTickCount();
			if (ENTITY::DOES_ENTITY_EXIST(container)) {
				RequestControlOfEnt(container);
				ENTITY::SET_ENTITY_COORDS(container, 0.f, 0.f, 0.f, 1, 1, 1, 0);
				ENTITY::DELETE_ENTITY(&container);
				OBJECT::DELETE_OBJECT(&container);
			}
			container = OBJECT::CREATE_OBJECT($("prop_container_ld2"), c.x, c.y, c.z - ((max.z / 2) + cmax.z), 1, 1, 0);
			ENTITY::SET_ENTITY_ROTATION(container, ENTITY::GET_ENTITY_PITCH(selfVeh), 0.f, ENTITY::GET_ENTITY_HEADING(selfVeh), 0, 0);
		}
	}
	else
	{

	}
	if (nowheels)
	{
		Player player = PLAYER::PLAYER_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);

		VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, DBL_MAX * DBL_MAX);//max
		WAIT(100);
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, DBL_MAX * DBL_MAX);//max
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, DBL_MAX * DBL_MAX);//max
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, 2, 0, 0, 0, 1, false, true, true, true, true);
		nowheels = false;

	}
	else
	{
		Player player = PLAYER::PLAYER_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, 1.0);
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, 1.0);

	}
	if (autofix)
	{
		Player player = PLAYER::PLAYER_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		if (VEHICLE::_IS_VEHICLE_DAMAGED(veh))
		{
			VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(playerPed));
		}

	}
	if (RainbowPlate)
	{
		Player player = PLAYER::PLAYER_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);

		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			std::string textInput = plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35] + plateSymbols[rand() % 35];
			char* plateText = (strcpy((char*)malloc(textInput.length() + 1), textInput.c_str()));
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(playerPed, 0), plateText);
		}
	}
	if (Hook)
	{

		VEHICLE::CREATE_PICK_UP_ROPE_FOR_CARGOBOB(veh, CARGOBOB_MAGNET);
	}
	else
	{

		VEHICLE::CREATE_PICK_UP_ROPE_FOR_CARGOBOB(veh, CARGOBOB_HOOK);
	}
	if (Hook_On)
	{

		VEHICLE::_SET_CARGOBOB_PICKUP_MAGNET_ACTIVE(veh, true);

	}
	else
	{


		VEHICLE::_SET_CARGOBOB_PICKUP_MAGNET_ACTIVE(veh, false);

	}
	if (glue)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			int myVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(myVehicle);
		}
	}
	if (carjump)
	{
		if (GetAsyncKeyState(VK_SPACE) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_ACCEPT)))
		{
			int ped = PLAYER::PLAYER_PED_ID();
			int veh = PED::GET_VEHICLE_PED_IS_IN(ped, true);
			if (PED::IS_PED_IN_VEHICLE(ped, veh, true))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, 3, 0, 0, 0, 1, false, true, true, true, true);
				notifyMap("Saace ~r~or A To Use Jump(A/X)");

			}
		}
	}
	if (superkarmode)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh))
		{
			notifyMap("Use Driving Any Controls and Handbrake");
			if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_VEH_ACCELERATE))
			{
				AUDIO::SET_VEHICLE_BOOST_ACTIVE(veh, 1);
				AUDIO::SET_VEHICLE_BOOST_ACTIVE(veh, 0);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, ENTITY::GET_ENTITY_SPEED_VECTOR(veh, true).y + 0.46f);
				//_START_SCREEN_EFFECT("RaceTurbo", 0, 0);
			}
			if (CONTROLS::IS_CONTROL_JUST_PRESSED(2, INPUT_VEH_BRAKE))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 0.0f);
			}
			else if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_VEH_BRAKE))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0, -0.4, 0.0, 0.0, 0.0, 0.0, 0, 1, 1, 1, 0, 1);
				//SET_VEHICLE_FORWARD_SPEED(g_myVeh, GET_ENTITY_SPEED(g_myVeh) - 0.46f);
				//_START_SCREEN_EFFECT("FocusOut", 0, 0);
			}
		}
	}
	if (inv)
	{

		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		RequestNetworkControl(VehID);
		ENTITY::SET_ENTITY_ALPHA(VehID, Alpha, false);

	}
	if (alpha)
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		RequestNetworkControl(VehID);
		ENTITY::SET_ENTITY_ALPHA(VehID, Alpha, false);
	}
	else
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		RequestNetworkControl(VehID);
		ENTITY::SET_ENTITY_ALPHA(VehID, 255, false);

	}
	if (alpha)
	{
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		RequestNetworkControl(VehID);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(VehID, dritlevel);
	}
	else
	{


	}

	if (heavy_mass)
	{

		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Ped playerPed = PLAYER::PLAYER_PED_ID();

		VEHICLE::SET_VEHICLE_FRICTION_OVERRIDE(veh, 100.0f);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(playerPed, 1);
		PED::SET_PED_CONFIG_FLAG(playerPed, 32, false);
		if (VEHICLE::_IS_VEHICLE_DAMAGED(veh))
			VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(playerPed));
		float speed = ENTITY::GET_ENTITY_SPEED(veh);
		if (speed < 0.5f)
			return;

		float pushForce = speed * 3.5f; // More speed === More bleed

		Entity touchy = ENTITY::IS_ENTITY_TOUCHING_ENTITY(veh, nearbyveh());
		if (touchy)
		{
			Vector3 dir = ENTITY::GET_COLLISION_NORMAL_OF_LAST_HIT_FOR_ENTITY(nearbyveh());
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
			RequestControlOfEnt(nearbyveh());
			ApplyForceToEntity(nearbyveh(), dir.x * pushForce, dir.y * pushForce, dir.z * pushForce);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, speed);

		}
	}
	if (DeleteBumper)
	{

		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		//boo
		VEHICLE::SET_VEHICLE_FRICTION_OVERRIDE(veh, 100.0f);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(playerPed, 1);
		PED::SET_PED_CONFIG_FLAG(playerPed, 32, false);
		if (VEHICLE::_IS_VEHICLE_DAMAGED(veh))
			VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(playerPed));

		Entity touchy = ENTITY::IS_ENTITY_TOUCHING_ENTITY(veh, nearbyveh());
		if (touchy)
		{
			RequestControlOfEnt(nearbyveh());
			ENTITY::SET_ENTITY_COORDS(nearbyveh(), 6400.f, 6400.f, 0.f, false, false, false, false);
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		}

	}
}

void AI_Drving()
{

	Menu::Title("");
	Menu::Subtitle("AI Driving");
	Vector3 des = get_blip_marker();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Hash vehicleModel = ENTITY::GET_ENTITY_MODEL(veh);
	if (Menu::Option("AI Driver"))
	{
		aidriver = true;
		if (waypoint)
		{
			AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(playerPed, veh, des.x,
				des.y, des.z, aispeed, drivingMode, 6);
		}
		else
		{
			notifyMap("please set a waypoint to direct the driver");

		}
		notifyMap("AI Driver on");
	}
	if (aidriver)
		if (Menu::Option("Turn off AI"))
		{

			AI::CLEAR_PED_TASKS(playerPed);
			notifyMap("AI Driver off");
			aidriver = false;
		}
	Menu::Float("AI Speed", aispeed, 0.0f, 99999.99f);
	if (Menu::Option("Normal")) {
		drivingMode = Normal;
		AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(playerPed, veh, des.x,
			des.y, des.z, aispeed, drivingMode, 6);
	}
	if (Menu::Option("Ignore Lights")) {
		drivingMode = IgnoreLights;
		AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(playerPed, veh, des.x,
			des.y, des.z, aispeed, drivingMode, 6);
	}
	if (Menu::Option("Sometimes Overtake Traffic")) {
		drivingMode = SometimesOvertakeTraffic;
		AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(playerPed, veh, des.x,
			des.y, des.z, aispeed, drivingMode, 6);
	}
	if (Menu::Option("Rushed")) {
		drivingMode = Rushed;
		AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(playerPed, veh, des.x,
			des.y, des.z, aispeed, drivingMode, 6);
	}
	if (Menu::Option("Avoid Traffic")) {
		drivingMode = AvoidTraffic;
		AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(playerPed, veh, des.x,
			des.y, des.z, aispeed, drivingMode, 6);
	}
	if (Menu::Option("Avoid Traffic A Lot")) {
		drivingMode = AvoidTrafficExtremely;
		AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(playerPed, veh, des.x,
			des.y, des.z, aispeed, drivingMode, 6);
	}

}
int pos;
int opendoor, closedoor;
int doorlocking;
int doorIndex_break;

std::vector<std::string> stu
{
	{ "Nothing" },
	{ "Close" },
	{ "Open" },
	{ "Door Locks" },
	{ "Break Doors" },
};

std::vector<std::string> DoorLockstu
{
	"Unlocked",
	"Locked",
	"LockedForPlayer",
	"ChildLock",
	"Unknown 5",
	"Unknown 6",
	"CanBeBrokenInto",
	"CanBeBrokenIntoPersist",
	"Unknown 9",
	"CannotBeTriedToBeEntered"
};
/*
0 = Front Left Door
1 = Front Right Door
2 = Back Left Door
3 = Back Right Door
4 = Hood
5 = Trunk
6 = Trunk2
*/
std::vector<std::string> Doors
{
	{ "Front Left Door" },
	{ "Front Right Door" },
	{ "Back Left Door" },
	{ "Back Right Door" },
	{ "Hood" },
	{ "Trunk" },
	{ "Trunk2" },
};
//int driverdrive;
//if (driverdrive == 0) {
//	drivingMode = Normal;
//}
//if (driverdrive == 1) {
//	drivingMode = IgnoreLights;
//}
//if (driverdrive == 2) {
//	drivingMode = SometimesOvertakeTraffic;
//}
//if (driverdrive == 3) {
//	drivingMode = Rushed;
//}
//if (driverdrive == 4) {
//	drivingMode = AvoidTraffic;
//}
//if (driverdrive == 5) {
//	drivingMode = AvoidTrafficExtremely;
//}
//std::vector<std::string> Driveingtypes
//{
//	{ "Normal" },
//	{ "Ignore Lights" },
//	{ "Sometimes Overtake Traffic" },
//	{ "Rushed" },
//	{ "Avoid Traffic" },
//	{ "Avoid Traffic A Lot" },
//
//};
bool aion = false;
void Veh_key()
{
	Menu::Title("");
	Menu::Subtitle("Vehicle Key");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle oldveh = PED::GET_VEHICLE_PED_IS_IN(playerPed, true);
	Vector3 me = Get_Position(playerPed);
	Menu::StringVector("Door Status: ", stu, pos);
	if (pos == 1)
	{
		if (Menu::StringVector("Close Doors: ", Doors, closedoor))
			if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed)
				VEHICLE::SET_VEHICLE_DOOR_SHUT(oldveh, closedoor, false);
	}
	if (pos == 2)
	{
		if (Menu::StringVector("Open Doors: ", Doors, opendoor))
			if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed)
				VEHICLE::SET_VEHICLE_DOOR_OPEN(oldveh, opendoor, false, false);
	}
	if (pos == 3)
	{
		if (Menu::StringVector("Door Lock: ", DoorLockstu, doorlocking))
			if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed)
				VEHICLE::SET_VEHICLE_DOORS_LOCKED(oldveh, doorlocking);
	}
	if (pos == 4)
	{
		if (Menu::StringVector("Break Doors: ", Doors, doorIndex_break))
			if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed)
				VEHICLE::SET_VEHICLE_DOOR_BROKEN(oldveh, doorIndex_break, true);
	}
	if (Menu::Option("Bring Car to me(AI)"))
	{
		Ped Driver = PED::CREATE_RANDOM_PED_AS_DRIVER(oldveh, false);
		Blip blip = set_blip(oldveh, 255, 30, true);
		AI::TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Driver, true);
		PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Driver, 1);
		PED::SET_PED_FLEE_ATTRIBUTES(Driver, 0, 0);
		PED::SET_PED_COMBAT_ATTRIBUTES(Driver, 17, 1);
		set_entity_alpha(Driver, 0);
		AI::TASK_VEHICLE_DRIVE_TO_COORD(Driver, oldveh, me.x, me.y, me.z, 40, 1, ENTITY::GET_ENTITY_MODEL(oldveh), Rushed, 20, -1);
		blip;
		notifyBottom("AI: On my way");
		aion = true;
	}
	/*if (is_entity_there(Driver, me) && aion)
	{
		aion = false;
		UI::SET_BLIP_ALPHA(blip, 0);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(Driver);
		PED::DELETE_PED(&Driver);
		notifyMap("AI: Hello, I'm Here.");
	}*/
	Menu::Break("beta");
	if (Menu::Option("Turn On Engine"))
		VEHICLE::SET_VEHICLE_ENGINE_ON(oldveh, true, true, false);
	if (Menu::Option("Lights On"))
		VEHICLE::SET_VEHICLE_LIGHTS(oldveh, 0);
	if (Menu::Option("Indicator"))
	{
		VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(oldveh, 0, true);
		VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(oldveh, 1, true);
	}
	if (Menu::Option("Hydraulics"))
	{
		int Trick = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 1);
		if (Trick == 0)	ApplyForceToEntity(oldveh, 0, 0, 1.0f);
		else ENTITY::APPLY_FORCE_TO_ENTITY(oldveh, 1, 0, 0, 10.0f, 20.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
	}
}
void menu_if_veh()
{

	if (Menu::Option("Fix Vehicle"))
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);

		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		VEHICLE::SET_VEHICLE_FIXED(veh);
	}
	if (Menu::Option("Add Ramp")) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vector3 Him = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true);
			STREAMING::REQUEST_MODEL(0xB157C9E4);
			if (STREAMING::HAS_MODEL_LOADED(0xB157C9E4))
			{
				Entity My_Objects = OBJECT::CREATE_OBJECT(0xB157C9E4, Him.x, Him.y, Him.z, 1, 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(My_Objects))
				{
					ENTITY::SET_ENTITY_COLLISION(My_Objects, true, true);
					ENTITY::SET_ENTITY_ALPHA(My_Objects, 120, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(My_Objects, VehicleID, 0, 0, 6.3, -0.3, 13.5, 0, 177.5, 0, 0, true, 0, 2, 1);
				}
			}
		}
		else {
			notifyMap("~r~Get in a vehicle");
		}
	}
	if (Menu::Option("Spawn Chauffer")) {
		int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
		if (UI::DOES_BLIP_EXIST(WaypointHandle))
		{
			Vector3 waypoint1 = UI::GET_BLIP_COORDS(WaypointHandle);
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("STRETCH"));
			while (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("STRETCH"))) WAIT(0);
			Vector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0);
			Vehicle veh = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY("STRETCH"), pos.x, pos.y, pos.z, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 1, 1);
			if (veh != 0)
			{
				Ped Driver = PED::CREATE_RANDOM_PED_AS_DRIVER(veh, false);
				AI::TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Driver, true);
				PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Driver, 1);
				PED::SET_PED_FLEE_ATTRIBUTES(Driver, 0, 0);
				PED::SET_PED_COMBAT_ATTRIBUTES(Driver, 17, 1);
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, 4);
				AI::TASK_VEHICLE_DRIVE_TO_COORD(Driver, veh, waypoint1.x, waypoint1.y, waypoint1.z, 40, 1, ENTITY::GET_ENTITY_MODEL(veh), 7, 6, -1);
				char* plateText = ("   WIND   ");
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, plateText);
				notifyMap("~g~Chauffer Spawned!");
			}
		}
		else
		{
			notifyMap("please set a waypoint to direct the driver");

		}
	}
	if (Menu::Option("Engine ~g~ON"))
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, false);
	}

}
void PV_()
{
	Ped  playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle vehlastused = PED::GET_VEHICLE_PED_IS_IN(playerPed, true);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int colour = rndInt(1, 40);
	Menu::Title("");
	Menu::Subtitle("PV Options");
	if (Menu::Option("Remember Vehicle"))
	{
		set_blip(veh, 255, colour, true);

	}
	if (Menu::Option("Teleport to Last Vehicle"))
	{
		Vector3 vehco = ENTITY::GET_ENTITY_COORDS(vehlastused, false);
		teleport_to_coords(playerPed, vehco);
	}
	if (Menu::Option("Teleport Last Vehicle to Self"))
	{
		Vector3 player = ENTITY::GET_ENTITY_COORDS(playerPed, false);
		teleport_to_coords(vehlastused, player);
	}
	if (Menu::Option("Teleport into Last Vehicle"))
	{
		PED::SET_PED_INTO_VEHICLE(playerPed, vehlastused, -1);
	}

}



void vehgunmenu()
{

	Menu::Title("");
	Menu::Subtitle("Vehicle Gun Menu");
	//Menu::Toggle("Green Laser", vLASER);//speed
	//Menu::Toggle("Red Laser", vENEMY_LASER);//speed
	Menu::Toggle("Airstrike Rocket", vAIRSTRIKE_ROCKET);//speed
	Menu::Toggle("Tazer", vSTUN);//not speed
	Menu::Toggle("Firework", vFIREWORK);//speed
	Menu::Toggle("Snowball", vSNOWBALL);//speed
	Menu::Toggle("Ball", vBALLss);//speed
	//Menu::Toggle("Flare 2", vFLAREee);//not speed
	Menu::Toggle("Flare Gun", vFLAREGUN);//not speed
	Menu::Toggle("Valkyrie Turret", vVALKYRIE);//not speed
	Menu::Toggle("Insurgent Turret", vTURRET_INSURGENT);//not speed
	Menu::Toggle("Technical Turret", vTURRET_TECHNICAL);//not speed
	notifyBottom("Use Num Plus ~g~+");
	Menu::Int("Bullet Damage", vybullet_damage, -1, 999999999);
	Menu::Float("Bullet Speed(Only for Some Bullets)", vybullet_speed, -9.0f, 999999999.999999f);

}

void Veh_control()
{


}

float mag;
void carbob_options()
{
	Menu::Title("");
	Menu::Subtitle("Cargobob");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	if (Menu::Option("Spawn Cargobob")) { SpawnVehboo("CARGOBOB"); }
	Menu::Toggle("Cargobob Hook", Hook);
	Menu::Toggle("Active Magnet", Hook_On);
	Menu::Float("Pick Up Strength", mag, 0.0, 9999.99);
	VEHICLE::_SET_CARGOBOB_PICKUP_MAGNET_STRENGTH(veh, mag);
}


void vehicleStuff()
{

	Menu::Title("");
	Menu::Subtitle("Vehicle Menu");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Menu::MenuOption("Spawner", vehspawnersub);
	Menu::MenuOption("Avi's Custom", LSCWW);
	Menu::MenuOption("Vehicle Gun Menu", guns_for_veh);
	Menu::MenuOption("Cargobob Settings", cargobobcase);
	Menu::MenuOption("AI Driving", AIDrving);
	Menu::MenuOption("Player Vehicle", PV);
	Menu::MenuOption("Vehicle Key", vehkey);
	menu_if_veh();
	Menu::Toggle("Auto Fix", autofix);
	Menu::Toggle("Invincible", invinveh);
	Menu::Toggle("Drit level", dritlevel);
	if (dritlevel) { Menu::Float("Custom Drit level", Drit, 0.1, 15.0); }
	Menu::Toggle("Alpha", alpha);
	if (alpha) { Menu::Int("Custom Alpha level", Alpha, 0, 255); }
	Menu::Toggle("Car Jump", carjump);
	Menu::Toggle("WWE Mode", heavy_mass);
	Menu::Toggle("Break Wheels", nowheels);
	Menu::Toggle("Vehicle on Vehicle Collision", coll);
	Menu::Toggle("Drive On Water", driveonwater);
	Menu::Toggle("Delete Bumper", DeleteBumper);
	Menu::Toggle("Super Car Mode", superkarmode);
	Menu::Toggle("Rainbow Colour", Rainbow);
	Menu::Toggle("Rainbow Neon", RainbowNeon);
	Menu::Toggle("Rainbow Plate", RainbowPlate);
	Menu::Toggle("Glue to Ground", glue);
	Menu::Toggle("Container Rider", riderC);
	//Menu::Toggle("Drive On Air (beta)", airdrive);
	//Menu::Toggle("Rainbow Smoke", Rainbowsmoke);
}
