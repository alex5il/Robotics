#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"

#include "Map/Map.h"
#include "PathFinder/AStar.h"
#include "Configurations/ConfigurationManager.h"
#include <iostream>

#include <map>

using namespace std;

int main() {

	//Map test

	Map* map = Map::getInstance();
	map->createGrid();

	// A start test
	AStar* astr = new AStar();

	std::map<Location, Location> came_from;
	std::map<Location, int> cost_so_far;

	vector<Location> path = astr->runAstar(map->getGraph(), map->getStartLocation(), map->getEndLocation(), came_from, cost_so_far);

	// print test
	for (int i=0; i<path.size(); i++) {
		map->getGraph()->edges[path[i].posY][path[i].posX].cellType = CURRENT_CELL;
	}

	map->printMap();

}
