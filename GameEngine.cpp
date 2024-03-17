#include "GameEngine.h"

GameEngine::GameEngine()
{
	std::cout << "Start";
	texture_player.loadFromFile("data/images/9 walk.png");
	texture_map.loadFromFile("data/maps/walls.png");

	player_1.info(texture_player, 16, 16, 0.08, 1, true);
}

void GameEngine::run()
{
	map.info(texture_map);
	map.read();
	RenderWindow window(VideoMode(800, 600), "window");
	
	save.read();
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
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time = time / 1000;

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
		
		window.draw(player_1.get_sprite());
	}
}



