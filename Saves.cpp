#include "Saves.h"

void Saves::read()
{
	try
	{
		nlohmann::json objJson;
		std::fstream fileInput;
		fileInput.open("save.json");
		fileInput >> objJson;
		fileInput.close();

		save = objJson["save"];
		num_room_id = objJson["room_id"];
		room_id_min = objJson["room_id_min"];
		room_id_max = objJson["room_id_max"];
		auto layers = objJson["rooms"];
		for (int i = 0; i < room_id_max; i++)
		{
			auto Data = layers[0]["room_main"];
			for (int j = 0; j < room_id_max; j++)
			{
				rooms[i][j] = Data[i * room_id_max + j];
			}
		}
	}
	catch (const nlohmann::json::exception& error)
	{
		std::cout << "Error reading JSON: " << error.what() << std::endl;
	}
}

void Saves::write()
{

}


