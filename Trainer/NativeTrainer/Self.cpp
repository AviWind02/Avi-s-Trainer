#include "MAIN.h"

int wantedlevel;
bool Modegod = false;
bool Wantednever, Wanted = false;
bool ragdollno = false;
bool manparticle = false;
bool yesclip = false;
bool airwalk = false;
bool superjump = false;
bool playerinv = false;
bool superman = false;
bool tinynigga = false;
bool phoneoff = false;
bool SuperRun = false;
bool FastSwim, FastRun = false;
bool ignoreplayer = false;
bool seatbelt = false;
bool neverwanted = false;
Vector3 CCombineVector(float x, float y, float z)
{
	Vector3 returnVector;
	returnVector.x = x;
	returnVector.y = y;
	returnVector.z = z;
	return returnVector;
}
Object CCreate_Obj(char* ObjectName, Vector3 Coordinates)
{
	Object returnObj;
	Hash ObjectHash = GAMEPLAY::GET_HASH_KEY(ObjectName);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash))
	{
		if (STREAMING::IS_MODEL_VALID(ObjectHash))
		{
			STREAMING::REQUEST_MODEL(ObjectHash);
			if (STREAMING::HAS_MODEL_LOADED(ObjectHash))
			{
				returnObj = OBJECT::CREATE_OBJECT(ObjectHash, Coordinates.x, Coordinates.y, Coordinates.z, 1, 1, 0);
			}
			else
			{
				returnObj = NULL;
			}
		}
	}
}

void BoneFX(char* call1, char* call2, char* name, int bone) {
	float fx = 0.08f;
	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(name, PLAYER::PLAYER_PED_ID(), 0.00f, 0.00f, 0.00f, 0.00f, 0.00f, 0.0f, bone, fx, 1, 1, 1);
	STREAMING::REMOVE_PTFX_ASSET();
}
void SelfFunction()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	if (seatbelt)
	{
		putonseatbelt(playerPed, true);
	}
	if(ignoreplayer)
	{
		network_set_everyone_ignore_player(playerPed);
		set_self_nearby_peds_calm();
	}
	else
	{
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(playerPed, 1);
		PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(playerPed, 0);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(playerPed, false);
		PLAYER::SET_POLICE_IGNORE_PLAYER(playerPed, false);
	}
	if (SuperRun)
	{
		if (AI::IS_PED_RUNNING(playerPed) || AI::IS_PED_SPRINTING(playerPed) && !PED::IS_PED_RUNNING_RAGDOLL_TASK(playerPed))
		{
			ApplyForceToEntity(playerPed, 0.0f, 1.0f, 0.0f);
		}
	}
	if (airwalk)
	{
		char* prop = "p_oil_slick_01";
		Hash ObjHash = GAMEPLAY::GET_HASH_KEY(prop);
		Vector3 PlayerCoord = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		Object WalkOnAir = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(PlayerCoord.x, PlayerCoord.y, PlayerCoord.z, 100, ObjHash, 1, 0, 1);
		float zPlane;

		if ((!ENTITY::DOES_ENTITY_EXIST(WalkOnAir)) && (airwalk))
		{
			Object WalkOnAir = CCreate_Obj(prop, PlayerCoord);
			ENTITY::FREEZE_ENTITY_POSITION(WalkOnAir, 1);
			ENTITY::SET_ENTITY_VISIBLE(WalkOnAir, 0, false);
		}
		else if ((ENTITY::DOES_ENTITY_EXIST(WalkOnAir)) && (airwalk))
		{
			float Normal = 1.0225;
			float Down = 1.60;
			float Up = 0.40;
			float Vehicular = 50.0;
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Q to go up and E down");
			//UI::_DRAW_NOTIFICATION(2000, 1);
			if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))       //Gone when in a Car
			{
				zPlane = PlayerCoord.z - Vehicular;
			}
			else if (GetAsyncKeyState(0x45) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_SCRIPT_LS)))      //Down Z and L3
			{
				zPlane = PlayerCoord.z - Down;
			}
			else if (GetAsyncKeyState(0x51) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_SCRIPT_RS)))      //Up Q and R3
			{
				zPlane = PlayerCoord.z - Up;
			}
			else                                              //Normal
			{
				zPlane = PlayerCoord.z - Normal;
			}

			Vector3 Coord = CCombineVector(Coord.x, Coord.y, zPlane);
			ENTITY::SET_ENTITY_COORDS(WalkOnAir, PlayerCoord.x, PlayerCoord.y, zPlane, 1, 0, 0, 1);
		}
	}

	if (Modegod)
	{
		GodMode(true);
	}
	else
	{
		GodMode(false);
	}
	if (ragdollno)
	{
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), FALSE);
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), FALSE);
	}
	else
	{
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), TRUE);
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), TRUE);
	}
	if (manparticle)
	{
		BoneFX("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0x796e);
		BoneFX("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0x8cbd);
		BoneFX("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0xdead);
	}
	else
	{

	}
	if (yesclip)
	{
		static auto noClipSpeed = 1.5f;
		auto ped = PLAYER::PLAYER_PED_ID();
		auto startDist = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));

		auto pos = ENTITY::GET_ENTITY_COORDS(ped, false);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ped, pos.x, pos.y, pos.z, false, false, false);

		if (GetAsyncKeyState(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {
			if (IsKeyPressed(VK_LSHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 21))
				startDist -= 3.0;
			if (IsKeyPressed(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 22))
				startDist += .5;

			startDist -= noClipSpeed;
			startDist -= .3f;
			Vector3 coords = add(&ENTITY::GET_ENTITY_COORDS(ped, 1), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDist));

			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ped, coords.x, coords.y, coords.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
			if (IsKeyPressed(VK_LSHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 21))
				startDist += 3.0;
			if (IsKeyPressed(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 22))
				startDist -= .5;

			startDist += noClipSpeed;
			startDist += 1.f;
			Vector3 coords = add(&ENTITY::GET_ENTITY_COORDS(ped, 1), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDist));

			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ped, coords.x, coords.y, coords.z, false, false, false);
		}
	}
	else
	{

	}
	if (superjump)
	{
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(playerPed);
	}
	if (playerinv)
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, 0);

	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, 0);
	}
	if (FastRun) {

		PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(playerPed, 1.49);
	}else PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(playerPed, 1.0);
	if (FastSwim) {
		PLAYER::SET_SWIM_MULTIPLIER_FOR_PLAYER(playerPed, 1.49);
	}else 	PLAYER::SET_SWIM_MULTIPLIER_FOR_PLAYER(playerPed, 1.0);
	if (superman)
	{

		Ped  playerPed = PLAYER::PLAYER_PED_ID();
		Entity EntityTarget;
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 dir = rot_to_direction(&rot);
		if (ENTITY::IS_ENTITY_A_PED(playerPed) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 1))
		{
			EntityTarget = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
		}
		else
			EntityTarget = playerPed; 	
		Entity  playeryaw = ENTITY::GET_ENTITY_HEADING(EntityTarget);
		if (IsKeyPressed(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_RT) && Menu::Settings::controllerinput)
		{
			ENTITY::FREEZE_ENTITY_POSITION(EntityTarget, false);
			ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 2, dir.y * 2, dir.z * 2, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);

		}
		if (IsKeyPressed(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_LT) && Menu::Settings::controllerinput)
		{
			ENTITY::FREEZE_ENTITY_POSITION(EntityTarget, true);
			set_ObjectStraight(EntityTarget);
		}
	}
	if (tinynigga)
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, tinynigga);
	}
	else
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 0, tinynigga);


	}
	if (phoneoff)
	{
		if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(0xF292D030) > 0) // cellphone_controller
		{
			GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("cellphone_controller");
		}
		else
		{
			SCRIPT::REQUEST_SCRIPT_WITH_NAME_HASH(GAMEPLAY::GET_HASH_KEY("cellphone_controller"));
		}
	}
	if (neverwanted)
	{
		PLAYER::SET_MAX_WANTED_LEVEL(6);
		PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID(), 0, 0); 
		PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), 0);
	}

}
int targettingmode; 

void Self()
{
	Menu::Title("Sub Menu");
	Menu::Subtitle("Local Menu");
	Menu::Toggle("Godmode", Modegod);
	if (Menu::Int("Wanted Level", wantedlevel, 0, 5)) { PLAYER::SET_MAX_WANTED_LEVEL(6); PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID(), wantedlevel, 0); PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::PLAYER_ID(), 0); }
	if (PLAYER::GET_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_PED_ID()) < 1) Menu::Toggle("Never Wanted", neverwanted);
	if (Menu::Int("Player Targeting", targettingmode, 0, 2)) { if (Menu::Settings::currentOption) {	notifyBottom("0 = Traditional GTA, 1 = Assisted Aiming, 2 = Free Aim"); } }
	Menu::Toggle("Seat Belt", seatbelt);
	Menu::Toggle("All Ignore Me", ignoreplayer);
	Menu::Toggle("No Ragdoll", ragdollno);
	Menu::Toggle("Super Jump", superjump);
	Menu::Toggle("Super Run", SuperRun);
	Menu::Toggle("Fast Run", FastRun);
	Menu::Toggle("Fast Swim", FastSwim);
	Menu::Toggle("Fly Mode", superman);
	Menu::Toggle("Tiny Player", tinynigga);
	Menu::Toggle("Invisible", playerinv);
	Menu::Toggle("Noclip", yesclip);
	Menu::Toggle("Particle Man", manparticle);
	Menu::Toggle("Turn Off Phone", phoneoff);
	PLAYER::SET_PLAYER_TARGETING_MODE(targettingmode);
}