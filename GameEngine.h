#pragma once
#include "global.h"
#include "player.h"
#include "menu.h"
#include "loading_map.h"

class GameEngine
{
public:
	GameEngine();
	void run();
private:
	menu MENU;
	Clock clock;
	Texture texture_player, texture_map;
	player player_1;
	loading_map map_class;

	int time = 0;

	void time_func();

	void current_scene_func(RenderWindow& window);
	

};

