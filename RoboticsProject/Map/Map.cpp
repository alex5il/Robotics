#include "Map.h"

double Map::mapResolution = 0;
std::string Map::mapPath = "/usr/robotics/PcBotWorld/hospital_section.png";
int Map::mapHeight = 0;
int Map::mapWidth = 0;

Map::Map() {


	// Init basic data of the map

	unsigned int height, width;

	// Get the image , map height, map width via the given map path
	int err = lodepng::decode(image,width,height,mapPath);

	mapWidth  = width;
	mapHeight = height;

	map.resize(mapHeight);

	for (int i = 0; i < mapHeight; i++)
	{
		map[i].resize(mapWidth);
			for (int j = 0; j < mapWidth; j++)
			{
				map[i][j] = UNKNOWN_CELL;
			}
	}
}

void Map::printMap() {
	char ch;
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			ch = map[i][j];
			std::cout << ch;

		}
		std::cout << "\n";
	}
}

void Map::updateCell(int x, int y, Cell cell) {
	map[x][y] = cell;
}

Cell Map::getCell(int x, int y) {
	return static_cast<Cell>(map[x][y]);
}

void Map::createGridFromImage()
{
	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA...,


	for (int x = 0; x < mapHeight; x++) {
		for (int y = 0; y < mapWidth; y++) {
			// Get the current pixel and check if its not white, if not then its an occupied cell!
			int current_pixel = (x * 4 * mapWidth) + (y * 4);
			if (image[current_pixel] == COLOR_WHITE) {
				updateCell(x, y, FREE_CELL);
			}
			else {
				updateCell(x, y, OCCUPIED_CELL);
			}
		}
	}
}


Map::~Map() {
	// TODO Auto-generated destructor stub
}

