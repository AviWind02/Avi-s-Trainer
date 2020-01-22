#pragma once
// main
void OnlineFuctions();
void playerlist();

// common
int targetPlayer();
void selected();

//Function
void Set_Player_Animation(char* option, char* anim, char* animid, Player target);
void Shoot_Player(char* option, char* Key, Player target);
void Ram_Player_With_Veh(char* option, char* Key, Player target);
void Attach_Object_Player(char* option, char* object, Player target);
void Set_PFX_Player(char* option, char* call1, char* call2, char* name, Player target);
