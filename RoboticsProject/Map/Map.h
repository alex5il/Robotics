#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#include "../Robot.h"

#include "../PngUtilities/lodepng.h"
#include "../PngUtilities/pngUtil.h"

#include "../Configurations/Consts.h"
#include "../Configurations/ConfigurationManager.h"


using namespace std;

enum Cell {
	FREE_CELL = ' ',
	OCCUPIED_CELL = '#',
	UNKNOWN_CELL = '?',
	CURRENT_CELL = '@',
	END_GOAL = 'E'
};

struct Location {

	int posX;
	int posY;

	Cell cellType;

	// In order to check if the location is a valid one we need some constraint on the current grid
	int rowGridCap;
	int colGridCap;

	bool isValid(int xOffset, int yOffset) {
		return (posY + yOffset) >= 0 && (posX + xOffset) >= 0
				&& (posY + yOffset) < rowGridCap
				&& (posX + xOffset) < colGridCap;
	}

	bool operator==(const Location& a) const {
		return (posX == a.posX && posY == a.posY);
	}

	bool operator!=(const Location& a) const {
		return (posX != a.posX || posY != a.posY);
	}

	bool operator <(const Location &rhs) const {
		return (posY < rhs.posY || (posY == rhs.posY && posX < rhs.posX));
	}

	bool operator >(const Location &lhs) const {
		return posY > lhs.posY;
	}

};

struct Graph {

	Location location;
	vector<Location>::iterator iterator;

	vector<vector<Location> > edges;

	vector<Location> neighbors(Location current) {
		vector<Location> result;
		for (int drow = -1; drow <= 1; ++drow) {
			for (int dcol = -1; dcol <= 1; ++dcol) {
				Location neighbor = edges[current.posY][current.posX];

				if (neighbor.isValid(dcol, drow)) {
					neighbor = edges[current.posY + drow][current.posX + dcol];
					result.push_back(neighbor);
				}
			}
		}
		return result;
	}

	// Check between 2 cells if they are in a diagonal path
	bool isDiagonal(Location a, Location b) {
		if (edges[a.posY + 1][a.posX + 1] == b
				|| edges[a.posY - 1][a.posX - 1] == b
				|| edges[a.posY + 1][a.posX - 1] == b
				|| edges[a.posY - 1][a.posX + 1] == b) {
			return true;
		}
		return false;
	}

	// Add buffer cost depending on how close it is to the OCCUPIED_CELL
	float bufferCost(Location a, Location b) {
		int bufferLevel = 5;
		int closestLevel = 0;

		for (int i = -bufferLevel; i < bufferLevel; i++) {
			for (int j = -bufferLevel; j < bufferLevel; j++) {
				if (edges[a.posY + i][a.posX + j].cellType == OCCUPIED_CELL) {
					if (closestLevel == 0) {
						closestLevel = std::min(abs(i), abs(j));
					}
					else {
						closestLevel = std::min(closestLevel, abs(j));
						closestLevel = std::min(closestLevel, abs(i));
					}
				}
			}
		}

		if (closestLevel != 0) {
			return bufferLevel * 10 - closestLevel * bufferLevel;
		} else {
			return 0;
		}

	}

	// Calculate cost between a and b locations
	float Cost(Location a, Location b) {

		// If the next cell (b) is occupied return 99(max cost)
		if (edges[b.posY][b.posX].cellType == OCCUPIED_CELL) {
			return 99;
		}

		// Check if the path is diagonal (if its is then return sqrt(2))
		if (isDiagonal(a, b)) {
			return 1.4 + bufferCost(a,b);
		}

		// Otherwise its vertical/horizontal - return cost 1
		return 1 + bufferCost(a,b);

	}

};

class Map {

private:
	std::vector<std::vector<Cell> > grid;

	Graph graph;

	// Map/ image coordinates and stuff

	int mapWidth;
	int mapHeight;

	Location startLocation;
	Location endLocation;

	float mapResolution;
	float gridResolution;
	std::string mapPath;

	std::vector<unsigned char> originalImage;
	std::vector<unsigned char> inflatedImage;
	std::vector<unsigned char> testImage;

	static Map* mapInstance;

	void updateCell(int x, int y, Cell cell);
	Cell getCell(int x, int y);

	void createGridFromImage(std::vector<unsigned char> image);
	void inflateImage();
	void createImageWithResolutionFromImage(std::vector<unsigned char> image);
	void createGridWithResolutionFromImage(std::vector<unsigned char> image, bool inverted);
	void createGridWithResolutionFromImageLegacy(std::vector<unsigned char> image, bool inverted);

	Map();
	virtual ~Map();

public:

	void printMap();
	void printMap2(Graph graph);

	void createGrid(bool inverted);
	std::vector<std::vector<Cell> > getGrid();
	int getMapWidth();
	int getMapHeight();

	Location getStartLocation();
	Location getEndLocation();

	Graph* getGraph();

	static Map* getInstance();
	static void deleteInstance();
};

#endif /* MAP_H_ */
