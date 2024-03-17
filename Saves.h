#pragma once
#include "global.h"
#include <fstream>
#include "nlohmann/json.hpp"

class Saves
{
public:
	int save;
	int num_room_id;
	int room_id_min;
	int room_id_max;
	int main_room[4] = {0,1,0,0};
	int rooms[10][4];
	void read();
	void write();


};

