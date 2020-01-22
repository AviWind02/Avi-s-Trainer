#include "MAIN.h"
bool plangoo = false;



Ped pilot;

Vehicle veh;
Entity var;
void ai_plane(Ped pilot, Vehicle aircraft, Vector3 destination, float speed)
{

	AI::TASK_PLANE_MISSION(pilot, aircraft, 0, 0, destination.x, destination.y, destination.z, 4, speed, 50.0f, 8585337, 400, 200);
}
void ai_plane_land(Ped pilot, Vehicle aircraft, Vector3 runwaystart, Vector3 runwayend)
{
	AI::TASK_PLANE_LAND(pilot, aircraft,
		runwaystart.x, runwaystart.y, runwaystart.z,
		runwayend.x, runwayend.y, runwayend.z);
}
Vector3 planedir;

bool can_takeoff = false;
bool Task_Land = false;

//Vector3 playercoords = { 2112.704102,4796.716309,40.591999 };
//Vector3 playercoords = { 1923.810303,4709.457520,40.837090 };
//Vector3 playercoords = { 1656.208130,4253.612793,285.050446 };
//
//Vector3 playercoords = { -2056.854248,2887.069336,32.558411 };
//Vector3 playercoords = { -2719.071533,3269.246338,32.559765 };
//Vector3 playercoords = { -4072.087402,2981.642334,438.664886 };
int Airports_ = 1;
std::vector<std::string> Airports
{

	"McKenzie Airfield",
	"Fort Zancudo",
	"Sandy Shores",
};

void parvplane()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle vehbeingused = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
	Vector3 waypoint1 = UI::GET_BLIP_COORDS(WaypointHandle);
	Vector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0);

	Menu::Title("");
	Menu::Subtitle("Private Jet");
	//Take off code TEST
	if (!can_takeoff)
	{
		if (Menu::Option("plane Spawn test"))
		{

			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("LUXOR2"));
			while (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("LUXOR2"))) WAIT(0);
			Vector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0);
			veh = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY("LUXOR2"), -971.267822, -3159.765381, 14.547380, 60.067535, 1, 1);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, 4);
			pilot = PED::CREATE_RANDOM_PED_AS_DRIVER(veh, false);
			can_takeoff = true;
		}
	}
	if (Menu::StringVectorOption("Airport: ", Airports, Airports_))
	{
			if (does_it_exist(veh))
				ENTITY::DELETE_ENTITY(&veh);

			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("LUXOR2"));
			while (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("LUXOR2"))) WAIT(0);
			veh = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY("LUXOR2"), -2946.535645, -1887.242432, 450.1710, 60.067535, 1, 1);
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, 4);
			pilot = PED::CREATE_RANDOM_PED_AS_DRIVER(veh, false);
			if (Airports_ == 0)
				AI::TASK_PLANE_MISSION(pilot, veh, 0, 0, 2112.704102, 4796.716309, 40.591999, 4, 80.55f, 150.0f, -1.0f, 400, 200);
			if (Airports_ == 1)
				AI::TASK_PLANE_MISSION(pilot, veh, 0, 0, -2056.854248, 2887.069336, 32.558411, 4, 80.55f, 150.0f, -1.0f, 400, 200);
			if (Airports_ == 2)
				AI::TASK_PLANE_MISSION(pilot, veh, 0, 0, -129.874222, 2847.480225, 167.342499, 4, 80.55f, 150.0f, -1.0f, 400, 200);
			VEHICLE::CONTROL_LANDING_GEAR(veh, 3);
			VEHICLE::_SET_VEHICLE_JET_ENGINE_ON(veh, true);
			VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, false);
			Task_Land = true;
			can_takeoff = false;
	}
	
	if (Menu::Option("ai land"))
	{
		AI::TASK_PLANE_LAND(pilot, veh,
			1071.870239, 3079.791504, 1.000000,
			1628.114136, 3228.425293, 1.000000);

	}
}
void update_plane()
{
	if (Task_Land)
	{
		if (ENTITY::IS_ENTITY_IN_AREA(veh, -660.627197, 2596.192139, 366.186798, // tarvs
			1059.662720, 3075.664551, 41.408012, true, true, 1)) {
			AI::TASK_PLANE_LAND(pilot, veh,
				1071.870239, 3079.791504, 1.000000,
				1628.114136, 3228.425293, 1.000000);
			Task_Land = false;
		}

		if (ENTITY::IS_ENTITY_IN_AREA(veh, -2719.071533, 3269.246338, 32.559765, // mail
			-4072.087402, 2981.642334, 438.664886, true, true, 1)) {
			AI::TASK_PLANE_LAND(pilot, veh,
				-2719.071533, 3269.246338, 32.559765,
				-2056.854248, 2887.069336, 32.558411);
			Task_Land = false;
		}

		if (ENTITY::IS_ENTITY_IN_AREA(veh, 1923.810303, 4709.457520, 40.837090, // mck
			1656.208130, 4253.612793, 285.050446, true, true, 1)) {
			AI::TASK_PLANE_LAND(pilot, veh,
				1923.810303, 4709.457520, 40.837090,
				2112.704102, 4796.716309, 40.591999);
			Task_Land = false;
		}
	}
}