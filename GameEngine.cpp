#include "GameEngine.h"

void GameEngine::run()
{
	texture_player.loadFromFile("data/SGQ_Dungeon/characters/main/elf.png");
	player player_1(texture_player, 16, 16, 0.8, 1, true);
	menu MENU;

	RenderWindow window(VideoMode(1280, 720), "window");
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		if (current_scene == 1) {
			MENU.run(window);
		}
		else if(current_scene == 2)
		{

		}
	}
}
