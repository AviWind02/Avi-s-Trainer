#include "MAIN.h"

bool boomgun, soul_gun, Gravity, Ammoinf, Ammoexp, drivegun, RemoveObjects, rapidfire, onehit, rapidMultiplier, Weapon_bullets_options_booll, Flare, SuperPunch, Rainbowcamo, deletegun = false;
//bullet fx
bool LASER, VALKYRIE, FLAREGUN, ENEMY_LASER, TURRET_INSURGENT, TURRET_TECHNICAL, AIRSTRIKE_ROCKET, STUN, FIREWORK, SNOWBALL, BALLss, FLAREee = false;
bool pedtorgun = false;
bool DeleteGun = false;
bool Alpha2, bombushka2, CARGOPLANE2, BUS2, RHINO2, DUMP2, Custom2, lasteused = false;
bool Alpha, bombushka, CARGOPLANE, BUS, RHINO, DUMP, Custom = false;
bool gun1, gun2, gun3, gun4, gun5, gun6, gun7 = false;
bool clown = false;
char* Car;
char* car2;
bool cargo = false;
bool mindcontrol = false;
bool forcegun = false;
bool tpgun = false;
bool drawmark = true;
bool shootboom = false;
bool pedgun = false;
bool freezray = false;
bool gravygun = false;
bool ropegun = false;
bool gunon = true;
bool ihaveit = false;
bool attachgun = false;
bool foundentitiyone = false;
bool isped = false;
bool portalgun = false;
bool sitgun = false;
bool triggerbot = false;
bool aimbotfull = false;
bool aimbot = false;
bool lightgun = false;
bool laser = false;
bool gotem = false;
int redg = 255, greeng, blueg;
RGB colour = { redg, greeng, blueg };
float screenX, screenY;
float damageScale = 1000.0f;
bool rcgun = false;
Ped rcped;
bool rccheck = false;
bool rcghostgun = false;
Ped rcghostped;
bool rcghostcheck = false;
bool getplayerpos = false;
bool disgun = false;

Vector3 playerpos;
#define OFFSET_PLAYER					0x08
#define OFFSET_PLAYER_INFO				0x10B8	
#define OFFSET_PLAYER_INFO_FRAMEFLAGS	0x1F8
enum eFrameFlag : DWORD {
	ExplosiveAmmo = 1 << 11,
	FireAmmo = 1 << 12,
	ExplosiveMelee = 1 << 13,
	SuperJump = 1 << 14
};



bool RrequestNetworkControl(uint vehID)
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

static  float dist(Vector3 p1, Vector3 p2)
{
	float x = p1.x - p2.x;
	float y = p1.y - p2.y;
	float z = p1.z - p2.z;
	return SYSTEM::SQRT(x * x + y * y + z * z);
}

Vector3 addVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}
double DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}
Vector3 RotationToDirection(Vector3 rot) {
	double num = DegreeToRadian(rot.z);
	double num2 = DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;

}
Vector3 multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}

Vector3 rotDirection(Vector3* rot)
{
	float radianz = rot->z * 0.0174532924f;
	float radianx = rot->x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx));

	Vector3 dir;

	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);

	return dir;
}


int MultiplierShot;
int bullet_damage;
float bullet_speed;


void Shootthingsoutofgun(char* carhash)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Weapon myWeaponEntity = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
	Vector3 PlayerPos = Get_Position(playerPed);
	Vector3 gunpos = Get_Position(myWeaponEntity);
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);


	if (PED::IS_PED_SHOOTING(playerPed))
	{
		int Hashs = GAMEPLAY::GET_HASH_KEY(carhash);
		STREAMING::REQUEST_MODEL(Hashs);
		if (STREAMING::HAS_MODEL_LOADED(Hashs))
		{
			Vehicle veh = VEHICLE::CREATE_VEHICLE(Hashs, gunpos.x, gunpos.y + 5, gunpos.z, 0, 1, 0);
			set_entity_as_mission(veh, false);// user can shoot more(vehicles dspawn if false)
			ENTITY::SET_ENTITY_NO_COLLISION_ENTITY(veh, playerPed, 1);// so you dont die/get hit
			ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, dir.x * 1000.0f, dir.y * 1000.0f, dir.z * 1000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 700.0);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hashs);

		}
	}

}

void Weapon_bullets_options(char* boonigga, int Damage, float bulletspeed)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	float startDistance = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 0.25;
	endDistance += 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && PED::IS_PED_SHOOTING(playerPed))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY(boonigga);
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, Damage, 1, weaponAssetRocket, playerPed, 1, 0, bulletspeed);
	}
}//
void Imapct_Bull(Hash bull)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_SHOOTING(playerPed))
	{
		//Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 PlayerPos;
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &PlayerPos);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(PlayerPos.x, PlayerPos.y, PlayerPos.z,
			0, 0, 0,
			250, 1, bull, playerPed, 1, 0, -1.0);

	}
}
void Imapct_Shot(char* VEHICLE)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_SHOOTING(playerPed))
	{
		Vector3 PlayerPos;
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &PlayerPos);
		int Hashs = GAMEPLAY::GET_HASH_KEY(VEHICLE);
		STREAMING::REQUEST_MODEL(Hashs);
		if (STREAMING::HAS_MODEL_LOADED(Hashs))
		{
			VEHICLE::CREATE_VEHICLE(Hashs, PlayerPos.x, PlayerPos.y, PlayerPos.z, 0.0f, 1, 0);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hashs);
		}
	}
}
bool shootthingy = false;
Vector3 GetCoordsInfrontOfCam(float distance) //GetCoordAimingAhead
{
	Vector3 GameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	Vector3 GameplayCamCoord = CAM::GET_GAMEPLAY_CAM_COORD();

	float tan = cos(GameplayCamRot.y) * distance;
	float xPlane = (sin(GameplayCamRot.z * -1.0f) * tan) + GameplayCamCoord.y;
	float yPlane = (cos(GameplayCamRot.z * -1.0f) * tan) + GameplayCamCoord.y;
	float zPlane = (sin(GameplayCamRot.y) * distance) + GameplayCamCoord.z;

	Vector3 Output;
	Output.x = xPlane;
	Output.y = yPlane;
	Output.z = zPlane;

	return Output;
}

void gunsmenu()
{

	Entity EntityTarget;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 5;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


	if (rcgun)
	{
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			getplayerpos = true;
			if (getplayerpos)
				playerpos = Get_Position(playerPed);
			getplayerpos = false;
			if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
			{

				GRAPHICS::SET_TIMECYCLE_MODIFIER("CAMERA_secuirity");
				rcped = PED::CREATE_RANDOM_PED(0, 0, 0);
				PED::SET_PED_INTO_VEHICLE(rcped, EntityTarget, -1);
				set_entity_alpha(rcped, 0);
				if (PED::IS_PED_IN_VEHICLE(rcped, EntityTarget, NULL))
				{
					PLAYER::CHANGE_PLAYER_PED(PLAYER::PLAYER_ID(), rcped, true, true);
					VEHICLE::SET_VEHICLE_DOORS_LOCKED(getvehpedisin(), 4);

				}
			}
		}
		rccheck = true;
	}
	else
	{

		Hash model = ENTITY::GET_ENTITY_MODEL(playerPed);
		if (rccheck)
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, playerpos.x, playerpos.y, playerpos.z, 0, 0, 1);
			GAMEPLAY::CLEAR_AREA_OF_PEDS(playerpos.x, playerpos.y, playerpos.z, 200, 0);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, playerpos.x, playerpos.y, playerpos.z, 0, 0, 1);
			GRAPHICS::SET_TIMECYCLE_MODIFIER("default");
			PED::DELETE_PED(&rcped);
			if (model != GAMEPLAY::GET_HASH_KEY("player_zero") &&
				model != GAMEPLAY::GET_HASH_KEY("player_one") &&
				model != GAMEPLAY::GET_HASH_KEY("player_two"))
			{
				notifyBottom("turning to ~g~normal~w~..");
				WAIT(1000);

				model = GAMEPLAY::GET_HASH_KEY("player_zero");
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model))
					WAIT(0);
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
				PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					WAIT(0);
			}
			rccheck = false;
		}
		
	}

	if (rcghostgun)
	{

		Entity EntityTarget;
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(playerPed, &EntityTarget))
		{
			if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
			{
				Ped Driver = PED::CREATE_RANDOM_PED_AS_DRIVER(EntityTarget, false);
				RequestControlOfEnt(EntityTarget);
				PED::SET_PED_INTO_VEHICLE(Driver, EntityTarget, -1);
				set_entity_alpha(Driver, 0);
			}
		}
	}
	if (disgun)
	{
		Entity EntityTarget;
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(playerPed, &EntityTarget))
		{
			RequestControlOfEnt(EntityTarget);

				ENTITY::SET_ENTITY_COORDS(EntityTarget, 0.f, 0.f, -10.f,
					true, true, true, false); 
				set_entity_pos_dead(EntityTarget, true);
		}
		if (ENTITY::IS_ENTITY_AT_COORD(EntityTarget, 0.f, 0.f, -10.f,
			100, 100, 100, true, false,
			1)) {
			Vector3 iCoord;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &iCoord))
			{
				ENTITY::SET_ENTITY_COORDS(EntityTarget, iCoord.x, iCoord.y, iCoord.z + 1, 0, 0, 1, 1);
				WAIT(0);

			}
		}
	}

	Player tempPed = PLAYER::PLAYER_ID();
	if (Gravity)
	{
		if (equippedWeapon == WeaponPistol)
		{
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
			{
				Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
				//PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
				{
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}

				RequestControlOfEnt(EntityTarget);

				if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget)) ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);
				//PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_ATTACK))
				{

					AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Foot_Swish", EntityTarget, "docks_heist_finale_2a_sounds", 0, 0);
					ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
					ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
					//Gravity = false;
					//ENTITY::DELETE_ENTITY(&EntityTarget);
					//PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				}
			}
		}
		/*if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			Gravity = true;
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
		}*/
		if (equippedWeapon != WeaponPistol && Gravity == true)
		{
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Equipe Pistol");
			UI::_DRAW_NOTIFICATION(2000, 1);
		}
	}

	if (ropegun)
	{
		ROPE::ROPE_LOAD_TEXTURES();
		Vector3 iCoord;
		Vector3 mycooords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_ID(), true);

		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &iCoord))
		{
			if (!ROPE::ROPE_ARE_TEXTURES_LOADED())
				ROPE::ROPE_LOAD_TEXTURES();
			Object ropy = ROPE::ADD_ROPE(iCoord.x, iCoord.y, iCoord.z, NULL, NULL,
				NULL, mycooords.y, 1, mycooords.y,
				1, 0, 0, 0, NULL,
				0, true, NULL);
			ROPE::ROPE_LOAD_TEXTURES();

			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
			{
				if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_ID()))
				{
					if (ENTITY::IS_ENTITY_A_PED(EntityTarget) || ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget)) {

						if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
						{
							EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
						}
						RequestControlOfEnt(EntityTarget);
						Vector3 EntityTargetCoords = ENTITY::GET_ENTITY_COORDS(EntityTarget, NULL);
						ROPE::ATTACH_ROPE_TO_ENTITY(ropy, EntityTarget, EntityTargetCoords.x, EntityTargetCoords.y,
							EntityTargetCoords.z, NULL);

					}
				}
			}
		}
	}
	if (laser)
	{
		GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_PED_ID());
	}
	if (Ammoinf)
	{
		Hash cur;
		if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &cur, 1))
		{
			if (WEAPON::IS_WEAPON_VALID(cur))
			{
				int maxAmmo;
				if (WEAPON::GET_MAX_AMMO(PLAYER::PLAYER_PED_ID(), cur, &maxAmmo))
				{
					WEAPON::SET_PED_AMMO(PLAYER::PLAYER_PED_ID(), cur, maxAmmo);

					maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, 1);
					if (maxAmmo > 0)
						WEAPON::SET_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, maxAmmo);
				}
			}
		}
	}
	if (Ammoexp)
	{
		//Imapct_Bull(VEHICLE_WEAPON_NOSE_TURRET_VALKYRIE);
		Vector3 blowimpact;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &blowimpact))
		{
			FIRE::ADD_EXPLOSION(blowimpact.x, blowimpact.y, blowimpact.z, ExplosionTypeStickyBomb, damageScale, true, false, NULL);
		}
	}
	if (rapidfire)
	{
		if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
			PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
			Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
			Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 1.0f)));
			Vector3 endCoords = addVector(startCoords, multiplyVector(gameplayCamDirection, 500.0f));
			Hash weaponhash;
			WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponhash, 1);
			if (CONTROLS::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
			}
		}
	}
	if (onehit)
	{
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			RequestControlOfEnt(EntityTarget);
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
			{

				if (ENTITY::IS_ENTITY_A_PED(EntityTarget)
					&& PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1)) {
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}
				VEHICLE::EXPLODE_VEHICLE(EntityTarget, true, false);
				VEHICLE::SET_VEHICLE_OUT_OF_CONTROL(EntityTarget, true, true);//idk
			}
		}
		PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 9999999.9999f);
		PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 9999999.9999f);
		PLAYER::SET_PLAYER_WEAPON_DEFENSE_MODIFIER(PLAYER::PLAYER_ID(), 9999999.9999f);
		PLAYER::SET_PLAYER_MELEE_WEAPON_DEFENSE_MODIFIER(PLAYER::PLAYER_ID(), 9999999.9999f);
	}
	if (SuperPunch)
	{
		GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_PED_ID());
		GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID());
	}
	if (Rainbowcamo)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		static LPCSTR weaponNames[] = {
			"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
			"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
			"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
			"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
			"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
			"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
			"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
			"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
			"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
			"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
			"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "", ""
		};
		for (int i = 0; i < sizeof(weaponNames) / sizeof(weaponNames[0]); i++)
		{
			if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY((char*)weaponNames[i]), 0))
			{
				WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, GAMEPLAY::GET_HASH_KEY((char*)weaponNames[i]), rand() % 8);
			}
		}
	}
	if (FLAREGUN) { Weapon_bullets_options("WEAPON_FLAREGUN", bullet_damage, bullet_speed); }
	if (STUN) { Weapon_bullets_options("WEAPON_STUNGUN", bullet_damage, bullet_speed); }
	if (AIRSTRIKE_ROCKET) { Weapon_bullets_options("WEAPON_AIRSTRIKE_ROCKET", bullet_damage, bullet_speed); }
	if (LASER) { Weapon_bullets_options("VEHICLE_WEAPON_PLAYER_LASER", bullet_damage, bullet_speed); }
	if (VALKYRIE) { Weapon_bullets_options("VEHICLE_WEAPON_NOSE_TURRET_VALKYRIE", bullet_damage, bullet_speed); }
	if (TURRET_INSURGENT) { Weapon_bullets_options("VEHICLE_WEAPON_TURRET_INSURGENT", bullet_damage, bullet_speed); }
	if (TURRET_TECHNICAL) { Weapon_bullets_options("VEHICLE_WEAPON_TURRET_TECHNICAL", bullet_damage, bullet_speed); }
	if (FLAREee) { Weapon_bullets_options("WEAPON_FLARE", bullet_damage, bullet_speed); }
	if (BALLss) { Weapon_bullets_options("WEAPON_BALL", bullet_damage, bullet_speed); }
	if (SNOWBALL) { Weapon_bullets_options("WEAPON_SNOWBALL", bullet_damage, bullet_speed); }
	if (FIREWORK) { Weapon_bullets_options("WEAPON_FIREWORK", bullet_damage, bullet_speed); }

	if (tpgun)
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		if (bPlayerExists && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 iCoord;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &iCoord))
			{
				ENTITY::SET_ENTITY_COORDS(playerPed, iCoord.x, iCoord.y, iCoord.z + 1, 0, 0, 1, 1);
				WAIT(0);

			}
		}
	}
	// Weapon List
	Hash weaponsList2[] = {
		0x92A27487, 0x958A4A8F, 0xF9E6AA4B, 0x84BD7BFD, 0xA2719263, 0x8BB05FD7, 0x440E4788, 0x4E875F73, 0xF9DCBF2D, 0xD8DF3C3C, 0x99B507EA, 0xDD5DF8D9, 0xDFE37640, 0x678B81B1, 0x19044EE0, 0xCD274149, 0x94117305, 0x3813FC08, // Melee
		0x1B06D571, 0xBFE256D4, 0x5EF9FEC4, 0x22D8FE39, 0x3656C8C1, 0x99AEEB3B, 0xBFD21232, 0x88374054, 0xD205520E, 0x83839C4, 0x47757124, 0xDC4DB296, 0xC1B3C3D1, 0xCB96392F, 0x97EA20B8, // Handguns
		0x13532244, 0x2BE6766B, 0x2BE6766B, 0xEFE7E2DF, 0x0A3D4D34, 0xDB1AA450, 0xBD248B55, // Submachine Guns
		0x1D073A89, 0x555AF99A, 0x7846A318, 0xE284C527, 0x9D61E50F, 0xA89CB99E, 0x3AABBBAA, 0xEF951FBB, 0x12E82D3D, // Shotguns
		0xBFEFFF6D, 0x394F415C, 0x83BF0278, 0xFAD1F1C9, 0xAF113F99, 0xC0A3098D, 0x969C3D67, 0x7F229F94, 0x84D6FAFD, 0x624FE830, // Assault Rifles
		0x9D07F764, 0x7FD62962, 0xDBBD7280, 0x61012683, // Light Machine Guns
		0x05FC3C11, 0x0C472FE2, 0xA914799, 0xC734385A, 0x6A6C02E0, // Sniper Rifles
		0xB1CA77B1, 0xA284510B, 0x4DD2DC56, 0x42BF8A85, 0x7F7497E5, 0x6D544C99, 0x63AB0442, 0x0781FE4A, // Heavy Weapons
		0x93E220BD, 0xA0973D5E, 0x24B17070, 0x2C3731D9, 0xAB564B93, 0x787F0BB, 0xBA45E8B8, 0x23C9F95C, 0xFDBC8A50, 0x497FACC3, // Throwables
		0x34A67B97, 0xFBAB5776, 0x060EC506, // Miscellaneous
		0xAF3696A1, 0x476BF155, 0xB62D1F67	 // 1.46
	};

	if (pedgun) {

		Entity EntityTarget;

		if (equippedWeapon == WeaponCombatPistol)
		{
			CONTROLS::DISABLE_CONTROL_ACTION(0, INPUT_ATTACK, TRUE);
			CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_ATTACK2, TRUE);
			CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_ATTACK, TRUE);
			CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_ATTACK2, TRUE);
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
			{
				if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_ATTACK))
				{
					RequestControlOfEnt(EntityTarget);
					PLAYER::CHANGE_PLAYER_PED(PLAYER::PLAYER_ID(), EntityTarget, true, true);
					check_player_model();
				}
			}
		}
		else
			notifyBottom("~bold~Equip ~bold~CombatPistol");
		//WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), WEAPON_COMBATPISTOL, 9999, false, true); i mean like i dont need this here 
	}

	if (freezray)
	{

		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
			{
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget)
					&& PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1)) {
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}
				RequestControlOfEnt(EntityTarget);
				ENTITY::FREEZE_ENTITY_POSITION(EntityTarget, true);
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget))
					AI::CLEAR_PED_TASKS_IMMEDIATELY(EntityTarget);

			}
			else if (ENTITY::IS_ENTITY_A_PED(EntityTarget))
			{

				CONTROLS::DISABLE_CONTROL_ACTION(0, INPUT_ATTACK, TRUE);
				CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_ATTACK2, TRUE);
				CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_ATTACK, TRUE);
				CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_ATTACK2, TRUE);
				if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_ATTACK))
				{

					if (ENTITY::IS_ENTITY_A_PED(EntityTarget)
						&& PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1)) {
						EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
					}
					RequestControlOfEnt(EntityTarget);
					ENTITY::FREEZE_ENTITY_POSITION(EntityTarget, true);
					if (ENTITY::IS_ENTITY_A_PED(EntityTarget))
						AI::CLEAR_PED_TASKS_IMMEDIATELY(EntityTarget);
				}

			}
		}
	}
	else
	{

		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
			{
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget)
					&& PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1)) {
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget)) EntityTarget = PLAYER::PLAYER_PED_ID();
				RequestControlOfEnt(EntityTarget);
				ENTITY::FREEZE_ENTITY_POSITION(EntityTarget, false);
			}
		}
	}

	if (pedtorgun)
	{
		Vector3 iCoord;
		float scaleX = .1, scaleY = .1, scaleZ = 45;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
		{
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(iCoord.x, iCoord.y, iCoord.z + 130, iCoord.x, iCoord.y, iCoord.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 130);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(iCoord.x, iCoord.y, iCoord.z + 130, iCoord.x, iCoord.y, iCoord.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 130);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(iCoord.x, iCoord.y, iCoord.z + 130, iCoord.x, iCoord.y, iCoord.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 130);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(iCoord.x, iCoord.y, iCoord.z + 130, iCoord.x, iCoord.y, iCoord.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET"), PLAYER::PLAYER_PED_ID(), 1, 1, 130);

		}
		//MAKE IT STAY FRAME 
		GRAPHICS::DRAW_MARKER(1, iCoord.x, iCoord.y, iCoord.z - 1, 0, 0, 0, 0, 0, 0, scaleX, scaleY, scaleZ, 255, 0, 0, 255, 0, 0, 2, 0, 0, 0, 0);
	}
	if (forcegun)
	{
		Entity EntityTarget;
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
			{
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget)
					&& PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1)) {
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}
				RequestControlOfEnt(EntityTarget);
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 100000.0f, dir.y * 100000.0f, dir.z * 100000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
			}
		}
	}
	if (gravygun)
	{
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{

			if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
			{
				EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
			}
			RequestControlOfEnt(EntityTarget);
			ENTITY::SET_ENTITY_HAS_GRAVITY(EntityTarget, false);
			if (IsKeyPressed(VK_LSHIFT))
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10.0f, dir.y * 10.0f, dir.z * -50.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
			else
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * -10.0f, dir.y * -10.0f, dir.z * +50.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);

			gunon = false;

		}
		if (gunon)
			notifyBottom("Right click and You'll use the Force, Left Shit + Right click To Pull");
	}

	if (DeleteGun)
	{
		auto cam = CAM::GET_GAMEPLAY_CAM_COORD();
		auto end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 5000.f));
		BOOL hit; Vector3 endCoords; Vector3 surfaceNormal; Entity entityHandle = 0;
		int ray = WORLDPROBE::_START_SHAPE_TEST_RAY(cam.x, cam.y, cam.z, end.x, end.y, end.z, -1, PLAYER::PLAYER_PED_ID(), 7);
		WORLDPROBE::GET_SHAPE_TEST_RESULT(ray, &hit, &endCoords, &surfaceNormal, &entityHandle);
		if (ENTITY::DOES_ENTITY_EXIST(entityHandle) &&
			(ENTITY::IS_ENTITY_A_PED(entityHandle) ||
				ENTITY::IS_ENTITY_A_VEHICLE(entityHandle) ||
				ENTITY::IS_ENTITY_AN_OBJECT(entityHandle)) &&
			PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID())) {
			RequestControlOfEnt(entityHandle);
			ENTITY::SET_ENTITY_COORDS(entityHandle, 0.f, 0.f, -10.f, 0, 0, 0, 1);
			ENTITY::DELETE_ENTITY(&entityHandle);
		}


	}

	if (Alpha2) { Shootthingsoutofgun("ALPHA"); }
	if (bombushka2) { Shootthingsoutofgun("bombushka"); }
	if (CARGOPLANE2) { Shootthingsoutofgun("CARGOPLANE"); }
	if (BUS2) { Shootthingsoutofgun("BUS"); }
	if (RHINO2) { Shootthingsoutofgun("RHINO"); }
	if (DUMP2) { Shootthingsoutofgun("DUMP"); }


	if (Alpha) { Imapct_Shot("ALPHA"); }
	if (bombushka) { Imapct_Shot("bombushka"); }
	if (CARGOPLANE) { Imapct_Shot("CARGOPLANE"); }
	if (BUS) { Imapct_Shot("BUS"); }
	if (RHINO) { Imapct_Shot("RHINO"); }
	if (DUMP) { Imapct_Shot("DUMP"); }


	if (Custom)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_SHOOTING(playerPed))
		{
			Vector3 PlayerPos;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &PlayerPos);
			int Hashs = GAMEPLAY::GET_HASH_KEY(Car);
			STREAMING::REQUEST_MODEL(Hashs);
			if (STREAMING::HAS_MODEL_LOADED(Hashs))
			{
				VEHICLE::CREATE_VEHICLE(Hashs, PlayerPos.x, PlayerPos.y, PlayerPos.z, 0.0f, 1, 0);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hashs);
				RrequestNetworkControl(Hashs);
				ENTITY::SET_ENTITY_ALPHA(Hashs, 0, false);
			}
		}

	}
	if (Custom2)
	{
		Imapct_Shot(car2);
	}
	if (Alpha) { Imapct_Bull(VEHICLE_WEAPON_WATER_CANNON); }
	if (bombushka) { Imapct_Bull(VEHICLE_WEAPON_PLANE_ROCKET); }
	if (CARGOPLANE) { Imapct_Bull(WEAPON_EXPLOSION); }
	//if (BUS) { Imapct_Bull("BUS"); }
	//if (RHINO) { Imapct_Bull("RHINO"); }
	//if (DUMP) { Imapct_Bull("DUMP"); }


	if (sitgun)
	{
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
			{
				if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
				{
					if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
					{
						PED::DELETE_PED(&EntityTarget);
						PED::SET_PED_INTO_VEHICLE(playerPed, EntityTarget, -1);
					}
					PED::SET_PED_INTO_VEHICLE(playerPed, EntityTarget, -1);
				}
			}

		}

	}
	if (triggerbot)
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
				Vector3 Mouth = PED::GET_PED_BONE_COORDS(peds[offsettedID], SKEL_Head, 0.1f, 0.0f, 0.0f);
				if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
				{
					if (ENTITY::IS_ENTITY_A_PED(EntityTarget))
					{
						PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), Mouth.x, Mouth.y, Mouth.z, true);
					}
				}
			}
		}

	}
	if (aimbotfull)
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		int peds[arrSize];
		peds[0] = numElements;
		int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
		for (int i = 0; i < count; ++i)
		{
			int offsettedID = i * 2 + 2;
			if (ENTITY::DOES_ENTITY_EXIST(peds[offsettedID]))
			{
				if (PLAYER::IS_PLAYER_FREE_AIMING(player))
				{
					Ped targetPed = peds[offsettedID];
					Vector3 targetPos = ENTITY::GET_ENTITY_COORDS(targetPed, 1);
					BOOL exists = ENTITY::DOES_ENTITY_EXIST(targetPed);
					BOOL dead = PLAYER::IS_PLAYER_DEAD(targetPed);


					BOOL onScreen = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(targetPos.x, targetPos.y, targetPos.z, &screenX, &screenY);
					if (ENTITY::IS_ENTITY_VISIBLE(targetPed) && onScreen)
					{
						if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, targetPed, 17))
						{
							Vector3 targetCoords = PED::GET_PED_BONE_COORDS(targetPed, 31086, 0, 0, 0);
							PED::SET_PED_SHOOTS_AT_COORD(playerPed, targetCoords.x, targetCoords.y, targetCoords.z, 1);

						}
					}
				}
			}
		}
	}
	if (lightgun)
	{
		if (PED::IS_PED_SHOOTING(playerPed))
		{
			Weapon myWeaponEntity = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
			if (does_it_exist(myWeaponEntity))
			{
				Vector3 gunpos = Get_Position(myWeaponEntity);
				DrawLightWithRange(gunpos, colour, 50.0f, 80.0f);
			}
		}
	}
	if (mindcontrol)
	{
		Hash firingPattern = key("FIRING_PATTERN_FULL_AUTO");
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			if (ENTITY::IS_ENTITY_A_PED(EntityTarget))
			{

				CONTROLS::DISABLE_CONTROL_ACTION(0, INPUT_ATTACK, TRUE);
				CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_ATTACK2, TRUE);
				CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_ATTACK, TRUE);
				CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_ATTACK2, TRUE);
				if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_ATTACK))
						gotem = true;
			}
		}
		if (gotem)
		{
			WEAPON::GIVE_WEAPON_TO_PED(nearbypeds(), GAMEPLAY::GET_HASH_KEY("WEAPON_RPG"), 25, 1, 1);
			AI::TASK_SHOOT_AT_ENTITY(nearbypeds(), EntityTarget, 50000, firingPattern);
		}
		if (PED::IS_PED_DEAD_OR_DYING(EntityTarget, true))
			gotem = false;
	}

}
void Main_Impact_Gun()
{
	Menu::Title("");
	Menu::Subtitle("Impact Menu");
	Menu::Toggle("Alpha", Alpha);
	Menu::Toggle("Bombushka", bombushka);
	Menu::Toggle("Cargo Plane", CARGOPLANE);
	Menu::Toggle("Bus", BUS);
	Menu::Toggle("Tank", RHINO);
	Menu::Toggle("Dump Truck", DUMP);
	Menu::Toggle("Custom Input", Custom);
	if (Custom)
	{
		if (Menu::Option("Input"))
		{
			GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(TRUE, "FMMC_KEY_TIP8", "", "", "", "", "", 12);
			while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
			Car = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		}
	}
	Menu::Break("Tests");
	

}



void Force_ObjectGun()
{
	Menu::Title("");
	Menu::Subtitle("Force Object Menu");
	Menu::Toggle("Alpha", Alpha2);
	Menu::Toggle("Bombushka", bombushka2);
	Menu::Toggle("Cargo Plane", CARGOPLANE2);
	Menu::Toggle("Bus", BUS2);
	Menu::Toggle("Tank", RHINO2); 
	Menu::Toggle("Dump Truck", DUMP2);
	//Menu::Toggle("Last Used Vehicle", lasteused);
	Menu::Toggle("Custom Input", Custom2);
	if (Custom2)
	{
		if (Menu::Option("Input"))
		{
			GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(TRUE, "FMMC_KEY_TIP8", "", "", "", "", "", 12);
			while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
			car2 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		}
	}

}


void Weapon_bullets_options_sets()
{
	Menu::Title("");
	Menu::Subtitle("Bullet Menu");
	//  Menu::Toggle("Cool bullet", Weapon_bullets_options_booll);
		//Menu::Toggle("Green Laser", LASER);//speed
		//Menu::Toggle("Red Laser", ENEMY_LASER);//speed
	Menu::Toggle("Airstrike Rocket", AIRSTRIKE_ROCKET);//speed
	Menu::Toggle("Tazer", STUN);//not speed
	Menu::Toggle("Firework", FIREWORK);//speed
	Menu::Toggle("Snowball", SNOWBALL);//speed
	Menu::Toggle("Ball", BALLss);//speed
	//Menu::Toggle("Flare 2", FLAREee);//not speed
	Menu::Toggle("Flare Gun", FLAREGUN);//not speed
	Menu::Toggle("Valkyrie Turret", VALKYRIE);//not speed
	Menu::Toggle("Insurgent Turret", TURRET_INSURGENT);//not speed
	Menu::Toggle("Technical Turret", TURRET_TECHNICAL);//not speed
	Menu::Float("Bullet Speed", bullet_speed, -1.0, 10.0);
	Menu::Int("Bullet Damage", bullet_damage, -1, 9999999999);


}
// new gun idea shoot get entity and shoot again and put it there 
void weaponsub()
{
	Menu::Title("");
	Menu::Subtitle("Gun Menu");
	Menu::MenuOption("Avi's Guns", guns);
	Menu::MenuOption("Bullet Options", bullet_menu);
	Menu::MenuOption("Impact Gun", impactgunveh);
	Menu::MenuOption("Force Object Gun", ForceObjectGun); 
	Menu::Toggle("Infinity Ammo", Ammoinf);
	Menu::Toggle("Flaming Ammo", laser);
	//Menu::Toggle("Disappear 0500", disgun);
	Menu::Toggle("Sticky Detonator", Stcikdgun);
	Menu::Toggle("RC Gun", rcgun);
//	Menu::Toggle("Ghost Gun", rcghostgun);
	Menu::Toggle("Explosive Ammo", Ammoexp);
if (Ammoexp) Menu::Float("Explosive Damage Scale", damageScale, 0.0f, 9999.9999f);
	Menu::Toggle("Trigger Bot", triggerbot);
	Menu::Toggle("Aimbot", aimbotfull);
	Menu::Toggle("Gravity Gun", Gravity);
	Menu::Toggle("Portal Gun", protelgun);
	Menu::Toggle("Soul Gun", pedgun);
	Menu::Toggle("Mind Control(beta)", mindcontrol);
	Menu::Toggle("Sit in car Gun", sitgun);
	Menu::Toggle("Teleport Gun", tpgun);
	Menu::Toggle("Rapid Fire", rapidfire);
	Menu::Toggle("Laser Gun (Alpha)", pedtorgun);
	Menu::Toggle("Freeze Ray (Alpha)", freezray);
	Menu::Toggle("The Force", gravygun);
	Menu::Toggle("Force Gun", forcegun);
	Menu::Toggle("Delete Gun", DeleteGun);
	Menu::Toggle("Rainbow Camo", Rainbowcamo);
	Menu::Toggle("One Shot", onehit);
	Menu::Toggle("Super Punch", SuperPunch);

}


