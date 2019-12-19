#include "MAIN.h"
bool Collision = true;
bool Sponner::LoadingObject = false;

int SpawnedObject[20];
int SpawnedObjects;
int SelectedObject;
int SelectedObject2;
int Alphae = 255;

Vector3 obje;

char* ObjectNameArray[20];
char* Sponner::ObjectString;

float Yaw;
float Pitch;
float roll;

void XAxis(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestControlOfEnt(Handle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(SpawnedObject[SelectedObject], 1);
		Menu::Axis("X", Pos.x, -9999999, 99999999);
		RequestControlOfEnt(Handle);
		ENTITY::SET_ENTITY_COORDS(Handle, Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
	}
}
void YAxis(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestControlOfEnt(Handle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(SpawnedObject[SelectedObject], 1);
		Menu::Axis("Y", Pos.y, -9999999, 99999999);
		RequestControlOfEnt(Handle);
		ENTITY::SET_ENTITY_COORDS(Handle, Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
	}
}
void ZAxis(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestControlOfEnt(Handle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(SpawnedObject[SelectedObject], 1);
		Menu::Axis("Z", Pos.z, -9999999, 99999999);
		RequestControlOfEnt(Handle);
		ENTITY::SET_ENTITY_COORDS(Handle, Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
	}
}
void RollAxis(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		Menu::Axis("Roll", roll, -9999999, 99999999);
		RequestControlOfEnt(Handle);
		ENTITY::SET_ENTITY_ROTATION(Handle, Pitch, roll, Yaw, 1, true);
	}
}
void PitchAxis(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		Menu::Axis("Pitch", Pitch, -9999999, 99999999);
		RequestControlOfEnt(Handle);
		ENTITY::SET_ENTITY_ROTATION(Handle, Pitch, roll, Yaw, 1, true);
	}
}
void YawAxis(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		Menu::Axis("Yaw", Yaw, -9999999, 99999999);
		RequestControlOfEnt(Handle);
		ENTITY::SET_ENTITY_ROTATION(Handle, Pitch, roll, Yaw, 1, true);
	}
}
void DeleteEntity(int Handle)
{
	RequestControlOfEnt(Handle);
	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Handle, 1, 1);
	ENTITY::DELETE_ENTITY(&Handle);
}

bool Create_Object(char* ObjectName, char* Name, Vector3 Pos, bool custom = false, int hash = 0)
{
	if (custom)
	{
		if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
		{
			if (STREAMING::IS_MODEL_VALID(hash))
			{
				STREAMING::REQUEST_MODEL(hash);
				if (STREAMING::HAS_MODEL_LOADED(hash))
				{
					SpawnedObject[SpawnedObjects] = OBJECT::CREATE_OBJECT(hash, Pos.x, Pos.y - 5, Pos.z, 1, 1, 1);
					ObjectNameArray[SpawnedObjects] = Name;
					if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SpawnedObjects]))
					{
						SpawnedObjects++;
						if (SpawnedObjects >= 15)
							SpawnedObjects = 0;
						return true;
					}
					else return false;
				}
			}
		}
	}
	else
	{
		if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(ObjectName)))
		{
			if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(ObjectName)))
			{
				STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(ObjectName));
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(ObjectName)))
				{
					SpawnedObject[SpawnedObjects] = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(ObjectName), coords.x, coords.y - 5, coords.z, 1, 1, 1);
					ENTITY::SET_ENTITY_ROTATION(GAMEPLAY::GET_HASH_KEY(ObjectName), coords.x - 5, coords.y - 5, coords.z - 5, 2, 1);

					ObjectNameArray[SpawnedObjects] = ObjectName;
					if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SpawnedObjects]))
					{
						SpawnedObjects++;
						if (SpawnedObjects >= 15)
							SpawnedObjects = 0;
						return true;
					}
					else return false;
				}
				else return false;
			}
		}
	}
}

void spooner_function()
{
	if (Sponner::LoadingObject)
	{

		if (Create_Object(Sponner::ObjectString, "", obje) == true)
		{
			Sponner::LoadingObject = false;
			Sponner::ObjectString = "";
		}
	}
}

void ObjectManager()
{
	Menu::Title("");
	Menu::Subtitle("Object Manager");
	for (int i = 0; i < 12; i++)
	{
		if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[i]))
		{
			Menu::MenuOption(ObjectNameArray[i], _Selectedentity) ? SelectedObject = i : NULL;
		}
		else
		{
			Menu::Option("No objects Spawned");
		}
	}
}






void copyobject()
{
	if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SelectedObject]))
	{
		int hash = ENTITY::GET_ENTITY_MODEL(SpawnedObject[SelectedObject]);
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(SpawnedObject[SelectedObject], true);
		pos.z += 0.60;
		Create_Object("", ObjectNameArray[SelectedObject], pos, true, hash);
		char buf[100];
		_snprintf(buf, sizeof(buf), "Copied: ~y~%s", ObjectNameArray[SelectedObject]);
		notifyMap(buf);
	}
}

void deleteobject()
{
	if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SelectedObject]))
	{
		DeleteEntity(SpawnedObject[SelectedObject]);
		char buf[100];
		_snprintf(buf, sizeof(buf), "Deleted: ~y~%s", ObjectNameArray[SelectedObject]);
		notifyMap(buf);
	}
}
void attachenitiy()
{
	Menu::Title("");
	Menu::Subtitle("Object Editor");
	for (int i = 0; i < 12; i++)
	{
		if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[i]))
		{
			Vector3 Pos = ENTITY::GET_ENTITY_COORDS(SpawnedObject[SelectedObject], 1);
			if (Menu::Option(ObjectNameArray[i]) ? SelectedObject2 = i : NULL)
				ENTITY::ATTACH_ENTITY_TO_ENTITY(SpawnedObject[SelectedObject2], SpawnedObject[SelectedObject], 
					0, Pos.x, Pos.y, Pos.z, Pitch, roll, Yaw, false, false, false, false, 0, false);
			
		}
	}
}
bool Dynamic = false;
int health;
bool invincble = false;
int LOD = 1000000;
bool misson = true;
bool gravity_e = true;
bool issee = true;
void MainMenuSpooner()
{
	Menu::Title("");
	Menu::Subtitle("Spooner");
	Menu::MenuOption("Spawn Objects", objectmenu);
	if (ENTITY::DOES_ENTITY_EXIST(SpawnedObject[SelectedObject]))
			Menu::MenuOption("Spawned Entitys", objectmanager);

}
void edit_menu()
{
	Menu::Title("");
	Menu::Subtitle("Object Editor");
	Menu::Floathundr("Scroll Sensitivity", Menu::Settings::Scroll, 0.0001f, 1.0000f);
	XAxis(SpawnedObject[SelectedObject]);
	YAxis(SpawnedObject[SelectedObject]);
	ZAxis(SpawnedObject[SelectedObject]);
	RollAxis(SpawnedObject[SelectedObject]);
	PitchAxis(SpawnedObject[SelectedObject]);
	YawAxis(SpawnedObject[SelectedObject]);
}
void Selectedentity_()
{
	Menu::Title("");
	Menu::Subtitle("Spooner");
	Entity Selectedentity = SpawnedObject[SelectedObject];
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(SpawnedObject[SelectedObject], 1);
	Menu::MenuOption("Edit Placement", editrmenu);
	Menu::MenuOption("Attach Entity", attch);
	Menu::Int("Entity Alpha", Alphae, 0, 255);
	Menu::Int("Entity Health", health, 0, 1000);
	Menu::Int("Entity LOD", LOD, 0, 1000000);
	Menu::Toggle("Collision", Collision);
	Menu::Toggle("Invincible", invincble);
	Menu::Toggle("Dynamic", Dynamic);
	Menu::Toggle("Save Spawned Entity", misson);
	Menu::Toggle("Entity Visible", issee);
	Menu::Toggle("Grvaity", gravity_e);
	if (Menu::Option("Copy Entity")) copyobject();
	if (Menu::Option("Set Entity Straight")) set_ObjectStraight(SpawnedObject[SelectedObject]);
	if (Menu::Option("Delete Entity")) deleteobject();
	if (Menu::Option("Teleport to Entity")) teleport_to_coords(PLAYER::PLAYER_PED_ID(), Pos);

	set_entity_as_visible(Selectedentity, issee);
	set_entity_gravity(Selectedentity, gravity_e);
	set_entity_as_mission(Selectedentity, misson);
	set_entity_lod(Selectedentity, LOD);
	set_entity_invincible(Selectedentity, invincble);
	set_entity_dynamic(Selectedentity, Dynamic);
	set_entity_health(Selectedentity, health);
	set_entity_alpha(Selectedentity, Alphae);
	set_entity_collision(Selectedentity, Collision);
}