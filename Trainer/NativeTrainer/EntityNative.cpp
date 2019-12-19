#include "MAIN.h"

void set_entity_invincible(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_INVINCIBLE(entity, toggle);
}
void set_entity_dynamic(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_DYNAMIC(entity, toggle);
}
void set_entity_health(Entity entity, int health)
{
	health = ENTITY::GET_ENTITY_HEALTH(entity);
	ENTITY::SET_ENTITY_HEALTH(entity, health);
}
void set_entity_alpha(Entity entity, int Alpha)
{
	ENTITY::SET_ENTITY_ALPHA(entity, Alpha, false);
}
void set_entity_collision(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_COLLISION(entity, toggle, toggle);
}
void set_entity_lod(Entity entity, int LOD)
{
	RequestControlOfEnt(entity);
	LOD = ENTITY::GET_ENTITY_LOD_DIST(entity);
	ENTITY::SET_ENTITY_LOD_DIST(entity, LOD);

}
void set_entity_as_mission(Entity entity, bool toggle)
{
	RequestControlOfEnt(entity);
	if (toggle)
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(entity, NULL, NULL);
	else
		ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&entity);

}
void set_entity_as_visible(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_VISIBLE(entity, toggle, false);
}
void set_entity_as_velocity(Entity entity, Vector3 velocity)
{
	RequestControlOfEnt(entity);
	 velocity = ENTITY::GET_ENTITY_VELOCITY(entity);
	ENTITY::SET_ENTITY_VELOCITY(entity, velocity.x, velocity.y, velocity.z);
}
void set_entity_gravity(Entity entity, bool toggle)
{
	ENTITY::SET_ENTITY_HAS_GRAVITY(entity, toggle);
}
void DrawLightWithRange(Vector3 position, RGB colour, float range, float intensity)
{
	GRAPHICS::DRAW_LIGHT_WITH_RANGE(position.x, position.y, position.z, colour.r, colour.g, colour.b, range, intensity);
}
bool does_it_exist(Entity entity)
{
	if (ENTITY::DOES_ENTITY_EXIST(entity))
		return true;
}
Vector3 Get_Position(Entity entity)
{
	return ENTITY::GET_ENTITY_COORDS(entity, NULL);
}
Hash gethash(char* hash)
{
	GAMEPLAY::GET_HASH_KEY(hash);
}