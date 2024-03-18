#include "Map.h"

void Map::info(Texture& image)
{
	sprite.setTexture(image);
}

void Map::read()
{	
	try
	{
		nlohmann::json objJson;
		std::fstream fileInput;
		fileInput.open("data/maps/map.json");
		fileInput >> objJson;
		fileInput.close();

		auto layers = objJson["layers"];
		for (int i = 0; i < matrix_h; i++)
		{
			auto groundData = layers[1]["data"];
			auto treeData = layers[0]["data"];

			for (int j = 0; j < matrix_w; j++)
			{
				Layer_odj_re[i][j] = groundData[i * matrix_w + j];
				Layer_background_re[i][j] = treeData[i * matrix_w + j];
			}
		}
		re_cutting(3);
	}
	catch (const nlohmann::json::exception& error)
	{
	std::cout << "Error reading JSON: " << error.what() << std::endl;
	} 
}

void Map::re_cutting(int dir) 
{
	for (int i = 0; i < matrix_h; i++)
	{
		for (int j = 0; j < matrix_w; j++)
		{
			if (dir == 1)
			{
				Layer_odj[i][j] = Layer_odj_re[i][j];
	
			}
			else if (dir == 2)
			{
				Layer_background[i][j] = Layer_background_re[i][j];
			
			}
			else if (dir == 3)
			{
				Layer_odj[i][j] = Layer_odj_re[i][j];
				Layer_background[i][j] = Layer_background_re[i][j];

			}
		}
	}
}

void Map::edit(int id_search, int id_edit, int Layer)
{
	for (int i = 0; i < matrix_h; i++)
	{
		for (int j = 0; j < matrix_w; j++)
		{
			if(Layer == 1)
			{
				if (Layer_odj[i][j] == id_search) 
				{
					Layer_odj[i][j] = id_edit;
				}
			}
			else if (Layer == 2)
			{
				if (Layer_background[i][j] == id_search)
				{
					Layer_background[i][j] = id_edit;
				}
			}
		}
	}
}

void Map::generation(int save, int rooms[10][4], int id_room_max, int id_room_min)
{
	if (save == 1) 
	{
		for (int j = 0; j < 4; j++)
		{
			if (rooms[num_room_id][j] == 1)
			{
				switch (j)
				{
				case 0:
					edit(35, 39, 1);
					break;
				case 1:
					edit(7, 12, 1);
					break;
				case 2:
					edit(21, 28, 1);
					break;
				case 3:
					edit(49, 55, 1);
					break;
				default:
					break;
				}
			}
		}
	}
	else 
	{
		int room = 0;
		save = 1;
		id_room_max = id_room_min + rand() % id_room_max;
		for (int i = 0; i < id_room_max; i++)
		{
			for (int j = 0; j < id_room_min; j++)
			{
				if (rooms[i][j] == 0)
				{
					room += 1;
				}
			}
			if (room == 4)
			{
				int r = 0 + rand() % (1 - id_room_min);
				rooms[i][r] = 1;
			}
			room = 0;
		}
		save_class.write(save, rooms, id_room_max, id_room_max, id_room_min);
	}
}

void Map::draw(RenderWindow& window)
{
	for (int i = 0; i < matrix_h; i++)
	{
		for (int j = 0; j < matrix_w; j++)
		{
			int groundTile = Layer_odj[i][j];
			int treeTile = Layer_background[i][j];

			if (groundTile != 0)
			{
				tile_bool = true;
				tile_x = 16;
				tile_y = 16;
				tilenumder = Layer_odj[i][j];
				tile_x = tilenumder * tile_x;
				while (tile_bool)
				{
					if (tile_x > 224)
					{
						tile_x = tile_x - 224;
						tile_y = tile_y + 16;
					}
					else
					{
						tile_bool = false;
					}
				}
				sprite.setTextureRect(IntRect(tile_x - 16, tile_y - 16, tile, tile));
				sprite.setPosition(j * tile - offsetX, i * tile - offsetY);
				window.draw(sprite);

			}

			if (treeTile != 0)
			{
				tile_bool = true;
				tile_x = 16;
				tile_y = 16;
				tilenumder = Layer_background[i][j];
				tile_x = tilenumder * tile_x;
				while (tile_bool)
				{
					if (tile_x > 224)
					{
						tile_x = tile_x - 224;
						tile_y = tile_y + 16;
					}
					else
					{
						tile_bool = false;
					}
				}
				sprite.setTextureRect(IntRect(tile_x - 16, tile_y - 16, tile, tile));
				sprite.setPosition(j * tile - offsetX, i * tile - offsetY);
				window.draw(sprite);
			}
		}
	}
}
