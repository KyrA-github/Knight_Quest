#pragma once
#include "global.h"
#include "Entity.h"

class player : public Entity
{
public:
	player(Texture& texture, int W, int H, float Speed, float HP, bool Life);
	~player();
private:
};

