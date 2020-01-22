#include "MAIN.h"

BOOL IsPlayerFriend(Player player)
{
	int handle[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle[0], 13);
	return NETWORK::NETWORK_IS_FRIEND(&handle[0]);
}
int selectedPlayer;
void playerlist()
{
	Menu::Title("");
	Menu::Subtitle("Player List");
	for (int i = 0; i < 32; i++)
	{
		char* playerName;
		char NameBuffer[255];
		int armor = PLAYER::GET_PLAYER_MAX_ARMOUR(i);
		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~g~Me~s~] ~s~[~y~Host~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, selectedplayeri) ? selectedPlayer = i : NULL;
		}
		else if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID())
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~g~Me~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, selectedplayeri) ? selectedPlayer = i : NULL;
		}
		else if (IsPlayerFriend(i) && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~b~Friend~s~] ~s~[~y~Host~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, selectedplayeri) ? selectedPlayer = i : NULL;
		}
		else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i)
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~y~Host~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, selectedplayeri) ? selectedPlayer = i : NULL;
		}
		else if (IsPlayerFriend(i))
		{
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~b~Friend~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, selectedplayeri) ? selectedPlayer = i : NULL;
		}
		else if (NETWORK::NETWORK_IS_PLAYER_TALKING(i)) {
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~HUD_COLOUR_PURPLE~Talking~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, selectedplayeri) ? selectedPlayer = i : NULL;
		}
		else if (NETWORK::NETWORK_IS_PLAYER_IN_MP_CUTSCENE(i)) {
			char* Name = PLAYER::GET_PLAYER_NAME(i);
			sprintf(NameBuffer, "%s ~s~[~HUD_COLOUR_PINK~In Cutscene~s~]", Name);
			Name = NameBuffer;
			Menu::MenuOption(Name, selectedplayeri) ? selectedPlayer = i : NULL;

		}
		else
		{
			Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), selectedplayeri) ? selectedPlayer = i : NULL;

		}
	}
}


//bool isPlayerModder(Player p) {
//	int modderValue = 0;
//	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
//	bool hasGodmode = PLAYER::GET_PLAYER_INVINCIBLE(ped);
//	bool inHouse = is_player_in_interior(p);
//	int alpha = ENTITY::GET_ENTITY_ALPHA(ped);
//	int level = globalHandle(1589819).At(p, 818).At(211).At(6).As<int>();
//	int kills = globalHandle(1589819).At(p, 818).At(211).At(28).As<int>();
//	int deaths = globalHandle(1589819).At(p, 818).At(211).At(29).As<int>();
//	float kd = globalHandle(1589819).At(p, 818).At(211).At(26).As<float>();
//	int total_money = globalHandle(1589819).At(p, 818).At(211).At(56).As<int>();
//	int wallet_money = globalHandle(1589819).At(p, 818).At(211).At(3).As<int>();
//	int bank_money = total_money - wallet_money;
//	Hash player_model = ENTITY::GET_ENTITY_MODEL(ped);
//
//	int max_legit_money = 8000000;
//	int max_legit_level = 666;
//	int max_legit_deaths = 1000000;
//	int max_legit_kills = 1000000;
//	float max_legit_kd = 6.0f;
//	Hash legit_model[] = {
//		GAMEPLAY::GET_HASH_KEY("mp_m_freemode_01"),
//		GAMEPLAY::GET_HASH_KEY("mp_f_freemode_01")
//	};
//
//	if (player_model != legit_model[0] && player_model != legit_model[1]) {
//		modderValue += 10;
//	}
//	if (hasGodmode) {
//		modderValue += 1;
//		if (!inHouse) {
//			modderValue += 1;
//		}
//	}
//
//	if (alpha < 25) {
//		modderValue += 1;
//	}
//
//	if (level > max_legit_level) {
//		modderValue += 3;
//	}
//
//	if (wallet_money > max_legit_money) {
//		modderValue += 2;
//	}
//
//	if (bank_money > max_legit_money) {
//		modderValue += 3;
//	}
//
//	if (kd > max_legit_kd) {
//		modderValue += 1;
//		if (kills > max_legit_kills) {
//			modderValue += 1;
//		}
//		if (deaths > max_legit_deaths) {
//			modderValue += 1;
//		}
//	}
//
//	if (modderValue > 10) {
//		return true;
//	}
//	return false;
//}