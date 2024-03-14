#include "global.h"


int tile = 16;

int current_scene = 1;

int matrix_h = 60, matrix_w = 60;

int Layer_odj[100][100];
int Layer_background[100][100];

float offsetX = 0, offsetY = 0;

int main()
{

	RenderWindow window(VideoMode(1366, 768), "window");

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
		// ...
	}
	return 0;
}
