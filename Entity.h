#pragma once
#include "global.h"

using namespace sf;

class Entity
{
protected:
	float dx, dy, hp, speed;
	int width, height;
	bool life;
	FloatRect rect;
	Sprite sprite;
public:
	bool Collision(FloatRect rect, float dx, float dy, int dir);

	Sprite get_sprite() const;
};
 