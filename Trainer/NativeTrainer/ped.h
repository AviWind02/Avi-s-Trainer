#pragma once
//=================
// PED FUNCTIONS
//=================
Ped ClonePed(Ped ped);
Ped CreatePed(char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle);
Ped nearbypeds();
void network_set_everyone_ignore_player(Player player);
void set_self_nearby_peds_calm();
void putonseatbelt(Ped ped, bool toggle);

//Animations
void LoadAnim(char* dict);
void playAnimation(Ped ped, bool loop, char* dict, char* anim);
//SKINS
bool applyChosenSkin(std::string skinName);
