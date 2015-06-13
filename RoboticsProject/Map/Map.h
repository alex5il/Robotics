#include "../Configurations/Consts.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "../Robot.h"

#include "../PngUtilities/lodepng.h"
#include "../PngUtilities/pngUtil.h"

#include "../Configurations/Consts.h"

#ifndef MAP_H_
#define MAP_H_

enum Cell { FREE_CELL = ' ' , OCCUPIED_CELL = '#', UNKNOWN_CELL = '?', CURRENT_CELL = 'R' };

class Map {


public:
	// Map/ image coordinates and stuff

	static int mapWidth;
	static int mapHeight;

	static double mapResolution;
	static std::string mapPath;

private:
	std::vector<unsigned char> image;
	std::vector<std::vector<Cell> > grid;


	std::vector<unsigned char > inflatedImage;




public:
	Map();
	virtual ~Map();
	void updateCell(int x, int y, Cell cell);
	Cell getCell(int x, int y);
	void printMap();
	void createGridFromImage();
	void inflateImage();
};

#endif /* MAP_H_ */
