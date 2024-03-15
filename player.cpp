#include "player.h"



void player::info(Texture& texture, int W, int H, float Speed, float HP, bool Life)
{	
	currentFrame = 0;
	viewed = 1;
	life = Life;
	hp = HP;
	speed = Speed;
	width = W;
	height = H;
	sprite.setTexture(texture);
	rect = FloatRect(7 * height, 9 * width, height, width);
}

void player::control(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		dy = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		dx = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		dy = speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		dx = speed;
	}
	update(time);
}

void player::update(float time)
{
	rect.left += dx * time;
	Collision(0);
	rect.top += dy * time;
	Collision(1);


	if (dy > 0)
	{

	}
	else if (dx < 0)
	{
		currentFrame += 0.01 * time;
		if (currentFrame > 3) currentFrame -= 3;
		sprite.setTextureRect(IntRect(width * int(currentFrame) + width, 0, -width, height));
	}
	else if (dx > 0)
	{
		currentFrame += 0.01 * time;
		if (currentFrame > 3) currentFrame -= 3;
		sprite.setTextureRect(IntRect(width * int(currentFrame), 0, width, height));
	}
	else
	{
		if (viewed) {
			currentFrame += 0.01 * time;
			if (currentFrame > 3) currentFrame -= 3;
			sprite.setTextureRect(IntRect(width * int(currentFrame), 32, width, height));

		}
		else
		{
			currentFrame += 0.01 * time;
			if (currentFrame > 3) currentFrame -= 3;
			sprite.setTextureRect(IntRect(width * int(currentFrame) + width, 32, -width, height));

		}
	}

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	dx = 0;
	dy = 0;
}

player::~player()
{

}


