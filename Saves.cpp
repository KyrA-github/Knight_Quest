#include "Saves.h"

void Saves::read()
{
	try
	{
		read_file();
		fileInput.open("save.json");
		fileInput >> objJson;
		fileInput.close();

		save = objJson["save"];
		num_room_id = objJson["room_id"];
		room_id_min = objJson["room_id_min"];
		room_id_max = objJson["room_id_max"];
		auto layers = objJson["rooms"];
		for (int i = 0; i < rooms_h; i++)
		{
			auto Data = layers[0]["data"];
			for (int j = 0; j < rooms_w; j++)
			{
				rooms[i][j] = Data[i * rooms_w + j];
			}
		}
	}
	catch (const nlohmann::json::exception& error)
	{
		std::cout << "Error reading JSON: " << error.what() << std::endl;
	}
	map.generation(save, rooms, room_id_max, room_id_min);
}

void Saves::write(int save, int rooms[10][4], int rooms_now, int id_room_max, int id_room_min)
{
	int room_list[10*4];
	for (int i = 0; i < id_room_max; i++)
	{
		for (int j = 0; j < id_room_min; j++)
		{
			room_list[i*j] = rooms[i][j];
		}
	}
	nlohmann::json jsonfile;
	jsonfile["name"] = save;
	jsonfile["rooms_now"] = rooms_now;

	std::ofstream file("save.json");
	file << jsonfile;

}

void read_file()
{
	nlohmann::json objJson;
	std::fstream fileInput;
}


