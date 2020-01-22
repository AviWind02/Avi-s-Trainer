#pragma once
//TELEPORTATION
Vector3 get_blip_marker();
void teleport_to_marker();
void teleport_to_objective();
void teleportplayertocoord(float pX, float pY, float pZ);
void teleport_to_coords(Entity e, Vector3 coords);
bool teleportplayertocoord(char* name, float pX, float pY, float pZ, bool toggle);
bool teleportplayertocoords(char* name, float pX, float pY, float pZ);
Blip set_blip(Entity entity, int alpha, int colour, bool toggleSaveEntity);
extern bool waypoint;