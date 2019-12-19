#include "MAIN.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void  Spawn_object()
{
	Menu::Title("");
	Menu::Subtitle("Objects");
	if (Menu::Option("Custom Input"))
	{
		GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(TRUE, "FMMC_KEY_TIP8", "", "", "", "", "", 12);
		while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
		Sponner::ObjectString = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		Sponner::LoadingObject = true;

	}
	string props;
	ifstream myfile("Avi's Trainer/props.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, props))
		{
			Menu::OptionProp(Menu::Tools::StringToChar(props));
		}
		myfile.close();
	}
	else
		notifyBottom("Unable to open file, Check if File is in GTA5 Folder(Avi's Trainer/props.txt)");
}