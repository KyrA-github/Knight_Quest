#pragma once
#include "global.h"

using namespace sf;

class Entity
{
protected:
	float dx, dy, hp, speed, currentFrame;
	int width, height, viewed;
	bool life;
	FloatRect rect;
	Sprite sprite;
public:
	void Collision(int dir);
	Sprite get_sprite() const;
};
 