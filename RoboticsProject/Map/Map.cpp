#include "Map.h"
#include "Config.h"

Map::Map(Robot *robot) {
	for (int i = 0; i < MAP_ROWS; i++)
		for (int j = 0; j < MAP_COLS; j++)
			map[i][j] = UNKNOWN;
	rob = robot;

}

void Map::printMap() {
	char ch;
	for (int i = 0; i < MAP_ROWS; i++) {
		for (int j = 0; j < MAP_COLS; j++) {
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


Map::~Map() {
	// TODO Auto-generated destructor stub
}

