#pragma once
#include "global.h"
#include "loading_map.h"
class Map
{
public:
	int id_room;
	int main_room[4] = {0,1,0,0};
	void generation();
};

