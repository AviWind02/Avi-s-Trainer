#include "MAIN.h"

int attachobj[100];
int attachobj_ = 1;


int targetPlayer()
{
	return PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
}

void Set_PFX_Player(char* option, char* call1, char* call2, char* name, Player target)
{
	Option(option);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{

			STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, target, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		}
	}
}
void Attach_Object_Player(char* option, char* object, Player target)
{
	bool custom = false;
	int hash = 0;
	Vector3 pos = Get_Position(target);
	hash = GAMEPLAY::GET_HASH_KEY(object);
	Option(option);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
			{
				if (STREAMING::IS_MODEL_VALID(hash))
				{
					STREAMING::REQUEST_MODEL(hash);
					if (STREAMING::HAS_MODEL_LOADED(hash))
					{
						attachobj[attachobj_] = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
						if (ENTITY::DOES_ENTITY_EXIST(attachobj[attachobj_]))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(attachobj[attachobj_], target, 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
							attachobj_++;
							if (attachobj_ >= 101) { attachobj_ = 1; }
						}
					}
				}
			}
		}
	}
}
void Ram_Player_With_Veh(char* option, char* Key, Player target)
{
	float offset;
	Hash vehmodel = key(Key);
	STREAMING::REQUEST_MODEL(vehmodel);

	while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
	Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(target, 0.0, -10.0, 0.0);
	Option(option);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
			{
				Vector3 dim1, dim2;
				GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

				offset = dim2.y * 1.6;

				Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(target);
				float rot = (ENTITY::GET_ENTITY_ROTATION(target, 0)).z;

				Vehicle veh = VEHICLE::CREATE_VEHICLE(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), pCoords.z, rot, 1, 1);

				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
				ENTITY::SET_ENTITY_VISIBLE(veh, true, 0);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 700.0);
			}
		}
	}
}
void Set_Player_Animation(char* option, char* anim, char* animid, Player target)
{
	Option(option);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			RequestControlOfEnt(target);
			STREAMING::REQUEST_ANIM_DICT(anim);
			if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
			{
				AI::TASK_PLAY_ANIM(target, anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
		}
	}
}
void Shoot_Player(char* option, char* Key, Player target)
{
	Hash Keyhash = key(Key);
	Option(option);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			Vector3 coords = Get_Position(target);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x + 5, coords.y + 5, coords.z + 5, coords.x, 
				coords.y, coords.z, 100, 1, Keyhash, PLAYER::PLAYER_PED_ID()/*ME!!*/, 1, 1, 100);
		}
	}
}
