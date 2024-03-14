#include "Entity.h"

bool Entity::Collision(FloatRect rect, float dx, float dy, int dir)
{
	for (int i = rect.top / tile; i < (rect.top + rect.height) / tile; i++)
		for (int j = rect.left / tile; j < (rect.left + rect.width) / tile; j++)
		{
			if (Layer_odj[i][j] != 0)
			{
				return true;
			}
			return false;
		}
}

Sprite Entity::get_sprite() const
{
	return sprite;
}
