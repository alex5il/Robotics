#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map/Map.h"
#include "Configurations/ConfigurationManager.h"
#include <iostream>

using namespace std;

int main() {
<<<<<<< HEAD
	Map* map = new Map();
	map->createGrid();
=======
	Map map;

	map.createGrid();
//Robot robot("localhost",6665);

//	string path = ConfigurationManager::getMapPath();

//	Map map;
//
//	map.createGrid();
>>>>>>> origin/Branch_1
}
