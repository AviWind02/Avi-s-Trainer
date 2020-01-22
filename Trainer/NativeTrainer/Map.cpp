#include "MAIN.h"



void teleportplayertocoord(float pX, float pY, float pZ)
{
	Entity Player = PLAYER::PLAYER_PED_ID();
	Entity tp_OP;
	if (ENTITY::IS_ENTITY_A_PED(Player) && PED::IS_PED_IN_ANY_VEHICLE(Player, 1))
	{
		tp_OP = PED::GET_VEHICLE_PED_IS_IN(Player, 0);
	}
	else tp_OP = Player;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(tp_OP, pX, pY, pZ, 0, 0, 1);
}
bool teleportplayertocoord(char* name, float pX, float pY, float pZ, bool toggle)
{
	Option(name);
	Entity Player = PLAYER::PLAYER_PED_ID();
	Entity tp_OP;
	if (ENTITY::IS_ENTITY_A_PED(Player) && PED::IS_PED_IN_ANY_VEHICLE(Player, 1))
	{
		tp_OP = PED::GET_VEHICLE_PED_IS_IN(Player, 0);
	}
	else tp_OP = Player;
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(tp_OP, pX, pY, pZ, 0, 0, 1);
			if (toggle)
				DLC2::_LOAD_MP_DLC_MAPS();
			return true;
		}
	}
	return false;
}
bool teleportplayertocoords(char* name, float pX, float pY, float pZ)
{
	Entity Player = PLAYER::PLAYER_PED_ID();
	Entity tp_OP;
	if (ENTITY::IS_ENTITY_A_PED(Player) && PED::IS_PED_IN_ANY_VEHICLE(Player, 1))
	{
		tp_OP = PED::GET_VEHICLE_PED_IS_IN(Player, 0);
	}
	else tp_OP = Player;
	Option(name);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(tp_OP, pX, pY, pZ, 0, 0, 1);
			return true;
		}
	}
	return false;
}
//void teleportplayertocoords(char* name, float pX, float pY, float pZ, bool toggle)
//{
//	Option(name);
//	Entity Player = PLAYER::PLAYER_PED_ID();
//	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
//		if (Menu::Settings::selectPressed)
//			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Player, pX, pY, pZ, 0, 0, 1);
//	if (toggle)
//		DLC2::_LOAD_MP_DLC_MAPS();
//	WAIT(0);
//}
void teleport_to_coords(Entity e, Vector3 coords)
{
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
	WAIT(0);

}
bool waypoint = false;
Vector3 get_blip_marker()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	// search for marker blip
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}
	if (blipFound)
	{
		waypoint = true;
		return coords;
	}
	else
	{
		waypoint = false;
	}

	return zero;
}

void teleport_to_marker()
{
	Vector3 coords = get_blip_marker();

	if (coords.x == 0 && coords.y == 0)
	{
		//notifyMap("No Waypoint has been set!", 0);
		return;
	}

	// get entity to teleport
	Entity e = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
	{
		e = PED::GET_VEHICLE_PED_IS_USING(e);
	}

	// load needed map region and check height levels for ground existence
	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}
	// if ground not found then set Z in air and give player a parachute
	if (!groundFound)
	{
		coords.z = 1000.0;
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
	}
	//do it
	teleport_to_coords(e, coords);
}
Blip set_blip(Entity entity, int alpha, int colour, bool toggleSaveEntity)
{
	Blip EntityBlip = UI::ADD_BLIP_FOR_ENTITY(entity);
	Hash model = ENTITY::GET_ENTITY_MODEL(entity);
	UI::SET_BLIP_ALPHA(EntityBlip, alpha);
	UI::SET_BLIP_COLOUR(EntityBlip, colour);
	if (VEHICLE::IS_THIS_MODEL_A_CAR(model))//car
		UI::SET_BLIP_SPRITE(EntityBlip, 225);
	else if (VEHICLE::IS_THIS_MODEL_A_BIKE(model) //bike
		|| VEHICLE::IS_THIS_MODEL_A_BICYCLE(model))//bicycle
		UI::SET_BLIP_SPRITE(EntityBlip, 226);
	else if (VEHICLE::IS_THIS_MODEL_A_BOAT(model))//boat
		UI::SET_BLIP_SPRITE(EntityBlip, 427);
	else if (VEHICLE::IS_THIS_MODEL_A_HELI(model))//heil
		UI::SET_BLIP_SPRITE(EntityBlip, 64);
	else if (VEHICLE::IS_THIS_MODEL_A_PLANE(model))//plane 
		UI::SET_BLIP_SPRITE(EntityBlip, 307);
	else if (VEHICLE::IS_THIS_MODEL_A_QUADBIKE(model))//ATV
		UI::SET_BLIP_SPRITE(EntityBlip, 147);
	else if (ENTITY::IS_ENTITY_A_VEHICLE(model))//if you can drive it set it as car icon
		UI::SET_BLIP_SPRITE(EntityBlip, 225);
	else
		UI::SET_BLIP_SPRITE(EntityBlip, 1);
	if (toggleSaveEntity)
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(entity, NULL, NULL);
	return 	EntityBlip;
}
