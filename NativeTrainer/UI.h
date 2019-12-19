#pragma once
void notifyleft(char* msg);

//NOTIFICATION
void notifyBottom(char* fmt, ...);
void notifyBottom(std::string str);
void notifyMap(char* fmt, ...);
void notifyMap(std::string str);
void notifyCenter(char* fmt, ...);
void notifyCenter(std::string str);
void update_status_text();

//DRAWING FUNCTIONS
void draw_rect(float A_0, float A_1, float A_2, float A_3, int A_4, int A_5, int A_6, int A_7);
void draw_menu_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true);