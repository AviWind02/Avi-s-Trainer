#include "MAIN.h"
bool helpheil = false;
Vehicle bird;
Ped pilott;
Ped shooterright;
Ped shooterleft;
float dis = 150.0f;
float speed = 95.0f;
int pos_ = 1;

Vector3 me;
float mebutfree = 20.0f;
Hash camy = 26379945;
void heilhelp()
{
	
	if (helpheil)
	{
		

	}

}
void camtest()
{
	/*
	step 1 render a new cam works
	step 2 move the cam
	*/
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	me = Get_Position(playerPed);
	Any cam = CAM::CREATE_CAMERA(camy, false);
	CAM::SET_CAM_ACTIVE(cam, true);
	CAM::RENDER_SCRIPT_CAMS(true, false, 3000, true, false);
	

	if (Menu::Float("Z", me.z, -180.0f, 180.0f))
	{
		Any free = CAM::GET_RENDERING_CAM();
		CAM::SET_CAM_COORD(free, me.x, me.y, me.z);
	}
}

void devwork()
{
	Menu::Title("");
	Menu::Subtitle("Dev Stuff");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Hash firingPattern = key("FIRING_PATTERN_FULL_AUTO");
	camtest();
	if (!does_it_exist(bird))
	{
		if (Menu::Option("Spawn Bird"))
		{
			Hash birdy = 0x2C75F0DD;//buzzard2 
			STREAMING::REQUEST_MODEL(birdy);// just in case
			//while (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("STRETCH"))) WAIT(0);
			shooterleft = PED::CREATE_RANDOM_PED(0, 0, 0);
			shooterright = PED::CREATE_RANDOM_PED(0, 0, 0);
			Vector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0);
			int randy = rndInt(1, 100);
			bird = VEHICLE::CREATE_VEHICLE(birdy, pos.x + randy, pos.y + randy, pos.z + 100, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 1, 1);
			set_blip(bird, 255, 25, false);
			PED::SET_PED_INTO_VEHICLE(shooterleft, bird, 1);
			PED::SET_PED_INTO_VEHICLE(shooterright, bird, 2);
			WEAPON::GIVE_WEAPON_TO_PED(shooterleft + shooterright, GAMEPLAY::GET_HASH_KEY("WEAPON_RAYCARBINE"), 9999, 1, 1);
		}
	}
	if (does_it_exist(bird))
	{

		pilott = PED::CREATE_RANDOM_PED_AS_DRIVER(bird, false);
		set_entity_invincible(bird);

		//AI::TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Driver, true);
		//PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Driver, 1);
		//PED::SET_PED_FLEE_ATTRIBUTES(Driver, 0, 0);
		//PED::SET_PED_COMBAT_ATTRIBUTES(Driver, 17, 1);
		Menu::Float("Distance", dis, 0.0f, 200.0f);
		Menu::Float("Speed", speed, 0.0f, 200.0f);
		AI::TASK_VEHICLE_MISSION_PED_TARGET(pilott, bird, playerPed, pos_, dis, Normal, speed, NULL, NULL);
		AI::TASK_SHOOT_AT_ENTITY(shooterleft + shooterright, nearbypeds(), 999, firingPattern);
		notifyBottom("Bird is something");
	}	
}