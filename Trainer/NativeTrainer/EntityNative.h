#pragma once
void set_entity_invincible(Entity entity, bool toggle);
void set_entity_dynamic(Entity entity, bool toggle);
void set_entity_health(Entity entity, int health);
void set_entity_alpha(Entity entity, int Alpha);
void set_entity_collision(Entity entity, bool toggle);
void set_entity_as_visible(Entity entity, bool toggle);
void set_entity_lod(Entity entity, int LOD);
void set_entity_as_mission(Entity entity, bool toggle);
void set_entity_as_velocity(Entity entity, Vector3 velocity);
void set_entity_gravity(Entity entity, bool toggle);
void DrawLightWithRange(Vector3 position, RGB colour, float range, float intensity);
bool does_it_exist(Entity entity);
Vector3 Get_Position(Entity entity);
Hash gethash(char* hash);