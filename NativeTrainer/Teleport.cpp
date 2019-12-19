#include "MAIN.h"

Vector3 TPCoords;
std::vector<Entity> _nearbyPeds, _nearbyVehicles, _worldPeds, _worldVehicles, _worldObjects, _worldEntities;
bool way = true;
void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}

void ipl()
{
	Menu::Title("IPLs");
	if (Menu::Option("North Yankton")) {
		STREAMING::REQUEST_IPL("prologue01");
		STREAMING::REQUEST_IPL("Prologue01c");
		STREAMING::REQUEST_IPL("Prologue01d");
		STREAMING::REQUEST_IPL("Prologue01e");
		STREAMING::REQUEST_IPL("Prologue01f");
		STREAMING::REQUEST_IPL("Prologue01g");
		STREAMING::REQUEST_IPL("prologue01h");
		STREAMING::REQUEST_IPL("prologue01i");
		STREAMING::REQUEST_IPL("prologue01j");
		STREAMING::REQUEST_IPL("prologue01k");
		STREAMING::REQUEST_IPL("prologue01z");
		STREAMING::REQUEST_IPL("prologue02");
		STREAMING::REQUEST_IPL("prologue03");
		STREAMING::REQUEST_IPL("prologue03b");
		STREAMING::REQUEST_IPL("prologue03_grv_cov");
		STREAMING::REQUEST_IPL("prologue03_grv_dug");
		STREAMING::REQUEST_IPL("prologue03_grv_fun");
		STREAMING::REQUEST_IPL("prologue04");
		STREAMING::REQUEST_IPL("prologue04b");
		STREAMING::REQUEST_IPL("prologue04_cover");
		STREAMING::REQUEST_IPL("prologue05");
		STREAMING::REQUEST_IPL("prologue05b");
		STREAMING::REQUEST_IPL("prologue06");
		STREAMING::REQUEST_IPL("prologue06b");
		STREAMING::REQUEST_IPL("prologue06_int");
		STREAMING::REQUEST_IPL("prologuerd");
		STREAMING::REQUEST_IPL("prologuerdb");
		STREAMING::REQUEST_IPL("prologue_DistantLights");
		STREAMING::REQUEST_IPL("prologue_grv_torch");
		STREAMING::REQUEST_IPL("prologue_m2_door");
		STREAMING::REQUEST_IPL("prologue_LODLights");
		STREAMING::REQUEST_IPL("DES_ProTree_start");
		notifyMap("~G~North ~G~Yankton ~G~Loaded ~g~Have ~g~Fun!");
		Vector3 Coords{ 3595.39673f, -4893.727f , 115.838394f };
		TPto(Coords);
	}
	if (Menu::Option("Yacht")) {
		STREAMING::REQUEST_IPL("smboat");
		Vector3 Coords;
		Coords.x = -2045.8f; Coords.y = -1031.2f; Coords.z = 11.9f;
		TPto(Coords);
	}
	if (Menu::Option("Aircraft Carrier")) {
		STREAMING::REQUEST_IPL("hei_carrier");
		STREAMING::REQUEST_IPL("hei_carrier_DistantLights");
		STREAMING::REQUEST_IPL("hei_Carrier_int1");
		STREAMING::REQUEST_IPL("hei_Carrier_int2");
		STREAMING::REQUEST_IPL("hei_Carrier_int3");
		STREAMING::REQUEST_IPL("hei_Carrier_int4");
		STREAMING::REQUEST_IPL("hei_Carrier_int5");
		STREAMING::REQUEST_IPL("hei_Carrier_int6");
		STREAMING::REQUEST_IPL("hei_carrier_LODLights");
		Vector3 Coords{ 3084.73, -4770.709, 15.26167 };
		TPto(Coords);
	}
	if (Menu::Option("Sunken Cargoship")) {
		STREAMING::REQUEST_IPL("sunkcargoship");
		Vector3 Coords;
		Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 0.0f;
		TPto(Coords);
	}
	if (Menu::Option("Hospital")) {
		STREAMING::REQUEST_IPL("RC12B_HospitalInterior");
		STREAMING::REQUEST_IPL("RC12B_Destroyed");
		Vector3 Coords;
		Coords.x = 356.8f; Coords.y = -590.1f; Coords.z = 43.3f;
		TPto(Coords);
	}
	if (Menu::Option("Oneil Farm")) {
		STREAMING::REMOVE_IPL("farm_burnt");
		STREAMING::REMOVE_IPL("farm_burnt_props");
		STREAMING::REQUEST_IPL("farm");
		STREAMING::REQUEST_IPL("farm_props");
		STREAMING::REQUEST_IPL("farmint");
		STREAMING::REQUEST_IPL("farmint_cap");
		Vector3 Coords;
		Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
		TPto(Coords);
	}
	if (Menu::Option("Life Invader Office")) {
		STREAMING::REQUEST_IPL("facelobby");
		STREAMING::REQUEST_IPL("facelobbyfake");
		Vector3 Coords;
		Coords.x = -1047.9f; Coords.y = -233.0f; Coords.z = 39.0f;
		TPto(Coords);
	}
	if (Menu::Option("Cargoship")) {
		STREAMING::REQUEST_IPL("cargoship");
		Vector3 Coords;
		Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 9.3192f;
		TPto(Coords);
	}
	if (Menu::Option("Jewelry Store")) {
		STREAMING::REQUEST_IPL("jewel2fake");
		STREAMING::REQUEST_IPL("post_hiest_unload");
		STREAMING::REQUEST_IPL("bh1_16_refurb");
		Vector3 Coords;
		Coords.x = -630.4f; Coords.y = -236.7f; Coords.z = 40.0f;
		TPto(Coords);
	}
	if (Menu::Option("Morgue")) {
		STREAMING::REQUEST_IPL("Coroner_Int_on");
		Vector3 Coords;
		Coords.x = 244.9f; Coords.y = -1374.7f; Coords.z = 39.5f;
		TPto(Coords);
	}

}


void ttp()
{

	Menu::Title("");
	if (Menu::Option("Teleport To Waypoint")) {
		{
			Vector3 coords = get_blip_marker();


			// get entity to teleport
			Entity e = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
			{
				e = PED::GET_VEHICLE_PED_IS_USING(e);
			}

			// load needed map region and check height levels for ground existence
			bool groundFound = false;
			static float groundCheckHeight[] =
			{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
			for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
				WAIT(100);
				if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
				{
					groundFound = true;
					coords.z += 3.0;
					Menu::Subtitle;
				}
			}
			// if ground not found then set Z in air and give player a parachute
			if (!groundFound)
			{
				coords.z = 1000.0;
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
			}
			//do it
			teleport_to_coords(e, coords);
			CAM::DO_SCREEN_FADE_IN(200);
		}
	}
}
void tpmenu()
{
	Menu::Title("");
	Menu::Subtitle("Teleport Menu");
	ttp();
	Menu::Break("beta");
	Menu::MenuOption("Land Marks", landmarks);
	Menu::MenuOption("High Locations", highLocations);
	Menu::MenuOption("Online Related", Onlinerelated);
	Menu::MenuOption("Interiors", _Interiors);
	Menu::MenuOption("Underwater", TPUnderwater);
	Menu::Break("Old menu blow still works");
	Menu::MenuOption("Load Maps", IPL);
	Menu::MenuOption("Clothing Stores", TPClothingStore);
	Menu::MenuOption("Barbers", TPBarbers);
	Menu::MenuOption("Los Santos Customs", TPLSC);
	Menu::MenuOption("Other Vehicle TPs", TPOVehicle);
	Menu::MenuOption("Ammunation", TPAmmunation);
	Menu::MenuOption("Sports", TPSports);
	Menu::MenuOption("Stores", TPStores);
	Menu::MenuOption("Cinema", TPCinema);
	Menu::MenuOption("Tattos", TPTattos);
	Menu::MenuOption("Airports", TPAir);
	Menu::MenuOption("Fun", TPFun);
	Menu::MenuOption("Other", TPOther);
	Menu::MenuOption("ATM's", TPATMs);
	Menu::MenuOption("Banks", TPBanks);
	Menu::MenuOption("Services", TPServices);
	Menu::MenuOption("Apartments Online", TPAparts);
}


//Clothing Stores
void  TTPClothingStore()
{
	Menu::Title("");

	Menu::Subtitle("Clothing stores");
	if (Menu::Option("Binco - Vespucci")) { Vector3 Coords;                 Coords.x = -814.432800f; Coords.y = -1085.986938f; Coords.z = 10.567306f;                 TPto(Coords); }
	if (Menu::Option("Binco - Strawberry")) { Vector3 Coords;                 Coords.x = 411.403564f; Coords.y = -806.654907f; Coords.z = 28.742212f;                 TPto(Coords); }
	if (Menu::Option("Discount Store - Grand Senora")) { Vector3 Coords;                 Coords.x = 1179.679688f; Coords.y = 2691.378662f; Coords.z = 37.124043f;                 TPto(Coords); }
	if (Menu::Option("Discount Store - Grapeseed")) { Vector3 Coords;                 Coords.x = 1678.057495f; Coords.y = 4819.882324f; Coords.z = 41.299820f;                 TPto(Coords); }
	if (Menu::Option("Discount Store - Great Chaparral")) { Vector3 Coords;                 Coords.x = -1089.404785f; Coords.y = 2697.033447f; Coords.z = 19.442095f;                 TPto(Coords); }
	if (Menu::Option("Discount Store - Polito Bay")) { Vector3 Coords;                 Coords.x = -4.509100f; Coords.y = 6521.252930f; Coords.z = 30.571024f;                 TPto(Coords); }
	if (Menu::Option("Discount Store - Strawberry")) { Vector3 Coords;                 Coords.x = 89.320786f; Coords.y = -1392.317627f; Coords.z = 28.800083f;                 TPto(Coords); }
	if (Menu::Option("Masks - Vespucci Beach")) { Vector3 Coords;                 Coords.x = -1342.185913f; Coords.y = -1280.013428f; Coords.z = 4.443256f;                 TPto(Coords); }
	if (Menu::Option("Ponsonbys - Burton")) { Vector3 Coords;                 Coords.x = -148.234741f; Coords.y = -308.074463f; Coords.z = 38.104240f;                 TPto(Coords); }
	if (Menu::Option("Ponsonbys - Rockford Hills")) { Vector3 Coords;                 Coords.x = -725.551453f; Coords.y = -162.833710f; Coords.z = 36.570301f;                 TPto(Coords); }
	if (Menu::Option("Ponsonbys - Morningwood")) { Vector3 Coords;                 Coords.x = -1460.654419f; Coords.y = -227.550964f; Coords.z = 48.728519f;                 TPto(Coords); }
	if (Menu::Option("Suburban - Havick")) { Vector3 Coords;                 Coords.x = 134.122055f; Coords.y = -200.211334f; Coords.z = 53.864090f;                 TPto(Coords); }
	if (Menu::Option("Suburban - Del Perro")) { Vector3 Coords;                 Coords.x = -1210.620361f; Coords.y = -784.160217f; Coords.z = 16.549015f;                 TPto(Coords); }
	if (Menu::Option("Suburban - Chumash")) { Vector3 Coords;                 Coords.x = -3166.560547f; Coords.y = 1059.929688f; Coords.z = 20.65988f;                 TPto(Coords); }
	if (Menu::Option("Suburban - Harmony")) { Vector3 Coords;                 Coords.x = 618.081604f; Coords.y = 2745.795410f; Coords.z = 42.276966f;                 TPto(Coords); }
}

//Barbers
void  TTPBarbers()
{
	Menu::Title("");

	Menu::Subtitle("Barbers");
	if (Menu::Option("Davis")) { Vector3 Coords;                 Coords.x = 1198.025757f; Coords.y = -471.814178f; Coords.z = 68.659100f;                 TPto(Coords); }
	if (Menu::Option("Havick")) { Vector3 Coords;                 Coords.x = -27.791309f; Coords.y = -136.863708f; Coords.z = 56.515392f;                 TPto(Coords); }
	if (Menu::Option("Mirror Park")) { Vector3 Coords;                 Coords.x = 1678.057495f; Coords.y = 4819.882324f; Coords.z = 41.299820f;                 TPto(Coords); }
	if (Menu::Option("Polito Bay")) { Vector3 Coords;                 Coords.x = -286.639038f; Coords.y = 6239.389648f; Coords.z = 30.567659f;                 TPto(Coords); }
	if (Menu::Option("Rockford Hills")) { Vector3 Coords;                 Coords.x = -829.426392f; Coords.y = -191.582718f; Coords.z = 36.921909f;                 TPto(Coords); }
	if (Menu::Option("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1938.357910f; Coords.y = 3717.808350f; Coords.z = 31.607185f;                 TPto(Coords); }
	if (Menu::Option("Vespucci")) { Vector3 Coords;                 Coords.x = -1294.995239f; Coords.y = -1117.641724f; Coords.z = 6.157444f;                 TPto(Coords); }

}

//LSC
void  TTPLSC()
{
	Menu::Title("");

	Menu::Subtitle("Los Santos Customs");
	if (Menu::Option("Bennys Garage")) { Vector3 Coords;                 Coords.x = -196, 349442; Coords.y = -1303, 103271; Coords.z = 30, 650515;                 TPto(Coords); }
	if (Menu::Option("Burton")) { Vector3 Coords;                 Coords.x = -370.533752f; Coords.y = -130.402649f; Coords.z = 38.197617f;                 TPto(Coords); }
	if (Menu::Option("Beekers Garage")) { Vector3 Coords;                 Coords.x = 116.223175f; Coords.y = 6606.201660f; Coords.z = 31.462461f;                 TPto(Coords); }
	if (Menu::Option("Los Santos Airport")) { Vector3 Coords;                 Coords.x = -1135.707275f; Coords.y = -1987.154175f; Coords.z = 12.976217f;                 TPto(Coords); }
	if (Menu::Option("La Mesa")) { Vector3 Coords;                 Coords.x = 709.295471f; Coords.y = -1081.996216f; Coords.z = 21.975765f;                 TPto(Coords); }
	if (Menu::Option("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1176.822632f; Coords.y = 2657.973145; Coords.z = 37.370682;                 TPto(Coords); }
}

//Other Vehicle Related TPs
void  TTPOVehicle()
{
	Menu::Title("");

	Menu::Subtitle("Other Vehicle TPs");
	if (Menu::Option("Little Seoul Car Wash")) { Vector3 Coords;                 Coords.x = -701.829956f; Coords.y = -921.928772f; Coords.z = 18.589094f;                 TPto(Coords); }
	if (Menu::Option("Mort Mutual Insurance")) { Vector3 Coords;    Coords.x = -221.749908f; Coords.y = -1158.249756f; Coords.z = 23.040998f;                 TPto(Coords); }
	if (Menu::Option("Simeon Docks")) { Vector3 Coords;                 Coords.x = 1205.028442f; Coords.y = -3089.802490f; Coords.z = 5.374923f;                 TPto(Coords); }
	if (Menu::Option("Strawberry Car Wash")) { Vector3 Coords;                 Coords.x = 57.513451f; Coords.y = -1389.658691f; Coords.z = 28.968079f;                 TPto(Coords); }
}

//Ammunation
void  TTPAmmunation()
{
	Menu::Title("");

	Menu::Subtitle("Ammunation");
	if (Menu::Option("Chumash")) { Vector3 Coords;                 Coords.x = -3155.888672f; Coords.y = 1073.844482f; Coords.z = 20.188726f;                 TPto(Coords); }
	if (Menu::Option("Cypress Flats")) { Vector3 Coords;                 Coords.x = 814.442017f; Coords.y = -2130.448486f; Coords.z = 28.867798f;                 TPto(Coords); }
	if (Menu::Option("Great Chaparral")) { Vector3 Coords;                 Coords.x = -1108.600830f; Coords.y = 2685.694092f; Coords.z = 18.177374f;                 TPto(Coords); }
	if (Menu::Option("Hawick")) { Vector3 Coords;                 Coords.x = 235.666794f; Coords.y = -42.263149f; Coords.z = 69.221313f;                 TPto(Coords); }
	if (Menu::Option("La Mesa")) { Vector3 Coords;                 Coords.x = 844.439026f; Coords.y = -1009.422424f; Coords.z = 27.511728f;                 TPto(Coords); }
	if (Menu::Option("Little Seoul")) { Vector3 Coords;                 Coords.x = -665.232727f; Coords.y = -952.522522f; Coords.z = 20.866556f;                 TPto(Coords); }
	if (Menu::Option("Morningwood")) { Vector3 Coords;                 Coords.x = -1328.592896f; Coords.y = -387.114410f; Coords.z = 36.126881f;                 TPto(Coords); }
	if (Menu::Option("Palomino Fwy")) { Vector3 Coords;                 Coords.x = 2571.371826f; Coords.y = 313.879608f; Coords.z = 107.970573f;                 TPto(Coords); }
	if (Menu::Option("Pillbox Hill")) { Vector3 Coords;                 Coords.x = 17.377790f; Coords.y = -1122.183105f; Coords.z = 28.469843f;                 TPto(Coords); }
	if (Menu::Option("Polito Bay")) { Vector3 Coords;                 Coords.x = -318.859039f; Coords.y = 6074.433105f; Coords.z = 30.614943f;                 TPto(Coords); }
	if (Menu::Option("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1704.671997f; Coords.y = 3748.880615f; Coords.z = 33.286053f;                 TPto(Coords); }
}

//Sports Including,Tennis,Golf,Darts,
void  TTPSports()
{
	Menu::Title("");


	Menu::Subtitle("Tennis Courts");
	if (Menu::Option("Alta")) { Vector3 Coords;                 Coords.x = 479.905945f; Coords.y = -235.494492f; Coords.z = 53.536331f;                 TPto(Coords); }
	if (Menu::Option("GWC and Golfing Society")) { Vector3 Coords;                 Coords.x = -1241.053101f; Coords.y = 355.518005f; Coords.z = 79.737648f;                 TPto(Coords); }
	if (Menu::Option("La Puerta")) { Vector3 Coords;                 Coords.x = -948.632141f; Coords.y = -1259.970093f; Coords.z = 7.726484f;                 TPto(Coords); }
	if (Menu::Option("Little Seoul")) { Vector3 Coords;                 Coords.x = -921.126953f; Coords.y = -725.521423f; Coords.z = 19.665815f;                 TPto(Coords); }
	if (Menu::Option("Richman")) { Vector3 Coords;                 Coords.x = -1628.552979f; Coords.y = 245.169250f; Coords.z = 59.455631f;                 TPto(Coords); }
	if (Menu::Option("Rockford Hills")) { Vector3 Coords;                 Coords.x = -1357.719360f; Coords.y = -109.870804f; Coords.z = 50.622841f;                 TPto(Coords); }
	if (Menu::Option("Rockford Hills - Michael")) { Vector3 Coords;                 Coords.x = -787.896729f; Coords.y = 151.680588f; Coords.z = 68.633354f;                 TPto(Coords); }
	if (Menu::Option("Vespucci Beach")) { Vector3 Coords;                 Coords.x = -1181.297241f; Coords.y = -1642.197021f; Coords.z = 4.363619f;                 TPto(Coords); }

	Menu::Subtitle("Darts");
	if (Menu::Option("Darts")) { Vector3 Coords;                 Coords.x = 1992.516357f; Coords.y = 3057.399658f; Coords.z = 47.058922f;                 TPto(Coords); }

	Menu::Subtitle("Golf");
	if (Menu::Option("Golf")) { Vector3 Coords;                 Coords.x = -1379.665039f; Coords.y = 51.105522f; Coords.z = 53.053589f;                 TPto(Coords); }
}

//Stores
void  TTPStores()
{
	Menu::Title("");

	Menu::Subtitle("Stores");
	if (Menu::Option("24/7 - Banham Canyon")) { Vector3 Coords;                 Coords.x = -3037.177246f; Coords.y = 590.165283f; Coords.z = 7.78449f;                 TPto(Coords); }
	if (Menu::Option("24/7 - Chumash")) { Vector3 Coords;                 Coords.x = -3237.171387f; Coords.y = 1004.163879f; Coords.z = 12.354364f;                 TPto(Coords); }
	if (Menu::Option("24/7 - Grand Senora Desert")) { Vector3 Coords;                 Coords.x = 2683.951172f; Coords.y = 3281.507324f; Coords.z = 55.347145f;                 TPto(Coords); }
	if (Menu::Option("24/7 - Harmony")) { Vector3 Coords;                 Coords.x = 543.490784f; Coords.y = 2675.008301f; Coords.z = 42.162228f;                 TPto(Coords); }
	if (Menu::Option("24/7 - Mount Chiliad")) { Vector3 Coords;                 Coords.x = 1730.461914f; Coords.y = 6410.027344f; Coords.z = 35.384476f;                 TPto(Coords); }
	if (Menu::Option("24/7 - Sandy Shores - Niland Ave")) { Vector3 Coords;                 Coords.x = 1966.198853f; Coords.y = 3738.300537f; Coords.z = 32.251864f;                 TPto(Coords); }
	if (Menu::Option("24/7 - Strawberry")) { Vector3 Coords;                 Coords.x = 28.123456f; Coords.y = -1351.123456f; Coords.z = 29.123456f;                 TPto(Coords); }
	if (Menu::Option("24/7 - Tataviam Mountains")) { Vector3 Coords;                 Coords.x = 2561.452881f; Coords.y = 384.998932f; Coords.z = 108.532890f;                 TPto(Coords); }
	if (Menu::Option("24/7 - Vinewood")) { Vector3 Coords;                 Coords.x = 376.287079f; Coords.y = 322.833252f; Coords.z = 103.418564f;                 TPto(Coords); }
	if (Menu::Option("Limited LTD Gasoline - Grapeseed")) { Vector3 Coords;                 Coords.x = 1695.349267f; Coords.y = 4932.165039f; Coords.z = 41.826122f;                 TPto(Coords); }
	if (Menu::Option("Limited LTD Gasoline - Grove St")) { Vector3 Coords;                 Coords.x = -54.6644520f; Coords.y = -1758.542847f; Coords.z = 29.432362f;                 TPto(Coords); }
	if (Menu::Option("Limited LTD Gasoline - Little Seoul")) { Vector3 Coords;                 Coords.x = -712.059570f; Coords.y = -919.167175f; Coords.z = 18.835764f;                 TPto(Coords); }
	if (Menu::Option("Limited LTD Gasoline - Mirror Park")) { Vector3 Coords;                 Coords.x = 1159.879761f; Coords.y = -329.307495f; Coords.z = 68.822609f;                 TPto(Coords); }
	if (Menu::Option("Limited LTD Gasoline - Richman Glen")) { Vector3 Coords;                 Coords.x = -1821.082275f; Coords.y = 787.085510f; Coords.z = 137.868439f;                 TPto(Coords); }
	if (Menu::Option("Rob's Liqour - Banham Canyon")) { Vector3 Coords;                 Coords.x = -2976.010742f; Coords.y = 391.081024f; Coords.z = 15.013429f;                 TPto(Coords); }
	if (Menu::Option("Rob's Liqour - Morningwood")) { Vector3 Coords;                 Coords.x = -1493.295166f; Coords.y = -385.783142f; Coords.z = 39.841709f;                 TPto(Coords); }
	if (Menu::Option("Rob's Liqour - Murrieta Heights")) { Vector3 Coords;                 Coords.x = 1142.654053f; Coords.y = -980.857788f; Coords.z = 45.945202f;                 TPto(Coords); }
	if (Menu::Option("Rob's Liqour - Vespucci Canals")) { Vector3 Coords;                 Coords.x = -1227.629639f; Coords.y = -900.404236f; Coords.z = 12.366796f;                 TPto(Coords); }
	if (Menu::Option("Scoops - Grand Senora Desert")) { Vector3 Coords;                 Coords.x = 1166.794556f; Coords.y = 2700.728027f; Coords.z = 38.224377f;                 TPto(Coords); }
	if (Menu::Option("N/A - Algonquin Blvd")) { Vector3 Coords;                 Coords.x = 1394.642578f; Coords.y = 3598.434082f; Coords.z = 34.892509f;                 TPto(Coords); }
}

//Cinema
void  TTPCinema()
{
	Menu::Title("");

	Menu::Subtitle("Cinema");
	if (Menu::Option("Oriental Theater")) { Vector3 Coords;                 Coords.x = 293.089f; Coords.y = 180.466f; Coords.z = 104.301f;                 TPto(Coords); }
	if (Menu::Option("Ten Cent")) { Vector3 Coords;                 Coords.x = 400.111111f; Coords.y = -711.111111f; Coords.z = 29.752497f;                 TPto(Coords); }
	if (Menu::Option("Morningwood")) { Vector3 Coords;                 Coords.x = -1421.111111f; Coords.y = -193.111111f; Coords.z = 46.789345f;                 TPto(Coords); }
}

//Tattos
void  TTPTattos()
{
	Menu::Title("");
	Menu::Subtitle("Tattos");
	if (Menu::Option("Chumash")) { Vector3 Coords;                 Coords.x = -3155.888672f; Coords.y = 1073.844482f; Coords.z = 20.188726f;                 TPto(Coords); }
	if (Menu::Option("El Burro Heights")) { Vector3 Coords;                 Coords.x = 1318.160889f; Coords.y = -1642.176147f; Coords.z = 51.787762f;                 TPto(Coords); }
	if (Menu::Option("Polito Bay")) { Vector3 Coords;                 Coords.x = -285.123456f; Coords.y = 6202.123456f; Coords.z = 30.123456f;                 TPto(Coords); }
	if (Menu::Option("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1853.771851f; Coords.y = 3746.440918f; Coords.z = 32.395195f;                 TPto(Coords); }
	if (Menu::Option("Vespucci")) { Vector3 Coords;                 Coords.x = -1163.504639f; Coords.y = -1413.232788f; Coords.z = 4.360025f;                 TPto(Coords); }
	if (Menu::Option("Vinewood")) { Vector3 Coords;                 Coords.x = 318.228790f; Coords.y = 164.457535f; Coords.z = 103.146561f;                 TPto(Coords); }
}

//Airports
void  TTPAir()
{
	Menu::Title("");
	Menu::Subtitle("Airports");
	if (Menu::Option("Los Santos Airport")) { Vector3 Coords;                 Coords.x = -1070.906250f; Coords.y = -2972.122803f; Coords.z = 13.773568f;                 TPto(Coords); }
	if (Menu::Option("McKenzie Airfield")) { Vector3 Coords;                 Coords.x = 2124.625732f; Coords.y = 4805.270020f; Coords.z = 40.479958f;                 TPto(Coords); }
	if (Menu::Option("Flight School")) { Vector3 Coords;                 Coords.x = -1142.084229f; Coords.y = -2697.341553f; Coords.z = 13.324973f;                 TPto(Coords); }
	if (Menu::Option("Fort Zancudo ATC entrance")) { Vector3 Coords;                 Coords.x = -2344.373f; Coords.y = 3267.498f; Coords.z = 32.811f;                 TPto(Coords); }
	if (Menu::Option("Fort Zancudo ATC top floor")) { Vector3 Coords;                 Coords.x = -2358.132f; Coords.y = 3249.754f; Coords.z = 101.451f;                 TPto(Coords); }
	if (Menu::Option("Fort Zancudo Front")) { Vector3 Coords;                 Coords.x = -1563.743286f; Coords.y = 2769.382080f; Coords.z = 16.819347f;                 TPto(Coords); }
	if (Menu::Option("Fort Zancudo")) { Vector3 Coords;                 Coords.x = -2446.711182f; Coords.y = 3142.811035f; Coords.z = 32.194775f;                 TPto(Coords); }
	if (Menu::Option("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1682.196411f; Coords.y = 3279.987793f; Coords.z = 40.647972f;                 TPto(Coords); }
}

//Fun
void  TTPFun()
{
	Menu::Title("");
	Menu::Subtitle("Fun");
	if (Menu::Option("Burnt FIB Building")) { Vector3 Coords;                 Coords.x = 153.344131f; Coords.y = -734.524353f; Coords.z = 253.848343f;                 TPto(Coords); }
	if (Menu::Option("FIB Roof")) { Vector3 Coords;                 Coords.x = 150.126f; Coords.y = -754.591f; Coords.z = 262.865f;                 TPto(Coords); }
	if (Menu::Option("FIB Top Floor")) { Vector3 Coords;                 Coords.x = 135.733f; Coords.y = -749.216f; Coords.z = 258.152f;                 TPto(Coords); }
	if (Menu::Option("IAA Roof")) { Vector3 Coords;                 Coords.x = 134.085f; Coords.y = -637.859f; Coords.z = 262.851f;                 TPto(Coords); }
	if (Menu::Option("IAA Office")) { Vector3 Coords;                 Coords.x = 117.220f; Coords.y = -620.938f; Coords.z = 206.047f;                 TPto(Coords); }
	if (Menu::Option("Mile High Club")) { Vector3 Coords;                 Coords.x = -144.274f; Coords.y = -946.813f; Coords.z = 269.135f;                 TPto(Coords); }
	if (Menu::Option("Play Boy Mansion")) { Vector3 Coords;                 Coords.x = -1475.234f; Coords.y = 167.088f; Coords.z = 55.841f;                 TPto(Coords); }
	if (Menu::Option("Strip Club")) { Vector3 Coords;                 Coords.x = 135.548096f; Coords.y = -1308.388306f; Coords.z = 28.344141f;                 TPto(Coords); }
	if (Menu::Option("Strip Club - DJ Booth")) { Vector3 Coords;                 Coords.x = 122.416924f; Coords.y = -1281.09976f; Coords.z = 29.480480f;                 TPto(Coords); }
	if (Menu::Option("Torture Room X")) { Vector3 Coords;                 Coords.x = 147.170f; Coords.y = -2201.804f; Coords.z = 4.688f;                 TPto(Coords); }
	if (Menu::Option("Weed Farm")) { Vector3 Coords;                 Coords.x = 2208.777f; Coords.y = 5578.235f; Coords.z = 53.735f;                 TPto(Coords); }
}


//Other
void  TTPOther()
{
	Menu::Title("");
	Menu::Subtitle("Other");
	if (Menu::Option("Abandon Mine")) { Vector3 Coords;                 Coords.x = -595.342f; Coords.y = 2086.008f; Coords.z = 131.412f;                 TPto(Coords); }
	if (Menu::Option("Airplane Graveyard Airplane Tail")) { Vector3 Coords;                 Coords.x = 2395.096f; Coords.y = 3049.616f; Coords.z = 60.053f;                 TPto(Coords); }
	if (Menu::Option("Altruist Cult Camp")) { Vector3 Coords;                 Coords.x = -1170.841f; Coords.y = 4926.646f; Coords.z = 224.295f;                 TPto(Coords); }
	if (Menu::Option("Beach Skatepark")) { Vector3 Coords;                 Coords.x = -1374.881f; Coords.y = -1398.835f; Coords.z = 6.141f;                 TPto(Coords); }
	if (Menu::Option("Calafia Train Bridge")) { Vector3 Coords;                 Coords.x = -517.869f; Coords.y = 4425.284f; Coords.z = 89.795897f;                 TPto(Coords); }
	if (Menu::Option("Cargo Ship")) { Vector3 Coords;                 Coords.x = 899.678f; Coords.y = -2882.191f; Coords.z = 19.013f;                 TPto(Coords); }
	if (Menu::Option("Casino")) { Vector3 Coords;                 Coords.x = 925.329f; Coords.y = 46.152f; Coords.z = 80.908f;                 TPto(Coords); }
	if (Menu::Option("Chicken")) { Vector3 Coords;                 Coords.x = -31.010f; Coords.y = 6316.830f; Coords.z = 40.083f;                 TPto(Coords); }
	if (Menu::Option("Chumash Historic Family Pier")) { Vector3 Coords;                 Coords.x = -3426.683f; Coords.y = 967.738f; Coords.z = 8.347f;                 TPto(Coords); }
	if (Menu::Option("Del Perro Pier")) { Vector3 Coords;                 Coords.x = -1850.127f; Coords.y = -1231.751f; Coords.z = 13.017f;                 TPto(Coords); }
	if (Menu::Option("Devin Weston's House")) { Vector3 Coords;                 Coords.x = -2639.872f; Coords.y = 1866.812f; Coords.z = 160.135f;                 TPto(Coords); }
	if (Menu::Option("El Gordo Lighthouse - Floor")) { Vector3 Coords;                 Coords.x = 3422.703125f; Coords.y = 5174.532715f; Coords.z = 7.382134f;                 TPto(Coords); }
	if (Menu::Option("El Gordo Lighthouse - Top")) { Vector3 Coords;                 Coords.x = 3431.182617f; Coords.y = 5173.422852f; Coords.z = 41.371891f;                 TPto(Coords); }
	if (Menu::Option("Epsilon Building")) { Vector3 Coords;                 Coords.x = -695.025f; Coords.y = 82.955f; Coords.z = 55.855f;                 TPto(Coords); }
	if (Menu::Option("Floyd's Apartment")) { Vector3 Coords;                 Coords.x = -1150.703f; Coords.y = -1520.713f; Coords.z = 10.633f;                 TPto(Coords); }
	if (Menu::Option("Galileo Observatory Roof")) { Vector3 Coords;                 Coords.x = -438.804f; Coords.y = 1076.097f; Coords.z = 352.411f;                 TPto(Coords); }
	if (Menu::Option("God's thumb")) { Vector3 Coords;                 Coords.x = -1006.402f; Coords.y = 6272.383f; Coords.z = 1.503f;                 TPto(Coords); }
	if (Menu::Option("Hippy Camp")) { Vector3 Coords;                 Coords.x = 2476.712f; Coords.y = 3789.645f; Coords.z = 41.226f;                 TPto(Coords); }
	if (Menu::Option("Humane Labs Entrance")) { Vector3 Coords;                 Coords.x = 3613.750000f; Coords.y = 3747.294180f; Coords.z = 28.59690090f;                 TPto(Coords); }
	if (Menu::Option("Humane Labs Tunnel")) { Vector3 Coords;                 Coords.x = 3525.495f; Coords.y = 3705.301f; Coords.z = 20.992f;                 TPto(Coords); }
	if (Menu::Option("Jolene Ghost - Time 23:00/24:00")) { Vector3 Coords;                 Coords.x = 3059.620f; Coords.y = 5564.246f; Coords.z = 197.091f;                 TPto(Coords); }
	if (Menu::Option("Kortz Center")) { Vector3 Coords;                 Coords.x = -2243.810f; Coords.y = 264.048f; Coords.z = 174.615f;                 TPto(Coords); }
	if (Menu::Option("La Puerta Freeway Bridge")) { Vector3 Coords;                 Coords.x = -543.932f; Coords.y = -2225.543f; Coords.z = 122.366f;                 TPto(Coords); }
	if (Menu::Option("Land Act Dam")) { Vector3 Coords;                 Coords.x = 1660.369f; Coords.y = -12.013f; Coords.z = 170.020f;                 TPto(Coords); }
	if (Menu::Option("Lester's House")) { Vector3 Coords;                 Coords.x = 1273.898f; Coords.y = -1719.304f; Coords.z = 54.771f;                 TPto(Coords); }
	if (Menu::Option("Little Portola")) { Vector3 Coords;                 Coords.x = -635.463f; Coords.y = -242.402f; Coords.z = 38.175f;                 TPto(Coords); }
	if (Menu::Option("Little Seoul")) { Vector3 Coords;                 Coords.x = -889.655f; Coords.y = -853.499f; Coords.z = 20.566f;                 TPto(Coords); }
	if (Menu::Option("Marlowe Vineyards")) { Vector3 Coords;                 Coords.x = -1868.971f; Coords.y = 2095.674f; Coords.z = 139.115f;                 TPto(Coords); }
	if (Menu::Option("Merryweather Dock")) { Vector3 Coords;                 Coords.x = 486.417f; Coords.y = -3339.692f; Coords.z = 6.070f;                 TPto(Coords); }
	if (Menu::Option("Mirror Park")) { Vector3 Coords;                 Coords.x = 1070.206f; Coords.y = -711.958f; Coords.z = 58.483f;                 TPto(Coords); }
	if (Menu::Option("Mount Gordo")) { Vector3 Coords;                 Coords.x = 2877.633f; Coords.y = 5911.078f; Coords.z = 369.624f;                 TPto(Coords); }
	if (Menu::Option("NOOSE Headquarters")) { Vector3 Coords;                 Coords.x = 2535.243f; Coords.y = -383.799f; Coords.z = 92.993f;                 TPto(Coords); }
	if (Menu::Option("Pacific Bluffs Country Club")) { Vector3 Coords;                 Coords.x = -3022.222f; Coords.y = 39.968f; Coords.z = 13.611f;                 TPto(Coords); }
	if (Menu::Option("Paleto Bay Pier")) { Vector3 Coords;                 Coords.x = -275.522f; Coords.y = 6635.835f; Coords.z = 7.425f;                 TPto(Coords); }
	if (Menu::Option("Paleto Forest Sawmill Chimney")) { Vector3 Coords;                 Coords.x = -549.467f; Coords.y = 5308.221f; Coords.z = 114.146f;                 TPto(Coords); }
	if (Menu::Option("Palmer-Taylor Power Station")) { Vector3 Coords;                 Coords.x = 2732.931f; Coords.y = 1577.540f; Coords.z = 83.671f;                 TPto(Coords); }
	if (Menu::Option("Police Station")) { Vector3 Coords;                 Coords.x = 436.491f; Coords.y = -982.172f; Coords.z = 30.699f;                 TPto(Coords); }
	if (Menu::Option("Quarry")) { Vector3 Coords;                 Coords.x = 2954.196f; Coords.y = 2783.410f; Coords.z = 41.004f;                 TPto(Coords); }
	if (Menu::Option("Rebel Radio")) { Vector3 Coords;                 Coords.x = 736.153f; Coords.y = 2583.143f; Coords.z = 79.634f;                 TPto(Coords); }
	if (Menu::Option("Rocket")) { Vector3 Coords;                 Coords.x = 1608.698f; Coords.y = 6438.096f; Coords.z = 37.637f;                 TPto(Coords); }
	if (Menu::Option("Sandy Shores Crane")) { Vector3 Coords;                 Coords.x = 1051.209f; Coords.y = 2280.452f; Coords.z = 89.727f;                 TPto(Coords); }
	if (Menu::Option("Satellite Dish Antenna")) { Vector3 Coords;                 Coords.x = 2034.988f; Coords.y = 2953.105f; Coords.z = 74.602f;                 TPto(Coords); }
	if (Menu::Option("Satellite Dishes")) { Vector3 Coords;                 Coords.x = 2062.123f; Coords.y = 2942.055f; Coords.z = 47.431f;                 TPto(Coords); }
	if (Menu::Option("Sisyphus Theater Stage")) { Vector3 Coords;                 Coords.x = 205.316f; Coords.y = 1167.378f; Coords.z = 227.005f;                 TPto(Coords); }
	if (Menu::Option("Snowman")) { Vector3 Coords;                 Coords.x = 971.245f; Coords.y = -1620.993f; Coords.z = 30.111f;                 TPto(Coords); }
	if (Menu::Option("Stab City")) { Vector3 Coords;                 Coords.x = 126.975f; Coords.y = 3714.419f; Coords.z = 46.827f;                 TPto(Coords); }
	if (Menu::Option("The Richman Hotel")) { Vector3 Coords;                 Coords.x = -1330.911f; Coords.y = 340.871f; Coords.z = 64.078f;                 TPto(Coords); }
	if (Menu::Option("Top of Mt Chilad")) { Vector3 Coords;                 Coords.x = 450.718f; Coords.y = 5566.614f; Coords.z = 806.183f;                 TPto(Coords); }
	if (Menu::Option("Trevor's Meth Lab")) { Vector3 Coords;                 Coords.x = 1391.773f; Coords.y = 3608.716f; Coords.z = 38.942f;                 TPto(Coords); }
	if (Menu::Option("Underpass Skatepark")) { Vector3 Coords;                 Coords.x = 718.341f; Coords.y = -1218.714f; Coords.z = 26.014f;                 TPto(Coords); }
	if (Menu::Option("University of San Andreas")) { Vector3 Coords;                 Coords.x = -1696.866f; Coords.y = 142.747f; Coords.z = 64.372f;                 TPto(Coords); }
	if (Menu::Option("Vinewood Bowl Stage")) { Vector3 Coords;                 Coords.x = 686.245f; Coords.y = 577.950f; Coords.z = 130.461f;                 TPto(Coords); }
	if (Menu::Option("Vinewood sign")) { Vector3 Coords;                 Coords.x = 711.362f; Coords.y = 1198.134f; Coords.z = 348.526f;                 TPto(Coords); }
	if (Menu::Option("Windmill Top")) { Vector3 Coords;                 Coords.x = 2026.677f; Coords.y = 1842.684f; Coords.z = 133.313f;                 TPto(Coords); }
}

//Underwater
void  TTPUnderwater()
{
	Menu::Title("");
	Menu::Subtitle("Underwater");
	if (Menu::Option("Dead Sea Monster")) { Vector3 Coords;                 Coords.x = -3373.726f; Coords.y = 504.714f; Coords.z = -24.656f;                 TPto(Coords); }
	if (Menu::Option("Sunken Body")) { Vector3 Coords;                 Coords.x = -3161.078f; Coords.y = 3001.998f; Coords.z = -37.974f;                 TPto(Coords); }
	if (Menu::Option("Sunken Cargo Ship")) { Vector3 Coords;                 Coords.x = 3199.748f; Coords.y = -379.018f; Coords.z = -22.500f;                 TPto(Coords); }
	if (Menu::Option("Sunken Plane")) { Vector3 Coords;                 Coords.x = -942.350f; Coords.y = 6608.752f; Coords.z = -20.912f;                 TPto(Coords); }
	if (Menu::Option("Sunken Plane2")) { Vector3 Coords;                 Coords.x = 1848.025879f; Coords.y = -2938.081787f; Coords.z = -24.797621f;                 TPto(Coords); }
	if (Menu::Option("Underwater Hatch")) { Vector3 Coords;                 Coords.x = 4273.950f; Coords.y = 2975.714f; Coords.z = -170.746f;                 TPto(Coords); }
	if (Menu::Option("Underwater UFO")) { Vector3 Coords;                 Coords.x = 762.426f; Coords.y = 7380.371f; Coords.z = -111.377f;                 TPto(Coords); }
	if (Menu::Option("Underwater WW2 Tank")) { Vector3 Coords;                 Coords.x = 4201.633f; Coords.y = 3643.821f; Coords.z = -39.016f;                 TPto(Coords); }
}

//ATM's
void  TTPATMs()
{
	Menu::Title("");
	Menu::Subtitle("ATM's");
	if (Menu::Option("ATM1")) { Vector3 Coords;                 Coords.x = -1109.797f; Coords.y = -1690.808f; Coords.z = 4.375014f;                 TPto(Coords); }
	if (Menu::Option("ATM2")) { Vector3 Coords;                 Coords.x = -821.6062f; Coords.y = -1081.885f; Coords.z = 11.13243f;                 TPto(Coords); }
	if (Menu::Option("ATM3")) { Vector3 Coords;                 Coords.x = -537.8409f; Coords.y = -854.5145f; Coords.z = 29.28953f;                 TPto(Coords); }
	if (Menu::Option("ATM4")) { Vector3 Coords;                 Coords.x = -1315.744f; Coords.y = -834.6907f; Coords.z = 16.96173f;                 TPto(Coords); }
	if (Menu::Option("ATM5")) { Vector3 Coords;                 Coords.x = -1314.786f; Coords.y = -835.9669f; Coords.z = 16.96015f;                 TPto(Coords); }
	if (Menu::Option("ATM6")) { Vector3 Coords;                 Coords.x = -1570.069f; Coords.y = -546.6727f; Coords.z = 34.95547f;                 TPto(Coords); }
	if (Menu::Option("ATM7")) { Vector3 Coords;                 Coords.x = -1571.018f; Coords.y = -547.3666f; Coords.z = 34.95734f;                 TPto(Coords); }
	if (Menu::Option("ATM8")) { Vector3 Coords;                 Coords.x = -866.6416f; Coords.y = -187.8008f; Coords.z = 37.84286f;                 TPto(Coords); }
	if (Menu::Option("ATM9")) { Vector3 Coords;                 Coords.x = -867.6165f; Coords.y = -186.1373f; Coords.z = 37.8433f;                 TPto(Coords); }
	if (Menu::Option("ATM10")) { Vector3 Coords;                 Coords.x = -721.1284f; Coords.y = -415.5296f; Coords.z = 34.98175f;                 TPto(Coords); }
	if (Menu::Option("ATM11")) { Vector3 Coords;                 Coords.x = -254.3758f; Coords.y = -692.4947f; Coords.z = 33.63751f;                 TPto(Coords); }
	if (Menu::Option("ATM12")) { Vector3 Coords;                 Coords.x = 24.37422f; Coords.y = -946.0142f; Coords.z = 29.35756f;                 TPto(Coords); }
	if (Menu::Option("ATM13")) { Vector3 Coords;                 Coords.x = 130.1186f; Coords.y = -1292.669f; Coords.z = 29.26953f;                 TPto(Coords); }
	if (Menu::Option("ATM14")) { Vector3 Coords;                 Coords.x = 129.7023f; Coords.y = -1291.954f; Coords.z = 29.26953f;                 TPto(Coords); }
	if (Menu::Option("ATM15")) { Vector3 Coords;                 Coords.x = 129.2096f; Coords.y = -1291.14f; Coords.z = 29.26953f;                 TPto(Coords); }
	if (Menu::Option("ATM16")) { Vector3 Coords;                 Coords.x = 288.8256f; Coords.y = -1282.364f; Coords.z = 29.64128f;                 TPto(Coords); }
	if (Menu::Option("ATM17")) { Vector3 Coords;                 Coords.x = 1077.768f; Coords.y = -776.4548f; Coords.z = 58.23997f;                 TPto(Coords); }
	if (Menu::Option("ATM18")) { Vector3 Coords;                 Coords.x = 527.2687f; Coords.y = -160.7156f; Coords.z = 57.08937f;                 TPto(Coords); }
	if (Menu::Option("ATM19")) { Vector3 Coords;                 Coords.x = -867.5897f; Coords.y = -186.1757f; Coords.z = 37.84291f;                 TPto(Coords); }
	if (Menu::Option("ATM20")) { Vector3 Coords;                 Coords.x = -866.6556f; Coords.y = -187.7766f; Coords.z = 37.84278f;                 TPto(Coords); }
	if (Menu::Option("ATM21")) { Vector3 Coords;                 Coords.x = -1205.024f; Coords.y = -326.2916f; Coords.z = 37.83985f;                 TPto(Coords); }
	if (Menu::Option("ATM22")) { Vector3 Coords;                 Coords.x = -1205.703f; Coords.y = -324.7474f; Coords.z = 37.85942f;                 TPto(Coords); }
	if (Menu::Option("ATM23")) { Vector3 Coords;                 Coords.x = -57.64693f; Coords.y = -92.66162f; Coords.z = 57.77995f;                 TPto(Coords); }
	if (Menu::Option("ATM24")) { Vector3 Coords;                 Coords.x = 527.3583f; Coords.y = -160.6381f; Coords.z = 57.0933f;                 TPto(Coords); }
	if (Menu::Option("ATM25")) { Vector3 Coords;                 Coords.x = -165.1658f; Coords.y = 234.8314f; Coords.z = 94.92194f;                 TPto(Coords); }
	if (Menu::Option("ATM26")) { Vector3 Coords;                 Coords.x = -165.1503f; Coords.y = 232.7887f; Coords.z = 94.92194f;                 TPto(Coords); }
	if (Menu::Option("ATM27")) { Vector3 Coords;                 Coords.x = -2072.445f; Coords.y = -317.3048f; Coords.z = 13.31597f;                 TPto(Coords); }
	if (Menu::Option("ATM28")) { Vector3 Coords;                 Coords.x = -3241.082f; Coords.y = 997.5428f; Coords.z = 12.55044f;                 TPto(Coords); }
	if (Menu::Option("ATM29")) { Vector3 Coords;                 Coords.x = -1091.462f; Coords.y = 2708.637f; Coords.z = 18.95291f;                 TPto(Coords); }
	if (Menu::Option("ATM30")) { Vector3 Coords;                 Coords.x = 1172.492f; Coords.y = 2702.492f; Coords.z = 38.17477f;                 TPto(Coords); }
	if (Menu::Option("ATM31")) { Vector3 Coords;                 Coords.x = 1171.537f; Coords.y = 2702.492f; Coords.z = 38.17542f;                 TPto(Coords); }
	if (Menu::Option("ATM32")) { Vector3 Coords;                 Coords.x = 1822.637f; Coords.y = 3683.131f; Coords.z = 34.27678f;                 TPto(Coords); }
	if (Menu::Option("ATM33")) { Vector3 Coords;                 Coords.x = 1686.753f; Coords.y = 4815.806f; Coords.z = 42.00874f;                 TPto(Coords); }
	if (Menu::Option("ATM34")) { Vector3 Coords;                 Coords.x = 1701.209f; Coords.y = 6426.569f; Coords.z = 32.76408f;                 TPto(Coords); }
	if (Menu::Option("ATM35")) { Vector3 Coords;                 Coords.x = -95.54314f; Coords.y = 6457.19f; Coords.z = 31.46093f;                 TPto(Coords); }
	if (Menu::Option("ATM36")) { Vector3 Coords;                 Coords.x = -97.23336f; Coords.y = 6455.469f; Coords.z = 31.46682f;                 TPto(Coords); }
	if (Menu::Option("ATM37")) { Vector3 Coords;                 Coords.x = -386.7451f; Coords.y = 6046.102f; Coords.z = 31.50172f;                 TPto(Coords); }
	if (Menu::Option("ATM38")) { Vector3 Coords;                 Coords.x = -1091.42f; Coords.y = 2708.629f; Coords.z = 18.95568f;                 TPto(Coords); }
	if (Menu::Option("ATM39")) { Vector3 Coords;                 Coords.x = 5.132f; Coords.y = -919.7711f; Coords.z = 29.55953f;                 TPto(Coords); }
	if (Menu::Option("ATM40")) { Vector3 Coords;                 Coords.x = -660.703f; Coords.y = -853.971f; Coords.z = 24.484f;                 TPto(Coords); }
	if (Menu::Option("ATM41")) { Vector3 Coords;                 Coords.x = -2293.827f; Coords.y = 354.817f; Coords.z = 174.602f;                 TPto(Coords); }
	if (Menu::Option("ATM42")) { Vector3 Coords;                 Coords.x = -2294.637f; Coords.y = 356.553f; Coords.z = 174.602f;                 TPto(Coords); }
	if (Menu::Option("ATM43")) { Vector3 Coords;                 Coords.x = -2295.377f; Coords.y = 358.241f; Coords.z = 174.648f;                 TPto(Coords); }
	if (Menu::Option("ATM44")) { Vector3 Coords;                 Coords.x = -1409.782f; Coords.y = -100.41f; Coords.z = 52.387f;                 TPto(Coords); }
	if (Menu::Option("ATM45")) { Vector3 Coords;                 Coords.x = -1410.279f; Coords.y = -98.649f; Coords.z = 52.436f;                 TPto(Coords); }
}

//Banks
void  TTPBanks()
{
	Menu::Title("");
	Menu::Subtitle("Banks");
	if (Menu::Option("Blaine County Bank")) { Vector3 Coords;                 Coords.x = -109.299f; Coords.y = 6464.035f; Coords.z = 31.627f;                 TPto(Coords); }
	if (Menu::Option("Pacific Standard Bank")) { Vector3 Coords;                 Coords.x = 235.046f; Coords.y = 216.434f; Coords.z = 106.287f;                 TPto(Coords); }
	if (Menu::Option("Pacific Standard Bank Vault")) { Vector3 Coords;                 Coords.x = 255.851f; Coords.y = 217.030f; Coords.z = 101.683f;                 TPto(Coords); }
	if (Menu::Option("Maze Bank Arena Roof")) { Vector3 Coords;                 Coords.x = -324.300f; Coords.y = -1968.545f; Coords.z = 67.002f;                 TPto(Coords); }
	if (Menu::Option("Maze Bank Roof")) { Vector3 Coords;                 Coords.x = -75.015f; Coords.y = -818.215f; Coords.z = 326.176f;                 TPto(Coords); }
}

//Services
void  TTPServices()
{
	Menu::Title("");
	Menu::Subtitle("Services");
	if (Menu::Option("Fire Station - Davis, Macdonald")) { Vector3 Coords;                 Coords.x = 213.927261f; Coords.y = -1639.267090f; Coords.z = 29.692514f;                 TPto(Coords); }
	if (Menu::Option("Fire Station - Fort Zancudo")) { Vector3 Coords;                 Coords.x = -2113.866699f; Coords.y = 2847.312988f; Coords.z = 32.558411f;                 TPto(Coords); }
	if (Menu::Option("Fire Station - LS HQ")) { Vector3 Coords;                 Coords.x = -639.470703f; Coords.y = -122.451233f; Coords.z = 38.112556f;                 TPto(Coords); }
	if (Menu::Option("Fire Station - LS Station 7")) { Vector3 Coords;                 Coords.x = 1200.554443f; Coords.y = -1457.295044f; Coords.z = 35.248623f;                 TPto(Coords); }
	if (Menu::Option("Fire Station - Paleto Bay")) { Vector3 Coords;                 Coords.x = -387.178131f; Coords.y = 6125.819336f; Coords.z = 31.586800f;                 TPto(Coords); }
	if (Menu::Option("Fire Station - Sandy Shores")) { Vector3 Coords;                 Coords.x = 1691.670166f; Coords.y = 3579.191895f; Coords.z = 35.636360f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Lifeguard 1")) { Vector3 Coords;                 Coords.x = -1290.980835f; Coords.y = -1757.102905f; Coords.z = 3.058975f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Lifeguard 2")) { Vector3 Coords;                 Coords.x = -1373.146851f; Coords.y = -1627.157837f; Coords.z = 3.364384f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Lifeguard 3")) { Vector3 Coords;                 Coords.x = -1432.086426f; Coords.y = -1512.424316f; Coords.z = 3.214696f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Lifeguard 4")) { Vector3 Coords;                 Coords.x = -1468.421753f; Coords.y = -1391.712158f; Coords.z = 3.525731f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Lifeguard 5")) { Vector3 Coords;                 Coords.x = -1520.238281f; Coords.y = -1275.765625f; Coords.z = 2.950766f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Lifeguard 6")) { Vector3 Coords;                 Coords.x = -1560.793945f; Coords.y = -1158.407593f; Coords.z = 3.295668f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Lifeguard 7")) { Vector3 Coords;                 Coords.x = -1798.075684f; Coords.y = -858.578857f; Coords.z = 8.840805f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Lifeguard 8")) { Vector3 Coords;                 Coords.x = -1904.379150f; Coords.y = -713.960449f; Coords.z = 8.344188f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Lifeguard 9")) { Vector3 Coords;                 Coords.x = -2006.548340f; Coords.y = -560.289368f; Coords.z = 12.898447f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Paleto Bay")) { Vector3 Coords;                 Coords.x = -440.541779f; Coords.y = 6019.399902f; Coords.z = 31.262650f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Rockford Hills")) { Vector3 Coords;                 Coords.x = -475.191345f; Coords.y = -353.762787f; Coords.z = 34.002174f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Sandy Shores")) { Vector3 Coords;                 Coords.x = 1850.026367f; Coords.y = 3679.041748f; Coords.z = 33.983913f;                 TPto(Coords); }
	if (Menu::Option("Hospital - Strawberry Ave")) { Vector3 Coords;                 Coords.x = 337.111145f; Coords.y = -1393.440063f; Coords.z = 32.257248f;                 TPto(Coords); }
	if (Menu::Option("Hospital - textile City")) { Vector3 Coords;                 Coords.x = 376.534027f; Coords.y = -581.015381f; Coords.z = 28.707024f;                 TPto(Coords); }
	if (Menu::Option("Police - La Mesa")) { Vector3 Coords;                 Coords.x = 817.000000f; Coords.y = -1290.000000f; Coords.z = 26.146124f;                 TPto(Coords); }
	if (Menu::Option("Police - Mission Row")) { Vector3 Coords;                 Coords.x = 429.601593f; Coords.y = -982.458923f; Coords.z = 30.463333f;                 TPto(Coords); }
	if (Menu::Option("Police - Paleto Bay")) { Vector3 Coords;                 Coords.x = -440.541779f; Coords.y = 6019.399902f; Coords.z = 31.262650f;                 TPto(Coords); }
	if (Menu::Option("Police - Rancho")) { Vector3 Coords;                 Coords.x = 360.000000f; Coords.y = -1583.000000f; Coords.z = 29.105696f;                 TPto(Coords); }
	if (Menu::Option("Police - Rockford Hills")) { Vector3 Coords;                 Coords.x = -557.245789f; Coords.y = -142.276871f; Coords.z = 38.247066f;                 TPto(Coords); }
	if (Menu::Option("Police - Sandy Shores")) { Vector3 Coords;                 Coords.x = 1858.026367f; Coords.y = 3679.041748f; Coords.z = 33.983913f;                 TPto(Coords); }
	if (Menu::Option("Police - Vespucci Beach")) { Vector3 Coords;                 Coords.x = -1312.137085f; Coords.y = -1528.899658f; Coords.z = 4.159692f;                 TPto(Coords); }
	if (Menu::Option("Police - Vespucci HQ")) { Vector3 Coords;                 Coords.x = -1110.682617f; Coords.y = -846.652466f; Coords.z = 19.361103f;                 TPto(Coords); }
	if (Menu::Option("Police - Vinewood")) { Vector3 Coords;                 Coords.x = 642.722046f; Coords.y = 0.252486f; Coords.z = 82.890823f;                 TPto(Coords); }
	if (Menu::Option("Police - Vinewood Hills Ranger")) { Vector3 Coords;                 Coords.x = 388.549255f; Coords.y = 791.305176f; Coords.z = 190.476166f;                 TPto(Coords); }
}

//Apartments Online
void  TTPApartss()
{
	Menu::Title("");
	Menu::Subtitle("Apartments Online");
	if (Menu::Option("3 Alta St")) { Vector3 Coords;                 Coords.x = -261.747620f; Coords.y = -976.950623f; Coords.z = 30.971106f;                 TPto(Coords); }
	if (Menu::Option("4 Integrit Way")) { Vector3 Coords;                 Coords.x = -54.668861f; Coords.y = -588.563904f; Coords.z = 36.193024f;                 TPto(Coords); }
	if (Menu::Option("Bay City Ave Apt 45")) { Vector3 Coords;                 Coords.x = -986.981323f; Coords.y = -1445.468018f; Coords.z = 5.942831f;                 TPto(Coords); }
	if (Menu::Option("Blvd Del Perro Apt 18")) { Vector3 Coords;                 Coords.x = -1611.278442f; Coords.y = -424.959167f; Coords.z = 40.691673f;                 TPto(Coords); }
	if (Menu::Option("Cougar Ave Apt 19")) { Vector3 Coords;                 Coords.x = -1538.185791f; Coords.y = -328.037628f; Coords.z = 47.265511f;                 TPto(Coords); }
	if (Menu::Option("Dream Tower Apt 15")) { Vector3 Coords;                 Coords.x = -755.427124f; Coords.y = -749.572021f; Coords.z = 26.665794f;                 TPto(Coords); }
	if (Menu::Option("Eclipse Towers")) { Vector3 Coords;                 Coords.x = -773.505920f; Coords.y = 296.763641f; Coords.z = 85.830109f;                 TPto(Coords); }
	if (Menu::Option("Milton Dr 0504")) { Vector3 Coords;                 Coords.x = -635.008545f; Coords.y = 161.922287f; Coords.z = 59.699619f;                 TPto(Coords); }
	if (Menu::Option("Milton Dr Apt 13")) { Vector3 Coords;                 Coords.x = -508.407379f; Coords.y = 112.594910f; Coords.z = 63.480057f;                 TPto(Coords); }
	if (Menu::Option("Power St 1162")) { Vector3 Coords;                 Coords.x = 269.939819f; Coords.y = -150.483261f; Coords.z = 64.293060f;                 TPto(Coords); }
	if (Menu::Option("Prosperity St Apt 21")) { Vector3 Coords;                 Coords.x = -1556.567627f; Coords.y = -415.096069f; Coords.z = 42.539715f;                 TPto(Coords); }
	if (Menu::Option("Richard Majestic")) { Vector3 Coords;                 Coords.x = -956.922424f; Coords.y = -403.93678f; Coords.z = 38.278751f;                 TPto(Coords); }
	if (Menu::Option("South Rockford Dr")) { Vector3 Coords;                 Coords.x = -837.304504f; Coords.y = -849.619080f; Coords.z = 19.522774f;                 TPto(Coords); }
	if (Menu::Option("South Rockford Dr Apt 13")) { Vector3 Coords;                 Coords.x = -818.702759f; Coords.y = -989.048035f; Coords.z = 13.501397f;                 TPto(Coords); }
	if (Menu::Option("The Royal Apt 19")) { Vector3 Coords;                 Coords.x = -201.004333f; Coords.y = 91.132614f; Coords.z = 69.530350f;                 TPto(Coords); }
	if (Menu::Option("Vespucci Blvd Apt 1")) { Vector3 Coords;                 Coords.x = -671.988403f; Coords.y = -854.607910f; Coords.z = 23.965218f;                 TPto(Coords); }
	if (Menu::Option("Weazel Plaza")) { Vector3 Coords;                 Coords.x = -924.684082f; Coords.y = -465.046417f; Coords.z = 36.882763f;                 TPto(Coords); }
}















void AircraftCarrier()
{
	STREAMING::REQUEST_IPL("hei_carrier");
	STREAMING::REQUEST_IPL("hei_carrier_DistantLights");
	STREAMING::REQUEST_IPL("hei_Carrier_int1");
	STREAMING::REQUEST_IPL("hei_Carrier_int2");
	STREAMING::REQUEST_IPL("hei_Carrier_int3");
	STREAMING::REQUEST_IPL("hei_Carrier_int4");
	STREAMING::REQUEST_IPL("hei_Carrier_int5");
	STREAMING::REQUEST_IPL("hei_Carrier_int6");
	STREAMING::REQUEST_IPL("hei_carrier_LODLights");
}
void ufo()
{
	STREAMING::REQUEST_IPL("ufo");
	STREAMING::REQUEST_IPL("ufo_lod");
	STREAMING::REQUEST_IPL("ufo_eye");
}

void landmark()
{
	Menu::Title("");	
	Menu::Subtitle("Land Marks");
	if (teleportplayertocoord("Aircraft Carrier", 3084.7303f, -4770.709f, 15.2620f, true)) { AircraftCarrier(); }
	teleportplayertocoords("Airport Entrance", -1034.6f, -2733.6f, 13.8f);
	teleportplayertocoords("Airport Runway", -1336.0f, -3044.0f, 13.9f);
	teleportplayertocoords("Altruist Cult Camp", -1170.841f, 4926.646f, 224.295f);
	teleportplayertocoords("Calafia Train Bridge", -517.869f, 4425.284f, 89.795f);
	teleportplayertocoords("Cargo Ship", 899.678f, -2882.191f, 19.013f);
	teleportplayertocoords("Chumash Historic Family Pier", -3426.683f, 967.738f, 8.347f);
	teleportplayertocoords("Del Perro Pier", -1850.127f, -1231.751f, 13.017f);
	teleportplayertocoords("Devin Weston's House", -2639.872f, 1866.812f, 160.135f);
	teleportplayertocoords("El Burro Heights", 1384.0f, -2057.1f, 52.0f);
	teleportplayertocoords("Elysian Island", 338.2f, -2715.9f, 38.5f);
	teleportplayertocoords("Far North San Andreas", 24.775f, 7644.102f, 19.055f);
	teleportplayertocoords("Ferris Wheel", -1670.7f, -1125.0f, 13.0f);
	teleportplayertocoords("Fort Zancudo Tower", -2358.132f, 3249.754f, 101.451f);
	if (teleportplayertocoord("Fort Zancudo (Opened)", -2047.4f, 3132.1f, 32.8f, false)) STREAMING::REQUEST_IPL("cs3_07_mpgates");
	teleportplayertocoords("Jetsam", 760.4f, -2943.2f, 5.8f);
	teleportplayertocoords("Jolene Cranley-Evans Ghost", 3059.620f, 5564.246f, 197.091f);
	teleportplayertocoords("Kortz Center", -2243.810f, 264.048f, 174.615f);
	teleportplayertocoords("Marlowe Vineyards", -1868.971f, 2095.674f, 139.115f);
	teleportplayertocoords("McKenzie Airfield", 2121.7f, 4796.3f, 41.1f);
	teleportplayertocoords("Merryweather Dock", 486.417f, -3339.692f, 6.070f);
	teleportplayertocoords("Mineshaft", -595.342f, 2086.008f, 131.412f);
	teleportplayertocoords("Mount Chiliad", 450.718f, 5566.614f, 806.183f);
	teleportplayertocoords("Life Invader Building Roof", -1076.255f, -247.1436f, 57.9219f);
	teleportplayertocoords("NOOSE Headquarters", 2535.243f, -383.799f, 92.993f);
	teleportplayertocoords("Pacific Standard Bank", 235.046f, 216.434f, 106.287f);
	teleportplayertocoords("Paleto Bay Pier", -275.522f, 6635.835f, 7.425f);
	teleportplayertocoords("Playboy Mansion", -1475.234f, 167.088f, 55.841f);
	teleportplayertocoords("Police Station", 436.491f, -982.172f, 30.699f);
	teleportplayertocoords("Quarry", 2954.196f, 2783.410f, 41.004f);
	teleportplayertocoords("Sandy Shores Airfield", 1747.0f, 3273.7f, 41.1f);
	teleportplayertocoords("Satellite Dishes", 2062.123f, 2942.055f, 47.431f);
	teleportplayertocoords("Sisyphus Theater Stage", 686.245f, 577.950f, 130.461f);
	teleportplayertocoords("Meth Lab", 1391.773f, 3608.716f, 38.942f);
	teleportplayertocoords("Weed Farm", 2208.777f, 5578.235f, 53.735f);
	teleportplayertocoords("Wind Farm", 2354.0f, 1830.3f, 101.1f);
}

void HighLocations()
{
	Menu::Title("");
	Menu::Subtitle("High Locations");
	teleportplayertocoords("Crane Top", -119.879f, -977.357f, 304.249f);
	teleportplayertocoords("FIB Building Roof", 150.126f, -754.591f, 262.865f);
	teleportplayertocoords("Galileo Observatory Roof", -438.804f, 1076.097f, 352.411f);
	teleportplayertocoords("IAA Building Roof", 134.085f, -637.859f, 262.851f);
	teleportplayertocoords("Maze Bank Roof", -75.015f, -818.215f, 326.176f);
	teleportplayertocoords("Palmer-Taylor Power Station Chimney", 2732.931f, 1577.540f, 83.671f);
	teleportplayertocoords("Sandy Shores Building Site Crane", 1051.209f, 2280.452f, 89.727f);
	teleportplayertocoords("Satellite Dish", 2034.988f, 2953.105f, 74.602f);
	teleportplayertocoords("Sky High", -119.879f, -977.357f, 10000.0f);
	if (teleportplayertocoord("UFO (Fort Zancudo)", -2052.000f, 3237.000f, 1456.973f, false)) ufo();
	teleportplayertocoords("Windmill Top", 2026.677f, 1842.684f, 133.313f);
}

void underwater()
{
	Menu::Title("");
	Menu::Subtitle("Underwater");
	teleportplayertocoords("Hatch", 4273.950f, 2975.714f, -170.746f);
	teleportplayertocoords("Sea Monster", -3373.726f, 504.714f, -24.656f);
	teleportplayertocoords("Sunken Body", -3161.078f, 3001.998f, -37.974f);
	teleportplayertocoords("Sunken Cargo Ship", 3199.748f, -379.018f, -22.500f);
	teleportplayertocoords("Sunken Plane", -942.350f, 6608.752f, -20.912f);
	teleportplayertocoords("Tank WW2", 4201.633f, 3643.821f, -39.016f);
	if (teleportplayertocoord("Tunnel (Humane Labs)", 3838.47f, 3673.06f, -19.7281f, false)) 	STREAMING::REQUEST_IPL("chemgrill_grp1");
	teleportplayertocoords("UFO", 762.426f, 7380.371f, -111.377f);

}
void OnlineRelated()
{
	Menu::Title("");
	Menu::Subtitle("Online");
	teleportplayertocoords("10 Car Garage", 229.3570f, -992.9106f, -98.9999f);
	teleportplayertocoords("2 Car Garage", 173.2904f, -1003.600f, -98.9999f);
	teleportplayertocoords("6 Car Garage", 197.8153f, -1002.293f, -98.5503f);
	teleportplayertocoords("Impound Lot", 391.4746f, -1637.9750f, 29.3153f);
	teleportplayertocoords("LSPD Char Creator", 402.6675f, -1003.0000f, -99.0040f);
	teleportplayertocoords("Mission Carpark", 405.9359f, -954.0912f, -99.0041f);
	teleportplayertocoords("Mors Mutual Impound", -222.1977f, -1185.8500f, 23.0294f);
}
void Bahama()
{
	STREAMING::REQUEST_IPL("sm_16_interior_v_bahama_milo_");
	STREAMING::REQUEST_IPL("hei_sm_16_interior_v_bahama_milo_");
	//STREAMING::REQUEST_IPL("chemgrill_grp1");
}
void northyankton()
{
	STREAMING::REQUEST_IPL("prologue01");
	STREAMING::REQUEST_IPL("Prologue01c");
	STREAMING::REQUEST_IPL("Prologue01d");
	STREAMING::REQUEST_IPL("Prologue01e");
	STREAMING::REQUEST_IPL("Prologue01f");
	STREAMING::REQUEST_IPL("Prologue01g");
	STREAMING::REQUEST_IPL("prologue01h");
	STREAMING::REQUEST_IPL("prologue01i");
	STREAMING::REQUEST_IPL("prologue01j");
	STREAMING::REQUEST_IPL("prologue01k");
	STREAMING::REQUEST_IPL("prologue01z");
	STREAMING::REQUEST_IPL("prologue02");
	STREAMING::REQUEST_IPL("prologue03");
	STREAMING::REQUEST_IPL("prologue03b");
	STREAMING::REQUEST_IPL("prologue03_grv_cov");
	STREAMING::REQUEST_IPL("prologue03_grv_dug");
	STREAMING::REQUEST_IPL("prologue03_grv_fun");
	STREAMING::REQUEST_IPL("prologue04");
	STREAMING::REQUEST_IPL("prologue04b");
	STREAMING::REQUEST_IPL("prologue04_cover");
	STREAMING::REQUEST_IPL("prologue05");
	STREAMING::REQUEST_IPL("prologue05b");
	STREAMING::REQUEST_IPL("prologue06");
	STREAMING::REQUEST_IPL("prologue06b");
	STREAMING::REQUEST_IPL("prologue06_int");
	STREAMING::REQUEST_IPL("prologuerd");
	STREAMING::REQUEST_IPL("prologuerdb");
	STREAMING::REQUEST_IPL("prologue_DistantLights");
	STREAMING::REQUEST_IPL("prologue_grv_torch");
	STREAMING::REQUEST_IPL("prologue_m2_door");
	STREAMING::REQUEST_IPL("prologue_LODLights");
	STREAMING::REQUEST_IPL("DES_ProTree_start");
}
void carshowroom()
{
	STREAMING::REQUEST_IPL("shutter_open");
	STREAMING::REQUEST_IPL("csr_inMission");
	STREAMING::REQUEST_IPL("shr_int");
	STREAMING::REQUEST_IPL("v_carshowroom");
	STREAMING::REQUEST_IPL("shutter_closed");
	STREAMING::REQUEST_IPL("fakeint");

}
void Interiors()
{
	Menu::Title("");
	Menu::Subtitle("Interiors");
	teleportplayertocoords("Ammunation Gun Range", 22.153f, -1072.854f, 29.797f);
	if (teleportplayertocoord("Bahama Mamas West", -1387.08f, -588.4f, 30.3195f, false))  Bahama();
	teleportplayertocoords("Bank (Blaine County)", -109.299f, 6464.035f, 31.627f);
	if (teleportplayertocoord("Bank (North Yankton)", 5309.519f, -5212.375f, 83.522f, false))  northyankton();
	teleportplayertocoords("Bank Vault", 255.851f, 217.030f, 101.683f);
	if (teleportplayertocoord("Car Showroom", -57.6615f, -1097.595f, 26.4224f, false)) carshowroom();
	//teleportplayertocoords("Cluckin' Bell Factory", -70.0624f, 6263.53f, 31.0909f, { "CS1_02_cf_onmission1", "CS1_02_cf_onmission2", "CS1_02_cf_onmission3", "CS1_02_cf_onmission4" }, { "CS1_02_cf_offmission" }),
	//teleportplayertocoords("Darnell Bros. Garment Factory", 712.7159f, -962.9055f, 30.3953f, { "id2_14_during1", "bnkheist_apt_norm", "bnkheist_apt_dest" }, {}), // both norm and dest?
	//teleportplayertocoords("East Los Santos Foundry", 1080.5678f, -1974.9805f, 31.4715f, { "lr_id1_17_interior_v_foundry_milo_" }, {}, true, false, true),
	//teleportplayertocoords("Epsilon Storage Room", 243.3000f, 365.7000f, 105.7383f, { "hei_hw1_01_interior_v_epsilonism_milo_" }, {}, true, false, true),
	teleportplayertocoords("FIB Building Burnt", 159.553f, -738.851f, 246.152f);
	teleportplayertocoords("FIB Building Floor 47", 134.573f, -766.486f, 234.152f);
	teleportplayertocoords("FIB Building Floor 49", 134.635f, -765.831f, 242.152f);
	//teleportplayertocoords("FIB Building Lobby", 110.4f, -744.2f, 45.7f, { "FIBlobby" }, { "FIBlobbyfake" }, false, false, true),
	teleportplayertocoords("FIB Building Top Floor", 135.733f, -749.216f, 258.152f);
	teleportplayertocoords("Garage (From Story Mode)", 195.1810f, -1024.9241f, -99.0000f);
	//{ "Hayes Autos", 478.5032f, -1316.4756f, 29.2040f, {}, {}, true ),
	//teleportplayertocoords("Hospital (Destroyed)", 302.651f, -586.293f, 43.3129f, { "RC12B_Destroyed", "RC12B_HospitalInterior" }, { "RC12B_Default", "RC12B_Fixed" }),
	teleportplayertocoords("Humane Labs Lower Level", 3525.495f, 3705.301f, 20.992f);
	teleportplayertocoords("Humane Labs Upper Level", 3618.52f, 3755.76f, 28.6901f);
	teleportplayertocoords("IAA Office", 117.220f, -620.938f, 206.047f);
	teleportplayertocoords("Janitor's Apartment", -110.721f, -8.22095f, 70.5197f);
	//teleportplayertocoords("Jewel Store", -630.07f, -236.332f, 38.0571f, { "post_hiest_unload" }, { "jewel2fake", "bh1_16_refurb" }),
	teleportplayertocoords("Lester's House", 1273.898f, -1719.304f, 54.771f);
	//teleportplayertocoords("Life Invader Office", -1049.13f, -231.779f, 39.0144f, { "LInvader", "facelobby" }, { "facelobbyfake" }),
	//teleportplayertocoords("Madrazo's Ranch", 1398.0800f, 1143.8001f, 114.3320f, { "apa_ch2_03c_interior_v_ranch_milo_" }, {}, true, false, true),
	//teleportplayertocoords("Max Renda Shop", -583.1606f, -282.3967f, 35.394f, { "refit_unload" }, { "bh1_16_doors_shut" }, false, false, true),
	//teleportplayertocoords("Meat Processing Factory", 976.1100f, -2184.4500f, 29.9779f, { "lr_id1_10_interior_v_abattoir_milo_" }, {}, true, false, true),
	//teleportplayertocoords("Morgue", 275.446f, -1361.11f, 24.5378f, { "coronertrash", "Coroner_Int_on" }, { "coronertrash", "Coroner_Int_off" }, false, false, true),
	teleportplayertocoords("Motel Room", 152.2600f, -1004.4700f, -99.0000f);
	//teleportplayertocoords("Movie Theatre", -1427.3129f, -245.1729f, 16.8037f, false, false, true),
	teleportplayertocoords("Omega's Garage", 2330.6196f, 2572.6108f, 46.6801f);
	/*teleportplayertocoords("ONeil's Farm", 2454.78f, 4971.92f, 46.8103f, { "farm", "farm_props", "farmint", "des_farmhs_start_occl", "des_farmhs_startimap" }, { "farm_burnt", "farm_burnt_props", "farmint_cap", "des_farmhs_endimap", "des_farmhs_end_occl" }),
	teleportplayertocoords("ONeil's Farm (Burnt)", 2454.78f, 4971.92f, 46.8103f, { "farm_burnt", "farm_burnt_props", "farmint", "des_farmhs_endimap", "des_farmhs_end_occl" }, { "farmint_cap", "farm", "farm_props", "des_farmhs_start_occl", "des_farmhs_startimap" }),
	teleportplayertocoords("Psychiatrist's Office", -1908.0244f, -573.4244f, 19.0972f, { "hei_sm_27_interior_v_psycheoffice_milo_" }, {}, false, false, true),
	teleportplayertocoords("Solomon's Office", -1005.8400f, -478.9200f, 50.0284f, { "hei_bh1_03_interior_v_58_sol_office_milo_" }, {}),
	teleportplayertocoords("Split Sides Comedy Club", 377.0883f, -991.8690f, -98.6035, { "apa_ss1_12_interior_v_comedy_milo_" }, {}),
	teleportplayertocoords("Stadium", -248.4916f, -2010.509f, 34.5743f, { "SP1_10_real_interior" }, { "SP1_10_fake_interior" }, false, false, true),
	teleportplayertocoords("Strip Club, Behind Bar", 126.1211f, -1278.5130f, 29.2696f),*/
	//teleportplayertocoords("Tequi-la-la Bar", -556.1166f, 284.5194f, 82.1763f, { "apa_ss1_11_interior_v_rockclub_milo_" }, {}),
	teleportplayertocoords("Torture Room", 136.514f, -2203.15f, 7.30914f);
	//teleportplayertocoords("Trevor's Trailer (Clean)", 1975.5515f, 3820.5376f, 33.4363f, { "TrevorsTrailerTidy" }, { "TrevorsTrailerCollision", "TrevorsTrailer", "TrevorsMP" }),
	//teleportplayertocoords("Trevor's Trailer (Dirty)", 1975.5515f, 3820.5376f, 33.4363f, { "TrevorsTrailerCollision", "TrevorsTrailer", "TrevorsMP" }, { "TrevorsTrailerTidy" }),
	//teleportplayertocoords("Union Depository", 2.6968f, -667.0166f, 16.1306f, { "FINBANK" }, { "DT1_03_Shutter", "DT1_03_Gr_Closed" }, false, false, true),
}