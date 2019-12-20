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
void KickPlayer(int i)// kicks
{
	unsigned int Bit = (1 << i);
	int kick_1[4] = { 2870072008, Bit, 0, 0 };
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, kick_1, 4, Bit);
	int kick_2[4] = { 1073025268, Bit, 0, 0 };
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, kick_2, 4, Bit);
	int kick_3[4] = { -1264063129, Bit, 0, 0 };
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, kick_3, 4, Bit);
	int kick_sp81[4] = { -568609240, Bit, 0, 0 }; 
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, kick_sp81, 4, Bit);
	int kick_sp8112[4] = { -418126478, Bit, 0, 0 };  
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, kick_sp8112, 4, Bit);
	int kick_sp8113[4] = { -891421850, Bit, 0, 0 };  
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, kick_sp8113, 4, Bit);
	int kick_sp8114[4] = { 183152618, Bit, 0, 0 };  
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, kick_sp8114, 4, Bit);
	int kick_sp8115[4] = { -1825000322, Bit, 0, 0 };  
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, kick_sp8115, 4, Bit);
	int kick_sp8116[4] = { 1054601398, Bit, 0, 0 }; 
	int infiniteload[9] = { 1000837481, Bit, 0, -1, 1, 115, 0, 0, 0 };
	SCRIPT::TRIGGER_SCRIPT_EVENT(1, infiniteload, 9, Bit);// idk why not
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


