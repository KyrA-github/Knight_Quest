//#include "global.h"
#include "GameEngine.h"

int tile = 16;

int current_scene = 2;

int matrix_h = 60, matrix_w = 60;

int Layer_odj[100][100];
int Layer_background[100][100];

float offsetX = 0, offsetY = 0;

int main()
{
	GameEngine engine;
	engine.run();
	return 0;
}
