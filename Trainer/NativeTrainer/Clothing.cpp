#include "MAIN.h"
/*Component ID - Name

0 - Head
1 - Beard
2 - Hair
3 - Torso
4 - Legs
5 - Hands
6 - Foot
7 - None?
8 - Accessories like parachute, scuba tank
9 - Accessories like bags, mask, scuba mask
10- Decals and mask
11 - Auxiliary parts for torso*/

int drawablemax, texturemax, drawid, textid;
int Bearddrawablemax, Beardtexturemax, Bearddrawid, Beardtextid;
int Hairdrawablemax, Hairtexturemax, Hairdrawid, Hairtextid;
int Torsodrawablemax, Torsotexturemax, Torsodrawid, Torsotextid;
int Legsdrawablemax, Legstexturemax, Legsdrawid, Legstextid;
int HBdrawablemax, HBtexturemax, HBdrawid, HBtextid;
int Shoedrawablemax, Shoetexturemax, Shoedrawid, Shoetextid;
int TSNBdrawablemax, TSNBtexturemax, TSNBdrawid, TSNBtextid;
int Topdrawablemax, Toptexturemax, Topdrawid, Toptextid;
int TAdrawablemax, TAtexturemax, TAdrawid, TAtextid;
int EDdrawablemax, EDtexturemax, EDdrawid, EDtextid;
int Tops2drawablemax, Tops2texturemax, Tops2drawid, Tops2textid;

void Clothing_Component(char* Option, int colthing, int drawablemax, int texturemax, int drawid, int textid)
{

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	std::string Style = (" Style");
	std::string fullname = Option + Style;
	drawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, colthing);
	texturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, colthing, drawid);
	drawid = PED::GET_PED_DRAWABLE_VARIATION(playerPed, colthing);
	textid = PED::GET_PED_TEXTURE_VARIATION(playerPed, colthing);
	if (Menu::Int(Option, drawid, 0, drawablemax))
	PED::SET_PED_COMPONENT_VARIATION(playerPed, colthing, drawid, textid, 0);
	if(Menu::Int(Menu::Tools::StringToChar(fullname), textid, 0, texturemax))
	PED::SET_PED_COMPONENT_VARIATION(playerPed, colthing, drawid, textid, 0);
}
void Prop_Component(char* Option, int prop)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	std::string Style = (" Style");
	std::string fullname = Option + Style;
	drawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, prop);
	texturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, prop, drawid);
	if (Menu::Int(Option, drawid, 0, drawablemax))
		PED::SET_PED_PROP_INDEX(playerPed, prop, drawid, textid, 0);
	if (Menu::Int(Menu::Tools::StringToChar(fullname), textid, 0, texturemax))
		PED::SET_PED_PROP_INDEX(playerPed, prop, drawid, textid, 0);
}

void colthing()
{
	Menu::Title("");
	Menu::Subtitle("Clothing");
	Clothing_Component("Beard/Mask", 1, Bearddrawablemax, Beardtexturemax, Bearddrawid, Beardtextid);
	Clothing_Component("Hair", 2, Hairdrawablemax, Hairtexturemax, Hairdrawid, Hairtextid);
	Clothing_Component("Torso", 3, Torsodrawablemax, Torsotexturemax, Torsodrawid, Torsotextid);
	Clothing_Component("Legs", 4, Legsdrawablemax, Legstexturemax, Legsdrawid, Legstextid);
	Clothing_Component("Hands/Back", 5, HBdrawablemax, HBtexturemax, HBdrawid, HBtextid);
	Clothing_Component("shoe", 6, Shoedrawablemax, Shoetexturemax, Shoedrawid, Shoetextid);
	Clothing_Component("Teeth/Scarf/Necklace/Bracelets", 7, TSNBdrawablemax, TSNBtexturemax, TSNBdrawid, TSNBtextid);
	Clothing_Component("Accessory/Tops", 8, Topdrawablemax, Toptexturemax, Topdrawid, Toptextid);
	Clothing_Component("Task/Armour", 9, TAdrawablemax, TAtexturemax, TAdrawid, TAtextid);
	Clothing_Component("Emblem/Decals", 10, EDdrawablemax, EDtexturemax, EDdrawid, EDtextid);
	Clothing_Component("Tops2 (Outer)", 11, Tops2drawablemax, Tops2texturemax, Tops2drawid, Tops2textid);
	//Prop_Component("Hats", 0);
	//Prop_Component("Glasses", 1);
	//Prop_Component("Ear Pieces", 2);
	//Prop_Component("Watches", 6);
	//Prop_Component("Bangles", 7);
	//Prop_Component("Unknown", 3);
	//Prop_Component("Unknown", 4);
	//Prop_Component("Unknown", 5);
	//Prop_Component("Unknown", 8);
	//Prop_Component("Unknown", 9);
}