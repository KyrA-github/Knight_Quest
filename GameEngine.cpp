#include "GameEngine.h"

GameEngine::GameEngine()
{
	std::cout << "Start";
	texture_player.loadFromFile("data/SGQ_Dungeon/characters/main/elf.png");
	texture_map.loadFromFile("data/maps/walls.png");

	player_1.info(texture_player, 16, 16, 0.8, 1, true);
}

void GameEngine::run()
{
	map_class.info(texture_map);
	RenderWindow window(VideoMode(1280, 720), "window");
	while (window.isOpen())
	{
		time_func();

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear(Color(33, 31, 48));

		current_scene_func(window);

		window.display();
	}
}

void GameEngine::time_func()
{
	float time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 700;

	if (time > 20) time = 20;
}

void GameEngine::current_scene_func(RenderWindow& window)
{
	if (current_scene == 1) {
		MENU.run(window);
	}
	else if (current_scene == 2)
	{

		player_1.control(time);
		map_class.draw(window);
		window.draw(player_1.get_sprite());
	}
}



