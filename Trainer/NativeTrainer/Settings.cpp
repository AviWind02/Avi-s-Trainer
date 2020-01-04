#include "MAIN.h"


void fonts()
{
	Menu::Title("");
	Menu::Subtitle("Font");
	if (Menu::Option("Chalet Comprime Cologne(Normal)")) { Menu::Settings::optionText.f = 4; }
	if (Menu::Option("Chalet London")) { Menu::Settings::optionText.f = 0; }
	if (Menu::Option("House Script")) { Menu::Settings::optionText.f = 1; }
	if (Menu::Option("Monospace")) { Menu::Settings::optionText.f = 2; }
	if (Menu::Option("Wing Dings")) { Menu::Settings::optionText.f = 3; }
	if (Menu::Option("Pricedown")) { Menu::Settings::optionText.f = 7; }
}
int NumberKeyboard() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}
//bool Menu::Settings::Sonny = false;
//void Rainbowmenu()
//{
//	if (Menu::Settings::Sonny)
//	{
//		if (Menu::Settings::titleRect.r > 0 && Menu::Settings::titleRect.b == 0, Menu::Settings::scroller.r > 0 && Menu::Settings::scroller.b == 0)
//		{
//			Menu::Settings::titleRect.r--;
//			Menu::Settings::titleRect.g++;
//			Menu::Settings::scroller.r--;
//			Menu::Settings::scroller.g++;
//		}
//		if (Menu::Settings::titleRect.g > 0 && Menu::Settings::titleRect.r == 0, Menu::Settings::scroller.g > 0 && Menu::Settings::scroller.r == 0)
//		{
//			Menu::Settings::titleRect.g--;
//			Menu::Settings::titleRect.b++;
//			Menu::Settings::scroller.g--;
//			Menu::Settings::scroller.b++;
//		}
//		if (Menu::Settings::titleRect.b > 0 && Menu::Settings::titleRect.g == 0, Menu::Settings::scroller.b > 0 && Menu::Settings::scroller.g == 0)
//		{
//			Menu::Settings::titleRect.r++;
//			Menu::Settings::titleRect.b--;
//			Menu::Settings::scroller.r++;
//			Menu::Settings::scroller.b--;
//		}
//
//		if (Menu::Settings::line.r > 0 && Menu::Settings::line.b == 0, Menu::Settings::titleEnd.r > 0 && Menu::Settings::titleEnd.b == 0)
//		{
//			Menu::Settings::line.r--;
//			Menu::Settings::line.g++;
//			Menu::Settings::titleEnd.r--;
//			Menu::Settings::titleEnd.g++;
//		}
//		if (Menu::Settings::line.g > 0 && Menu::Settings::line.r == 0, Menu::Settings::titleEnd.g > 0 && Menu::Settings::titleEnd.r == 0)
//		{
//			Menu::Settings::line.g--;
//			Menu::Settings::line.b++;
//			Menu::Settings::titleEnd.g--;
//			Menu::Settings::titleEnd.b++;
//		}
//		if (Menu::Settings::line.b > 0 && Menu::Settings::line.g == 0, Menu::Settings::titleEnd.b > 0 && Menu::Settings::titleEnd.g == 0)
//		{
//			Menu::Settings::line.r++;
//			Menu::Settings::line.b--;
//			Menu::Settings::titleEnd.r++;
//			Menu::Settings::titleEnd.b--;
//		}
//		(Menu::Settings::titleRect.r, Menu::Settings::titleRect.g, Menu::Settings::titleRect.b);
//		(Menu::Settings::scroller.r, Menu::Settings::scroller.g, Menu::Settings::scroller.b);
//		(Menu::Settings::line.r, Menu::Settings::line.g, Menu::Settings::line.b);
//		(Menu::Settings::titleEnd.r, Menu::Settings::titleEnd.g, Menu::Settings::titleEnd.b);
//
//	}
//}
void menuthemes()
{
	Menu::Title("");
	Menu::Subtitle("Menu Theme Colours");
	//Menu::Toggle("Sonny mode", Menu::Settings::Sonny);
	if (Menu::Option("Black Theme(Normal)")) {
		Menu::Settings::titleRect = { 0, 0, 0, 255 };
		Menu::Settings::scroller = { 0, 0, 0, 255 };
		Menu::Settings::line = { 255, 255, 255, 255 };
	}
	if (Menu::Option("Red Theme")) {
		Menu::Settings::titleRect = { 100, 0, 0, 255 };
		Menu::Settings::scroller = { 100, 0, 0, 255 };
		Menu::Settings::line = { 255, 0, 0, 255 };
	}
	if (Menu::Option("Blue Theme")) {
		Menu::Settings::titleRect = { 0, 0, 200, 255 };
		Menu::Settings::scroller = { 0, 0, 200, 255 };
		Menu::Settings::line = { 0, 0, 255, 255 };
	}
	if (Menu::Option("Green Theme")) {
		Menu::Settings::titleRect = { 0, 180, 0, 255 };
		Menu::Settings::scroller = { 0, 180, 0, 255 };
		Menu::Settings::line = { 0, 255, 0, 255 };
	}
}
void settingsoptiontext()
{
	Menu::Title("");
	Menu::Subtitle("Option Text");
	if (Menu::Int("Red", Menu::Settings::optionText.r, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::optionText.r = numberKeyboard();
		}
	}
	if (Menu::Int("Green", Menu::Settings::optionText.g, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::optionText.g = numberKeyboard();
		}
	}
	if (Menu::Int("Blue", Menu::Settings::optionText.b, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::optionText.b = numberKeyboard();
		}
	}
	if (Menu::Int("Opacity", Menu::Settings::optionText.a, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::optionText.a = numberKeyboard();
		}
	}
}
void linesettings()
{
	Menu::Title("");
	Menu::Subtitle("Line Color");
	if (Menu::Int("Red", Menu::Settings::line.r, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::line.r = numberKeyboard();
		}
	}
	if (Menu::Int("Green", Menu::Settings::line.g, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::line.g = numberKeyboard();
		}
	}
	if (Menu::Int("Blue", Menu::Settings::line.b, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::line.b = numberKeyboard();
		}
	}
	if (Menu::Int("Opacity", Menu::Settings::line.a, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::line.a = numberKeyboard();
		}
	}
}
void settingsscroller()
{
	Menu::Title("");
	Menu::Subtitle("Scroller");
	if (Menu::Int("Red", Menu::Settings::scroller.r, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::scroller.r = numberKeyboard();
		}
	}
	if (Menu::Int("Green", Menu::Settings::scroller.g, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::scroller.g = numberKeyboard();
		}
	}
	if (Menu::Int("Blue", Menu::Settings::scroller.b, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::scroller.b = numberKeyboard();
		}
	}
	if (Menu::Int("Opacity", Menu::Settings::scroller.a, 0, 255))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::scroller.a = numberKeyboard();
		}
	}
}
void settingfunctionss()
{


}
float fl;
void setting()
{
	Menu::Title("");
	Menu::Subtitle("Settings");
	Menu::MenuOption("Fonts", Font);
	Menu::MenuOption("Themes", themes);
	Menu::MenuOption("Scroller", scroller);
	Menu::MenuOption("Lines", scroller);
	Menu::MenuOption("Text", text);
	Menu::Break("Menu POS");
	if (Menu::Option("MenuX plus")) {
		if (Menu::Settings::menuX < 0.81f) Menu::Settings::menuX += 0.01f;
	}
	if (Menu::Option("MenuX minus")) {
		if (Menu::Settings::menuX > 0.17f) Menu::Settings::menuX -= 0.01f;
	}
	if (Menu::Option("Left")) { Menu::Settings::menuX = 0.17f; }
	if (Menu::Option("Center")) { Menu::Settings::menuX = 0.498f; }
	if (Menu::Option("Right")) { Menu::Settings::menuX = 0.883f; }
	if (Menu::Option("Beside Map")) { Menu::Settings::menuX = 0.294f; }
	Menu::Break("Menu Delay");
	if (Menu::Int("Scroll Delay", Menu::Settings::keyPressDelay2, 1, 200))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::keyPressDelay2 = NumberKeyboard();
		}
	}
	if (Menu::Int("Int/Float Delay", Menu::Settings::keyPressDelay3, 1, 200))
	{
		if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			Menu::Settings::keyPressDelay3 = NumberKeyboard();
		}
	}
	Menu::Break("--------");
	if (Menu::Option("Exit Game")) exit(0);




}








