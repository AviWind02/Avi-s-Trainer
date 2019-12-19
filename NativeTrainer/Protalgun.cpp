#include "MAIN.h"
bool protelgun = false; bool goball = false; bool help = true;
bool voidgun_ = false; 
Entity BALL1; Entity BALL2;
Vector3 ball1Coord; Vector3 ball2Coord;
Object poertal1; Object poertal2;
//imt void
void teleygun()
{
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	
	if (IsKeyPressed(VK_LSHIFT))//Add A for controller
		goball = true;
	else 
		goball = false;

	if (protelgun)
	{

		Entity ObjectHash1 = 1441141378;
		Entity ObjectHash2 = 2310559750;
		if (equippedWeapon == WeaponPistol50) 
		{
			if (!goball)
			{
				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &ball1Coord))
				{
					ENTITY::DELETE_ENTITY(&BALL1);
					if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash1))
					{
						if (STREAMING::IS_MODEL_VALID(ObjectHash1))
						{
							STREAMING::REQUEST_MODEL(ObjectHash1);
							if (STREAMING::HAS_MODEL_LOADED(ObjectHash1))
							{
								BALL1 = OBJECT::CREATE_OBJECT(ObjectHash1, ball1Coord.x, ball1Coord.y, ball1Coord.z, 1, 1, 1);
								ENTITY::FREEZE_ENTITY_POSITION(BALL1, true);
							}
						}
					}
				}
			}
			if (goball)
			{

				if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &ball2Coord))
				{
					ENTITY::DELETE_ENTITY(&BALL2);
					if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash2))
					{
						if (STREAMING::IS_MODEL_VALID(ObjectHash2))
						{
							STREAMING::REQUEST_MODEL(ObjectHash2);
							if (STREAMING::HAS_MODEL_LOADED(ObjectHash2))
							{
								BALL2 = OBJECT::CREATE_OBJECT(ObjectHash2, ball2Coord.x, ball2Coord.y, ball2Coord.z, 1, 1, 1);
								ENTITY::FREEZE_ENTITY_POSITION(BALL2, true);

							}
						}
					}
				}
			}
		}
		else 
			notifyBottom("Use ~bold~LeftShift to switch Portal gun and Equip ~bold~Pistol50");

		
		if (ENTITY::IS_ENTITY_TOUCHING_ENTITY(playerPed, BALL1))
		{
			if (ENTITY::DOES_ENTITY_EXIST(BALL2))

			{
				ball2Coord = ENTITY::GET_ENTITY_COORDS(BALL2, false);
				
				ENTITY::SET_ENTITY_COORDS(playerPed, ball2Coord.x + 1, ball2Coord.y, ball2Coord.z + 1, 0, 0, 1, 0);
				WAIT(0);
			}
			else
				notifyBottom("Spawn in ~bold~PORTAL ~o~2");
		}
		if (ENTITY::IS_ENTITY_TOUCHING_ENTITY(playerPed, BALL2))
		{
			if (ENTITY::DOES_ENTITY_EXIST(BALL1))
			{
				ball1Coord = ENTITY::GET_ENTITY_COORDS(BALL1, false);
				ENTITY::SET_ENTITY_COORDS(playerPed, ball1Coord.x + 1, ball1Coord.y, ball1Coord.z + 1, 0, 0, 1, 0);
				WAIT(0);
			}
			else
				notifyBottom("Spawn in ~bold~PORTAL ~b~1");
		}
		if (!ENTITY::IS_ENTITY_TOUCHING_ENTITY(playerPed, BALL2) && !ENTITY::IS_ENTITY_TOUCHING_ENTITY(playerPed, BALL1))
		{
			if (!help)
			{
				if (!goball)
					notifyBottom("~bold~PORTAL ~b~1");
				if (goball)
					notifyBottom("~bold~PORTAL ~o~2");
			}
		}
		if (PED::IS_PED_SHOOTING(playerPed))
			help = false;

	}
	else
	{
		ENTITY::DELETE_ENTITY(&BALL1);
		ENTITY::DELETE_ENTITY(&BALL2);

	}
}


	
