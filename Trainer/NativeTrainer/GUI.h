#pragma once
#pragma once
enum SubMenus { //Add Sub Menus in here
	NOMENU,
	NOMENU2,
	mainmenu,
	Self_,
	settings,
	exitgta,
	settingstheme,
	Credits,
	themeloader,
	font,
	plist,
	onlineselectedplayer,
	pmenu,
	dev,
	playermenu,
	clothingmenu,
	TP_Selected,
	Menufunctions,
	vvehtroll,
	Unlocks,
	spawnvheonplayer,
	tpplayerthing,
	VehicleStuff,
	weathersub,
	Onlineselecc,
	Weaponsub,
	Networksub,
	Recoverysub,
	vehspawnersub,
	Super,
	rFenders,
	Sports,
	SportClassic,
	Blocksforplayer,
	spacialg,
	Offroad,
	Sedans,
	Coupes,
	Muscle,
	Boats,
	Commercial,
	mapmods,
	Compacts,
	Cycles,
	Emergency,
	Helicopters,
	Industrial,
	Military,
	Motorcycles,
	Planes,
	Service,
	sSuper,
	sSports,
	sSportClassic,
	sOffroad,
	Transmissionp,
	modlsc,
	Bennysmodlsc,
	performance,
	Suspensionp,
	Brakesp,
	EMS,
	sSedans,
	sCoupes,
	sMuscle,
	sBoats,
	sCommercial,
	sCompacts,
	guns_for_veh,
	windindowoptions,
	worldvheoptions,
	worldspeedchnage,
	worldwether,
	Worldclouds,
	worldgrav,
	worldTime,
	WorldWind,
	cargobobcase,
	Worldclear,
	worldradio,
	worldradios,
	impactgunveh,
	sCycles,
	bullet_menu,
	sEmergency,
	sHelicopters,
	sIndustrial,
	sMilitary,
	sMotorcycles,
	sPlanes,
	sService,
	sSUV,
	sTrailer,
	sTrains,
	sUtility,
	clubchanger,
	SUV,
	Trailer,
	Trains,
	Utility,
	Vans,
	doomsdaycar,
	Smuggler,
	newdlc146,
	vehtroll,
	attch,
	Makeupmenu,
	plasticmenu,
	//LSC SubMenus
	///////////////////////////////////////////////////
	wheelcolour,
	brightshit,
	Rims,
	TRGB,
	ResprayssED,
	bennys,
	BackWheels,
	Bennywheel,
	O,
	B,
	wars,
	NEEE,
	New_DLC_foursix,
	Primaryyy,
	Secondaryyy,
	ResprayssEED,
	pbright,
	sbright,
	ClassicMetallic,
	Matte,
	Metals,
	Chrome,
	ClassicMetallics,
	Mattes,
	Metalss,
	Chromes,
	Roll,
	Spoiler,
	LSCWW,
	Trimd,
	Ornaments,
	Dashboard,
	Dials,
	Speaker,
	Lowrider,
	Musclerims,
	SUVrims,
	Sportrims,
	Highendrims,
	Lowriderrims,
	Offroadrims,
	Tunerrims,
	Smoke,
	Seats,
	Steeringwheel,
	Shifter,
	Plaques,
	Speakers,
	Trunk,
	Hydrulics,
	Block,
	Fit,
	smg,
	torc,
	ecase,
	Fliters,
	Struts,
	Aerials,
	Tank,
	Livrey,
	Platee,
	plate_Optionss,
	Light,
	Plate,
	Resprayss,
	Neonnn,
	Bennyss,
	ee,
	b,
	coolguns,
	inside,
	plateeee,
	Speakerr,
	picker,
	Armour,
	Brakes,
	armor,
	Engine,
	Hood,
	Roof,
	Grill,
	Skirts,
	Exhaust,
	Rollcage,
	Fenders,
	Horns,
	Windows,
	Suspension,
	Trans,
	Holder,
	Vanity,
	plateoptions,
	Wheels,
	fbumper,
	rbumper,
	pearlescentp,
	pearlescents,
	ClassicMetallicp,
	Mattep,
	Metalsp,
	Chromep,
	ClassicMetallicsp,
	Mattesp,
	Metalssp,
	Chromesp,
	wheelclass,
	wheelmatte,
	wheelmetal,
	fcar,
	//LSC SubMenus ends
	//////////////////////////////////////////////////
	//GunStore
	//////////////////////////////////////////////////
	guns,
	tints,
	MicroSMG,
	AssultSMG,
	SMG,
	Rifes,
	Shotgun,
	pump,
	AssaultShotgun,
	BullpupShotgun,
	HeavyShotgun,
	Saw,
	Pistol,
	Handguns,
	sns,
	heavy,
	combat,
	app,
	cal,
	vintage,
	MACHINE,
	Revolver,
	MarksmanPistol,
	StunGun,
	FlareGun,
	CombatPDW,
	MG,
	CombatMG,
	Gusenberg,
	Musket,
	DoubleBarrelShotgun,
	SawnoffShotgun,
	Autoshotgun,
	MachineGuns,
	AssaultRifle,
	CarbineRifle,
	AdvancedRifle,
	SpecialCarbine,
	BullpupRifle,
	CompactRifle,
	SniperRifles,
	sp,
	HeavySniper,
	MarksmanRifle,
	HeavyGuns,
	GrenadeLauncher,
	GrenadeLauncherSmoke,
	HomingLauncher,
	Railgun,
	Firework,
	Minigun,
	RPG,
	CompactLauncher,
	II,
	MK2_Pistol,
	Magazine_p,
	Attachment_p,
	Camos_p,
	Tints_P,
	SMG_Mk_II,
	Magazine_s,
	Muzzle_s,
	Camos_s,
	Tints_s,
	Scope_s,
	Barrel_s,
	Attachment_s,
	Assault_Rifle_Mk_II,
	Magazine_a,
	Scope_a,
	Muzzle_a,
	Attachment_a,
	Barrel_a,
	Camos_a,
	Tints_a,
	Carbine_Rifle_Mk_II,
	Magazine_c,
	Scope_c,
	Muzzle_c,
	Attachment_c,
	Barrel_c,
	Camos_c,
	Tints_c,
	Combat_MG_Mk_II,
	Magazine_mg,
	Scope_mg,
	Muzzle_mg,
	Attachment_mg,
	Barrel_mg,
	Camos_mg,
	Tints_mg,
	Heavy_Sniper_Mk_II,
	Magazine_hs,
	Scope_hs,
	Muzzle_hs,
	Attachment_hs,
	Barrel_hs,
	Camos_hs,
	Tints_hs,
	SNS_Pistol_Mk_II,
	Magazine_sn,
	Attachment_sn,
	Camos_sn,
	Tints_sn,
	Revolver_Mk_II,
	Magazine_r,
	Attachment_r,
	Camos_r,
	Special_Carbine_Mk_II,
	Magazine_sc,
	Scope_sc,
	Muzzle_sc,
	Attachment_sc,
	Barrel_sc,
	Camos_sc,
	Tints_sc,
	Bullpup_Rifle_Mk_II,
	Magazine_b,
	Scope_b,
	Muzzle_b,
	Attachment_b,
	Barrel_b,
	Camos_b,
	Tints_b,
	Pump_Shotgun_Mk_II,
	Magazine_sg,
	Scope_sg,
	Attachment_sg,
	Camos_sg,
	Tints_sg,
	Muzzle_sg,
	Marksman_Rifle_Mk_II,
	Magazine_m,
	Scope_m,
	Muzzle_m,
	Attachment_m,
	Barrel_m,
Camos_m,
Tints_m,
m,
Tints_r,
SwitchBlade,
KnuckleDuster,
Melee,
ThrownWeapons,
RAYPISTOL,
RAYCARBINE,
RAYMINIGUN,
checkguns,
//GunStore end
//////////////////////////////////////////////////
	 //Teleport 
//////////////////////////////////////////////////
TPMenu,
TPClothingStore,
TPBarbers,
TPLSC,
TPOVehicle,
TPAmmunation,
TPSports,
TPStores,
TPCinema,
TPTattos,
TPAir,
TPFun,
TPOther,
TPUnderwater,
TPATMs,
TPBanks,
TPServices,
TPAparts,
tp,
fun,
//Teleport end
//////////////////////////////////////////////////
//clothing
////////////////////////////////////
heads,
assssss,
mask,
hair,
torso,
legs,
hands,
shoe,
tee,
tops,
task,
emble,
topstwo,
clear,
w,
Outfitmale,
Outfitfemale,
Outfitssp,
Outfitinfo,
////////////////////////////////////
//clothing
settingss,
Font,
scroller,
Line,
text,
Title__Rect,
themes,
spoonermenu,
objectmenu,
objectmanager,
editrmenu,
_Selectedentity,
attach,
By_DLC_,//spawns for dlc soft by

BeachBum_,
Business_,
HighLife_,
ImNotAHipster_,
FlightSchool_,
LastTeamStanding_,
NextGenRelease_,
FestiveSuprise_,
Heists_,
III_Gotten_Gains_part1_,
III_Gotten_Gains_part2_,
halloween_,
Excutives_and_other_Criminals_,
Valentine_,
Bennys_update_,
Finance_and_Felony_,
AIDrving,
IPL,
dlc148,
//models
Modelmenu,
AModel,
PV,
ForceObjectGun,
landmarks,
highLocations,
Onlinerelated,
_Interiors,
vehkey,
};

void Option(char* option);
void Option(const char* option);

extern enum SubMenus;


typedef struct VECTOR2 {
	float x, y;
};
typedef struct VECTOR2_2 {
	float w, h;
};
typedef struct RGBAF {
	int r, g, b, a, f;
};
typedef struct RGBA {
	int r, g, b, a;
};
typedef struct RGB {
	int r, g, b;
};
namespace Menu {
	namespace Drawing {
		void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Title(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
	}
	namespace Settings {
		extern bool selectPressed;
		extern bool leftPressed;
		extern bool rightPressed;
		extern bool center;
		extern bool controllerinput;

		extern int maxVisOptions;
		extern int currentOption;
		extern int optionCount;

		extern SubMenus currentMenu;
		extern int menuLevel;
		extern int optionsArray[1000];
		extern SubMenus menusArray[1000];

		extern float menuX;
		extern RGBAF count;
		extern RGBAF titleText;
		extern RGBA titleRect;
		extern RGBAF breakText;
		extern RGBAF optionText;
		extern RGBA selectedText;
		extern RGBAF arrow;
		extern RGBAF integre;
		extern RGBA optionRect;
		extern RGBA scroller;
		extern RGBA line;
		extern RGBA primary;
		extern RGBA secondary;
		extern RGBA titleEnd;


		extern int keyPressDelay;
		extern int keyPressPreviousTick;
		extern int keyPressDelay2;
		extern int keyPressPreviousTick2;
		extern int keyPressDelay3;
		extern int keyPressPreviousTick3;
		extern int openKey;
		extern int backKey;
		extern int upKey;
		extern int downKey;
		extern int leftKey;
		extern int rightKey;
		extern int selectKey;
		extern int arrowupKey;
		extern int arrowdownKey;
		extern int arrowleftKey;
		extern int arrowrightKey;
		extern int enterKey;
		extern int deleteKey;
		extern int openpress;
		extern int downpress;
		extern int uppress;
		extern int backpress;
		extern int click;
		extern int leftpress;
		extern int rightpress;
		//menu shit
		extern float GlareX;
		extern float GlareY;
		extern float Glarewidth;
		extern float Glareheight;
		extern float menuX;
		extern float menuY;
		extern float menuW;
		extern float menuH;
		extern float menuR;

		//Object spooner
		extern float Scroll;



	}
	namespace MenuLevelHandler {
		void MoveMenu(SubMenus menu);
		void BackMenu();
	}
	namespace Checks {
		void Controlls();
	}
	namespace Tools {
		char* StringToChar(std::string string);
	}
	namespace Files {
		void WriteStringToIni(std::string string, std::string file, std::string app, std::string key);
		std::string ReadStringFromIni(std::string file, std::string app, std::string key);
		void WriteIntToIni(int intValue, std::string file, std::string app, std::string key);
		int ReadIntFromIni(std::string file, std::string app, std::string key);
		void WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key);
		float ReadFloatFromIni(std::string file, std::string app, std::string key);
		void WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key);
		bool ReadBoolFromIni(std::string file, std::string app, std::string key);
	}
	void Title(const char* title);
	void info(const char* title);
	//void Vehicle(std::string texture1, std::string texture2);
	void Speedometer(char* text);
	void fps(char* text);
	void AddSmallTitle(char* text);
	void AddSmallInfo(char* text, short line);
	void AddSmallTitle2(char* text);
	void AddSmallInfo2(char* text, short line);
	void AddSmallTitle3(char* text);
	void AddSmallInfo3(char* text, short line);
	bool Break(const char* option);
	bool Option(const char* option);
	bool Option(const char* option, char* maptext);

	void Subtitle(const char* title);
	bool OptionProp(char* Prop_Name);
	bool ColourOption(char* colour_Name, int colour_index, int colour_index2, bool Pearlescent, bool WheelColor);
	bool WheelOption(char* colour_Name, int wheel_index, int rim_index, bool Custom);
	bool WeaponOption(char* weapon_Name, char* hash, char* hashment, int ammo, int tnit, bool attchment, bool tint, bool gun);
	bool SpawnOption(char* option, char* carname);

	//bool Option(const char* option, std::function<void()> function);
	bool MenuOption(const char* option, SubMenus newSub);
	void PlayerOption(int i);
	bool tick(const char* option);
	//bool MenuOption(const char* option, SubMenus newSub, std::function<void()> function);
	bool Toggle(const char* option, bool& b00l);
	//bool Toggle(const char* option, bool& b00l, std::function<void()> function);
	bool Int(const char* option, int& _int, int min, int max);
	bool Int(const char* option, int& _int, int min, int max, int step);
	//bool Int(const char* option, int& _int, int min, int max, std::function<void()> function);
	//bool Int(const char* option, int& _int, int min, int max, int step, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max);
	bool Float(const char* option, float& _float, int min, int max, int step);
	bool Axis(const char* option, float& _float, int min, int max);
	bool Floathundr(const char* option, float& _float, int min, int max);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position);

	//bool Float(const char* option, float& _float, int min, int max, std::function<void()> function);
	//bool Float(const char* option, float& _float, int min, int max, int step, std::function<void()> function);
	//bool IntVector(const char* option, std::vector<int> Vector, int& position);
	//bool IntVector(const char* option, std::vector<int> Vector, int& position, std::function<void()> function);
	//bool FloatVector(const char* option, std::vector<float> Vector, int& position);
	//bool FloatVector(const char* option, std::vector<float> Vector, int& position, std::function<void()> function);
	//bool StringVector(const char* option, std::vector<std::string> Vector, int& position);
	//bool StringVector(const char* option, std::vector<std::string> Vector, int& position, std::function<void()> function);
	//bool StringVector(const char* option, std::vector<char*> Vector, int& position);
	//bool StringVector(const char* option, std::vector<char*> Vector, int& position, std::function<void()> function);
	//bool Teleport(const char* option, Vector3 coords);
	//bool Teleport(const char* option, Vector3 coords, std::function<void()> function);
	void End();
}
