#include"MAIN.h"

bool deletecarbool = true;
bool Sppwnin = true;

char* CharKeyboard(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}
void SpawnVeh2(char* toSpawn)
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
		if (deletecarbool) deletecar();
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
		if (Sppwnin) PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}

void inputveh()
{
	if (Menu::Option("Input Vehicle")) {
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID());


		if (bPlayerExists)
		{
			GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(TRUE, "FMMC_KEY_TIP8", "", "", "", "", "", 12);
			while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
			char* keyboardResult = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
			Hash hash = GAMEPLAY::GET_HASH_KEY(keyboardResult);
			if (STREAMING::IS_MODEL_IN_CDIMAGE(hash) && STREAMING::IS_MODEL_A_VEHICLE(hash))
			{
				STREAMING::REQUEST_MODEL(hash);
				while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(0);
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				SpawnVeh2(keyboardResult);
				WAIT(0);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
				ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
			}
		}

	}
}
void By_DLC()
{
	Menu::Title("");
	Menu::Subtitle("Vehicle Spawner By DLC");
	Menu::MenuOption("BeachBum", BeachBum_);
	Menu::MenuOption("Business", Business_);
	Menu::MenuOption("HighLife", HighLife_);
	Menu::MenuOption("Im Not A Hipster", ImNotAHipster_);
	Menu::MenuOption("FlightSchool", FlightSchool_);
	Menu::MenuOption("Last Team Standing", LastTeamStanding_);
	Menu::MenuOption("NextGenRelease", NextGenRelease_);
	Menu::MenuOption("FestiveSuprise", FestiveSuprise_);
	Menu::MenuOption("Heists", Heists_);
	Menu::MenuOption("III Gotten Gains part 1", III_Gotten_Gains_part1_);
	Menu::MenuOption("III Gotten Gains part 2", III_Gotten_Gains_part2_);
	Menu::MenuOption("Halloween", halloween_);
	Menu::MenuOption("Excutives and other Criminals", Excutives_and_other_Criminals_);
	Menu::MenuOption("Valentine", Valentine_);
	Menu::MenuOption("Bennys", Bennys_update_);
	Menu::MenuOption("Finance and Felony", Finance_and_Felony_);
	Menu::MenuOption("Diamond Casino", dlc148);
	Menu::MenuOption("Diamond Casino Heist", dlc150);
}

void spawner()
{
	Menu::Title("");
	Menu::Subtitle("Vehicle Spawner");
	Menu::MenuOption("Sort By DLC", By_DLC_);
	Menu::Toggle("Delete Old Car", deletecarbool);
	Menu::Toggle("Spawn in Car", Sppwnin);
	inputveh();
	Menu::MenuOption("Super", Super);
	Menu::MenuOption("Sports", Sports);
	Menu::MenuOption("Sport Classic", SportClassic);
	Menu::MenuOption("Offroad", Offroad);
	Menu::MenuOption("Sedans", Sedans);
	Menu::MenuOption("Coupes", Coupes);
	Menu::MenuOption("Muscle", Muscle);
	Menu::MenuOption("Utility & Vans", Utility);
	Menu::MenuOption("Commercial", Commercial);
	Menu::MenuOption("Compacts", Compacts);
	Menu::MenuOption("SUV", SUV);
	Menu::Break("Bikes");
	Menu::MenuOption("Cycles", Cycles);
	Menu::MenuOption("Motorcycles", Motorcycles);
	Menu::Break("Flying Vehicles");
	Menu::MenuOption("Helicopters", Helicopters);
	Menu::MenuOption("Planes", Planes);
	Menu::Break("Service Vehicles");
	Menu::MenuOption("Emergency", Emergency);
	Menu::MenuOption("Industrial", Industrial);
	Menu::MenuOption("Trailer", Trailer);
	Menu::MenuOption("Trains", Trains);
	Menu::MenuOption("Service", Service);
	Menu::MenuOption("Boats", Boats);
	Menu::MenuOption("Industrial", Industrial);
	Menu::MenuOption("Military", Military);
}


void Superr()
{
	Menu::Title("");
	Menu::Subtitle("Super");
	Menu::SpawnOption("Adder", "ADDER");
	Menu::SpawnOption("Autarch", "autarch");
	Menu::SpawnOption("Banshee 900R", "BANSHEE2");
	Menu::SpawnOption("Bullet", "BULLET");
	Menu::SpawnOption("Cheetah", "CHEETAH");
	Menu::SpawnOption("Deluxo", "deluxo");
	Menu::SpawnOption("Entity FX", "ENTITYXF");
	Menu::SpawnOption("FMJ", "FMJ");
	Menu::SpawnOption("Inferuns", "INFERNUS");
	Menu::SpawnOption("Nero", "NERO");
	Menu::SpawnOption("Nero Custom ", "NERO2");
	Menu::SpawnOption("Osiris", "OSIRIS");
	Menu::SpawnOption("LE7B", "LE7B");
	Menu::SpawnOption("Itali GTB", "ITALIGTB");
	Menu::SpawnOption("Itali GTB Custom", "ITALIGTB2");
	Menu::SpawnOption("Pfister 811", "PFISTER811");
	Menu::SpawnOption("Prototipo", "PROTOTIPO");
	Menu::SpawnOption("Reaper", "REAPER");
	Menu::SpawnOption("Sultan RS", "SULTANRS");
	Menu::SpawnOption("T20", "T20");
	Menu::SpawnOption("Tempesta", "TEMPESTA");
	Menu::SpawnOption("Turismor", "TURISMOR");
	Menu::SpawnOption("Tyrus", "TYRUS");
	Menu::SpawnOption("Tezeract", "tezeract");
	Menu::SpawnOption("Entity XXR", "entity2");
	Menu::SpawnOption("Vacca", "VACCA");
	Menu::SpawnOption("Voltic", "VOLTIC");
	Menu::SpawnOption("Zentorno", "ZENTORNO");
	Menu::SpawnOption("Visione", "visione");
	Menu::SpawnOption("Vigilante", "Vigilante");
	Menu::SpawnOption("Voltic", "VOLTIC2"); 
	Menu::SpawnOption("Penetrator", "PENETRATOR");
	Menu::SpawnOption("GP1", "GP1");

}
void dlccars()
{
	Menu::Title("");
	Menu::Subtitle("Diamond Casino");
	Menu::SpawnOption("Caracara", "caracara2");
	Menu::SpawnOption("Drafter", "drafter");
	Menu::SpawnOption("Drafter", "drafter");
	Menu::SpawnOption("Emerus", "emerus");
	Menu::SpawnOption("Gauntlet Classic", "gauntlet3");
	Menu::SpawnOption("GP1", "gauntlet4");
	Menu::SpawnOption("Gauntlet Hellfire", "hellion");
	Menu::SpawnOption("Issi Sport", "issi7");
	Menu::SpawnOption("Jugular", "jugular");
	Menu::SpawnOption("Locust", "locust");
	Menu::SpawnOption("Nebula", "nebula");
	Menu::SpawnOption("Neo", "neo");
	Menu::SpawnOption("Novak", "novak");
	Menu::SpawnOption("Paragon", "paragon");
	Menu::SpawnOption("Paragon R (Armored)", "paragon2");
	Menu::SpawnOption("Peyote Gasser", "peyote2");
	Menu::SpawnOption("Rampant Rocket", "rrocket");
	Menu::SpawnOption("S80", "s80");
	Menu::SpawnOption("Thrax", "thrax");
	Menu::SpawnOption("Zorrusso", "zorrusso");
}


void sportspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Sports Cars");
	 Menu::SpawnOption("Alpha", "ALPHA");
	 Menu::SpawnOption("Bravado Banshee", "BANSHEE");
	 Menu::SpawnOption("Vapid Flash GT", "flashgt");
	 Menu::SpawnOption("Grotti Bestia GTS", "BESTIAGTS");
	 Menu::SpawnOption("Dinka Blista Compact", "BLISTA2");
	 Menu::SpawnOption("Dinka Go Go Money Blista", "BLISTA3");
	 Menu::SpawnOption("Grotti Itali GTO", "ITALIGTO");
	 Menu::SpawnOption("Benefactor Schlagen GT", "SCHLAGEN");
	 Menu::SpawnOption("Bravado Buffalo", "BUFFALO");
	 Menu::SpawnOption("Bravado Buffalo S", "BUFFALO2");
	 Menu::SpawnOption("Bravado Sprunk Buffalo", "BUFFALO3");
	 Menu::SpawnOption("Ocelot Swinger", "swinger");
	 Menu::SpawnOption("Phister Comet Safari", "comet4");
	 Menu::SpawnOption("Phister Comet SR", "comet5");
	 Menu::SpawnOption("Grotti Carbonizzare", "CARBONIZZARE");
	 Menu::SpawnOption("Phister Comet", "COMET2");
	 Menu::SpawnOption("Inverto Coquette", "COQUETTE");
	 Menu::SpawnOption("Coil Cyclone", "cyclone");
	 Menu::SpawnOption("Annis Elegy Retro Custom", "ELEGY");
	 Menu::SpawnOption("Annis Elegy RH8", "ELEGY2");
	 Menu::SpawnOption("AlBenefactor Feltzerpha", "FELTZER2");
	 Menu::SpawnOption("Lampadeti Furore GT", "FUROREGT");
	 Menu::SpawnOption("Schyster Fusilade", "FUSILADE");
	 Menu::SpawnOption("Karin Futo", "FUTO");
	 Menu::SpawnOption("Dinka Jester", "JESTER");
	 Menu::SpawnOption("Dinka Jester(Racecar)", "JESTER2");
	 Menu::SpawnOption("Vapid Dominator GTX", "dominator3");
	 Menu::SpawnOption("Hijak Khamelion", "KHAMELION");
	 Menu::SpawnOption("Karin Kuruma", "KURUMA");
	 Menu::SpawnOption("Karin Karuma(Armoured)", "KURUMA2");
	 Menu::SpawnOption("Annis Apocalypse ZR380", "ZR380");
	 Menu::SpawnOption("Annis Nightmare ZR380", "ZR3803");
	 Menu::SpawnOption("Ocelot Lynx", "LYNX");
	 Menu::SpawnOption("Dewbauchdee Massacro", "MASSACRO");
	 Menu::SpawnOption("Dewbauchdee Massacro (racecar)", "MASSACRO2");
	 Menu::SpawnOption("Ocelot Pariah", "pariah");
	 Menu::SpawnOption("Coil Raiden", "raiden");
	 Menu::SpawnOption("Obey 9F", "NINEF");
	 Menu::SpawnOption("Obey 9F Cabrio", "NINEF2");
	 Menu::SpawnOption("Obey Omnis", "OMNIS");
	 Menu::SpawnOption("Maibatsu Penumbra", "PENUMBRA");
	 Menu::SpawnOption("Dewbauchee Rapid GT", "RAPIDGT");
	 Menu::SpawnOption("Overflod Tyrant", "tyrant");
	 Menu::SpawnOption("Declasse Hotring Sabre", "hotring");
	 Menu::SpawnOption("Vapid Ellie", "ellie");
	 Menu::SpawnOption("Dewbauchee Rapid GT(Convertable)", "RAPIDGT2");
	 Menu::SpawnOption("BF Raptor", "RAPTOR");
	 Menu::SpawnOption("Benefactor Schafter V12", "SCHAFTER3");
	 Menu::SpawnOption("Benefactor Schafter LWB", "SCHAFTER4");
	 Menu::SpawnOption("Chevel Taipan", "taipan");
	 Menu::SpawnOption("Schwartzer", "SCHWARZER");
	 Menu::SpawnOption("Dinka Jester Classic", "jester3");
	 Menu::SpawnOption("Dewbauchee Seven-70", "SEVEN70");
	 Menu::SpawnOption("Karin Sultan", "SULTAN");
	 Menu::SpawnOption("Benefactor Surano", "SURANO");
	 Menu::SpawnOption("Dewbauchee Specter", "SPECTER");
	 Menu::SpawnOption("Dewbauchee Specter Custom", "SPECTER2");
	 Menu::SpawnOption("Declasse Scramjet", "scramjet");
	 Menu::SpawnOption("Declasse Drift Tampa", "TAMPA2");
	 Menu::SpawnOption("Lampadati Tropos Rallye", "TROPOS");
	 Menu::SpawnOption("Bravado Verlierer", "VERLIERER2");
	 Menu::SpawnOption("Imponte Ruiner 2000", "RUINER2");
	 Menu::SpawnOption("JoBuilt Phantom Wedge", "PHANTOM2");
	 Menu::SpawnOption("Hijak Rusto", "RUSTON");



}
void sportclassicsspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Sport Classic Cars");
	 Menu::SpawnOption("Albanny Roosevelt", "BTYPE");
	 Menu::SpawnOption("Albanny Roosevelt Valor", "BTYPE3");
	 Menu::SpawnOption("Lampadati Casco", "CASCO");
	 Menu::SpawnOption("Invetero Coquette Classic", "COQUETTE2");
	 Menu::SpawnOption("Declass Tulip", "TULIP");
	 Menu::SpawnOption("Declass Vamos", "VAMOS");
	 Menu::SpawnOption("Benefactor Stirling GT", "FELTZER3");
	 Menu::SpawnOption("Dewbauchee JB 700", "JB700");
	 Menu::SpawnOption("Grotti GT500", "gt500");
	 Menu::SpawnOption("Phister Neon", "neon");
	 Menu::SpawnOption("Albany Hermes", "hermes");
	 Menu::SpawnOption("Vapid Hustler", "hustler");
	 Menu::SpawnOption("Declasse Mamba", "MAMBA");
	 Menu::SpawnOption("Albany Manana", "MANANA");
	 Menu::SpawnOption("Pegassi Monroe", "MONROE");
	 Menu::SpawnOption("Vapid Peyote", "PEYOTE");
	 Menu::SpawnOption("Lampadati Pigalle", "PIGALLE");
	 Menu::SpawnOption("Benefactor Stirling GT", "STINGER");
	 Menu::SpawnOption("Lampaditi Viseris", "viseris");
	 Menu::SpawnOption("Karin 190z", "z190");
	 Menu::SpawnOption("Stinger GT", "STINGERGT");
	 Menu::SpawnOption("Declasse Tornado", "TORNADO");
	 Menu::SpawnOption("Albany Roosevelt", "revolter");
	 Menu::SpawnOption("Vapid Clique", "IMPALER");
	 Menu::SpawnOption("Vapid Apocalypse Imperator", "IMPALER2");
	 Menu::SpawnOption("Vapid Future Shock Imperator", "IMPALER3");
	 Menu::SpawnOption("Vapid Nightmare Imperator", "IMPALER4");
	 Menu::SpawnOption("Declasse Tornado(Convertable)", "TORNADO2");
	 Menu::SpawnOption("Declasse Tornado(Old)", "TORNADO3");
	 Menu::SpawnOption("Declasse Tornado(Mexican)", "TORNADO4");
	 Menu::SpawnOption("Declasse Tornado Custom", "TORNADO5");
	 Menu::SpawnOption("Declasse Tornado Rat-Rod", "TORNADO6");
	 Menu::SpawnOption("Schyster Deviant", "DEVIANT");
	 Menu::SpawnOption("Vapid Apocalypse Imperator", "IMPERATOR");
	 Menu::SpawnOption("Vapid Future Shock Imperator", "IMPERATOR2");
	 Menu::SpawnOption("Vapid Nightmare Imperator", "IMPERATOR3");
	 Menu::SpawnOption("Truffade Z-Type", "ZTYPE");
	 Menu::SpawnOption("Pegassi Infernus Classic", "INFERNUS2");
	 Menu::SpawnOption("Grotti Turismo Classic", "TURISMO2");
	 Menu::SpawnOption("Vapid Clique", "CLIQUE");
}
void SUVspinSpawner()//done
{
	Menu::Title("");
	Menu::Subtitle("SUV");
	 Menu::SpawnOption("Gallivanter Baller", "BALLER");
	 Menu::SpawnOption("Gallivanter Baller(Second Generation)", "BALLER2");
	 Menu::SpawnOption("Baller LE", "BALLER3");
	 Menu::SpawnOption("Baller LE(Armored)", "BALLER5");
	 Menu::SpawnOption("Baller LE LWB", "BALLER4");
	 Menu::SpawnOption("Pegassi Toros", "TOROS");
	 Menu::SpawnOption("Baller LE LWB(Armored)", "BALLER6");
	 Menu::SpawnOption("Karin BeeJay XL", "BJXL");
	 Menu::SpawnOption("Albany Cavalcade", "CAVALCADE");
	 Menu::SpawnOption("Albany Cavalcade(Second Generation)", "CAVALCADE2");
	 Menu::SpawnOption("Vapid Contender", "CONTENDER");
	 Menu::SpawnOption("Benefactor Dubsta", "DUBSTA");
	 Menu::SpawnOption("Benefactor Dubsta 6x6", "DUBSTA2");
	 Menu::SpawnOption("Benefactor Streiter", "streiter");
	 Menu::SpawnOption("Fathom FQ 2", "FQ2");
	 Menu::SpawnOption("Declasse Granger", "GRANGER");
	 Menu::SpawnOption("Bravado Gresley", "GRESLEY");
	 Menu::SpawnOption("Vapid Riata", "riata");
	 Menu::SpawnOption("Emperor Habanero", "HABANERO");
	 Menu::SpawnOption("Huntley S", "HUNTLEY");
	 Menu::SpawnOption("Landstalker", "LANDSTALKER");
	 Menu::SpawnOption("Mesa", "MESA");
	 Menu::SpawnOption("Mesa Grande(Merryweather)", "MESA2");
	 Menu::SpawnOption("Patriot", "PATRIOT");
	 Menu::SpawnOption("Vapid Radius", "RADI");
	 Menu::SpawnOption("Obey Rocoto", "ROCOTO");
	 Menu::SpawnOption("Canis Seminole", "SEMINOLE");
	 Menu::SpawnOption("Benefactor Serrano", "SERRANO");
	 Menu::SpawnOption("Benefactor XLS", "XLS");
	 Menu::SpawnOption("Benefactor XLS(Armored)", "XLS2");
}
void TrailerspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Trailers");
	 Menu::SpawnOption("Army Trailer(Tanker)", "ARMYTANKER");
	 Menu::SpawnOption("Army Trailer", "ARMYTRAILER");
	 Menu::SpawnOption("Benefactor Terrorbyte", "terbyte");
	 Menu::SpawnOption("MTL Pounder", "pounder2");
	 Menu::SpawnOption("Civilian Army Trailer", "ARMYTRAILER2");
	 Menu::SpawnOption("Bale Trailer", "BALETRAILER");
	 Menu::SpawnOption("Boat Trailer", "BOATTRAILER");
	 Menu::SpawnOption("Dock Trailer", "DOCKTRAILER");
	 Menu::SpawnOption("Freight Trailer", "FREIGHTTRAILER");
	 Menu::SpawnOption("Grain Trailer", "GRAINTRAILER");
	 Menu::SpawnOption("Prop Trailer", "PROPTRAILER");
	 Menu::SpawnOption("Rake Trailer", "RAKETRAILER");
	 Menu::SpawnOption("Tanker", "TANKER");
	 Menu::SpawnOption("Tanker 2", "TANKER2");
	 Menu::SpawnOption("Car Carrier Trailer", "TR2");
	 Menu::SpawnOption("yacht Trailer", "TR3");
	 Menu::SpawnOption("Car Carrier Trailer(With Cars)", "TR4");
	 Menu::SpawnOption("Vapid Festival Bus", "pbus2");
	 Menu::SpawnOption("Maibatsu Mule", "mule4");
	 Menu::SpawnOption("Trailer(Logs)", "TRAILERLOGS");
	 Menu::SpawnOption("Trailer", "TRAILERS");
	 Menu::SpawnOption("Trailer 2", "TRAILERS2");
	 Menu::SpawnOption("Trailer 3", "TRAILERS3");
	 Menu::SpawnOption("Trailer(small)", "TRAILERSMALL");
	 Menu::SpawnOption("Flat bed", "TRFLAT");
	 Menu::SpawnOption("TV Trailer", "TVTRAILER");
}
void TranspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Trans");
	 Menu::SpawnOption("Cable Car", "CABLECAR");
	 Menu::SpawnOption("Freight", "FREIGHT");
	 Menu::SpawnOption("Freight Car", "FREIGHTCAR");
	 Menu::SpawnOption("Freight Count 1", "FREIGHTCONT1");
	 Menu::SpawnOption("Freight Count 2", "FREIGHTCONT2");
	 Menu::SpawnOption("Freight Grain", "FREIGHTGRAIN");
	 Menu::SpawnOption("Metro Train", "METROTRAIN");
	 Menu::SpawnOption("Tank Car", "TANKERCAR");
}
void UtilityspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Utility");
	 Menu::SpawnOption("HVY Airtug", "AIRTUG");
	 Menu::SpawnOption("Caddy", "CADDY");
	 Menu::SpawnOption("Caddy 2", "CADDY2");
	 Menu::SpawnOption("HVY Docktug", "DOCKTUG");
	 Menu::SpawnOption("Fork Lift", "FORKLIFT");
	 Menu::SpawnOption("Mower", "MOWER");
	 Menu::SpawnOption("HVY Ripley", "RIPLEY");
	 Menu::SpawnOption("Sadler", "SADLER");
	 Menu::SpawnOption("Sadler(Snow)", "SADLER2");
	 Menu::SpawnOption("Vapid Scrap", "SCRAP");
	 Menu::SpawnOption("Tow Truck", "TOWTRUCK");
	 Menu::SpawnOption("Vapid Towtruck", "TOWTRUCK2");
	 Menu::SpawnOption("Canis Kamacho", "kamacho");
	 Menu::SpawnOption("Tractor(Rusty)", "TRACTOR");
	 Menu::SpawnOption("Tractor", "TRACTOR2");
	 Menu::SpawnOption("Tractor(Snow)", "TRACTOR3");
	 Menu::SpawnOption("Yosemite", "yosemite");
	 Menu::SpawnOption("Cherry Picker", "UTILLITRUCK");
	 Menu::SpawnOption("Flatbed Utility Truck", "UTILLITRUCK2");
	 Menu::SpawnOption("Utility Truck(Pick-Up)", "UTILLITRUCK3");
	 Menu::SpawnOption("Bravado Bison", "BISON");
	 Menu::SpawnOption("Bison(McGill-Olsen)", "BISON2");
	 Menu::SpawnOption("Bison(Mighty Bush)", "BISON3");
	 Menu::SpawnOption("Vapid Bobcat XL", "BOBCATXL");
	 Menu::SpawnOption("BoxVille(LSDWP)", "BOXVILLE");
	 Menu::SpawnOption("BoxVille(GoPostal)", "BOXVILLE2");
	 Menu::SpawnOption("BoxVille(The Humane Labs)", "BOXVILLE3");
	 Menu::SpawnOption("BoxVille(Post OP)", "BOXVILLE4");
	 Menu::SpawnOption("Burrito(LSWP)", "BURRITO");
	 Menu::SpawnOption("Burrito(Bugstars)", "BURRITO2");
	 Menu::SpawnOption("Burrito(Second Generation)", "BURRITO3");
	 Menu::SpawnOption("Burrito", "BURRITO4");
	 Menu::SpawnOption("Burrito(Snow)", "BURRITO5");
	 Menu::SpawnOption("Burrito(Lost MC Gang)", "GBURRITO");
	 Menu::SpawnOption("Burrito(standard Gang)", "GBURRITO2");
	 Menu::SpawnOption("Camper Van", "CAMPER");
	 Menu::SpawnOption("Vapid Speedo Custom", "speedo");
	 Menu::SpawnOption("Journey", "JOURNEY");
	 Menu::SpawnOption("Vapid Minivan", "MINIVAN");
	 Menu::SpawnOption("Vapid Minivan Custom", "MINIVAN2");
	 Menu::SpawnOption("Bravado Paradise", "PARADISE");
	 Menu::SpawnOption("Pony", "PONY");
	 Menu::SpawnOption("Pony 2", "PONY2");
	 Menu::SpawnOption("Bravado Rumpo", "RUMPO");
	 Menu::SpawnOption("Bravado Rumpo 2", "RUMPO2");
	 Menu::SpawnOption("Bravado Rumpo Custom", "RUMPO3");
	 Menu::SpawnOption("Vapid Speedo Custom", "SPEEDO");
	 Menu::SpawnOption("Vapid Clown Van", "SPEEDO2");
	 Menu::SpawnOption("BF Surfer", "SURFER");
	 Menu::SpawnOption("BF Surfer(Rusty)", "SURFER2");
	 Menu::SpawnOption("Brute Taco Van", "TACO");
	 Menu::SpawnOption("Bravado Youga", "YOUGA");
	 Menu::SpawnOption("Bravado Youga Classic", "YOUGA2");

}
void BoatspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Boats");
	 Menu::SpawnOption("Nagasaki Dinghy(4-seater)", "DINGHY");
	 Menu::SpawnOption("Nagasaki Dinghy(2-seater)", "DINGHY2");
	 Menu::SpawnOption("Nagasaki Dinghy(Heists)", "DINGHY3");
	 Menu::SpawnOption("Nagasaki Dinghy(Yacht)", "DINGHY4");
	 Menu::SpawnOption("Shitzu Jetmax", "JETMAX");
	 Menu::SpawnOption("Dinka Marquis", "MARQUIS");
	 Menu::SpawnOption("Police Predator", "PREDATOR");
	 Menu::SpawnOption("Speedophile Seashark", "SEASHARK");
	 Menu::SpawnOption("Speedophile Seashark(Lifeguard)", "SEASHARK2");
	 Menu::SpawnOption("Speedophile Seashark(Yacht)", "SEASHARK3");
	 Menu::SpawnOption("Pegassi Speeder", "SPEEDER");
	 Menu::SpawnOption("Pegassi Speeder(Yacht)", "SPEEDER2");
	 Menu::SpawnOption("Shitzu Squalo", "SQUALO");
	 Menu::SpawnOption("Submersibles", "SUBMERSIBLE");
	 Menu::SpawnOption("Kraken", "SUBMERSIBLE2");
	 Menu::SpawnOption("Suntrap", "SUNTRAP");
	 Menu::SpawnOption("Lampadati Toro", "TORO");
	 Menu::SpawnOption("Lampadati Toro(Yacht)", "TORO2");
	 Menu::SpawnOption("Shitzu Tropic", "TROPIC");
	 Menu::SpawnOption("Shitzu Tropic(Yacht)", "TROPIC2");
	 Menu::SpawnOption("Tug", "TUG");
	// Menu::SpawnOption("BOO", "BOOO");
}

void CommercialspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Commercial");
	 Menu::SpawnOption("Benson", "BENSON");
	 Menu::SpawnOption("HVY Biff", "BIFF");
	 Menu::SpawnOption("Jobuilt Hauler", "HAULER");
	 Menu::SpawnOption("Mule", "MULE");
	 Menu::SpawnOption("Mule 2", "bbb");
	 Menu::SpawnOption("MULE2", "bbb");
	 Menu::SpawnOption("Mule Custom", "bbb");
	 Menu::SpawnOption("MULE3", "bbb");
	 Menu::SpawnOption("Packer", "PACKER");
	 Menu::SpawnOption("Jobuilt Phantom", "PHANTOM");
	 Menu::SpawnOption("MTL Pounder", "POUNDER");
	 Menu::SpawnOption("Stockade", "STOCKADE");
	 Menu::SpawnOption("Stockade(Snow)", "STOCKADE3");


}
void CompactsspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Compact");
	 Menu::SpawnOption("RC Bandito", "RCBANDITO");
	 Menu::SpawnOption("Blista", "BLISTA");
	 Menu::SpawnOption("Grotti Brioso", "BRIOSO");
	 Menu::SpawnOption("Apocalypse Slamvan", "SLAMVAN4");
	 Menu::SpawnOption("Nightmare Slamvan", "SLAMVAN5");
	 Menu::SpawnOption("Future Shock Slamvan", "SLAMVAN6");
	 Menu::SpawnOption("Apocalypse Issi", "issi3");
	 Menu::SpawnOption("Nightmare Issi", "issi4");
	 Menu::SpawnOption("Future Shock Issi", "issi5");
	 Menu::SpawnOption("Issi Sports", "ISSI6");
	 Menu::SpawnOption("Dilettante", "DILETTANTE");
	 Menu::SpawnOption("Merryweather Dilettante", "DILETTANTE2");
	 Menu::SpawnOption("Canis Freecrawler", "freecrawler");
	 Menu::SpawnOption("Issi Classic", "ISSI2");
	 Menu::SpawnOption("Panto", "PANTO");
	 Menu::SpawnOption("Bollokan Prairie", "PRAIRIE");
	 Menu::SpawnOption("Vapid GB200", "gb200");
	 Menu::SpawnOption("Michelli GT", "michelli");
	 Menu::SpawnOption("Declasse Rhapsody", "RHAPSODY");
	 Menu::SpawnOption("Übermacht Sentinel Classic", "sentinel3");
	 Menu::SpawnOption("Vapid Retinue", "retinue");

}
void CoupesspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Coupe");
	 Menu::SpawnOption("Enus Cognoscenti Cabrio", "COGCABRIO");
	 Menu::SpawnOption("Dewbauchee Exemplar", "EXEMPLAR");
	 Menu::SpawnOption("Ocelot F620", "F620");
	 Menu::SpawnOption("Lampadati Felon", "FELON");
	 Menu::SpawnOption("Lampadati Felon GT", "FELON2");
	 Menu::SpawnOption("Ocelot Jackal", "JACKAL");
	 Menu::SpawnOption("Ubermacht Oracle", "ORACLE");
	 Menu::SpawnOption("Ubermacht Oracle XS", "ORACLE2");
	 Menu::SpawnOption("Ubermacht Sentinel", "SENTINEL");
	 Menu::SpawnOption("Ubermacht Sentinel XS", "SENTINEL2");
	 Menu::SpawnOption("Enus Windsor", "WINDSOR");
	 Menu::SpawnOption("Enus Windsor Drop", "WINDSOR2");
	 Menu::SpawnOption("Annis Savestra", "savestra");
	 Menu::SpawnOption("Ubermacht Zion", "ZION");
	 Menu::SpawnOption("Ubermacht Zion Cabrio", "ZION2");
}
void CyclesspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Cycles");
	 Menu::SpawnOption("BMX", "BMX");
	 Menu::SpawnOption("Cruiser", "CRUISER");
	 Menu::SpawnOption("Scorcher", "SCORCHER");
	 Menu::SpawnOption("Fixter", "FIXTER");
	 Menu::SpawnOption("Whippet Race Bike", "TRIBIKE3");
	 Menu::SpawnOption("Tri-Cycles Race Bike", "TRIBIKE");
	 Menu::SpawnOption("Endurex Race Bike", "TRIBIKE2");
}
void EmergencyspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Emergency");
	 Menu::SpawnOption("Ambulance", "AMBULANCE");
	 Menu::SpawnOption("FBI Car", "FBI");
	 Menu::SpawnOption("FBI Rancher", "FBI2");
	 Menu::SpawnOption("FireTruck", "FIRETRUK");
	 Menu::SpawnOption("Declasse Lifeguard", "LGUARD");
	 Menu::SpawnOption("Police Bus", "PBUS");
	 Menu::SpawnOption("Declasse Park Ranger", "PRANGER");
	 Menu::SpawnOption("Police Car", "POLICE");
	 Menu::SpawnOption("Buffalo Police Car", "POLICE2");
	 Menu::SpawnOption("Vapid Police Car", "POLICE3");
	 Menu::SpawnOption("Stockade(Snow)", "POLICE4");
	 Menu::SpawnOption("Western Motorcycle Company Police Bike", "POLICEB");
	 Menu::SpawnOption("Declasse Police Rancher(Snow)", "POLICEOLD1");
	 Menu::SpawnOption("Albany Police Roadcruiser(Snow)", "POLICEOLD2");
	 Menu::SpawnOption("Declasse Police Transporter", "POLICET");
	 Menu::SpawnOption("Vapid Sheriff Cruiser", "SHERIFF");
	 Menu::SpawnOption("Declasse Sheriff SUV", "SHERIFF2");
	 Menu::SpawnOption("Brute Police Riot", "RIOT");
	 Menu::SpawnOption("RCV", "RIOT2");
}
void HelicoptersspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Helicopters");
	 Menu::SpawnOption("Akula", "akula");
	 Menu::SpawnOption("Annihilator", "ANNIHILATOR");
	 Menu::SpawnOption("Atomic Blimp", "BLIMP");
	 Menu::SpawnOption("Xero Blimp", "BLIMP2");
	 Menu::SpawnOption("Black Blimp", "BLIMP3");
	 Menu::SpawnOption("Buzzard Attack Chopper", "BUZZARD");
	 Menu::SpawnOption("Buzzard(No Guns)", "BUZZARD2");
	 Menu::SpawnOption("Cargobob", "CARGOBOB");
	 Menu::SpawnOption("Cargobob 893(black)", "CARGOBOB2");
	 Menu::SpawnOption("Cargobob(TP Enterprises)", "CARGOBOB3");
	 Menu::SpawnOption("Cargobob(Black)", "CARGOBOB4");
	 Menu::SpawnOption("Frogger", "FROGGER");
	 Menu::SpawnOption("Frogger(TP Enterprises)", "FROGGER2");
	 Menu::SpawnOption("Maverick", "MAVERICK");
	 Menu::SpawnOption("Nagasaki Havok", "havok");
	 Menu::SpawnOption("FH-1 Hunter", "hunter");
	 Menu::SpawnOption("Police Maverick", "POLMAV");
	 Menu::SpawnOption("Savage", "SAVAGE");
	 Menu::SpawnOption("Skylift", "SKYLIFT");
	 Menu::SpawnOption("Buckingham SuperVolito", "SUPERVOLITO");
	 Menu::SpawnOption("Buckingham SuperVolito Carbon", "SUPERVOLITO2");
	 Menu::SpawnOption("Buckingham Swift", "SWIFT");
	 Menu::SpawnOption("Buckingham Swift Deluxe", "SWIFT2");
	 Menu::SpawnOption("Sea Sparrow", "seasparrow");
	 Menu::SpawnOption("Valkyrie", "VALKYRIE");
	 Menu::SpawnOption("Valkyrie MOD.O", "VALKYRIE2");
	 Menu::SpawnOption("Buckingham Volatus", "VOLATUS");

}
void IndustrialspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Industrial");
	 Menu::SpawnOption("HVY Dozer", "BULLDOZER");
	 Menu::SpawnOption("HVY Cutter", "CUTTER");
	 Menu::SpawnOption("HVY Dump", "DUMP");
	 Menu::SpawnOption("HVY Mixer", "MIXER");
	 Menu::SpawnOption("HVY Mixer(dirty)", "MIXER2");
	 Menu::SpawnOption("MTL Flatbed", "FLATBED");
	 Menu::SpawnOption("Vapid Guardian", "GUARDIAN");
	 Menu::SpawnOption("Dock Handler", "HANDLER");
	 Menu::SpawnOption("JoBuilt Rubble", "RUBBLE");
	 Menu::SpawnOption("Brute Tipper(Full)", "TIPTRUCK");
	 Menu::SpawnOption("Brute Tipper(Empty)", "TIPTRUCK2");
	 Menu::SpawnOption("MTL Apocalypse Cerberus", "CERBERUS");
	 Menu::SpawnOption("MTL Future Shock Cerberus", "CERBERUS2");
	 Menu::SpawnOption("MTL Nightmare Cerberus", "CERBERUS3");

}
void MilitaryspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Military");
	 Menu::SpawnOption("Barracks(Black)", "BARRACKS");
	 Menu::SpawnOption("HVY Barracks Semi", "BARRACKS2");
	 Menu::SpawnOption("Barracks(Dirty)", "BARRACKS3");
	 Menu::SpawnOption("Vapid Caracara", "caracara");
	 Menu::SpawnOption("Barrage", "barrage");
	 Menu::SpawnOption("Pegassi Oppressor Mk.II", "oppressor2");
	 Menu::SpawnOption("Pegassi Oppressor", "oppressor");
	 Menu::SpawnOption("Mamouth Thruster", "thruster");
	 Menu::SpawnOption("Canis Crusader", "CRUSADER");
	 Menu::SpawnOption("Rhino Tank", "RHINO");
	 Menu::SpawnOption("HVY Menacer", "menacer");
	 Menu::SpawnOption("TM-02 Khanjali", "khanjali");
	 Menu::SpawnOption("HVY Apocalypse Scarab", "SCARAB");
	 Menu::SpawnOption("HVY Future Shock Scarab", "SCARAB2");
	 Menu::SpawnOption("HVY Nightmare Scarab", "SCARAB3");
	 Menu::SpawnOption("RCV", "RIOT2");



}
void MotorcyclespinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Motorcycles");
	 Menu::SpawnOption("Dinka Akuma", "AKUMA");
	 Menu::SpawnOption("LCC Avarus", "AVARUS");
	 Menu::SpawnOption("Western Bagger", "BAGGER");
	 Menu::SpawnOption("Pegassi Bati 801", "BATI");
	 Menu::SpawnOption("Pegassi Bati 801RR", "BATI2");
	 Menu::SpawnOption("Western Apocalypse Deathbike", "DEATHBIKE");
	 Menu::SpawnOption("Western Future Shock Deathbike", "DEATHBIKE2");
	 Menu::SpawnOption("Western Nightmare Deathbike", "DEATHBIKE3");
	 Menu::SpawnOption("Nagasaki BF400", "BF400");
	 Menu::SpawnOption("Nagasaki Carbon RS", "CARBONRS");
	 Menu::SpawnOption("Nagasaki Chimera", "CHIMERA");
	 Menu::SpawnOption("Western Cliffhanger", "DAEMON");
	 Menu::SpawnOption("Western Daemon", "DAEMON2");
	 Menu::SpawnOption("Western Daemon(Alternate)", "DEFILER");
	 Menu::SpawnOption("Dinka Double-T", "DOUBLE");
	 Menu::SpawnOption("Dinka Enduro", "ENDURO");
	 Menu::SpawnOption("Pegassi Esskey", "ESSKEY");
	 Menu::SpawnOption("Pegassi Faggio Sport", "FAGGIO");
	 Menu::SpawnOption("Pegassi Faggio", "FAGGIO2");
	 Menu::SpawnOption("Pegassi Faggio Mod", "FAGGIO3");
	 Menu::SpawnOption("Western Gargoyle", "GARGOYLE");
	 Menu::SpawnOption("Shitzu Hakuchou", "HAKUCHOU");
	 Menu::SpawnOption("Shitzu Hakuchou Drag", "HAKUCHOU2");
	 Menu::SpawnOption("LCC Hexer", "HEXER");
	 Menu::SpawnOption("LCC Innovation", "INNOVATION");
	 Menu::SpawnOption("Principe Lectro", "LECTRO");
	 Menu::SpawnOption("Maibatsu Manchez", "MANCHEZ");
	 Menu::SpawnOption("Principe Nemesis", "NEMESIS");
	 Menu::SpawnOption("Western Nightblade", "NIGHTBLADE");
	 Menu::SpawnOption("Shitzu PCJ 600", "PCJ");
	 Menu::SpawnOption("Western Rat Bike", "RATBIKE");
	 Menu::SpawnOption("Maibatsu Sanchez(Livery)", "SANCHEZ");
	 Menu::SpawnOption("Maibatsu Sanchez", "SANCHEZ2");
	 Menu::SpawnOption("LCC Sanctus", "SANCTUS");
	 Menu::SpawnOption("Nagasaki Shotaro", "SHOTARO");
	 Menu::SpawnOption("Western Sovereign", "SOVEREIGN");
	 Menu::SpawnOption("Dinka Thrust", "THRUST");
	 Menu::SpawnOption("Shitzu Vader", "VADER");
	 Menu::SpawnOption("Dinka Vindicator", "VINDICATOR");
	 Menu::SpawnOption("Pegassi Vortex", "VORTEX");
	 Menu::SpawnOption("Western Wolfsbane", "WOLFSBANE");
	 Menu::SpawnOption("Western Zombie Bobber", "ZOMBIEA");
	 Menu::SpawnOption("Western Zombie Chopper", "ZOMBIEB");
	 Menu::SpawnOption("Principe Diablous", "DIABLOUS");
	 Menu::SpawnOption("Principe Diablous Custom", "DIABLOUS2");
	 Menu::SpawnOption("Pegassi FCR 1000", "FCR");
	 Menu::SpawnOption("Pegassi FCR 1000 Custom", "FCR2");
}
void MusclespinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Muscle");
	 Menu::SpawnOption("Vapid Blade", "BLADE");
	 Menu::SpawnOption("Albany Buccaneer", "BUCCANEER");
	 Menu::SpawnOption("Albany Buccaneer Custom", "BUCCANEER2");
	 Menu::SpawnOption("Vapid Chino", "CHINO");
	 Menu::SpawnOption("Vapid Chino Custom", "CHINO2");
	 Menu::SpawnOption("Vapid Apocalypse Dominator", "DOMINATOR4");
	 Menu::SpawnOption("Vapid Future Shock Dominator", "DOMINATOR5");
	 Menu::SpawnOption("Vapid Nightmare Dominator", "DOMINATOR6");
	 Menu::SpawnOption("Invetro Coquette Blackfin", "COQUETTE3");
	 Menu::SpawnOption("Vapid Dominator", "DOMINATOR");
	 Menu::SpawnOption("Vapid Pisswasser Dominator", "DOMINATOR2");
	 Menu::SpawnOption("Imponte Dukes", "DUKES");
	 Menu::SpawnOption("Imponte Duke O'Death", "DUKES2");
	 Menu::SpawnOption("Bravado Gauntlet", "GAUNTLET");
	 Menu::SpawnOption("Bravado Redwood Gauntlet", "GAUNTLET2");
	 Menu::SpawnOption("Willard Faction", "FACTION");
	 Menu::SpawnOption("Willard Faction Custom", "FACTION2");
	 Menu::SpawnOption("Willard Faction Custom Donk", "FACTION3");
	 Menu::SpawnOption("Vapid Hotknife", "HOTKNIFE");
	 Menu::SpawnOption("Albany Lurcher", "LURCHER");
	//add frnken
	 Menu::SpawnOption("Declasse Moonbeam", "MOONBEAM");
	 Menu::SpawnOption("Declasse Moonbeam Custom", "MOONBEAM2");
	 Menu::SpawnOption("Imponte Nightshade", "NIGHTSHADE");
	 Menu::SpawnOption("Imponte Phoenix", "PHOENIX");
	 Menu::SpawnOption("Cheval Picador", "PICADOR");
	 Menu::SpawnOption("Rat-Loader", "RATLOADER");
	 Menu::SpawnOption("Dewbauchee Raid GT Classic", "rapidgt3");
	 Menu::SpawnOption("Bravado Rat Truck", "RATLOADER2");
	 Menu::SpawnOption("Imponte Ruiner", "RUINER");
	 Menu::SpawnOption("Imponte Ruiner 2000", "RUINER2");
	 Menu::SpawnOption("Imponte Ruiner(Wrecked)", "RUINER3");
	 Menu::SpawnOption("Declasse Sabre Turbo", "SABREGT");
	 Menu::SpawnOption("Declasse Sabre Turbo Custom", "SABREGT2");
	 Menu::SpawnOption("Vapid Slamvan", "SLAMVAN");
	 Menu::SpawnOption("Vapid Lost Slamvan", "SLAMVAN2");
	 Menu::SpawnOption("Vapid Slamvan Custom", "SLAMVAN3");
	 Menu::SpawnOption("Declasse Stallion", "STALION");
	 Menu::SpawnOption("Declasse Burger Shot Stallion", "STALION2");
	 Menu::SpawnOption("Declasse Tampa", "TAMPA");
	 Menu::SpawnOption("Declasse Vigero", "VIGERO");
	 Menu::SpawnOption("Albany Virgo", "VIRGO");
	 Menu::SpawnOption("Dundreary Virgo Classic Custom", "VIRGO2");
	 Menu::SpawnOption("Dundreary Virgo Classic", "VIRGO3");
	 Menu::SpawnOption("Declasse Voodoo Custom", "VOODOO");
	 Menu::SpawnOption("Declassse Voodoo", "VOODOO2");

}
void OffRoadspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("OffRoad");
	 Menu::SpawnOption("Benefactor Apocalypse Bruiser", "BRUISER");
	 Menu::SpawnOption("Benefator Future Shock Bruiser", "BRUISER2");
	 Menu::SpawnOption("Benefactor Nightmare Bruiser", "BRUISER3");
	 Menu::SpawnOption("Declasse Apocalypse Brutus", "BRUTUS");
	 Menu::SpawnOption("Declasse Future Shock Brutus", "BRUTUS2");
	 Menu::SpawnOption("Declasse Nightmare Brutus", "BRUTUS3");
	 Menu::SpawnOption("BF Injection", "BFINJECTION");
	 Menu::SpawnOption("BF Bifta", "BIFTA");
	 Menu::SpawnOption("Nagasaki Blazer", "BLAZER");
	 Menu::SpawnOption("Nagasaki Blazer Lifeguard", "BLAZER2");
	 Menu::SpawnOption("Nagasaki Hot Rod Blazer", "BLAZER3");
	 Menu::SpawnOption("Nagasaki Streeet Blazer", "BLAZER4");
	 Menu::SpawnOption("Canis Bodhi", "BODHI2");
	 Menu::SpawnOption("Coil Brawler", "BRAWLER");
	 Menu::SpawnOption("Bravado Duneloader", "DLOADER");
	 Menu::SpawnOption("Benefactor Dubsta 6x6", "DUBSTA3");
	 Menu::SpawnOption("BF Dune Buggy", "DUNE");
	 Menu::SpawnOption("Space Docker", "DUNE2");
	 Menu::SpawnOption("HVY Insurgent Pick-up", "INSURGENT");
	 Menu::SpawnOption("HVY Insurgent", "INSURGENT2");
	 Menu::SpawnOption("Canis Kalahari", "KALAHARI");
	 Menu::SpawnOption("Cheval Marshall", "MARSHALL");
	 Menu::SpawnOption("Canis Mesa", "MESA3");
	 Menu::SpawnOption("Vapid Liberator", "MONSTER");
	 Menu::SpawnOption("Bravado Apocalypse Sasquatch", "MONSTER3");
	 Menu::SpawnOption("Bravado Future Shock Sasquatch", "MONSTER4");
	 Menu::SpawnOption("Bravado Nightmare Sasquatch", "MONSTER5");
	 Menu::SpawnOption("Declasse Rancher XL", "RANCHERXL");
	 Menu::SpawnOption("Declasse Rancher XL(Snow)", "RANCHERXL2");
	 Menu::SpawnOption("Karin Rusty Rebel", "REBEL");
	 Menu::SpawnOption("Karin Rebel", "REBEL2");
	 Menu::SpawnOption("Vapid Sandking XL", "SANDKING");
	 Menu::SpawnOption("Vapid Sandking SWB", "SANDKING2");
	 Menu::SpawnOption("Karin Technical", "TECHNICAL");
	 Menu::SpawnOption("Vapid Trophy Truck", "TROPHYTRUCK");
	 Menu::SpawnOption("Desert Raid", "TROPHYTRUCK2");
	 Menu::SpawnOption("Karin Technical Aqua", "TECHNICAL2");
	 Menu::SpawnOption("Ramp Buggy(Spoiler)", "DUNE4");
	 Menu::SpawnOption("Ramp Buggy", "DUNE5");
	 Menu::SpawnOption("Nagasaki Blazer Aqua", "BLAZER5");



}
void PlanesspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Planes");
	 Menu::SpawnOption("Buckingham Alpha-Z1", "alphaz1");
	 Menu::SpawnOption("Mammoth Avenger", "avenger");
	 Menu::SpawnOption("Western Besra", "BESRA");
	 Menu::SpawnOption("RM-10 Bombushka", "bombushka");
	 Menu::SpawnOption("Cargoplane", "CARGOPLANE");
	 Menu::SpawnOption("Cuban 800", "CUBAN800");
	 Menu::SpawnOption("Mammoth Dodo", "DODO");
	 Menu::SpawnOption("Duster", "DUSTER");
	 Menu::SpawnOption("Mammoth Hydra", "HYDRA");
	 Menu::SpawnOption("Jet", "JET");
	 Menu::SpawnOption("P-996 Lazer", "LAZER");
	 Menu::SpawnOption("Buckingham Luxor", "LUXOR");
	 Menu::SpawnOption("Buckingham Luxor Deluxe", "LUXOR2");
	 Menu::SpawnOption("Western Seabreeze", "seabreeze");
	 Menu::SpawnOption("Mammoth Tula", "tula");
	 Menu::SpawnOption("Mammatus", "MAMMATUS");
	 Menu::SpawnOption("Buckingham Miljet", "MILJET");
	 Menu::SpawnOption("Buckingham Nimbus", "NIMBUS");
	 Menu::SpawnOption("Western Rogue", "rogue");
	 Menu::SpawnOption("LF-22 Starling", "starling");
	 Menu::SpawnOption("Buckingham Pyro", "Pyro");
	 Menu::SpawnOption("Mammoth Mogul", "mogul");
	 Menu::SpawnOption("Nagasaki Ultralight", "microlight");
	 Menu::SpawnOption("V-65 Molotok", "molotok");
	 Menu::SpawnOption("P-45 Nokota", "nokota");
	 Menu::SpawnOption("Buckingham Howard NX-25", "howard");
	 Menu::SpawnOption("Buckinghma Shamal", "SHAMAL");
	 Menu::SpawnOption("B-11 Strikeforce", "strikeforce");
	 Menu::SpawnOption("Mallard", "STUNT");
	 Menu::SpawnOption("Titan", "TITAN");
	 Menu::SpawnOption("Velum", "VELUM");
	 Menu::SpawnOption("Velum 5-seater", "VELUM2");
	 Menu::SpawnOption("Buckingham Vestra", "VESTRA");
	 Menu::SpawnOption("Volatol", "volatol");
	// Menu::SpawnOption("Perrrrr", "FCR2");


}
void SedansspinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Sedan");
	 Menu::SpawnOption("Declasse Asea", "ASEA");
	 Menu::SpawnOption("Declasse Asea(Snow)", "ASEA2");
	 Menu::SpawnOption("Karin Asterope", "ASTEROPE");
	 Menu::SpawnOption("Enus Cognoscenti 55", "COG55");
	 Menu::SpawnOption("Enus Cognoscenti 55(Armoured)", "COG552");
	 Menu::SpawnOption("Enus Cognoscenti", "COGNOSCENTI");
	 Menu::SpawnOption("Enus Cognoscenti(Armoured)", "COGNOSCENTI2");
	 Menu::SpawnOption("Albany Emperor", "EMPEROR");
	 Menu::SpawnOption("Albany Emperor(Dirty)", "EMPEROR2");
	 Menu::SpawnOption("Albany Emperor(Snow)", "EMPEROR3");
	 Menu::SpawnOption("Cheval Fugitive", "FUGITIVE");
	 Menu::SpawnOption("Benefactor Glendale", "GLENDALE");
	 Menu::SpawnOption("Vulcan Ingot", "INGOT");
	 Menu::SpawnOption("Karin Intruder", "INTRUDER");
	 Menu::SpawnOption("Benefactor Turreted Limo", "LIMO2");
	//add other limos
	 Menu::SpawnOption("Declasse Premier", "PREMIER");
	 Menu::SpawnOption("Albany Primo", "PRIMO");
	 Menu::SpawnOption("Albany Primo Custom", "PRIMO2");
	 Menu::SpawnOption("Dundreary Regina", "REGINA");
	 Menu::SpawnOption("Chariot Romero Hearse", "ROMERO");
	 Menu::SpawnOption("Benefactor Schafter", "SCHAFTER2");
	 Menu::SpawnOption("Benefactor Schafter V12(Armoured)", "SCHAFTER5");
	 Menu::SpawnOption("Benefactor Schafter LWB(Armoured)", "SCHAFTER6");
	 Menu::SpawnOption("Vapid Stanier", "STANIER");
	 Menu::SpawnOption("Zinconium Stratum", "STRATUM");
	 Menu::SpawnOption("Dundreary Stretch", "STRETCH");
	 Menu::SpawnOption("Enus Super Diamond", "SUPERD");
	 Menu::SpawnOption("Cheval Surge", "SURGE");
	 Menu::SpawnOption("Obey Tailgater", "TAILGATER");
	 Menu::SpawnOption("Vulcan Warrener", "WARRENER");
	 Menu::SpawnOption("Albany Washington", "WASHINGTON");


}
void ServicespinSpawner()
{
	Menu::Title("");
	Menu::Subtitle("Service");
	 Menu::SpawnOption("Airport Bus", "AIRBUS");
	 Menu::SpawnOption("MTL Brickade", "BRICKADE");
	 Menu::SpawnOption("Bus", "BUS");
	 Menu::SpawnOption("Dashound", "COACH");
	 Menu::SpawnOption("MTL Dune", "RALLYTRUCK");
	 Menu::SpawnOption("Rental Shuttle Bus", "RENTALBUS");
	 Menu::SpawnOption("Taxi", "TAXI");
	 Menu::SpawnOption("Mammoth Patriot Stretch", "patriot2");
	 Menu::SpawnOption("Tourbus", "TOURBUS");
	 Menu::SpawnOption("Trashmaster(Dirty)", "TRASH2");
	 Menu::SpawnOption("MTL Wastelander", "WASTELANDER");
}
//Sort By DLC Blow
//https://www.gtabase.com/grand-theft-auto-v/vehicles/#sort=attr.ct3.frontend_value&sortdir=desc&attr.ct4.value=heists&page=1
void BeachBum()
{
	Menu::Title("");
	Menu::Subtitle("BeachBum");
	 Menu::SpawnOption("Bravado Paradise", "PARADISE");
	 Menu::SpawnOption("Canis Kalahari", "KALAHARI");
	 Menu::SpawnOption("BF Bifta", "BIFTA");
	 Menu::SpawnOption("Pegassi Speeder", "SPEEDER");
}
void Business()
{
	Menu::Title("");
	Menu::Subtitle("Business");
	 Menu::SpawnOption("Alpha", "ALPHA");
	 Menu::SpawnOption("Grotti Turismo Classic", "TURISMO2");
	 Menu::SpawnOption("Dinka Jester", "JESTER");
	 Menu::SpawnOption("Buckingham Vestra", "VESTRA");

}
void HighLife()
{
	Menu::Title("");
	Menu::Subtitle("High Life");
	 Menu::SpawnOption("Huntley S", "HUNTLEY");
	 Menu::SpawnOption("Zentorno", "ZENTORNO");// add to super
	 Menu::SpawnOption("Dewbauchdee Massacro", "MASSACRO");
	 Menu::SpawnOption("Dinka Thrust", "THRUST");

}
void ImNotAHipster()
{
	Menu::Title("");
	Menu::Subtitle("Im Not A Hipster");
	 Menu::SpawnOption("Lampadati Pigalle", "PIGALLE");
	 Menu::SpawnOption("Vulcan Warrener", "WARRENER");
	 Menu::SpawnOption("Benefactor Glendale", "GLENDALE");
	 Menu::SpawnOption("Benefactor Dubsta 6x6", "DUBSTA3");
	 Menu::SpawnOption("Vapid Blade", "BLADE");
	 Menu::SpawnOption("Declasse Rhapsody", "RHAPSODY");
	 Menu::SpawnOption("Panto", "PANTO");


}
void FlightSchool()
{
	Menu::Title("");
	Menu::Subtitle("Flight School");
	 Menu::SpawnOption("Invetero Coquette Classic", "COQUETTE2");
	 Menu::SpawnOption("Buckingham Miljet", "MILJET");
	 Menu::SpawnOption("Western Besra", "BESRA");
	 Menu::SpawnOption("Buckingham Swift", "SWIFT");

}
void LastTeamStanding()
{
	Menu::Title("");
	Menu::Subtitle("Last Team Standing");
	 Menu::SpawnOption("Lampadeti Furore GT", "FUROREGT");
	 Menu::SpawnOption("Canis Kalahari", "KALAHARI");
	 Menu::SpawnOption("LCC Innovation", "INNOVATION");
	 Menu::SpawnOption("Shitzu Hakuchou", "HAKUCHOU");

}
void NextGenRelease()
{
	Menu::Title("");
	Menu::Subtitle("NextGenRelease");
	 Menu::SpawnOption("Bravado Sprunk Buffalo", "BUFFALO3");
	 Menu::SpawnOption("Dinka Go Go Money Blista", "BLISTA3");
	 Menu::SpawnOption("Dinka Blista Compact", "BLISTA2");
	 Menu::SpawnOption("Xero Blimp", "BLIMP2");
	 Menu::SpawnOption("Mammoth Dodo", "DODO");
	 Menu::SpawnOption("Cheval Marshall", "MARSHALL");
	 Menu::SpawnOption("Declasse Burger Shot Stallion", "STALION2");
	 Menu::SpawnOption("Declasse Stallion", "STALION");
	 Menu::SpawnOption("Bravado Redwood Gauntlet", "GAUNTLET2");
	 Menu::SpawnOption("Imponte Dukes", "DUKES");
	 Menu::SpawnOption("Imponte Duke O'Death", "DUKES2");
	 Menu::SpawnOption("Vapid Pisswasser Dominator", "DOMINATOR2");
	 Menu::SpawnOption("Kraken", "SUBMERSIBLE2");

}
void FestiveSuprise()
{
	Menu::Title("");
	Menu::Subtitle("Festive Suprise");
	 Menu::SpawnOption("Dewbauchdee Massacro (racecar)", "MASSACRO2");
	 Menu::SpawnOption("Dinka Jester(Racecar)", "JESTER2");
	 Menu::SpawnOption("Vapid Slamvan", "SLAMVAN");
	 Menu::SpawnOption("Bravado Rat Truck", "RATLOADER2");
}
void Heists()
{
	Menu::Title("");
	Menu::Subtitle("Heists");
	 Menu::SpawnOption("Maibatsu Mule", "mule4");
	 Menu::SpawnOption("HVY Insurgent Pick-up", "INSURGENT");
	 Menu::SpawnOption("Vapid Lost Slamvan", "SLAMVAN2");
	 Menu::SpawnOption("Burrito(standard Gang)", "GBURRITO2");
	 Menu::SpawnOption("Lampadati Casco", "CASCO");
	 Menu::SpawnOption("Karin Karuma(Armoured)", "KURUMA2");
	 Menu::SpawnOption("Karin Kuruma", "KURUMA");
	 Menu::SpawnOption("Velum 5-seater", "VELUM2");
	 Menu::SpawnOption("Mammoth Hydra", "HYDRA");
	 Menu::SpawnOption("Karin Technical", "TECHNICAL");
	 Menu::SpawnOption("HVY Insurgent", "INSURGENT2");
	 Menu::SpawnOption("Principe Lectro", "LECTRO");
	 Menu::SpawnOption("Dinka Enduro", "ENDURO");
	 Menu::SpawnOption("Vapid Guardian", "GUARDIAN");
	 Menu::SpawnOption("Valkyrie", "VALKYRIE");
	 Menu::SpawnOption("Valkyrie MOD.O", "VALKYRIE2");
	 Menu::SpawnOption("Savage", "SAVAGE");

}
void III_Gotten_Gains_part1()
{
	Menu::Title("");
	Menu::Subtitle("III Gotten Gains part 1");
	 Menu::SpawnOption("Osiris", "OSIRIS");
	 Menu::SpawnOption("Benefactor Stirling GT", "STINGER");
	 Menu::SpawnOption("Buckingham Luxor Deluxe", "LUXOR2");
	 Menu::SpawnOption("Albany Virgo", "VIRGO");
	 Menu::SpawnOption("Buckingham Swift Deluxe", "SWIFT2");
	 Menu::SpawnOption("Enus Windsor", "WINDSOR");
}
void III_Gotten_Gains_part2()
{
	Menu::Title("");
	Menu::Subtitle("III Gotten Gains part 2");
	 Menu::SpawnOption("T20", "T20");
	 Menu::SpawnOption("Coil Brawler", "BRAWLER");
	 Menu::SpawnOption("Invetro Coquette Blackfin", "COQUETTE3");
	 Menu::SpawnOption("Vapid Chino", "CHINO");
	 Menu::SpawnOption("Dinka Vindicator", "VINDICATOR");
	// Menu::SpawnOption("Pegassi Osiris", "OSIRIS"); check what else goes here


}
void halloween()
{
	Menu::Title("");
	Menu::Subtitle("Halloween");
	 Menu::SpawnOption("Albany Lurcher", "LURCHER");
	 Menu::SpawnOption("Albany Franken", "btype2");
}

void Excutives_and_other_Criminals()
{
	Menu::Title("");
	Menu::Subtitle("Excutives and other Criminals");
	 Menu::SpawnOption("Baller LE(Armored)", "BALLER5");
	 Menu::SpawnOption("Baller LE LWB", "BALLER4");
	 Menu::SpawnOption("Baller LE LWB(Armored)", "BALLER6");
	 Menu::SpawnOption("Baller LE", "BALLER3");
	 Menu::SpawnOption("Declasse Mamba", "MAMBA");
	 Menu::SpawnOption("Bravado Verlierer", "VERLIERER2");
	 Menu::SpawnOption("Benefactor Schafter V12", "SCHAFTER3");
	 Menu::SpawnOption("Benefactor Schafter LWB", "SCHAFTER4");
	 Menu::SpawnOption("Benefactor Turreted Limo", "LIMO2");
	 Menu::SpawnOption("Benefactor Schafter V12(Armoured)", "SCHAFTER5");
	 Menu::SpawnOption("Benefactor Schafter LWB(Armoured)", "SCHAFTER6");
	 Menu::SpawnOption("Enus Cognoscenti 55", "COG55");
	 Menu::SpawnOption("Enus Cognoscenti 55(Armoured)", "COG552");
	 Menu::SpawnOption("Enus Cognoscenti", "COGNOSCENTI");
	 Menu::SpawnOption("Enus Cognoscenti(Armoured)", "COGNOSCENTI2");
	 Menu::SpawnOption("Enus Cognoscenti Cabrio", "COGCABRIO");
	 Menu::SpawnOption("Imponte Nightshade", "NIGHTSHADE");
	 Menu::SpawnOption("Buckingham SuperVolito", "SUPERVOLITO");
	 Menu::SpawnOption("Buckingham SuperVolito Carbon", "SUPERVOLITO2");

}
void Valentine()
{
	Menu::Title("");
	Menu::Subtitle("Valentine");
	 Menu::SpawnOption("Albanny Roosevelt", "BTYPE");
	 Menu::SpawnOption("Albanny Roosevelt Valor", "BTYPE3");
}
void Bennys_update()
{
	Menu::Title("");
	Menu::Subtitle("Bennys");
	 Menu::SpawnOption("Banshee 900R", "BANSHEE2");
	 Menu::SpawnOption("Sultan rs", "SULTANRS");
	 Menu::SpawnOption("Declasse Sabre Turbo Custom", "SABREGT2");
	 Menu::SpawnOption("Vapid Slamvan Custom", "SLAMVAN3");
	 Menu::SpawnOption("Declasse Tornado Custom", "TORNADO5");// recheck hash
	 Menu::SpawnOption("Dundreary Virgo Classic Custom", "VIRGO2");
	 Menu::SpawnOption("Dundreary Virgo Classic", "VIRGO3");
	 Menu::SpawnOption("Willard Faction Custom", "FACTION2");
	 Menu::SpawnOption("Willard Faction Custom Donk", "FACTION3");
	 //add all bannys why not
}
void Finance_and_Felony()
{
	Menu::Title("");
	Menu::Subtitle("Finance and Felony");
	 Menu::SpawnOption("Dewbauchee Seven-70", "SEVEN70");
	 Menu::SpawnOption("Pfister 811", "PFISTER811");//add to super
	 Menu::SpawnOption("Grotti X80", "X80");//add to super
	 Menu::SpawnOption("Bravado Rumpo Custom", "RUMPO3");
	 Menu::SpawnOption("Benefactor XLS(Armored)", "XLS2");
	 Menu::SpawnOption("Benefactor XLS", "XLS");
	 Menu::SpawnOption("Pegassi Reaper", "REAPER");
	 Menu::SpawnOption("Vapid FMJ", "FMJ");
	 Menu::SpawnOption("Grotti Bestia GTS", "BESTIAGTS");
	 Menu::SpawnOption("MTL Brickade", "BRICKADE");
	 Menu::SpawnOption("Buckingham Nimbus", "NIMBUS");
	 Menu::SpawnOption("Buckingham Volatus", "VOLATUS");
	 Menu::SpawnOption("Enus Windsor Drop", "WINDSOR2");
	 Menu::SpawnOption("Tug", "TUG");

}
void dimhistcars()
{
	Menu::Title("");
	Menu::Subtitle("Diamond Casino");
	Menu::SpawnOption("ABSO", "ABSO");
	Menu::SpawnOption("EVERON", "EVERON");
	Menu::SpawnOption("FORMULA", "FORMULA");
	Menu::SpawnOption("FORMULA2", "FORMULA2");
	Menu::SpawnOption("FURIA", "FURIA");
	Menu::SpawnOption("IMORGON", "IMORGON");
	Menu::SpawnOption("JB7002", "JB7002");
	Menu::SpawnOption("KANJO", "KANJO");
	Menu::SpawnOption("KOMODA", "KOMODA");
	Menu::SpawnOption("MINITANK", "MINITANK");
	Menu::SpawnOption("OUTLAW", "OUTLAW");
	Menu::SpawnOption("REBLA", "REBLA");
	Menu::SpawnOption("RETINUE2", "RETINUE2");
	Menu::SpawnOption("STRYDER", "STRYDER");
	Menu::SpawnOption("SUGOI", "SUGOI");
	Menu::SpawnOption("SULTAN2", "SULTAN2");
	Menu::SpawnOption("VAGRANT", "VAGRANT");
	Menu::SpawnOption("VSTR", "VSTR");
	Menu::SpawnOption("YOSEMITE2", "YOSEMITE2");
	Menu::SpawnOption("ZHABA", "ZHABA");

}