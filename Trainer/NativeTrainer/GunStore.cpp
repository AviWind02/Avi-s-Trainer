#pragma once
#include "MAIN.h"

void sppp()
{
	Hash cur;
	notifyleft("Click Again For ~b~Ammo");
	if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &cur, 1))
	{
		if (WEAPON::IS_WEAPON_VALID(cur))
		{
			int maxAmmo;
			if (WEAPON::GET_MAX_AMMO(PLAYER::PLAYER_PED_ID(), cur, &maxAmmo))
			{
				WEAPON::SET_PED_AMMO(PLAYER::PLAYER_PED_ID(), cur, maxAmmo);

				maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, 1);
				if (maxAmmo > 0)
					WEAPON::SET_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, maxAmmo);
			}
		}
	}
}
//done 

// Weapon List
Hash weaponsList[] = {
	0x92A27487, 0x958A4A8F, 0xF9E6AA4B, 0x84BD7BFD, 0xA2719263, 0x8BB05FD7, 0x440E4788, 0x4E875F73, 0xF9DCBF2D, 0xD8DF3C3C, 0x99B507EA, 0xDD5DF8D9, 0xDFE37640, 0x678B81B1, 0x19044EE0, 0xCD274149, 0x94117305, 0x3813FC08, // Melee
	0x1B06D571, 0xBFE256D4, 0x5EF9FEC4, 0x22D8FE39, 0x3656C8C1, 0x99AEEB3B, 0xBFD21232, 0x88374054, 0xD205520E, 0x83839C4, 0x47757124, 0xDC4DB296, 0xC1B3C3D1, 0xCB96392F, 0x97EA20B8, // Handguns
	0x13532244, 0x2BE6766B, 0x2BE6766B, 0xEFE7E2DF, 0x0A3D4D34, 0xDB1AA450, 0xBD248B55, // Submachine Guns
	0x1D073A89, 0x555AF99A, 0x7846A318, 0xE284C527, 0x9D61E50F, 0xA89CB99E, 0x3AABBBAA, 0xEF951FBB, 0x12E82D3D, // Shotguns
	0xBFEFFF6D, 0x394F415C, 0x83BF0278, 0xFAD1F1C9, 0xAF113F99, 0xC0A3098D, 0x969C3D67, 0x7F229F94, 0x84D6FAFD, 0x624FE830, // Assault Rifles
	0x9D07F764, 0x7FD62962, 0xDBBD7280, 0x61012683, // Light Machine Guns
	0x05FC3C11, 0x0C472FE2, 0xA914799, 0xC734385A, 0x6A6C02E0, // Sniper Rifles
	0xB1CA77B1, 0xA284510B, 0x4DD2DC56, 0x42BF8A85, 0x7F7497E5, 0x6D544C99, 0x63AB0442, 0x0781FE4A, // Heavy Weapons
	0x93E220BD, 0xA0973D5E, 0x24B17070, 0x2C3731D9, 0xAB564B93, 0x787F0BB, 0xBA45E8B8, 0x23C9F95C, 0xFDBC8A50, 0x497FACC3, // Throwables
	0x34A67B97, 0xFBAB5776, 0x060EC506, // Miscellaneous
	0xAF3696A1, 0x476BF155, 0xB62D1F67	 // 1.46
};


void maingunmenu()
{

	Menu::Title("");
	Menu::Subtitle("Weapon");

	Menu::MenuOption("Melee", Melee);//done
	Menu::MenuOption("DLC", New_DLC_foursix);//done
	Menu::MenuOption("Handguns", Handguns);//done
	Menu::MenuOption("Machine Guns", MachineGuns);//done
	Menu::MenuOption("AR", Rifes);//done
	Menu::MenuOption("Sniper Rifles", SniperRifles);//done
	Menu::MenuOption("Shotguns", Shotgun);//done
	Menu::MenuOption("Heavy Weapon", HeavyGuns);//done
	Menu::MenuOption("Thrown Weapons", ThrownWeapons);//done
	Menu::MenuOption("Mark II guns", II);//done
	Menu::MenuOption("Tints", tints);//done
	Menu::MenuOption("Cool Guns", spacialg);//done
	Menu::WeaponOption("Parachute", "gadget_parachute", "N/A", 9999, NULL, false, false, true);
	if (Menu::Option("Give All Weapons")) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		for each (Hash weapon in weaponsList)
		{
			WEAPON::GIVE_WEAPON_TO_PED(playerPed, weapon, 9999, false, true);
		}
	}
}
//done
void marktwoguns()
{
	Menu::Title("");
	Menu::Subtitle("MK2 Weapon");
	Menu::MenuOption("Pistol MK II", MK2_Pistol);//done
	Menu::MenuOption("SMG Mk II", SMG_Mk_II);//done
	Menu::MenuOption("Assault Rifle Mk II", Assault_Rifle_Mk_II);//done
	Menu::MenuOption("Carbine Rifle Mk II", Carbine_Rifle_Mk_II);//done
	Menu::MenuOption("Combat MG Mk II", Combat_MG_Mk_II);//done
	Menu::MenuOption("Heavy Sniper Mk II", Heavy_Sniper_Mk_II);//done
	Menu::MenuOption("SNS Pistol Mk II", SNS_Pistol_Mk_II);//done
	Menu::MenuOption("Revolver Mk II", Revolver_Mk_II);//done
	Menu::MenuOption("Special Carbine Mk II", Special_Carbine_Mk_II);//done
	Menu::MenuOption("Bullpup Rifle Mk II", Bullpup_Rifle_Mk_II);//done
	Menu::MenuOption("Pump Shotgun Mk II", Pump_Shotgun_Mk_II);//done
	Menu::MenuOption("Marksman Rifle Mk II", Marksman_Rifle_Mk_II);//done
}
//done
void heavyguns()
{
	Menu::Title("");
	Menu::Subtitle("Heavy Weapon");
	Menu::MenuOption("Grenade Launcher", GrenadeLauncher);//done
	Menu::MenuOption("Grenade Launcher Smoke", GrenadeLauncherSmoke);//done
	Menu::MenuOption("Homing Launcher", HomingLauncher);//done
	Menu::MenuOption("Railgun", Railgun);//done
	Menu::MenuOption("Firework", Firework);//done
	Menu::MenuOption("Minigun", Minigun);//done
	Menu::MenuOption("RPG", RPG);//done
	Menu::MenuOption("Compact Launcher", CompactLauncher);//done
}
//done
void sniperrifles()
{
	Menu::Title("");
	Menu::Subtitle("SniperRifles");
	Menu::MenuOption("SniperRifle", sp);//done
	Menu::MenuOption("HeavySniper", HeavySniper);//done
	Menu::MenuOption("MarksmanRifle", MarksmanRifle);//done

}
//done
void rifes()
{
	Menu::Title("");
	Menu::Subtitle("AR");
	Menu::MenuOption("AssaultRifle", AssaultRifle);//done
	Menu::MenuOption("CarbineRifle", CarbineRifle);//done
	Menu::MenuOption("AdvancedRifle", AdvancedRifle);//done
	Menu::MenuOption("SpecialCarbine", SpecialCarbine);//done
	Menu::MenuOption("BullpupRifle", BullpupRifle);//done
	Menu::MenuOption("CompactRifle", CompactRifle);//done
}
//done
void handguns()
{
	Menu::Title("");
	Menu::Subtitle("HandGuns");
	Menu::MenuOption("Pistol", Pistol);//done
	Menu::MenuOption("SNS pistol", sns);//done
	Menu::MenuOption("Haevy Pistol", heavy);//done
	Menu::MenuOption("Combat Pistol", combat);//done
	Menu::MenuOption("AP Pistol", app);//done
	Menu::MenuOption(".50 Cal Pistol", cal);//done
	Menu::MenuOption("Vintage Pistol", vintage);//done
	Menu::MenuOption("Revolver", Revolver);//done
	Menu::MenuOption("MarksmanPistol", MarksmanPistol);//done
	Menu::MenuOption("StunGun", StunGun);//done
	Menu::MenuOption("FlareGun", FlareGun);//done
}
//done
void shotgun()
{
	Menu::Title("");
	Menu::Subtitle("ShotGuns");
	Menu::MenuOption("PumpShotgun", pump);//done
	Menu::MenuOption("AssaultShotgun", AssaultShotgun);//done
	Menu::MenuOption("BullpupShotgun", BullpupShotgun);//done
	Menu::MenuOption("HeavyShotgun", HeavyShotgun);//done
	Menu::MenuOption("Musket", Musket);//done
	Menu::MenuOption("DoubleBarrelShotgun", DoubleBarrelShotgun);//done
	Menu::MenuOption("SawnoffShotgun", SawnoffShotgun);//done
	Menu::MenuOption("Autoshotgun", Autoshotgun);//done
}
//done
void machineguns()
{
	Menu::Title("");
	Menu::Subtitle("Machine Guns");
	Menu::MenuOption("SMG", smg);//donet
	Menu::MenuOption("MicroSMG", MicroSMG);//done
	Menu::MenuOption("AssultSMG", AssultSMG);//done
	Menu::MenuOption("CombatPDW", CombatPDW);//done
	Menu::MenuOption("MG", MG);//done
	Menu::MenuOption("Machine Pistol", MACHINE);//done
	Menu::MenuOption("CombatMG", CombatMG);//done
	Menu::MenuOption("Gusenberg", Gusenberg);//done

}
//done
void new_DLC_foursix()
{
	Menu::Title("");
	Menu::Subtitle("DLC 1.46 Weapnes");
	Menu::MenuOption("Widowmaker", RAYMINIGUN);//done
	Menu::MenuOption("Unholy Hellbringer", RAYCARBINE);//done
	Menu::MenuOption("Ray Pistol", RAYPISTOL);//done
}
//done
void Tints()
{
	Menu::Title("");
	Menu::Subtitle("Tints");
	Menu::WeaponOption("Normal", "N/A", "N/A", NULL, 0, false, true, false);
	Menu::WeaponOption("Green", "N/A", "N/A", NULL, 1, false, true, false);
	Menu::WeaponOption("Gold", "N/A", "N/A", NULL, 2, false, true, false);
	Menu::WeaponOption("Pink", "N/A", "N/A", NULL, 3, false, true, false);
	Menu::WeaponOption("Army", "N/A", "N/A", NULL, 4, false, true, false);
	Menu::WeaponOption("LSPD", "N/A", "N/A", NULL, 5, false, true, false);
	Menu::WeaponOption("Orange", "N/A", "N/A", NULL, 6, false, true, false);
	Menu::WeaponOption("Platinum", "N/A", "N/A", NULL, 7, false, true, false);
}
//done
void thorwable()
{
	Menu::Title("");
	Menu::Subtitle("Thrown Weapons");
	Menu::WeaponOption("Grenades", "WEAPON_GRENADE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("StickyBomb", "WEAPON_STICKYBOMB", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("ProximityMine", "WEAPON_PROXMINE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("BZGas", "WEAPON_BZGAS", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Molotov", "WEAPON_MOLOTOV", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Flare", "WEAPON_FLARE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("SmokeGrenade", "WEAPON_SMOKEGRENADE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("PipeBomb", "WEAPON_PIPEBOMB", "N/A", 9999, NULL, false, false, true);
}
//done
void Cool_Guns()
{
	Menu::Title("");
	Menu::Subtitle("Other Weapons");
	Menu::WeaponOption("Garbage Bag", "WEAPON_GARBAGEBAG", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Hand Cuffs", "WEAPON_HANDCUFFS", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Digiscanner", "WEAPON_DIGISCANNER", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Briefcase", "WEAPON_BRIEFCASE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Stone Hatchet", "weapon_stone_hatchet", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Double Action Revolver", "weapon_doubleaction", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Baseball", "weapon_ball", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Snowball", "WEAPON_SNOWBALL", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Fire Extinguisher", "WEAPON_FIREEXTINGUISHER", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Jerry Can", "WEAPON_PETROLCAN", "N/A", 9999, NULL, false, false, true);


}
//done
void meleee()
{
	Menu::Title("");
	Menu::Subtitle("Melee");
	Menu::MenuOption("KnuckleDuster", KnuckleDuster);
	Menu::MenuOption("SwitchBlade", SwitchBlade);
	Menu::WeaponOption("Knife", "WEAPON_KNIFE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Night Stick", "WEAPON_NIGHTSTICK", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Hammer", "WEAPON_HAMMER", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Bat", "WEAPON_BAT", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Crow Bar", "WEAPON_CROWBAR", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Golf Club", "WEAPON_GOLFCLUB", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Bottle", "WEAPON_BOTTLE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Dagger", "WEAPON_DAGGER", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Hatchet", "WEAPON_HATCHET", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Hatchet", "WEAPON_MACHETE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Flashlight", "WEAPON_FLASHLIGHT", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Wrench", "WEAPON_WRENCH", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("BattleAxe", "WEAPON_BATTLEAXE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Stone Hatchet", "weapon_stone_hatchet", "N/A", 9999, NULL, false, false, true);
}
//done
void knuckleduster()
{
	Menu::Title("");
	Menu::Subtitle("KnuckleDuster");
	Menu::WeaponOption("KnuckleDuster", "weapon_knuckle", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Varmod Ballas", "N/A", "COMPONENT_KNUCKLE_VARMOD_BALLAS", NULL, NULL, true, false, false);
	Menu::WeaponOption("Varmod Base", "N/A", "COMPONENT_KNUCKLE_VARMOD_BASE", NULL, NULL, true, false, false);
	Menu::WeaponOption("Varmod Dollar", "N/A", "COMPONENT_KNUCKLE_VARMOD_DOLLAR", NULL, NULL, true, false, false);
	Menu::WeaponOption("Varmod Diamond", "N/A", "COMPONENT_KNUCKLE_VARMOD_DIAMOND", NULL, NULL, true, false, false);
	Menu::WeaponOption("Varmod Hate", "N/A", "COMPONENT_KNUCKLE_VARMOD_HATE", NULL, NULL, true, false, false);
	Menu::WeaponOption("Varmod King", "N/A", "COMPONENT_KNUCKLE_VARMOD_KING", NULL, NULL, true, false, false);
	Menu::WeaponOption("Varmod Love", "N/A", "COMPONENT_KNUCKLE_VARMOD_LOVE", NULL, NULL, true, false, false);
	Menu::WeaponOption("Varmod Pimp", "N/A", "COMPONENT_KNUCKLE_VARMOD_PIMP", NULL, NULL, true, false, false);
	Menu::WeaponOption("Varmod Player", "N/A", "COMPONENT_KNUCKLE_VARMOD_PLAYER", NULL, NULL, true, false, false);
	Menu::WeaponOption("Varmod Vagos", "N/A", "COMPONENT_KNUCKLE_VARMOD_VAGOS", NULL, NULL, true, false, false);
}
//done
void switchblade()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("SwitchBlade");
	Menu::WeaponOption("SwitchBlade", "WEAPON_SWITCHBLADE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Default Handle", "N/A", "COMPONENT_SWITCHBLADE_VARMOD_BASE", NULL, NULL, true, false, false);
	Menu::WeaponOption("VIP Variant", "N/A", "COMPONENT_SWITCHBLADE_VARMOD_BASE", NULL, NULL, true, false, false);
	Menu::WeaponOption("Bodyguard Variant", "N/A", "COMPONENT_SWITCHBLADE_VARMOD_VAR1", NULL, NULL, true, false, false);
}
//done
void Raygun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Widowmaker");
	Menu::WeaponOption("Widowmaker", "WEAPON_RAYMINIGUN", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Purple", "N/A", "N/A", NULL, 1, false, true, false);
	Menu::WeaponOption("Green", "N/A", "N/A", NULL, 2, false, true, false);
	Menu::WeaponOption("Orange", "N/A", "N/A", NULL, 3, false, true, false);
	Menu::WeaponOption("Pink", "N/A", "N/A", NULL, 4, false, true, false);
	Menu::WeaponOption("Gold", "N/A", "N/A", NULL, 5, false, true, false);
	Menu::WeaponOption("Platinum", "N/A", "N/A", NULL, 6, false, true, false);
}
//done
void RAYCarbine()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Unholy Hellbringer");
	Menu::WeaponOption("Unholy Hellbringer", "WEAPON_RAYCARBINE", "N/A", 9999, NULL, false, false, true);
	Menu::WeaponOption("Purple", "N/A", "N/A", NULL, 1, false, true, false);
	Menu::WeaponOption("Green", "N/A", "N/A", NULL, 2, false, true, false);
	Menu::WeaponOption("Orange", "N/A", "N/A", NULL, 3, false, true, false);
	Menu::WeaponOption("Pink", "N/A", "N/A", NULL, 4, false, true, false);
	Menu::WeaponOption("Gold", "N/A", "N/A", NULL, 5, false, true, false);
	Menu::WeaponOption("Platinum", "N/A", "N/A", NULL, 6, false, true, false);
}
//done
void RAYPistol()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Up-n-atomizer");
	if (Menu::Option("Give Up-n-atomizer"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_RAYPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Pruple"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}

}
//done
void mk2tints()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Tints");
	if (Menu::Option("Classic Black"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Classic Gray"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Classic Two Tone"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Classic White"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Classic Beige"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("Classic Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Classic Blue"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Classic Earth"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
	if (Menu::Option("Classic Brown And Black"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 8);
	}
	if (Menu::Option("Red Contrast"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 9);
	}
	if (Menu::Option("Blue Contrast"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 10);
	}
	if (Menu::Option("Yellow Contrast"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 11);
	}
	if (Menu::Option("Orange Contrast"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 12);
	}
	if (Menu::Option("Bold Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 13);
	}
	if (Menu::Option("Bold Purple And Yellow"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 14);
	}
	if (Menu::Option("Bold Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 15);
	}
	if (Menu::Option("Bold Green And Purple"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 16);
	}
	if (Menu::Option("Bold Red Features"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 17);
	}
	if (Menu::Option("Bold Green Features"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 18);
	}
	if (Menu::Option("Bold Cyan Features"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 19);
	}
	if (Menu::Option("Bold Yellow Features"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 20);
	}
	if (Menu::Option("Bold Red And White"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 21);
	}
	if (Menu::Option("Bold Blue And White"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 22);
	}
	if (Menu::Option("Metallic Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 23);
	}
	if (Menu::Option("Metallic Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 25);
	}
	if (Menu::Option("Metallic Gray And Lilac"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 26);
	}
	if (Menu::Option("Metallic Purple And Lime"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 27);
	}
	if (Menu::Option("Metallic Red"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 28);
	}
	if (Menu::Option("Metallic Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 29);
	}
	if (Menu::Option("Metallic Blue"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 30);
	}
	if (Menu::Option("Metallic White And Aqua"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 31);
	}
	if (Menu::Option("Metallic Red And Yellow"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 32);
	}
}
/*MarksmanRifle Mk II*/
void MarksmanRifleMkII()
{
	Menu::Title("");
	Menu::Subtitle("Marksman Rifle Mk II");
	if (Menu::Option("Give Marksman Rifle Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_m);
	Menu::MenuOption("Scope", Scope_m);
	Menu::MenuOption("Muzzle", Muzzle_m);
	Menu::MenuOption("Attachment", Attachment_m);
	Menu::MenuOption("Barrel", Barrel_m);
	Menu::MenuOption("Camos", Camos_m);
	Menu::MenuOption("Tints", Tints_m);
}
//done
void camos_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_04"));
	}
	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK "), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CAMO_IND_01"));
	}
}
//done
void muzzle_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Muzzle");
	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}

}
//done
void barrel_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Barrel");

	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MRFL_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MRFL_BARREL_02"));
	}
}
//done
void attachment_m()
{
	Menu::Title("");
	Menu::Subtitle("Attachment");
	Hash WeapHash;
	if (Menu::Option("FlashLight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void scope_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Scope");

	if (Menu::Option("Holographic Sight"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Large Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
	if (Menu::Option("Zoom Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_LARGE_FIXED_ZOOM_MK2"));
	}
}
//done
void magazine_m()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");

	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_INCENDIARY"));
	}
	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MARKSMANRIFLE_MK2_CLIP_FMJ"));
	}

}
/*pump shotgun Mk II*/
void pump_Shotgun_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("Pump Shotgun Mk II");
	if (Menu::Option("Pump Shotgun Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_sg);
	Menu::MenuOption("Scope", Scope_sg);
	Menu::MenuOption("Muzzle", Muzzle_sg);
	Menu::MenuOption("Attachment", Attachment_sg);
	Menu::MenuOption("Camos", Camos_sg);
	Menu::MenuOption("Tints", Tints_sg);
}
//done
void muzzle_sg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Muzzle");

	if (Menu::Option("Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_08"));
	}
}
//done
void camos_sg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_04"));
	}
	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CAMO_IND_01"));
	}
}
//done
void attachment_sg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");

	if (Menu::Option("Flashlight"))//
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SR_SUPP_03"));
	}
}
//done
void scope_sg()
{
	Menu::Title("");
	Menu::Subtitle("Scope");
	Hash WeapHash;
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL_MK2"));
	}
}
//done
void magazine_sg()
{
	Menu::Title("");
	Menu::Subtitle("Magazine");
	Hash WeapHash;
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_01"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_INCENDIARY"));
	}
	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("Hellow Point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("Explosive Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PUMPSHOTGUN_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_MK2_CLIP_EXPLOSIVE"));
	}
}
/*bullpup Rifle Mk II*/
void bullpup_Rifle_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("Bullpup Rifle Mk II");
	if (Menu::Option("Give  Bullpup Rifle Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_b);
	Menu::MenuOption("Scope", Scope_b);
	Menu::MenuOption("Muzzle", Muzzle_b);
	Menu::MenuOption("Attachment", Attachment_b);
	Menu::MenuOption("Barrel", Barrel_b);
	Menu::MenuOption("Camos", Camos_b);
	Menu::MenuOption("Tints", Tints_b);
}
//done
void camos_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");

	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CAMO_IND_01"));
	}
}
//done
void muzzle_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Muzzle");

	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void barrel_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Barrel");

	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_BARREL_02"));
	}
}
//done
void attachment_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");

	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void scope_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Scope");

	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_02_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL_MK2"));
	}
}
//donethe bla
void magazine_b()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_BULLPUPRIFLE_MK2_CLIP_FMJ"));
	}
}
/*Special Carbine Mk II*/
void special_Carbine_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("Special Carbine Mk II");
	if (Menu::Option("Give Special Carbine Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_sc);
	Menu::MenuOption("Scope", Scope_sc);
	Menu::MenuOption("Muzzle", Muzzle_sc);
	Menu::MenuOption("Attachment", Attachment_sc);
	Menu::MenuOption("Barrel", Barrel_sc);
	Menu::MenuOption("Camos", Camos_sc);
	Menu::MenuOption("Tints", Tints_sc);
}
//done
void camos_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_04"));
	}
	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CAMO_IND_01"));
	}
}
//done
void muzzle_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Muzzle");
	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void barrel_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Barrel");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SC_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SC_BARREL_02"));
	}
}
//done
void attachment_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP_02"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void scope_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Scope");
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
}
//done
void magazine_sc()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");

	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SPECIALCARBINE_MK2_CLIP_FMJ"));
	}
}
/*Revolver MK 2*/
void revolver_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("Revolver Mk II");
	if (Menu::Option("Give Revolver Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_r);
	Menu::MenuOption("Attachment", Attachment_r);
	Menu::MenuOption("Camos", Camos_r);
	Menu::MenuOption("Tints", Tints_r);
}
//done
void camos_r()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CAMO_IND_01"));
	}
}
//done
void attachment_r()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");

	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Compensator"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_COMP_03"));
	}
}
//done
void magazine_r()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");

	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CLIP_01"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_INCENDIARY"));
	}
	if (Menu::Option("Hollow point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("FMJ"))//check
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_MK2_CLIP_FMJ"));
	}
}
/*SNS Pistol MK2*/
void sNS_Pistol_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("SNS Pistol Mk II");
	if (Menu::Option("Give SNS Pistol Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_sn);
	Menu::MenuOption("Attachment", Attachment_sn);
	Menu::MenuOption("Camos", Camos_sn);
	Menu::MenuOption("Tints", Tints_sn);
}
//done
void camos_sn()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_10"));
	}
	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CAMO_IND_01"));
	}
}
//done
void attachment_sn()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");
	if (Menu::Option("Mounted Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_RAIL_02"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH_03"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP_02"));
	}
	if (Menu::Option("Compensator"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_COMP_02"));
	}
}
//done
void magazine_sn()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_TRACER"));
	}sppp();
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Hollow point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_MK2_CLIP_FMJ"));
	}
}
/*Heavy Sinper MK 2*/
void heavy_Sniper_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("Heavy Sniper Mk II");
	if (Menu::Option("Give Heavy Sniper Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_hs);
	Menu::MenuOption("Scope", Scope_hs);
	Menu::MenuOption("Muzzle", Muzzle_hs);
	Menu::MenuOption("Attachment", Attachment_hs);
	Menu::MenuOption("Barrel", Barrel_hs);
	Menu::MenuOption("Camos", Camos_hs);
	Menu::MenuOption("Tints", Tints_hs);
}
//done
void camos_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_10"));
	}
	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CAMO_IND_01"));
	}
}
//done
void muzzle_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Muzzle");
	if (Menu::Option("Squared Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_08"));
	}
	if (Menu::Option("Bell-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_09"));
	}
}
//done
void barrel_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Barrel");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SR_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SR_BARREL_02"));
	}
}
//done
void attachment_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SR_SUPP_03"));
	}
}
//done
void scope_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Scope");
	if (Menu::Option("Zoom scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_LARGE_MK2"));
	}
	if (Menu::Option("Advanced Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MAX"));
	}
	if (Menu::Option("Night Vision Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_NV"));
	}
	if (Menu::Option("Thermal Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_THERMAL"));
	}
}
//done
void magazine_hs()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_02"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_FMJ"));
	}
	if (Menu::Option("Explosive Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYSNIPER_MK2_CLIP_EXPLOSIVE"));
	}

}
/*Combat MG MK2*/
void combat_MG_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("Combat MG Mk II");
	if (Menu::Option("Give Combat MG Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_mg);
	Menu::MenuOption("Scope", Scope_mg);
	Menu::MenuOption("Muzzle", Muzzle_mg);
	Menu::MenuOption("Attachment", Attachment_mg);
	Menu::MenuOption("Barrel", Barrel_mg);
	Menu::MenuOption("Camos", Camos_mg);
	Menu::MenuOption("Tints", Tints_mg);
}
//done
void camos_mg()
{
	Hash WeapHash;

	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CAMO_IND_01"));
	}
}
//done
void muzzle_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Muzzle");
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void barrel_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Barrel");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MG_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MG_BARREL_02"));
	}
}
//done
void attachment_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void scope_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Scope");
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
}
//done
void magazine_mg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_MK2_CLIP_FMJ"));
	}
}
/*Carbine Rifle mk 2*/
void carbine_Rifle_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("Carbine Rifle Mk II");
	if (Menu::Option("Give Carbine Rifle Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_c);
	Menu::MenuOption("Scope", Scope_c);
	Menu::MenuOption("Muzzle", Muzzle_c);
	Menu::MenuOption("Attachment", Attachment_c);
	Menu::MenuOption("Barrel", Barrel_c);
	Menu::MenuOption("Camos", Camos_c);
	Menu::MenuOption("Tints", Tints_c);
}
//done
void camos_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CAMO_IND_01"));
	}
}
//done
void muzzle_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Muzzle");
	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void barrel_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Barrel");
	if (Menu::Option("Normal Barrel"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_CR_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_CR_BARREL_02"));
	}

}
//done
void attachment_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void scope_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Scope");
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
}
//done
void magazine_c()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_CARBINERIFLE_MK2_CLIP_FMJ"));
	}
}
/*Assault Rifle mk 2*/
void assault_Rifle_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("Assault Rifle Mk II");
	if (Menu::Option("Give Assault Rifle Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_a);
	Menu::MenuOption("Scope", Scope_a);
	Menu::MenuOption("Muzzle", Muzzle_a);
	Menu::MenuOption("Attachment", Attachment_a);
	Menu::MenuOption("Barrel", Barrel_a);
	Menu::MenuOption("Camos", Camos_a);
	Menu::MenuOption("Tints", Tints_a);
}
//done
void camos_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_10"));
	}
	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CAMO_IND_01"));
	}
}
//done
void muzzle_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Muzzle");
	if (Menu::Option("Flat Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void barrel_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Barrel");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_BARREL_02"));
	}
}
//done
void attachment_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))//fixed
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP_02"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP_02"));
	}
}
//done
void scope_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Scope");
	if (Menu::Option("Holographic Sight"))//chec
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS"));
	}
	if (Menu::Option("Small Scope"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MEDIUM_MK2"));
	}
}
//done
void magazine_a()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Armor Piercing Rounds"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_ARMORPIERCING"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTRIFLE_MK2_CLIP_FMJ"));
	}
}
/*MK2 SMG*/
void sMG_Mk_II()
{
	Menu::Title("");
	Menu::Subtitle("SMG Mk II");
	if (Menu::Option("Give SMG Mk II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_s);
	Menu::MenuOption("Scope", Scope_s);
	Menu::MenuOption("Muzzle", Muzzle_s);
	Menu::MenuOption("Attachment", Attachment_s);
	Menu::MenuOption("Barrel", Barrel_s);
	Menu::MenuOption("Camos", Camos_s);
	Menu::MenuOption("Tints", Tints_s);
}
//done
void camos_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_04"));
	}

	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CAMO_IND_01"));
	}
}
//done
void muzzle_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Muzzle");
	if (Menu::Option("Tactical Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_01"));
	}
	if (Menu::Option("Fat-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_02"));
	}
	if (Menu::Option("Precision Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_03"));
	}
	if (Menu::Option("Heavy Duty Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_04"));
	}
	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_05"));
	}

	if (Menu::Option("Slanted Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_06"));
	}
	if (Menu::Option("Split-End Muzzle Brake"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_MUZZLE_07"));
	}
}
//done
void barrel_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Barrel");
	if (Menu::Option("Normal Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SB_BARREL_01"));
	}
	if (Menu::Option("Heavy Barrel"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SB_BARREL_02"));
	}
}
//done
void attachment_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
}
//done
void scope_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Scope");
	if (Menu::Option("Holographic Sight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SIGHTS_SMG"));
	}
	if (Menu::Option("Small Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO_02_SMG_MK2"));
	}
	if (Menu::Option("Medium Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL_SMG_MK2"));
	}
}
//done
void magazine_s()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Hollow point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SMG_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SMG_MK2_CLIP_FMJ"));
	}
}
/*PISTOL MK2*/
void mK2_Pistol()
{
	Menu::Title("");
	Menu::Subtitle("Pistol MK II");
	if (Menu::Option("Give Pistol MK II"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), 9999, 1, 1);
	}
	Menu::MenuOption("Magazine", Magazine_p);
	Menu::MenuOption("Attachment", Attachment_p);
	Menu::MenuOption("Camos", Camos_p);
	Menu::MenuOption("Tints", Tints_P);
}
//done
void camos_p()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Camos");
	if (Menu::Option("Digital Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO"));
	}
	if (Menu::Option("Brushstroke Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_02"));
	}
	if (Menu::Option("Woodland Camo"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_03"));
	}
	if (Menu::Option("Skull"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_04"));
	}
	if (Menu::Option("Sessanta Nove"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_05"));
	}
	if (Menu::Option("Perseus"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_06"));
	}
	if (Menu::Option("Leopard"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_07"));
	}
	if (Menu::Option("Zebra"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_08"));
	}
	if (Menu::Option("Geometric"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_09"));
	}
	if (Menu::Option("Boom"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_10"));
	}

	if (Menu::Option("Patriotic"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CAMO_IND_01"));
	}
}
//done
void attachment_p()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Attachment");
	if (Menu::Option("Mounted Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_RAIL"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH_02"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP_02"));
	}
	if (Menu::Option("Compensator"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_COMP"));
	}
}
//done
void magazine_p()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Magazine");
	if (Menu::Option("Normal Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_01"));
	}
	if (Menu::Option("Extended Magazine"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_02"));
	}
	if (Menu::Option("Tracer"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_TRACER"));
	}
	if (Menu::Option("Incendiary"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_INCENDIARY"));
	}

	if (Menu::Option("Hollow point"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_HOLLOWPOINT"));
	}
	if (Menu::Option("FMJ"))
	{
		sppp();
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL_MK2"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_MK2_CLIP_FMJ"));
	}
}
// reg guns
//done
//pistol
void pistol()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Pistol");
	if (Menu::Option("Give Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_CLIP_02"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL_VARMOD_LUXE"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void marksmanPistol()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("MarksmanPistol");
	if (Menu::Option("Give MarksmanPistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MARKSMANPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void revolver()
{
	Hash WeapHash;
	Menu::Title("");

	Menu::Subtitle("Revolver");
	if (Menu::Option("Give Revolver"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER"), 9999, 1, 1);
	}
	if (Menu::Option("Varmod Goon"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_VARMOD_GOON"));
	}
	if (Menu::Option("Varmod Boss"))

	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_REVOLVER"), GAMEPLAY::GET_HASH_KEY("COMPONENT_REVOLVER_VARMOD_BOSS"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void Vintage()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Vintage Pistol");
	if (Menu::Option("Give vintage Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_VINTAGEPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_VINTAGEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_VINTAGEPISTOL_CLIP_02"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_VINTAGEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void mACHINE()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Machine Pistol");
	if (Menu::Option("Give Machine Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MACHINEPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MACHINEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MACHINEPISTOL_CLIP_02"));
	}
	if (Menu::Option("Drum Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MACHINEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MACHINEPISTOL_CLIP_03"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MACHINEPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void App()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("AP pistol");
	if (Menu::Option("Give AP Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_APPISTOL_CLIP_02"));
	}
	if (Menu::Option("Gilded Gun Metal Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_APPISTOL_VARMOD_LUXE"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_APPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void call()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle(".50 Cal");
	if (Menu::Option("Give .50 Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL50_CLIP_02"));
	}
	if (Menu::Option("Platinum Pearl Deluxe Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PISTOL50_VARMOD_LUXE"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_PISTOL50"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void snss()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("SNS Pistol");
	if (Menu::Option("Give SNS Pistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_CLIP_02"));
	}
	if (Menu::Option("Etched Wood Grip Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNSPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SNSPISTOL_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Combat()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Combat Pistol");
	if (Menu::Option("Give CombatPistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATPISTOL_CLIP_02"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATPISTOL_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void HEavy()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Heavy Pistol");
	if (Menu::Option("Give HeavyPistol"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYPISTOL_CLIP_02"));
	}
	if (Menu::Option("Etched Wood Grip Finish"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_HEAVYPISTOL_VARMOD_LUXE"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYPISTOL"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_PI_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void flareGun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("FlareGun");
	if (Menu::Option("Give FlareGun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_FLAREGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void stunGun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("StunGun");
	if (Menu::Option("Give Stun Gun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//shotguns
void autoshotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Auto shotgun");
	if (Menu::Option("Give Auto shotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_AUTOSHOTGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void sawnoffShotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Sawn off Shotgun");
	if (Menu::Option("Give Sawn off Shotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SAWNOFFSHOTGUN"), 9999, 1, 1);
	}
	if (Menu::Option("VarmodLuxe"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SAWNOFFSHOTGUN"), GAMEPLAY::GET_HASH_KEY("COMPONENT_SAWNOFFSHOTGUN_VARMOD_LUXE"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void doubleBarrelShotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Double Barrel");
	if (Menu::Option("Give Double Barrel"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_DBSHOTGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void HeavyshOtgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("HeavyShotgun");
	if (Menu::Option("Give HeavyShotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_heavyshotgun_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_heavyshotgun_clip_03"));
	}
	if (Menu::Option("Grip"))

	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void bullpupShotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("BullpupShotgun");
	if (Menu::Option("Give Bullpup Shotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), 9999, 1, 1);
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void assaultShotgun()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("AssaultShotgun");
	if (Menu::Option("Give AssaultShotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), 9999, 1, 1);
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTSHOTGUN_CLIP_02"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void PumP()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("PumpShotgun");
	if (Menu::Option("Give PumpShotgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), 9999, 1, 1);
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_sr_supp"));
	}
	if (Menu::Option("Special finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), GAMEPLAY::GET_HASH_KEY("COMPONENT_PUMPSHOTGUN_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void musket()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Musket");
	if (Menu::Option("Give Musket"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_musket"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
//SUB
void gusenberg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Gusenberg");
	if (Menu::Option("give Gusenberg"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GUSENBERG"), 9999, 1, 1);
	}
	if (Menu::Option("Drum Mag"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GUSENBERG"), GAMEPLAY::GET_HASH_KEY("component_gusenberg_clip_02"));
	}

	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void assultSMG()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("AssaultSMG");
	if (Menu::Option("Give AssultSMG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTSMG_CLIP_02"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP_02"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_ASSAULTSMG_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void microSMG()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("MicroSMG");
	if (Menu::Option("Give MicroSMG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_microsmg_clip_02"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_at_scope_macro"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Varmod Luxe"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_MICROSMG_VARMOD_LUXE"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void ssmg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("SMG");
	if (Menu::Option("Give SMG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_smg_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_smg_clip_03"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_at_pi_supp"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_smg_varmod_luxe"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void combatPDW()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("CombatPDW");
	if (Menu::Option("Give CombatPDW"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Clip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("component_combatpdw_clip_02"));
	}
	if (Menu::Option("Drum Mag"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("component_combatpdw_clip_03"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATPDW"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void combatMG()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("CombatMG");
	if (Menu::Option("Give CombatMG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), 9999, 1, 1);
	}
	if (Menu::Option("Extended/Drum Mag"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), GAMEPLAY::GET_HASH_KEY("component_combatmg_clip_02"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
	}
	if (Menu::Option("Etched Gun Metal Finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), GAMEPLAY::GET_HASH_KEY("COMPONENT_COMBATMG_VARMOD_LOWRIDER"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMBATMG"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void MGg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("MG");
	if (Menu::Option("Give MG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MG"), 9999, 1, 1);
	}
	if (Menu::Option("Extended/Drum Mag"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MG"), GAMEPLAY::GET_HASH_KEY("component_mg_clip_02"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MG"), GAMEPLAY::GET_HASH_KEY("component_at_scope_small_02"));
	}
	if (Menu::Option("Yusuf Amir Luxury Finish"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MG"), GAMEPLAY::GET_HASH_KEY("component_mg_varmod_lowrider"));
	}

	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//AR
//done
void Bullpuprifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("BullpupRifle");
	if (Menu::Option("Give BullpupRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("component_bullpuprifle_clip_02"));
	}

	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Varmod Lowrider"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("component_bullpuprifle_varmod_low"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_AFGRIP"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_BULLPUPRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Specialcarbine()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("SpecialCarbine");
	if (Menu::Option("Give SpecialCarbine"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_specialcarbine_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_specialcarbine_clip_03"));
	}

	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
	}
	if (Menu::Option("Varmod Lowrider"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_specialcarbine_varmod_lowrider"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SPECIALCARBINE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void Advancedrifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("AdvancedRifle");
	if (Menu::Option("Give AdvancedRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("component_advancedrifle_clip_02"));
	}

	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Varmod Luxe"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("component_advancedrifle_varmod_luxe"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ADVANCEDRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Carbinerifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("CarbineRifle");
	if (Menu::Option("Give CarbineRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_carbinerifle_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_carbinerifle_clip_03"));
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
	}
	if (Menu::Option("Varmod Luxe"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_carbinerifle_varmod_luxe"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_CARBINERIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_SUPP"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void assaultRifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("AssaultRifle");
	if (Menu::Option("Give AssaultRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_assaultrifle_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_assaultrifle_clip_03"));
	}
	if (Menu::Option("Scope"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MACRO"));
	}
	if (Menu::Option("Varmod Luxe"))
	{

		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_assaultrifle_varmod_luxe"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flashlight"))//check
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_AR_FLSH"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_ASSAULTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Compactrifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("CompactRifle");
	if (Menu::Option("Give CompactRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMPACTRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMPACTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_compactrifle_clip_02"));
	}
	if (Menu::Option("Drum Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMPACTRIFLE"), GAMEPLAY::GET_HASH_KEY("component_compactrifle_clip_03"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//sinpers
void Marksmanrifle()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("MarksmanRifle");
	if (Menu::Option("Give MarksmanRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), 9999, 1, 1);
	}
	if (Menu::Option("Extended Magazine"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_marksmanrifle_clip_02"));
	}

	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void spp()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("SniperRifle");
	if (Menu::Option("Give SniperRifle"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNIPERRIFLE"), 9999, 1, 1);
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNIPERRIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_scope_max"));
	}
	if (Menu::Option("Suppressor"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_SNIPERRIFLE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Heavysniper()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("HeavySniper");
	if (Menu::Option("Give HeavySniper"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER"), 9999, 1, 1);
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HEAVYSNIPER"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_MAX"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//heavy guns
//done
void RPGg()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("RPG");
	if (Menu::Option("Give RPG"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_RPG"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void MinigunN()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Minigun");
	if (Menu::Option("Give Minigun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_MINIGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void GrenadeLauncherR()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("GrenadeLauncher");
	if (Menu::Option("Give GrenadeLauncher"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER"), 9999, 1, 1);
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}

}
//done
void FireworkK()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Firework");
	if (Menu::Option("Give Firework"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_FIREWORK"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void HomingLauncherr()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("HomingLauncher");
	if (Menu::Option("Give HomingLauncher"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_HOMINGLAUNCHER"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void GrenadeLauncherSmokee()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("GrenadeLauncherSmoke");
	if (Menu::Option("Give Smoke Launcher"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER_SMOKE"), 9999, 1, 1);
	}
	if (Menu::Option("Scope"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER_SMOKE"), GAMEPLAY::GET_HASH_KEY("COMPONENT_AT_SCOPE_SMALL"));
	}
	if (Menu::Option("Flash Light"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER_SMOKE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
	}
	if (Menu::Option("Grip"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER_SMOKE"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void CompactLauncherr()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("CompactLauncher");
	if (Menu::Option("Give Compact Launcher"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_COMPACTLAUNCHER"), 25, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
//done
void Railgunn()
{
	Hash WeapHash;
	Menu::Title("");
	Menu::Subtitle("Railgun");
	if (Menu::Option("Give Railgun"))
	{
		WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN"), 9999, 1, 1);
	}
	if (Menu::Option("Normal"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
	}
	if (Menu::Option("Green"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
	}
	if (Menu::Option("Gold"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
	}
	if (Menu::Option("Pink"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
	}
	if (Menu::Option("Army"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
	}
	if (Menu::Option("LSPD"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
	}
	if (Menu::Option("Orange"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
	}
	if (Menu::Option("Platinum"))
	{
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
	}
}
