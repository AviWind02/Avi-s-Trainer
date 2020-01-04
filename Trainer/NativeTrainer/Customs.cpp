#pragma region LSC/bennys
#include "MAIN.h"

void plate()
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "FMMC_KEY_TIP", "", "", "", "", "", 8);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	char* plateText = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, plateText);
}

float torq = 1.0; float eingp = 1.0;
int Selectedmod; int testthing = 0;
bool l1 = false; bool l2 = false; bool l3 = false; bool l4 = false;
bool bennysveh = false; bool popo = false;
bool b1, b2, b3, b4 = false;
bool t1, t2, t3, t4 = false;
bool s1, s2, s3, s4, s5 = false;
bool a1, a2, a3, a4, a5, a6 = false;
bool tor1, tor2, tor3, tor4, tor5, tor6 = false;
bool e1, e2, e3, e4, e5, e6 = false;
bool custom_Wheels, chrome_wheels = false;
bool Turbobo, nopooptries, LSC::Neon, LSC::Neonl, LSC::Neonf, LSC::Neonr, LSC::Neonrr = false;
bool headlightsss = false; bool Lightt = true;
int  pearlescentColor, wheelColor, primaryColor, secondaryColor, modType, Red, Blue, Green, TR, TG, TB, Prim_, Sec_, SR, SB, SG, red, green, blue, horns, Tint_, engine, brakes, armoor, trans, sup, Bespoke, Originals, NR, NG, NB = 0;// LSC
void LSCfunctions()
{

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	//LSC FUNCTION
	//all neon
	if (LSC::Neon)
	{
		LSC::Neonl = true; LSC::Neonf = true; LSC::Neonr = true; LSC::Neonrr = true;
	}
	//Front
	if (LSC::Neonf)
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, true); 
	//	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, true);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, true);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, true);

	}
	//Right
	if (LSC::Neonr)
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, true);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, true);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, true);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, true);

	}
	//Left
	if (LSC::Neonl)
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, true);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, true);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, true);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, true);

	}
	//rear
	if (LSC::Neonrr)
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, true);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, true);
		//VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, true);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, true);

	}
	if (nopooptries)
	{
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, true);
	}
	else
	{
		//VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, false);
	}
	if (Turbobo)
	{
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, true);
	}
	else
	{
		//VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, false);
	}
	if (Lightt)
	{
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, true);
	}
	else
	{
		//VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, false);
	}
	//EMS 
	if (tor1)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, 1.0);

	}
	else if (tor2)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, 2.0);

	}
	else if (tor3)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, 4.0);

	}
	else if (tor4)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, 6.0);

	}
	else if (tor5)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, 8.0);

	}
	else if (tor6)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, 10.0);

	}
	else
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, torq);
	if (e1)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, 1.0);

	}
	else if (e2)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, 2.0);

	}
	else if (e3)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, 4.0);

	}
	else if (e4)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, 6.0);

	}
	else if (e5)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, 8.0);

	}
	else if (e6)
	{
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, 10.0);

	}
	else
		VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, eingp);


}

void SpawnbennysVeh(char* toSpawn)
{
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		deletecar();
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 0, 0);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 0, 0, 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		ENTITY::_SET_ENTITY_REGISTER(veh, true);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry2");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}
void bennys_upgrade()
{

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Hash carhash = ENTITY::GET_ENTITY_MODEL(veh);
	if (carhash == 0xC1E908D2)//banshee 
	{
		SpawnbennysVeh("BANSHEE2");
	}
	if (carhash == 0xD756460C)//BUCCANEER
	{
		SpawnbennysVeh("BUCCANEER2");
	}
	if (carhash == 0x14D69010)//CHINO
	{
		SpawnbennysVeh("CHINO2");
	}
	if (carhash == 0xC1AE4D16)//comet
	{
		SpawnbennysVeh("COMET3");
	}
	if (carhash == 0x25676EAF)//fcr
	{
		SpawnbennysVeh("FCR2");
	}

	if (carhash == 0x3DA47243)//nero
	{
		SpawnbennysVeh("NERO2");
	}

	if (carhash == 0xED7EADA4)//minivan
	{
		SpawnbennysVeh("MINIVAN2");
	}

	if (carhash == 0x1F52A43F)//moonbeam
	{
		SpawnbennysVeh("moonbeam2");
	}

	if (carhash == 0x85E8E76B)//italigtb2
	{
		SpawnbennysVeh("italigtb2");
	}

	if (carhash == 0xBB6B404F)//PRIMO
	{
		SpawnbennysVeh("PRIMO2");
	}

	if (carhash == 0x9B909C94)//SABREGT
	{
		SpawnbennysVeh("SABREGT2");
	}

	if (carhash == 0x2B7F9DE3)//slamvan
	{
		SpawnbennysVeh("slamvan3");
	}

	if (carhash == 0x1BB290BC)//tornado
	{
		SpawnbennysVeh("tornado5");
	}
	if (carhash == 0xCA62927A)//virgo2 check this 
	{
		SpawnbennysVeh("virgo3");
	}
	if (carhash == 0x1F3766E3)//voodoo2
	{
		SpawnbennysVeh("voodoo");

	}
	if (carhash == 0x39DA2754)//sultan
	{
		SpawnbennysVeh("sultanrs");
	}
	if (carhash == 0x39DA2754)//Diabolus
	{
		SpawnbennysVeh("diablous2");
	}
	if (carhash == 0xDE3D9D22)//elegy2
	{
		SpawnbennysVeh("elegy");
	}
	if (carhash == 0x706E2B40)//Dewbauchee
	{
		SpawnbennysVeh("specter2");
	}
}

void FACTIONbich()
{
	Menu::Title("");
	Menu::Subtitle("Avi's Customs");
	if (Menu::Option("Faction Custom"))
	{
		SpawnbennysVeh("FACTION2");
	}
	if (Menu::Option("Faction Donk"))
	{
		SpawnbennysVeh("FACTION3");
	}
}
bool lscopen = true;
void upgradeabletobennys();
void LSCWwW()
{
	//if (lscopen) notifyBottom("You may Need to use max upgrade before you can use custom mods");
	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);

	Menu::Title("");
	Menu::Subtitle("Avi's Customs");
	if (Menu::Option("Max Upgrade")) 
	{
		{
			lscopen = false;
			a6, t4, b4, l4, s4, a6, nopooptries = true;
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, 0);
			VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
			for (int i = 0; i < 52; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
			}
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Avi");
		}
	}
	VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
	VEHICLE::SET_VEHICLE_MOD(vehicle, 16, 3, 0);
	upgradeabletobennys();
	Menu::MenuOption("Benny's Vehicle Upgrades", Bennysmodlsc, isbennys());
	Menu::MenuOption("Armour Upgrades", Armour);
	Menu::MenuOption("Performance Upgrades", performance);
	Menu::MenuOption("Light Upgrades", Light);
	Menu::MenuOption("Plate Upgrades", plateeee);
	//Menu::MenuOption("Vehicle Upgrades", modlsc, islsc());
	for (int i = 0; i < 10; i++) // 0 to 10 here since those are the simple mods
	{
		if (VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) > 0)
		{
			Menu::MenuOption(VEHICLE::GET_MOD_SLOT_NAME(vehicle, i), fbumper) ? Selectedmod = i : NULL;

		}
	}
	Menu::MenuOption("Colours/Liverys", Resprayss);
	Menu::MenuOption("Window Options/Upgrades", windindowoptions);
	Menu::MenuOption("Wheels/Rims", Wheels);
}
void Armours()
{
	Menu::Title("");
	Menu::Subtitle("Armor");
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_ID());
	setvehmod("None", 16, -1);
	setvehmod("Armor Upgrade 20%", 16, 0);
	setvehmod("Armor Upgrade 40%", 16, 1);
	setvehmod("Armor Upgrade 60%", 16, 2);
	setvehmod("Armor Upgrade 80%", 16, 3);
	setvehmod("Armor Upgrade 100%", 16, 4);
	Menu::Toggle("bulletproof tires", nopooptries);
	lscopen = false;
}
void upgradeabletobennys()
{
	Hash carhash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));
	if (carhash == 0xC1E908D2 || carhash == 0xD756460C || carhash == 0x14D69010 || carhash == 0xC1AE4D16 || carhash == 0x25676EAF || carhash == 0x3DA47243 || carhash == 0xED7EADA4 || carhash == 0x1F52A43F || carhash == 0x85E8E76B || carhash == 0xBB6B404F || carhash == 0x9B909C94 || carhash == 0x2B7F9DE3 || carhash == 0x1BB290BC || carhash == 0xCA62927A || carhash == 0x1F3766E3 || carhash == 0x39DA2754 || carhash == 0x39DA2754 || carhash == 0x706E2B40 || carhash == 0xF1B44F44)
	{
		if (Menu::Option("Upgrade to Benny's Vehicle"))
		{
			bennys_upgrade();
		}
	}
	else if (carhash == 0x81A9CDDF)// this is the big wheel car add a ask option // faction make a check for it and if its there put a case for it
	{
		Menu::MenuOption("Upgrade to Benny's Vehicle", fcar);
	}
	
}
void Bennys_vehicle_Mods()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Menu::Title("");
	Menu::Subtitle("Bennys");
	if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, Aerials_mod) > 0) Menu::MenuOption("Aerials", Aerials);
	if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, AirFilter) > 0) Menu::MenuOption("Engine Fliters", Fliters);
	if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, Struts_mod) > 0) Menu::MenuOption("Strut Brace", Struts);
	if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, EngineBlock) > 0) Menu::MenuOption("Engine Block", Block);
	if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, Hydraulics) > 0) Menu::MenuOption("Hydraulics", Hydrulics);
	if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, Trunk_mod) > 0) Menu::MenuOption("Trunk", Trunk);
	if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, Tank_mod) > 0) Menu::MenuOption("Tank", Tank);
	lscopen = false;

}
void LSC_vehicle_Mods()
{
	Menu::Title("");
	Menu::Subtitle("Avi's Customs");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	for (int i = 0; i < 10; i++) // 0 to 10 here since those are the simple not null mods 
	{
		if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) > 0)
		{
			Menu::MenuOption(VEHICLE::GET_MOD_SLOT_NAME(veh, i), fbumper) ? Selectedmod = i : NULL;

		}
	}
}
void fbumpear()// grabs  all mods
{
	Menu::Title("");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Menu::Subtitle(VEHICLE::GET_MOD_SLOT_NAME(veh, Selectedmod));
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, Selectedmod);

	for (int i = -1; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, Selectedmod, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Menu::Option(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, Selectedmod, i, 1);
				}
			}
		}
	}
	lscopen = false;

}
void proformancce()
{
	Menu::Title("");
	Menu::Subtitle("EMS");
	Menu::MenuOption("EMS Upgrades", EMS);
	Menu::MenuOption("Engine Power", ecase);
	Menu::MenuOption("Engine Torque", torc);
	Menu::MenuOption("Brakes Upgrades", Brakesp);
	Menu::MenuOption("Transmission Upgrades", Transmissionp);
	Menu::MenuOption("Suspension Upgrades", Suspensionp);
	//Menu::Float("Engine Torque", torque, 0.1, 9999.9999);w
	//Menu::Float("Engine Power", Power, 0.1, 9999.9999);
	//VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, torque);
	//VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, Power);
	Menu::Toggle("Turbo", Turbobo);
	lscopen = false;

}
void engineEMS()
{
	Menu::Title("");
	Menu::Subtitle("EMS Upgrade");
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_ID());
	setvehmod("EMS Upgrade, Level 1", 11, 0);
	setvehmod("EMS Upgrade, Level 2", 11, 1);
	setvehmod("EMS Upgrade, Level 3", 11, 2);
	setvehmod("EMS Upgrade, Level 4", 11, 3);
	lscopen = false;

}
void tor()
{
	Menu::Title("");
	Menu::Subtitle("Engine Torque");
	Menu::Toggle("Stock", tor1);
	Menu::Toggle("X2", tor2);
	Menu::Toggle("X4", tor3);
	Menu::Toggle("X6", tor4);
	Menu::Toggle("X8", tor5);
	Menu::Toggle("X10", tor6);
	Menu::Break("T to set custom");
	if (IsKeyPressed(VK_KEY_T))
		torq = numberKeyboard();
	lscopen = false;

}
void epower()
{
	Menu::Title("");
	Menu::Subtitle("Engine Power");
	Menu::Toggle("Stock", e1);
	Menu::Toggle("X2", e2);
	Menu::Toggle("X4", e3);
	Menu::Toggle("X6", e4);
	Menu::Toggle("X8", e5);
	Menu::Toggle("X10", e6);
	Menu::Break("E to set custom");
	if (IsKeyPressed(VK_KEY_E))
		eingp = numberKeyboard();
}
void BrakesEMS()
{
	Menu::Title("");
	Menu::Subtitle("Brakes");
	setvehmod("Stock Brakes", 12, -1);
	setvehmod("Street Brakes", 12, 0);
	setvehmod("Sports Brakes", 12, 1);
	setvehmod("Race Brakes", 12, 2);


}
void TransmissionEMS()
{
	Menu::Title("");
	Menu::Subtitle("Transmission");
	setvehmod("Stock Transmission", 13, -1);
	setvehmod("Street Transmission", 13, 0);
	setvehmod("Sports Transmission", 13, 1);
	setvehmod("Race Transmission", 13, 2);

}
void SuspensionEMS()
{
	Menu::Title("");
	Menu::Subtitle("Suspension");
	setvehmod("Stock Suspension", 15, -1);
	setvehmod("Street Suspension", 15, -1);
	setvehmod("Sports Suspension", 15, -1);
	setvehmod("Race Suspension", 15, -1);
	setvehmod("Competition Suspension", 15, -1);
	

}
void Wheelss()
{

	Menu::Title("");
	Menu::Subtitle("Rims");
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	Menu::Subtitle("Wheels");
	Menu::Toggle("Custom Wheels", custom_Wheels);
	Menu::Toggle("Chrome Wheels", chrome_wheels);
	Hash s0uthwind = ENTITY::GET_ENTITY_MODEL(veh);
	if (VEHICLE::IS_THIS_MODEL_A_BIKE(s0uthwind) == true) Menu::MenuOption("Bike Wheels", BackWheels);
	if (VEHICLE::IS_THIS_MODEL_A_BIKE(s0uthwind) == false) Menu::MenuOption("Rims", Rims);
	Menu::MenuOption("Wheel Colour", wheelclass);
	Menu::MenuOption("Tire smoke", Smoke);
}
void Rimns()
{
	Menu::Title("");
	Menu::Subtitle("Rims");
	Menu::MenuOption("Highend", Highendrims);
	Menu::MenuOption("Lowrider", Lowriderrims);
	Menu::MenuOption("Muscle", Musclerims);
	Menu::MenuOption("Offroad", Offroadrims);
	Menu::MenuOption("Sport", Sportrims);
	Menu::MenuOption("SUV", SUVrims);
	Menu::MenuOption("Tuner", Tunerrims);
	Menu::MenuOption("Benny's Bespoke", B);
	Menu::MenuOption("Benny's Originals", O);
}
void BackWheaels()
{
	Menu::Title("");
	Menu::Subtitle("Bike Wheels");
	Menu::Title("");

	if (Menu::Option("Front Wheels"))
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);


		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			int nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 23) - 1;
			int currmod = VEHICLE::GET_VEHICLE_MOD(veh, 23);
			if (currmod < nummods)
			{
				VEHICLE::SET_VEHICLE_MOD(veh, 23, currmod + 1, 0);


			}
			else
			{

				VEHICLE::SET_VEHICLE_MOD(veh, 23, 1, 0);

			}
		}
	}
	if (Menu::Option("Back Wheel"))
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);


		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			int nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 24) - 1;
			int currmod = VEHICLE::GET_VEHICLE_MOD(veh, 24);
			if (currmod < nummods)
			{

				VEHICLE::SET_VEHICLE_MOD(veh, 24, currmod + 1, 0);

			}
			else
			{

				VEHICLE::SET_VEHICLE_MOD(veh, 24, 1, 0);

			}

		}

	}//
}
void Respdrayss()
{
	Menu::Title("");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int Livreyg = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 48);
	Menu::Subtitle("Colours/Liverys");
	Menu::MenuOption("RGB Colours", ResprayssED);
	Menu::MenuOption("Primary Colours", Primaryyy);
	Menu::MenuOption("Secondary Colours", Secondaryyy);
	Menu::MenuOption("Primary Bright Colours", pbright);
	Menu::MenuOption("Secondary Bright Colours", sbright);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Livreyg != 0)
		{
			Menu::MenuOption("Livery", Livrey);
		}
	}
	else
	{

	}
}
void plateeeae()
{
	Menu::Title("");
	Menu::Subtitle("plates");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, Plateholder) > 0) Menu::MenuOption("Plate Holder", Platee);//
	if (VEHICLE::GET_NUM_VEHICLE_MODS(veh, VanityPlate) > 0) Menu::MenuOption("Vanity Plate", Vanity);
	Menu::MenuOption("Plate Options", plate_Optionss);
	if (Menu::Option("Change Plate Text")) { plate(); }

}
void plate_Options()
{
	Menu::Title("");
	Menu::Subtitle("Plate");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	if (Menu::Option("Blue on White 1")) { VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 0); }
	if (Menu::Option("Blue on White2")) { VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 3); }
	if (Menu::Option("Blue on White3")) { VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 4); }
	if (Menu::Option("Yellow on Blue")) { VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 2); }
	if (Menu::Option("Yellow on black")) { VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 1); }
	if (Menu::Option("Yankton")) { VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 5); }


}
void Lightttt()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Menu::Title("");
	Menu::Subtitle("Light");
	Menu::MenuOption("Neno Light/UnderGlow", Neonnn);
	Menu::Toggle("XenosLight", Lightt);
	if (Lightt)
	{
		if (Menu::Option("White"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 0);
		}
		if (Menu::Option("Blue"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 1);
		}
		if (Menu::Option("Electric Blue"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 2);
		}
		if (Menu::Option("Mint Green"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 3);
		}
		if (Menu::Option("Lime Green"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 4);
		}
		if (Menu::Option("Yellow"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 5);
		}
		if (Menu::Option("Golden Shower"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 6);
		}
		if (Menu::Option("Orange"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 7);
		}
		if (Menu::Option("Red"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 8);//
		}
		if (Menu::Option("Pony Pink"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 9);
		}
		if (Menu::Option("Hot Pink"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 10);
		}
		if (Menu::Option("Purple"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 11);
		}
		if (Menu::Option("Black light"))
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			VEHICLE::SET_HEADLIGHT_COLOR(veh, 12);
		}
	}
}
void NEEaE()
{
	Menu::Title("");
	Menu::Subtitle("Neon RGB");
	Menu::Int("Red", NR, 0, 255);
	Menu::Int("Red", NR, 0, 255);
	Menu::Int("Green", NG, 0, 255);
	Menu::Int("Blue", NB, 0, 255);
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, NR, NG, NB);
	}
}
void Neonnan()
{
	Menu::Title("");
	Menu::Subtitle("Neon Options");
	Menu::Toggle("Toggle All Neons", LSC::Neon);
	Menu::Toggle("Toggle Front Neons", LSC::Neonf);
	Menu::Toggle("Toggle Rear Neons", LSC::Neonrr);
	Menu::Toggle("Toggle Right Neons", LSC::Neonr);
	Menu::Toggle("Toggle Left Neons", LSC::Neonl);

	if (LSC::Neon || LSC::Neonr || LSC::Neonrr || LSC::Neonl || LSC::Neonf)
	{
		Menu::MenuOption("RGB Neon", NEEE);
		if (Menu::Option("Red Neons")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 255, 0, 0);
			}
		}
		if (Menu::Option("Green Neons")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 0, 255, 0);
			}
		}
		if (Menu::Option("Blue Neons")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 0, 0, 255);
			}
		}
		if (Menu::Option("Hot Pink Neons")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 226, 35, 157);
			}
		}
		if (Menu::Option("Yellow Neons")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 247, 244, 0);
			}
		}
		if (Menu::Option("Orange")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 247, 91, 0);
			}
		}
		if (Menu::Option("Aqua")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 40, 255, 255);
			}
		}
		if (Menu::Option("White")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 255, 255, 255);
			}
		}
		if (Menu::Option("Magenta")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 102, 0, 35);
			}
		}
		if (Menu::Option("Purple")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 53, 0, 83);
			}
		}
		if (Menu::Option("Dark Green")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 0, 118, 0);
			}
		}
		if (Menu::Option("Rose Red")) {
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 8);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 161, 0, 0);
			}
		}
	}
	else
	{

	}
}
void insidea()
{
	Menu::Title("");
	Menu::Subtitle("interior");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Player player = PLAYER::PLAYER_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int Ornamentsf = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 28);
	int Dashboardf = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 29);
	int Seatfs = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 32);
	int Steeringwheefl = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 33);
	int Dialfs = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 30);
	int Trimdf = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 27);
	int Speakefr = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 31);
	int Speakerfr = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 36);
	int Shifterf = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 34);
	int Plaquesf = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 35);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Ornamentsf != 0)
		{
			Menu::MenuOption("Ornaments", Ornaments);
		}
	}
	else
	{
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Dashboardf != 0)
		{
			Menu::MenuOption("Dash", Dashboard);
		}
	}
	else
	{
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Seatfs != 0)
		{
			Menu::MenuOption("Seats", Seats);
		}
	}
	else
	{
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Steeringwheefl != 0)
		{
			Menu::MenuOption("Steeringwheel", Steeringwheel);
		}
	}
	else
	{
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Dialfs != 0)
		{
			Menu::MenuOption("Dials", Dials);
		}
	}
	else
	{
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Trimdf != 0)
		{
			Menu::MenuOption("Trim", Trimd);
		}
	}
	else
	{
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Speakefr != 0)
		{
			Menu::MenuOption("Door Speakers", Speaker);
		}
	}
	else
	{
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Speakerfr != 0)
		{
			Menu::MenuOption("Speaker", Speakerr);
		}
	}
	else
	{
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Shifterf != 0)
		{
			Menu::MenuOption("Shifter", Shifter);
		}
	}
	else
	{
	}
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		if (Plaquesf != 0)
		{
			Menu::MenuOption("Plaques", Plaques);
		}
	}
	else
	{
	}
}
void Oa()
{
	Menu::Title("");
	Menu::Subtitle("Benny's Originals");
	Menu::Int("Benny's Originals", Originals, 0, 216);
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 9);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, Originals, 0);
	}
}
void Ba()
{
	Menu::Title("");
	Menu::Subtitle("Benny's Bespoke");
	Menu::Int("Benny's Bespoke", Bespoke, 0, 216);
	{

		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 9);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, Bespoke, 0);
	}
}
void Vaniaty()
{
	Menu::Title("");
	Menu::Subtitle("Vanity Plate");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 26);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 26);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 26, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 26, i, 1);
					//set the veh mod
				}
			}
		}
	}

}
void Window_Options()
{
	Menu::Title("");
	Menu::Subtitle("Windows");
	//Menu::Subtitle("Windows");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	if (Menu::Option("Window Tint None"))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, Tint_);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, VehicleWindowTintNone);
	}
	if (Menu::Option("Window Tint Stock"))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, Tint_);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, VehicleWindowTintStock);
	}
	if (Menu::Option("Window Tint Light Smoke"))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, Tint_);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, VehicleWindowTintLightSmoke);
	}
	if (Menu::Option("Window Tint Dark Smoke"))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, Tint_);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, VehicleWindowTintDarkSmoke);
	}
	if (Menu::Option("Window Tint Limo"))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, Tint_);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, VehicleWindowTintLimo);
	}
	if (Menu::Option("Window Tint Pure Black"))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, Tint_);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, VehicleWindowTintPureBlack);
	}
	if (Menu::Option("Window Tint Green"))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, Tint_);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, VehicleWindowTintGreen);
	}
	if (Menu::Option("Fix All Windows")) { for (int i = -1; i < 8; i++) { VEHICLE::FIX_VEHICLE_WINDOW(veh, i); VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, VehicleWindowTintNone); } }
	Menu::Break("Roll Down Windows");
	if (Menu::Option("Roll Down All Windows")) { VEHICLE::ROLL_DOWN_WINDOWS(veh); }
	if (Menu::Option("Front Right Window")) { VEHICLE::ROLL_DOWN_WINDOW(veh, 0); }
	if (Menu::Option("Front Left Window")) { VEHICLE::ROLL_DOWN_WINDOW(veh, 1); }
	if (Menu::Option("Back Right Window")) { VEHICLE::ROLL_DOWN_WINDOW(veh, 2); }
	if (Menu::Option("Back Left Window")) { VEHICLE::ROLL_DOWN_WINDOW(veh, 3); }
	Menu::Break("Roll Up Windows");
	if (Menu::Option("Roll Up All Windows")) { VEHICLE::ROLL_DOWN_WINDOWS(veh); }
	if (Menu::Option("Front Right Window")) { VEHICLE::ROLL_UP_WINDOW(veh, 0); }
	if (Menu::Option("Front Left Window")) { VEHICLE::ROLL_UP_WINDOW(veh, 1); }
	if (Menu::Option("Back Right Window")) { VEHICLE::ROLL_UP_WINDOW(veh, 2); }
	if (Menu::Option("Back Left Window")) { VEHICLE::ROLL_UP_WINDOW(veh, 3); }
	Menu::Break("Remove Windows");
	if (Menu::Option("Front Left Window")) { VEHICLE::REMOVE_VEHICLE_WINDOW(veh, 0); }
	if (Menu::Option("Front Right Window")) { VEHICLE::REMOVE_VEHICLE_WINDOW(veh, 1); }
	if (Menu::Option("Middle Left Window")) { VEHICLE::REMOVE_VEHICLE_WINDOW(veh, 2); }
	if (Menu::Option("Middle Right Window")) { VEHICLE::REMOVE_VEHICLE_WINDOW(veh, 3); }
	if (Menu::Option("Back Left Window")) { VEHICLE::REMOVE_VEHICLE_WINDOW(veh, 4); }
	if (Menu::Option("Back Right Window")) { VEHICLE::REMOVE_VEHICLE_WINDOW(veh, 5); }
	if (Menu::Option("Windscreen (Front)")) { VEHICLE::REMOVE_VEHICLE_WINDOW(veh, 6); }
	if (Menu::Option("Back Window")) { VEHICLE::REMOVE_VEHICLE_WINDOW(veh, 7); }
	Menu::Break("Smash Windows");
	if (Menu::Option("Front Left Window")) { VEHICLE::SMASH_VEHICLE_WINDOW(veh, 0); }
	if (Menu::Option("Front Right Window")) { VEHICLE::SMASH_VEHICLE_WINDOW(veh, 1); }
	if (Menu::Option("Middle Left Window")) { VEHICLE::SMASH_VEHICLE_WINDOW(veh, 2); }
	if (Menu::Option("Middle Right Window")) { VEHICLE::SMASH_VEHICLE_WINDOW(veh, 3); }
	if (Menu::Option("Back Left Window")) { VEHICLE::SMASH_VEHICLE_WINDOW(veh, 4); }
	if (Menu::Option("Back Right Window")) { VEHICLE::SMASH_VEHICLE_WINDOW(veh, 5); }
	if (Menu::Option("Windscreen (Front)")) { VEHICLE::SMASH_VEHICLE_WINDOW(veh, 6); }
	if (Menu::Option("Back Window")) { VEHICLE::SMASH_VEHICLE_WINDOW(veh, 7); }
	Menu::Break("Fix Windows");
	if (Menu::Option("Front Left Window")) { VEHICLE::FIX_VEHICLE_WINDOW(veh, 0); }
	if (Menu::Option("Front Right Window")) { VEHICLE::FIX_VEHICLE_WINDOW(veh, 1); }
	if (Menu::Option("Middle Left Window")) { VEHICLE::FIX_VEHICLE_WINDOW(veh, 2); }
	if (Menu::Option("Middle Right Window")) { VEHICLE::FIX_VEHICLE_WINDOW(veh, 3); }
	if (Menu::Option("Back Left Window")) { VEHICLE::FIX_VEHICLE_WINDOW(veh, 4); }
	if (Menu::Option("Back Right Window")) { VEHICLE::FIX_VEHICLE_WINDOW(veh, 5); }
	if (Menu::Option("Windscreen (Front)")) { VEHICLE::FIX_VEHICLE_WINDOW(veh, 6); }
	if (Menu::Option("Back Window")) { VEHICLE::FIX_VEHICLE_WINDOW(veh, 7); }


}
void Triamd()
{
	Menu::Title("");
	Menu::Subtitle("Trim");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 27);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 27);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 27, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 27, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Ornamentas()
{
	Menu::Title("");
	Menu::Subtitle("Ornaments");

	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 28);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 28);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 28, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 28, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Dashboaard()
{
	Menu::Title("");
	Menu::Subtitle("Dashboard");

	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 29);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 29);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 29, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 29, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Diaals()
{
	Menu::Title("");
	Menu::Subtitle("Dials");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 30);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 30);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 30, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 30, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Speaadker()
{
	Menu::Title("");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Menu::Subtitle(VEHICLE::GET_MOD_SLOT_NAME(veh, Selectedmod));
	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, Selectedmod);

	for (int i = -1; i < nummods; i++)
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, Selectedmod, i));
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (Menu::Option(mod))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					VEHICLE::SET_VEHICLE_MOD(veh, Selectedmod, i, 1);
				}
			}
		}
	}
}
void Seaatas()
{
	Menu::Title("");
	Menu::Subtitle("Seats");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 32);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 32);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 32, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 32, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Steeringwheael()
{
	Menu::Title("");
	Menu::Subtitle("Steering wheel");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 33);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 33);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 33, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 33, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Shiffter()
{
	Menu::Title("");
	Menu::Subtitle("Shifter");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 34);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 34);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 34, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 34, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Plaqaues()
{
	Menu::Title("");
	Menu::Subtitle("Plaques");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 35);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 35);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 35, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 35, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Trunak()
{
	Menu::Title("");
	Menu::Subtitle("Trunk");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 37);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 37);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 37, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 37, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Hydrulicas()
{
	Menu::Title("");
	Menu::Subtitle("Hydrulics");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 38);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 38);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 38, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 38, i, 1);
					//set the veh mod
				}
			}
		}
	}

}
void Blocak()
{
	Menu::Title("");
	Menu::Subtitle("Engine Block");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 39);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 39);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 39, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 39, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Flitersa()
{
	Menu::Title("");
	Menu::Subtitle("Engine Fliters");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 40);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 40);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 40, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 40, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Strutsa()
{
	Menu::Title("");
	Menu::Subtitle("Struts");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 41);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 41);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 41, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 41, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Speakferr()
{
	Menu::Title("");
	Menu::Subtitle("Speakers");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 36);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 36);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 36, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 36, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void Livreya()
{
	Menu::Title("");
	Menu::Subtitle("Livery");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());


	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 48);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 48);

	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 48, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 48, i, 1);
					//set the veh mod
				}
			}
		}
	}

}
void Aerialsa()
{
	Menu::Title("");
	Menu::Subtitle("Aerials");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 43);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 43);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 43, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name 
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 43, i, 1);
					//set the veh mod

				}
			}
		}
	}
}
void Tanka()
{
	Menu::Title("");
	Menu::Subtitle("Tank");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vehicle VEHICLE_ID = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	char nummods = VEHICLE::GET_NUM_VEHICLE_MODS(veh, 45);
	char currmod = VEHICLE::GET_VEHICLE_MOD(veh, 45);
	for (int i = 0; i < nummods; i++)
		//gets the mod numbers
	{
		char* mod = UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, 45, i));
		//gets the name in the game set lang
		{
			if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				//only puts the names out if person in car and checks car
			{
				if (Menu::Option(mod))
					//mod puts all the name
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					//mod kit should lways be 0
					VEHICLE::SET_VEHICLE_MOD(veh, 45, i, 1);
					//set the veh mod
				}
			}
		}
	}
}
void pbrdght()
{
	Menu::Title("");
	Menu::Subtitle("Bright Colours");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	if (Menu::Option("Electric Lime")) {

		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 204, 255, 00);
		}
	}
	if (Menu::Option("Fluoresent Yellow")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 204, 255, 0);
		}
	}
	if (Menu::Option("Fuchsia")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 0, 205);
		}
	}
	if (Menu::Option("Turquoise")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 255, 0);
		}
	}
	if (Menu::Option("Silver")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 192, 192, 192);
		}
	}
	if (Menu::Option("Hot Pink")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 0, 255);
		}
	}
	if (Menu::Option("Lime Green")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 134, 236, 0);
		}
	}
	if (Menu::Option("Purple")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 137, 0, 255);
		}
	}
	if (Menu::Option("Light Blue")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 0, 191, 255);
		}
	}
	if (Menu::Option("Midnight Blue")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 25, 25, 112);
		}
	}
	if (Menu::Option("Aventador Orange")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 69, 0);
		}
	}
	if (Menu::Option("Cream")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 253, 208);
		}
	}
	if (Menu::Option("White")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 255, 255);
		}
	}
	if (Menu::Option("Green")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 43, 183, 62);
		}
	}
	if (Menu::Option("Gold")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 122, 86, 3);
		}
	}
	if (Menu::Option("Grey")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 128, 128, 128);
		}
	}
	if (Menu::Option("~o~R~y~a~r~n~p~d~b~o~g~m")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);

		}
	}
}
void sbrdight()
{
	Menu::Title("");
	Menu::Subtitle("Bright Colours");
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	if (Menu::Option("Electric Lime")) {

		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 204, 255, 00);
		}
	}
	if (Menu::Option("Fluoresent Yellow")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 204, 255, 0);
		}
	}
	if (Menu::Option("Fuchsia")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 0, 205);
		}
	}
	if (Menu::Option("Turquoise")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 255, 0);
		}
	}
	if (Menu::Option("Silver")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 192, 192, 192);
		}
	}
	if (Menu::Option("Hot Pink")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 0, 255);
		}
	}
	if (Menu::Option("Lime Green")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 134, 236, 0);
		}
	}
	if (Menu::Option("Purple")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 137, 0, 255);
		}
	}
	if (Menu::Option("Light Blue")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 0, 191, 255);
		}
	}
	if (Menu::Option("Midnight Blue")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 25, 25, 112);
		}
	}
	if (Menu::Option("Aventador Orange")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 69, 0);
		}
	}
	if (Menu::Option("Cream")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 253, 208);
		}
	}
	if (Menu::Option("White")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 255, 255, 255);
		}
	}
	if (Menu::Option("Green")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 43, 183, 62);
		}
	}
	if (Menu::Option("Gold")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 122, 86, 3);
		}
	}
	if (Menu::Option("Grey")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, 128, 128, 128);
		}
	}
	if (Menu::Option("~o~R~y~a~r~n~p~d~b~o~g~m")) {
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
		}
	}
}
void RespdrayssED()
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Menu::Title("");
	Menu::Subtitle("RGB");
	Menu::Int("RED Primary", Red, 0, 255);
	Menu::Int("GREEN Primary", Green, 0, 255);
	Menu::Int("BLUE Primary", Blue, 0, 255);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, Red, Green, Blue);
	}
	//Menu::Subtitle("Secondary");
	Menu::Int("RED Secondary", SR, 0, 255);
	Menu::Int("GREEN Secondary", SG, 0, 255);
	Menu::Int("BLUE Secondary", SB, 0, 255);
	if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, SR, SG, SB);
	}
}
void Smomke()
{
	Menu::Subtitle("Tire Smoke");
	Menu::Title("");
	Menu::MenuOption("RGB Tire smoke picker", TRGB);
	if (Menu::Option("White")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 254, 254, 254);
	}

	if (Menu::Option("Black")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 1, 1, 1);
	}

	if (Menu::Option("Blue")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 0, 0, 255);
	}

	if (Menu::Option("Yellow")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 255, 255, 0);
	}

	if (Menu::Option("Purple")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 150, 0, 255);
	}

	if (Menu::Option("Orange")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 255, 175, 0);
	}

	if (Menu::Option("Green")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 0, 255, 0);
	}

	if (Menu::Option("Red")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 255, 0, 0);
	}

	if (Menu::Option("Pink")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 255, 0, 255);
	}

	if (Menu::Option("~r~P~w~A~b~T~r~R~w~I~b~O~r~T")) {
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 0, 0, 0);
	}
}
void TRaGB()
{
	Menu::Title("");

	Menu::Subtitle("RGB Smoke Picker");
	Menu::Int("RED", TR, 0, 255);
	Menu::Int("GREEN", TG, 0, 255);
	Menu::Int("BLUE", TB, 0, 255);
	{
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, TR, TG, TB);
	}
}
void Primaaaryyy()
{
	Menu::Title("");
	Menu::Subtitle("Primary Color");
	Menu::MenuOption("Chrome", Chrome);
	Menu::MenuOption("Classic/Metallic", ClassicMetallic);
	Menu::MenuOption("Matte", Matte);
	Menu::MenuOption("Metals", Metals);
	Menu::MenuOption("pearlescent", pearlescents);
}
void Secondaryysy()
{
	Menu::Title("");
	Menu::Subtitle("Secondary Color");
	Menu::MenuOption("Chrome", Chromes);
	Menu::MenuOption("Classic/Metallic", ClassicMetallics);
	Menu::MenuOption("Matte", Mattes);
	Menu::MenuOption("Metals", Metalss);
}
void Charome()
{
	Menu::Title("");
	Menu::Subtitle("Chrome");
	int SecondaryColor, Primarycolour;
	VEHICLE::GET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), &Primarycolour, &SecondaryColor);
	VEHICLE::GET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), &Primarycolour, &SecondaryColor);
	Menu::ColourOption("Chrome", 120, SecondaryColor, false, false);
}
void ClassicMetaallic()
{
	Menu::Title("");
	Menu::Subtitle("Classic/Metallic");
	//Classic/Metallic
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int SecondaryColor, Primarycolour;
	VEHICLE::GET_VEHICLE_COLOURS(veh, &Primarycolour, &SecondaryColor);
	Menu::ColourOption("Black", 0, SecondaryColor, false, false);
	Menu::ColourOption("Carbon Black", 147, SecondaryColor, false, false);
	Menu::ColourOption("Graphite", 2, SecondaryColor, false, false);
	Menu::ColourOption("Anhracite Black", 11, SecondaryColor, false, false);
	Menu::ColourOption("Black Steel", 2, SecondaryColor, false, false);
	Menu::ColourOption("Dark Steel", 3, SecondaryColor, false, false);
	Menu::ColourOption("Silver", 4, SecondaryColor, false, false);
	Menu::ColourOption("Bluish Silver", 5, SecondaryColor, false, false);
	Menu::ColourOption("Rolled Steel", 6, SecondaryColor, false, false);
	Menu::ColourOption("Shadow Silve", 7, SecondaryColor, false, false);
	Menu::ColourOption("Stone Silver", 8, SecondaryColor, false, false);
	Menu::ColourOption("Midnight Silver", 9, SecondaryColor, false, false);
	Menu::ColourOption("Cast Iron Silver", 10, SecondaryColor, false, false);
	Menu::ColourOption("Red", 27, SecondaryColor, false, false);
	Menu::ColourOption("Torino Red", 28, SecondaryColor, false, false);
	Menu::ColourOption("Formula Red", 29, SecondaryColor, false, false);
	Menu::ColourOption("Lava Red", 150, SecondaryColor, false, false);
	Menu::ColourOption("Blaze Red", 30, SecondaryColor, false, false);
	Menu::ColourOption("Grace Red", 31, SecondaryColor, false, false);
	Menu::ColourOption("Garnet Red", 32, SecondaryColor, false, false);
	Menu::ColourOption("Sunset Red", 33, SecondaryColor, false, false);
	Menu::ColourOption("Cabernet Red", 34, SecondaryColor, false, false);
	Menu::ColourOption("Wine Red", 143, SecondaryColor, false, false);
	Menu::ColourOption("Candy Red", 35, SecondaryColor, false, false);
	Menu::ColourOption("Hot Pink", 135, SecondaryColor, false, false);
	Menu::ColourOption("Pfsiter Pink", 137, SecondaryColor, false, false);
	Menu::ColourOption("Salmon Pink", 136, SecondaryColor, false, false);
	Menu::ColourOption("Sunrise Orange", 36, SecondaryColor, false, false);
	Menu::ColourOption("Orange", 38, SecondaryColor, false, false);
	Menu::ColourOption("Bright Orange", 138, SecondaryColor, false, false);
	Menu::ColourOption("Gold", 99, SecondaryColor, false, false);
	Menu::ColourOption("Bronze", 90, SecondaryColor, false, false);
	Menu::ColourOption("Yellow", 88, SecondaryColor, false, false);
	Menu::ColourOption("Race Yellow", 89, SecondaryColor, false, false);
	Menu::ColourOption("Dew Yellow", 91, SecondaryColor, false, false);
	Menu::ColourOption("Dark Green", 49, SecondaryColor, false, false);
	Menu::ColourOption("Racing Green", 50, SecondaryColor, false, false);
	Menu::ColourOption("Sea Green", 51, SecondaryColor, false, false);
	Menu::ColourOption("Olive Green", 52, SecondaryColor, false, false);
	Menu::ColourOption("Bright Green", 53, SecondaryColor, false, false);
	Menu::ColourOption("Gasoline Green", 54, SecondaryColor, false, false);
	Menu::ColourOption("Lime Green", 92, SecondaryColor, false, false);
	Menu::ColourOption("Midnight Blue", 141, SecondaryColor, false, false);
	Menu::ColourOption("Galaxy Blue", 61, SecondaryColor, false, false);
	Menu::ColourOption("Dark Blue", 62, SecondaryColor, false, false);
	Menu::ColourOption("Saxon Blue", 63, SecondaryColor, false, false);
	Menu::ColourOption("Blue", 64, SecondaryColor, false, false);
	Menu::ColourOption("Mariner Blue", 65, SecondaryColor, false, false);
	Menu::ColourOption("Harbor Blue", 66, SecondaryColor, false, false);
	Menu::ColourOption("Diamond Blue", 67, SecondaryColor, false, false);
	Menu::ColourOption("Surf Blue", 68, SecondaryColor, false, false);
	Menu::ColourOption("Nautical Blue", 69, SecondaryColor, false, false);
	Menu::ColourOption("Racing Blue", 73, SecondaryColor, false, false);
	Menu::ColourOption("Ultra Blue", 70, SecondaryColor, false, false);
	Menu::ColourOption("Light Blue", 74, SecondaryColor, false, false);
	Menu::ColourOption("Chocolate Brown", 96, SecondaryColor, false, false);
	Menu::ColourOption("Bison Brown", 101, SecondaryColor, false, false);
	Menu::ColourOption("Creeen Brown", 95, SecondaryColor, false, false);
	Menu::ColourOption("Feltzer Brown", 94, SecondaryColor, false, false);
	Menu::ColourOption("Maple Brown", 97, SecondaryColor, false, false);
	Menu::ColourOption("Beechwood Brown", 103, SecondaryColor, false, false);
	Menu::ColourOption("Sienna Brown", 104, SecondaryColor, false, false);
	Menu::ColourOption("Saddle Brown", 98, SecondaryColor, false, false);
	Menu::ColourOption("Moss Brown", 100, SecondaryColor, false, false);
	Menu::ColourOption("Woodbeech Brown", 102, SecondaryColor, false, false);
	Menu::ColourOption("Straw Brown", 99, SecondaryColor, false, false);
	Menu::ColourOption("Sandy Brown", 105, SecondaryColor, false, false);
	Menu::ColourOption("Bleached Brown", 106, SecondaryColor, false, false);
	Menu::ColourOption("Schafter Purple", 71, SecondaryColor, false, false);
	Menu::ColourOption("Spinnaker Purple", 72, SecondaryColor, false, false);
	Menu::ColourOption("Midnight Purple", 142, SecondaryColor, false, false);
	Menu::ColourOption("Bright Purple", 145, SecondaryColor, false, false);
	Menu::ColourOption("Cream", 107, SecondaryColor, false, false);
	Menu::ColourOption("Ice White", 111, SecondaryColor, false, false);
	Menu::ColourOption("Frost White", 112, SecondaryColor, false, false);
}
void Mattae()
{
	Menu::Title("");

	Menu::Subtitle("Matte");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int SecondaryColor, Primarycolour;
	VEHICLE::GET_VEHICLE_COLOURS(veh, &Primarycolour, &SecondaryColor);
	//Mate
	Menu::ColourOption("Black", 12, SecondaryColor, false, false);
	Menu::ColourOption("Gray", 13, SecondaryColor, false, false);
	Menu::ColourOption("Light Gray", 14, SecondaryColor, false, false);
	Menu::ColourOption("Ice White", 131, SecondaryColor, false, false);
	Menu::ColourOption("Blue", 83, SecondaryColor, false, false);
	Menu::ColourOption("Dark Blue", 82, SecondaryColor, false, false);
	Menu::ColourOption("Midnight Blue", 84, SecondaryColor, false, false);
	Menu::ColourOption("Midnight Purple", 149, SecondaryColor, false, false);
	Menu::ColourOption("Schafter Purple", 148, SecondaryColor, false, false);
	Menu::ColourOption("Red", 39, SecondaryColor, false, false);
	Menu::ColourOption("Dark Red", 40, SecondaryColor, false, false);
	Menu::ColourOption("Orange", 41, SecondaryColor, false, false);
	Menu::ColourOption("Yellow", 42, SecondaryColor, false, false);
	Menu::ColourOption("Lime Green", 55, SecondaryColor, false, false);
	Menu::ColourOption("Green", 128, SecondaryColor, false, false);
	Menu::ColourOption("Forest Green", 151, SecondaryColor, false, false);
	Menu::ColourOption("Foliage Green", 155, SecondaryColor, false, false);
	Menu::ColourOption("Olive Darb", 152, SecondaryColor, false, false);
	Menu::ColourOption("Dark Earth", 153, SecondaryColor, false, false);
	Menu::ColourOption("Desert Tan", 154, SecondaryColor, false, false);
}
void Meatals()
{
	Menu::Title("");
	Menu::Subtitle("Metals");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int SecondaryColor, Primarycolour;
	VEHICLE::GET_VEHICLE_COLOURS(veh, &Primarycolour, &SecondaryColor);
	//Metals
	Menu::ColourOption("Brushed Steel", 117, SecondaryColor, false, false);
	Menu::ColourOption("Brushed Black Steel", 118, SecondaryColor, false, false);
	Menu::ColourOption("Brushed Aluminum", 119, SecondaryColor, false, false);
	Menu::ColourOption("Pure Gold", 158, SecondaryColor, false, false);
	Menu::ColourOption("Brushed Gold", 159, SecondaryColor, false, false);
}
void pearlesscents()
{
	Menu::Title("");
	Menu::Subtitle("pearlescent");
	Menu::ColourOption("Black", 0, 0, true, false);
	Menu::ColourOption("Carbon Black", 147, 0, true, false);
	Menu::ColourOption("Graphite", 2, 0, true, false);
	Menu::ColourOption("Anhracite Black", 11, 0, true, false);
	Menu::ColourOption("Black Steel", 2, 0, true, false);
	Menu::ColourOption("Dark Steel", 3, 0, true, false);
	Menu::ColourOption("Silver", 4, 0, true, false);
	Menu::ColourOption("Bluish Silver", 5, 0, true, false);
	Menu::ColourOption("Rolled Steel", 6, 0, true, false);
	Menu::ColourOption("Shadow Silve", 7, 0, true, false);
	Menu::ColourOption("Stone Silver", 8, 0, true, false);
	Menu::ColourOption("Midnight Silver", 9, 0, true, false);
	Menu::ColourOption("Cast Iron Silver", 10, 0, true, false);
	Menu::ColourOption("Red", 27, 0, true, false);
	Menu::ColourOption("Torino Red", 28, 0, true, false);
	Menu::ColourOption("Formula Red", 29, 0, true, false);
	Menu::ColourOption("Lava Red", 150, 0, true, false);
	Menu::ColourOption("Blaze Red", 30, 0, true, false);
	Menu::ColourOption("Grace Red", 31, 0, true, false);
	Menu::ColourOption("Garnet Red", 32, 0, true, false);
	Menu::ColourOption("Sunset Red", 33, 0, true, false);
	Menu::ColourOption("Cabernet Red", 34, 0, true, false);
	Menu::ColourOption("Wine Red", 143, 0, true, false);
	Menu::ColourOption("Candy Red", 35, 0, true, false);
	Menu::ColourOption("Hot Pink", 135, 0, true, false);
	Menu::ColourOption("Pfsiter Pink", 137, 0, true, false);
	Menu::ColourOption("Salmon Pink", 136, 0, true, false);
	Menu::ColourOption("Sunrise Orange", 36, 0, true, false);
	Menu::ColourOption("Orange", 38, 0, true, false);
	Menu::ColourOption("Bright Orange", 138, 0, true, false);
	Menu::ColourOption("Gold", 99, 0, true, false);
	Menu::ColourOption("Bronze", 90, 0, true, false);
	Menu::ColourOption("Yellow", 88, 0, true, false);
	Menu::ColourOption("Race Yellow", 89, 0, true, false);
	Menu::ColourOption("Dew Yellow", 91, 0, true, false);
	Menu::ColourOption("Dark Green", 49, 0, true, false);
	Menu::ColourOption("Racing Green", 50, 0, true, false);
	Menu::ColourOption("Sea Green", 51, 0, true, false);
	Menu::ColourOption("Olive Green", 52, 0, true, false);
	Menu::ColourOption("Bright Green", 53, 0, true, false);
	Menu::ColourOption("Gasoline Green", 54, 0, true, false);
	Menu::ColourOption("Lime Green", 92, 0, true, false);
	Menu::ColourOption("Midnight Blue", 141, 0, true, false);
	Menu::ColourOption("Galaxy Blue", 61, 0, true, false);
	Menu::ColourOption("Dark Blue", 62, 0, true, false);
	Menu::ColourOption("Saxon Blue", 63, 0, true, false);
	Menu::ColourOption("Blue", 64, 0, true, false);
	Menu::ColourOption("Mariner Blue", 65, 0, true, false);
	Menu::ColourOption("Harbor Blue", 66, 0, true, false);
	Menu::ColourOption("Diamond Blue", 67, 0, true, false);
	Menu::ColourOption("Surf Blue", 68, 0, true, false);
	Menu::ColourOption("Nautical Blue", 69, 0, true, false);
	Menu::ColourOption("Racing Blue", 73, 0, true, false);
	Menu::ColourOption("Ultra Blue", 70, 0, true, false);
	Menu::ColourOption("Light Blue", 74, 0, true, false);
	Menu::ColourOption("Chocolate Brown", 96, 0, true, false);
	Menu::ColourOption("Bison Brown", 101, 0, true, false);
	Menu::ColourOption("Creeen Brown", 95, 0, true, false);
	Menu::ColourOption("Feltzer Brown", 94, 0, true, false);
	Menu::ColourOption("Maple Brown", 97, 0, true, false);
	Menu::ColourOption("Beechwood Brown", 103, 0, true, false);
	Menu::ColourOption("Sienna Brown", 104, 0, true, false);
	Menu::ColourOption("Saddle Brown", 98, 0, true, false);
	Menu::ColourOption("Moss Brown", 100, 0, true, false);
	Menu::ColourOption("Woodbeech Brown", 102, 0, true, false);
	Menu::ColourOption("Straw Brown", 99, 0, true, false);
	Menu::ColourOption("Sandy Brown", 105, 0, true, false);
	Menu::ColourOption("Bleached Brown", 106, 0, true, false);
	Menu::ColourOption("Schafter Purple", 71, 0, true, false);
	Menu::ColourOption("Spinnaker Purple", 72, 0, true, false);
	Menu::ColourOption("Midnight Purple", 142, 0, true, false);
	Menu::ColourOption("Bright Purple", 145, 0, true, false);
	Menu::ColourOption("Cream", 107, 0, true, false);
	Menu::ColourOption("Ice White", 111, 0, true, false);
	Menu::ColourOption("Frost White", 112, 0, true, false);
}
void Cahromes()
{
	Menu::Title("");
	Menu::Subtitle("Chrome");
	int SecondaryColor, Primarycolour;
	VEHICLE::GET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), &Primarycolour, &SecondaryColor);
	VEHICLE::GET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), &Primarycolour, &SecondaryColor);
	Menu::ColourOption("Chrome", Primarycolour, 120, false, false);
}
void ClassicMetallaics()
{
	Menu::Title("");
	Menu::Subtitle("Classic/Metallic");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int SecondaryColor, Primarycolour;
	VEHICLE::GET_VEHICLE_COLOURS(veh, &Primarycolour, &SecondaryColor);
	Menu::ColourOption("Black", Primarycolour, 0, false, false);
	Menu::ColourOption("Carbon Black", Primarycolour, 147, false, false);
	Menu::ColourOption("Graphite", Primarycolour, 1, false, false);
	Menu::ColourOption("Anhracite Black", Primarycolour, 11, false, false);
	Menu::ColourOption("Black Steel", Primarycolour, 2, false, false);
	Menu::ColourOption("Dark Steel", Primarycolour, 3, false, false);
	Menu::ColourOption("Silver", Primarycolour, 4, false, false);
	Menu::ColourOption("Bluish Silver", Primarycolour, 5, false, false);
	Menu::ColourOption("Rolled Steel", Primarycolour, 6, false, false);
	Menu::ColourOption("Shadow Silve", Primarycolour, 7, false, false);
	Menu::ColourOption("Stone Silver", Primarycolour, 8, false, false);
	Menu::ColourOption("Midnight Silver", Primarycolour, 9, false, false);
	Menu::ColourOption("Cast Iron Silver", Primarycolour, 10, false, false);
	Menu::ColourOption("Red", Primarycolour, 27, false, false);
	Menu::ColourOption("Torino Red", Primarycolour, 28, false, false);
	Menu::ColourOption("Formula Red", Primarycolour, 29, false, false);
	Menu::ColourOption("Lava Red", Primarycolour, 150, false, false);
	Menu::ColourOption("Blaze Red", Primarycolour, 30, false, false);
	Menu::ColourOption("Grace Red", Primarycolour, 31, false, false);
	Menu::ColourOption("Garnet Red", Primarycolour, 32, false, false);
	Menu::ColourOption("Sunset Red", Primarycolour, 33, false, false);
	Menu::ColourOption("Cabernet Red", Primarycolour, 34, false, false);
	Menu::ColourOption("Wine Red", Primarycolour, 143, false, false);
	Menu::ColourOption("Candy Red", Primarycolour, 35, false, false);
	Menu::ColourOption("Hot Pink", Primarycolour, 135, false, false);
	Menu::ColourOption("Pfsiter Pink", Primarycolour, 137, false, false);
	Menu::ColourOption("Salmon Pink", Primarycolour, 136, false, false);
	Menu::ColourOption("Sunrise Orange", Primarycolour, 36, false, false);
	Menu::ColourOption("Orange", Primarycolour, 38, false, false);
	Menu::ColourOption("Bright Orange", Primarycolour, 138, false, false);
	Menu::ColourOption("Gold", Primarycolour, 99, false, false);
	Menu::ColourOption("Bronze", Primarycolour, 90, false, false);
	Menu::ColourOption("Yellow", Primarycolour, 88, false, false);
	Menu::ColourOption("Race Yellow", Primarycolour, 89, false, false);
	Menu::ColourOption("Dew Yellow", Primarycolour, 91, false, false);
	Menu::ColourOption("Dark Green", Primarycolour, 49, false, false);
	Menu::ColourOption("Racing Green", Primarycolour, 50, false, false);
	Menu::ColourOption("Sea Green", Primarycolour, 51, false, false);
	Menu::ColourOption("Olive Green", Primarycolour, 52, false, false);
	Menu::ColourOption("Bright Green", Primarycolour, 53, false, false);
	Menu::ColourOption("Gasoline Green", Primarycolour, 54, false, false);
	Menu::ColourOption("Lime Green", Primarycolour, 92, false, false);
	Menu::ColourOption("Midnight Blue", Primarycolour, 141, false, false);
	Menu::ColourOption("Galaxy Blue", Primarycolour, 61, false, false);
	Menu::ColourOption("Dark Blue", Primarycolour, 62, false, false);
	Menu::ColourOption("Saxon Blue", Primarycolour, 63, false, false);
	Menu::ColourOption("Blue", Primarycolour, 64, false, false);
	Menu::ColourOption("Mariner Blue", Primarycolour, 65, false, false);
	Menu::ColourOption("Harbor Blue", Primarycolour, 66, false, false);
	Menu::ColourOption("Diamond Blue", Primarycolour, 67, false, false);
	Menu::ColourOption("Surf Blue", Primarycolour, 68, false, false);
	Menu::ColourOption("Nautical Blue", Primarycolour, 69, false, false);
	Menu::ColourOption("Racing Blue", Primarycolour, 73, false, false);
	Menu::ColourOption("Ultra Blue", Primarycolour, 70, false, false);
	Menu::ColourOption("Light Blue", Primarycolour, 74, false, false);
	Menu::ColourOption("Chocolate Brown", Primarycolour, 96, false, false);
	Menu::ColourOption("Bison Brown", Primarycolour, 101, false, false);
	Menu::ColourOption("Creeen Brown", Primarycolour, 95, false, false);
	Menu::ColourOption("Feltzer Brown", Primarycolour, 94, false, false);
	Menu::ColourOption("Maple Brown", Primarycolour, 97, false, false);
	Menu::ColourOption("Beechwood Brown", Primarycolour, 103, false, false);
	Menu::ColourOption("Sienna Brown", Primarycolour, 104, false, false);
	Menu::ColourOption("Saddle Brown", Primarycolour, 98, false, false);
	Menu::ColourOption("Moss Brown", Primarycolour, 100, false, false);
	Menu::ColourOption("Woodbeech Brown", Primarycolour, 102, false, false);
	Menu::ColourOption("Straw Brown", Primarycolour, 99, false, false);
	Menu::ColourOption("Sandy Brown", Primarycolour, 105, false, false);
	Menu::ColourOption("Bleached Brown", Primarycolour, 106, false, false);
	Menu::ColourOption("Schafter Purple", Primarycolour, 71, false, false);
	Menu::ColourOption("Spinnaker Purple", Primarycolour, 72, false, false);
	Menu::ColourOption("Midnight Purple", Primarycolour, 142, false, false);
	Menu::ColourOption("Bright Purple", Primarycolour, 145, false, false);
	Menu::ColourOption("Cream", Primarycolour, 107, false, false);
	Menu::ColourOption("Ice White", Primarycolour, 111, false, false);
	Menu::ColourOption("Frost White", Primarycolour, 112, false, false);
}
void Matteas()
{
	Menu::Title("");

	Menu::Subtitle("Matte");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int SecondaryColor, Primarycolour;
	VEHICLE::GET_VEHICLE_COLOURS(veh, &Primarycolour, &SecondaryColor);
	//Mate
	Menu::ColourOption("Black", Primarycolour, 12, false, false);
	Menu::ColourOption("Gray", Primarycolour, 13, false, false);
	Menu::ColourOption("Light Gray", Primarycolour, 14, false, false);
	Menu::ColourOption("Ice White", Primarycolour, 131, false, false);
	Menu::ColourOption("Blue", Primarycolour, 83, false, false);
	Menu::ColourOption("Dark Blue", Primarycolour, 82, false, false);
	Menu::ColourOption("Midnight Blue", Primarycolour, 84, false, false);
	Menu::ColourOption("Midnight Purple", Primarycolour, 149, false, false);
	Menu::ColourOption("Schafter Purple", Primarycolour, 148, false, false);
	Menu::ColourOption("Red", Primarycolour, 39, false, false);
	Menu::ColourOption("Dark Red", Primarycolour, 40, false, false);
	Menu::ColourOption("Orange", Primarycolour, 41, false, false);
	Menu::ColourOption("Yellow", Primarycolour, 42, false, false);
	Menu::ColourOption("Lime Green", Primarycolour, 55, false, false);
	Menu::ColourOption("Green", Primarycolour, 128, false, false);
	Menu::ColourOption("Forest Green", Primarycolour, 151, false, false);
	Menu::ColourOption("Foliage Green", Primarycolour, 155, false, false);
	Menu::ColourOption("Olive Darb", Primarycolour, 152, false, false);
	Menu::ColourOption("Dark Earth", Primarycolour, 153, false, false);
	Menu::ColourOption("Desert Tan", Primarycolour, 154, false, false);
}
void Metaalss()
{
	Menu::Title("");

	Menu::Subtitle("Metals");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	int SecondaryColor, Primarycolour;
	VEHICLE::GET_VEHICLE_COLOURS(veh, &Primarycolour, &SecondaryColor);
	//Metals
	Menu::ColourOption("Brushed Steel", Primarycolour, 117, false, false);
	Menu::ColourOption("Brushed Black Steel", Primarycolour, 118, false, false);
	Menu::ColourOption("Brushed Aluminum", Primarycolour, 119, false, false);
	Menu::ColourOption("Pure Gold", Primarycolour, 158, false, false);
	Menu::ColourOption("Brushed Gold", Primarycolour, 159, false, false);
}
void WheelColour()
{
	Menu::Title("");
	Menu::Subtitle("Wheel Colours");
	//Menu::ColourOption("Chrome", 120, 0, false, true); dont fucking work
	Menu::ColourOption("Black", 0, 0, false, true);
	Menu::ColourOption("Carbon Black", 147, 0, false, true);
	Menu::ColourOption("Graphite", 2, 0, false, true);
	Menu::ColourOption("Anhracite Black", 11, 0, false, true);
	Menu::ColourOption("Black Steel", 2, 0, false, true);
	Menu::ColourOption("Dark Steel", 3, 0, false, true);
	Menu::ColourOption("Silver", 4, 0, false, true);
	Menu::ColourOption("Bluish Silver", 5, 0, false, true);
	Menu::ColourOption("Rolled Steel", 6, 0, false, true);
	Menu::ColourOption("Shadow Silve", 7, 0, false, true);
	Menu::ColourOption("Stone Silver", 8, 0, false, true);
	Menu::ColourOption("Midnight Silver", 9, 0, false, true);
	Menu::ColourOption("Cast Iron Silver", 10, 0, false, true);
	Menu::ColourOption("Red", 27, 0, false, true);
	Menu::ColourOption("Torino Red", 28, 0, false, true);
	Menu::ColourOption("Formula Red", 29, 0, false, true);
	Menu::ColourOption("Lava Red", 150, 0, false, true);
	Menu::ColourOption("Blaze Red", 30, 0, false, true);
	Menu::ColourOption("Grace Red", 31, 0, false, true);
	Menu::ColourOption("Garnet Red", 32, 0, false, true);
	Menu::ColourOption("Sunset Red", 33, 0, false, true);
	Menu::ColourOption("Cabernet Red", 34, 0, false, true);
	Menu::ColourOption("Wine Red", 143, 0, false, true);
	Menu::ColourOption("Candy Red", 35, 0, false, true);
	Menu::ColourOption("Hot Pink", 135, 0, false, true);
	Menu::ColourOption("Pfsiter Pink", 137, 0, false, true);
	Menu::ColourOption("Salmon Pink", 136, 0, false, true);
	Menu::ColourOption("Sunrise Orange", 36, 0, false, true);
	Menu::ColourOption("Orange", 38, 0, false, true);
	Menu::ColourOption("Bright Orange", 138, 0, false, true);
	Menu::ColourOption("Gold", 99, 0, false, true);
	Menu::ColourOption("Bronze", 90, 0, false, true);
	Menu::ColourOption("Yellow", 88, 0, false, true);
	Menu::ColourOption("Race Yellow", 89, 0, false, true);
	Menu::ColourOption("Dew Yellow", 91, 0, false, true);
	Menu::ColourOption("Dark Green", 49, 0, false, true);
	Menu::ColourOption("Racing Green", 50, 0, false, true);
	Menu::ColourOption("Sea Green", 51, 0, false, true);
	Menu::ColourOption("Olive Green", 52, 0, false, true);
	Menu::ColourOption("Bright Green", 53, 0, false, true);
	Menu::ColourOption("Gasoline Green", 54, 0, false, true);
	Menu::ColourOption("Lime Green", 92, 0, false, true);
	Menu::ColourOption("Midnight Blue", 141, 0, false, true);
	Menu::ColourOption("Galaxy Blue", 61, 0, false, true);
	Menu::ColourOption("Dark Blue", 62, 0, false, true);
	Menu::ColourOption("Saxon Blue", 63, 0, false, true);
	Menu::ColourOption("Blue", 64, 0, false, true);
	Menu::ColourOption("Mariner Blue", 65, 0, false, true);
	Menu::ColourOption("Harbor Blue", 66, 0, false, true);
	Menu::ColourOption("Diamond Blue", 67, 0, false, true);
	Menu::ColourOption("Surf Blue", 68, 0, false, true);
	Menu::ColourOption("Nautical Blue", 69, 0, false, true);
	Menu::ColourOption("Racing Blue", 73, 0, false, true);
	Menu::ColourOption("Ultra Blue", 70, 0, false, true);
	Menu::ColourOption("Light Blue", 74, 0, false, true);
	Menu::ColourOption("Chocolate Brown", 96, 0, false, true);
	Menu::ColourOption("Bison Brown", 101, 0, false, true);
	Menu::ColourOption("Creeen Brown", 95, 0, false, true);
	Menu::ColourOption("Feltzer Brown", 94, 0, false, true);
	Menu::ColourOption("Maple Brown", 97, 0, false, true);
	Menu::ColourOption("Beechwood Brown", 103, 0, false, true);
	Menu::ColourOption("Sienna Brown", 104, 0, false, true);
	Menu::ColourOption("Saddle Brown", 98, 0, false, true);
	Menu::ColourOption("Moss Brown", 100, 0, false, true);
	Menu::ColourOption("Woodbeech Brown", 102, 0, false, true);
	Menu::ColourOption("Straw Brown", 99, 0, false, true);
	Menu::ColourOption("Sandy Brown", 105, 0, false, true);
	Menu::ColourOption("Bleached Brown", 106, 0, false, true);
	Menu::ColourOption("Schafter Purple", 71, 0, false, true);
	Menu::ColourOption("Spinnaker Purple", 72, 0, false, true);
	Menu::ColourOption("Midnight Purple", 142, 0, false, true);
	Menu::ColourOption("Bright Purple", 145, 0, false, true);
	Menu::ColourOption("Cream", 107, 0, false, true);
	Menu::ColourOption("Ice White", 111, 0, false, true);
	Menu::ColourOption("Frost White", 112, 0, false, true);
}
void Tunerrimss()
{
	Menu::Title("");
	Menu::Subtitle("Tuner");
	if (!chrome_wheels) {

		Menu::WheelOption("Cosmo", 5, 0, custom_Wheels);
		Menu::WheelOption("Super Mesh", 5, 1, custom_Wheels);
		Menu::WheelOption("Outsider", 5, 2, custom_Wheels);
		Menu::WheelOption("Rollas", 5, 3, custom_Wheels);
		Menu::WheelOption("Drffmeister", 5, 4, custom_Wheels);
		Menu::WheelOption("Slicer", 5, 5, custom_Wheels);
		Menu::WheelOption("El Quatro", 5, 6, custom_Wheels);
		Menu::WheelOption("Dubbed", 5, 7, custom_Wheels);
		Menu::WheelOption("Five Star", 5, 8, custom_Wheels);
		Menu::WheelOption("Five Star", 5, 9, custom_Wheels);
		Menu::WheelOption("Slideways", 5, 10, custom_Wheels);
		Menu::WheelOption("Apex", 5, 11, custom_Wheels);
		Menu::WheelOption("Stanced EG", 5, 12, custom_Wheels);
		Menu::WheelOption("Countersteer", 5, 13, custom_Wheels);
		Menu::WheelOption("Endo v.1", 5, 14, custom_Wheels);
		Menu::WheelOption("Endo v.2", 5, 15, custom_Wheels);
		Menu::WheelOption("Gruppe Z", 5, 16, custom_Wheels);
		Menu::WheelOption("Choku-Dori", 5, 17, custom_Wheels);
		Menu::WheelOption("Chicane", 5, 18, custom_Wheels);
		Menu::WheelOption("Saisoku", 5, 19, custom_Wheels);
		Menu::WheelOption("Dished Eight", 5, 20, custom_Wheels);
		Menu::WheelOption("Fujiwara", 5, 21, custom_Wheels);
		Menu::WheelOption("Zokusha", 5, 22, custom_Wheels);
		Menu::WheelOption("Battle VIII", 5, 23, custom_Wheels);
		Menu::WheelOption("Rally Master", 5, 24, custom_Wheels);
	}
	if (chrome_wheels) {

		Menu::WheelOption("Cosmo", 5, 25, custom_Wheels);
		Menu::WheelOption("Super Mesh", 5, 26, custom_Wheels);
		Menu::WheelOption("Outsider", 5, 27, custom_Wheels);
		Menu::WheelOption("Rollas", 5, 28, custom_Wheels);
		Menu::WheelOption("Drffmeister", 5, 29, custom_Wheels);
		Menu::WheelOption("Slicer", 5, 30, custom_Wheels);
		Menu::WheelOption("El Quatro", 5, 31, custom_Wheels);
		Menu::WheelOption("Dubbed", 5, 32, custom_Wheels);
		Menu::WheelOption("Five Star", 5, 33, custom_Wheels);
		Menu::WheelOption("Five Star", 5, 34, custom_Wheels);
		Menu::WheelOption("Slideways", 5, 35, custom_Wheels);
		Menu::WheelOption("Apex", 5, 36, custom_Wheels);
		Menu::WheelOption("Stanced EG", 5, 37, custom_Wheels);
		Menu::WheelOption("Countersteer", 5, 38, custom_Wheels);
		Menu::WheelOption("Endo v.1", 5, 39, custom_Wheels);
		Menu::WheelOption("Endo v.2", 5, 40, custom_Wheels);
		Menu::WheelOption("Gruppe Z", 5, 41, custom_Wheels);
		Menu::WheelOption("Choku-Dori", 5, 42, custom_Wheels);
		Menu::WheelOption("Chicane", 5, 43, custom_Wheels);
		Menu::WheelOption("Saisoku", 5, 44, custom_Wheels);
		Menu::WheelOption("Dished Eight", 5, 45, custom_Wheels);
		Menu::WheelOption("Fujiwara", 5, 46, custom_Wheels);
		Menu::WheelOption("Zokusha", 5, 47, custom_Wheels);
		Menu::WheelOption("Battle VIII", 5, 48, custom_Wheels);
		Menu::WheelOption("Rally Master", 5, 49, custom_Wheels);
	}
}
void auscalerims()
{
	Menu::Title("");
	Menu::Subtitle("Muscle");
	if (!chrome_wheels) {

		Menu::WheelOption("Classic Five", 1, 0, custom_Wheels);
		Menu::WheelOption("Dukes", 1, 1, custom_Wheels);
		Menu::WheelOption("Muscle Freak", 1, 2, custom_Wheels);
		Menu::WheelOption("Kracka", 1, 3, custom_Wheels);
		Menu::WheelOption("Azreal", 1, 4, custom_Wheels);
		Menu::WheelOption("Mecha", 1, 5, custom_Wheels);
		Menu::WheelOption("Black Top", 1, 6, custom_Wheels);
		Menu::WheelOption("Drag SPL", 1, 7, custom_Wheels);
		Menu::WheelOption("Revolver", 1, 8, custom_Wheels);
		Menu::WheelOption("Classic Rod", 1, 9, custom_Wheels);
		Menu::WheelOption("Fairle", 1, 10, custom_Wheels);
		Menu::WheelOption("Spooner", 1, 11, custom_Wheels);
		Menu::WheelOption("Five Star", 1, 12, custom_Wheels);
		Menu::WheelOption("Old School", 1, 13, custom_Wheels);
		Menu::WheelOption("El Jefe", 1, 14, custom_Wheels);
		Menu::WheelOption("Dodman", 1, 15, custom_Wheels);
		Menu::WheelOption("Six Gun", 1, 16, custom_Wheels);
		Menu::WheelOption("Mercenary", 1, 17, custom_Wheels);
	}
	if (chrome_wheels) {

		Menu::WheelOption("Classic Five", 1, 18, custom_Wheels);
		Menu::WheelOption("Dukes", 1, 19, custom_Wheels);
		Menu::WheelOption("Muscle Freak", 1, 20, custom_Wheels);
		Menu::WheelOption("Kracka", 1, 21, custom_Wheels);
		Menu::WheelOption("Azreal", 1, 22, custom_Wheels);
		Menu::WheelOption("Mecha", 1, 24, custom_Wheels);
		Menu::WheelOption("Black Top", 1, 25, custom_Wheels);
		Menu::WheelOption("Drag SPL", 1, 26, custom_Wheels);
		Menu::WheelOption("Revolver", 1, 27, custom_Wheels);
		Menu::WheelOption("Classic Rod", 1, 28, custom_Wheels);
		Menu::WheelOption("Fairle", 1, 29, custom_Wheels);
		Menu::WheelOption("Spooner", 1, 30, custom_Wheels);
		Menu::WheelOption("Five Star", 1, 31, custom_Wheels);
		Menu::WheelOption("Old School", 1, 32, custom_Wheels);
		Menu::WheelOption("El Jefe", 1, 33, custom_Wheels);
		Menu::WheelOption("Dodman", 1, 34, custom_Wheels);
		Menu::WheelOption("Six Gun", 1, 35, custom_Wheels);
		Menu::WheelOption("Mercenary", 1, 36, custom_Wheels);
	}
}
void Hdghendrims()
{
	Menu::Title("");
	Menu::Subtitle("Highend");//7

	if (!chrome_wheels) {

		Menu::WheelOption("Shadow", 7, 0, custom_Wheels);
		Menu::WheelOption("Hypher", 7, 1, custom_Wheels);
		Menu::WheelOption("Blade", 7, 2, custom_Wheels);
		Menu::WheelOption("Diamond", 7, 3, custom_Wheels);
		Menu::WheelOption("Supa Gee", 7, 4, custom_Wheels);
		Menu::WheelOption("Chromatic Z", 7, 5, custom_Wheels);
		Menu::WheelOption("Mercie ch.Lip", 7, 6, custom_Wheels);
		Menu::WheelOption("Obey RS", 7, 7, custom_Wheels);
		Menu::WheelOption("GT Chrome", 7, 8, custom_Wheels);
		Menu::WheelOption("Cheetah R", 7, 9, custom_Wheels);
		Menu::WheelOption("Solar", 7, 10, custom_Wheels);
		Menu::WheelOption("Split Ten", 7, 11, custom_Wheels);
		Menu::WheelOption("Dash VIP", 7, 12, custom_Wheels);
		Menu::WheelOption("LozspeedTen", 7, 13, custom_Wheels);
		Menu::WheelOption("Carbon Inferno", 7, 14, custom_Wheels);
		Menu::WheelOption("Carbon Shadow", 7, 15, custom_Wheels);
		Menu::WheelOption("Carbon Z", 7, 16, custom_Wheels);
		Menu::WheelOption("Carbon Cheetah R", 7, 17, custom_Wheels);
		Menu::WheelOption("Carbon S Racer", 7, 18, custom_Wheels);
		Menu::WheelOption("Carbon S Racer", 7, 19, custom_Wheels);
	}
	if (chrome_wheels) {
		Menu::WheelOption("Shadow", 7, 20, custom_Wheels);
		Menu::WheelOption("Hypher", 7, 21, custom_Wheels);
		Menu::WheelOption("Blade", 7, 22, custom_Wheels);
		Menu::WheelOption("Diamond", 7, 23, custom_Wheels);
		Menu::WheelOption("Supa Gee", 7, 24, custom_Wheels);
		Menu::WheelOption("Chromatic Z", 7, 25, custom_Wheels);
		Menu::WheelOption("Mercie ch.Lip", 7, 26, custom_Wheels);
		Menu::WheelOption("Obey RS", 7, 27, custom_Wheels);
		Menu::WheelOption("GT Chrome", 7, 28, custom_Wheels);
		Menu::WheelOption("Cheetah R", 7, 29, custom_Wheels);
		Menu::WheelOption("Solar", 7, 30, custom_Wheels);
		Menu::WheelOption("Split Ten", 7, 31, custom_Wheels);
		Menu::WheelOption("Dash VIP", 7, 0, custom_Wheels);
		Menu::WheelOption("LozspeedTen", 7, 32, custom_Wheels);
		Menu::WheelOption("Carbon Inferno", 7, 33, custom_Wheels);
		Menu::WheelOption("Carbon Shadow", 7, 34, custom_Wheels);
		Menu::WheelOption("Carbon Z", 7, 35, custom_Wheels);
		Menu::WheelOption("Carbon Cheetah R", 7, 36, custom_Wheels);
		Menu::WheelOption("Carbon S Racer", 7, 37, custom_Wheels);
		Menu::WheelOption("Carbon S Racer", 7, 38, custom_Wheels);
	}
}
void SUVrisms()
{

	Menu::Title("");
	Menu::Subtitle("SUV");
	if (!chrome_wheels) {
		Menu::WheelOption("VIP", 3, 0, custom_Wheels);
		Menu::WheelOption("Benefactor", 3, 1, custom_Wheels);
		Menu::WheelOption("Cosmo", 3, 2, custom_Wheels);
		Menu::WheelOption("Bippu", 3, 3, custom_Wheels);
		Menu::WheelOption("Royal Six", 3, 4, custom_Wheels);
		Menu::WheelOption("Fagorme", 3, 5, custom_Wheels);
		Menu::WheelOption("Deluxe", 3, 6, custom_Wheels);
		Menu::WheelOption("Iced Out", 3, 7, custom_Wheels);
		Menu::WheelOption("Cognoscenti", 3, 8, custom_Wheels);
		Menu::WheelOption("LozSpeed Ten", 3, 9, custom_Wheels);
		Menu::WheelOption("Supernova", 3, 10, custom_Wheels);
		Menu::WheelOption("Obey RS", 3, 11, custom_Wheels);
		Menu::WheelOption("LozSpeed Baller", 3, 12, custom_Wheels);
		Menu::WheelOption("Extravaganzo", 3, 13, custom_Wheels);
		Menu::WheelOption("Split Six", 3, 14, custom_Wheels);
		Menu::WheelOption("Empowered", 3, 15, custom_Wheels);
		Menu::WheelOption("Sunrise", 3, 16, custom_Wheels);
		Menu::WheelOption("Dash VIP", 3, 17, custom_Wheels);
		Menu::WheelOption("Cutter", 3, 18, custom_Wheels);
	}
	if (chrome_wheels) {
		Menu::WheelOption("VIP", 3, 19, custom_Wheels);
		Menu::WheelOption("Benefactor", 3, 20, custom_Wheels);
		Menu::WheelOption("Cosmo", 3, 21, custom_Wheels);
		Menu::WheelOption("Bippu", 3, 22, custom_Wheels);
		Menu::WheelOption("Royal Six", 3, 23, custom_Wheels);
		Menu::WheelOption("Fagorme", 3, 24, custom_Wheels);
		Menu::WheelOption("Deluxe", 3, 25, custom_Wheels);
		Menu::WheelOption("Iced Out", 3, 26, custom_Wheels);
		Menu::WheelOption("Cognoscenti", 3, 27, custom_Wheels);
		Menu::WheelOption("LozSpeed Ten", 3, 28, custom_Wheels);
		Menu::WheelOption("Supernova", 3, 29, custom_Wheels);
		Menu::WheelOption("Obey RS", 3, 30, custom_Wheels);
		Menu::WheelOption("LozSpeed Baller", 3, 31, custom_Wheels);
		Menu::WheelOption("Extravaganzo", 3, 32, custom_Wheels);
		Menu::WheelOption("Split Six", 3, 33, custom_Wheels);
		Menu::WheelOption("Empowered", 3, 34, custom_Wheels);
		Menu::WheelOption("Sunrise", 3, 35, custom_Wheels);
		Menu::WheelOption("Dash VIP", 3, 36, custom_Wheels);
		Menu::WheelOption("Cutter", 3, 37, custom_Wheels);
	}

}
void Lowrisderrims()
{
	Menu::Title("");
	Menu::Subtitle("Lowrider");
	if (!chrome_wheels) {
		Menu::WheelOption("Flare", 2, 0, custom_Wheels);
		Menu::WheelOption("Wired", 2, 1, custom_Wheels);
		Menu::WheelOption("Triple Golds", 2, 2, custom_Wheels);
		Menu::WheelOption("Big Worm", 2, 3, custom_Wheels);
		Menu::WheelOption("Seven Fives", 2, 4, custom_Wheels);
		Menu::WheelOption("Split Six", 2, 5, custom_Wheels);
		Menu::WheelOption("Fresh Mesh", 2, 6, custom_Wheels);
		Menu::WheelOption("Lead Sled", 2, 7, custom_Wheels);
		Menu::WheelOption("Turbine", 2, 8, custom_Wheels);
		Menu::WheelOption("Super Fin", 2, 9, custom_Wheels);
		Menu::WheelOption("Classic Rod", 2, 10, custom_Wheels);
		Menu::WheelOption("Dollar", 2, 11, custom_Wheels);
		Menu::WheelOption("Dukes", 2, 12, custom_Wheels);
		Menu::WheelOption("Low Five", 2, 13, custom_Wheels);
		Menu::WheelOption("Gooch", 2, 14, custom_Wheels);
	}
	if (chrome_wheels) {
		Menu::WheelOption("Flare", 2, 15, custom_Wheels);
		Menu::WheelOption("Wired", 2, 16, custom_Wheels);
		Menu::WheelOption("Triple Golds", 2, 17, custom_Wheels);
		Menu::WheelOption("Big Worm", 2, 18, custom_Wheels);
		Menu::WheelOption("Seven Fives", 2, 19, custom_Wheels);
		Menu::WheelOption("Split Six", 2, 20, custom_Wheels);
		Menu::WheelOption("Fresh Mesh", 2, 21, custom_Wheels);
		Menu::WheelOption("Lead Sled", 2, 22, custom_Wheels);
		Menu::WheelOption("Turbine", 2, 23, custom_Wheels);
		Menu::WheelOption("Super Fin", 2, 24, custom_Wheels);
		Menu::WheelOption("Classic Rod", 2, 25, custom_Wheels);
		Menu::WheelOption("Dollar", 2, 26, custom_Wheels);
		Menu::WheelOption("Dukes", 2, 27, custom_Wheels);
		Menu::WheelOption("Low Five", 2, 28, custom_Wheels);
		Menu::WheelOption("Gooch", 2, 29, custom_Wheels);
	}
}
void Sportrsims()
{

	Menu::Title("");//0
	Menu::Subtitle("Sports");
	if (!chrome_wheels) {
		Menu::WheelOption("Inferno", 0, 0, custom_Wheels);
		Menu::WheelOption("Deep Five", 0, 1, custom_Wheels);
		Menu::WheelOption("Lozspeed Mk.v", 0, 2, custom_Wheels);
		Menu::WheelOption("Diamond Cut", 0, 3, custom_Wheels);
		Menu::WheelOption("Chrono", 0, 4, custom_Wheels);
		Menu::WheelOption("Feroci RR", 0, 5, custom_Wheels);
		Menu::WheelOption("FiftyNine", 0, 6, custom_Wheels);
		Menu::WheelOption("Mercie", 0, 7, custom_Wheels);
		Menu::WheelOption("Synthetic Z", 0, 8, custom_Wheels);
		Menu::WheelOption("Organic Type 0", 0, 9, custom_Wheels);
		Menu::WheelOption("Endo v.1", 0, 10, custom_Wheels);
		Menu::WheelOption("GT One", 0, 11, custom_Wheels);
		Menu::WheelOption("Duper 7", 0, 12, custom_Wheels);
		Menu::WheelOption("Uzer", 0, 13, custom_Wheels);
		Menu::WheelOption("GroundRide", 0, 14, custom_Wheels);
		Menu::WheelOption("S Racer", 0, 15, custom_Wheels);
		Menu::WheelOption("Venum", 0, 16, custom_Wheels);
		Menu::WheelOption("Cosmo", 0, 17, custom_Wheels);
		Menu::WheelOption("Dash VIP", 0, 18, custom_Wheels);
		Menu::WheelOption("Ice Kid", 0, 19, custom_Wheels);
		Menu::WheelOption("Ruff Weld", 0, 20, custom_Wheels);
		Menu::WheelOption("Wangen Master", 0, 21, custom_Wheels);
		Menu::WheelOption("Super Five", 0, 22, custom_Wheels);
		Menu::WheelOption("Endo v.2", 0, 23, custom_Wheels);
		Menu::WheelOption("Slit Six", 0, 24, custom_Wheels);
	}
	if (chrome_wheels) {

		Menu::WheelOption("Inferno", 0, 25, custom_Wheels);
		Menu::WheelOption("Deep Five", 0, 26, custom_Wheels);
		Menu::WheelOption("Lozspeed Mk.v", 0, 27, custom_Wheels);
		Menu::WheelOption("Diamond Cut", 0, 28, custom_Wheels);
		Menu::WheelOption("Chrono", 0, 29, custom_Wheels);
		Menu::WheelOption("Feroci RR", 0, 30, custom_Wheels);
		Menu::WheelOption("FiftyNine", 0, 31, custom_Wheels);
		Menu::WheelOption("Mercie", 0, 32, custom_Wheels);
		Menu::WheelOption("Synthetic Z", 0, 33, custom_Wheels);
		Menu::WheelOption("Organic Type 0", 0, 34, custom_Wheels);
		Menu::WheelOption("Endo v.1", 0, 35, custom_Wheels);
		Menu::WheelOption("GT One", 0, 36, custom_Wheels);
		Menu::WheelOption("Duper 7", 0, 37, custom_Wheels);
		Menu::WheelOption("Uzer", 0, 38, custom_Wheels);
		Menu::WheelOption("GroundRide", 0, 39, custom_Wheels);
		Menu::WheelOption("S Racer", 0, 40, custom_Wheels);
		Menu::WheelOption("Venum", 0, 41, custom_Wheels);
		Menu::WheelOption("Cosmo", 0, 42, custom_Wheels);
		Menu::WheelOption("Dash VIP", 0, 43, custom_Wheels);
		Menu::WheelOption("Ice Kid", 0, 44, custom_Wheels);
		Menu::WheelOption("Ruff Weld", 0, 45, custom_Wheels);
		Menu::WheelOption("Wangen Master", 0, 46, custom_Wheels);
		Menu::WheelOption("Super Five", 0, 47, custom_Wheels);
		Menu::WheelOption("Endo v.2", 0, 48, custom_Wheels);
		Menu::WheelOption("Slit Six", 0, 49, custom_Wheels);
	}



}
void Oaffroadrims()
{

	Menu::Title("");
	Menu::Subtitle("Off road");
	if (!chrome_wheels) {

		Menu::WheelOption("Raider", 4, 0, custom_Wheels);
		Menu::WheelOption("Mudslinger", 4, 1, custom_Wheels);
		Menu::WheelOption("Nevis", 4, 2, custom_Wheels);
		Menu::WheelOption("Cairngorm", 4, 3, custom_Wheels);
		Menu::WheelOption("Amazon", 4, 4, custom_Wheels);
		Menu::WheelOption("Challenger", 4, 5, custom_Wheels);
		Menu::WheelOption("Dune Basher", 4, 6, custom_Wheels);
		Menu::WheelOption("Five Star", 4, 7, custom_Wheels);
		Menu::WheelOption("Rock Crawler", 4, 8, custom_Wheels);
		Menu::WheelOption("Mil Spec Steelie", 4, 9, custom_Wheels);
	}
	if (chrome_wheels) {

		Menu::WheelOption("Raider", 4, 10, custom_Wheels);
		Menu::WheelOption("Mudslinger", 4, 11, custom_Wheels);
		Menu::WheelOption("Nevis", 4, 12, custom_Wheels);
		Menu::WheelOption("Cairngorm", 4, 13, custom_Wheels);
		Menu::WheelOption("Amazon", 4, 14, custom_Wheels);
		Menu::WheelOption("Challenger", 4, 15, custom_Wheels);
		Menu::WheelOption("Dune Basher", 4, 16, custom_Wheels);
		Menu::WheelOption("Five Star", 4, 17, custom_Wheels);
		Menu::WheelOption("Rock Crawler", 4, 18, custom_Wheels);
		Menu::WheelOption("Mil Spec Steelie", 4, 19, custom_Wheels);
	}
}
#pragma endregion