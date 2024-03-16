#include "player.h"



void player::info(Texture& texture, int W, int H, float Speed, float HP, bool Life)
{	
	dx = 0;
	dy = 0;
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
	std::cout << time << std::endl;
	rect.left += dx * time;
	Collision(0);
	rect.top += dy * time;
	Collision(1);


	if (dy > 0)
	{
		currentFrame += 0.008 * time;
		if (currentFrame > 4) currentFrame -= 4;
		sprite.setTextureRect(IntRect(0, width * int(currentFrame), width, height));
	}
	else if (dy < 0)
	{
		currentFrame += 0.008 * time;
		if (currentFrame > 4) currentFrame -= 4;
		sprite.setTextureRect(IntRect(16, width * int(currentFrame), width, height));
	}
	else if (dx < 0)
	{
		currentFrame += 0.008 * time;
		if (currentFrame > 4) currentFrame -= 4;
		sprite.setTextureRect(IntRect(48, width * int(currentFrame), width, height));
	}
	else if (dx > 0)
	{
		currentFrame += 0.008 * time;
		if (currentFrame > 4) currentFrame -= 4;
		sprite.setTextureRect(IntRect(32, width * int(currentFrame), width, height));
	}
	else
	{
		currentFrame += 0.008 * time;
		if (currentFrame > 1) currentFrame -= 1;
		sprite.setTextureRect(IntRect(width * int(currentFrame), 0, width, height));
	}

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	dx = 0;
	dy = 0;
}

player::~player()
{

}


