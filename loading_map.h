#pragma once
#include "global.h"
#include <fstream>
#include <nlohmann/json.hpp>

class loading_map
{
public:
	Sprite sprite;
	bool tile_bool;
	int tile_x;
	int tile_y;
	int tilenumder;
	int width_map_img, height_map_img;

	void info(Texture& image);
	void read_file();
	void draw(RenderWindow& window);

};


