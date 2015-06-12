#include "../Configurations/Consts.h"
#include <iostream>
#include <math.h>
#include "../Robot.h"

#ifndef MAP_H_
#define MAP_H_

enum Cell { FREE = ' ' , OCCUPIED = '*', UNKNOWN = '?' };

class Map {


private:

double _posX;
double _posY;
double _yaw;
Robot* rob;
Cell map[MAP_ROWS][MAP_COLS];

public:
	Map();
	Map(Robot *robot);
	virtual ~Map();
	void updateCell(int x, int y, Cell cell);
	Cell getCell(int x, int y);
	void printMap(void);
};

#endif /* MAP_H_ */
