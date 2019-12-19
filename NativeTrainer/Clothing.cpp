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
bool Accessoriess, unbknownoptions, head, Hair, handsback, masks, torsos, leg, hand, shoes, tees, top, taks, embles, toptwo = false;

//Components
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


void colthing()
{
	Menu::Title("");
	Menu::Subtitle("Clothing");
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	// old way
	Bearddrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 1);
	Beardtexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 1, Bearddrawid);
	Hairdrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 2);
	Hairtexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 2, Hairdrawid);
	Torsodrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 3);
	Torsotexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 3, Torsodrawid);
	Legsdrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 4);
	Legstexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 4, Legsdrawid);
	HBdrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 5);
	HBtexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 5, HBdrawid);
	Shoedrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 6);
	Shoetexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 6, Shoedrawid);
	TSNBdrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 7);
	TSNBtexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 7, TSNBdrawid);
	Topdrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 8);
	Toptexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 8, Topdrawid);
	TAdrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 9);
	TAtexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 9, TAdrawid);
	EDdrawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 10);
	EDtexturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 10, EDdrawid);
	Tops2drawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 11);
	Tops2texturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 11, Tops2drawid);




	Menu::Toggle("Beard/Mask", masks);
	if (masks)
	{
		Menu::Int("Beard/Mask", Bearddrawid, 0, Bearddrawablemax);
		Menu::Int("Beard/Mask Style", Beardtextid, 0, Beardtexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, Bearddrawid, Beardtextid, 0);
	}
	Menu::Toggle("Hair", Hair);
	if (Hair)
	{
		Menu::Int("Beard/Mask", Hairdrawid, 0, Hairdrawablemax);
		Menu::Int("Beard/Mask Style", Hairtextid, 0, Hairtexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, Hairdrawid, Hairtextid, 0);
	}
	Menu::Toggle("Torso", torsos);
	if (torsos)
	{

		Menu::Int("Torso", Torsodrawid, 0, Torsodrawablemax);
		Menu::Int("Torso Style", Torsotextid, 0, Torsotexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, Torsodrawid, Torsotextid, 0);
	}
	Menu::Toggle("Legs", leg);
	if (leg)
	{
		Menu::Int("Legs", Legsdrawid, 0, Legsdrawablemax);
		Menu::Int("Leg Style", Legstextid, 0, Legstexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, Legsdrawid, Legstextid, 0);
	}
	Menu::Toggle("Hands/Back", handsback);
	if (handsback)
	{
		Menu::Int("Hands/Back", HBdrawid, 0, HBdrawablemax);
		Menu::Int("Hands/Back Style", HBtextid, 0, HBtexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, HBdrawid, HBtextid, 0);
	}
	Menu::Toggle("shoes", shoes);
	if (shoes)
	{
		Menu::Int("shoe", Shoedrawid, 0, Shoedrawablemax);
		Menu::Int("Shoe Style", Shoetextid, 0, Shoetexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, Shoedrawid, Shoetextid, 0);
	}
	Menu::Toggle("Teeth/Scarf/Necklace/Bracelets", tees);
	if (tees)
	{
		Menu::Int("Teeth/Scarf/Necklace/Bracelets", TSNBdrawid, 0, TSNBdrawablemax);
		Menu::Int("Teeth/Scarf/Necklace/Braceletss Style", TSNBtextid, 0, TSNBtexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 7, TSNBdrawid, TSNBtextid, 0);

	}
	Menu::Toggle("Top", top);
	if (top)
	{
		Menu::Int("Accessory/Tops", Topdrawid, 0, Topdrawablemax);
		Menu::Int("Accessory/Tops Style", Toptextid, 0, Toptexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Topdrawid, Toptextid, 0);
	}
	Menu::Toggle("Task/Armour", taks);
	if (taks)
	{
		Menu::Int("Task/Armour", TAdrawid, 0, TAdrawablemax);
		Menu::Int("Task/Armour Style", TAtextid, 0, TAtexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, TAdrawid, TAtextid, 0);
	}
	Menu::Toggle("Emblem/Decals", embles);
	if (embles)
	{
		Menu::Int("Emblem/Decals", EDdrawid, 0, EDdrawablemax);
		Menu::Int("Emblem/Decals Style", EDtextid, 0, EDtexturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, EDdrawid, EDtextid, 0);
	}
	Menu::Toggle("Tops2(Outer)", toptwo);
	if (toptwo)
	{
		Menu::Int("Tops2 (Outer)", Tops2drawid, 0, Tops2drawablemax);
		Menu::Int("Tops2 (Outer) Style", Tops2textid, 0, Tops2texturemax);
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, Tops2drawid, Tops2textid, 0);
	}

	Menu::Toggle("Unknown Options", unbknownoptions);
	if (unbknownoptions)
	{
		int earonee;
		//no clue what these do.
		// 3
		int noone, nothree, nofour;
		int noo = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 3);
		int nooo = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 3, earonee);
		int noooo = PED::GET_PED_PALETTE_VARIATION(playerPed, 3);
		// 4
		int neverone, neverthree, neverfour;
		int nver = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 4);
		int nverr = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 4, earonee);
		int nverrr = PED::GET_PED_PALETTE_VARIATION(playerPed, 4);
		// 5
		int unone, unthree, unfour;
		int un = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 5);
		int unn = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 5, earonee);
		int unnn = PED::GET_PED_PALETTE_VARIATION(playerPed, 5);
		// 8
		int gayone, gaythree, gayfour;
		int gay = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 8);
		int gayy = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 8, earonee);
		int gayyy = PED::GET_PED_PALETTE_VARIATION(playerPed, 8);
		// 9
		int idkone, idkthree, idkfour;
		int idkk = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 9);
		int idkkk = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 9, earonee);
		int idkkkk = PED::GET_PED_PALETTE_VARIATION(playerPed, 9);
		Menu::Int("Unknown", noo, 0, noone);//3 DONE 
		Menu::Int("Unknown", nver, 0, neverone);//4 DONE
		Menu::Int("Unknown ", un, 0, unone);//5 DONE
		Menu::Int("Unknown", gayone, 0, gay);//8 DONE
		Menu::Int("Unknown", idkone, 0, idkk);//9 DONE
		Menu::Int("Unknown Style", unthree, 0, noooo);//3 DONE
		Menu::Int("Unknown Style", neverthree, 0, nverrr);//4 DONE
		Menu::Int("Unknown Style", unthree, 0, unnn);//5 DONE
		Menu::Int("Unknown Style", gaythree, 0, gayyy);//8 DONE
		Menu::Int("Unknown Style", idkthree, 0, idkkk);//9 DONE
			// THEEE UNKNOWN FUCKERS
		{ PED::SET_PED_PROP_INDEX(playerPed, 3, noone, nothree, nofour); }// done
		{ PED::SET_PED_PROP_INDEX(playerPed, 4, neverone, neverthree, neverfour); }// done
		{ PED::SET_PED_PROP_INDEX(playerPed, 5, unone, unthree, unfour); }// done
		{ PED::SET_PED_PROP_INDEX(playerPed, 8, gayone, gaythree, gayfour); }// done
		{ PED::SET_PED_PROP_INDEX(playerPed, 9, idkone, idkthree, idkfour); }// done
	}
	Menu::Toggle("Accessoriess", Accessoriess);
	if (Accessoriess)// chnage to each a toggle 
	{
		//PED 0
		int Headone, Headthree, Headfour;
		int Head = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 0);
		int Headd = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 0, Headone);
		int Headdd = PED::GET_PED_PALETTE_VARIATION(playerPed, 0);
		//1
		int eyeone, eyethree, eyefour;
		int eyes = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 1);
		int eyess = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 1, Headone);
		int eyesss = PED::GET_PED_PALETTE_VARIATION(playerPed, 1);
		//2
		int earone, earthree, earfour;
		int ear = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 2);
		int earr = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 2, earone);
		int earrr = PED::GET_PED_PALETTE_VARIATION(playerPed, 2);
		// 6
		int waone, wathree, wafour;
		int waa = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 6);
		int waaa = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 6, waone);
		int waaaa = PED::GET_PED_PALETTE_VARIATION(playerPed, 6);
		// 7
		int bangone, bangthree, bangfour;
		int bang = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 7);
		int bangg = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, 7, bangone);
		int banggg = PED::GET_PED_PALETTE_VARIATION(playerPed, 7);
		Menu::Int("Hats", Headone, 0, Head);//0 DONE
		Menu::Int("Glasses", eyeone, 0, eyes);//1 DONE 
		Menu::Int("Ear Pieces", earone, 0, ear);//2 DONE
		Menu::Int("Watches", waone, 0, waa);//6 DONE
		Menu::Int("Bangles", bangone, 0, bang);//7 DONE
		Menu::Break("Accessories Style");// HEADSSSSSSSS NIGGGAAA
		Menu::Int("Hats Style", Headthree, 0, Headd);//0
		Menu::Int("Glasses Style", eyethree, 0, eyess);//1 DONE
		Menu::Int("Ear Pieces Style", earthree, 0, earrr);//2 DONE
		Menu::Int("Watches Style", wathree, 0, waaa);//6 done
		Menu::Int("Bangle Style", bangthree, 0, bangg);//7 done
		// prop
		{ PED::SET_PED_PROP_INDEX(playerPed, 0, Headone, Headthree, Headfour); }// done
		{ PED::SET_PED_PROP_INDEX(playerPed, 1, eyeone, eyethree, eyefour); }// done
		{ PED::SET_PED_PROP_INDEX(playerPed, 2, earone, earthree, earfour); }// done
		{ PED::SET_PED_PROP_INDEX(playerPed, 6, waone, wathree, wafour); }// done
		{ PED::SET_PED_PROP_INDEX(playerPed, 7, bangone, bangthree, bangfour); }// done
	}
}