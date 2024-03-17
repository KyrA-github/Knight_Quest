#include "Map.h"

void Map::read()
{	
	id_room = 3 + rand() % 6;

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
				Layer_odj[i][j] = groundData[i * matrix_w + j];
				Layer_background[i][j] = treeData[i * matrix_w + j];
			}
		}
	}
	catch (const nlohmann::json::exception& error)
	{
		std::cout << "Error reading JSON: " << error.what() << std::endl;
	} 
}

void Map::generation()
{
	

}
