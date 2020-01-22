#include"MAIN.h"
#pragma warning(disable : 4244 4305) // double <-> float conversions
void update()//update function/loop
{
	SelfFunction();
	gunsmenu();
	vehfunctions();
	LSCfunctions();
	world_misc_functions();
	check_player_model();
	update_status_text();
	teleygun();
	sickygun();
	spooner_function();
	readplayer();
	OnlineFuctions();
	update_plane();
}
void writrecoords()
{
	Menu::Title("");
	Menu::Subtitle("Add Coords");
	//write the file
	std::ofstream croodsfile("Avi's Trainer/croodslist.txt", std::fstream::app);
	Vector3 playerCoord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
	float WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
	Vector3 waypoint1 = UI::GET_BLIP_COORDS(WaypointHandle);
	float player_heading = ENTITY::GET_ENTITY_HEADING(WaypointHandle);
	std::string xMsg = std::to_string(waypoint1.x);
	std::string yMsg = std::to_string(waypoint1.y);
	std::string zMsg = std::to_string(waypoint1.z);
	std::string Heading = std::to_string(WaypointHandle);
	std::string pxMsg = std::to_string(playerCoord.x);
	std::string pyMsg = std::to_string(playerCoord.y);
	std::string pzMsg = std::to_string(playerCoord.z);

	if (croodsfile.is_open())
	{
		if (Menu::Option("Store player Croods "))
			croodsfile << "Vector3 playercoords = {" << pxMsg << "," << pyMsg << "," << pzMsg << "};" << '\n';
		if (Menu::Option("Store Waypoint Croods"))
			croodsfile << "Vector3 WaypointCroods = {" << xMsg << "," << yMsg << "," << zMsg << "};" << "Heading: " << Heading << '\n';
			
	}
	else
		notifyBottom("Unable to open file, Check if File is in GTA5 Folder(Avi's Trainer/croodslist.txt)");
}
bool open = true;
void main()
{
 while (true)
 {
		Menu::Checks::Controlls();
		update();
  switch (Menu::Settings::currentMenu) {
	case NOMENU: { if (open)notifyBottom("~bold~Insert or ~bold~RB ~bold~+ ~bold~A to open menu");  } break;
	case mainmenu:
	{

		Menu::Title("");
		Menu::Subtitle("~r~Made ~w~in ~r~Canada V1.0.3");
		Menu::MenuOption("Self", Self_);
		Menu::MenuOption("Player Model", Modelmenu);
		Menu::MenuOption("Player Black List", Blocksforplayer);
		Menu::MenuOption("Character Appearance", clothingmenu);
		Menu::MenuOption("Map Mods", mapmods);// Map Mods for Now see if u can think of map options
		Menu::MenuOption("Object Spooner", spoonermenu);
		Menu::MenuOption("Location Options", TPMenu);
		Menu::MenuOption("Online Options", Onlineselecc);
		Menu::MenuOption("Vehicle Options", VehicleStuff);
		Menu::MenuOption("Weapon Options", Weaponsub);
		Menu::MenuOption("World/Misc Options", Menufunctions);
		Menu::MenuOption("Settings", settingss);
		//Menu::MenuOption("Dev Stuff(Beta)", dev);
		//Menu::tick("tick test");
		//Menu::info("ooo info");
		open = false;
		Menu::End();
	}
	break;
	case dev: { devwork();  Menu::End();  } break;
	case Blocksforplayer: {  writreplayer(); Menu::End(); } break;
	//blacklist
	case mapmods: {  MapMods(); Menu::End(); } break;
		//Self
	case Self_: {  Self(); Menu::End(); } break;
		//Teleports
	case TPMenu: { tpmenu(); Menu::End(); } break;
	case TPClothingStore: { TTPClothingStore(); Menu::End(); } break;
	case TPBarbers: { TTPBarbers(); Menu::End(); } break;
	case TPLSC: { TTPLSC(); Menu::End(); } break;
	case TPOVehicle: { TTPOVehicle(); Menu::End(); } break;
	case TPAmmunation: { TTPAmmunation(); Menu::End(); } break;
	case TPSports: { TTPSports(); Menu::End(); } break;
	case TPStores: { TTPStores(); Menu::End(); } break;
	case TPCinema: { TTPCinema(); Menu::End(); } break;
	case TPTattos: { TTPTattos(); Menu::End(); } break;
	case TPAir: { TTPAir(); Menu::End(); } break;
	case TPFun: { TTPFun(); Menu::End(); } break;
	case TPOther: { TTPOther(); Menu::End(); } break;
	case TPUnderwater: { underwater(); Menu::End(); } break;
	case TPATMs: { TTPATMs(); Menu::End(); } break;
	case TPBanks: { TTPBanks(); Menu::End(); } break;
	case TPServices: { TTPServices(); Menu::End(); } break;
	case TPAparts: { TTPApartss(); Menu::End(); } break;

	case landmarks: { landmark(); Menu::End(); } break;
	case highLocations: { HighLocations(); Menu::End(); } break;
	case Onlinerelated: { OnlineRelated(); Menu::End(); } break;
	case _Interiors: { Interiors(); Menu::End(); } break;

		//locations
	case IPL: { ipl(); Menu::End(); } break;
		//Vehicle
	case VehicleStuff: { vehicleStuff(); Menu::End(); } break;
	case AIDrving: { AI_Drving(); Menu::End(); } break;
	case cargobobcase: { carbob_options(); 	Menu::End(); } break;
	case guns_for_veh: { vehgunmenu(); 	Menu::End(); } break;
	case PV: { PV_(); 	Menu::End(); } break;
	case vehkey: { Veh_key(); 	Menu::End(); } break;
	case privatejet: { parvplane(); 	Menu::End(); } break;
		//veh spawner
		//by dlc
	case By_DLC_: { By_DLC(); Menu::End(); } break;
	case BeachBum_: { BeachBum(); Menu::End(); } break;
	case Business_: { Business(); Menu::End(); } break;
	case HighLife_: { HighLife(); Menu::End(); } break;
	case ImNotAHipster_: { ImNotAHipster(); Menu::End(); } break;
	case FlightSchool_: { FlightSchool(); Menu::End(); } break;
	case LastTeamStanding_: { LastTeamStanding(); Menu::End(); } break;
	case NextGenRelease_: { NextGenRelease(); Menu::End(); } break;
	case FestiveSuprise_: { FestiveSuprise(); Menu::End(); } break;
	case Heists_: { Heists(); Menu::End(); } break;
	case III_Gotten_Gains_part1_: { III_Gotten_Gains_part1(); Menu::End(); } break;
	case III_Gotten_Gains_part2_: { III_Gotten_Gains_part2(); Menu::End(); } break;
	case halloween_: { halloween(); Menu::End(); } break;
	case Valentine_: { Valentine(); Menu::End(); } break;
	case Excutives_and_other_Criminals_: { Excutives_and_other_Criminals(); Menu::End(); } break;
	case Bennys_update_: { Bennys_update(); Menu::End(); } break;
	case Finance_and_Felony_: { Finance_and_Felony(); Menu::End(); } break;
	case dlc148: { dlccars(); }  break;
	case dlc150: { dimhistcars(); }  break;
		//Normal
	case vehspawnersub: { spawner(); Menu::End(); } break;
	case Super: { Superr(); Menu::End(); } break;
	case Sports: { sportspinSpawner(); Menu::End(); } break;
	case SportClassic: { sportclassicsspinSpawner(); Menu::End(); } break;
	case Offroad: { OffRoadspinSpawner(); Menu::End(); } break;
	case Sedans: { SedansspinSpawner(); Menu::End(); } break;
	case Coupes: { CoupesspinSpawner(); Menu::End(); } break;
	case Muscle: { MusclespinSpawner(); Menu::End(); } break;
	case Boats: { BoatspinSpawner(); Menu::End(); } break;
	case Commercial: { CommercialspinSpawner(); Menu::End(); } break;
	case Compacts: { CompactsspinSpawner(); Menu::End(); } break;
	case Cycles: { CyclesspinSpawner(); Menu::End(); } break;
	case Emergency: { EmergencyspinSpawner(); Menu::End(); } break;
	case Helicopters: { HelicoptersspinSpawner(); Menu::End(); } break;
	case Industrial: { IndustrialspinSpawner(); Menu::End(); } break;
	case Military: { MilitaryspinSpawner(); Menu::End(); } break;
	case Planes: { PlanesspinSpawner(); Menu::End(); } break;
	case Service: { ServicespinSpawner(); Menu::End(); } break;
	case Motorcycles: { MotorcyclespinSpawner(); Menu::End(); } break;
	case SUV: { SUVspinSpawner(); Menu::End(); } break;
	case Trailer: { TrailerspinSpawner(); Menu::End(); } break;
	case Trains: { TranspinSpawner(); Menu::End(); } break;
	case Utility: { UtilityspinSpawner(); Menu::End(); } break;
		//Customs
	case LSCWW: { LSCWwW(); Menu::End(); } break;//menu
	case modlsc: { LSC_vehicle_Mods(); Menu::End(); } break;//LSC mods Men
	case fbumper: { fbumpear(); Menu::End(); } break;//LSC Mods
	case Bennysmodlsc: { Bennys_vehicle_Mods(); Menu::End(); } break;//Bennys Mod
	case windindowoptions: { Window_Options(); Menu::End(); } break;
	case torc: { tor(); Menu::End(); } break;
	case Armour: { Armours(); 	Menu::End(); } break;
	case ecase: { epower(); Menu::End(); } break;
	case Speaker: { Speaadker(); Menu::End(); Menu::End(); } break;
	case plate_Optionss: { plate_Options(); Menu::End(); } break;
	case Transmissionp: { TransmissionEMS(); Menu::End(); } break;
	case Suspensionp: { SuspensionEMS(); Menu::End(); } break;
	case Brakesp: { BrakesEMS(); Menu::End(); } break;
	case EMS: { engineEMS(); Menu::End(); } break;
	case performance: {  proformancce(); Menu::End(); } break;
	case pbright: { pbrdght(); Menu::End(); } break;
	case sbright: { sbrdight(); Menu::End(); } break;
	case Resprayss: { Respdrayss(); Menu::End(); } break;
	case ResprayssED: { RespdrayssED(); Menu::End(); } break;
	case Smoke: { Smomke(); Menu::End(); } break;
	case TRGB: { TRaGB(); Menu::End(); } break;
	case Primaryyy: { Primaaaryyy(); Menu::End(); } break;
	case Chrome: { Charome(); Menu::End(); } break;
	case ClassicMetallic: { ClassicMetaallic(); Menu::End(); } break;
	case Matte: { Mattae(); Menu::End(); } break;
	case Metals: { Meatals();   Menu::End(); } break;
	case Secondaryyy: { Secondaryysy(); Menu::End(); } break;
	case pearlescents: { pearlesscents(); Menu::End(); } break;
	case Chromes: { Cahromes(); } break;
	case ClassicMetallics: { ClassicMetallaics(); Menu::End(); } break;
	case Mattes: { Matteas(); Menu::End(); } break;
	case Metalss: { Metaalss(); Menu::End(); } break;
	case Wheels: { Wheelss(); Menu::End(); } break;
	case bennyscustomwheels: { bennyscustomrims(); Menu::End(); } break;
	case wheelclass: { WheelColour(); Menu::End(); } break;
	case BackWheels: { BackWheaels(); Menu::End(); } break;
	case frontwheels: { frontWheaels(); Menu::End(); } break;
	case Rims: { Rimns(); Menu::End(); } break;
	case Tunerrims: { Tunerrimss(); Menu::End(); } break;
	case SUVrims: { SUVrisms(); Menu::End(); } break;
	case Lowriderrims: { Lowrisderrims(); Menu::End(); } break;
	case Sportrims: { Sportrsims(); Menu::End(); } break;
	case Offroadrims: { Oaffroadrims(); Menu::End(); } break;
	case Musclerims: { auscalerims(); Menu::End(); } break;
	case Highendrims: { Hdghendrims(); Menu::End(); } break;
	case Light: { Lightttt(); Menu::End(); } break;
	case NEEE: { NEEaE(); Menu::End(); } break;
	case Neonnn: { Neonnan(); Menu::End(); } break;
	case plateeee: { plateeeae(); Menu::End(); } break;
	case inside: { insidea(); Menu::End(); } break;
	case O: { Oa(); Menu::End(); } break;
	case B: { Ba(); Menu::End(); } break;
	case Vanity: { Vaniaty(); Menu::End(); } break;
	case Trimd: { Triamd(); Menu::End(); } break;
	case Ornaments: { Ornamentas(); Menu::End(); } break;
	case Dashboard: { Dashboaard(); Menu::End(); } break;
	case Dials: { Diaals(); Menu::End(); } break;
	case Speakerr: { Speakferr(); } break;
	case Seats: { Seaatas(); Menu::End(); } break;
	case Steeringwheel: { Steeringwheael(); Menu::End(); } break;
	case Shifter: { Shiffter(); Menu::End(); } break;
	case Plaques: { Plaqaues(); Menu::End(); } break;
	case Trunk: { Trunak(); Menu::End(); } break;
	case Hydrulics: { Hydrulicas(); Menu::End(); } break;
	case Block: { Blocak(); Menu::End(); } break;
	case Fliters: { Flitersa(); Menu::End(); } break;
	case Struts: { Strutsa(); Menu::End(); } break;
	case Livrey: { Livreya(); Menu::End(); } break;
	case Aerials: {  Aerialsa(); Menu::End(); } break;
	case Tank: { Tanka(); Menu::End(); } break;
		//Weapons
	case Weaponsub: {  weaponsub();  Menu::End(); } break;
	case impactgunveh: { Main_Impact_Gun(); 	Menu::End(); } break;
	case bullet_menu: { Weapon_bullets_options_sets(); 	Menu::End(); } break;
	case ForceObjectGun: { Force_ObjectGun(); 	Menu::End(); } break;
		//Gun Menu
	case guns: { maingunmenu(); Menu::End(); } break;
	case II: { marktwoguns(); Menu::End(); } break;
	case HeavyGuns: { heavyguns(); Menu::End(); } break;
	case SniperRifles: { sniperrifles(); Menu::End(); } break;
	case Rifes: { rifes(); Menu::End(); } break;
	case Handguns: { handguns(); Menu::End(); } break;
	case Shotgun: { shotgun(); Menu::End(); } break;
	case MachineGuns: { machineguns(); Menu::End(); } break;
	case New_DLC_foursix: { new_DLC_foursix(); Menu::End(); } break;
	case tints: { Tints(); Menu::End(); } break;
		//thing shit
	case spacialg: { Cool_Guns(); Menu::End(); } break;
	case ThrownWeapons: { thorwable(); Menu::End(); } break;
	case Melee: { meleee(); Menu::End(); } break;
	case KnuckleDuster: { knuckleduster(); Menu::End(); } break;
	case SwitchBlade: { switchblade(); Menu::End(); } break;
		//1.47
	case RAYMINIGUN: { Raygun(); Menu::End(); } break;
	case RAYCARBINE: { RAYCarbine(); Menu::End(); } break;
	case RAYPISTOL: { RAYPistol(); Menu::End(); } break;
		//Marksman_Rifle_Mk_II
	case Marksman_Rifle_Mk_II: { MarksmanRifleMkII(); Menu::End(); } break;
	case Tints_m: { mk2tints(); Menu::End(); } break;
	case Camos_m: { camos_m(); Menu::End(); } break;
	case Muzzle_m: { muzzle_m(); Menu::End(); } break;
	case Barrel_m: { barrel_m(); Menu::End(); } break;
	case Attachment_m: { attachment_m(); Menu::End(); } break;
	case Scope_m: { scope_m(); Menu::End(); } break;
	case Magazine_m: { magazine_m(); Menu::End(); } break;
		//Pump_Shotgun_Mk_II
	case Pump_Shotgun_Mk_II: { pump_Shotgun_Mk_II(); Menu::End(); } break;
	case Muzzle_sg: { muzzle_sg(); Menu::End(); } break;
	case Tints_sg: { mk2tints(); Menu::End(); } break;
	case Camos_sg: { camos_sg(); Menu::End(); } break;
	case Attachment_sg: { attachment_sg(); Menu::End(); } break;
	case Scope_sg: { scope_sg(); Menu::End(); } break;
	case Magazine_sg: { magazine_sg(); Menu::End(); } break;
		//Bullpup_Rifle_Mk_II
	case Bullpup_Rifle_Mk_II: { bullpup_Rifle_Mk_II(); Menu::End(); } break;
	case Tints_b: { mk2tints(); Menu::End(); } break;
	case Camos_b: { camos_b(); Menu::End(); } break;
	case Muzzle_b: { muzzle_b(); Menu::End(); } break;
	case Barrel_b: { barrel_b(); Menu::End(); } break;
	case Attachment_b: { attachment_b(); Menu::End(); } break;
	case Scope_b: { scope_b(); Menu::End(); } break;
	case Magazine_b: { magazine_b(); Menu::End(); } break;
		//Special_Carbine_Mk_II
	case Special_Carbine_Mk_II: { special_Carbine_Mk_II(); Menu::End(); } break;
	case Tints_sc: { mk2tints(); Menu::End(); }  break;
	case Camos_sc: { camos_sc(); Menu::End(); } break;
	case Muzzle_sc: { muzzle_sc(); Menu::End(); } break;
	case Barrel_sc: { barrel_sc(); Menu::End(); } break;
	case Attachment_sc: { attachment_sc(); Menu::End(); } break;
	case Scope_sc: { scope_sc(); Menu::End(); } break;
	case Magazine_sc: { magazine_sc(); Menu::End(); } break;
	case Revolver_Mk_II: { revolver_Mk_II(); Menu::End(); } break;
	case Tints_r: { mk2tints(); Menu::End(); } break;
	case Camos_r: { camos_r(); Menu::End(); } break;
	case Attachment_r: { attachment_r(); Menu::End(); } break;
	case Magazine_r: { magazine_r(); Menu::End(); } break;
		//SNS Pistol MK II
	case SNS_Pistol_Mk_II: { sNS_Pistol_Mk_II(); Menu::End(); Menu::End(); } break;
	case Tints_sn: { mk2tints(); Menu::End(); } break;
	case Camos_sn: { camos_sn(); Menu::End(); } break;
	case Attachment_sn: { attachment_sn(); Menu::End(); } break;
	case Magazine_sn: { magazine_sn(); Menu::End(); } break;
		// Heavy Sniper MK II
	case Heavy_Sniper_Mk_II: { heavy_Sniper_Mk_II(); Menu::End(); } break;
	case Tints_hs: { mk2tints(); Menu::End(); } break;
	case Camos_hs: { camos_hs(); Menu::End(); } break;
	case Muzzle_hs: { muzzle_hs(); Menu::End(); } break;
	case Barrel_hs: { barrel_hs(); Menu::End(); } break;
	case Attachment_hs: { attachment_hs(); Menu::End(); } break;
	case Scope_hs: { scope_hs(); Menu::End(); } break;
	case Magazine_hs: { magazine_hs(); Menu::End(); } break;
		// Combat MG MK II
	case Combat_MG_Mk_II: { combat_MG_Mk_II(); Menu::End(); } break;
	case Tints_mg: { mk2tints(); Menu::End(); } break;
	case Camos_mg: { camos_mg(); Menu::End(); } break;
	case Muzzle_mg: { muzzle_mg(); Menu::End(); } break;
	case Barrel_mg: { barrel_mg(); Menu::End(); } break;
	case Attachment_mg: { attachment_mg(); Menu::End(); } break;
	case Scope_mg: { scope_mg(); Menu::End(); } break;
	case Magazine_mg: { magazine_mg(); Menu::End(); } break;
		//Carbine Rifle MK II
	case Carbine_Rifle_Mk_II: { carbine_Rifle_Mk_II(); Menu::End(); } break;
	case Tints_c: { mk2tints(); Menu::End(); } break;
	case Camos_c: { camos_c(); Menu::End(); } break;
	case Muzzle_c: { muzzle_c(); Menu::End(); } break;
	case Barrel_c: { barrel_c(); Menu::End(); } break;
	case Attachment_c: { attachment_c(); Menu::End(); } break;
	case Scope_c: { scope_c(); } break;
	case Magazine_c: { magazine_c(); Menu::End(); } break;
		// Assault Rifle MK II
	case Assault_Rifle_Mk_II: { assault_Rifle_Mk_II(); Menu::End(); } break;
	case Tints_a: { mk2tints(); Menu::End(); } break;
	case Camos_a: { camos_a(); Menu::End(); } break;
	case Muzzle_a: { muzzle_a(); Menu::End(); } break;
	case Barrel_a: { barrel_a(); Menu::End(); } break;
	case Attachment_a: { attachment_a(); Menu::End(); } break;
	case Scope_a: { scope_a(); } break;
	case Magazine_a: { magazine_a(); Menu::End(); } break;
		// SMG MK II
	case SMG_Mk_II: { sMG_Mk_II(); Menu::End(); } break;
	case Tints_s: { mk2tints(); Menu::End(); } break;
	case Camos_s: { camos_s(); Menu::End(); } break;
	case Muzzle_s: { muzzle_s(); Menu::End(); } break;
	case Barrel_s: { barrel_s(); Menu::End(); } break;
	case Attachment_s: { attachment_s(); Menu::End(); } break;
	case Scope_s: { scope_s(); Menu::End(); } break;
	case Magazine_s: { magazine_s(); Menu::End(); } break;
		//Pistol MK2
	case MK2_Pistol: { mK2_Pistol(); Menu::End(); } break;
	case Tints_P: { mk2tints(); Menu::End(); } break;
	case Camos_p: { camos_p(); Menu::End(); } break;
	case Attachment_p: { attachment_p(); Menu::End(); } break;
	case Magazine_p: { magazine_p(); Menu::End(); } break;
		// Pistols
	case cal: { call(); Menu::End(); } break;
	case sns: { snss(); Menu::End(); } break;
	case Pistol: { pistol(); Menu::End(); } break;
	case MarksmanPistol: { marksmanPistol(); Menu::End(); } break;
	case Revolver: { revolver(); Menu::End(); } break;
	case vintage: { Vintage(); Menu::End(); } break;
	case MACHINE: { mACHINE(); Menu::End(); } break;
	case app: { App(); Menu::End(); } break;
	case combat: { Combat(); Menu::End(); } break;
	case heavy: { HEavy(); Menu::End(); } break;
	case FlareGun: { flareGun(); Menu::End(); } break;
	case StunGun: { stunGun(); Menu::End(); } break;
		// ShotGun
	case Autoshotgun: { autoshotgun(); Menu::End(); } break;
	case SawnoffShotgun: { sawnoffShotgun(); Menu::End(); } break;
	case DoubleBarrelShotgun: { doubleBarrelShotgun(); Menu::End(); } break;
	case HeavyShotgun: { HeavyshOtgun(); Menu::End(); } break;
	case BullpupShotgun: { bullpupShotgun(); Menu::End(); } break;
	case AssaultShotgun: { assaultShotgun(); Menu::End(); } break;
	case pump: { PumP(); Menu::End(); } break;
	case Musket: { musket(); Menu::End(); } break;
		//Sub Gun
	case Gusenberg: { gusenberg(); Menu::End(); } break;
	case AssultSMG: { assultSMG(); Menu::End(); } break;
	case MicroSMG: { microSMG(); Menu::End(); } break;
	case smg: { ssmg(); Menu::End(); } break;
	case CombatPDW: { combatPDW();  Menu::End(); } break;
	case CombatMG: { combatMG(); Menu::End(); } break;
	case MG: { MGg(); Menu::End(); } break;
		//AR
	case BullpupRifle: { Bullpuprifle(); Menu::End(); } break;
	case SpecialCarbine: { Specialcarbine(); Menu::End(); } break;
	case AdvancedRifle: { Advancedrifle(); Menu::End(); } break;
	case CarbineRifle: { Carbinerifle(); Menu::End(); } break;
	case AssaultRifle: { assaultRifle(); Menu::End(); } break;
	case CompactRifle: { Compactrifle(); Menu::End(); } break;
		//sinper
	case MarksmanRifle: { Marksmanrifle(); Menu::End(); } break;
	case sp: { spp(); Menu::End(); } break;
	case HeavySniper: { Heavysniper();  Menu::End(); } break;
		//Heavy Guns
	case RPG: { RPGg(); Menu::End(); } break;
	case Minigun: { MinigunN(); Menu::End(); } break;
	case GrenadeLauncher: { GrenadeLauncherR(); Menu::End(); } break;
	case Firework: { FireworkK(); Menu::End(); } break;
	case HomingLauncher: { HomingLauncherr(); Menu::End(); } break;
	case GrenadeLauncherSmoke: { GrenadeLauncherSmokee(); Menu::End(); } break;
	case CompactLauncher: { CompactLauncherr(); Menu::End(); } break;
	case Railgun: { Railgunn(); Menu::End(); } break;
		//World
	case Menufunctions: { misc_world_Sub(); Menu::End(); } break;
	case worldvheoptions: { World_Vehicle_Options(); 	Menu::End(); } break;
	case worldspeedchnage: { Worldspeed(); 	Menu::End(); } break;
	case worldwether: { wether(); Menu::End(); } break;
	case Worldclouds: { world_cloud(); 	Menu::End(); } break;
	case worldgrav: { World_Gravity(); 	Menu::End(); } break;
	case worldTime: { world_time(); 	Menu::End(); } break;
	case WorldWind: { world_wind(); 	Menu::End(); } break;
	case Worldclear: { World_Clear(); 	Menu::End(); } break;
	case worldradios: { World_Stations(); 	Menu::End(); } break;
	case worldradio: { World_Radio(); 	Menu::End(); } break;
		//Settings
	case settingss: { setting(); Menu::End(); } break;
	case Font: { fonts(); Menu::End(); } break;
	case scroller: { settingsscroller(); Menu::End(); } break;
	case Line: { linesettings(); Menu::End(); } break;
	case text: { settingsoptiontext(); Menu::End(); } break;
	case themes: { menuthemes(); Menu::End(); } break;
		//sponner
	case _Selectedentity: { Selectedentity_(); Menu::End(); } break;
	case spoonermenu: { MainMenuSpooner(); Menu::End(); } break;
	case objectmenu: { Spawn_object(); Menu::End(); } break;
	case objectmanager: { ObjectManager(); Menu::End(); } break;
	case editrmenu: { edit_menu(); Menu::End(); } break;
	case attch: { attachenitiy(); Menu::End(); } break;
		//Player
	case clothingmenu: { colthing(); Menu::End(); } break;
	case Modelmenu: { ModelMenu(); Menu::End(); } break;
	case AModel: { AnimalModels(); Menu::End(); } break;
	case AmbientFemale_: { AmbientFemale(); Menu::End(); } break;
	case AmbientMale_: { AmbientMale(); Menu::End(); } break;
	case Cutscene_: { Cutscene(); Menu::End(); } break;
	case GangFemale_: { GangFemale(); Menu::End(); } break;
	case GangMale_: { GangMale(); Menu::End(); } break;
	case Story_: { Story(); Menu::End(); } break;
	case Multiplayer_: { Multiplayer(); Menu::End(); } break;
	case ScenarioFemale_: { ScenarioFemale(); Menu::End(); } break;
	case ScenarioMale_: { ScenarioMale(); Menu::End(); } break;
	case StoryScenarioFemale_: { StoryScenarioFemale(); Menu::End(); } break;
	case StoryScenarioMale_: { StoryScenarioMale(); Menu::End(); } break;
	case other_: { other(); Menu::End(); } break; 
		// Online
	case Onlineselecc: { playerlist(); Menu::End(); } break;
	case selectedplayeri: { selected(); Menu::End(); } break;

















			//case mapmods: { MapMods(); Menu::End(); } break;
			//case Makeupmenu: { makup();  Menu::End(); } break;
			//case plasticmenu: { Plastic_face_functions(); Menu::End(); } break;
			//case playermenu: {  mainplayermenu(); Menu::End(); } break;






#pragma endregion
		}
		WAIT(0);
	}
}

void ScriptMain()
{
	srand(GetTickCount());
	main();
}
