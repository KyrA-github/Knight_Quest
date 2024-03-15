#pragma once
#include "global.h"
#include "player.h"
#include "menu.h"

class GameEngine
{
public:
	GameEngine();
	void run();
private:
	menu MENU;
	Clock clock;
	Texture texture_player;
	player player_1;

	int time = 0;

	void time_func();

	void current_scene_func(RenderWindow& window);
	

};

