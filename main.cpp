#include "GameEngine.h"

int tile = 16;

int current_scene = 2;

int matrix_h = 35, matrix_w = 47;

int Layer_odj[100][100];
int Layer_background[100][100];

float offsetX = -20, offsetY = -19;

int main()
{
	GameEngine engine;
	engine.run();
	return 0;
}
