#pragma once
//VEHICLE
bool get_vehicle_keyboard_result(uint* outModel);
Vehicle nearbyveh();
bool islsc();
void deletecar();
bool isbennys();
void drive_on_water(Ped ped, Entity& waterobject);
bool setvehmod(char* mod, int type, int index);
Vehicle getvehpedisin();