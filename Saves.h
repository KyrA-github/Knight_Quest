#pragma once
#include "global.h"
#include "Map.h"
#include <fstream>
#include "nlohmann/json.hpp"

class Saves
{
private:
	Map map;
public:
	int room_id_max, room_id_min, save;
	const int rooms_h = 10, rooms_w = 4;
	int rooms[10][4];
	void read();
	void write();


};

