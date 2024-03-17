#pragma once
#include "global.h"
#include <fstream>
#include <nlohmann/json.hpp>

class Map
{
public:
	Sprite sprite;

	bool tile_bool;

	int width_map_img, height_map_img, id_room, tilenumder, tile_y, tile_x;

	void info(Texture& image);
	void read();
	void generation(int save, int rooms[10][4]);
	void draw(RenderWindow& window);
	void edit(int id_search, int id_edit, int Layer);
};

