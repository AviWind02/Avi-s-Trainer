#include "MAIN.h"
bool Stcikdgun = false;

Entity stickyboom;
Vector3 stickyboomCoord;
void sickygun()
{
	if (Stcikdgun)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Entity ObjectHash1 = 1441141378;
		if (does_it_exist(stickyboom))
		{
			RGB red{ 255, 0, 0 };
			notifyBottom("Click Left Shift to Blow it");
			Vector3 boomhere = Get_Position(stickyboom);
			DrawLightWithRange(boomhere, red, 999999.99999f, 999.9f);
			//set_entity_as_visible(stickyboom, false);
			if (IsKeyPressed(VK_LSHIFT)) // Add A for controller
			{
			
				FIRE::ADD_EXPLOSION(boomhere.x, boomhere.y, boomhere.z, ExplosionTypeStickyBomb, 1000.0f, true, false, NULL);
				ENTITY::DELETE_ENTITY(&stickyboom); 
			}
		}
		else
		{
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &stickyboomCoord))
			{

				if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash1))
				{
					if (STREAMING::IS_MODEL_VALID(ObjectHash1))
					{
						STREAMING::REQUEST_MODEL(ObjectHash1);
						if (STREAMING::HAS_MODEL_LOADED(ObjectHash1))
						{
							stickyboom = OBJECT::CREATE_OBJECT(ObjectHash1, stickyboomCoord.x, stickyboomCoord.y, stickyboomCoord.z, 1, 1, 1);
							ENTITY::FREEZE_ENTITY_POSITION(stickyboom, true);
						}
					}
				}
			}
		}

	}

}