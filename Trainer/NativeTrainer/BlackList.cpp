#include "MAIN.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool blockedpler = false;
void KickPlayer(int i);

void saveoption()
{
	if (Menu::Option("Save"))
	{


	}
}
void readplayer()
{

	string playername;
	string playerkick = "Blocked Player is being kicked ";
	ifstream myfile("Avi's Trainer/Blacklist.txt");
	//read file
	if (myfile.is_open())
	{
		while (getline(myfile, playername))
		{

			for (int i = 0; i < 32; ++i) {
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {

					if (playername == PLAYER::GET_PLAYER_NAME(i))
					{
						getline(cin, playername);
						std::string fullbottom = playerkick + " " + playername;
						KickPlayer(i);
						notifyBottom(fullbottom);
					}
				}
			}
		}
	}
	else
		notifyBottom("Unable to open file, Check if File is in GTA5 Folder(Avi's Trainer/Blacklist.txt)");
}
void writreplayer()
{
	Menu::Title("");
	Menu::Subtitle("Add Players to BlackList");
	//write the file
	ofstream Blacklistfile("Avi's Trainer/Blacklist.txt", fstream::app);
	if (Blacklistfile.is_open())
	{
		for (int i = 0; i < 32; ++i) {
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {

				if (Menu::Option(PLAYER::GET_PLAYER_NAME(i)))
				{
					Blacklistfile << PLAYER::GET_PLAYER_NAME(i) << '\n';
				}
			}
		}

	}
	else
		notifyBottom("Unable to open file, Check if File is in GTA5 Folder(Avi's Trainer/Blacklist.txt)");
}
void KickPlayer(int i)// kicks may be outdated
{
	unsigned int Bit = (1 << i);
	int kick_1[4] = { 2870072008, Bit, 0, 0 };//old kick
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, kick_1, 4, Bit);
}
void wditblackplayer()// making this for editing list in game dont wanna do anything for now
{

	string playername;
	ifstream myfile("Avi's Trainer/Blacklist.txt");
	//read file
	if (myfile.is_open())
	{
		while (getline(myfile, playername))
		{
			Menu::Option(Menu::Tools::StringToChar(playername));
		}
	}
	else
		notifyBottom("Unable to open file, Check if File is in GTA5 Folder(Avi's Trainer/Blacklist.txt)");
}