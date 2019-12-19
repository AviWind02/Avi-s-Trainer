#include "MAIN.h"

//NOTIFICATIONS
/*
Colours:
~r~ = Red
~b~ = Blue
~g~ = Green
~y~ = Yellow
~p~ = Purple
~o~ = Orange
~c~ = Grey
~m~ = Dark Grey
~u~ = Black
~n~ = Skip Line
~s~ = White
~d~ = dark blue
~f~ = light blue
~l~ = black
~t~ = gray
~v~ = black

Fonts:
~italic~ = italic font
~bold~ = bold font
*/

void notifyleft(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	UI::_DRAW_NOTIFICATION(2000, 1);
}

char status_text[2048] = { 0 };
void update_status_text()
{
	if (GetTickCount() < 2500)
	{
		UI::SET_TEXT_FONT(0);
		UI::SET_TEXT_SCALE(0.55f, 0.55f);
		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_WRAP(0.0f, 1.0f);
		UI::SET_TEXT_CENTRE(1);
		UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 205);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(status_text);
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0.5, 0.5);
	}
}

void notifyBottom(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	UI::END_TEXT_COMMAND_PRINT(4000, 1);
}	void notifyBottom(std::string str) { notifyBottom(&str[0]); }

void notifyMap(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	//UI::_DRAW_NOTIFICATION(FALSE, FALSE);
}	void notifyMap(std::string str) { notifyMap(&str[0]); }

void notifyCenter(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	sprintf_s(status_text, "%s", buf);
}	void notifyCenter(std::string str) { notifyCenter(&str[0]); }

//DRAWING FUNCTIONS
void draw_rect(float A_0, float A_1, float A_2, float A_3, int A_4, int A_5, int A_6, int A_7)
{
	GRAPHICS::DRAW_RECT((A_0 + (A_2 * 0.5f)), (A_1 + (A_3 * 0.5f)), A_2, A_3, A_4, A_5, A_6, A_7);
}

void draw_menu_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText)
{
	// default values
	int text_col[4] = { 255, 255, 255, 255 },
		rect_col[4] = { 0, 0, 0, 80 };
	float text_scale = 0.30f;
	int font = 0;
	bool outline = true;
	bool dropshadow = true;

	// correcting values for active line
	if (active)
	{

		outline = false;
		dropshadow = true;
		text_col[0] = 0;
		text_col[1] = 0;
		text_col[2] = 0;
		text_col[3] = 255;

		rect_col[0] = 255;
		rect_col[1] = 255;
		rect_col[2] = 255;
		rect_col[3] = 80;

		if (rescaleText)text_scale = 0.30f;
	}

	if (title)
	{
		outline = true;
		dropshadow = true;
		text_col[0] = 255;
		text_col[1] = 255;
		text_col[2] = 255;
		text_col[3] = 255;

		rect_col[0] = 93;
		rect_col[1] = 182;
		rect_col[2] = 229;
		rect_col[2] = 255;

		if (rescaleText)text_scale = 0.36f;
		font = 0;
	}

	int screen_w, screen_h;
	GRAPHICS::GET_SCREEN_RESOLUTION(&screen_w, &screen_h);

	textLeft += lineLeft;

	float lineWidthScaled = lineWidth / (float)screen_w; // line width
	float lineTopScaled = lineTop / (float)screen_h; // line top offset
	float textLeftScaled = textLeft / (float)screen_w; // text left offset
	float lineHeightScaled = lineHeight / (float)screen_h; // line height

	float lineLeftScaled = lineLeft / (float)screen_w;

	// this is how it's done in original scripts

	// text upper part
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.0, text_scale);
	UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
	UI::SET_TEXT_CENTRE(0);
	if (outline)
	{
		UI::SET_TEXT_EDGE(1, 255, 215, 0, 255); //UI::SET_TEXT_OUTLINE();
	}

	if (dropshadow)
	{
		UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
	}
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)caption.c_str());
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(textLeftScaled, (((lineTopScaled + 0.00278f) + lineHeightScaled) - 0.005f));

	// text lower part
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.0, text_scale);
	UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
	UI::SET_TEXT_CENTRE(0);
	if (outline)
	{
		UI::SET_TEXT_EDGE(1, 255, 215, 0, 255); //UI::SET_TEXT_OUTLINE();
	}

	if (dropshadow)
	{
		UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
	}
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)caption.c_str());
	int num25 = UI::_GET_TEXT_SCREEN_LINE_COUNT(textLeftScaled, (((lineTopScaled + 0.00278f) + lineHeightScaled) - 0.005f));

	// rect
	draw_rect(lineLeftScaled, lineTopScaled + (0.00278f),
		lineWidthScaled, ((((float)(num25)*UI::_GET_TEXT_SCALE_HEIGHT(text_scale, 0)) + (lineHeightScaled * 1.0f)) + 0.005f),
		rect_col[0], rect_col[1], rect_col[2], rect_col[3]);
}