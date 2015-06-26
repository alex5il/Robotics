#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map/Map.h"
#include "Configurations/ConfigurationManager.h"
#include <iostream>

using namespace std;

int main() {

	//Map map = Map::getInstance();

	Map* map = Map::getInstance();
	map->createGrid();

}
