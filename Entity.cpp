#include "Entity.h"

void Entity::Collision(int dir)
{
	for (int i = rect.top / tile; i < (rect.top + rect.height) / tile; i++)
		for (int j = rect.left / tile; j < (rect.left + rect.width) / tile; j++)
		{
			if (Layer_odj[i][j] != 0)
			{
				if ((dx > 0) && (dir == 0)) rect.left = j * tile - rect.width;
				if ((dx < 0) && (dir == 0)) rect.left = j * tile + tile;
				if ((dy > 0) && (dir == 1)) rect.top = i * tile - rect.height;
				if ((dy < 0) && (dir == 1)) rect.top = i * tile + tile;
			}
		}
}

Sprite Entity::get_sprite() const
{
	return sprite;
}
