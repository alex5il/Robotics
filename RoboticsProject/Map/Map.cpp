#include "Map.h"

// TODO get from parameters
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

	grid.resize(mapHeight);

	for (int i = 0; i < mapHeight; i++)
	{
		grid[i].resize(mapWidth);
			for (int j = 0; j < mapWidth; j++)
			{
				grid[i][j] = UNKNOWN_CELL;
			}
	}
}

void Map::printMap() {
	char ch;
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			ch = grid[i][j];
			std::cout << ch;

		}
		std::cout << "\n";
	}
}

void Map::updateCell(int x, int y, Cell cell) {
	grid[x][y] = cell;
}

Cell Map::getCell(int x, int y) {
	return static_cast<Cell>(grid[x][y]);
}

void Map::createGridFromImage()
{
	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA...,

	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			// Get the current pixel and check if its not white, if not then its an occupied cell!
			if (image[y * mapWidth * 4 + x * 4]
						|| image[y * mapWidth * 4 + x * 4 + 1]
						|| image[y * mapWidth * 4 + x * 4 + 2]) {
				updateCell(y, x, FREE_CELL);
			}
			else {
				updateCell(y, x, OCCUPIED_CELL);
			}
		}
	}
}

void Map::inflateImage()
{
	int xInflation, yInflation;

	// We will inflate each obstacle by half of the robots size
	xInflation = (int)((30) / 2); // TODO get from parameters
	yInflation = (int)((30) / 2); // TODO get from parameters

	inflatedImage.resize(mapWidth * mapHeight * 4);

	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++) {

			int curr_pixel = y * mapWidth * 4 + x * 4;

			if (image[curr_pixel]
					|| image[curr_pixel + 1]
					|| image[curr_pixel + 2])
			{
				inflatedImage[curr_pixel] = CONSTS_H_::COLOR_WHITE;
				inflatedImage[curr_pixel + 1] = CONSTS_H_::COLOR_WHITE;
				inflatedImage[curr_pixel + 2] = CONSTS_H_::COLOR_WHITE;

				inflatedImage[curr_pixel + 3] = 255;// IMPORTANT it is int and not char...
			}

			else
			{
				// We surround the "black" pixels with more black on all sides
				//[I][I][I]
				//[I][B][I]  <- [I] - inflated, [B] - Black pixel
				//[I][I][I]
				for (int i = -xInflation; i < xInflation; i++) {
					for (int j = -yInflation; j < yInflation; j++) {

						// We multiply by 4 cause of bytes
						int inflationPixel = mapWidth * i * 4 + j * 4; // Same calculation is current pixel

						// Check so that it wont go out of our permitted image buffer size
						if (curr_pixel + inflationPixel >= 0 && curr_pixel + inflationPixel + 3 < inflatedImage.size()) {
							inflatedImage[curr_pixel + inflationPixel] = CONSTS_H_::COLOR_BLACK;
							inflatedImage[curr_pixel + 1 + inflationPixel] = CONSTS_H_::COLOR_BLACK;
							inflatedImage[curr_pixel + 2 + inflationPixel] = CONSTS_H_::COLOR_BLACK;

							inflatedImage[curr_pixel + 3 + inflationPixel] = 255;// IMPORTANT it is int and not char...
						}
					}
				}

			}
		}
	}

	encodeOneStep("inflatedImage.png", inflatedImage, mapWidth, mapHeight);
}


Map::~Map() {
	// TODO Auto-generated destructor stub
}

