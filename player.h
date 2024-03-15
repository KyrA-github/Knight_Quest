#pragma once
#include "global.h"
#include "Entity.h"

class player : public Entity
{
public:
	void info(Texture& texture, int W, int H, float Speed, float HP, bool Life);
	void control(float time);
	~player();
private:
	void update(float time);
};

