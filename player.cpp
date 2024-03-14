#include "player.h"

player::player(Texture& texture, int W, int H, float Speed, float HP, bool Life)
{
	life = Life;
	hp = HP;
	speed = Speed;
	width = W;
	height = H;
	sprite.setTexture(texture);
	rect = FloatRect(7 * height, 9 * width, height, width);
}

player::~player()
{
}
