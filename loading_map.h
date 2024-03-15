#pragma once
#include "global.h"
#include <fstream>
#include "json/include/nlohmann/json.hpp"

class loading_map
{
public:
	Sprite sprite;
	bool tile_bool;
	int tile_x;
	int tile_y;
	int tilenumder;

	loading_map(Texture& image);

	void read_file();
	void draw(RenderWindow& window);

};


