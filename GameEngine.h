#pragma once
#include "global.h"
#include "player.h"
#include "menu.h"
#include "Map.h"
#include "Saves.h"

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
	Map map;
	Saves save;

	int time = 0;

	void time_func();

	void current_scene_func(RenderWindow& window);
	

};

