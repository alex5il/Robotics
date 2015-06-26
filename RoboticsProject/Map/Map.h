#ifndef MAP_H_
#define MAP_H_


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "../Robot.h"

#include "../PngUtilities/lodepng.h"
#include "../PngUtilities/pngUtil.h"

#include "../Configurations/Consts.h"
#include "../Configurations/ConfigurationManager.h"

enum Cell { FREE_CELL = ' ' , OCCUPIED_CELL = '#', UNKNOWN_CELL = '?', CURRENT_CELL = 'R' };

class Map {

private:
	std::vector<std::vector<Cell> > grid;

	// Map/ image coordinates and stuff

	int mapWidth;
	int mapHeight;

	float mapResolution;
	float gridResolution;
	std::string mapPath;

	std::vector<unsigned char> originalImage;
	std::vector<unsigned char > inflatedImage;
	std::vector<unsigned char > testImage;

	static Map* mapInstance;

	void updateCell(int x, int y, Cell cell);
	Cell getCell(int x, int y);
	void printMap();
	void createGridFromImage(std::vector<unsigned char> image);
	void inflateImage();
	void createImageWithResolutionFromImage(std::vector<unsigned char> image);
	void createGridWithResolutionFromImage(std::vector<unsigned char> image);

	Map();
	virtual ~Map();

public:

	void createGrid();
	std::vector<std::vector<Cell> > getGrid();
	int getMapWidth();
	int getMapHeight();


	static Map* getInstance();
};

#endif /* MAP_H_ */
