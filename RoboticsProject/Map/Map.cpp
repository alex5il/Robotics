#include "Map.h"
#include "../Configurations/ConfigurationManager.h"

Map* Map::mapInstance = NULL;

Map::Map() {

	mapResolution = ConfigurationManager::getMapResolutionCM();
	gridResolution = ConfigurationManager::getGridResolutionCM();
	mapPath = ConfigurationManager::getMapPath();

	mapHeight = 0;
	mapWidth = 0;

	// Init basic data of the map

	unsigned int height, width;

	// Get the image , map height, map width via the given map path
	int err = lodepng::decode(originalImage, width, height, mapPath);

	mapWidth = width;
	mapHeight = height;

	graph.edges.resize(mapHeight);

	//grid.resize(mapHeight);

	for (int i = 0; i < mapHeight; i++) {
		graph.edges[i].resize(mapWidth);
		//grid[i].resize(mapWidth);
		for (int j = 0; j < mapWidth; j++) {
			//grid[i][j] = UNKNOWN_CELL;
			graph.edges[i][j].cellType = UNKNOWN_CELL;
			graph.edges[i][j].posX = j;
			graph.edges[i][j].posY = i;
			graph.edges[i][j].rowGridCap = mapHeight;
			graph.edges[i][j].colGridCap = mapWidth;
		}
	}

	// Start and end location fgor testing
	Location start;
	//start.posX = 50;
	//start.posY = 50;
	start.posX = ConfigurationManager::getStartLocationX();
	start.posY = ConfigurationManager::getStartLocationY();
	start.cellType = CURRENT_CELL;
	start.rowGridCap = mapHeight;
	start.colGridCap = mapWidth;

	Location end;
	//end.posX = 144;
	//end.posY = 137;
	//end.posX = 763;
	//end.posY = 70;
	end.posX = ConfigurationManager::getGoalX();
	end.posY = ConfigurationManager::getGoalY();
	end.cellType = END_GOAL;
	start.rowGridCap = mapHeight;
	end.colGridCap = mapWidth;

	startLocation = start;
	endLocation = end;

}

void Map::printMap() {
	char ch;
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			//ch = grid[i][j];
			ch = graph.edges[i][j].cellType;
			std::cout << ch;

		}
		std::cout << "\n";
	}
}

void Map::printMap2(Graph graph) {
	char ch;
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			//ch = grid[i][j];
			ch = graph.edges[i][j].cellType;
			std::cout << ch;

			if (graph.edges[i][j].cellType == CURRENT_CELL) {
				std::cout << "@";
			}

		}
		std::cout << "\n";
	}
}

void Map::updateCell(int x, int y, Cell cell) {
	//grid[x][y] = cell;
	graph.edges[x][y].cellType = cell;
}

Cell Map::getCell(int x, int y) {
	return static_cast<Cell>(grid[x][y]);
}

void Map::createGridFromImage(std::vector<unsigned char> image) {
	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA...,

	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			// Get the current pixel and check if its not white, if not then its an occupied cell!
			if (image[y * mapWidth * 4 + x * 4]
					|| image[y * mapWidth * 4 + x * 4 + 1]
					|| image[y * mapWidth * 4 + x * 4 + 2]) {
				updateCell(y, x, FREE_CELL);
			} else {
				updateCell(y, x, OCCUPIED_CELL);
			}
		}
	}
}

// Test method
void Map::createImageWithResolutionFromImage(std::vector<unsigned char> image) {

	// Get map resolution difference
	int gridRes = (int) (gridResolution / mapResolution) / 2;
	int resolutionCap = ((int) (gridRes * gridRes) / 2);

	testImage.resize(mapHeight * mapWidth * 4);

	int counter = 0;

	// We are going to run through the map, in the grid resolution, and create our new grid
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			int map_pixel = y * mapWidth * 4 + x * 4; // current map pixel
			int grid_pixel = y * mapWidth * 4 + x * 4; // current grid pixel

			// Run through the grid "pixel" and map the map accordingly to the grid
			// e.g. the grid resolution is 4 times larger than that of the map (10 and 2.5)
			// then for each pixel we check if it should be black or not by comparing the neighbour (3 to each side) pixels
			// if more than half neighbours are black then the grid pixel is black otherwise its white
			for (int i = -gridRes; i < gridRes; i++) {
				for (int j = -gridRes; j < gridRes; j++) {
					int offset = mapWidth * i * 4 + j * 4;

					if (map_pixel + offset >= 0
							&& map_pixel + offset + 3 < image.size()) {
						if (image[map_pixel + offset] == CONSTS_H_::COLOR_BLACK
								|| image[map_pixel + offset + 1]
										== CONSTS_H_::COLOR_BLACK
								|| image[map_pixel + offset + 2]
										== CONSTS_H_::COLOR_BLACK) {
							counter++;
						}
					}
				}
			}

			// Check if there are enough black pixels to confirm the black pixel on the grid
			if (counter > resolutionCap) {
				testImage[grid_pixel] = CONSTS_H_::COLOR_BLACK;
				testImage[grid_pixel + 1] = CONSTS_H_::COLOR_BLACK;
				testImage[grid_pixel + 2] = CONSTS_H_::COLOR_BLACK;
			}

			else {
				testImage[grid_pixel] = CONSTS_H_::COLOR_WHITE;
				testImage[grid_pixel + 1] = CONSTS_H_::COLOR_WHITE;
				testImage[grid_pixel + 2] = CONSTS_H_::COLOR_WHITE;
			}

			counter = 0;
			testImage[grid_pixel + 3] = 255;
		}
	}

	encodeOneStep("testGrid.png", testImage, mapWidth, mapHeight);
}

void Map::createGridWithResolutionFromImageLegacy(
		std::vector<unsigned char> image, bool inverted) {

	// Get map resolution difference
	int gridRes = (int) (gridResolution / mapResolution) / 2;

	// We are going to run through the map, in the grid resolution, and create our new grid
//	for (int y = 0; y < mapHeight; y++) {
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			int map_pixel;
			if (inverted) {
				map_pixel = (mapHeight - y) * mapWidth * 4 + x * 4; // current map pixel
			} else {
				map_pixel = y * mapWidth * 4 + x * 4; // current map pixel
			}

			// Run through the grid "pixel" and map the map accordingly to the grid
			// e.g. the grid resolution is 4 times larger than that of the map (10 and 2.5)
			// then for each pixel we check if it should be black or not by comparing the neighbour (3 to each side) pixels
			// if more than half neighbours are black then the grid pixel is black otherwise its white
			for (int i = -gridRes; i < gridRes; i++) {
				for (int j = -gridRes; j < gridRes; j++) {
					int offset = mapWidth * i * 4 + j * 4;

					if (map_pixel + offset >= 0
							&& map_pixel + offset + 3 < image.size()) {

						// Get the current pixel and check if its not white, if not then its an occupied cell!
						if (image[offset] || image[offset + 1]
								|| image[offset + 2]) {
							updateCell(y, x, FREE_CELL);
						} else {
							updateCell(y, x, OCCUPIED_CELL);
						}
					}
				}
			}
		}
	}
}

void Map::createGridWithResolutionFromImage(std::vector<unsigned char> image,
		bool inverted) {

	// Get map resolution difference
	int gridRes = (int) (gridResolution / mapResolution) / 2;
	int resolutionCap = ((int) (gridRes * gridRes) / 2);

	int counter = 0;

	// We are going to run through the map, in the grid resolution, and create our new grid
//	for (int y = 0; y < mapHeight; y++) {
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			int map_pixel;
			if (inverted) {
				map_pixel = (mapHeight - y) * mapWidth * 4 + x * 4; // current map pixel
			} else {
				map_pixel = y * mapWidth * 4 + x * 4; // current map pixel
			}

			// Run through the grid "pixel" and map the map accordingly to the grid
			// e.g. the grid resolution is 4 times larger than that of the map (10 and 2.5)
			// then for each pixel we check if it should be black or not by comparing the neighbour (3 to each side) pixels
			// if more than half neighbours are black then the grid pixel is black otherwise its white
			for (int i = -gridRes; i < gridRes; i++) {
				for (int j = -gridRes; j < gridRes; j++) {
					int offset = mapWidth * i * 4 + j * 4;

					if (map_pixel + offset >= 0
							&& map_pixel + offset + 3 < image.size()) {
						if (image[map_pixel + offset] == CONSTS_H_::COLOR_BLACK
								|| image[map_pixel + offset + 1]
										== CONSTS_H_::COLOR_BLACK
								|| image[map_pixel + offset + 2]
										== CONSTS_H_::COLOR_BLACK) {
							counter++;
						}
					}
				}
			}

			// Check if there are enough black pixels to confirm the black pixel on the grid
			if (counter > resolutionCap) {
				updateCell(y, x, OCCUPIED_CELL);
			}

			else {
				updateCell(y, x, FREE_CELL);
			}

			counter = 0;
		}
	}
}

void Map::inflateImage() {
	int xInflation, yInflation;

	// We will inflate each obstacle by half of the robots size
	// The robot is 30x30 cm so convert to our pixel size and then cut in half
	xInflation = (int) ((ConfigurationManager::getRobotSizeX() / mapResolution)) * (0.5);
	yInflation = (int) ((ConfigurationManager::getRobotSizeY() / mapResolution)) * (0.5);

	inflatedImage.resize(mapWidth * mapHeight * 4);

	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {

			int curr_pixel = y * mapWidth * 4 + x * 4;

			if (originalImage[curr_pixel] || originalImage[curr_pixel + 1]
					|| originalImage[curr_pixel + 2]) {
				inflatedImage[curr_pixel] = CONSTS_H_::COLOR_WHITE;
				inflatedImage[curr_pixel + 1] = CONSTS_H_::COLOR_WHITE;
				inflatedImage[curr_pixel + 2] = CONSTS_H_::COLOR_WHITE;

				inflatedImage[curr_pixel + 3] = 255; // IMPORTANT it is int and not char...
			}

			else {
				// We surround the "black" pixels with more black on all sides
				//[I][I][I]
				//[I][B][I]  <- [I] - inflated, [B] - Black pixel
				//[I][I][I]
				for (int i = -xInflation; i < xInflation; i++) {
					for (int j = -yInflation; j < yInflation; j++) {

						// We multiply by 4 cause of bytes
						int inflationPixel = mapWidth * i * 4 + j * 4; // Same calculation is current pixel

						// Check so that it wont go out of our permitted image buffer size
						if (curr_pixel + inflationPixel >= 0
								&& curr_pixel + inflationPixel + 3
										< inflatedImage.size()) {
							inflatedImage[curr_pixel + inflationPixel] =
									CONSTS_H_::COLOR_BLACK;
							inflatedImage[curr_pixel + 1 + inflationPixel] =
									CONSTS_H_::COLOR_BLACK;
							inflatedImage[curr_pixel + 2 + inflationPixel] =
									CONSTS_H_::COLOR_BLACK;

							inflatedImage[curr_pixel + 3 + inflationPixel] =
									255; // IMPORTANT it is int and not char...
						}
					}
				}

			}
		}
	}

	encodeOneStep("inflatedImage.png", inflatedImage, mapWidth, mapHeight);
}

// PUBLIC METHODS

void Map::createGrid(bool inverted) {
	inflateImage();
	createGridWithResolutionFromImage(inflatedImage, inverted);

	createImageWithResolutionFromImage(inflatedImage);

	graph.edges[startLocation.posY][startLocation.posX] = startLocation;
	graph.edges[endLocation.posY][endLocation.posX] = endLocation;

	//printMap();
}

std::vector<std::vector<Cell> > Map::getGrid() {
	return grid;
}

int Map::getMapHeight() {
	return mapHeight;
}

int Map::getMapWidth() {
	return mapWidth;
}

Map* Map::getInstance() {
	if (Map::mapInstance != NULL) {
		return Map::mapInstance;
	}

	mapInstance = new Map();

	return mapInstance;
}

Location Map::getStartLocation() {
	return startLocation;
}

Location Map::getEndLocation() {
	return endLocation;
}

Graph* Map::getGraph() {
	return &graph;
}

void Map::deleteInstance() {
	delete mapInstance;
}

Map::~Map() {
}

