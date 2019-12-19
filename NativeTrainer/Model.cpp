#include "MAIN.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void mainplayermenu()//Not in use
{
	Menu::Title("");
	Menu::Subtitle("Character Appearance");
	Menu::MenuOption("Clothing Options", clothingmenu);
	//Menu::MenuOption("Plastic Surgery Options", plasticmenu); Online Only
	//Menu::MenuOption("Hair And Makeup Options", Makeupmenu);Online Only


}

bool SetModel(char* option, Hash Model)
{
	Option(option);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			if (STREAMING::IS_MODEL_IN_CDIMAGE(Model))
			{
				if (STREAMING::IS_MODEL_VALID(Model))
				{
					STREAMING::REQUEST_MODEL(Model);
					if (STREAMING::HAS_MODEL_LOADED(Model))
					{
						PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), Model);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
						return true;
					}
					else return false;
				}
			}
			return true;
		}
	}
	return false;
}
bool SetModel(char* option, char* Model)
{
	Option(option);
	if (Menu::Settings::currentOption == Menu::Settings::optionCount)
	{
		if (Menu::Settings::selectPressed)
		{
			if (STREAMING::IS_MODEL_IN_CDIMAGE(gethash(Model)))
			{
				if (STREAMING::IS_MODEL_VALID(gethash(Model)))
				{
					STREAMING::REQUEST_MODEL(gethash(Model));
					if (STREAMING::HAS_MODEL_LOADED(gethash(Model)))
					{
						PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), gethash(Model));
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(gethash(Model));
						return true;
					}
					else return false;
				}
			}
			return true;
		}
	}
	return false;
}

void ModelMenu()
{
	Menu::Title("");
	Menu::Subtitle("Player Menu");
	Menu::MenuOption("Animal Models", AModel);

}
void playerpedlist()
{
	string pedname;
	string pedhash;
	ifstream pednamefile("Avi's Trainer/pedlist/player.txt");
	ifstream pedhashfile("Avi's Trainer/pedlist/playerhash.txt");
	if (pednamefile.is_open())
	{
		if (pedhashfile.is_open())
		{
			while (getline(pednamefile, pedname) && getline(pedhashfile, pedhash))
			{
				char* pedenames = Menu::Tools::StringToChar(pedname);
				char* pedhashnames = Menu::Tools::StringToChar(pedhash);
				Hash pedhash = gethash(pedhashnames);
				SetModel(pedenames, pedhash);
			}
		}
		else
			notifyBottom("Unable to open file, Check if File is in GTA5 Folder(Avi's Trainer/pedlist/player.txt)");
	}
	else
		notifyBottom("Unable to open file, Check if File is in GTA5 Folder(Avi's Trainer/pedlist/playerhash.txt)");
}
void AnimalModels()//Done
{
	Menu::Title("");
	Menu::Subtitle("Animal Menu");
	SetModel("Cat", 1462895032);
	SetModel("Boar", -832573324);
	SetModel("Cormorant", 1457690978);
	SetModel("Cow", -50684386);
	SetModel("Coyote", 1682622302);
	SetModel("Crow", 402729631);
	SetModel("Deer", -664053099);
	SetModel("Fish", 802685111);
	SetModel("Dolphin", -1950698411);
	SetModel("HammerShark", 1015224100);
	SetModel("Hen", 1794449327);
	SetModel("Humpback", 1193010354);
	SetModel("Husky", 1318032802);
	SetModel("KillerWhale", -1920284487);
	SetModel("MountainLion", 307287994);
	SetModel("Pig", -1323586730);
	SetModel("Pigeon", 111281960);
	SetModel("Poodle", 1125994524);
	SetModel("Pug", 1832265812);
	SetModel("Rabbit", -541762431);
	SetModel("Rat", -1011537562);
	SetModel("Retriever", 882848737);
	SetModel("Rhesus", -1026527405);
	SetModel("Rottweiler", -1788665315);
	SetModel("Seagull", -745300483);
	SetModel("Shepherd", 1126154828);
	SetModel("Stingray", -1589092019);
	SetModel("TigerShark", 113504370);
	SetModel("Westy", -1384627013);
	
}
void StoryModels()
{
	SetModel("Franklin", -1692214353);//no clue why i add'ed em 
	SetModel("Michael", 225514697); // no clue why i add'ed em 
	SetModel("Trevor", -1686040670); // no clue why i add'ed em 
	SetModel("Lester Crest", 1302784073);
	SetModel("Dave Norton", 365775923);
}
 